//nclude "DIALOGS\Thomas O'Reily_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_Meeting;
	int iTest;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);

	string iDay, iMonth;
	iDay = environment.date.day;
	iMonth = environment.date.month;
	string lastspeak_date = iday + " " + iMonth;
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

		case "trade":
			d.Text = DLG_TEXT[0];
			Link.l1 = DLG_TEXT[1];
			Link.l1.go = "trade_1";
			Link.l2 = DLG_TEXT[2];
			Link.l2.go = "items";
			Link.l3 = DLG_TEXT[3];
			Link.l3.go = "exit";
		break;

		case "trade_1":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
			LaunchStore(REDMOND_STORE);
		break;

		case "items":
			if (npchar.quest.item_date != lastspeak_date)
			{
				GiveItemToTrader(npchar);
				npchar.quest.item_date = lastspeak_date;
			}
			
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
			LaunchItemsTrade(NPChar);
		break;

		case "First time":
			Dialog.defAni = "Gov_Dialog_1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "Gov_Dialog_1";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";

			if(NPChar.quest.meeting == "0")
			{
				d.Text = DLG_TEXT[4] + address_form.eng + DLG_TEXT[5];
				Link.l1 = DLG_TEXT[6] + Pchar.name + " " + Pchar.lastname + DLG_TEXT[7];
				Link.l1.go = "meeting";
				NPC_Meeting = "1"; 
			}
			else
			{
				dialog.snd1 = "";
				dialog.snd2 = "";
				dialog.snd3 = "";
				d.Text = RandPhrase(TimeGreeting() + DLG_TEXT[8] + address_form.eng + " " + DLG_TEXT[9] + PChar.name + DLG_TEXT[10], DLG_TEXT[11] + PChar.name + DLG_TEXT[12], DLG_TEXT[13], &dialog, dialog.snd1, dialog.snd2, dialog.snd3);
				Link.l1 = DLG_TEXT[14];
				Link.l1.go = "Trade";
				Link.l2 = DLG_TEXT[15];
				Link.l2.go = "quest lines";
				Link.l3 = DLG_TEXT[16];
				Link.l3.go = "exit";
			}
			Diag.TempNode = "First Time";
		break;

		case "Meeting":
				d.Text = DLG_TEXT[17] + NPChar.name + " " + NPChar.lastname + DLG_TEXT[18];
				Link.l1 = DLG_TEXT[19] + NPChar.name + DLG_TEXT[20];
				Link.l1.go = "Trade";
				Link.l2 = DLG_TEXT[21] + NPChar.name + DLG_TEXT[22];
				Link.l2.go = "quest lines";
				Link.l3 = DLG_TEXT[23];
				Link.l3.go = "exit";
		break;

		case "quest lines":
			iTest = 0;
			d.Text = DLG_TEXT[24];
			if (npchar.quest_begin == "0")
			////////////////////////////////////////
			// ВЫДАЧА КВЕСТОВ
			////////////////////////////////////////
			{
				if (npchar.quest.contraband == "100000000" && !LAI_IsDead(characterFromID("Andre Juliao")) && GetSquadronFreeSpace(pchar, GOOD_EBONY)>=100)
				{
					Link.l1 = DLG_TEXT[25];
					Link.l1.go = "contraband";
				}
				if (NPChar.quest.first_job == "100000" && !(GetNationRelation2MainCharacter(FRANCE) == RELATION_ENEMY) && GetSquadronFreeSpace(pchar, GOOD_SILK) > 200)
				{
					Link.l1 = DLG_TEXT[26];
					Link.l1.go = "first_job";
				}
			}
			if (CheckAttribute(pchar, "quest.iQuantityGoods"))
			{
				int iQuantityShipGoods = pchar.quest.iQuantityGoods;
				int iQuestTradeGoods = pchar.quest.iTradeGoods;
			}
			if (CheckQuestAttribute("generate_trade_quest_progress", "begin") || CheckQuestAttribute("generate_trade_quest_progress",  "failed"))
			{
				if (CheckQuestAttribute("iTradeNation", npchar.nation) &&  GetSquadronGoods(pchar, iQuestTradeGoods) >= iQuantityShipGoods && pchar.quest.iTradeColony == pchar.location)
				{
					dialog.text = DLG_TEXT[27];
					link.l2 = DLG_TEXT[28];
					link.l2.go = "generate_quest_2";
				}
			}
			else
			{
				if (!CheckQuestAttribute("generate_trade_quest_progress", "begin"))
				{
					link.l2 = DLG_TEXT[29];
					link.l2.go = "generate_quest";
				}
			}
			////////////////////////////////////////
			// ПРИЕМ КВЕСТОВ
			////////////////////////////////////////
			if (NPChar.quest.first_job == "complete" && iTest < QUEST_COUNTER)
			{
				Link.l1 = characters[GetCharacterIndex(DLG_TEXT[30])].lastname + DLG_TEXT[31] + NPChar.name + DLG_TEXT[32];
				Link.l1.go = "first_job_complete";
				iTest = iTest + 1;
			}
			if (characters[GetCharacterIndex("Arnaud Matton")].quest.to_redmond_1 == "1" && iTest < QUEST_COUNTER && GetCargoGoods(pchar, GOOD_CHOCOLATE) >= 100)
			{
				link.l2 = DLG_TEXT[33] + characters[GetCharacterIndex(DLG_TEXT[34])].name + " " + characters[GetCharacterIndex(DLG_TEXT[35])].lastname + DLG_TEXT[36];
				link.l2.go = "redmond_1";
				iTest = iTest + 1;
			}
			////////////////////////////////////////
			// квест про котнрабандистов
			////////////////////////////////////////
			if (Characters[GetCharacterIndex("Milon Blacque")].quest.son == "2" && iTest < QUEST_COUNTER)
			{
				Characters[GetCharacterIndex("Milon Blacque")].quest.son = "money";
				link.l3 = DLG_TEXT[37];
				link.l3.go = "marc";
			}
			if (npchar.quest.contraband == "after_fight" && iTest < QUEST_COUNTER)
			{
				link.l3 = pcharrepphrase(DLG_TEXT[38], DLG_TEXT[39]);
				link.l3.go = "contraband_7";
				iTest = iTest + 1;
			}
			if (npchar.quest.contraband == "almost_done" && iTest < QUEST_COUNTER)
			{
				link.l3 = pcharrepphrase(DLG_TEXT[40], DLG_TEXT[41]);
				link.l3.go = "contraband_13";
				iTest = iTest + 1;
			}
			////////////////////////////////////////
			// конец квеста про котнрабандистов
			////////////////////////////////////////
			Link.l99 = DLG_TEXT[42];
			Link.l99.go = "no quest";
		break;

		case "contraband":
			dialog.text = DLG_TEXT[43] + address_form.eng + DLG_TEXT[44];
			link.l1 = pcharrepphrase(DLG_TEXT[45], DLG_TEXT[46]);
			link.l1.go = "contraband_1";
		break;

		case "contraband_1":
			dialog.text = DLG_TEXT[47];
			link.l1 = pcharrepphrase(DLG_TEXT[48], DLG_TEXT[49]);
			link.l1.go = "contraband_2";
		break;

		case "contraband_2":
			dialog.text = DLG_TEXT[50] + address_form.eng + DLG_TEXT[51];
			link.l1 = pcharrepphrase(DLG_TEXT[52], DLG_TEXT[53]);
			link.l1.go = "contraband_3";
			link.l2 = pcharrepphrase(DLG_TEXT[54], DLG_TEXT[55]);
			link.l2.go = "exit";
		break;

		case "contraband_3":
			dialog.text = DLG_TEXT[56];
			link.l1 = pcharrepphrase(DLG_TEXT[57], DLG_TEXT[58]);
			link.l1.go = "contraband_4";
			link.l2 = pcharrepphrase(DLG_TEXT[59], DLG_TEXT[60]);
			link.l2.go = "contraband_money";
			npchar.money.quest = "6000";
		break;

		case "contraband_4":
			dialog.text = DLG_TEXT[61];
			link.l1 = pcharrepphrase(DLG_TEXT[62], DLG_TEXT[63]);
			link.l1.go = "contraband_5";
		break;

		case "contraband_5":
			dialog.text = DLG_TEXT[64];
			link.l1 = pcharrepphrase(DLG_TEXT[65], DLG_TEXT[66]);
			link.l1.go = "contraband_6";
		break;

		case "contraband_6":
			dialog.text = DLG_TEXT[67] + characters[GetCharacterIndex(DLG_TEXT[68])].name + " " + characters[GetCharacterIndex(DLG_TEXT[69])].lastname + DLG_TEXT[70];
			link.l1 = pcharrepphrase(DLG_TEXT[71], DLG_TEXT[72]);
			link.l1.go = "exit";
			AddDialogExitQuest("thomas_contraband_exit");
			npchar.quest.contraband = "begin";
			AddMoneyToCharacter(pchar, makeint(npchar.money.quest)/2);
			npchar.money.quest = makeint(npchar.money.quest)/2;
		break;

		case "contraband_7":
			dialog.text = DLG_TEXT[73];
			link.l1 = pcharrepphrase(DLG_TEXT[74], DLG_TEXT[75]);
			link.l1.go = "contraband_8";
		break;

		case "contraband_8":
			dialog.text = DLG_TEXT[76];
			link.l1 = pcharrepphrase(DLG_TEXT[77], DLG_TEXT[78]);
			link.l1.go = "contraband_9";
		break;

		case "contraband_9":
			dialog.text = DLG_TEXT[79];
			link.l1 = pcharrepphrase(DLG_TEXT[80], DLG_TEXT[81]);
			link.l1.go = "contraband_10";
		break;

		case "contraband_10":
			dialog.text = DLG_TEXT[82] + address_form.eng + DLG_TEXT[83];
			link.l1 = pcharrepphrase(DLG_TEXT[84], DLG_TEXT[85]);
			link.l1.go = "contraband_11";
		break;

		case "contraband_11":
			dialog.text = DLG_TEXT[86];
			link.l1 = pcharrepphrase(DLG_TEXT[87], DLG_TEXT[88]);
			link.l1.go = "contraband_12";
			link.l2 = pcharrepphrase(DLG_TEXT[89], DLG_TEXT[90]);
			link.l2.go = "contraband_15";
		break;

		case "contraband_12":
			dialog.text = DLG_TEXT[91];
			link.l1 = pcharrepphrase(DLG_TEXT[92], DLG_TEXT[93]);
			link.l1.go = "exit";
			npchar.quest.contraband = "speed";
			npchar.money.quest = makeint(npchar.money.quest) + 2000;
			AddDialogExitQuest("thomas_contraband_12_exit");
		break;

		case "contraband_13":
			dialog.text = DLG_TEXT[94];
			link.l1 = pcharrepphrase(DLG_TEXT[95], DLG_TEXT[96]);
			link.l1.go = "contraband_14";
		break;

		case "contraband_14":
			dialog.text = DLG_TEXT[97];
			link.l1 = pcharrepphrase(DLG_TEXT[98], DLG_TEXT[99]);
			link.l1.go = "exit";
			AddPartyExp(pchar, 1500);
			AddMoneyToCharacter(pchar, makeint(npchar.money.quest));
			npchar.quest.contraband = "done";
			AddQuestRecord("Thomas_O'Reily_contraband", "4");
			CloseQuestHeader("Thomas_O'Reily_contraband");
		break;

		case "contraband_15":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
			npchar.quest.contraband = "done";
			AddQuestRecord("Thomas_O'Reily_contraband", "4");
			CloseQuestHeader("Thomas_O'Reily_contraband");
		break;

		case "contraband_money":
			dialog.text = DLG_TEXT[100] + (6000 + (GetSummonSkillFromName(pchar, DLG_TEXT[101])-1)*100) + DLG_TEXT[102];
			link.l1 = pcharrepphrase(DLG_TEXT[103], DLG_TEXT[104]);
			link.l1.go = "contraband_4";
			link.l2 = pcharrepphrase(DLG_TEXT[105], DLG_TEXT[106]);
			link.l2.go = "exit";
			npchar.money.quest = (6000 + (GetSummonSkillFromName(pchar, "commerce")-1)*100)
		break;

		case "No quest":
			d.Text = DLG_TEXT[107] + address_Form.eng + " " + PChar.name + DLG_TEXT[108];
			Link.l1 = DLG_TEXT[109];
			Link.l1.go = "Trade";
			Link.l2 = DLG_TEXT[110];
			Link.l2.go = "exit";
		break;

		case "first_job":
			d.Text = DLG_TEXT[111];
			Link.l1 = DLG_TEXT[112];
			Link.l1.go = "first_job_1";
			Link.l2 = DLG_TEXT[113];
			Link.l2.go = "first_job_2";
			Link.l3 = DLG_TEXT[114] + NPChar.name + DLG_TEXT[115];
			Link.l3.go = "exit";
		break;
		
		case "first_job_1":
			d.Text = DLG_TEXT[116];
			Link.l1 = DLG_TEXT[117];
			if(makeint(Pchar.skill.commerce) >= 2)
			{
				Link.l1.go = "first_job_3";
			}
			else
			{
				Link.l1.go = "first_job_4";
			}
			Link.l2 = DLG_TEXT[118];
			Link.l2.go = "first_job_5";
			Link.l3 = DLG_TEXT[119] + NPChar.name + DLG_TEXT[120];
			Link.l3.go = "exit";
		break;

		case "first_job_2":
			d.Text = DLG_TEXT[121];
			Link.l1 = DLG_TEXT[122];
			Link.l1.go = "first_job_1";
			Link.l2 = DLG_TEXT[123] + NPChar.name + DLG_TEXT[124];
			Link.l2.go = "exit";
		break;

		case "first_job_3":
			d.Text = DLG_TEXT[125];
			Link.l1 = DLG_TEXT[126];
			Link.l1.go = "first_job_6";
			Link.l2 = DLG_TEXT[127] + NPChar.name + DLG_TEXT[128];
			Link.l2.go = "No quest";
		break;

		case "first_job_4":
			d.Text = DLG_TEXT[129] + PChar.name + DLG_TEXT[130];
			Link.l1 = DLG_TEXT[131];
			Link.l1.go = "first_job_5";
			Link.l2 = DLG_TEXT[132] + NPChar.name + DLG_TEXT[133];
			Link.l2.go = "No quest";
		break;

		case "first_job_5":
			NPChar.quest.first_job = "1";
			NPChar.money.quest = "1500";
			d.Text = DLG_TEXT[134] + PChar.name + DLG_TEXT[135];
			AddCharacterGoods(pchar, GOOD_SILK, 200);
			Link.l1 = DLG_TEXT[136];
			Link.l1.go = "trade";
			Link.l2 = DLG_TEXT[137] + NPChar.name + DLG_TEXT[138];
			Link.l2.go = "exit";
		break;

		case "first_job_6":
			NPChar.quest.first_job = "1";
			NPChar.money.quest = "1500";
			d.Text = DLG_TEXT[139] + PChar.name + DLG_TEXT[140];
			Link.l1 = DLG_TEXT[141];
			Link.l1.go = "trade";
			Link.l2 = DLG_TEXT[142] + NPChar.name + DLG_TEXT[143];
			Link.l2.go = "exit";
		break;

		case "first_job_complete":
			NPChar.quest.first_job = "done";
			NPChar.money.quest = "1500";
			d.Text = DLG_TEXT[144] + PChar.name + DLG_TEXT[145];
			Link.l1 = DLG_TEXT[146] + NPChar.money.quest + DLG_TEXT[147];
			Link.l1.go = "first_job_complete_1";
			Link.l2 = DLG_TEXT[148] + NPChar.name + DLG_TEXT[149];
			Link.l2.go = "first_job_complete_2";
			npchar.quest_begin = "0";
		break;

		case "first_job_complete_1":
			AddMoneyToCharacter(pchar, makeint(npchar.money.quest));
			NPChar.quest.first_job = "done";
			d.Text = DLG_TEXT[150] + NPChar.money.quest + DLG_TEXT[151];
			Link.l1 = DLG_TEXT[152] + NPChar.name + DLG_TEXT[153];
			Link.l1.go = "No quest";
			Link.l2 = DLG_TEXT[154] + NPChar.name + DLG_TEXT[155];
			Link.l2.go = "exit";
		break;

		case "first_job_complete_2":
			d.Text = DLG_TEXT[156];
			Link.l1 = DLG_TEXT[157];
			Link.l1.go = "first_job_complete_1";
		break;

		case "redmond_1":
			Dialog.text = DLG_TEXT[158];
			link.l1 = Characters[GetcharacterIndex(DLG_TEXT[159])].name + " " + characters[GetcharacterIndex(DLG_TEXT[160])].lastname + DLG_TEXT[161];
			link.l1.go = "redmond_2";
		break;
	
		case "redmond_2":
			dialog.text = DLG_TEXT[162];
			link.l1 = DLG_TEXT[163];
			link.l1.go = "redmond_3";
			RemoveCharacterGoods(pchar, GOOD_CHOCOLATE, 100);
			characters[GetcharacterIndex("Arnaud Matton")].quest.to_redmond_1 = "cargo_done";
		break;

		case "redmond_3":
			dialog.text = DLG_TEXT[164];
			link.l1 = DLG_TEXT[165];
			link.l1.go = "trade"; 
			link.l2 = DLG_TEXT[166];
			link.l2.go = "exit";
		break;

		case "marc":
			Dialog.text = DLG_TEXT[167];
			link.l1 = DLG_TEXT[168];
			link.l1.go = "marc_1";
		break;

		case "marc_1":
			Dialog.text = DLG_TEXT[169];
			link.l1 = DLG_TEXT[170];
			link.l1.go = "marc_2";
		break;

		case "marc_2":
			Dialog.text = DLG_TEXT[171];
			link.l1 = DLG_TEXT[172];
			link.l1.go = "marc_3";
		break;

		case "marc_3":
			Dialog.text = DLG_TEXT[173];
			link.l1 = DLG_TEXT[174];
			link.l1.go = "marc_4";
		break;

		case "marc_4":
			Dialog.text = DLG_TEXT[175];
			link.l1 = DLG_TEXT[176];
			link.l1.go = "exit";
			if (makeint(pchar.money) >= 3000)
			{
				link.l1 = DLG_TEXT[177];
				link.l1.go = "marc_5";
			}
		break;

		case "marc_5":
			Dialog.text = DLG_TEXT[178];
			link.l1 = DLG_TEXT[179];
			link.l1.go = "exit";
			AddMoneyToCharacter(pchar, -3000);
			Characters[GetcharacterIndex("Milon Blacque")].quest.son = "money_done";
		break;

		case "generate_quest":
			if (npchar.quest.trade_date != lastspeak_date)
			{
				npchar.quest.trade_date = lastspeak_date;
				//проверка враждебности нам страны торговца
				if (GetNationRelation2MainCharacter(ENGLAND) == RELATION_ENEMY)
				{
					dialog.text = DLG_TEXT[180];
					link.l1 = DLG_TEXT[181];
					link.l1.go = "exit";
				}
				else
				{
					int iTradeNation = GenerateNationTrade(ENGLAND);
					if (iTradeNation < 0)
					{
						dialog.text = DLG_TEXT[182];
						link.l1 = DLG_TEXT[183];
						link.l1.go = "exit";
					}
					else
					{
						//проверяем импорт/экспорт
						int iTradeGoods = rand(22) + 4;
						//проверяем свободное место (при этом должно вмещаться по меньшей мере 100 единиц выбранного груза
						if (GetSquadronFreeSpace(pchar, iTradeGoods) < 100)
						{
							dialog.text = DLG_TEXT[184];
							link.l1 = DLG_TEXT[185];
							link.l1.go = "exit";
						}
						else
						{
							int iQuantityGoods = GetSquadronFreeSpace(pchar, iTradeGoods) - 20;
							int iMoney = ((iQuantityGoods *10+99)/100)*100;
							int iDaysExpired = 30;

							pchar.quest.iTradeGoods = iTradeGoods;
							pchar.quest.iQuantityGoods = iQuantityGoods;
							pchar.quest.iMoney = iMoney;
							pchar.quest.iTradeNation = iTradeNation;
							
							string sNation;

							switch (iTradeNation)
							{
								case FRANCE: sNation = FRA_COLONY; break;
								case SPAIN: sNation = SPA_COLONY; break;
								case HOLLAND: sNation = HOL_COLONY; break;
								case PORTUGAL: sNation = POR_COLONY; break;
								case ENGLAND: 
									int iColony = rand(2);
									switch (iColony)
									{
										case 0: sNation = RED_COLONY; pchar.quest.iTradeColony = "Redmond_store"; break;
										case 1: sNation = GREEN_COLONY; pchar.quest.iTradeColony = "Greenford_store"; break;
										case 2: sNation = OX_COLONY; pchar.quest.iTradeColony = "Oxbay_store"; break;
									}
								break;
							}
							dialog.text = DLG_TEXT[186] + sNation + DLG_TEXT[187] + pchar.quest.iMoney + DLG_TEXT[188];
							link.l1 = DLG_TEXT[189];
							link.l1.go = "exit_trade";
							link.l2  = DLG_TEXT[190];
							link.l2.go = "exit";
						}
					}
				}
			}
			else
			{
				dialog.text = DLG_TEXT[191];
				link.l1 = DLG_TEXT[192];
				link.l1.go = "exit";
			}
		break;
		
		case "exit_trade":
			AddDialogExitQuest("trade_quest_open");
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;

		case "generate_quest_2":
			if (pchar.quest.generate_trade_quest_progress == "failed")
			{
				dialog.text = DLG_TEXT[193];
				link.l1 = DLG_TEXT[194];
				link.l1.go = "exit";
				ChangeCharacterReputation(pchar, -1);
			}
			else
			{
				dialog.text = DLG_TEXT[195];
				link.l1 = DLG_TEXT[196];
				link.l1.go = "exit";
				ChangeCharacterReputation(pchar, 1);
				AddPartyExp(pchar, (makeint(pchar.quest.iMoney)/2));
				AddMoneyToCharacter(pchar, makeint(pchar.quest.iMoney));
				pchar.quest.generate_trade_quest_progress = "";
				pchar.quest.generate_trade_quest.over = "yes";
				RemoveCharacterGoods(pchar, makeint(pchar.quest.iTradeGoods), makeint(pchar.quest.iQuantityGoods));
			}
			AddDialogExitQuest("close_trade_quest");
		break;

	}
}
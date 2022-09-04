//nclude "DIALOGS\Alan Milds_dialog.h"

void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_Meeting;

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
			dialog.snd = "Voice\ALMI\ALMI001";
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
			DialogExit();
			LaunchStore(OXBAY_STORE);
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
			Dialog.defAni = "dialog_stay2";
			Dialog.defCam = "2";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";

			if(NPChar.quest.meeting == "0")
			{
				dialog.snd = "Voice\ALMI\ALMI002";
				d.Text = DLG_TEXT[4] + address_form.eng + DLG_TEXT[5];
				Link.l1 = DLG_TEXT[6] + Pchar.name + " " + Pchar.lastname + DLG_TEXT[7];
				Link.l1.go = "meeting";
				NPC_Meeting = "1";
			}
			else
			{
				dialog.snd1 = "Voice\ALMI\ALMI003";
				dialog.snd2 = "Voice\ALMI\ALMI004";
				dialog.snd3 = "Voice\ALMI\ALMI005";
				d.Text = RandPhrase(DLG_TEXT[8], DLG_TEXT[9], DLG_TEXT[10], &dialog, dialog.snd1, dialog.snd2, dialog.snd3);
				Link.l1 = DLG_TEXT[11];
				if(CheckAttribute(Pchar, "Quest.Story_OxbayCaptured"))
				{
					Link.l1.go = "no trade";
				}
				else
				{
					Link.l1.go = "trade";
				}
				Link.l2 = DLG_TEXT[12];
				Link.l2.go = "quest lines";
				Link.l3 = DLG_TEXT[13];
				Link.l3.go = "exit";
			}
			Diag.TempNode = "First Time";
		break;

		case "Meeting":
			dialog.snd = "Voice\ALMI\ALMI006";
			d.Text = DLG_TEXT[14] + NPChar.name + " " + NPChar.lastname + DLG_TEXT[15];
			Link.l1 = DLG_TEXT[16] + NPChar.name + DLG_TEXT[17];
				if(CheckAttribute(Pchar, "Quest.Story_OxbayCaptured"))
				{
					Link.l1.go = "no trade";
				}
				else
				{
					Link.l1.go = "trade";
				}
			Link.l2 = DLG_TEXT[18] + NPChar.name + DLG_TEXT[19];
			Link.l2.go = "quest lines";
			Link.l3 = DLG_TEXT[20];
			Link.l3.go = "exit";
		break;

		case "quest lines":
			dialog.snd = "Voice\ALMI\ALMI007";
			d.Text = DLG_TEXT[21];
			if (CheckAttribute(pchar, "quest.iQuantityGoods"))
			{
				int iQuantityShipGoods = pchar.quest.iQuantityGoods;
				int iQuestTradeGoods = pchar.quest.iTradeGoods;
			}
			if (CheckQuestAttribute("generate_trade_quest_progress", "begin") || CheckQuestAttribute("generate_trade_quest_progress",  "failed"))
			{
				if (CheckQuestAttribute("iTradeNation", npchar.nation) &&  GetSquadronGoods(pchar, iQuestTradeGoods) >= iQuantityShipGoods && pchar.quest.iTradeColony == pchar.location)
				{
					dialog.snd = "Voice\ALMI\ALMI008";
					dialog.text = DLG_TEXT[22];
					link.l1 = DLG_TEXT[23];
					link.l1.go = "generate_quest_2";
				}
			}
			else
			{
				if (!CheckQuestAttribute("generate_trade_quest_progress", "begin"))
				{
					if(!CheckAttribute(Pchar, "Quest.Story_OxbayCaptured"))
					{
						link.l1 = DLG_TEXT[24];
						link.l1.go = "generate_quest";
					}
				}
			}
			link.l99 = DLG_TEXT[25];
			Link.l99.go = "no quest";
		break;

		case "generate_quest":
			if (npchar.quest.trade_date != lastspeak_date)
			{
				npchar.quest.trade_date = lastspeak_date;
				//проверка враждебности нам страны торговца
				if (GetNationRelation2MainCharacter(ENGLAND) == RELATION_ENEMY)
				{
					dialog.snd = "Voice\ALMI\ALMI009";
					dialog.text = DLG_TEXT[26];
					link.l1 = DLG_TEXT[27];
					link.l1.go = "exit";
				}
				else
				{
					int iTradeNation = GenerateNationTrade(ENGLAND);
					if (iTradeNation < 0)
					{
						dialog.snd = "Voice\ALMI\ALMI010";
						dialog.text = DLG_TEXT[28];
						link.l1 = DLG_TEXT[29];
						link.l1.go = "exit";
					}
					else
					{
						//проверяем импорт/экспорт
						int iTradeGoods = rand(22) + 4;
						//проверяем свободное место (при этом должно вмещаться по меньшей мере 100 единиц выбранного груза
						if (GetSquadronFreeSpace(pchar, iTradeGoods) < 100)
						{
							dialog.snd = "Voice\ALMI\ALMI011";
							dialog.text = DLG_TEXT[30];
							link.l1 = DLG_TEXT[31];
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
							dialog.snd = "Voice\ALMI\ALMI012";
							dialog.text = DLG_TEXT[32] + sNation + DLG_TEXT[33] + pchar.quest.iMoney + DLG_TEXT[34];
							link.l1 = DLG_TEXT[35];
							link.l1.go = "exit_trade";
							link.l2  = DLG_TEXT[36];
							link.l2.go = "exit";
						}
					}
				}
			}
			else
			{
				dialog.snd = "Voice\ALMI\ALMI013";
				dialog.text = DLG_TEXT[37];
				link.l1 = DLG_TEXT[38];
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
				dialog.snd = "Voice\ALMI\ALMI014";
				dialog.text = DLG_TEXT[39];
				link.l1 = DLG_TEXT[40];
				link.l1.go = "exit";
				ChangeCharacterReputation(pchar, -1);
			}
			else
			{
				dialog.snd = "Voice\ALMI\ALMI015";
				dialog.text = DLG_TEXT[41];
				link.l1 = DLG_TEXT[42];
				link.l1.go = "exit";
				ChangeCharacterReputation(pchar, +1);
				AddPartyExp(pchar, (makeint(pchar.quest.iMoney)/2));
				AddMoneyToCharacter(pchar, makeint(pchar.quest.iMoney));
				pchar.quest.generate_trade_quest_progress = "";
				pchar.quest.generate_trade_quest.over = "yes";
				RemoveCharacterGoods(pchar, makeint(pchar.quest.iTradeGoods), makeint(pchar.quest.iQuantityGoods));
			}
			AddDialogExitQuest("close_trade_quest");
		break;

		case "No quest":
			dialog.snd = "Voice\ALMI\ALMI016";
			d.Text = DLG_TEXT[43] + address_Form.eng + " " + PChar.name + DLG_TEXT[44];
			Link.l1 = DLG_TEXT[45];
			if(CheckAttribute(Pchar, "Quest.Story_OxbayCaptured"))
			{
				Link.l1.go = "no trade";
			}
			else
			{
				Link.l1.go = "trade";
			}
			Link.l2 = DLG_TEXT[46];
			Link.l2.go = "exit";
		break;

		case "No trade":
			dialog.snd = "Voice\ALMI\ALMI017";
			d.Text = DLG_TEXT[47] + address_Form.eng + " " + PChar.name + DLG_TEXT[48];
			Link.l1 = DLG_TEXT[49];
			Link.l1.go = "No quest";
		break;


	}
}
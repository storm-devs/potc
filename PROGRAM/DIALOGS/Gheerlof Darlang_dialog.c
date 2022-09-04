//nclude "DIALOGS\Gheerlof Darlang_dialog.h"
// object	Dialog;	declared in dialog.c
// ref		NPChar; declared in dialog.c
//#include "Dialogs\blaze_dialog_defines.c"

void ProcessDialogEvent()
{
	ref NPChar;
	
	DeleteAttribute(&Dialog,"Links");
	aref Link, NextDiag;
	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	int iTest;

	string iDay, iMonth;
	iDay = environment.date.day;
	iMonth = environment.date.month;
	string lastspeak_date = iday + " " + iMonth;

	ref PChar;
	PChar = GetMainCharacter();


	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			if (npchar.quest.meeting == "0")
			{
				dialog.snd = "Voice\GHDA\GHDA001";
				Dialog.Text = DLG_TEXT[0] + address_form.eng + DLG_TEXT[1] + npchar.name + " " + npchar.lastname + DLG_TEXT[2];
				Link.l1 = DLG_TEXT[3] + pchar.name + " " + pchar.lastname + DLG_TEXT[4];
				link.l1.go = "node_1";
			}
			NextDiag.TempNode = "Second time";
		break;

		case "second time":
			dialog.snd = pcharrepphrase("Voice\GHDA\GHDA002", "Voice\GHDA\GHDA003");
			dialog.text = pcharrepphrase(DLG_TEXT[5] + address_form.eng + DLG_TEXT[6], DLG_TEXT[7]);
			Link.l1 = pcharrepphrase(DLG_TEXT[8] + npchar.name + DLG_TEXT[9], DLG_TEXT[10]); 
			link.l1.go = "node_1";
			NextDiag.TempNode = "Second time";
		break;

		case "node_1":
			dialog.snd = "Voice\GHDA\GHDA004";
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "market";
			link.l2 = DLG_TEXT[13];
			link.l2.go = "quests";
			link.l3 = DLG_TEXT[14];
			link.l3.go = "exit";
		break;

		case "market":
			dialog.snd = "Voice\GHDA\GHDA005";
			dialog.Text = DLG_TEXT[15];
			Link.l1 = DLG_TEXT[16];
			Link.l1.go = "trade_1";
			Link.l2 = DLG_TEXT[17];
			Link.l2.go = "items";
			Link.l3 = DLG_TEXT[18];
			Link.l3.go = "exit";
		break;

		case "trade_1":
			NextDiag.CurrentNode = NextDiag.TempNode;
			//NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
			LaunchStore(DOUWESEN_STORE);
		break;

		case "items":
			if (npchar.quest.item_date != lastspeak_date)
			{
				GiveItemToTrader(npchar);
				npchar.quest.item_date = lastspeak_date;
			}
			
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			LaunchItemsTrade(NPChar);
		break;

		case "quests":
			iTest = 0;
			if (CheckAttribute(pchar, "quest.iQuantityGoods"))
			{
				int iQuantityShipGoods = pchar.quest.iQuantityGoods;
				int iQuestTradeGoods = pchar.quest.iTradeGoods;
			}
			if (CheckQuestAttribute("generate_trade_quest_progress", "begin") || CheckQuestAttribute("generate_trade_quest_progress",  "failed"))
			{
				if (CheckQuestAttribute("iTradeNation", npchar.nation) &&  GetSquadronGoods(pchar, iQuestTradeGoods) >= iQuantityShipGoods)
				{
					dialog.snd = "Voice\GHDA\GHDA006";
					dialog.text = DLG_TEXT[19];
					link.l1 = DLG_TEXT[20];
					link.l1.go = "generate_quest_2";
				}
			}
			else
			{
				if (!CheckQuestAttribute("generate_trade_quest_progress", "begin"))
				{
					link.l1 = DLG_TEXT[21];
					link.l1.go = "generate_quest";
				}
			}
			link.l99 = DLG_TEXT[22];
			Link.l99.go = "exit";
		break;

		case "generate_quest":
			if (npchar.quest.trade_date != lastspeak_date)
			{
				npchar.quest.trade_date = lastspeak_date;
				//проверка враждебности нам страны торговца
				if (GetNationRelation2MainCharacter(HOLLAND) == RELATION_ENEMY)
				{
					dialog.snd = "Voice\GHDA\GHDA007";
					dialog.text = DLG_TEXT[23];
					link.l1 = DLG_TEXT[24];
					link.l1.go = "exit";
				}
				else
				{
					int iTradeNation = GenerateNationTrade(HOLLAND);
					if (iTradeNation < 0)
					{
						dialog.snd = "Voice\GHDA\GHDA008";
						dialog.text = DLG_TEXT[25];
						link.l1 = DLG_TEXT[26];
						link.l1.go = "exit";
					}
					else
					{
						//проверяем импорт/экспорт
						int iTradeGoods = rand(22) + 4;
						//проверяем свободное место (при этом должно вмещаться по меньшей мере 100 единиц выбранного груза
						if (GetSquadronFreeSpace(pchar, iTradeGoods) < 100)
						{
							dialog.snd = "Voice\GHDA\GHDA009";
							dialog.text = DLG_TEXT[27];
							link.l1 = DLG_TEXT[28];
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
									if (iColony == 2 && CheckAttribute(Pchar, "Quest.Story_OxbayCaptured"))
									{
										iColony = rand(1);
									}
									switch (iColony)
									{
										case 0: sNation = RED_COLONY; pchar.quest.iTradeColony = "Redmond_store"; break;
										case 1: sNation = GREEN_COLONY; pchar.quest.iTradeColony = "Greenford_store"; break;
										case 2: sNation = OX_COLONY; pchar.quest.iTradeColony = "Oxbay_store"; break;
									}
								break;
							}
							dialog.snd = "Voice\GHDA\GHDA010";
							dialog.text = DLG_TEXT[29] + sNation + DLG_TEXT[30] + pchar.quest.iMoney + DLG_TEXT[31];
							link.l1 = DLG_TEXT[32];
							link.l1.go = "exit_trade";
							link.l2  = DLG_TEXT[33];
							link.l2.go = "exit";
						}
					}
				}
			}
			else
			{
				dialog.snd = "Voice\GHDA\GHDA011";
				dialog.text = DLG_TEXT[34];
				link.l1 = DLG_TEXT[35];
				link.l1.go = "exit";
			}
		break;
		
		case "exit_trade":
			AddDialogExitQuest("trade_quest_open");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "generate_quest_2":
			if (pchar.quest.generate_trade_quest_progress == "failed")
			{
				dialog.snd = "Voice\GHDA\GHDA012";
				dialog.text = DLG_TEXT[36];
				link.l1 = DLG_TEXT[37];
				link.l1.go = "exit";
				ChangeCharacterReputation(pchar, -1);
			}
			else
			{
				dialog.snd = "Voice\GHDA\GHDA013";
				dialog.text = DLG_TEXT[38];
				link.l1 = DLG_TEXT[39];
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
		
		case "no_quests":
			dialog.snd = "Voice\GHDA\GHDA014";
			dialog.text = DLG_TEXT[40];
			link.l1 = DLG_TEXT[41];
			link.l1.go = "node_1";
		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}

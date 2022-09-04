//nclude "DIALOGS\Peter Blowhorn_dialog.h"
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
		// ----------------------------------- Диалог первый - первая встреча
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
				Dialog.snd = "voice\PEBL\PEBL001";
				Dialog.Text = DLG_TEXT[0] + address_form.eng + DLG_TEXT[1] + npchar.name + " " + npchar.lastname + DLG_TEXT[2];
				Link.l1 = DLG_TEXT[3] + pchar.name + " " + pchar.lastname + DLG_TEXT[4];
				link.l1.go = "node_1";
			}
			NextDiag.TempNode = "Second time";
		break;

		case "second time":
			Dialog.snd = pcharrepphrase("voice\PEBL\PEBL002", "voice\PEBL\PEBL003");
			dialog.text = pcharrepphrase(DLG_TEXT[5] + address_form.eng + DLG_TEXT[6], DLG_TEXT[7]);
			Link.l1 = pcharrepphrase(DLG_TEXT[8] + npchar.name + DLG_TEXT[9], DLG_TEXT[10]); 
			link.l1.go = "node_1";
			NextDiag.TempNode = "Second time";
		break;

		case "node_1":
			Dialog.snd = "voice\PEBL\PEBL004";
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "trade";
			link.l2 = DLG_TEXT[13];
			link.l2.go = "quests";
			link.l3 = DLG_TEXT[14];
			link.l3.go = "exit";
		break;

		case "trade":
			Dialog.snd = "voice\PEBL\PEBL005";
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
			DialogExit();
			LaunchStore(PIRATES_STORE);
		break;

		case "items":
			if (npchar.quest.Meeting != lastspeak_date)
			{
				GiveItemToTrader(npchar);
				npchar.quest.Meeting = lastspeak_date;
			}
			
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			LaunchItemsTrade(NPChar);
		break;

		case "quests":
			iTest = 0;
			Dialog.snd = "voice\PEBL\PEBL006";
			Dialog.text = DLG_TEXT[19];
			Link.l1 = DLG_TEXT[20];
			Link.l1.go = "no_quests";
			if (CheckQuestAttribute("nigel_away_for_ship", "talk_with_clauss"))
			{
				link.l1 = DLG_TEXT[21];
				link.l1.go = "clauss";
			}
		break;
		
		case "clauss":
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "clauss_2";
		break;
		
		case "clauss_2":
			dialog.text = DLG_TEXT[24];
			if (makeint(pchar.money >=2632))
			{
				link.l1 = DLG_TEXT[25];
				link.l1.go = "clauss_3";
			}
			link.l2 = DLG_TEXT[26];
			link.l2.go = "exit";
		break;
		
		case "clauss_3":
			dialog.text = DLG_TEXT[27];
			link.l1 = DLG_TEXT[28];
			link.l1.go = "exit";
			AddDialogExitQuest("clauss_to_tavern");
		break;
		
		case "no_quests":
			Dialog.snd = "voice\PEBL\PEBL007";
			dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "node_1";
		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}

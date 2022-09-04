//nclude "DIALOGS\Jacinto Arcibaldo Barreto_dialog.h"
// object	Dialog;	declared in dialog.c
// ref		NPChar; declared in dialog.c
//#include "Dialogs\blaze_dialog_defines.c"

void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

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
			Dialog.snd = "dialogs\0\009";

			if (npchar.quest.meeting == "0")
			{
				dialog.text = DLG_TEXT[0] + npchar.name + " " + npchar.middlename + " " + npchar.lastname + DLG_TEXT[1] + address_form.spa + DLG_TEXT[2];
				Link.l1 = DLG_TEXT[3] + pchar.name + " " + pchar.lastname + DLG_TEXT[4];
				Link.l1.go = "node_1";
				npchar.quest.meeting = "1";
			}
			else
			{
				dialog.text = DLG_TEXT[5];
				link.l1 = DLG_TEXT[6];
				link.l1.go = "quests";
				link.l2 = DLG_TEXT[7];
				link.l2.go = "exit";
			}
			NextDiag.TempNode = "First time";
		break;

		case "node_1":
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "quests";
			link.l2 = DLG_TEXT[10];
			link.l2.go = "node_2";
		break;

		case "node_2":
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "exit";
		break;

		case "quests":
			dialog.text = DLG_TEXT[13] + address_form.spa + DLG_TEXT[14];
			if (CheckQuestAttribute("nigel_con_parri_checker", "win_win") || CheckQuestAttribute("nigel_con_parri_checker", "win"))
			{
				link.l1 = DLG_TEXT[15];
				link.l1.go = "garri";
			}			
			link.l99 = DLG_TEXT[16];
			link.l99.go = "exit";
		break;
		
		case "garri":
			dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];
			link.l1.go = "garri_2";
		break;
		
		case "garri_2":
			dialog.text = DLG_TEXT[19];
			link.l1 = DLG_TEXT[20];
			if (CheckQuestAttribute("nigel_con_parri_checker", "win_win"))
			{
				link.l1.go = "garri_3";
			}
			else
			{
				link.l1.go = "exit";
			}
			AddQuestrecord("nigel", "15");
			DeleteAttribute(PChar, "quest.nigel_con_parri_checker");
			PChar.quest.con_parri_expired.over = "yes";
			AddMoneyToCharacter(pchar, 3000);
			ChangeCharacterReputation(pchar, 1);
			AddDialogExitQuest("nigel_third_encounter");
		break;
		
		case "garri_3":
			dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "garri_4";
		break;
		
		case "garri_4":
			dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[24];
			link.l1.go = "exit";
			AddMoneyToCharacter(pchar, 6000);
			ChangeCharacterReputation(pchar, 1);
		break;
						
		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "j_day":
			dialog.text = Pchar.name + " " + Pchar.lastname + DLG_TEXT[25]; 
			link.l1 = DLG_TEXT[26];
			link.l1.go = "continue1";
		break;

		case "continue1":
			LAi_QuestDelay("ex_dialog", 2);
			DialogExit();
			NextDiag.CurrentNode = "j_day2";
		break;

		case "j_day2":
			dialog.text = Pchar.name + " " + Pchar.lastname + DLG_TEXT[27]; 
			link.l1 = DLG_TEXT[28];
			link.l1.go = "exit";
		break;

	}
}

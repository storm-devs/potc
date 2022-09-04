//nclude "DIALOGS\Unhappy women_dialog.h"

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
						
			Dialog.snd = "voice\UNWO\UNWO001";
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
			
			if (!CheckAttribute(pchar, "quest.ANIMISTS"))
			{
				Dialog.snd = "voice\UNWO\UNWO002";
				dialog.text = DLG_TEXT[2];
				link.l1 = DLG_TEXT[3];
				link.l1.go = "talk_1";
			}
			if (CheckQuestAttribute("ANIMISTS", "denied"))
			{
				link.l1 = DLG_TEXT[4];
				link.l1.go = "exit";
				pchar.quest.ANIMISTS.over = "yes";
			}
			if (CheckQuestAttribute("ANIMISTS", "completed") && npchar.quest.ANIMISTS != "completed")
			{
				Dialog.snd = "voice\UNWO\UNWO003";
				dialog.text = DLG_TEXT[5];
				link.l1 = DLG_TEXT[6];
				link.l1.go = "destroyed_sekt";
			}

			NextDiag.TempNode = "first time";
		break;

		case "destroyed_sekt":
			Dialog.snd = "voice\UNWO\UNWO004";
			dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "exit";
			AddpartyExp(pchar, 4000);
			npchar.quest.ANIMISTS = "completed";
			AddDialogExitQuest("womens_leave_town");
		break;

		case "talk_1":
			Dialog.snd = "voice\UNWO\UNWO005";
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "talk_2";
		break;

		case "talk_2":
			Dialog.snd = "voice\UNWO\UNWO006";
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "talk_3";
		break;

		case "talk_3":
			Dialog.snd = "voice\UNWO\UNWO007";
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "talk_4";
		break;

		case "talk_4":
			Dialog.snd = "voice\UNWO\UNWO008";
			dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "talk_5";
		break;

		case "talk_5":
			Dialog.snd = "voice\UNWO\UNWO009";
			dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];
			link.l1.go = "exit";
			SetQuestHeader("ANIMISTS");
			AddQuestrecord("ANIMISTS", "1");
			pchar.quest.ANIMISTS = "begin";
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}

//nclude "DIALOGS\QC citizen_dialog.h"

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
			Dialog.snd = "voice\QCSI\QCSI001";
			
			dialog.snd1 = "";
			dialog.snd2 = "";
			dialog.snd3 = "";
			
			dialog.snd1 = "";
			dialog.snd2 = "";
			dialog.snd3 = "";
			dialog.text = randphrase(DLG_TEXT[0], DLG_TEXT[1], DLG_TEXT[2], &dialog, dialog.snd1, dialog.snd2, dialog.snd3);
			link.l1 = DLG_TEXT[3];
			link.l1.go = "exit";

			if (pchar.quest.main_line == "blaze_talk_with_silehard_complete" && characters[GetCharacterIndex("Ines Diaz")].quest.rheims != "speak_with_humans")
			{
				Dialog.snd = "voice\QCSI\QCSI001";
				dialog.text = DLG_TEXT[4];
				link.l1 = DLG_TEXT[5] + characters[GetCharacterIndex(DLG_TEXT[6])].name + " " + characters[GetCharacterIndex(DLG_TEXT[7])].lastname + DLG_TEXT[8];
				link.l1.go = "search_rheims";
				AddQuestRecord("Blaze_search_Rheims", "12");
				characters[GetCharacterIndex("Ines Diaz")].quest.rheims = "speak_with_humans";
			}
			NextDiag.TempNode = "first time";
		break;

		case "search_rheims":
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "exit";
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}

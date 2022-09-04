//nclude "DIALOGS\Gilbert Ballester_dialog.h"

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
			
			dialog.snd = "Voice\GIBA\GIBA001";
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
			
			if (characters[GetCharacterIndex("Father Bernard")].quest.church_help == "to_greenford" || Characters[GetCharacterIndex("Father Bernard")].quest.church_help == "after_traktir" || characters[GetCharacterIndex("Father Bernard")].quest.church_help == "speak_with_jerald")
			{
				link.l1 = DLG_TEXT[2] + characters[GetCharacterIndex(DLG_TEXT[3])].name + " " + characters[GetCharacterIndex(DLG_TEXT[4])].lastname + DLG_TEXT[5];
				link.l1.go = "to_greenford_2";
			}
			NextDiag.TempNode = "first time";
		break;

		case "to_greenford_2":
			dialog.snd = "Voice\GIBA\GIBA002";
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "to_greenford_3";
		break;

		case "to_greenford_3":
			dialog.snd = "Voice\GIBA\GIBA003";
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "to_greenford_4";
		break;

		case "to_greenford_4":
			dialog.snd = "Voice\GIBA\GIBA004";
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "to_greenford_5";
		break;

		case "to_greenford_5":
			dialog.snd = "Voice\GIBA\GIBA005";
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "to_greenford_6";
			GiveItem2Character(pchar, LOVE_LETTERS_OF_PRIEST);
		break;

		case "to_greenford_6":
			dialog.snd = "Voice\GIBA\GIBA006";
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "to_greenford_7";
		break;

		case "to_greenford_7":
			dialog.snd = "Voice\GIBA\GIBA007";
			dialog.text = DLG_TEXT[16] + characters[GetCharacterIndex(DLG_TEXT[17])].name + " " + characters[GetCharacterIndex(DLG_TEXT[18])].lastname + DLG_TEXT[19];
			if (Characters[GetCharacterIndex("Father Bernard")].quest.church_help == "after_traktir")
			{
				link.l1 = DLG_TEXT[20];
				link.l1.go = "to_greenford_8";
			}
			else
			{
				link.l1 = DLG_TEXT[21];
				link.l1.go = "exit";
			}
			if (characters[GetCharacterIndex("Father Bernard")].quest.church_help == "speak_with_jerald")
			{
				characters[GetCharacterIndex("Father Bernard")].quest.church_help = "letters_2";
			}
			else
			{
				characters[GetCharacterIndex("Father Bernard")].quest.church_help = "letters_1";
			}
			AddQuestRecord("church_help", "3");
		break;

		case "to_greenford_8":
			dialog.snd = "Voice\GIBA\GIBA008";
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "exit";
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}

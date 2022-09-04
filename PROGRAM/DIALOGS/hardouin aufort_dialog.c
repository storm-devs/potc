//nclude "DIALOGS\hardouin aufort_dialog.h"
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
			
			dialog.snd = "Voice\HAAU\HAAU001";
			Dialog.Text = DLG_TEXT[0] + NPChar.name + " " + NPChar.Lastname + DLG_TEXT[1];
			Link.l1 = DLG_TEXT[2] + PChar.name + " " + PChar.lastname + DLG_TEXT[3];
			link.l1.go = "Second time";
			NextDiag.TempNode = "Second time";
		break;

		case "Second time":
			dialog.snd = "Voice\HAAU\HAAU002";
			Dialog.text = DLG_TEXT[4];
			Link.l1 = DLG_TEXT[5];
			Link.l1.go = "node_3";
			if (Characters[GetCharacterIndex("Patric Cardone")].quest.teodoro == "4")
			{
				Link.l2 = DLG_TEXT[6];
				link.l2.go = "teodoro";
			}
		break;

		case "node_3":
			dialog.snd = "Voice\HAAU\HAAU003";
			Dialog.text = DLG_TEXT[7] + Address_Form.Fra + DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "exit";
		break;

		case "teodoro":
			dialog.snd = "Voice\HAAU\HAAU004";
			Dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11] + Characters[GetCharacterIndex(DLG_TEXT[12])].name + " " + Characters[GetCharacterIndex(DLG_TEXT[13])].lastname + DLG_TEXT[14];
			link.l1.go = "teodoro_1";
		break;

		case "teodoro_1":
			dialog.snd = "Voice\HAAU\HAAU005";
			Dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go ="teodoro_2";
		break;

		case "teodoro_2":
			dialog.snd = "Voice\HAAU\HAAU006";
			Dialog.text = DLG_TEXT[17];
			Link.l1 = DLG_TEXT[18] + Characters[GetCharacterIndex(DLG_TEXT[19])].name + " " + Characters[GetCharacterIndex(DLG_TEXT[20])].lastname + DLG_TEXT[21];
			link.l1.go = "teodoro_3";
		break;

		case "teodoro_3":
			dialog.snd = "Voice\HAAU\HAAU007";
			Dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			Link.l1.go = "teodoro_4";
		break;

		case "teodoro_4":
			dialog.snd = "Voice\HAAU\HAAU008";
			Dialog.text = DLG_TEXT[24];
			Link.l1 = DLG_TEXT[25];
			link.l1.go = "teodoro_5";
		break;

		case "teodoro_5":
			dialog.snd = "Voice\HAAU\HAAU009";
			Dialog.text = DLG_TEXT[26];
			Link.l1 = DLG_TEXT[27];
			link.l1.go = "teodoro_6";
		break;

		case "teodoro_6":
			dialog.snd = "Voice\HAAU\HAAU010";
			Dialog.text = DLG_TEXT[28];
			Link.l1 = DLG_TEXT[29];
			link.l1.go = "exit";
			Characters[GetCharacterIndex("Patric Cardone")].dialog.currentnode = "Teodoro_completed";
			characters[GetCharacterIndex("Lucien Bescanceny")].location	= "none";
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode =  NextDiag.TempNode;
		break;
	}
}

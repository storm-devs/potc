//nclude "DIALOGS\milon blacque_dialog.h"
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
			Dialog.snd = "voice\MIBL\MIBL001";

			Dialog.Text = DLG_TEXT[0] + Address_Form.Fra + DLG_TEXT[1];
			Link.l1 = DLG_TEXT[2] + Pchar.ship.name + DLG_TEXT[3];
			Link.l1.go = "node_2";
			NPChar.quest.first_talk = "1";
			NextDiag.TempNode = "Second time";
		break;

		case "node_2":
			Dialog.snd = "voice\MIBL\MIBL002";
			Dialog.Text = DLG_TEXT[4];
			Link.l1 = DLG_TEXT[5];
			Link.l1.go = "node_3";
		break;

		case "node_3":
			Dialog.snd = "voice\MIBL\MIBL003";
			Dialog.Text = DLG_TEXT[6];
			Link.l1 = DLG_TEXT[7];
			Link.l1.go = "Exit";
		break;

		case "Second Time":
			Dialog.snd = "voice\MIBL\MIBL004";
			Dialog.text = DLG_TEXT[8] + Address_Form.Fra + DLG_TEXT[9];
			if (Npchar.quest.son == "letter")
			{
				link.l1 = DLG_TEXT[10];
				link.l1.go = "letter";
			}
			else 
			{
				if (Npchar.quest.son == "rescue")
				{
					link.l1 = pcharrepphrase(DLG_TEXT[11], DLG_TEXT[12]);
					link.l1.go = "rescue";
				}
				else
				{
					link.l1 = DLG_TEXT[13];
					link.l1.go = "exit";
				}
			}
			link.l2 = DLG_TEXT[14];
			link.l2.go = "exit";
		break;

		case "letter":
			Dialog.snd = "voice\MIBL\MIBL005";
			Dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "exit";
			pchar.experience = makeint(pchar.experience) + 50;
			npchar.quest.son = "letter_return";
		break;

		case "rescue":
			Dialog.snd = "voice\MIBL\MIBL006";
			Dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];
			link.l1.go = "exit";
			ChangeCharacterAddress(characterFromID("Marc Blacque"), "Falaise_de_fleur_location_01", "carpenter2");
			RemovePassenger(pchar, characterFromID("Marc Blacque"));
			ChangeCharacterReputation(pchar, 1);
			AddPartyExp(pchar, 1000);
			npchar.quest.son = "done";
			NextDiag.TempNode = "Third time";
		break;

		case "Third time":
			Dialog.snd = "voice\MIBL\MIBL006";
			Dialog.text = DLG_TEXT[19] + Address_Form.Fra + DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "exit";
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}

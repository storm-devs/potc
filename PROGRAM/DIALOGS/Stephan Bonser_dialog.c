//nclude "DIALOGS\Stephan Bonser_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag, NextDiag;
	string NPC_Meeting;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			
			if (pchar.quest.main_line == "to_rudnik" || pchar.quest.main_line == "after_library")
			{
				Dialog.snd = "voice\STBO\STBO001";
				dialog.text = DLG_TEXT[0];
				link.l1 = DLG_TEXT[1];
				link.l1.go = "kick";
			}
			else
			{
				if(NPChar.quest.meeting == "0")
				{
					Dialog.snd = "voice\STBO\STBO002";
					d.Text = DLG_TEXT[2] + address_form.eng + DLG_TEXT[3] + pchar.name + " " + pchar.lastname + DLG_TEXT[4];
					Link.l1 = pcharrepphrase(DLG_TEXT[5], DLG_TEXT[6]);
					Link.l1.go = "meeting";
					NPC_Meeting = "1"; 
				}
				else
				{
					Dialog.snd = "voice\STBO\STBO003";
					d.Text = DLG_TEXT[7];
					link.l1 = DLG_TEXT[8];
					Link.l1.go = "meeting";
				}
			}
			Diag.TempNode = "First Time";
		break;

		case "kick":
			Dialog.snd = "voice\STBO\STBO004";
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "kick_2";
		break;

		case "kick_2":
			Dialog.snd = "voice\STBO\STBO005";
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "kick_exit";
		break;

		case "kick_exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("kicked_to_mine_complete");
		break;

		case "Meeting":
			if (pchar.location.from_sea == "Redmond_shore_02")
			{
				Dialog.snd = "voice\STBO\STBO006";
				dialog.text = DLG_TEXT[13] + characters[GetCharacterIndex(DLG_TEXT[14])].name + DLG_TEXT[15];
				link.l1 = pcharrepphrase(DLG_TEXT[16], DLG_TEXT[17]);
				link.l1.go = "node_1";
			}
			else
			{
				Dialog.snd = "voice\STBO\STBO007";
				dialog.text = DLG_TEXT[18];
				link.l1 = pcharrepphrase(DLG_TEXT[19], DLG_TEXT[20]);
				link.l1.go = "exit";
			}
		break;

		case "node_1":
			Dialog.snd = "voice\STBO\STBO008";
			dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "exit";
			AddDialogExitQuest("stephan_bonser_attack")
			characters[GetCharacterIndex("Thomas O'Reily")].quest.contraband = "after_fight";
		break;
		
	}
}


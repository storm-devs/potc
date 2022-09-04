//nclude "DIALOGS\Virgile Boon_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча

	
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;
	
		case "Quest_exit":
			//------------Присоединение Вирджила Буна.
			SetCompanionIndex(Pchar, -1, GetCharacterIndex("Virgile Boon"));
			SetCharacterRemovable(&Characters[GetCharacterIndex("Virgile Boon")], false);

			Pchar.quest.Story_Blaze_and_Boon_leaving.win_condition.l1 = "location";
			Pchar.quest.Story_Blaze_and_Boon_leaving.win_condition.l1.location = "FalaisedeFleur";
			Pchar.quest.Story_Blaze_and_Boon_leaving.win_condition = "Story_Blaze_and_Boon_leaving";
			
			Diag.CurrentNode = "Third time";
			DialogExit();
			Locations[FindLocation("Falaise_de_fleur_port_01")].reload.l3.disable = 0;
		break;

		case "First time":
			Diag.TempNode = "Second time";
			NPChar.quest.meeting = "1";
			Dialog.Snd = "Dialogs\VIBO\VIBO001";
			d.Text = DLG_TEXT[0] + address_form.eng + DLG_TEXT[1];
			Link.l1 = DLG_TEXT[2] + PChar.name + DLG_TEXT[3];
			Link.l1.go = "Node_1";
		break;

		case "Node_1":
			Dialog.Snd = "Dialogs\VIBO\VIBO002";
			d.Text = DLG_TEXT[4];
			Link.l1 = DLG_TEXT[5];
			Link.l1.go = "Node_2";
		break;

		case "Node_2":
			Dialog.Snd = "Dialogs\VIBO\VIBO003";
			d.Text = DLG_TEXT[6] + Characters[GetCharacterIndex(DLG_TEXT[7])].name + " " + Characters[GetCharacterIndex(DLG_TEXT[8])].lastname + DLG_TEXT[9];
			if(CheckCharacterItem(Pchar,"Story_Gramota"))
			{
				Link.l1 = DLG_TEXT[10];
				Link.l1.go = "node_3";
			}
			else
			{
				Link.l1 = DLG_TEXT[11];
				Link.l1.go = "node_4";
			}
		break;

		case "Node_3":
			AddDialogExitQuest("Story_BoonStartTalkToTancredeAgain");
			Dialog.Snd = "Dialogs\VIBO\VIBO004";
			d.Text = DLG_TEXT[12]; 
			Link.l1 = DLG_TEXT[13];
			Link.l1.go = "exit";
			AddDialogExitQuest("Story_BoonStartTalkToTancredeAgain");
		break;

		case "Node_4":
			if(GetCharacterShipLocation(Pchar) == "Falaise_de_Fleur_port_01")
			{
				Dialog.Snd = "Dialogs\VIBO\VIBO005";
				d.Text = DLG_TEXT[14];
				Link.l1 = DLG_TEXT[15];
				Link.l1.go = "Quest_exit";
			}
			else
			{
				Dialog.Snd = "Dialogs\VIBO\VIBO006";
				d.Text = DLG_TEXT[16];
				Link.l1 = DLG_TEXT[17];
				Link.l1.go = "Node_no_ship";
			}
		break;

		case "Node_no_ship":
			Dialog.Snd = "Dialogs\VIBO\VIBO007";
			d.Text = DLG_TEXT[18];
			Link.l1 = DLG_TEXT[19];
			Link.l1.go = "Exit";
			AddDialogExitQuest("Story_BoonStartTalkToTancredeAgain");
		break;

		case "Second Time_NotMet":
			Dialog.Snd = "Dialogs\VIBO\VIBO008";
			d.Text = DLG_TEXT[20] + address_form.fra + DLG_TEXT[21];
			Link.l1 = DLG_TEXT[22] + Characters[GetCharacterIndex(DLG_TEXT[23])].name + " " + Characters[GetCharacterIndex(DLG_TEXT[24])].lastname + DLG_TEXT[25];
			Link.l1.go = "Second Time_NotMet_1";
		break;

		case "Second Time_NotMet_1":
			d.Text = DLG_TEXT[26];
			Dialog.Snd = "Dialogs\VIBO\VIBO009";
			Link.l1 = DLG_TEXT[27] + Pchar.name + DLG_TEXT[28];
			Link.l1.go = "Second Time_NotMet_2";
		break;

		case "Second Time_NotMet_2":
			Dialog.Snd = "Dialogs\VIBO\VIBO010";
			d.Text = DLG_TEXT[29];
			Link.l1 = DLG_TEXT[30];
			Link.l1.go = "Second Time_NotMet_3";
		break;

		case "Second Time_NotMet_3":
			Dialog.Snd = "Dialogs\VIBO\VIBO011";
			d.Text = DLG_TEXT[31] + Characters[GetCharacterIndex(DLG_TEXT[32])].name + " " + Characters[GetCharacterIndex(DLG_TEXT[33])].lastname + DLG_TEXT[34];
			Link.l1 = DLG_TEXT[35];
			Link.l1.go = "Node_4";
		break;

		case "Second Time":
			Dialog.Snd = "Dialogs\VIBO\VIBO012";
			d.Text = DLG_TEXT[36];
			if(CheckCharacterItem(Pchar,"Story_Gramota"))
			{
				Link.l1 = DLG_TEXT[37];
				Link.l1.go = "node_5";
			}
			else
			{
				Link.l1 = DLG_TEXT[38];
				Link.l1.go = "node_4";
			}
		break;
	
		case "Node_5":
			Dialog.Snd = "Dialogs\VIBO\VIBO013";
			d.Text = DLG_TEXT[39];
			Link.l1 = DLG_TEXT[40] + Characters[GetCharacterIndex(DLG_TEXT[41])].name + DLG_TEXT[42];
			Link.l1.go = "exit";
			AddDialogExitQuest("Story_BoonStartTalkToTancredeAgain");
		break;
	
		case "Third time":
			Dialog.Snd = "Dialogs\VIBO\VIBO014";
			d.Text = DLG_TEXT[43];
			Link.l1 = DLG_TEXT[44];
			Link.l1.go = "exit";
			AddDialogExitQuest("Story_BoonStartTalkToTancredeAgain");
		break;
	


		}
}


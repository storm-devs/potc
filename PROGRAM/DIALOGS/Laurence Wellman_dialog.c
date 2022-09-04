//nclude "DIALOGS\Laurence Wellman_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_meeting;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);
	
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
			Dialog.snd = "dialogs\0\009";
			Diag.TempNode = "first time";

			if(NPChar.quest.meeting == "0")
			{
				NPC_meeting = "1";
				d.Text = DLG_TEXT[0] + address_form.eng + DLG_TEXT[1];
				Link.l1 = DLG_TEXT[2] + PChar.name + DLG_TEXT[3] + PChar.ship.name + DLG_TEXT[4];
			}
			else
			{
				dialog.snd1 = "";
				dialog.snd2 = "";
				dialog.snd3 = "";
				d.Text = RandPhrase(DLG_TEXT[5] + address_form.eng + DLG_TEXT[6], DLG_TEXT[7] + Pchar.name + DLG_TEXT[8], DLG_TEXT[9] + PChar.name + DLG_TEXT[10], &dialog, dialog.snd1, dialog.snd2, dialog.snd3);
				Link.l1 = DLG_TEXT[11];
			}
			Link.l1.go = "node_2";
		break;

		case "node_2":
			d.Text = DLG_TEXT[12] + PChar.name + DLG_TEXT[13];
			Link.l1 = DLG_TEXT[14];
			Link.l1.go = "node_3";
			Link.l2 = DLG_TEXT[15];
			Link.l2.go = "node_work";
			if(characters[GetCharacterIndex("Rys Bloom")].quest.help == "agreed")
			{
				Link.l3 = DLG_TEXT[16];
				Link.l3.go = "Node_Rys";
			}
		break;

		case "node_3":
			d.Text = DLG_TEXT[17];
			Link.l1 = DLG_TEXT[18];
			Link.l1.go = "node_4";
			Link.l2 = DLG_TEXT[19];
			Link.l2.go = "node_work";
			Link.l3 = DLG_TEXT[20];
			Link.l3.go = "exit";
		break;

		case "node_4":
			d.Text = DLG_TEXT[21];
			Link.l1 = DLG_TEXT[22];
			Link.l1.go = "exit";
			Link.l2 = DLG_TEXT[23];
			Link.l2.go = "node_work";
			
		break;

		case "node_work":
			if(NPChar.quest.meeting == "0")
			{
				d.Text = DLG_TEXT[24] + PChar.name + DLG_TEXT[25];
			}
			else
			{
				d.Text = DLG_TEXT[26] + PChar.name + DLG_TEXT[27];
			}
			Link.l1 = DLG_TEXT[28];
			Link.l1.go = "node_3";
			Link.l2 = DLG_TEXT[29];
			Link.l2.go = "node_work_1";
			if(characters[GetCharacterIndex("Rys Bloom")].quest.help == "agreed")
			{
				Link.l3 = DLG_TEXT[30];
				Link.l3.go = "Node_Rys";
			}
		break;

		case "node_work_1":
			d.Text = DLG_TEXT[31];
			Link.l1 = DLG_TEXT[32];
			Link.l1.go = "node_3";
			if(characters[GetCharacterIndex("Rys Bloom")].quest.help == "agreed")
			{
				Link.l2 = DLG_TEXT[33];
				Link.l2.go = "Node_Rys";
			}
			Link.l3 = DLG_TEXT[34];
			Link.l3.go = "exit";
		break;

		case "node_Rys":
			d.Text = DLG_TEXT[35];
			Link.l1 = DLG_TEXT[36];
			Link.l1.go = "node_Rys Bloom_2";
			Link.l2 = DLG_TEXT[37];
			Link.l2.go = "node_Rys Bloom_3";
			Link.l3 = DLG_TEXT[38];
			Link.l3.go = "node_2";
		break;

		case "node_Rys Bloom_2":
			d.Text = DLG_TEXT[39];
			Link.l1 = DLG_TEXT[40];
			Link.l1.go = "node_Rys Bloom_3";
			Link.l2 = DLG_TEXT[41];
			Link.l2.go = "node_2";
		break;

		case "node_Rys Bloom_3":
			d.Text = DLG_TEXT[42];
			Link.l1 = DLG_TEXT[43];
			Link.l1.go = "node_Rys Bloom_4";
			Link.l2 = DLG_TEXT[44];
			Link.l2.go = "exit";
		break;

		case "node_Rys Bloom_4":
			d.Text = DLG_TEXT[45] + PChar.name + DLG_TEXT[46];
			Link.l1 = DLG_TEXT[47];
			if(makeint(PChar.reputation)>=6)
			{
				Link.l1.go = "node_Rys Bloom_5";
			}
			else
			{
				Link.l1.go = "node_Rys Bloom_6";
			}

			Link.l2 = DLG_TEXT[48];
			Link.l2.go = "node_2";
		break;

		case "node_Rys Bloom_5":
			Characters[GetCharacterIndex("Rys Bloom")].quest.help = "done";
			characters[GetCharacterIndex("Rys Bloom")].dialog.currentnode = "Help_succesful";
			d.Text = DLG_TEXT[49];
			Link.l1 = DLG_TEXT[50];
			Link.l1.go = "exit";
			Link.l2 = DLG_TEXT[51];
			Link.l2.go = "node_2";
		break;

		case "node_Rys Bloom_6":
			Characters[GetCharacterIndex("Rys Bloom")].quest.help = "failed";
			d.Text = DLG_TEXT[52] + address_form.eng + DLG_TEXT[53];
			Link.l1 = DLG_TEXT[54];
			Link.l1.go = "exit";
			Link.l2 = DLG_TEXT[55];
			Link.l2.go = "node_2";
		break;

		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_meeting;
			DialogExit();
		break;
		
	}
}

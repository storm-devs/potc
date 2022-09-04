//nclude "DIALOGS\Smuggler Agent_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d, her;
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_Meeting;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча

		case "Smuggling_exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;

			PlaceSmugglersOnShore(Pchar.quest.contraband.CurrentPlace);
			Pchar.quest.Contraband.active = true;

			DialogExit();
			trace("And once again That REALLY Sucks!!" + Pchar.quest.contraband.CurrentPlace);
		break;
		
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

		case "First time":			
			
			//trace(SelectSmugglingLocation());
			if(NPChar.quest.meeting == "0")
			{
				Dialog.snd = "voice\SMAG\SMAG001";
				d.Text = DLG_TEXT[0];
				Link.l1 = PCharPhrase(DLG_TEXT[1] + Pchar.name + " " + Pchar.lastname + DLG_TEXT[2], DLG_TEXT[3] + Pchar.name + " " + Pchar.lastname + DLG_TEXT[4] + Pchar.ship.name + DLG_TEXT[5]);
				Link.l1.go = "meeting";
				NPC_Meeting = "1"; 
			}
			else
			{
				Dialog.snd = "voice\SMAG\SMAG002";
				d.Text = DLG_TEXT[6];
				if(FindFirstContrabandGoods(PChar) != -1)
				{
					Link.l1 = DLG_TEXT[7];
					Link.l1.go = "Meeting_3";
				}
				Link.l2 = DLG_TEXT[8];
				Link.l2.go = "Exit";				
			}
		break;

		case "Meeting":
			Dialog.snd = "voice\SMAG\SMAG003";
			d.Text = DLG_TEXT[9];
			if(FindFirstContrabandGoods(PChar) != -1)
			{
				Link.l1 = DLG_TEXT[10];
				Link.l1.go = "Meeting_1";
			}
			Link.l2 = DLG_TEXT[11];
			Link.l2.go = "Exit";				
		break;

		case "Meeting_1":
			Dialog.snd = "voice\SMAG\SMAG004";
			d.Text = DLG_TEXT[12];
			Link.l1 = DLG_TEXT[13];
			Link.l1.go = "Meeting_2";				
			Link.l2 = DLG_TEXT[14];
			Link.l2.go = "exit";				
		break;

		case "Meeting_2":
			Dialog.snd = "voice\SMAG\SMAG005";
			d.Text = DLG_TEXT[15];
			Link.l1 = DLG_TEXT[16];
			Link.l1.go = "Meeting_3";				
		break;

		case "Meeting_3":
			if(CheckAttribute(Pchar, "quest.Contraband.Active") && Pchar.quest.Contraband.Active == true)
			{
				Dialog.snd = "voice\SMAG\SMAG006";				
				d.Text = DLG_TEXT[17];
				Link.l1 = DLG_TEXT[18];
				Link.l1.go = "Exit";				
			}
			else
			{
				Dialog.snd = "voice\SMAG\SMAG007";
				Pchar.quest.contraband.CurrentPlace = SelectSmugglingLocation();				
				d.Text = DLG_TEXT[19] + LanguageConvertString(g_LocLngFileID,locations[FindLocation(Pchar.quest.contraband.CurrentPlace)].id.label) + DLG_TEXT[20];
				Link.l1 = DLG_TEXT[21];
				Link.l1.go = "Smuggling_exit";
			}
		break;


				

	}
}
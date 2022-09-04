//nclude "DIALOGS\Leonardo Violate_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_Meeting;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);
	
	string iDay, iMonth;
	iDay = environment.date.day;
	iMonth = environment.date.month;
	string lastspeak_date = iday + " " + iMonth;
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

		case "trade":
			d.Text = DLG_TEXT[0];
			Link.l1 = DLG_TEXT[1];
			Link.l1.go = "trade_1";
			Link.l2 = DLG_TEXT[2];
			Link.l2.go = "items";
			Link.l3 = DLG_TEXT[3];
			Link.l3.go = "exit";
		break;

		case "trade_1":
			//Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
			LaunchStore(SMUGGLERS_STORE);
		break;

		case "items":
			//Diag.CurrentNode = Diag.TempNode;
			//NPChar.quest.meeting = NPC_Meeting;
			if (npchar.quest.Meeting != lastspeak_date)
			{
				GiveItemToTrader(npchar);
				npchar.quest.Meeting = lastspeak_date;
			}
			
			DialogExit();
			LaunchItemsTrade(NPChar);
		break;

		case "First time":
			Dialog.defAni = "dialog_stay2";
			Dialog.defCam = "2";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";

			if(NPChar.quest.meeting == "0")
			{
				d.Text = DLG_TEXT[4] + address_form.eng + DLG_TEXT[5];
				Link.l1 = DLG_TEXT[6] + Pchar.name + " " + Pchar.lastname + DLG_TEXT[7];
				Link.l1.go = "meeting";
				NPC_Meeting = "1"; 
			}
			else
			{
				dialog.snd1 = "";
				dialog.snd2 = "";
				dialog.snd3 = "";
				d.Text = RandPhrase(TimeGreeting() + DLG_TEXT[8] + address_form.eng + " " + DLG_TEXT[9] + PChar.name + DLG_TEXT[10], DLG_TEXT[11] + PChar.name + DLG_TEXT[12], DLG_TEXT[13], &dialog, dialog.snd1, dialog.snd2, dialog.snd3);
				Link.l1 = DLG_TEXT[14];
				Link.l1.go = "trade";
				Link.l2 = DLG_TEXT[15];
				Link.l2.go = "quest lines";
				Link.l3 = DLG_TEXT[16];
				Link.l3.go = "exit";
			}
		break;

		case "Meeting":
			d.Text = DLG_TEXT[17] + NPChar.name + " " + NPChar.lastname + DLG_TEXT[18];
			Link.l1 = DLG_TEXT[19] + NPChar.name + DLG_TEXT[20];
			Link.l1.go = "trade";
			Link.l2 = DLG_TEXT[21] + NPChar.name + DLG_TEXT[22];
			Link.l2.go = "quest lines";
			Link.l3 = DLG_TEXT[23];
			Link.l3.go = "exit";
		break;

		case "quest lines":
			d.Text = DLG_TEXT[24];
			Link.l99 = DLG_TEXT[25];
			Link.l99.go = "no quest";
		break;

		case "No quest":
				d.Text = DLG_TEXT[26] + address_Form.eng + " " + PChar.name + DLG_TEXT[27];
				Link.l1 = DLG_TEXT[28];
				Link.l1.go = "trade";
				Link.l2 = DLG_TEXT[29];
				Link.l2.go = "exit";
		break;

		case "No trade":
				d.Text = DLG_TEXT[30] + address_Form.eng + " " + PChar.name + DLG_TEXT[31];
				Link.l1 = DLG_TEXT[32];
				Link.l1.go = "No quest";
		break;
				

	}
}
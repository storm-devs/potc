//nclude "DIALOGS\David Fairweather_dialog.h"
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
		case "First time":
			Dialog.defAni = "Gov_Dialog_1";
			Dialog.ani = "Gov_Dialog_2";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.cam = "1";

			if(NPChar.quest.meeting == "0")
			{
				dialog.snd = "Voice\DAFA\DAFA001";
				d.Text = TimeGreeting() + DLG_TEXT[0] + NPChar.name + " " + NPChar.lastname + DLG_TEXT[1];
				Link.l1 = DLG_TEXT[2] + Pchar.name + " " + Pchar.lastname + DLG_TEXT[3] + PChar.Ship.name + DLG_TEXT[4];
				Link.l1.go = "meeting";
				npchar.quest.Meeting = "1"; 
			}
			else
			{
				dialog.snd = "Voice\DAFA\DAFA002";
				d.Text = TimeGreeting() + DLG_TEXT[5] + PChar.name + DLG_TEXT[6] + address_form.eng + DLG_TEXT[7];
				Link.l1 = DLG_TEXT[8];
				Link.l1.go = "Shipyard";
				Link.l2 = DLG_TEXT[9];
				Link.l2.go = "quest lines";
				Link.l3 = DLG_TEXT[10];
				Link.l3.go = "exit";
			}
		break;

		case "Meeting":
			dialog.snd = "Voice\DAFA\DAFA003";
				d.Text = DLG_TEXT[11];
				Link.l1 = DLG_TEXT[12] + NPChar.name +DLG_TEXT[13];
				Link.l1.go = "Shipyard";
				Link.l2 = DLG_TEXT[14];
				Link.l2.go = "quest lines";
				Link.l3 = DLG_TEXT[15];
				Link.l3.go = "exit";
		break;

		case "quest lines":
			dialog.snd = "Voice\DAFA\DAFA004";
				d.Text = DLG_TEXT[16] + PChar.name + DLG_TEXT[17];
				Link.l1 = DLG_TEXT[18];
				Link.l1.go = "no quest";
		break;

		case "No quest":
			dialog.snd = "Voice\DAFA\DAFA005";
				d.Text = DLG_TEXT[19] + PChar.name + DLG_TEXT[20];
				Link.l1 = DLG_TEXT[21];
				Link.l1.go = "Shipyard";
				Link.l2 = DLG_TEXT[22];
				Link.l2.go = "exit";
		break;

		case "shipyard":
			dialog.snd = "Voice\DAFA\DAFA006";
				d.Text = DLG_TEXT[23];
				Link.l1 = DLG_TEXT[24];
				Link.l1.go = "SHIPYARD_interface";
				Link.l2 = DLG_TEXT[25];
				Link.l2.go = "Cannons_interface";
				Link.l3 = DLG_TEXT[26];
				Link.l3.go = "no quest";
		break;

		case "SHIPYARD_interface":
			if (npchar.quest.Meeting != lastspeak_date)
			{
				int iTest_ship;

				DeleteAttribute(npchar, "shipyard");
			
				npchar.shipyard.ship1 = SHIP_TARTANE;

				iTest_ship = rand(2);
				if (iTest_ship == 1)
				{
					npchar.shipyard.ship2 = SHIP_BARQUE_ENGLAND;
				}
				if (iTest_ship == 2) 
				{
					npchar.shipyard.ship2 = SHIP_BARQUE2_ENGLAND;
				}

				iTest_ship = rand(2);
				if (iTest_ship == 1) npchar.shipyard.ship3 = SHIP_YACHT_ENGLAND;
				if (iTest_ship == 2) npchar.shipyard.ship3 = SHIP_YACHT2_ENGLAND;
				
				iTest_ship = rand(2);
				if (iTest_ship == 1) npchar.shipyard.ship4 = SHIP_LUGGER_ENGLAND;
				if (iTest_ship == 2) npchar.shipyard.ship4 = SHIP_LUGGER2_ENGLAND;

				iTest_ship = rand(3);
				if (iTest_ship == 1) npchar.shipyard.ship5 = SHIP_SLOOP_ENGLAND;
				if (iTest_ship == 2) npchar.shipyard.ship5 = SHIP_SLOOP2_ENGLAND;
				
				iTest_ship = rand(3);
				if (iTest_ship == 1) npchar.shipyard.ship6 = SHIP_GALEOTH_ENGLAND;
				if (iTest_ship == 2) npchar.shipyard.ship6 = SHIP_GALEOTH2_ENGLAND;
		
				iTest_ship = rand(3);
				if (iTest_ship == 1) npchar.shipyard.ship7 = SHIP_XEBEC_ENGLAND;
				if (iTest_ship == 2)npchar.shipyard.ship7 = SHIP_XEBEC2_ENGLAND;
				
				iTest_ship = rand(4);
				if (iTest_ship == 1) npchar.shipyard.ship8 = SHIP_SCHOONER_ENGLAND;
				if (iTest_ship == 2) npchar.shipyard.ship8 = SHIP_SCHOONER2_ENGLAND;
				
				iTest_ship = rand(4);
				if (iTest_ship == 1) npchar.shipyard.ship9 = SHIP_CARAVEL_ENGLAND;
				if (iTest_ship == 2) npchar.shipyard.ship9 = SHIP_CARAVEL2_ENGLAND;
				
				iTest_ship = rand(4);
				if (iTest_ship == 1) npchar.shipyard.ship10 = SHIP_FLEUT_ENGLAND;
				if (iTest_ship == 2) npchar.shipyard.ship10 = SHIP_FLEUT2_ENGLAND;

				npchar.quest.Meeting = lastspeak_date;
			}
			DialogExit();
			LaunchShipyard(npchar);
		break;

		case "CANNONS_interface":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			LaunchCannons();
		break;

		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;
		
	}
}
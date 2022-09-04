//nclude "DIALOGS\Lambrecht Fobes_dialog.h"
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
			Dialog.snd = "dialogs\0\009";

			if(NPChar.quest.meeting == "0")
			{
				d.Text = TimeGreeting() + DLG_TEXT[0] + NPChar.name + " " + NPChar.lastname + DLG_TEXT[1];
				Link.l1 = DLG_TEXT[2] + Pchar.name + " " + Pchar.lastname + DLG_TEXT[3] + PChar.Ship.name + DLG_TEXT[4];
				Link.l1.go = "meeting";
				NPChar.quest.meeting = "1"; 
			}
			else
			{
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
				d.Text = DLG_TEXT[11];
				Link.l1 = DLG_TEXT[12] + NPChar.name +DLG_TEXT[13];
				Link.l1.go = "Shipyard";			
				Link.l2 = DLG_TEXT[14];
				Link.l2.go = "quest lines";
				Link.l3 = DLG_TEXT[15];
				Link.l3.go = "exit";
		break;

		case "quest lines":
				d.Text = DLG_TEXT[16]+ PChar.name + DLG_TEXT[17];
				Link.l1 = DLG_TEXT[18];
				Link.l1.go = "no quest";
		break;

		case "No quest":
				d.Text = DLG_TEXT[19] + PChar.name + DLG_TEXT[20];
				Link.l1 = DLG_TEXT[21];
				Link.l1.go = "Shipyard";
				Link.l2 = DLG_TEXT[22];
				Link.l2.go = "exit";
		break;

		case "shipyard":
				d.Text = DLG_TEXT[23];
				Link.l1 = DLG_TEXT[24];
				Link.l1.go = "SHIPYARD_interface";
				Link.l2 = DLG_TEXT[25];
				Link.l2.go = "Cannons_interface";
				Link.l3 = DLG_TEXT[26];
				Link.l3.go = "no quest";
		break;

		case "SHIPYARD_interface":
			Diag.CurrentNode = Diag.TempNode;
			
			if (npchar.quest.Meeting != lastspeak_date)
			{
				int iTest_ship;

				DeleteAttribute(npchar, "shipyard");
			
				npchar.shipyard.ship1 = SHIP_TARTANE;

				iTest_ship = rand(2);
				if (iTest_ship == 1)
				{
					npchar.shipyard.ship2 = SHIP_BARQUE_HOLLAND;
				}
				if (iTest_ship == 2) 
				{
					npchar.shipyard.ship2 = SHIP_BARQUE2_HOLLAND;
				}

				iTest_ship = rand(2);
				if (iTest_ship == 1) npchar.shipyard.ship3 = SHIP_YACHT_HOLLAND;
				if (iTest_ship == 2) npchar.shipyard.ship3 = SHIP_YACHT2_HOLLAND;
				
				iTest_ship = rand(2);
				if (iTest_ship == 1) npchar.shipyard.ship4 = SHIP_LUGGER_HOLLAND;
				if (iTest_ship == 2) npchar.shipyard.ship4 = SHIP_LUGGER2_HOLLAND;

				iTest_ship = rand(3);
				if (iTest_ship == 1) npchar.shipyard.ship5 = SHIP_SLOOP_HOLLAND;
				if (iTest_ship == 2) npchar.shipyard.ship5 = SHIP_SLOOP2_HOLLAND;
				
				iTest_ship = rand(3);
				if (iTest_ship == 1) npchar.shipyard.ship6 = SHIP_GALEOTH_HOLLAND;
				if (iTest_ship == 2) npchar.shipyard.ship6 = SHIP_GALEOTH2_HOLLAND;
		
				iTest_ship = rand(3);
				if (iTest_ship == 1) npchar.shipyard.ship7 = SHIP_XEBEC_HOLLAND;
				if (iTest_ship == 2)npchar.shipyard.ship7 = SHIP_XEBEC2_HOLLAND;
				
				iTest_ship = rand(4);
				if (iTest_ship == 1) npchar.shipyard.ship8 = SHIP_SCHOONER_HOLLAND;
				if (iTest_ship == 2) npchar.shipyard.ship8 = SHIP_SCHOONER2_HOLLAND;
				
				iTest_ship = rand(4);
				if (iTest_ship == 1) npchar.shipyard.ship9 = SHIP_CARAVEL_HOLLAND;
				if (iTest_ship == 2) npchar.shipyard.ship9 = SHIP_CARAVEL2_HOLLAND;
				
				iTest_ship = rand(4);
				if (iTest_ship == 1) npchar.shipyard.ship10 = SHIP_FLEUT_HOLLAND;
				if (iTest_ship == 2) npchar.shipyard.ship10 = SHIP_FLEUT2_HOLLAND;
				
				iTest_ship = rand(5);
				if (iTest_ship == 1) npchar.shipyard.ship11 = SHIP_PINNACE_HOLLAND;
				if (iTest_ship == 2) npchar.shipyard.ship11 = SHIP_PINNACE2_HOLLAND;
				
				iTest_ship = rand(5);
				if (iTest_ship == 1) npchar.shipyard.ship12 = SHIP_BRIG_HOLLAND;
				if (iTest_ship == 2) npchar.shipyard.ship12 = SHIP_BRIG2_HOLLAND;
				
				iTest_ship = rand(5);
				if (iTest_ship == 1) npchar.shipyard.ship13 = SHIP_GALEON_HOLLAND;
				if (iTest_ship == 2) npchar.shipyard.ship13 = SHIP_GALEON2_HOLLAND;

				iTest_ship = rand(6);
				if (iTest_ship == 1) npchar.shipyard.ship14 = SHIP_CORVETTE_HOLLAND;
				if (iTest_ship == 2) npchar.shipyard.ship14 = SHIP_CORVETTE2_HOLLAND;

				iTest_ship = rand(6);
				if (iTest_ship == 1) npchar.shipyard.ship15 = SHIP_FRIGATE_HOLLAND;
				if (iTest_ship == 2) npchar.shipyard.ship15 = SHIP_FRIGATE2_HOLLAND;

				iTest_ship = rand(7);
				if (iTest_ship == 1) npchar.shipyard.ship16 = SHIP_BATTLESHIP_HOLLAND;
				if (iTest_ship == 2) npchar.shipyard.ship16 = SHIP_BATTLESHIP2_HOLLAND;

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

		case "continue":
			if (NPC_Meeting == "1")
			{
				d.Text = DLG_TEXT[27] + Pchar.name + DLG_TEXT[28];
				Link.l1 = DLG_TEXT[29];
				Link.l1.go = "continue1";
			}
			else
			{
				d.Text = DLG_TEXT[30];
				Link.l1 = DLG_TEXT[31];
				Link.l1.go = "continue1";
			}
		break;

		case "continue1":
			NPC_Meeting = "1"; 
			d.Text = DLG_TEXT[32];
			Link.l1 = DLG_TEXT[33];
			Link.l1.go = "continue3";
			Link.l2 = DLG_TEXT[34];
			Link.l2.go = "exit1";
			
			if(makeint(PChar.skill.leadership) > 200)
			{
				d.Text = DLG_TEXT[35];
				Link.l1 = DLG_TEXT[36];
				Link.l1.go = "exit2";
			}
		break;

		case "continue2":
			d.Text = PCharPhrase(DLG_TEXT[37], DLG_TEXT[38] + address_form.eng + DLG_TEXT[39]);
			Link.l1 = DLG_TEXT[40] + NPChar.name +DLG_TEXT[41];
			if(CheckAttribute(Pchar, "Quest.Story_OxbayCaptured"))
			{
				Link.l1.go = "No ships";
			}
			else
			{
				Link.l1.go = "Shipyard";
			}			
			Link.l2 = DLG_TEXT[42];
			Link.l2.go = "quest lines";
			Link.l3 = DLG_TEXT[43];
			Link.l3.go = "continue3";
			Link.l4 = DLG_TEXT[44];
			Link.l4.go = "exit";
		break;

		case "continue3":
			AddDialogExitQuest("change_clauss_adress");
			Diag.CurrentNode = "First time";
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

		case "exit2":
			Pchar.quest.pirate_fort.win_condition.l1 = "location";
			Pchar.quest.pirate_fort.win_condition.l1.character = "Blaze";
			Pchar.quest.pirate_fort.win_condition.l1.location = "Pirate_fort";
			Pchar.quest.pirate_fort.win_condition = "Pirates_vs_Blaze";
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

		case "exit1":
			Diag.CurrentNode = "continue2";
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;		
	}
}
//nclude "DIALOGS\patric cardone_dialog.h"
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
	
	string iDay, iMonth;
	iDay = environment.date.day;
	iMonth = environment.date.month;
	string lastspeak_date = iday + " " + iMonth;

	if (NPChar.quest.teodoro == "2")
	{
		Dialog.CurrentNode = "TeodoroQuestDone";
	}
	if (NPChar.quest.teodoro == "3")
	{
		Dialog.CurrentNode = "TeodoroLie";
	}


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

			Dialog.Text = DLG_TEXT[0];
			Link.l1 = DLG_TEXT[1];
			Link.l1.go = "node_1";
			NextDiag.tempNode = "First time";
		break;

		case "node_1":
			Dialog.Text = DLG_TEXT[2];
			Link.l1 = DLG_TEXT[3];
			Link.l1.go = "node_2";
			Link.l2 = DLG_TEXT[4];
			Link.l2.go = "exit";
		break;

		case "node_2":
			Dialog.Text = DLG_TEXT[5];
			Link.l1 = DLG_TEXT[6];
			Link.l1.go = "node_3";
			Link.l2 = DLG_TEXT[7];
			Link.l2.go = "exit";
		break;

		case "node_3":
			Dialog.Text = DLG_TEXT[8] + Address_Form.Fra + DLG_TEXT[9];
			Link.l1 = DLG_TEXT[10];
			Link.l1.go = "node_4";
			Link.l2 = DLG_TEXT[11];
			Link.l2.go = "exit";
			NextDiag.TempNode = "Second Time";
		break;

		case "node_4":
			Dialog.Text = DLG_TEXT[12];
			Link.l1 = DLG_TEXT[13] + PChar.Name + " " + PChar.Lastname + DLG_TEXT[14];
			Link.l1.go = "node_5";
		break;

		case "node_5":
			Dialog.Text = DLG_TEXT[15] + NPChar.name + " " + NPChar.lastname + DLG_TEXT[16];
			Link.l1 = DLG_TEXT[17] + NPChar.name + DLG_TEXT[18];
			Link.l1.go = "node_6";
			Link.l2 = DLG_TEXT[19];
			Link.l2.go = "exit";
		break;

		case "node_6":
			Dialog.Text = DLG_TEXT[20] + Address_Form.Fra +DLG_TEXT[21];
			Link.l1 = DLG_TEXT[22];
			Link.l1.go = "node_7";
			Link.l2 = DLG_TEXT[23];
			Link.l2.go = "exit";
		break;

		case "node_7":
			Dialog.text = DLG_TEXT[24];
			Link.l1 = DLG_TEXT[25];
			Link.l1.go = "node_8";
			Link.l2 = DLG_TEXT[26];
			Link.l2.go = "exit";
		break;

		case "node_8":
			Dialog.Text = DLG_TEXT[27] + Characters[GetCharacterIndex(DLG_TEXT[28])].name + " " + Characters[GetCharacterIndex(DLG_TEXT[29])].lastname + DLG_TEXT[30];
			Link.l1 = DLG_TEXT[31];
			Link.l1.go = "node_11";
		break;

		case "node_11":
			Dialog.Text = DLG_TEXT[32];
			Link.l1 = DLG_TEXT[33];
			Link.l1.go = "node_12";
			Link.l2 = DLG_TEXT[34];
			Link.l2.go = "node_13";
		break;

		case "node_12":
			Dialog.Text = DLG_TEXT[35];
			Link.l1 = DLG_TEXT[36];
			Link.l1.go = "node_13";
		break;

		case "node_13":
			Dialog.text = DLG_TEXT[37] + Characters[GetCharacterIndex(DLG_TEXT[38])].name + DLG_TEXT[39];
			Link.l1 = DLG_TEXT[40];
			Link.l1.go = "node_14";
		break;

		case "node_14":
			Dialog.text = DLG_TEXT[41];
			Link.l1 = DLG_TEXT[42] + Characters[GetCharacterIndex(DLG_TEXT[43])].name + DLG_TEXT[44];
			Link.l1.go = "node_15";
			Link.l2 = DLG_TEXT[45] + NPChar.name + DLG_TEXT[46];
			Link.l2.go = "exit";
		break;

		case "node_15":
			Dialog.text = DLG_TEXT[47];
			Link.l1 = DLG_TEXT[48];
			Link.l1.go = "node_16";
		break;

		case "node_16":
			Dialog.text = DLG_TEXT[49] + Characters[GetCharacterIndex(DLG_TEXT[50])].name + DLG_TEXT[51];
			Link.l1 = DLG_TEXT[52];
			Link.l1.go = "node_17";
			Link.l2 = DLG_TEXT[53];
			Link.l2.go ="node_18";
		break;

		case "node_17":
			Dialog.text = DLG_TEXT[54] + Address_Form.Fra + DLG_TEXT[55];
			Link.l1 = DLG_TEXT[56];
			Link.l1.go = "node_17_1";
			Link.l2 = DLG_TEXT[57];
			Link.l2.go = "exit;"
		break;

		case "node_17_1":
			Dialog.text = DLG_TEXT[58];
			Link.l1 = DLG_TEXT[59];
			Link.l1.go = "node_19";
		break;

		case "node_18":
			Dialog.text = DLG_TEXT[60];
			Link.l1 = DLG_TEXT[61];
			Link.l1.go = "node_19";
		break;

		case "node_19":
			Dialog.text = DLG_TEXT[62];
			Link.l1 = DLG_TEXT[63];
			Link.l1.go = "node_20";
			Link.l2 = DLG_TEXT[64];
			Link.l2.go = "node_21";
		break;

		case "node_20":
			if (makeint(PChar.skill.Commerce) > 2)
			{
				Dialog.text = DLG_TEXT[65];
				Link.l1 = DLG_TEXT[66] + Characters[GetCharacterIndex(DLG_TEXT[67])].name + DLG_TEXT[68];
				Link.l1.go = "node_21_1";
				NPChar.money.quest = "5000";
			}
			else
			{
				Dialog.text = DLG_TEXT[69];
				Link.l1 = DLG_TEXT[70];
				Link.l1.go = "node_20_1";
			}
		break;

		case "node_20_1":
			Dialog.text = DLG_TEXT[71];
			Link.l1 = DLG_TEXT[72];
			Link.l1.go = "exit";
			Link.l2 = DLG_TEXT[73];
			Link.l2.go = "node_21";
		break;

		case "node_21":
			Dialog.Text = DLG_TEXT[74] + Address_Form.Fra + DLG_TEXT[75];
			Link.l1 = DLG_TEXT[76];
			Link.l1.go = "node_21_1";
			NPChar.quest.teodoro = "1";
			NPChar.money.quest = "3000";
		break;

		case "node_21_1":
			Dialog.text = DLG_TEXT[77];
			Link.l1 = DLG_TEXT[78];
			Link.l1.go = "exit";
		break;

		////////////////////////////////////////////////////////////////////
		// второй разговор.
		////////////////////////////////////////////////////////////////////

		case "Second Time":
			Dialog.Text = DLG_TEXT[79] + Address_Form.Fra + DLG_TEXT[80];
			Link.l1 = DLG_TEXT[81];
			Link.l1.go = "node_22";
			if (NPChar.quest.teodoro == "1")
			{
				Dialog.text = DLG_TEXT[82] + Address_Form.Fra + DLG_TEXT[83];
				Link.l1 = DLG_TEXT[84];
				Link.l1.go = "exit";
			}
			if (npchar.quest.teodoro == "4")
			{
				if (characters[GetCharacterIndex("Raoul Calmes")].quest.visit == "0")
				{
					dialog.text = DLG_TEXT[85] + Characters[GetCharacterIndex(DLG_TEXT[86])].name + DLG_TEXT[87];
					link.l1 = DLG_TEXT[88];
					link.l1.go = "exit";
					characters[GetCharacterIndex("Raoul Calmes")].quest.visit = "1";
				}
			}
		break;

		case "node_22":
			Dialog.Text = DLG_TEXT[89];
			Link.l1 = DLG_TEXT[90];
			Link.l1.go = "Items";
			Link.l2 = DLG_TEXT[91];
			Link.l2.go = "exit";
		break;

		//Руморсы
		case "Rumours":
			Dialog.text = SelectRumour();
			Link.l1 = DLG_TEXT[92];
			Link.l1.go = "exit";
			Link.l2 = DLG_TEXT[93];
			Link.l2.go = "node_23";
		break;


		// выполнение квеста.
		case "Teodoro_completed":
			Dialog.Text = DLG_TEXT[94] + Address_Form.Fra + DLG_TEXT[95]; 
			Link.l1 = DLG_TEXT[96];
			Link.l1.go = "exit";
			ChangeCharacterReputation(pchar, 1);
			AddMoneyToCharacter(pchar, makeint(npchar.money.quest));
			AddPartyExp(pchar, 1000);
			NPChar.money.quest = "0";
			NPChar.quest.Teodoro = "done";
			NextDiag.TempNode = "Second Time";
		break;		

		case "TeodoroLie":
			Dialog.text = DLG_TEXT[97];
			Link.l1 = DLG_TEXT[98];
			Link.l1.go = "lie_1";
			Link.l2 = DLG_TEXT[99];
			Link.l2.go = "lie_2";
			NPChar.quest.Teodoro = "done";
		break;

		case "lie_1":
			Dialog.text = DLG_TEXT[100];
			Link.l1 = DLG_TEXT[101];
			Link.l1.go = "exit";
			NextDiag.TempNode = "Second Time";
		break;

		case "lie_2":
			Dialog.text = DLG_TEXT[102] + Characters[GetCharacterIndex(DLG_TEXT[103])].name + DLG_TEXT[104];
			Link.l1 = DLG_TEXT[105];
			Link.l1.go = "lie_2_1";
		break;

		case "lie_2_1":
			Dialog.text = DLG_TEXT[106];
			Link.l1 = DLG_TEXT[107];
			Link.l1.go = "exit";
			ChangeCharacterReputation(pchar, 1);
			AddMoneyToCharacter(pchar, makeint(npchar.money.quest));
			NPChar.money.quest = "0";
			AddPartyExp(pchar, 1000);
			NextDiag.TempNode = "Second Time";
		break;

		case "tavern":
			Dialog.text = DLG_TEXT[108] + Address_Form.Fra + DLG_TEXT[109];
			Link.l1 = DLG_TEXT[110];
			Link.l1.go = "node_23";
			Link.l2 = DLG_TEXT[111];
			Link.l2.go = "exit";
		break;

		case "store":
			Dialog.text = DLG_TEXT[112];
			Link.l1 = DLG_TEXT[113];
			Link.l1.go = "node_23";
			Link.l2 = DLG_TEXT[114];
			Link.l2.go = "exit";
		break;

		case "shipyard":
			Dialog.text = DLG_TEXT[115];
			Link.l1 = DLG_TEXT[116];
			Link.l1.go = "node_23";
			Link.l2 = DLG_TEXT[117];
			Link.l2.go = "exit";
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode =  NextDiag.TempNode;
		break;
		
		
		case "Items":
			if (npchar.quest.Meeting != lastspeak_date)
			{
				GiveItemToTrader(npchar);
				npchar.quest.Meeting = lastspeak_date;
			}
			
			NextDiag.CurrentNode =  NextDiag.TempNode;
			DialogExit();
			LaunchItemsTrade(NPChar);
		break;
	}
}


//nclude "DIALOGS\turpin cabanel_dialog.h"
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
		// ----------------------------------- Диалог первый - первая встреча
		case "Story_Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			AddDialogExitQuest("turpin_cabanel_story_exit");			
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
			Dialog.snd = "dialogs\0\009";

			Dialog.Text = PChar.name + " " + PChar.lastname + DLG_TEXT[0] + PChar.ship.name + DLG_TEXT[1];
			Link.l1 = DLG_TEXT[2];
			Link.l1.go = "node_2";
			NextDiag.TempNode = "Second Time";
		break;

		case "node_2":
			Dialog.Text = DLG_TEXT[3] + Npchar.name + " " + NPchar.lastname + DLG_TEXT[4];
			Link.l1 = DLG_TEXT[5];
			link.l1.go = "node_3";
		break;

		case "Second Time":
			Dialog.text = TimeGreeting() + DLG_TEXT[6] + PChar.name + " " + PChar.lastname + DLG_TEXT[7];
			Link.l1 = DLG_TEXT[8];
			link.l1.go = "node_3";
			if (NPChar.quest.smugglers == "letters")
			{
				Link.l2 = DLG_TEXT[9];
				Link.l2.go = "smugglers_6_1";
			}
			if (NPChar.quest.smugglers == "letters_1")
			{
				Link.l2 = DLG_TEXT[10];
				Link.l2.go = "smugglers_6";
			}
			if (npchar.quest.smugglers == "orable_truth")
			{
				link.l2 = DLG_TEXT[11];
				link.l2.go = "smugglers_8";
			}
			if (npchar.quest.smugglers == "residence")
			{
				link.l2 = DLG_TEXT[12];
				link.l2.go = "smugglers_12";
			}
			if(CheckCharacterItem(Pchar,"Story_Gramota") && !LAi_IsDead(characterFromID("Virgile Boon")))
			{
				link.l3 = DLG_TEXT[13];
				link.l3.go = "Story_Convoy";
			}
			NextDiag.TempNode = "Second Time";
		break;

		case "node_3":
			Dialog.text = DLG_TEXT[14];
			Link.l1 = DLG_TEXT[15];
			Link.l1.go = "town";
			if (NPChar.quest.smugglers == "1")
			{
				Link.l2 = DLG_TEXT[16];
				Link.l2.go = "smugglers";
			}
			if (NPChar.quest.smugglers == "letters")
			{
				Link.l2 = DLG_TEXT[17];
				Link.l2.go = "smugglers_6_1";
			}
			if (NPChar.quest.smugglers == "letters_1")
			{
				Link.l2 = DLG_TEXT[18];
				Link.l2.go = "smugglers_6";
			}
			if(CheckCharacterItem(Pchar,"Story_Gramota"))
			{
				link.l3 = DLG_TEXT[19];
				link.l3.go = "Story_Convoy";
			}
		break;

		case "smugglers":
			Dialog.text = DLG_TEXT[20];
			Link.l1 = DLG_TEXT[21];
			Link.l1.go = "smugglers_1";
		break;

		case "smugglers_1":
			Dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "node_3";
			Link.l2 = DLG_TEXT[24];
			Link.l2.go = "smugglers_2";
		break;

		case "smugglers_2":
			Dialog.text = DLG_TEXT[25];
			link.l1 = DLG_TEXT[26];
			link.l1.go = "smugglers_3";
		break;

		case "smugglers_3":
			Dialog.text = DLG_TEXT[27];
			Link.l1 = DLG_TEXT[28];
			Link.l1.go = "smugglers_4";
			if (!CheckAttribute(pchar, "quest.Story_OxbayCaptured"))
			{
				Link.l2 = DLG_TEXT[29];
				link.l2.go = "fight";
			}
		break;

		case "smugglers_4":
			Dialog.text = DLG_TEXT[30];
			Link.l1 = DLG_TEXT[31];
			link.l1.go = "smugglers_5";
		break;

		case "smugglers_5":
			Dialog.text = DLG_TEXT[32];
			Link.l1 = DLG_TEXT[33];
			Link.l1.go = "exit";
			NPchar.quest.smugglers = "2";
			NPchar.money.quest = "5000";
		break;

		case "smugglers_6":
			Dialog.text = DLG_TEXT[34];
			Link.l1 = DLG_TEXT[35];
			Link.l1.go = "smugglers_7";
		break;

		case "smugglers_6_1":
			Dialog.text = DLG_TEXT[36];
			Link.l1 = DLG_TEXT[37];
			Link.l1.go = "smugglers_7_1";
		break;

		case "smugglers_7_1":
			Dialog.text = DLG_TEXT[38];
			Link.l1 = DLG_TEXT[39];
			Link.l1.go = "smugglers_7_2";
			Link.l1 = DLG_TEXT[40];
			Link.l1.go = "smugglers_7_3";
		break;

		case "smugglers_7_2":
			Dialog.text = DLG_TEXT[41];
			AddMoneyToCharacter(pchar, 1500);
			ChangeCharacterReputation(pchar, 1);
			AddPartyExp(pchar, 1500);
			npchar.quest.smugglers = "done";
			npchar.money.quest = "0";
			Link.l1 = DLG_TEXT[42];
			Link.l1.go = "exit";
			ChangeCharacterAddress(characterFromID("Raoul Calmes"),"none", "");
			ChangeCharacterAddress(characterFromID("Andre Juliao"),"none", "");
		break;

		case "smugglers_7_3":
			Dialog.text = DLG_TEXT[43];
			AddMoneyToCharacter(pchar, makeint(npchar.money.quest));
			ChangeCharacterReputation(pchar, 1);
			AddPartyExp(pchar, 1500);
			npchar.quest.smugglers = "done";
			npchar.money.quest = "0";
			Link.l1 = DLG_TEXT[44];
			Link.l1.go = "exit";
			characters[GetCharacterIndex("Andre Juliao")].death = true;
			characters[GetCharacterIndex("Raoul Calmes")].death = true;
		break;

		case "smugglers_7":
			Dialog.text = DLG_TEXT[45];
			AddMoneyToCharacter(pchar, makeint(npchar.money.quest));
			ChangeCharacterReputation(pchar, 1);
			AddPartyExp(pchar, 1500);
			npchar.quest.smugglers = "done";
			npchar.money.quest = "0";
			characters[GetCharacterIndex("Andre Juliao")].death = true;
			characters[GetCharacterIndex("Raoul Calmes")].death = true;
			Link.l1 = DLG_TEXT[46];
			Link.l1.go = "exit";
		break;

		case "smugglers_8":
			dialog.text = DLG_TEXT[47];
			link.l1 = DLG_TEXT[48] + characters[GetCharacterIndex(DLG_TEXT[49])].name + " " + characters[GetCharacterIndex(DLG_TEXT[50])].lastname + DLG_TEXT[51];
			link.l1.go = "smugglers_9";
		break;

		case "smugglers_9":
			dialog.text = DLG_TEXT[52] + Characters[GetCharacterIndex(DLG_TEXT[53])].name + DLG_TEXT[54];
			link.l1 = DLG_TEXT[55];
			link.l1.go = "smugglers_10";
		break;

		case "smugglers_10":
			dialog.text = DLG_TEXT[56] + address_form.fra + DLG_TEXT[57];
			link.l1 = DLG_TEXT[58];
			link.l1.go = "smugglers_11";
		break;

		case "smugglers_11":
			dialog.text = DLG_TEXT[59];
			link.l1 = DLG_TEXT[60];
			link.l1.go = "exit2";
			npchar.quest.smugglers = "residence";
		break;

		case "smugglers_12":
			dialog.text = DLG_TEXT[61];
			link.l1 = DLG_TEXT[62];
			link.l1.go = "exit3";
			characters[GetCharacterIndex("Andre Juliao")].location= "0";
			characters[GetCharacterIndex("Raoul Calmes")].location= "0";
			AddMoneyToCharacter(pchar, makeint(npchar.money.quest));
			ChangeCharacterReputation(pchar, 1);
			AddPartyExp(pchar, 1500);
			npchar.quest.smugglers = "done";
			npchar.money.quest = "0";
		break;

		case "town":
			Dialog.text = DLG_TEXT[63];
			link.l1 = DLG_TEXT[64];
			Link.l1.go = "exit";
			if ( CheckAttribute(&Characters[GetCharacterIndex("Milon Blacque")], "quest.first_talk") && Characters[GetCharacterIndex("Milon Blacque")].quest.first_talk == "done")
			{
				Link.l2 = DLG_TEXT[65] + Characters[GetCharacterIndex(DLG_TEXT[66])].lastname + DLG_TEXT[67];
				Link.l2.go = "blacque";
			}
		break;

		case "blacque":
			Dialog.text = DLG_TEXT[68];
			link.l1 = DLG_TEXT[69] + Characters[GetCharacterIndex(DLG_TEXT[70])].name + DLG_TEXT[71];
			link.l1.go = "blacque_1";
		break;

		case "blacque_1":
			Dialog.text = DLG_TEXT[72];
			Link.l1 = DLG_TEXT[73];
			Link.l1.go = "blacque_2";
			Link.l2 = DLG_TEXT[74];
			Link.l2.go = "exit";
		break;

		case "blacque_2":
			Dialog.text = DLG_TEXT[75];
			link.l1 = DLG_TEXT[76];
			link.l1.go ="blacque_3";
		break;

		case "blacque_3":
			Dialog.text = DLG_TEXT[77];
			link.l1 = DLG_TEXT[78];
			link.l1.go = "blacque_4";
		break;

		case "blacque_4":
			Dialog.text = Characters[GetCharacterIndex(DLG_TEXT[79])].name + DLG_TEXT[80];
			link.l1 = DLG_TEXT[81];
			Link.l1.go = "exit";
			Characters[GetCharacterIndex("Rachel Blacque")].quest.badguy = "3";
		break;

		case "fight":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("turpin_cabanel_fight");
		break;

		case "Exit2":
			changeCharacterAddress(npchar, "Falaise_de_Fleur_location_03", "sitizen07");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "Exit3":
			ChangeCharacterAddress(npchar, "Falaise_de_Fleur_location_01", "shipyarder");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "Story_After_talk":
			Dialog.Text = DLG_TEXT[82] + Npchar.name + " " + NPchar.lastname + DLG_TEXT[83];
			Link.l1 = DLG_TEXT[84];
			link.l1.go = "node_3";
		break;
	
		case "Story_Convoy":
			Dialog.Text = DLG_TEXT[85];
			if (Characters[GetCharacterIndex("Virgile boon")].quest.meeting == "0")
			{
				Link.l1 = DLG_TEXT[86];
				link.l1.go = "Story_Convoy_2";
			}
			else
			{
				Link.l1 = DLG_TEXT[87];
				link.l1.go = "Story_Convoy_3";
			}
		break;

		case "Story_Convoy_2":
			Characters[GetCharacterIndex("Virgile Boon")].Dialog.CurrentNode = "Second Time_NotMet";
			TakeItemFromCharacter(PChar, "Story_Gramota");
			if(LAI_IsDead("Virgile Boon"))
			{
				Dialog.Text = DLG_TEXT[88];
			}
			else
			{
				Dialog.Text = DLG_TEXT[89];
			}
			Link.l1 = DLG_TEXT[90] + NPChar.name + DLG_TEXT[91];
			link.l1.go = "Story_exit";
		break;

		case "Story_Convoy_3":
			Characters[GetCharacterIndex("Virgile Boon")].Dialog.CurrentNode = "Second Time";
			TakeItemFromCharacter(Pchar,"Story_Gramota");
			Dialog.Text = DLG_TEXT[92];
			Link.l1 = DLG_TEXT[93] + NPChar.name + DLG_TEXT[94];
			link.l1.go = "Story_exit";
		break;



	}
}

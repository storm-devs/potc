//nclude "DIALOGS\Father Jerald_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_Meeting;
	int DonationSize, iTest;
	
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
			

			if(NPChar.quest.meeting == "0")
			{
				dialog.snd = "Voice\FATJ\FATJ001";
				d.Text = TimeGreeting() + DLG_TEXT[0];
				Link.l1 = DLG_TEXT[1] + Pchar.name + " " + Pchar.lastname + DLG_TEXT[2] + PChar.Ship.name + DLG_TEXT[3];
				Link.l1.go = "meeting";
				NPC_Meeting = "1"; 
			}
			else
			{
				dialog.snd1 = "Voice\FATJ\FATJ002";
				dialog.snd2 = "Voice\FATJ\FATJ003";
				dialog.snd3 = "Voice\FATJ\FATJ004";
				d.Text = RandPhrase(DLG_TEXT[4] + PChar.name + DLG_TEXT[5], DLG_TEXT[6] + PChar.name + DLG_TEXT[7], DLG_TEXT[8], &dialog, dialog.snd1, dialog.snd2, dialog.snd3);
				Link.l1 = NPChar.name + " " + NPChar.lastname + DLG_TEXT[9];
				Link.l1.go = "donation";
				Link.l2 = DLG_TEXT[10];
				Link.l2.go = "quest lines";
				Link.l3 = DLG_TEXT[11];
				Link.l3.go = "exit";
			}
		break;

		case "Meeting":
			dialog.snd = "Voice\FATJ\FATJ005";
				d.Text = DLG_TEXT[12] + NPChar.name + " " + NPChar.lastname + DLG_TEXT[13];
				Link.l1 = DLG_TEXT[14];
				Link.l1.go = "donation";
				Link.l2 = DLG_TEXT[15];
				Link.l2.go = "quest lines";
				Link.l3 = DLG_TEXT[16];
				Link.l3.go = "exit";
		break;

		case "quest lines":
			dialog.snd = "Voice\FATJ\FATJ006";
				d.Text = DLG_TEXT[17];
				if (characters[GetCharacterIndex("Father Bernard")].quest.church_help == "to_greenford" || characters[GetCharacterIndex("Father Bernard")].quest.church_help == "after_traktir")
				{
					link.l1 = DLG_TEXT[18];	
					link.l1.go = "to_greenford";
				}
				if (characters[GetCharacterIndex("Father Bernard")].quest.church_help == "letters_1")
				{
					link.l1 = DLG_TEXT[19];
					link.l1.go = "letters_1";
				}
				if (characters[GetCharacterIndex("Father Bernard")].quest.church_help == "letters_2" || characters[GetCharacterIndex("Father Bernard")].quest.church_help == "after_off")
				{
					link.l1 = DLG_TEXT[20];
					link.l1.go = "letters_2";
				}
				Link.l99 = DLG_TEXT[21]);
				Link.l99.go = "no quest";
		break;

		case "letters_1":
			dialog.snd = "Voice\FATJ\FATJ007";
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "letters_1_2";
		break;

		case "letters_1_2":
			dialog.snd = "Voice\FATJ\FATJ008";
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "letters_2_2";
		break;

		case "letters_2":
			dialog.snd = "Voice\FATJ\FATJ009";
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "letters_2_2";
		break;

		case "letters_2_2":
			dialog.snd = "Voice\FATJ\FATJ010";
			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "letters_2_3";
		break;

		case "letters_2_3":
			dialog.snd = "Voice\FATJ\FATJ011";
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "letters_2_4";
		break;

		case "letters_2_4":
			dialog.snd = "Voice\FATJ\FATJ012";
			dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "letters_2_4_exit";
			link.l2 = DLG_TEXT[34];
			link.l2.go = "letters_2_5";
		break;

		case "letters_2_4_exit":
			AddQuestRecord("church_help", "4");
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

		case "letters_2_5":
			dialog.snd = "Voice\FATJ\FATJ013";
			dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "letters_2_6";
		break;

		case "letters_2_6":
			if (GetCharacterSkill(pchar, SKILL_LEADERSHIP) > 4)
			{
				dialog.snd = "Voice\FATJ\FATJ014";
				dialog.text = DLG_TEXT[37];
				link.l1 = DLG_TEXT[38];
				link.l1.go = "letters_2_7";
			}
			else
			{
				dialog.snd = "Voice\FATJ\FATJ015";
				dialog.text = DLG_TEXT[39];
				link.l1 = DLG_TEXT[40];
				link.l1.go = "exit";
			}
		break;

		case "letters_2_7":
			dialog.snd = "Voice\FATJ\FATJ016";
			dialog.text = DLG_TEXT[41];
			link.l1 = DLG_TEXT[42];
			link.l1.go = "letters_2_9";
			link.l2 = DLG_TEXT[43];
			link.l2.go = "letters_2_8";
			AddMoneyToCharacter(pchar, 2000);
		break;

		case "letters_2_8":
			dialog.snd = "Voice\FATJ\FATJ017";
			dialog.text = DLG_TEXT[44];
			link.l1 = DLG_TEXT[45];
			link.l1.go = "exit";
			AddQuestRecord("church_help", "5");
		break;

		case "letters_2_9":
			AddQuestRecord("church_help", "6");
			characters[GetCharacterIndex("Father Bernard")].quest.church_help = "without_letters";
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

		case "to_greenford":
			dialog.snd = "Voice\FATJ\FATJ018";
			dialog.text = DLG_TEXT[46];
			link.l1 = DLG_TEXT[47] + characters[GetCharacterIndex(DLG_TEXT[48])].name + " " + characters[GetCharacterIndex(DLG_TEXT[49])].lastname + DLG_TEXT[50];
			link.l1.go = "to_greenford_2";
		break;

		case "to_greenford_2":
			dialog.snd = "Voice\FATJ\FATJ019";
			dialog.text = DLG_TEXT[51];
			link.l1 = DLG_TEXT[52];
			link.l1.go = "to_greenford_3";
		break;

		case "to_greenford_3":
			dialog.snd = "Voice\FATJ\FATJ020";
			dialog.text = DLG_TEXT[53];
			link.l1 = DLG_TEXT[54];
			link.l1.go = "exit";
			characters[GetCharacterIndex("Father Bernard")].quest.church_help = "speak_with_jerald";
		break;

		case "No quest":
			dialog.snd = "Voice\FATJ\FATJ021";
				d.Text = DLG_TEXT[55];
				Link.l1 = DLG_TEXT[56];
				Link.l1.go = "donation";
				Link.l2 = DLG_TEXT[57];
				Link.l2.go = "exit";
		break;

		case "donation":
			dialog.snd = "Voice\FATJ\FATJ022";
			d.Text = DLG_TEXT[58];
			Link.l1 = DLG_TEXT[59];
			Link.l1.go = "No donation";
			if(makeint(PChar.money)>=100)
			{	
				Link.l2 = DLG_TEXT[60];
				Link.l2.go = "donation paid_100";
			}
			if(makeint(PChar.money)>=1000)
			{
				Link.l3 = DLG_TEXT[61];
				Link.l3.go = "donation paid_1000";
			}
			if(makeint(PChar.money)>=5000)
			{	
				Link.l4 = DLG_TEXT[62];
				Link.l4.go = "donation paid_5000";
			}
		break;

		case "No donation":
			dialog.snd = "Voice\FATB\FATB045";
			d.Text = DLG_TEXT[63];
			Link.l1 = DLG_TEXT[64];
			Link.l1.go = "quest lines";
			Link.l2 = DLG_TEXT[65];
			Link.l2.go = "exit";
		break;

		case "donation paid_100":
			dialog.snd = "Voice\FATB\FATB046";
			AddMoneyToCharacter(pchar, -100);
			pchar.quest.donate = makeint(pchar.quest.donate) + 100;
			d.Text = DLG_TEXT[66];
			Link.l1 = DLG_TEXT[67];
			Link.l1.go = "quest lines";
			Link.l2 = DLG_TEXT[68];
			Link.l2.go = "exit";
			AddDialogExitQuest("donation");
		break;
		
		case "donation paid_1000":
			dialog.snd = "Voice\FATB\FATB046";
			AddMoneyToCharacter(pchar, -1000);
			pchar.quest.donate = makeint(pchar.quest.donate) + 1000;
			d.Text = DLG_TEXT[69];
			Link.l1 = DLG_TEXT[70];
			Link.l1.go = "quest lines";
			Link.l2 = DLG_TEXT[71];
			Link.l2.go = "exit";
			AddDialogExitQuest("donation");
		break;
		
		case "donation paid_5000":
			dialog.snd = "Voice\FATB\FATB046";
			AddMoneyToCharacter(pchar, -5000);
			pchar.quest.donate = makeint(pchar.quest.donate) + 5000;
			d.Text = DLG_TEXT[72];
			Link.l1 = DLG_TEXT[73];
			Link.l1.go = "quest lines";
			Link.l2 = DLG_TEXT[74];
			Link.l2.go = "exit";
			AddDialogExitQuest("donation");
		break;

		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;
		
	}
}
//nclude "DIALOGS\pater jourdain_dialog.h"
// object	Dialog;	declared in dialog.c
// ref		NPChar; declared in dialog.c
//#include "Dialogs\blaze_dialog_defines.c"

void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();

	
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
			Dialog.snd = "voice\PAJO\PAJO001";

			Dialog.Text = DLG_TEXT[0];
			Link.l1 = DLG_TEXT[1];
			Link.l1.go = "node_2";
			link.l2 = DLG_TEXT[2];
			link.l2.go = "node_3";
			NextDiag.TempNode = "First time";
		break;

		case "node_2":
			Dialog.snd = "voice\PAJO\PAJO002";
			dialog.text = DLG_TEXT[3];
			link.l1 = DLG_TEXT[4];
			link.l1.go = "exit";
			ChangeCharacterReputation(pchar, -1);
		break;

		case "node_3":
			Dialog.snd = "voice\PAJO\PAJO003";
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "donation";
			link.l2 = DLG_TEXT[7];
			link.l2.go = "ispoved";
			link.l3 = DLG_TEXT[8];
			link.l3.go = "exit";
			if (npchar.quest.prihod == "0")
			{
				link.l4 = DLG_TEXT[9];
				link.l4.go = "prihod";
			}
			if (npchar.quest.prihod == "2")
			{
				link.l4 = DLG_TEXT[10];
				link.l4.go = "prihod_5";
			}
			if (npchar.quest.prihod == "3")
			{
				link.l4 = DLG_TEXT[11];
				link.l4.go = "prihod_4";
			}
		break;

		case "donation":
			Dialog.snd = "voice\PAJO\PAJO004";
			dialog.Text = DLG_TEXT[12];
			Link.l1 = DLG_TEXT[13];
			Link.l1.go = "No donation";
			if(makeint(PChar.money)>=100)
			{	
				Link.l2 = DLG_TEXT[14];
				Link.l2.go = "donation paid_100";
			}
			if(makeint(PChar.money)>=1000)
			{
				Link.l3 = DLG_TEXT[15];
				Link.l3.go = "donation paid_1000";
			}
			if(makeint(PChar.money)>=5000)
			{	
				Link.l4 = DLG_TEXT[16];
				Link.l4.go = "donation paid_5000";
			}
		break;

		case "No donation":
			Dialog.snd = "voice\PADO\PADO042";
			dialog.Text = DLG_TEXT[17];
			Link.l1 = DLG_TEXT[18];
			Link.l1.go = "node_3";
			Link.l2 = DLG_TEXT[19];
			Link.l2.go = "exit";
		break;

		case "donation paid_100":
			Dialog.snd = "voice\PADO\PADO043";
			AddMoneyToCharacter(pchar, -100);
			pchar.quest.donate = makeint(pchar.quest.donate) + 100;
			dialog.Text = DLG_TEXT[20];
			Link.l1 = DLG_TEXT[21];
			Link.l1.go = "node_3";
			Link.l2 = DLG_TEXT[22];
			Link.l2.go = "exit";
			AddDialogExitQuest("donation");
		break;
		
		case "donation paid_1000":
			Dialog.snd = "voice\PADO\PADO043";
			AddMoneyToCharacter(pchar, -1000);
			pchar.quest.donate = makeint(pchar.quest.donate) + 1000;
			dialog.Text = DLG_TEXT[23];
			Link.l1 = DLG_TEXT[24];
			Link.l1.go = "node_3";
			Link.l2 = DLG_TEXT[25];
			Link.l2.go = "exit";
			AddDialogExitQuest("donation");
		break;
		
		case "donation paid_5000":
			Dialog.snd = "voice\PADO\PADO043";
			AddMoneyToCharacter(pchar, -5000);
			pchar.quest.donate = makeint(pchar.quest.donate) + 5000;
			dialog.Text = DLG_TEXT[26];
			Link.l1 = DLG_TEXT[27];
			Link.l1.go = "node_3";
			Link.l2 = DLG_TEXT[28];
			Link.l2.go = "exit";
			AddDialogExitQuest("donation");
		break;

		case "ispoved":
			Dialog.snd = "voice\PAJO\PAJO006";
			dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[31];
			link.l2.go = "ispoved_1";
		break;

		case "ispoved_1":
			Dialog.snd = "voice\PAJO\PAJO007";	
			dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "ispoved_2";
		break;

		case "ispoved_2":
			Dialog.snd = "voice\PAJO\PAJO008";
			dialog.text = DLG_TEXT[34];
			link.l1 = DLG_TEXT[35];
			link.l1.go = "ispoved_3";
			link.l2 = DLG_TEXT[36];
			link.l2.go = "ispoved_4";
		break;

		case "ispoved_3":
			Dialog.snd = "voice\PAJO\PAJO009";
			dialog.text = DLG_TEXT[37];
			link.l1 = DLG_TEXT[38];
			link.l1.go = "exit";
		break;

		case "ispoved_4":
			Dialog.snd = "voice\PAJO\PAJO010";
			dialog.text = DLG_TEXT[39];
			link.l1 = DLG_TEXT[40];
			link.l1.go = "exit";
		break;

		case "prihod":
			if (makeint(pchar.reputation) > 50)
			{
				Dialog.snd = "voice\PAJO\PAJO0011";
				dialog.text = DLG_TEXT[41];
				link.l1 = DLG_TEXT[42];
				link.l1.go = "exit";
				link.l2 = DLG_TEXT[43];
				link.l2.go = "prihod_1";
			}
			else
			{
				Dialog.snd = "voice\PAJO\PAJO012";
				dialog.text = DLG_TEXT[44];
				link.l1 = DLG_TEXT[45];
				link.l1.go = "exit";
			}
		break;

		case "prihod_1":
			Dialog.snd = "voice\PAJO\PAJO013";
			dialog.text = DLG_TEXT[46];
			link.l1 = DLG_TEXT[47];
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[48];
			link.l2.go = "prihod_2";
		break;

		case "prihod_2":
			Dialog.snd = "voice\PAJO\PAJO014";
			dialog.text = DLG_TEXT[49];
			link.l1 = DLG_TEXT[50];
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[51];
			link.l2.go = "prihod_3";
		break;

		case "prihod_3":
			if (makeint(pchar.reputation) >= 60)
			{
				Dialog.snd = "voice\PAJO\PAJO015";
				dialog.text = DLG_TEXT[52] + characters[GetCharacterIndex(DLG_TEXT[53])].name + " " + characters[GetCharacterIndex(DLG_TEXT[54])].lastname + DLG_TEXT[55];
				link.l1 = DLG_TEXT[56];
				link.l1.go = "exit";
				npchar.quest.prihod = "1";
			}
			else
			{
				Dialog.snd = "voice\PAJO\PAJO016";
				dialog.text = DLG_TEXT[57];
				link.l1 = DLG_TEXT[58];
				link.l1.go = "exit";
			}
		break;

		case "prihod_4":
			Dialog.snd = "voice\PAJO\PAJO017";
			dialog.text = DLG_TEXT[59];
			link.l1 = DLG_TEXT[60];
			link.l1.go = "exit";
		break;

		case "prihod_5":
			Dialog.snd = "voice\PAJO\PAJO018";
			dialog.text = DLG_TEXT[61];
			link.l1 = DLG_TEXT[62];
			link.l1.go = "exit";
			ChangeCharacterReputation(pchar, 2);
			AddPartyExp(pchar, 800);
			npchar.quest.prihod = "done";
		break;
		
		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}

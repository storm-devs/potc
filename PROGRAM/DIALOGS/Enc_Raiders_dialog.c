//nclude "DIALOGS\Enc_Raiders_dialog.h"
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
	
	switch(Dialog.CurrentNode)
	{
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();			
		break;

		case "exit_Robbed":
			AddMoneyToCharacter(pchar, -(makeint(makeint(Pchar.money)/20)*10));
			AddDialogExitQuest("LandEnc_RaidersRobbed");

			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();			
		break;

		case "exit_fight":
			AddDialogExitQuest("LandEnc_RaidersFight");

			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();			
		break;

		case "exit_RunFight":
			AddDialogExitQuest("LandEnc_RaidersRunAway");

			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

		case "exit_noFight":
			AddDialogExitQuest("LandEnc_RaidersNoFight");

			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();			
		break;

		case "Node_1":
			Dialog.defAni = "dialog_stay2";
			Dialog.defCam = "2";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";

			LAi_type_actor_Reset(CharacterFromID("Enc_Char1"));
			LAi_type_actor_Reset(CharacterFromID("Enc_Char2"));
			LAi_type_actor_Reset(CharacterFromID("Enc_Char3"));
			LAi_type_actor_Reset(CharacterFromID("Enc_Char4"));

			dialog.snd1 = "";
			dialog.snd2 = "";
			dialog.snd3 = "";
			d.Text = RandPhrase(DLG_TEXT[0], DLG_TEXT[1], DLG_TEXT[2], &dialog, dialog.snd1, dialog.snd2, dialog.snd3);
			Link.l1 = LinkRandPhrase(DLG_TEXT[3], DLG_TEXT[4], DLG_TEXT[5]);
			Link.l1.go = "Node_2";
			Link.l2 = LinkRandPhrase(DLG_TEXT[6], DLG_TEXT[7], DLG_TEXT[8]);
			Link.l2.go = "CheckSkills";
			
		break;

		case "Node_2":
			dialog.snd1 = "";
			dialog.snd2 = "";
			dialog.snd3 = "";
			d.Text = RandPhrase(DLG_TEXT[9], DLG_TEXT[10], DLG_TEXT[11], &dialog, dialog.snd1, dialog.snd2, dialog.snd3);
			Link.l1 = DLG_TEXT[12] + makeint(makeint(Pchar.money)/20)*10 + DLG_TEXT[13];
			Link.l1.go = "CheckMoney";
			Link.l2 = DLG_TEXT[14];
			Link.l2.go = "CheckSkills";			
		break;

		case "CheckSkills":
			if(makeint(Pchar.skill.Fencing) >= 7 && makeint(Pchar.Rank) >= 8 && Makeint(PChar.reputation) <= 30) 
			{
				Diag.TempNode = "GetLost";
				dialog.snd1 = "";
				dialog.snd2 = "";
				dialog.snd3 = "";
				d.Text = RandPhrase(DLG_TEXT[15], DLG_TEXT[16], DLG_TEXT[17], &dialog, dialog.snd1, dialog.snd2, dialog.snd3);
				Link.l1 = LinkRandPhrase(DLG_TEXT[18], DLG_TEXT[19], DLG_TEXT[20]);
				Link.l1.go = "Exit_NoFight";
				Link.l99 = LinkRandPhrase(DLG_TEXT[21], DLG_TEXT[22], DLG_TEXT[23]);
				Link.l99.go = "Exit_RunFight";
			}
			else 
			{
				dialog.snd1 = "";
				dialog.snd2 = "";
				dialog.snd3 = "";
				d.Text = RandPhrase(DLG_TEXT[24], DLG_TEXT[25], DLG_TEXT[26], &dialog, dialog.snd1, dialog.snd2, dialog.snd3);
				Link.l1 = DLG_TEXT[27];
				Link.l1.go = "Exit_Fight";				
			}

		break;

		case "CheckMoney":
			if(makeint(makeint(Pchar.money)/20)*10 >= makeint(Pchar.rank)*100)
			{
				Diag.TempNode = "OnceAgain";
				dialog.snd1 = "";
				dialog.snd2 = "";
				dialog.snd3 = "";
				d.Text = RandPhrase(DLG_TEXT[28], DLG_TEXT[29], DLG_TEXT[30], &dialog, dialog.snd1, dialog.snd2, dialog.snd3);
				Link.l1 = DLG_TEXT[31];
				Link.l1.go = "Exit_Robbed";				
			}
			else
			{
				d.Text = DLG_TEXT[32];
				Link.l1 = DLG_TEXT[33];
				Link.l1.go = "Exit_Fight";				
			}				
		break;

		case "OnceAgain":
			Diag.TempNode = "OnceAgain";
			dialog.snd1 = "";
			dialog.snd2 = "";
			dialog.snd3 = "";
			d.Text = RandPhrase(DLG_TEXT[34], DLG_TEXT[35], DLG_TEXT[36], &dialog, dialog.snd1, dialog.snd2, dialog.snd3);
			Link.l1 = DLG_TEXT[37];
			Link.l1.go = "Exit";
			Link.l2 = DLG_TEXT[38];
			Link.l2.go = "Exit_Fight";
		break;
				
		case "GetLost":
			Diag.TempNode = "GetLost";
			dialog.snd1 = "";
			dialog.snd2 = "";
			dialog.snd3 = "";
			d.Text = RandPhrase(DLG_TEXT[39], DLG_TEXT[40], DLG_TEXT[41], &dialog, dialog.snd1, dialog.snd2, dialog.snd3);
			Link.l1 = DLG_TEXT[42];
			Link.l1.go = "Exit";
			Link.l2 = DLG_TEXT[43];
			Link.l2.go = "Exit_Fight";
		break;

		case "GetTheHellOut":
			Diag.TempNode = "GetTheHellOut";
			dialog.snd1 = "";
			dialog.snd2 = "";
			dialog.snd3 = "";
			d.Text = RandPhrase(DLG_TEXT[44], DLG_TEXT[45], DLG_TEXT[46], &dialog, dialog.snd1, dialog.snd2, dialog.snd3);
			Link.l1 = DLG_TEXT[47];
			Link.l1.go = "Exit";			
		break;


	}
}
//nclude "DIALOGS\Leborio Drago_dialog.h"

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
			Dialog.snd = "dialogs\0\009";
			
			if (npchar.location == "Oxbay_mine")
			{
				dialog.text = DLG_TEXT[0];
				link.l1 = DLG_TEXT[1];
				link.l1.go = "exit";
			}
			else
			{
				dialog.text = DLG_TEXT[2];
				link.l1 = DLG_TEXT[3];
				link.l1.go = "exit";
			}

			if (pchar.quest.main_line == "slave_in_oxbay_mine_begin")
			{
				Dialog.Text = DLG_TEXT[4];
				Link.l1 = DLG_TEXT[5];
				Link.l1.go = "node_2";
			}
			if (pchar.quest.main_line == "talk_with_Liborio")
			{
				Dialog.Text = DLG_TEXT[6];
				Link.l1 = DLG_TEXT[7];
				Link.l1.go = "learn";
			}
			if (pchar.quest.main_line == "resque_leborio")
			{
				dialog.text = DLG_TEXT[8];
				link.l1 = DLG_TEXT[9];
				link.l1.go = "bad_story";
			}
			if (pchar.quest.main_line == "resque_leborio_bad")
			{
				dialog.text = DLG_TEXT[10];
				link.l1 = DLG_TEXT[11];
				link.l1.go = "hire";
			}
			if (pchar.quest.main_line == "resque_leborio_denied")
			{
				dialog.text = DLG_TEXT[12];
				link.l1 = DLG_TEXT[13];
				link.l1.go = "exit";
				link.l2 = DLG_TEXT[14];
				link.l2.go = "learn_4";
			}
			if (npchar.quest.hire == "not_hired" && pchar.location == "Falaise_De_Fleur_tavern")
			{
				dialog.text = DLG_TEXT[15];
				link.l1 = DLG_TEXT[16];
				link.l1.go = "hire_4";
				link.l2 = DLG_TEXT[17];
				link.l2.go = "exit";
			}
			if (pchar.quest.main_line == "resque_from_mines_denied")
			{
				dialog.text = DLG_TEXT[18];
				link.l1 = DLG_TEXT[19];
				link.l1.go = "resque_from_mines_denied_2";
			}
			if (pchar.quest.main_line == "lets_go_mines")
			{
				dialog.text = DLG_TEXT[20];
				link.l1 = DLG_TEXT[21];
				link.l1.go = "lets_go_exit";
			}
			if (pchar.quest.main_line == "after_speak_with_leborio" && npchar.quest.hire == "ask_for_hire")
			{
				dialog.text = DLG_TEXT[22];
				link.l1 = DLG_TEXT[23];
				link.l1.go = "passenger_exit";
				link.l2 = DLG_TEXT[24];
				link.l2.go = "fight";
			}
			if (pchar.quest.main_line == "talk_with_Liborio_2")
			{
				Dialog.Text = DLG_TEXT[25];
				Link.l1 = DLG_TEXT[26];
				Link.l1.go = "knowlege";
			}
			if( CheckQuestAttribute("FindMysteriousTablet","TabletBroken") )
			{
				Dialog.Text = DLG_TEXT[27];
				link.l1 = DLG_TEXT[28];
				link.l1.go = "Tablet_copy_1";
			}
			if( CheckQuestAttribute("FindMysteriousTablet","ToMine") )
			{
				Dialog.Text = DLG_TEXT[29];
				link.l1 = DLG_TEXT[30];
				link.l1.go = "knowlege";
			}
			NextDiag.TempNode = "first time";
		break;

		case "Tablet_copy_1":
			Dialog.Text = DLG_TEXT[31];
			link.l1 = DLG_TEXT[32];
			link.l1.go = "exit";
		break;

		case "knowlege":
			dialog.text = DLG_TEXT[33];
			link.l1 = DLG_TEXT[34];
			link.l1.go = "learn_4";
			link.l2 = DLG_TEXT[35];
			link.l2.go = "bad_learn";
		break;

		case "passenger_exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogexitQuest("leborio_drago_passenger_exit");
		break;

		case "fight":
			dialog.text = DLG_TEXT[36];
			link.l1 = DLG_TEXT[37];
			link.l1.go = "exit";
			AddDialogExitQuest("leborio_drago_fight_exit");
		break;

		case "lets_go_exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("lets_go_begin");
		break;

		case "resque_from_mines_denied_2":
			dialog.text = DLG_TEXT[38];
			link.l1 = DLG_TEXT[39];
			link.l1.go = "resque_from_mines_denied_3";
		break;
		
		case "resque_from_mines_denied_3":
			dialog.text = DLG_TEXT[40];
			link.l1 = DLG_TEXT[41];
			link.l1.go = "resque_from_mines_denied_4";
		break;

		case "resque_from_mines_denied_4":
			dialog.text = DLG_TEXT[42];
			link.l1 = DLG_TEXT[43];
			link.l1.go = "resque_from_mines_denied_5";
		break;

		case "resque_from_mines_denied_5":
			dialog.text = DLG_TEXT[44];
			link.l1 = DLG_TEXT[45];
			link.l1.go = "resque_from_mines_denied_6";
		break;

		case "resque_from_mines_denied_6":
			dialog.text = DLG_TEXT[46];
			link.l1 = DLG_TEXT[47];
			link.l1.go = "resque_from_mines_denied_7";
		break;

		case "resque_from_mines_denied_7":
			dialog.text = DLG_TEXT[48];
			link.l1 = DLG_TEXT[49];
			link.l1.go = "resque_from_mines_denied_8";
		break;

		case "resque_from_mines_denied_8":
			dialog.text = DLG_TEXT[50];
			link.l1 = DLG_TEXT[51];
			link.l1.go = "resque_from_mines_denied_9";
		break;

		case "resque_from_mines_denied_9":
			dialog.text = DLG_TEXT[52];
			link.l1 = DLG_TEXT[53];
			link.l1.go = "resque_from_mines_denied_10";
		break;

		case "resque_from_mines_denied_10":
			dialog.text = DLG_TEXT[54];
			link.l1 = DLG_TEXT[55];
			link.l1.go = "resque_from_mines_denied_11";
		break;

		case "resque_from_mines_denied_11":
			dialog.text = DLG_TEXT[56];
			link.l1 = DLG_TEXT[57];
			link.l1.go = "resque_from_mines_denied_exit";
			AddQuestRecord("search_danielle", "15");
		break;

		case "resque_from_mines_denied_exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("wait_for_resque_from_mines");
		break;

		case "learn":
			dialog.text = DLG_TEXT[58];
			link.l1 = DLG_TEXT[59];
			link.l1.go = "learn_2";
		break;

		case "learn_2":
			dialog.text = DLG_TEXT[60] + characters[GetCharacterIndex(DLG_TEXT[61])].name + " " + characters[GetCharacterIndex(DLG_TEXT[62])].lastname + DLG_TEXT[63];
			link.l1 = DLG_TEXT[64];
			link.l1.go = "learn_3";
			link.l2 = DLG_TEXT[65];
			link.l2.go = "bad_learn";
		break; 

		case "learn_3":
			dialog.text = DLG_TEXT[66];
			link.l1 = DLG_TEXT[67];
			link.l1.go = "learn_4";
			link.l2 = DLG_TEXT[68];
			link.l2.go = "bad_learn";
		break;

		case "learn_4":
			dialog.text = DLG_TEXT[69];
			pchar.quest.main_line = "ask_for_resque_leborio";
			link.l1 = DLG_TEXT[70];
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[71];
			link.l2.go = "bad_learn";
			AddQuestRecord("search_danielle", "17");
		break;

		case "bad_learn":
			dialog.text = DLG_TEXT[72];
			link.l1 = DLG_TEXT[73];
			link.l1.go = "bad_story";
		break;

		case "bad_story":
			dialog.text = DLG_TEXT[74];
			link.l1 = DLG_TEXT[75];
			link.l1.go = "bad_story_2";
			AddQuestRecord("search_danielle", "18");
			NextDiag.tempnode = "first time";
		break;

		case "bad_story_2":
			dialog.text = DLG_TEXT[76];
			link.l1 = DLG_TEXT[77];
			link.l1.go = "bad_story_3";
		break;

		case "bad_story_3":
			dialog.text = DLG_TEXT[78];
			link.l1 = DLG_TEXT[79];
			if (pchar.id == "Blaze")
			{
				link.l1.go = "bad_story_4";
			}
			else
			{
				pchar.quest.FindMysteriousTablet = "FindCopy";
				if (npchar.location == "Oxbay_mine")
				{
					link.l1.go = "exit";
					pchar.quest.main_line = "bad_story";
				}
				else
				{
					link.l1.go = "hire";
				}
			}
		break;

		case "bad_story_4":
			dialog.text = DLG_TEXT[80];
			link.l1 = DLG_TEXT[81];
			link.l1.go = "bad_story_5";
		break;

		case "bad_story_5":
			dialog.text = DLG_TEXT[82];
			link.l1 = DLG_TEXT[83];
			if (pchar.quest.main_line == "resque_leborio")
			{
				link.l1.go = "hire";
				pchar.quest.main_line = "hire_leborio";
			}
			else
			{
				link.l1.go = "exit";
				pchar.quest.main_line = "after_speak_with_leborio";
			}
		break;

		case "hire":
			dialog.text = DLG_TEXT[84];
			link.l1 = DLG_TEXT[85];
			link.l1.go = "hire_2";
			OfficersReaction("good");
		break;

		case "hire_2":
			dialog.text = DLG_TEXT[86];
			link.l1 = DLG_TEXT[87];
			link.l1.go = "hire_3";
		break;

		case "hire_3":
			dialog.text = DLG_TEXT[88];
			link.l1 = DLG_TEXT[89];
			link.l1.go = "hire_4";
			link.l2 = DLG_TEXT[90];
			link.l2.go = "hire_denied";
		break;

		case "hire_4":
			dialog.text = DLG_TEXT[91];
			link.l1 = DLG_TEXT[92];
			link.l1.go = "hire_5";
		break;

		case "hire_5":
			dialog.text = DLG_TEXT[93];
			if (makeint(pchar.money) >= 1500)
			{
				link.l1 = DLG_TEXT[94];
				link.l1.go = "hire_6";
			}
			link.l2 = DLG_TEXT[95];
			link.l2.go = "hire_denied";
			if(pchar.id == "Blaze")
			{
				pchar.quest.main_line = "to_isla_muelle";
			}
		break;
		
		case "hire_6":
			dialog.text = DLG_TEXT[96];
			link.l1 = DLG_TEXT[97] + pchar.ship.name + DLG_TEXT[98];
			link.l1.go = "exit";
			npchar.quest.hire = "hired";
			AddMoneyToCharacter(pchar, -1500);
			AddPassenger(pchar, npchar, -1);
			GiveItem2Character(npchar, "blade1");
			EquipCharacterByItem(npchar, "blade1");	
			npchar.dialog.currentnode = "hired";		
		break;

		case "hire_denied":
			dialog.text = DLG_TEXT[99];
			link.l1 = DLG_TEXT[100];
			link.l1.go = "exit";
			AddDialogExitQuest("leborio_hire_denied");
			npchar.quest.hire = "not_hired";
		break;

		case "node_2":
			dialog.text = DLG_TEXT[101];
			link.l1 = DLG_TEXT[102];
			link.l1.go = "node_3";
		break;

		case "node_3":
			dialog.text = DLG_TEXT[103];
			link.l1 = DLG_TEXT[104];
			link.l1.go = "node_4";
		break;

		case "node_4":
			dialog.text = DLG_TEXT[105];
			link.l1 = DLG_TEXT[106];
			link.l1.go = "node_5";
			pchar.quest.main_line = "slave_in_oxbay_mine_begin_1";
			link.l2 = DLG_TEXT[107];
			link.l2.go = "node_5";
			AddQuestRecord("search_danielle", "12");
		break;

		case "node_5":
			dialog.text = DLG_TEXT[108];
			link.l1 = DLG_TEXT[109];
			link.l1.go = "exit";
			AddDialogExitQuest("miner_again_kick_exit");
		break;

		case "Exit_2":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			pchar.quest.main_line = "blaze_in_mine";
			EndQuestMovie();
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			EndQuestMovie();
		break;
		
		case "hired":
			Dialog.text = DLG_TEXT[110];
			link.l1 = DLG_TEXT[111];
			link.l1.go = "exit";
		break;
	}
}

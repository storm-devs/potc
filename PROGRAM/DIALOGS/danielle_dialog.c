//nclude "DIALOGS\danielle_dialog.h"
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
			Dialog.snd = "dialogs\0\009";

			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
			
			if (pchar.quest.main_line == "danielle_wait_for_remove_companion")
			{
				dialog.text = DLG_TEXT[2] + pchar.name + DLG_TEXT[3];
				link.l1 = DLG_TEXT[4];
				link.l1.go = "blaze_search_rheims_with_danielle_6"; 
			}
			// разговор в квестовой таверне Редмонда
			if (pchar.quest.main_line == "talk_in_tavern_begin")
			{
				dialog.text = DLG_TEXT[5] + characters[GetCharacterIndex(DLG_TEXT[6])].name + DLG_TEXT[7];
				Link.l1 = DLG_TEXT[8];
				Link.l1.go = "talk_in_tavern";
			}
			if(pchar.quest.main_line == "fawn_death")
			{
				dialog.text = characters[GetCharacterIndex(DLG_TEXT[9])].name + DLG_TEXT[10];
				link.l1 = DLG_TEXT[11] + characters[GetCharacterIndex(DLG_TEXT[12])].name + DLG_TEXT[13];
				link.l1.go = "talk_in_tavern_1";
			}
			//разговор на маяке
			if (pchar.quest.main_line == "meet_danielle_in_lighthouse")
			{
				dialog.text = pchar.name + DLG_TEXT[14];
				link.l1 = npchar.name + DLG_TEXT[15];
				link.l1.go = "meet_danielle_in_lighthouse_2";
			}
			if (pchar.quest.main_line == "speak_danielle_in_lighthouse_prepare_to_search_rheims")
			{
				dialog.text = DLG_TEXT[16];
				link.l1 = DLG_TEXT[17] + characters[GetCharacterIndex(DLG_TEXT[18])].lastname + DLG_TEXT[19];
				link.l1.go = "speak_danielle_in_lighthouse_prepare_to_search_rheims_2";
			}
			if (pchar.quest.main_line == "blaze_search_rheims_with_danielle")
			{
				dialog.text = DLG_TEXT[20] + pchar.name + DLG_TEXT[21];
				link.l1 = DLG_TEXT[22];
				link.l1.go = "blaze_search_rheims_with_danielle_2";
			}
			if (pchar.quest.main_line == "blaze_goto_douwesen_with_danielle_2")
			{
				dialog.text = pchar.name + DLG_TEXT[23] + characters[getcharacterindex(DLG_TEXT[24])].name + DLG_TEXT[25];
				link.l1 = DLG_TEXT[26];
				link.l1.go = "blaze_goto_douwesen_with_danielle";
			}
			if (pchar.quest.main_line == "vincent_away_from_douwesen_tavern")
			{
				dialog.text = DLG_TEXT[27] + characters[GetCharacterIndex(DLG_TEXT[28])].name + DLG_TEXT[29];
				link.l1 = DLG_TEXT[30];
				link.l1.go = "vincent_away_from_douwesen_tavern";
			}
			if (pchar.quest.main_line == "from_tavern_to_rheims_house")
			{
				dialog.text = pchar.name + DLG_TEXT[31];
				link.l1 = DLG_TEXT[32] + characters[GetCharacterIndex(DLG_TEXT[33])].lastname + DLG_TEXT[34];
				link.l1.go = "runaway";
			}
			if (pchar.quest.main_line == "to_rheims_house")
			{
				dialog.text = DLG_TEXT[35];
				link.l1 = DLG_TEXT[36] + characters[GetCharacterIndex(DLG_TEXT[37])].lastname + DLG_TEXT[38];
				link.l1.go = "prepare_to_dagger";
			}
			if (pchar.quest.main_line == "resque_danielle")
			{
				dialog.text = pchar.name + DLG_TEXT[39];
				link.l1 = DLG_TEXT[40];
				link.l1.go = "resque_danielle";
			}
			if (pchar.quest.main_line == "to_secret_redmond_shore")
			{
				if (makeint(environment.time) >22.0 || makeint(environment.time) <5.0)
				{
					pchar.quest.main_line = "after_wait_for_night_in_shore";
				}
				else
				{
					dialog.text = DLG_TEXT[41];
					link.l1 = DLG_TEXT[42];
					link.l1.go = "wait_for_night_in_shore";
				}
			}
			if (pchar.quest.main_line == "after_wait_for_night_in_shore")
			{
				dialog.text = DLG_TEXT[43];
				link.l1 = DLG_TEXT[44];
				link.l1.go = "after_wait_for_night_in_shore";
			}
			if (pchar.quest.main_line == "both_escape_from_redmond" && pchar.location == "Redmond_shore_01")
			{
				dialog.text = DLG_TEXT[45];
				link.l1 = DLG_TEXT[46];
				link.l1.go = "both_escape_from_redmond_complete_2";
			}
			// разговор в квестовой таверне Редмонда
			if( CheckQuestAttribute("FindMysteriousTablet","EnterDenied") )
			{
				dialog.text = RandSwear() + DLG_TEXT[47];
				link.l1 = DLG_TEXT[48];
				link.l1.go = "exit";
				AddDialogExitQuest("DanielleTalkAboutAssault_enter");
				//addDialogExitQuest("before_talk_with_command");
			}
			if( CheckQuestAttribute("FindMysteriousTablet","PerorateAboutAssault") )
			{
				dialog.text = DLG_TEXT[49];
				link.l1 = DLG_TEXT[50];
				link.l1.go = "exit";
			}
			if( CheckQuestAttribute("Find_Blaze","Muelle_Ship_Stolen") )
			{
				dialog.text = DLG_TEXT[51];
				Link.l1 = DLG_TEXT[52];
				Link.l1.go = "exit";
				AddDialogExitQuest("danielle_muelle_bartender_talk");
			}
			if(CheckQuestAttribute("story_FindRheims","complete") && pchar.location == "Douwesen_town_exit")
			{
				dialog.text = DLG_TEXT[53];
				Link.l1 = " ";
				Link.l1.go = "exit";
				pchar.quest.story_FindRheims = "complete2";
			}
			if (CheckQuestAttribute("Find_Blaze", "Muelle_Ship_Stolen"))
			{
				dialog.text = DLG_TEXT[54] + characters[GetCharacterIndex(DLG_TEXT[55])].name + DLG_TEXT[56];
				link.l1 = DLG_TEXT[57];
				link.l1.go = "exit";
			}
			if (characters[GetCharacterIndex("Toff Oremans")].quest.daughter != "" && characters[GetCharacterIndex("Toff Oremans")].quest.daughter != "help_denied" && pchar.location == "Douwesen_port" && pchar.id == "danielle")
			{
				dialog.text = DLG_TEXT[58];
				link.l1 = DLG_TEXT[59];
				link.l1.go = "to_the_ship";
				link.l2 = DLG_TEXT[60];
				link.l2.go = "not_to_the_ship";
			}
			if (characters[getCharacterIndex("Toff Oremans")].quest.daughter == "bad_complete" || characters[getCharacterIndex("Toff Oremans")].quest.daughter == "good" && pchar.id == "danielle")
			{
				dialog.text = DLG_TEXT[61];
				link.l1 = DLG_TEXT[62];
				link.l1.go = "exit";
				if (characters[getCharacterIndex("Toff Oremans")].quest.daughter == "bad_complete")
				{
					characters[getCharacterIndex("Toff Oremans")].quest.daughter = "bad_2_complete";
				}
				else
				{
					characters[getCharacterIndex("Toff Oremans")].quest.daughter = "good_2_complete";
				}
				AddDialogExitQuest("teneken_in_the_ship");
			}
			if (CheckQuestAttribute("ANIMISTS", "letter_to_father_bernard"))
			{
				dialog.text = DLG_TEXT[63];
				link.l1 = DLG_TEXT[64];
				link.l1.go = "exit";
			}
			NextDiag.TempNode = "first time";
		break;

		case "to_the_ship":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("to_the_ship");
		break;

		case "not_to_the_ship":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("not_to_the_ship");
		break;

		case "escape_from_Isenbrandt_house":
			dialog.text = RandSwear() + DLG_TEXT[65];
			link.l1 = DLG_TEXT[66];
			link.l1.go = "exit";
			NextDiag.TempNode = "first time";
		break;

		case "both_escape_from_redmond_complete_2":
			dialog.text = DLG_TEXT[67] + characters[GetCharacterIndex(DLG_TEXT[68])].lastname + DLG_TEXT[69] + characters[GetCharacterIndex(DLG_TEXT[70])].name + " " + characters[GetCharacterIndex(DLG_TEXT[71])].lastname + DLG_TEXT[72];
			link.l1 = DLG_TEXT[73];
			link.l1.go = "both_escape_from_redmond_complete_3";
		break;

		case "both_escape_from_redmond_complete_3":
			dialog.text = DLG_TEXT[74];
			link.l1 = DLG_TEXT[75];
			link.l1.go = "both_escape_from_redmond_complete_4";
		break;

		case "both_escape_from_redmond_complete_4":
			dialog.text = DLG_TEXT[76] + pchar.name + DLG_TEXT[77];
			link.l1 = DLG_TEXT[78];
			link.l1.go = "exit_both_escape_from_redmond_complete";
			AddQuestRecord("search_danielle", "4");
		break;

		case "exit_both_escape_from_redmond_complete":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			RemovePassenger(pchar, &characters[GetCharacterIndex("Danielle")]);
			ReStorePassengers("Blaze");
			RemoveCharacterCompanion(pchar, npchar);
			pchar.quest.main_line = "return_idol_from_greenford_soldier";
			pchar.quest.to_idol.win_condition.l1 = "location"; 
			pchar.quest.to_idol.win_condition.l1.location = "redmond"; 
			pchar.quest.to_idol.win_condition = "to_idol_complete"; 
		break;

		case "after_wait_for_night_in_shore":
			dialog.text = DLG_TEXT[79];
			link.l1 = DLG_TEXT[80];
			link.l1.go = "after_wait_for_night_in_shore_exit";
			AddQuestRecord("search_danielle", "2");
		break;

		case "after_wait_for_night_in_shore_exit":
			pchar.quest.main_line = "both_to_redmond_residence";
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("both_to_residence_complete");
		break;

		case "wait_for_night_in_shore":
			pchar.quest.main_line = "after_wait_for_night_in_shore";
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			//Выставляем ночь
			AddDialogExitQuest("wait_for_night_in_shore");
		break;

		case "resque_danielle":
			dialog.text = DLG_TEXT[81];
			link.l1 = DLG_TEXT[82];
			link.l1.go = "resque_danielle_2";
		break;

		case "resque_danielle_2":
			dialog.text = DLG_TEXT[83] + pchar.name + DLG_TEXT[84];
			link.l1 = DLG_TEXT[85];
			link.l1.go = "resque_danielle_3";
		break;

		case "resque_danielle_3":
			dialog.text = DLG_TEXT[86];
			link.l1 = DLG_TEXT[87] + npchar.name + DLG_TEXT[88] + characters[getCharacterIndex(DLG_TEXT[89])].lastname + DLG_TEXT[90];
			link.l1.go = "resque_danielle_4";
		break;

		case "resque_danielle_4":
			dialog.text = DLG_TEXT[91] + pchar.name + DLG_TEXT[92];
			link.l1 = DLG_TEXT[93] + npchar.name + DLG_TEXT[94];
			link.l1.go = "resque_danielle_5";
		break;

		case "resque_danielle_5":
			dialog.text = DLG_TEXT[95];
			link.l1 = DLG_TEXT[96];
			link.l1.go = "resque_danielle_6";
		break;

		case "resque_danielle_6":
			dialog.text = DLG_TEXT[97];
			link.l1 = DLG_TEXT[98];
			link.l1.go = "resque_danielle_7";
		break;
		
		case "resque_danielle_7":
			dialog.text = DLG_TEXT[99];
			link.l1 = DLG_TEXT[100] + npchar.name + DLG_TEXT[101] + characters[GetCharacterIndex(DLG_TEXT[102])].lastname + DLG_TEXT[103];
			link.l1.go = "resque_danielle_8";
		break;

		case "resque_danielle_8":
			dialog.text = DLG_TEXT[104];
			link.l1 = DLG_TEXT[105];
			link.l1.go = "resque_danielle_9";
		break;
		
		case "resque_danielle_9":
			dialog.text = DLG_TEXT[106];
			link.l1 = DLG_TEXT[107];
			link.l1.go = "resque_danielle_10";
		break;

		case "resque_danielle_10":
			dialog.text = pchar.name + DLG_TEXT[108];
			link.l1 = DLG_TEXT[109];
			link.l1.go = "resque_danielle_11";
		break;

		case "resque_danielle_11":
			dialog.text = DLG_TEXT[110];
			link.l1 = DLG_TEXT[111];
			link.l1.go = "resque_danielle_12";
		break;

		case "resque_danielle_12":
			dialog.text = DLG_TEXT[112] + pchar.name + DLG_TEXT[113];
			link.l1 = DLG_TEXT[114];
			link.l1.go = "resque_danielle_13";
		break;

		case "resque_danielle_13":
			dialog.text = DLG_TEXT[115] + pchar.name + DLG_TEXT[116];
			link.l1 = DLG_TEXT[117];
			link.l1.go = "resque_danielle_14";
		break;

		case "resque_danielle_14":
			dialog.text = DLG_TEXT[118] + characters[GetCharacterIndex(DLG_TEXT[119])].lastname + DLG_TEXT[120];
			link.l1 = DLG_TEXT[121];
			link.l1.go = "resque_danielle_15";
		break;

		case "resque_danielle_15":
			dialog.text = DLG_TEXT[122];
			link.l1 = DLG_TEXT[123];
			link.l1.go = "resque_danielle_16";
		break;

		case "resque_danielle_16":
			dialog.text = DLG_TEXT[124];
			link.l1 = DLG_TEXT[125];
			link.l1.go = "resque_danielle_17";
		break;

		case "resque_danielle_17":
			dialog.text = DLG_TEXT[126];
			link.l1 = DLG_TEXT[127];
			link.l1.go = "resque_danielle_18";
		break;

		case "resque_danielle_18":
			dialog.text = DLG_TEXT[128] + pchar.name + DLG_TEXT[129];
			link.l1 = DLG_TEXT[130];
			link.l1.go = "officer_exit";
			pchar.quest.main_line = "to_secret_redmond_shore";
			pchar.quest.to_muelle.win_condition.l1 = "location";
			pchar.quest.to_muelle.win_condition.l1.location = "Muelle_town_01";
			pchar.quest.to_muelle.win_condition = "to_muelle_complete";
			AddQuestRecord("search_danielle", "23");
			CloseQuestHeader("search_danielle");
			SetQuestHeader("revenge_for_silehard");
			AddQuestRecord("revenge_for_silehard", "1");
		break;

		case "officer_exit":
			SetCompanionIndex(pchar, -1, GetCharacterIndex(npchar.id));
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("resque_danielle");
		break;

		case "prepare_to_dagger":
			dialog.text = DLG_TEXT[131];
			link.l1 = DLG_TEXT[132];
			link.l1.go = "DAGGER";
		break;

		case "DAGGER":
			AddQuestrecord("again_find_rheims", "6");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("dagger");
		break;

		case "runaway":			
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			
			AddDialogExitQuest("prepare_danielle_with_rheims_runaway_complete");
		break;

		case "vincent_away_from_douwesen_tavern":
			dialog.text = DLG_TEXT[133];
			link.l1 = DLG_TEXT[134];
			link.l1.go = "vincent_away_from_douwesen_tavern_2";
		break;

		case "vincent_away_from_douwesen_tavern_2":
			dialog.text = DLG_TEXT[135] + pchar.name + DLG_TEXT[136];
			link.l1 = DLG_TEXT[137] + npchar.name + DLG_TEXT[138];
			link.l1.go = "vincent_away_from_douwesen_tavern_3";
		break;

		case "vincent_away_from_douwesen_tavern_3":
			dialog.text = DLG_TEXT[139] + characters[GetCharacterIndex(DLG_TEXT[140])].lastname + DLG_TEXT[141];
			link.l1 = DLG_TEXT[142];
			link.l1.go = "exit";
			pchar.quest.main_line = "talk_with_rheims_in_douwesen_tavern";
		break;

		case "blaze_goto_douwesen_with_danielle":
			dialog.text = DLG_TEXT[143] + pchar.name + DLG_TEXT[144] + characters[GetCharacterIndex(DLG_TEXT[145])].lastname + DLG_TEXT[146];
			link.l1 = DLG_TEXT[147];
			link.l1.go = "exit";
		break;

		case "blaze_search_rheims_with_danielle_2":
			dialog.text = DLG_TEXT[148];
			link.l1 = DLG_TEXT[149] + characters[GetCharacterIndex(DLG_TEXT[150])].name + DLG_TEXT[151];
			link.l1.go = "blaze_search_rheims_with_danielle_3";
		break;

		case "blaze_search_rheims_with_danielle_3":
			dialog.text = DLG_TEXT[152];
			link.l1 = DLG_TEXT[153] + characters[getCharacterIndex(DLG_TEXT[154])].name + DLG_TEXT[155];
			link.l1.go = "blaze_search_rheims_with_danielle_4";
		break;

		case "blaze_search_rheims_with_danielle_4":
			dialog.text = DLG_TEXT[156];
			link.l1 = DLG_TEXT[157];
			link.l1.go = "blaze_search_rheims_with_danielle_5";
		break;

		case "blaze_search_rheims_with_danielle_5":
			dialog.text = DLG_TEXT[158] + characters[getCharacterIndex(DLG_TEXT[159])].name + DLG_TEXT[160];
			link.l1 = DLG_TEXT[161];
			link.l1.go = "blaze_search_rheims_with_danielle_6";
			AddQuestrecord("again_find_rheims", "3");
		break;

		case "blaze_search_rheims_with_danielle_6":
			if (SetCompanionIndex(pchar, -1, GetCharacterIndex(npchar.id)) == GetCharacterIndex(npchar.id))
			{
				dialog.text = DLG_TEXT[162];
				link.l1 = DLG_TEXT[163];
				link.l1.go = "exit";
				pchar.quest.main_line = "danielle_wait_for_remove_companion";
			}
			else
			{
				dialog.text = DLG_TEXT[164];
				link.l1 = DLG_TEXT[165];
				link.l1.go = "exit";
				AddDialogExitQuest("danielle_join_to_us_when_we_are_swimm_to_douwesen_fo_search_rheims");
			}
		break;

		case "speak_danielle_in_lighthouse_prepare_to_search_rheims_2":
			dialog.text = DLG_TEXT[166] + pchar.name + DLG_TEXT[167];
			link.l1 = DLG_TEXT[168];
			link.l1.go = "speak_danielle_in_lighthouse_prepare_to_search_rheims_3";
		break;

		case "speak_danielle_in_lighthouse_prepare_to_search_rheims_3":
			dialog.text = DLG_TEXT[169];
			link.l1  = DLG_TEXT[170];
			link.l1.go = "first_exit_from_lighthouse";
			pchar.quest.main_line = "blaze_again_find_rheims";
			SetQuestHeader("again_find_rheims");
			AddQuestRecord("again_find_rheims", "1");
		break;

		case "first_exit_from_lighthouse":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			locations[FindLocation("Oxbay_Lighthouse")].reload.l1.disable = 0;
		break;

		case "meet_danielle_in_lighthouse_2":
			dialog.text = DLG_TEXT[171] + pchar.name + DLG_TEXT[172];
			link.l1 = DLG_TEXT[173];
			link.l1.go = "meet_danielle_in_lighthouse_3";
		break;

		case "meet_danielle_in_lighthouse_3":
			dialog.text = DLG_TEXT[174] + pchar.name + DLG_TEXT[175] + characters[GetCharacterIndex(DLG_TEXT[176])].name + DLG_TEXT[177] + characters[GetCharacterIndex(DLG_TEXT[178])].name + " " + characters[GetCharacterIndex(DLG_TEXT[179])].lastname + DLG_TEXT[180];
			link.l1 = DLG_TEXT[181];
			link.l1.go = "meet_danielle_in_lighthouse_4";
		break;

		case "meet_danielle_in_lighthouse_4":
			dialog.text = DLG_TEXT[182];
			link.l1 = DLG_TEXT[183];
			link.l1.go = "meet_danielle_in_lighthouse_5";
		break;

		case "meet_danielle_in_lighthouse_5":
			dialog.text = DLG_TEXT[184] + pchar.lastname + DLG_TEXT[185];
			link.l1 = DLG_TEXT[186] + npchar.name + DLG_TEXT[187] + characters[GetCharacterIndex(DLG_TEXT[188])].lastname + DLG_TEXT[189];
			link.l1.go = "meet_danielle_in_lighthouse_6";
		break;

		case "meet_danielle_in_lighthouse_6":
			dialog.text = DLG_TEXT[190] + characters[GetCharacterIndex(DLG_TEXT[191])].name + DLG_TEXT[192];
			link.l1 = DLG_TEXT[193];
			link.l1.go = "meet_danielle_in_lighthouse_7";
		break;

		case "meet_danielle_in_lighthouse_7":
			dialog.text = DLG_TEXT[194] + pchar.name + DLG_TEXT[195];
			link.l1 = DLG_TEXT[196] + npchar.name + DLG_TEXT[197] + characters[GetCharacterIndex(DLG_TEXT[198])].name + DLG_TEXT[199] + characters[GetCharacterIndex(DLG_TEXT[200])].lastname + DLG_TEXT[201];
			link.l1.go = "meet_danielle_in_lighthouse_8";
		break;

		case "meet_danielle_in_lighthouse_8":
			dialog.text = DLG_TEXT[202];
			link.l1 = DLG_TEXT[203];
			link.l1.go = "exit";
			pchar.quest.main_line = "meet_Vincent_in_lighthouse";
		break;

		case "talk_in_tavern":
			Dialog.Text = DLG_TEXT[204] + characters[GetCharacterIndex(DLG_TEXT[205])].name + DLG_TEXT[206];
			Link.l1 = DLG_TEXT[207];
			Link.l1.go = "exit";
			AddDialogExitQuest("prepare_to_battle_in_quest_redmond_tavern");
		break;

		case "talk_in_tavern_1":
			Dialog.Text = DLG_TEXT[208] + pchar.name + DLG_TEXT[209];
			link.l1 = DLG_TEXT[210];
			link.l1.go = "talk_in_tavern_2";
		break;

		case "talk_in_tavern_2":
			dialog.text = DLG_TEXT[211];
			link.l1 = DLG_TEXT[212];
			link.l1.go = "exit";
			AddDialogExitQuest("danielle_exit_from_tavern_danielle");
		break;

		case "MetBlazeOnIslaMuelle":
			Dialog.defAni = "";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";
						
			NextDiag.TempNode = "first time";

			dialog.text = Pchar.name + DLG_TEXT[213];
			Link.l1 = Npchar.name + DLG_TEXT[214];
			Link.l1.go = "MetBlazeOnIslaMuelle_1";
		break;

		case "MetBlazeOnIslaMuelle_1":
			Dialog.Text = DLG_TEXT[215];
			Link.l1 = DLG_TEXT[216];
			Link.l1.go = "MetBlazeOnIslaMuelle_2";
		break;

		case "MetBlazeOnIslaMuelle_2":
			Dialog.Text = DLG_TEXT[217];
			Link.l1 = DLG_TEXT[218];
			Link.l1.go = "MetBlazeOnIslaMuelle_3";
		break;

		case "MetBlazeOnIslaMuelle_3":
			Dialog.Text = DLG_TEXT[219];
			Link.l1 = DLG_TEXT[220];
			Link.l1.go = "MetBlazeOnIslaMuelle_4";
		break;

		case "MetBlazeOnIslaMuelle_4":
			Dialog.Text = DLG_TEXT[221];
			Link.l1 = DLG_TEXT[222] + NPChar.name + DLG_TEXT[223];
			Link.l1.go = "MetBlazeOnIslaMuelle_5";
		break;

		case "MetBlazeOnIslaMuelle_5":
			Dialog.Text = DLG_TEXT[224];
			Link.l1 = DLG_TEXT[225];
			Link.l1.go = "MetBlazeOnIslaMuelle_6";
		break;

		case "MetBlazeOnIslaMuelle_6":
			Dialog.Text = DLG_TEXT[226];
			Link.l1 = DLG_TEXT[227];
			Link.l1.go = "MetBlazeOnIslaMuelle_7";
		break;

		case "MetBlazeOnIslaMuelle_7":
			Dialog.Text = DLG_TEXT[228];
			Link.l1 = DLG_TEXT[229];
			Link.l1.go = "MetBlazeOnIslaMuelle_Exit";
		break;


		case "Talk_upstairs":
			Dialog.Text = DLG_TEXT[230];
			Link.l1 = DLG_TEXT[231] + Npchar.name + DLG_TEXT[232];
			Link.l1.go = "Talk_upstairs_1";
		break;

		case "Talk_upstairs_1":
			Dialog.Text = DLG_TEXT[233] + PChar.name + DLG_TEXT[234];
			Link.l1 = DLG_TEXT[235];
			Link.l1.go = "Talk_upstairs_2";
		break;

		case "Talk_upstairs_2":
			Dialog.Text = DLG_TEXT[236];
			Link.l1 = DLG_TEXT[237];
			Link.l1.go = "Talk_upstairs_3";
		break;

		case "Talk_upstairs_3":
			Dialog.Text = DLG_TEXT[238];
			Link.l1 = DLG_TEXT[239] + Characters[getCharacterIndex(DLG_TEXT[240])].name + DLG_TEXT[241];
			Link.l1.go = "Talk_upstairs_4";
		break;

		case "Talk_upstairs_4":
			Dialog.Text = DLG_TEXT[242];
			Link.l1 = DLG_TEXT[243];
			Link.l1.go = "Talk_upstairs_Exit";
		break;

		case "MetInMuellePort":
			Dialog.Text = DLG_TEXT[244];
			Link.l1 = DLG_TEXT[245];
			Link.l1.go = "MetInMuellePort_1";
		break;

		case "MetInMuellePort_1":
			Dialog.Text = DLG_TEXT[246];
			Link.l1 = DLG_TEXT[247];
			Link.l1.go = "MetInMuellePort_Exit";
		break;

		case "MetInMuellePort_1":
			Dialog.Text = DLG_TEXT[248];
			Link.l1 = DLG_TEXT[249];
			Link.l1.go = "MetInMuellePort_Exit";
		break;


		case "CaptureGreenford":
			Dialog.Text = DLG_TEXT[250] + Characters[getCharacterIndex(DLG_TEXT[251])].name + DLG_TEXT[252];
			Link.l1 = DLG_TEXT[253];
			Link.l1.go = "CaptureGreenford_1";
		break;

		case "CaptureGreenford_1":
			Dialog.Text = DLG_TEXT[254];
			Link.l1 = DLG_TEXT[255];
			Link.l1.go = "CaptureGreenford_2";
		break;

		case "CaptureGreenford_2":
			Dialog.Text = DLG_TEXT[256];
			Link.l1 = DLG_TEXT[257];
			Link.l1.go = "CaptureGreenford_3";
		break;

		case "CaptureGreenford_3":
			Dialog.Text = DLG_TEXT[258];
			Link.l1 = DLG_TEXT[259];
			Link.l1.go = "CaptureGreenford_4";
		break;

		case "CaptureGreenford_4":
			Dialog.Text = DLG_TEXT[260];
			Link.l1 = DLG_TEXT[261];
			Link.l1.go = "CaptureGreenford_5";
		break;
	
		case "CaptureGreenford_5":
			NextDiag.TempNode = "GoToShip";
			Dialog.Text = DLG_TEXT[262];
			Link.l1 = DLG_TEXT[263];
			Link.l1.go = "CaptureGreenford_exit";
			Link.l2 = DLG_TEXT[264];
			Link.l2.go = "We_Are_ready_exit";
		break;

		case "CaptureGreenford_5":
			NextDiag.TempNode = "KickTheAss";
			Dialog.Text = DLG_TEXT[265];
			Link.l1 = DLG_TEXT[266];
			Link.l1.go = "We_Are_ready_exit";
			Link.l2 = DLG_TEXT[267];
			Link.l2.go = "CaptureGreenford_exit";
		break;

		case "KickTheAss":
			NextDiag.TempNode = "KickTheAss";
			Dialog.Text = DLG_TEXT[268];
			Link.l1 = DLG_TEXT[269];
			Link.l1.go = "Exit";
		break;

		case "GoToShip":
			Dialog.Text = DLG_TEXT[270] + PChar.name + DLG_TEXT[271];
			Link.l1 = DLG_TEXT[272];
			Link.l1.go = "Exit";
		break;
		
		case "WaitUntilReady":
			Dialog.Text = DLG_TEXT[273];
			Link.l1 = DLG_TEXT[274];
			Link.l1.go = "Exit";
		break;

		case "Are_we_ready":
			Dialog.Text = DLG_TEXT[275];
			Link.l1 = DLG_TEXT[276];
			Link.l1.go = "Are_we_ready_3";
			Link.l2 = DLG_TEXT[277];
			Link.l2.go = "Are_we_ready_2";
		break;

		case "Are_we_ready_2":
			Dialog.Text = DLG_TEXT[278] + PChar.name + DLG_TEXT[279];
			Link.l1 = DLG_TEXT[280];
			Link.l1.go = "We_Are_not_ready_exit";
		break;

		case "Are_we_ready_3":
			Dialog.Text = DLG_TEXT[281];
			Link.l1 = DLG_TEXT[282];
			Link.l1.go = "Are_we_ready_4";
		break;

		case "Are_we_ready_4":
			Dialog.Text = DLG_TEXT[283] + PChar.name + DLG_TEXT[284];
			Link.l1 = DLG_TEXT[285] + NPChar.name + DLG_TEXT[286];
			Link.l1.go = "We_Are_Ready_Exit";
		break;

		case "Greenford_captured":
			Dialog.Text = DLG_TEXT[287];
			Link.l1 = DLG_TEXT[288];
			Link.l1.go = "Greenford_captured_1";
		break;

		case "Greenford_captured_1":
			NextDiag.TempNode = "MovingToPrison";
			Dialog.Text = DLG_TEXT[289];
			Link.l1 = DLG_TEXT[290] + Characters[GetCharacterIndex(DLG_TEXT[291])].name + DLG_TEXT[292];
			Link.l1.go = "Greenford_captured_exit";
		break;

		case "MovingToPrison":
			NextDiag.TempNode = "MovingToPrison";
			Dialog.Text = PChar.name + DLG_TEXT[293];
			Link.l1 = DLG_TEXT[294];
			Link.l1.go = "Exit";
		break;

		case "BeforeEnglishSiege":
			NextDiag.TempNode = "RepelTheSiege";
			Dialog.Text = DLG_TEXT[295];
			Link.l1 = Characters[GetCharacterIndex(DLG_TEXT[296])].name + DLG_TEXT[297];
			Link.l1.go = "BeforeEnglishSiege_1";
		break;

		case "BeforeEnglishSiege_1":
			Dialog.Text = DLG_TEXT[298];
			Link.l1 = DLG_TEXT[299];
			Link.l1.go = "BeforeEnglishSiege_2";
		break;

		case "BeforeEnglishSiege_2":
			Dialog.Text = DLG_TEXT[300];
			Link.l1 = DLG_TEXT[301];
			Link.l1.go = "BeforeEnglishSiege_3";
		break;

		case "BeforeEnglishSiege_3":
			Dialog.Text = DLG_TEXT[302] + Pchar.name + DLG_TEXT[303];
			Link.l1 = DLG_TEXT[304];
			Link.l1.go = "BeforeEnglishSiege_4";
		break;

		case "BeforeEnglishSiege_4":
			Dialog.Text = DLG_TEXT[305];
			Link.l1 = DLG_TEXT[306];
			Link.l1.go = "BeforeEnglishSiege_5";
		break;

		case "BeforeEnglishSiege_5":
			Dialog.Text = DLG_TEXT[307];
			Link.l1 = DLG_TEXT[308];
			Link.l1.go = "BeforeEnglishSiege_exit";
		break;

		case "RepelEnglishAssault":
			Dialog.defAni = "dialog_stay1";
			//Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			//Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			//Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";

			Dialog.Text = DLG_TEXT[309];
			Link.l1 = DLG_TEXT[310];
			Link.l1.go = "RepelEnglishAssault_1";
		break;

		case "RepelEnglishAssault_1":
			NextDiag.tempNode = "Must_Hurry_to_Fort";			
			Dialog.Text = DLG_TEXT[311];
			Link.l1 = DLG_TEXT[312];
			Link.l1.go = "RepelEnglishAssault_exit";
		break;

		case "AfterGreenfordSiege":
			Dialog.Text = DLG_TEXT[313];
			Link.l1 = DLG_TEXT[314] + Characters[GetCharacterindex(DLG_TEXT[315])].name + DLG_TEXT[316];
			Link.l1.go = "AfterGreenfordSiege_1";
		break;

		case "AfterGreenfordSiege_1":
			NextDiag.tempNode = "PayVisitToResearcher";
			Dialog.Text = DLG_TEXT[317] + PChar.name + DLG_TEXT[318];
			Link.l1 = DLG_TEXT[319];
			Link.l1.go = "AfterGreenfordSiege_exit";
		break;

		case "PayVisitToResearcher":
			Dialog.Text = DLG_TEXT[320];
			Link.l1 = DLG_TEXT[321];
			Link.l1.go = "Exit";
		break;

		case "Temple":
			NextDiag.TempNode = "GoGoGo";
			Dialog.Text = PChar.name + DLG_TEXT[322];
			Link.l1 = DLG_TEXT[323];
			Link.l1.go = "Temple_exit";
		break;

		case "Gogogo":
			NextDiag.TempNode = "GoGoGo";
			Dialog.Text = DLG_TEXT[324];
			Link.l1 = DLG_TEXT[325];
			Link.l1.go = "Gogogo_1";
		break;

		case "Gogogo_1":
			Dialog.Text = DLG_TEXT[326];
			Link.l1 = DLG_TEXT[327];
			Link.l1.go = "Exit";
		break;

		case "Split":
			Dialog.Text = DLG_TEXT[328];
			Link.l1 = DLG_TEXT[329] + Characters[GetCharacterIndex(DLG_TEXT[330])].name + DLG_TEXT[331];
			Link.l1.go = "Split_exit";
		break;

		case "I'm going on left":
			Dialog.Text = DLG_TEXT[332];
			Link.l1 = DLG_TEXT[333];
			Link.l1.go = "I'm going on left_exit";
		break;

		case "ReadyForKhaelRoa":
			Dialog.TempNode = "ReadyForKhaelRoa";
			Dialog.Text = DLG_TEXT[334];
			Link.l1 = DLG_TEXT[335];
			Link.l1.go = "exit";
		break;

		case "ITakeTheStone":
			Dialog.Text = DLG_TEXT[336];
			Link.l1 = DLG_TEXT[337];
			Link.l1.go = "ITakeTheStone_1";
		break;

		case "ITakeTheStone_1":
			Dialog.Text = DLG_TEXT[338];
			Link.l1 = DLG_TEXT[339];
			Link.l1.go = "ITakeTheStone_exit";
		break;

		case "ITakeTheStone_exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;	
			AddDialogExitQuest("Story_ITakeTheStone");
		break;

		case "Treasure_room":
			Dialog.TempNode = "ReadyForKhaelRoa";
			Dialog.Text = DLG_TEXT[340] + Characters[GetCharacterIndex(DLG_TEXT[341])].name + DLG_TEXT[342];
			Link.l1 = DLG_TEXT[343];
			Link.l1.go = "Treasure_room_exit";
		break;

		case "Must_Hurry_to_Fort":
			Dialog.TempNode = "Must_Hurry_to_Fort";
			Dialog.Text = DLG_TEXT[344] + Pchar.name + DLG_TEXT[345];
			Link.l1 = DLG_TEXT[346];
			Link.l1.go = "Must_Hurry_to_Fort_1";
		break;

		case "Must_Hurry_to_Fort_1":
			Dialog.Text = DLG_TEXT[347] + Pchar.name + DLG_TEXT[348];
			Link.l1 = DLG_TEXT[349];
			Link.l1.go = "RepelEnglishAssault_again_exit";
		break;

		case "WhatWasThat":
			Dialog.TempNode = "OMyTreasure";
			Dialog.Text = DLG_TEXT[350];
			Link.l1 = DLG_TEXT[351];
			Link.l1.go = "exit";
			AddDialogExitQuest("Story_ResearcherExplainsInTemple");
		break;

		case "OMyTreasure":
			Dialog.TempNode = "OMyTreasure";
			Dialog.Text = DLG_TEXT[352] + Pchar.name + DLG_TEXT[353];
			Link.l1 = DLG_TEXT[354];
			Link.l1.go = "OMyTreasure_1";			
		break;

		case "OMyTreasure_1":
			Dialog.Text = DLG_TEXT[355];
			Link.l1 = DLG_TEXT[356];
			Link.l1.go = "exit";			
		break;

		case "TooDangerous":
			Dialog.Text = DLG_TEXT[357];
			Link.l1 = " ";
			Link.l1.go = "exit";			
		break;

		case "ThinkingAboutQuebradas":
			AddDialogExitQuest("Fem_ReadyToleaveRedmondForQuebradas");
			Dialog.Text = DLG_TEXT[358] + Characters[GetCharacterIndex(DLG_TEXT[359])].name + DLG_TEXT[360] + Characters[getCharacterIndex(DLG_TEXT[361])].lastname + DLG_TEXT[362] + Characters[getCharacterIndex(DLG_TEXT[363])].lastname + DLG_TEXT[364] + Characters[getCharacterIndex(DLG_TEXT[365])].lastname + DLG_TEXT[366] + Characters[getCharacterIndex(DLG_TEXT[367])].lastname + DLG_TEXT[368];
			Link.l1 = " ";
			Link.l1.go = "exit";			
		break;

		case "RheimsLogBook":			
			Dialog.Text = DLG_TEXT[369] + Characters[GetCharacterIndex(DLG_TEXT[370])].lastname + DLG_TEXT[371] + Characters[GetCharacterIndex(DLG_TEXT[372])].lastname + DLG_TEXT[373] + Characters[GetCharacterIndex(DLG_TEXT[374])].name + DLG_TEXT[375] + Characters[GetCharacterIndex(DLG_TEXT[376])].name + DLG_TEXT[377];
			Link.l1 = DLG_TEXT[378];
			Link.l1.go = "RheimsLogBook_2";			
			Link.l2 = DLG_TEXT[379];
			Link.l2.go = "RheimsLogBook_1";			
		break;

		case "RheimsLogBook_1":			
			Dialog.Text = DLG_TEXT[380];
			Link.l1 = " ";
			Link.l1.go = "exit";			
		break;

		case "RheimsLogBook_2":			
			Dialog.Text = DLG_TEXT[381] + Characters[GetCharacterIndex(DLG_TEXT[382])].name + DLG_TEXT[383];
			Link.l1 = " ";
			Link.l1.go = "exit";			
		break;

		
		case "Treasure_room_exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;	
			AddDialogExitQuest("Story_ResearcherTalkInAlcove");
		break;

		case "I'm going on left_exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;			
			AddDialogExitQuest("Story_DanielleWentIntoLeftPassage");
		break;

		case "Split_exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Danielle_split_exit");
		break;

		case "Temple_exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		
			DoQuestCheckDelay("Story_ResearcherSpeaksonKhaelRoaBeach", 1);
		break;

		case "AfterGreenfordSiege_exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("danielle_AfterGreenfordSiege_exit");
		break;

		case "RepelEnglishAssault_again_exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("danielle_RepelEnglishAssault_again_exit");
		break;

		
		case "RepelEnglishAssault_exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("danielle_RepelEnglishAssault_exit");
		break;


		case "BeforeEnglishSiege_exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

			AddDialogExitQuest("danielle_BeforeEnglishSiege_exit");
		break;

		case "Greenford_captured_exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

			AddDialogExitQuest("danielle_Greenford_captured_exit");
		break;

		case "We_Are_not_ready_exit":
			Characters[GetCharacterIndex("Danielle")].Dialog.CurrentNode = "WaitUntilReady";
			Pchar.quest.Story_PrepareToSiegeGreenford.win_condition.l1 = "location";
			Pchar.quest.Story_PrepareToSiegeGreenford.win_condition.l1.location = "Oxbay";
			Pchar.quest.Story_PrepareToSiegeGreenford.win_condition = "Story_PrepareToSiegeGreenford";
			Pchar.quest.Story_PrepareToSiegeGreenford.fail_condition = "Story_PrepareToSiegeGreenford";

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "We_Are_ready_exit":
			EndQuestMovie();
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			SetQuestHeader("Capture_greenford");
			AddQuestRecord("Capture_greenford", "2");

			AddDialogExitQuest("Story_GreenfordAssaultStarted");
		break;

		case "CaptureGreenford_exit":
			SetQuestHeader("Capture_greenford");
			AddQuestRecord("Capture_greenford", "1");

			Pchar.quest.Story_PrepareToSiegeGreenford.win_condition.l1 = "location";
			Pchar.quest.Story_PrepareToSiegeGreenford.win_condition.l1.location = "Oxbay";
			Pchar.quest.Story_PrepareToSiegeGreenford.win_condition = "Story_PrepareToSiegeGreenford";
			Pchar.quest.Story_PrepareToSiegeGreenford.fail_condition = "Story_PrepareToSiegeGreenford";

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "MetBlazeOnIslaMuelle_Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("danielle_MetBlazeOnIslaMuelle_Exit");
		break;

		case "MetInMuellePort_Exit":			
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("danielle_MetInMuellePort_Exit");
			/*Pchar.quest.Story_DanielleGoesToBlazeShip.win_condition.l1 = "locator";
			Pchar.quest.Story_DanielleGoesToBlazeShip.win_condition.l1.character = "Danielle";
			Pchar.quest.Story_DanielleGoesToBlazeShip.win_condition.l1.location = "Muelle_port";
			Pchar.quest.Story_DanielleGoesToBlazeShip.win_condition.l1.locator_group = "Reload";
			Pchar.quest.Story_DanielleGoesToBlazeShip.win_condition.l1.locator = "Reload3";
			Pchar.quest.Story_DanielleGoesToBlazeShip.win_condition = "Story_DanielleGoesToBlazeShip";
			Pchar.quest.Story_DanielleGoesToBlazeShip.fail_condition = "Story_DanielleGoesToBlazeShip";
			//ActGotoLocator(NPChar, "Reload", "reload3",1);*/
		break;


		case "Talk_upstairs_Exit":
			AddDialogExitQuest("danielle_Talk_upstairs_Exit");
			
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
		

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}

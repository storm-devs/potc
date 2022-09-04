//nclude "DIALOGS\Robert Christopher Silehard_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_meeting;
	int Itest;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);

	trace ("----------------------------------" + Dialog.CurrentNode);
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча

		case "exit":
			NPChar.quest.meeting = NPC_meeting; 
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;

		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay1";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";

			if (NPChar.quest.meeting == "0")
			{
				d.Text = DLG_TEXT[0];
				Link.l1 = DLG_TEXT[1] + PChar.name + " " + PChar.lastname + DLG_TEXT[2] + PChar.ship.name + DLG_TEXT[3];
				Link.l1.go = "meeting";	
				NPC_meeting = "1";
			}
			else
			{
				dialog.snd1 = "";
				dialog.snd2 = "";
				dialog.snd3 = "";
				d.Text = RandPhrase(DLG_TEXT[4] + PChar.name + DLG_TEXT[5], DLG_TEXT[6] + PChar.name + DLG_TEXT[7], DLG_TEXT[8] + PChar.name + DLG_TEXT[9], &dialog, dialog.snd1, dialog.snd2, dialog.snd3);
				Link.l1 = DLG_TEXT[10];
				Link.l1.go = "quest lines";
				Link.l2 = DLG_TEXT[11];
				Link.l2.go = "random quests";
				Link.l3 = DLG_TEXT[12];
				Link.l3.go = "exit";	
			}
		break;

		case "Meeting":
			d.Text = DLG_TEXT[13] + PChar.name + DLG_TEXT[14];
			Link.l1 = DLG_TEXT[15];
			Link.l1.go = "Story_Oxbay_Captured";
		break;

		case "Quest Lines":
			iTest = 0;
			if (pchar.quest.main_line == "blaze_again_find_rheims" && iTest < QUEST_COUNTER)
			{
				dialog.text = DLG_TEXT[16];
				link.l1 = DLG_TEXT[17];
				link.l1.go = "blaze_again_find_rheims_2";
				iTest = iTest + 1;
			}
			else
			{
				d.Text = DLG_TEXT[18];
				Link.l99 = DLG_TEXT[19];
				Link.l99.go = "No quest";
				if(CheckQuestAttribute("Story_1stTaskComplete", "1"))
				{
					Link.l1 = DLG_TEXT[20];
					Link.l1.go = "Story_1stTaskComplete";
				}
				if(CheckQuestAttribute("Story_1stTaskComplete", "Complete"))
				{
					Link.l1 = DLG_TEXT[21];
					Link.l1.go = "Story_2ndTask";
				}	
			}
		break;

		case "Random Quests":
			d.Text = DLG_TEXT[22];
			Link.l1 = DLG_TEXT[23];
			Link.l1.go = "quest lines";
			Link.l2 = DLG_TEXT[24];
			Link.l2.go = "exit";	
		break;

		case "No quest":
			d.Text = DLG_TEXT[25] + PChar.name + DLG_TEXT[26];
			Link.l2 = DLG_TEXT[27];
			Link.l2.go = "random quests";
			Link.l3 = DLG_TEXT[28];
			Link.l3.go = "exit";	
		break;

		case "Pirates_killed":
			d.Text = DLG_TEXT[29];
			Link.l1 = DLG_TEXT[30];
			Link.l1.go = "Pirates_killed_1";
		break;

		case "Pirates_killed_1":
			AddMoneyToCharacter(pchar, 5000);
			PChar.quest.killed.pirates = "0";
			d.Text = DLG_TEXT[31];
			Link.l1 = DLG_TEXT[32];
			Link.l1.go = "Quest Lines";
			Link.l2 = DLG_TEXT[33];
			Link.l2.go = "random quests";
			Link.l3 = DLG_TEXT[34] + NPChar.name + DLG_TEXT[35];
			Link.l3.go = "exit";	
		break;
	
		case "Story_Oxbay_Captured":
			d.Text = DLG_TEXT[36];
			Link.l1 = DLG_TEXT[37];
			Link.l1.go = "Story_Oxbay_Captured_1";
		break;
	
		case "Story_Oxbay_Captured_1":
			d.Text = DLG_TEXT[38];
			Link.l1 = DLG_TEXT[39];
			Link.l1.go = "Story_Oxbay_Captured_2";
		break;

		case "Story_Oxbay_Captured_2":
			d.Text = DLG_TEXT[40] + PChar.name + DLG_TEXT[41];
			Link.l1 = DLG_TEXT[42];
			Link.l1.go = "Story_Oxbay_Captured_3";
			Link.l2 = DLG_TEXT[43];
			Link.l2.go = "Story_Oxbay_Captured_4";
			Link.l3 = DLG_TEXT[44];
			Link.l3.go = "Story_Oxbay_Captured_5";	
		break;

		case "Story_Oxbay_Captured_3":
			d.Text = DLG_TEXT[45];
			Link.l1 = DLG_TEXT[46];
			Link.l1.go = "Story_Oxbay_Captured_6";
		break;

		case "Story_Oxbay_Captured_4":
			d.Text = DLG_TEXT[47];
			Link.l1 = DLG_TEXT[48];
			Link.l1.go = "Story_Oxbay_Captured_7";
		break;

		case "Story_Oxbay_Captured_5":
			d.Text = DLG_TEXT[49] + PChar.name + DLG_TEXT[50];
			Link.l1 = DLG_TEXT[51];
			Link.l1.go = "Story_Oxbay_Captured_3";
		break;

		case "Story_Oxbay_Captured_6":
			d.Text = DLG_TEXT[52];
			Link.l1 = DLG_TEXT[53];
			Link.l1.go = "Story_Oxbay_Captured_8";
			Link.l2 = DLG_TEXT[54];
			Link.l2.go = "Story_Oxbay_Captured_9";
		break;

		case "Story_Oxbay_Captured_7":
			d.Text = DLG_TEXT[55] + PChar.name + DLG_TEXT[56];
			Link.l1 = DLG_TEXT[57];
			Link.l1.go = "Story_Oxbay_Captured_3";
		break;

		case "Story_Oxbay_Captured_8":
			d.Text = DLG_TEXT[58] + PChar.name + DLG_TEXT[59];
			Link.l1 = DLG_TEXT[60];
			Link.l1.go = "Story_Oxbay_Captured_10";
		break;

		case "Story_Oxbay_Captured_9":
			d.Text = DLG_TEXT[61];
			Link.l1 = RandSwear() + DLG_TEXT[62];
			Link.l1.go = "Story_Oxbay_Captured_8";
		break;

		case "Story_Oxbay_Captured_10":
			d.Text = DLG_TEXT[63];
			Link.l1 = DLG_TEXT[64];
			Link.l1.go = "Story_Oxbay_Captured_11";
			Link.l2 = DLG_TEXT[65];
			Link.l2.go = "Story_Oxbay_Captured_12";
		break;

		case "Story_Oxbay_Captured_11":
			d.Text = DLG_TEXT[66];
			Link.l1 = DLG_TEXT[67];
			Link.l1.go = "Story_Oxbay_Captured_13";
			Link.l2 = DLG_TEXT[68];
			Link.l2.go = "Story_Oxbay_Captured_12";
		break;

		case "Story_Oxbay_Captured_12":
			If(makeint(Pchar.skill.commerce) > 1)
			{
				d.Text = DLG_TEXT[69];
				Link.l1 = DLG_TEXT[70];
				Link.l1.go = "Story_Oxbay_Captured_14";
			}
			else
			{
				d.Text = DLG_TEXT[71] + Pchar.name + DLG_TEXT[72];
				Link.l1 = DLG_TEXT[73];
				Link.l1.go = "Story_Oxbay_Captured_14";
			}
		break;

		case "Story_Oxbay_Captured_13":
			d.Text = DLG_TEXT[74];
			Link.l1 = DLG_TEXT[75];
			Link.l1.go = "Story_Oxbay_Captured_15";
		break;

		case "Story_Oxbay_Captured_14":
			d.Text = DLG_TEXT[76];
			Link.l1 = DLG_TEXT[77];
			Link.l1.go = "Story_Oxbay_Captured_13";
		break;

		case "Story_Oxbay_Captured_15":
			d.Text = DLG_TEXT[78] + PChar.name + DLG_TEXT[79];
			Link.l1 = DLG_TEXT[80];
			Link.l1.go = "exit";
			AddDialogExitQuest("silehard_Story_Oxbay_Captured_15");
		break;

		case "Story_1stTaskComplete":
			d.Text = DLG_TEXT[81];
			Link.l1 = DLG_TEXT[82];
			Link.l1.go = "Story_1stTaskComplete_1";
		break;

		case "Story_1stTaskComplete_1":
			d.Text = DLG_TEXT[83];
			Link.l1 = DLG_TEXT[84];
			Link.l1.go = "Story_1stTaskComplete_2";
		break;

		case "Story_1stTaskComplete_2":
			PChar.quest.Story_1stTaskComplete = "2";
			Pchar.quest.Story_1stTaskPayment = "7000";
			AddMoneyToCharacter(Pchar,3000);
			AddCharacterExp(pchar, 1200);
			AddQuestRecord("Story_1stTaskReceived", "5");
			d.Text = DLG_TEXT[85] + Pchar.name + DLG_TEXT[86];
			Link.l1 = DLG_TEXT[87];
			Link.l1.go = "Story_1stTaskComplete_3";
		break;

		case "Story_1stTaskComplete_3":
			d.Text = DLG_TEXT[88];
			Link.l1 = DLG_TEXT[89];
			Link.l1.go = "Story_1stTaskComplete_4";
		break;

		case "Story_1stTaskComplete_4":
			d.Text = DLG_TEXT[90];
			Link.l1 = DLG_TEXT[91];
			Link.l1.go = "Story_1stTaskComplete_5";
			Link.l1 = DLG_TEXT[92] + NPChar.lastname + DLG_TEXT[93];
			Link.l1.go = "exit";
		break;

		case "Story_1stTaskComplete_5":
			d.Text = DLG_TEXT[94] + PChar.name + DLG_TEXT[95];
			Link.l1 = DLG_TEXT[96];
			Link.l1.go = "exit";
		break;

		case "Story_2ndTask":
			CloseQuestHeader("Story_1stTaskReceived");
			d.Text = DLG_TEXT[97] + Pchar.name + DLG_TEXT[98];
			Link.l1 = DLG_TEXT[99];
			Link.l1.go = "Story_2ndTask_1";
		break;

		case "Story_2ndTask_1":
			d.Text = DLG_TEXT[100];
			Link.l1 = DLG_TEXT[101];
			Link.l1.go = "Story_2ndTask_2";
		break;

		case "Story_2ndTask_2":
			d.Text = DLG_TEXT[102];
			Link.l1 = DLG_TEXT[103];
			Link.l1.go = "Story_2ndTask_3";
		break;

		case "Story_2ndTask_3":
			d.Text = DLG_TEXT[104];
			Link.l1 = DLG_TEXT[105];
			Link.l1.go = "Story_2ndTask_4";
		break;

		case "Story_2ndTask_4":
			d.Text = DLG_TEXT[106] + Characters[GetCharacterIndex(DLG_TEXT[107])].name + " " + Characters[GetCharacterIndex(DLG_TEXT[108])].lastname + DLG_TEXT[109] + Characters[GetCharacterIndex(DLG_TEXT[110])].name + DLG_TEXT[111];
			Link.l1 = DLG_TEXT[112];
			Link.l1.go = "Story_2ndTask_5";
		break;

		case "Story_2ndTask_5":
			d.Text = DLG_TEXT[113];
			Link.l1 = DLG_TEXT[114];
			Link.l1.go = "Story_2ndTask_6";
		break;

		case "Story_2ndTask_6":
			d.Text = DLG_TEXT[115];
			Link.l1 = DLG_TEXT[116];
			Link.l1.go = "Story_2ndTask_7";
		break;

		case "Story_2ndTask_7":
			d.Text = Characters[GetCharacterIndex(DLG_TEXT[117])].name + DLG_TEXT[118];
			Link.l1 = DLG_TEXT[119];
			Link.l1.go = "Story_2ndTask_8";
		break;

		case "Story_2ndTask_8":
			AddMoneyToCharacter(Pchar,makeint(Pchar.quest.Story_1stTaskPayment));
			Pchar.quest.Story_1stTaskPayment.over = "yes";
			d.Text = DLG_TEXT[120] + PChar.name + DLG_TEXT[121];
			Link.l1 = DLG_TEXT[122];
			Link.l1.go = "Story_2ndTask_9";
		break;

		case "Story_2ndTask_9":
			PChar.quest.Story_1stTaskComplete.over = "yes";
			ChangeCharacterAddressGroup(characterFromID("Ewan Glover"), "Redmond_port", "goto", "goto_2");
			SetCharacterShipLocation(characterFromID("Ewan Glover"), "Redmond_port");
			SetQuestHeader("Story_2ndTask");
			AddQuestRecord("Story_2ndTask", "1");
			Pchar.quest.Story_Meeting_Ewan_Glover.win_condition.l1 = "location";
			Pchar.quest.Story_Meeting_Ewan_Glover.win_condition.l1.location = "Redmond_port";
			Pchar.quest.Story_Meeting_Ewan_Glover.win_condition = "Story_Meeting_Ewan_Glover";

			d.Text = DLG_TEXT[123];
			Link.l1 = DLG_TEXT[124];
			Link.l1.go = "Exit";
			AddPartyExp(pchar, 4000);
		break;

		case "Story_2ndTask_complete":
			Diag.tempNode = "First time";
			PChar.quest.Story_2ndtask.over = "yes";
			AddQuestRecord("Story_2ndTask","12");
			CloseQuestHeader("Story_2ndTask");

			if(LAi_IsDead(characterFromID("Ewan Glover")))
			{
				Pchar.Quest.Story_Glover_sunk.over = "yes";	
				d.Text = DLG_TEXT[125] + Pchar.name + DLG_TEXT[126];
				Link.l1 = DLG_TEXT[127];
				Link.l1.go = "2nd_task_failed";
			}
			else
			{	
				d.text = DLG_TEXT[128];
				Link.l1 = DLG_TEXT[129];
				Link.l1.go = "2nd_task_Complete_1";
			}
		break;


		case "2nd_task_failed":
			d.Text = DLG_TEXT[130] + Characters[GetCharacterindex(DLG_TEXT[131])].name + DLG_TEXT[132];
			Link.l1 = DLG_TEXT[133] + address_form.eng + DLG_TEXT[134];
			Link.l1.go = "2nd_task_failed_1";	
		break;


		case "2nd_task_failed_1":
			d.Text = DLG_TEXT[135];
			Link.l1 =   DLG_TEXT[136];
			Link.l1.go =  "2nd_task_failed_2";	
		break;


		case "2nd_task_failed_2":
			addMoneytoCharacter(PChar, 5000);
			addMoneyTocharacter(Pchar, 6000);
			d.text =  DLG_TEXT[137];
			Link.l1 =  DLG_TEXT[138];
			Link.l1.go =   "2nd_task_failed_3";	
		break;


		case "2nd_task_failed_3":
			d.Text = DLG_TEXT[139];
			Link.l1 = DLG_TEXT[140];
			Link.l1.go = "2nd_task_failed_4";	
		break;

		case "2nd_task_failed_4":
			d.Text = DLG_TEXT[141];
			Link.l1 = DLG_TEXT[142];
			Link.l1.go = "Exit";	
			SetQuestHeader("Blaze_out_from_silehard");
			AddQuestRecord("Blaze_out_from_silehard", "1");
			AddDialogExitQuest("exit_from_silehard_complete");
			AddDialogExitQuest("pchar_back_to_player");
		break;

		case "2nd_Task_Complete_1":
			d.Text = Characters[GetCharacterIndex(DLG_TEXT[143])].name + DLG_TEXT[144]+ Characters[GetCharacterIndex(DLG_TEXT[145])].name + " " + Characters[GetCharacterIndex(DLG_TEXT[146])].lastname + DLG_TEXT[147];
			Link.l1 = DLG_TEXT[148];
			Link.l1.go = "2nd_Task_Complete_2";
		break;

		case "2nd_Task_Complete_2":
			addMoneyTocharacter(Pchar, 10000);
			d.text = DLG_TEXT[149];
			Link.l1 = DLG_TEXT[150];
			Link.l1.go = "2nd_Task_Complete_3";
		break;

		case "2nd_Task_Complete_3":
			d.Text = DLG_TEXT[151];
			link.l1 = DLG_TEXT[152];
			Link.l1.go = "2nd_Task_Complete_4";
		break;

		case "2nd_Task_Complete_4":
			d.Text = DLG_TEXT[153];
			Link.l1 = DLG_TEXT[154];
			Link.l1.go =  "exit";	
			SetQuestHeader("Blaze_out_from_silehard");
			AddQuestRecord("Blaze_out_from_silehard", "1");
			AddDialogExitQuest("exit_from_silehard_complete");
			AddDialogExitQuest("pchar_back_to_player");
		break;

//!!!!__________BY ARTEM!!!!!!!!!!!!!!
//!!!!__________BY ARTEM!!!!!!!!!!!!!!
//!!!!__________BY ARTEM!!!!!!!!!!!!!!


		case "both_talk_with_Silehard_node":
			Dialog.defAni = "dialog_stay1";
			Dialog.ani = "dialog_stay2";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";

			dialog.text = DLG_TEXT[155] + pchar.name + DLG_TEXT[156] + characters[GetCharacterIndex(DLG_TEXT[157])].name + DLG_TEXT[158];
			link.l1 = DLG_TEXT[159];
			link.l1.go = "both_talk_with_Silehard_2";

			Diag.TempNode = "first time";
		break;

		case "both_talk_with_Silehard_2":
			dialog.text = DLG_TEXT[160];
			link.l1 = DLG_TEXT[161] + npchar.lastname + DLG_TEXT[162] + characters[GetCharacterIndex(DLG_TEXT[163])].name + DLG_TEXT[164];
			link.l1.go = "both_talk_with_Silehard_3";
		break;

		case "both_talk_with_Silehard_3":
			dialog.text = DLG_TEXT[165] + characters[getCharacterIndex(DLG_TEXT[166])].name + DLG_TEXT[167];
			link.l1 = DLG_TEXT[168];
			link.l1.go = "both_talk_with_Silehard_4";
		break;

		case "both_talk_with_Silehard_4":
			dialog.text = DLG_TEXT[169];
			link.l1 = DLG_TEXT[170];
			link.l1.go = "both_talk_with_Silehard_5";
		break;

		case "both_talk_with_Silehard_5":
			dialog.text = DLG_TEXT[171];
			link.l1 = DLG_TEXT[172] + characters[getCharacterIndex(DLG_TEXT[173])].name + DLG_TEXT[174];
			link.l1.go = "fight_exit";
		break;

		case "fight_exit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			AddDialogExitQuest("fight_in_residence_complete");
			AddQuestRecord("search_danielle", "3");
		break;

		case "blaze_again_find_rheims_2":
			dialog.text = DLG_TEXT[175];
			link.l1 = DLG_TEXT[176];
			link.l1.go = "blaze_again_find_rheims_3";
		break;

		case "blaze_again_find_rheims_3":
			dialog.text = DLG_TEXT[177];
			link.l1 = DLG_TEXT[178];
			link.l1.go = "blaze_again_find_rheims_4";
		break;

		case "blaze_again_find_rheims_4":
			dialog.text = DLG_TEXT[179] + pchar.name + DLG_TEXT[180];
			link.l1 = DLG_TEXT[181];
			link.l1.go = "blaze_again_find_rheims_5";
		break;

		case "blaze_again_find_rheims_5":
			dialog.text = characters[getCharacterIndex(DLG_TEXT[182])].lastname + DLG_TEXT[183];
			link.l1 = DLG_TEXT[184];
			link.l1.go = "blaze_again_find_rheims_6";
		break;

		case "blaze_again_find_rheims_6":
			dialog.text = DLG_TEXT[185] + pchar.name + DLG_TEXT[186];
			link.l1 = DLG_TEXT[187];
			link.l1.go = "exit";
			pchar.quest.main_line = "blaze_search_rheims_with_danielle";
			setCharacterShipLocation(&characters[GetCharacterIndex("Danielle")], "Oxbay_lighthouse");
			ChangeCharacterAddress(&characters[GetCharacterIndex("Danielle")], "Oxbay_Lighthouse", "goto29");
			ChangeCharacterAddress(&characters[GetCharacterIndex("Vincent Bethune")], "none", "none");
			ChangeCharacterAddress(&characters[GetCharacterIndex("RESEARCHER")], "none", "none");
			pchar.quest.return_to_lighthouse_search_rheims.win_condition.l1 = "location";
			pchar.quest.return_to_lighthouse_search_rheims.win_condition.l1.location = "Oxbay_lighthouse";
			pchar.quest.return_to_lighthouse_search_rheims.win_condition = "return_to_lighthouse_search_rheims_complete";
			AddQuestRecord("move_prisoner_from_greenford", "3");
			CloseQuestHeader("move_prisoner_from_greenford");
			AddQuestRecord("again_find_rheims", "2");
		break;

		case "incas_collection_complete_node":
		Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay1";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";

			dialog.text = pchar.name + DLG_TEXT[188];
			link.l1 = DLG_TEXT[189];
			link.l1.go = "incas_collection_complete_2";
			Diag.TempNode = "first time";
		break;

		case "incas_collection_complete_2":
			dialog.text = DLG_TEXT[190];
			link.l1 = DLG_TEXT[191];
			link.l1.go = "incas_collection_complete_3";
		break;

		case "incas_collection_complete_3":
			dialog.text = DLG_TEXT[192];
			link.l1 = DLG_TEXT[193];
			link.l1.go = "incas_collection_complete_exit";
		break;

		case "incas_collection_complete_exit":
			pchar.quest.see_statuetes.win_condition = "see_statuetes_complete";
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			characters[GetCharacterIndex("Robert Christopher Silehard")].dialog.CurrentNode = "incas_collection_complete_node_2";
		break;

		case "incas_collection_complete_node_2":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay1";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";

			dialog.text = DLG_TEXT[194];
			link.l1 = DLG_TEXT[195];
			link.l1.go = "incas_collection_complete_4";
		break;

		case "incas_collection_complete_4":
			dialog.text = DLG_TEXT[196] + pchar.name + DLG_TEXT[197];
			link.l1 = DLG_TEXT[198];
			link.l1.go = "incas_collection_complete_5";
			AddMoneyToCharacter(pchar, 10000);
			AddPartyExp(pchar, 6000);
			TakeItemFromCharacter(pchar, INCAS_COLLECTION);
			CloseQuestHeader("blaze_to_incas_collection");
		break;

		case "incas_collection_complete_5":
			dialog.text = DLG_TEXT[199] + pchar.name + DLG_TEXT[200];
			link.l1 = DLG_TEXT[201];
			link.l1.go = "incas_collection_complete_7";
		break;

		case "incas_collection_complete_7":
			dialog.text = DLG_TEXT[202] + pchar.name + DLG_TEXT[203];
			link.l1 = DLG_TEXT[204];
			link.l1.go = "incas_collection_complete_8";
		break;

		case "incas_collection_complete_8":
			dialog.text = DLG_TEXT[205] + characters[getCharacterIndex(DLG_TEXT[206])].name + " " + characters[getCharacterIndex(DLG_TEXT[207])].lastname + DLG_TEXT[208];
			link.l1 = DLG_TEXT[209];
			link.l1.go = "exit";
			pchar.quest.main_line = "to_oxbay_by_prisoner";
			Diag.TempNode = "first time";
			SetQuestHeader("move_prisoner_from_greenford");
			AddQuestRecord("move_prisoner_from_greenford", "1");
		break;

		case "letter_to_Isenbrandt_complete_node":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay1";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";

			dialog.text = DLG_TEXT[210];
			link.l1 = DLG_TEXT[211];
			link.l1.go = "letter_to_Isenbrandt_complete_2";
		break;

		case "letter_to_Isenbrandt_complete_2":
			dialog.text = DLG_TEXT[212] + pchar.name + DLG_TEXT[213];
			link.l1 = DLG_TEXT[214];
			link.l1.go = "letter_to_Isenbrandt_complete_3";
		break;

		case "letter_to_Isenbrandt_complete_3":
			dialog.text = DLG_TEXT[215] + pchar.name + DLG_TEXT[216];
			link.l1 = DLG_TEXT[217];
			link.l1.go = "letter_to_Isenbrandt_complete_4";
			AddMoneyToCharacter(pchar, 2500);
			AddPartyExp(pchar, 2000);
			CloseQuestHeader("blaze_to_Isenbrandt");
		break;

		case "letter_to_Isenbrandt_complete_4":
			dialog.text = DLG_TEXT[218] + pchar.name + DLG_TEXT[219];
			link.l1 = DLG_TEXT[220];
			link.l1.go = "letter_to_Isenbrandt_complete_5";
		break;

		case "letter_to_Isenbrandt_complete_5":
			dialog.text = DLG_TEXT[221] + pchar.name + DLG_TEXT[222];
			link.l1 = DLG_TEXT[223];
			link.l1.go = "letter_to_Isenbrandt_complete_6";
		break;

		case "letter_to_Isenbrandt_complete_6":
			dialog.text = DLG_TEXT[224] + pchar.name + DLG_TEXT[225];
			link.l1 = DLG_TEXT[226];
			link.l1.go = "letter_to_Isenbrandt_complete_7";
		break;

		case "letter_to_Isenbrandt_complete_7":
			dialog.text = DLG_TEXT[227] + characters[GetCharacterIndex(DLG_TEXT[228])].ship.name + DLG_TEXT[229] + characters[GetCharacterIndex(DLG_TEXT[230])].name + " " + characters[GetCharacterIndex(DLG_TEXT[231])].lastname + DLG_TEXT[232] + pchar.name + DLG_TEXT[233];
			link.l1 = DLG_TEXT[234];
			link.l1.go = "letter_to_Isenbrandt_complete_8";
		break;

		case "letter_to_Isenbrandt_complete_8":
			dialog.text = DLG_TEXT[235] + pchar.name + DLG_TEXT[236];
			link.l1 = DLG_TEXT[237];
			link.l1.go = "exit";
			SetQuestHeader("blaze_to_incas_collection");
			AddQuestRecord("blaze_to_incas_collection", "1");
			pchar.quest.main_line = "blaze_to_incas_collection_begin";
			AddMoneyToCharacter(pchar, 10000);
			setCharacterShipLocation(&characters[GetCharacterIndex("Pirate Captain 05")], "Douwesen_shore_01");
			pchar.quest.prepare_fighting_on_deck.win_condition.l1 = "location";
			pchar.quest.prepare_fighting_on_deck.win_condition.l1.location = "Douwesen_shore_01";
			pchar.quest.prepare_fighting_on_deck.win_condition = "prepare_fighting_on_deck_complete";
			//
			//SetCharacterIslandLocation(&Characters[GetCharacterIndex("Pirate Captain 06")], "DOUWESEN", "quest_ships", "quest_ship_9", "stay", "runaway", "");
			Group_CreateGroup("Pirate Captain 06");
			Group_AddCharacter("Pirate Captain 06", "Pirate Captain 06");
			Group_SetGroupCommander("Pirate Captain 06", "Pirate Captain 06");
			Group_SetAddress("Pirate Captain 06", "Douwesen", "Quest_Ships","Quest_Ship_9");

			pchar.quest.abording_pirate_06.win_condition.l1 = "Character_Capture";
			pchar.quest.abording_pirate_06.win_condition.l1.character = "Pirate Captain 06";
			pchar.quest.abording_pirate_06.win_condition = "abording_pirate_06_complete";
			//
			pchar.quest.kill_pirate_06.win_condition.l1 = "NPC_Death";
			pchar.quest.kill_pirate_06.win_condition.l1.character = "Pirate Captain 06";
			pchar.quest.kill_pirate_06.win_condition = "kill_pirate_06_complete";
			
			Diag.TempNode = "first time";
			characters[GetCharacterIndex("pirate for abordage 01")].location = "ship_deck";
			characters[GetCharacterIndex("pirate for abordage 02")].location = "ship_deck";
			characters[GetCharacterIndex("pirate for abordage 03")].location = "ship_deck";
		break;

		case "blaze_return_to_silehard_node":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay1";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";

			dialog.text = DLG_TEXT[238] + pchar.name + DLG_TEXT[239] + characters[GetCharacterIndex(DLG_TEXT[240])].lastname + DLG_TEXT[241];
			link.l1 = DLG_TEXT[242] ;
			link.l1.go = "blaze_return_to_silehard_2";
		break;

		case "blaze_return_to_silehard_2":
			dialog.text = DLG_TEXT[243] + pchar.name + DLG_TEXT[244];
			link.l1 = DLG_TEXT[245] + characters[GetCharacterIndex(DLG_TEXT[246])].lastname + DLG_TEXT[247];
			link.l1.go = "blaze_return_to_silehard_3";
		break;
		
		case "blaze_return_to_silehard_3":
			dialog.text = DLG_TEXT[248];
			link.l1 = DLG_TEXT[249];
			link.l1.go = "blaze_return_to_silehard_4";
		break;

		case "blaze_return_to_silehard_4":
			dialog.text = DLG_TEXT[250] + pchar.name + DLG_TEXT[251];
			link.l1 = DLG_TEXT[252];
			link.l1.go = "blaze_return_to_silehard_5";
		break;
		
		case "blaze_return_to_silehard_5":
			AddMoneyToCharacter(pchar, 5000);
			AddPartyExp(pchar, 4000);
			dialog.text = DLG_TEXT[253] + pchar.name + DLG_TEXT[254] + characters[GetCharacterIndex(DLG_TEXT[255])].name + " " + characters[GetCharacterIndex(DLG_TEXT[256])].lastname  + DLG_TEXT[257] + characters[GetCharacterIndex(DLG_TEXT[258])].lastname + DLG_TEXT[259];
			link.l1 = DLG_TEXT[260];
			link.l1.go = "blaze_return_to_silehard_6";
		break;
		
		case "blaze_return_to_silehard_6":
			dialog.text = DLG_TEXT[261] + pchar.name + DLG_TEXT[262];
			link.l1 = DLG_TEXT[263];
			link.l1.go = "exit";
			pchar.quest.main_line = "letter_to_Isenbrandt";
			AddQuestRecord("blaze_search_rheims", "11");
			CloseQuestHeader("blaze_search_rheims");
			SetQuestHeader("Blaze_to_Isenbrandt");
			AddQuestRecord("blaze_to_Isenbrandt", "1");
			Diag.TempNode = "first time";
		break;

		case "main_line_find_rheims_node":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay1";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";

			dialog.text = DLG_TEXT[264];
			link.l1 = DLG_TEXT[265];
			link.l1.go = "main_line_find_rheims_1";
		break;
		
		case "main_line_find_rheims_1":
			dialog.text = DLG_TEXT[266];
			link.l1 = DLG_TEXT[267];
			link.l1.go = "main_line_find_rheims_2";
		break;

		case "main_line_find_rheims_2":
			dialog.text = DLG_TEXT[268] + characters[GetCharacterIndex(DLG_TEXT[269])].name + " " + characters[GetCharacterIndex(DLG_TEXT[270])].lastname + DLG_TEXT[271];
			link.l1 = DLG_TEXT[272];
			link.l1.go = "main_line_find_rheims_3";
		break;

		case "main_line_find_rheims_3":
			dialog.text = DLG_TEXT[273] + characters[GetCharacterIndex(DLG_TEXT[274])].lastname + DLG_TEXT[275];
			link.l1 = DLG_TEXT[276];
			link.l1.go = "main_line_find_rheims_4";
		break;

		case "main_line_find_rheims_4":
			dialog.text = DLG_TEXT[277];
			link.l1 = DLG_TEXT[278];
			link.l1.go = "exit";
			pchar.quest.main_line = "blaze_talk_with_silehard_complete";
			AddMoneyToCharacter(pchar, 5000);
			SetQuestHeader("Blaze_search_Rheims");
			AddQuestRecord("Blaze_search_Rheims", "1");
			Diag.TempNode = "first time";
		break;

		case "escape_from_prison_node":
			Dialog.defAni = "Dialog_stay1";
			Dialog.ani = "Dialog_stay2";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";
			dialog.text = DLG_TEXT[279];
			link.l1 = DLG_TEXT[280];
			link.l1.go = "escape_from_prison_2";
			pchar.quest.main_line = "kill_soldiers_in_prison";
		break;

		case "escape_from_prison_node_2":
			Dialog.defAni = "Dialog_stay1";
			Dialog.ani = "Dialog_stay2";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";

			dialog.text = DLG_TEXT[281] + pchar.name + DLG_TEXT[282]; 
			link.l1 = DLG_TEXT[283];
			link.l1.go = "escape_from_prison_9";
			characters[GetCharacterIndex("Edgar Attwood")].quest.to_hire = "possible_to_hire_edgard";
			pchar.quest.main_line = "wait_for_resque_in_prison";
		break;

		case "escape_from_prison_2":
			dialog.text = DLG_TEXT[284];
			if (pchar.quest.edgar_life == "death")
			{
				link.l1 = DLG_TEXT[285];
				link.l1.go = "escape_from_prison_6";
			}
			else
			{
				link.l1 = DLG_TEXT[286];
				link.l1.go = "escape_from_prison_7";
				link.l2 = DLG_TEXT[287];
				link.l2.go = "escape_from_prison_3";
			}
		break;

		case "escape_from_prison_3":
			dialog.text = DLG_TEXT[288] + pchar.name + DLG_TEXT[289];
			link.l1 = DLG_TEXT[290];
			link.l1.go = "escape_from_prison_4";
		break;

		case "escape_from_prison_4":
			dialog.text = DLG_TEXT[291];
			if (makeint(pchar.money) >= 1000)
			{
				link.l1 = DLG_TEXT[292];
				link.l1.go = "escape_from_prison_5";
			}
			link.l2 = DLG_TEXT[293];
			link.l2.go = "escape_from_prison_7";
		break;

		case "escape_from_prison_5":
			AddMoneyToCharacter(pchar, -1000);
			dialog.text = DLG_TEXT[294];
			link.l1 = DLG_TEXT[295];
			link.l1.go = "escape_from_prison_71";
			//ChangeCharacterAddress(&characters[GetCharacterIndex("Edgar Attwood")], "Redmond_town_02", "goto10");
			pchar.quest.exit_from_silehard_2.win_condition.l1 = "location";
			pchar.quest.exit_from_silehard_2.win_condition.l1.location = "Redmond_port";
			pchar.quest.exit_from_silehard_2.win_condition = "exit_from_silehard_2_complete";
		break;

		case "escape_from_prison_6":
			dialog.text = DLG_TEXT[296];
			link.l1 = DLG_TEXT[297];
			link.l1.go = "escape_from_prison_7";
		break;

		case "escape_from_prison_71":
			dialog.text = DLG_TEXT[298];
			link.l1 = DLG_TEXT[299];
			link.l1.go = "escape_from_prison_8";
		break;

		case "escape_from_prison_7":
			dialog.text = DLG_TEXT[300];
			link.l1 = DLG_TEXT[301];
			link.l1.go = "escape_from_prison_8";
			//убиваем Эдгара
			ChangeCharacterAddress(characterFromID("Edgar Attwood"), "none", "none");
			characters[GetCharacterIndex("Edgar Attwood")].act.hp = 0.0;
		break;

		case "escape_from_prison_8":
			dialog.text = DLG_TEXT[302];
			link.l1 = DLG_TEXT[303];
			link.l1.go = "exit";
			AddDialogExitQuest("exit_from_prison");
			if (pchar.quest.main_line == "kill_soldiers_in_prison")
			{
				AddQuestRecord("Blaze_in_prison", "6");
			}
			else
			{
				AddQuestRecord("Blaze_in_prison", "7");
			}
			CloseQuestHeader("Blaze_in_prison");
			Diag.TempNode = "first time";
		break;

		case "escape_from_prison_9":
			dialog.text = DLG_TEXT[304];
			link.l1 = DLG_TEXT[305];
			link.l1.go = "escape_from_prison_8";
			AddMoneytoCharacter(pchar, 1000);
		break;
	}
}





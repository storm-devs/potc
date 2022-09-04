//nclude "DIALOGS\Reynard Grueneveldt_dialog.h"

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
	int iTest;
	
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
			Dialog.snd = "voice\REGR\REGR001";
			
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "talk_1";

			NextDiag.TempNode = "second time";
		break;

		case "talk_1":
			Dialog.snd = "voice\REGR\REGR002";
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3] + pchar.name + " " + pchar.lastname + DLG_TEXT[4] + pchar.ship.name + DLG_TEXT[5];
			link.l1.go = "talk_2";
		break;

		case "talk_2":
			Dialog.snd = "voice\REGR\REGR003";
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "quests";
			link.l2 = DLG_TEXT[8];
			link.l2.go = "talk_3";
		break;

		case "talk_3":
			Dialog.snd = "voice\REGR\REGR004";
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "exit";
		break;

		case "second time":
			Dialog.snd = "voice\REGR\REGR005";
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "quests";
			link.l2 = DLG_TEXT[13];
			link.l2.go = "exit";
		break;

		case "quests":
			itest = 0;
			Dialog.snd = "voice\REGR\REGR006";
			dialog.text = DLG_TEXT[14];
			if (CheckQuestAttribute("ANIMISTS", "begin") && iTest < QUEST_COUNTER)
			{
				link.l1 = DLG_TEXT[15];
				Link.l1.go = "ANIMISTS_1";
				iTest = iTest + 1;
			}
			if (CheckQuestAttribute("ANIMISTS", "completed") && npchar.quest.ANIMISTS !="completed" && iTest < QUEST_COUNTER)
			{
				link.l1 = DLG_TEXT[16];
				link.l1.go = "ANIMISTS_completed";
			}
			if (characters[GetCharacterIndex("Toff Oremans")].quest.daughter == "help_begin" && iTest < QUEST_COUNTER)
			{
				link.l2 = DLG_TEXT[17];
				link.l2.go = "daughter_1";
			}
			if (characters[GetCharacterIndex("Toff Oremans")].quest.daughter == "good_2_complete" || characters[GetCharacterIndex("Toff Oremans")].quest.daughter == "almost_complete")
			{
				link.l2 = DLG_TEXT[18];
				link.l2.go = "daughter_5";
			}
			link.l99  = DLG_TEXT[19];
			link.l99.go = "exit";
		break;

		case "ANIMISTS_completed":
			Dialog.snd = "voice\REGR\REGR007";
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "exit";
			npchar.quest.ANIMISTS = "completed";
			AddPartyExp(pchar, 2800);
		break;

		case "daughter_1":
			Dialog.snd = "voice\REGR\REGR008";
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23] + GetCharacterFullName(DLG_TEXT[24]) + DLG_TEXT[25];
			link.l1.go = "daughter_2";
		break;

		case "daughter_2":
			Dialog.snd = "voice\REGR\REGR009";
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "daughter_3";
		break;

		case "daughter_3":
			Dialog.snd = "voice\REGR\REGR010";
			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "daughter_4";
		break;

		case "daughter_4":
			Dialog.snd = "voice\REGR\REGR011";
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "exit";
			characters[GetCharacterIndex("Toff Oremans")].quest.daughter = "governor";
			AddQuestRecord("daughter", "2");
		break;

		case "daughter_5":
			Dialog.snd = "voice\REGR\REGR012";
			dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "daughter_6";
		break;

		case "daughter_6":
			Dialog.snd = "voice\REGR\REGR013";
			dialog.text = DLG_TEXT[34];
			link.l1 = DLG_TEXT[35];
			link.l1.go = "daughter_7";
		break;

		case "daughter_7":
			Dialog.snd = "voice\REGR\REGR014";
			dialog.text = DLG_TEXT[36];
			link.l1 = DLG_TEXT[37];
			link.l1.go = "exit";
			AddQuestRecord("daughter", "5");
			if (characters[GetCharacterIndex("Toff Oremans")].quest.daughter == "almost_complete")
			{
				closeQuestHeader("daughter");
				characters[GetCharacterIndex("Toff Oremans")].quest.daughter = "almost_2_complete";
			}
			characters[GetCharacterIndex("Toff Oremans")].quest.daughter = "bad_2_complete";
			AddPartyExp(pchar, 4500);
			AddMoneyToCharacter(pchar, 850);
		break;

		case "ANIMISTS_1":
			Dialog.snd = "voice\REGR\REGR015";
			dialog.text = DLG_TEXT[38];
			link.l1 = DLG_TEXT[39];
			link.l1.go = "ANIMISTS_2";
		break;

		case "ANIMISTS_2":
			Dialog.snd = "voice\REGR\REGR016";
			dialog.text = DLG_TEXT[40];
			link.l1 = DLG_TEXT[41];
			link.l1.go = "ANIMISTS_3";
		break;

		case "ANIMISTS_3":
			Dialog.snd = "voice\REGR\REGR017";
			dialog.text = DLG_TEXT[42];
			link.l1 = DLG_TEXT[43];
			link.l1.go = "ANIMISTS_4";
		break;

		case "ANIMISTS_4":
			Dialog.snd = "voice\REGR\REGR018";
			dialog.text = DLG_TEXT[44];
			link.l1 = DLG_TEXT[45];
			link.l1.go = "ANIMISTS_5";
			link.l2 = DLG_TEXT[46];
			link.l2.go = "ANIMISTS_denied";
			pchar.quest.ANIMISTS = "denied";
			pchar.quest.exit_from_douwesen_townhall.win_condition.l1 = "location";
			pchar.quest.exit_from_douwesen_townhall.win_condition.l1.location = "Douwesen_town";
			pchar.quest.exit_from_douwesen_townhall.win_condition = "exit_from_douwesen_townhall_complete";
		break;

		case "ANIMISTS_5":
			Dialog.snd = "voice\REGR\REGR019";
			dialog.text = DLG_TEXT[47];
			link.l1 = DLG_TEXT[48];
			link.l1.go = "exit";
			pchar.quest.ANIMISTS = "to_douwesen_tavern";
			AddQuestRecord("ANIMISTS", "3");
			ChangeCharacterAddressGroup(&characters[GetCharacterIndex("Gheraed Drabbe")], "Douwesen_tavern", "sit", "sit5");
		break;

		case "ANIMISTS_denied":
			AddQuestRecord("ANIMISTS", "2");
			CloseQuestHeader("ANIMISTS");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}

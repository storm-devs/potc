//nclude "DIALOGS\Greenford Commander_dialog.h"

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
			Dialog.defAni = "Gov_Dialog_1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "Gov_Dialog_2";
			Dialog.cam = "1";
			
			dialog.snd = "Voice\GRCO\GRCO001";
			dialog.text = DLG_TEXT[0];
			if (pchar.quest.main_line == "to_oxbay_by_prisoner")
			{
				Link.l1 = DLG_TEXT[1] + characters[GetCharacterIndex(DLG_TEXT[2])].name + " " + characters[GetCharacterIndex(DLG_TEXT[3])].lastname + DLG_TEXT[4];
				Link.l1.go = "to_oxbay_by_prisoner_2";
			}
			if (pchar.quest.main_line == "return_idol_from_greenford")
			{
				link.l1 = DLG_TEXT[5] + characters[GetCharacterIndex(DLG_TEXT[6])].lastname + DLG_TEXT[7];
				link.l1.go = "return_idol_from_greenford_2";
			}
			if (CheckQuestAttribute("ANIMISTS", "to_prison_for_teacher_3"))
			{
				//приказ об освобождении
				link.l1 = DLG_TEXT[8];
				link.l1.go = "freedom_letter";
			}
			if (CheckQuestAttribute("ANIMISTS", "to_prison_for_teacher"))
			{
				link.l1 = DLG_TEXT[9];
				link.l1.go = "dopros";
			}
			if (CheckQuestAttribute("ANIMISTS", "raskainye"))
			{
				dialog.snd = "Voice\GRCO\GRCO002";
				dialog.text = DLG_TEXT[10];
				link.l1 = DLG_TEXT[11];
				link.l1.go = "exit";
				pchar.quest.ANIMISTS = "dopros";
			}
			link.l99 = DLG_TEXT[12];
			link.l99.go = "exit";
			NextDiag.TempNode = "first time";
		break;

		case "dopros":
			dialog.snd = "Voice\GRCO\GRCO003";
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "dopros_2";
		break;

		case "dopros_2":
			dialog.snd = "Voice\GRCO\GRCO004";
			dialog.text = DLG_TEXT[15];
			if (GetCharacterSkill(pchar, SKILL_LEADERSHIP) > 3)
			{
				link.l1 = DLG_TEXT[16];
				link.l1.go = "dopros_3";
			}
			link.l2 = DLG_TEXT[17];
			link.l2.go = "dopros_bad";
		break;

		case "dopros_3":
			if (GetCharacterSkill(pchar, SKILL_LEADERSHIP) > 5)
			{
				dialog.snd = "Voice\GRCO\GRCO005";
				dialog.text = DLG_TEXT[18];
				link.l1 = DLG_TEXT[19];
				link.l1.go = "exit";
				pchar.quest.ANIMISTS = "dopros";
				AddDialogExitQuest("mystery_man_to_prison");
				AddQuestRecord("ANIMISTS", "31");
			}
			else
			{
				dialog.snd = "Voice\GRCO\GRCO006";
				dialog.text = DLG_TEXT[20];
				link.l1 = DLG_TEXT[21];
				link.l1.go = "dopros_4";
			}
		break;

		case "dopros_4":
			dialog.snd = "Voice\GRCO\GRCO007";
			dialog.text = DLG_TEXT[22];
			if (makeint(pchar.money >= 5000))
			{
				link.l1 = DLG_TEXT[23];
				link.l1.go = "money_good";
			}
			link.l2 = DLG_TEXT[24];
			link.l2.go = "dopros_bad";
		break;

		case "dopros_bad":
			dialog.snd = "Voice\GRCO\GRCO008";
			dialog.text = DLG_TEXT[25];
			link.l1 = DLG_TEXT[26];
			link.l1.go = "dopros_bad_2";
			link.l2 = DLG_TEXT[27];
			link.l2.go = "exit";
			AddQuestRecord("ANIMISTS", "28");
		break;

		case "dopros_bad_2":
			dialog.snd = "Voice\GRCO\GRCO009";
			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "dopros_bad_3";
			AddQuestRecord("ANIMISTS", "29");
		break;

		case "dopros_bad_3":
			dialog.snd = "Voice\GRCO\GRCO010";
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "exit";
			AddDialogExitQuest("prison_commander_captured");
		break;

		case "money_good":
			AddMoneyToCharacter(pchar, -5000);
			dialog.snd = "Voice\GRCO\GRCO011";
			dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "exit";
			pchar.quest.ANIMISTS = "dopros";
			AddDialogExitQuest("mystery_man_to_prison");
			AddQuestRecord("ANIMISTS", "30");
		break;

		case "freedom_letter":
			dialog.snd = "Voice\GRCO\GRCO012";
			dialog.text = DLG_TEXT[34];
			link.l1 = DLG_TEXT[35];
			link.l1.go = "exit";
			pchar.quest.ANIMISTS = "freedom_letter";
			AddDialogExitQuest("mystery_man_to_prison");
		break;

		case "return_idol_from_greenford_2":
			dialog.snd = "Voice\GRCO\GRCO013";
			dialog.text = DLG_TEXT[36];
			link.l1 = DLG_TEXT[37];
			link.l1.go = "return_idol_from_greenford_3";
		break;

		case "return_idol_from_greenford_3":
			dialog.snd = "Voice\GRCO\GRCO014";
			dialog.text = DLG_TEXT[38];
			link.l1 = DLG_TEXT[39];
			link.l1.go = "exit";
			AddDialogExitQuest("Greenford_commander_fight_exit");
		break;

		case "to_oxbay_by_prisoner_2":
			dialog.snd = "Voice\GRCO\GRCO015";
			dialog.text = DLG_TEXT[40];
			link.l1 = DLG_TEXT[41];
			link.l1.go = "to_oxbay_by_prisoner_3";
		break;

		case "to_oxbay_by_prisoner_3":
			dialog.snd = "Voice\GRCO\GRCO016";
			dialog.text = DLG_TEXT[42];
			link.l1 = DLG_TEXT[43];
			link.l1.go = "exit";
			AddDialogExitQuest("prepare_for_first_meeting_with_researcher");
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}

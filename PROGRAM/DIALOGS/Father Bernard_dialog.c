//nclude "DIALOGS\Father Bernard_dialog.h"
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
			Dialog.snd = "dialogs\0\009";

			if(NPChar.quest.meeting == "0")
			{
				dialog.snd = "Voice\FATB\FATB001";
				d.Text = TimeGreeting() + DLG_TEXT[0];
				Link.l1 = DLG_TEXT[1] + Pchar.name + " " + Pchar.lastname + DLG_TEXT[2] + PChar.Ship.name + DLG_TEXT[3];
				Link.l1.go = "meeting";
				NPC_Meeting = "1"; 
			}
			else
			{
				dialog.snd1 = "Voice\FATB\FATB002";
				dialog.snd2 = "Voice\FATB\FATB003";
				dialog.snd3 = "Voice\FATB\FATB004";
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
			dialog.snd = "Voice\FATB\FATB005";
				d.Text = DLG_TEXT[12] + NPChar.name + " " + NPChar.lastname + DLG_TEXT[13];
				Link.l1 = DLG_TEXT[14];
				Link.l1.go = "donation";
				Link.l2 = DLG_TEXT[15];
				Link.l2.go = "quest lines";
				Link.l3 = DLG_TEXT[16];
				Link.l3.go = "exit";
		break;

		case "quest lines":
			iTest = 0;
			dialog.snd = "Voice\FATB\FATB006";
			d.Text = DLG_TEXT[17];
			if (npchar.quest.church_help == "0" && iTest < QUEST_COUNTER)
			{
				link.l1 = DLG_TEXT[18];
				link.l1.go = "church_help";
				iTest = iTest + 1;
			}
			if (npchar.quest.church_help != "0" && npchar.quest.church_help != "to_greenford" && npchar.quest.church_help != "done" && iTest < QUEST_COUNTER)
			{
				link.l2 = DLG_TEXT[19];
				link.l2.go = "church_help_done";
				itest = iTest + 1;
			}
			if (npchar.quest.church_help == "done" && pchar.quest.ANIMISTS == "FRIGATE_LOST")
			{
				link.l1 = DLG_TEXT[20];
				link.l1.go = "ANIMISTS_letter";
			}
			if (CheckQuestAttribute("ANIMISTS", "letter_to_father_bernard"))
			{
				link.l1 = DLG_TEXT[21];
				link.l1.go = "letter_to_father_bernard";
			}
			if (CheckQuestAttribute("ANIMISTS", "kill_all_ANIMISTS_in_church"))
			{
				dialog.snd = "Voice\FATB\FATB007";
				dialog.text = DLG_TEXT[22] + GetCharacterFullName(DLG_TEXT[23]) + DLG_TEXT[24];
				link.l1 = DLG_TEXT[25];
				link.l1.go = "kill_all_ANIMISTS_in_church";
			}
			if (CheckQuestAttribute("ANIMISTS", "to_prison_for_teacher"))
			{
				link.l1 = DLG_TEXT[26];
				link.l1.go = "to_prison_for_teacher";
			}
			if (CheckQuestAttribute("ANIMISTS", "to_prison_for_teacher_2"))
			{
				dialog.snd = "Voice\FATB\FATB008";
				dialog.text = DLG_TEXT[27];
				link.l1 = DLG_TEXT[28];
				link.l1.go = "exit";
				GiveItem2Character(pchar, PRISON_LETTER);
				pchar.quest.ANIMISTS = "to_prison_for_teacher_3";
			}
			if (CheckQuestAttribute("ANIMISTS", "completed") && npchar.quest.ANIMISTS != "completed")
			{
				dialog.snd = "Voice\FATB\FATB009";
				dialog.text = DLG_TEXT[29];
				link.l1 = DLG_TEXT[30];
				link.l1.go = "destroyed_sekt";
			}
			if (CheckQuestAttribute("artois_line", "found_gold") && makeint(pchar.money) >=4000)
			{
				link.l1 = DLG_TEXT[31];
				link.l1.go = "exit";
				AddDialogExitQuest("artois_donate_done");
			}
			Link.l99 = DLG_TEXT[32];
			Link.l99.go = "no quest";
		break;

		case "destroyed_sekt":
			AddpartyExp(pchar, 7000);
			AddMoneyToCharacter(pchar, 15000);
			dialog.snd = "Voice\FATB\FATB010";
			dialog.text = DLG_TEXT[33];
			link.l1 = DLG_TEXT[34];
			link.l1.go = "exit";
			npchar.quest.ANIMISTS = "completed";
		break;

		case "to_prison_for_teacher":
			dialog.snd = "Voice\FATB\FATB011";
			dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "to_prison_for_teacher_2";
		break;

		case "to_prison_for_teacher_2":
			dialog.snd = "Voice\FATB\FATB012";
			dialog.text = DLG_TEXT[37];
			link.l1 = DLG_TEXT[38];
			link.l1.go = "to_prison_for_teacher_3";
		break;

		case "to_prison_for_teacher_3":
			dialog.snd = "Voice\FATB\FATB013";
			dialog.text = DLG_TEXT[39];
			link.l1 = DLG_TEXT[40];
			link.l1.go = "exit";
			pchar.quest.ANIMISTS = "to_prison_for_teacher_2";
			AddDialogExitQuest("wait_in_church_for_letters");
			AddQuestRecord("ANIMISTS", "33");
		break;

		case "kill_all_ANIMISTS_in_church":
			dialog.snd = "Voice\FATB\FATB014";
			dialog.text = DLG_TEXT[41];
			link.l1 = DLG_TEXT[42];
			link.l1.go = "kill_all_ANIMISTS_in_church_2";
		break;

		case "kill_all_ANIMISTS_in_church_2":
			dialog.snd = "Voice\FATB\FATB015";
			dialog.text = DLG_TEXT[43];
			link.l1 = DLG_TEXT[44];
			link.l1.go = "kill_all_ANIMISTS_in_church_3";
			AddQuestRecord("ANIMISTS", "23");
		break;

		case "kill_all_ANIMISTS_in_church_3":
			if (LAi_IsDead(characterFromID("Jaoquin de masse")))
			{
				dialog.snd = "Voice\FATB\FATB016";
				dialog.text = DLG_TEXT[45];
				link.l1 = DLG_TEXT[46];
				link.l1.go = "exit";
				pchar.quest.ANIMISTS = "to_muelle_for_rumors";
			}
			else
			{
				dialog.snd = "Voice\FATB\FATB017";
				dialog.text = DLG_TEXT[47];
				link.l1 = DLG_TEXT[48];
				link.l1.go = "exit";
				pchar.quest.ANIMISTS = "first_time_Masse";
				AddDialogExitQuest("meeting_with_Jaoquin_De_Masse");
			}
		break;

		case "kill_all_ANIMISTS_in_church_2":
			dialog.snd = "Voice\FATB\FATB018";
			dialog.text = DLG_TEXT[49];
			link.l1 = DLG_TEXT[50];
			link.l1.go = "kill_all_ANIMISTS_in_church_3";
		break;

		case "letter_to_father_bernard":
			dialog.snd = "Voice\FATB\FATB019";
			dialog.text = DLG_TEXT[51] + GetCharacterFullName(DLG_TEXT[52]) + DLG_TEXT[53];
			link.l1 = DLG_TEXT[54];
			link.l1.go = "letter_to_father_bernard_2";
		break;

		case "letter_to_father_bernard_2":
			dialog.snd = "Voice\FATB\FATB020";
			dialog.text = DLG_TEXT[55];
			link.l1 = DLG_TEXT[56];
			link.l1.go = "letter_to_father_bernard_3";
		break;

		case "letter_to_father_bernard_3":
			dialog.snd = "Voice\FATB\FATB021";
			dialog.text = DLG_TEXT[57];
			link.l1 = DLG_TEXT[58];
			link.l1.go = "letter_to_father_bernard_4";
		break;

		case "letter_to_father_bernard_4":
			dialog.snd = "Voice\FATB\FATB022";
			dialog.text = DLG_TEXT[59];
			link.l1 = DLG_TEXT[60];
			link.l1.go = "exit";
			AddDialogExitQuest("father_Gareth_stopping_us");
		break;

		case "ANIMISTS_letter":
			if (makeint(pchar.reputation) >= 50)
			{
				dialog.snd = "Voice\FATB\FATB023";
				dialog.text = DLG_TEXT[61];
				link.l1 = DLG_TEXT[62];
				link.l1.go = "ANIMISTS_letter_2";
			}
			else
			{
				dialog.snd = "Voice\FATB\FATB024";
				dialog.text = DLG_TEXT[63];
				link.l1 = DLG_TEXT[64];
				link.l1.go = "exit";
			}
		break;

		case "ANIMISTS_letter_2":
			dialog.snd = "Voice\FATB\FATB025";
			dialog.text = DLG_TEXT[65];
			link.l1 = DLG_TEXT[66];
			link.l1.go = "ANIMISTS_letter_3";
		break;

		case "ANIMISTS_letter_3":
			dialog.snd = "Voice\FATB\FATB026";
			dialog.text = DLG_TEXT[67];
			link.l1 = DLG_TEXT[68];
			link.l1.go = "ANIMISTS_letters_4";
		break;

		case "ANIMISTS_letters_4":
			dialog.snd = "Voice\FATB\FATB027";
			dialog.text = DLG_TEXT[69] + characters[GetCharacterIndex(DLG_TEXT[70])].name + " " + characters[GetCharacterIndex(DLG_TEXT[71])].lastname + DLG_TEXT[72];
			link.l1 = DLG_TEXT[73];
			link.l1.go = "ANIMISTS_letters_5";
		break;

		case "ANIMISTS_letters_5":
			dialog.snd = "Voice\FATB\FATB028";
			dialog.text = DLG_TEXT[74];
			link.l1 = DLG_TEXT[75];
			link.l1.go = "ANIMISTS_letters_6";
		break;

		case "ANIMISTS_letters_6":
			dialog.snd = "Voice\FATB\FATB029";
			dialog.text = DLG_TEXT[76];
			link.l1 = DLG_TEXT[77];
			link.l1.go = "ANIMISTS_letters_7";
		break;

		case "ANIMISTS_letters_7":
			dialog.snd = "Voice\FATB\FATB030";
			dialog.text = DLG_TEXT[78] + GetCharacterFullName(DLG_TEXT[79]) + DLG_TEXT[80];
			link.l1 = DLG_TEXT[81];
			link.l1.go = "exit";
			AddQuestRecord("ANIMISTS", "8");
			pchar.quest.ANIMISTS = "letter_to_domingues";
			GiveItem2Character(pchar, LETTER_TO_DOMINGUES);
			pchar.quest.to_muelle_for_letter.win_condition.l1 = "location";
			pchar.quest.to_muelle_for_letter.win_condition.l1.location = "IslaMuelle";
			pchar.quest.to_muelle_for_letter.win_condition = "to_muelle_for_letter";
		break;

		case "church_help_done":
			dialog.snd = "Voice\FATB\FATB031";
			dialog.text = DLG_TEXT[82];
			if (iTest < QUEST_COUNTER && npchar.quest.church_help == "bad_dautch" || npchar.quest.church_help == "to_dautch" || npchar.quest.church_help == "after_off" || npchar.quest.church_help == "letters_1" || npchar.quest.church_help == "letters_2" || npchar.quest.church_help == "dautch_denied" || npchar.quest.church_help == "without_letters")
			{
				link.l1 = characters[GetCharacterIndex(DLG_TEXT[83])].name + " " + characters[GetCharacterIndex(DLG_TEXT[84])].lastname + DLG_TEXT[85];
				link.l1.go = "church_help_bad";
			}
			if (iTest < QUEST_COUNTER && npchar.quest.church_help == "almost_done" || npchar.quest.church_help == "good_dautch" || npchar.quest.church_help == "good_off" || npchar.quest.church_help == "without_letters")
			{
				link.l1 = characters[GetCharacterIndex(DLG_TEXT[86])].name + " " + characters[GetCharacterIndex(DLG_TEXT[87])].lastname + DLG_TEXT[88];
				link.l1.go = "church_help_good";
			}
		break;

		case "church_help_good":
			dialog.snd = "Voice\FATB\FATB032";
			dialog.text = DLG_TEXT[89];
			link.l1 = DLG_TEXT[90];
			link.l1.go = "church_help_good_2";
		break;

		case "church_help_good_2":
			dialog.snd = "Voice\FATB\FATB033";
			dialog.text = DLG_TEXT[91];
			link.l1 = DLG_TEXT[92];
			link.l1.go = "exit";
			AddQuestRecord("church_help", "13");
			CloseQuestHeader("church_help");
			npchar.quest.church_help = "done";
			AddMoneyToCharacter(pchar, 2500);
			AddPartyExp(pchar, 5000);
			ChangeCharacterReputation(pchar, 5);
			ChangeCharacterAddress(characterFromID("Gilbert Ballester"), "none", "none");
			TakeItemFromCharacter(pchar, LOVE_LETTERS_OF_PRIEST);
		break;

		case "church_help_bad":
			dialog.snd = "Voice\FATB\FATB034";
			dialog.text = DLG_TEXT[93];
			link.l1 = DLG_TEXT[94];
			link.l1.go = "church_help_bad_2";
		break;

		case "church_help_bad_2":
			dialog.snd = "Voice\FATB\FATB035";
			dialog.text = DLG_TEXT[95];
			link.l1 = DLG_TEXT[96];
			link.l1.go = "exit";
			AddQuestRecord("church_help", "14");
			CloseQuestHeader("church_help");
			npchar.quest.church_help = "done";
			AddMoneyToCharacter(pchar, 2500);
			AddPartyExp(pchar, 2000);
			ChangeCharacterAddress(characterFromID("father jerald"), "none", "none");
			characters[GetCharacterIndex("Gilbert Ballester")].dialog.filename = "father jerald_dialog.c";
			TakeItemFromCharacter(pchar, LOVE_LETTERS_OF_PRIEST);
		break;

		case "church_help":
			if (makeint(pchar.reputation) >=60)
			{
				dialog.snd = "Voice\FATB\FATB036";
				dialog.text = DLG_TEXT[97];
				link.l1 = DLG_TEXT[98];
				link.l1.go = "church_help_2";
			}
			else
			{
				dialog.snd = "Voice\FATB\FATB037";
				dialog.text = DLG_TEXT[99];
				link.l1 = DLG_TEXT[100];
				link.l1.go = "exit";
			}
		break;

		case "church_help_2":
			dialog.snd = "Voice\FATB\FATB038";
			dialog.text = DLG_TEXT[101];
			link.l1 = DLG_TEXT[102];
			link.l1.go = "church_help_3";
		break;

		case "church_help_3":
			dialog.snd = "Voice\FATB\FATB039";
			dialog.text = DLG_TEXT[103];
			link.l1 = DLG_TEXT[104];
			link.l1.go = "church_help_4";
		break;

		case "church_help_4":
			dialog.snd = "Voice\FATB\FATB040";
			dialog.text = DLG_TEXT[105];
			link.l1 = DLG_TEXT[106];
			link.l1.go = "church_help_5";
		break;

		case "church_help_5":
			dialog.snd = "Voice\FATB\FATB041";
			dialog.text = DLG_TEXT[107] + characters[GetCharacterIndex(DLG_TEXT[108])].name + " " + characters[GetCharacterIndex(DLG_TEXT[109])].lastname + DLG_TEXT[110];
			link.l1 = DLG_TEXT[111];
			link.l1.go = "church_help_6";
		break;

		case "church_help_6":
			dialog.snd = "Voice\FATB\FATB042";
			dialog.text = DLG_TEXT[112];
			link.l1 = DLG_TEXT[113];
			link.l1.go = "exit";
			SetQuestHeader("Church_help");
			AddQuestRecord("Church_help", "1");
			npchar.quest.church_help = "to_greenford";
		break;

		case "No quest":
			dialog.snd = "Voice\FATB\FATB043";
			d.Text = DLG_TEXT[114];
			Link.l1 = DLG_TEXT[115];
			Link.l1.go = "donation";
			Link.l2 = DLG_TEXT[116];
			Link.l2.go = "exit";
		break;

		case "donation":
			dialog.snd = "Voice\FATB\FATB044";
			d.Text = DLG_TEXT[117];
			Link.l1 = DLG_TEXT[118];
			Link.l1.go = "No donation";
			if(makeint(PChar.money)>=100)
			{	
				Link.l2 = DLG_TEXT[119];
				Link.l2.go = "donation paid_100";
			}
			if(makeint(PChar.money)>=1000)
			{
				Link.l3 = DLG_TEXT[120];
				Link.l3.go = "donation paid_1000";
			}
			if(makeint(PChar.money)>=5000)
			{	
				Link.l4 = DLG_TEXT[121];
				Link.l4.go = "donation paid_5000";
			}
		break;

		case "No donation":
			dialog.snd = "Voice\FATB\FATB045";
			d.Text = DLG_TEXT[122];
			Link.l1 = DLG_TEXT[123];
			Link.l1.go = "quest lines";
			Link.l2 = DLG_TEXT[124];
			Link.l2.go = "exit";
		break;

		case "donation paid_100":
			dialog.snd = "Voice\FATB\FATB046";
			AddMoneyToCharacter(pchar, -100);
			pchar.quest.donate = makeint(pchar.quest.donate) + 100;
			d.Text = DLG_TEXT[125];
			Link.l1 = DLG_TEXT[126];
			Link.l1.go = "quest lines";
			Link.l2 = DLG_TEXT[127];
			Link.l2.go = "exit";
			AddDialogExitQuest("donation");
		break;
		
		case "donation paid_1000":
			dialog.snd = "Voice\FATB\FATB046";
			AddMoneyToCharacter(pchar, -1000);
			pchar.quest.donate = makeint(pchar.quest.donate) + 1000;
			d.Text = DLG_TEXT[128];
			Link.l1 = DLG_TEXT[129];
			Link.l1.go = "quest lines";
			Link.l2 = DLG_TEXT[130];
			Link.l2.go = "exit";
			AddDialogExitQuest("donation");
		break;
		
		case "donation paid_5000":
			dialog.snd = "Voice\FATB\FATB046";
			AddMoneyToCharacter(pchar, -5000);
			pchar.quest.donate = makeint(pchar.quest.donate) + 5000;
			d.Text = DLG_TEXT[131];
			Link.l1 = DLG_TEXT[132];
			Link.l1.go = "quest lines";
			Link.l2 = DLG_TEXT[133];
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
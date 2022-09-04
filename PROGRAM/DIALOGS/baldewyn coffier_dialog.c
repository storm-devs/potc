//nclude "DIALOGS\baldewyn coffier_dialog.h"
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
		// ----------------------------------- Диалог первый - первая встреча
		case "First time":
			Dialog.defAni = "Sit_Right_Strong_Yes";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_stay1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "Sit_Right_Dialog_1";
			Dialog.cam = "1";
			
			dialog.snd = "Voice\BACO\BACO001";
			Dialog.Text = DLG_TEXT[0] + Address_form.Fra + DLG_TEXT[1];
			if (npchar.quest.hire == "arno")
			{
				Link.l1 = pcharrepphrase(DLG_TEXT[2] + npchar.name + " " + npchar.lastname + DLG_TEXT[3], DLG_TEXT[4] + npchar.name + " " + npchar.lastname + DLG_TEXT[5]);
				Link.l1.go = "line_one";
			}
			if (npchar.quest.hire == "0")
			{
				Link.l1 = pcharrepphrase(DLG_TEXT[6], DLG_TEXT[7]);
				Link.l1.go = "line_two";
			}
			if (npchar.quest.hire == "question_1_done")
			{
				link.l1 = DLG_TEXT[8];
				link.l1.go = "line_one_5";
			}
			if (npchar.quest.hire == "question_1_not_done")
			{
				link.l1 = DLG_TEXT[9];
				link.l1.go = "line_one_7";
			}
			if (npchar.quest.hire == "not_money_3")
			{
				link.l1 = DLG_TEXT[10];
				link.l1.go = "line_one_8";
			}
			if (npchar.quest.hire == "almost_done")
			{
				link.l1 = DLG_TEXT[11];
				link.l1.go = "work";
			}
			if (npchar.quest.hire == "almost_done_1")
			{
				link.l1 = DLG_TEXT[12] + Characters[GetCharacterIndex(DLG_TEXT[13])].name + DLG_TEXT[14];
				link.l1.go = "work_3";
				link.l2 = DLG_TEXT[15];
				link.l2.go = "hire_denied";
			}
			if (npchar.quest.hire == "money_31")
			{
				link.l1 = DLG_TEXT[16];
				link.l1.go = "work_3";
			}
			if (npchar.quest.hire == "hire_denied")
			{
				dialog.snd = "Voice\BACO\BACO002";
				dialog.text = DLG_TEXT[17];
				link.l1 = DLG_TEXT[18];
				link.l1.go = "work_2";
			}
			if (npchar.quest.hire == "money_3" || npchar.quest.hire == "money_2")
			{
				dialog.snd = "Voice\BACO\BACO002";
				dialog.text = DLG_TEXT[19];
				link.l1 = DLG_TEXT[20];
				link.l1.go = "line_money";
			}
			link.l2 = pcharrepphrase(DLG_TEXT[21], DLG_TEXT[22]);
			link.l2.go = "exit";
			NextDiag.TempNode = "First time";
		break;

		case "hire_denied":
			dialog.snd = "Voice\BACO\BACO003";
			dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[24];
			link.l1.go = "exit";
			npchar.quest.hire = "hire_denied";
		break;

		case "line_two":
			dialog.snd = "Voice\BACO\BACO004";
			dialog.text = DLG_TEXT[25];
			link.l1 = pcharrepphrase(DLG_TEXT[26], DLG_TEXT[27]);
			link.l1.go = "line_two_1";
			link.l2 = pcharrepphrase(DLG_TEXT[28], DLG_TEXT[29]);
			link.l2.go = "exit";
		break;

		case "line_two_1":
			dialog.snd = "Voice\BACO\BACO005";
			dialog.text = DLG_TEXT[30];
			link.l1 = pcharrepphrase(DLG_TEXT[31], DLG_TEXT[32]);
			link.l1.go = "line_two_2";
			link.l2 = pcharrepphrase(DLG_TEXT[33], DLG_TEXT[34]);
			link.l2.go = "exit";
		break;

		case "line_two_2":
			dialog.snd = "Voice\BACO\BACO006";
			dialog.text = DLG_TEXT[35] + address_form.fra + DLG_TEXT[36];
			link.l1 = pcharrepphrase(DLG_TEXT[37], DLG_TEXT[38]);
			link.l1.go = "line_two_3";
		break;

		case "line_two_3":
			dialog.snd = "Voice\BACO\BACO007";
			dialog.text = DLG_TEXT[39];
			link.l1 = pcharrepphrase(DLG_TEXT[40], DLG_TEXT[41]);
			link.l1.go = "line_two_4";
			link.l2 = pcharrepphrase(DLG_TEXT[42], DLG_TEXT[43]);
			link.l2.go = "exit";
		break;

		case "line_two_4":
			dialog.snd = "Voice\BACO\BACO008";
			dialog.text = DLG_TEXT[44] + Characters[GetCharacterIndex(DLG_TEXT[45])].name + " " + Characters[GetCharacterIndex(DLG_TEXT[46])].lastname + DLG_TEXT[47] + Characters[GetCharacterIndex(DLG_TEXT[48])].name + DLG_TEXT[49];
			link.l1 = pcharrepphrase(DLG_TEXT[50], DLG_TEXT[51]);
			link.l1.go = "line_two_5";
			link.l2 = pcharrepphrase(DLG_TEXT[52], DLG_TEXT[53]);
			link.l2.go = "exit";
		break;

		case "line_two_5":
			if (makeint(pchar.reputation) > 40 )
			{
				dialog.snd = "Voice\BACO\BACO009";
				dialog.text = DLG_TEXT[54] + Address_Form.Fra + DLG_TEXT[55] + Characters[GetCharacterIndex(DLG_TEXT[56])].name + DLG_TEXT[57];
				if (makeint(pchar.money) >= 10000)
				{
					link.l1 = DLG_TEXT[58];
					link.l1.go = "money";
				}
				link.l2 = DLG_TEXT[59];
				link.l2.go = "work";
				link.l3 = DLG_TEXT[60];
				link.l3.go = "exit";
			}
			else
			{
				dialog.snd = "Voice\BACO\BACO010";
				dialog.text = DLG_TEXT[61] + Address_form.Fra + DLG_TEXT[62];
				link.l1 = pcharrepphrase(DLG_TEXT[63], DLG_TEXT[64]);
				link.l1.go = "exit";
			}
		break;

		case "line_one":
			dialog.snd = "Voice\BACO\BACO011";
			dialog.text = DLG_TEXT[65];
			link.l1 = pcharrepphrase(DLG_TEXT[66] + Characters[GetCharacterIndex(DLG_TEXT[67])].name + DLG_TEXT[68], DLG_TEXT[69]);
			link.l1.go = "line_one_2";
		break;

		case "line_one_2":
			dialog.snd = "Voice\BACO\BACO012";
			dialog.text = DLG_TEXT[70];
			link.l1 = pcharrepphrase(Characters[GetCharacterIndex(DLG_TEXT[71])].name + DLG_TEXT[72], DLG_TEXT[73] + characters[GetCharacterIndex(DLG_TEXT[74])].name + DLG_TEXT[75]);
			link.l1.go = "line_one_3";
		break;

		case "line_one_3":
			dialog.snd = "Voice\BACO\BACO013";
			dialog.text = DLG_TEXT[76] + Address_Form.Fra + DLG_TEXT[77];
			if (makeint(pchar.reputation) > 40)
			{
				link.l1 = DLG_TEXT[78];
				link.l1.go = "line_one_4";
			}
			link.l2 = pcharrepphrase(DLG_TEXT[79] + Characters[GetCharacterIndex(DLG_TEXT[80])].name + DLG_TEXT[81], DLG_TEXT[82]);
			link.l2.go = "line_one_7";
		break;

		case "line_one_4":
			dialog.snd = "Voice\BACO\BACO014";
			dialog.text = DLG_TEXT[83] + Address_form.Fra + DLG_TEXT[84];
			link.l1 = DLG_TEXT[85];
			link.l1.go = "exit";
			npchar.quest.hire = "question_1";
		break;

		case "line_one_5":
			dialog.snd = "Voice\BACO\BACO015";
			dialog.text = DLG_TEXT[86];
			link.l1 = DLG_TEXT[87] + Characters[GetCharacterIndex(DLG_TEXT[88])].name + DLG_TEXT[89];
			link.l1.go = "line_one_6";
			link.l2 = pcharrepphrase(DLG_TEXT[90], DLG_TEXT[91] + characters[GetCharacterIndex(DLG_TEXT[92])].name + DLG_TEXT[93]);
			link.l2.go = "line_one_8";
		break;

		case "line_one_6":
			dialog.snd = "Voice\BACO\BACO016";
			dialog.text = DLG_TEXT[94] + Characters[GetCharacterIndex(DLG_TEXT[95])].name + DLG_TEXT[96];
			link.l1 = DLG_TEXT[97];
			link.l1.go = "exit";
			npchar.quest.hire =  "not_money_3";
		break;

		case "line_one_7":
			dialog.snd = "Voice\BACO\BACO017";
			dialog.text = DLG_TEXT[98] + Address_Form.Fra + DLG_TEXT[99];
			link.l1 = pcharrepphrase(DLG_TEXT[100], DLG_TEXT[101]);
			link.l1.go = "exit";
			npchar.quest.hire =  "not_money_2";
		break;

		case "line_one_8":
			if (makeint(pchar.reputation) > 40 )
			{
				dialog.snd = "Voice\BACO\BACO018";
				dialog.text = DLG_TEXT[102] + Address_Form.Fra + DLG_TEXT[103] + Characters[GetCharacterIndex(DLG_TEXT[104])].name + DLG_TEXT[105];
				if (makeint(pchar.money) >= 10000)
				{
					link.l1 = DLG_TEXT[106];
					link.l1.go = "money";
				}
				link.l2 = DLG_TEXT[107];
				link.l2.go = "work";
				link.l3 = DLG_TEXT[108];
				link.l3.fo = "exit";
				npchar.quest.hire =  "not_money_3";
			}
			else
			{
				dialog.snd = "Voice\BACO\BACO019";
				dialog.text = DLG_TEXT[109] + Address_form.Fra + DLG_TEXT[110];
				link.l1 = pcharrepphrase(DLG_TEXT[111], DLG_TEXT[112]);
				link.l1.go = "exit";
				npchar.quest.hire =  "not_money_2";
			}
		break;

		case "work":
			if(npchar.quest.hire == "almost_done")
			{
				dialog.snd = "Voice\BACO\BACO020";
				dialog.text = DLG_TEXT[113] + Address_form.Fra + DLG_TEXT[114];
				link.l1 = DLG_TEXT[115];
				link.l1.go = "exit";
				if (makeint(pchar.money) > 1500)
				{
					link.l2 = DLG_TEXT[116];
					link.l2.go = "work_2";
				}
			}
			else
			{
				dialog.snd = "Voice\BACO\BACO021";
				dialog.text = DLG_TEXT[117] + Address_form.Fra + DLG_TEXT[118] + characters[GetCharacterIndex(DLG_TEXT[119])].name + DLG_TEXT[120];
				if (makeint(pchar.money) > 2000)
				{
					link.l1 = DLG_TEXT[121];
					link.l1.go = "work_1";
				}
				link.l2 = DLG_TEXT[122];
				link.l2.go = "exit";
				npchar.quest.hire =  "not_money_3";
			}
		break;

		case "money":
			dialog.snd = "Voice\BACO\BACO022";
			dialog.text = DLG_TEXT[123] + Address_Form.Fra + DLG_TEXT[124];
			link.l1 = DLG_TEXT[125];
			link.l1.go = "exit";
			AddMoneyToCharacter(pchar, -10000);
			ChangeCharacterReputation(pchar, 2);
			AddDialogExitQuest("baldewyn_wait_month");
		break;

		case "work_1":
			dialog.snd = "Voice\BACO\BACO023";
			dialog.text = DLG_TEXT[126] + Address_Form.Fra + DLG_TEXT[127] + Characters[GetCharacterIndex(DLG_TEXT[128])].name + DLG_TEXT[129];
			link.l1 = DLG_TEXT[130];
			link.l1.go = "exit";
			if (npchar.quest.hire == "0")
			{
				npchar.quest.hire = "money_4";
			}
			else
			{
				npchar.quest.hire =  "money_1";
			}
		break;

		case "work_2":
			dialog.snd = "Voice\BACO\BACO024";
			dialog.text = DLG_TEXT[131];
			link.l1 = DLG_TEXT[132] + pchar.ship.name + DLG_TEXT[133];
			link.l1.go = "exit";
			AddPassenger(pchar, npchar, 0);
			npchar.quest.hire = "hired";
			AddDialogExitQuest("hire_baldewyn");
		break;

		case "work_3":
			dialog.snd = "Voice\BACO\BACO025";
			dialog.text = DLG_TEXT[134];
			link.l1 = DLG_TEXT[135] + pchar.ship.name + DLG_TEXT[136];
			link.l1.go = "exit";
			AddPartyExp(pchar, 1000);
			AddPassenger(pchar, npchar, 0);
			npchar.quest.hire = "hired";
			AddDialogExitQuest("hire_baldewyn");
		break;

		case "line_money":
			dialog.snd = "Voice\BACO\BACO026";
			dialog.text = DLG_TEXT[137] + Address_form.Fra + DLG_TEXT[138];
			link.l1 = DLG_TEXT[139];
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[140];
			link.l2.go = "work";
			npchar.quest.hire =  "almost_done";
			AddMoneyToCharacter(pchar, 15000);
			AddPartyExp(pchar, 750);
			ChangeCharacterReputation(pchar, 2);
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}

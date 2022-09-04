//nclude "DIALOGS\eng_officiant_dialog.h"
	
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
	string iDay, iMonth;
	iDay = environment.date.day;
	iMonth = environment.date.month;
	string lastsex_date = iday + " " + iMonth;
	
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
			NextDiag.TempNode = "first time";
			
			if (characters[GetCharacterIndex("Father Bernard")].quest.church_help == "letters_1" || characters[GetCharacterIndex("Father Bernard")].quest.church_help == "letters_2" && npchar.id == "Greenford_officiant")
			{
				dialog.snd = "Voice\ENOF\ENOF002";
				dialog.text = DLG_TEXT[0] + address_form.eng + DLG_TEXT[1];
				link.l1 = DLG_TEXT[2] + npchar.name + " " + npchar.lastname + DLG_TEXT[3];
				link.l1.go = "church_help";
			}
			else
			{
				switch(Rand(4))
				{
					case 0:
						dialog.snd = "Voice\ENOF\ENOF001";
						dialog.text = DLG_TEXT[4];
						link.l1 = DLG_TEXT[5];
						link.l1.go = "exit";
					break;

					case 1:
						dialog.snd = "Voice\ENOF\ENOF001";
						dialog.text = DLG_TEXT[6];
						link.l1 = DLG_TEXT[7];
						link.l1.go = "exit";
					break;

					case 2:
						dialog.snd = "Voice\ENOF\ENOF001";
						dialog.text = DLG_TEXT[8];
						link.l1 = DLG_TEXT[9];
						link.l1.go = "exit";
					break;

					case 3:
						dialog.snd = "Voice\ENOF\ENOF001";
						dialog.text = DLG_TEXT[10];
						link.l1 = DLG_TEXT[11];
						link.l1.go = "exit";
					break;

					case 4:
						dialog.snd = "Voice\ENOF\ENOF001";
						dialog.text = DLG_TEXT[12];
						link.l1 = DLG_TEXT[13];
						link.l1.go = "exit";
					break;


				}
			}

		break;

		case "church_help":
			dialog.snd = "Voice\ENOF\ENOF003";	
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15] + characters[getCharacterIndex(DLG_TEXT[16])].name + " " + characters[getCharacterIndex(DLG_TEXT[17])].lastname + DLG_TEXT[18];
			link.l1.go = "church_help_2";
		break;

		case "church_help_2":
			dialog.snd = "Voice\ENOF\ENOF004";
			dialog.text = DLG_TEXT[19];
			link.l1 = DLG_TEXT[20];
			link.l1.go = "church_help_4";
		break;

		case "church_help_4":
			dialog.snd = "Voice\ENOF\ENOF005";
			dialog.text = DLG_TEXT[21] + characters[GetCharacterIndex(DLG_TEXT[22])].name + " " +  + characters[GetCharacterIndex(DLG_TEXT[23])].lastname + DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "church_help_5";
		break;

		case "church_help_5":
			dialog.snd = "Voice\ENOF\ENOF006";
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "exit";
			characters[GetCharacterIndex("Father Bernard")].quest.church_help = "after_off";
			AddQuestRecord("Church_help", "7");
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "without_money":
			NextDiag.TempNode = "first time";
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			
			dialog.snd = "Voice\ENOF\ENOF007";
			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "without_money_2";
		break;

		case "without_money_2":
			dialog.snd = "Voice\ENOF\ENOF008";
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "without_money_3";
		break;

		case "without_money_3":
			dialog.snd = "Voice\ENOF\ENOF009";
			dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "without_money_4";
		break;

		case "without_money_4":
			dialog.snd = "Voice\ENOF\ENOF010";
			dialog.text = DLG_TEXT[34];
			link.l2 = DLG_TEXT[35];
			link.l2.go = "exit";
			ChangeCharacterReputation(pchar, -1);
		break;

		case "sister":
			dialog.snd = "Voice\ENOF\ENOF011";
			dialog.text = DLG_TEXT[36];
			link.l1 = DLG_TEXT[37];
			link.l1.go = "exit";
			characters[GetCharacterIndex("Virginie d'Espivant")].dialog.currentnode = "speak_2";
			AddDialogExitQuest("virginie_speak");
			Dialog.TempNode = "first time";
		break;
	}
}

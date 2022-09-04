//#include "DIALOGS\Malcolm Hatcher_dialog.h"
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

		case "exit":
			NextDiag.CurrentNode = NextDiag.Tempnode;
			DialogExit();

		break;


		case "start":
			dialog.text = DLG_TEXT[0] + NPchar.name + DLG_TEXT[1];
			link.l1 = DLG_TEXT[2];
			link.l1.go = "start1";
		break;

		case "start1":
			dialog.text = DLG_TEXT[3];
			link.l1 = DLG_TEXT[4];
			link.l1.go = "start2";
			link.l2 = DLG_TEXT[5];
			link.l2.go = "Skip_tutorial";
		break;

		case "start2":
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "start3";
		break;

		case "start3":			
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "start4";
		break;

		case "start4":
			addDialogExitQuest("Tut_TakeStuff");
			NextDiag.TempNode = "TakeWeapon";
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "Exit";
		break;

		case "TakeWeapon":			
			if(CheckCharacterItem(Pchar, "blade1") == 0 || CheckCharacterItem(Pchar, "Spyglass1") == 0 || CheckCharacterItem(Pchar, "pistol1") == 0)
			{
				NextDiag.TempNode = "TakeWeapon";
				dialog.text = DLG_TEXT[12];
				link.l1 = DLG_TEXT[13];
				link.l1.go = "Exit";
			}
			else
			{
				addDialogExitQuest("Tut_EquipWeapon");
				NextDiag.TempNode = "EquipWeapon";
				dialog.text = DLG_TEXT[14];
				link.l1 = DLG_TEXT[15];
				link.l1.go = "Exit";
			}
			if(IsEquipCharacterByItem(Pchar, "blade1") == true && IsEquipCharacterByItem(Pchar, "pistol1") == true )
			{
				dialog.text = DLG_TEXT[16];
				link.l1 = DLG_TEXT[17];
				link.l1.go = "Swordplay";
				link.l2 = DLG_TEXT[18];
				link.l2.go = "OutOfThisShip";
				link.l3 = DLG_TEXT[19];
				link.l3.go = "Skip_tutorial";
			}

		break;

		case "EquipWeapon":
			NextDiag.TempNode = "EquipWeapon";
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "Exit";

			if(IsEquipCharacterByItem(Pchar, "blade1") == true && IsEquipCharacterByItem(Pchar, "pistol1") == true )
			{
				dialog.text = DLG_TEXT[22];
				link.l1 = DLG_TEXT[23];
				link.l1.go = "Swordplay";
				link.l2 = DLG_TEXT[24];
				link.l2.go = "OutOfThisShip";
				link.l3 = DLG_TEXT[25];
				link.l3.go = "Skip_tutorial";

			}
			if(IsEquipCharacterByItem(Pchar, "blade1") == true && IsEquipCharacterByItem(Pchar, "pistol1") == false )
			{
				Dialog.TempNode = "EquipWeapon";
				dialog.text = DLG_TEXT[26];
				link.l1 = DLG_TEXT[27];
				link.l1.go = "Exit";
			}
			if(IsEquipCharacterByItem(Pchar, "blade1") == false && IsEquipCharacterByItem(Pchar, "pistol1") == true )
			{
				Dialog.TempNode = "EquipWeapon";
				dialog.text = DLG_TEXT[28];
				link.l1 = DLG_TEXT[29];
				link.l1.go = "Exit";
			}

		break;

		case "Swordplay":			
			addDialogExitQuest("Tut_WalkToSwordplayPlace");
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "Swordplay_1";
		break;

		case "Swordplay_1":			
			dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "Exit";
		break;

		case "NowHitMe":
			AddDialogExitQuest("Tut_FirstMeleeFight");
			NextDiag.Tempnode = "WhatAreYouWaitingFor";
			dialog.text = DLG_TEXT[34];
			link.l1 = DLG_TEXT[35];
			link.l1.go = "NowHitMe_1";
		break;

		case "NowHitMe_1":
			NextDiag.Tempnode = "WhatAreYouWaitingFor";
			dialog.text = DLG_TEXT[36];
			link.l1 = DLG_TEXT[37];
			link.l1.go = "Exit";
		break;

		case "WhatAreYouWaitingFor":
			NextDiag.Tempnode = "WhatAreYouWaitingFor";
			dialog.text = DLG_TEXT[38];
			link.l1 = DLG_TEXT[39];
			link.l1.go = "Continue_ToSeriousFight";
			link.l2 = DLG_TEXT[40];
			link.l2.go = "WhatAreYouWaitingFor_1";
			link.l3 = DLG_TEXT[41];
			link.l3.go = "Skip_tutorial";
		break;

		case "HurtEnough":
			AddDialogExitQuest("Tut_ReturnPlayer");
			dialog.text = DLG_TEXT[42];
			link.l1 = DLG_TEXT[43];
			link.l1.go = "Continue_ToSeriousFight";
			link.l2 = DLG_TEXT[44];
			link.l2.go = "WhatAreYouWaitingFor_1";
			link.l3 = DLG_TEXT[45];
			link.l3.go = "Skip_tutorial";
		break;

		case "WhatAreYouWaitingFor_1":
			AddDialogExitQuest("Tut_FirstMeleeFight");
			NextDiag.Tempnode = "WhatAreYouWaitingFor";
			dialog.text = DLG_TEXT[46];
			link.l1 = DLG_TEXT[47];
			link.l1.go = "Exit";			
		break;

		case "Continue_ToSeriousFight":
			AddDialogExitQuest("Tut_StartSeriousFight");
			NextDiag.Tempnode = "WhatAreYouWaitingFor";
			dialog.text = DLG_TEXT[48];
			link.l1 = DLG_TEXT[49];
			link.l1.go = "Exit";			
		break;

		case "SeriousStopped":
			//AddDialogExitQuest("Tut_StartSeriousFight");
			//NextDiag.Tempnode = "WhatAreYouWaitingFor";
			if(LAi_GetCharacterHP(Pchar) >= (LAi_GetCharacterHP(CharacterFromID("Malcolm Hatcher"))+50))
			{
				dialog.text = DLG_TEXT[50];
				link.l1 = DLG_TEXT[51];
				link.l1.go = "OutOfThisShip";			
				link.l2 = DLG_TEXT[52];
				link.l2.go = "OnceAgain";			
				link.l3 = DLG_TEXT[53];
				link.l3.go = "Skip_Tutorial";			

			}
			else
			{
				dialog.text = DLG_TEXT[54];
				link.l1 = DLG_TEXT[55];
				link.l1.go = "OnceAgain";	
				link.l2 = DLG_TEXT[56];
				link.l2.go = "OutOfThisShip";			
				link.l3 = DLG_TEXT[57];
				link.l3.go = "Skip_Tutorial";			
			}
			
		break;


		case "OnceAgain":
			AddDialogExitQuest("Tut_StartSeriousFightAgain");
			dialog.text = DLG_TEXT[58];
			link.l1 = DLG_TEXT[59];
			link.l1.go = "Exit";			
		break;

		case "SeriousStoppedAgain":
			if(LAi_GetCharacterHP(Pchar) >= (LAi_GetCharacterHP(CharacterFromID("Malcolm Hatcher"))+50))
			{
				dialog.text = DLG_TEXT[60];
				link.l1 = DLG_TEXT[61];
				link.l1.go = "OutOfThisShip";			
				link.l2 = DLG_TEXT[62];
				link.l2.go = "OnceAgain";			
				link.l3 = DLG_TEXT[63];
				link.l3.go = "Skip_Tutorial";			

			}
			else
			{
				dialog.text = DLG_TEXT[64];
				link.l1 = DLG_TEXT[65];
				link.l1.go = "OnceAgain";	
				link.l2 = DLG_TEXT[66];
				link.l2.go = "OutOfThisShip";			
				link.l3 = DLG_TEXT[67];
				link.l3.go = "Skip_Tutorial";			
			}
		break;

		case "OutOfThisShip":
			dialog.text = DLG_TEXT[68];
			link.l1 = DLG_TEXT[69];
			link.l1.go = "DistributePoints";	
			link.l2 = DLG_TEXT[70];			
			link.l2.go = "SkillDescription";			
			link.l3 = DLG_TEXT[71];			
			link.l3.go = "FuckTheSkillsLetsGo";			
		break;

		case "DistributePoints":
			dialog.text = DLG_TEXT[72];			
			link.l1 = DLG_TEXT[73];			
			link.l1.go = "DistributePoints_1";			
			link.l2 = DLG_TEXT[74];			
			link.l2.go = "FuckTheSkillsLetsGo";			
			link.l3 = DLG_TEXT[75];			
			link.l3.go = "SkillDescription";			
		break;

		case "DistributePoints_1":
			NextDiag.TempNode = "ContinueAfterSkills";
			AddDialogExitQuest("Tut_PlayerDistributeSkills");
			dialog.text = DLG_TEXT[76];			
			link.l1 = DLG_TEXT[77];			
			link.l1.go = "Exit";						
		break;

		case "ContinueAfterSkills":
			NextDiag.TempNode = "ContinueAfterSkills";
			dialog.text = DLG_TEXT[78];			
			link.l1 = DLG_TEXT[79];			
			link.l1.go = "DistributePoints_1";			
			link.l2 = DLG_TEXT[80];			
			link.l2.go = "FuckTheSkillsLetsGo";			
			link.l3 = DLG_TEXT[81];			
			link.l3.go = "SkillDescription";			
		break;


		case "SkillDescription":
			dialog.text = DLG_TEXT[82];			
			link.l1 = DLG_TEXT[83];			
			link.l1.go = "Leadership";			
			link.l2 = DLG_TEXT[84];			
			link.l2.go = "Melee Combat";			
			link.l3 = DLG_TEXT[85];			
			link.l3.go = "Sailing";						
			link.l4 = DLG_TEXT[86];			
			link.l4.go = "Accuracy";			
			link.l5 = DLG_TEXT[87];			
			link.l5.go = "Cannons";			
			link.l6 = DLG_TEXT[88];			
			link.l6.go = "Grappling";			
			link.l7 = DLG_TEXT[89];			
			link.l7.go = "Repair";			
			link.l8 = DLG_TEXT[90];			
			link.l8.go = "Defense";			
			link.l9 = DLG_TEXT[91];			
			link.l9.go = "Commerce";			
			link.l10 = DLG_TEXT[92];			
			link.l10.go = "luck";			
		break;

		case "Leadership":
			dialog.text = DLG_TEXT[93];			
			link.l1 = DLG_TEXT[94];			
			link.l1.go = "SkillDescription";			
			link.l2 = DLG_TEXT[95];			
			link.l2.go = "FuckTheSkillsLetsGo";	
			link.l3 = DLG_TEXT[96];			
			link.l3.go = "DistributePoints_1";			
		break;

		case "Melee Combat":
			dialog.text = DLG_TEXT[97];			
			link.l1 = DLG_TEXT[98];			
			link.l1.go = "SkillDescription";			
			link.l2 = DLG_TEXT[99];			
			link.l2.go = "FuckTheSkillsLetsGo";			
			link.l3 = DLG_TEXT[100];			
			link.l3.go = "DistributePoints_1";			
		break;

		case "Sailing":
			dialog.text = DLG_TEXT[101];			
			link.l1 = DLG_TEXT[102];			
			link.l1.go = "SkillDescription";			
			link.l2 = DLG_TEXT[103];			
			link.l2.go = "FuckTheSkillsLetsGo";			
			link.l3 = DLG_TEXT[104];			
			link.l3.go = "DistributePoints_1";			
		break;

		case "Accuracy":
			dialog.text = DLG_TEXT[105];			
			link.l1 = DLG_TEXT[106];			
			link.l1.go = "SkillDescription";			
			link.l2 = DLG_TEXT[107];			
			link.l2.go = "FuckTheSkillsLetsGo";			
			link.l3 = DLG_TEXT[108];			
			link.l3.go = "DistributePoints_1";			
		break;

		case "Cannons":
			dialog.text = DLG_TEXT[109];			
			link.l1 = DLG_TEXT[110];			
			link.l1.go = "SkillDescription";			
			link.l2 = DLG_TEXT[111];			
			link.l2.go = "FuckTheSkillsLetsGo";			
			link.l3 = DLG_TEXT[112];			
			link.l3.go = "DistributePoints_1";			
		break;

		case "Grappling":
			dialog.text = DLG_TEXT[113];			
			link.l1 = DLG_TEXT[114];			
			link.l1.go = "SkillDescription";			
			link.l2 = DLG_TEXT[115];			
			link.l2.go = "FuckTheSkillsLetsGo";			
			link.l3 = DLG_TEXT[116];			
			link.l3.go = "DistributePoints_1";			
		break;

		case "Repair":
			dialog.text = DLG_TEXT[117];			
			link.l1 = DLG_TEXT[118];			
			link.l1.go = "SkillDescription";			
			link.l2 = DLG_TEXT[119];			
			link.l2.go = "FuckTheSkillsLetsGo";			
			link.l3 = DLG_TEXT[120];			
			link.l3.go = "DistributePoints_1";			
		break;

		case "Commerce":
			dialog.text = DLG_TEXT[121];			
			link.l1 = DLG_TEXT[122];			
			link.l1.go = "SkillDescription";			
			link.l2 = DLG_TEXT[123];			
			link.l2.go = "FuckTheSkillsLetsGo";			
			link.l3 = DLG_TEXT[124];			
			link.l3.go = "DistributePoints_1";			
		break;

		case "Luck":
			dialog.text = DLG_TEXT[125];			
			link.l1 = DLG_TEXT[126];			
			link.l1.go = "SkillDescription";			
			link.l2 = DLG_TEXT[127];			
			link.l2.go = "FuckTheSkillsLetsGo";			
			link.l3 = DLG_TEXT[128];			
			link.l3.go = "DistributePoints_1";			
		break;

		case "Defense":
			dialog.text = DLG_TEXT[129];			
			link.l1 = DLG_TEXT[130];			
			link.l1.go = "SkillDescription";			
			link.l2 = DLG_TEXT[131];			
			link.l2.go = "FuckTheSkillsLetsGo";			
			link.l3 = DLG_TEXT[132];			
			link.l3.go = "DistributePoints_1";			
		break;


		case "FuckTheSkillsLetsGo":
			dialog.text = DLG_TEXT[133];			
			link.l1 = DLG_TEXT[134];			
			link.l1.go = "TutorialTasks";			
		break;

		case "TutorialTasks":
			dialog.text = DLG_TEXT[135];
			link.l1 = DLG_TEXT[136];
			link.l1.go = "TutorialTasks_1";				
		break;

		case "TutorialTasks_1":
			addDialogExitQuest("Tut_ReloadToOxbayPort");
			dialog.text = DLG_TEXT[137];
			link.l1 = DLG_TEXT[138];
			link.l1.go = "Exit";				
		break;

		case "NowLetsBuyASpyglass":
			dialog.text = DLG_TEXT[139];
			link.l1 = DLG_TEXT[140];
			link.l1.go = "GuideToSpyglass";				
			link.l2 = DLG_TEXT[141];
			link.l2.go = "ContinueWithoutSpyglass";
			link.l3 = DLG_TEXT[142];
			link.l3.go = "Skip_TutorialInPort";
		break;

		case "GuideToSpyglass":
			AddDialogExitQuest("Tut_GuideToSpyglass");
			dialog.text = DLG_TEXT[143];
			link.l1 = DLG_TEXT[144];
			link.l1.go = "Exit";							
		break;

		case "HereAretheTraders":
			addDialogExitQuest("Tut_SoBuyTheFuckingGlass");
			NextDiag.TempNode = "SoBuyTheFuckingGlass";
			dialog.text = DLG_TEXT[145];
			link.l1 = DLG_TEXT[146];
			link.l1.go = "Exit";							
		break;

		case "SoBuyTheFuckingGlass":
			if(CheckCharacterItem(Pchar, "spyglass2"))
			{
				dialog.text = DLG_TEXT[147];
				link.l1 = DLG_TEXT[148];
				link.l1.go = "GoToStore";
				link.l2 = DLG_TEXT[149];
				link.l2.go = "Skip_TutorialInPort";
			}
			else
			{
				NextDiag.TempNode = "SoBuyTheFuckingGlass";
				dialog.text = DLG_TEXT[150];
				link.l1 = DLG_TEXT[151];
				link.l1.go = "Exit";	
				link.l2 = DLG_TEXT[152];
				link.l2.go = "ContinueWithoutSpyglass";
				link.l3 = DLG_TEXT[153];
				link.l3.go = "Skip_TutorialInPort";
			}
		break;

		case "ContinueWithoutSpyglass":
			dialog.text = DLG_TEXT[154];
			link.l1 = DLG_TEXT[155];
			link.l1.go = "GoToStore";
			link.l2 = DLG_TEXT[156];
			link.l2.go = "Skip_TutorialInPort";
		break;

		case "GoToStore":
			AddDialogExitQuest("Tut_ReloadToOxbay");
			dialog.text = DLG_TEXT[157];
			link.l1 = DLG_TEXT[158];
			link.l1.go = "Exit";							
		break;

		case "NowGoTotheStore":
			dialog.text = DLG_TEXT[159];
			link.l1 = DLG_TEXT[160];
			link.l1.go = "NowGoTotheStore_1";
			link.l2 = DLG_TEXT[161];
			link.l2.go = "Skip_tutorialInTown";
		break;

		case "NowGoTotheStore_1":
			AddDialogExitQuest("Tut_MalcolmShowsTheStore");
			dialog.text = DLG_TEXT[162];
			link.l1 = DLG_TEXT[163];
			link.l1.go = "Exit";							
		break;

		case "MoreDetailsOnTrade":
			AddDialogExitQuest("Tut_StartTrading");
			dialog.text = DLG_TEXT[164]; 
			link.l1 = DLG_TEXT[165];
			link.l1.go = "MoreDetailsOnTrade_1";	
			link.l2 = DLG_TEXT[166];
			link.l2.go = "MoreDetailsOnTrade_2";							
		break;
		
		case "MoreDetailsOnTrade_1":
			dialog.text = DLG_TEXT[167];
			link.l1 = DLG_TEXT[168];
			link.l1.go = "MoreDetailsOnTrade_2";
		break;

		case "MoreDetailsOnTrade_2":
			dialog.text = DLG_TEXT[169];
			link.l1 = DLG_TEXT[170];
			link.l1.go = "exit";
		break;

		case "GoodsSoldInStore":
			if(GetCargoGoods(Pchar,GOOD_CHOCOLATE) != 0 || GetCargoGoods(Pchar,GOOD_LEATHER) != 0)
			{
				dialog.text = DLG_TEXT[171];
				link.l1 = DLG_TEXT[172];
				link.l1.go = "GoodsSoldInStore_1";
				link.l2 = DLG_TEXT[173];
				link.l2.go = "Skip_TutorialInTown";
			}
			else
			{
				dialog.text = DLG_TEXT[174];
				link.l1 = DLG_TEXT[175];
				link.l1.go = "GoodsSoldInStore_1";
				link.l2 = DLG_TEXT[176];
				link.l2.go = "Skip_TutorialInTown";
			}
		break;	

		case "GoodsSoldInStore_1":
			AddDialogExitQuest("Tut_MalcolmLeadsToTavern");
			dialog.text = DLG_TEXT[177];
			link.l1 = DLG_TEXT[178];
			link.l1.go = "exit";
		break;

		case "CrewHiringInTavern":
			dialog.text = DLG_TEXT[179];
			link.l1 = DLG_TEXT[180];
			link.l1.go = "CrewHiringInTavern_1";
		break;

		case "CrewHiringInTavern":
			dialog.text = DLG_TEXT[181];
			link.l1 = DLG_TEXT[182];
			link.l1.go = "CrewHiringInTavern_1";
		break;

		case "CrewHiringInTavern_1":
			addDialogExitQuest("Tut_MalcolmLeavesTavern");
			dialog.text = DLG_TEXT[183];
			link.l1 = DLG_TEXT[184];
			link.l1.go = "exit";
		break;

		case "CrewHiredintavern":
			if(GetMaxCrewQuantity(Pchar) == GetCrewQuantity(Pchar))
			{
				dialog.text = DLG_TEXT[185];
				link.l1 = DLG_TEXT[186];
				link.l1.go = "CrewHiredintavern_1";
				link.l2 = DLG_TEXT[187];
				link.l2.go = "Skip_TutorialInTown";
			}
			else
			{
				dialog.text = DLG_TEXT[188];
				link.l1 = DLG_TEXT[189];
				link.l1.go = "CrewHiredintavern_1";
				link.l2 = DLG_TEXT[190];
				link.l2.go = "Skip_TutorialInTown";
			}
		break;

		case "CrewHiredintavern_1":
			AddDialogExitQuest("Tut_BooGoForShipyard");
			dialog.text = DLG_TEXT[191];
			link.l1 = DLG_TEXT[192];
			link.l1.go = "exit";			
		break;

		case "ShipRepairing":
			dialog.text = DLG_TEXT[193];
			link.l1 = DLG_TEXT[194];
			link.l1.go = "ShipRepairing_1";
			link.l2 = DLG_TEXT[195];
			link.l2.go = "ShipRepairing_2";
		break;

		case "ShipRepairing_1":
			dialog.text = DLG_TEXT[196];
			link.l1 = DLG_TEXT[197];
			link.l1.go = "ShipRepairing_2";			
		break;

		case "ShipRepairing_2":
			AddDialogExitQuest("Tut_MalcolmLeavesShipyard");
			dialog.text = DLG_TEXT[198];
			link.l1 = DLG_TEXT[199];
			link.l1.go = "exit";			
		break;

		case "FinalStage":
			AddDialogExitQuest("Tut_Finished");
			dialog.text = DLG_TEXT[200];
			link.l1 = DLG_TEXT[201];
			link.l1.go = "FinalStage_1";			
		break;

		case "FinalStage_1":
			dialog.text = DLG_TEXT[202];
			link.l1 = DLG_TEXT[203];
			link.l1.go = "Suggestions";			
			link.l2 = DLG_TEXT[204];
			link.l2.go = "Ship_sailing";			
			link.l3 = DLG_TEXT[205];
			link.l3.go = "Final_Goodbye";			
		break;

		case "Suggestions":
			dialog.text = DLG_TEXT[206];
			link.l1 = DLG_TEXT[207];
			link.l1.go = "Loanshark";			
			link.l2 = DLG_TEXT[208];
			link.l2.go = "Ship_sailing";			
			link.l3 = DLG_TEXT[209];
			link.l3.go = "Final_Goodbye";			
		break;

		case "Loanshark":
			dialog.text = DLG_TEXT[210];
			link.l1 = DLG_TEXT[211];
			link.l1.go = "Ship_sailing";			
			link.l2 = DLG_TEXT[212];
			link.l2.go = "Final_Goodbye";			
		break;


		case "Skip_tutorial":
			dialog.text = DLG_TEXT[213];			
			link.l1 = DLG_TEXT[214];			
			link.l1.go = "Skip_tutorial_1";			
		break;

		case "Skip_tutorial_1":
			dialog.text = DLG_TEXT[215];
			link.l1 = DLG_TEXT[216];
			link.l1.go = "Skip_tutorial_2";				
		break;

		case "Skip_tutorial_2":
			addDialogExitQuest("Tut_SkipTutorialOnShip");
			dialog.text = DLG_TEXT[217];
			link.l1 = DLG_TEXT[218];
			link.l1.go = "Exit";				
		break;

		case "Skip_TutorialInPort":
			addDialogExitQuest("Tut_SkipTutorialInPort");
			dialog.text = DLG_TEXT[219];
			link.l1 = DLG_TEXT[220];
			link.l1.go = "Skip_TutorialInPort_1";			
		break

		case "Skip_TutorialInPort_1":
			dialog.text = DLG_TEXT[221];
			link.l1 = DLG_TEXT[222];
			link.l1.go = "Suggestions";			
			link.l2 = DLG_TEXT[223];
			link.l2.go = "Ship_sailing";			
			link.l3 = DLG_TEXT[224];
			link.l3.go = "Final_Goodbye";			
		break;

		case "Skip_TutorialInTown":
			addDialogExitQuest("Tut_SkipTutorialInTown");
			dialog.text = DLG_TEXT[225];
			link.l1 = DLG_TEXT[226];
			link.l1.go = "Skip_TutorialInTown_1";			
		break;

		case "Skip_TutorialInTown_1":
			dialog.text = DLG_TEXT[227];
			link.l1 = DLG_TEXT[228];
			link.l1.go = "Suggestions";			
			link.l2 = DLG_TEXT[229];
			link.l2.go = "Ship_sailing";			
			link.l3 = DLG_TEXT[230];
			link.l3.go = "Final_Goodbye";			
		break;

		case "Ship_sailing":
			dialog.text = DLG_TEXT[231];
			link.l1 = DLG_TEXT[232];
			link.l1.go = "CannonFire";			
			link.l2 = DLG_TEXT[233];
			link.l2.go = "BoardingShips";			
			link.l3 = DLG_TEXT[234];
			link.l3.go = "Final_Goodbye";			
		break;

		case "CannonFire":
			dialog.text = DLG_TEXT[235];
			link.l1 = DLG_TEXT[236];
			link.l1.go = "BoardingShips";			
			link.l2 = DLG_TEXT[237];
			link.l2.go = "Ship_sailing";			
			link.l3 = DLG_TEXT[238];
			link.l3.go = "Final_Goodbye";			
		break;

		case "BoardingShips":
			dialog.text = DLG_TEXT[239];
			link.l1 = DLG_TEXT[240];
			link.l1.go = "CannonFire";			
			link.l2 = DLG_TEXT[241];
			link.l2.go = "Ship_sailing";			
			link.l3 = DLG_TEXT[242];
			link.l3.go = "Final_Goodbye";			
		break;

		case "Final_Goodbye":
			AddDialogExitQuest("Tut_SkipTutorialInTown");
			NextDiag.Tempnode = "Questions";
			dialog.text = DLG_TEXT[243];
			link.l1 = DLG_TEXT[244];
			link.l1.go = "Exit";						
		break;

		case "Questions":
			dialog.text = DLG_TEXT[245];
			link.l1 = DLG_TEXT[246];
			link.l1.go = "Suggestions";			
			link.l2 = DLG_TEXT[247];
			link.l2.go = "Ship_sailing";			
			link.l3 = DLG_TEXT[248];
			link.l3.go = "Final_Goodbye";			
		break;




	}
}


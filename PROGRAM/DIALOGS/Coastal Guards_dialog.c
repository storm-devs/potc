//nclude "DIALOGS\Coastal Guards_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d, her;
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
		// -----------------------------------Диалог первый - первая встреча

		case "exit":
			StopCoastalGuardPursuit();
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
			LAi_SetPlayerType(Pchar);
		break;

		case "First time":			
			dialog.snd = "Voice\COGU\COGU001";
			d.Text = DLG_TEXT[0];
			Link.l1 = DLG_TEXT[1];
			if(makeint(Pchar.reputation) >= 80 && makeint(Pchar.skill.Leadership) >= 5)
			{
				Link.l1.go = "ThisTimeFree";
			}
			else
			{
				Link.l1.go = "IDontBelieveYou";
			}
			Link.l2 = DLG_TEXT[2];
			if(makeint(Pchar.rank) >= 4 && makeint(Pchar.skill.Commerce) >= 5)
			{
				Link.l2.go = "GiveMeSomeMoneyToo";
			}
			else
			{
				Link.l2.go = "TryingToGiveBribe";
			}
			Link.l3 = DLG_TEXT[3];
			if(makeint(Pchar.reputation) <= 10 && makeint(Pchar.skill.Fencing) >= 8)
			{
				Link.l3.go = "GettingLostFromHere";
			}
			else
			{
				Link.l3.go = "howDareYou";
			}

		break;

		case "ThisTimeFree":
			dialog.snd = "Voice\COGU\COGU002";		
			d.Text = DLG_TEXT[4] + Pchar.name + DLG_TEXT[5];
			Link.l1 = DLG_TEXT[6];
			Link.l1.go = "ThisTimeFree_1";
			Link.l2 = DLG_TEXT[7];
			Link.l2.go = "ThisTimeFree_fight";				
		break;

		case "ThisTimeFree_1":	
			dialog.snd = "Voice\COGU\COGU003";	
			ChangeCharacterReputation(pchar, -40);
			d.Text = DLG_TEXT[8];
			Link.l1 = DLG_TEXT[9];
			Link.l1.go = "ThisTimeFree_exit";
		break;

		case "ThisTimeFree_fight":			
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();

			Pchar.quest.Rand_ContrabandInterruptionAtSeaEnded.win_condition.l1 = "MapEnter";
			Pchar.quest.Rand_ContrabandInterruptionAtSeaEnded.win_condition = "Rand_ContrabandInterruptionAtSeaEnded";


			
			LAi_group_FightGroups("Smugglers", "CoastalGuards", true);
			LAi_group_FightGroups(LAI_GROUP_PLAYER, "CoastalGuards", true);

			LAi_SetPlayerType(Pchar);

			trace("And we fight those soldiers!!" + Pchar.quest.contraband.CurrentPlace);
		break;

		case "ThisTimeFree_exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();

			StopCoastalGuardPursuit();
			pchar.quest.Contraband.relation = makeint(pchar.quest.Contraband.relation) - 30;

						
			LAi_group_FightGroups("Smugglers", "CoastalGuards", true);
			LAi_SetPlayerType(Pchar);
		break;

		case "IDontBelieveYou":
			dialog.snd = "Voice\COGU\COGU004";
			d.Text = DLG_TEXT[10];
			Link.l1 = DLG_TEXT[11];
			Link.l1.go = "ThisTimeFree_fight";
		break;

		case "GiveMeSomeMoneyToo":	
			dialog.snd = "Voice\COGU\COGU005";		
			d.Text = DLG_TEXT[12];
			Link.l1 = DLG_TEXT[13] + makeint(sti(Pchar.money)/10) + DLG_TEXT[14] ;
			if(makeint(Pchar.rank)*1000 <= makeint(sti(Pchar.money)/10))
			{
				Link.l1.go = "MoneyAccepted";
			}
			else
			{
				Link.l1.go = "TryingToGiveBribe";
			}

			Link.l2 = DLG_TEXT[15] + makeint(sti(Pchar.money)/5) + DLG_TEXT[16];
			if(makeint(Pchar.rank)*1000 <= makeint(sti(Pchar.money)/5))
			{
				Link.l2.go = "MoneyAccepted";
			}
			else
			{
				Link.l2.go = "TryingToGiveBribe";
			}

			Link.l3 = DLG_TEXT[17] + makeint(sti(Pchar.money)/2) + DLG_TEXT[18];
			if(makeint(Pchar.rank)*1000 <= makeint(sti(Pchar.money)/2))
			{
				Link.l3.go = "MoneyAccepted";
			}
			else
			{
				Link.l3.go = "TryingToGiveBribe";
			}
		break;

		case "TryingToGiveBribe":
			dialog.snd = "Voice\COGU\COGU006";
			d.Text = DLG_TEXT[19];
			Link.l1 = DLG_TEXT[20];
			Link.l1.go = "ThisTimeFree_fight";
		break;

		case "MoneyAccepted":
			dialog.snd = "Voice\COGU\COGU007";
			d.Text = DLG_TEXT[21];
			Link.l1 = DLG_TEXT[22];
			Link.l1.go = "ThisTimeFree_fight";
		break;

		case "GettingLostFromHere":
			dialog.snd = "Voice\COGU\COGU008";
			d.Text = DLG_TEXT[23];
			Link.l1 = DLG_TEXT[24];
			Link.l1.go = "GettingLostFromHere_1";
		break;

		case "GettingLostFromHere_1":
			dialog.snd = "Voice\COGU\COGU009";
			d.Text = DLG_TEXT[25];
			Link.l1 = DLG_TEXT[26];
			Link.l1.go = "GettingLostFromHere_exit";
		break;

		case "GettingLostFromHere_exit":
			pchar.quest.Contraband.relation = makeint(pchar.quest.Contraband.relation) + 10;

			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();

			StopCoastalGuardPursuit();
			LAi_ActorRunToLocation(&Characters[Pchar.quest.contraband.SoldierIDX1], "reload", "Reload1", "none", "", "", "", 120);
			LAi_ActorRunToLocation(&Characters[Pchar.quest.contraband.SoldierIDX2], "reload", "Reload1", "none", "", "", "", 120);
			LAi_ActorRunToLocation(&Characters[Pchar.quest.contraband.SoldierIDX3], "reload", "Reload1", "none", "", "", "", 120);
			LAi_ActorRunToLocation(&Characters[Pchar.quest.contraband.SoldierIDX4], "reload", "Reload1", "none", "", "", "", 120);
			LAi_ActorRunToLocation(&Characters[Pchar.quest.contraband.SoldierIDX5], "reload", "Reload1", "none", "", "", "", 120);
			LAi_ActorRunToLocation(&Characters[Pchar.quest.contraband.SoldierIDX6], "reload", "Reload1", "none", "", "", "", 120);
			LAi_SetPlayerType(Pchar);
		break;

		case "howDareYou":
			dialog.snd = "Voice\COGU\COGU010";
			d.Text = DLG_TEXT[27];
			Link.l1 = DLG_TEXT[28];
			Link.l1.go = "ThisTimeFree_fight";
		break;




	}
}
void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
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
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();			
		break;

		case "exit_hire":
			DeleteAttribute(Npchar, "quest.discount");
			Pchar.quest.HiringOfficerIDX = GetCharacterIndex(Npchar.id);
			AddDialogExitQuest("LandEnc_OfficerHired");
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

		case "exit_fire":
			Pchar.quest.FiringOfficerIDX = GetCharacterIndex(Npchar.id);
			AddDialogExitQuest("LandEnc_OfficerFired");
			
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;

			DialogExit();			
		break;

		case "Node_1":
			Dialog.defAni = "dialog_stay2";
			Dialog.defCam = "2";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";

			switch(Rand(4))
			{
				case 0:
					Npchar.quest.officertype = GlobalStringConvert("OFFIC_TYPE_BOATSWAIN");
					Npchar.quest.LeadershipModify = 0;
					Npchar.quest.FencingModify = Rand(3) + 2;
					Npchar.quest.SailingModify = 0;
					Npchar.quest.AccuracyModify = 0;
					Npchar.quest.CannonsModify = 0;
					Npchar.quest.GrapplingModify = Rand(3) + 2;
					Npchar.quest.RepairModify = 0;
					Npchar.quest.DefenseModify = 0;
					Npchar.quest.CommerceModify = 0;
					Npchar.quest.SneakModify = 0;
				break;

				case 1:
					Npchar.quest.officertype = GlobalStringConvert("OFFIC_TYPE_CANNONEER");
					Npchar.quest.LeadershipModify = 0;
					Npchar.quest.FencingModify = 0;
					Npchar.quest.SailingModify = 0;
					Npchar.quest.AccuracyModify = Rand(3) + 2;
					Npchar.quest.CannonsModify = Rand(3) + 2;
					Npchar.quest.GrapplingModify = 0;
					Npchar.quest.RepairModify = 0;
					Npchar.quest.DefenseModify = 0;
					Npchar.quest.CommerceModify = 0;
					Npchar.quest.SneakModify = 0;
				break;

				case 2:
					Npchar.quest.officertype = GlobalStringConvert("OFFIC_TYPE_QMASTER");
					Npchar.quest.LeadershipModify = 0;
					Npchar.quest.FencingModify = 0;
					Npchar.quest.SailingModify = 0;
					Npchar.quest.AccuracyModify = 0;
					Npchar.quest.CannonsModify = 0;
					Npchar.quest.GrapplingModify = 0;
					Npchar.quest.RepairModify = Rand(3) + 2;
					Npchar.quest.DefenseModify = 0;
					Npchar.quest.CommerceModify = Rand(3) + 2;
					Npchar.quest.SneakModify = 0;
				break;

				case 3:
					Npchar.quest.officertype = GlobalStringConvert("OFFIC_TYPE_NAVIGATOR");
					Npchar.quest.LeadershipModify = 0;
					Npchar.quest.FencingModify = 0;
					Npchar.quest.SailingModify = Rand(3) + 2;
					Npchar.quest.AccuracyModify = 0;
					Npchar.quest.CannonsModify = 0;
					Npchar.quest.GrapplingModify = 0;
					Npchar.quest.RepairModify = 0;
					Npchar.quest.DefenseModify = Rand(3) + 2;
					Npchar.quest.CommerceModify = 0;
					Npchar.quest.SneakModify = 0;
				break;

				case 4:
					Npchar.quest.officertype = GlobalStringConvert("OFFIC_TYPE_FIRSTMATE");
					Npchar.quest.LeadershipModify = Rand(3) + 2;
					Npchar.quest.FencingModify = 0;
					Npchar.quest.SailingModify = 0;
					Npchar.quest.AccuracyModify = 0;
					Npchar.quest.CannonsModify = 0;
					Npchar.quest.GrapplingModify = 0;
					Npchar.quest.RepairModify = 0;
					Npchar.quest.DefenseModify = 0;
					Npchar.quest.CommerceModify = 0;
					Npchar.quest.SneakModify = Rand(3) + 2;
				break;
			}

			Npchar.rank = makeint(Pchar.rank) - 2 + Rand(4);
			Npchar.experience = CalculateExperienceFromRank(sti(Npchar.rank));

			CalculateAppropriateSkills(NPchar);

			Npchar.skill.Leadership = makeint(Npchar.skill.Leadership) + makeint(Npchar.quest.LeadershipModify);
			Npchar.skill.Fencing = makeint(Npchar.skill.Fencing) + makeint(Npchar.quest.FencingModify);
			Npchar.skill.Sailing = makeint(Npchar.skill.Sailing) + makeint(Npchar.quest.SailingModify);
			Npchar.skill.Accuracy = makeint(Npchar.skill.Accuracy)  + makeint(Npchar.quest.AccuracyModify);
			Npchar.skill.Cannons = makeint(Npchar.skill.Cannons)  + makeint(Npchar.quest.CannonsModify);
			Npchar.skill.Grappling = makeint(Npchar.skill.Grappling) + makeint(Npchar.quest.GrapplingModify);
			Npchar.skill.Repair = makeint(Npchar.skill.Repair) + makeint(Npchar.quest.RepairModify);
			Npchar.skill.Defence = makeint(Npchar.skill.Defence) + makeint(Npchar.quest.DefenseModify);
			Npchar.skill.Commerce = makeint(Npchar.skill.Commerce) + makeint(Npchar.quest.CommerceModify);
			Npchar.skill.Sneak = makeint(Npchar.skill.Sneak) + makeint(Npchar.quest.SneakModify);

			if(makeint(Npchar.skill.Leadership)	>= 10) Npchar.skill.Leadership = 10;
			if(makeint(Npchar.skill.Fencing)	>= 10) Npchar.skill.Fencing = 10;
			if(makeint(Npchar.skill.Sailing)	>= 10) Npchar.skill.Sailing = 10;
			if(makeint(Npchar.skill.Accuracy)	>= 10) Npchar.skill.Accuracy = 10;
			if(makeint(Npchar.skill.Cannons)	>= 10) Npchar.skill.Cannons = 10;
			if(makeint(Npchar.skill.Grappling)	>= 10) Npchar.skill.Grappling = 10;
			if(makeint(Npchar.skill.Repair)	>= 10) Npchar.skill.Repair = 10;
			if(makeint(Npchar.skill.Defence)	>= 10) Npchar.skill.Defence = 10;
			if(makeint(Npchar.skill.Commerce)	>= 10) Npchar.skill.Commerce = 10;
			if(makeint(Npchar.skill.Sneak)	>= 10) Npchar.skill.Sneak = 10;

			Npchar.quest.OfficerPrice = (makeint(Npchar.skill.Leadership) + makeint(Npchar.skill.Fencing) + makeint(Npchar.skill.Sailing) + makeint(Npchar.skill.Accuracy) + makeint(Npchar.skill.Cannons) + makeint(Npchar.skill.Grappling) + makeint(Npchar.skill.Repair) + makeint(Npchar.skill.Defence) + makeint(Npchar.skill.Commerce) + makeint(Npchar.skill.Sneak))*100;

			Diag.TempNode = "OnceAgain";

			d.Text = DLG_TEXT[0];
			Link.l1 = DLG_TEXT[1];
			Link.l1.go = "Node_2";
			Link.l2 = DLG_TEXT[2];
			Link.l2.go = "Exit";
			
		break;

		case "Node_2":
			d.Text = DLG_TEXT[3] + Npchar.quest.officertype + DLG_TEXT[4];
			Link.l1 = DLG_TEXT[5];
			Link.l1.go = "price";
			Link.l2 = DLG_TEXT[6] + Npchar.quest.officertype + DLG_TEXT[7];
			Link.l2.go = "Exit";			

		break;

		case "OnceAgain":
			Diag.TempNode = "OnceAgain";
			d.Text = DLG_TEXT[8] + Npchar.quest.officertype + DLG_TEXT[9];
			Link.l1 = DLG_TEXT[10];
			Link.l1.go = "price";
			Link.l2 = DLG_TEXT[11];
			Link.l2.go = "exit";
		break;

		case "price":
			d.Text = DLG_TEXT[12] + Npchar.quest.OfficerPrice + DLG_TEXT[13];
			Link.l1 = DLG_TEXT[14];
			Link.l1.go = "trade";
			Link.l2 = DLG_TEXT[15];
			Link.l2.go = "hire";
			Link.l3 = DLG_TEXT[16];
			Link.l3.go = "exit";
		break;

		case "trade":
			if(makeint(Pchar.skill.commerce) >= Rand(6) && CheckAttribute(NPchar, "quest.discount") != true )
			{
				Npchar.quest.discount = 1;
				Npchar.quest.OfficerPrice = makeint(Npchar.quest.OfficerPrice) - makeint(Pchar.skill.commerce)*100;
				d.Text = DLG_TEXT[17] + Npchar.quest.OfficerPrice + DLG_TEXT[18];
				Link.l1 = DLG_TEXT[19];
				Link.l1.go = "hire";				
				Link.l2 = DLG_TEXT[20];
				Link.l2.go = "exit";
			}
			else
			{
				d.Text = DLG_TEXT[21];
				Link.l1 = DLG_TEXT[22];
				Link.l1.go = "hire";				
				Link.l2 = DLG_TEXT[23];
				Link.l2.go = "exit";
			}
		break;

		case "hire":
			if(makeint(Pchar.money) >= makeint(Npchar.quest.OfficerPrice))
			{
				AddMoneyToCharacter(Pchar, -(makeint(Npchar.quest.OfficerPrice)));
				Diag.TempNode = "OnboardSoon";
				d.Text = DLG_TEXT[24];
				Link.l1 = DLG_TEXT[25];
				Link.l1.go = "Exit_hire";								
			}
			else
			{
				d.Text = DLG_TEXT[26];
				Link.l1 = DLG_TEXT[27];
				Link.l1.go = "Exit";								
			}
		break;

		case "OnboardSoon":			
			Diag.TempNode = "OnboardSoon";
			d.Text = DLG_TEXT[28];
			Link.l1 = DLG_TEXT[29];
			Link.l1.go = "Exit";											
		break;


		case "hired":
			Diag.TempNode = "Hired";
			d.Text = DLG_TEXT[30];
			Link.l1 = DLG_TEXT[31];
			Link.l1.go = "Exit";								
			Link.l2 = DLG_TEXT[32];
			Link.l2.go = "AsYouWish";		
		break;

		case "AsYouWish":
			//Diag.TempNode = "Fired";
			d.Text = DLG_TEXT[33];
			Link.l1 = DLG_TEXT[34];
			Link.l1.go = "Exit";								
			Link.l2 = DLG_TEXT[35];
			Link.l2.go = "Exit_Fire";		
		break;

		case "Fired":
			Diag.TempNode = "Fired";
			d.Text = DLG_TEXT[36];
			Link.l1 = DLG_TEXT[37];
			Link.l1.go = "Exit";											
		break;




	}
}
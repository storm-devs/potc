// Set characters initial data

void CreateCharacters()
{
 	ref ch;
	int n;

	for(n=0; n<TOTAL_CHARACTERS; n++)
	{
		makeref(ch,Characters[n]);
		//DeleteAttribute(ch,"act");
		DeleteAttribute(ch,"");
		//Logic data
		ch.id = "0";
		ch.index = n;
		ch.sex = "man";
		//Model data
		ch.model = "none";
		ch.model.entity = "NPCharacter";
		ch.model.animation = "";
		//Address
		ch.location = "none";
		ch.location.group = "";
		ch.location.locator = "";
		ch.location.from_sea = "";
		//Ship data
		ch.Ship.Type = SHIP_NOTUSED;//SHIP_LUGGER;
		//Quest data
		ch.Dialog.CurrentNode = "First time";
		ch.Dialog.TempNode = ch.Dialog.CurrentNode;
		ch.quest.meeting = "0";
		ch.quest = "True";
		//Misc data
		ch.nation = ENGLAND;
		ch.skill.freeskill = 0;
		ch.rank = 1;
		ch.reputation = REPUTATION_NEUTRAL;
		// battle hp
		ch.headModel = "capitan";
		LAi_SetLoginTime(ch, 6.0, 21.98333);
		LAi_SetHP(ch, LAI_DEFAULT_HP, LAI_DEFAULT_HP_MAX);
	}

	ReloadProgressUpdate();

	makeref(ch,Characters[0]);		//Blaze Devlin
	//ch.perks.list.InstantBoarding = true;
	ch.name 	= "Nathaniel";
	ch.lastname = "Hawk";
	ch.id		= "Blaze";
	ch.nation	= ENGLAND;
	ch.model	= "blaze";
	ch.activity_begin = "0";
	ch.activity_end = "24";
	ch.sex = "man";
	ch.luck = 4;
	/*ch.spyglass.itemID = COMMON_SPYGLASS;
	ch.gun.itemID = GUN_COMMON;
	ch.gun = "gun";
	ch.blade = "saber";
	ch.blade.itemID = BLADE_SABER;
	ch.blade.time = 0.1;
	ch.blade.colorstart = argb(128, 22, 46, 190);
	ch.blade.colorend = argb(0, 20, 60, 100);*/
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "blaze_dialog.c";
	ch.rank 	= 1;
	ch.reputation = "50";
	ch.experience = 0;//CalculateExperienceFromRank(sti(ch.rank));
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "1";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.skill.freeskill = 2;
	ch.perks.freepoints = 1;
	ch.money = "1000";
	ch.Ship.Name = "Victory";
	//ch.Ship.Type = SHIP_FRIGATE_ENGLAND;
	//ch.Ship.Type = SHIP_CORVETTE_ENGLAND;
	ch.Ship.Type = SHIP_LUGGER_ENGLAND;
	//ch.Ship.Type = SHIP_MANOWAR2_FRANCE;
	ch.Ship.Stopped = true;
	//ch.Ship.Cannons.Type = CANNON_TYPE_TEST;
	ch.FaceId = 31;
	ch.ShipSlot1.Type=SHIP_NOTUSED;
	ch.ShipSlot1.Name="NoName";
	ch.ShipSlot2.Type=SHIP_NOTUSED;
	ch.ShipSlot2.Name="NoName";
	ch.ShipSlot3.Type=SHIP_NOTUSED;
	ch.ShipSlot3.Name="NoName";

	ch.quest.Contraband.relation = 50;
	ch.quest.RelationAgentMet = "0";
	ch.quest.gambling = "0";
	ch.quest.friend_in_tavern = "";
	ch.quest.main_line = "0";
	ch.quest.killed.pirates = "0";
	Ch.quest.Story_LeavingOxbay.win_condition.l1 = "location";
	Ch.quest.Story_LeavingOxbay.win_condition.l1.character = "Blaze";
	Ch.quest.Story_LeavingOxbay.win_condition.l1.location = "Oxbay";
	Ch.quest.Story_LeavingOxbay.win_condition = "Story_leavingOxbay";
	Ch.quest.Story_LeavingOxbay.fail_condition = "Story_leavingOxbay";

/*	string stmp;
	stmp = GUN_COMMON;	Ch.items.(stmp) = 1;
	stmp = POTION;	Ch.items.(stmp) = 2;
	stmp = BLADE_SABER;	Ch.items.(stmp) = 1;
	stmp = CHEAP_SPYGLASS;	Ch.items.(stmp) = 1;*/

	// QUESTS BEGINNINGS

	// Main story line
	Ch.quest.Begining.win_condition.l1 = "location";
	Ch.quest.Begining.win_condition.l1.location = "Oxbay_port";
	Ch.quest.Begining.win_condition = "Begining";

	//Hitman

	ch.quest.Hitman = "";
	ch.quest.Hit_start.win_condition.l1 = "location";
	ch.quest.Hit_start.win_condition.l1.character = ch.id;
	ch.quest.Hit_start.win_condition.l1.location = "Oxbay_port";
	ch.quest.Hit_start.win_condition = "Hit_start";

	//Hitman

	//Lucas

	ch.quest.Lucas = "";
	ch.quest.Luc_start.win_condition.l1 = "location";
	ch.quest.Luc_start.win_condition.l1.character = ch.id;
	ch.quest.Luc_start.win_condition.l1.location = "Muelle_Residence";
	ch.quest.Luc_start.win_condition = "Luc_start";


	//Lucas

	//Tutorial

	ch.quest.Tut_start.win_condition.l1 = "location";
	ch.quest.Tut_start.win_condition.l1.character = ch.id;
	ch.quest.Tut_start.win_condition.l1.location = "Tutorial_Deck";
	ch.quest.Tut_start.win_condition = "Tut_start";

	//Tutorial

	// Artois Voysey and Nigel Blythe quest
	Ch.quest.Story_Artois_Nigel.win_condition.l1 = "location";
	Ch.quest.Story_Artois_Nigel.win_condition.l1.character = "Blaze";
	Ch.quest.Story_Artois_Nigel.win_condition.l1.location = "QC_town";
	Ch.quest.Story_Artois_Nigel.win_condition = "Story_Artois";
	//

	ReloadProgressUpdate();

	n = 1;
	n = CreateFalaiseDeFleurCharacters(n);
	ReloadProgressUpdate();
	n = CreateRedmondCharacters(n);
	ReloadProgressUpdate();
	n = CreateIslaMuelleCharacters(n);
	ReloadProgressUpdate();
	n = CreateOxbayCharacters(n);
	ReloadProgressUpdate();
	n = CreateConceicaoCharacters(n);
	ReloadProgressUpdate();
	n = CreateDouwesenCharacters(n);
	ReloadProgressUpdate();
	n = CreateOfficersCharacters(n);
	ReloadProgressUpdate();
	n = CreateStoryCharacters(n);
	ReloadProgressUpdate();
	n = CreateTempQuestCharacters(n);
	ReloadProgressUpdate();
	n = CreateQuebradasCostillasCharacters(n);
	ReloadProgressUpdate();
	n = CreateTempQuestEnemy(n);
	ReloadProgressUpdate();
	n = CreateFortCommandants(n);
	ReloadProgressUpdate();
	n = CreateTownUsurers(n);
	ReloadProgressUpdate();
	n = CreateStreetMerchants(n);
	ReloadProgressUpdate();
	//Trace("NChar: " + n);

	CreateOtherCharacters();

	ReloadProgressUpdate();

	if(GetMainCharacterIndex()>=0)
	{
		SetMainCharacterIndex(GetMainCharacterIndex());
	}

	//SetAllShipData();
	//SetAllFellows();

	//Post init
	for(n=0; n<TOTAL_CHARACTERS; n++)
	{
		ref rCharacter = GetCharacter(n);

		if(rCharacter.sex == "man")
		{
			rCharacter.model.animation = "man";
			rCharacter.model.height = 1.8;
		}else{
			rCharacter.model.animation = "towngirl";
			rCharacter.model.height = 1.75;
		}
		rCharacter.FaceGroup = 0;

		// set fellows
		if (CheckAttribute(rCharacter,"fellows")) { SetBaseFellows(rCharacter); }
		// set base ship data
		SetBaseShipData(rCharacter);

		if(n > 1) rCharacter.FaceId = 0;

		switch (rCharacter.model)
		{
			case "black_corsair": 	rCharacter.FaceId = 0; break;
			case "bocman1":			rCharacter.FaceId = 1; break;
			case "bocman3":			rCharacter.FaceId = 2; break;
			case "bocman4":			rCharacter.FaceId = 3; break;
			case "brodyaga":		rCharacter.FaceId = 4; break;
			case "capitan":			rCharacter.FaceId = 5; break;
			case "capitan1":		rCharacter.FaceId = 6; break;
			case "chameleon":		rCharacter.FaceId = 7; break;
			case "chelovek":		rCharacter.FaceId = 8; break;
			case "chelovek1":		rCharacter.FaceId = 9; break;
			case "corsair1":		rCharacter.FaceId = 10; break;
			case "corsair1_1":		rCharacter.FaceId = 11; break;
			case "corsair1_2":		rCharacter.FaceId = 12; break;
			case "corsair2":		rCharacter.FaceId = 13; break;
			case "corsair3":		rCharacter.FaceId = 14; break;
			case "danielle":		rCharacter.FaceId = 15; break;
			case "blaze":			rCharacter.FaceId = 16; break;
			case "fawn":			rCharacter.FaceId = 17; break;
			case "killer":			rCharacter.FaceId = 18; break;
			case "korsar":			rCharacter.FaceId = 19; break;
			case "korsar1":			rCharacter.FaceId = 20; break;
			case "lucas":			rCharacter.FaceId = 21; break;
			case "maltese":			rCharacter.FaceId = 22; break;
			case "man1":			rCharacter.FaceId = 23; break;
			case "man1_1":			rCharacter.FaceId = 24; break;
			case "man1_2":			rCharacter.FaceId = 25; break;
			case "man2":			rCharacter.FaceId = 26; break;
			case "man3":			rCharacter.FaceId = 27; break;
			case "man3_1":			rCharacter.FaceId = 28; break;
			case "man6":			rCharacter.FaceId = 29; break;
			case "man6_1":			rCharacter.FaceId = 30; break;
			case "offic_fra":		rCharacter.FaceId = 31; break;
			case "old_man1":		rCharacter.FaceId = 32; break;
			case "old_man2":		rCharacter.FaceId = 33; break;
			case "researcher":		rCharacter.FaceId = 34; break;
			case "sailor1":			rCharacter.FaceId = 35; break;
			case "sailor2":			rCharacter.FaceId = 36; break;
			case "sailor3":			rCharacter.FaceId = 37; break;
			case "sailor4":			rCharacter.FaceId = 38; break;
			case "sailor5":			rCharacter.FaceId = 39; break;
			case "sailor6":			rCharacter.FaceId = 40; break;
			case "animists2":		rCharacter.FaceId = 41; break;
			case "storeman":		rCharacter.FaceId = 42; break;
			case "storeman2":		rCharacter.FaceId = 43; break;
			case "will_2":			rCharacter.FaceId = 44; break;
			case "huber_eng":		rCharacter.FaceId = 45; break;
			case "blackman":		rCharacter.FaceId = 46; break;
		}

		rCharacter.headModel = "h_" + rCharacter.model;
		if(CheckAttribute(rCharacter,"blade"))
		{
			if(CheckAttribute(rCharacter,"blade.itemID"))
			{
				rCharacter.equip.blade = rCharacter.blade.itemID;
			}
			else
			{
				rCharacter.equip.blade = BLADE_SABER;
			}
			DeleteAttribute(rCharacter,"blade");
		}
		if(CheckAttribute(rCharacter,"gun"))
		{
			if(CheckAttribute(rCharacter,"gun.itemID"))
			{
				rCharacter.equip.gun = rCharacter.gun.itemID;
			}
			else
			{
				rCharacter.equip.gun = GUN_COMMON;
			}
			DeleteAttribute(rCharacter,"gun");
		}
		if(CheckAttribute(rCharacter,"spyglass.itemID"))
		{
			rCharacter.equip.spyglass = rCharacter.spyglass.itemID;
			DeleteAttribute(rCharacter,"spyglass");
		}
	}

	// MainCharacter start parameters
	ch.Ship.HP = 300;
	ch.Ship.crew.quantity = 30;
	SetCharacterGoods(&Characters[0],GOOD_BALLS,300);
	SetCharacterGoods(&Characters[0],GOOD_GRAPES,100);
	SetCharacterGoods(&Characters[0],GOOD_KNIPPELS,100);
	SetCharacterGoods(&Characters[0],GOOD_BOMBS,300);
	SetCharacterGoods(&Characters[0],GOOD_CHOCOLATE,100);
	SetCharacterGoods(&Characters[0],GOOD_LEATHER,25);

	Characters[GetCharacterIndex("Danielle")].model.animation = "woman";

	ReloadProgressUpdate();

}

void SetAllShipData()
{
	for(int i=0;i<MAX_CHARACTERS;i++)
	{
		SetBaseShipData(GetCharacter(i));
	}
}

void SetAllFellows()
{
	ref rcc;
	for(int i=0;i<MAX_CHARACTERS;i++)
	{
		rcc = GetCharacter(i);
		if(CheckAttribute(rcc,"fellows"))
		{
			SetBaseFellows(rcc);
		}
	}
}

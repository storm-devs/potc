void BothQuestComplete(string sQuestName)
{
	ref PChar, NPChar, sld;
	PChar = GetMainCharacter();
	float locx;
	float locy;
	float locz;

	float ocx;
	float ocy;
	float ocz;

	trace ("ПРОВЕРЯЕТСЯ КВЕСТ " + sQuestName);
	switch(sQuestName)
	{

		////////////////////////////////////////////////////////////////////////
		//  Квест про проклятые монетки
		////////////////////////////////////////////////////////////////////////
	
		case "Story_CursedCoinsStarted":
			GiveItem2Character(Pchar,"Chest");

			Locations[FindLocation("Redmond_town_01")].locators_radius.goto.goto17 = 5.0;

			ChangeCharacterAddressGroup(CharacterFromID("Cursed_Pirate_01"), "Redmond_town_01", "goto", "goto54");
			ChangeCharacterAddressGroup(CharacterFromID("Cursed_Pirate_02"), "Redmond_town_01", "goto", "goto55");
			
			Pchar.quest.Story_CursedCoinsEncounter.win_condition.l1 = "locator";
			Pchar.quest.Story_CursedCoinsEncounter.win_condition.l1.location = "Redmond_town_01";
			Pchar.quest.Story_CursedCoinsEncounter.win_condition.l1.locator_group = "goto";
			Pchar.quest.Story_CursedCoinsEncounter.win_condition.l1.locator = "goto17";
			Pchar.quest.Story_CursedCoinsEncounter.win_condition = "Story_CursedCoinsEncounter";
		break;

		case "Story_CursedCoinsEncounter":
			LAi_SetActorType(Pchar);
			LAi_SetActorType(CharacterFromID("Cursed_Pirate_01"));
			LAi_SetActorType(CharacterFromID("Cursed_Pirate_02"));
			LAi_ActorTurnToCharacter(Pchar, CharacterFromID("Cursed_Pirate_01"));
			LAi_ActorWaitDialog(Pchar, CharacterFromID("Cursed_Pirate_01"));
			LAi_ActorDialog(CharacterFromID("Cursed_Pirate_01"), PChar, "", 20.0, 1.0);
			LAi_ActorFollow(CharacterFromID("Cursed_Pirate_02"), PChar, "", 30.0);
			LAi_group_MoveCharacter(CharacterFromID("Cursed_Pirate_01"), "CURSED_PIRATES");
			LAi_group_MoveCharacter(CharacterFromID("Cursed_Pirate_02"), "CURSED_PIRATES");

			LAi_group_SetRelation("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_NEITRAL);
			LAi_group_SetAlarmReaction("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY, LAI_GROUP_FRIEND);


		break;
	
		case "Story_CursedCoinsGiveOutChest":
			LAi_SetPlayerType(Pchar);
			LAi_SetActorType(CharacterFromID("Cursed_Pirate_01"));
			LAi_SetActorType(CharacterFromID("Cursed_Pirate_02"));
			Characters[GetCharacterIndex("Cursed_Pirate_01")].location = "None";
			Characters[GetCharacterIndex("Cursed_Pirate_02")].location = "None";
			LAi_ActorRunToLocation(CharacterFromID("Cursed_Pirate_01"), "Reload", "Reload_2_4_back", "None", "", "", "", 120);
			LAi_ActorRunToLocation(CharacterFromID("Cursed_Pirate_02"), "Reload", "Reload_2_4_back", "None", "", "", "", 120);

			LAi_group_SetAlarmReaction("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY, LAI_GROUP_FRIEND);
			LAi_group_SetRelation("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);

/*			locations[FindLocation("Redmond_town_01")].reload.l1.disable = 0;
			locations[FindLocation("Redmond_town_01")].reload.l2.disable = 0;
			locations[FindLocation("Redmond_town_01")].reload.l3.disable = 0;
			locations[FindLocation("Redmond_town_01")].reload.l4.disable = 0;
			locations[FindLocation("Redmond_town_01")].reload.l5.disable = 0;
			locations[FindLocation("Redmond_town_01")].reload.l6.disable = 0;
			locations[FindLocation("Redmond_town_01")].reload.l7.disable = 0;
			locations[FindLocation("Redmond_town_01")].reload.l8.disable = 0;
			locations[FindLocation("Redmond_town_01")].reload.l9.disable = 0;
			locations[FindLocation("Redmond_town_01")].reload.l10.disable = 0;
			locations[FindLocation("Redmond_town_01")].reload.l11.disable = 0;
			locations[FindLocation("Redmond_town_01")].reload.l12.disable = 0;
			locations[FindLocation("Redmond_town_01")].reload.l13.disable = 0;*/
		break;
	
		case "Story_CursedCoinsFirstFightWithPirates":
			LAi_SetPlayerType(Pchar);
			LAi_QuestDelay("Story_CursedCoinsImmortalPirates", 7.0);
			LAi_group_MoveCharacter(CharacterFromID("Cursed_Pirate_01"), "CURSED_PIRATES");
			LAi_group_MoveCharacter(CharacterFromID("Cursed_Pirate_02"), "CURSED_PIRATES");
			LAi_group_FightGroups("CURSED_PIRATES", LAI_GROUP_PLAYER, true);
		break;
	
		case "Story_CursedCoinsImmortalPirates":
			LAi_SetActorType(Pchar);
			LAi_SetActorType(CharacterFromID("Cursed_Pirate_01"));
			LAi_SetActorType(CharacterFromID("Cursed_Pirate_02"));
	
			LAi_type_actor_Reset(CharacterFromID("Cursed_Pirate_01"));
			LAi_type_actor_Reset(CharacterFromID("Cursed_Pirate_02"));
			
			Characters[GetCharacterIndex("Cursed_Pirate_01")].Dialog.CurrentNode = "We_are_immortal";
			LAi_ActorWaitDialog(Pchar, CharacterFromID("Cursed_Pirate_01"));
			LAi_ActorDialog(CharacterFromID("Cursed_Pirate_01"), PChar, "Story_CursedCoinsCloseQuestMovie", 20.0, 1.0);
		break;

		case "Story_CursedCoinsCloseQuestMovie":
			EndQuestMovie();
		break;
	
		case "Story_CursedCoinsFightPiratesAgain":
			StartQuestMovie(true, true, false);
			LAi_SetPlayerType(Pchar);
			Characters[getCharacterIndex("Cursed_Pirate_01")].skill.fencing = 10;
			Characters[getCharacterIndex("Cursed_Pirate_02")].skill.fencing = 10;
			LAi_group_MoveCharacter(CharacterFromID("Cursed_Pirate_01"), "CURSED_PIRATES");
			LAi_group_MoveCharacter(CharacterFromID("Cursed_Pirate_02"), "CURSED_PIRATES");
			LAi_group_FightGroups("CURSED_PIRATES", LAI_GROUP_PLAYER, true);
		break;
	
		case "Seen_Black_Pearl":
			Log_SetStringToLog(GlobalStringConvert("QUEST_MESSAGE7"));
			
			Group_CreateGroup("Big Boss");
			Group_AddCharacter("Big Boss", "Barbossa");
			Group_SetGroupCommander("Big Boss", "Barbossa");
			Group_SetPursuitGroup("Big Boss", PLAYER_GROUP);
			Group_SetAddress("Big Boss", "FalaiseDeFleur", "", "");
			Group_SetTaskMove("Big Boss", 10000, 10000);
			Group_LockTask("Big Boss");
			
			SetCharacterRelationBoth(GetCharacterIndex("Barbossa"),GetMainCharacterIndex(),RELATION_FRIEND);
			UpdateRelations();
			
			pchar.quest.seen_black_pearl_away1.win_condition.l1 = "MapEnter";
			pchar.quest.seen_black_pearl_away1.win_condition = "seen_black_pearl_away";
			
			pchar.quest.seen_black_pearl_away2.win_condition.l1 = "location";
			pchar.quest.seen_black_pearl_away2.win_condition.l1.location = "Falaise_De_Fleur_port_01";
			pchar.quest.seen_black_pearl_away2.win_condition = "seen_black_pearl_away";
			
			pchar.quest.seen_black_pearl_away3.win_condition.l1 = "location";
			pchar.quest.seen_black_pearl_away3.win_condition.l1.location = "Falaise_De_Fleur_shore_01";
			pchar.quest.seen_black_pearl_away3.win_condition = "seen_black_pearl_away";
		break;
		
		case "seen_black_pearl_away":
			pchar.quest.seen_black_pearl_away2.over = "yes";
			pchar.quest.seen_black_pearl_away3.over = "yes";
			Group_SetAddress("Big Boss", "none", "", "");
			pchar.quest.seen_black_pearl_away1.over = "yes";
			pchar.quest.seen_black_pearl_away2.over = "yes";
			pchar.quest.seen_black_pearl_away3.over = "yes";
		break;
	
		case "about_ruby":
			pchar.quest.Carpenter.over = "yes";
			pchar.quest.Carpenter1.over = "yes";

			SetCharacterToNearLocatorFromMe("Gordon Carpenter", 10);
			LAi_SetActorType(CharacterFromID("Gordon Carpenter"));
			LAi_ActorDialog(CharacterFromID("Gordon Carpenter"), Pchar, "", 1.0, 1.0);
		break;
	
		case "talk_about_ruby":
			LAi_Fade("talk_about_ruby1", "talk_about_ruby2");
		break;
	
		case "talk_about_ruby1":
			DoQuestReloadToLocation("Falaise_De_Fleur_tavern", "sit", "sit4", "");
			ChangeCharacterAddressGroup(CharacterFromID("Gordon Carpenter"), "Falaise_De_Fleur_tavern", "sit", "sit8");
			LAi_SetActorType(Pchar);
			LAi_ActorSetSitMode(Pchar);
			LAi_SetActorType(CharacterFromID("Gordon Carpenter"));
			LAi_ActorSetSitMode(CharacterFromID("Gordon Carpenter"));
		break;
	
		case "talk_about_ruby2":
			Lai_ActorWaitDialog(Pchar, CharacterFromID("Gordon Carpenter"));
			LAi_ActorDialog(CharacterFromID("Gordon Carpenter"), Pchar, "", 1.0, 1.0);
		break;

		case "Story_CursedCoinsFinished":
			LAI_SetPlayerType(Pchar);
			DoReloadCharacterToLocation("Falaise_De_Fleur_tavern", "goto", "goto3");
			Characters[GetCharacterIndex("Gordon Carpenter")].location = "None";

			CloseQuestHeader("chest");
		break;

		case "Story_CursedCoinsShit":
			Lai_SetActorType(CharacterFromID("Henry Peat"));
			LAi_ActorSetSitMode(CharacterFromID("Henry Peat"));
		break;

		case "Story_CursedCoinsPeatSilent":
			AddQuestRecord("Chest", 6);
			LAi_CharacterDisableDialog(CharacterFromID("Henry Peat"));
		break;










//Tutorial

		case "Tut_start":
			LAi_SetPlayerType(pchar);

			locDisableUpdateTime = true;

			Pchar.quest.tutorial.Spyglass = 1;

			//StartQuestMovie(true, false, false);
			ChangeCharacterAddressGroup(CharacterFromID("Malcolm Hatcher"), "Tutorial_Deck", "goto", "goto2");
			LAi_SetWarriorTypeNoGroup(CharacterFromID("Malcolm Hatcher"));

			LAi_group_MoveCharacter(CharacterFromID("Malcolm Hatcher"), "tutorial");

			LAi_group_SetAlarmReaction("tutorial", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY, LAI_GROUP_ENEMY);

			LAi_SetImmortal(CharacterFromID("Malcolm Hatcher"), false);
			Characters[GetCharacterIndex("Malcolm Hatcher")].Dialog.CurrentNode = "start";

			locations[FindLocation(Pchar.location)].box1.items.pistol1 = 1;
			locations[FindLocation(Pchar.location)].box1.items.spyglass1 = 1;			
			locations[FindLocation(Pchar.location)].box1.items.potion1 = 2;			
			locations[FindLocation(Pchar.location)].box1.money = 1000;			
			locations[FindLocation(Pchar.location)].box1 = Items_MakeTime(0, 0, 1, 2003);

			Locations[FindLocation("Oxbay_Port")].locators_radius.goto.goto18 = 3.0;
			SetQuestHeader("Tutorial_AppearedOnOxbay");
			AddQuestRecord("Tutorial_AppearedOnOxbay", "1");

			Pchar.quest.Tut_KillTutor.win_condition.l1 = "NPC_Death";
			Pchar.quest.Tut_KillTutor.win_condition.l1.character = "Malcolm Hatcher";
			PChar.quest.Tut_KillTutor.win_condition = "Tut_KillTutor";

			LAi_QuestDelay("Tut_start1", 3);
		break;

		case "Tut_KillTutor":
			Log_SetStringToLog(GlobalStringConvert("QUEST_MESSAGE8"));
			Log_SetStringToLog(GlobalStringConvert("QUEST_MESSAGE9"));
			ChangeCharacterReputation(Pchar, -10);

			Pchar.quest.Tut_RewardForKillingTutor.win_condition.l1 = "rank";
			Pchar.quest.Tut_RewardForKillingTutor.win_condition.l1.character = Pchar.id;
			Pchar.quest.Tut_RewardForKillingTutor.win_condition.l1.value = 6;
			Pchar.quest.Tut_RewardForKillingTutor.win_condition.l1.operation = ">=";
			pchar.quest.Tut_RewardForKillingTutor.win_condition.l2 = "location";
			pchar.quest.Tut_RewardForKillingTutor.win_condition.l2.location = "QC_Pirate_house";
			PChar.quest.Tut_RewardForKillingTutor.win_condition = "Tut_RewardForKillingTutor"

			if(Pchar.location == "Tutorial_Deck")
			{
				Lai_QuestDelay("Tut_SkipTutorialOnShip", 2.0);
			}
			if(Pchar.location == "Oxbay_port")
			{
				Lai_QuestDelay("Tut_SkipTutorialInPort", 2.0);
			}
			if(Pchar.location == "Oxbay_port" || Pchar.location == "Oxbay_tavern" || Pchar.location == "Oxbay_store" || Pchar.location == "Oxbay_shipyard")
			{
				Lai_QuestDelay("Tut_SkipTutorialInTown", 2.0);
			}
		break;

		case "Tut_RewardForKillingTutor":
			Log_SetStringToLog(GlobalStringConvert("QUEST_MESSAGE10")); 
			Log_SetStringToLog(GlobalStringConvert("QUEST_MESSAGE11"));

			TakeNItems(Pchar,"blade23", 1);
		break;
		
		case "Tut_start1":
			Lai_SetCheckMinHP(CharacterFromID("Malcolm Hatcher"), 399, true, "Tut_HatcherAttacksAndKills");
			Lai_SetActorTypeNoGroup(CharacterFromID("Malcolm Hatcher"));
			LAi_ActorTurnToCharacter(CharacterFromID("Malcolm Hatcher"), pchar);
			LAi_ActorDialog(CharacterFromID("Malcolm Hatcher"), PChar, "", 5.0, 1.0);
		break;
	
		case "Tut_TakeStuff":
			LAi_SetWarriorTypeNoGroup(CharacterFromID("Malcolm Hatcher"));
			LAi_warrior_SetStay(CharacterFromID("Malcolm Hatcher"), true);
			LAi_warrior_DialogEnable(CharacterFromID("Malcolm Hatcher"), true);
		break;

		case "Tut_HatcherAttacksAndKills":
			LAi_SetActorType(CharacterFromID("Malcolm Hatcher"));
			LAi_type_actor_Reset(CharacterFromID("Malcolm Hatcher"));
			LAi_ActorAttack(CharacterFromID("Malcolm Hatcher"), Pchar, "");
		break;

		case "Tut_WalkToSwordplayPlace":
			LAi_SetFightMode(PChar, false);
			LAi_LockFightMode(Pchar, true);

			LAi_SetActorTypeNoGroup(CharacterFromID("Malcolm Hatcher"));
			LAi_ActorGoToLocator(CharacterFromID("Malcolm Hatcher"), "goto", "goto3", "Tut_StartFirstSwordplay", 10);

			Lai_QuestDelay("Tut_PLayerFollowHatcher", 1.0);
		break;

		case "Tut_PlayerFollowHatcher":
			LAi_SetActorTypeNoGroup(Pchar);
			LAi_ActorGoToLocator(Pchar, "goto", "goto2", "Tut_StartFirstSwordplay", 10);
		break;

		case "Tut_StartFirstSwordplay":
			Characters[GetCharacterIndex("Malcolm Hatcher")].Dialog.CurrentNode = "NowHitMe";
			Lai_SetPlayerType(PChar);
			LAi_ActorDialog(CharacterFromID("Malcolm Hatcher"), PChar, "", 5.0, 1.0);
		break;

		case "Tut_FirstMeleeFight":
			LAi_LockFightMode(Pchar, false);
			LAi_ActorWaitDialog(CharacterFromID("Malcolm Hatcher"), Pchar);
			LAi_SetHP(CharacterFromID("Malcolm Hatcher"), 400.0, 400.0);
			Lai_SetCheckMinHP(CharacterFromID("Malcolm Hatcher"), 300.0, true, "Tut_NowFightWithMight");
		break;

		case "Tut_NowFightWithMight":
			LAi_type_actor_Reset(CharacterFromID("Malcolm Hatcher"));
			LAi_SetActorType(PChar);
			LAi_SetFightMode(PChar, false);
			LAi_type_actor_Reset(Pchar);
			LAi_ActorWaitDialog(PChar, CharacterFromID("Malcolm Hatcher"));
			Characters[GetCharacterIndex("Malcolm Hatcher")].Dialog.CurrentNode = "HurtEnough";			
			LAi_ActorDialog(CharacterFromID("Malcolm Hatcher"), PChar, "", 1.0, 1.0);		
		//	Lai_QuestDelay("Tut_ReturnPlayer", 2.0);
		break;

		case "Tut_ReturnPlayer":
			LAi_SetPlayerType(Pchar);
		break;

		case "Tut_StartSeriousFight":
			Lai_SetImmortal(CharacterFromID("Malcolm Hatcher"), false);
			Characters[GetCharacterIndex("Malcolm Hatcher")].skill.Fencing = 1;		
			LAi_SetHP(CharacterFromID("Malcolm Hatcher"), 400.0, 400.0);
			LAi_SetHP(PChar, 400.0, 400.0);
			LAi_SetFightMode(PChar, true);
			LAi_SetActorTypeNoGroup(CharacterFromID("Malcolm Hatcher"));
			LAi_ActorAttack(CharacterFromID("Malcolm Hatcher"), Pchar, "");

			Lai_SetCheckMinHP(Pchar, 200.0, false, "SeriousFightFinished");
			Lai_SetCheckMinHP(CharacterFromID("Malcolm Hatcher"), 200.0, true, "SeriousFightFinished");

		break;

		case "SeriousFightFinished":
			LAi_RemoveCheckMinHP(CharacterFromID("Malcolm Hatcher"));
			LAi_RemoveCheckMinHP(Pchar);

			LAi_type_actor_Reset(CharacterFromID("Malcolm Hatcher"));

			LAi_SetActorTypeNoGroup(PChar);
			Lai_ActorWaitDialog(Pchar, CharacterFromID("Malcolm Hatcher"));
			LAi_SetFightMode(PChar, false);

			Lai_QuestDelay("Tut_ReturnPlayer", 1.5);
			
			Characters[GetCharacterIndex("Malcolm Hatcher")].Dialog.CurrentNode = "SeriousStopped";
			LAi_ActorDialog(CharacterFromID("Malcolm Hatcher"), PChar, "", 1.0, 1.0);

			LAi_group_SetRelation(LAI_GROUP_PLAYER, "tutorial", LAI_GROUP_FRIEND);
		break;

		case "Tut_StartSeriousFightAgain":
			Lai_SetImmortal(CharacterFromID("Malcolm Hatcher"), false);
			Characters[GetCharacterIndex("Malcolm Hatcher")].skill.Fencing = 1;		
			LAi_SetHP(CharacterFromID("Malcolm Hatcher"), 400.0, 400.0);
			LAi_SetHP(PChar, 400.0, 400.0);
			LAi_SetFightMode(PChar, true);
			LAi_SetActorTypeNoGroup(CharacterFromID("Malcolm Hatcher"));
			LAi_ActorAttack(CharacterFromID("Malcolm Hatcher"), Pchar, "");

			Lai_SetCheckMinHP(Pchar, 200.0, false, "SeriousFightFinishedAgain");
			Lai_SetCheckMinHP(CharacterFromID("Malcolm Hatcher"), 200.0, true, "SeriousFightFinishedAgain");

		break;

		case "SeriousFightFinishedAgain":
			LAi_RemoveCheckMinHP(CharacterFromID("Malcolm Hatcher"));
			LAi_RemoveCheckMinHP(Pchar);

			LAi_type_actor_Reset(CharacterFromID("Malcolm Hatcher"));

			LAi_SetActorTypeNoGroup(PChar);
			Lai_ActorWaitDialog(Pchar, CharacterFromID("Malcolm Hatcher"));
			LAi_SetFightMode(PChar, false);

			Lai_QuestDelay("Tut_ReturnPlayer", 1.5);

			LAi_group_SetRelation(LAI_GROUP_PLAYER, "tutorial", LAI_GROUP_FRIEND);
			
			Characters[GetCharacterIndex("Malcolm Hatcher")].Dialog.CurrentNode = "SeriousStoppedAgain";
			LAi_ActorDialog(CharacterFromID("Malcolm Hatcher"), PChar, "", 1.0, 1.0);
		break;

		case "Tut_PlayerDistributeSkills":
			LAi_SetImmortal(CharacterFromID("Malcolm Hatcher"), true);
			LAi_SetWarriorTypeNoGroup(CharacterFromID("Malcolm Hatcher"));
			LAi_warrior_SetStay(CharacterFromID("Malcolm Hatcher"), true);
			LAi_warrior_DialogEnable(CharacterFromID("Malcolm Hatcher"), true);			
		break;

		case "Tut_ReloadToOxbayPort":
			LAi_SetHP(PChar, LAI_DEFAULT_HP, LAI_DEFAULT_HP);
			LAi_SetHP(CharacterFromID("Malcolm Hatcher"), 120.0, 120.0);
			LAi_group_SetAlarm("tutorial", LAI_GROUP_PLAYER, 0.0);
			LAi_group_SetRelation("tutorial", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);

			SetQuestHeader("Tutorial_SpyGlass");
			AddQuestRecord("Tutorial_SpyGlass", "1");

			Pchar.quest.Tut_BuySpyGlass.win_condition.l1 = "item";
			Pchar.quest.Tut_BuySpyGlass.win_condition.l1.character = Pchar.id;
			Pchar.quest.Tut_BuySpyGlass.win_condition.l1.item = "SpyGlass2";
			Pchar.quest.Tut_BuySpyGlass.win_condition = "Tut_BuySpyGlass";
			Pchar.quest.Tut_BuySpyGlass.fail_condition = "Tut_BuySpyGlass";

			SetQuestHeader("Tutorial_Store");
			AddQuestRecord("Tutorial_Store", "1");

			Pchar.quest.Tut_SellGoods.win_condition.l1 = "goods";
			Pchar.quest.Tut_SellGoods.win_condition.l1.character = Pchar.id;
			Pchar.quest.Tut_SellGoods.win_condition.l1.goods = GOOD_CHOCOLATE;
			Pchar.quest.Tut_SellGoods.win_condition.l1.quantity = "0";
			Pchar.quest.Tut_SellGoods.win_condition.l1.operation = "=";
			Pchar.quest.Tut_SellGoods.win_condition.l2 = "goods";
			Pchar.quest.Tut_SellGoods.win_condition.l2.character = Pchar.id;
			Pchar.quest.Tut_SellGoods.win_condition.l2.goods = GOOD_LEATHER;
			Pchar.quest.Tut_SellGoods.win_condition.l2.quantity = "0";
			Pchar.quest.Tut_SellGoods.win_condition.l2.operation = "=";
			Pchar.quest.Tut_SellGoods.win_condition = "Tut_SellGoods";
			Pchar.quest.Tut_SellGoods.fail_condition = "Tut_SellGoods";

			SetQuestHeader("Tutorial_Shipyard");
			AddQuestRecord("Tutorial_Shipyard", "1");

			Pchar.quest.Tut_RepairShip.win_condition.l1 = "Ship_HP";
			Pchar.quest.Tut_RepairShip.win_condition.l1.character = Pchar.id;
			Pchar.quest.Tut_RepairShip.win_condition.l1.quantity = "500";
			Pchar.quest.Tut_RepairShip.win_condition.l1.operation = "=";
			Pchar.quest.Tut_RepairShip.win_condition = "Tut_RepairShip";
			Pchar.quest.Tut_RepairShip.fail_condition = "Tut_RepairShip";

			SetQuestHeader("Tutorial_Tavern");
			AddQuestRecord("Tutorial_Tavern", "1");

			Pchar.quest.Tut_HireCrew.win_condition.l1 = "Crew_Space";
			Pchar.quest.Tut_HireCrew.win_condition.l1.character = Pchar.id;
			Pchar.quest.Tut_HireCrew.win_condition.l1.quantity = "0";
			Pchar.quest.Tut_HireCrew.win_condition.l1.operation = "=";
			Pchar.quest.Tut_HireCrew.win_condition = "Tut_HireCrew";
			Pchar.quest.Tut_HireCrew.fail_condition = "Tut_HireCrew";

			Locations[FindLocation("Oxbay_port")].reload.l1.disable = 1;
			Locations[FindLocation("Oxbay_port")].reload.l3.disable = 1;
			Locations[FindLocation("Oxbay_port")].reload.l2.disable = 1;
			Locations[FindLocation("Oxbay_port")].reload.l4.disable = 1;

			ChangeCharacterAddressGroup(CharacterFromID("Malcolm Hatcher"), "Oxbay_port", "goto", "goto3");
			DoQuestReloadToLocation("Oxbay_port", "reload", "Reload2", "Tut_StartTalkInPort");
		break;

		case "Tut_BuySpyGlass":
			DeleteAttribute(Pchar, "quest.tutorial.Spyglass");
			AddQuestRecord("Tutorial_SpyGlass", "2");
			CloseQuestHeader("Tutorial_SpyGlass");
		break;

		case "Tut_SellGoods":
			AddQuestRecord("Tutorial_Store", "2");
			CloseQuestHeader("Tutorial_Store");
		break;

		case "Tut_RepairShip":
			AddQuestRecord("Tutorial_Shipyard", "2");
			CloseQuestHeader("Tutorial_Shipyard");
		break;

		case "Tut_HireCrew":
			AddQuestRecord("Tutorial_Tavern", "2");
			CloseQuestHeader("Tutorial_Tavern");
		break;

		case "Tut_StartTalkInPort":
			StartQuestMovie(true, false, false);

			Locations[FindLocation("Oxbay_Port")].locators_radius.goto.goto18 = 0.5;
			LAi_SetActorTypeNoGroup(CharacterFromID("Malcolm Hatcher"));
			Lai_SetCheckMinHP(CharacterFromID("Malcolm Hatcher"), 119.0, false, "Tut_HatcherAttacksAndKills");
			Characters[GetCharacterIndex("Malcolm Hatcher")].Dialog.CurrentNode = "NowLetsBuyASpyglass";
			LAi_SetFightMode(PChar, false);
			LAi_LockFightMode(Pchar, true);			
			LAi_ActorDialog(CharacterFromID("Malcolm Hatcher"), PChar, "", 5.0, 1.0);
		break;

		case "Tut_GuideToSpyglass":
			LAi_ActorgoToLocator(CharacterFromID("Malcolm Hatcher"), "goto", "goto18", "", 40.0);

			pchar.quest.Tut_FollowTheSpyglass.win_condition.l1 = "locator";
			pchar.quest.Tut_FollowTheSpyglass.win_condition.l1.character = PChar.id;
			pchar.quest.Tut_FollowTheSpyglass.win_condition.l1.location = "Oxbay_port";
			pchar.quest.Tut_FollowTheSpyglass.win_condition.l1.locator_group = "goto";
			pchar.quest.Tut_FollowTheSpyglass.win_condition.l1.locator = "goto18";
			pchar.quest.Tut_FollowTheSpyglass.win_condition.l2 = "locator";
			pchar.quest.Tut_FollowTheSpyglass.win_condition.l2.character = "Malcolm Hatcher";
			pchar.quest.Tut_FollowTheSpyglass.win_condition.l2.location = "Oxbay_port";
			pchar.quest.Tut_FollowTheSpyglass.win_condition.l2.locator_group = "goto";
			pchar.quest.Tut_FollowTheSpyglass.win_condition.l2.locator = "goto18";
			pchar.quest.Tut_FollowTheSpyglass.win_condition = "Tut_FollowTheSpyglass";

		break;

		case "Tut_FollowTheSpyglass":
			LAi_type_actor_Reset(CharacterFromID("Malcolm Hatcher"));
			Lai_SetActorTypeNoGroup(Pchar);
			LAi_ActorWaitDialog(Pchar, CharacterFromID("Malcolm Hatcher"));
			Characters[GetCharacterIndex("Malcolm Hatcher")].Dialog.CurrentNode = "HereAretheTraders";
			LAi_ActorDialog(CharacterFromID("Malcolm Hatcher"), PChar, "", 3.0, 1.0);
		break;

		case "Tut_SoBuyTheFuckingGlass":
			Lai_SetPlayerType(Pchar);
			LAi_SetWarriorTypeNoGroup(CharacterFromID("Malcolm Hatcher"));
			LAi_warrior_SetStay(CharacterFromID("Malcolm Hatcher"), true);
			LAi_warrior_DialogEnable(CharacterFromID("Malcolm Hatcher"), true);
		break;

		case "Tut_ReloadToOxbay":
			LAi_SetActorTypeNoGroup(CharacterFromID("Malcolm Hatcher"));
			LAi_ActorgoToLocation(CharacterFromID("Malcolm Hatcher"), "Reload", "Reload1", "Oxbay_town", "goto", "Goto38", "Tut_TownOpened", 20);
			EndQuestMovie();

			pchar.quest.Tut_ReloadToOxbayTown.win_condition.l1 = "location";
			pchar.quest.Tut_ReloadToOxbayTown.win_condition.l1.location = "Oxbay_town";
			pchar.quest.Tut_ReloadToOxbayTown.win_condition = "Tut_ReloadPlayerToOxbayTown";
		break;

		case "Tut_TownOpened":
			chrEnableReloadLocator("Oxbay_port", "reload1", true);
		break;

		case "Tut_ReloadPlayerToOxbayTown":
			Characters[GetCharacterIndex("Malcolm Hatcher")].Dialog.CurrentNode = "NowGoTotheStore";
			LAi_ActorDialog(CharacterFromID("Malcolm Hatcher"), PChar, "", 3.0, 1.0);
			Locations[FindLocation("Oxbay_port")].reload.l1.disable = 0;
			Locations[FindLocation("Oxbay_port")].reload.l3.disable = 0;
			Locations[FindLocation("Oxbay_port")].reload.l2.disable = 0;
			Locations[FindLocation("Oxbay_port")].reload.l4.disable = 0;
		break;
	
		case "Tut_MalcolmShowsTheStore":
			LAi_ActorgoToLocation(CharacterFromID("Malcolm Hatcher"), "Reload", "Reload15", "Oxbay_Store", "goto", "locator6", "tut_StoreOpened", 30.0);

			Locations[FindLocation("Oxbay_town")].reload.l3.disable = 1;

			Locations[FindLocation("Oxbay_town")].reload.l1.disable = 1;
			Locations[FindLocation("Oxbay_town")].reload.l9.disable = 1;
			Locations[FindLocation("Oxbay_town")].reload.l10.disable = 1;
			Locations[FindLocation("Oxbay_town")].reload.l20.disable = 1;
			Locations[FindLocation("Oxbay_town")].reload.l21.disable = 1;
			Locations[FindLocation("Oxbay_town")].reload.l22.disable = 1;
			Locations[FindLocation("Oxbay_town")].reload.l2.disable = 1;
			Locations[FindLocation("Oxbay_town")].reload.l4.disable = 1;
			Locations[FindLocation("Oxbay_town")].reload.l18.disable = 1;
			Locations[FindLocation("Oxbay_town")].reload.l7.disable = 1;
			Locations[FindLocation("Oxbay_town")].reload.l55.disable = 1;

			pchar.quest.Tut_PlayerEntersTheStore.win_condition.l1 = "location";
			pchar.quest.Tut_PlayerEntersTheStore.win_condition.l1.location = "Oxbay_store";
			pchar.quest.Tut_PlayerEntersTheStore.win_condition = "Tut_PlayerEntersTheStore";
		break;

		case "tut_StoreOpened":
			chrEnableReloadLocator("Oxbay_town", "reload15", true);
			//Locations[FindLocation("Oxbay_town")].reload.l3.disable = 0;

		break;

		case "Tut_PlayerEntersTheStore":
			chrEnableReloadLocator("Oxbay_store", "locator2", false);
			Characters[GetCharacterIndex("Malcolm Hatcher")].Dialog.CurrentNode = "MoreDetailsOnTrade";
			LAi_ActorDialog(CharacterFromID("Malcolm Hatcher"), PChar, "", 3.0, 1.0);
		break;

		case "Tut_StartTrading":
			LAi_ActorGoToLocation(CharacterFromID("Malcolm Hatcher"), "Reload", "locator2", "Oxbay_town", "goto", "goto26", "Tut_FreeFromStore", 6);
			
			pchar.quest.Tut_ToOxbayAfterTrading.win_condition.l1 = "location";
			pchar.quest.Tut_ToOxbayAfterTrading.win_condition.l1.location = "Oxbay_town";
			pchar.quest.Tut_ToOxbayAfterTrading.win_condition = "Tut_ToOxbayAfterTrading";
		break;

		case "Tut_FreeFromStore":
			chrEnableReloadLocator("Oxbay_store", "locator2", true);
		break;
			
		case "Tut_ToOxbayAfterTrading":
			LAi_SetFightMode(PChar, false);
			Characters[GetCharacterIndex("Malcolm Hatcher")].Dialog.CurrentNode = "GoodsSoldInStore";
			LAi_ActorDialog(CharacterFromID("Malcolm Hatcher"), PChar, "", 3.0, 1.0);

			Locations[FindLocation("Oxbay_town")].reload.l4.disable = 1;
			
			Locations[FindLocation("Oxbay_town")].reload.l3.disable = 1;
			Locations[FindLocation("Oxbay_town")].reload.l1.disable = 1;
			Locations[FindLocation("Oxbay_town")].reload.l9.disable = 1;
			Locations[FindLocation("Oxbay_town")].reload.l10.disable = 1;
			Locations[FindLocation("Oxbay_town")].reload.l20.disable = 1;
			Locations[FindLocation("Oxbay_town")].reload.l21.disable = 1;
			Locations[FindLocation("Oxbay_town")].reload.l22.disable = 1;
			Locations[FindLocation("Oxbay_town")].reload.l2.disable = 1;
			Locations[FindLocation("Oxbay_town")].reload.l18.disable = 1;
			Locations[FindLocation("Oxbay_town")].reload.l7.disable = 1;
			Locations[FindLocation("Oxbay_town")].reload.l55.disable = 1;

		break;

		case "Tut_MalcolmLeadsToTavern":
			LAi_ActorgoToLocation(CharacterFromID("Malcolm Hatcher"), "Reload", "Reload13", "Oxbay_tavern", "goto", "goto20", "Tut_TavernOpened", 20);
			
			pchar.quest.Tut_ToTavernForCrew.win_condition.l1 = "location";
			pchar.quest.Tut_ToTavernForCrew.win_condition.l1.location = "Oxbay_tavern";
			pchar.quest.Tut_ToTavernForCrew.win_condition = "Tut_ToTavernForCrew";
		break;

		case "Tut_TavernOpened":
			//Locations[FindLocation("Oxbay_town")].reload.l4.disable = 0;
			chrEnableReloadLocator("Oxbay_town", "reload13", true);
		break;

		case "Tut_ToTavernForCrew":
			chrEnableReloadLocator("Oxbay_tavern", "reload1", false);
			Characters[GetCharacterIndex("Malcolm Hatcher")].Dialog.CurrentNode = "CrewHiringInTavern";
			LAi_ActorDialog(CharacterFromID("Malcolm Hatcher"), PChar, "", 3.0, 1.0);
		break;

		case "Tut_MalcolmLeavesTavern":
			LAi_ActorGoToLocation(CharacterFromID("Malcolm Hatcher"), "Reload", "Reload1", "Oxbay_town", "goto", "goto41", "Tut_FreeFromTavern", 6);
			
			pchar.quest.Tut_ToOxbayAfterHiring.win_condition.l1 = "location";
			pchar.quest.Tut_ToOxbayAfterHiring.win_condition.l1.location = "Oxbay_town";
			pchar.quest.Tut_ToOxbayAfterHiring.win_condition = "Tut_ToOxbayAfterHiring";
		break;

		case "Tut_FreeFromTavern":
			chrEnableReloadLocator("Oxbay_tavern", "reload1", true);
		break;

		case "Tut_ToOxbayAfterHiring":
			LAi_SetFightMode(PChar, false);
			Characters[GetCharacterIndex("Malcolm Hatcher")].Dialog.CurrentNode = "CrewHiredintavern";
			LAi_ActorDialog(CharacterFromID("Malcolm Hatcher"), PChar, "", 3.0, 1.0);

			Locations[FindLocation("Oxbay_town")].reload.l7.disable = 1;

			Locations[FindLocation("Oxbay_town")].reload.l4.disable = 1;
			Locations[FindLocation("Oxbay_town")].reload.l3.disable = 1;
			Locations[FindLocation("Oxbay_town")].reload.l1.disable = 1;
			Locations[FindLocation("Oxbay_town")].reload.l9.disable = 1;
			Locations[FindLocation("Oxbay_town")].reload.l10.disable = 1;
			Locations[FindLocation("Oxbay_town")].reload.l20.disable = 1;
			Locations[FindLocation("Oxbay_town")].reload.l21.disable = 1;
			Locations[FindLocation("Oxbay_town")].reload.l22.disable = 1;
			Locations[FindLocation("Oxbay_town")].reload.l2.disable = 1;
			Locations[FindLocation("Oxbay_town")].reload.l18.disable = 1;
			Locations[FindLocation("Oxbay_town")].reload.l55.disable = 1;

		break;


		case "Tut_BooGoForShipyard":
			LAi_ActorgoToLocation(CharacterFromID("Malcolm Hatcher"), "Reload", "Reload3", "Oxbay_SHIPYARD", "goto", "goto1", "Tut_ShipyardOpened", 40);
			
			pchar.quest.Tut_ToShipyardForRepairs.win_condition.l1 = "location";
			pchar.quest.Tut_ToShipyardForRepairs.win_condition.l1.location = "Oxbay_shipyard";
			pchar.quest.Tut_ToShipyardForRepairs.win_condition = "Tut_ToShipyardForRepairs";
		break;

		case "Tut_ShipyardOpened":
			//Locations[FindLocation("Oxbay_town")].reload.l7.disable = 0;
			chrEnableReloadLocator("Oxbay_town", "reload3", true);
		break;

		case "Tut_ToShipyardForRepairs":
			chrEnableReloadLocator("Oxbay_shipyard", "reload1", false);
			Characters[GetCharacterIndex("Malcolm Hatcher")].Dialog.CurrentNode = "ShipRepairing";
			LAi_ActorDialog(CharacterFromID("Malcolm Hatcher"), PChar, "", 3.0, 1.0);
		break;

		case "Tut_MalcolmLeavesShipyard":
			LAi_ActorGoToLocation(CharacterFromID("Malcolm Hatcher"), "Reload", "Reload1", "Oxbay_town", "goto", "goto23", "Tut_FreeFromShipyard", 6);
			
			pchar.quest.Tut_ToOxbayAfterFixing.win_condition.l1 = "location";
			pchar.quest.Tut_ToOxbayAfterFixing.win_condition.l1.location = "Oxbay_town";
			pchar.quest.Tut_ToOxbayAfterFixing.win_condition = "Tut_ToOxbayAfterFixing";
		break;

		case "Tut_FreeFromShipyard":
			chrEnableReloadLocator("Oxbay_shipyard", "reload1", true);
		break;

		case "Tut_ToOxbayAfterFixing":
			Pchar.quest.Tut_KillTutor.over = "yes";
			locDisableUpdateTime = false;
			Characters[GetCharacterIndex("Malcolm Hatcher")].Dialog.CurrentNode = "FinalStage";
			LAi_ActorDialog(CharacterFromID("Malcolm Hatcher"), PChar, "", 3.0, 1.0);
		break;

		case "Tut_SkipTutorialOnShip":
			locDisableUpdateTime = false;
			LAi_LockFightMode(Pchar, false);
			EndQuestMovie();
			LAi_RemoveCheckMinHP(CharacterFromID("Malcolm Hatcher"));
			LAi_RemoveCheckMinHP(Pchar);

			LAi_SetHP(PChar, LAI_DEFAULT_HP, LAI_DEFAULT_HP);
			LAi_SetHP(CharacterFromID("Malcolm Hatcher"), 120.0, 120.0);
			LAi_group_SetAlarm("tutorial", LAI_GROUP_PLAYER, 0.0);
			LAi_group_SetRelation("tutorial", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);

	//		Pchar.ship.hp = 500;
	//		Pchar.ship.crew.quantity = 57;

			if(CheckCharacterItem(Pchar, "blade1") == 0) GiveItem2Character(Pchar, "blade1");
			if(makeint(Pchar.money) == 1000) AddMoneyToCharacter(Pchar, 1000);


			if(CheckCharacterItem(Pchar, "Spyglass1") == 0) GiveItem2Character(Pchar, "Spyglass1");
				
			if(CheckCharacterItem(Pchar, "pistol1") == 0) GiveItem2Character(Pchar, "pistol1");

			if(CheckCharacterItem(Pchar, "potion1") == 0) TakenItems(Pchar, "potion1", 2);

			EquipCharacterbyItem(Pchar, "blade1");
			EquipCharacterbyItem(Pchar, "Spyglass1");
			EquipCharacterbyItem(Pchar, "Pistol1");

			Locations[FindLocation("Oxbay_Port")].locators_radius.goto.goto18 = 0.5;

			DoReloadCharacterToLocation("Oxbay_port", "reload", "Reload2");

			CloseQuestHeader("Tutorial_AppearedOnOxbay");

			SetQuestHeader("Tutorial_SpyGlass");
			AddQuestRecord("Tutorial_SpyGlass", "1");

			Pchar.quest.Tut_BuySpyGlass.win_condition.l1 = "item";
			Pchar.quest.Tut_BuySpyGlass.win_condition.l1.character = Pchar.id;
			Pchar.quest.Tut_BuySpyGlass.win_condition.l1.item = "SpyGlass2";
			Pchar.quest.Tut_BuySpyGlass.win_condition = "Tut_BuySpyGlass";
			Pchar.quest.Tut_BuySpyGlass.fail_condition = "Tut_BuySpyGlass";

			SetQuestHeader("Tutorial_Store");
			AddQuestRecord("Tutorial_Store", "1");

			Pchar.quest.Tut_SellGoods.win_condition.l1 = "goods";
			Pchar.quest.Tut_SellGoods.win_condition.l1.character = Pchar.id;
			Pchar.quest.Tut_SellGoods.win_condition.l1.goods = GOOD_CHOCOLATE;
			Pchar.quest.Tut_SellGoods.win_condition.l1.quantity = "0";
			Pchar.quest.Tut_SellGoods.win_condition.l1.operation = "=";
			Pchar.quest.Tut_SellGoods.win_condition.l2 = "goods";
			Pchar.quest.Tut_SellGoods.win_condition.l2.character = Pchar.id;
			Pchar.quest.Tut_SellGoods.win_condition.l2.goods = GOOD_LEATHER;
			Pchar.quest.Tut_SellGoods.win_condition.l2.quantity = "0";
			Pchar.quest.Tut_SellGoods.win_condition.l2.operation = "=";
			Pchar.quest.Tut_SellGoods.win_condition = "Tut_SellGoods";
			Pchar.quest.Tut_SellGoods.fail_condition = "Tut_SellGoods";

			SetQuestHeader("Tutorial_Shipyard");
			AddQuestRecord("Tutorial_Shipyard", "1");

			Pchar.quest.Tut_RepairShip.win_condition.l1 = "Ship_HP";
			Pchar.quest.Tut_RepairShip.win_condition.l1.character = Pchar.id;
			Pchar.quest.Tut_RepairShip.win_condition.l1.quantity = "500";
			Pchar.quest.Tut_RepairShip.win_condition.l1.operation = "=";
			Pchar.quest.Tut_RepairShip.win_condition = "Tut_RepairShip";
			Pchar.quest.Tut_RepairShip.fail_condition = "Tut_RepairShip";

			SetQuestHeader("Tutorial_Tavern");
			AddQuestRecord("Tutorial_Tavern", "1");

			Pchar.quest.Tut_HireCrew.win_condition.l1 = "Crew_Space";
			Pchar.quest.Tut_HireCrew.win_condition.l1.character = Pchar.id;
			Pchar.quest.Tut_HireCrew.win_condition.l1.quantity = "0";
			Pchar.quest.Tut_HireCrew.win_condition.l1.operation = "=";
			Pchar.quest.Tut_HireCrew.win_condition = "Tut_HireCrew";
			Pchar.quest.Tut_HireCrew.fail_condition = "Tut_HireCrew";

			Pchar.quest.Tut_KillTutor.over = "yes";
		break;

		case "Tut_SkipTutorialInPort":
			LAi_LockFightMode(Pchar, false);
			EndQuestMovie();
			locDisableUpdateTime = false;
			LAi_RemoveCheckMinHP(CharacterFromID("Malcolm Hatcher"));
			LAi_RemoveCheckMinHP(Pchar);

			chrEnableReloadLocator("Oxbay_port", "reload1", true);
			chrEnableReloadLocator("Oxbay_port", "reload2_back", true);
			chrEnableReloadLocator("Oxbay_port", "reload3", true);
			chrEnableReloadLocator("Oxbay_port", "reload4", true);


	//		Pchar.ship.hp = 500;
	//		Pchar.ship.crew.quantity = 57;

			Locations[FindLocation("Oxbay_Port")].locators_radius.goto.goto18 = 0.5;

			pchar.quest.Tut_FollowTheSpyglass.over = "yes";
			pchar.quest.Tut_ReloadToOxbayTown.over = "yes";

			CloseQuestHeader("Tutorial_AppearedOnOxbay");

	/*		SetQuestHeader("Tutorial_SpyGlass");
			AddQuestRecord("Tutorial_SpyGlass", "1");

			Pchar.quest.Tut_BuySpyGlass.win_condition.l1 = "item";
			Pchar.quest.Tut_BuySpyGlass.win_condition.l1.character = Pchar.id;
			Pchar.quest.Tut_BuySpyGlass.win_condition.l1.item = "SpyGlass2";
			Pchar.quest.Tut_BuySpyGlass.win_condition = "Tut_BuySpyGlass";
			Pchar.quest.Tut_BuySpyGlass.fail_condition = "Tut_BuySpyGlass";

			SetQuestHeader("Tutorial_Store");
			AddQuestRecord("Tutorial_Store", "1");

			Pchar.quest.Tut_SellGoods.win_condition.l1 = "goods";
			Pchar.quest.Tut_SellGoods.win_condition.l1.character = Pchar.id;
			Pchar.quest.Tut_SellGoods.win_condition.l1.goods = GOOD_CHOCOLATE;
			Pchar.quest.Tut_SellGoods.win_condition.l1.quantity = "0";
			Pchar.quest.Tut_SellGoods.win_condition.l1.operation = "=";
			Pchar.quest.Tut_SellGoods.win_condition.l2 = "goods";
			Pchar.quest.Tut_SellGoods.win_condition.l2.character = Pchar.id;
			Pchar.quest.Tut_SellGoods.win_condition.l2.goods = GOOD_LEATHER;
			Pchar.quest.Tut_SellGoods.win_condition.l2.quantity = "0";
			Pchar.quest.Tut_SellGoods.win_condition.l2.operation = "=";
			Pchar.quest.Tut_SellGoods.win_condition = "Tut_SellGoods";
			Pchar.quest.Tut_SellGoods.fail_condition = "Tut_SellGoods";

			SetQuestHeader("Tutorial_Shipyard");
			AddQuestRecord("Tutorial_Shipyard", "1");

			Pchar.quest.Tut_RepairShip.win_condition.l1 = "Ship_HP";
			Pchar.quest.Tut_RepairShip.win_condition.l1.character = Pchar.id;
			Pchar.quest.Tut_RepairShip.win_condition.l1.quantity = "500";
			Pchar.quest.Tut_RepairShip.win_condition.l1.operation = "=";
			Pchar.quest.Tut_RepairShip.win_condition = "Tut_RepairShip";
			Pchar.quest.Tut_RepairShip.fail_condition = "Tut_RepairShip";

			SetQuestHeader("Tutorial_Tavern");
			AddQuestRecord("Tutorial_Tavern", "1");

			Pchar.quest.Tut_HireCrew.win_condition.l1 = "Crew_Space";
			Pchar.quest.Tut_HireCrew.win_condition.l1.character = Pchar.id;
			Pchar.quest.Tut_HireCrew.win_condition.l1.quantity = "0";
			Pchar.quest.Tut_HireCrew.win_condition.l1.operation = "=";
			Pchar.quest.Tut_HireCrew.win_condition = "Tut_HireCrew";
			Pchar.quest.Tut_HireCrew.fail_condition = "Tut_HireCrew";
*/

			LAi_SetWarriorTypeNoGroup(CharacterFromID("Malcolm Hatcher"));
			LAi_warrior_SetStay(CharacterFromID("Malcolm Hatcher"), true);
			LAi_warrior_DialogEnable(CharacterFromID("Malcolm Hatcher"), true);

			Pchar.quest.Tut_KillTutor.over = "yes";
		break;

		case "Tut_SkipTutorialInTown":
			LAi_LockFightMode(Pchar, false);
			EndQuestMovie();
			locDisableUpdateTime = false;
			LAi_RemoveCheckMinHP(CharacterFromID("Malcolm Hatcher"));
			LAi_RemoveCheckMinHP(Pchar);
			
			chrEnableReloadLocator("Oxbay_town", "reload1", true);
			chrEnableReloadLocator("Oxbay_town", "reload2", true);
			chrEnableReloadLocator("Oxbay_town", "reload3", true);
			chrEnableReloadLocator("Oxbay_town", "reload4", true);
			chrEnableReloadLocator("Oxbay_town", "reload5", true);
			chrEnableReloadLocator("Oxbay_town", "reload6", true);
			chrEnableReloadLocator("Oxbay_town", "reload7", true);
			chrEnableReloadLocator("Oxbay_town", "reload8", true);
			chrEnableReloadLocator("Oxbay_town", "reload9", true);
			chrEnableReloadLocator("Oxbay_town", "reload10", true);
			chrEnableReloadLocator("Oxbay_town", "reload11", true);
			chrEnableReloadLocator("Oxbay_town", "reload12", true);
			chrEnableReloadLocator("Oxbay_town", "reload13", true);
			chrEnableReloadLocator("Oxbay_town", "reload14", true);
			chrEnableReloadLocator("Oxbay_town", "reload15", true);
			chrEnableReloadLocator("Oxbay_town", "reload16", true);
			chrEnableReloadLocator("Oxbay_town", "reload17", true);
			chrEnableReloadLocator("Oxbay_town", "reload18", true);
			chrEnableReloadLocator("Oxbay_town", "reload19", true);

	//		Pchar.ship.hp = 500;
	//		Pchar.ship.crew.quantity = 57;

			Locations[FindLocation("Oxbay_Port")].locators_radius.goto.goto18 = 0.5;
			
			CloseQuestHeader("Tutorial_AppearedOnOxbay");
/*			SetQuestHeader("Tutorial_SpyGlass");
			AddQuestRecord("Tutorial_SpyGlass", "1");

			Pchar.quest.Tut_BuySpyGlass.win_condition.l1 = "item";
			Pchar.quest.Tut_BuySpyGlass.win_condition.l1.character = Pchar.id;
			Pchar.quest.Tut_BuySpyGlass.win_condition.l1.item = "SpyGlass2";
			Pchar.quest.Tut_BuySpyGlass.win_condition = "Tut_BuySpyGlass";
			Pchar.quest.Tut_BuySpyGlass.fail_condition = "Tut_BuySpyGlass";

			SetQuestHeader("Tutorial_Store");
			AddQuestRecord("Tutorial_Store", "1");

			Pchar.quest.Tut_SellGoods.win_condition.l1 = "goods";
			Pchar.quest.Tut_SellGoods.win_condition.l1.character = Pchar.id;
			Pchar.quest.Tut_SellGoods.win_condition.l1.goods = GOOD_CHOCOLATE;
			Pchar.quest.Tut_SellGoods.win_condition.l1.quantity = "0";
			Pchar.quest.Tut_SellGoods.win_condition.l1.operation = "=";
			Pchar.quest.Tut_SellGoods.win_condition.l2 = "goods";
			Pchar.quest.Tut_SellGoods.win_condition.l2.character = Pchar.id;
			Pchar.quest.Tut_SellGoods.win_condition.l2.goods = GOOD_LEATHER;
			Pchar.quest.Tut_SellGoods.win_condition.l2.quantity = "0";
			Pchar.quest.Tut_SellGoods.win_condition.l2.operation = "=";
			Pchar.quest.Tut_SellGoods.win_condition = "Tut_SellGoods";
			Pchar.quest.Tut_SellGoods.fail_condition = "Tut_SellGoods";

			SetQuestHeader("Tutorial_Shipyard");
			AddQuestRecord("Tutorial_Shipyard", "1");

			Pchar.quest.Tut_RepairShip.win_condition.l1 = "Ship_HP";
			Pchar.quest.Tut_RepairShip.win_condition.l1.character = Pchar.id;
			Pchar.quest.Tut_RepairShip.win_condition.l1.quantity = "500";
			Pchar.quest.Tut_RepairShip.win_condition.l1.operation = "=";
			Pchar.quest.Tut_RepairShip.win_condition = "Tut_RepairShip";
			Pchar.quest.Tut_RepairShip.fail_condition = "Tut_RepairShip";

			SetQuestHeader("Tutorial_Tavern");
			AddQuestRecord("Tutorial_Tavern", "1");

			Pchar.quest.Tut_HireCrew.win_condition.l1 = "Crew_Space";
			Pchar.quest.Tut_HireCrew.win_condition.l1.character = Pchar.id;
			Pchar.quest.Tut_HireCrew.win_condition.l1.quantity = "0";
			Pchar.quest.Tut_HireCrew.win_condition.l1.operation = "=";
			Pchar.quest.Tut_HireCrew.win_condition = "Tut_HireCrew";
			Pchar.quest.Tut_HireCrew.fail_condition = "Tut_HireCrew";
*/

			LAi_SetWarriorTypeNoGroup(CharacterFromID("Malcolm Hatcher"));
			LAi_warrior_SetStay(CharacterFromID("Malcolm Hatcher"), true);
			LAi_warrior_DialogEnable(CharacterFromID("Malcolm Hatcher"), true);

			Pchar.quest.Tut_KillTutor.over = "yes";
		break;








		////////////////////////////////////////////////////////////////////////
		//  ЗАЙМЫ - ОГРАНИЧЕНИЕ ПО ВРЕМЕНИ
		////////////////////////////////////////////////////////////////////////

		case "Loans_Redmond":

			ChangeCharacterReputation(Pchar, -20);
			Characters[GetCharacterIndex("Redmond Usurer")].Dialog.CurrentNode = "DeadMotherfucker";

			NPChar = CharacterFromID("Usurer_Avenger01");

			//Простановка параметров капитанам-преследователям
			NPChar.act.hp = 120;
			NPChar.nation =  PIRATE;
			SetRandomNameToCharacter(NPChar);
			NPChar.rank = makeint(Pchar.rank) - 2 + Rand(4);
			NPChar.experience = CalculateExperienceFromRank(sti(NPChar.rank));
			NPChar.model = "pirat6";

			CalculateAppropriateSkills(NPChar);	

			SelectCoastalGuardShip(NPChar);

			SetRandomNameToShip(characterFromID("Usurer_Avenger01"));
			SetBaseShipData(NPChar);

			Group_CreateGroup("Usurer_Avenger");
			Group_addCharacter("Usurer_Avenger", "Usurer_Avenger01");
			Group_SetGroupCommander("Usurer_Avenger", "Usurer_Avenger01");


			NPChar = CharacterFromID("Usurer_Avenger02");

		//Простановка параметров капитанам-преследователям
			NPChar.act.hp = 120;
			NPChar.nation =  PIRATE;
			SetRandomNameToCharacter(NPChar);
			NPChar.rank = makeint(Pchar.rank) - 2 + Rand(4);
			NPChar.experience = CalculateExperienceFromRank(sti(NPChar.rank));
			NPChar.model = "pirat3";

			CalculateAppropriateSkills(NPChar);	

			SelectCoastalGuardShip(NPChar);
			SetRandomNameToShip(characterFromID("Usurer_Avenger02"));
			SetBaseShipData(NPChar);

			Group_addCharacter("Usurer_Avenger", "Usurer_Avenger02");


			NPChar = CharacterFromID("Usurer_Avenger03");

		//Простановка параметров капитанам-преследователям
			NPChar.act.hp = 120;
			NPChar.nation =  PIRATE;
			SetRandomNameToCharacter(NPChar);
			NPChar.rank = makeint(Pchar.rank) - 2 + Rand(4);
			NPChar.experience = CalculateExperienceFromRank(sti(NPChar.rank));
			NPChar.model = "pirat4";

			CalculateAppropriateSkills(NPChar);	

			SelectCoastalGuardShip(NPChar);

			SetBaseShipData(NPChar);
			SetRandomNameToShip(characterFromID("Usurer_Avenger03"));
			Group_addCharacter("Usurer_Avenger", "Usurer_Avenger03");

			SetCharacterRelationBoth(GetCharacterIndex("Usurer_Avenger01"),GetMainCharacterIndex(),RELATION_ENEMY);	
			Group_SetTaskAttack("Usurer_Avenger", PLAYER_GROUP);
			Group_LockTask("Usurer_Avenger");

			Encounter_SetQuestMapEncounter("Usurer_Avenger", ENCOUNTER_WAR, true, 50);
		
		break;

		case "Loans_Oxbay":

			ChangeCharacterReputation(Pchar, -20);

			Characters[GetCharacterIndex("Oxbay Usurer")].Dialog.CurrentNode = "DeadMotherfucker";

			NPChar = CharacterFromID("Usurer_Avenger01");

			//Простановка параметров капитанам-преследователям
			NPChar.act.hp = 120;
			NPChar.nation =  PIRATE;
			SetRandomNameToCharacter(NPChar);
			NPChar.rank = makeint(Pchar.rank) - 2 + Rand(4);
			NPChar.experience = CalculateExperienceFromRank(sti(NPChar.rank));
			NPChar.model = "pirat6";

			CalculateAppropriateSkills(NPChar);	

			SelectCoastalGuardShip(NPChar);

			SetRandomNameToShip(characterFromID("Usurer_Avenger01"));
			SetBaseShipData(NPChar);

			Group_CreateGroup("Usurer_Avenger");
			Group_addCharacter("Usurer_Avenger", "Usurer_Avenger01");
			Group_SetGroupCommander("Usurer_Avenger", "Usurer_Avenger01");


			NPChar = CharacterFromID("Usurer_Avenger02");

		//Простановка параметров капитанам-преследователям
			NPChar.act.hp = 120;
			NPChar.nation =  PIRATE;
			SetRandomNameToCharacter(NPChar);
			NPChar.rank = makeint(Pchar.rank) - 2 + Rand(4);
			NPChar.experience = CalculateExperienceFromRank(sti(NPChar.rank));
			NPChar.model = "pirat3";

			CalculateAppropriateSkills(NPChar);	

			SelectCoastalGuardShip(NPChar);

			SetRandomNameToShip(characterFromID("Usurer_Avenger02"));
			SetBaseShipData(NPChar);

			Group_addCharacter("Usurer_Avenger", "Usurer_Avenger02");


			NPChar = CharacterFromID("Usurer_Avenger03");

		//Простановка параметров капитанам-преследователям
			NPChar.act.hp = 120;
			NPChar.nation =  PIRATE;
			SetRandomNameToCharacter(NPChar);
			NPChar.rank = makeint(Pchar.rank) - 2 + Rand(4);
			NPChar.experience = CalculateExperienceFromRank(sti(NPChar.rank));
			NPChar.model = "pirat4";

			CalculateAppropriateSkills(NPChar);	

			SelectCoastalGuardShip(NPChar);

			SetRandomNameToShip(characterFromID("Usurer_Avenger03"));
			SetBaseShipData(NPChar);

			Group_addCharacter("Usurer_Avenger", "Usurer_Avenger03");

			SetCharacterRelationBoth(GetCharacterIndex("Usurer_Avenger01"),GetMainCharacterIndex(),RELATION_ENEMY);	
			Group_SetTaskAttack("Usurer_Avenger", PLAYER_GROUP);
			Group_LockTask("Usurer_Avenger");

			Encounter_SetQuestMapEncounter("Usurer_Avenger", ENCOUNTER_WAR, true, 50);	
		break;

		case "Loans_Greenford":
			Characters[GetCharacterIndex("Greenford Usurer")].Dialog.CurrentNode = "DeadMotherfucker";

			ChangeCharacterReputation(Pchar, -20);

			NPChar = CharacterFromID("Usurer_Avenger01");

			//Простановка параметров капитанам-преследователям
			NPChar.act.hp = 120;
			NPChar.nation =  PIRATE;
			SetRandomNameToCharacter(NPChar);
			NPChar.rank = makeint(Pchar.rank) - 2 + Rand(4);
			NPChar.experience = CalculateExperienceFromRank(sti(NPChar.rank));
			NPChar.model = "pirat6";

			CalculateAppropriateSkills(NPChar);	

			SelectCoastalGuardShip(NPChar);

			SetRandomNameToShip(characterFromID("Usurer_Avenger01"));
			SetBaseShipData(NPChar);

			Group_CreateGroup("Usurer_Avenger");
			Group_addCharacter("Usurer_Avenger", "Usurer_Avenger01");
			Group_SetGroupCommander("Usurer_Avenger", "Usurer_Avenger01");


			NPChar = CharacterFromID("Usurer_Avenger02");

		//Простановка параметров капитанам-преследователям
			NPChar.act.hp = 120;
			NPChar.nation =  PIRATE;
			SetRandomNameToCharacter(NPChar);
			NPChar.rank = makeint(Pchar.rank) - 2 + Rand(4);
			NPChar.experience = CalculateExperienceFromRank(sti(NPChar.rank));
			NPChar.model = "pirat3";

			CalculateAppropriateSkills(NPChar);	

			SelectCoastalGuardShip(NPChar);

			SetRandomNameToShip(characterFromID("Usurer_Avenger02"));
			SetBaseShipData(NPChar);

			Group_addCharacter("Usurer_Avenger", "Usurer_Avenger02");


			NPChar = CharacterFromID("Usurer_Avenger03");

		//Простановка параметров капитанам-преследователям
			NPChar.act.hp = 120;
			NPChar.nation =  PIRATE;
			SetRandomNameToCharacter(NPChar);
			NPChar.rank = makeint(Pchar.rank) - 2 + Rand(4);
			NPChar.experience = CalculateExperienceFromRank(sti(NPChar.rank));
			NPChar.model = "pirat4";

			CalculateAppropriateSkills(NPChar);	

			SelectCoastalGuardShip(NPChar);

			SetRandomNameToShip(characterFromID("Usurer_Avenger03"));
			SetBaseShipData(NPChar);

			Group_addCharacter("Usurer_Avenger", "Usurer_Avenger03");

			SetCharacterRelationBoth(GetCharacterIndex("Usurer_Avenger01"),GetMainCharacterIndex(),RELATION_ENEMY);	
			Group_SetTaskAttack("Usurer_Avenger", PLAYER_GROUP);
			Group_LockTask("Usurer_Avenger");

			Encounter_SetQuestMapEncounter("Usurer_Avenger", ENCOUNTER_WAR, true, 50);	
		break;

		case "Loans_FalaiseDeFleur":
			Characters[GetCharacterIndex("FF Usurer")].Dialog.CurrentNode = "DeadMotherfucker";

			ChangeCharacterReputation(Pchar, -20);

			NPChar = CharacterFromID("Usurer_Avenger01");

			//Простановка параметров капитанам-преследователям
			NPChar.act.hp = 120;
			NPChar.nation =  PIRATE;
			SetRandomNameToCharacter(NPChar);
			NPChar.rank = makeint(Pchar.rank) - 2 + Rand(4);
			NPChar.experience = CalculateExperienceFromRank(sti(NPChar.rank));
			NPChar.model = "pirat6";

			CalculateAppropriateSkills(NPChar);	

			SelectCoastalGuardShip(NPChar);

			SetRandomNameToShip(characterFromID("Usurer_Avenger01"));
			SetBaseShipData(NPChar);

			Group_CreateGroup("Usurer_Avenger");
			Group_addCharacter("Usurer_Avenger", "Usurer_Avenger01");
			Group_SetGroupCommander("Usurer_Avenger", "Usurer_Avenger01");


			NPChar = CharacterFromID("Usurer_Avenger02");

		//Простановка параметров капитанам-преследователям
			NPChar.act.hp = 120;
			NPChar.nation =  PIRATE;
			SetRandomNameToCharacter(NPChar);
			NPChar.rank = makeint(Pchar.rank) - 2 + Rand(4);
			NPChar.experience = CalculateExperienceFromRank(sti(NPChar.rank));
			NPChar.model = "pirat3";

			CalculateAppropriateSkills(NPChar);	

			SelectCoastalGuardShip(NPChar);

			SetRandomNameToShip(characterFromID("Usurer_Avenger02"));
			SetBaseShipData(NPChar);

			Group_addCharacter("Usurer_Avenger", "Usurer_Avenger02");


			NPChar = CharacterFromID("Usurer_Avenger03");

		//Простановка параметров капитанам-преследователям
			NPChar.act.hp = 120;
			NPChar.nation =  PIRATE;
			SetRandomNameToCharacter(NPChar);
			NPChar.rank = makeint(Pchar.rank) - 2 + Rand(4);
			NPChar.experience = CalculateExperienceFromRank(sti(NPChar.rank));
			NPChar.model = "pirat4";

			CalculateAppropriateSkills(NPChar);	

			SelectCoastalGuardShip(NPChar);

			SetRandomNameToShip(characterFromID("Usurer_Avenger03"));
			SetBaseShipData(NPChar);

			Group_addCharacter("Usurer_Avenger", "Usurer_Avenger03");

			SetCharacterRelationBoth(GetCharacterIndex("Usurer_Avenger01"),GetMainCharacterIndex(),RELATION_ENEMY);	
			Group_SetTaskAttack("Usurer_Avenger", PLAYER_GROUP);
			Group_LockTask("Usurer_Avenger");

			Encounter_SetQuestMapEncounter("Usurer_Avenger", ENCOUNTER_WAR, true, 50);	
		break;

		case "Loans_Conceicao":
			Characters[GetCharacterIndex("Conceicao Usurer")].Dialog.CurrentNode = "DeadMotherfucker";

			ChangeCharacterReputation(Pchar, -20);

			NPChar = CharacterFromID("Usurer_Avenger01");

			//Простановка параметров капитанам-преследователям
			NPChar.act.hp = 120;
			NPChar.nation =  PIRATE;
			SetRandomNameToCharacter(NPChar);
			NPChar.rank = makeint(Pchar.rank) - 2 + Rand(4);
			NPChar.experience = CalculateExperienceFromRank(sti(NPChar.rank));
			NPChar.model = "pirat6";

			CalculateAppropriateSkills(NPChar);	

			SelectCoastalGuardShip(NPChar);

			SetRandomNameToShip(characterFromID("Usurer_Avenger01"));
			SetBaseShipData(NPChar);

			Group_CreateGroup("Usurer_Avenger");
			Group_addCharacter("Usurer_Avenger", "Usurer_Avenger01");
			Group_SetGroupCommander("Usurer_Avenger", "Usurer_Avenger01");


			NPChar = CharacterFromID("Usurer_Avenger02");

		//Простановка параметров капитанам-преследователям
			NPChar.act.hp = 120;
			NPChar.nation =  PIRATE;
			SetRandomNameToCharacter(NPChar);
			NPChar.rank = makeint(Pchar.rank) - 2 + Rand(4);
			NPChar.experience = CalculateExperienceFromRank(sti(NPChar.rank));
			NPChar.model = "pirat3";

			CalculateAppropriateSkills(NPChar);	

			SelectCoastalGuardShip(NPChar);

			SetRandomNameToShip(characterFromID("Usurer_Avenger02"));
			SetBaseShipData(NPChar);

			Group_addCharacter("Usurer_Avenger", "Usurer_Avenger02");


			NPChar = CharacterFromID("Usurer_Avenger03");

		//Простановка параметров капитанам-преследователям
			NPChar.act.hp = 120;
			NPChar.nation =  PIRATE;
			SetRandomNameToCharacter(NPChar);
			NPChar.rank = makeint(Pchar.rank) - 2 + Rand(4);
			NPChar.experience = CalculateExperienceFromRank(sti(NPChar.rank));
			NPChar.model = "pirat4";

			CalculateAppropriateSkills(NPChar);	

			SelectCoastalGuardShip(NPChar);

			SetRandomNameToShip(characterFromID("Usurer_Avenger03"));
			SetBaseShipData(NPChar);

			Group_addCharacter("Usurer_Avenger", "Usurer_Avenger03");

			SetCharacterRelationBoth(GetCharacterIndex("Usurer_Avenger01"),GetMainCharacterIndex(),RELATION_ENEMY);	
			Group_SetTaskAttack("Usurer_Avenger", PLAYER_GROUP);
			Group_LockTask("Usurer_Avenger");

			Encounter_SetQuestMapEncounter("Usurer_Avenger", ENCOUNTER_WAR, true, 50);	
		break;

		case "Loans_Douwesen":
			Characters[GetCharacterIndex("Douwesen Usurer")].Dialog.CurrentNode = "DeadMotherfucker";

			ChangeCharacterReputation(Pchar, -20);

			NPChar = CharacterFromID("Usurer_Avenger01");

			//Простановка параметров капитанам-преследователям
			NPChar.act.hp = 120;
			NPChar.nation =  PIRATE;
			SetRandomNameToCharacter(NPChar);
			NPChar.rank = makeint(Pchar.rank) - 2 + Rand(4);
			NPChar.experience = CalculateExperienceFromRank(sti(NPChar.rank));
			NPChar.model = "pirat6";

			CalculateAppropriateSkills(NPChar);	

			SelectCoastalGuardShip(NPChar);

			SetRandomNameToShip(characterFromID("Usurer_Avenger01"));
			SetBaseShipData(NPChar);

			Group_CreateGroup("Usurer_Avenger");
			Group_addCharacter("Usurer_Avenger", "Usurer_Avenger01");
			Group_SetGroupCommander("Usurer_Avenger", "Usurer_Avenger01");


			NPChar = CharacterFromID("Usurer_Avenger02");

		//Простановка параметров капитанам-преследователям
			NPChar.act.hp = 120;
			NPChar.nation =  PIRATE;
			SetRandomNameToCharacter(NPChar);
			NPChar.rank = makeint(Pchar.rank) - 2 + Rand(4);
			NPChar.experience = CalculateExperienceFromRank(sti(NPChar.rank));
			NPChar.model = "pirat3";

			CalculateAppropriateSkills(NPChar);	

			SelectCoastalGuardShip(NPChar);

			SetRandomNameToShip(characterFromID("Usurer_Avenger02"));
			SetBaseShipData(NPChar);

			Group_addCharacter("Usurer_Avenger", "Usurer_Avenger02");


			NPChar = CharacterFromID("Usurer_Avenger03");

		//Простановка параметров капитанам-преследователям
			NPChar.act.hp = 120;
			NPChar.nation =  PIRATE;
			SetRandomNameToCharacter(NPChar);
			NPChar.rank = makeint(Pchar.rank) - 2 + Rand(4);
			NPChar.experience = CalculateExperienceFromRank(sti(NPChar.rank));
			NPChar.model = "pirat4";

			CalculateAppropriateSkills(NPChar);	

			SelectCoastalGuardShip(NPChar);

			SetRandomNameToShip(characterFromID("Usurer_Avenger03"));
			SetBaseShipData(NPChar);

			Group_addCharacter("Usurer_Avenger", "Usurer_Avenger03");

			SetCharacterRelationBoth(GetCharacterIndex("Usurer_Avenger01"),GetMainCharacterIndex(),RELATION_ENEMY);	
			Group_SetTaskAttack("Usurer_Avenger", PLAYER_GROUP);
			Group_LockTask("Usurer_Avenger");

			Encounter_SetQuestMapEncounter("Usurer_Avenger", ENCOUNTER_WAR, true, 50);
		break;

		case "Loans_Muelle":
			Characters[GetCharacterIndex("Muelle Usurer")].Dialog.CurrentNode = "DeadMotherfucker";

			ChangeCharacterReputation(Pchar, -20);

			NPChar = CharacterFromID("Usurer_Avenger01");

			//Простановка параметров капитанам-преследователям
			NPChar.act.hp = 120;
			NPChar.nation =  PIRATE;
			SetRandomNameToCharacter(NPChar);
			NPChar.rank = makeint(Pchar.rank) - 2 + Rand(4);
			NPChar.experience = CalculateExperienceFromRank(sti(NPChar.rank));
			NPChar.model = "pirat6";

			CalculateAppropriateSkills(NPChar);	

			SelectCoastalGuardShip(NPChar);

			SetRandomNameToShip(characterFromID("Usurer_Avenger01"));
			SetBaseShipData(NPChar);

			Group_CreateGroup("Usurer_Avenger");
			Group_addCharacter("Usurer_Avenger", "Usurer_Avenger01");
			Group_SetGroupCommander("Usurer_Avenger", "Usurer_Avenger01");


			NPChar = CharacterFromID("Usurer_Avenger02");

		//Простановка параметров капитанам-преследователям
			NPChar.act.hp = 120;
			NPChar.nation =  PIRATE;
			SetRandomNameToCharacter(NPChar);
			NPChar.rank = makeint(Pchar.rank) - 2 + Rand(4);
			NPChar.experience = CalculateExperienceFromRank(sti(NPChar.rank));
			NPChar.model = "pirat3";

			CalculateAppropriateSkills(NPChar);	

			SelectCoastalGuardShip(NPChar);

			SetRandomNameToShip(characterFromID("Usurer_Avenger02"));
			SetBaseShipData(NPChar);

			Group_addCharacter("Usurer_Avenger", "Usurer_Avenger02");


			NPChar = CharacterFromID("Usurer_Avenger03");

		//Простановка параметров капитанам-преследователям
			NPChar.act.hp = 120;
			NPChar.nation =  PIRATE;
			SetRandomNameToCharacter(NPChar);
			NPChar.rank = makeint(Pchar.rank) - 2 + Rand(4);
			NPChar.experience = CalculateExperienceFromRank(sti(NPChar.rank));
			NPChar.model = "pirat4";

			CalculateAppropriateSkills(NPChar);	

			SelectCoastalGuardShip(NPChar);

			SetRandomNameToShip(characterFromID("Usurer_Avenger03"));
			SetBaseShipData(NPChar);

			Group_addCharacter("Usurer_Avenger", "Usurer_Avenger03");

			SetCharacterRelationBoth(GetCharacterIndex("Usurer_Avenger01"),GetMainCharacterIndex(),RELATION_ENEMY);	
			Group_SetTaskAttack("Usurer_Avenger", PLAYER_GROUP);
			Group_LockTask("Usurer_Avenger");

			Encounter_SetQuestMapEncounter("Usurer_Avenger", ENCOUNTER_WAR, true, 50);	
		break;

		case "Loans_QC":
			Characters[GetCharacterIndex("QC Usurer")].Dialog.CurrentNode = "DeadMotherfucker";

			ChangeCharacterReputation(Pchar, -20);

			NPChar = CharacterFromID("Usurer_Avenger01");

			//Простановка параметров капитанам-преследователям
			NPChar.act.hp = 120;
			NPChar.nation =  PIRATE;
			SetRandomNameToCharacter(NPChar);
			NPChar.rank = makeint(Pchar.rank) - 2 + Rand(4);
			NPChar.experience = CalculateExperienceFromRank(sti(NPChar.rank));
			NPChar.model = "pirat6";

			CalculateAppropriateSkills(NPChar);	

			SelectCoastalGuardShip(NPChar);

			SetRandomNameToShip(characterFromID("Usurer_Avenger01"));
			SetBaseShipData(NPChar);

			Group_CreateGroup("Usurer_Avenger");
			Group_addCharacter("Usurer_Avenger", "Usurer_Avenger01");
			Group_SetGroupCommander("Usurer_Avenger", "Usurer_Avenger01");


			NPChar = CharacterFromID("Usurer_Avenger02");

		//Простановка параметров капитанам-преследователям
			NPChar.act.hp = 120;
			NPChar.nation =  PIRATE;
			SetRandomNameToCharacter(NPChar);
			NPChar.rank = makeint(Pchar.rank) - 2 + Rand(4);
			NPChar.experience = CalculateExperienceFromRank(sti(NPChar.rank));
			NPChar.model = "pirat3";

			CalculateAppropriateSkills(NPChar);	

			SelectCoastalGuardShip(NPChar);

			SetRandomNameToShip(characterFromID("Usurer_Avenger02"));
			SetBaseShipData(NPChar);

			Group_addCharacter("Usurer_Avenger", "Usurer_Avenger02");


			NPChar = CharacterFromID("Usurer_Avenger03");

		//Простановка параметров капитанам-преследователям
			NPChar.act.hp = 120;
			NPChar.nation =  PIRATE;
			SetRandomNameToCharacter(NPChar);
			NPChar.rank = makeint(Pchar.rank) - 2 + Rand(4);
			NPChar.experience = CalculateExperienceFromRank(sti(NPChar.rank));
			NPChar.model = "pirat4";

			CalculateAppropriateSkills(NPChar);	

			SelectCoastalGuardShip(NPChar);

			SetRandomNameToShip(characterFromID("Usurer_Avenger03"));
			SetBaseShipData(NPChar);

			Group_addCharacter("Usurer_Avenger", "Usurer_Avenger03");

			SetCharacterRelationBoth(GetCharacterIndex("Usurer_Avenger01"),GetMainCharacterIndex(),RELATION_ENEMY);	
			Group_SetTaskAttack("Usurer_Avenger", PLAYER_GROUP);
			Group_LockTask("Usurer_Avenger");

			Encounter_SetQuestMapEncounter("Usurer_Avenger", ENCOUNTER_WAR, true, 50);
		break;




		////////////////////////////////////////////////////////////////////////
		//  Служебный квест контрабандистов - ограничение по времени
		////////////////////////////////////////////////////////////////////////

		case "Rand_Smuggling":
			Pchar.quests.contraband.relation = makeint(Pchar.quests.contraband.relation) - 10;
			RemoveSmugglersFromShore();
		break;

		case "Rand_SmugglingRemove":
			ChangeCharacterAddressGroup(CharacterFromID("Rand_Smug01"), "None", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Rand_Smug02"), "None", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Rand_Smug03"), "None", "", "");			
		break;


		//Постановка стражников в локацию передачи контрабандистов
		case "Rand_ContrabandInterruption":

			//trace("ПОЯВЛЕНИЕ БЕРЕГОВОЙ СТРАЖИ: " + sld.id);

			//LAi_CreateFantomCharacter("soldier_eng", "", "");
						
			
			sld = LAi_CreateFantomCharacter(SelectSoldierModelbyLocationNation(Pchar.location, "Officer"), "", "");
			Pchar.quest.contraband.SoldierIDX1 = sld.index;
		//	Log_SetstringToLog("Индекс ссылки на первого солдата(фантома): " + sld.index);
			//Pchar.quest.contraband.SoldierIDX1 = getCharacterIndex(sld.id);
			LAi_SetActorType(sld);
			LAi_group_MoveCharacter(sld, "CoastalGuards");
			sld.Dialog.Filename = "Coastal Guards_dialog.c";
			sld.Dialog.CurrentNode = "First time";
			sld.skill.Fencing = makeint(Pchar.skill.Fencing) - 1 + Rand(4);
		//	Log_SetstringToLog("Индекс первого солдата: " + Pchar.quest.contraband.SoldierIDX1);

			trace("ПОЯВЛЕНИЕ БЕРЕГОВОЙ СТРАЖИ: " + sld.id);
			LAi_ActorDialog(sld, Pchar, "", 120, 0);
			
			
			sld = LAi_CreateFantomCharacter(SelectSoldierModelbyLocationNation(Pchar.location, "Soldier"), "", "");
			Pchar.quest.contraband.SoldierIDX2 = sld.index;			
			LAi_SetActorType(sld);
			LAi_group_MoveCharacter(sld, "CoastalGuards");
			sld.skill.Fencing = makeint(Pchar.skill.Fencing) - 2 + Rand(4);
			LAi_ActorFollow(sld, Pchar, "", 120);

			sld = LAi_CreateFantomCharacter(SelectSoldierModelbyLocationNation(Pchar.location, "Soldier"), "", "");
			Pchar.quest.contraband.SoldierIDX3 = sld.index;
			LAi_SetActorType(sld);
			LAi_group_MoveCharacter(sld, "CoastalGuards");
			sld.skill.Fencing = makeint(Pchar.skill.Fencing) - 2 + Rand(4);
			LAi_ActorFollow(sld, Pchar, "", 120);

			sld = LAi_CreateFantomCharacter(SelectSoldierModelbyLocationNation(Pchar.location, "Soldier"), "", "");
			Pchar.quest.contraband.SoldierIDX4 = sld.index;
			LAi_SetActorType(sld);
			LAi_group_MoveCharacter(sld, "CoastalGuards");
			sld.skill.Fencing = makeint(Pchar.skill.Fencing) - 2 + Rand(4);
			LAi_ActorFollow(sld, Pchar, "", 120);

			sld = LAi_CreateFantomCharacter(SelectSoldierModelbyLocationNation(Pchar.location, "Soldier"), "", "");
			Pchar.quest.contraband.SoldierIDX5 = sld.index;
			LAi_SetActorType(sld);
			LAi_group_MoveCharacter(sld, "CoastalGuards");
			sld.skill.Fencing = makeint(Pchar.skill.Fencing) - 2 + Rand(4);
			LAi_ActorFollow(sld, Pchar, "", 120);

			sld = LAi_CreateFantomCharacter(SelectSoldierModelbyLocationNation(Pchar.location, "Soldier"), "", "");
			Pchar.quest.contraband.SoldierIDX6 = sld.index;
			LAi_SetActorType(sld);
			LAi_group_MoveCharacter(sld, "CoastalGuards");
			sld.skill.Fencing = makeint(Pchar.skill.Fencing) - 2 + Rand(4);
			LAi_ActorFollow(sld, Pchar, "", 120);

			SetCoastalGuardPursuit();

			Lai_QuestDelay("Rand_CoastalPatrolAppear", 1.0);
		/*	Pchar.quest.Rand_ContrabandInterruptionAtSea.win_condition.l1 = "location";
			Pchar.quest.Rand_ContrabandInterruptionAtSea.win_condition.l1.character = PChar.id;
			Pchar.quest.Rand_ContrabandInterruptionAtSea.win_condition.l1.location = Islands[GetCharacterCurrentIsland(pchar)].id;
			Pchar.quest.Rand_ContrabandInterruptionAtSea.win_condition = "Rand_ContrabandInterruptionAtSea";*/
		break;

		case "Rand_CoastalPatrolAppear":			  
			Trace("QUEST Rand_CoastalPatrolAppear reports: Soldier Idx = " + Pchar.quest.contraband.SoldierIDX1);
			//StartQuestMovie(true, true, true);
			LAi_SetActorTypeNoGroup(Pchar);
			LAi_ActorTurnToCharacter(Pchar, &Characters[makeint(Pchar.quest.contraband.SoldierIDX1)]);
			LAi_ActorWaitDialog(Pchar, &Characters[makeint(Pchar.quest.contraband.SoldierIDX1)]);
			//LAi_SetPlayerType(Pchar);
		break;

		case "Rand_ContrabandInterruptionAtSeaEnded":
			StopCoastalGuardPursuit();
		break;

		





////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////LAND ENCOUNTERS QUESTS///////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////


//------------------------------------------RAIDERS----------------------------------------------------
		case "LandEnc_RaidersLogin":
			LAi_group_SetRelation("ENC_RAIDERS_GROUP", LAI_GROUP_PLAYER, LAI_GROUP_NEITRAL);

			LAi_SetCheckMinHP(characterFromID("Enc_Char1"), (LAi_GetCharacterHP(CharacterFromID("Enc_Char1")) - 1), false, "LandEnc_RaidersFight");
			LAi_SetCheckMinHP(characterFromID("Enc_Char2"), (LAi_GetCharacterHP(CharacterFromID("Enc_Char2")) - 1), false, "LandEnc_RaidersFight");
			LAi_SetCheckMinHP(characterFromID("Enc_Char3"), (LAi_GetCharacterHP(CharacterFromID("Enc_Char3")) - 1), false, "LandEnc_RaidersFight");
			LAi_SetCheckMinHP(characterFromID("Enc_Char4"), (LAi_GetCharacterHP(CharacterFromID("Enc_Char4")) - 1), false, "LandEnc_RaidersFight");
		break;


		case "LandEnc_RaidersStart":
			LAi_SetActorType(CharacterFromID("Enc_Char1"));
			LAi_SetActorType(CharacterFromID("Enc_Char2"));
			LAi_SetActorType(CharacterFromID("Enc_Char3"));
			LAi_SetActorType(CharacterFromID("Enc_Char4"));

			LAi_group_MoveCharacter(CharacterFromID("Enc_Char1"), "ENC_RAIDERS_GROUP");
			LAi_group_MoveCharacter(CharacterFromID("Enc_Char2"), "ENC_RAIDERS_GROUP");
			LAi_group_MoveCharacter(CharacterFromID("Enc_Char3"), "ENC_RAIDERS_GROUP");
			LAi_group_MoveCharacter(CharacterFromID("Enc_Char4"), "ENC_RAIDERS_GROUP");

			LAi_SetCheckMinHP(characterFromID("Enc_Char1"), (LAi_GetCharacterHP(CharacterFromID("Enc_Char1")) - 1), false, "LandEnc_RaidersFight");
			LAi_SetCheckMinHP(characterFromID("Enc_Char2"), (LAi_GetCharacterHP(CharacterFromID("Enc_Char2")) - 1), false, "LandEnc_RaidersFight");
			LAi_SetCheckMinHP(characterFromID("Enc_Char3"), (LAi_GetCharacterHP(CharacterFromID("Enc_Char3")) - 1), false, "LandEnc_RaidersFight");
			LAi_SetCheckMinHP(characterFromID("Enc_Char4"), (LAi_GetCharacterHP(CharacterFromID("Enc_Char4")) - 1), false, "LandEnc_RaidersFight");
			
			LAi_ActorDialog(CharacterFromID("Enc_Char1"), Pchar, "", 10, 0);
			LAi_ActorDialog(CharacterFromID("Enc_Char2"), Pchar, "", 10, 0);
			LAi_ActorDialog(CharacterFromID("Enc_Char3"), Pchar, "", 10, 0);
			LAi_ActorDialog(CharacterFromID("Enc_Char4"), Pchar, "", 10, 0);

			if(CheckAttribute(Pchar, "quest.LandEnc_StartingQuest1")) pchar.quest.LandEnc_StartingQuest1.over = "yes";
			if(CheckAttribute(Pchar, "quest.LandEnc_StartingQuest2")) pchar.quest.LandEnc_StartingQuest2.over = "yes";
			if(CheckAttribute(Pchar, "quest.LandEnc_StartingQuest3")) pchar.quest.LandEnc_StartingQuest3.over = "yes";

			LAi_SetFightMode(PChar, false);
			LAi_LockFightMode(Pchar, true);
		break;

		case "LandEnc_RaidersFight":
			LAi_LockFightMode(Pchar, false);

			LAi_RemoveCheckMinHP(characterFromID("Enc_Char1"));
			LAi_RemoveCheckMinHP(characterFromID("Enc_Char2"));
			LAi_RemoveCheckMinHP(characterFromID("Enc_Char3"));
			LAi_RemoveCheckMinHP(characterFromID("Enc_Char4"));

			LAi_type_actor_Reset(CharacterFromID("Enc_Char1"));
			LAi_type_actor_Reset(CharacterFromID("Enc_Char2"));
			LAi_type_actor_Reset(CharacterFromID("Enc_Char3"));
			LAi_type_actor_Reset(CharacterFromID("Enc_Char4"));

			LAi_SetWarriorTypeNoGroup(CharacterFromID("Enc_Char1"));
			LAi_SetWarriorTypeNoGroup(CharacterFromID("Enc_Char2"));
			LAi_SetWarriorTypeNoGroup(CharacterFromID("Enc_Char3"));
			LAi_SetWarriorTypeNoGroup(CharacterFromID("Enc_Char4"));

			LAi_group_MoveCharacter(CharacterFromID("Enc_Char1"), "ENC_RAIDERS_GROUP");
			LAi_group_MoveCharacter(CharacterFromID("Enc_Char2"), "ENC_RAIDERS_GROUP");
			LAi_group_MoveCharacter(CharacterFromID("Enc_Char3"), "ENC_RAIDERS_GROUP");
			LAi_group_MoveCharacter(CharacterFromID("Enc_Char4"), "ENC_RAIDERS_GROUP");

			if(CheckAttribute(Pchar, "quest.LandEnc_StartingQuest1")) pchar.quest.LandEnc_StartingQuest1.over = "yes";
			if(CheckAttribute(Pchar, "quest.LandEnc_StartingQuest2")) pchar.quest.LandEnc_StartingQuest2.over = "yes";
			if(CheckAttribute(Pchar, "quest.LandEnc_StartingQuest3")) pchar.quest.LandEnc_StartingQuest3.over = "yes";

			LAi_group_FightGroups("ENC_RAIDERS_GROUP", LAI_GROUP_PLAYER, false);
		break;

		case "LandEnc_RaidersRunAway":
			LAi_LockFightMode(Pchar, false);

			LAi_type_actor_Reset(CharacterFromID("Enc_Char1"));
			LAi_type_actor_Reset(CharacterFromID("Enc_Char2"));
			LAi_type_actor_Reset(CharacterFromID("Enc_Char3"));
			LAi_type_actor_Reset(CharacterFromID("Enc_Char4"));

			LAi_ActorAfraid(CharacterFromID("Enc_Char1"), Pchar, true);
			LAi_ActorAfraid(CharacterFromID("Enc_Char2"), Pchar, true);
			LAi_ActorAfraid(CharacterFromID("Enc_Char3"), Pchar, true);
			LAi_ActorAfraid(CharacterFromID("Enc_Char4"), Pchar, true);

			if(CheckAttribute(Pchar, "quest.LandEnc_StartingQuest1")) pchar.quest.LandEnc_StartingQuest1.over = "yes";
			if(CheckAttribute(Pchar, "quest.LandEnc_StartingQuest2")) pchar.quest.LandEnc_StartingQuest2.over = "yes";
			if(CheckAttribute(Pchar, "quest.LandEnc_StartingQuest3")) pchar.quest.LandEnc_StartingQuest3.over = "yes";

			Characters[GetCharacterIndex("Enc_Char1")].Dialog.CurrentNode = "GetTheHellOut";
			Characters[GetCharacterIndex("Enc_Char2")].Dialog.CurrentNode = "GetTheHellOut";
			Characters[GetCharacterIndex("Enc_Char3")].Dialog.CurrentNode = "GetTheHellOut";
			Characters[GetCharacterIndex("Enc_Char4")].Dialog.CurrentNode = "GetTheHellOut";
		break;

		case "LandEnc_RaidersNoFight":
			LAi_LockFightMode(Pchar, false);

			LAi_type_actor_Reset(CharacterFromID("Enc_Char1"));
			LAi_type_actor_Reset(CharacterFromID("Enc_Char2"));
			LAi_type_actor_Reset(CharacterFromID("Enc_Char3"));
			LAi_type_actor_Reset(CharacterFromID("Enc_Char4"));

			LAi_SetWarriorTypeNoGroup(CharacterFromID("Enc_Char1"));
			LAi_SetWarriorTypeNoGroup(CharacterFromID("Enc_Char2"));
			LAi_SetWarriorTypeNoGroup(CharacterFromID("Enc_Char3"));
			LAi_SetWarriorTypeNoGroup(CharacterFromID("Enc_Char4"));

			LAi_warrior_DialogEnable(CharacterFromID("Enc_Char1"), true);
			LAi_warrior_DialogEnable(CharacterFromID("Enc_Char2"), true);
			LAi_warrior_DialogEnable(CharacterFromID("Enc_Char3"), true);
			LAi_warrior_DialogEnable(CharacterFromID("Enc_Char4"), true);

			if(CheckAttribute(Pchar, "quest.LandEnc_StartingQuest1")) pchar.quest.LandEnc_StartingQuest1.over = "yes";
			if(CheckAttribute(Pchar, "quest.LandEnc_StartingQuest2")) pchar.quest.LandEnc_StartingQuest2.over = "yes";
			if(CheckAttribute(Pchar, "quest.LandEnc_StartingQuest3")) pchar.quest.LandEnc_StartingQuest3.over = "yes";

			Characters[GetCharacterIndex("Enc_Char1")].Dialog.CurrentNode = "GetLost";
			Characters[GetCharacterIndex("Enc_Char2")].Dialog.CurrentNode = "GetLost";
			Characters[GetCharacterIndex("Enc_Char3")].Dialog.CurrentNode = "GetLost";
			Characters[GetCharacterIndex("Enc_Char4")].Dialog.CurrentNode = "GetLost";
		break;

		case "LandEnc_RaidersRobbed":
			LAi_LockFightMode(Pchar, false);

			LAi_type_actor_Reset(CharacterFromID("Enc_Char1"));
			LAi_type_actor_Reset(CharacterFromID("Enc_Char2"));
			LAi_type_actor_Reset(CharacterFromID("Enc_Char3"));
			LAi_type_actor_Reset(CharacterFromID("Enc_Char4"));

			LAi_SetWarriorTypeNoGroup(CharacterFromID("Enc_Char1"));
			LAi_SetWarriorTypeNoGroup(CharacterFromID("Enc_Char2"));
			LAi_SetWarriorTypeNoGroup(CharacterFromID("Enc_Char3"));
			LAi_SetWarriorTypeNoGroup(CharacterFromID("Enc_Char4"));

			LAi_warrior_DialogEnable(CharacterFromID("Enc_Char1"), true);
			LAi_warrior_DialogEnable(CharacterFromID("Enc_Char2"), true);
			LAi_warrior_DialogEnable(CharacterFromID("Enc_Char3"), true);
			LAi_warrior_DialogEnable(CharacterFromID("Enc_Char4"), true);

			if(CheckAttribute(Pchar, "quest.LandEnc_StartingQuest1")) pchar.quest.LandEnc_StartingQuest1.over = "yes";
			if(CheckAttribute(Pchar, "quest.LandEnc_StartingQuest2")) pchar.quest.LandEnc_StartingQuest2.over = "yes";
			if(CheckAttribute(Pchar, "quest.LandEnc_StartingQuest3")) pchar.quest.LandEnc_StartingQuest3.over = "yes";

			Characters[GetCharacterIndex("Enc_Char1")].Dialog.CurrentNode = "OnceAgain";
			Characters[GetCharacterIndex("Enc_Char2")].Dialog.CurrentNode = "OnceAgain";
			Characters[GetCharacterIndex("Enc_Char3")].Dialog.CurrentNode = "OnceAgain";
			Characters[GetCharacterIndex("Enc_Char4")].Dialog.CurrentNode = "OnceAgain";
		break;


//------------------------------------------RAPERS----------------------------------------------------

		case "LandEnc_RapersStart":
	/*		LAi_SetActorType(CharacterFromID("Enc_Char1"));
			LAi_SetActorType(CharacterFromID("Enc_Char2"));
			LAi_SetActorType(CharacterFromID("Enc_Char3"));
			LAi_SetActorType(CharacterFromID("Enc_Char4"));*/

			/*LAi_group_MoveCharacter(CharacterFromID("Enc_Char1"), "ENC_RAIDERS_GROUP");
			LAi_group_MoveCharacter(CharacterFromID("Enc_Char2"), "ENC_RAIDERS_GROUP");
			LAi_group_MoveCharacter(CharacterFromID("Enc_Char3"), "ENC_RAIDERS_GROUP");
			LAi_group_MoveCharacter(CharacterFromID("Enc_Char4"), "ENC_RAIDERS_GROUP");*/

			LAi_ActorDialog(CharacterFromID("Enc_Char1"), Pchar, "", 120, 0);
			LAi_QuestDelay("LandEnc_RapersPursue", 5);
		break;

		case "LandEnc_RapersPursue":
			//При первом подходе или истечении времени сработает квест
			LAi_ActorFollow(CharacterFromID("Enc_Char2"), CharacterFromID("Enc_Char1"), "", 240);
			LAi_ActorFollow(CharacterFromID("Enc_Char3"), CharacterFromID("Enc_Char1"), "", 240);
			LAi_ActorFollow(CharacterFromID("Enc_Char4"), CharacterFromID("Enc_Char1"), "", 240);
		break;

		case "LandEnc_RapersTalk":
			LAi_SetActorType(CharacterFromID("Enc_Char2"));
			LAi_SetActorType(CharacterFromID("Enc_Char3"));
			LAi_SetActorType(CharacterFromID("Enc_Char4"));

			LAi_ActorAfraid(CharacterFromID("Enc_Char1"), CharacterFromID("Enc_Char2"), true);

			LAi_SetCheckMinHP(characterFromID("Enc_Char2"), (LAi_GetCharacterHP(CharacterFromID("Enc_Char2")) - 1), false, "LandEnc_RapersFight");
			LAi_SetCheckMinHP(characterFromID("Enc_Char3"), (LAi_GetCharacterHP(CharacterFromID("Enc_Char3")) - 1), false, "LandEnc_RapersFight");
			LAi_SetCheckMinHP(characterFromID("Enc_Char4"), (LAi_GetCharacterHP(CharacterFromID("Enc_Char4")) - 1), false, "LandEnc_RapersFight");

			LAi_ActorDialog(CharacterFromID("Enc_Char2"), Pchar, "", 1, 0);
			LAi_ActorDialog(CharacterFromID("Enc_Char3"), Pchar, "", 1, 0);
			LAi_ActorDialog(CharacterFromID("Enc_Char4"), Pchar, "", 1, 0);
		break;

		case "LandEnc_RapersFight":
			LAi_RemoveCheckMinHP(characterFromID("Enc_Char2"));
			LAi_RemoveCheckMinHP(characterFromID("Enc_Char3"));
			LAi_RemoveCheckMinHP(characterFromID("Enc_Char4"));

			LAi_SetWarriorType(CharacterFromID("Enc_Char2"));
			LAi_SetWarriorType(CharacterFromID("Enc_Char3"));
			LAi_SetWarriorType(CharacterFromID("Enc_Char4"));

			LAi_group_MoveCharacter(CharacterFromID("Enc_Char2"), "ENC_RAPERS_GROUP");
			LAi_group_MoveCharacter(CharacterFromID("Enc_Char3"), "ENC_RAPERS_GROUP");
			LAi_group_MoveCharacter(CharacterFromID("Enc_Char4"), "ENC_RAPERS_GROUP");

			Pchar.quest.LandEnc_KillAllRapers.win_condition.l1 = "NPC_Death";
			Pchar.quest.LandEnc_KillAllRapers.win_condition.l1.character = "Enc_Char2";
			Pchar.quest.LandEnc_KillAllRapers.win_condition.l2 = "NPC_Death";
			Pchar.quest.LandEnc_KillAllRapers.win_condition.l2.character = "Enc_Char3";
			Pchar.quest.LandEnc_KillAllRapers.win_condition.l3 = "NPC_Death";
			Pchar.quest.LandEnc_KillAllRapers.win_condition.l3.character = "Enc_Char4";
			PChar.quest.LandEnc_KillAllRapers.win_condition = "LandEnc_KillAllRapers";

			LAi_ActorAfraid(CharacterFromID("Enc_Char1"), CharacterFromID("Enc_Char2"), true);

			LAi_group_FightGroups("ENC_RAPERS_GROUP", LAI_GROUP_PLAYER, false);
		break;

		case "LandEnc_RapersNoFight":

			Pchar.reputation = makeint(Pchar.reputation) - 5;

			LAi_ActorAfraid(CharacterFromID("Enc_Char1"), CharacterFromID("Enc_Char2"), true);

			LAi_ActorFollow(CharacterFromID("Enc_Char2"), CharacterFromID("Enc_Char1"), "", -1);
			LAi_ActorFollow(CharacterFromID("Enc_Char3"), CharacterFromID("Enc_Char1"), "", -1);
			LAi_ActorFollow(CharacterFromID("Enc_Char4"), CharacterFromID("Enc_Char1"), "", -1);

		break;

		case "LandEnc_KillAllRapers":
			//Pchar.reputation = makeint(Pchar.reputation) + 5;
			AddPartyExp(Pchar, makeint(Pchar.rank)*100);
			LAi_type_actor_Reset(CharacterFromID("Enc_Char1"));
			Characters[GetCharacterIndex("Enc_Char1")].Dialog.CurrentNode = "ThanksForHelp";
			LAi_ActorDialog(CharacterFromID("Enc_Char1"), Pchar, "", 15, 0);

		break;

//------------------------------------------OFFICER----------------------------------------------------

		case "LandEnc_OfficerHired":
			if(FindFreeRandomOfficer() != -1)
			{
				Pchar.quest.FreeRandomOfficerIdx = Characters[FindFreeRandomOfficer()].index;
				Pchar.quest.FreeRandomOfficerID = Characters[makeint(Pchar.quest.FreeRandomOfficerIdx)].id;
				
				trace("Free Random Officer IDX is " + Pchar.quest.FreeRandomOfficerIdx + "and he has id " + Pchar.quest.FreeRandomOfficerID);
	
				CopyAttributes(&Characters[makeint(Pchar.quest.FreeRandomOfficerIdx)], &Characters[makeint(Pchar.quest.HiringOfficerIDX)]);
				
				Characters[makeint(Pchar.quest.FreeRandomOfficerIdx)].index = Pchar.quest.FreeRandomOfficerIdx;
				Characters[makeint(Pchar.quest.FreeRandomOfficerIdx)].id = Pchar.quest.FreeRandomOfficerID;

				SetOfficersIndex(Pchar, 3, makeint(Pchar.quest.FreeRandomOfficerIdx));

				Characters[makeint(Pchar.quest.FreeRandomOfficerIdx)].location = "None";
				
			/*	Pchar.quest.LandEnc_OfficerJoined.win_condition.l1 = "ExitFromLocation";
				Pchar.quest.LandEnc_OfficerJoined.win_condition.l1.location = Pchar.location;
				Pchar.quest.LandEnc_OfficerJoined.win_condition = "LandEnc_OfficerJoined";*/

				LAi_Fade("LandEnc_OfficerJoined", "");
	
			}
			else
			{
				Log_SetStringToLog(GlobalStringConvert("QUEST_MESSAGE12"));
				DeleteAttribute(Pchar, "quest.FreeRandomOfficerIdx");
				DeleteAttribute(Pchar, "quest.FreeRandomOfficerID");
			}
		break;

		case "LandEnc_OfficerJoined":

			characters[makeint(Pchar.quest.FreeRandomOfficerIdx)].Dialog.CurrentNode = "hired";
			ChangeCharacterAddressGroup(&Characters[makeint(Pchar.quest.HiringOfficerIDX)], "None", "", "");

			PlaceCharacter(characterFromID(Pchar.quest.FreeRandomOfficerID), "goto", Pchar.location);		

			DeleteAttribute(Pchar, "quest.FreeRandomOfficerIdx");
			DeleteAttribute(Pchar, "quest.FreeRandomOfficerID");
			DeleteAttribute(Pchar, "quest.HiringOfficerIDX");			
		break;


		case "LandEnc_OfficerFired":
			RemovePassenger(Pchar, &Characters[makeint(Pchar.quest.FiringOfficerIDX)]);			
			LAi_SetCitizenType(&Characters[makeint(Pchar.quest.FiringOfficerIDX)]);
			Characters[makeint(Pchar.quest.FiringOfficerIDX)].Dialog.CurrentNode = "Fired";
			Characters[makeint(Pchar.quest.FiringOfficerIDX)].location = "none";
			
			DeleteAttribute(Pchar, "quest.FiringOfficerIDX");
		//	DeleteAttribute(Pchar, "quest.FiringOfficerIDX");
		break;


			
	}
}




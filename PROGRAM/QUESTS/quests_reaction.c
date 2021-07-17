bool CreateParticleSystemOnLocator(string _location_id, string _locatorName, string _particleName)
{
	aref locator;
	if (!FindLocator(_location_id, _locatorName, &locator, true))
		return false;

	CreateParticleSystemX(_particleName,stf(locator.x),stf(locator.y),stf(locator.z), stf(locator.vz.x),stf(locator.vz.y),stf(locator.vz.z),0);
	return true;
}

int GenerateNationTrade(int nation)
{
	int i = -1;
	while (i == -1)
	{
		i = rand(MAX_NATIONS - 1);
		if (GetNationRelation2MainCharacter(i) == RELATION_ENEMY || GetNationRelation(nation, i) == RELATION_ENEMY || nation == i || i == PIRATE)
		{
			i = -1;
		}
	}
	return i;
}

void FaceMaker(aref rCharacter)
{
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
		case "Offic_eng":		rCharacter.FaceId = 47; break;
		case "Offic_fra":		rCharacter.FaceId = 48; break;
		case "Offic_hol":		rCharacter.FaceId = 49; break;
		case "Offic_por":		rCharacter.FaceId = 50; break;
		case "Offic_spa":		rCharacter.FaceId = 51; break;

	}
	rCharacter.headModel = "h_" + rCharacter.model;
}

void OfficersReaction(string alignment)
{
	int iPassenger;
	ref PChar;
	PChar = GetMainCharacter();

	for (int io = 0; io<GetPassengersQuantity(pchar); io++)
	{
		iPassenger = GetPassenger(pchar, io);
		if(CheckAttribute(characters[iPassenger], "loyality"))
		{
			if (characters[iPassenger].alignment == alignment)
			{
				characters[iPassenger].loyality = makeint(characters[iPassenger].loyality) + 1;
			}
			else
			{
				characters[iPassenger].loyality = makeint(characters[iPassenger].loyality) - 1;
	
				if(makeint(characters[iPassenger].loyality) < 1)
				{
					string homelocation = pchar.location;
					PlaceCharacter(&characters[iPassenger], "goto", pchar.location);
					characters[iPassenger].selfdialog.filename = characters[iPassenger].dialog.filename;
					characters[iPassenger].selfdialog.currentnode = characters[iPassenger].dialog.currentnode;
					characters[iPassenger].dialog.filename = "anacleto_dialog.c";
					characters[iPassenger].dialog.currentnode = "remove";
					LAi_SetActorType(&characters[iPassenger]);
					LAi_ActorDialog(&characters[iPassenger], pchar, "pchar_back_to_player", 2.0, 1.0);
					LAi_SetStayType(pchar);
				}
			}
		}
	}
}


void GiveItemToTrader(aref ch)
{
	int irand;
	ref PChar;
	PChar = GetMainCharacter();
	
	DeleteAttribute(ch, "items");
	
	TakeNItems(ch,"blade1", Rand(4)+1);
	TakeNItems(ch,"blade2", Rand(4)+1);
	TakeNItems(ch,"blade3", Rand(4)+1);
	TakeNItems(ch,"blade4", Rand(10)+1);
	TakeNItems(ch,"blade5", Rand(4)+1);
		
	irand = rand(2);
	if (irand == 1) { TakeNItems(ch,"blade6", Rand(1)+1);}
	if (irand == 2) { TakeNItems(ch,"blade7", Rand(1)+1);}
	if (irand == 3) { TakeNItems(ch,"blade9", Rand(1)+1);}
	
	if (makeint(pchar.rank) >=8)
	{
		irand = rand(3);
		if (irand == 1) { TakeNItems(ch,"blade10", Rand(1)+1);}
		if (irand == 2) { TakeNItems(ch,"blade13", Rand(1)+1);}
	}
	if (makeint(pchar.rank) >=12)
	{
		irand = rand(4);
		if (irand == 1) { TakeNItems(ch,"blade15", Rand(1)+1);}
		if (irand == 2) { TakeNItems(ch,"blade16", Rand(1)+1);}
	}
	if (makeint(pchar.rank) >= 20)
	{
		irand = rand(5);
		if (irand == 1) { TakeNItems(ch,"blade17", Rand(1)+1);}
		if (irand == 2) { TakeNItems(ch,"blade19", Rand(1)+1);}
	}

	TakeNItems(ch,"pistol1", Rand(3)+1);
	
	if (makeint(pchar.rank) >= 3)
	{
		irand = rand(3);
		if (irand == 1) { TakeNItems(ch,"pistol2", Rand(3)+1);}
	}
	if (makeint(pchar.rank) >= 5)
	{
		irand = rand(3);
		if (irand == 1) { TakeNItems(ch,"pistol3", Rand(3)+1);}
	}
	if (makeint(pchar.rank) >= 7)
	{
		irand = rand(3);
		if (irand == 1) { TakeNItems(ch,"pistol4", Rand(3)+1);}
	}
	if (makeint(pchar.rank) >= 9)
	{
		irand = rand(3);
		if (irand == 1) { TakeNItems(ch,"pistol5", Rand(1)+1);}
	}
	if (makeint(pchar.rank) >= 11)
	{
		irand = rand(3);
		if (irand == 1) { TakeNItems(ch,"pistol6", Rand(1)+1);}
	}

	TakeNItems(ch,"spyglass1", Rand(2)+1);
	
	irand = rand(2);
	if (irand == 1 && makeint(pchar.rank) >=3) { TakeNItems(ch,"spyglass2", Rand(2)+1);}
	irand = rand(4);
	if (irand == 1  && makeint(pchar.rank) >=7) { TakeNItems(ch,"spyglass3", Rand(2)+1);}
	irand = rand(6);
	if (irand == 1 && makeint(pchar.rank) >=10) { TakeNItems(ch,"spyglass4", Rand(2)+1);}

	TakeNItems(ch,"potion1", Rand(20)+1);
	TakeNItems(ch,"potion2", Rand(10)+1);
	TakeNItems(ch,"potion3", Rand(10)+1);
	TakeNItems(ch,"potion4", Rand(5)+1);


	irand = rand(9);
	if (irand == 1) {TakeNItems(ch,"jewelry1", Rand(5)+1);}
	irand = rand(9);
	if (irand == 1) {TakeNItems(ch,"jewelry2", Rand(5)+1);}
	irand = rand(9);
	if (irand == 1) {TakeNItems(ch,"jewelry3", Rand(5)+1);}
	irand = rand(9);
	if (irand == 1) {TakeNItems(ch,"jewelry4", Rand(5)+1);}
	irand = rand(9);
	if (irand == 1) {TakeNItems(ch,"jewelry5", Rand(5)+1);}
	irand = rand(9);
	if (irand == 1) {TakeNItems(ch,"jewelry6", Rand(5)+1);}
	irand = rand(9);
	if (irand == 1) {TakeNItems(ch,"jewelry7", Rand(5)+1);}
	irand = rand(9);
	if (irand == 1) {TakeNItems(ch,"jewelry8", Rand(5)+1);}
	irand = rand(9);
	if (irand == 1) {TakeNItems(ch,"jewelry9", Rand(5)+1);}
	irand = rand(9);
	if (irand == 1) {TakeNItems(ch,"jewelry10", Rand(5)+1);}
	irand = rand(9);
	if (irand == 1) {TakeNItems(ch,"jewelry11", Rand(5)+1);}
	irand = rand(9);
	if (irand == 1) {TakeNItems(ch,"jewelry12", Rand(5)+1);}
	irand = rand(9);
	if (irand == 1) {TakeNItems(ch,"jewelry13", Rand(5)+1);}
	irand = rand(9);
	if (irand == 1) {TakeNItems(ch,"jewelry14", Rand(5)+1);}
	irand = rand(9);
	if (irand == 1) {TakeNItems(ch,"jewelry15", Rand(5)+1);}
	irand = rand(9);
	if (irand == 1) {TakeNItems(ch,"jewelry16", Rand(5)+1);}
	irand = rand(9);
	if (irand == 1) {TakeNItems(ch,"indian1", Rand(5)+1);}
	irand = rand(9);
	if (irand == 1) {TakeNItems(ch,"indian2", Rand(5)+1);}
	irand = rand(9);
	if (irand == 1) {TakeNItems(ch,"indian3", Rand(5)+1);}
	irand = rand(9);
	if (irand == 1) {TakeNItems(ch,"indian4", Rand(5)+1);}
	irand = rand(9);
	if (irand == 1) {TakeNItems(ch,"indian5", Rand(5)+1);}
	irand = rand(9);
	if (irand == 1) {TakeNItems(ch,"indian6", Rand(5)+1);}
	irand = rand(9);
	if (irand == 1) {TakeNItems(ch,"indian7", Rand(5)+1);}
	irand = rand(9);
	if (irand == 1) {TakeNItems(ch,"indian8", Rand(5)+1);}
	irand = rand(9);
	if (irand == 1) {TakeNItems(ch,"indian9", Rand(5)+1);}
	irand = rand(9);
	if (irand == 1) {TakeNItems(ch,"indian10", Rand(5)+1);}
	irand = rand(9);
	if (irand == 1) {TakeNItems(ch,"indian11", Rand(5)+1);}
	irand = rand(9);
	if (irand == 1) {TakeNItems(ch,"indian12", Rand(5)+1);}
	irand = rand(9);
	if (irand == 1) {TakeNItems(ch,"indian13", Rand(5)+1);}
	irand = rand(9);
	if (irand == 1) {TakeNItems(ch,"indian14", Rand(5)+1);}
	irand = rand(9);
	if (irand == 1) {TakeNItems(ch,"indian15", Rand(5)+1);}
	irand = rand(9);
	if (irand == 1) {TakeNItems(ch,"indian16", Rand(5)+1);}
}

string GenerateDestination()
{
	ref PChar;
	PChar = GetMainCharacter();
	
	int destination;
	destination = makeint(rand(5));
	string sdestination = pchar.quest.destination;
	if (destination == 0) 
	{
		if (GetNationRelation2MainCharacter(ENGLAND) != RELATION_ENEMY)
		{
			sdestination = "Redmond";
		}
	}
	if (destination == 1) 
	{
		if (GetNationRelation2MainCharacter(ENGLAND) != RELATION_ENEMY && !CheckAttribute(Pchar, "Quest.Story_OxbayCaptured"))
		{
			sdestination = "Oxbay";
		}
	}
	if (destination == 2) 
	{
		if (GetNationRelation2MainCharacter(SPAIN) != RELATION_ENEMY)
		{
			sdestination = "Isla Muelle";
		}
	}
	if (destination == 3)
	{
		if (GetNationRelation2MainCharacter(PORTUGAL) != RELATION_ENEMY)
		{
			sdestination = "Conceicao";
		}
	}
	if (destination == 4) 
	{
		if (GetNationRelation2MainCharacter(HOLLAND) != RELATION_ENEMY)
		{
			sdestination = "Douwesen";
		}
	}
	if (destination == 5) 
	{
		if (GetNationRelation2MainCharacter(FRANCE) != RELATION_ENEMY)
		{
			sdestination = "Falaise De Fleur";
		}
	}
	return sdestination;
}

void GenerateConvoyQuest()
{
	ref PChar;
	//ref refShip;
	PChar = GetMainCharacter();
	int iShipType, iCargoType, iTradeGoods, iTradeMoney, iNation, irank;
	string sdestination;
	irank = PChar.rank;
	DeleteAttribute(characterFromID("Quest trader"), "Ship");
	
	//AddCharacterGoods(characterFromID("quest trader"), GOOD_BALLS, 600);
	//AddCharacterGoods(characterFromID("quest trader"), GOOD_BOMBS, 600);
	if (irank < 4)
	{
		iShipType = makeint(rand(4))+1;
		characters[GetCharacterIndex("Quest trader")].ship.type = iShipType;
	}
	if (irank >= 4 && irank < 7)
	{
		iShipType = makeint(rand(14))+1;
		characters[GetCharacterIndex("Quest trader")].ship.type = iShipType;
	}
	if (irank >= 7 && irank < 10)
	{
		iShipType = makeint(rand(24))+1;
		characters[GetCharacterIndex("Quest trader")].ship.type = iShipType;
	}
	if (irank >= 10)
	{
		iShipType = makeint(rand(44))+1;
		characters[GetCharacterIndex("Quest trader")].ship.type = iShipType;
	}
	SetRandomNameToShip(characterFromID("Quest trader"));
	SetBaseShipData(characterFromID("Quest trader"));
	
	//makeref(refShip,ShipsTypes[iShipType]);
	//characters[GetCharacterIndex("Quest trader")].ship.hp = refShip.HP;
	//characters[GetCharacterIndex("Quest trader")].ship.sp = refShip.SP;
	//characters[GetCharacterIndex("Quest trader")].ship.crew = refShip.maxcrew;
	
	iTradeGoods = rand(20) + 6;
	iCargoType = GetCharacterFreeSpace(characterFromID("quest trader"), iTradeGoods);
	AddCharacterGoods(characterFromID("quest trader"), iTradeGoods, iCargoType);
	iTradeMoney = ((iCargoType*8+99)/100)*100 + irank*100;
	
	pchar.quest.convoymoney = iTradeMoney;
			
	pchar.quest.generate_convoy_quest.win_condition.l1 = "Timer";
	pchar.quest.generate_convoy_quest.win_condition.l1.date.day = GetAddingDataDay(0, 20, 0);
    	pchar.quest.generate_convoy_quest.win_condition.l1.date.month = GetAddingDataMonth(0, 20, 0);
	pchar.quest.generate_convoy_quest.win_condition.l1.date.year = GetAddingDataYear(0, 20, 0);
	pchar.quest.generate_convoy_quest.win_condition = "generate_convoy_quest";
	pchar.quest.generate_convoy_quest_progress = "begin";
	
	pchar.quest.generate_convoy_quest_failed.win_condition.l1 = "NPC_Death";
	pchar.quest.generate_convoy_quest_failed.win_condition.l1.character = "Quest trader";
	pchar.quest.generate_convoy_quest_failed.win_condition = "generate_convoy_quest_failed";
	
	sdestination = pchar.quest.destination;
	
	sdestination = GenerateDestination();
	
	if (sdestination == pchar.quest.destination)
	{
		sDestination = "Conceicao smugglers";
	}
	
	pchar.quest.destination = sdestination; 	
}

void TavernWaitDate(string date)
{
	int iTime, iAddTime;
	iTime = sti(environment.time);
	if (date == "wait_day")
	{
		if (iTime >= 22) iAddTime = 24 - iTime + 10;
		if (iTime <= 10) iAddTime = 10 - iTime;
		StoreDayUpdate();
	}
	else
	{
		if (iTime < 22) iAddtime = 22 - iTime;
	}
	LAi_Fade("", "");
	WaitDate("",0,0,0,iAddtime,1);
	RecalculateJumpTable();
}

void TavernWaitDate2(string date)
{
	int iTime, iAddTime;
	iTime = sti(environment.time);
	if (date == "wait_day")
	{
		if (iTime >= 22) iAddTime = 24 - iTime + 10;
		if (iTime <= 10) iAddTime = 10 - iTime;
		StoreDayUpdate();
	}
	else
	{
		if (iTime < 22) iAddtime = 22 - iTime;
	}
	WaitDate("",0,0,0,iAddtime,1);
	RecalculateJumpTable();
}

void PlaceCharacter(aref ch, string group, string location)
{
	float locx;
	float locy;
	float locz;
	string homelocator;
	GetCharacterPos(GetMainCharacter(), &locx, &locy, &locz);
	homelocator = LAi_FindNearestFreeLocator(group, locx, locy, locz);
	ChangeCharacterAddressGroup(ch, location, group, homelocator);
}

void QuestComplete(string sQuestName)
{
	ref PChar, sld;
	int iPassenger;
	PChar = GetMainCharacter();
	float locx;
	float locy;
	float locz;
	int iColony;
	int iTradeGoods, iQuantityGoods, iTradeNation;
	string homelocation, homegroup, homelocator, tavernfriend;

	//Log_SetStringToLog("Quest " + sQuestName + " completed");
	//trace("=============================================== QUEST " + sQuestName + " CHECKED");

	switch(sQuestName)
	{
		case "begining":
			Locations[FindLocation("Labirint_3")].models.always.koster = "door";
			Locations[FindLocation("Labirint_3")].models.always.koster.locator.group = "door";
			Locations[FindLocation("Labirint_3")].models.always.koster.locator.name = "door1";
			Locations[FindLocation("Labirint_3")].models.always.koster.tech = "dLightModel";
			
			worldMap.islands.Oxbay.locations.city.label.icon = FRANCE;
			Nations_SetAllFriends();
			
			SetNationRelationBoth(ENGLAND, PIRATE, RELATION_ENEMY);
			SetNationRelationBoth(ENGLAND, FRANCE, RELATION_ENEMY);
			SetNationRelationBoth(PORTUGAL, PIRATE, RELATION_ENEMY);
			SetNationRelationBoth(HOLLAND, PIRATE, RELATION_ENEMY);
			SetNationRelationBoth(FRANCE, PIRATE, RELATION_ENEMY);
			SetNationRelationBoth(SPAIN, PIRATE, RELATION_ENEMY);
			
			SetNationRelation2MainCharacter(PIRATE, RELATION_ENEMY);
			SetNationRelation2MainCharacter(FRANCE, RELATION_ENEMY);
			
			Character_SetAbordageEnable(characterFromID("Barbossa"), false);
			LAi_SetImmortal(characterFromID("Barbossa"), true);
			characters[GetCharacterindex("Barbossa")].ship.hp = 100000;
			
			Locations[FindLocation("Labirint_3")].reload.l28.disable = true;
			Locations[FindLocation("Oxbay_canyon")].reload.l3.disable = true;
			
			Locations[FindLocation("Oxbay_town")].reload.l2.disable = true;
			Locations[FindLocation("Oxbay_town")].reload.l55.disable = true;

			Island_SetReloadEnableLocal("KhaelRoa", "reload_1", false);
			Island_SetReloadEnableLocal("IslaMuelle", "reload_2", false);

			LAi_RemoveLoginTime(characterFromID("Danielle"));
			LAi_RemoveLoginTime(pchar);

			LAi_group_SetRelation("CONCEICAO_SOLDIERS", "CONCEICAO_CITIZENS", LAI_GROUP_FRIEND);
			LAi_group_SetRelation("CONCEICAO_SOLDIERS", "CONCEICAO_SOLDIERS", LAI_GROUP_FRIEND);
			LAi_group_SetRelation("CONCEICAO_SOLDIERS", LAI_DEFAULT_GROUP, LAI_GROUP_FRIEND);
			LAi_group_SetAlarmReaction("CONCEICAO_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY, LAI_GROUP_FRIEND);
			LAi_group_SetAlarmReaction("CONCEICAO_SOLDIERS", "CONCEICAO_CITIZENS", LAI_GROUP_FRIEND, LAI_GROUP_FRIEND);
			LAi_group_SetLookRadius("CONCEICAO_SOLDIERS", LAI_GROUP_GRD_LOOK);
			LAi_group_SetHearRadius("CONCEICAO_SOLDIERS", LAI_GROUP_GRD_HEAR);
			LAi_group_SetSayRadius("CONCEICAO_SOLDIERS", LAI_GROUP_GRD_SAY);
			LAi_group_SetPriority("CONCEICAO_CITIZENS", LAI_GROUP_PCITIZENS);
			LAi_group_SetPriority("CONCEICAO_SOLDIERS", LAI_GROUP_PGUARDS);

			LAi_group_SetLookRadius("CONCEICAO_CITIZENS", LAI_GROUP_DEF_LOOK);
			LAi_group_SetHearRadius("CONCEICAO_CITIZENS", LAI_GROUP_DEF_HEAR);
			LAi_group_SetSayRadius("CONCEICAO_CITIZENS", LAI_GROUP_DEF_SAY);

			LAi_group_SetAlarmReaction("SMUGGLERS_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY, LAI_GROUP_FRIEND);
			LAi_group_SetRelation("SMUGGLERS_SOLDIERS", "SMUGGLERS_SOLDIERS", LAI_GROUP_FRIEND);
			LAi_group_SetRelation("SMUGGLERS_CITIZENS", "SMUGGLERS_SOLDIERS", LAI_GROUP_FRIEND);
			LAi_group_SetRelation("SMUGGLERS_SOLDIERS", LAI_DEFAULT_GROUP, LAI_GROUP_FRIEND);
			LAi_group_SetLookRadius("SMUGGLERS_SOLDIERS", LAI_GROUP_GRD_LOOK);
			LAi_group_SetHearRadius("SMUGGLERS_SOLDIERS", LAI_GROUP_GRD_HEAR);
			LAi_group_SetSayRadius("SMUGGLERS_SOLDIERS", LAI_GROUP_GRD_SAY);
			LAi_group_SetAlarmReaction("SMUGGLERS_SOLDIERS", "SMUGGLERS_CITIZENS", LAI_GROUP_FRIEND, LAI_GROUP_FRIEND);
			LAi_group_SetPriority("SMUGGLERS_CITIZENS", LAI_GROUP_PCITIZENS);
			LAi_group_SetPriority("SMUGGLERS_SOLDIERS", LAI_GROUP_PGUARDS);

			LAi_group_SetLookRadius("SMUGGLERS_CITIZENS", LAI_GROUP_DEF_LOOK);
			LAi_group_SetHearRadius("SMUGGLERS_CITIZENS", LAI_GROUP_DEF_HEAR);
			LAi_group_SetSayRadius("SMUGGLERS_CITIZENS", LAI_GROUP_DEF_SAY);
			
			LAi_group_SetAlarmReaction("DOUWESEN_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY, LAI_GROUP_FRIEND);
			LAi_group_SetRelation("DOUWESEN_CITIZENS", "DOUWESEN_SOLDIERS", LAI_GROUP_FRIEND);
			LAi_group_SetRelation("DOUWESEN_SOLDIERS", "DOUWESEN_SOLDIERS", LAI_GROUP_FRIEND);
			LAi_group_SetRelation("DOUWESEN_SOLDIERS", LAI_DEFAULT_GROUP, LAI_GROUP_FRIEND);
			LAi_group_SetLookRadius("DOUWESEN_SOLDIERS", LAI_GROUP_GRD_LOOK);
			LAi_group_SetHearRadius("DOUWESEN_SOLDIERS", LAI_GROUP_GRD_HEAR);
			LAi_group_SetSayRadius("DOUWESEN_SOLDIERS", LAI_GROUP_GRD_SAY);
			LAi_group_SetAlarmReaction("DOUWESEN_SOLDIERS", "DOUWESEN_CITIZENS", LAI_GROUP_FRIEND, LAI_GROUP_FRIEND);
			LAi_group_SetPriority("DOUWESEN_CITIZENS", LAI_GROUP_PCITIZENS);
			LAi_group_SetPriority("DOUWESEN_SOLDIERS", LAI_GROUP_PGUARDS);

			LAi_group_SetLookRadius("DOUWESEN_SOLDIERS", LAI_GROUP_DEF_LOOK);
			LAi_group_SetHearRadius("DOUWESEN_SOLDIERS", LAI_GROUP_DEF_HEAR);
			LAi_group_SetSayRadius("DOUWESEN_SOLDIERS", LAI_GROUP_DEF_SAY);

			LAi_group_SetAlarmReaction("DOUWESEN_PIRATE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY, LAI_GROUP_FRIEND);
			LAi_group_SetRelation("DOUWESEN_PIRATE_SOLDIERS", "DOUWESEN_PIRATE_SOLDIERS", LAI_GROUP_FRIEND);
			LAi_group_SetRelation("DOUWESEN_PIRATE_CITIZENS", "DOUWESEN_PIRATE_SOLDIERS", LAI_GROUP_FRIEND);
			LAi_group_SetRelation("DOUWESEN_PIRATE_SOLDIERS", LAI_DEFAULT_GROUP, LAI_GROUP_FRIEND);
			LAi_group_SetLookRadius("DOUWESEN_PIRATE_SOLDIERS", LAI_GROUP_GRD_LOOK);
			LAi_group_SetHearRadius("DOUWESEN_PIRATE_SOLDIERS", LAI_GROUP_GRD_HEAR);
			LAi_group_SetSayRadius("DOUWESEN_PIRATE_SOLDIERS", LAI_GROUP_GRD_SAY);
			LAi_group_SetAlarmReaction("DOUWESEN_PIRATE_SOLDIERS", "DOUWESEN_PIRATE_CITIZENS", LAI_GROUP_FRIEND, LAI_GROUP_FRIEND);
			LAi_group_SetPriority("DOUWESEN_PIRATE_CITIZENS", LAI_GROUP_PCITIZENS);
			LAi_group_SetPriority("DOUWESEN_PIRATE_SOLDIERS", LAI_GROUP_PGUARDS);

			LAi_group_SetLookRadius("DOUWESEN_PIRATE_CITIZENS", LAI_GROUP_DEF_LOOK);
			LAi_group_SetHearRadius("DOUWESEN_PIRATE_CITIZENS", LAI_GROUP_DEF_HEAR);
			LAi_group_SetSayRadius("DOUWESEN_PIRATE_CITIZENS", LAI_GROUP_DEF_SAY);

			LAi_group_SetAlarmReaction("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY, LAI_GROUP_FRIEND);
			LAi_group_SetRelation("FRANCE_CITIZENS", "FRANCE_SOLDIERS", LAI_GROUP_FRIEND);
			LAi_group_SetRelation("FRANCE_SOLDIERS", "FRANCE_SOLDIERS", LAI_GROUP_FRIEND);
			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_DEFAULT_GROUP, LAI_GROUP_FRIEND);
			LAi_group_SetLookRadius("FRANCE_SOLDIERS", LAI_GROUP_GRD_LOOK);
			LAi_group_SetHearRadius("FRANCE_SOLDIERS", LAI_GROUP_GRD_HEAR);
			LAi_group_SetSayRadius("FRANCE_SOLDIERS", LAI_GROUP_GRD_SAY);
			LAi_group_SetAlarmReaction("FRANCE_SOLDIERS", "FRANCE_CITIZENS", LAI_GROUP_FRIEND, LAI_GROUP_FRIEND);
			LAi_group_SetPriority("FRANCE_CITIZENS", LAI_GROUP_PCITIZENS);
			LAi_group_SetPriority("FRANCE_SOLDIERS", LAI_GROUP_PGUARDS);

			LAi_group_SetLookRadius("FRANCE_CITIZENS", LAI_GROUP_DEF_LOOK);
			LAi_group_SetHearRadius("FRANCE_CITIZENS", LAI_GROUP_DEF_HEAR);
			LAi_group_SetSayRadius("FRANCE_CITIZENS", LAI_GROUP_DEF_SAY);

			LAi_group_SetAlarmReaction("SPAIN_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY, LAI_GROUP_FRIEND);
			LAi_group_SetRelation("SPAIN_CITIZENS", "SPAIN_SOLDIERS", LAI_GROUP_FRIEND);
			LAi_group_SetRelation("SPAIN_SOLDIERS", "SPAIN_SOLDIERS", LAI_GROUP_FRIEND);
			LAi_group_SetRelation("SPAIN_SOLDIERS", LAI_DEFAULT_GROUP, LAI_GROUP_FRIEND);
			LAi_group_SetLookRadius("SPAIN_SOLDIERS", LAI_GROUP_GRD_LOOK);
			LAi_group_SetHearRadius("SPAIN_SOLDIERS", LAI_GROUP_GRD_HEAR);
			LAi_group_SetSayRadius("SPAIN_SOLDIERS", LAI_GROUP_GRD_SAY);
			LAi_group_SetAlarmReaction("SPAIN_SOLDIERS", "SPAIN_CITIZENS", LAI_GROUP_FRIEND, LAI_GROUP_FRIEND);
			LAi_group_SetPriority("SPAIN_CITIZENS", LAI_GROUP_PCITIZENS);
			LAi_group_SetPriority("SPAIN_SOLDIERS", LAI_GROUP_PGUARDS);

			LAi_group_SetLookRadius("SPAIN_CITIZENS", LAI_GROUP_DEF_LOOK);
			LAi_group_SetHearRadius("SPAIN_CITIZENS", LAI_GROUP_DEF_HEAR);
			LAi_group_SetSayRadius("SPAIN_CITIZENS", LAI_GROUP_DEF_SAY);

			LAi_group_SetAlarmReaction("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY, LAI_GROUP_FRIEND);
			LAi_group_SetRelation("ENGLAND_CITIZENS", "ENGLAND_SOLDIERS", LAI_GROUP_FRIEND);
			LAi_group_SetRelation("ENGLAND_SOLDIERS", "ENGLAND_SOLDIERS", LAI_GROUP_FRIEND);
			LAi_group_SetRelation("ENGLAND_SOLDIERS", LAI_DEFAULT_GROUP, LAI_GROUP_FRIEND);
			LAi_group_SetLookRadius("ENGLAND_SOLDIERS", LAI_GROUP_GRD_LOOK);
			LAi_group_SetHearRadius("ENGLAND_SOLDIERS", LAI_GROUP_GRD_HEAR);
			LAi_group_SetSayRadius("ENGLAND_SOLDIERS", LAI_GROUP_GRD_SAY);
			LAi_group_SetAlarmReaction("ENGLAND_SOLDIERS", "ENGLAND_CITIZENS", LAI_GROUP_FRIEND, LAI_GROUP_FRIEND);
			LAi_group_SetPriority("ENGLAND_CITIZENS", LAI_GROUP_PCITIZENS);
			LAi_group_SetPriority("ENGLAND_SOLDIERS", LAI_GROUP_PGUARDS);

			LAi_group_SetLookRadius("ENGLAND_CITIZENS", LAI_GROUP_DEF_LOOK);
			LAi_group_SetHearRadius("ENGLAND_CITIZENS", LAI_GROUP_DEF_HEAR);
			LAi_group_SetSayRadius("ENGLAND_CITIZENS", LAI_GROUP_DEF_SAY);

			LAi_group_SetAlarmReaction("QC_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY, LAI_GROUP_FRIEND);
			LAi_group_SetRelation("QC_CITIZENS", "QC_SOLDIERS", LAI_GROUP_FRIEND);
			LAi_group_SetRelation("QC_SOLDIERS", "QC_SOLDIERS", LAI_GROUP_FRIEND);
			LAi_group_SetRelation("QC_SOLDIERS", LAI_DEFAULT_GROUP, LAI_GROUP_FRIEND);
			LAi_group_SetLookRadius("QC_SOLDIERS", LAI_GROUP_GRD_LOOK);
			LAi_group_SetHearRadius("QC_SOLDIERS", LAI_GROUP_GRD_HEAR);
			LAi_group_SetSayRadius("QC_SOLDIERS", LAI_GROUP_GRD_SAY);
			LAi_group_SetAlarmReaction("QC_SOLDIERS", "QC_CITIZENS", LAI_GROUP_FRIEND, LAI_GROUP_FRIEND);
			LAi_group_SetPriority("QC_CITIZENS", LAI_GROUP_PCITIZENS);
			LAi_group_SetPriority("QC_SOLDIERS", LAI_GROUP_PGUARDS);

			LAi_group_SetLookRadius("QC_CITIZENS", LAI_GROUP_DEF_LOOK);
			LAi_group_SetHearRadius("QC_CITIZENS", LAI_GROUP_DEF_HEAR);
			LAi_group_SetSayRadius("QC_CITIZENS", LAI_GROUP_DEF_SAY);

			LAi_group_SetAlarmReaction("ANIMIST_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY, LAI_GROUP_ENEMY);
			LAi_group_SetRelation("ANIMIST_SOLDIERS", "ANIMIST_SOLDIERS", LAI_GROUP_FRIEND);
			LAi_group_SetLookRadius("ANIMIST_SOLDIERS", LAI_GROUP_GRD_LOOK);
			LAi_group_SetHearRadius("ANIMIST_SOLDIERS", LAI_GROUP_GRD_HEAR);
			LAi_group_SetSayRadius("ANIMIST_SOLDIERS", LAI_GROUP_GRD_SAY);
			LAi_group_SetPriority("ANIMIST_SOLDIERS", LAI_GROUP_PGUARDS);

			pchar.quest.Story_LeavingOxbay.win_condition.l1 = "location";
			pchar.quest.Story_LeavingOxbay.win_condition.l1.location = "Oxbay";
			pchar.quest.Story_LeavingOxbay.win_condition = "Story_leavingOxbay";
			LAi_SetImmortal(characterFromID("FalaiseDeFleur Commander"), true);

			LAi_LocationMonstersGen(&locations[FindLocation("Oxbay_town_exit")], false);

			pchar.quest.becomes_oldman.win_condition.l1 = "Timer";
			pchar.quest.becomes_oldman.win_condition.l1.date.day = 1;
			pchar.quest.becomes_oldman.win_condition.l1.date.month = 1;
			pchar.quest.becomes_oldman.win_condition.l1.date.year = 1650;
			pchar.quest.becomes_oldman.win_condition = "becomes_oldman";
		break;
		
		//Персонаж покидает Оксбэй в первый раз - включение первого сюжетного ролика
		case "Story_leavingOxbay":
			SetNationRelation2MainCharacter(FRANCE, RELATION_ENEMY);
			Locations[FindLocation("Oxbay_town_exit")].locators_radius.goto.citizen08 = 12.0;
			Locations[FindLocation("Falaise_De_Fleur_location_03")].reload.l3.disable = 1;
			//включаем корабль одного из офицеров.
			//setCharacterShipLocation(characterFromID("Clair Larrouse"), "Muelle_port");
			//Установка атрибута для проверки захваченности Оксбэя
			PChar.Quest.Story_OxbayCaptured = "1";
			//Смена национальности форта Оксбэя
			Characters[GetCharacterIndex("Oxbay Commander")].nation = FRANCE;
			Characters[GetCharacterIndex("Oxbay Commander")].model = "Soldier_fra";
			LAi_SetImmortal(characterFromID("Oxbay Commander"), true);
			//Смена английских солдат в Оксбэе на французских
			//Удаление английских
			ChangeCharacterAddress(characterFromID("Ox_Soldier_1"), "None", "");
			ChangeCharacterAddress(characterFromID("Ox_Soldier_2"), "None", "");
			ChangeCharacterAddress(characterFromID("Ox_Soldier_3"), "None", "");
			ChangeCharacterAddress(characterFromID("Ox_Soldier_4"), "None", "");
			ChangeCharacterAddress(characterFromID("Ox_Soldier_5"), "None", "");
			ChangeCharacterAddress(characterFromID("Ox_Soldier_6"), "None", "");
			ChangeCharacterAddress(characterFromID("Ox_Soldier_7"), "None", "");
			ChangeCharacterAddress(characterFromID("Ox_Soldier_8"), "None", "");
			ChangeCharacterAddress(characterFromID("Ox_Patrol_1"), "None", "");
			ChangeCharacterAddress(characterFromID("Ox_Patrol_2"), "None", "");
			ChangeCharacterAddress(characterFromID("Ox_Patrol_3"), "None", "");
			ChangeCharacterAddress(characterFromID("Ox_Patrol_4"), "None", "");
			//Постановка французских
			ChangeCharacterAddress(characterFromID("Fra_occupant_01"), "Oxbay_town", "goto3");
			ChangeCharacterAddress(characterFromID("Fra_occupant_02"), "Oxbay_town", "goto4");
			ChangeCharacterAddress(characterFromID("Fra_occupant_03"), "Oxbay_town", "goto1");
			ChangeCharacterAddress(characterFromID("Fra_occupant_04"), "Oxbay_town", "goto2");
			ChangeCharacterAddress(characterFromID("Fra_occupant_05"), "Oxbay_port", "goto20");
			ChangeCharacterAddress(characterFromID("Fra_occupant_06"), "Oxbay_port", "goto21");
			ChangeCharacterAddress(characterFromID("Fra_occupant_07"), "Oxbay_town_exit", "citizen09");
			ChangeCharacterAddress(characterFromID("Fra_occupant_08"), "Oxbay_town_exit", "citizen010");
			ChangeCharacterAddress(characterFromID("Occ_Patrol_1"), "Oxbay_port", "goto18");
			ChangeCharacterAddress(characterFromID("Occ_Patrol_2"), "Oxbay_port", "goto12");
			ChangeCharacterAddress(characterFromID("Occ_Patrol_3"), "Oxbay_town", "goto31");
			ChangeCharacterAddress(characterFromID("Occ_Patrol_4"), "Oxbay_town", "goto20");
			
			//Постановка в гавань Оксбэя кораблей французской эскадры
			SetCrewQuantity(characterFromID("Remy Gatien"), 650);
			SetCrewQuantity(characterFromID("Yves Giner"), 400);
			SetCrewQuantity(characterFromID("Begon Monchaty"), 400);
			
			Character_SetAbordageEnable(characterFromID("Remy Gatien"), false);
			Character_SetAbordageEnable(characterFromID("Yves Giner"), false);
			Character_SetAbordageEnable(characterFromID("Begon Monchaty"), false);
			
			Group_CreateGroup("Story_French_Squadron");
			Group_AddCharacter("Story_French_Squadron", "Remy Gatien");
			Group_AddCharacter("Story_French_Squadron", "Yves Giner");
			Group_AddCharacter("Story_French_Squadron", "Begon Monchaty");
			Group_SetGroupCommander("Story_French_Squadron", "Remy Gatien");
			Group_SetAddress("Story_French_Squadron", "Oxbay", "Quest_Ships","Quest_Ship_7");
			
			//Заведение квеста на диалог с солдатами у входа в город Оксбэй с острова
			Pchar.quest.Story_FraSoldiers_attack_in_jungles.win_condition.l1 = "location";
			Pchar.quest.Story_FraSoldiers_attack_in_jungles.win_condition.l1.location = "Oxbay_town_exit";
			Pchar.quest.Story_FraSoldiers_attack_in_jungles.win_condition = "Story_FraSoldiers_attack_in_jungles";
			locations[FindLocation("Oxbay_town_exit")].disableencounters = 1;
	
			//Перемещение Реймса в резиденцию губернатора
			ChangeCharacterAddress(characterFromID("Raoul Rheims"), "Redmond_residence", "goto1");
		
			//Заведение квеста на встречу с Реймсом в резиденции губернатора и уход Реймса
			Pchar.quest.Story_First_Meeting_with_Rheims.win_condition.l1 = "location";
			Pchar.quest.Story_First_Meeting_with_Rheims.win_condition.l1.location = "redmond_residence";
			Pchar.quest.Story_First_Meeting_with_Rheims.win_condition = "Story_First_Meeting_with_Rheims";

			//заведение квеста на диалог со стражником
			pchar.quest.first_time_to_redmond_townhall.win_condition.l1 = "locator";
			pchar.quest.first_time_to_redmond_townhall.win_condition.l1.location = "Redmond_town_01";
			pchar.quest.first_time_to_redmond_townhall.win_condition.l1.locator_group = "goto";
			pchar.quest.first_time_to_redmond_townhall.win_condition.l1.locator = "goto10";
			pchar.quest.first_time_to_redmond_townhall.win_condition = "first_time_to_redmond_townhall_complete";

			Locations[FindLocation("Redmond_town_01")].locators_radius.goto.goto10 = 2.0;

			DeleteQuestHeader("Tutorial_SpyGlass");
			DeleteQuestHeader("Tutorial_Store");
			DeleteQuestHeader("Tutorial_Shipyard");
			DeleteQuestHeader("Tutorial_Tavern");

			Pchar.quest.Tut_SellGoods.over = "yes";
			Pchar.quest.Tut_RepairShip.over = "yes";
			Pchar.quest.Tut_HireCrew.over = "yes";
			Pchar.quest.Tut_BuySpyGlass.over = "yes";
			DeleteAttribute(Pchar, "quest.tutorial.Spyglass");
			
			//Добавление записи в журнал
			SetQuestHeader("Story_OxbayCaptured");
			AddQuestRecord("Story_OxbayCaptured", "1");
			PostVideoAndQuest("Invasion",500,"Story_MapLoadAfterleavingOxbay");
			bSkipSeaLogin = true;
			Locations[FindLocation("Oxbay_town")].reload.l2.disable = false;
			Locations[FindLocation("Oxbay_town")].reload.l55.disable = false;
		break;

		case "Story_MapLoadAfterleavingOxbay":
			Sea_MapLoadXZ_AY(-1871.555, 880.81, -1.58);
			AddQuestRecord("Story_OxbayCaptured", "1");
			Locations[FindLocation("Redmond_Residence")].reload.l1.disable = 1;
		break;

		case "first_time_to_redmond_townhall_complete":
			LAi_SetActorType(characterFromID("Eng_soldier_5"));
			characters[GetCharacterIndex("Eng_soldier_5")].dialog.currentnode = "who_you_blaze";
			LAi_ActorDialogNow(characterFromID("Eng_soldier_5"), pchar, "first_time_to_redmond_townhall_complete_2", -1);
		break;

		case "first_time_to_redmond_townhall_complete_2":
			LAi_SetGuardianType(characterFromID("Eng_soldier_5"));
			LAi_group_MoveCharacter(characterFromID("Eng_soldier_5"), "ENGLAND_SOLDIERS");
		break;

		//При заходе игрока в резиденцию Редмонда Реймс покидает ее
		case "Story_First_Meeting_with_Rheims": 
			pchar.quest.first_time_to_redmond_townhall.over = "yes";
			LAi_SetActorType(Pchar);
			LAi_SetActorType(characterFromID("Raoul Rheims"));
			//Выставление Реймсу нужной ноды
			Characters[GetCharacterIndex("Raoul Rheims")].Dialog.CurrentNode = "First_meeting";
			LAi_ActorFollow(pchar, characterFromID("Raoul Rheims"), "", 1.0);
			LAi_ActorFollow(characterFromID("Raoul Rheims"), pchar, "Story_First_Meeting_with_Rheims_2", 1.0);
		break;
		
		case "Story_First_Meeting_with_Rheims_2":
			//----------------Реймс подходит и просит его пропустить!
			LAi_ActorWaitDialog(Pchar, characterFromID("Raoul Rheims"));
			LAi_ActorDialog(characterFromID("Raoul Rheims"), Pchar, "", 5.0, 0);
		break;

		case "Rheims_away_from_residence":
			Locations[FindLocation("Redmond_Residence")].reload.l1.disable = 0;
			//----------------Отправляем игрока в соседний локатор, чтобы он не мешал Реймсу выйти
			LAi_ActorGoToLocator(PChar, "goto", "goto7", "", 4.0);
			//----------------Отправляем Реймса в локатор
			LAi_ActorGoToLocator(CharacterFromID("Raoul Rheims"), "Reload", "reload1", "Story_Rheims_leaves", 2.0);
		break;

		case "Story_Rheims_leaves": 
			//------------Реймс телепортируется в никуда
			ChangeCharacterAddress(characterFromID("Raoul Rheims"), "None", "");
			LAi_SetPlayerType(pchar);
		break;

		case "silehard_Story_Oxbay_Captured_15":
			PChar.Quest.Story_1stTaskReceived = "1";
			CloseQuestHeader("Story_OxbayCaptured");
			SetQuestHeader("Story_1stTaskReceived");
			AddQuestRecord("Story_1stTaskReceived","1");
			Pchar.quest.Story_1stTaskPayment = "10000";
			ChangeCharacterAddressGroup(characterFromID("Valentin Massoni"), "Oxbay_tavern", "Sit", "Sit5");
			LAi_SetSitType(characterFromID("Valentin Massoni"));
			AddPartyExp(pchar, 1500);
		break;

		case "Story_SitAndDrinkWithMassoni":
			LAi_Fade("Story_SitAndDrinkWithMassoni_2", "Story_MassoniStartTalkingInTavern");
		break;

		case "Story_SitAndDrinkWithMassoni_2":
			LAi_SetActorType(pchar);
			LAi_ActorSetSitMode(pchar);
			ChangeCharacterAddressGroup(pchar, "Oxbay_tavern", "sit", "sit4");
		break

		case "Story_MassoniStartTalkingInTavern":
			SetCurrentTime(23, 0);
			LAi_NoRebirthDisable(characterFromID("Fra_occupant_07"));
			LAi_NoRebirthDisable(characterFromID("Fra_occupant_08"));
			//Уничтожаем квест на атаку солдат в джунглях
			PChar.Quest.Story_FraSoldiers_attack_in_jungles.over = "yes";

			Locations[FindLocation("Oxbay_town")].reload.l1.disable = 1;
			LAi_ActorDialogNow(Pchar, characterFromID("Valentin Massoni"), "", -1);
			characters[getCharacterIndex("Fra_Occupant_01")].Dialog.Filename = "Story_French Occupant_2_dialog.c";
			characters[getCharacterIndex("Fra_Occupant_02")].Dialog.Filename = "Story_French Occupant_2_dialog.c";
		break;

		case "Story_Massony_Reload_to_Town":
			//Смена Диалога Стражникам на воротах
			Characters[GetCharacterIndex("Fra_Occupant_03")].Dialog.Filename = "Story_French Occupant_2_dialog.c";
			Characters[GetCharacterIndex("Fra_Occupant_04")].Dialog.Filename = "Story_French Occupant_2_dialog.c";
			//Установки им всем временного бессмертия
			LAi_SetImmortal(characterFromID("Fra_Occupant_03"), true);
			LAi_SetImmortal(characterFromID("Fra_Occupant_04"), true);
			LAi_SetImmortal(characterFromID("Valentin Massoni"), true);
			LAi_SetStayType(pchar);
			//Смена типа Валентину Массони			
			LAi_SetActorType(characterFromID("Valentin Massoni"));

			//Перемещение Массони и Блэйза к выходу из Оксбэя
			ChangeCharacterAddress(characterFromID("Valentin Massoni"), "Oxbay_town", "goto36");
			DoQuestReloadToLocation("Oxbay_town", "goto", "goto37", "Story_Check_Blaze_And_Massoni");
		break;

		//Массони отправляется к локатору релоада, чтобы выйти из города.
		case "Story_Massoni_leave_Oxbay":
			//Массони перегружается в выход из Оксбэя
			ChangeCharacterAddress(characterFromID("Valentin Massoni"), "Oxbay_town_exit", "Citizen08");
		break;

		case "Story_Check_Blaze_And_Massoni":
			Locations[FindLocation("Oxbay_town_exit")].reload.l1.disable = true;
			Locations[FindLocation("Oxbay_town_exit")].reload.l2.disable = true;
			Locations[FindLocation("Oxbay_town_exit")].reload.l3.disable = true;
			Locations[FindLocation("Oxbay_town_exit")].reload.l4.disable = true;
			Locations[FindLocation("Oxbay_town_exit")].reload.l5.disable = true;

			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Fra_occupant_01"));
			LAi_ActorFollow(pchar, characterFromID("Fra_occupant_01"), "", 2.0);
			LAi_ActorFollow(characterFromID("Fra_occupant_01"), pchar, "Story_Check_Blaze_And_Massoni_2", 2.0);
		break;
		
		case "Story_Check_Blaze_And_Massoni_2":
			LAi_type_actor_Reset(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("Fra_occupant_01"));
			LAi_ActorDialog(characterFromID("Fra_occupant_01"), Pchar, "massoni_answer_to_soldier", 3.0, 0);
		break;

		case "massoni_answer_to_soldier":
			Locations[FindLocation("Oxbay_town_exit")].locators_radius.goto.citizen08 = 1.0;
			characters[getCharacterIndex("Valentin Massoni")].dialog.currentnode="Talk_to_Soldiers";
			LAi_ActorWaitDialog(pchar, characterFromID("valentin massoni"));
			LAi_ActorDialog(characterFromID("valentin massoni"), Pchar, "prepare_FRANCE_SOLDIERS_return_to_post", 50, 0);
		break;

		case "prepare_FRANCE_SOLDIERS_return_to_post":
			pchar.quest.massoni_died.win_condition.l1 = "NPC_Death";
			pchar.quest.massoni_died.win_condition.l1.character = "Valentin Massoni";
			pchar.quest.massoni_died.win_condition = "massoni_died";
			
			LAi_SetPlayerType(pchar);
			//Игрок покидает город вслед за Массони
			Pchar.quest.Story_Walk_Away_with_Massoni.win_condition.l1 = "location";
			Pchar.quest.Story_Walk_Away_with_Massoni.win_condition.l1.location = "Oxbay_town_exit";
			Pchar.quest.Story_Walk_Away_with_Massoni.win_condition = "Story_Walk_Away_with_Massoni";

			//Массони уходит в ворота Оксбэя
			LAi_ActorGoToLocator(characterFromID("Valentin Massoni"), "reload", "reload12", "Story_Massoni_leave_Oxbay", 5.0);
			LAi_SetImmortal(characterFromID("Fra_Occupant_01"), false);
			LAi_SetImmortal(characterFromID("Fra_Occupant_02"), false);
			//Солдаты возвращаются на свои места
			LAi_ActorGoToLocator(characterFromID("Fra_Occupant_01"), "goto", "goto3", "Story_Fra_Occupant_01_ReturnedToPost", 3.0);
			//Увеличиваем радуис детекторного локатора
			Locations[FindLocation("Oxbay_town_exit")].locators_radius.goto.citizen018 = 2.0;
			Locations[FindLocation("Oxbay_town_exit")].locators_radius.goto.citizen05 = 3.0;
			//Устанавливается диалог для Массони
			Characters[GetCharacterIndex("Valentin Massoni")].Dialog.CurrentNode = "What_are_you_waiting_for";
			//Смена Диалога Стражникам на воротах
			Characters[GetCharacterIndex("Fra_Occupant_01")].Dialog.Filename = "Story_French Occupant_dialog.c";
			Characters[GetCharacterIndex("Fra_Occupant_02")].Dialog.Filename = "Story_French Occupant_dialog.c";
			Characters[GetCharacterIndex("Fra_Occupant_07")].Dialog.Filename = "Story_Fra_Occup_common_dialog.c";
			Characters[GetCharacterIndex("Fra_Occupant_08")].Dialog.Filename = "Story_Fra_Occup_common_dialog.c";
		break;

		case "Story_Fra_Occupant_01_ReturnedToPost":
			LAi_ActorTurnByLocator(characterFromID("Fra_Occupant_01"), "goto", "goto3");
			LAi_SetGuardianType(characterFromID("Fra_Occupant_01"));
			LAi_group_MoveCharacter(characterFromID("Fra_occupant_01"), "FRANCE_SOLDIERS");
		break;

		//игрок выходит в джунгли вслед за Массони
		case "Story_Walk_Away_with_Massoni":
			LAi_SetImmortal(characterFromID("Fra_Occupant_03"), false);
			LAi_SetImmortal(characterFromID("Fra_Occupant_04"), false);
			ChangeCharacterAddress(characterFromID("Valentin Massoni"), "Oxbay_town_exit", "Citizen08");
			
			LAi_SetImmortal(characterFromID("Valentin Massoni"), false);
			LAi_SetCheckMinHP(characterFromID("Valentin Massoni"), 79.9, false, "Massoni_doomed");

			LAi_type_actor_Reset(characterFromID("Valentin Massoni"));

			LAi_ActorGoToLocator(characterFromID("Valentin Massoni"), "Goto", "citizen018", "Story_Massoni_go_walking", 50.0);
			LAi_SetGuardianType(characterFromID("Fra_occupant_07"));
			LAi_group_MoveCharacter(characterFromID("Fra_occupant_07"), "FRANCE_SOLDIERS");
			LAi_SetGuardianType(characterFromID("Fra_occupant_08"));
			LAi_group_MoveCharacter(characterFromID("Fra_occupant_08"), "FRANCE_SOLDIERS");

			LAi_group_MoveCharacter(characterFromID("Valentin Massoni"), "FRANCE_SOLDIERS");
			LAi_group_SetHearRadius("FRANCE_SOLDIERS", 100.0);
		break;

		case "massoni_died":
			Locations[FindLocation("Oxbay_town_exit")].reload.l1.disable = false;
			Locations[FindLocation("Oxbay_town_exit")].reload.l2.disable = false;
			Locations[FindLocation("Oxbay_town_exit")].reload.l3.disable = false;
			Locations[FindLocation("Oxbay_town_exit")].reload.l4.disable = false;
			Locations[FindLocation("Oxbay_town_exit")].reload.l5.disable = false;

			GiveItem2Character(Pchar, "Massoni_papers");
			AddQuestRecord("Story_1stTaskReceived", "13");
			
			Pchar.quest.Story_Massoni_order_attack_Blaze_denied.win_condition.l1 = "ExitFromLocation";
			Pchar.quest.Story_Massoni_order_attack_Blaze_denied.win_condition.l1.location = "Oxbay_town_exit";
			Pchar.quest.Story_Massoni_order_attack_Blaze_denied.win_condition = "Story_Massoni_order_attack_Blaze_denied";
		break;

		//Игрок и пьяный Массони идут в джунглях, и дойдя до локатора, массони начинает диалог
		case "Story_Massoni_go_walking":
			LAi_ActorDialog(characterFromID("Valentin Massoni"), Pchar, "", 20.0, 1.0);
		break;

		case "Massony_run_to_last_locator":
			LAi_ActorGoToLocator(characterFromID("Valentin Massoni"), "goto", "citizen05", "Story_Massoni_found_Cheating", 20.0);
		break;

		//игрок доходит до локатора где Массони отказывается идти дальше
		case "Story_Massoni_found_Cheating":
			Characters[GetCharacterIndex("Valentin Massoni")].Dialog.CurrentNode = "Final_talk";
			PChar.quest.Story_Massoni_go_walking.over = "yes";
			LAi_ActorTurnToCharacter(characterFromID("Valentin Massoni"), PChar);
			Locations[FindLocation("Oxbay_town")].reload.l1.disable = 0;
			LAi_ActorDialog(characterFromID("Valentin Massoni"), Pchar, "", 20.0, 1.0);
		break;

		case "Massoni_spared":
			Locations[FindLocation("Oxbay_town_exit")].reload.l1.disable = false;
			Locations[FindLocation("Oxbay_town_exit")].reload.l2.disable = false;
			Locations[FindLocation("Oxbay_town_exit")].reload.l3.disable = false;
			Locations[FindLocation("Oxbay_town_exit")].reload.l4.disable = false;
			Locations[FindLocation("Oxbay_town_exit")].reload.l5.disable = false;
			//Массони бежит к городу
			pchar.quest.massoni_died.over = "yes";
			LAi_ActorRunToLocator(characterFromID("Valentin Massoni"), "reload", "reload3", "Story_Massoni_order_attack_Blaze", 30.0);
			Pchar.quest.Story_1stTaskComplete = 1;
			ChangeCharacterAddress(characterFromID("Faust Gasquet"), "Falaise_de_fleur_port_01", "goto13");
			SetCharacterShipLocation(characterFromID("Virgile boon"), "Falaise_de_Fleur_port_01");
			//Квест на появление Блэйза на Фале де Флер
			Pchar.quest.Story_Appear_on_Falaise.win_condition.l1 = "location";
			Pchar.quest.Story_Appear_on_Falaise.win_condition.l1.location = "Falaise_de_Fleur_port_01";
			Pchar.quest.Story_Appear_on_Falaise.win_condition = "Story_Appear_on_Falaise";
			
			Pchar.quest.Story_Appear_on_Falaise_shore.win_condition.l1 = "location";
			Pchar.quest.Story_Appear_on_Falaise_shore.win_condition.l1.location = "Falaise_de_fleur_shore";
			Pchar.quest.Story_Appear_on_Falaise_shore.win_condition = "Story_Appear_on_Falaise_shore";
			//Квест на потопление барка "Ойсу"
			Pchar.quest.Story_Sink_Oiseau.win_condition.l1 = "NPC_Death";
			Pchar.quest.Story_Sink_Oiseau.win_condition.l1.character = "Virgile Boon";
			Pchar.quest.Story_Sink_Oiseau.win_condition = "Story_Sink_Oiseau";

			Pchar.quest.Story_Massoni_order_attack_Blaze_denied.win_condition.l1 = "ExitFromLocation";
			Pchar.quest.Story_Massoni_order_attack_Blaze_denied.win_condition.l1.location = "Oxbay_town_exit";
			Pchar.quest.Story_Massoni_order_attack_Blaze_denied.win_condition = "Story_Massoni_order_attack_Blaze_denied";

			Pchar.quest.France_becomes_neutral.win_condition.l1 = "location";
			Pchar.quest.France_becomes_neutral.win_condition.l1.location = "FalaiseDeFleur";
			Pchar.quest.France_becomes_neutral.win_condition = "France_becomes_neutral";
		break;

		case "France_becomes_neutral":
			AddQuestRecord("Story_1stTaskReceived", "14");
			pchar.nation = FRANCE;
			SetNationRelation2MainCharacter(FRANCE, RELATION_NEUTRAL);
			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_NEITRAL);
		break;

		case "Massoni_doomed":
			Locations[FindLocation("Oxbay_town_exit")].reload.l1.disable = false;
			Locations[FindLocation("Oxbay_town_exit")].reload.l2.disable = false;
			Locations[FindLocation("Oxbay_town_exit")].reload.l3.disable = false;
			Locations[FindLocation("Oxbay_town_exit")].reload.l4.disable = false;
			Locations[FindLocation("Oxbay_town_exit")].reload.l5.disable = false;

			LAi_RemoveCheckMinHP(characterFromID("Valentin Massoni"));
			LAi_type_actor_Reset(characterFromID("Valentin Massoni"));
			
			if (CheckCharacterItem(Pchar,"Massoni_papers"))
			{
				pchar.quest.massoni_died.over = "yes";
			}

			LAi_ActorAttack(characterFromID("Valentin Massoni"), pchar, "");
			Pchar.quest.Story_1stTaskComplete = "1";

			ChangeCharacterAddress(CharacterFromID("Faust Gasquet"), "Falaise_de_fleur_port_01", "goto1");
			SetCharacterShipLocation(characterFromID("Virgile boon"), "Falaise_de_Fleur_port_01");
			//Квест на появление Блэйза на Фале де Флер
			Pchar.quest.Story_Appear_on_Falaise.win_condition.l1 = "location";
			Pchar.quest.Story_Appear_on_Falaise.win_condition.l1.location = "Falaise_de_Fleur_port_01";
			Pchar.quest.Story_Appear_on_Falaise.win_condition = "Story_Appear_on_Falaise";

			Pchar.quest.Story_Appear_on_Falaise_shore.win_condition.l1 = "location";
			Pchar.quest.Story_Appear_on_Falaise_shore.win_condition.l1.location = "Falaise_de_fleur_shore";
			Pchar.quest.Story_Appear_on_Falaise_shore.win_condition = "Story_Appear_on_Falaise_shore";
			//Квест на потопление барка "Ойсу"
			Pchar.quest.Story_Sink_Oiseau.win_condition.l1 = "NPC_Death";
			Pchar.quest.Story_Sink_Oiseau.win_condition.l1.character = "Virgile Boon";
			Pchar.quest.Story_Sink_Oiseau.win_condition = "Story_Sink_Oiseau";
			
			Pchar.quest.Story_Massoni_order_attack_Blaze_denied.win_condition.l1 = "ExitFromLocation";
			Pchar.quest.Story_Massoni_order_attack_Blaze_denied.win_condition.l1.location = "Oxbay_town_exit";
			Pchar.quest.Story_Massoni_order_attack_Blaze_denied.win_condition = "Story_Massoni_order_attack_Blaze_denied";

			Pchar.quest.France_becomes_neutral.win_condition.l1 = "location";
			Pchar.quest.France_becomes_neutral.win_condition.l1.location = "FalaiseDeFleur";
			Pchar.quest.France_becomes_neutral.win_condition = "France_becomes_neutral";
		break;

		//Массони добегает до ворот и приказывает стражникам, если они еще есть, убить Блэйза
		case "Story_Massoni_order_attack_Blaze":
			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			ChangeCharacterAddress(characterFromID("Valentin Massoni"), "none", "");
		break;

		case "Story_Massoni_order_attack_Blaze_denied":
			ChangeCharacterAddress(characterFromID("Valentin Massoni"), "none", "");
		break;

		//Солдаты завязывают с игроком разговором, когда он подходит к Оксбэю с суши.
		case "Story_FraSoldiers_attack_in_jungles":
			LAi_SetCheckMinHP(characterFromID("Fra_occupant_07"), 29.0, false, "fight_before_enter_to_oxbay");
			LAi_SetCheckMinHP(characterFromID("Fra_occupant_08"), 29.0, false, "fight_before_enter_to_oxbay");
			pchar.quest.Story_FraSoldiers_attack_in_jungles_2.win_condition.l1 = "locator";
			pchar.quest.Story_FraSoldiers_attack_in_jungles_2.win_condition.l1.location = "Oxbay_town_exit";
			pchar.quest.Story_FraSoldiers_attack_in_jungles_2.win_condition.l1.locator_group = "goto";
			pchar.quest.Story_FraSoldiers_attack_in_jungles_2.win_condition.l1.locator = "citizen08";
			pchar.quest.Story_FraSoldiers_attack_in_jungles_2.win_condition = "Story_FraSoldiers_attack_in_jungles_2";
		break;

		case "Story_FraSoldiers_attack_in_jungles_2":
			LAi_SetActorType(characterFromID("Fra_occupant_07"));
			LAi_SetActorType(characterFromID("Fra_occupant_08"));
			LAi_ActorFollow(characterFromID("Fra_occupant_07"), Pchar, "Story_FraSoldiers_attack_in_jungles_3", 10.0);
			LAi_ActorFollow(characterFromID("Fra_occupant_08"), Pchar, "", 10.0);
			
			LAi_NoRebirthEnable(characterFromID("Fra_occupant_07"));
			LAi_NoRebirthEnable(characterFromID("Fra_occupant_08"));
			if (LAi_group_GetPlayerAlarm() == 0)
			{
				LAi_SetActorType(pchar);
				LAi_ActorFollow(pchar, characterFromID("Fra_occupant_07"), "", 10.0);
			}
		break;
		
		case "Story_FraSoldiers_attack_in_jungles_3":
			LAi_ActorWaitDialog(pchar, characterFromID("Fra_occupant_07"));
			LAi_ActorDialog(characterFromID("Fra_occupant_07"), Pchar, "pchar_back_to_player", 1.0, 1.0);
		break;

		case "fight_before_enter_to_oxbay":
			pchar.quest.Story_FraSoldiers_attack_in_jungles_2.over = "yes";
			LAi_RemoveCheckMinHP(characterFromID("Fra_occupant_07"));
			LAi_RemoveCheckMinHP(characterFromID("Fra_occupant_08"));
			LAi_group_MoveCharacter(characterFromID("Fra_occupant_07"), "FRANCE_PATROL");
			LAi_group_MoveCharacter(characterFromID("Fra_occupant_08"), "FRANCE_PATROL");
			LAi_group_FightGroups("FRANCE_PATROL", LAI_GROUP_PLAYER, true);
		break;

		case "FRANCE_SOLDIERS_in_oxbay_exit_returned_to_post":
			//Отправляем солдат назад на посты
			LAi_ActorGoToLocator(characterFromID("Fra_occupant_07"), "goto", "citizen09", "Fra_occupant_07_return_to_post", -1);
			LAi_ActorGoToLocator(characterFromID("Fra_occupant_08"), "goto", "citizen010", "Fra_occupant_08_return_to_post", -1);
		break;

		case "Fra_occupant_07_return_to_post":
			LAi_SetGuardianType(characterFromID("Fra_occupant_07"));
			LAi_group_MoveCharacter(characterFromID("Fra_occupant_07"), "FRANCE_SOLDIERS");
		break;

		case "Fra_occupant_08_return_to_post":
			LAi_SetGuardianType(characterFromID("Fra_occupant_08"));
			LAi_group_MoveCharacter(characterFromID("Fra_occupant_08"), "FRANCE_SOLDIERS");
		break;
		
		//Блэйз в первый раз приплывает на Фале де Флер, чтобы поговорить с Беранжере
		case "Story_Appear_on_Falaise":
			locations[FindLocation("Oxbay_town_exit")].disableencounters = 0;
			pchar.quest.Story_Appear_on_Falaise_shore.over = "yes";
			LAi_group_SetHearRadius("FRANCE_SOLDIERS", LAI_GROUP_GRD_HEAR);
			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
			LAi_group_SetAlarmReaction("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY, LAI_GROUP_FRIEND);

			Locations[FindLocation("Oxbay_town_exit")].locators_radius.goto.citizen017 = 0.5;
			Locations[FindLocation("Falaise_de_fleur_port_01")].reload.l3.disable = 1;
			Pchar.quest.main_line = "GetAGramotaFromBerangere";
			ChangeCharacterAddress(characterFromID("Amiel Berangere"), "Falaise_de_fleur_tavern_upstairs", "goto4");
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Faust Gasquet"));
			LAi_ActorFollow(pchar, characterFromID("Faust Gasquet"), "", 2.0);
			LAi_ActorFollow(characterFromID("Faust Gasquet"), pchar, "Story_Appear_on_Falaise_2", 2.0);
		break;
		
		case "Story_Appear_on_Falaise_2":
			LAi_ActorWaitDialog(pchar, characterFromID("Faust Gasquet"));
			LAi_ActorDialog(characterFromID("Faust Gasquet"), Pchar, "return_faust_to_citizen", 2.0, 0);
			LAi_SetImmortal(characterFromID("Amiel Berangere"), true);
		break;

		case "Story_Appear_on_Falaise_shore":
			pchar.quest.Story_Appear_on_Falaise.over = "yes";
			LAi_group_SetHearRadius("FRANCE_SOLDIERS", LAI_GROUP_GRD_HEAR);
			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
			LAi_group_SetAlarmReaction("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY, LAI_GROUP_FRIEND);

			Locations[FindLocation("Oxbay_town_exit")].locators_radius.goto.citizen017 = 0.5;
			Locations[FindLocation("Falaise_de_fleur_port_01")].reload.l3.disable = 1;
			Pchar.quest.main_line = "GetAGramotaFromBerangere";
			PChar.quest.Story_AskAboutBerangere = "3";
			ChangeCharacterAddress(characterFromID("Amiel Berangere"), "Falaise_de_fleur_tavern_upstairs", "goto4");
			ChangeCharacterAddress(characterFromID("Faust Gasquet"), "none", "none");
		break;

		case "return_faust_to_citizen":
			LAi_SetPlayerType(pchar);
			LAi_SetCitizenType(characterFromID("Faust Gasquet"));
			LAi_group_MoveCharacter(characterFromID("Faust Gasquet"), "FRANCE_CITIZENS");
		break;

		//Блэйз топит снабженческий барк Oiseau, оставляя французов без боеприпасов.
		case "Story_Sink_Oiseau":
			SetNationRelation2MainCharacter(ENGLAND, RELATION_FRIEND);
			SetCharacterShipLocation(characterFromID("Virgile boon"), "none");
			pchar.quest.Convoy_Virgile_Boon.over = "yes";
			pchar.quest.Convoy_Virgile_Boon2.over = "yes";
			Pchar.quest.Story_Convoy_Virgile_Boon_1.over = "yes";
			Pchar.quest.Story_Convoy_Virgile_Boon_2.over = "yes";
			Pchar.quest.Story_Convoy_Virgile_Boon_3.over = "yes";
			Pchar.quest.Story_Convoy_Virgile_Boon_4.over = "yes";
			Pchar.quest.Story_Convoy_Virgile_Boon_5.over = "yes";
			Pchar.quest.Story_Convoy_Virgile_Boon_6.over = "yes";
			Pchar.quest.Story_Convoy_Virgile_Boon_7.over = "yes";
			Pchar.quest.Story_Convoy_Virgile_Boon_8.over = "yes";
			Pchar.quest.Story_Blaze_and_Boon_leaving.over = "yes";

			bQuestDisableMapEnter = false;
			Island_SetReloadEnableGlobal(PChar.location, true);
			AddQuestRecord("Story_1stTaskReceived", "12");
			ChangeCharacterAddress(characterFromID("Faust Gasquet"), "none", "");
			ChangeCharacterAddress(characterFromID("Amiel Berangere"), "none", "");
			Pchar.quest.Story_1stTaskComplete = "Complete";
			SetNationRelation2MainCharacter(FRANCE, RELATION_ENEMY);
			pchar.quest.story_askaboutberangere.over = "yes";
		break;

		//Блэйз приплывает с барком Ойсу на любой остров.
		case "Convoy_Virgile_Boon":
			pchar.nation = ENGLAND;
			SetCharacterRemovable(characterFromID("Virgile Boon"), true);
			pchar.quest.Convoy_Virgile_Boon2.over = "yes";
			Pchar.quest.Story_Convoy_Virgile_Boon_1.over = "yes";
			Pchar.quest.Story_Convoy_Virgile_Boon_2.over = "yes";
			Pchar.quest.Story_Convoy_Virgile_Boon_3.over = "yes";
			Pchar.quest.Story_Convoy_Virgile_Boon_4.over = "yes";
			Pchar.quest.Story_Convoy_Virgile_Boon_5.over = "yes";
			Pchar.quest.Story_Convoy_Virgile_Boon_6.over = "yes";
			Pchar.quest.Story_Convoy_Virgile_Boon_7.over = "yes";
			Pchar.quest.Story_Convoy_Virgile_Boon_8.over = "yes";
			Pchar.quest.Story_Blaze_and_Boon_leaving.over = "yes";

			bQuestDisableMapEnter = true;
			Island_SetReloadEnableGlobal(PChar.location, false);

			RemoveCharacterCompanion(Pchar, characterFromID("Virgile Boon"));

			SetCharacterRelationBoth(GetCharacterIndex("Redmond Commander"),GetCharacterIndex("Virgile Boon"),RELATION_ENEMY);
			SetCharacterRelationBoth(GetCharacterIndex("Greenford Commander"),GetCharacterIndex("Virgile Boon"),RELATION_ENEMY);
			SetCharacterRelationBoth(GetCharacterIndex("FalaiseDeFleur Commander"),GetCharacterIndex("Virgile Boon"),RELATION_FRIEND);
			SetCharacterRelationBoth(GetCharacterIndex("Virgile Boon"),GetMainCharacterIndex(),RELATION_ENEMY);
			
			Group_CreateGroup("Virgile Boon");
			Group_AddCharacter("Virgile Boon", "Virgile Boon");
			Group_SetGroupCommander("Virgile Boon", "Virgile Boon");
			Group_SetPursuitGroup("Virgile Boon", PLAYER_GROUP);
			Group_SetTaskAttack("Virgile Boon", PLAYER_GROUP);
			Group_LockTask("Virgile Boon");
			Group_SetAddress("Virgile Boon", Characters[GetMainCharacterIndex()].location, "", "");

			UpdateRelations();
		break;
		
		case "Convoy_Virgile_Boon2":
			SetCharacterRemovable(characterFromID("Virgile Boon"), true);
			pchar.quest.Convoy_Virgile_Boon.over = "yes";
			Pchar.quest.Story_Convoy_Virgile_Boon_1.over = "yes";
			Pchar.quest.Story_Convoy_Virgile_Boon_2.over = "yes";
			Pchar.quest.Story_Convoy_Virgile_Boon_3.over = "yes";
			Pchar.quest.Story_Convoy_Virgile_Boon_4.over = "yes";
			Pchar.quest.Story_Convoy_Virgile_Boon_5.over = "yes";
			Pchar.quest.Story_Convoy_Virgile_Boon_6.over = "yes";
			Pchar.quest.Story_Convoy_Virgile_Boon_7.over = "yes";
			Pchar.quest.Story_Convoy_Virgile_Boon_8.over = "yes";
			Pchar.quest.Story_Blaze_and_Boon_leaving.over = "yes";

			bQuestDisableMapEnter = true;
			Island_SetReloadEnableGlobal(PChar.location, false);

			RemoveCharacterCompanion(Pchar, characterFromID("Virgile Boon"));

			SetCharacterRelationBoth(GetCharacterIndex("Redmond Commander"),GetCharacterIndex("Virgile Boon"),RELATION_ENEMY);
			SetCharacterRelationBoth(GetCharacterIndex("Greenford Commander"),GetCharacterIndex("Virgile Boon"),RELATION_ENEMY);
			SetCharacterRelationBoth(GetCharacterIndex("FalaiseDeFleur Commander"),GetCharacterIndex("Virgile Boon"),RELATION_FRIEND);
			SetCharacterRelationBoth(GetCharacterIndex("Virgile Boon"),GetMainCharacterIndex(),RELATION_ENEMY);
			
			Group_CreateGroup("Virgile Boon");
			Group_AddCharacter("Virgile Boon", "Virgile Boon");
			Group_SetGroupCommander("Virgile Boon", "Virgile Boon");
			Group_SetPursuitGroup("Virgile Boon", PLAYER_GROUP);
			Group_SetTaskAttack("Virgile Boon", PLAYER_GROUP);
			Group_LockTask("Virgile Boon");
			Group_SetAddress("Virgile Boon", Characters[GetMainCharacterIndex()].location, "", "");
			
			Sea_LoginGroupNow("Virgile Boon");

			UpdateRelations();
		break;

		case "Story_BerangereStartTalkingToBlaze":
			pchar.quest.main_line = "";
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Amiel Berangere"));
			LAi_ActorFollow(pchar, characterFromID("Amiel Berangere"), "", 1.5);
			LAi_ActorFollow(characterFromID("Amiel Berangere"), pchar, "Story_BerangereBeginsDialog", 1.5);
		break;

		case "Story_BerangereBeginsDialog":
			LAi_type_actor_Reset(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("Amiel Berangere"));
			LAi_ActorDialog(characterFromID("Amiel Berangere"), Pchar, "pchar_back_to_player", 1.0, 1.0);
		break;

		//Игрок убивает Эмиля Беранжере
		case "Story_BlazeStartsThinkAboutGramota":
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], true);
			Pchar.Dialog.CurrentNode = "Story_FindBerangereDocuments";
			LAi_QuestDelay("Story_BlazeStartsThinkAboutGramota_2", 2.0);
		break;

		case "Story_BlazeStartsThinkAboutGramota_2":
			LAi_SetActorType(pchar);
			LAi_ActorSelfDialog(pchar, "");
		break;

		case "Story_BlazeStartLookingForGramota":
			AddQuestRecord("Story_1stTaskReceived","9");

			Event("QuestSceneCommand", "ssass", "gotopoint", "", PChar, "goto", "goto2");
			Event("QuestSceneCommand", "ssa", "stay", "", PChar);
			Event("QuestSceneCommand", "ssass", "TurnByLocator", "", PChar, "goto", "goto2");
			Event("QuestSceneCommand", "ssass", "gotopoint", "", PChar, "goto", "goto1");
			Event("QuestSceneCommand", "ssass", "gotopoint", "", PChar, "goto", "goto4");
			Event("QuestSceneCommand", "ssass", "gotopoint", "", PChar, "goto", "goto5");
			Event("QuestSceneCommand", "ssa", "stay", "", PChar);
			Event("QuestSceneCommand", "ssass", "turnbylocator", "Story_FoundGramotaAndLebrettonAppeared", PChar, "goto", "goto5");
			//Event("QuestSceneCommand", "ssas", "action", "Story_FoundGramotaAndLebrettonAppeared", PChar, "");
			//------- !!!!!!!! Вставить проигрывание звука открывающейся двери
			PostEvent("startAfterWaitScene",0,"a",PChar);
			AddPartyExp(pchar, 2000);
		break;
		
		case "Story_FoundGramotaAndLebrettonAppeared":
			//--------Получение предмета
			GiveItem2Character(Pchar,"Story_Gramota");
			//--------Постановка Вирджила Буна в первый порт Фале де Флер
			ChangeCharacterAddress(characterFromID("Virgile Boon"), "Falaise_de_Fleur_port_01", "goto1");
			//-------- Появление Антуана Лебреттона
			Characters[GetCharacterIndex("antoine lebretton")].dialog.CurrentNode = "Story_Berangere_killed";
			Locations[FindLocation("Falaise_De_Fleur_tavern_upstairs")].reload.l1.disable = 0;
			ChangeCharacterAddressGroup(characterFromID("antoine lebretton"), "Falaise_De_Fleur_tavern_upstairs", "reload","reload1");
			LAi_SetActorType(characterFromID("antoine lebretton"));
			//------- Убираем ненужного Фауста Гаске
			ChangeCharacterAddress(characterFromID("Faust Gasquet"), "none", "");
			LAi_ActorGoToLocator(pchar, "goto", "goto3", "before_lebretton_talk_with_us_in_upstairs", 4.0);
			LAi_ActorDialog(characterFromID("antoine lebretton"), Pchar, "", 3.0, 1.0);
		break;

		case "before_lebretton_talk_with_us_in_upstairs":
			LAi_ActorWaitDialog(pchar, characterFromID("Antoine lebretton"));
		break;

		case "Story_Lebretton_leaves_upstairs":
			LAi_SetPlayerType(pchar);
			//---------перегрузка Лебреттона обратно за стойку в таверне.
			ChangeCharacterAddressGroup(characterFromID("antoine lebretton"), "Falaise_De_Fleur_tavern", "merchant","goto1");
			//---------снимается бессмертие с Антуана Лебреттона			
			LAi_SetMerchantType(characterFromID("antoine lebretton"));
			LAi_group_MoveCharacter(characterFromID("antoine lebretton"), "FRANCE_CITIZENS");
		break;

		case "Story_ReturnToFFPortToFindBoon":
			Characters[GetCharacterIndex("Tancrede Rimbaud")].dialog.filename = "Tancrede Rimbaud_dialog.c";
			LAi_SetActorType(characterFromID("Virgile Boon"));
			LAi_group_MoveCharacter(characterFromID("Virgile Boon"), "FRANCE_CITIZENS");
			LAi_SetActorType(characterFromID("Tancrede Rimbaud"));
			LAi_group_MoveCharacter(characterFromID("Tancrede Rimbaud"), "FRANCE_CITIZENS");
			LAi_ActorFollow(characterFromID("Virgile Boon"), characterFromID("Tancrede Rimbaud"), "Story_ReturnToFFPortToFindBoon_2", 10.0);
			LAi_SetCheckMinHP(characterFromID("Virgile Boon"), 79.0, false, "boon_becomes_citizen");
		break;

		case "boon_becomes_citizen":
			LAi_SetCitizenType(characterFromID("Virgile Boon"));
			LAi_group_MoveCharacter(characterFromID("Virgile Boon"), "FRANCE_CITIZENS");
		break;

		case "Story_ReturnToFFPortToFindBoon_2":
			LAi_ActorTurnToCharacter(characterFromID("Virgile Boon"), characterFromID("Tancrede Rimbaud"));
			LAi_ActorTurnToCharacter(characterFromID("Tancrede Rimbaud"), characterFromID("Virgile Boon"));
			LAi_ActorWaitDialog(characterFromID("Virgile Boon"), pchar);
			LAi_ActorWaitDialog(characterFromID("Tancrede Rimbaud"), pchar);
		break; 

		case "Story_BoonStartTalkToTancredeAgain":
			LAi_ActorTurnToCharacter(characterFromID("Virgile Boon"), characterFromID("Tancrede Rimbaud"));
			LAi_ActorTurnToCharacter(characterFromID("Tancrede Rimbaud"), characterFromID("Virgile Boon"));
			LAi_ActorWaitDialog(characterFromID("Virgile Boon"), pchar);
			LAi_ActorWaitDialog(characterFromID("Tancrede Rimbaud"), pchar);
		break;

		case "Story_Blaze_and_Boon_leaving":
			characters[GetCharacterIndex("Virgile Boon")].location = "none";
			//------------Выдача Квестов на нападение Буна на игрока
			Pchar.quest.Story_Convoy_Virgile_Boon_1.win_condition.l1 = "location";
			Pchar.quest.Story_Convoy_Virgile_Boon_1.win_condition.l1.location = "Oxbay";
			Pchar.quest.Story_Convoy_Virgile_Boon_1.win_condition = "Convoy_Virgile_Boon";

			Pchar.quest.Story_Convoy_Virgile_Boon_2.win_condition.l1 = "location";
			Pchar.quest.Story_Convoy_Virgile_Boon_2.win_condition.l1.location = "Redmond";
			Pchar.quest.Story_Convoy_Virgile_Boon_2.win_condition = "Convoy_Virgile_Boon";

			Pchar.quest.Story_Convoy_Virgile_Boon_3.win_condition.l1 = "location";
			Pchar.quest.Story_Convoy_Virgile_Boon_3.win_condition.l1.location = "IslaMuelle";
			Pchar.quest.Story_Convoy_Virgile_Boon_3.win_condition = "Convoy_Virgile_Boon";

			Pchar.quest.Story_Convoy_Virgile_Boon_4.win_condition.l1 = "location";
			Pchar.quest.Story_Convoy_Virgile_Boon_4.win_condition.l1.location = "Conceicao";
			Pchar.quest.Story_Convoy_Virgile_Boon_4.win_condition = "Convoy_Virgile_Boon";

			Pchar.quest.Story_Convoy_Virgile_Boon_5.win_condition.l1 = "location";
			Pchar.quest.Story_Convoy_Virgile_Boon_5.win_condition.l1.location = "Douwesen";
			Pchar.quest.Story_Convoy_Virgile_Boon_5.win_condition = "Convoy_Virgile_Boon";

			Pchar.quest.Story_Convoy_Virgile_Boon_6.win_condition.l1 = "location";
			Pchar.quest.Story_Convoy_Virgile_Boon_6.win_condition.l1.location = "QuebradasCostillas";
			Pchar.quest.Story_Convoy_Virgile_Boon_6.win_condition = "Convoy_Virgile_Boon";

			Pchar.quest.Story_Convoy_Virgile_Boon_7.win_condition.l1 = "location";
			Pchar.quest.Story_Convoy_Virgile_Boon_7.win_condition.l1.location = "KhaelRoa";
			Pchar.quest.Story_Convoy_Virgile_Boon_7.win_condition = "Convoy_Virgile_Boon";
			
			Pchar.quest.Story_Convoy_Virgile_Boon_8.win_condition.l1 = "location";
			Pchar.quest.Story_Convoy_Virgile_Boon_8.win_condition.l1.location = "";
			Pchar.quest.Story_Convoy_Virgile_Boon_8.win_condition = "Convoy_Virgile_Boon2";
			character_SetCompanionEnemyEnable(characterFromID("Virgile Boon"), true);

			LAi_SetCitizenType(characterFromID("Tancrede Rimbaud"));
			LAi_group_MoveCharacter(characterFromID("Tancrede Rimbaud"), "FRANCE_CITIZENS");
		break;

		case "Story_Meeting_Ewan_Glover":
			//---------Капитан десантного шлюпа Эван Глоувер подходит к игроку знакомитьс
			LAi_SetActorType(characterFromID("Ewan Glover"));
			Locations[FindLocation("Greenford_port")].reload.l1.disable = 1;
			LAi_SetImmortal(characterFromID("Ewan Glover"), true);
			LAi_ActorDialog(characterFromID("Ewan Glover"), PChar, "", 3.0, 1.0);
		break;

		case "Ewan_Once_Again_exit_no_join":
			//---------Отправляем Глоувера к локатору
			LAi_ActorGoToLocator(characterFromID("Ewan Glover"), "goto", "goto2", "", -1);
		break;

		case "Ewan_exit_no_join":
			//---------Отправляем Гроувера к локатору
			LAi_ActorGoToLocator(characterfromID("Ewan Glover"), "reload", "reload_1_2", "Story_Glover_goes_to_tavern", -1);
		break;

		case "Ewan_Exit_need_some_walk":			
			//---------Отправляем Глоувера к локатору
			LAi_ActorRunToLocator(characterfromID("Ewan Glover"),"Reload","reload4", "Story_Glover_to_tavern_on_Greenford", 20.0);
			pchar.quest.checker_for_greenford_tavern_for_meet_with_evan_glover.win_condition.l1 = "location";
			pchar.quest.checker_for_greenford_tavern_for_meet_with_evan_glover.win_condition.l1.location = "Greenford_tavern";
			pchar.quest.checker_for_greenford_tavern_for_meet_with_evan_glover.win_condition = "Story_Glover_to_tavern_on_Greenford";
			Characters[GetCharacterIndex("Ewan Glover")].Dialog.CurrentNode = "Are_you_ready_again";

			Pchar.quest.Story_Blaze_and_Glover_Land_troops.win_condition.l1 = "location";
			Pchar.quest.Story_Blaze_and_Glover_Land_troops.win_condition.l1.location = "Oxbay_shore_02";
			Pchar.quest.Story_Blaze_and_Glover_Land_troops.win_condition.l2 = "Ship_location";
			Pchar.quest.Story_Blaze_and_Glover_Land_troops.win_condition.l2.location = "Oxbay_shore_02";
			Pchar.quest.Story_Blaze_and_Glover_Land_troops.win_condition = "Story_Blaze_and_Glover_Land_troops";
			
			Pchar.quest.Story_Blaze_and_Glover_Land_troops_denied.win_condition.l1 = "NPC_death";
			Pchar.quest.Story_Blaze_and_Glover_Land_troops_denied.win_condition.l1.character = "Ewan Glover";
			Pchar.quest.Story_Blaze_and_Glover_Land_troops_denied.win_condition = "Story_Blaze_and_Glover_Land_troops_denied";
		break;

		case "ewan_again_gain_quest_for_night":
			Pchar.quest.Story_Blaze_and_Glover_Land_troops.win_condition.l1 = "location";
			Pchar.quest.Story_Blaze_and_Glover_Land_troops.win_condition.l1.location = "Oxbay_shore_02";
			Pchar.quest.Story_Blaze_and_Glover_Land_troops.win_condition.l2 = "Ship_location";
			Pchar.quest.Story_Blaze_and_Glover_Land_troops.win_condition.l2.location = "Oxbay_shore_02";
			Pchar.quest.Story_Blaze_and_Glover_Land_troops.win_condition = "Story_Blaze_and_Glover_Land_troops";
			
			Pchar.quest.Story_Blaze_and_Glover_Land_troops_denied.win_condition.l1 = "NPC_death";
			Pchar.quest.Story_Blaze_and_Glover_Land_troops_denied.win_condition.l1.character = "Ewan Glover";
			Pchar.quest.Story_Blaze_and_Glover_Land_troops_denied.win_condition = "Story_Blaze_and_Glover_Land_troops_denied";
		break;

		case "Ewan_exit_business":
			Locations[FindLocation("Greenford_town")].reload.l4.disable = 1;
			
			//---------Возвращаем обоим тип стоящих.
			LAi_SetCitizenType(characterfromID("Ewan Glover"));
			//---------Начинаем проверку на попадание игрока и Глоувера в локейшен ночной высадки
			Pchar.quest.Story_Blaze_and_Glover_Land_troops.win_condition.l1 = "location";
			Pchar.quest.Story_Blaze_and_Glover_Land_troops.win_condition.l1.location = "Oxbay_shore_02";
			Pchar.quest.Story_Blaze_and_Glover_Land_troops.win_condition.l2 = "Ship_location";
			Pchar.quest.Story_Blaze_and_Glover_Land_troops.win_condition.l2.location = "Oxbay_shore_02";
			Pchar.quest.Story_Blaze_and_Glover_Land_troops.win_condition = "Story_Blaze_and_Glover_Land_troops";
			
			Pchar.quest.Story_Blaze_and_Glover_Land_troops_denied.win_condition.l1 = "NPC_death";
			Pchar.quest.Story_Blaze_and_Glover_Land_troops_denied.win_condition.l1.character = "Ewan Glover";
			Pchar.quest.Story_Blaze_and_Glover_Land_troops_denied.win_condition = "Story_Blaze_and_Glover_Land_troops_denied";

			if (pchar.location == "Greenford_tavern")
			{
				//---------Выставляем время на вечер
				SetCurrentTime(23, 0);
				LAi_SetPlayerType(pchar);
				//---------Телепортируем Глоувера в никуда, а игрока на пристань Гринфорда
				ChangeCharacterAddress(characterFromID("Ewan Glover"), "none", "");

				DoReloadCharacterToLocation("Greenford_port", "Reload", "Reload4");
			}
			//Отключаем выход в карту
			bQuestDisableMapEnter = true;
		break;

		case "Ewan_goodbye_exit":
			RemoveCharacterCompanion(Pchar, characterFromID("Ewan Glover"));
			LAi_ActorGoToLocator(characterFromID("Ewan Glover"), "Reload", "reload1", "Story_Glover_leaves_on_complete", 60.0);
			Pchar.quest.Story_2ndTask = "Second_part";
			LAi_SetSitType(characterFromID("CounterSpy"));
			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_NEITRAL);
			ChangeCharacterAddressGroup(&Characters[GetCharacterIndex("CounterSpy")], "Oxbay_tavern", "Sit", "Sit6");
			Characters[GetCharacterIndex("CounterSpy")].Dialog.CurrentNode = "Met_Blaze";
		break;

		case "Ewan_Glover_exit_join":
			//----------Присоединяем Эвана Глоувера к игроку
			SetCompanionIndex(Pchar, -1, GetCharacterIndex("Ewan Glover"));
			SetCharacterRemovable(characterFromID("Ewan Glover"), false);
			//----------Выставляем квест на потопление корабля Эвана
			Pchar.quest.Story_Convoy_Glover_to_Greenford.win_condition.l1 = "NPC_Death";
			Pchar.quest.Story_Convoy_Glover_to_Greenford.win_condition.l1.character = "Ewan Glover";
			Pchar.quest.Story_Convoy_Glover_to_Greenford.win_condition = "Story_Glover_Sunk2";
			//---------Отправляем Глоувера к локатору
			LAi_ActorRunToLocator(characterFromID("Ewan Glover"), "reload", "sea_1", "Story_Glover_leaves_tavern", 75.0);
			//-------перемещаем местного жителя к причалу Гринфорда
			ChangeCharacterAddress(characterFromID("Wilfred"), "Greenford_port", "goto20");
			//-------Заводим квест на попадание игрока в порт Гринфорда
			Pchar.quest.Story_Blaze_reaches_Greenford.win_condition.l1 = "location";
			Pchar.quest.Story_Blaze_reaches_Greenford.win_condition.l1.location = "Greenford_port";
			Pchar.quest.Story_Blaze_reaches_Greenford.win_condition = "Story_Blaze_reaches_Greenford";
			
			Pchar.quest.Story_Blaze_reaches_shore1.win_condition.l1 = "location";
			Pchar.quest.Story_Blaze_reaches_shore1.win_condition.l1.location = "Oxbay_shore_01";
			Pchar.quest.Story_Blaze_reaches_shore1.win_condition = "Story_Blaze_reaches_shore1";
			
			Pchar.quest.Story_Blaze_reaches_shore2.win_condition.l1 = "location";
			Pchar.quest.Story_Blaze_reaches_shore2.win_condition.l1.location = "Oxbay_shore_02";
			Pchar.quest.Story_Blaze_reaches_shore2.win_condition = "Story_Blaze_reaches_shore1";
			
			Pchar.quest.Story_Blaze_reaches_shore3.win_condition.l1 = "location";
			Pchar.quest.Story_Blaze_reaches_shore3.win_condition.l1.location = "Oxbay_lighthouse";
			Pchar.quest.Story_Blaze_reaches_shore3.win_condition = "Story_Blaze_reaches_shore1";

			Pchar.quest.Story_Glover_leaves_tavern.win_condition.l1 = "location";
			Pchar.quest.Story_Glover_leaves_tavern.win_condition.l1.location = "Redmond";
			Pchar.quest.Story_Glover_leaves_tavern.win_condition = "Story_Glover_leaves_tavern";
		break;
		
		case "Story_Blaze_reaches_shore1":
			Pchar.quest.Story_Blaze_reaches_shore1.over = "yes";
			Pchar.quest.Story_Blaze_reaches_shore2.over = "yes";
			Pchar.quest.Story_Blaze_reaches_shore3.over = "yes";

			homelocation = pchar.location;
			PlaceCharacter(characterFromID("Ewan Glover"), "goto", homelocation);
			
			characters[GetCharacterIndex("Ewan Glover")].dialog.currentnode = "CameToOxbay_shore";
			LAi_type_actor_Reset(characterFromID("Ewan Glover"));
			LAi_ActorDialog(characterFromID("Ewan Glover"), pchar, "", 2.0, 1.0);
		break;

		case "prepare_Story_ReloadedtoGreenfordTavernWithGlover":
			SetCurrentTime(23, 0);
			//---------Телепортируем Глоувера и игрока в таверну Гринфорда
			ChangeCharacterAddressGroup(characterFromID("Ewan Glover"), "Greenford_tavern", "Sit", "Sit4");
			DoQuestReloadToLocation("Greenford_tavern", "sit", "sit3", "Story_ReloadedtoGreenfordTavernWithGlover");
		break;
		
		case "prepare_Story_ReloadedtoGreenfordTavernWithGlover_1":
			//---------Телепортируем Глоувера и игрока в таверну Гринфорда
			ChangeCharacterAddressGroup(characterFromID("Ewan Glover"), "Greenford_tavern", "Sit", "Sit4");
			//DoQuestReloadToLocation("Greenford_tavern", "sit", "sit3", "Story_ReloadedtoGreenfordTavernWithGlover");
			LAi_Fade("prepare_Story_ReloadedtoGreenfordTavernWithGlover_2", "Story_ReloadedtoGreenfordTavernWithGlover");
		break;

		case "prepare_Story_ReloadedtoGreenfordTavernWithGlover_2":
			LAi_SetSitType(characterFromID("Ewan Glover"));
			LAi_SetActorType(pchar);
			LAi_ActorSetSitMode(pchar);
			
			ChangeCharacterAddressGroup(pchar, "Greenford_tavern", "sit", "sit3");
		break;

		case "Story_Glover_Sunk2":
			SetCharacterShipLocation(characterFromID("Ewan Glover"), "none");
			AddQuestRecord("Story_2ndTask", "8");
			Pchar.quest.Story_Glover_Sunk = true;
			
			Locations[FindLocation("Greenford_town")].reload.l4.disable = 0;
			Locations[FindLocation("Oxbay_shore_02")].reload.l3.disable = 0;
			bQuestDisableMapEnter = false;
			Pchar.quest.Story_2ndTask = "Second_part";
			LAi_SetSitType(characterFromID("Counterspy"));
			ChangeCharacterAddressGroup(characterFromID("CounterSpy"), "Oxbay_tavern", "Sit", "Sit6");
			Characters[GetCharacterIndex("CounterSpy")].Dialog.CurrentNode = "Met_Blaze";
			Characters[GetCharacterIndex("Wilfred")].Dialog.CurrentNode = "Failed_in_last_moment";
		break;

		case "Story_Glover_goes_to_tavern":
			//--------перемещаем Эвана Глоувера в никуда... Предположительно, он в таверне Редмонда
			ChangeCharacterAddress(characterFromID("Ewan Glover"), "None", "");
			Pchar.Quest.Story_Ask_for_Glover = "1";
		break;

		case "Story_Glover_leaves_tavern":
			//--------перемещаем Эвана Глоувера в никуда... Предположительно, он на своем корабле
			ChangeCharacterAddressGroup(characterFromID("Ewan Glover"), "Greenford_port", "Goto", "goto21");
			LAi_SetImmortal(characterFromID("Ewan Glover"), false);
		break;

		case "Story_Glover_goes_to_ship":
			//--------перемещаем Эвана Глоувера в никуда... Предположительно, он на своем корабле
			ChangeCharacterAddress(characterFromID("Ewan Glover"), "None", "");
			LAi_SetImmortal(characterFromID("Ewan Glover"), false);
		break;

		case "Story_Blaze_reaches_Greenford":
			ChangeCharacterAddress(characterFromID("Wilfred"), "Greenford_port", "goto20");
			
			Pchar.quest.Story_Blaze_reaches_shore1.over = "yes";
			Pchar.quest.Story_Blaze_reaches_shore2.over = "yes";
			Pchar.quest.Story_Blaze_reaches_shore3.over = "yes";
			
			Lai_SetStayType(pchar);
			//---------ставим рядом с Блэйзом Эвана Глоувера
			if (!LAi_IsDead(characterFromID("Ewan Glover")))
			{
				AddQuestRecord("Story_2ndTask", "8");
				Characters[GetCharacterIndex("Ewan Glover")].Dialog.CurrentNode = "CameToGreenford";
				ChangeCharacterAddress(characterFromID("Ewan Glover"), "Greenford_port", "goto21");
				LAi_type_actor_Reset(characterFromID("Ewan Glover"));
				LAi_ActorDialog(characterFromID("Ewan Glover"), pchar, "Story_Blaze_reaches_Greenford_2", 2.0, 1.0);
			}
			else
			{
				LAi_QuestDelay("Story_Blaze_reaches_Greenford_2", 0.2);
			}
		break;
		
		case "Story_Blaze_reaches_Greenford_2":
			LAi_SetActorType(characterFromID("Wilfred"));
			LAi_ActorDialog(characterFromID("Wilfred"), Pchar, "", 4.0, 1.0);
			//---------На всякий случай делаем его бессмертным
			LAi_SetImmortal(characterFromID("Wilfred"), true);
		break;

		case "Wilfred_exit_failed":
			//--------Отправка Уилфреда в ворота Гринфорда.
			LAi_ActorRunToLocator(characterFromID("Wilfred"), "Reload","reload4", "Story_Wilfred_leaves_forever", 15.0);
			LAi_SetPlayerType(pchar);
			Pchar.quest.Story_2ndTask = "Second_part";
			LAi_SetSitType(characterFromID("CounterSpy"));
			ChangeCharacterAddressGroup(characterFromID("CounterSpy"), "Oxbay_tavern", "Sit", "Sit6");
			Characters[GetCharacterIndex("CounterSpy")].Dialog.CurrentNode = "Met_Blaze";
		break;

		case "Wilfred_Exit_failed_in_last_moment":
			//--------Отправка Уилфреда к локатору релоада.
			LAi_ActorRunToLocator(characterFromID("Wilfred"), "Reload","reload2", "Story_Wilfred_leaves_forever", 15.0);
			LAi_SetPlayerType(pchar);
		break;

		case "Story_Wilfred_leaves_forever":
			//---------Отправляем Уилфреда в никуда, считая что он от горя сбежал домой
			ChangeCharacterAddress(characterFromID("Wilfred"), "None", "");
		break;

		case "Story_Convoy_Glover_to_Greenford":
			AddQuestRecord("Story_2ndTask", "4");
			//--------Зачисляем игроку проваленный квест
			Pchar.quest.Story_Glover_sunk = true;
			//--------Стартуем вторую половину задания
			Pchar.quest.Story_2ndTask = "Second_part";
			LAi_SetSitType(characterFromID("CounterSpy"));
			ChangeCharacterAddressGroup(characterFromID("CounterSpy"), "Oxbay_tavern", "Sit", "Sit6");
			Characters[GetCharacterIndex("CounterSpy")].Dialog.CurrentNode = "Met_Blaze";
		break;

		case "Story_Wilfred_go_to_shore_prepare":
			AddPartyExp(pchar, 2500);
			//---------Установка диалога Эвану Глоуверу
			Characters[GetCharacterIndex("Ewan Glover")].Dialog.CurrentNode = "Are_you_ready";
			LAi_type_actor_Reset(characterFromID("Ewan Glover"));
			LAi_ActorDialog(characterFromID("Ewan Glover"), Pchar, "pchar_back_to_player", 3.0, 5.0);
			//--------Запись в журнал
			AddQuestRecord("Story_2ndTask","6");
			//--------Отправка Уилфреда в ворота Гринфорда.
			LAi_ActorRunToLocator(characterFromID("Wilfred"), "Reload", "reload4", "Story_Wilfred_go_to_shore", 60.0);
		break;

		case "pchar_back_to_player":
			Lai_SetPlayerType(pchar);
		break;
		
		case "Story_Wilfred_go_to_shore":
			//---------Отправляем Уилфреда в никуда, считая что он отправился на берег встречать Блэйза
			ChangeCharacterAddress(characterFromID("Wilfred"), "None", "");
		break;

		case "Wilfred_exit_fight":			
			LAi_ActorRunToLocator(characterfromID("Wilfred"), "goto", "locator8", "Story_Wilfred_scared_run_away", 40.0);
			LAi_SetPlayerType(pchar);

			LAi_group_MoveCharacter(characterFromID("Fra_patrolman_01"), "FRANCE_SOLDIERS"); 
			LAi_group_MoveCharacter(characterFromID("Fra_patrolman_02"), "FRANCE_SOLDIERS"); 
			LAi_group_MoveCharacter(characterFromID("Fra_patrolman_03"), "FRANCE_SOLDIERS"); 
			LAi_group_MoveCharacter(characterFromID("Fra_patrolman_04"), "FRANCE_SOLDIERS"); 
			//--------Появление французских солдат
			ChangeCharacterAddressGroup(characterFromID("Fra_patrolman_01"), "Oxbay_shore_02", "reload", "reload2_back");
			ChangeCharacterAddress(characterFromID("Fra_patrolman_02"), "Oxbay_shore_02", "locator27");
			ChangeCharacterAddress(characterFromID("Fra_patrolman_03"), "Oxbay_shore_02", "locator26");
			ChangeCharacterAddress(characterFromID("Fra_patrolman_04"), "Oxbay_shore_02", "locator13");
			//-----------Смена типа английским солдатам
			LAi_group_MoveCharacter(characterFromID("Eng_land_soldier_01"), LAI_GROUP_PLAYER); 
			LAi_group_MoveCharacter(characterFromID("Eng_land_soldier_02"), LAI_GROUP_PLAYER); 
			LAi_group_MoveCharacter(characterFromID("Eng_land_soldier_03"), LAI_GROUP_PLAYER); 
			LAi_group_MoveCharacter(characterFromID("Eng_land_soldier_04"), LAI_GROUP_PLAYER); 
			//--------нападение их на группу игрока	
			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("FRANCE_SOLDIERS", "Story_kill_french_patrol");

			//--------Отправка Уилфреда к локатору, где он будет бояться.
			LAi_SetImmortal(characterFromID("Wilfred"), true);
			Locations[FindLocation("Oxbay_shore_02")].reload.l3.disable = 1;
		break;

		case "Story_Glover_to_tavern_on_Greenford":
			//----------Выставляем Глоуверу сидячую позицию.
			LAi_type_actor_Reset(characterFromID("Ewan Glover"));
			LAi_SetSitType(characterFromID("Ewan Glover"));
			//---------Перегружаем Эвана Глоувера в таверну Гринфорда, где он будет ждать игрока.
			ChangeCharacterAddressGroup(characterFromID("Ewan Glover"), "Greenford_tavern", "sit", "sit4");
			Characters[GetCharacterIndex("Ewan Glover")].Dialog.CurrentNode = "Are_you_ready_again";
		break;

		case "Story_ReloadedtoGreenfordTavernWithGlover":
			SetCurrentTime(23, 0);
			LAi_SetSitType(characterFromID("Ewan Glover"));
			LAi_SetActorType(pchar);
			LAi_ActorSetSitMode(pchar);
			
			Locations[FindLocation("Greenford_port")].reload.l1.disable = 0;
			Characters[GetCharacterIndex("Ewan Glover")].Dialog.CurrentNode = "Talk_in_tavern";

			LAi_ActorDialogNow(Pchar, characterFromID("Ewan Glover"), "", -1);
			Locations[FindLocation("Oxbay_shore_02")].reload.l3.disable = 0;
		break;

		case "Story_Blaze_and_Glover_Land_troops":
			if (makeint(environment.time) >=23 || makeint(environment.time) <= 6)
			{
				pchar.quest.checker_for_greenford_tavern_for_meet_with_evan_glover.over = "yes";
				Locations[FindLocation("Greenford_town")].reload.l4.disable = 0;
				if (!LAi_IsDead(characterFromID("Ewan Glover")))
				{
					//----------Высаживаем Английских солдат вместе с игроком
					ChangeCharacterAddress(characterFromID("Eng_land_soldier_01"), "Oxbay_shore_02", "locator7");
					ChangeCharacterAddress(characterFromID("Eng_land_soldier_02"), "Oxbay_shore_02", "locator23");
					ChangeCharacterAddress(characterFromID("Eng_land_soldier_03"), "Oxbay_shore_02", "locator24");
					ChangeCharacterAddress(characterFromID("Eng_land_soldier_04"), "Oxbay_shore_02", "locator25");
					Characters[GetCharacterIndex("Wilfred")].Dialog.CurrentNode = "Warning";
				}
				//----------Появляем местного жителя.
				LAi_type_actor_Reset(characterFromID("Wilfred"));
				LAi_type_actor_Reset(characterFromID("Wilfred"));
				ChangeCharacterAddress(characterFromID("Wilfred"), "Oxbay_shore_02", "locator8");
				LAi_SetActorType(pchar);
				LAi_ActorFollow(pchar, characterFromID("Wilfred"), "", 10.0);
				LAi_ActorFollow(characterFromID("Wilfred"), pchar, "Story_Blaze_and_Glover_Land_troops_speak", 10.0);
			}
			else
			{
				pchar.quest.ewan_again_gain_quest_for_night.win_condition.l1 = "ExitFromLocation";
				pchar.quest.ewan_again_gain_quest_for_night.win_condition.l1.location = "Oxbay_shore_02";
				pchar.quest.ewan_again_gain_quest_for_night.win_condition = "ewan_again_gain_quest_for_night";
			}
		break;

		case "Story_Blaze_and_Glover_Land_troops_speak":
			LAi_type_actor_Reset(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("Wilfred"));
			LAi_type_actor_Reset(characterFromID("Wilfred"));
			LAi_ActorDialog(characterFromID("Wilfred"), Pchar, "", 20.0, 1.0);
		break;
		
		case "Story_Blaze_and_Glover_Land_troops_denied":
			pchar.quest.checker_for_greenford_tavern_for_meet_with_evan_glover.over = "yes";
			SetCharacterShipLocation(characterFromID("Ewan Glover"), "none");
			Locations[FindLocation("Greenford_town")].reload.l4.disable = 0;
			bQuestDisableMapEnter = false;
			AddQuestRecord("Story_2ndTask", "8");
			//--------Зачисляем игроку проваленный квест
			Pchar.quest.Story_Glover_sunk = true;
			//--------Стартуем вторую половину задания
			Pchar.quest.Story_2ndTask = "Second_part";
			LAi_SetSitType(characterFromID("Counterspy"));
			ChangeCharacterAddressGroup(characterFromID("CounterSpy"), "Oxbay_tavern", "Sit", "Sit6");
			Characters[GetCharacterIndex("CounterSpy")].Dialog.CurrentNode = "Met_Blaze";
			Characters[GetCharacterIndex("Wilfred")].Dialog.CurrentNode = "Failed_in_last_moment";
			//LAi_ActorDialog(characterFromID("Wilfred"), Pchar, "", 5.0, 1.0);
		break;
		
		case "Story_Wilfred_scared_run_away":
			LAi_group_MoveCharacter(characterFromID("Wilfred"), LAI_GROUP_ACTOR); 
		break;

		case "Wilfred_exit_complete":
			//-----------Возвращаем игрока в таверну Гринфорда на след. день
			LAi_SetImmortal(characterFromID("Wilfred"), false);
			ChangeCharacterAddress(characterFromID("Eng_land_soldier_01"), "None", "");
			ChangeCharacterAddress(characterFromID("Eng_land_soldier_02"), "None", "");
			ChangeCharacterAddress(characterFromID("Eng_land_soldier_03"), "None", "");
			ChangeCharacterAddress(characterFromID("Eng_land_soldier_04"), "None", "");
			ChangeCharacterAddress(characterFromID("Wilfred"), "None", "");
			SetCharacterShipLocation(Pchar, "Greenford_port");
			SetCharacterShipLocation(characterFromID("Ewan Glover"), "None");
			ChangeCharacterAddress(characterFromID("Ewan Glover"), "Greenford_Tavern", "Goto1");
			SetCurrentTime(10, 0);
			DoQuestReloadToLocation("Greenford_tavern", "Goto", "goto17", "Story_ReturnedToGreenfordTavern");
		break;

		case "Story_kill_french_patrol":
			AddPartyExp(pchar, 2500);
			LAi_ActorFollow(characterFromID("Wilfred"), pchar, "Story_kill_french_patrol_3", 10.0);
			LAi_QuestDelay("Story_kill_french_patrol_2", 3.0);
		break;
		
		case "Story_kill_french_patrol_2":
			LAi_SetActorType(pchar);
			LAi_ActorFollow(pchar, characterFromID("Wilfred"), "", 10.0);
			AddQuestRecord("Story_2ndTask", "7");
		break;
		
		case "Story_kill_french_patrol_3":
			LAi_ActorWaitDialog(pchar, characterFromID("Wilfred"));
			Characters[GetCharacterIndex("Wilfred")].Dialog.CurrentNode = "Victory";
			LAi_ActorDialog(characterFromID("Wilfred"), Pchar, "", 10.0, 1.0);
		break;

		case "Story_ReturnedToGreenfordTavern":
			Locations[FindLocation("Oxbay_shore_02")].reload.l3.disable = 0;
			LAi_group_SetRelation(LAI_DEFAULT_GROUP, LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
			LAi_group_SetRelation("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
			LAi_group_SetRelation("ENGLAND_CITIZENS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
			pchar.quest.Story_Blaze_and_Glover_Land_troops.over = "yes";
			pchar.quest.Story_Blaze_and_Glover_Land_troops_denied.over = "yes";
			pchar.quest.story_glover_to_tavern_on_greenford.over = "yes";
			pchar.quest.story_convoy_glover_to_greenford.over = "yes";
			
			//-----------Возвращаем возможность выхода в карту
			bQuestDisableMapEnter = false;
			//-----------Эван Глоувер начинает диалог с игроком.
			LAi_SetActorType(characterFromID("Ewan Glover"));
			LAi_SetActorType(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("Ewan Glover"));
			Characters[GetCharacterIndex("Ewan Glover")].dialog.CurrentNode = "GoodBye";

			ChangeCharacterAddress(characterFromID("Eng_land_soldier_01"), "none", "");
			ChangeCharacterAddress(characterFromID("Eng_land_soldier_02"), "none", "");
			ChangeCharacterAddress(characterFromID("Eng_land_soldier_03"), "none", "");
			ChangeCharacterAddress(characterFromID("Eng_land_soldier_04"), "none", "");
			ChangeCharacterAddress(characterFromID("Wilfred"), "none", "");

			LAi_ActorDialog(characterFromID("Ewan Glover"), Pchar, "", 3.0.0, 1.0);
			LAi_SetSitType(characterFromID("CounterSpy"));
			ChangeCharacterAddressGroup(characterFromID("CounterSpy"), "Oxbay_tavern", "Sit", "Sit6");
		break;

		case "Story_KillFrenchArresters":
			Locations[FindLocation("Oxbay_shore_02")].reload.l3.disable = 0;
			pchar.quest.Story_Blaze_reaches_Greenford.over = "yes";
			ChangeCharacterAddress(characterfromID("Wilfred"), "none", "");
			AddPartyExp(pchar, 1500);
			LAi_LocationFightDisable(&Locations[FindLocation("Oxbay_tavern")], true);
			ChangeCharacterAddress(characterFromID("Fra_arrester_01"), "none", "");
			ChangeCharacterAddress(characterFromID("Fra_arrester_02"), "none", "");
			ChangeCharacterAddress(characterFromID("Fra_arrester_03"), "none", "");
			LAi_SetFightMode(pchar, false);
			LAi_QuestDelay("Story_AMinuteLaterAfterKillingFrenchArresters", 2.0);
		break;

		case "Story_AMinuteLaterAfterKillingFrenchArresters":
			/*LAi_group_SetAlarm(LAI_DEFAULT_GROUP, LAI_GROUP_PLAYER, 0.0);
			LAi_group_SetAlarm("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, 0.0);
			LAi_group_SetAlarm("ENGLAND_CITIZENS", LAI_GROUP_PLAYER, 0.0);*/
			LAi_group_SetRelation(LAI_DEFAULT_GROUP, LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
			LAi_group_SetRelation("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
			LAi_group_SetRelation("ENGLAND_CITIZENS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
			LAi_group_SetRelation(LAI_DEFAULT_GROUP, "FRANCE_SOLDIERS", LAI_GROUP_FRIEND);

			AddQuestRecord("Story_2ndTask", "9");
			LAi_SetImmortal(characterFromID("Counterspy"), true);
			LAi_SetActorType(characterFromID("Counterspy"));
			LAi_Fade("Story_AMinuteLaterAfterKillingFrenchArresters_2", "");
		break;

		case "Story_AMinuteLaterAfterKillingFrenchArresters_2":
			LAi_SetFightMode(pchar, false);
			LAi_SetPlayerType(pchar);
			ChangeCharacterAddress(characterFromID("Counterspy"), "Oxbay_tavern", "goto2");
			ChangeCharacterAddress(pchar, "oxbay_tavern", "goto3");
			Characters[GetCharacterIndex("Counterspy")].Dialog.CurrentNode = "After_Fight";
			LAi_ActorDialogNow(characterFromID("Counterspy"), Pchar, "", -1);

			Pchar.quest.Story_RunToTheShipyardThroughOxbay.win_condition.l1 = "location";
			Pchar.quest.Story_RunToTheShipyardThroughOxbay.win_condition.l1.location = "Oxbay_town";
			Pchar.quest.Story_RunToTheShipyardThroughOxbay.win_condition = "Story_RunToTheShipyardThroughOxbay";
		break;

		case "Story_RunToTheShipyardThroughOxbay":
			Locations[FindLocation("Oxbay_town")].reload.l1.disable = 1;
			Locations[FindLocation("Oxbay_town")].reload.l2.disable = 1;
			Locations[FindLocation("Oxbay_town")].reload.l3.disable = 1;
			Locations[FindLocation("Oxbay_town")].reload.l4.disable = 1;
			Locations[FindLocation("Oxbay_town")].reload.l7.close_for_night = 0;
			LAi_SetActorType(characterFromID("Counterspy"));
			LAi_ActorRunToLocator(characterFromID("Counterspy"), "Reload", "reload3", "Story_CounterspyWentToShipyardBeforeBlaze", 25.0);
			
			if(GetOfficersIndex(Pchar, 1) != -1 && GetOfficersIndex(Pchar, 1) != GetCharacterIndex("counterspy"))
			{
				iPassenger = GetOfficersIndex(Pchar, 1);
				LAi_SetActorType(&characters[iPassenger]);
				LAi_ActorRunToLocation(&characters[iPassenger], "reload", "reload3", "none", "", "", "", 25.0);
			}
			if(GetOfficersIndex(Pchar, 2) != -1 && GetOfficersIndex(Pchar, 2) != GetCharacterIndex("counterspy"))
			{
				iPassenger = GetOfficersIndex(Pchar, 2);
				LAi_SetActorType(&characters[iPassenger]);
				LAi_ActorRunToLocation(&characters[iPassenger], "reload", "reload3", "none", "", "", "", 25.0);
			}
			if(GetOfficersIndex(Pchar, 3) != -1 && GetOfficersIndex(Pchar, 3) != GetCharacterIndex("counterspy"))
			{
				iPassenger = GetOfficersIndex(Pchar, 3);
				LAi_SetActorType(&characters[iPassenger]);
				LAi_ActorRunToLocation(&characters[iPassenger], "reload", "reload3", "none", "", "", "", 25.0);
			}
		break;

		case "Story_CounterspyWentToShipyardBeforeBlaze":
			ChangeCharacterAddress(characterFromID("Counterspy"),"Oxbay_Shipyard", "goto11");
		break;

		case "Story_Goto_Oxbay_shipyard_with_Counterspy":
			if(GetOfficersIndex(Pchar, 1) != -1 && GetOfficersIndex(Pchar, 1) != GetCharacterIndex("counterspy"))
			{
				iPassenger = GetOfficersIndex(Pchar, 1);
				LAi_SetOfficerType(&characters[iPassenger]);
			}
			if(GetOfficersIndex(Pchar, 2) != -1 && GetOfficersIndex(Pchar, 2) != GetCharacterIndex("counterspy"))
			{
				iPassenger = GetOfficersIndex(Pchar, 2);
				LAi_SetOfficerType(&characters[iPassenger]);
			}
			if(GetOfficersIndex(Pchar, 3) != -1 && GetOfficersIndex(Pchar, 3) != GetCharacterIndex("counterspy"))
			{
				iPassenger = GetOfficersIndex(Pchar, 3);
				LAi_SetOfficerType(&characters[iPassenger]);
			}			
			LAi_SetActorType(characterFromID("Counterspy"));
			LAi_type_actor_Reset(characterFromID("Counterspy"));
			LAi_SetImmortal(characterFromID("Counterspy"), true);
			LAi_SetImmortal(characterFromID("Oweyn McDorey"), true);
			Characters[GetCharacterIndex("Oweyn McDorey")].Dialog.CurrentNode = "Blaze and Counterspy";
			LAi_SetActorType(characterFromID("Oweyn MCDorey"));
			LAi_ActorDialog(characterFromID("Oweyn MCDorey"), Pchar, "", 5.0, 0);
			LAi_SetActorType(pchar);
			LAi_ActorFollow(pchar, characterFromID("Oweyn MCDorey"), "Story_Goto_Oxbay_shipyard_with_Counterspy_2", 1.0);
		break;

		case "Story_Goto_Oxbay_shipyard_with_Counterspy_2":
			LAi_ActorWaitDialog(pchar, characterFromID("Oweyn MCDorey"));
		break;

		case "Blaze_and_Counterspy_exit_from_shipyard":
			RemovePassenger(Pchar, characterFromID("Counterspy"));
			//----------------перегрузить игрока и шпиона наверх верфи
			LAi_Fade("Blaze_and_Counterspy_exit_from_shipyard_2", "Story_HiddenInShipyardWatch");
		break;

		case "Blaze_and_Counterspy_exit_from_shipyard_2":
			if(GetOfficersIndex(Pchar, 1) != -1 && GetOfficersIndex(Pchar, 1) != GetCharacterIndex("counterspy"))
			{
				iPassenger = GetOfficersIndex(Pchar, 1);
				LAi_SetActorType(&characters[iPassenger]);
				LAi_ActorSetSitMode(&characters[iPassenger]);
				ChangeCharacterAddress(&characters[iPassenger], "none", "goto11");
			}
			if(GetOfficersIndex(Pchar, 2) != -1 && GetOfficersIndex(Pchar, 2) != GetCharacterIndex("counterspy"))
			{
				iPassenger = GetOfficersIndex(Pchar, 2);
				LAi_SetActorType(&characters[iPassenger]);
				LAi_ActorSetSitMode(&characters[iPassenger]);
				ChangeCharacterAddress(&characters[iPassenger], "none", "goto11");
			}
			if(GetOfficersIndex(Pchar, 3) != -1 && GetOfficersIndex(Pchar, 3) != GetCharacterIndex("counterspy"))
			{
				iPassenger = GetOfficersIndex(Pchar, 3);
				LAi_SetActorType(&characters[iPassenger]);
				LAi_ActorSetSitMode(&characters[iPassenger]);
				ChangeCharacterAddress(&characters[iPassenger], "none", "goto11");
			}	
			LAi_ActorSetSitMode(pchar);
			LAi_ActorSetSitMode(characterFromID("CounterSpy"));
			
			locx = stf(loadedLocation.locators.camera.camera_2.x);
			locy = stf(loadedLocation.locators.camera.camera_2.y);
			locz = stf(loadedLocation.locators.camera.camera_2.z);
			locCameraToPos(locx, locy, locz, false);

			ChangeCharacterAddress(pchar, "Oxbay_shipyard", "goto9");
			ChangeCharacterAddress(characterFromID("Counterspy"), "Oxbay_Shipyard", "goto11");
		break;

		case "Story_HiddenInShipyardWatch":
			//----------------Зафиксить камеру в нужном локаторе
			LAi_QuestDelay("Story_HiddenInShipyardWatch_2", 1.0);
		break;

		case "Story_HiddenInShipyardWatch_2":
			//----------------- Явить солдат сквозь дверь.
			ChangeCharacterAddressGroup(characterFromID("Fra_arrester_04"),"Oxbay_Shipyard", "Reload","reload1");
			ChangeCharacterAddressGroup(characterFromID("Fra_arrester_05"),"Oxbay_Shipyard", "Reload","reload1");
			ChangeCharacterAddressGroup(characterFromID("Fra_arrester_06"),"Oxbay_Shipyard", "Reload","reload1");
			//----------------Начать диалог между солдатами и Оуэном
			LAi_SetActorType(characterFromID("Fra_arrester_04"));
			LAi_SetActorType(characterFromID("Fra_arrester_05"));
			LAi_SetActorType(characterFromID("Fra_arrester_06"));

			LAi_ActorGoToLocator(characterFromID("Fra_arrester_05"), "Goto", "Goto12", "", 8.4);
			LAi_ActorGoToLocator(characterFromID("Fra_arrester_06"), "Goto", "Goto2", "", 8.4);
			LAi_ActorWaitDialog(characterFromID("Oweyn McDorey"), characterFromID("Fra_arrester_04"));
			LAi_ActorDialog(characterFromID("Fra_arrester_04"), characterFromID("Oweyn McDorey"), "", 5.0, 5.0);
			
			LAi_QuestDelay("Story_BlazeHidesInShipyard_FrenchSoldiersFinishTalking", 8.5);
		break;

		case "Story_AfterHiddenInShipyardWatch":
			pchar.quest.Story_RunToTheShipyardThroughOxbay.over = "yes";
			Characters[getCharacterIndex("Counterspy")].Dialog.CurrentNode = "Officer_Money";
			LAi_ActorDialog(characterFromID("Counterspy"), Pchar, "", 5.0, 0);
		break;

		case "Story_Glover_leaves_on_complete":
			ChangeCharacterAddress(characterFromID("Ewan Glover"), "none", "");
			LAi_SetPlayerType(Pchar);
		break;
		
		case "Story_BlazeHidesInShipyard_FrenchSoldiersFinishTalking":
			LAi_type_actor_Reset(characterFromID("Fra_arrester_04"));
			LAi_type_actor_Reset(characterFromID("Fra_arrester_05"));
			LAi_type_actor_Reset(characterFromID("Fra_arrester_06"));
			LAi_ActorGoToLocation(characterFromID("Fra_arrester_04"), "reload", "Reload1", "none", "Reload", "reload1", "", 5.8);
			LAi_ActorGoToLocation(characterFromID("Fra_arrester_05"), "reload", "Reload1", "none", "Reload", "reload1", "", 5.8);
			LAi_ActorGoToLocation(characterFromID("Fra_arrester_06"), "reload", "Reload1", "none", "Reload", "reload1", "", 5.8);
			LAi_QuestDelay("Story_FrenchSoldiersGoneFromShipyard", 9.5);
		break;

		case "Story_FrenchSoldiersGoneFromShipyard":
			ChangeCharacterAddressGroup(characterFromID("Fra_arrester_04"),"none", "Reload","reload1");
			ChangeCharacterAddressGroup(characterFromID("Fra_arrester_05"),"none", "Reload","reload1");
			ChangeCharacterAddressGroup(characterFromID("Fra_arrester_06"),"none", "Reload","reload1");
			LAi_SetImmortal(characterFromID("Oweyn McDorey"), false);
			Characters[GetCharacterIndex("Oweyn McDorey")].Dialog.CurrentNode = "Soldiers left";
			LAi_SetImmortal(characterFromID("Counterspy"), true);
			LAi_SetActorType(characterFromID("Counterspy"));
			LAi_ActorSetStayMode(characterFromID("CounterSpy"));

			Locations[FindLocation("Oxbay_town")].reload.l1.disable = 0;
			Locations[FindLocation("Oxbay_town")].reload.l2.disable = 0;
			Locations[FindLocation("Oxbay_town")].reload.l3.disable = 0;
			Locations[FindLocation("Oxbay_town")].reload.l4.disable = 0;

			LAi_Fade("Story_FrenchSoldiersGoneFromShipyard_2", "Story_McDoreyStartTalking");
		break;

		case "Story_FrenchSoldiersGoneFromShipyard_2":
			ChangeCharacterAddress(characterFromID("Oweyn MCDorey"), "Oxbay_shipyard", "goto3");
			ChangeCharacterAddress(characterFromID("Counterspy"), "Oxbay_shipyard", "Goto7");
			ChangeCharacterAddress(pchar, "Oxbay_shipyard", "Goto8");
			locCameraFollow();
			LAi_SetPlayerType(Pchar);
		break;

		case "Story_McDoreyStartTalking":
			LAi_type_actor_Reset(characterFromID("Oweyn MCDorey"));
			LAi_ActorDialog(characterFromID("Oweyn MCDorey"), Pchar, "", 2.0, 1.0);
		break;

		case "Story_WaitingForEveningInTheShipyard":
			LAi_QuestDelay("Story_ReadyToGiveBribe", 1.0);
			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_NEITRAL);
			LAi_group_SetRelation("ENGLAND_CITIZENS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
			LAi_group_SetRelation(LAI_DEFAULT_GROUP, LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
		break;
		
		case "Story_ReadyToGiveBribe":
			Characters[GetCharacterIndex("Counterspy")].dialog.CurrentNode = "Ready_for_meeting";
			LAi_ActorDialog(characterFromID("Counterspy"),Pchar, "", 2.0, 1.0);
		break;

		case "Story_Blaze_and_Rabel_Leave_tavern":
			LAi_SetActorType(characterFromID("Rabel Iverneau"));
			LAi_SetImmortal(characterFromID("Rabel Iverneau"), true);
			LAi_SetImmortal(characterFromID("Counterspy"), true);
			Characters[GetCharacterIndex("Counterspy")].Dialog.CurrentNode = "Talk_AfterTavern";
			ChangeCharacterAddress(characterFromID("Rabel Iverneau"), "Oxbay_town", "goto41");
			ChangeCharacterAddress(characterFromID("Counterspy"), "Oxbay_town", "goto10");
			LAi_ActorWaitDialog(characterFromID("Counterspy"), pchar);
			DoQuestReloadToLocation("Oxbay_town", "Reload", "Reload13", "Story_BlazeAndRabelGoToMeetCounterspy");
			Locations[FindLocation("Oxbay_town")].reload.l7.close_for_night = 1;
		break;

		case "Story_BlazeAndRabelGoToMeetCounterspy":
			LAi_ActorFollow(characterFromID("Rabel Iverneau"), Pchar, "", -1);
			//SetShipRemovable(ref _refCharacter, bool bRemovable)
		break;

		case "Story_CounterspyGoesToPort":
			ChangeCharacterAddress(characterFromID("Counterspy"), "Oxbay_port", "goto10");
		break;

		case "Story_RabelGoesToPort":
			ChangeCharacterAddress(characterFromID("Rabel Iverneau"), "Oxbay_port", "goto8");
		break;

		case "Story_LeaveOxbayWithRabelAndCounterspy":
			Locations[FindLocation("Oxbay_port")].reload.l2.disable = 1;
			Locations[FindLocation("Oxbay_port")].reload.l3.disable = 1;
			//---------На случай, если игрок первым добежит до ворот.
			PlaceCharacter(characterFromID("Counterspy"), "officers", "Oxbay_port");
			PlaceCharacter(characterFromID("Rabel Iverneau"), "officers", "Oxbay_port");

			LAi_type_actor_Reset(characterFromID("counterspy"));
			LAi_type_actor_Reset(characterFromID("Rabel Iverneau"));

			LAi_SetActorType(characterFromID("Fra_occupant_05"));
			LAi_SetActorType(pchar);
			
			LAi_ActorFollow(pchar, characterFromID("Fra_occupant_05"), "", 1.0);
			LAi_ActorFollow(characterFromID("Fra_occupant_05"), pchar, "Story_LeaveOxbayWithRabelAndCounterspy_2", 1.0);
		break;
		
		case "Story_LeaveOxbayWithRabelAndCounterspy_2":
			LAi_type_actor_Reset(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("Fra_occupant_05"));
			Characters[GetCharacterIndex("Fra_occupant_05")].Dialog.Filename = "Leaving_Oxbay_dialog.c";
			LAi_ActorDialog(characterFromID("Fra_occupant_05"), Pchar, "pchar_back_to_player", 1.0, 1.0);
		break;

		case "Story_Follow_Rabel_And_Counterspy":
			if (characters[GetCharacterIndex("Rabel Iverneau")].location == "none" && characters[GetCharacterIndex("counterspy")].location == "none")
			{
				characters[GetCharacterIndex("Oxbay Commander")].skill.Accuracy = 2;
				characters[GetCharacterIndex("Oxbay Commander")].skill.cannons = 2;
				Locations[FindLocation("Oxbay_port")].reload.l2.disable = 0;
				Locations[FindLocation("Oxbay_port")].reload.l3.disable = 0;
				Pchar.quest.Story_BlazeEscapedFromOxbay.win_condition.l1 = "Location";
				Pchar.quest.Story_BlazeEscapedFromOxbay.win_condition.l1.location = "Redmond";
				Pchar.quest.Story_BlazeEscapedFromOxbay.win_condition = "Story_BlazeEscapedFromOxbay";
				Pchar.quest.Story_BlazeEscapedFromOxbay_cheat_fix.win_condition.l1 = "MapEnter";
				Pchar.quest.Story_BlazeEscapedFromOxbay_cheat_fix.win_condition = "Story_BlazeEscapedFromOxbay_cheat_fix";
				characters[GetCharacterIndex("Rabel Iverneau")].skill.Sailing = 10;
				characters[GetCharacterIndex("Rabel Iverneau")].skill.Repair = 10;
				characters[GetCharacterIndex("Rabel Iverneau")].rank = 11;
				characters[GetCharacterIndex("Rabel Iverneau")].reputation = 54;
				characters[GetCharacterIndex("Rabel Iverneau")].experience = CalculateExperienceFromRank(11)+ (CalculateExperienceFromRank(11)/10 + rand(11000));
				characters[GetCharacterIndex("Rabel Iverneau")].perks.list.BasicBattleState = true;
				characters[GetCharacterIndex("Rabel Iverneau")].perks.list.AdvancedBattleState = true;
				characters[GetCharacterIndex("Rabel Iverneau")].perks.list.ShipDefenseProfessional = true;
				characters[GetCharacterIndex("Rabel Iverneau")].perks.list.LightRepair = true;
				characters[GetCharacterIndex("Rabel Iverneau")].perks.list.ShipSpeedUp = true;
				SetOfficersIndex(Pchar, 3, GetCharacterIndex("Rabel Iverneau"));
				SetCharacterRemovable(characterFromID("Rabel Iverneau"), false);
				SetCharacterRemovable(characterFromID("Counterspy"), false);
			}
			DoQuestCheckDelay("Story_Follow_Rabel_And_Counterspy_2", 20.0);
		break;
		
		case "Story_BlazeEscapedFromOxbay_cheat_fix":
			RemoveOfficersIndex(pchar, GetCharacterIndex("Rabel Iverneau"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Counterspy"));
		break;
		
		case "Story_Follow_Rabel_And_Counterspy_2":
			Group_SetTaskAttack("Story_French_Squadron", PLAYER_GROUP);
			Group_LockTask("Story_French_Squadron");
			SetShipRemovable(pchar, false);
		break;

		case "Story_RabelSuggestsToRun":
			LAi_type_actor_Reset(characterFromID("Rabel Iverneau"));
			LAi_ActorDialogNow(characterFromID("Rabel Iverneau"), pchar, "", -1);
		break;

		case "Story_PlayerTriesToRunFromOxbay":
			LAi_QuestDelay("Story_PlayerTriesToRunFromOxbay_2", 6.0);
		break;

		case "Story_PlayerTriesToRunFromOxbay_2":
			sld = LAi_CreateFantomCharacter("Soldier_fra", "reload", "reload1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			
			sld = LAi_CreateFantomCharacter("Soldier_fra2", "reload", "reload1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			
			sld = LAi_CreateFantomCharacter("Soldier_fra3", "reload", "reload1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			
			sld = LAi_CreateFantomCharacter("Soldier_fra4", "reload", "reload1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			
			sld = LAi_CreateFantomCharacter("Soldier_fra5", "reload", "reload1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");

			LAi_group_MoveCharacter(characterFromID("Fra_occupant_05"), "FRANCE_SOLDIERS");

			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, true);
		break;

		case "Story_CapturedByHotPursuit":
			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			
			sld = LAi_CreateFantomCharacter("Soldier_fra", "reload", "reload1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			
			sld = LAi_CreateFantomCharacter("Soldier_fra2", "reload", "reload1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			
			sld = LAi_CreateFantomCharacter("Soldier_fra3", "reload", "reload1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			
			sld = LAi_CreateFantomCharacter("Soldier_fra4", "reload", "reload1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			
			sld = LAi_CreateFantomCharacter("Soldier_fra5", "reload", "reload1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			
			LAi_group_MoveCharacter(characterFromID("Fra_occupant_05"), "FRANCE_SOLDIERS");

			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, true);
		break;

		case "Story_BlazeEscapedFromOxbay":
			characters[GetCharacterIndex("Oxbay Commander")].skill.Accuracy = 9;
			characters[GetCharacterIndex("Oxbay Commander")].skill.cannons = 5;
			locations[FindLocation("Redmond_town_01")].reload.l11.go = "quest_redmond_tavern";
			RecalculateJumpTable();
			RemovePassenger(Pchar, characterFromID("Counterspy"));
			RemovePassenger(Pchar, characterFromID("Rabel Iverneau"));
			LAi_SetActorType(characterFromID("Rabel Iverneau"));
			ChangeCharacterAddress(characterFromID("Robert Christopher Silehard"), "Redmond_residence", "goto8");
			ChangeCharacterAddress(characterFromID("Counterspy"), "Redmond_residence", "goto3");
			ChangeCharacterAddress(characterFromID("Rabel Iverneau"), "Redmond_residence", "goto2");
			DoReloadFromSeaToLocation("Redmond_residence","goto", "goto1");
			pchar.quest.Story_BlazeWithRabelAndCounterspyReturn.win_condition.l1 = "location";
			pchar.quest.Story_BlazeWithRabelAndCounterspyReturn.win_condition.l1.location = "redmond_residence";
			pchar.quest.Story_BlazeWithRabelAndCounterspyReturn.win_condition = "Story_BlazeWithRabelAndCounterspyReturn";
			Locations[FindLocation("Falaise_De_Fleur_location_03")].reload.l3.disable = 0;
			SetShipRemovable(pchar, true);
		break;

		case "Story_BlazeWithRabelAndCounterspyReturn":
			RestorePassengers("Blaze");
			if(GetOfficersIndex(Pchar, 1) != -1 && GetOfficersIndex(Pchar, 1) != GetCharacterIndex("counterspy"))
			{
				iPassenger = GetOfficersIndex(Pchar, 1);
				LAi_SetOfficerType(&characters[iPassenger]);
			}
			if(GetOfficersIndex(Pchar, 2) != -1 && GetOfficersIndex(Pchar, 2) != GetCharacterIndex("counterspy"))
			{
				iPassenger = GetOfficersIndex(Pchar, 2);
				LAi_SetOfficerType(&characters[iPassenger]);
			}
			if(GetOfficersIndex(Pchar, 3) != -1 && GetOfficersIndex(Pchar, 3) != GetCharacterIndex("counterspy"))
			{
				iPassenger = GetOfficersIndex(Pchar, 3);
				LAi_SetOfficerType(&characters[iPassenger]);
			}	
			
			Pchar.quest.Story_BlazeEscapedFromOxbay.over = "yes";
			LAi_SetActorType(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("Robert Christopher Silehard"));
			pchar.ship.type = SHIP_NOTUSED;
			ExchangeCharacterShip(Pchar, characterFromID("Ship Storage"));
			SetCharacterShipLocation(Pchar, "Redmond_port");

			LAi_type_actor_Reset(characterFromID("Rabel Iverneau"));
			LAi_type_actor_Reset(characterFromID("Counterspy"));
			LAi_ActorTurnToCharacter(characterFromID("Rabel Iverneau"), characterFromID("Robert Christopher Silehard"));
			LAi_QuestDelay("Story_RabelLeavesResidence", 1.0);
			
			Characters[GetCharacterIndex("Robert Christopher Silehard")].dialog.CurrentNode = "Story_2ndTask_complete";
		break;

		case "Story_CounterspyLeavesResidence":
			LAi_ActorGoToLocation(characterFromID("Counterspy"), "reload", "reload1", "none", "reload", "reload1", "", 5.0);
			LAi_SetActorType(characterFromID("Robert Christopher Silehard"));
			LAi_ActorDialog(characterFromID("Robert Christopher Silehard"), PChar, "back_to_hovernor_type", 5.0, 0);
		break;

		case "Story_RabelLeavesResidence":
			LAi_ActorDialog(characterFromID("Counterspy"), characterFromID("Robert Christopher Silehard"), "Story_CounterspyLeavesResidence", 2.0, 1.0);
			LAi_type_actor_Reset(characterFromID("Rabel Iverneau"));
			LAi_ActorGoToLocation(characterFromID("Rabel Iverneau"), "reload", "Reload1", "none", "reload", "reload1", "", 5.0);
			LAi_QuestDelay("Story_SilehardCongratulateWith2ndComplete", 2.0);
		break;

		case "Story_SilehardCongratulateWith2ndComplete":
			pchar.quest.story_playertriestorunfromoxbay.over = "yes";
			LAi_type_actor_Reset(characterFromID("Counterspy"));
			LAi_ActorGoToLocation(characterFromID("Counterspy"), "reload", "Reload1", "none", "reload", "reload1", "", 4.0);
			SetCharacterShipLocation(Pchar, "Redmond_port");
			LAi_SetActorType(characterFromID("Robert Christopher Silehard"));
			LAi_ActorDialog(characterFromID("Robert Christopher Silehard"), PChar, "back_to_hovernor_type", 5.0, 0);
		break;

		case "Story_DanielleWaitsInMuelleTown":
			pchar.quest.Story_AppearOnIslaMuelleonAnacletoShip.over = "yes";
			ChangeCharacterAddress(characterFromID("danielle"), "muelle_tavern", "goto6");
			Characters[GetCharacterIndex("Danielle")].dialog.CurrentNode  = "MetBlazeOnIslaMuelle";
			LAi_SetActorType(characterFromID("danielle"));
			LAi_ActorDialog(characterFromID("Danielle"), Pchar, "", 5.0, 1.0);
		break;

		case "Story_AppearOnIslaMuelleonAnacletoShip":
			iPassenger = makeint(Pchar.Temp.Officer.idx1);
			
			PlaceCharacter(&Characters[iPassenger], "officers", "Muelle_port");
						
			LAi_SetActorType(&Characters[iPassenger]);
			Characters[iPassenger].Dialog.Filename = "Found_Blaze_1_dialog.c";
			Characters[iPassenger].Dialog.currentnode = "First time";
			LAi_ActorDialog(&Characters[iPassenger], Pchar, "", 8.0, 1.0);
			
			iPassenger = makeint(Pchar.Temp.Officer.idx2);
			
			PlaceCharacter(&Characters[iPassenger], "officers", "Muelle_port");
			
			LAi_SetActorType(&Characters[iPassenger]);
			Characters[iPassenger].Dialog.Filename = "Found_Blaze_2_dialog.c";
			Characters[iPassenger].Dialog.currentnode = "First time";
			LAi_ActorFollow(&Characters[iPassenger], pchar, "", 8.0);
			
			iPassenger = makeint(Pchar.Temp.Officer.idx3);
			
			PlaceCharacter(&Characters[iPassenger], "goto", "Muelle_port");
			
			LAi_SetActorType(&Characters[iPassenger]);
			Characters[iPassenger].Dialog.Filename = "Found_Blaze_3_dialog.c";
			Characters[iPassenger].Dialog.currentnode = "First time";
			LAi_ActorFollow(&Characters[iPassenger], pchar, "", 8.0);

			ChangeCharacterAddress(characterFromID("Danielle"), "Muelle_Tavern", "goto2");
		break;

		case "Story_OfficersShutUpAfterFoundBlaze":
			iPassenger = makeint(Pchar.Temp.Officer.idx1);
			Characters[iPassenger].Dialog.CurrentNode = "Explanation";
			LAi_ActorDialogNow(&Characters[iPassenger], Pchar, "", -1);
			
			iPassenger = makeint(Pchar.Temp.Officer.idx2);
			LAi_ActorTurnToCharacter(&Characters[iPassenger], Pchar);
			
			iPassenger = makeint(Pchar.Temp.Officer.idx3);
			LAi_ActorTurnToCharacter(&Characters[iPassenger], Pchar);
		break;

		case "Story_OfficersGoToTavernWithBlaze":
			SetQuestHeader("Meet_Danielle_on_Muelle");
			AddQuestRecord("Meet_Danielle_on_Muelle", "3");
			ChangeCharacterAddress(characterFromID("Danielle"), "None", "");
			Pchar.Quest.Story_DanielleWaitsInMuelleTown.over = "yes";
			characters[getCharacterIndex("Tiago Marquina")].location = "none";
			characters[getCharacterIndex("Muelle_officiant")].location = "none";
			DoQuestReloadToLocation("Muelle_tavern", "sit","sit7", "Story_AppearedinMuelleTavernwithOfficers");
		break;

		case "Story_AppearedinMuelleTavernwithOfficers":
			ChangeCharacterAddress(characterFromID("danielle"), "none", "");
			
			iPassenger = makeint(Pchar.Temp.Officer.idx3);
			ChangeCharacterAddressGroup(&Characters[iPassenger], "Muelle_tavern", "Sit", "sit3");
			LAi_SetActorType(&Characters[iPassenger]);
			LAi_ActorSetSitMode(&Characters[iPassenger]);
			
			iPassenger = makeint(Pchar.Temp.Officer.idx2);
			ChangeCharacterAddressGroup(&Characters[iPassenger], "Muelle_tavern", "Sit", "sit4");
			LAi_SetActorType(&Characters[iPassenger]);
			LAi_ActorSetSitMode(&Characters[iPassenger]);
			
			iPassenger = makeint(Pchar.Temp.Officer.idx1);
			ChangeCharacterAddressGroup(&Characters[iPassenger], "Muelle_tavern", "Sit", "sit8");
			LAi_SetActorType(&Characters[iPassenger]);
			LAi_ActorSetSitMode(&Characters[iPassenger]);

			LAi_SetSitType(pchar);


			LAi_QuestDelay("Story_OfficersStartTalkInMuelleTavern", 0.5);
		break;

		case "Story_OfficersStartTalkInMuelleTavern":
			Characters[makeint(Pchar.Temp.Officer.idx3)].Dialog.CurrentNode = "Talk_In_Tavern";
			LAi_ActorDialogNow(&Characters[makeint(Pchar.Temp.Officer.idx3)], Pchar, "", -1);
		break;

		case "Story_CameToOgarrioHouse":
			LAi_ActorTurnToCharacter(characterFromID("Sidonio Ogarrio"), Pchar);
			LAi_QuestDelay("Story_OgarrioTalksToPlayer", 0.5);
		break;

		case "Story_OgarrioTalksToPlayer":
			LAi_ActorDialog(characterFromID("Sidonio Ogarrio"), Pchar, "", 5.0, 1.0);
		break;

		case "found_blaze_Exit_Danielle":
			LAi_type_actor_Reset(characterFromID("danielle"));
			Characters[GetCharacterIndex("Danielle")].dialog.CurrentNode  = "MetBlazeOnIslaMuelle";
			LAi_ActorDialog(characterFromID("Danielle"), Pchar, "", 10.0, 1.0);
		break;

		case "Story_BlazeMetDanielleOnIslaMuelle":
			ChangeCharacterAddress(characterFromID("Danielle"), "Muelle_Tavern_upstairs", "goto3");
			LAi_SetStayType(pchar);
			DoQuestReloadToLocation("Muelle_tavern_upstairs", "Goto", "Goto2", "Story_BlazeAndDanielleStartTalkinMuelleTavern");
			locations[FindLocation("Douwesen_town")].reload.l3.disable = false;
		break;

		case "Story_BlazeAndDanielleStartTalkinMuelleTavern":
			SetCurrentTime(22, 0);
			Characters[getCharacterIndex("Danielle")].Dialog.Filename = "danielle_dialog.c";
			Characters[getCharacterIndex("Danielle")].Dialog.CurrentNode = "Talk_upstairs";
			LAi_SetActorType(pchar);
			LAi_ActorFollow(pchar, characterFromID("danielle"), "Story_BlazeAndDanielleStartTalkinMuelleTavern_2", 2.0);
		break;
		
		case "Story_BlazeAndDanielleStartTalkinMuelleTavern_2":
			LAi_SetPlayerType(pchar);
			LAi_ActorDialog(characterFromID("Danielle"), Pchar, "", 1.0, 0);
		break;
		
		case "Story_BlazeLeavesDanielleRoom":
			LAi_SetPlayerType(pchar);
			pchar.location.locator = "";
			AddQuestRecord("Meet_Danielle_on_Muelle", "4");
			SetCurrentTime(9, 0);
			
			RestorePassengers("blaze");

			iPassenger = makeint(Pchar.Temp.Officer.idx1);
			if(Characters[iPassenger].id != "Blaze_Crewmember_01" && getOfficersIndex(Pchar, 1) != -1)
			{
				Characters[getOfficersIndex(Pchar, 1)].Dialog.Filename = Pchar.Temp.Officer.idx1.Dialog;
				Characters[getOfficersIndex(Pchar, 1)].Dialog.CurrentNode = Pchar.Temp.Officer.idx1.CurrentNode;
			}
			iPassenger = makeint(Pchar.Temp.Officer.idx2);
			if(Characters[iPassenger].id != "Blaze_Crewmember_02" && getOfficersIndex(Pchar, 2) != -1)
			{
				Characters[getOfficersIndex(Pchar, 2)].Dialog.Filename = Pchar.Temp.Officer.idx2.Dialog;
				Characters[getOfficersIndex(Pchar, 2)].Dialog.CurrentNode = Pchar.Temp.Officer.idx2.CurrentNode;
			}
			iPassenger = makeint(Pchar.Temp.Officer.idx3);
			if(Characters[iPassenger].id != "Blaze_Crewmember_03" && getOfficersIndex(Pchar, 3) != -1)
			{
				Characters[getOfficersIndex(Pchar, 3)].Dialog.Filename = Pchar.Temp.Officer.idx3.Dialog;
				Characters[getOfficersIndex(Pchar, 3)].Dialog.CurrentNode = Pchar.Temp.Officer.idx3.CurrentNode;
			}

			DeleteAttribute(characterFromID("danielle"), "ship");
			DeleteAttribute(PChar, "temp.officer");
			characters[GetCharacterIndex("danielle")].ship.type = SHIP_NOTUSED;
			AddMoneyToCharacter(pchar, 70000);
			/*if (pchar.ship.type != SHIP_TARTANE)
			{
				characters[GetCharacterIndex("danielle")].ship.type = pchar.ship.type;
				SetBaseShipData(characterFromID("danielle"));
			}*/
			
			if (Pchar.Temp.Companion.idx1 > 0)
			{
				iPassenger = Pchar.Temp.Companion.idx1;
				SetCompanionIndex(pchar, 1, iPassenger); 
			}
			if (Pchar.Temp.Companion.idx2 > 0)
			{
				iPassenger = Pchar.Temp.Companion.idx2;
				SetCompanionIndex(pchar, 2, iPassenger); 
			}
			if (Pchar.Temp.Companion.idx3 > 0)
			{
				iPassenger = Pchar.Temp.Companion.idx3;
				SetCompanionIndex(pchar, 3, iPassenger); 
			}
			DeleteAttribute(PChar, "temp.Companion");
			ExchangeCharacterShip(Pchar, characterFromID("Ship Storage"));
			pchar.location.from_sea = "Muelle_port";
			pchar.money = pchar.tempmoney;
			characters[getCharacterIndex("Tiago Marquina")].location = "Muelle_tavern";
			characters[getCharacterIndex("Muelle_officiant")].location = "Muelle_tavern";
			DoQuestReloadToLocation("Muelle_port", "Goto", "character4", "Story_BlazeMeetDanielleInMuellePort");
		break;

		case "danielle_Talk_upstairs_Exit":
			LAi_SetActorType(pchar);
	
			LAi_ActorGoToLocator(pchar, "reload", "reload1", "Story_BlazeLeavesDanielleRoom", 3.0);
			
			Locations[FindLocation("Oxbay_lighthouse")].locators_radius.goto.goto23 = 15.0;
			Pchar.quest.Speak_with_lighthouse_guards.win_condition.l1 = "location";
			Pchar.quest.Speak_with_lighthouse_guards.win_condition.l1.location = "Lighthouse_Inside";
			Pchar.quest.Speak_with_lighthouse_guards.win_condition = "Speak_with_lighthouse_guards";
			DeleteAttribute(&Locations[FindLocation("Oxbay_lighthouse")], "models.night.light");
			//Locations[FindLocation("Oxbay_lighthouse")].models.night.light = "";
		break;

		case "Story_BlazeMeetDanielleInMuellePort":
			//Locations[FindLocation("Muelle_Tavern_upstairs")].reload.l1.disable = 0;
			PlaceCharacter(characterFromID("danielle"), "goto", "Muelle_port");
			Characters[GetCharacterIndex("Danielle")].Dialog.CurrentNode = "MetInMuellePort";
			LAi_SetActorType(pchar);
			LAi_ActorFollow(pchar, characterFromID("danielle"), "", 2.0);
			LAi_ActorFollow(characterFromID("danielle"), pchar, "Story_BlazeMeetDanielleInMuellePort_2", 2.0);
		break;
		
		case "Story_BlazeMeetDanielleInMuellePort_2":
			LAi_type_actor_Reset(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("danielle"));
			LAi_ActorDialog(characterFromID("Danielle"), Pchar, "pchar_back_to_player", 1.0, 1.0);
			pchar.location.from_sea = "Muelle_port";
		break;

		case "danielle_MetInMuellePort_Exit":
			LAi_ActorRunToLocator(characterFromID("danielle"), "reload", "reload3", "Story_DanielleGoesToBlazeShip", 5.0);
			pchar.location.from_sea = "muelle_port";
			ChangeCharacterAddress(characterFromID("researcher"), "none", "");
		break;
			
		case "Story_DanielleGoesToBlazeShip":
			Island_SetReloadEnableGlobal("Oxbay", true);
			ChangeCharacterAddress(characterFromID("Danielle"), "None", "");
			ChangeCharacterAddress(characterFromID("Lighthouse_Guard_01"), "Lighthouse_Inside", "goto3");
			ChangeCharacterAddress(characterFromID("Lighthouse_Guard_02"), "Lighthouse_Inside", "goto2");
			ChangeCharacterAddress(characterFromID("Lighthouse_Officer"), "Lighthouse_Inside", "goto1");
			Locations[FindLocation("Oxbay_lighthouse")].reload.l4.disable = 0;

			/*if (characters[GetCharacterIndex("danielle")].ship.type != SHIP_NOTUSED)
			{
				SetCompanionIndex(pchar, -1, GetCharacterIndex("danielle")); 
			}
			else
			{*/
				SetOfficersIndex(Pchar, 1, GetCharacterIndex("Danielle"));
				LAi_SetOfficerType(characterFromID("danielle"));
			//}
			SetCharacterRemovable(characterFromID("Danielle"), false);

			Pchar.quest.Story_KillSoldiersAtLighthouse.win_condition.l1 = "NPC_Death";
			Pchar.quest.Story_KillSoldiersAtLighthouse.win_condition.l1.character = "Lighthouse_Guard_01";
			Pchar.quest.Story_KillSoldiersAtLighthouse.win_condition.l2 = "NPC_Death";
			Pchar.quest.Story_KillSoldiersAtLighthouse.win_condition.l2.character = "Lighthouse_Guard_02";
			Pchar.quest.Story_KillSoldiersAtLighthouse.win_condition.l3 = "NPC_Death";
			Pchar.quest.Story_KillSoldiersAtLighthouse.win_condition.l3.character = "Lighthouse_Officer";
			Pchar.quest.Story_KillSoldiersAtLighthouse.win_condition = "Story_KillSoldiersAtLighthouse";
			
			pchar.quest.to_lighthouse_after_danielle_join.win_condition.l1 = "location";
			pchar.quest.to_lighthouse_after_danielle_join.win_condition.l1.location = "Oxbay_lighthouse";
			pchar.quest.to_lighthouse_after_danielle_join.win_condition = "to_lighthouse_after_danielle_join";
		break;
		
		case "to_lighthouse_after_danielle_join":
			PlaceCharacter(characterFromID("danielle"), "goto", "Oxbay_lighthouse");
			LAi_SetOfficerType(characterFromID("danielle"));
		break;

		case "Story_KillSoldiersAtLighthouse":
			characters[GetCharacterIndex("Lighthouse_Guard_01")].location = "none";
			characters[GetCharacterIndex("Lighthouse_Guard_02")].location = "none";
			characters[GetCharacterIndex("Lighthouse_Officer")].location = "none";

			AddQuestRecord("Meet_Danielle_on_Muelle","5");
	
			pchar.quest.Story_TalkAfterKillingSoldiersatLighthouse.win_condition.l1 = "location";
			pchar.quest.Story_TalkAfterKillingSoldiersatLighthouse.win_condition.l1.location = "Oxbay_Lighthouse";
			pchar.quest.Story_TalkAfterKillingSoldiersatLighthouse.win_condition = "Story_TalkAfterKillingSoldiersatLighthouse";
		break;

		case "Story_TalkAfterKillingSoldiersatLighthouse":
			PlaceCharacter(characterFromID("danielle"), "goto", "Oxbay_lighthouse");
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("danielle"));
			Lai_ActorFollow(pchar, characterFromID("Danielle"), "", 3.0);
			Lai_ActorFollow(characterFromID("Danielle"), pchar, "Story_TalkAfterKillingSoldiersatLighthouse_2", 3.0);
		break;
		
		case "Story_TalkAfterKillingSoldiersatLighthouse_2":
			LAi_SetPlayerType(pchar);
			Characters[GetCharacterIndex("Danielle")].Dialog.CurrentNode = "CaptureGreenford";
			LAi_ActorDialog(characterFromID("Danielle"), Pchar, "", 2.0, 0);
		break;

		case "Story_PrepareToSiegeGreenford":
			LAi_SetOfficerType(characterFromID("danielle"));
			Pchar.quest.Story_AreYouReadyToCaptureGreenford.win_condition.l1 = "location";
			Pchar.quest.Story_AreYouReadyToCaptureGreenford.win_condition.l1.location = "Oxbay_lighthouse";
			Pchar.quest.Story_AreYouReadyToCaptureGreenford.win_condition = "Story_AreYouReadyToCaptureGreenford";
		break;

		case "Story_AreYouReadyToCaptureGreenford":
			Characters[GetCharacterIndex("Danielle")].Dialog.CurrentNode = "Are_we_ready";
			LAi_ActorDialog(characterFromID("Danielle"), Pchar, "", 5.0, 1.0);
		break;

		case "Story_GreenfordAssaultStarted":
			Pchar.quest.Story_CaptureGreenfordFort.win_condition.l1 = "FORT_destroy";
			Pchar.quest.Story_CaptureGreenfordFort.win_condition.l1.character = "Greenford Commander";
			Pchar.quest.Story_CaptureGreenfordFort.win_condition = "Story_CaptureGreenfordFort";
			
			LAi_SetImmortal(characterFromID("Greenford Commander"), false);

			SetCharacterRemovable(characterFromID("Danielle"), true);
			RemovePassenger(Pchar, characterFromID("Danielle"));
			RemoveCharacterCompanion(pchar, characterFromID("danielle"));

			bQuestDisableMapEnter = true;
			//--------------Отключение возможности выгрузиться на остров
			Island_SetReloadEnableGlobal("Oxbay", false);

			DoReloadCharactertoLocation("Oxbay", "reload", "reload_4");

			Pchar.quest.Story_FightingInGreenfordPort.win_condition.l1 = "location";
			Pchar.quest.Story_FightingInGreenfordPort.win_condition.l1.location = "Fake_Greenford_port";
			Pchar.quest.Story_FightingInGreenfordPort.win_condition = "Story_FightingInGreenfordPort";
		break;

		case "Story_CaptureGreenfordFort":
			Islands[3].reload.l2.name = "reload_1";
			Islands[3].reload.l2.go = "Fake_Greenford_port";
			Islands[3].reload.l2.emerge = "reload1";
			Islands[3].reload.l2.radius = 200.0;
		break;

		case "Story_FightingInGreenfordPort":
			//-----------------Возвращение состояния Релоадов острова Оксбэй и восстановление выхода в карту
			Island_SetReloadEnableGlobal("Oxbay", true);
			//Восстановление адреса локатора перегрузки в Порт Гринфорда вместо фэйкового Гринфорда
			Islands[3].reload.l2.name = "reload_1";
			Islands[3].reload.l2.go = "Greenford_port";
			Islands[3].reload.l2.emerge = "reload1";
			Islands[3].reload.l2.radius = 200.0;

			bQuestDisableMapEnter = false;

			sld = LAi_CreateFantomCharacter("Soldier_eng", "reload", "reload4");
			LAi_group_MoveCharacter(sld, "ENGLAND_PORT_SOLDIERS");
			
			sld = LAi_CreateFantomCharacter("Soldier_eng2", "reload", "reload4");
			LAi_group_MoveCharacter(sld, "ENGLAND_PORT_SOLDIERS");
			
			sld = LAi_CreateFantomCharacter("Soldier_eng3", "reload", "reload4");
			LAi_group_MoveCharacter(sld, "ENGLAND_PORT_SOLDIERS");
			
			sld = LAi_CreateFantomCharacter("Soldier_eng4", "reload", "reload4");
			LAi_group_MoveCharacter(sld, "ENGLAND_PORT_SOLDIERS");
			
			sld = LAi_CreateFantomCharacter("Soldier_eng5", "reload", "reload4");
			LAi_group_MoveCharacter(sld, "ENGLAND_PORT_SOLDIERS");
			
			sld = LAi_CreateFantomCharacter("Soldier_eng6", "reload", "reload4");
			LAi_group_MoveCharacter(sld, "ENGLAND_PORT_SOLDIERS");
			
			sld = LAi_CreateFantomCharacter("Soldier_eng", "reload", "reload4");
			LAi_group_MoveCharacter(sld, "ENGLAND_PORT_SOLDIERS");
			
			sld = LAi_CreateFantomCharacter("Soldier_eng2", "reload", "reload4");
			LAi_group_MoveCharacter(sld, "ENGLAND_PORT_SOLDIERS");
			
			LAi_group_SetHearRadius("ENGLAND_PORT_SOLDIERS", 100.0);
			LAi_group_FightGroups("ENGLAND_PORT_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetRelation("ENGLAND_PORT_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);

			Pchar.quest.Story_FightingInGreenfordTown.win_condition.l1 = "location";
			Pchar.quest.Story_FightingInGreenfordTown.win_condition.l1.location = "Fake_Greenford_town";
			Pchar.quest.Story_FightingInGreenfordTown.win_condition = "Story_FightingInGreenfordTown";

			LAi_group_SetCheck("ENGLAND_PORT_SOLDIERS", "Story_KillEverybodyInGreenfordPort");
		break;

		case "Story_KillEverybodyInGreenfordPort":
			Locations[FindLocation("Fake_Greenford_port")].reload.l2.name = "reload4";
			Locations[FindLocation("Fake_Greenford_port")].reload.l2.go = "Fake_Greenford_town";
			Locations[FindLocation("Fake_Greenford_port")].reload.l2.emerge = "reload1";
		break;


		case "Story_FightingInGreenfordTown":
			ChangeCharacterAddressGroup(characterFromID("Danielle"), "Fake_greenford_town", "reload", "reload26");

			sld = LAi_CreateFantomCharacter("Black_Corsair", "reload", "reload26");
			LAi_SetHP(sld, 120.0, 120.0);
			LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);

			sld = LAi_CreateFantomCharacter("fatman", "reload", "reload26");
			LAi_SetHP(sld, 120.0, 120.0);
			LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);

			sld = LAi_CreateFantomCharacter("Chameleon", "reload", "reload26");
			LAi_SetHP(sld, 120.0, 120.0);
			LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);


			LAi_group_MoveCharacter(characterFromID("Danielle"), LAI_GROUP_PLAYER);

			sld = LAi_CreateFantomCharacter("Soldier_eng", "reload", "reload19");
			LAi_group_MoveCharacter(sld, "ENGLAND_TOWN_SOLDIERS");

			sld = LAi_CreateFantomCharacter("Soldier_eng2", "reload", "reload19");
			LAi_group_MoveCharacter(sld, "ENGLAND_TOWN_SOLDIERS");

			sld = LAi_CreateFantomCharacter("Soldier_eng3", "reload", "reload19");
			LAi_group_MoveCharacter(sld, "ENGLAND_TOWN_SOLDIERS");
			
			sld = LAi_CreateFantomCharacter("Soldier_eng4", "reload", "reload19");
			LAi_group_MoveCharacter(sld, "ENGLAND_TOWN_SOLDIERS");
			
			sld = LAi_CreateFantomCharacter("Soldier_eng5", "reload", "reload19");
			LAi_group_MoveCharacter(sld, "ENGLAND_TOWN_SOLDIERS");
			
			sld = LAi_CreateFantomCharacter("Soldier_eng6", "reload", "reload19");
			LAi_group_MoveCharacter(sld, "ENGLAND_TOWN_SOLDIERS");
			
			sld = LAi_CreateFantomCharacter("Soldier_eng", "reload", "reload19");
			LAi_group_MoveCharacter(sld, "ENGLAND_TOWN_SOLDIERS");
			
			sld = LAi_CreateFantomCharacter("Soldier_eng2", "reload", "reload19");
			LAi_group_MoveCharacter(sld, "ENGLAND_TOWN_SOLDIERS");
			
			sld = LAi_CreateFantomCharacter("Soldier_eng3", "reload", "reload19");
			LAi_group_MoveCharacter(sld, "ENGLAND_TOWN_SOLDIERS");
			
			LAi_group_SetCheck("ENGLAND_TOWN_SOLDIERS", "Story_GreenfordCapturedByBlazeAndDanielle");
			LAi_group_SetHearRadius("ENGLAND_TOWN_SOLDIERS", 100.0);
			LAi_group_FightGroups("ENGLAND_TOWN_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetRelation("ENGLAND_TOWN_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
		break;

		
		case "Story_GreenfordCapturedByBlazeAndDanielle":
			Locations[FindLocation("Fake_Greenford_town")].reload.l1.name = "reload27";
			Locations[FindLocation("Fake_Greenford_town")].reload.l1.go = "Fake_Greenford_prison";
			Locations[FindLocation("Fake_Greenford_town")].reload.l1.emerge = "Reload1";
			SetCharacterShipLocation(Pchar, "Greenford_port");
			SetCharacterRelationAsOtherCharacter(GetCharacterIndex("Greenford commander"), GetMainCharacterIndex());
			SetCharacterRelation(GetCharacterIndex("Greenford commander"),GetMainCharacterIndex(),RELATION_FRIEND);
			UpdateRelations();
			LAi_QuestDelay("Story_DanielleOffersToGoSaveResearcher", 1.0);
		break;

		case "Story_DanielleOffersToGoSaveResearcher":
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("danielle"));
			Lai_ActorFollow(pchar, characterFromID("danielle"), "", 2.0);
			Lai_ActorFollow(characterFromID("danielle"), pchar, "Story_DanielleOffersToGoSaveResearcher_2", 2.0);
		break;
		
		case "Story_DanielleOffersToGoSaveResearcher_2":
			LAi_ActorWaitDialog(pchar, characterFromID("danielle"));
			Characters[GetCharacterIndex("Danielle")].Dialog.CurrentNode = "Greenford_captured";
			LAi_SetStayType(characterFromID("researcher"));
			LAi_SetActorType(characterFromID("danielle"));
			LAi_ActorDialog(characterFromID("Danielle"), PChar, "pchar_back_to_player", 10.0, 1.0);
		break;

		case "Story_DanielleWentToGreenfordPrison":
			ChangeCharacterAddress(characterFromID("Danielle"), "Fake_Greenford_prison", "goto18");
		break;

		case "Story_AppearedInGreenfordPrison":
			Pchar.quest.Story_DanielleWentToGreenfordPrison.over = "yes";
			Characters[GetCharacterIndex("Researcher")].Dialog.CurrentNode = "Translation";
		break;

		case "Story_MovingToLighthouse":
			RemovePassenger(Pchar, characterFromID("Danielle"));

			CloseQuestHeader("Meet_Danielle_on_Muelle");
			CloseQuestHeader("Capture_greenford");

			ChangeCharacterAddress(characterFromID("Danielle"), "Oxbay_lighthouse", "goto22");
			ChangeCharacterAddress(characterFromID("Researcher"), "Oxbay_lighthouse", "goto23");
			
			DoQuestReloadToLocation("Oxbay_lighthouse", "Goto", "goto24", "Story_TalkWithResearcherAfterSaving");
			//Убираем английских солдат из Гринфорда
			ChangeCharacterAddress(characterFromID("Eng_soldier_38"), "None", "");
			ChangeCharacterAddress(characterFromID("Eng_soldier_39"), "None", "");
			ChangeCharacterAddress(characterFromID("Eng_soldier_40"), "None", "");
			ChangeCharacterAddress(characterFromID("Eng_soldier_41"), "None", "");
			ChangeCharacterAddress(characterFromID("Green_soldier_1"), "None", "");
			ChangeCharacterAddress(characterFromID("Green_soldier_2"), "None", "");
			ChangeCharacterAddress(characterFromID("Green_soldier_3"), "None", "");
			ChangeCharacterAddress(characterFromID("Green_soldier_4"), "None", "");
			ChangeCharacterAddress(characterFromID("Green_soldier_5"), "None", "");
			ChangeCharacterAddress(characterFromID("Green_soldier_6"), "None", "");
			ChangeCharacterAddress(characterFromID("Green_soldier_7"), "None", "");
			ChangeCharacterAddress(characterFromID("Green_soldier_8"), "None", "");
			ChangeCharacterAddress(characterFromID("Green_patrol_1"), "None", "");
			ChangeCharacterAddress(characterFromID("Green_patrol_2"), "None", "");
			ChangeCharacterAddress(characterFromID("Green_patrol_3"), "None", "");
			ChangeCharacterAddress(characterFromID("Green_patrol_4"), "None", "");
			ChangeCharacterAddress(characterFromID("Green_patrol_41"), "None", "");
			ChangeCharacterAddress(characterFromID("Green_soldier_8"), "None", "");
			ChangeCharacterAddress(characterFromID("Mine_soldier_05"), "None", "");
			ChangeCharacterAddress(characterFromID("Mine_soldier_06"), "None", "");
			ChangeCharacterAddress(characterFromID("Greenford Prison Commendant"), "None", "");
			locations[FindLocation("Oxbay_lighthouse")].fastreload = "Oxbay";
		break;

		case "Story_TalkWithResearcherAfterSaving":
			PlaceCharacter(characterFromID("researcher"), "goto", "Oxbay_lighthouse");
			PlaceCharacter(characterFromID("danielle"), "goto", "Oxbay_lighthouse");
			Characters[GetCharacterIndex("Researcher")].Dialog.CurrentNode = "NeedSomeTime";
			LAi_SetActorType(characterFromID("researcher"));
			LAi_SetActorType(pchar);
			LAi_ActorFollow(pchar, characterFromID("researcher"), "", 2.0);
			LAi_ActorFollow(characterFromID("researcher"), pchar, "Story_TalkWithResearcherAfterSaving_2", 2.0);
		break;
		
		case "Story_TalkWithResearcherAfterSaving_2":
			LAi_type_actor_Reset(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("researcher"));
			LAi_ActorDialog(characterFromID("Researcher"), Pchar, "pchar_back_to_player", 1.0, 1.0);
		break;

		case "Story_ReloadToTavernAndSpeakToDanielle":
			ChangeCharacterAddress(characterFromID("Danielle"), "Greenford_tavern", "goto7");
			DoQuestReloadToLocation("Greenford_tavern", "Goto", "goto17", "Story_DanielleStartsTalkAboutResearcher");
		break;

		case "Story_DanielleStartsTalkAboutResearcher":
			LAi_SetActorType(characterFromID("danielle"));
			Characters[GetCharacterIndex("Danielle")].Dialog.CurrentNode = "BeforeEnglishSiege";
			LAi_ActorDialogNow(characterFromID("Danielle"), Pchar, "", -1);
		break;

		case "Story_DanielleOffersToBecomeFortCommander":
			Characters[GetCharacterIndex("Danielle")].Dialog.CurrentNode = "RepelEnglishAssault";
			LAi_ActorDialog(characterFromID("Danielle"), Pchar, "", 5.0, 0);
			LAi_ActorRunToLocation(characterFromID("Blaze_Crewmember_01"), "reload", "reload1", "none", "", "", "", 10.0);
		break;

		/*case "Story_DanielleGoesToGreenfordFort":
			LAi_SetPlayerType(pchar);
			
			SetQuestHeader("Repel_English_Attack");
			AddQuestRecord("Repel_English_Attack", "1");

			Locations[FindLocation("Greenford_tavern")].reload.l1.name = "reload1";
			Locations[FindLocation("Greenford_tavern")].reload.l1.go = "Greenford_port";
			Locations[FindLocation("Greenford_tavern")].reload.l1.emerge = "reload4";

			SetCrewQuantity(characterFromID("Waulter Tomlison"), 200);
			SetCrewQuantity(characterFromID("Malcolm Hart"), 650);
			SetCrewQuantity(characterFromID("Henry Banfield"), 650);

			Group_AddCharacter("Story_English_Squadron", "Waulter Tomlison");
			Group_AddCharacter("Story_English_Squadron", "Malcolm Hart");
			Group_AddCharacter("Story_English_Squadron", "Henry Banfield");
		
			SetCharacterRelationAsOtherCharacter(GetCharacterIndex("danielle"), GetMainCharacterIndex());
			SetCharacterRelation(GetCharacterIndex("danielle"),GetMainCharacterIndex(),RELATION_FRIEND);
			
			SetCharacterRelationBoth(GetCharacterIndex("Waulter Tomlison"), GetMainCharacterIndex(), RELATION_ENEMY);
			SetCharacterRelationBoth(GetCharacterIndex("Waulter Tomlison"), GetCharacterIndex("danielle"), RELATION_ENEMY);
			Group_SetGroupCommander("Story_English_Squadron", "Waulter Tomlison");
			Group_SetTaskAttack("Story_English_Squadron", PLAYER_GROUP);
			Group_SetAddress("Story_English_Squadron", "Oxbay", "Quest_Ships","Quest_ship_23");
			Group_LockTask("Story_English_Squadron");

			Pchar.quest.Story_RepelEnglishAssaultOnGreenford.win_condition.l1 = "NPC_Death";
			Pchar.quest.Story_RepelEnglishAssaultOnGreenford.win_condition.l1.character = "Waulter Tomlison";
			Pchar.quest.Story_RepelEnglishAssaultOnGreenford.win_condition.l2 = "NPC_Death";
			Pchar.quest.Story_RepelEnglishAssaultOnGreenford.win_condition.l2.character = "Malcolm Hart";
			Pchar.quest.Story_RepelEnglishAssaultOnGreenford.win_condition.l3 = "NPC_Death";
			Pchar.quest.Story_RepelEnglishAssaultOnGreenford.win_condition.l3.character = "Henry Banfield";
			Pchar.quest.Story_RepelEnglishAssaultOnGreenford.win_condition = "Story_RepelEnglishAssaultOnGreenford";

			bQuestDisableMapEnter = true;
			Island_SetReloadEnableGlobal("oxbay",false);
		break;*/

		case "Story_RepelEnglishAssaultOnGreenford":
			DisableFastTravel(true);
			DisableMenuLaunch(true);
			DoQuestCheckDelay("Story_RepelEnglishAssaultOnGreenford_2", 5.0);
		break;

		case "Story_RepelEnglishAssaultOnGreenford_2":
			ChangeCharacterAddressGroup(characterFromID("Danielle"), "Greenford_port", "reload", "reload4");
			ChangeCharacterAddressGroup(characterFromID("Greenford Commander"), "Oxbay", "reload", "reload_fort1");
			Characters[GetCharacterIndex("Danielle")].ship.type = SHIP_NOTUSED;
			DoQuestReloadToLocation("Greenford_port", "reload", "reload1", "Story_WeMadeThem");
		break;

		case "Story_WeMadeThem":
			DisableFastTravel(false);
			DisableMenuLaunch(false);
			CloseQuestHeader("Repel_English_Attack");
			//-----------------Возвращение состояния Релоадов острова Оксбэй и восстановление выхода в карту
			Island_SetReloadEnableGlobal("oxbay",true);

			bQuestDisableMapEnter = false;
			//-----------------Возвращение состояния релоада выхода из гринфордской таверны
			Locations[FindLocation("Greenford_tavern")].reload.l1.name = "reload1";
			Locations[FindLocation("Greenford_tavern")].reload.l1.go = "Greenford_Town";
			Locations[FindLocation("Greenford_tavern")].reload.l1.emerge = "reload7";
			
			Locations[FindLocation("Greenford_port")].reload.l2.name = "reload4";
			Locations[FindLocation("Greenford_port")].reload.l2.go = "Greenford_town";
			Locations[FindLocation("Greenford_port")].reload.l2.emerge = "reload1";

			Characters[GetCharacterIndex("Danielle")].Dialog.CurrentNode = "AfterGreenfordSiege";
			LAi_SetActorType(characterFromID("danielle"));
			LAi_ActorDialog(characterFromID("Danielle"), pchar, "", 20.0, 1.0);
			pchar.location.from_sea = "Oxbay_lighthouse";
			Locations[FindLocation("Oxbay_lighthouse")].reload.l3.disable = 1;
		break;

		case "Story_VoyageToKhaelRoaBegan":
			LAi_LocationMonstersGen(&Locations[FindLocation("Labirint_1")], true);
			LAi_LocationMonstersGen(&Locations[FindLocation("Labirint_2")], true);
			LAi_LocationMonstersGen(&Locations[FindLocation("Labirint_3")], true);
			LAi_LocationMonstersGen(&Locations[FindLocation("Treasure_Alcove")], true);

			Islands[7].model = "KhaelRoa1";
			Islands[7].filespath.models = "islands\KhaelRoa1";
			Islands[7].refl_model = "KhaelRoa1_refl";

			SetQuestHeader("Sail_to_KhaelRoa");
			AddQuestRecord("Sail_to_KhaelRoa", "1");
			characters[GetCharacterIndex("Robert Christopher Silehard")].rank = makeint(pchar.rank) - 4;

			SetCrewQuantity(characterFromID("Isenbrandt Jurcksen"), 400);
			SetCrewQuantity(characterFromID("Brian The Slaver"), 450);
			//SetCrewQuantity(characterFromID("Torquato Paulino"), 120);
			SetCrewQuantity(characterFromID("Femensy Strijdom"), 160);
			SetCrewQuantity(characterFromID("Robert Christopher Silehard"), 950);

			Group_AddCharacter("Story_Pirate_Squadron", "Isenbrandt Jurcksen");
			Group_AddCharacter("Story_Pirate_Squadron", "Brian The Slaver");
			Group_AddCharacter("Story_Pirate_Squadron", "Femensy Strijdom");
			Group_AddCharacter("Story_Pirate_Squadron", "Robert Christopher Silehard");

			Group_SetGroupCommander("Story_Pirate_Squadron", "Isenbrandt Jurcksen");
			Group_SetTaskAttack("Story_Pirate_Squadron", PLAYER_GROUP);
			Group_SetAddress("Story_Pirate_Squadron", "KhaelRoa", "Quest_ships", "Quest_Ship_4");

			Pchar.quest.Story_SinkPiratesAtKhaelRoa.win_condition.l1 = "NPC_Death";
			Pchar.quest.Story_SinkPiratesAtKhaelRoa.win_condition.l1.character = "Isenbrandt Jurcksen";
			Pchar.quest.Story_SinkPiratesAtKhaelRoa.win_condition.l2 = "NPC_Death";
			Pchar.quest.Story_SinkPiratesAtKhaelRoa.win_condition.l2.character = "Brian The Slaver";
			Pchar.quest.Story_SinkPiratesAtKhaelRoa.win_condition.l3 = "NPC_Death";
			Pchar.quest.Story_SinkPiratesAtKhaelRoa.win_condition.l3.character = "Femensy Strijdom";
			Pchar.quest.Story_SinkPiratesAtKhaelRoa.win_condition.l4 = "NPC_Death";
			Pchar.quest.Story_SinkPiratesAtKhaelRoa.win_condition.l4.character = "Robert Christopher Silehard";
			Pchar.quest.Story_SinkPiratesAtKhaelRoa.win_condition = "Story_SinkPiratesAtKhaelRoa";

			Pchar.quest.Story_AppearAtKhaelRoa.win_condition.l1 = "location";
			Pchar.quest.Story_AppearAtKhaelRoa.win_condition.l1.location = "KhaelRoa";
			Pchar.quest.Story_AppearAtKhaelRoa.win_condition = "Story_AppearAtKhaelRoa";

			Characters[GetCharacterIndex("Danielle")].Dialog.CurrentNode = "ReadyForKhaelRoa";
		break;
		
		case "Story_AppearAtKhaelRoa":						
			LAi_SetImmortal(characterFromID("Robert Christopher Silehard"), false);
			LAi_SetImmortal(characterFromID("Isenbrandt Jurcksen"), false);
			bQuestDisableMapEnter = true; 
			Island_SetReloadEnableLocal("KhaelRoa", "reload_1", true);
			Island_SetReloadEnableGlobal("KhaelRoa", false);
			SetNationRelation2MainCharacter(PIRATE,RELATION_ENEMY);
			ChangeCharacterShipGroup(characterFromID("Isenbrandt Jurcksen"), "Pirates");
			ChangeCharacterShipGroup(characterFromID("Brian The Slaver"), "Pirates");
			ChangeCharacterShipGroup(characterFromID("Femensy Strijdom"), "Pirates");
			ChangeCharacterShipGroup(characterFromID("Robert Christopher Silehard"), "Pirates");
			Group_SetTaskAttack("Pirates", PLAYER_GROUP);
			Group_LockTask("Pirates");
			UpdateRelations();
		break;

		case "Story_SinkPiratesAtKhaelRoa":			
			Island_SetReloadEnableLocal("KhaelRoa", "reload_1", true);
			Island_SetReloadEnableGlobal("KhaelRoa", true);
			Island_SetGotoEnableLocal("KhaelRoa", "reload_1", true);
			RefreshBattleInterface();
			
			Locations[FindLocation("KhaelRoa_port")].reload.l1.disable = 1;
			Locations[FindLocation("Temple")].reload.l3.disable = 1;
			Locations[FindLocation("Labirint_1")].reload.l1.disable = 1;

			CloseQuestHeader("Sail_to_KhaelRoa");
			SetQuestHeader("Into_the_temple");
			AddQuestRecord("Into_the_temple","1");

			SetOfficersIndex(Pchar, -1,getCharacterIndex("Researcher"));
			SetCharacterRemovable(characterFromID("Researcher"), false);

			Pchar.quest.Story_LandedOnKhaelRoa.win_condition.l1 = "location";
			Pchar.quest.Story_LandedOnKhaelRoa.win_condition.l1.location = "KhaelRoa_port";
			Pchar.quest.Story_LandedOnKhaelRoa.win_condition = "Story_LandedOnKhaelRoa";
		break;
		
		case "Story_LandedOnKhaelRoa":
			StorePassengers(pchar.id);
			
			locDisableUpdateTime = true;
			
			ChangeCharacterAddressGroup(characterFromID("danielle"), "KhaelRoa_port", "officers", "reload2_1");
			ChangeCharacterAddressGroup(characterFromID("Researcher"), "KhaelRoa_port", "officers", "reload2_1");
			LAi_QuestDelay("Story_IntoKhaelRoa", 2.0);
			
		break;

		case "Story_IntoKhaelRoa":
			LAi_SetActorType(characterFromID("danielle"));
			Characters[GetCharacterIndex("Danielle")].Dialog.CurrentNode = "Temple";
			LAi_ActorDialog(characterFromID("Danielle"), Pchar, "danielle_becomes_officer", 5.0, 1.0);
		break;

		case "danielle_becomes_officer":
			AddPassenger(Pchar, characterFromID("danielle"), 0);
			AddPassenger(Pchar, characterFromID("researcher"), 0);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Danielle"));
			SetOfficersIndex(Pchar, 2, getCharacterIndex("Researcher"));
			LAi_SetOfficerType(characterFromID("danielle"));
		break;

		case "researcher_becomes_officer":
			LAi_SetOfficerType(characterFromID("researcher"));
		break;

		case "Story_ResearcherSpeaksonKhaelRoaBeach":
			Characters[GetCharacterIndex("researcher")].dialog.CurrentNode = "Danger";
			LAi_SetActorType(characterFromID("researcher"));
			LAi_ActorDialog(characterFromID("Researcher"), Pchar, "researcher_becomes_officer", 5.0, 1.0);
		
			Locations[FindLocation("Labirint_1")].locators_radius.goto.goto1 = 3.0;
			
			Pchar.quest.Story_SplitInLabyrinth.win_condition.l1 = "locator";
			Pchar.quest.Story_SplitInLabyrinth.win_condition.l1.location = "Labirint_1";
			Pchar.quest.Story_SplitInLabyrinth.win_condition.l1.locator_group = "goto";
			Pchar.quest.Story_SplitInLabyrinth.win_condition.l1.locator = "goto1";
			Pchar.quest.Story_SplitInLabyrinth.win_condition = "Story_SplitInLabyrinth";
		break;

		case "Story_SplitInLabyrinth":
			LAi_SetActorType(characterFromID("danielle"));
			LAi_SetActorType(characterFromID("researcher"));
			LAi_SetActorType(pchar);
			LAi_ActorFollow(pchar, characterFromID("danielle"), "", 2.0);
			LAi_ActorFollow(characterFromID("researcher"), pchar, "", 2.0);
			LAi_ActorFollow(characterFromID("danielle"), pchar, "Story_SplitInLabyrinth_2", 2.0);
		break;

		case "Story_SplitInLabyrinth_2":
			LAi_type_actor_Reset(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("danielle"));
			Characters[GetCharacterIndex("Danielle")].Dialog.CurrentNode = "Split";
			LAi_ActorDialog(characterFromID("Danielle"), Pchar, "", 2.0, 0);
		break;

		case "Story_DanielleWentIntoLeftPassage":
			Locations[FindLocation("KhaelRoa_port")].reload.l1.disable = 0;
			Locations[FindLocation("Temple")].reload.l3.disable = 0;
			SetCharacterRemovable(characterFromID("Danielle"), true);
			RemovePassenger(Pchar, characterFromID("Danielle"));
			LAi_type_actor_Reset(characterFromID("researcher"));
			LAi_type_actor_Reset(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("researcher"));
			LAi_SetActorType(characterFromID("danielle"));
			characters[GetCharacterIndex("danielle")].location = "labirint1";
			LAi_ActorRunToLocator(characterFromID("danielle"), "goto", "goto3", "", 25.0);
			Characters[GetCharacterIndex("Researcher")].Dialog.CurrentNode = "I go to the right";
			LAi_ActorDialog(characterFromID("Researcher"), Pchar, "pchar_back_to_player", 5.0, 0);
		break; 

		case "Danielle_split_exit":
			Characters[GetCharacterIndex("Danielle")].Dialog.CurrentNode = "First time";
			LAi_type_actor_Reset(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("researcher"));
			LAi_SetActorType(characterFromID("researcher"));
			Characters[GetCharacterIndex("Researcher")].Dialog.CurrentNode = "Split";
			LAi_ActorDialog(characterFromID("researcher"), pchar, "pchar_back_to_player", 2.0, 1.0);
		break;

		case "danielle_AfterGreenfordSiege_exit":
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Danielle"));
			SetCharacterRemovable(characterFromID("Danielle"), false);
			ChangeCharacterAddress(characterFromID("researcher"),"Oxbay_lighthouse", "goto30");
			Characters[GetCharacterIndex("researcher")].dialog.CurrentNode = "AlreadyTranslated";
			DoQuestReloadToLocation("Oxbay_lighthouse", "Goto", "goto24", "Story_TalkWithResearcherAfterSiegeGreenford");
		break;

		case "Story_TalkWithResearcherAfterSiegeGreenford":
			PlaceCharacter(characterFromID("researcher"), "goto", "Oxbay_lighthouse");
			LAi_SetActorType(characterFromID("researcher"));
			LAi_SetActorType(pchar);
			LAi_ActorFollow(pchar, characterfromID("researcher"), "", 2.0);
			LAi_ActorFollow(characterfromID("researcher"), pchar, "Story_TalkWithResearcherAfterSiegeGreenford_2", 2.0);
		break;
		
		case "Story_TalkWithResearcherAfterSiegeGreenford_2":
			LAi_type_actor_Reset(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("researcher"));
			LAi_ActorDialog(characterFromID("researcher"), pchar, "pchar_back_to_player", 3.0, 1.0);
		break;

		case "danielle_RepelEnglishAssault_again_exit":
			LAi_SetActorType(characterFromID("danielle"));
			LAi_ActorGoToLocator(characterFromID("danielle"), "reload", "reload1", "", 5.0);
		break;

		case "danielle_RepelEnglishAssault_exit":
			LAi_SetPlayerType(pchar);
			Fort_SetCharacter(characterFromID("danielle"), "Oxbay", "reload", "reload_fort1");
			LAi_SetActorType(characterFromID("danielle"));
			//LAi_ActorRunToLocator(characterFromID("danielle"), "reload", "reload1", "Story_DanielleGoesToGreenfordFort", 5.0);
			LAi_ActorRunToLocator(characterFromID("danielle"), "reload", "reload1", "", 5.0);
			LAi_SetPlayerType(pchar);
			
			SetQuestHeader("Repel_English_Attack");
			AddQuestRecord("Repel_English_Attack", "1");

			Locations[FindLocation("Greenford_tavern")].reload.l1.name = "reload1";
			Locations[FindLocation("Greenford_tavern")].reload.l1.go = "Greenford_port";
			Locations[FindLocation("Greenford_tavern")].reload.l1.emerge = "reload4";

			pchar.quest.to_suadron.win_condition.l1 = "location";
			pchar.quest.to_suadron.win_condition.l1.location = "Oxbay";
			pchar.quest.to_suadron.win_condition = "to_suadron";
			bQuestDisableMapEnter = true;
			Island_SetReloadEnableGlobal("oxbay",false);
		break;
		
		case "to_suadron":
			SetCrewQuantity(characterFromID("Waulter Tomlison"), 200);
			SetCrewQuantity(characterFromID("Malcolm Hart"), 650);
			SetCrewQuantity(characterFromID("Henry Banfield"), 650);

			Group_AddCharacter("Story_English_Squadron", "Waulter Tomlison");
			Group_AddCharacter("Story_English_Squadron", "Malcolm Hart");
			Group_AddCharacter("Story_English_Squadron", "Henry Banfield");
		
			SetCharacterRelationAsOtherCharacter(GetCharacterIndex("danielle"), GetMainCharacterIndex());
			SetCharacterRelationBoth(GetCharacterIndex("danielle"),GetMainCharacterIndex(),RELATION_FRIEND);
			
			SetCharacterRelationBoth(GetCharacterIndex("Waulter Tomlison"), GetMainCharacterIndex(), RELATION_ENEMY);
			SetCharacterRelationBoth(GetCharacterIndex("Waulter Tomlison"), GetCharacterIndex("danielle"), RELATION_ENEMY);
			Group_SetGroupCommander("Story_English_Squadron", "Waulter Tomlison");
			Group_SetTaskAttack("Story_English_Squadron", PLAYER_GROUP);
			Group_SetAddress("Story_English_Squadron", "Oxbay", "Quest_Ships","Quest_ship_23");
			Group_LockTask("Story_English_Squadron");

			Pchar.quest.Story_RepelEnglishAssaultOnGreenford.win_condition.l1 = "NPC_Death";
			Pchar.quest.Story_RepelEnglishAssaultOnGreenford.win_condition.l1.character = "Waulter Tomlison";
			Pchar.quest.Story_RepelEnglishAssaultOnGreenford.win_condition.l2 = "NPC_Death";
			Pchar.quest.Story_RepelEnglishAssaultOnGreenford.win_condition.l2.character = "Malcolm Hart";
			Pchar.quest.Story_RepelEnglishAssaultOnGreenford.win_condition.l3 = "NPC_Death";
			Pchar.quest.Story_RepelEnglishAssaultOnGreenford.win_condition.l3.character = "Henry Banfield";
			Pchar.quest.Story_RepelEnglishAssaultOnGreenford.win_condition = "Story_RepelEnglishAssaultOnGreenford";
		break;

		case "danielle_BeforeEnglishSiege_exit":
			LAi_SetHP(characterFromID("Blaze_CrewMember_01"), 80.0, 80.0);
			LAi_SetActorType(characterFromID("Blaze_CrewMember_01"));
			ChangeCharacterAddressGroup(characterFromID("Blaze_Crewmember_01"), "Greenford_tavern", "reload", "reload1");
			Characters[GetCharacterIndex("Blaze_Crewmember_01")].Dialog.Filename = "EnglishAttack_dialog.c";
			Characters[GetCharacterIndex("Blaze_Crewmember_01")].Dialog.CurrentNode = "First time";
			LAi_ActorDialog(characterfromID("Blaze_Crewmember_01"), pchar, "pchar_back_to_player", 2.0, 1.0);
		break;

		case "danielle_Greenford_captured_exit":
			LAi_SetActorType(characterFromID("danielle"));
			ChangeCharacterAddress(characterFromID("Researcher"), "Fake_Greenford_prison", "goto9");

			Pchar.quest.Story_AppearedInGreenfordPrison.win_condition.l1 = "location";
			Pchar.quest.Story_AppearedInGreenfordPrison.win_condition.l1.location = "Fake_Greenford_prison";
			Pchar.quest.Story_AppearedInGreenfordPrison.win_condition = "Story_AppearedInGreenfordPrison";

			LAi_ActorRunToLocator(characterFromID("danielle"), "reload", "reload27", "Story_DanielleWentToGreenfordPrison", 20.0);
		break;

		case "researcher_danger_wait_exit":
			SetCurrentTime(10, 0);
			SetNextWeather("Blue Sky");
			DoReloadCharacterToLocation("KhaelRoa_port", "reload", "reload2");
		break;

		case "Story_TimeToGoIntoCentralPassage":						
			ChangeCharacterAddress(characterFromID("danielle"), "none", "");
			ChangeCharacterAddress(characterFromID("researcher"), "none", "");
			LAi_SetPlayerType(pchar);
			Locations[FindLocation("Treasure_Alcove")].locators_radius.goto.goto3 = 5.0;

			AddQuestRecord("Into_the_temple","1");

			Pchar.quest.Story_DanielleAndResearcherAppear.win_condition.l1 = "Location";
			Pchar.quest.Story_DanielleAndResearcherAppear.win_condition.l1.location = "Treasure_Alcove";
			Pchar.quest.Story_DanielleAndResearcherAppear.win_condition = "Story_DanielleAndResearcherAppear";
		break;

		case "Story_DanielleAndResearcherAppear":
			ChangeCharacterAddressGroup(characterfromID("danielle"), "Treasure_Alcove", "officers", "reload1_1");
			ChangeCharacterAddressGroup(characterfromID("researcher"), "Treasure_Alcove", "officers", "reload1_2");
			AddPassenger(Pchar, characterFromID("danielle"), 0);
			AddPassenger(Pchar, characterFromID("researcher"), 0);

			SetOfficersIndex(PChar, 1, getCharacterIndex("Danielle"));
			SetCharacterRemovable(characterFromID("danielle"), false);
			SetOfficersIndex(PChar, 2, getCharacterIndex("Researcher"));
			SetCharacterRemovable(characterFromID("researcher"), false);

			Pchar.quest.Story_DanielleAndResearcherComeCloser.win_condition.l1 = "locator";
			Pchar.quest.Story_DanielleAndResearcherComeCloser.win_condition.l1.location = "Treasure_Alcove";
			Pchar.quest.Story_DanielleAndResearcherComeCloser.win_condition.l1.locator_group = "goto";
			Pchar.quest.Story_DanielleAndResearcherComeCloser.win_condition.l1.locator = "goto3";
			Pchar.quest.Story_DanielleAndResearcherComeCloser.win_condition = "Story_DanielleAndResearcherComeCloser";
		break;

		case "Story_DanielleAndResearcherComeCloser":
			Characters[GetCharacterIndex("Danielle")].Dialog.CurrentNode = "Treasure_room";

			LAi_SetActorType(characterFromID("danielle"));
			LAi_ActorDialog(characterFromID("danielle"), pchar, "", 3.0, 1.0);
		break;

		case "Story_ResearcherTalkInAlcove":
			LAi_SetActorType(characterFromID("researcher"));
			Characters[GetCharacterIndex("Researcher")].Dialog.CurrentNode = "Alcove_talk";
			LAi_ActorDialog(characterFromID("Researcher"), Pchar, "", 5.0, 1.0);
		break;
		
		case "Story_ResearcherReadsDanielleTalks":
			LAi_ActorGoToLocator(characterFromID("Researcher"), "goto", "goto4", "", 30.0);
			Characters[GetCharacterIndex("Danielle")].Dialog.CurrentNode = "ITakeTheStone";
			LAi_ActorDialog(characterFromID("Danielle"), Pchar, "", 5.0, 1.0);
		break;

		case "Story_ITakeTheStone":
			LAi_ActorRunToLocator(characterFromID("danielle"), "goto", "goto5", "Story_PlayTheFirstPartVideo_prepare", 15.0);
		break;

		case "Story_PlayTheFirstPartVideo_prepare":
			LAi_SetActorType(pchar);
			LAi_ActorFollow(pchar, characterfromID("danielle"), "Story_PlayTheFirstPartVideo", 15.0);
		break;

		case "Story_PlayTheFirstPartVideo":
			GiveItem2Character(pchar, "artefact");
			SetNextWeather("Black Pearl Fight");
			bMainMenuLaunchAfterVideo = true;
			PostVideoAndQuest("temple", 100, "Story_Escaped_from_temple");
		break;

		case "Story_Escaped_from_temple":
			PostEvent("DoInfoShower",100,"s","");
			ChangeCharacterAddressGroup(characterFromID("Danielle"), "KhaelRoa_port", "Officers", "Reload1_1");
			ChangeCharacterAddressGroup(characterFromID("Researcher"), "KhaelRoa_port", "Officers", "Reload1_2");
			DoQuestReloadToLocation("KhaelRoa_port", "Reload", "Reload1", "Story_GetOnBoardOnKhaelRoa");
		break;

		case "Story_GetOnBoardOnKhaelRoa":
			RestorePassengers(pchar.id);
			LAi_type_actor_Reset(characterFromID("Danielle"));
			LAi_type_actor_Reset(characterFromID("Researcher"));

			LAi_SetPlayerType(pchar);
			LAi_SetOfficerType(characterfromID("danielle"));
			LAi_type_actor_Reset(characterFromID("Researcher"));
			Characters[GetCharacterIndex("researcher")].Dialog.CurrentNode = "TempleWillBlast";
			LAi_ActorDialog(characterFromID("researcher"), PChar, "to_the_ship_whualya", 2.0, 0);
		break;

		case "to_the_ship_whualya":
			LAi_SetOfficerType(characterFromID("researcher"));
			Locations[FindLocation("KhaelRoa_port")].reload.l2.disable = 1;
			ReStorePassengers(pchar.id);
		break;

		case "Story_LeavingKhaelRoa":
			LAi_QuestDelay("Story_MeetSilehardManowar", 5.0);
		break;

		case "Story_MeetSilehardManowar":
			Lai_SetImmortal(CharacterFromID("Barbossa"), false);
			Group_AddCharacter("Black_Pearl", "Barbossa");
			SetCharacterRelation(GetCharacterIndex("Barbossa"),GetMainCharacterIndex(),RELATION_ENEMY);

			Group_SetGroupCommander("Black_Pearl", "Barbossa");
			Group_SetTaskAttack("Black_Pearl", PLAYER_GROUP);
			Group_SetAddress("Black_Pearl", "KhaelRoa", "Quest_Ships","Quest_Ship_2");
			Group_LockTask("Black_Pearl");
			characters[GetCharacterindex("Barbossa")].ship.hp = 100000;
			RemoveOfficersIndex(pchar, GetCharacterIndex("researcher"));
			bMainMenuLaunchAfterVideo = true;
			PostVideoAndQuest("blackpearl", 100, "Story_FaceTheBoss");
			Island_SetGotoEnableLocal("KhaelRoa", "reload_1", false);
		break;
		
		case "onUseArtefact":
			bMainMenuLaunchAfterVideo = true;
			PostVideoAndQuest("artefact", 100, "post_use_artefact");
			TakeItemFromCharacter(pchar, "artefact");
		break;
		
		case "post_use_artefact":
			PostEvent("DoInfoShower",100,"s","");
			CreateEntity(&artifact, "artifact");
			LayerAddObject(SEA_REALIZE, &artifact, -1);
			
			int iHP1, iHP2, iHP3;
			iHP1 = 0;
			iHP2 = 0;
			iHP3 = 0;
			if (GetCompanionIndex(pchar,1) > 0)
			{
				ipassenger = GetCompanionIndex(pchar,1);
				iHP1 = makeint(characters[ipassenger].ship.hp);
			}
			if (GetCompanionIndex(pchar,2) > 0)
			{
				ipassenger = GetCompanionIndex(pchar,2);
				iHP2 = makeint(characters[ipassenger].ship.hp);
			}
			if (GetCompanionIndex(pchar,3) > 0)
			{
				ipassenger = GetCompanionIndex(pchar,3);
				iHP3 = makeint(characters[ipassenger].ship.hp);
			}
			iPassenger = pchar.ship.type;
			pchar.ship.hp =  ShipsTypes[iPassenger].HP;
			
			characters[GetCharacterindex("Barbossa")].ship.hp = makeint(pchar.ship.hp) + iHP1 + iHP2 + iHP3;
			characters[GetCharacterindex("Barbossa")].skill.cannons = 7;
			characters[GetCharacterindex("Barbossa")].skill.accuracy = 7;
			characters[GetCharacterIndex("Barbossa")].perks.list.LightRepair = true;
		break;

		case "Story_FaceTheBoss":
			PostEvent("DoInfoShower",100,"s","");
			QuestToSeaLogin_PrepareLoc("KhaelRoa", "Quest_Ships", "Quest_Ship_5", true);
			QuestToSeaLogin_Launch();

			bQuestDisableMapEnter = true;
			Island_SetReloadEnableGlobal("KhaelRoa", false);

			pchar.quest.Story_KillTheFinalBoss.win_condition.l1 = "NPC_Death";
			pchar.quest.Story_KillTheFinalBoss.win_condition.l1.character = "Barbossa";
			pchar.quest.Story_KillTheFinalBoss.win_condition = "Story_KillTheFinalBoss";
		break;

		case "Story_KillTheFinalBoss":
			DoQuestCheckDelay("Story_KillTheFinalBoss_2", 5.0);
		break;
		
		case "Story_KillTheFinalBoss_2":
			bQuestDisableMapEnter = false;
			bMainMenuLaunchAfterVideo = true;
			InterfaceStates.Buttons.Resume.enable = false;
			InterfaceStates.Buttons.Save.enable = false;
			GameOver("finish");
			DelEventHandler(EVENT_END_VIDEO,"LaunchMainMenu_afterVideo");
			bMainMenuLaunchAfterVideo = true;
			PostVideoAndQuest("ending",100, "credits");
		break;
		
		case "credits":
			PostEvent("DoInfoShower",100,"s","");
			PostVideoAndQuest("credits", 1, "end_game");
		break;

		case "end_game":
			LaunchMainMenu();
			Characters[GetCharacterIndex("researcher")].Dialog.CurrentNode = "First time";
			Characters[GetCharacterIndex("danielle")].Dialog.CurrentNode = "First time";
		break;

		case "remove_officers_from_blaze_in_redmond_complete":
			characters[GetCharacterIndex("Eng_soldier_5")].dialog.currentnode = "do_not_go";
			LAi_ActorDialogNow(characterFromID("Eng_soldier_5"), pchar, "", -1);
		break;

		//Выходим от губернатора
		case "exit_from_silehard_complete":
			pchar.quest.main_line = "talk_in_tavern_begin";
			AddPartyExp(pchar, 7000);
			LAi_SetImmortal(characterFromID("Danielle"), true);
			Group_SetAddress("Story_French_Squadron", "none", "Quest_Ships","Quest_Ship_7");

			LAi_SetStayType(characterFromID("danielle"));
			LAi_SetStayType(characterFromID("ralph fawn"));
			LAi_group_MoveCharacter(characterFromID("danielle"), LAI_GROUP_PLAYER);
			LAi_group_MoveCharacter(characterFromID("ralph fawn"), LAI_GROUP_PLAYER);

			ChangeCharacterAddress(characterFromID("Danielle"), "Quest_redmond_tavern", "goto2");
			ChangeCharacterAddress(characterFromID("Ralph Fawn"), "Quest_redmond_tavern", "goto3");
			ChangeCharacterAddressGroup(characterFromID("Charles Windem"), "Quest_redmond_tavern", "merchant", "goto1");
			//Делаем невозможность уйти из локации
			locations[FindLocation("Redmond_port")].reload.l2.disable = 1;
			locations[FindLocation("Redmond_port")].reload.l3.disable = 1;
			locations[FindLocation("Redmond_Shore_01")].reload.l2.disable = 1;
			locations[FindLocation("Redmond_Shore_02")].reload.l2.disable = 1;
			
			/*locations[FindLocation("Redmond_town_01")].reload.l1.disable = 1;
			locations[FindLocation("Redmond_town_01")].reload.l2.disable = 1;
			locations[FindLocation("Redmond_town_01")].reload.l3.disable = 1;
			locations[FindLocation("Redmond_town_01")].reload.l4.disable = 1;
			locations[FindLocation("Redmond_town_01")].reload.l5.disable = 1;
			locations[FindLocation("Redmond_town_01")].reload.l6.disable = 1;
			locations[FindLocation("Redmond_town_01")].reload.l7.disable = 1;
			locations[FindLocation("Redmond_town_01")].reload.l8.disable = 1;
			locations[FindLocation("Redmond_town_01")].reload.l9.disable = 1;
			locations[FindLocation("Redmond_town_01")].reload.l10.disable = 1;
			locations[FindLocation("Redmond_town_01")].reload.l11.disable = 1;
			locations[FindLocation("Redmond_town_01")].reload.l12.disable = 1;
			locations[FindLocation("Redmond_town_01")].reload.l13.disable = 1;*/
			
			pchar.quest.to_quest_redmond_tavern.win_condition.l1 = "location";
			pchar.quest.to_quest_redmond_tavern.win_condition.l1.location = "Quest_Redmond_tavern";
			pchar.quest.to_quest_redmond_tavern.win_condition = "to_quest_redmond_tavern_complete";
			//убираем выход из таверны
			locations[FindLocation("quest_redmond_tavern")].reload.l1.disable = 1;
			worldMap.islands.Oxbay.locations.city.label.icon = ENGLAND;
		break;
		
		// заходим в квестовую таверну.
		case "to_quest_redmond_tavern_complete":
			//восстанавливаем выходы из города
			locations[FindLocation("Redmond_port")].reload.l2.disable = 0;
			locations[FindLocation("Redmond_port")].reload.l3.disable = 0;
			locations[FindLocation("Redmond_Shore_01")].reload.l2.disable = 0;
			locations[FindLocation("Redmond_Shore_02")].reload.l2.disable = 0;
		break;

		case "prepare_to_battle_in_quest_redmond_tavern":
			LAi_SetActorType(pchar);

			locx = stf(loadedLocation.locators.camera.locator12.x);
			locy = stf(loadedLocation.locators.camera.locator12.y);
			locz = stf(loadedLocation.locators.camera.locator12.z);
			locCameraToPos(locx, locy, locz, false);

			sld = LAi_CreateFantomCharacter("offic_eng", "goto", "goto19");
			LAi_SetHP(sld, 50.0, 50.0);
			sld.id = "soldier1";
			sld.Dialog.Filename = "soldier_for_fight_in_tavern_01_dialog.c";
			sld.model.head = "h_offic_eng";
			LAi_SetActorType(sld);

			sld = LAi_CreateFantomCharacter("soldier_eng", "goto", "goto17");
			LAi_SetHP(sld, 50.0, 50.0);
			sld.id = "soldier2";
			LAi_SetWarriorType(sld);
			LAi_warrior_SetStay(sld, true);

			sld = LAi_CreateFantomCharacter("soldier_eng2", "goto", "goto18");
			LAi_SetHP(sld, 50.0, 50.0);
			sld.id = "soldier3";
			LAi_SetWarriorType(sld);
			LAi_warrior_SetStay(sld, true);

			sld = LAi_CreateFantomCharacter("soldier_eng3", "reload", "reload1");
			LAi_SetHP(sld, 50.0, 50.0);
			sld.id = "soldier4";
			LAi_SetWarriorType(sld);
			LAi_warrior_SetStay(sld, true);

			LAi_SetActorType(characterFromID("danielle"));
			LAi_SetActorType(characterFromID("ralph fawn"));

			LAi_group_MoveCharacter(characterFromID("soldier2"), "ENGLAND_TAVERN_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("soldier3"), "ENGLAND_TAVERN_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("soldier4"), "ENGLAND_TAVERN_SOLDIERS");
				

			LAi_ActorTurnToCharacter(pchar, characterFromID("soldier1"));
			LAi_ActorTurnToCharacter(characterFromID("Danielle"), characterFromID("soldier1"));
			LAi_ActorTurnToCharacter(characterFromID("Ralph Fawn"), characterFromID("soldier1"));

			LAi_ActorDialog(characterFromID("soldier1"), pchar, "", 5.0, 0);
			LAi_ActorWaitDialog(pchar, characterFromID("soldier1"));
		break;

		//солдат в таверне бьет нас по мордe
		case "kicked_by_soldier_complete":
			LAi_ActorAnimation(characterFromID("soldier1"), "attack_2", "kicked_by_soldier_2_complete", 0.5);
		break;

		case "kicked_by_soldier_2_complete":
			LAi_ActorAnimation(pchar, "hit_2", "kicked_by_soldier_3_complete", 1.5);
		break;

		case "kicked_by_soldier_3_complete":
			pchar.quest.main_line = "after_soldier_kick";
			//LAi_SetPlayerType(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("soldier1"));
			LAi_ActorDialogNow(characterFromID("soldier1"), pchar, "", -1);
		break;
	
		case "fighting_in_tavern":
			LAi_SetPlayerType(pchar);
			locCameraFollow();
			LAi_LocationFightDisable(&Locations[FindLocation("Quest_redmond_tavern")], false);
			LAi_SetWarriorType(characterFromID("soldier1"));
			LAi_group_MoveCharacter(characterFromID("soldier1"), "ENGLAND_TAVERN_SOLDIERS");
			
			LAi_SetHP(characterFromID("Ralph Fawn"), 1.0, 1.0);

			LAi_SetOfficerType(characterFromID("danielle"));
			LAi_SetOfficerType(characterFromID("ralph fawn"));
			LAi_group_FightGroups("ENGLAND_TAVERN_SOLDIERS", LAI_GROUP_PLAYER, true);
			//трактирщик убегает в обычную (не квестовую таверну)
			LAi_SetActorType(characterFromID("Charles Windem"));
			LAi_ActorRunToLocator(characterFromID("Charles Windem"), "merchant", "reload2", "Charles_escape_from_quest_redmond_tavern_complete", -1);
			LAi_group_SetCheck("ENGLAND_TAVERN_SOLDIERS", "out_from_quest_tavern_complete");
			LAi_QuestDelay("ralph_fawn_death_complete", 6.0);
		break;

		case "ralph_fawn_death_complete":
			LAi_KillCharacter(characterFromID("ralph fawn"));
		break;

		//смерть всех солдат в таверне
		case "out_from_quest_tavern_complete":
			LAi_LocationFightDisable(&Locations[FindLocation("Quest_redmond_tavern")], true);
			pchar.quest.main_line = "fawn_death";
			AddQuestRecord("Blaze_out_from_silehard", "2");
			LAi_QuestDelay("out_from_quest_tavern_complete_2", 3.0);
		break;

		case "out_from_quest_tavern_complete_2":
			LAi_setActorType(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("danielle"));
			LAi_SetActorType(characterFromID("danielle"));
			LAi_ActorDialog(characterFromID("Danielle"), pchar, "pchar_back_to_player", 3.0, 1.0);
		break;

		//Даниель убегает из таверны, оставляя там Блейза
		case "danielle_escape_from_quest_redmond_tavern_complete":
			//убираем Даниель
			ChangeCharacterAddress(characterFromID("Danielle"), "none", "none");
			LAi_QuestDelay("danielle_escape_from_quest_redmond_tavern_2_complete", 1.0);
		break;

		case "danielle_escape_from_quest_redmond_tavern_2_complete":
			LAi_SetStayType(pchar);

			sld = LAi_CreateFantomCharacter("soldier_eng", "goto", "goto17");
			sld.model.head = "h_soldier_eng";
			
			sld = LAi_CreateFantomCharacter("soldier_eng2", "goto", "goto18");
			sld.model.head = "h_soldier_eng";
			
			sld = LAi_CreateFantomCharacter("soldier_eng", "reload", "reload1");
			sld.model.head = "h_soldier_eng";

			sld = LAi_CreateFantomCharacter("offic_eng", "goto", "goto19");
			sld.model.head = "h_offic_eng";
			sld.dialog.filename = "soldier_for_fight_in_tavern_01_dialog.c";
			
			LAi_SetActorType(sld);
			LAi_ActorDialog(sld, pchar, "pchar_back_to_player", 8.0, 2.0);
			

			locx = stf(loadedLocation.locators.camera.locator12.x);
			locy = stf(loadedLocation.locators.camera.locator12.y);
			locz = stf(loadedLocation.locators.camera.locator12.z);
			locCameraToPos(locx, locy, locz, false);
		break;

		//трактирщик убегает из квестовой таверны
		case "Charles_escape_from_quest_redmond_tavern_complete":
			//убираем трактирщика
			ChangeCharacterAddressGroup(characterFromID("Charles Windem"), "Redmond_Tavern", "merchant", "goto1");
			LAi_SetMerchantType(characterFromID("Charles Windem"));
		break;

		case "Blaze_to_prison_complete":
			RemoveCharacterEquip(pchar, BLADE_ITEM_TYPE);
			RemoveCharacterEquip(pchar, GUN_ITEM_TYPE);
			EnableEquip(pchar, BLADE_ITEM_TYPE, false);
			EnableEquip(pchar, GUN_ITEM_TYPE, false);
			StorePassengers("Blaze");

			DoQuestReloadToLocation("Redmond_prison", "goto", "goto9", "prepare_Edgar_to_Blaze_complete");
		break;

		case "prepare_Edgar_to_Blaze_complete":			
			LAi_SetActorType(characterFromID("Edgar Attwood"));

			AddQuestRecord("Blaze_out_from_silehard", "3");
			CloseQuestHeader("Blaze_out_from_silehard");
			SetQuestHeader("Blaze_in_prison");
			AddQuestRecord("Blaze_in_prison", "1");
			//Выключаем выход из тюрьмы
			locations[FindLocation("Redmond_prison")].reload.l1.disable = 1;
			//говорим подойти Эдгару к блейзу и начать разговор
			LAi_ActorGoToLocator(characterFromID("Edgar Attwood"), "goto", "goto23", "Edgar_to_Blaze_complete", -1);
			//включаем обычную таверну
			locations[FindLocation("Redmond_town_01")].reload.l11.go = "Redmond_tavern";
			//на всякий случай еще раз передвигаем трактирщика
			ChangeCharacterAddressGroup(characterFromID("Charles Windem"), "Redmond_Tavern", "merchant", "goto1");
		break;

		//Эдгар подходит к блейзу
		case "Edgar_to_Blaze_complete":
			locx = stf(loadedLocation.locators.camera.camera13.x);
			locy = stf(loadedLocation.locators.camera.camera13.y);
			locz = stf(loadedLocation.locators.camera.camera13.z);
			locCameraToPos(locx, locy, locz, false);

			pchar.quest.main_line = "prison";
			LAi_ActorDialogNow(characterFromID("Edgar Attwood"), pchar, "", -1);
			pchar.quest.edgar_life = "live";
			pchar.quest.kill_edgar_attwood_in_prison.win_condition.l1 = "NPC_Death";
			pchar.quest.kill_edgar_attwood_in_prison.win_condition.l1.character = "Edgar Attwood";
			pchar.quest.kill_edgar_attwood_in_prison.win_condition = "kill_edgar_attwood_in_prison_complete";

			pchar.quest.to_locator_where_soldiers_in_prison_see_you.win_condition.l1 = "locator";
			pchar.quest.to_locator_where_soldiers_in_prison_see_you.win_condition.l1.location = "Redmond_prison";
			pchar.quest.to_locator_where_soldiers_in_prison_see_you.win_condition.l1.locator_group = "merchant";
			pchar.quest.to_locator_where_soldiers_in_prison_see_you.win_condition.l1.locator = "reload13";
			pchar.quest.to_locator_where_soldiers_in_prison_see_you.win_condition = "to_locator_where_soldiers_in_prison_see_you_complete";
		break;

		//Эдгар отходит от камеры
		case "wait_for_night_in_prison_complete":
			pchar.quest.main_line = "inside_redmond_prison";
			ChangeCharacterAddressGroup(characterFromID("Robert Christopher Silehard"), "Redmond_Prison", "merchant", "reload13");
			LAi_SetActorType(characterFromID("Robert Christopher Silehard"));
			LAi_ActorGoToLocator(characterFromID("Robert Christopher Silehard"), "goto", "goto23", "Silehard_to_blaze_complete", -1);
			characters[GetCharacterIndex("Robert Christopher Silehard")].dialog.CurrentNode = "escape_from_prison_node_2";
			LAi_Fade("", "");
		break;

		case "prepare_exit_from_cam":
			LAi_Fade("blaze_exit_from_cam_complete", "second_speak_with_edgar_complete");
		break;

		//Блейз выходит из камеры
		case "blaze_exit_from_cam_complete":
			EnableEquip(pchar, BLADE_ITEM_TYPE, true);
			EnableEquip(pchar, GUN_ITEM_TYPE, true);
			EquipCharacterByItem(pchar, FindCharacterItemByGroup(pchar, BLADE_ITEM_TYPE));
			EquipCharacterByItem(pchar, FindCharacterItemByGroup(pchar, GUN_ITEM_TYPE));
			//ставим Эдгара рядом с блейзом
			locCameraFollow();
			ChangeCharacterAddress(pchar, "Redmond_prison", "goto12");
			pchar.quest.main_line = "escape_from_redmond_prison";
			ChangeCharacterAddress(characterFromID("Edgar Attwood"), "redmond_prison", "goto23");
			//даем квест на убийство всех стражников в тюрьме
			pchar.quest.kill_all_soldiers_in_prison.win_condition.l1 = "NPC_Death";
			pchar.quest.kill_all_soldiers_in_prison.win_condition.l1.character = "Eng_soldier_35";
			pchar.quest.kill_all_soldiers_in_prison.win_condition.l2 = "NPC_Death";
			pchar.quest.kill_all_soldiers_in_prison.win_condition.l2.character = "Eng_soldier_36";
			pchar.quest.kill_all_soldiers_in_prison.win_condition = "kill_all_soldiers_in_prison_complete";
			//продолжаем разговор, где говорим, что нужно убить солдат на выходе.
			characters[GetCharacterIndex("Robert Christopher Silehard")].dialog.CurrentNode = "escape_from_prison_node";
			//временно прячем губернатора
			ChangeCharacterAddress(characterFromID("Robert Christopher Silehard"), "none", "none");
			LAi_LocationFightDisable(&Locations[FindLocation("redmond_prison")], false);
		break;

		case "kill_edgard_in_prison_2_complete":
			if (pchar.location == "redmond_prison")
			{
				LAi_SetPlayerType(pchar);
				pchar.quest.edgar_life = "death";
				AddQuestRecord("Blaze_in_prison", "4");
				//солдаты слышат шум и идут воевать игрока.
				LAi_group_SetRelation("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
				OfficersReaction("bad");
			}
		break;

		case "second_speak_with_edgar_complete":
			LAi_ActorDialog(characterFromID("Edgar Attwood"), pchar, "", 1.0, 1.0);
		break;
		
		//сайлхард подходит к блейзу
		case "Silehard_to_Blaze_complete":
			LAi_SetCitizenType(characterFromID("Edgar Attwood"));
			LAi_ActorDialogNow(characterFromID("Robert Christopher Silehard"), pchar, "", -1);
		break;

		case "exit_from_prison":
			pchar.quest.to_locator_where_soldiers_in_prison_see_you.over = "yes";
			locCameraFollow();
			LAi_group_SetRelation("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
			ChangeCharacterAddress(characterFromID("Robert Christopher Silehard"), "redmond_residence", "goto8");
			characters[GetCharacterIndex("Robert Christopher Silehard")].dialog.CurrentNode = "main_line_find_rheims_node";
			pchar.quest.main_line = "blaze_talk_with_silehard";
			DoQuestReloadToLocation("redmond_residence", "goto", "goto3", "blaze_from_prison_to_residence_complete");
			LAi_LocationFightDisable(&Locations[FindLocation("redmond_prison")], true);
			EnableEquip(pchar, BLADE_ITEM_TYPE, true);
			EnableEquip(pchar, GUN_ITEM_TYPE, true);
			EquipCharacterByItem(pchar, FindCharacterItemByGroup(pchar, BLADE_ITEM_TYPE));
			EquipCharacterByItem(pchar, FindCharacterItemByGroup(pchar, GUN_ITEM_TYPE));
			RecalculateJumpTable();
		break;

		//проходим за сайлхардом в его кабинет
		case "blaze_from_prison_to_residence_complete":
			ReStorePassengers("Blaze");
			LAi_group_SetRelation("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
			LAi_group_SetRelation("ENGLAND_CITIZENS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);

			LAi_group_SetAlarm("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, 0.0);
			LAi_group_SetAlarm("ENGLAND_CITIZENS", LAI_GROUP_PLAYER, 0.0);
			LAi_group_SetAlarm("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, 0.0);

			LAi_LocationFightDisable(&Locations[FindLocation("redmond_prison")], true);
			pchar.quest.kill_edgar_attwood_in_prison.over = "yes";
			pchar.quest.to_locator_where_soldiers_in_prison_see_you.over = "yes";
			locations[FindLocation("Redmond_prison")].reload.l1.disable = 0;
			LAi_SetHuberStayType(characterFromID("Robert Christopher Silehard"));
			LAi_SetActorType(pchar);
			LAi_ActorDialog(pchar, characterFromID("Robert Christopher Silehard"), "pchar_back_to_player", 2.0, 1.0);
			ChangeCharacterAddress(characterFromID("Eng_soldier_35"), "redmond_prison", "goto16");
			ChangeCharacterAddress(characterFromID("Eng_soldier_36"), "redmond_prison", "goto14");
			ChangeCharacterAddressGroup(characterFromID("Redmond prison commendant"), "redmond_prison", "sit", "sit1");

			DeleteAttribute(Pchar, "Quest.Story_OxbayCaptured"); 
			//Смена национальности форта Оксбэя
			Characters[GetCharacterIndex("Oxbay Commander")].nation = ENGLAND;
			Characters[GetCharacterIndex("Oxbay Commander")].model = "Soldier_Eng";
			//Смена французских солдат в Оксбэе на английских
			//Удаление французских
			ChangeCharacterAddress(characterFromID("Fra_occupant_01"), "None", "");
			ChangeCharacterAddress(characterFromID("Fra_occupant_02"), "None", "");
			ChangeCharacterAddress(characterFromID("Fra_occupant_03"), "None", "");
			ChangeCharacterAddress(characterFromID("Fra_occupant_04"), "None", "");
			ChangeCharacterAddress(characterFromID("Fra_occupant_05"), "None", "");
			ChangeCharacterAddress(characterFromID("Fra_occupant_06"), "None", "");
			ChangeCharacterAddress(characterFromID("Fra_occupant_07"), "None", "");
			ChangeCharacterAddress(characterFromID("Fra_occupant_08"), "None", "");
			ChangeCharacterAddress(characterFromID("Occ_Patrol_1"), "none", "");
			ChangeCharacterAddress(characterFromID("Occ_Patrol_2"), "none", "");
			ChangeCharacterAddress(characterFromID("Occ_Patrol_3"), "none", "");
			ChangeCharacterAddress(characterFromID("Occ_Patrol_4"), "none", "");
			//Постановка английских
			ChangeCharacterAddress(characterFromID("Ox_Soldier_1"), "Oxbay_town", "goto3");
			ChangeCharacterAddress(characterFromID("Ox_Soldier_2"), "Oxbay_town", "goto4");
			ChangeCharacterAddress(characterFromID("Ox_Soldier_3"), "Oxbay_town", "goto1");
			ChangeCharacterAddress(characterFromID("Ox_Soldier_4"), "Oxbay_town", "goto2");
			ChangeCharacterAddress(characterFromID("Ox_Soldier_5"), "Oxbay_port", "goto20");
			ChangeCharacterAddress(characterFromID("Ox_Soldier_6"), "Oxbay_port", "goto21");
			ChangeCharacterAddress(characterFromID("Ox_Soldier_7"), "Oxbay_town_exit", "citizen09");
			ChangeCharacterAddress(characterFromID("Ox_Soldier_8"), "Oxbay_town_exit", "citizen010");
			ChangeCharacterAddress(characterFromID("Ox_Patrol_1"), "Oxbay_port", "goto18");
			ChangeCharacterAddress(characterFromID("Ox_Patrol_2"), "Oxbay_port", "goto12");
			ChangeCharacterAddress(characterFromID("Ox_Patrol_3"), "Oxbay_town", "goto31");
			ChangeCharacterAddress(characterFromID("Ox_Patrol_4"), "Oxbay_town", "goto20");
			//Убирание из гавани Оксбэя кораблей французской эскадры
			Group_SetAddress("Story_French_Squadron", "none", "Quest_Ships","Quest_Ship_7");
			LAi_SetImmortal(characterFromID("FalaiseDeFleur Commander"), false);
			LAi_SetImmortal(characterFromID("Oxbay Commander"), false);
			
			SetNationRelation2MainCharacter(FRANCE, RELATION_NEUTRAL);
			RestorePassengers("Blaze");
		break;

		case "back_to_hovernor_type":
			characters[GetCharacterIndex("Counterspy")].location = "none";
			characters[GetCharacterIndex("Rabel Iverneau")].location = "none";
			LAi_SetHuberStayType(characterFromID("Robert Christopher Silehard"));
		break;

		//убить всех солдат в тюрьме
		case "kill_all_soldiers_in_prison_complete":
			LAi_group_SetRelation("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
			//появления губернатора со стражниками и начало разговора
			LAi_QuestDelay("Silehard_in_prison_complete", 3.0);
		break;

		case "silehard_in_prison_complete":
			LAi_SetActorType(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("Robert Christopher Silehard"));
			LAi_LocationFightDisable(&Locations[FindLocation("redmond_prison")], true);
			LAi_SetActorType(characterFromID("Robert Christopher Silehard"));
			ChangeCharacterAddressGroup(characterFromID("Robert Christopher Silehard"), "Redmond_Prison", "reload", "reload1");
			LAi_ActorDialog(characterFromID("Robert Christopher Silehard"), pchar, "", 5.0, 0);
		break;

		//блейз достигает локатора в тюрьме, за которым его видят стражники
		case "to_locator_where_soldiers_in_prison_see_you_complete":
			if (pchar.quest.main_line == "escape_from_redmond_prison")
			{
				LAi_group_SetRelation("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
				LAi_group_FightGroups("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, true);
				//Убираем сидящего солдата
				ChangeCharacterAddress(characterFromID("Redmond prison commendant"), "none", "none");
			}
		break;

		case "exit_from_silehard_2_complete":
			ChangeCharacterAddress(characterFromID("Edgar Attwood"), "redmond_port", "goto_2");
			LAi_SetActorType(characterFromID("Edgar Attwood"));
			LAi_ActorDialog(characterFromID("Edgar Attwood"), pchar, "", 3.0, 1.0);
		break;

		//появление мужика, дающего информацию о местонахождении реймса
		case "ines_denied_exit_from_tavern_complete":
			pchar.quest.kill_pirate_for_rheims_lore.win_condition.l1 = "NPC_death";
			pchar.quest.kill_pirate_for_rheims_lore.win_condition.l1.character = "quest_pirate_01";
			pchar.quest.kill_pirate_for_rheims_lore.win_condition = "kill_pirate_for_rheims_lore_complete";
			LAi_SetHP(characterFromID("quest_pirate_01"), 80.0, 80.0);
			ChangeCharacterAddress(characterFromID("quest_pirate_01"), "QC_town", "goto12");
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("quest_pirate_01"));
			LAi_ActorFollow(pchar, characterFromID("quest_pirate_01"), "", 2.0);
			LAi_ActorFollow(characterFromID("quest_pirate_01"), pchar, "ines_denied_exit_from_tavern_complete_2", 2.0);
		break;
		
		case "ines_denied_exit_from_tavern_complete_2":
			LAi_type_actor_Reset(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("quest_pirate_01"));
			LAi_ActorDialog(characterFromID("quest_pirate_01"), pchar, "quest_pirate_01_back_to_player", 1.0, 1.0);
		break;

		case "quest_pirate_ines_info_denied_6":
			pchar.quest.main_line = "blaze_talk_with_innes_diaz_complete";
			AddQuestRecord("Blaze_search_Rheims", "4");
			locations[FindLocation("QC_town")].reload.l3.disable = 0;
			pchar.quest.kill_pirate_for_rheims_lore.over = "yes";
			LAi_SetCitizenType(characterFromID("quest_pirate_01"));
		break;

		case "quest_pirate_01_back_to_player":
			LAi_SetPlayerType(pchar);
		break;

		case "fight_with_quest_pirate_after_ines_denied":
			LAi_group_MoveCharacter(characterFromID("quest_pirate_01"), "QC_BRODYAGA");
			LAi_group_FightGroups("QC_BRODYAGA", LAI_GROUP_PLAYER, true);
			//LAi_ActorAttack(characterFromID("quest_pirate_01"), pchar, "");
		break;

		case "kill_pirate_for_rheims_lore_complete":
			AddQuestRecord("Blaze_search_Rheims", "13");
			pchar.quest.main_line = "blaze_talk_with_innes_diaz_complete_21";
			//возраждаем пирата для следующих сценок
			characters[getCharacterIndex("quest_pirate_01")].location = "none";
			LAi_SetCurHP(characterFromID("quest_pirate_01"), 80.0); 
			
			Locations[FindLocation("QC_town")].reload.l3.disable = 0;
	
			OfficersReaction("bad");
		break;

		//говорим контрабандистам отвести блейза к камило мачадо
		case "exit_from_duarte_complete":
			PlaceCharacter(characterFromID("quest_smuggler_01"), "goto", "Conceicao_town");
			
			LAi_SetActorType(pchar);
			LAi_ActorFollow(pchar, characterFromID("quest_smuggler_01"), "", 2.0);
			LAi_ActorFollow(characterFromID("quest_smuggler_01"), pchar, "exit_from_duarte_complete_2", 2.0);
		break;
		
		case "exit_from_duarte_complete_2":
			LAi_type_actor_Reset(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("quest_smuggler_01"));
			Locations[FindLocation("Smugglers_residence")].reload.l1.disable = 1;
			LAi_ActorDialog(characterFromID("quest_smuggler_01"),  pchar, "pchar_back_to_player", 5.0, 1.0);
		break;
		
		//первый раз попадаем в дом к Мачадо
		case "blaze_first_speak_with_machado_complete":
			Locations[FindLocation("Rheims_house_in_smugglers")].reload.l1.disable = 1;
			Locations[FindLocation("Conceicao_town")].reload.l3.disable = 0;
			pchar.quest.main_line = "blaze_talk_with_machado";
			LAi_SetActorType(characterFromID("Camilo Machado"));
			LAi_ActorDialog(characterFromID("Camilo Machado"), pchar, "machado_back_to_hovernor_type", 50, 0);
		break;

		case "machado_back_to_hovernor_type":
			if (makeint(environment.time) >= 22 || makeint(environment.time) < 6)
			{
				pchar.quest.main_line = "night_for_rheims_house_complete";
				Locations[FindLocation("Smugglers_Lair")].reload.l6.disable = 0;
			}
			LAi_SetHuberStayType(characterFromID("Camilo Machado"));
			LAi_group_MoveCharacter(characterFromID("Camilo Machado"), "SMUGGLERS_CITIZENS");
		break;

		//блейз ждал ночи в таверне
		case "wait_for_night_complete":
			//включаем ночь.
			pchar.quest.main_line = "night_for_rheims_house_complete";
			Locations[FindLocation("Smugglers_Lair")].reload.l6.disable = 0;
			AddQuestrecord("Blaze_search_Rheims", "8");
		break;

		//блейз ждет ночи в комнате
		case "wait_for_night_in_room_complete":
			pchar.quest.main_line = "night_for_rheims_house";
		break;

		//Блейз пробрался в дом Реймса
		case "blaze_to_rheims_house_in_smugglers_complete":
			LAi_QuestDelay("blaze_to_rheims_house_in_smugglers_find_book_complete", 2.0);
		break;
		
		//Блейз нашел книгу.
		case "blaze_to_rheims_house_in_smugglers_find_book_complete":
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(pchar, "goto", "goto2", "blaze_to_rheims_house_in_smugglers_find_book_complete_2", 2.0);
		break;

		case "blaze_to_rheims_house_in_smugglers_find_book_complete_2":
			characters[GetCharacterIndex("Robert Christopher Silehard")].dialog.CurrentNode = "blaze_return_to_silehard_node";
			pchar.quest.main_line = "blaze_found_book_in_rheims_house";
			//Добавляем предмет
			GiveItem2Character(pchar, RHEIMS_JOURNAL);
			LAi_ActorSelfDialog(pchar, "");
		break;

		case "blaze_fight_in_rheims_house_complete":
			Locations[FindLocation("Rheims_house_in_smugglers")].reload.l1.disable = 0;
			if (LAi_IsDead(characterFromID("Macario Regalo")) && LAi_IsDead(characterFromID("Evaristo Filho")))
			{
				//появляем других стражников
				ChangeCharacterAddressGroup(characterFromID("Fernam  Barrios"), "Rheims_house_in_smugglers", "reload", "reload1");
				ChangeCharacterAddressGroup(characterFromID("Leborio Violate"), "Rheims_house_in_smugglers", "reload", "reload1");
				LAi_SetActorType(characterfromID("Leborio Violate"));
				LAi_ActorFollow(pchar, characterfromID("Leborio Violate"), "", 1.0);
				LAi_ActorFollow(characterfromID("Leborio Violate"), pchar, "blaze_fight_in_rheims_house_complete_2", 1.0);
			}
			else
			{
				//появляем стражников у дома реймса
				ChangeCharacterAddressGroup(characterFromID("Macario Regalo"), "Rheims_house_in_smugglers", "reload", "reload1");
				ChangeCharacterAddressGroup(characterFromID("Evaristo Filho"), "Rheims_house_in_smugglers", "reload", "reload1");
				LAi_SetActorType(characterfromID("Evaristo Filho"));
				LAi_ActorFollow(pchar, characterfromID("Evaristo Filho"), "", 1.0);
				LAi_ActorFollow(characterfromID("Evaristo Filho"), pchar, "blaze_fight_in_rheims_house_complete_3", 1.0);
			}
		break;
		
		case "blaze_fight_in_rheims_house_complete_2":
			LAi_type_actor_Reset(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("Leborio Violate"));
			LAi_ActorDialog(characterFromID("Leborio Violate"), pchar, "back_to_smuggler_guard", 3.0, 0);
		break;
		
		case "blaze_fight_in_rheims_house_complete_3":
			LAi_type_actor_Reset(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("Evaristo Filho"));
			LAi_ActorDialog(characterFromID("Evaristo Filho"), pchar, "back_to_smuggler_guard", 3.0, 0);
		break;

		case "back_to_smuggler_guard":
			Lai_SetPlayerType(pchar);
			LAi_group_MoveCharacter(characterfromID("Leborio Violate"), "SMUGGLERS_SOLDIERS");
			LAi_group_MoveCharacter(characterfromID("Evaristo Filho"), "SMUGGLERS_SOLDIERS");
			LAi_group_MoveCharacter(characterfromID("Fernam  Barrios"), "SMUGGLERS_SOLDIERS");
			LAi_group_MoveCharacter(characterfromID("Macario Regalo"), "SMUGGLERS_SOLDIERS");
			LAi_group_SetRelation("SMUGGLERS_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("SMUGGLERS_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("SMUGGLERS_SOLDIERS", "kill_guards_in_rheims_house_smugglers_complete");
		break;
		
		//блейз убивает стражников
		case "kill_guards_in_rheims_house_smugglers_complete":
			if (pchar.location == "Rheims_house_in_smugglers")
			{
				LAi_group_SetRelation("SMUGGLERS_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
				AddQuestrecord("Blaze_search_Rheims", "9");
				pchar.quest.main_line = "blaze_return_to_silehard";
				Locations[FindLocation("Rheims_house_in_smugglers")].reload.l1.disable = 0;
			}
			else
			{
				AddQuestrecord("Blaze_search_Rheims", "10");
				Locations[FindLocation("Smugglers_Lair")].reload.l5.disable = 0;
			}
			LAi_SetHP(characterFromID("quest_pirate_01"), 80.0, 80.0);
		break;

		//блейз убивает стражников
		case "kill_guards_in_rheims_house_smugglers_2_complete":
			LAi_group_SetRelation("SMUGGLERS_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
			AddQuestrecord("Blaze_search_Rheims", "9");
			pchar.quest.main_line = "blaze_return_to_silehard";
			Locations[FindLocation("Rheims_house_in_smugglers")].reload.l1.disable = 0;
		break;

		case "Friedrich_Corleis_go_away":
			LAi_SetActorType(characterfromID("Friedrich Corleis")); 
			LAi_ActorGoToLocator(characterfromID("Friedrich Corleis"), "Merchant", "reload3", "blaze_to_incas_collection_begin_1_complete", -1);
		break;

		//Трактирщик на Дувезене уходит за пиратом
		case "blaze_to_incas_collection_begin_1_complete":
			ChangeCharacterAddress(characterFromID("Friedrich Corleis"), "none", "");
			LAi_QuestDelay("wait_for_pirate_in_tavern_complete", 2.0);
		break;

		case "wait_for_pirate_in_tavern_complete":
			LAi_SetHP(characterFromID("quest_pirate_01"), 80.0, 80.0);
			Lai_SetActorType(characterFromID("quest_pirate_01"));
			characters[GetCharacterIndex("quest_pirate_01")].model = "corsair2";
			characters[GetCharacterIndex("quest_pirate_01")].headmodel = "h_corsair2";
			ChangeCharacterAddressGroup(characterFromID("quest_pirate_01"), "Douwesen_tavern", "reload", "reload1");
			LAi_ActorDialog(characterFromID("quest_pirate_01"), pchar, "", 2.0, 1.0);
		break;

		case "teleport_to_douwesen_exit":
			LAi_SetCheckMinHP(characterFromID("quest_pirate_01"), 79.0, false, "quest_pirate_01_exit_with_fight");
			ChangeCharacterAddressGroup(CharacterFromID("Friedrich Corleis"), "Douwesen_tavern", "merchant", "goto1");
			LAi_SetMerchantType(characterfromID("Friedrich Corleis")); 
			DoQuestReloadToLocation("Douwesen_town_exit", "goto", "goto10", "incas_collection_to_douwesen_town_exit");
			ChangeCharacterAddress(CharacterFromID("quest_pirate_01"), "Douwesen_town_exit", "goto11");
			StorePassengers(pchar.id);
			LAi_SetMerchantType(characterfromID("Friedrich Corleis")); 
			pchar.quest.return_officers_in_ship_location.win_condition.l1 = "location";
			pchar.quest.return_officers_in_ship_location.win_condition.l1.location = pchar.location.from_sea;
			pchar.quest.return_officers_in_ship_location.win_condition = "return_officers_in_ship_location";
		break;
		
		case "return_officers_in_ship_location":
			reStorePassengers(pchar.id);
		break;

		//пират объясняет нам как попасть в логово пиратов
		case "incas_collection_to_douwesen_town_exit":
			LAi_ActorDialog(characterFromID("quest_pirate_01"), pchar, "", 2.0, 1.0);
		break;

		case "prepare_go_to_pirate_fort_complete":
			pchar.quest.main_line = "blaze_to_incas_collection_begin_3";
			pchar.quest.go_to_pirate_fort.win_condition.l1 = "location";
			pchar.quest.go_to_pirate_fort.win_condition.l1.location = "Douwesen_jungle_03";
			pchar.quest.go_to_pirate_fort.win_condition = "go_to_pirate_fort_complete";
			LAi_ActorRunToLocator(CharacterFromID("quest_pirate_01"), "reload", "reload1_back", "", 90.0);
		break;

		case "go_to_pirate_fort_complete":
			LAi_type_actor_Reset(CharacterFromID("quest_pirate_01"));
			ChangeCharacterAddress(CharacterFromID("quest_pirate_01"), "Douwesen_jungle_03", "citizen09");
			LAi_ActorRunToLocator(CharacterFromID("quest_pirate_01"), "reload", "reload3_back", "", 90.0);
			pchar.quest.go_to_pirate_fort1.win_condition.l1 = "location";
			pchar.quest.go_to_pirate_fort1.win_condition.l1.location = "Douwesen_jungle_02";
			pchar.quest.go_to_pirate_fort1.win_condition = "go_to_pirate_fort1_complete";
		break;

		case "go_to_pirate_fort1_complete":
			LAi_type_actor_Reset(CharacterFromID("quest_pirate_01"));
			ChangeCharacterAddressGroup(CharacterFromID("quest_pirate_01"), "Douwesen_jungle_02", "reload", "reload3");
			LAi_ActorRunToLocator(characterFromID("quest_pirate_01"), "reload", "reload2_back", "", 90.0);
			pchar.quest.go_to_pirate_fort2.win_condition.l1 = "location";
			pchar.quest.go_to_pirate_fort2.win_condition.l1.location = "Douwesen_jungle_01";
			pchar.quest.go_to_pirate_fort2.win_condition = "go_to_pirate_fort2_complete";
		break;

		case "go_to_pirate_fort2_complete":
			LAi_type_actor_Reset(CharacterFromID("quest_pirate_01"));
			ChangeCharacterAddress(characterFromID("quest_pirate_01"), "Douwesen_jungle_01", "citizen08");
			LAi_ActorRunToLocator(characterFromID("quest_pirate_01"), "reload", "reload1_back", "", 90.0);
			pchar.quest.go_to_pirate_fort3.win_condition.l1 = "location";
			pchar.quest.go_to_pirate_fort3.win_condition.l1.location = "Pirate_Fort";
			pchar.quest.go_to_pirate_fort3.win_condition = "go_to_pirate_fort3_complete";
		break;

		case "go_to_pirate_fort3_complete":
			pchar.quest.main_line = "blaze_to_incas_collection_begin_4";
			ChangeCharacterAddress(characterFromID("quest_pirate_01"), "Pirate_fort", "goto17");
			if (!LAi_isDead(characterFromID("quest_pirate_01")))
			{
				LAi_type_actor_Reset(CharacterFromID("quest_pirate_01"));
				LAi_SetActorType(pchar);
				LAi_ActorFollow(pchar, characterFromID("quest_pirate_01"), "", 2.0);
				LAi_ActorFollow(characterFromID("quest_pirate_01"), pchar, "go_to_pirate_fort4_complete", 2.0);
			}
			else
			{
				if (GetCharacterSkill(pchar, SKILL_SNEAK) < 3)
				{
					LAi_SetActorType(characterFromID("Pieter Nolt"));
					LAi_SetActorType(pchar);
					LAi_ActorFollow(pchar, characterfromID("Pieter Nolt"), "", 3.0);
					LAi_ActorFollow(characterfromID("Pieter Nolt"), pchar, "speak_with_pieter_nolt", 3.0);
				}
			}
			reStorePassengers(pchar.id);
		break;

		case "speak_with_pieter_nolt":
			LAi_type_actor_Reset(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("Pieter Nolt"));
			LAi_ActorDialog(characterFromID("Pieter Nolt"), pchar, "pieter_nolt_back_to_soldier", 4.0, 0);	
		break;
		
		case "go_to_pirate_fort4_complete":
			LAi_type_actor_Reset(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("quest_pirate_01"));
			LAi_ActorDialog(characterFromID("quest_pirate_01"), pchar, "pchar_back_to_player", 1.0, 1.0);
		break;

		case "pieter_nolt_back_to_soldier":
			LAi_SetPlayerType(pchar);
			LAi_SetPatrolType(characterFromID("Pieter Nolt"));
			LAi_group_MoveCharacter(characterFromID("Pieter Nolt"), "DOUWESEN_PIRATE_SOLDIERS");
		break;

		case "pirate_go_to_jungle_complete":
			ChangeCharacterAddress(characterFromID("quest_pirate_01"), "none", "none");
			pchar.quest.main_line = "blaze_to_incas_collection_begin_5";
		break;

		case "go_to_pirate_fort_fight_complete":
			if (!Lai_IsDead(characterFromID("quest_pirate_01")))
			{
				ChangeCharacterAddress(characterFromID("quest_pirate_01"), "Douwesen_jungle_03", "citizen01");
				LAi_ActorDialog(characterFromID("quest_pirate_01"), pchar, "", 2.0, 0);
				pchar.quest.go_to_pirate_fort3.win_condition.l1 = "location";
				pchar.quest.go_to_pirate_fort3.win_condition.l1.location = "Pirate_Fort";
				pchar.quest.go_to_pirate_fort3.win_condition = "go_to_pirate_fort3_complete";
			}
		break;

		case "garcilaso_fight_1":
			LAi_LocationFightDisable(&Locations[FindLocation("Douwesen_Pirate_Residence")], false);
			AddQuestRecord("blaze_to_incas_collection", "7");
			LAi_QuestDelay("garcilaso_fight_4", 2.0);
			LAi_SetActorType(pchar);
			LAi_ActorAttack(pchar, characterFromID("Alistair Garcilaso"), "");
		break;

		case "garcilaso_fight_2":
			LAi_LocationFightDisable(&Locations[FindLocation("Douwesen_Pirate_Residence")], false);
			AddQuestRecord("blaze_to_incas_collection", "15");
			LAi_SetActorType(pchar);
			LAi_ActorAttack(pchar, characterFromID("Alistair Garcilaso"), "");
			LAi_QuestDelay("garcilaso_fight_4", 2.0);
		break;

		case "garcilaso_fight_3":
			LAi_LocationFightDisable(&Locations[FindLocation("Douwesen_Pirate_Residence")], false);
			LAi_SetActorType(pchar);
			LAi_ActorAttack(pchar, characterFromID("Alistair Garcilaso"), "");
			LAi_QuestDelay("garcilaso_fight_4", 2.0);
			GiveItem2Character(pchar, INCAS_COLLECTION);
			Group_SetAddress("Pirate Captain 06", "none", "Quest_Ships","Quest_Ship_9");
			pchar.quest.main_line = "blaze_to_incas_collection_begin_8";
			AddQuestRecord("blaze_to_incas_collection", "14");
			SetCharacterShipLocation(&characters[GetCharacterIndex("Pirate Captain 05")], "none");
			ChangeCharacterAddress(&characters[GetCharacterIndex("Danielle_sailor")], "none", "none");
			characters[GetCharacterIndex("Robert Christopher Silehard")].dialog.CurrentNode = "incas_collection_complete_node";
		break;

		case "garcilaso_fight_4":
			LAi_KillCharacter(characterFromID("Alistair Garcilaso"));
			LAi_SetPlayerType(pchar);
			pchar.quest.main_line = "blaze_to_incas_collection_begin_6";
			LAi_LocationFightDisable(&Locations[FindLocation("Douwesen_Pirate_Residence")], true);
		break;

		case "prepare_fighting_on_deck_complete":
			if (pchar.quest.main_line == "blaze_to_incas_collection_begin_6" || pchar.quest.main_line == "blaze_to_incas_collection_begin" || pchar.quest.main_line == "kill_pirate_06" || pchar.quest.main_line == "blaze_to_incas_collection_begin_7" || pchar.quest.main_line == "blaze_to_incas_collection_begin")
			{
				PlaceCharacter(characterFromID("danielle_sailor"), "goto", "douwesen_shore_01");
				LAi_SetActorType(pchar);
				LAi_SetActorType(characterFromID("danielle_sailor"));
				LAi_ActorFollow(pchar, characterFromID("danielle_sailor"), "", 2.0);
				LAi_ActorFollow(characterFromID("danielle_sailor"), pchar, "prepare_fighting_on_deck_complete_2", 2.0);
			}
		break;
		
		case "prepare_fighting_on_deck_complete_2":
			LAi_type_actor_Reset(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("danielle_sailor"));
			LAi_ActorDialog(characterFromID("danielle_sailor"), pchar, "pchar_back_to_player", 2.0, 1.0);
		break;

		case "exit_to_ship":
			DoQuestReloadToLocation("Ship_deck", "reload", "locator2", "fighting_on_deck_complete");
		break;

		case "fighting_on_deck_complete":
			pchar.quest.abording_pirate_06.over = "yes";
			pchar.quest.kill_pirate_06.over = "yes";
			ChangeCharacterAddress(characterFromID("danielle_sailor"), "none", "none");
			LAi_group_MoveCharacter(characterFromID("pirate for abordage 01"), "PIRATES_FOR_ABORDAGE");
			LAi_group_MoveCharacter(characterFromID("pirate for abordage 02"), "PIRATES_FOR_ABORDAGE");
			LAi_group_MoveCharacter(characterFromID("pirate for abordage 03"), "PIRATES_FOR_ABORDAGE");
			LAi_group_SetRelation("PIRATES_FOR_ABORDAGE", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("PIRATES_FOR_ABORDAGE", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("PIRATES_FOR_ABORDAGE", "kill_all_fighting_on_deck_complete");
		break;

		case "kill_all_fighting_on_deck_complete":
			LAi_QuestDelay("kill_all_fighting_on_deck_complete_2", 2.0);
			pchar.location.from_sea = "Douwesen_shore_01";
			AddPartyExp(pchar, 2000);
		break;

		case "kill_all_fighting_on_deck_complete_2":
			DoReloadCharacterToLocation("Douwesen_shore_01", "reload", "reload1");
			pchar.quest.main_line = "blaze_to_incas_collection_begin_6";
			characters[GetCharacterIndex("Robert Christopher Silehard")].dialog.CurrentNode = "incas_collection_complete_node";
			setCharacterShipLocation(characterFromID("Pirate Captain 04"), "none");
			AddQuestRecord("blaze_to_incas_collection", "8");
			pchar.quest.prepare_fighting_on_deck_complete.over = "yes";
			GiveItem2Character(pchar, INCAS_COLLECTION);
			Group_SetAddress("Pirate Captain 06", "none", "Quest_Ships","Quest_Ship_9");
			SetCharacterShipLocation(&characters[GetCharacterIndex("Pirate Captain 05")], "none");
		break;

		//начинается сценка с изобретателем
		case "prepare_for_first_meeting_with_researcher":
			pchar.quest.prepare_fighting_on_deck_complete.over = "yes";
			ChangeCharacterAddress(characterFromID("Bernard Gosling"), "none", "none");
			ChangeCharacterAddress(characterFromID("Garry Ankers"), "none", "none");
			ChangeCharacterAddress(characterFromID("Susannah Lazar"), "none", "none");
			ChangeCharacterAddress(characterFromID("Michael Collop"), "none", "none");
			ChangeCharacterAddress(characterFromID("Edgar Malter"), "none", "none");
			//ChangeCharacterAddress(characterFromID("Harold Smith"), "none", "none");
			ChangeCharacterAddress(characterFromID("Alan Newman"), "none", "none");
			ChangeCharacterAddress(characterFromID("Audrey Proude"), "none", "none");
			ChangeCharacterAddress(characterFromID("Green_patrol_3"), "none", "none");
			ChangeCharacterAddress(characterFromID("Green_patrol_4"), "none", "none");
			ChangeCharacterAddress(characterFromID("Green_patrol_41"), "none", "none");
			
			/*LAi_SetStayType(characterFromID("murderer_in_douwesen_01"));
			LAi_SetStayType(characterFromID("murderer_in_douwesen_02"));
			LAi_SetStayType(characterFromID("murderer_in_douwesen_03"));*/
			LAi_SetStayType(characterFromID("murderer_in_greenford_04"));
			LAi_SetStayType(characterFromID("murderer_in_greenford_05"));
			LAi_SetStayType(characterFromID("murderer_in_greenford_06"));

			/*ChangeCharacterAddress(characterFromID("murderer_in_douwesen_01"), "Greenford_town", "goto52");
			ChangeCharacterAddress(characterFromID("murderer_in_douwesen_02"), "Greenford_town", "goto53");
			ChangeCharacterAddress(characterFromID("murderer_in_douwesen_03"), "Greenford_town", "goto54");*/
			ChangeCharacterAddress(characterFromID("murderer_in_greenford_04"), "Greenford_town", "goto55");
			ChangeCharacterAddress(characterFromID("murderer_in_greenford_05"), "Greenford_town", "goto43");
			ChangeCharacterAddress(characterFromID("murderer_in_greenford_06"), "Greenford_town", "goto44");

			/*LAi_group_MoveCharacter(characterFromID("murderer_in_douwesen_01"), "GREENFORD_MURDERERS");
			LAi_group_MoveCharacter(characterFromID("murderer_in_douwesen_02"), "GREENFORD_MURDERERS");
			LAi_group_MoveCharacter(characterFromID("murderer_in_douwesen_03"), "GREENFORD_MURDERERS");*/
			LAi_group_MoveCharacter(characterFromID("murderer_in_greenford_04"), "GREENFORD_MURDERERS");
			LAi_group_MoveCharacter(characterFromID("murderer_in_greenford_05"), "GREENFORD_MURDERERS");
			LAi_group_MoveCharacter(characterFromID("murderer_in_greenford_06"), "GREENFORD_MURDERERS");
			
			/*LAi_SetHP(characterFromID("murderer_in_douwesen_01"), 50.0, 50.0);
			LAi_SetHP(characterFromID("murderer_in_douwesen_02"), 50.0, 50.0);
			LAi_SetHP(characterFromID("murderer_in_douwesen_03"), 50.0, 50.0);*/
			LAi_SetHP(characterFromID("murderer_in_greenford_04"), 50.0, 50.0);
			LAi_SetHP(characterFromID("murderer_in_greenford_05"), 50.0, 50.0);
			LAi_SetHP(characterFromID("murderer_in_greenford_06"), 50.0, 50.0);
			
			/*LAi_SetCheckMinHP(characterFromID("murderer_in_douwesen_01"), 49.0, false, "kill_murderer_2_complete");
			LAi_SetCheckMinHP(characterFromID("murderer_in_douwesen_02"), 49.0, false, "kill_murderer_2_complete");
			LAi_SetCheckMinHP(characterFromID("murderer_in_douwesen_03"), 49.0, false, "kill_murderer_2_complete");*/
			LAi_SetCheckMinHP(characterFromID("murderer_in_greenford_04"), 49.0, false, "kill_murderer_2_complete");
			LAi_SetCheckMinHP(characterFromID("murderer_in_greenford_05"), 49.0, false, "kill_murderer_2_complete");
			LAi_SetCheckMinHP(characterFromID("murderer_in_greenford_06"), 49.0, false, "kill_murderer_2_complete");

			pchar.quest.main_line = "to_oxbay_by_prisoner_escape";
			ChangeCharacterAddress(characterFromID("greenford_citizen_01"), "Greenford_town", "goto23");
		
			pchar.quest.meeting_researcher.win_condition.l1 = "location";
			pchar.quest.meeting_researcher.win_condition.l1.location = "Greenford_town";
			pchar.quest.meeting_researcher.win_condition = "meeting_researcher_complete";

			Locations[FindLocation("Greenford_town")].models.always.koster = "koster";
			Locations[FindLocation("Greenford_town")].models.always.koster.locator.group = "goto";
			Locations[FindLocation("Greenford_town")].models.always.koster.locator.name = "goto24";
			Locations[FindLocation("Greenford_town")].models.always.koster.tech = "dLightModel";
			ChangeCharacterAddress(characterFromID("researcher"), "Greenford_town", "goto45");
			LAi_SetActorType(characterFromID("researcher"));
			LAi_ActorAnimation(characterFromID("researcher"), "Ground_sitting", "", "");

			Locations[FindLocation("Greenford_town")].reload.l1.disable = 1;
			Locations[FindLocation("Greenford_town")].reload.l2.disable = 1;
			Locations[FindLocation("Greenford_town")].reload.l3.disable = 1;
			Locations[FindLocation("Greenford_town")].reload.l4.disable = 1;
			Locations[FindLocation("Greenford_town")].reload.l7.disable = 1;
			Locations[FindLocation("Greenford_town")].reload.l9.disable = 1;
			AddQuestRecord("move_prisoner_from_greenford", "2");
		break;

		case "meeting_researcher_complete":
			LAi_SetActorType(pchar);
			LAi_ActorFollow(pchar, characterFromID("greenford_citizen_01"), "", 2.0);
			LAi_ActorFollow(characterFromID("greenford_citizen_01"), pchar, "meeting_researcher_complete_2", 2.0);
			LAi_group_SetCheck("GREENFORD_MURDERERS", "kill_all_murderer_in_greenford_complete");
		break;
		
		case "meeting_researcher_complete_2":
			LAi_type_actor_Reset(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("greenford_citizen_01"));
			LAi_ActorDialog(characterFromID("greenford_citizen_01"), pchar, "pchar_back_to_player", 1.0, 1.0);
		break;

		case "kicked_by_murderer_complete":
			LAi_ActorAnimation(characterFromID("murderer_in_greenford_04"), "attack_2", "kicked_by_murderer_complete_2", 0.3);
		break;

		case "kicked_by_murderer_complete_2":
			LAi_ActorAnimation(pchar, "hit_2", "kicked_by_murderer_2_complete", 2.5);
		break;

		case "kicked_by_murderer_2_complete":
			pchar.quest.main_line = "resque_researcher_bad_kick";
			LAi_SetPlayerType(pchar);
			LAi_ActorDialogNow(characterFromID("murderer_in_greenford_04"), pchar, "", -1);
		break;

		case "kick_murderer_complete":
			LAi_SetActorType(pchar);
			LAi_ActorAttack(pchar, characterFromID("murderer_in_greenford_04"), "");
			LAi_QuestDelay("kill_murderer_complete", 2.0);
		break;

		case "kill_murderer_complete":
			LAi_KillCharacter(characterFromID("murderer_in_greenford_04"));
			LAi_group_FightGroups("GREENFORD_MURDERERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetRelation("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_NEITRAL);
			LAi_SetPlayerType(pchar);
		break;
		
		case "kill_murderer_2_complete":
			/*LAi_RemoveCheckMinHP(characterFromID("murderer_in_douwesen_01"));
			LAi_RemoveCheckMinHP(characterFromID("murderer_in_douwesen_02"));
			LAi_RemoveCheckMinHP(characterFromID("murderer_in_douwesen_03"));*/
			LAi_RemoveCheckMinHP(characterFromID("murderer_in_greenford_04"));
			LAi_RemoveCheckMinHP(characterFromID("murderer_in_greenford_05"));
			LAi_RemoveCheckMinHP(characterFromID("murderer_in_greenford_06"));
			
			LAi_group_FightGroups("GREENFORD_MURDERERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetRelation("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_NEITRAL);
		break;

		case "kill_all_murderer_in_greenford_complete":
			LAi_Fade("greenford_to_normal", "we_resque_researcher");
		break;
		
		case "greenford_to_normal":
			ChangeCharacterAddress(characterFromID("greenford_citizen_01"), "none", "none");

			ChangeCharacterAddress(characterFromID("Bernard Gosling"), "Greenford_town", "goto5");
			ChangeCharacterAddress(characterFromID("Garry Ankers"), "Greenford_town", "goto13");
			ChangeCharacterAddress(characterFromID("Susannah Lazar"), "Greenford_town", "goto12");
			ChangeCharacterAddress(characterFromID("Michael Collop"), "Greenford_town", "goto15");
			ChangeCharacterAddress(characterFromID("Edgar Malter"), "Greenford_town", "goto38");
			//ChangeCharacterAddress(characterFromID("Harold Smith"), "Greenford_town", "goto11");
			ChangeCharacterAddress(characterFromID("Alan Newman"), "Greenford_town", "goto17");
			ChangeCharacterAddress(characterFromID("Audrey Proude"), "Greenford_town", "goto33");
			ChangeCharacterAddress(characterFromID("Green_patrol_3"), "Greenford_town", "goto4");
			ChangeCharacterAddress(characterFromID("Green_patrol_4"), "Greenford_town", "goto27");
			ChangeCharacterAddress(characterFromID("Green_patrol_41"), "Greenford_town", "goto17");

			/*ChangeCharacterAddress(characterFromID("murderer_in_douwesen_01"), "none", "none");
			ChangeCharacterAddress(characterFromID("murderer_in_douwesen_02"), "none", "none");
			ChangeCharacterAddress(characterFromID("murderer_in_douwesen_03"), "none", "none");*/
			ChangeCharacterAddress(characterFromID("murderer_in_greenford_04"), "none", "none");
			ChangeCharacterAddress(characterFromID("murderer_in_greenford_05"), "none", "none");
			ChangeCharacterAddress(characterFromID("murderer_in_greenford_06"), "none", "none");
		break;
		
		case "we_resque_researcher":
			LAi_SetStayType(pchar);
			Locations[FindLocation("Greenford_town")].reload.l9.disable = 0;
			pchar.quest.main_line = "resque_researcher_complete";
			//убираем столб.
			
			Locations[FindLocation("Greenford_town")].models.always.koster = "";
			Locations[FindLocation("Greenford_town")].models.always.koster.locator.group = "";
			Locations[FindLocation("Greenford_town")].models.always.koster.locator.name = "";
			LAi_ActorAnimation(characterFromID("researcher"), "Ground_StandUp", "resque_researcher_in_greenford_complete", 1.0);
		break;
		
		case "soldier_help_us_resque_researher":
			LAi_fade("soldier_help_us_resque_researher_2", "resque_researcher_in_greenford_complete");
		break;
		
		case "soldier_help_us_resque_researher_2":
			pchar.quest.main_line = "resque_researcher_complete";
			LAi_type_actor_Reset(characterFromID("researcher"));
			ChangeCharacterAddressGroup(pchar, "Greenford_town", "reload", "reload1");
			//убираем столб.
			Locations[FindLocation("Greenford_town")].models.always.koster = "";
			Locations[FindLocation("Greenford_town")].models.always.koster.locator.group = "";
			Locations[FindLocation("Greenford_town")].models.always.koster.locator.name = "";
			PlaceCharacter(characterFromID("researcher"), "goto", "greenford_town");
			ChangeCharacterAddress(&characters[getCharacterIndex("researcher")], "Greenford_town", "goto9");
		break;

		case "resque_researcher_in_greenford_complete":
			LAi_group_SetRelation("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
			AddPartyExp(pchar, 3000);
			LAi_SetActorType(pchar);
			LAi_ActorFollow(pchar, characterFromID("researcher"), "", 2.0);
			LAi_ActorFollow(characterFromID("researcher"), pchar, "resque_researcher_in_greenford_complete_2", 3.0);
		break;
		
		case "resque_researcher_in_greenford_complete_2":
			LAi_type_actor_Reset(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("researcher"));
			LAi_ActorDialog(characterFromID("researcher"), pchar, "pchar_back_to_player", 2.0, 1.0)
		break;

		case "first_speak_with_danielle_in_lighthouse":
			LAi_ActorGoToLocator(characterFromID("researcher"), "reload", "reload2", "researcher_to_stay_type", -1);
			pchar.quest.main_line = "meet_danielle_in_lighthouse";
			LAi_type_actor_Reset(characterFromID("danielle"));
			LAi_ActorDialog(characterFromID("Danielle"), pchar, "first_speak_with_vincent_in_lighthouse", 2.0, 1.0);
		break;

		case "researcher_to_stay_type":
			LAi_SetStayType(characterFromID("researcher"));
		break;

		case "first_speak_with_vincent_in_lighthouse":
			LAi_type_actor_Reset(characterFromID("Vincent bethune"));
			LAi_ActorDialog(characterFromID("Vincent bethune"), pchar, "first_speak_with_danielle_in_lighthouse_2", 2.0, 1.0);
		break;

		case "first_speak_with_danielle_in_lighthouse_2":
			LAi_ActorDialog(characterFromID("danielle"), pchar, "first_speak_with_danielle_in_lighthouse_3", 2.0, 1.0);
		break;

		case "first_speak_with_danielle_in_lighthouse_3":
			LAi_SetCitizenType(characterFromID("vincent bethune"));
			LAi_SetCitizenType(characterFromID("danielle"));
		break;
			
		case "meet_danielle_in_lighthouse_complete":
			pchar.quest.kill_all_murderer_in_greenford.over = "yes";
			LAi_ActorDialog(characterFromID("researcher"), pchar, "", 5.0, 1.0);
			locations[FindLocation("Oxbay_Lighthouse")].reload.l1.disable = 1;
		break;

		case "blaze_with_researcher_to_lighthouse":
			DoQuestReloadToLocation("Oxbay_Lighthouse", "reload", "reload1", "blaze_with_researcher_to_lighthouse_1");
		break;

		case "blaze_with_researcher_to_lighthouse_1":
			Locations[FindLocation("Greenford_town")].reload.l1.disable = 0;
			Locations[FindLocation("Greenford_town")].reload.l2.disable = 0;
			Locations[FindLocation("Greenford_town")].reload.l3.disable = 0;
			Locations[FindLocation("Greenford_town")].reload.l4.disable = 0;
			Locations[FindLocation("Greenford_town")].reload.l7.disable = 0;
			Locations[FindLocation("Greenford_town")].reload.l9.disable = 0;
			LAi_SetActorType(characterFromID("Vincent Bethune"));
			LAi_SetActorType(characterFromID("Danielle"));
			ChangeCharacterAddress(characterFromID("Danielle"), "Oxbay_Lighthouse", "goto28");
			ChangeCharacterAddress(characterFromID("Vincent Bethune"), "Oxbay_Lighthouse", "goto9");
			ChangeCharacterAddress(characterFromID("researcher"), "Oxbay_Lighthouse", "goto7");
			pchar.quest.main_line = "meet_in_lighthouse";
			LAi_ActorFollow(CharacterFromID("Danielle"), pchar, "", -1);
			LAi_ActorFollow(CharacterFromID("Vincent Bethune"), pchar, "", -1);
			LAi_SetActorType(pchar);
			LAi_ActorFollow(pchar, characterFromID("researcher"), "", 2.0);
			LAi_ActorFollow(characterFromID("researcher"), pchar, "blaze_with_researcher_to_lighthouse_2", 2.0);
		break;
		
		case "blaze_with_researcher_to_lighthouse_2":
			LAi_type_actor_Reset(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("researcher"));
			LAi_ActorDialog(CharacterFromID("researcher"), pchar, "pchar_back_to_player", 1.0, 1.0);
		break;

		case "kill_edgard_in_prison_complete":
			pchar.quest.kill_edgard_in_prison_2.win_condition.l1 = "NPC_Death";
			pchar.quest.kill_edgard_in_prison_2.win_condition.l1.character = "Edgar Attwood";
			pchar.quest.kill_edgard_in_prison_2.win_condition = "kill_edgard_in_prison_2_complete";
			LAi_SetActorType(pchar);
			LAi_ActorAttack(pchar, characterFromID("Edgar Attwood"), "");
			Lai_QuestDelay("kill_edgard_in_prison_complete_2", 2.0);
		break;

		case "kill_edgard_in_prison_complete_2":
			LAi_KillCharacter(characterFromID("Edgar Attwood"));
		break;

		case "abording_pirate_06_complete":
			setCharacterShipLocation(characterFromID("Pirate Captain 05"), "none");
			SetCharacterIslandLocation(characterFromID("Pirate Captain 06"), "none", "quest_ships", "quest_ship_9", "stay", "runaway", "");
			pchar.quest.main_line = "blaze_to_incas_collection_begin_6";
			characters[GetCharacterIndex("Robert Christopher Silehard")].dialog.CurrentNode = "incas_collection_complete_node";
			ChangeCharacterAddress(characterFromID("danielle_sailor"), "none", "locator12");
			AddQuestRecord("blaze_to_incas_collection", "9");
		break;

		case "kill_pirate_06_complete":
			setCharacterShipLocation(characterFromID("Pirate Captain 05"), "none");
			SetCharacterIslandLocation(characterFromID("Pirate Captain 06"), "none", "quest_ships", "quest_ship_9", "stay", "runaway", "");
			pchar.quest.main_line = "kill_pirate_06";
			characters[GetCharacterIndex("danielle_sailor")].quest.kill_pirate_06 = "done";
			AddQuestRecord("blaze_to_incas_collection", "10");
			DoQuestCheckDelay("kill_pirate_06_complete_2", 1.0);
		break;
		
		case "kill_pirate_06_complete_2":
			pchar.location.from_sea = "Douwesen_shore_01";
			DoReloadFromSeaToLocation("Douwesen_shore_01", "reload", "reload1");
			pchar.quest.back_to_douwesen_shore.win_condition.l1 = "location";
			pchar.quest.back_to_douwesen_shore.win_condition.l1.location = "Douwesen_shore_01";
			pchar.quest.back_to_douwesen_shore.win_condition = "prepare_fighting_on_deck_complete";
			AddPartyExp(pchar, 3000);
		break;

		case "find_statuets_complete":
			LAi_Fade("find_statuets_2_complete", "");
		break;

		case "find_statuets_2_complete":
			LAi_ActorDialog(characterFromID("danielle_sailor"), pchar, "", 5.0, 1.0);
			pchar.quest.main_line = "blaze_to_incas_collection_begin_7";
			characters[GetCharacterIndex("Robert Christopher Silehard")].dialog.CurrentNode = "incas_collection_complete_node";
			AddQuestRecord("blaze_to_incas_collection", "11");
			pchar.quest.prepare_fighting_on_deck_complete.over = "yes";
			GiveItem2Character(pchar, INCAS_COLLECTION);
			Group_SetAddress("Pirate Captain 06", "none", "Quest_Ships","Quest_Ship_9");
			SetCharacterShipLocation(&characters[GetCharacterIndex("Pirate Captain 05")], "none");
		break;

		case "see_statuetes_complete":
			LAi_Fade("", "see_statuetes_2_complete");
		break;

		case "see_statuetes_2_complete":
			LAi_SetActorType(characterFromID("Robert Christopher Silehard"));
			LAi_ActorDialogNow(characterFromID("Robert Christopher Silehard"), pchar, "back_to_hovernor_type", -1);
			AddQuestRecord("blaze_to_incas_collection", "12");
			CloseQuestHeader("blaze_to_incas_collection");
		break;

		//возвращаемся на маяк для разговора даниэль и отплытия за реймсом
		case "return_to_lighthouse_search_rheims_complete":
			PlaceCharacter(characterFromID("Danielle"), "goto", "Oxbay_lighthouse");
			LAi_SetActorType(characterFromID("danielle"));
			LAi_ActorDialog(characterFromID("Danielle"), pchar, "", 50, 0);
		break;

		//прибываем в порт дувезена
		case "to_douwesen_port_search_blaze_complete":
			if (pchar.quest.main_line == "blaze_goto_douwesen_with_danielle")
			{
				LAi_type_actor_Reset(characterFromID("danielle"));
				pchar.quest.to_douwesen_shore_1_search_blaze.over = "yes";
				pchar.quest.to_douwesen_shore_2_search_blaze.over = "yes";
				PlaceCharacter(characterFromID("danielle"), "goto", "Douwesen_port");
				ChangeCharacterAddress(characterFromID("Vincent Bethune"), "Douwesen_tavern", "goto3");
				Lai_SetSitType(characterFromID("Raoul Rheims"));
				ChangeCharacterAddressGroup(characterFromID("Raoul Rheims"), "Douwesen_tavern", "sit", "sit5");
				LAi_SetActorType(pchar);
				LAi_ActorFollow(pchar, characterFromID("danielle"), "", 3.0);
				LAi_ActorFollow(characterFromID("danielle"), pchar, "danielle_speak_with_blaze_in_douwesen_port", 3.0);
			}
		break;

		//прибываем на первый пляж дувезена
		case "to_douwesen_shore_1_search_blaze_complete":
			if (pchar.quest.main_line == "blaze_goto_douwesen_with_danielle")
			{
				LAi_type_actor_Reset(characterFromID("danielle"));
				pchar.quest.to_douwesen_port_search_blaze.over = "yes";
				pchar.quest.to_douwesen_shore_2_search_blaze.over = "yes";
				PlaceCharacter(characterFromID("danielle"), "goto", "douwesen_shore_01");
				ChangeCharacterAddress(characterFromID("Vincent Bethune"), "Douwesen_tavern", "goto3");
				Lai_SetSitType(characterFromID("Raoul Rheims"));
				ChangeCharacterAddressGroup(characterFromID("Raoul Rheims"), "Douwesen_tavern", "sit", "sit4");
				LAi_SetActorType(pchar);
				LAi_ActorFollow(pchar, characterFromID("danielle"), "", 3.0);
				LAi_ActorFollow(characterFromID("danielle"), pchar, "danielle_speak_with_blaze_in_douwesen_port", 3.0);
			}
		break;

		//прибываем на второй пляж дувезена
		case "to_douwesen_shore_2_search_blaze_complete":
			if (pchar.quest.main_line == "blaze_goto_douwesen_with_danielle")
			{
				LAi_type_actor_Reset(characterFromID("danielle"));
				pchar.quest.to_douwesen_port_search_blaze.over = "yes";
				pchar.quest.to_douwesen_shore_1_search_blaze.over = "yes";
				PlaceCharacter(characterFromID("danielle"), "goto", "douwesen_shore_02");
				ChangeCharacterAddress(characterFromID("Vincent Bethune"), "Douwesen_tavern", "goto3");
				Lai_SetSitType(characterFromID("Raoul Rheims"));
				ChangeCharacterAddressGroup(characterFromID("Raoul Rheims"), "Douwesen_tavern", "sit", "sit4");
				LAi_SetActorType(pchar);
				LAi_ActorFollow(pchar, characterFromID("danielle"), "", 3.0);
				LAi_ActorFollow(characterFromID("danielle"), pchar, "danielle_speak_with_blaze_in_douwesen_port", 3.0);
			}
		break;
		
		case "danielle_speak_with_blaze_in_douwesen_port":
			pchar.quest.main_line = "blaze_goto_douwesen_with_danielle_2";
			LAi_type_actor_Reset(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("danielle"));
			LAi_ActorDialog(characterFromID("danielle"), pchar, "danielle_becomes_officer_in_douwesen", 1.0, 1.0);
		break;

		case "danielle_becomes_officer_in_douwesen":
			LAi_SetPlayerType(pchar);
			Locations[FindLocation("Douwesen_port")].reload.l2.disable = 1;
			Locations[FindLocation("Douwesen_port")].reload.l3.disable = 1;
			Locations[FindLocation("Douwesen_shore_01")].reload.l2.disable = 1;
			Locations[FindLocation("Douwesen_shore_02")].reload.l2.disable = 1;
			pchar.quest.main_line = "blaze_goto_douwesen_with_danielle_3";
			pchar.quest.goto_with_danielle_to_douwesen_tavern_for_rheims.win_condition.l1 = "location";
			pchar.quest.goto_with_danielle_to_douwesen_tavern_for_rheims.win_condition.l1.location = "Douwesen_tavern";
			pchar.quest.goto_with_danielle_to_douwesen_tavern_for_rheims.win_condition = "goto_with_danielle_to_douwesen_tavern_for_rheims_complete";

			LAi_SetOfficerType(characterFromID("danielle"));
			SetOfficersIndex(Pchar, 3, GetCharacterIndex("danielle"));
			SetCharacterRemovable(characterFromID("danielle"), false);
		break;

		//заходим в таверну за Винсетом, который покажет нам реймса
		case "goto_with_danielle_to_douwesen_tavern_for_rheims_complete":
			LAi_SetActorType(characterFromID("vincent bethune"));
			LAi_SetActorType(pchar);
			LAi_ActorFollow(pchar, characterFromID("Vincent Bethune"), "", 2.0);
			LAi_ActorFollow(characterFromID("Vincent Bethune"), pchar, "goto_with_danielle_to_douwesen_tavern_for_rheims_complete_2", 2.0);
		break;
		
		case "goto_with_danielle_to_douwesen_tavern_for_rheims_complete_2":
			LAi_type_actor_Reset(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("Vincent Bethune"));
			LAi_ActorDialog(characterFromID("Vincent Bethune"), pchar, "goto_with_danielle_to_douwesen_tavern_for_rheims_complete_3", 1.0, 1.0);
		break;

		//Винсент идет за своими головорезами
		case "vincent_away_from_tavern_complete":
			ChangeCharacterAddress(characterFromID("Vincent Bethune"), "none", "none");
		break;
		
		case "goto_with_danielle_to_douwesen_tavern_for_rheims_complete_3":
			LAi_ActorWaitDialog(pchar, characterFromID("danielle"));
			LAi_SetActorType(characterFromID("danielle"));
			LAi_ActorDialog(characterFromID("danielle"), pchar, "pchar_back_to_player", 1.0, 1.0);
		break;

		case "from_tavern_to_rheims_house_complete":
			LAi_LocationMonstersGen(&locations[FindLocation("Douwesen_town_exit")], false);
			pchar.quest.main_line = "from_tavern_to_rheims_house";
			LAi_SetActorType(characterFromID("Raoul Rheims"));
			RemovePassenger(pchar, characterFromID("Danielle"));
			RemoveCharacterCompanion(pchar, characterFromID("Danielle"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Danielle"));
			StorePassengers(pchar.id);
			LAi_SetActorType(characterFromID("Danielle"));
			DoQuestReloadToLocation("Douwesen_town_exit", "goto", "goto2", "from_town_to_jungle_to_rheims_house_complete");
			locations[FindLocation("Douwesen_town_exit")].reload.l1.disable = 1;
			locations[FindLocation("Douwesen_town_exit")].reload.l2.disable = 1;
		break;

		//выходим в город и на нас нападют головорезы
		case "from_town_to_jungle_to_rheims_house_complete":
			PlaceCharacter(characterFromID("danielle"), "goto", "douwesen_town_exit");
			PlaceCharacter(characterFromID("Raoul Rheims"), "goto", "Douwesen_town_exit");
			
			LAi_ActorDialog(characterFromID("danielle"), pchar, "", 5.0, 0);
		break;

		case "prepare_danielle_with_rheims_runaway_complete":
			LAi_SetHP(characterFromID("murderer_in_douwesen_01"), 60.0, 60.0);
			LAi_SetHP(characterFromID("murderer_in_douwesen_02"), 60.0, 60.0);
			LAi_SetHP(characterFromID("murderer_in_douwesen_03"), 60.0, 60.0);
			ChangeCharacterAddress(characterFromID("murderer_in_douwesen_01"), "douwesen_town_exit", "goto4");
			ChangeCharacterAddress(characterFromID("murderer_in_douwesen_02"), "douwesen_town_exit", "goto4");
			ChangeCharacterAddress(characterFromID("murderer_in_douwesen_03"), "douwesen_town_exit", "goto4");
			LAi_group_MoveCharacter(characterFromID("murderer_in_douwesen_01"), "DOUWESEN_MURDERERS");
			LAi_group_MoveCharacter(characterFromID("murderer_in_douwesen_02"), "DOUWESEN_MURDERERS");
			LAi_group_MoveCharacter(characterFromID("murderer_in_douwesen_03"), "DOUWESEN_MURDERERS");
			LAi_group_FightGroups("DOUWESEN_MURDERERS", LAI_GROUP_PLAYER, true);
			LAi_ActorRunToLocator(characterFromID("danielle"), "reload", "reload1_back", "", 40.0);
			LAi_ActorRunToLocator(characterFromID("raoul Rheims"), "reload", "reload1_back", "danielle_with_rheims_runaway_complete", 40.0);
			LAi_group_SetCheck("DOUWESEN_MURDERERS", "kill_murderers_in_douwesen_town_exit_complete");

			pchar.quest.prepare_dagger.win_condition.l1 = "location";
			pchar.quest.prepare_dagger.win_condition.l1.location = "Rheims_house_inside";
			pchar.quest.prepare_dagger.win_condition = "prepare_dagger";
		break;

		//Даниэль с Реймсом убегают
		case "danielle_with_rheims_runaway_complete":
			ChangeCharacterAddressGroup(characterFromID("Danielle"), "Rheims_house_inside", "item", "item1");
			ChangeCharacterAddress(characterFromID("Raoul Rheims"), "Rheims_house_inside", "goto1");
			ChangeCharacterAddress(characterFromID("Vincent Bethune"), "Rheims_house_inside", "goto2");
		break;

		case "prepare_dagger":
			locx = stf(loadedLocation.locators.camera.locator4.x);
			locy = stf(loadedLocation.locators.camera.locator4.y);
			locz = stf(loadedLocation.locators.camera.locator4.z);
			locCameraToPos(locx, locy, locz, false);

			LAi_type_actor_Reset(characterFromID("danielle"));
			LAi_type_actor_Reset(characterFromID("Raoul Rheims"));
			LAi_type_actor_Reset(characterFromID("Vincent Bethune"));
			LAi_ActorAnimation(characterFromID("Raoul Rheims"), "Lay_1", "", -1);
			LAi_ActorAnimation(characterFromID("Vincent Bethune"), "Lay_2", "", -1);
			
			LAi_SetActorType(pchar);
			LAi_ActorDialog(pchar, characterFromID("danielle"), "", 2.0, 1.0);
			LAi_ActorWaitDialog(characterFromID("danielle"), pchar);
			LAi_CharacterDisableDialog(characterFromID("Raoul Rheims"));
			LAi_CharacterDisableDialog(characterFromID("Vincent Bethune"));
			AddQuestrecord("again_find_rheims", "5");
			pchar.quest.main_line = "to_rheims_house";
		break;

		case "kill_murderers_in_douwesen_town_exit_complete":
			locations[FindLocation("Douwesen_town_exit")].reload.l1.disable = 0;
			locations[FindLocation("Douwesen_town_exit")].reload.l2.disable = 0;
			characters[GetCharacterIndex("murderer_in_douwesen_01")].location = "none";
			characters[GetCharacterIndex("murderer_in_douwesen_02")].location = "none";
			characters[GetCharacterIndex("murderer_in_douwesen_03")].location = "none";
		break;

		case "dagger":
			locx = stf(loadedLocation.locators.camera.locator4.x);
			locy = stf(loadedLocation.locators.camera.locator4.y);
			locz = stf(loadedLocation.locators.camera.locator4.z);
			locCameraToPos(locx, locy, locz, false);
			LAi_LocationMonstersGen(&locations[FindLocation("Douwesen_town_exit")], true);
			LAi_SetActorType(characterFromID("blaze"));
			LAi_SetImmortal(pchar, true);
			LAi_ActorAttack(characterFromID("danielle"), characterFromID("blaze"), "");
			LAi_QuestDelay("dagger_2", 2.0);
		break;

		case "dagger_2":
			LAi_ActorAnimation(characterFromID("blaze"), "death_1", "dagger_3", 2.0);
		break;

		case "dagger_3":
			LAi_ActorAnimation(characterFromID("blaze"), "Lay_1", "", -1);
			LAi_SetPlayerType(characterFromID("danielle"));
			SetMainCharacterIndex(GetCharacterIndex("danielle"));
			PChar = GetMainCharacter();
			ChangeCharacterAddress(characterFromID("Blaze"), "Rheims_house_inside", "goto5");

			DoQuestReloadToLocation("Rheims_house_inside", "item", "item1", "start_quest_movie_speak_with_rheims_complete");
			pchar.quest.main_line = "danielle_speak_with_almost_dead_rheims";
			
			locations[FindLocation("Douwesen_town_exit")].reload.l1.disable = 0;
			locations[FindLocation("Douwesen_town_exit")].reload.l2.disable = 0;
		break;

		//Блэйз слышит диалог Даниель с Реймсом
		case "start_quest_movie_speak_with_rheims_complete":
			locx = stf(loadedLocation.locators.camera.locator4.x);
			locy = stf(loadedLocation.locators.camera.locator4.y);
			locz = stf(loadedLocation.locators.camera.locator4.z);
			locCameraToPos(locx, locy, locz, false);

			LAi_CharacterEnableDialog(characterFromID("Raoul Rheims"));
			characters[GetCharacterIndex("Raoul Rheims")].dialog.currentnode = "danielle_speak_with_almost_dead_rheims_node";
			LAi_ActorSetLayMode(characterFromID("Raoul Rheims"));
			LAi_ActorWaitDialog(characterFromID("Raoul Rheims"), pchar);
			LAi_SetActorType(pchar);
			LAi_ActorDialogNow(pchar, characterFromID("Raoul Rheims"), "", -1);
		break;

		case "start_quest_movie_speak_with_rheims_complete_2":
			LAi_ActorGoToLocator(pchar, "reload", "reload1", "exit_after_speak_with_rheims", 5.0);
		break;

		case "kill_ferro_cerezo_complete":
			pchar.quest.main_line = "compramat_bul_bul";
			AddQuestrecord("search_danielle", "8");
		break;

		case "abording_ferro_cerezo_complete":
			GiveItem2Character(pchar, COMPRAMAT_TO_DOMIGUES);
			pchar.quest.main_line = "compramat_done";
			AddQuestRecord("search_danielle", "7");
			pchar.quest.kill_ferro_cerezo_complete.over = "yes";
		break;

		//блэйза бьют по башке
		case "to_oxbay_mine_complete":
			if (pchar.location.locator == "reload1")
			{
				LAi_SetHP(characterFromID("Stephan Bonser"), 60.0, 60.0);
				LAi_SetHP(characterFromID("Oswald Chappel"), 60.0, 60.0);
				LAi_SetHP(characterFromID("Gyles Dubois"), 60.0, 60.0);
				ChangeCharacterAddress(characterFromID("Stephan Bonser"), "Oxbay_canyon", "goto29");
				ChangeCharacterAddress(characterFromID("Oswald Chappel"), "Oxbay_canyon", "goto30");
				ChangeCharacterAddress(characterFromID("Gyles Dubois"), "Oxbay_canyon", "goto18");
				LAi_SetActorType(characterFromID("Stephan Bonser"));
				LAi_SetActorType(characterFromID("Oswald Chappel"));
				LAi_SetActorType(characterFromID("Gyles Dubois"));
				LAi_ActorFollow(characterFromID("Oswald Chappel"), pchar, "", -1);
				LAi_ActorFollow(characterFromID("Gyles Dubois"), pchar, "", -1);
				LAi_SetActorType(pchar);
				LAi_ActorFollow(pchar, characterFromID("Stephan Bonser"), "", 2.0);
				LAi_ActorFollow(characterFromID("Stephan Bonser"), pchar, "to_oxbay_mine_complete_2", 2.0);
		
				Locations[FindLocation("Oxbay_canyon")].reload.l1.disable = 1;
				Locations[FindLocation("Oxbay_canyon")].reload.l2.disable = 1;
			}
			else
			{
				pchar.quest.main_line = "kick_on_mine_not_exist";
			}
			Locations[FindLocation("Oxbay_canyon")].reload.l3.disable = false;
		break;
		
		case "to_oxbay_mine_complete_2":
			LAi_ActorWaitDialog(pchar, characterFromID("Stephan Bonser"));
			LAi_ActorDialog(characterFromID("Stephan Bonser"), pchar, "", 1.0, 0);
		break;

		case "kicked_to_mine_complete":
			LAi_SetActorType(pchar);
			pchar.quest.kill_ferro_cerezo.over = "yes";
			pchar.quest.abording_ferro_cerezo.over = "yes";
			if (GetCharacterSkill(pchar, SKILL_FENCING) > 7)
			{
				LAi_QuestDelay("after_kicked_2_complete", 0.5);
			}
			else
			{
				LAi_ActorTurnToCharacter(characterFromID("Stephan Bonser"), pchar);
				LAi_ActorAnimation(characterFromID("Stephan Bonser"), "attack_2", "kicked_to_mine_3_complete", 0.4);
			}
		break;

		case "kicked_to_mine_3_complete":
			LAi_SetActorType(pchar);
			LAi_ActorAnimation(pchar, "death_1", "after_kicked_complete", 3.5);
			LAi_SetImmortal(pchar, true);
			LAi_group_MoveCharacter(characterFromID("Stephan Bonser"), "MURDERERS_IN_CANYON");
			LAi_group_MoveCharacter(characterFromID("Oswald Chappel"), "MURDERERS_IN_CANYON");
			LAi_group_MoveCharacter(characterFromID("Gyles Dubois"), "MURDERERS_IN_CANYON");
			LAi_group_SetRelation("MURDERERS_IN_CANYON", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("MURDERERS_IN_CANYON", LAI_GROUP_PLAYER, true);
		break;

		case "after_kicked_complete":
			LAi_SetImmortal(pchar, false);
			LAi_SetPlayerType(pchar);
			StorePassengers("Blaze");
			pchar.tempmoney = pchar.money;
			RemoveCharacterEquip(pchar, GUN_ITEM_TYPE);
			RemoveCharacterEquip(pchar, BLADE_ITEM_TYPE);
			EnableEquip(pchar, GUN_ITEM_TYPE, false);
			EnableEquip(pchar, BLADE_ITEM_TYPE, false);

			pchar.quest.main_line = "slave_in_oxbay_mine_begin";
			DoQuestReloadToLocation("Oxbay_mine", "goto", "goto1", "to_mines_complete");
			Locations[FindLocation("Oxbay_canyon")].reload.l1.disable = 1;
			Locations[FindLocation("Oxbay_canyon")].reload.l2.disable = 0;
			Locations[FindLocation("Oxbay_mine")].reload.l1.disable = 1;
			Locations[FindLocation("Oxbay_mine")].reload.l2.disable = 1;
			AddQuestRecord("search_danielle", "11");
		break;

		case "after_kicked_2_complete":
			LAi_SetPlayerType(pchar);
			LAi_group_MoveCharacter(characterFromID("Stephan Bonser"), "MURDERERS_IN_CANYON");
			LAi_group_MoveCharacter(characterFromID("Oswald Chappel"), "MURDERERS_IN_CANYON");
			LAi_group_MoveCharacter(characterFromID("Gyles Dubois"), "MURDERERS_IN_CANYON");
			LAi_group_SetRelation("MURDERERS_IN_CANYON", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("MURDERERS_IN_CANYON", LAI_GROUP_PLAYER, true);
			pchar.quest.main_line = "kick_on_mine_not_exist";
			AddQuestRecord("search_danielle", "10");
			Locations[FindLocation("Oxbay_canyon")].reload.l1.disable = 0;
			Locations[FindLocation("Oxbay_canyon")].reload.l2.disable = 0;
		break;

		case "to_mines_complete":
			ChangeCharacterAddress(characterFromID("Stephan Bonser"), "none", "none");
			ChangeCharacterAddress(characterFromID("Oswald Chappel"), "none", "none");
			ChangeCharacterAddress(characterFromID("Gyles Dubois"), "none", "none");
			LAi_SetActorType(characterFromID("Leborio Drago"));
			LAi_ActorDialog(characterFromID("Leborio Drago"), pchar, "", 2.0, 1.0);
		break;

		case "second_speak_with_leborio_in_mines":
			pchar.quest.main_line = "resque_from_mines_denied";
			LAi_SetActorType(characterFromID("leborio drago"));
			LAi_ActorDialog(characterFromID("leborio drago"), pchar, "", 2.0, 1.0);
			LAi_ActorGoToLocator(characterFromID("mine_soldier_01"), "goto", "goto9", "mine_soldier_back_to_soldier", 5.0);
		break;
		
		case "mine_soldier_back_to_soldier":
			LAi_SetGuardianType(characterFromID("mine_soldier_01"));
			LAi_group_MoveCharacter(characterFromID("mine_soldier_01"), "ENGLAND_SOLDIERS");
		break;

		//включаем ролик, расставляем всех персонажей.
		case "movie_with_fight_complete":
			SetCurrentTime(23, 0);
			characters[GetCharacterIndex("danielle")].skill.fencing = "7";
			characters[GetCharacterIndex("danielle")].skill.sailing = "5";
			characters[GetCharacterIndex("danielle")].skill.cannons = "6";
			characters[GetCharacterIndex("danielle")].skill.accuracy = "4";
			characters[GetCharacterIndex("danielle")].rank = "9";
			characters[GetCharacterIndex("danielle")].experience = CalculateExperienceFromRank(9)+ (CalculateExperienceFromRank(9)/10 + rand(9000));
			characters[GetCharacterIndex("danielle")].ship.type = SHIP_PINNACE2_SPAIN;
			characters[GetCharacterIndex("danielle")].ship.hp = 4200;
			characters[GetCharacterIndex("danielle")].Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS24;
			characters[GetCharacterIndex("danielle")].perks.list.LongRangeShoot = true;
			characters[GetCharacterIndex("danielle")].perks.list.FastReload = true;
			characters[GetCharacterIndex("danielle")].perks.list.CriticalHit = true;
			characters[GetCharacterIndex("danielle")].perks.list.Gunman = true;
			characters[GetCharacterIndex("danielle")].perks.list.CriticalHit = true;
			characters[GetCharacterIndex("danielle")].perks.list.BasicBattleState = true;
			characters[GetCharacterIndex("danielle")].perks.list.AdvancedBattleState = true;
			characters[GetCharacterIndex("danielle")].perks.list.ShipDefenseProfessional = true;
			GiveItem2Character(characterFromID("danielle"), "blade9");
			EquipCharacterByItem(characterFromID("danielle"), "blade9");
			
			LAi_SetActorType(characterFromID("Danielle"));
			LAi_ActorAnimation(characterFromID("Danielle"), "lay_1", "", -1);
			LAi_CharacterDisableDialog(characterFromID("Danielle"));
			ChangeCharacterAddress(characterFromID("Danielle"), "Quest_Muelle_town_01", "goto21");
			LAi_SetHP(characterFromID("pirate for quest muelle 01"), 80.0, 80.0);
			LAi_SetHP(characterFromID("pirate for quest muelle 03"), 80.0, 80.0);
			LAi_SetHP(characterFromID("pirate for quest muelle 02"), 80.0, 80.0);
			ChangeCharacterAddress(characterFromID("pirate for quest muelle 01"), "Quest_Muelle_town_01", "goto100");
			ChangeCharacterAddress(characterFromID("pirate for quest muelle 02"), "Quest_Muelle_town_01", "goto101");
			ChangeCharacterAddress(characterFromID("pirate for quest muelle 03"), "Quest_Muelle_town_01", "goto102");
			DoReloadCharacterToLocation("Quest_Muelle_town_01", "goto", "goto23");
			pchar.quest.to_quest_muelle.win_condition.l1 = "location";
			pchar.quest.to_quest_muelle.win_condition.l1.location = "Quest_Muelle_town_01";
			pchar.quest.to_quest_muelle.win_condition = "to_quest_muelle_complete";
			AddQuestRecord("search_danielle", "22");
			Locations[FindLocation("Oxbay_canyon")].reload.l3.disable = true;
		break;

		case "to_quest_muelle_complete":
			LAi_group_MoveCharacter(characterFromID("pirate for quest muelle 01"), "QUEST_MUELLE_PIRATES");
			LAi_group_MoveCharacter(characterFromID("pirate for quest muelle 02"), "QUEST_MUELLE_PIRATES");
			LAi_group_MoveCharacter(characterFromID("pirate for quest muelle 03"), "QUEST_MUELLE_PIRATES");
			LAi_group_SetRelation("QUEST_MUELLE_PIRATES", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("QUEST_MUELLE_PIRATES", LAI_GROUP_PLAYER, true);

			pchar.quest.kill_all_pirate_in_quest_muelle.win_condition.l1 = "NPC_death";
			pchar.quest.kill_all_pirate_in_quest_muelle.win_condition.l1.character = "pirate for quest muelle 01";
			pchar.quest.kill_all_pirate_in_quest_muelle.win_condition.l2 = "NPC_death";
			pchar.quest.kill_all_pirate_in_quest_muelle.win_condition.l2.character = "pirate for quest muelle 02";
			pchar.quest.kill_all_pirate_in_quest_muelle.win_condition.l3 = "NPC_death";
			pchar.quest.kill_all_pirate_in_quest_muelle.win_condition.l3.character = "pirate for quest muelle 03";
			pchar.quest.kill_all_pirate_in_quest_muelle.win_condition = "kill_all_pirate_in_quest_muelle_complete";
		break;

		case "kill_all_pirate_in_quest_muelle_complete":
			LAi_CharacterEnableDialog(characterFromID("Danielle"));
			ChangeCharacterAddress(characterFromID("pirate for quest muelle 01"), "none", "goto100");
			ChangeCharacterAddress(characterFromID("pirate for quest muelle 02"), "none", "goto101");
			ChangeCharacterAddress(characterFromID("pirate for quest muelle 03"), "none", "goto102");
			LAi_Fade("prepare_back_to_muelle_complete", "back_to_muelle_complete");
		break;

		case "prepare_back_to_muelle_complete":
			LAi_type_actor_Reset(characterFromID("danielle"));
			LAi_SetActorType(pchar);
		break;

		case "back_to_muelle_complete":
			pchar.quest.main_line = "resque_danielle";
			LAi_ActorFollow(pchar, characterFromID("danielle"), "", 4.0);
			LAi_ActorFollow(characterFromID("danielle"), pchar, "back_to_muelle_complete_2", 4.0);
		break;
		
		case "back_to_muelle_complete_2":
			AddPartyExp(pchar, 10000);
			LAi_type_actor_Reset(pchar);
			LAi_ActorWaitDialog(pchar, characterFromId("danielle"));
			LAi_ActorDialog(characterFromID("Danielle"), pchar, "pchar_back_to_player", 2.0, 1.0);
			pchar.quest.blaze_to_map.win_condition.l1 = "location";
			pchar.quest.blaze_to_map.win_condition.l1.location = "Redmond";
			pchar.quest.blaze_to_map.win_condition = "blaze_to_map_complete";
		break;
		
		case "danielle_death":
			Log_SetStringToLog(GlobalStringConvert("QUEST_MESSAGE1"));
			Lai_KillCharacter(pchar);
		break;

		case "blaze_to_map_complete":
			//задизейблить выход из карты
			pchar.location.from_sea = "Redmond_shore_01";
			DoReloadFromSeaToLocation("Redmond_shore_01", "reload", "reload1");
			pchar.quest.to_secret_oxbay_shore_complete.win_condition.l1 = "location";
			pchar.quest.to_secret_oxbay_shore_complete.win_condition.l1.location = "Redmond_shore_01";
			pchar.quest.to_secret_oxbay_shore_complete.win_condition = "to_secret_oxbay_shore_complete";
			//разрешить выход из карты
		break;

		case "to_secret_oxbay_shore_complete":
			LAi_SetActorType(characterFromID("danielle"));
			LAi_type_actor_Reset(characterFromID("danielle"));
			LAi_LocationFightDisable(&locations[FindLocation("Quest_Residence")], true);
			
			PlaceCharacter(characterFromID("danielle"), "goto", "redmond_shore_01");
			LAi_ActorDialog(characterFromID("Danielle"), pchar, "", 5.0, 0);
		break;
		
		case "to_secret_oxbay_shore_complete2":
			LAi_type_actor_Reset(characterFromID("danielle"));
			LAi_ActorDialog(characterFromID("Danielle"), pchar, "", 5.0, 0);
		break;

		case "both_to_residence_complete":
			pchar.quest.main_line = "both_to_redmond_residence";
			StorePassengers(pchar.id);
			LAi_SetOfficerType(characterFromID("Danielle"));
			ChangeCharacterAddress(characterFromID("Robert Christopher Silehard"), "Quest_residence", "goto6");

			Locations[FindLocation("Quest_Residence")].reload.l1.disable = 1;
			DoQuestReloadToLocation("Quest_residence", "reload", "reload1", "both_to_residence_complete_2");
			characters[GetCharacterIndex("Robert Christopher Silehard")].Dialog.CurrentNode = "both_talk_with_Silehard_node";
			pchar.quest.main_line = "both_talk_with_Silehard";
			LAi_ActorDialog(CharacterFromID("Robert Christopher Silehard"), pchar, "", 5.0, 0);
			ChangeCharacterAddress(CharacterFromID("Danielle"), "Quest_residence", "goto4");
			Locations[FindLocation("Greenford_town")].reload.l9.close_for_night = 0;
		break;
		
		case "both_to_residence_complete_2":
			LAi_SetActorType(characterFromID("robert christopher silehard"));
			LAi_ActorDialog(characterFromID("robert christopher silehard"), pchar, "", 5.0, 1.0);
		break;

		case "both_escape_from_redmond_complete":
			PlaceCharacter(characterFromID("danielle"), "goto", "redmond_shore_01");
			pchar.quest.main_line = "both_escape_from_redmond";
			LAi_SetActorType(characterFromID("danielle"));
			LAi_ActorDialog(characterFromID("Danielle"), pchar, "", 5.0, 0);
			LAi_group_SetRelation("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
			AddQuestRecord("Revenge_for_Silehard", "4");
			AddPartyExp(pchar, 5000);
			Locations[FindLocation("Redmond_Town_01")].reload.l13.disable = true;
		break;

		case "to_idol_complete":
			ChangeCharacterAddress(characterFromID("Danielle"), "none", "none");
		break;

		case "return_idol_from_frigate_complete":
			pchar.quest.return_idol_from_frigate1.over = "yes";
			pchar.quest.return_idol_from_frigate.over = "yes";
			Island_SetReloadEnableGlobal("Oxbay", true);
			AddQuestRecord("Revenge_for_Silehard", "8");
			ChangeCharacterAddress(characterFromID("researcher"), "oxbay_lighthouse", "goto24");
			GiveItem2Character(pchar, INCAS_IDOL);
			AddPartyExp(pchar, 10000);

			pchar.quest.main_line = "blaze_search_danielle_again";

			pchar.quest.to_lighthouse_to_meet_danielle_before_storm.win_condition.l1 = "location";
			pchar.quest.to_lighthouse_to_meet_danielle_before_storm.win_condition.l1.location = "Oxbay_lighthouse";
			pchar.quest.to_lighthouse_to_meet_danielle_before_storm.win_condition = "to_lighthouse_to_meet_danielle_before_storm";

			pchar.quest.before_storm.win_condition.l1 = "MapEnter";
			pchar.quest.before_storm.win_condition = "before_storm";
			
			pchar.nation = PIRATE;
		break;

		case "prepare_for_storm":
			CloseQuestHeader("Where_are_i");
			bQuestDisableMapEnter = false;
		break;

		case "before_storm":	
			characters[getCharacterIndex("Greenford Commander")].skill.accuracy = "9";
			characters[getCharacterIndex("Greenford Commander")].skill.cannons = "5";
			/*worldMap.islands.Douwesen.locations.city.position.x = -195.439728;
			worldMap.islands.Douwesen.locations.city.position.y = 6.049987;
			worldMap.islands.Douwesen.locations.city.position.z = -106.659912;*/
			LAi_group_SetRelation("DOUWESEN_PIRATE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_NEITRAL);
			if(GetOfficersIndex(Pchar, 1) == -1)
			{
				Pchar.Temp.Officer.idx1 = GetCharacterIndex("Blaze_Crewmember_01");
			}
			else
			{
				Pchar.Temp.Officer.idx1 = getOfficersIndex(Pchar, 1);
				Pchar.Temp.Officer.idx1.Dialog = Characters[getOfficersIndex(Pchar, 1)].Dialog.Filename;
				Pchar.Temp.Officer.idx1.CurrentNode = Characters[getOfficersIndex(Pchar, 1)].Dialog.CurrentNode;
			}
			if(GetOfficersIndex(Pchar, 2) == -1)
			{
				Pchar.Temp.Officer.idx2 = GetCharacterIndex("Blaze_Crewmember_02");
			}
			else
			{
				Pchar.Temp.Officer.idx2 = getOfficersIndex(Pchar, 2);
				Pchar.Temp.Officer.idx2.Dialog = Characters[getOfficersIndex(Pchar, 2)].Dialog.Filename;
				Pchar.Temp.Officer.idx2.CurrentNode = Characters[getOfficersIndex(Pchar, 2)].Dialog.CurrentNode;
			}
			if(GetOfficersIndex(Pchar, 3) == -1)
			{
				Pchar.Temp.Officer.idx3 = GetCharacterIndex("Blaze_Crewmember_03");
			}
			else
			{
				Pchar.Temp.Officer.idx3 = getOfficersIndex(Pchar, 3);
				Pchar.Temp.Officer.idx3.Dialog = Characters[getOfficersIndex(Pchar, 3)].Dialog.Filename;
				Pchar.Temp.Officer.idx3.CurrentNode = Characters[getOfficersIndex(Pchar, 3)].Dialog.CurrentNode;
			}
			if (GetCompanionIndex(pchar,1) > 0)
			{
				Pchar.Temp.Companion.idx1 = GetCompanionIndex(pchar,1);
				iPassenger = GetCompanionIndex(pchar,1);
				RemoveCharacterCompanion(Pchar, &Characters[iPassenger]);
			}
			else
			{
				Pchar.Temp.Companion.idx1 = -1;
			}
			if (GetCompanionIndex(pchar,2) > 0)
			{
				Pchar.Temp.Companion.idx2 = GetCompanionIndex(pchar,2);
				iPassenger = GetCompanionIndex(pchar,2);
				RemoveCharacterCompanion(Pchar, &Characters[iPassenger]);
			}
			else
			{
				Pchar.Temp.Companion.idx2 = -1;
			}
			if (GetCompanionIndex(pchar,3) > 0)
			{
				Pchar.Temp.Companion.idx3 = GetCompanionIndex(pchar,3);
				iPassenger = GetCompanionIndex(pchar,3);
				RemoveCharacterCompanion(Pchar, &Characters[iPassenger]);
			}
			else
			{
				Pchar.Temp.Companion.idx3 = -1;
			}
			bMainMenuLaunchAfterVideo = true;
			PostVideoAndQuest("storm",1, "storm_complete");
		break;
		
		case "storm_complete":
			PostEvent("DoInfoShower",100,"s","");
			StorePassengers("Blaze");
			ExchangeCharacterShip(Pchar, characterFromID("Ship Storage"));
			pchar.ship.name = characters[getCharacterIndex("Ship Storage")].ship.name;
			SetCharacterShipLocation(characterFromID("Ship Storage"), "Muelle_port");
			DeleteAttribute(pchar, "ship");
			pchar.ship.type = SHIP_NOTUSED;
			pchar.tempmoney = pchar.money;
			pchar.money = 0;
			locations[FindLocation("Douwesen_town")].reload.l3.disable = true;
			CloseQuestHeader("Revenge_for_Silehard");
			SetQuestHeader("Where_are_i");
			AddQuestrecord("Where_are_i", "1");
			pchar.quest.main_line = "speak_with_peasant";
			Pchar.quest.Story_DanielleWaitsInMuelleTown.win_condition.l1 = "location";
			Pchar.quest.Story_DanielleWaitsInMuelleTown.win_condition.l1.location = "Muelle_tavern";
			Pchar.quest.Story_DanielleWaitsInMuelleTown.win_condition = "Story_DanielleWaitsInMuelleTown";
	
			Pchar.quest.Story_AppearOnIslaMuelleonAnacletoShip.win_condition.l1 = "location";
			Pchar.quest.Story_AppearOnIslaMuelleonAnacletoShip.win_condition.l1.location = "Muelle_port";
			Pchar.quest.Story_AppearOnIslaMuelleonAnacletoShip.win_condition = "Story_AppearOnIslaMuelleonAnacletoShip";
			
			iPassenger = makeint(Pchar.Temp.Officer.idx1);
			ChangeCharacterAddress(&Characters[iPassenger], "Muelle_port", "Goto4"); 
			iPassenger = makeint(Pchar.Temp.Officer.idx2);
			ChangeCharacterAddress(&Characters[iPassenger], "Muelle_port", "Goto1"); 
			iPassenger = makeint(Pchar.Temp.Officer.idx3);
			ChangeCharacterAddress(&Characters[iPassenger], "Muelle_port", "Goto2");
			LAi_group_SetRelation("DOUWESEN_PIRATE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
			LAi_group_SetRelation("DOUWESEN_PIRATE_CITIZENS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
			DoQuestReloadToLocation("Douwesen_shore_01", "reload", "reload1", "to_douwesen_shore_complete");
		break;

		case "to_lighthouse_to_meet_danielle_before_storm":
			PlaceCharacter(characterFromID("researcher"), "goto", "Oxbay_lighthouse");
			LAi_SetActorType(characterFromID("researcher"));
			LAi_ActorDialog(characterFromID("researcher"), pchar, "", 20.0, 1.0);
			CloseQuestheader("Revenge_for_Silehard");
		break;
			
		case "fight_in_residence_complete":
			Locations[FindLocation("Quest_Residence")].reload.l1.disable = 1;
			LAi_SetActorType(characterFromID("Robert Christopher Silehard"));
			LAi_ActorRunToLocator(characterFromID("Robert Christopher Silehard"), "reload", "reload1", "silehard_escape_complete", 5.0);
		break;

		case "silehard_escape_complete":
			AddQuestRecord("Revenge_for_Silehard", "3");
			LAi_LocationFightDisable(&locations[FindLocation("Quest_Residence")], false);
			ChangeCharacterAddress(characterFromID("Robert Christopher Silehard"), "Redmond_residence", "goto8");
			//Locations[FindLocation("Redmond_town_01")].reload.l6.disable = 1;
			LAi_QuestDelay("soldier_in_residence", 1.5);
			ChangeCharacterAddress(characterFromID("researcher"), "oxbay_lighthouse", "goto24");
		break;

		case "soldier_in_residence":
			LAi_group_MoveCharacter(characterFromID("Eng Soldier for residence 01"), "ENGLAND_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("Eng Soldier for residence 02"), "ENGLAND_SOLDIERS");
			ChangeCharacterAddressGroup(characterFromID("Eng Soldier for residence 01"), "Quest_residence", "reload", "reload1");
			ChangeCharacterAddressGroup(characterFromID("Eng Soldier for residence 02"), "Quest_residence", "reload", "reload1");
			LAi_group_SetRelation("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("ENGLAND_SOLDIERS", "to_redmond_shore_01");
		break;

		case "to_redmond_shore_01":
			Locations[FindLocation("Quest_Residence")].reload.l1.go = "redmond_shore_01";
			Locations[FindLocation("Quest_Residence")].reload.l1.emerge = "reload2";
			Locations[FindLocation("Quest_Residence")].reload.l1.disable = 0;
			//DoQuestReloadToLocation("redmond_shore_01", "reload", "reload2", "both_escape_from_redmond_complete");
			pchar.quest.both_escape_from_redmond_complete.win_condition.l1 = "location";
			pchar.quest.both_escape_from_redmond_complete.win_condition.l1.location = "redmond_shore_01";
			pchar.quest.both_escape_from_redmond_complete.win_condition = "both_escape_from_redmond_complete";
		break;

		case "to_douwesen_shore_complete":
			PlaceCharacter(characterFromID("peasant"), "goto", "Douwesen_shore_01");
			LAi_SetActorType(pchar);
			LAi_ActorFollow(pchar, characterFromID("peasant"), "", 2.0);
			LAi_ActorFollow(characterFromID("peasant"), pchar, "to_douwesen_shore_complete_2", 2.0);
		break;
		
		case "to_douwesen_shore_complete_2":
			LAi_ActorWaitDialog(pchar, characterFromID("peasant"));
			LAi_ActorDialog(characterFromID("peasant"), pchar, "pchar_back_to_player", 2.0, 1.0);
			ChangeCharacterAddressGroup(characterFromID("Anacleto Rui Sa Pinto"), "Pirate_tavern", "sit", "sit4");
			bQuestDisableMapEnter = true;
		break;

		case "kill_Serrao_complete":
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], true);
			pchar.quest.main_line = "after_defeat_Serrao";
			LAi_type_actor_Reset(characterFromID("Gervasio Serrao"));
			LAi_SetActorType(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("Gervasio Serrao"));
			LAi_ActorDialogNow(characterFromID("Gervasio Serrao"), pchar, "pchar_back_to_Player", -1);
			LAi_SetImmortal(characterFromID("Gervasio Serrao"), false);
		break;

		case "serrao_wait_for_hire":
			if (characters[GetCharacterIndex("Gervasio Serrao")].location.locator != "sit5")
			{
				LAi_Fade("serrao_wait_for_hire_2", "");
			}
		break;

		case "serrao_wait_for_hire_2":
			ChangeCharacterAddressGroup(characterFromID("Gervasio Serrao"), "pirate_tavern", "sit", "sit5");
			Lai_SetSitType(characterFromID("Gervasio Serrao"));
		break;

		case "kill_anacleto_complete":
			worldMap.playerShipX = -220.27;
			worldMap.playerShipZ = 2.34;
			worldMap.playerShipAY = 3.0;
			worldMap.playerShipActionRadius = 20.0;
			worldMap.playerShipDispX = stf(worldMap.playerShipX) - stf(worldMap.islands.Douwesen.position.rx);
			worldMap.playerShipDispZ = stf(worldMap.playerShipZ) - stf(worldMap.islands.Douwesen.position.rz);
			
			bQuestDisableMapEnter = false;
			LAi_LocationFightDisable(&locations[Findlocation("pirate_tavern")], true);
			pchar.ship.type = characters[GetCharacterIndex("Anacleto Rui Sa Pinto")].ship.type;
			pchar.ship.name = characters[GetCharacterIndex("Anacleto Rui Sa Pinto")].ship.name;
			SetCrewQuantity(pchar, 200);
			SetBaseShipData(pchar);
			pchar.location.from_sea = "Douwesen_shore_01";
			sld = LAi_CreateFantomCharacter("man1", "reload", "reload1");
			sld.headmodel = "h_man1";
			sld.id  = "temp_id_sld_fucker";
			sld.dialog.filename = "anacleto_dialog.c";
			sld.dialog.currentnode = "first time";
			LAi_SetActorType(sld);
			LAi_SetStayType(pchar);
			LAi_SetPlayerType(pchar);
			LAi_ActorDialog(sld, pchar, "sld_exit_from_pirate_tavern", 3.0, 1.0);
		break;
		
		case "sld_exit_from_pirate_tavern":
			LAi_ActorGoToLocation(characterFromID("temp_id_sld_fucker"), "reload", "reload1", "none", "", "", "", 10.0);
		break;

		case "kill_anacleto_complete_2":
			LAi_LocationFightDisable(&locations[Findlocation("pirate_tavern")], true);
			pchar.ship.type = characters[GetCharacterIndex("Anacleto Rui Sa Pinto")].ship.type;
			SetCrewQuantity(pchar, 200);
			SetBaseShipData(pchar);
			pchar.location.from_sea = "Douwesen_shore_01";
			bQuestDisableMapEnter = false;
			QuestToSeaLogin_PrepareLoc("Oxbay", "reload", "reload_5", true);
			Island_SetReloadEnableGlobal("Oxbay", true);
			QuestToSeaLogin_Launch();
			pchar.quest.main_line = "blaze_search_danielle_again_10";
		break;


		case "danielle_MetBlazeOnIslaMuelle_Exit":
			LAi_ActorGoToLocator(characterFromID("danielle"), "reload", "reload2", "Story_BlazeMetDanielleOnIslaMuelle", 10.0);
		break;

		case "kill_Ogario_complete":
			characters[GetCharacterIndex("Wilfred Bythesea")].quest.kill_Ogario = "Almost_complete";
		break;

		case "soldier_goto_to_mine_commander":
			ChangeCharacterAddress(characterFromID("mine_soldier_01"), "none", "none");
			LAi_QuestDelay("soldier_goto_to_mine_commander_2", 0.5);
		break;

		case "soldier_goto_to_mine_commander_2":
			ChangeCharacterAddressGroup(characterFromID("mine_commander"), "Oxbay_mine", "reload", "reload1");
			LAi_setActorType(characterFromID("Mine_commander"));
			LAi_ActorDialog(characterFromID("mine_commander"), pchar, "", 12.0, 0);
		break;

		case "commendant_exit_from_mines_complete":
			ChangeCharacterAddress(characterFromID("mine_commander"), "Mines_commander_house", "goto3");
			restorepassengers("Blaze");
			pchar.money = pchar.tempmoney;
			pchar.tempmoney = 0;
			Locations[FindLocation("Oxbay_mine")].reload.l1.disable = 0;
			Locations[FindLocation("Oxbay_mine")].reload.l2.disable = 0;
		break;

		case "commendant_exit_2_from_mines_complete":
			ChangeCharacterAddress(characterFromID("mine_commander"), "Mines_commander_house", "goto3");
			LAi_ActorDialog(characterFromID("Leborio Drago"), pchar, "", 5.0, 0);
		break;

		case "wait_for_resque_from_mines":
			LAi_Fade("mine_soldier_return_to_post", "wait_for_resque_from_mines_complete");
		break;

		case "mine_soldier_return_to_post":
			ChangeCharacterAddress(characterFromID("mine_soldier_01"), "Oxbay_mine", "goto9");
			LAi_SetGuardianType(characterFromID("mine_soldier_01"));
			LAi_group_MoveCharacter(characterFromID("mine_soldier_01"), "ENGLAND_SOLDIERS");
		break;
		
		case "wait_for_resque_from_mines_complete":
			pchar.quest.main_line = "lets_go_mines";
			LAi_SetActorType(characterFromID("Leborio Drago"));
			LAi_ActorDialog(characterFromID("Leborio Drago"), pchar, "", 1.0, 1.0);
		break;

		case "lets_go_begin":
			pchar.location.from_sea = "Oxbay_lighthouse";
			LAi_SetImmortal(characterFromID("leborio drago"), true);
			GiveItem2Character(characterFromID("Leborio Drago"),BLADE_SABER);
			GiveItem2Character(characterFromID("Miner_01"),BLADE_SABER);
			GiveItem2Character(characterFromID("Miner_02"),BLADE_SABER);
			GiveItem2Character(characterFromID("Miner_03"),BLADE_SABER);
			GiveItem2Character(characterFromID("Miner_05"),BLADE_SABER);
			GiveItem2Character(pchar, BLADE_SABER);
			EquipCharacterByItem(pchar, BLADE_SABER);
			EquipCharacterByItem(characterFromID("Leborio Drago"), BLADE_SABER);
			EquipCharacterByItem(characterFromID("Miner_01"),BLADE_SABER);
			EquipCharacterByItem(characterFromID("Miner_02"),BLADE_SABER);
			EquipCharacterByItem(characterFromID("Miner_03"),BLADE_SABER);
			EquipCharacterByItem(characterFromID("Miner_05"),BLADE_SABER);
			LAi_SetHP(characterFromID("Leborio Drago"), 80.0, 80.0);
			LAi_SetHP(characterFromID("Miner_01"), 80.0, 80.0);
			LAi_SetHP(characterFromID("Miner_02"), 80.0, 80.0);
			LAi_SetHP(characterFromID("Miner_03"), 80.0, 80.0);
			LAi_SetHP(characterFromID("Miner_05"), 80.0, 80.0);
			
			pchar.quest.main_line = "lets_go";
			locations[FindLocation("Oxbay_canyon")].reload.l1.disable = 1;
			locations[FindLocation("Oxbay_canyon")].reload.l2.disable = 1;
			LAi_SetOfficerType(characterFromID("Leborio Drago"));
			LAi_SetOfficerType(characterFromID("Miner_01"));
			LAi_SetOfficerType(characterFromID("Miner_02"));
			LAi_SetOfficerType(characterFromID("Miner_03"));
			LAi_SetOfficerType(characterFromID("Miner_05"));
			
			LAi_QuestDelay("lets_go_begin_2", 1.0);
		break;

		case "lets_go_begin_2":
			LAi_group_FightGroups("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, true);
			pchar.quest.to_canyon.win_condition.l1 = "location";
			pchar.quest.to_canyon.win_condition.l1.location = "Oxbay_canyon";
			pchar.quest.to_canyon.win_condition = "to_canyon_complete";

			pchar.quest.mine_soldiers_dead.win_condition.l1 = "NPC_Death";
			pchar.quest.mine_soldiers_dead.win_condition.l1.character = "Mine_soldier_02";
			pchar.quest.mine_soldiers_dead.win_condition.l2 = "NPC_Death";
			pchar.quest.mine_soldiers_dead.win_condition.l2.character = "Mine_soldier_03";
			pchar.quest.mine_soldiers_dead.win_condition.l3 = "NPC_Death";
			pchar.quest.mine_soldiers_dead.win_condition.l3.character = "Mine_soldier_04";
			pchar.quest.mine_soldiers_dead.win_condition = "mine_soldiers_dead_complete";
		break;

		case "mine_soldiers_dead_complete":
			locations[FindLocation("Oxbay_canyon")].reload.l2.disable = 0;
			Locations[FindLocation("Oxbay_mine")].reload.l1.disable = 0;
			Locations[FindLocation("Oxbay_mine")].reload.l2.disable = 0;
			if (!LAi_IsDead(characterFromID("Leborio Drago")))
			{
				LAi_SetActorType(characterFromID("Leborio Drago"));
				LAi_ActorRunToLocation(characterFromID("Leborio Drago"), "reload", "reload1", "Oxbay_canyon", "officers", "reload4_1", "", 20.0);
			}
			if (!LAi_IsDead(characterFromID("Miner_01")))
			{
				LAi_SetActorType(characterFromID("Miner_01"));
				LAi_ActorRunToLocation(characterFromID("Miner_01"), "reload", "reload1", "Oxbay_canyon", "officers", "reload4_2", "", 20.0.);
			}
			if (!LAi_IsDead(characterFromID("Miner_02")))
			{
				LAi_SetActorType(characterFromID("Miner_02"));
				LAi_ActorRunToLocation(characterFromID("Miner_02"), "reload", "reload1", "Oxbay_canyon", "officers", "reload4_2", "", 20.0);
			}
			if (!LAi_IsDead(characterFromID("Miner_03")))
			{
				LAi_SetActorType(characterFromID("Miner_03"));
				LAi_ActorRunToLocation(characterFromID("Miner_03"), "reload", "reload1", "Oxbay_canyon", "officers", "reload4_3", "", 20.0);
			}
			if (!LAi_IsDead(characterFromID("Miner_05")))
			{
				LAi_SetActorType(characterFromID("Miner_05"));
				LAi_ActorRunToLocation(characterFromID("Miner_05"), "reload", "reload1", "Oxbay_canyon", "officers", "reload4_4", "", 20.0);
			}
			locations[FindLocation("Oxbay_canyon")].reload.l3.disable = 1;
		break;

		case "to_canyon_complete":
			locations[FindLocation("Oxbay_canyon")].reload.l1.disable = 0;
			PlaceCharacter(characterFromID("Leborio drago"), "officers", "Oxbay_canyon");
			PlaceCharacter(characterFromID("Miner_01"), "officers", "Oxbay_canyon");
			PlaceCharacter(characterFromID("Miner_02"), "officers", "Oxbay_canyon");
			PlaceCharacter(characterFromID("Miner_03"), "goto", "Oxbay_canyon");
			PlaceCharacter(characterFromID("Miner_05"), "goto", "Oxbay_canyon");
			LAi_SetOfficerType(characterFromID("Leborio Drago"));
			LAi_SetOfficerType(characterFromID("Miner_01"));
			LAi_SetOfficerType(characterFromID("Miner_02"));
			LAi_SetOfficerType(characterFromID("Miner_03"));
			LAi_SetOfficerType(characterFromID("Miner_05"));

			pchar.quest.to_lighthouse.win_condition.l1 = "location";
			pchar.quest.to_lighthouse.win_condition.l1.location = "Oxbay_lighthouse";
			pchar.quest.to_lighthouse.win_condition = "to_lighthouse_complete";

			pchar.quest.peace_when_we_are_leaving_canyon.win_condition.l1 = "ExitFromLocation";
			pchar.quest.peace_when_we_are_leaving_canyon.win_condition.l1.location = "Oxbay_canyon";
			pchar.quest.peace_when_we_are_leaving_canyon.win_condition = "peace_when_we_are_leaving_canyon";

			LAi_group_FightGroups("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, true);

			pchar.quest.canyon_soldiers_dead.win_condition.l1 = "NPC_Death";
			pchar.quest.canyon_soldiers_dead.win_condition.l1.character = "Mine_soldier_05";
			pchar.quest.canyon_soldiers_dead.win_condition.l2 = "NPC_Death";
			pchar.quest.canyon_soldiers_dead.win_condition.l2.character = "Mine_soldier_06";
			pchar.quest.canyon_soldiers_dead.win_condition = "canyon_soldiers_dead_complete";
		break;

		case "peace_when_we_are_leaving_canyon":
			locations[FindLocation("Oxbay_canyon")].reload.l3.disable = 0;
			LAi_group_SetRelation("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
		break;

		case "canyon_soldiers_dead_complete":
			if (!LAi_IsDead(characterFromID("Leborio Drago")))
			{
				LAi_SetActorType(characterFromID("Leborio Drago"));
				LAi_ActorRunToLocation(characterFromID("Leborio Drago"), "reload", "reload6_back", "Oxbay_lighthouse", "officers", "reload1_1", "", 45.0);
			}
			if (!LAi_IsDead(characterFromID("Miner_01")))
			{
				LAi_SetActorType(characterFromID("Miner_01"));
				LAi_ActorRunToLocation(characterFromID("Miner_01"), "reload", "reload6_back", "none", "reload", "reload1", "", 45.0);
			}
			if (!LAi_IsDead(characterFromID("Miner_02")))
			{
				LAi_SetActorType(characterFromID("Miner_02"));
				LAi_ActorRunToLocation(characterFromID("Miner_02"), "reload", "reload6_back", "none", "reload", "reload1", "", 45.0);
			}
			if (!LAi_IsDead(characterFromID("Miner_03")))
			{
				LAi_SetActorType(characterFromID("Miner_03"));
				LAi_ActorRunToLocation(characterFromID("Miner_03"), "reload", "reload6_back", "none", "reload", "reload1", "", 45.0);
			}
			if (!LAi_IsDead(characterFromID("Miner_05")))
			{
				LAi_SetActorType(characterFromID("Miner_05"));
				LAi_ActorRunToLocation(characterFromID("Miner_05"), "reload", "reload6_back", "none", "reload", "reload1", "", 45.0);
			}
		break;

		case "to_lighthouse_complete":
			LAi_SetImmortal(characterFromID("leborio drago"), false);
			EnableEquip(pchar, BLADE_ITEM_TYPE, true);
			EnableEquip(pchar, GUN_ITEM_TYPE, true);
			EquipCharacterByItem(pchar, FindCharacterItemByGroup(pchar, BLADE_ITEM_TYPE));
			EquipCharacterByItem(pchar, FindCharacterItemByGroup(pchar, GUN_ITEM_TYPE));
			ChangeCharacterAddress(characterFromID("Miner_01"), "none", "none");
			ChangeCharacterAddress(characterFromID("Miner_02"), "none", "none");
			ChangeCharacterAddress(characterFromID("Miner_03"), "none", "none");
			ChangeCharacterAddress(characterFromID("Miner_05"), "none", "none");
			restorepassengers("Blaze");
			pchar.money = pchar.tempmoney;
			RestorePassengers(pchar.id);
			pchar.tempmoney = "0";
			Locations[FindLocation("Oxbay_canyon")].reload.l1.disable = 0;
			pchar.quest.main_line = "after_speak_with_leborio";
			LAi_type_actor_Reset(characterFromID("Leborio Drago"));
			ChangeCharacterAddressGroup(characterFromID("Leborio Drago"), "Oxbay_lighthouse", "officers", "reload1_1");
			characters[GetCharacterIndex("Leborio Drago")].quest.hire = "ask_for_hire";
			LAi_ActorDialog(characterFromID("Leborio Drago"), pchar, "", 2.0, 1.0);
			AddPartyExp(pchar, 15000);
			AddQuestRecord("search_danielle", "16");
		break;

		case "hired_leborio_complete":
			LAi_SetOfficerType(characterFromID("leborio drago"));
		break;

		case "resque_danielle":
			Locations[FindLocation("Quest_Muelle_town_01")].reload.l1.name = "reload1";
			Locations[FindLocation("Quest_Muelle_town_01")].reload.l1.go = "Muelle_port";
			Locations[FindLocation("Quest_Muelle_town_01")].reload.l1.emerge = "reload2";
			Locations[FindLocation("Quest_Muelle_town_01")].reload.l1.autoreload = 0;
			Locations[FindLocation("Quest_Muelle_town_01")].reload.l1.label = "port";
						
			LAi_ActorRunToLocator(characterFromID("danielle"), "reload", "reload1", "danielle_to_muelle_port", 30.0);

			pchar.quest.to_secret_oxbay_shore.win_condition.l1 = "location";
			pchar.quest.to_secret_oxbay_shore.win_condition.l1.location = "Redmond_shore_01";
			pchar.quest.to_secret_oxbay_shore.win_condition = "to_secret_oxbay_shore_complete";
		break;

		case "danielle_to_muelle_port":
			ChangeCharacterAddress(characterFromID("danielle"), "none", "");
		break;

		case "wait_for_night_in_shore":
			SetCurrentTime(23, 0);
			LAi_Fade("", "to_secret_oxbay_shore_complete2");
		break;

		case "exit_after_speak_with_rheims":
			LAi_SetActorType(characterFromID("danielle"));
			SetMainCharacterIndex(0);
			PChar = GetMainCharacter();
			LAi_SetImmortal(pchar, false);
			ChangeCharacterAddress(characterFromID("Danielle"), "none", "none");
			ChangeCharacterAddress(characterFromID("Vincent Bethune"), "none", "none");
			ChangeCharacterAddress(characterFromID("Raoul Rheims"), "none", "none");
			DoQuestReloadToLocation("Rheims_house_inside", "goto", "goto5", "exit_after_speak_with_rheims_2");
			Locations[FindLocation("Douwesen_port")].reload.l2.disable = 0;
			Locations[FindLocation("Douwesen_port")].reload.l3.disable = 0;
			Locations[FindLocation("Douwesen_shore_01")].reload.l2.disable = 0;
			Locations[FindLocation("Douwesen_shore_02")].reload.l2.disable = 0;
			pchar.quest.main_line = "danielle_speak_with_almost_dead_rheims_complete";
			AddQuestRecord("again_find_rheims", "7");
			CloseQuestHeader("again_find_rheims");
			SetQuestHeader("search_danielle");
			AddQuestrecord("search_danielle", "1");
			locCameraFollow();
			restorepassengers(pchar.id);

			RemoveCharacterEquip(characterFromID("danielle"), BLADE_ITEM_TYPE);
			GiveItem2Character(characterFromID("danielle"), "blade6");
			EquipCharacterByItem(characterFromID("danielle"), "blade6");
			AddPartyExp(pchar, 10000);
		break;
		
		case "exit_after_speak_with_rheims_2":
			LAi_SetPlayerType(characterFromID("blaze"));
		break;

		case "restore_hp":
			int iOfficer;
			LAi_SetCurHPMax(pchar);
			for (int i=1; i<4; i++)
			{
				if (GetOfficersIndex(Pchar, i) != -1)
				{
					iOfficer = GetOfficersIndex(Pchar, i);
					LAi_SetCurHPMax(&characters[iOfficer]);
				}
			}			
		break;

		case "sleep_in_greenford_tavern":
			DoQuestReloadToLocation("Greenford_tavern_upstairs", "reload", "reload1", "restore_hp");
		break;

		case "sleep_in_oxbay_tavern":
			DoQuestReloadToLocation("Oxbay_tavern_upstairs", "reload", "reload1", "restore_hp");
		break;

		case "sleep_in_redmond_tavern":
			DoQuestReloadToLocation("Redmond_tavern_upstairs", "reload", "reload1", "restore_hp");
		break;

		case "sleep_in_falaise_de_fleur_tavern":
			DoQuestReloadToLocation("Falaise_De_Fleur_tavern_upstairs", "reload", "reload1", "restore_hp");
		break;

		case "sleep_in_douwesen_tavern":
			DoQuestReloadToLocation("Douwesen_tavern_upstairs", "reload", "reload1", "restore_hp");
		break;

		case "sleep_in_muelle_tavern":
			DoQuestReloadToLocation("Muelle_tavern_upstairs", "reload", "reload1", "restore_hp");
		break;

		case "sleep_in_Conceicao_tavern":
			DoQuestReloadToLocation("Conceicao_tavern_upstairs", "reload", "reload1", "restore_hp");
		break;

		case "sleep_in_smugglers_tavern":
			DoQuestReloadToLocation("Smugglers_tavern_upstairs", "reload", "reload1", "restore_hp");
		break;

		case "sleep_in_qc_tavern":
			DoQuestReloadToLocation("QC_tavern_upstairs", "reload", "reload1", "restore_hp");
		break;

		case "sleep_in_pirate_tavern":
			DoQuestReloadToLocation("Pirate_tavern_upstairs", "reload", "reload1", "restore_hp");
		break;

		case "bad_swimming_in_oxbay":
			LAi_SetActorType(characterFromID("Anacleto Rui Sa Pinto"));
			ChangeCharacterAddress(characterFromID("Anacleto Rui Sa Pinto"), "ship_deck", "goto2");
			ChangeCharacterAddress(characterFromID("pirate for abordage 01"), "ship_deck", "goto1");
			ChangeCharacterAddress(characterFromID("pirate for abordage 02"), "ship_deck", "goto3");
			ChangeCharacterAddress(characterFromID("pirate for abordage 03"), "ship_deck", "goto4");
			DoQuestReloadToLocation("ship_deck", "reload", "locator2", "bad_swimming_in_oxbay_complete");
		break;

		case "bad_swimming_in_oxbay_complete":
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Anacleto Rui Sa Pinto"));
			LAi_ActorFollow(pchar, characterFromID("Anacleto Rui Sa Pinto"), "", 2.0);
			LAi_ActorFollow(characterFromID("Anacleto Rui Sa Pinto"), pchar, "bad_swimming_in_oxbay_complete_1", 2.0);
		break
		
		case "bad_swimming_in_oxbay_complete_1":
			LAi_type_actor_Reset(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("Anacleto Rui Sa Pinto"));
			LAi_ActorDialog(characterFromID("Anacleto Rui Sa Pinto"), pchar, "pchar_back_to_player", 3.0, 0);
		break;

		case "swimming_to_lighthouse":
			ChangeCharacterAddressGroup(characterFromID("researcher"), "Oxbay_Lighthouse", "officers", "reload3_1");
			DoQuestReloadToLocation("Oxbay_lighthouse", "reload", "reload3", "to_lighthouse_see_tartane_complete");
			worldMap.playerShipX = 176.27;
			worldMap.playerShipZ = 35.34;
			worldMap.playerShipAY = 3.0;
			worldMap.playerShipActionRadius = 20.0;
			worldMap.playerShipDispX = stf(worldMap.playerShipX) - stf(worldMap.islands.Oxbay.position.rx);
			worldMap.playerShipDispZ = stf(worldMap.playerShipZ) - stf(worldMap.islands.Oxbay.position.rz);
			pchar.location.from_sea = "Oxbay_lighthouse";
			pchar.ship.type = SHIP_TARTANE;
			setCharacterShipLocation(characterFromID("researcher"), "none");
			setCharacterShipLocation(pchar, "Oxbay_Lighthouse");
		break;

		case "without_ship_complete":
			LAi_fade("", "to_lighthouse_see_tartane_complete_3");
		break;

		case "to_lighthouse_see_tartane_complete":
			pchar.quest.main_line = "without_ship";
			PlaceCharacter(characterfromID("researcher"), "goto", "Oxbay_lighthouse");
			LAi_SetActorType(characterFromID("researcher"));
			LAi_SetActorType(pchar);
			LAi_ActorFollow(pchar, characterFromID("researcher"), "", 3.0);
			LAi_ActorFollow(characterFromID("researcher"), pchar, "to_lighthouse_see_tartane_complete_2", 3.0);
		break;
		
		case "to_lighthouse_see_tartane_complete_2":
			LAi_type_actor_Reset(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("researcher"));
			LAi_ActorDialog(characterFromID("researcher"), pchar, "pchar_back_to_player", 1.0, 1.0);
		break;

		case "to_lighthouse_see_tartane_complete_3":
			pchar.quest.main_line = "see_yaht";
			LAi_SetActorType(characterFromID("researcher"));
			LAi_ActorDialog(characterFromID("researcher"), pchar, "", 5.0, 1.0);
			bQuestDisableMapEnter = false;
		break;

		case "tavern_keeper":
			homelocation = pchar.location;
			switch(homelocation)
			{
				case "Redmond_tavern":
					characters[GetCharacterIndex("Charles Windem")].dialog.currentnode = "tavern_keeper";
					LAi_ActorWaitDialog(pchar, characterFromID("Charles Windem"));
					LAi_SetActorType(characterFromID("Charles Windem"));
					LAi_ActorDialogNow(characterFromID("Charles Windem"), pchar, "tavern_keeper_2", -1);
				break;

				case "Oxbay_tavern":
					characters[GetCharacterIndex("Everard Gordon")].dialog.currentnode = "tavern_keeper";
					LAi_ActorWaitDialog(pchar, characterFromID("Everard Gordon"));
					LAi_SetActorType(characterFromID("Everard Gordon"));
					LAi_ActorDialogNow(characterFromID("Everard Gordon"), pchar, "tavern_keeper_2", -1);
				break;

				case "Greenford_tavern":
					characters[GetCharacterIndex("Simon Hanpool")].dialog.currentnode = "tavern_keeper";
					LAi_ActorWaitDialog(pchar, characterFromID("Simon Hanpool"));
					LAi_SetActorType(characterFromID("Simon Hanpool"));
					LAi_ActorDialogNow(characterFromID("Simon Hanpool"), pchar, "tavern_keeper_2", -1);
				break;

				case "Falaise_De_Fleur_tavern":
					characters[GetCharacterIndex("Antoine Lebretton")].dialog.currentnode = "tavern_keeper";
					LAi_ActorWaitDialog(pchar, characterFromID("Antoine Lebretton"));
					LAi_SetActorType(characterFromID("Antoine Lebretton"));
					LAi_ActorDialogNow(characterFromID("Antoine Lebretton"), pchar, "tavern_keeper_2", -1);
				break;

				case "Muelle_tavern":
					characters[GetCharacterIndex("Claudio Burrieza")].dialog.currentnode = "tavern_keeper";
					LAi_ActorWaitDialog(pchar, characterFromID("Claudio Burrieza"));
					LAi_SetActorType(characterFromID("Claudio Burrieza"));
					LAi_ActorDialogNow(characterFromID("Claudio Burrieza"), pchar, "tavern_keeper_2", -1);
				break;

				case "Douwesen_tavern":
					characters[GetCharacterIndex("Friedrich Corleis")].dialog.currentnode = "tavern_keeper";
					LAi_ActorWaitDialog(pchar, characterFromID("Friedrich Corleis"));
					LAi_SetActorType(characterFromID("Friedrich Corleis"));
					LAi_ActorDialogNow(characterFromID("Friedrich Corleis"), pchar, "tavern_keeper_2", -1);
				break;

				case "Pirate_tavern":
					characters[GetCharacterIndex("Mario Figuiera")].dialog.currentnode = "tavern_keeper";
					LAi_ActorWaitDialog(pchar, characterFromID("Mario Figuiera"));
					LAi_SetActorType(characterFromID("Mario Figuiera"));
					LAi_ActorDialogNow(characterFromID("Mario Figuiera"), pchar, "tavern_keeper_2", -1);
				break;

				case "Conceicao_tavern":
					characters[GetCharacterIndex("Duarte Correja")].dialog.currentnode = "tavern_keeper";
					LAi_ActorWaitDialog(pchar, characterFromID("Duarte Correja"));
					LAi_SetActorType(characterFromID("Duarte Correja"));
					LAi_ActorDialogNow(characterFromID("Duarte Correja"), pchar, "tavern_keeper_2", -1);
				break;

				case "Smugglers_tavern":
					characters[GetCharacterIndex("Fabiao Dunga")].dialog.currentnode = "tavern_keeper";
					LAi_ActorWaitDialog(pchar, characterFromID("Fabiao Dunga"));
					LAi_SetActorType(characterFromID("Fabiao Dunga"));
					LAi_ActorDialogNow(characterFromID("Fabiao Dunga"), pchar, "tavern_keeper_2", -1);
				break;

				case "QC_tavern":
					characters[GetCharacterIndex("Ines Diaz")].dialog.currentnode = "tavern_keeper";
					LAi_ActorWaitDialog(pchar, characterFromID("Ines Diaz"));
					LAi_SetActorType(characterFromID("Ines Diaz"));
					LAi_ActorDialogNow(characterFromID("Ines Diaz"), pchar, "tavern_keeper_2", -1);
				break;
			}
		break;

		case "tavern_keeper_2":
			homelocation = pchar.location;
			switch(homelocation)
			{
				case "Redmond_tavern":
					characters[GetCharacterIndex("Charles Windem")].dialog.currentnode = "First time";
					LAi_SetBarmanType(characterFromID("Charles Windem"));
				break;

				case "Oxbay_tavern":
					characters[GetCharacterIndex("Everard Gordon")].dialog.currentnode = "First time";
					LAi_SetBarmanType(characterFromID("Everard Gordon"));
				break;

				case "Greenford_tavern":
					LAi_SetBarmanType(characterFromID("Simon Hanpool"));
					characters[GetCharacterIndex("Simon Hanpool")].dialog.currentnode = "second time";
				break;

				case "Falaise_De_Fleur_tavern":
					LAi_SetBarmanType(characterFromID("Antoine Lebretton"));
					characters[GetCharacterIndex("Antoine Lebretton")].dialog.currentnode = "second time";
				break;

				case "Muelle_tavern":
					LAi_SetBarmanType(characterFromID("Claudio Burrieza"));
					characters[GetCharacterIndex("Claudio Burrieza")].dialog.currentnode = "second time";
				break;

				case "Douwesen_tavern":
					LAi_SetBarmanType(characterFromID("Friedrich Corleis"));
					characters[GetCharacterIndex("Friedrich Corleis")].dialog.currentnode = "second time";
				break;

				case "Pirate_tavern":
					LAi_SetBarmanType(characterFromID("Mario Figuiera"));
					characters[GetCharacterIndex("Mario Figuiera")].dialog.currentnode = "second time";
				break;

				case "Conceicao_tavern":
					LAi_SetBarmanType(characterFromID("Duarte Correja"));
					characters[GetCharacterIndex("Duarte Correja")].dialog.currentnode = "second time";
				break;

				case "Smugglers_tavern":
					LAi_SetBarmanType(characterFromID("Fabiao Dunga"));
					characters[GetCharacterIndex("Fabiao Dunga")].dialog.currentnode = "second time";
				break;

				case "QC_tavern":
					LAi_SetBarmanType(characterFromID("Ines Diaz"));
					characters[GetCharacterIndex("Ines Diaz")].dialog.currentnode = "second time";
				break;
			}
		break;

		case "drink_talk_with_soldier":
			tavernfriend = pchar.quest.friend_in_tavern;
			LAi_SetSitType(characterFromID(tavernfriend));
			switch(pchar.location)
			{
				case "Redmond_tavern":
					LAi_SetHP(characterFromID("Redmond soldier"), 80.0, 80.0);
					ChangeCharacterAddress(characterFromID("Redmond Soldier"), "Redmond_town_01", "cityzen9");
					DoQuestReloadToLocation("Redmond_town_01", "goto", "goto12", "drink_speak_with_soldier");
					LAi_group_MoveCharacter(characterFromID("Redmond Soldier"), "ENGLAND_SOLDIERS");
					pchar.friend_in_tavern2 = "ENGLAND_SOLDIERS";
				break;

				case "Oxbay_tavern":
					LAi_SetHP(characterFromID("Oxbay soldier"), 80.0, 80.0);
					ChangeCharacterAddress(characterFromID("Oxbay Soldier"), "Oxbay_town", "goto37");
					DoQuestReloadToLocation("Oxbay_town", "goto", "goto36", "drink_speak_with_soldier");
					LAi_group_MoveCharacter(characterFromID("Oxbay Soldier"), "ENGLAND_SOLDIERS");
					pchar.friend_in_tavern2 = "ENGLAND_SOLDIERS";
				break;

				case "Greenford_tavern":
					LAi_SetHP(characterFromID("Greenford soldier"), 80.0, 80.0);
					ChangeCharacterAddress(characterFromID("Greenford Soldier"), "Greenford_town", "goto9");
					DoQuestReloadToLocation("Greenford_town", "goto", "goto14", "drink_speak_with_soldier");
					LAi_group_MoveCharacter(characterFromID("Greenford Soldier"), "ENGLAND_SOLDIERS");
					pchar.friend_in_tavern2 = "ENGLAND_SOLDIERS";
				break;

				case "Falaise_De_Fleur_tavern":
					LAi_SetHP(characterFromID("Falaise de Fleur soldier"), 80.0, 80.0);
					ChangeCharacterAddress(characterFromID("Falaise De Fleur Soldier"), "Falaise_de_fleur_location_03", "locator12");
					DoQuestReloadToLocation("Falaise_De_fleur_location_03", "goto", "locator11", "drink_speak_with_soldier");
					LAi_group_MoveCharacter(characterFromID("Falaise De Fleur Soldier"), "FRANCE_SOLDIERS");
					pchar.friend_in_tavern2 = "FRANCE_SOLDIERS";
				break;

				case "Muelle_tavern":
					LAi_SetHP(characterFromID("Muelle soldier"), 80.0, 80.0);
					ChangeCharacterAddress(characterFromID("Muelle Soldier"), "Muelle_town_01", "goto23");
					DoQuestReloadToLocation("Muelle_town_01", "goto", "goto100", "drink_speak_with_soldier");
					LAi_group_MoveCharacter(characterFromID("Muelle Soldier"), "SPAIN_SOLDIERS");
					pchar.friend_in_tavern2 = "SPAIN_SOLDIERS";
				break;

				case "Douwesen_tavern":
					LAi_SetHP(characterFromID("Douwesen soldier"), 80.0, 80.0);
					ChangeCharacterAddress(characterFromID("Douwesen Soldier"), "Douwesen_town", "goto3");
					DoQuestReloadToLocation("Douwesen_town", "goto", "goto5", "drink_speak_with_soldier");
					LAi_group_MoveCharacter(characterFromID("DOuwesen Soldier"), "DOUWESEN_SOLDIERS");
					pchar.friend_in_tavern2 = "DOUWESEN_SOLDIERS";
				break;

				case "Pirate_tavern":
					LAi_SetHP(characterFromID("Pirate soldier"), 80.0, 80.0);
					ChangeCharacterAddress(characterFromID("Pirate Soldier"), "Pirate_fort", "character9");
					DoQuestReloadToLocation("Pirate_fort", "goto", "character10", "drink_speak_with_soldier");
					LAi_group_MoveCharacter(characterFromID("Pirate Soldier"), "PIRATE_SOLDIERS");
					pchar.friend_in_tavern2 = "PIRATE_SOLDIERS";
				break;

				case "Conceicao_tavern":
					LAi_SetHP(characterFromID("Conceicao soldier"), 80.0, 80.0);
					ChangeCharacterAddress(characterFromID("Conceicao Soldier"), "Conceicao_town", "goto5");
					DoQuestReloadToLocation("Conceicao_town", "goto", "goto4", "drink_speak_with_soldier");
					LAi_group_MoveCharacter(characterFromID("Conceicao Soldier"), "CONCEICAO_SOLDIERS");
					pchar.friend_in_tavern2 = "CONCEICAO_SOLDIERS";
				break;

				case "Smugglers_tavern":
					LAi_SetHP(characterFromID("Smugglers soldier"), 80.0, 80.0);
					ChangeCharacterAddress(characterFromID("Smugglers Soldier"), "Smugglers_lair", "goto12");
					DoQuestReloadToLocation("Smugglers_lair", "goto", "goto11", "drink_speak_with_soldier");
					LAi_group_MoveCharacter(characterFromID("Smugglers Soldier"), "SMUGGLER_SOLDIERS");
					pchar.friend_in_tavern2 = "SMUGGLER_SOLDIERS";
				break;

				case "QC_tavern":
					LAi_SetHP(characterFromID("QC soldier"), 80.0, 80.0);
					DoQuestReloadToLocation("QC_town", "goto", "character4", "drink_speak_with_soldier");
					LAi_group_MoveCharacter(characterFromID("QC Soldier"), "QC_SOLDIERS");
					pchar.friend_in_tavern2 = "QC_SOLDIERS";
				break;
			}
		break;

		case "drink_speak_with_soldier":
			LAi_SetActorType(pchar);
			switch(pchar.location)
			{
				case "Redmond_town_01":
					characters[GetCharacterIndex("Redmond soldier")].dialog.currentnode = "drink";
					LAi_ActorDialog(pchar, characterFromID("Redmond soldier"), "pchar_back_to_player", 5.0, 1.0);
				break;

				case "Oxbay_town":
					characters[GetCharacterIndex("Oxbay soldier")].dialog.currentnode = "drink";
					LAi_ActorDialog(pchar, characterFromID("Oxbay Soldier"), "pchar_back_to_player", 5.0, 1.0);
				break;

				case "Greenford_town":
					characters[GetCharacterIndex("Greenford soldier")].dialog.currentnode = "drink";
					LAi_ActorDialog(pchar, characterFromID("Greenford soldier"), "pchar_back_to_player", 5.0, 1.0);
				break;

				case "Falaise_De_Fleur_town":
					characters[GetCharacterIndex("Falaise De Fleur soldier")].dialog.currentnode = "drink";
					LAi_ActorDialog(pchar, characterFromID("Falaise De Fleur soldier"), "pchar_back_to_player", 5.0, 1.0);
				break;

				case "Muelle_town_01":
					characters[GetCharacterIndex("Muelle soldier")].dialog.currentnode = "drink";
					LAi_ActorDialog(pchar, characterFromID("Muelle soldier"), "pchar_back_to_player", 5.0, 1.0);
				break;

				case "Douwesen_town":
					characters[GetCharacterIndex("Douwesen Soldier")].dialog.currentnode = "drink";
					LAi_ActorDialog(pchar, characterFromID("Douwesen Soldier"), "pchar_back_to_player", 5.0, 1.0);
				break;

				case "Pirate_town":
					characters[GetCharacterIndex("Pirate Soldier")].dialog.currentnode = "drink";
					LAi_ActorDialog(pchar, characterFromID("Pirate Soldier"), "pchar_back_to_player", 5.0, 1.0);
				break;

				case "Conceicao_town":
					characters[GetCharacterIndex("Conceicao Soldier")].dialog.currentnode = "drink";
					LAi_ActorDialog(pchar, characterFromID("Conceicao Soldier"), "pchar_back_to_player", 5.0, 1.0);
				break;

				case "Smugglers_town":
					characters[GetCharacterIndex("Smugglers Soldier")].dialog.currentnode = "drink";
					LAi_ActorDialog(pchar, characterFromID("Smugglers Soldier"), "pchar_back_to_player", 5.0, 1.0);
				break;

				case "QC_town":
					PlaceCharacter(characterFromID("QC Soldier"), "goto", "QC_town");
					characters[GetCharacterIndex("QC Soldier")].dialog.currentnode = "drink";
					LAi_ActorDialog(pchar, characterFromID("QC Soldier"), "pchar_back_to_player", 5.0, 1.0);
				break;
			}
		break;

		case "without_memory":
			LAi_Fade("exit_sit_2", "saved_by_off");
		break;

		case "drink_fight_in_tavern_with_fantoms":
			LAi_Fade("exit_sit_2", "fighting2");
		break;

		case "fighting":
			sld = LAi_CreateFantomCharacter("man1", "reload", "reload1");
			sld.headmodel = "h_man1";
			sld.dialog.filename = "tavern fightingman_dialog.c";
			
			LAi_SetActorType(sld);
			LAi_group_MoveCharacter(sld, "TAVERN_FIGHTER");
			LAi_ActorDialogNow(sld, pchar, "", -1);
		break;

		case "fighting2":
			locCameraFollow();
			LAi_SetSitType(characterFromID(pchar.quest.friend_in_tavern));
			LAi_SetPlayerType(pchar);
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false); 
		
			LAi_group_FightGroups("TAVERN_FIGHTER", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("TAVERN_FIGHTER", "kill_tavern_fightman_complete");
		break;

		case "saved_by_off":
			LAi_SetStayType(pchar);
			AddMoneyToCharacter(pchar, -100);
			homelocation = pchar.location;
			switch(homelocation)
			{
				case "Redmond_tavern":
					PlaceCharacter(characterFromID("Redmond_officiant"), "goto", homelocation);
					characters[GetCharacterIndex("Redmond_officiant")].dialog.currentnode = "without_money";
					LAi_SetActorType(characterFromID("Redmond_officiant"));
					LAi_ActorDialog(characterFromID("Redmond_officiant"), pchar, "officiant_back_to_citizen", 5.0, 1.0);
				break;

				case "Oxbay_tavern":
					PlaceCharacter(characterFromID("Oxbay_officiant"), "goto", homelocation);
					characters[GetCharacterIndex("Oxbay_officiant")].dialog.currentnode = "without_money";
					LAi_SetActorType(characterFromID("Oxbay_officiant"));
					LAi_ActorDialog(characterFromID("Oxbay_officiant"), pchar, "officiant_back_to_citizen", 5.0, 1.0);
				break;

				case "Greenford_tavern":
					PlaceCharacter(characterFromID("Greenford_officiant"), "goto", homelocation);
					characters[GetCharacterIndex("Greenford_officiant")].dialog.currentnode = "without_money";
					LAi_SetActorType(characterFromID("Greenford_officiant"));
					LAi_ActorDialog(characterFromID("Greenford_officiant"), pchar, "officiant_back_to_citizen", 5.0, 1.0);
				break;

				case "Falaise_De_Fleur_tavern":
					PlaceCharacter(characterFromID("Falaise_De_Fleur_officiant"), "goto", homelocation);
					characters[GetCharacterIndex("Falaise_De_Fleur_officiant")].dialog.currentnode = "without_money";
					LAi_SetActorType(characterFromID("Falaise_De_fleur_officiant"));
					LAi_ActorDialog(characterFromID("Falaise_de_fleur_officiant"), pchar, "officiant_back_to_citizen", 5.0, 1.0);
				break;

				case "Muelle_tavern":
					PlaceCharacter(characterFromID("Muelle_officiant"), "goto", homelocation);
					characters[GetCharacterIndex("Muelle_officiant")].dialog.currentnode = "without_money";
					LAi_SetActorType(characterFromID("Muelle_officiant"));
					LAi_ActorDialog(characterFromID("Muelle_officiant"), pchar, "officiant_back_to_citizen", 5.0, 1.0);
				break;

				case "Douwesen_tavern":
					PlaceCharacter(characterFromID("Douwesen_officiant"), "goto", homelocation);
					characters[GetCharacterIndex("Douwesen_officiant")].dialog.currentnode = "without_money";
					LAi_SetActorType(characterFromID("Douwesen_officiant"));
					LAi_ActorDialog(characterFromID("Douwesen_officiant"), pchar, "officiant_back_to_citizen", 5.0, 1.0);
				break;

				case "Pirate_tavern":
					PlaceCharacter(characterFromID("Pirate_officiant"), "goto", homelocation);
					characters[GetCharacterIndex("Pirate_officiant")].dialog.currentnode = "without_money";
					LAi_SetActorType(characterFromID("Pirate_officiant"));
					LAi_ActorDialog(characterFromID("Pirate_officiant"), pchar, "officiant_back_to_citizen", 5.0, 1.0);
				break;

				case "Conceicao_tavern":
					PlaceCharacter(characterFromID("Conceicao_officiant"), "goto", homelocation);
					characters[GetCharacterIndex("Conceicao_officiant")].dialog.currentnode = "without_money";
					LAi_SetActorType(characterFromID("Conceicao_officiant"));
					LAi_ActorDialog(characterFromID("Conceicao_officiant"), pchar, "officiant_back_to_citizen", 5.0, 1.0);
				break;

				case "Smugglers_tavern":
					PlaceCharacter(characterFromID("Smugglers_officiant"), "goto", homelocation);
					characters[GetCharacterIndex("Smugglers_officiant")].dialog.currentnode = "without_money";
					LAi_SetActorType(characterFromID("Smugglers_officiant"));
					LAi_ActorDialog(characterFromID("Smugglers_officiant"), pchar, "officiant_back_to_citizen", 5.0, 1.0);
				break;

				case "QC_tavern":
					PlaceCharacter(characterFromID("QC_officiant"), "goto", homelocation);
					characters[GetCharacterIndex("QC_officiant")].dialog.currentnode = "without_money";
					LAi_SetActorType(characterFromID("QC_officiant"));
					LAi_ActorDialog(characterFromID("QC_officiant"), pchar, "officiant_back_to_citizen", 5.0, 1.0);
				break;
			}
		break;

		case "officiant_back_to_citizen":
			LAi_SetPlayerType(pchar);
			AddMoneyToCharacter(pchar, -100);
			switch(pchar.location)
			{
				case "Redmond_tavern":
					LAi_SetWaitressType(characterFromID("Redmond_officiant"));
					LAi_group_MoveCharacter(characterFromID("Redmond_officiant"), "ENGLAND_CITIZENS");
				break;

				case "Oxbay_tavern":
					LAi_SetWaitressType(characterFromID("Oxbay_officiant"));
					LAi_group_MoveCharacter(characterFromID("Oxbay_officiant"), "ENGLAND_CITIZENS");
				break;

				case "Greenford_tavern":
					LAi_SetWaitressType(characterFromID("Greenford_officiant"));
					LAi_group_MoveCharacter(characterFromID("Greenford_officiant"), "ENGLAND_CITIZENS");
				break;

				case "Falaise_De_Fleur_tavern":
					LAi_SetWaitressType(characterFromID("Falaise_De_fleur_officiant"));
					LAi_group_MoveCharacter(characterFromID("Falaise_De_fleur_officiant"), "FRANCE_CITIZENS");
				break;

				case "Muelle_tavern":
					LAi_SetWaitressType(characterFromID("Muelle_officiant"));
					LAi_group_MoveCharacter(characterFromID("Muelle_officiant"), "SPAIN_CITIZENS");
				break;

				case "Douwesen_tavern":
					LAi_SetWaitressType(characterFromID("Douwesen_officiant"));
					LAi_group_MoveCharacter(characterFromID("Douwesen_officiant"), "DOUWESEN_CITIZENS");
				break;

				case "Pirate_tavern":
					LAi_SetWaitressType(characterFromID("Pirate_officiant"));
					LAi_group_MoveCharacter(characterFromID("Pirate_officiant"), "DOUWESEN_PIRATE_CITIZENS");
				break;

				case "Conceicao_tavern":
					LAi_SetWaitressType(characterFromID("Conceicao_officiant"));
					LAi_group_MoveCharacter(characterFromID("Conceicao_officiant"), "CONCEICAO_CITIZENS");
				break;

				case "Smugglers_tavern":
					LAi_SetWaitressType(characterFromID("Smugglers_officiant"));
					LAi_group_MoveCharacter(characterFromID("Smugglers_officiant"), "SMUGGLERS_CITIZENS");
				break;

				case "QC_tavern":
					LAi_SetWaitressType(characterFromID("QC_officiant"));
					LAi_group_MoveCharacter(characterFromID("QC_officiant"), "QC_CITIZENS");
				break;
			}
		break;

		case "alc":
			LAi_Fade("alc_2_prepare", "alc2");
		break;

		case "alc_2_prepare":
			LAi_SetSitType(pchar);
			LAi_SetActorType(characterFromID(pchar.quest.friend_in_tavern));
			LAi_ActorSetSitMode(characterFromID(pchar.quest.friend_in_tavern));
			
			switch(pchar.location)
			{
				case "Redmond_tavern":
					if (characters[GetCharacterIndex(pchar.quest.friend_in_tavern)].location.locator == "sit1")		
					{
						ChangeCharacterAddressGroup(pchar, "redmond_tavern", "sit", "sit11");
					}
					if (characters[GetCharacterIndex(pchar.quest.friend_in_tavern)].location.locator == "sit3")		
					{
						ChangeCharacterAddressGroup(pchar, "redmond_tavern", "sit", "sit2");
					}
				break;

				case "Oxbay_tavern":
					if (characters[GetCharacterIndex(pchar.quest.friend_in_tavern)].location.locator == "sit1")		
					{
						ChangeCharacterAddressGroup(pchar, "oxbay_tavern", "sit", "sit11");
					}
					if (characters[GetCharacterIndex(pchar.quest.friend_in_tavern)].location.locator == "sit3")		
					{
						ChangeCharacterAddressGroup(pchar, "oxbay_tavern", "sit", "sit2");
					}
				break;

				case "Greenford_tavern":
					if (characters[GetCharacterIndex(pchar.quest.friend_in_tavern)].location.locator == "sit5")		
					{
						ChangeCharacterAddressGroup(pchar, "greenford_tavern", "sit", "sit6");
					}
					if (characters[GetCharacterIndex(pchar.quest.friend_in_tavern)].location.locator == "sit1")		
					{
						ChangeCharacterAddressGroup(pchar, "greenford_tavern", "sit", "sit2");
					}	
				break;

				case "Falaise_De_Fleur_tavern":
							
				break;

				case "Muelle_tavern":
					if (characters[GetCharacterIndex(pchar.quest.friend_in_tavern)].location.locator == "sit1")		
					{
						ChangeCharacterAddressGroup(pchar, "muelle_tavern", "sit", "sit2");
					}
					if (characters[GetCharacterIndex(pchar.quest.friend_in_tavern)].location.locator == "sit7")		
					{
						ChangeCharacterAddressGroup(pchar, "muelle_tavern", "sit", "sit3");
					}			
				break;

				case "Douwesen_tavern":
					if (characters[GetCharacterIndex(pchar.quest.friend_in_tavern)].location.locator == "sit1")		
					{
						ChangeCharacterAddressGroup(pchar, "douwesen_tavern", "sit", "sit2");
					}
					if (characters[GetCharacterIndex(pchar.quest.friend_in_tavern)].location.locator == "sit7")		
					{
						ChangeCharacterAddressGroup(pchar, "douwesen_tavern", "sit", "sit3");
					}		
				break;

				case "Pirate_tavern":
					if (characters[GetCharacterIndex(pchar.quest.friend_in_tavern)].location.locator == "sit1")		
					{
						ChangeCharacterAddressGroup(pchar, "pirate_tavern", "sit", "sit2");
					}
					if (characters[GetCharacterIndex(pchar.quest.friend_in_tavern)].location.locator == "sit4")		
					{
						ChangeCharacterAddressGroup(pchar, "pirate_tavern", "sit", "sit2");
					}		
				break;

				case "Conceicao_tavern":
					if (characters[GetCharacterIndex(pchar.quest.friend_in_tavern)].location.locator == "sit1")		
					{
						ChangeCharacterAddressGroup(pchar, "conceicao_tavern", "sit", "sit2");
					}
					if (characters[GetCharacterIndex(pchar.quest.friend_in_tavern)].location.locator == "sit7")		
					{
						ChangeCharacterAddressGroup(pchar, "conceicao_tavern", "sit", "sit3");
					}
				break;

				case "Smugglers_tavern":
					if (characters[GetCharacterIndex(pchar.quest.friend_in_tavern)].location.locator == "sit5")		
					{
						ChangeCharacterAddressGroup(pchar, "smugglers_tavern", "sit", "sit6");
					}
					if (characters[GetCharacterIndex(pchar.quest.friend_in_tavern)].location.locator == "sit4")		
					{
						ChangeCharacterAddressGroup(pchar, "smugglers_tavern", "sit", "sit3");
					}	
				break;

				case "QC_tavern":
					if (characters[GetCharacterIndex(pchar.quest.friend_in_tavern)].location.locator == "sit1")		
					{
						ChangeCharacterAddressGroup(pchar, "QC_tavern", "sit", "sit2");
					}
					if (characters[GetCharacterIndex(pchar.quest.friend_in_tavern)].location.locator == "sit3")		
					{
						ChangeCharacterAddressGroup(pchar, "QC_tavern", "sit", "sit7");
					}		
				break;
			}
		break;

		case "alc2":
			LAi_ActorDialogNow(characterFromID(pchar.quest.friend_in_tavern), pchar, "", -1);
		break;

		case "exit_sit":
			if (CheckQuestAttribute("fight_in_tavern", "fight"))
			{
				pchar.quest.fight_in_tavern = "0";
				LAi_SetSitType(characterFromID(pchar.quest.friend_in_tavern));
			}
			else
			{
				if (pchar.location.group == "sit")
				{
					LAi_SetPlayerType(pchar);
					LAi_SetSitType(characterFromID(pchar.quest.friend_in_tavern));
					LAi_Fade("exit_sit_2", "");
				}
			}
		break;

		case "exit_sit_2":
			homelocation = pchar.quest.friend_in_tavern;
			LAi_SetSitType(characterFromID(homelocation));
			LAi_SetPlayerType(pchar);
			switch(pchar.location)
			{
				case "Redmond_tavern":
					LAi_group_MoveCharacter(characterFromID(pchar.quest.friend_in_tavern), "ENGLAND_CITIZENS");
					ChangeCharacterAddress(pchar, "redmond_tavern", "goto20"); 
				break;

				case "Oxbay_tavern":
					LAi_group_MoveCharacter(characterFromID(pchar.quest.friend_in_tavern), "ENGLAND_CITIZENS");
					ChangeCharacterAddress(pchar, "oxbay_tavern", "goto20");
				break;

				case "Greenford_tavern":
					LAi_group_MoveCharacter(characterFromID(pchar.quest.friend_in_tavern), "ENGLAND_CITIZENS");
					ChangeCharacterAddress(pchar, "Greenford_tavern", "goto5");
				break;

				case "Falaise_De_Fleur_tavern":
					LAi_group_MoveCharacter(characterFromID(pchar.quest.friend_in_tavern), "FRANCE_CITIZENS");
					ChangeCharacterAddress(pchar, "Falaise_de_fleur_tavern", "goto6");
				break;

				case "Muelle_tavern":
					LAi_group_MoveCharacter(characterFromID(pchar.quest.friend_in_tavern), "SPAIN_CITIZENS");
					ChangeCharacterAddress(pchar, "Muelle_tavern", "goto6");
				break;

				case "Douwesen_tavern":
					LAi_group_MoveCharacter(characterFromID(pchar.quest.friend_in_tavern), "DOUWESEN_CITIZENS");
					ChangeCharacterAddress(pchar, "Douwesen_tavern", "goto6");
				break;

				case "Pirate_tavern":
					LAi_group_MoveCharacter(characterFromID(pchar.quest.friend_in_tavern), "DOUWESEN_PIRATE_CITIZENS");
					ChangeCharacterAddress(pchar, "Pirate_tavern", "goto5");
				break;

				case "Conceicao_tavern":
					LAi_group_MoveCharacter(characterFromID(pchar.quest.friend_in_tavern), "CONCEICAO_CITIZENS");
					ChangeCharacterAddress(pchar, "Conceicao_tavern", "goto6");
				break;

				case "Smugglers_tavern":
					LAi_group_MoveCharacter(characterFromID(pchar.quest.friend_in_tavern), "SMUGGLERS_CITIZENS");
					ChangeCharacterAddress(pchar, "Smugglers_tavern", "goto5");
				break;

				case "QC_tavern":
					LAi_group_MoveCharacter(characterFromID(pchar.quest.friend_in_tavern), "QC_CITIZENS");
					ChangeCharacterAddress(pchar, "QC_tavern", "goto5");
				break;
			}
		break;

		case "kill_tavern_fightman_complete":
			LAi_SetStayType(pchar);
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], true);
			LAi_SetPlayerType(pchar);
		break;

		case "exit_from_douwesen_townhall_complete":
			LAi_ActorDialog(characterFromID("Lisebet Schefold"), pchar, "", 5.0, 1.0);
		break;

		case "sleep_in_tavern":
			//RecalculateJumpTable();
			DoQuestReloadToLocation(pchar.location + "_upstairs", "goto", "goto2", "restore_hp");
		break;

		case "OnUse_Idol": //используем статую идольскую.
			bMainMenuLaunchAfterVideo = true;
			PostVideoAndQuest("idol", 100, "OnUse_Idol_2");
		break;
		
		case "OnUse_Idol_2":
			PostEvent("DoInfoShower",100,"s","");
			deleteAttribute(&Locations[FindLocation("Labirint_3")], "models.always.koster");
			DoQuestReloadToLocation("Labirint_3", "item", "button01", "recharge_portals");
			Locations[FindLocation("Labirint_3")].reload.l28.disable = false;
		break;
		
		case "recharge_portals":			
			pchar.quest.first_portal.win_condition.l1 = "locator";
			pchar.quest.first_portal.win_condition.l1.location = "Treasure_alcove";
			pchar.quest.first_portal.win_condition.l1.locator_group = "teleport";
			pchar.quest.first_portal.win_condition.l1.locator = "teleport1";
			pchar.quest.first_portal.win_condition = "first_portal";
			
			pchar.quest.second_portal.win_condition.l1 = "locator";
			pchar.quest.second_portal.win_condition.l1.location = "Treasure_alcove";
			pchar.quest.second_portal.win_condition.l1.locator_group = "teleport";
			pchar.quest.second_portal.win_condition.l1.locator = "teleport2";
			pchar.quest.second_portal.win_condition = "second_portal";
			
			pchar.quest.third_portal.win_condition.l1 = "locator";
			pchar.quest.third_portal.win_condition.l1.location = "Treasure_alcove";
			pchar.quest.third_portal.win_condition.l1.locator_group = "teleport";
			pchar.quest.third_portal.win_condition.l1.locator = "teleport3";
			pchar.quest.third_portal.win_condition = "third_portal";
			
			pchar.quest.fourth_portal.win_condition.l1 = "locator";
			pchar.quest.fourth_portal.win_condition.l1.location = "Treasure_alcove";
			pchar.quest.fourth_portal.win_condition.l1.locator_group = "teleport";
			pchar.quest.fourth_portal.win_condition.l1.locator = "teleport4";
			pchar.quest.fourth_portal.win_condition = "fourth_portal";
			
			pchar.quest.fifth_portal.win_condition.l1 = "locator";
			pchar.quest.fifth_portal.win_condition.l1.location = "Treasure_alcove";
			pchar.quest.fifth_portal.win_condition.l1.locator_group = "teleport";
			pchar.quest.fifth_portal.win_condition.l1.locator = "teleport5";
			pchar.quest.fifth_portal.win_condition = "fifth_portal";
			
			pchar.quest.monster_portal.win_condition.l1 = "locator";
			pchar.quest.monster_portal.win_condition.l1.location = "Treasure_alcove";
			pchar.quest.monster_portal.win_condition.l1.locator_group = "teleport";
			pchar.quest.monster_portal.win_condition.l1.locator = "teleport0";
			pchar.quest.monster_portal.win_condition = "monster_portal";
		break;
		
		case "empting_portals":
			pchar.quest.first_portal.over = "yes";
			pchar.quest.second_portal.over = "yes";
			pchar.quest.third_portal.over = "yes";
			pchar.quest.fourth_portal.over = "yes";
			pchar.quest.fifth_portal.over = "yes";
			pchar.quest.monster_portal.over = "yes";
		break;
		
		case "first_portal":
			LAi_QuestDelay("empting_portals", 0.0);
			LAi_fade("teleport_1_2", "");
			PlayStereoSound("Ambient\INCA TEMPLE\teleporter.wav");
		break;
		
		case "second_portal":
			LAi_QuestDelay("empting_portals", 0.0);
			LAi_fade("teleport_2_1", "");
			PlayStereoSound("Ambient\INCA TEMPLE\teleporter.wav");
		break;
		
		case "third_portal":
			LAi_QuestDelay("empting_portals", 0.0);
			LAi_fade("teleport_3_4", "");
			PlayStereoSound("Ambient\INCA TEMPLE\teleporter.wav");
		break;
		
		case "fourth_portal":
			LAi_QuestDelay("empting_portals", 0.0);
			LAi_fade("teleport_4_3", "");
			PlayStereoSound("Ambient\INCA TEMPLE\teleporter.wav");
		break;
		
		case "fifth_portal":
			LAi_QuestDelay("empting_portals", 0.0);
			LAi_fade("teleport_5_treasure", "");
			PlayStereoSound("Ambient\INCA TEMPLE\teleporter.wav");
		break;
		
		case "teleport_1_2":
			ChangeCharacterAddress(characterFromID("danielle"), "Treasure_alcove", "teleport2_1");
			ChangeCharacterAddress(characterFromID("researcher"), "Treasure_alcove", "teleport2_2");
			ChangeCharacterAddressGroup(pchar, "Treasure_alcove", "teleport", "teleport2");
			LAi_QuestDelay("recharge_portals", 2.0);
		break;
		
		case "teleport_2_1":
			ChangeCharacterAddress(characterFromID("danielle"), "Treasure_alcove", "teleport1_1");
			ChangeCharacterAddress(characterFromID("researcher"), "Treasure_alcove", "teleport1_2");
			ChangeCharacterAddressGroup(pchar, "Treasure_alcove", "teleport", "teleport1");
			LAi_QuestDelay("recharge_portals", 2.0);
		break;
		
		case "teleport_3_4":
			ChangeCharacterAddress(characterFromID("danielle"), "Treasure_alcove", "teleport4_1");
			ChangeCharacterAddress(characterFromID("researcher"), "Treasure_alcove", "teleport4_2");
			ChangeCharacterAddressGroup(pchar, "Treasure_alcove", "teleport", "teleport4");
			LAi_QuestDelay("recharge_portals", 2.0);
		break;
		
		case "teleport_4_3":
			ChangeCharacterAddress(characterFromID("danielle"), "Treasure_alcove", "teleport3_1");
			ChangeCharacterAddress(characterFromID("researcher"), "Treasure_alcove", "teleport3_2");
			ChangeCharacterAddressGroup(pchar, "Treasure_alcove", "teleport", "teleport3");
			LAi_QuestDelay("recharge_portals", 2.0);
		break;
		
		case "teleport_5_treasure":
			ChangeCharacterAddress(characterFromID("danielle"), "Treasure_alcove", "teleport6_1");
			ChangeCharacterAddress(characterFromID("researcher"), "Treasure_alcove", "teleport6_2");
			ChangeCharacterAddressGroup(pchar, "Treasure_alcove", "teleport", "teleport6");
			//LAi_QuestDelay("recharge_portals", 1.0);
		break;
		
		case "monster_portal":
			//LAi_QuestDelay("empting_portals", 0.0);
			LAi_fade("", "monster_generate_in_alcove");
			PlayStereoSound("Ambient\INCA TEMPLE\teleporter.wav");
			LAi_QuestDelay("recharge_portals", 2.0);
		break;
		
		case "monster_generate_in_alcove":
			//ChangeCharacterAddressGroup(pchar, "Treasure_alcove", "teleport", "teleport0");
		
			LAi_group_SetLookRadius("monsters", 30.0);
			sld = LAi_CreateFantomCharacter("mummy", "goto", "monster1");
			LAi_group_MoveCharacter(sld, "monsters");
		
			sld = LAi_CreateFantomCharacter("mummy", "goto", "monster2");
			LAi_group_MoveCharacter(sld, "monsters");
			
			sld = LAi_CreateFantomCharacter("mummy", "goto", "monster3");
			//LAi_SetMonkeyType(sld);
			LAi_group_MoveCharacter(sld, "monsters");
			LAi_group_FightGroups("monsters", LAI_GROUP_PLAYER, true);
		break;

		//GENERATE
		case "generate_trade_quest":
			if (pchar.quest.generate_trade_quest_progress == "begin")
			{
				pchar.quest.generate_trade_quest_progress = "failed";
				Log_SetStringToLog(GlobalStringConvert("QUEST_MESSAGE2"));
				DoQuestCheckDelay("close_trade_quest", 0.0);
			}
		break;

		//NEW
		case "becomes_oldman":
			if (isEntity(&characters[0]))
			{
				GetCharacterPos(GetMainCharacter(), &locx, &locy, &locz);
				CreateParticleSystemX("blast", locx, locy, locz, locx, locy, locz,0);
			}
			Log_SetStringToLog(GlobalStringConvert("QUEST_MESSAGE3"));
			pchar.model = "skel1";
		break;

		case "alistar_garcilaso_money":
			AddMoneyToCharacter(pchar, -10000);
			GiveItem2Character(pchar, INCAS_COLLECTION);
			Group_SetAddress("Pirate Captain 06", "none", "Quest_Ships","Quest_Ship_9");
			pchar.quest.prepare_fighting_on_deck_complete.over = "yes";
			pchar.quest.main_line = "blaze_to_incas_collection_begin_8";
			AddQuestRecord("blaze_to_incas_collection", "13");
			AddPartyExp(pchar, 4000);
			SetCharacterShipLocation(&characters[GetCharacterIndex("Pirate Captain 05")], "none");
			characters[GetCharacterIndex("Robert Christopher Silehard")].dialog.CurrentNode = "incas_collection_complete_node";
		break;

		case "alistar_garcilaso_money_2":
			AddMoneyToCharacter(pchar, -8000);
			GiveItem2Character(pchar, INCAS_COLLECTION);
			Group_SetAddress("Pirate Captain 06", "none", "Quest_Ships","Quest_Ship_9");
			pchar.quest.main_line = "blaze_to_incas_collection_begin_8";
			AddQuestRecord("blaze_to_incas_collection", "13");
			SetCharacterShipLocation(&characters[GetCharacterIndex("Pirate Captain 05")], "none");
			AddPartyExp(pchar, 5000);
			characters[GetCharacterIndex("Robert Christopher Silehard")].dialog.CurrentNode = "incas_collection_complete_node";
		break;

		case "alistar_garcilaso_idols":
			GiveItem2Character(pchar, INCAS_COLLECTION);
			Group_SetAddress("Pirate Captain 06", "none", "Quest_Ships","Quest_Ship_9");
			pchar.quest.main_line = "blaze_to_incas_collection_begin_8";
			AddQuestRecord("blaze_to_incas_collection", "14");
			SetCharacterShipLocation(&characters[GetCharacterIndex("Pirate Captain 05")], "none");
			ChangeCharacterAddress(&characters[GetCharacterIndex("Danielle_sailor")], "none", "none");
			AddPartyExp(pchar, 6000);
			characters[GetCharacterIndex("Robert Christopher Silehard")].dialog.CurrentNode = "incas_collection_complete_node";
		break;

		case "alistar_garcilaso_idols_2":
			GiveItem2Character(pchar, INCAS_COLLECTION);
			Group_SetAddress("Pirate Captain 06", "none", "Quest_Ships","Quest_Ship_9");
			pchar.quest.main_line = "blaze_to_incas_collection_begin_8";
			AddQuestRecord("blaze_to_incas_collection", "14");
			AddPartyExp(pchar, 6000);
			SetCharacterShipLocation(&characters[GetCharacterIndex("Pirate Captain 05")], "none");
			ChangeCharacterAddress(&characters[GetCharacterIndex("Danielle_sailor")], "none", "none");
			characters[GetCharacterIndex("Robert Christopher Silehard")].dialog.CurrentNode = "incas_collection_complete_node";
		break;

		case "andre_juliao_fight_1":
			LAi_Fade("andre_find_locator", "andre_juliao_fight_2");
		break;
		
		case "andre_find_locator":
			homelocation = pchar.location;
			PlaceCharacter(characterFromID("andre juliao"), "goto", homelocation);
			LAi_SetWarriorType(characterFromID("andre juliao")); 
		break;
		
		case "andre_juliao_fight_2":
			LAi_LocationFightDisable(&Locations[FindLocation("Falaise_de_fleur_tavern")], false);
			LAi_group_MoveCharacter(characterFromID("andre juliao"), "FALAISE_SMUGGLER");
			LAi_group_FightGroups("FALAISE_SMUGGLER", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("FALAISE_SMUGGLER", "andre_juliao_fight_3");
		break;
		
		case "andre_juliao_fight_3":
			LAi_SetActorType(pchar);
			LAi_LocationFightDisable(&Locations[FindLocation("Falaise_de_fleur_tavern")], true);
			LAi_SetPlayerType(pchar);
		break;

		case "blaze_fighting_with_amiel_berangere":
			LAi_LocationFightDisable(&Locations[FindLocation("Falaise_de_fleur_tavern_upstairs")], false);
			//---Эмиль нападает на Блэйза
			LAi_SetImmortal(characterFromID("Amiel Berangere"), false); 
			LAi_ActorAttack(characterFromID("Amiel Berangere"), PChar, "");
			locations[FindLocation("Falaise_De_Fleur_tavern_upstairs")].reload.l1.disable = 1;
			//----Отключается локатор выхода из комнаты
			//-------Убимраем ненужного Фауста Гаске
			ChangeCharacterAddress(characterFromID("Faust Gasquet"), "None", "");
			
			Pchar.quest.Story_BlazeStartsThinkAboutGramota.win_condition.l1 = "NPC_death";
			Pchar.quest.Story_BlazeStartsThinkAboutGramota.win_condition.l1.character = "Amiel Berangere";
			Pchar.quest.Story_BlazeStartsThinkAboutGramota.win_condition = "Story_BlazeStartsThinkAboutGramota";
		break;

		case "Glover_exit":
			Pchar.Quest.Story_Ask_for_Glover.over = "yes";
			ChangeCharacterAddressGroup(characterFromID("Ewan Glover"), "Redmond_tavern", "reload", "reload1");
			LAi_SetActorType(characterFromID("Ewan Glover"));
			LAi_ActorDialog(characterFromID("Ewan Glover"), pchar, "", 50, 0);
		break;

		case "CounterSpy_Talk_AfterTavern_exit":
			AddQuestRecord("Story_2ndTask","11");
			Pchar.quest.Story_LeaveOxbayWithRabelAndCounterspy.win_condition.l1 = "location";
			Pchar.quest.Story_LeaveOxbayWithRabelAndCounterspy.win_condition.l1.location = "Oxbay_port";
			Pchar.quest.Story_LeaveOxbayWithRabelAndCounterspy.win_condition = "Story_LeaveOxbayWithRabelAndCounterspy";

			/*Pchar.quest.Story_RabelGoesToPort.win_condition.l1 = "locator";
			Pchar.quest.Story_RabelGoesToPort.win_condition.l1.character = "Rabel Iverneau";
			Pchar.quest.Story_RabelGoesToPort.win_condition.l1.location = "Oxbay_town";
			Pchar.quest.Story_RabelGoesToPort.win_condition.l1.locator_group = "reload";
			Pchar.quest.Story_RabelGoesToPort.win_condition.l1.locator = "reload1";
			Pchar.quest.Story_RabelGoesToPort.win_condition = "Story_RabelGoesToPort";
			
			Pchar.quest.Story_CounterspyGoesToPort.win_condition.l1 = "locator";
			Pchar.quest.Story_CounterspyGoesToPort.win_condition.l1.character = "Counterspy";
			Pchar.quest.Story_CounterspyGoesToPort.win_condition.l1.location = "Oxbay_town";
			Pchar.quest.Story_CounterspyGoesToPort.win_condition.l1.locator_group = "reload";
			Pchar.quest.Story_CounterspyGoesToPort.win_condition.l1.locator = "reload1";
			Pchar.quest.Story_CounterspyGoesToPort.win_condition = "Story_CounterspyGoesToPort";*/
			LAi_ActorRunToLocation(characterFromID("counterspy"), "reload", "reload1", "none", "", "", "", 45.0);
			LAi_ActorRunToLocation(characterFromID("Rabel Iverneau"), "reload", "reload1", "none", "", "", "", 45.0);
			ExchangeCharacterShip(characterFromID("Rabel Iverneau"), Pchar);
			ExchangeCharacterShip(characterFromID("Rabel Iverneau"), characterFromID("Ship Storage"));
			SetCharacterShipLocation(Pchar, "Oxbay_port");
			//LAi_ActorRunToLocator(characterFromID("Rabel Iverneau"), "reload", "reload1", "Story_RabelGoesToPort", 20.0.0); 
		break;

		case "Counterspy_Exit_fight":
			//----------Появление солдат в таверне
			LAi_group_SetRelation(LAI_DEFAULT_GROUP, "FRANCE_SOLDIERS", LAI_GROUP_NEITRAL);
			ChangeCharacterAddressGroup(characterFromID("Fra_arrester_01"), "Oxbay_Tavern", "Reload", "Reload1");
			ChangeCharacterAddressGroup(characterFromID("Fra_arrester_02"), "Oxbay_Tavern", "Reload", "Reload1");
			ChangeCharacterAddressGroup(characterFromID("Fra_arrester_03"), "Oxbay_Tavern", "Reload", "Reload1");

			LAi_SetActorType(characterFromID("Fra_arrester_01"));
			LAi_SetActorType(characterFromID("Fra_arrester_02"));
			LAi_SetActorType(characterFromID("Fra_arrester_03"));

			LAi_ActorFollow(characterFromID("Fra_arrester_02"), characterFromID("Fra_arrester_01"), "", 15.0); 
			LAi_ActorFollow(characterFromID("Fra_arrester_03"), characterFromID("Fra_arrester_01"), "", 15.0); 
			LAi_ActorDialog(characterFromID("Fra_arrester_01"), pchar, "", 10.0, 1.0); 
			LAi_Fade("Counterspy_Exit_fight_2", "");
		break;
		
		case "Counterspy_Exit_fight_2":
			PlaceCharacter(characterFromID("counterspy"), "goto", "Oxbay_tavern");
			LAi_SetOfficerType(characterFromID("counterspy"));
			LAi_SetImmortal(characterFromID("counterspy"), true);
		break;

		case "Counterspy_After_Fight_Exit":
			//-------------Заводится квест на попадание в верфь Оксбэя
			Pchar.quest.Story_Goto_Oxbay_shipyard_with_Counterspy.win_condition.l1 = "location";
			Pchar.quest.Story_Goto_Oxbay_shipyard_with_Counterspy.win_condition.l1.location = "Oxbay_shipyard";
			Pchar.quest.Story_Goto_Oxbay_shipyard_with_Counterspy.win_condition = "Story_Goto_Oxbay_shipyard_with_Counterspy";

			//-------------Заводится квест на Попытку сбежать из города в джунгли
			Pchar.quest.Story_PlayerTriesToRunFromOxbay.win_condition.l1 = "location";
			Pchar.quest.Story_PlayerTriesToRunFromOxbay.win_condition.l1.location = "Oxbay_town_exit";
			Pchar.quest.Story_PlayerTriesToRunFromOxbay.win_condition = "Story_PlayerTriesToRunFromOxbay";
			
			//-----------Присоединение шпиона в качестве офицера		
			SetOfficersIndex(Pchar, 3, GetCharacterIndex("CounterSpy"));
			SetCharacterRemovable(characterFromID("Counterspy"), false);
			LAi_SetActorType(characterFromID("Oweyn McDorey"));
			ChangeCharacterAddress(characterFromID("Oweyn McDorey"), "Oxbay_Shipyard", "Goto8");
		break;

		case "CounterSpy_Ready_for_meeting_exit":
			SetCharacterRemovable(characterFromID("Counterspy"), true);
			RemovePassenger(Pchar, getCharacterIndex("Counterspy"));
			StorePassengers(pchar.id);
			LAi_SetSitType(characterFromID("Rabel Iverneau"));
			LAi_SetImmortal(characterFromID("Rabel Iverneau"), true);
			SetCharacterShipLocation(&Characters[GetCharacterIndex("Rabel Iverneau")], "Oxbay_port");
			ChangeCharacterAddressGroup(characterfromID("Rabel Iverneau"), "Oxbay_tavern", "Sit", "Sit4");
		break;

		case "counterspy_Officer_money_exit":
			LAi_Fade("counterspy_Officer_money_exit_2", "Story_WaitingForEveningInTheShipyard");
		break;

		case "counterspy_Officer_money_exit_2":
			SetCurrentTime(22, 0);
			//WaitDate("",0,0,0,0,1);
			LAi_SetSitType(characterfromID("Oweyn McDorey"));
			ChangeCharacterAddressGroup(characterFromID("Oweyn McDorey"), "Oxbay_shipyard", "Sit", "Sit_1");
		break;

		case "arrest_in_tavern_for_fra_occupants":
			LAi_LocationFightDisable(&Locations[FindLocation("Oxbay_tavern")], false);
			LAi_SetWarriorType(characterFromID("Fra_arrester_01"));
			LAi_SetWarriorType(characterFromID("Fra_arrester_02"));
			LAi_SetWarriorType(characterFromID("Fra_arrester_03"));
			LAi_group_MoveCharacter(characterFromID("Fra_arrester_01"), "FRANCE_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("Fra_arrester_02"), "FRANCE_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("Fra_arrester_03"), "FRANCE_SOLDIERS");
			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, true);
			
			LAi_group_SetCheck("FRANCE_SOLDIERS", "Story_KillFrenchArresters");
			LAi_SetImmortal(characterFromID("Counterspy"), true);
		break;

		case "Yedam_kinne_attack":
			AddQuestRecord("church_help", "11");
			LAi_group_MoveCharacter(characterFromID("Yedam Kinne"), "YedamKine");
			LAi_SetActorType(characterFromID("Yedam Kinne"));
			LAi_ActorAttack(characterFromID("Yedam Kinne"), pchar, "");
			characters[GetCharacterIndex("Father bernard")].quest.church_help = "bad_dautch";
		break;

		case "vincent_exit_from_tavern":
			LAi_ActorGoToLocator(characterFromID("Vincent bethune"), "reload", "reload1", "vincent_away_from_tavern_complete", 90.0);
			pchar.quest.main_line = "vincent_away_from_douwesen_tavern";
		break;

		case "turpin_cabanel_story_exit":
			AddQuestRecord("Story_1stTaskReceived", "11");
			pchar.quest.turpin_cabanel_story_exit_2.win_condition.l1 = "location";
			pchar.quest.turpin_cabanel_story_exit_2.win_condition.l1.location = "Falaise_de_fleur_port_01";
			pchar.quest.turpin_cabanel_story_exit_2.win_condition = "turpin_cabanel_story_exit_2";
		break;
		
		case "turpin_cabanel_story_exit_2":
			LAi_SetCitizenType(characterFromID("Tancrede Rimbaud"));
			LAi_type_actor_Reset(characterFromID("Virgile Boon"));
			LAi_ActorDialog(characterFromID("Virgile Boon"), Pchar, "", 25.0, 1.0);
		break;

		case "turpin_cabanel_fight":
			LAi_group_MoveCharacter(characterFromID("Turpin Cabanel"), "FRANCE_SOLDIERS");
			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			SetNationRelation2MainCharacter(FRANCE, RELATION_ENEMY);
			ChangeCharacterReputation(pchar, -2);
		break;

		case "prepare_thierry_bosquet_fight":
			LAi_SetActorType(characterFromID("thierry bosquet"));
			LAi_SetActorType(characterFromID("France_bukaner_01"));
			ChangeCharacterAddress(characterFromID("thierry bosquet"), "Falaise_de_Fleur_jungle", "locator5");
			ChangeCharacterAddress(characterFromID("France_bukaner_01"), "Falaise_de_Fleur_jungle", "locator6");
			LAi_ActorDialog(characterFromID("thierry bosquet"), pchar, "", 3.0, 1.0);
			LAi_ActorFollow(characterFromID("France_bukaner_01"), pchar, "", 5.0);
			LAi_SetCheckMinHP(characterFromID("thierry bosquet"), 79.0, false, "thierry_bosquet_fight");
			LAi_SetCheckMinHP(characterFromID("France_bukaner_01"), 79.0, false, "thierry_bosquet_fight");
		break;

		case "thierry_bosquet_fight":
			LAi_RemoveCheckMinHP(characterFromID("thierry bosquet"));
			LAi_RemoveCheckMinHP(characterFromID("France_bukaner_01"));
			LAi_group_MoveCharacter(characterFromID("thierry bosquet"), "FRANCE_BUKANERS");
			LAi_group_MoveCharacter(characterFromID("France_bukaner_01"), "FRANCE_BUKANERS");
			LAi_group_FightGroups("FRANCE_BUKANERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("FRANCE_BUKANERS", "thierry_bosquet_fight_completed");
		break;
		
		case "thierry_bosquet_fight_completed":
			GiveItem2Character(pchar, "blade7");
		break;

		case "thomas_contraband_exit":
			LAi_SetHP(characterFromID("Stephan Bonser"), 80.0, 80.0);
			LAi_SetHP(characterFromID("Oswald Chappel"), 80.0, 80.0);
			LAi_SetHP(characterFromID("Gyles Dubois"), 80.0, 80.0);
			LAi_SetCheckMinHP(characterFromID("Stephan Bonser"), 79.0, false, "stephan_bonser_attack");
			LAi_SetCheckMinHP(characterFromID("Oswald Chappel"), 79.0, false, "stephan_bonser_attack");
			LAi_SetCheckMinHP(characterFromID("Gyles Dubois"), 79.0, false, "stephan_bonser_attack");
			ChangeCharacterAddress(characterFromID("Stephan Bonser"), "Redmond_Shore_02", "goto4");
			ChangeCharacterAddress(characterFromID("Oswald Chappel"), "Redmond_Shore_02", "goto6");
			ChangeCharacterAddress(characterFromID("Gyles Dubois"), "Redmond_Shore_02", "goto5"); 
			SetQuestHeader("Thomas_O'Reily_contraband");
			AddQuestRecord("Thomas_O'Reily_contraband", "1");
		break;

		case "thomas_contraband_12_exit":
			AddQuestRecord("Thomas_O'Reily_contraband", "3");
			AddCharacterGoods(characterFromID("Pirate Captain 04"),GOOD_EBONY,100);
			pchar.quest.thomas_contraband_12_exit_2.win_condition.l1 = "location";
			pchar.quest.thomas_contraband_12_exit_2.win_condition.l1.location = "Redmond";
			pchar.quest.thomas_contraband_12_exit_2.win_condition = "thomas_contraband_12_exit_2";
		break;

		case "thomas_contraband_12_exit_2":
			bQuestDisableMapEnter = true;
			Island_SetReloadEnableGlobal("Redmond", false);

			Group_CreateGroup("Smugglers_squadron2");
			Group_AddCharacter("Smugglers_squadron2", "Pirate Captain 04");
			Group_SetGroupCommander("Smugglers_squadron2", "Pirate Captain 04");

			Group_SetPursuitGroup("Smugglers_squadron2", PLAYER_GROUP);
			Group_SetTaskAttack("Smugglers_squadron2", PLAYER_GROUP);
			Group_SetAddress("Smugglers_squadron2", Characters[GetMainCharacterIndex()].location, "", "");

			SetCharacterRelation(GetCharacterIndex("Pirate Captain 04"),GetMainCharacterIndex(),RELATION_ENEMY);

			UpdateRelations();

			pchar.quest.boarding_smuggler_ship.win_condition.l1 = "Character_Capture";
			pchar.quest.boarding_smuggler_ship.win_condition.l1.character = "Pirate Captain 04";
			pchar.quest.boarding_smuggler_ship.win_condition = "boarding_smuggler_ship";

			pchar.quest.sink_smuggler_ship.win_condition.l1 = "NPC_Death";
			pchar.quest.sink_smuggler_ship.win_condition.l1.character = "Pirate Captain 04";
			pchar.quest.sink_smuggler_ship.win_condition = "sink_smuggler_ship";
		break;

		case "boarding_smuggler_ship":
			bQuestDisableMapEnter = false;
			Island_SetReloadEnableGlobal("Redmond", true);
			characters[GetCharacterIndex("Thomas O'Reily")].quest.contraband = "boarding";
		break;

		case "sink_smuggler_ship":
			bQuestDisableMapEnter = false;
			Island_SetReloadEnableGlobal("Redmond", true);
		break;

		case "stephan_bonser_attack":
			LAi_RemoveCheckMinHP(characterFromID("Stephan Bonser"));
			LAi_RemoveCheckMinHP(characterFromID("Oswald Chappel"));
			LAi_RemoveCheckMinHP(characterFromID("Gyles Dubois"));

			LAi_SetActorType(characterFromID("Stephan Bonser"));
			LAi_SetActorType(characterFromID("Oswald Chappel"));
			LAi_SetActorType(characterFromID("Gyles Dubois"));

			AddQuestRecord("Thomas_O'Reily_contraband", "2");
			LAi_ActorAttack(characterFromID("stephan bonser"), pchar, "");
			LAi_ActorAttack(characterFromID("Oswald Chappel"), pchar, "");
			LAi_ActorAttack(characterFromID("Gyles Dubois"), pchar, "");
			pchar.quest.exit_from_redmond_shore_02.win_condition.l1 = "location";
			pchar.quest.exit_from_redmond_shore_02.win_condition.l1.location = "Redmond";
			pchar.quest.exit_from_redmond_shore_02.win_condition = "quest_exit_from_redmond_shore_02_complete";
			characters[GetCharacterIndex("Thomas O'Reily")].quest.contraband = "after_fight";
		break;

		case "quest_exit_from_redmond_shore_02_complete":
			Group_CreateGroup("Smugglers_squadron");
			Group_AddCharacter("Smugglers_squadron", "Pirate Captain 01");
			Group_AddCharacter("Smugglers_squadron", "Pirate Captain 02");
			Group_AddCharacter("Smugglers_squadron", "Pirate Captain 03");
			Group_SetGroupCommander("Smugglers_squadron", "Pirate Captain 01");

			Group_SetPursuitGroup("Smugglers_squadron", PLAYER_GROUP);
			Group_SetTaskAttack("Smugglers_squadron", PLAYER_GROUP);
			Group_SetAddress("Smugglers_squadron", Characters[GetMainCharacterIndex()].location, "", "");

			SetCharacterRelation(GetCharacterIndex("Pirate Captain 01"),GetMainCharacterIndex(),RELATION_ENEMY);

			UpdateRelations();
		break;

		case "researcher_I_go_to_the_right_exit":
			LAi_SetActorType(pchar);
			RemovePassenger(Pchar, characterFromID("Researcher"));
			LAi_SetActorType(characterFromID("Researcher"));
			characters[GetCharacterIndex("researcher")].location = "labirint1";
			LAi_ActorRunToLocator(characterFromID("researcher"), "goto", "goto2", "", 25.0);
			Characters[GetCharacterIndex("researcher")].Dialog.CurrentNode = "First time";
			LAi_ActorRunToLocator(pchar, "goto", "goto11", "Story_TimeToGoIntoCentralPassage", 15.0);
		break;

		case "researcher_split_exit":
			Characters[GetCharacterIndex("Danielle")].Dialog.CurrentNode = "I'm going on left";
			LAi_ActorDialog(characterFromID("Danielle"), pchar, "", 30.0, 5);
		break;
				
		case "Speak_with_lighthouse_guards":
			LAi_SetActorType(characterFromID("lighthouse_officer"));
			LAi_SetActorType(pchar);
			LAi_ActorFollow(pchar, characterFromID("lighthouse_officer"), "", 2.0);
			LAi_ActorFollow(characterFromID("lighthouse_officer"), pchar, "Speak_with_lighthouse_guards_2", 2.0);
		break;
		
		case "Speak_with_lighthouse_guards_2":
			LAi_type_actor_Reset(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("lighthouse_officer"));
			LAi_ActorDialog(characterFromID("lighthouse_officer"), pchar, "pchar_back_to_player", 2.0, 1.0);
		break;

		case "researcher_captured_exit_fight":
			LAi_group_MoveCharacter(characterFromID("lighthouse_officer"), "LIGHTHOUSE_SOLDIERS");
			LAi_group_SetHearRadius("LIGHTHOUSE_SOLDIERS", 30.0);
			LAi_group_FightGroups("LIGHTHOUSE_SOLDIERS", LAI_GROUP_PLAYER, true);
		break;

		case "fight_with_soldier_for_drink":
			LAi_group_FightGroups(pchar.friend_in_tavern2, LAI_GROUP_PLAYER, true);
		break;

		case "raoul_calmes_fight":
			LAi_SetActorType(characterFromID("raoul calmes"));
			LAi_ActorAttack(characterfromID("raoul calmes"), pchar, "");
			characters[GetCharacterIndex("Turpin Cabanel")].quest.smugglers = "letters_1";
		break;

		case "rabel_yverneau_exit_run":
			LAi_QuestDelay("rabel_yverneau_exit_run_1", 1.2);
		break;

		case "rabel_yverneau_exit_run_1":
			LAi_SetImmortal(characterFromID("counterspy"), true);
			LAi_SetImmortal(characterFromID("rabel Iverneau"), true);
			
			AddPassenger(Pchar, characterFromID("Rabel Iverneau"), 0);
			AddPassenger(Pchar, characterFromID("Counterspy"), 0);

			Characters[getCharacterIndex("Fra_occupant_05")].dialog.Filename = "Story_French Occupant_dialog.c";
			Characters[getCharacterIndex("Fra_occupant_06")].dialog.Filename = "Story_French Occupant_dialog.c";

			LAi_type_actor_Reset(characterFromID("Rabel Iverneau"));
			LAi_type_actor_Reset(characterFromID("counterspy"));

			LAi_ActorRunToLocation(characterFromID("counterspy"), "reload", "reload2_back", "none", "", "", "Story_Follow_Rabel_And_Counterspy", 30.0);
			LAi_ActorRunToLocation(characterFromID("Rabel Iverneau"), "reload", "reload2_back", "none", "", "", "Story_Follow_Rabel_And_Counterspy", 30.0);

			LAi_group_MoveCharacter(characterFromID("Fra_occupant_05"), "FRANCE_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("Fra_occupant_06"), "FRANCE_SOLDIERS");

			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, true);

			LAi_QuestDelay("rabel_yverneau_exit_run_2", 7.0);
		break;

		case "rabel_yverneau_exit_run_2":			
			sld = LAi_CreateFantomCharacter("Soldier_fra", "reload", "reload1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			
			sld = LAi_CreateFantomCharacter("Soldier_fra2", "reload", "reload1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			
			sld = LAi_CreateFantomCharacter("Soldier_fra3", "reload", "reload1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			
			sld = LAi_CreateFantomCharacter("Soldier_fra4", "reload", "reload1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			
			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, true);
		break;

		case "blaze_exit_to_machado":
			DoQuestReloadToLocation("Smugglers_residence", "reload", "reload1", "blaze_first_speak_with_machado_complete");
		break;

		case "quest_pirate_01_exit_go_one":
			AddQuestRecord("blaze_to_incas_collection", "2");
			pchar.quest.main_line = "blaze_to_incas_collection_begin_5";
			pchar.quest.go_to_pirate_fort_fight.win_condition.l1 = "location";
			pchar.quest.go_to_pirate_fort_fight.win_condition.l1.location = "Douwesen_jungle_03";
			pchar.quest.go_to_pirate_fort_fight.win_condition = "go_to_pirate_fort_fight_complete";
		break;

		case "quest_pirate_01_exit_with_fight":
			LAi_ActorAttack(characterFromID("quest_pirate_01"), pchar, "");
			AddQuestRecord("blaze_to_incas_collection", "4");
		break;

		case "quest_pirate_01_exit_from_fort":
			LAi_ActorGoToLocator(characterFromID("quest_pirate_01"), "reload", "reload1", "pirate_go_to_jungle_complete", 120.0);
		break;

		case "Pieter_nolt_fight":
			LAi_group_FightGroups("DOUWESEN_PIRATE_SOLDIERS", LAI_GROUP_PLAYER, true);
			pchar.quest.pirates_becomes_neutral.win_condition.l1 = "location";
			pchar.quest.pirates_becomes_neutral.win_condition.l1.location = "Douwesen";
			pchar.quest.pirates_becomes_neutral.win_condition = "pirates_becomes_neutral";
		break;
		
		case "pirates_becomes_neutral":
			LAi_group_SetRelation("DOUWESEN_PIRATE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_NEITRAL);
		break;

		case "miner_again_kick_exit":
			LAi_SetStayType(characterFromID("leborio drago"));
			LAi_setActorType(characterFromID("Mine_soldier_01"));
			LAi_ActorDialog(characterFromID("Mine_soldier_01"), pchar, "", 3.0, 5);
		break;

		case "mine_soldier_resque_exit":
			pchar.quest.main_line = "resque_from_mine_step_one";
			LAi_SetActorType(characterFromID("Mine_soldier_01"));
			LAi_ActorGoToLocator(characterFromID("Mine_soldier_01"), "reload", "reload1", "soldier_goto_to_mine_commander", 45.0);
			pchar.quest.main_line = "soldier_to_mine_commander_resque";
		break;

		case "mine_commander_resque_exit":			
			LAi_ActorGoToLocator(characterFromID("Mine_commander"), "reload", "reload1", "commendant_exit_from_mines_complete", 45.0);
			pchar.quest.main_line = "talk_with_Liborio";
		break;

		case "mine_commander_resque_denied_exit":
			LAi_ActorGoToLocator(characterFromID("Mine_commander"), "reload", "reload1", "commendant_exit_2_from_mines_complete", 45.0);
			
			pchar.quest.main_line = "resque_from_mines_denied";
			AddQuestRecord("search_danielle", "14");
		break;

		case "lucient_bescanceny_fight":
			LAi_setActorType(characterFromID("lucien bescanceny"));
			LAi_ActorAttack(characterfromID("lucien bescanceny"), pchar, "");
		break;

		case "leborio_drago_passenger_exit":
			AddPassenger(pchar, characterFromID("leborio drago"), -1);
			LAi_SetOfficerType(characterFromID("leborio drago"));

			pchar.quest.hired_leborio.win_condition.l1 = "location";
			pchar.quest.hired_leborio.win_condition.l1.location = "Oxbay";
			pchar.quest.hired_leborio.win_condition = "hired_leborio_complete";
		break;

		case "leborio_drago_fight_exit":
			LAi_ActorAttack(characterFromID("leborio drago"), pchar, "");
		break;

		case "leaving_oxbay_exit_no_run":
			Characters[getCharacterIndex("Fra_occupant_05")].dialog.Filename = "Story_French Occupant_dialog.c";
			Characters[getCharacterIndex("Fra_occupant_06")].dialog.Filename = "Story_French Occupant_dialog.c";
			
			LAi_type_actor_Reset(characterFromID("Counterspy"));
			LAi_type_actor_Reset(characterFromID("Rabel Iverneau"));
			LAi_ActorRunToLocation(characterFromID("Counterspy"), "reload", "reload2_back", "none", "", "", "Story_Follow_Rabel_And_Counterspy", 30.0);
			LAi_ActorRunToLocation(characterFromID("Rabel Iverneau"), "reload", "reload2_back", "none", "", "", "Story_Follow_Rabel_And_Counterspy", 30.0);

			AddPassenger(Pchar, characterFromID("Rabel Iverneau"), 0);
			AddPassenger(Pchar, characterFromID("Counterspy"), 0);
			LAi_QuestDelay("Story_CapturedByHotPursuit", 6.0);
		break;

		case "joseph_claude_le_mougne_english_war_ship":
			characters[GetCharacterIndex("joseph claude le moigne")].quest.english_war_ship = "1";

			SetCharacterRelation(GetCharacterIndex("Eng Captain Near FdF"),GetMainCharacterIndex(),RELATION_ENEMY);
			SetCharacterRelation(GetCharacterIndex("FalaiseDeFleur Commander"),GetCharacterIndex("Eng Captain Near FdF"),RELATION_ENEMY);
			
			Group_CreateGroup("Eng Captain Near FdF");
			Group_AddCharacter("Eng Captain Near FdF", "Eng Captain Near FdF");
			Group_SetGroupCommander("Eng Captain Near FdF", "Eng Captain Near FdF");
			Group_SetAddress("Eng Captain Near FdF", "FalaisedeFleur", "Quest_Ships","Quest_Ship_12");
			Group_SetTaskAttack("Eng Captain Near FdF", PLAYER_GROUP);

			UpdateRelations();

			SetQuestHeader("Hire_by_france_for_defeat_england_corvette");
			AddQuestRecord("Hire_by_france_for_defeat_england_corvette", "1");
			pchar.quest.killing_pirate_near_fdf.win_condition.l1 = "NPC_death";
			pchar.quest.killing_pirate_near_fdf.win_condition.l1.character = "Eng Captain Near FdF";
			pchar.quest.killing_pirate_near_fdf.win_condition = "killing_pirate_near_fdf";
		break;

		case "killing_pirate_near_fdf":
			characters[getCharacterindex("Joseph Claude Le Moigne")].quest.english_war_ship = "2";
		break;

		case "greenford_citizen_01_researcher_good_exit":
			AddQuestRecord("resque_researcher", "1");
			pchar.quest.main_line = "resque_researcher_good";
			LAi_ActorGoToLocator(characterFromID("greenford_citizen_01"), "reload", "reload1", "", 90.0);
		break;

		case "greenford_citizen_01_researcher_bad_exit":
			pchar.quest.prepare_fighting_on_deck_complete.over = "yes";
			AddQuestRecord("resque_researcher", "2");
			pchar.quest.main_line = "resque_researcher_bad";
			LAi_SetActorType(characterFromID("murderer_in_greenford_04"));
			LAi_SetActorType(pchar);
			LAi_ActorFollow(pchar, characterFromID("murderer_in_greenford_04"), "", 3.0);
			LAi_ActorFollow(characterFromID("murderer_in_greenford_04"), pchar, "greenford_citizen_01_researcher_bad_exit_2", 3.0);
		break;
		
		case "greenford_citizen_01_researcher_bad_exit_2":
			LAi_type_actor_Reset(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("murderer_in_greenford_04"));
			LAi_ActorDialog(characterFromID("murderer_in_greenford_04"), pchar, "", 1.0, 1.0);
			LAi_ActorGoToLocator(characterFromID("greenford_citizen_01"), "reload", "reload1", "", 9.0);
			OfficersReaction("bad");
		break;

		case "Greenford_commander_fight_exit":
			LAi_LocationFantomsGen(&locations[FindLocation("Greenford_prison")], false);
			LAi_NoRebirthEnable(characterFromID("Greenford Prison Commendant"));
			LAi_NoRebirthEnable(characterFromID("Eng_soldier_38"));
			LAi_NoRebirthEnable(characterFromID("Eng_soldier_39"));
			
			characters[getCharacterIndex("Greenford Commander")].skill.accuracy = "2";
			characters[getCharacterIndex("Greenford Commander")].skill.cannons = "3";
			LAi_SetImmortal(characterFromID("Greenford Commander"), true);
			LAi_LocationFightDisable(&Locations[FindLocation("Greenford_prison")], false);
			bQuestDisableMapEnter = true;
			Island_SetReloadEnableGlobal("Oxbay", false);
			pchar.quest.main_line = "return_idol_from_greenford_1";

			AddQuestRecord("Revenge_for_Silehard", "7");
			//выставляем англию враждебной.
			LAi_group_SetRelation("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			
			LAi_group_FightGroups("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("ENGLAND_SOLDIERS", "prepare_escape_from_greenford");
					
			Group_CreateGroup("Idol_Squadron");
			Group_AddCharacter("Idol_Squadron", "Eng Captain Idol");
			Group_SetGroupCommander("Idol_Squadron", "Eng Captain Idol");
			Group_SetTaskAttack("Idol_Squadron", PLAYER_GROUP);
			Group_SetAddress("Idol_Squadron", "Oxbay", "Quest_Ships","Quest_Ship_23");
			Group_LockTask("Idol_Squadron");
			
			pchar.quest.escape_from_greenford.win_condition.l1 = "location";
			pchar.quest.escape_from_greenford.win_condition.l1.location = "Oxbay";
			pchar.quest.escape_from_greenford.win_condition = "escape_from_greenford";
			
			pchar.quest.escape_from_greenford.win_condition.l1 = "ExitFromLocation";
			pchar.quest.escape_from_greenford.win_condition.l1.location = "Greenford_prison";
			pchar.quest.escape_from_greenford.win_condition = "prepare_escape_from_greenford";

			pchar.quest.return_idol_from_frigate.win_condition.l1 = "Character_Capture";
			pchar.quest.return_idol_from_frigate.win_condition.l1.character = "Eng Captain Idol";
			pchar.quest.return_idol_from_frigate.win_condition = "return_idol_from_frigate_complete";
			pchar.quest.return_idol_from_frigate1.win_condition.l1 = "NPC_Death";
			pchar.quest.return_idol_from_frigate1.win_condition.l1.character = "Eng Captain Idol";
			pchar.quest.return_idol_from_frigate1.win_condition = "return_idol_from_frigate_complete";
		break;
		
		case "prepare_escape_from_greenford":
			LAi_group_SetRelation("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
			LAi_group_SetRelation("ENGLAND_CITIZENS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
			SetNationRelation2MainCharacter(ENGLAND,RELATION_ENEMY);
		break;
		
		case "escape_from_greenford":
			LAi_group_SetRelation("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			SetNationRelation2MainCharacter(ENGLAND,RELATION_ENEMY);
		break;

		case "Gervasio_Serrao_fight_again":
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
			LAi_ActorAttack(characterFromID("Gervasio Serrao"), pchar, "");
			pchar.quest.killing_gervasio.win_condition.l1 = "NPC_Death";
			pchar.quest.killing_gervasio.win_condition.l1.character = "Gervasio Serrao";
			pchar.quest.killing_gervasio.win_condition = "killing_gervasio";
		break;

		case "killing_gervasio":
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], true);
			LAi_group_SetRelation(LAI_GROUP_PLAYER, LAI_DEFAULT_GROUP, LAI_GROUP_FRIEND);
			LAi_group_SetRelation(LAI_GROUP_PLAYER, "DOUWESEN_PIRATE_CITIZENS", LAI_GROUP_FRIEND);
			LAi_group_SetRelation(LAI_GROUP_PLAYER, "DOUWESEN_PIRATE_CITIZENS", LAI_GROUP_FRIEND);
		break;

		case "french_patrol_fight_exit":
			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
		break;

		case "found_blaze_exit_1":
			Characters[makeint(Pchar.Temp.Officer.idx2)].Dialog.CurrentNode = "Miracle";
			LAi_type_actor_Reset(&Characters[makeint(Pchar.Temp.Officer.idx2)]);
			LAi_ActorDialog(&Characters[makeint(Pchar.Temp.Officer.idx2)], PChar, "", 3.0, 1.0);
		break;

		case "found_blaze_exit_2":
			Characters[makeint(Pchar.Temp.Officer.idx3)].Dialog.CurrentNode = "Miracle_1";
			LAi_type_actor_Reset(&Characters[makeint(Pchar.Temp.Officer.idx3)]);
			LAi_ActorDialog(&Characters[makeint(Pchar.Temp.Officer.idx3)], PChar, "", 3.0, 1.00);
		break;

		case "found_blaze_exit_3":
			iPassenger = makeint(Pchar.Temp.Officer.idx1);
			Characters[iPassenger].Dialog.CurrentNode = "Miracle_2";
			LAi_SetActorType(&Characters[iPassenger]);
			LAi_ActorDialog(&Characters[iPassenger], PChar, "", 3.0, 1.0);
		break;

		case "found_blaze_Exit_in_Tavern_1":
			iPassenger = makeint(Pchar.Temp.Officer.idx2);
			Characters[iPassenger].Dialog.CurrentNode = "Talk_in_tavern_1";
			LAi_ActorDialogNow(&Characters[iPassenger], PChar, "", 1.0);
		break;

		case "found_blaze_Exit_in_Tavern_2":
			iPassenger = makeint(Pchar.Temp.Officer.idx1);
			Characters[iPassenger].Dialog.CurrentNode = "Talk_in_tavern_2";
			LAi_ActorDialogNow(&Characters[iPassenger], PChar, "", 1.0);
			ChangeCharacterAddressGroup(characterFromID("Danielle"), "Muelle_tavern", "Reload", "Reload2");
			LAi_SetActorType(characterFromID("danielle"));
			LAi_ActorRunToLocator(characterFromID("danielle"), "goto", "goto6", "found_blaze_Exit_Danielle", 10.0);
		break;

		case "father_bernard_church_help_bad_2":
			AddDialogExitQuest("father_bernard_church_help_bad_2");
			characters[getCharacterIndex("father bernard")].quest.church_help = "done";
			AddQuestRecord("church_help", "14");
			CloseQuestHeader("church_help");
			AddMoneyToCharacter(pchar, 2500);
			AddPartyExp(pchar, 3000);
			ChangeCharacterAddress(characterFromID("Father Jerald"), "none", "none");
			ChangeCharacterAddress(characterFromID("Gilbert Ballester"), "Greenford_Church", "goto11");
			LAi_SetStayType(characterFromID("Gilbert Ballester"));
			TakeItemFromCharacter(pchar, LOVE_LETTERS_OF_PRIEST);
		break;

		case "ewan_glover_Exit_to_port_of_Redmond":
			LAi_ActorRunToLocator(characterFromID("Ewan Glover"), "reload", "reload_from_port", "", 45.0);
		break;

		case "edgar_attwood_exit_from_blaze":
			pchar.quest.main_line = "inside_redmond_prison";
			LAi_ActorGoToLocator(characterFromID("Edgar Attwood"), "goto", "goto13", "wait_for_night_in_prison_complete", 30.0);
		break;

		case "anacleto_rui_sa_pinto_bad_swimming_in_oxbay_good_2":
			AddQuestrecord("Where_are_i", "9");
			LAi_SetImmortal(characterFromID("Anacleto Rui Sa Pinto"), false); 
			LAi_SetActorType(characterFromID("anacleto rui sa pinto"));
			LAi_ActorAttack(characterFromID("anacleto rui sa pinto"), pchar, "");
			pchar.quest.kill_anacleto.win_condition.l1 = "NPC_death";
			pchar.quest.kill_anacleto.win_condition.l1.character = "anacleto rui sa pinto";
			pchar.quest.kill_anacleto.win_condition = "kill_anacleto_complete_2";
		break;

		case "anacleto_rui_sa_pinto_fight_exit":
			LAi_SetImmortal(characterFromID("Anacleto Rui Sa Pinto"), false); 
			CloseQuestHeader("Where_are_i");
			LAi_Fade("anacleto_rui_sa_pinto_fight_exit_2", "anacleto_rui_sa_pinto_fight_exit_3");
		break;

		case "anacleto_rui_sa_pinto_fight_exit_2":
			LAi_SetImmortal(characterFromID("Anacleto Rui Sa Pinto"), false); 
			LAi_LocationFightDisable(&locations[Findlocation("pirate_tavern")], false);
			ChangeCharacterAddress(characterFromID("anacleto rui sa pinto"), "Pirate_tavern", "goto6");
		break;

		case "anacleto_rui_sa_pinto_fight_exit_3":
			LAi_SetImmortal(characterFromID("Anacleto Rui Sa Pinto"), false); 
			LAi_SetActorType(characterFromID("anacleto rui sa pinto"));
			LAi_ActorAttack(characterFromID("anacleto rui sa pinto"), pchar, "");
			pchar.quest.kill_anacleto.win_condition.l1 = "NPC_death";
			pchar.quest.kill_anacleto.win_condition.l1.character = "anacleto rui sa pinto";
			pchar.quest.kill_anacleto.win_condition = "kill_anacleto_complete";
		break;

		case "anacleto_rui_sa_pinto_luck_exit":
			pchar.quest.main_line = "anacleto_luck_exit";
			ChangeCharacterAddressGroup(characterFromID("Wilfred Bythesea"), "Pirate_tavern", "reload", "reload1");
			LAi_SetActorType(characterFromID("Wilfred Bythesea"));
			LAi_ActorDialog(characterFromID("Wilfred Bythesea"), pchar, "", 5.0, 1.0);
			worldMap.playerShipX = -200.27;
			worldMap.playerShipZ = 2.34;
			worldMap.playerShipAY = 3.0;
			worldMap.playerShipActionRadius = 20.0;
			worldMap.playerShipDispX = stf(worldMap.playerShipX) - stf(worldMap.islands.Douwesen.position.rx);
			worldMap.playerShipDispZ = stf(worldMap.playerShipZ) - stf(worldMap.islands.Douwesen.position.rz);
		break;

		case "anacleto_rui_sa_pinto_exit_captain":
			LAi_SetImmortal(characterFromID("Anacleto Rui Sa Pinto"), true); 
			LAi_Fade("anacleto_rui_sa_pinto_exit_captain_1", "anacleto_rui_sa_pinto_exit_captain_2");
		break;

		case "anacleto_rui_sa_pinto_exit_captain_1":
			ChangeCharacterAddress(characterFromID("Gervasio Serrao"), "Pirate_tavern", "goto6");
			characters[GetCharacterIndex("Wilfred Bythesea")].quest.kill_ogario = "0";
		break;

		case "anacleto_rui_sa_pinto_exit_captain_2":
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
			LAi_SetActorType(characterFromID("Gervasio Serrao"));
			LAi_ActorAttack(characterFromID("Gervasio Serrao"), pchar, "");
			LAi_SetCheckMinHP(characterFromID("Gervasio Serrao"), 15.0, true, "kill_Serrao_complete"); 
		break;

		case "danielle_exit_from_tavern_danielle":
			LAi_ActorRunToLocator(characterFromID("danielle"), "reload", "reload1", "danielle_escape_from_quest_redmond_tavern_complete", 10.0);
		break;

		case "antoine_lebretton_story_exit":
			LAi_ActorRunToLocator(characterFromID("antoine lebretton"), "reload", "reload1", "Story_Lebretton_leaves_upstairs", 10.0);
		break;

		/////////////////////////////////////////////////////////////////////////
		//   ///////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////////
		
		case "exit_from_douwesen_townhall_complete":
			LAi_SetActorType(CharacterFromID("Lisebet Schefold"));
			LAi_ActorDialog(CharacterFromID("Lisebet Schefold"), pchar, "",  2.0, 1.0);
		break;

		case "to_muelle_for_letter":
			pchar.location.from_sea = "Muelle_shore";
			DisableFastTravel(true);
			DisableMenuLaunch(true);
			DoQuestCheckDelay("to_muelle_for_letter_2", 3.0);
		break;

		case "to_muelle_for_letter_2":04.06.2003 14:43
			DoReloadFromSeaToLocation("Muelle_shore", "reload", "reload2");
			Locations[FindLocation("Muelle_shore")].reload.l2.disable = 1;
			pchar.quest.mystery_men_meeting_us.win_condition.l1 = "location";
			pchar.quest.mystery_men_meeting_us.win_condition.l1.location = "Muelle_shore";
			pchar.quest.mystery_men_meeting_us.win_condition = "mystery_men_meeting_us";
		break;

		case "mystery_men_meeting_us":
			DisableFastTravel(false);
			DisableMenuLaunch(false);
			LAi_SetHP(characterFromID("Mystery_Man_01"), 80.0, 80.0);
			LAi_SetHP(characterFromID("Mystery_Man_02"), 80.0, 80.0);
			LAi_SetHP(characterFromID("Mystery_Man_03"), 80.0, 80.0);
			ChangeCharacterAddress(characterFromID("Mystery_Man_01"), "Muelle_shore", "goto12");
			ChangeCharacterAddressGroup(characterFromID("Mystery_Man_02"), "Muelle_shore", "reload", "reload3");
			ChangeCharacterAddressGroup(characterFromID("Mystery_Man_03"), "Muelle_shore", "reload", "reload3");
			LAi_SetStayType(pchar);
			LAi_SetActorType(characterFromID("Mystery_Man_01"));
			LAi_SetActorType(characterFromID("Mystery_Man_02"));
			LAi_SetActorType(characterFromID("Mystery_Man_03"));
			LAi_ActorDialog(characterFromID("Mystery_Man_01"), pchar, "pchar_back_to_player", 3.0, 1.0);
			LAi_ActorFollow(characterFromID("Mystery_Man_02"), pchar, "", 3.0);
			LAi_ActorFollow(characterFromID("Mystery_Man_03"), pchar, "", 3.0);
			AddQuestRecord("animist", "9");
		break;

		case "fight_with_mystery_mens_in_muelle_shore":
			LAi_group_MoveCharacter(characterFromID("Mystery_Man_01"), "ANIMISTS_IN_SHORE");
			LAi_group_MoveCharacter(characterFromID("Mystery_Man_02"), "ANIMISTS_IN_SHORE");
			LAi_group_MoveCharacter(characterFromID("Mystery_Man_03"), "ANIMISTS_IN_SHORE");
			LAi_group_FightGroups("ANIMISTS_IN_SHORE", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("ANIMISTS_IN_SHORE", "kill_all_animists_in_muelle_shore");
		break;

		case "kill_all_animists_in_muelle_shore":
			Locations[FindLocation("Muelle_shore")].reload.l2.disable = 0;
			GiveItem2Character(pchar, ANIMISTS_AMULET);
			AddQuestRecord("animists", "10");
		break;
		
		case "i_give_first_letter_to_animists":
			pchar.quest.animists = "letter_to_domingues_opened";
			AddMoneyToCharacter(pchar, 1000);
			OfficersReaction("bad");
			Locations[FindLocation("Muelle_shore")].reload.l2.disable = 0;
			characters[GetCharacterIndex("Mystery_Man_01")].location = "none";
			characters[GetCharacterIndex("Mystery_Man_02")].location = "none";
			characters[GetCharacterIndex("Mystery_Man_03")].location = "none";
			AddQuestRecord("animists", "11");
		break;

		case "prepare_for_barkue":
			AddQuestRecord("animists", "14");
			pchar.quest.to_greenford_for_montanez.win_condition.l1 = "location";
			pchar.quest.to_greenford_for_montanez.win_condition.l1.location = "Oxbay";
			pchar.quest.to_greenford_for_montanez.win_condition = "to_greenford_for_montanez_complete";

			LAi_SetHP(characterFromID("Mystery_man_01"), 80.0, 80.0);
			LAi_SetHP(characterFromID("Mystery_man_02"), 80.0, 80.0);

			SetCharacterRelation(GetCharacterIndex("Mergildo Hurtado"),GetMainCharacterIndex(), RELATION_FRIEND);
			SetCharacterRelation(GetCharacterIndex("Mystery_Man_01"),GetMainCharacterIndex(), RELATION_ENEMY);
			
			Group_CreateGroup("Mergildo Hurtado");
			Group_AddCharacter("Mergildo Hurtado", "Mergildo Hurtado");
			Group_SetGroupCommander("Mergildo Hurtado", "Mergildo Hurtado");
			Group_SetPursuitGroup("Mergildo Hurtado", PLAYER_GROUP);
			Group_SetAddress("Mergildo Hurtado", "Oxbay", "", "");

			Group_CreateGroup("animists");
			Group_AddCharacter("animists", "Mystery_Man_01");
			Group_AddCharacter("animists", "Mystery_Man_02");

			Group_SetGroupCommander("animists", "Mystery_man_01");
			Group_SetPursuitGroup("animists", PLAYER_GROUP);
			Group_SetAddress("animists", "Oxbay", "", "");

			Group_LockTask("animists");
			Group_LockTask("Mergildo Hurtado");
			Group_SetTaskAttack("animists", "Mergildo Hurtado");
			Group_SetTaskRunAway("Mergildo Hurtado");
			UpdateRelations();
		break;

		case "to_greenford_for_montanez_complete":
			bQuestDisableMapEnter = true;
			Island_SetReloadEnableGlobal(PChar.location, false);

			pchar.quest.saints_barkue_drown.win_condition.l1 = "NPC_Death";
			pchar.quest.saints_barkue_drown.win_condition.l1.character = "Mergildo Hurtado";
			pchar.quest.saints_barkue_drown.win_condition = "saints_barkue_drown_complete";

			pchar.quest.animists_drown.win_condition.l1 = "NPC_Death";
			pchar.quest.animists_drown.win_condition.l1.character = "Mystery_Man_01";
			pchar.quest.animists_drown.win_condition.l2 = "NPC_Death";
			pchar.quest.animists_drown.win_condition.l2.character = "Mystery_Man_02";
			pchar.quest.animists_drown.win_condition = "animists_drown_complete";
		break;

		case "saints_barkue_drown_complete":
			pchar.quest.animists_drown.over = "yes";
			Group_LockTask("animists");
			Group_SetTaskRunAway("animists");
			bQuestDisableMapEnter = false;
			Island_SetReloadEnableGlobal("Oxbay", true);
			pchar.quest.animists = "barkue_drown";
			AddQuestRecord("animists", "15");
		break;

		case "animists_drown_complete":
			DoQuestCheckDelay("animists_drown_complete_2", 5.0);
			AddQuestRecord("animists", "16");
		break;

		case "animists_drown_complete_2":
			bQuestDisableMapEnter = false;
			Island_SetReloadEnableGlobal("Oxbay", true);
			if (GetNationRelation2MainCharacter(ENGLAND) == RELATION_ENEMY)
			{
				pchar.location.from_sea = "Oxbay_lighthouse";
			}
			else
			{
				pchar.location.from_sea = "Greenford_port";
			}
			DisableFastTravel(true);
			DisableMenuLaunch(true);
			Group_SetAddress("Mergildo Hurtado", "none", "", "");
			DoQuestReloadToLocation("Greenford_tavern", "sit", "sit4", "speak_with_Mergilo");
			ChangeCharacterAddressGroup(characterFromID("Mergildo Hurtado"), "Greenford_tavern", "sit", "sit3");
		break;

		case "speak_with_Mergilo":
			DisableFastTravel(false);
			DisableMenuLaunch(false);
			LAi_SetActorType(pchar);
			LAi_ActorSetSitMode(pchar);
			LAi_SetSitType(characterFromID("Mergildo Hurtado"));
			LAi_ActorDialogNow(pchar, characterFromID("Mergildo Hurtado"), "", 1.0);
		break;

		case "to_barkue_complete":
			AddQuestRecord("animists", "18");
			DoQuestReloadToLocation(pchar.location.from_sea, "reload", "reload1", "");
			LAi_SetPlayerType(pchar);
			characters[GetCharacterIndex("Mergildo Hurtado")].location = "Greenford_tavern";
			ChangeCharacterAddress(characterFromID("Mergildo Hurtado"), "none", "");
		break;

		case "oops_animists_want_letter_again":
			Locations[FindLocation("Muelle_church")].reload.l1.go = "Quest_Muelle_town_01";
			Locations[FindLocation("Muelle_church")].reload.l1.emerge = "reload3";
			pchar.quest.animists_again_meeting_us.win_condition.l1 = "location";
			pchar.quest.animists_again_meeting_us.win_condition.l1.location = "Quest_Muelle_town_01";
			pchar.quest.animists_again_meeting_us.win_condition = "animists_again_meeting_us_complete";
		break;

		case "animists_again_meeting_us_complete":
			LAi_SetStayType(pchar);
			LAi_SetHP(characterFromID("Mystery_Man_01"), 80.0, 80.0);
			LAi_SetHP(characterFromID("Mystery_Man_02"), 80.0, 80.0);
			LAi_SetHP(characterFromID("Mystery_Man_03"), 80.0, 80.0);
			Locations[FindLocation("Muelle_church")].reload.l1.go = "Muelle_town_04";
			Locations[FindLocation("Muelle_church")].reload.l1.emerge = "reload4";
			ChangeCharacterAddress(characterFromID("Mystery_Man_01"), "Quest_Muelle_town_01", "goto73");
			ChangeCharacterAddress(characterFromID("Mystery_Man_02"), "Quest_Muelle_town_01", "goto96");
			ChangeCharacterAddress(characterFromID("Mystery_Man_03"), "Quest_Muelle_town_01", "goto77");
			LAi_SetActorType(CharacterFromID("Mystery_Man_01"));
			LAi_SetActorType(CharacterFromID("Mystery_Man_02"));
			LAi_SetActorType(CharacterFromID("Mystery_Man_03"));
			LAi_ActorDialog(characterFromID("Mystery_Man_01"), pchar, "pchar_back_to_player", 2.0, 1.0);
			LAi_ActorFollow(characterFromID("Mystery_Man_02"), pchar, "", 3.0);
			LAi_ActorFollow(characterFromID("Mystery_Man_03"), pchar, "", 3.0);
		break;

		case "second_fight_with_animists":
			LAi_QuestDelay("second_fight_with_animists_begin", 1.0);
		break;

		case "second_fight_with_animists_begin":
			LAi_group_MoveCharacter(characterFromID("Mystery_Man_01"), "ANIMISTS_IN_MUELLE");
			LAi_group_MoveCharacter(characterFromID("Mystery_Man_02"), "ANIMISTS_IN_MUELLE");
			LAi_group_MoveCharacter(characterFromID("Mystery_Man_03"), "ANIMISTS_IN_MUELLE");
			LAi_group_FightGroups("ANIMISTS_IN_MUELLE", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("ANIMISTS_IN_MUELLE", "kill_all_animists_in_muelle_town");
		break;

		case "kill_all_animists_in_muelle_town":
			LAi_QuestDelay("kill_all_animists_in_muelle_town_complete", 2.0);
		break;

		case "kill_all_animists_in_muelle_town_complete":
			AddQuestRecord("animists", "21");
			DoQuestReloadToLocation("Muelle_port", "reload", "reload2", "to_the_muelle_port_with_letter");
			changeCharacterAddress(characterfromID("padre Domingues"), "Muelle_animists", "goto20");
			changeCharacterAddress(characterfromID("second_spaniard_priest"), "Muelle_church", "goto11");
		break;

		case "to_the_muelle_port_with_letter":
			LAi_SetActorType(pchar);
			LAi_ActorSelfDialog(pchar, "pchar_back_to_player");
			Locations[FindLocation("Muelle_church")].reload.l1.go = "Muelle_town_04";
			Locations[FindLocation("Muelle_church")].reload.l1.emerge = "reload4";
		break;

		case "father_Gareth_stopping_us":
			Locations[FindLocation("Muelle_church")].reload.l1.go = "Muelle_town_04";
			Locations[FindLocation("Muelle_church")].reload.l1.emerge = "reload4";
			pchar.quest.animists = "before_knight";
			TakeItemFromCharacter(pchar, LETTER_TO_BERNARD);
			GiveItem2Character(characterFromID("father Gareth"), "blade5");
			EquipCharacterByItem(characterFromID("father Gareth"), "blade5");

			LAi_SetImmortal(characterFromID("father Gareth"), false);
			LAi_SetImmortal(characterFromID("father Bernard"), true);

			LAi_SetActorType(characterFromID("father Gareth"));

			if (characters[GetCharacterIndex("father Gareth")].location == "Redmond_church")
			{
				LAi_ActorDialog(characterFromID("father Gareth"), pchar, "", 2.0, 1.0);

			}
			else
			{
				ChangeCharacterAddressGroup(characterfromid("Father Gareth"), "Redmond_church", "reload", "reload1");
				LAi_ActorDialog(characterFromID("father Gareth"), pchar, "", 2.0, 1.0);
			}
		break;

		case "fight_with_animists_in_church":
			AddQuestRecord("animists", "22");
			LAi_LocationFightDisable(&locations[FindLocation("redmond_church")], false);
			LAi_SetHP(characterFromID("Mystery_Man_01"), 80.0, 80.0);
			LAi_SetHP(characterFromID("Mystery_Man_02"), 80.0, 80.0);
			LAi_SetHP(characterFromID("Mystery_Man_03"), 80.0, 80.0);
			ChangeCharacterAddressGroup(characterFromID("Mystery_Man_01"), "Redmond_Church", "reload", "reload1");
			ChangeCharacterAddressGroup(characterFromID("Mystery_Man_02"), "Redmond_Church", "reload", "reload1");
			ChangeCharacterAddressGroup(characterFromID("Mystery_Man_03"), "Redmond_Church", "reload", "reload1");

			LAi_group_MoveCharacter(characterFromID("Mystery_Man_01"), "ANIMISTS_IN_CHURCH");
			LAi_group_MoveCharacter(characterFromID("Mystery_Man_02"), "ANIMISTS_IN_CHURCH");
			LAi_group_MoveCharacter(characterFromID("Mystery_Man_03"), "ANIMISTS_IN_CHURCH");
			LAi_group_MoveCharacter(characterFromID("father Gareth"), "ANIMISTS_IN_CHURCH");
			LAi_group_FightGroups("ANIMISTS_IN_CHURCH", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("ANIMISTS_IN_CHURCH", "kill_all_ANIMISTS_in_church_complete");
		break;

		case "kill_all_ANIMISTS_in_church_complete":
			ChangeCharacterAddress(characterFromID("Mystery_Man_01"), "none", "");
			ChangeCharacterAddress(characterFromID("Mystery_Man_02"), "none", "");
			ChangeCharacterAddress(characterFromID("Mystery_Man_03"), "none", "");
			ChangeCharacterAddress(characterFromID("father Gareth"), "none", "");
			LAi_LocationFightDisable(&locations[FindLocation("redmond_church")], true);
			pchar.quest.ANIMISTS = "kill_all_ANIMISTS_in_church";
			LAi_SetActorType(characterFromID("father Bernard"));
			LAi_ActorDialog(characterFromID("father Bernard"), pchar, "bernard_back_to_stay_type", 2.0, 1.0);
		break;

		case "bernard_back_to_stay_type":
			LAi_SetStayType(characterFromID("father Bernard"));
		break;

		case "meeting_with_Jaoquin_De_Masse":
			ChangeCharacterAddressGroup(characterFromID("Jaoquin de masse"), "Redmond_church", "reload", "reload1");
			LAi_SetActorType(characterFromID("Jaoquin de masse"));
			LAi_ActorDialog(characterFromID("Jaoquin de masse"), pchar, "", 2.0, 1.0);
		break;

		case "masse_becomes_officer":
			AddQuestRecord("ANIMISTS", "24");
			AddPassenger(pchar, characterFromID("Jaoquin de masse"), 0);
			Characters[getCharacterIndex("Jaoquin de masse")].location = "none";
		break;

		case "speak_with_jordano":
			AddQuestRecord("ANIMISTS", "25");
			ChangeCharacterAddress(characterFromID("Jordano"), "Muelle_town_01", "goto18");
			LAi_SetActorType(characterFromID("Jordano"));
			LAi_ActorDialog(characterFromID("Jordano"), pchar, "", 5.0, 1.0);
		break;

		case "wait_in_church_for_letters":
			pchar.quest.ANIMISTS = "to_prison_for_teacher_2";
			LAi_Fade("", "");
			LAi_SetActorType(characterFromID("father Bernard"));
			LAi_ActorDialog(characterFromID("father Bernard"), pchar, "bernard_back_to_stay_type", 2.0, 1.0);
		break;

		case "bernard_back_to_stay_type":
			LAi_SetStayType(characterFromID("father Bernard"));
		break;

		case "mystery_man_to_prison":
			LAi_SetStayType(characterFromID("Mystery_man_01"));
			LAi_SetHP(characterFromID("Mystery_Man_01"), 80.0, 80.0);
			ChangeCharacterAddress(characterFromID("Mystery_Man_01"), "Greenford_prison", "goto9");
		break;

		case "teacher_died":
			Island_SetReloadEnableLocal("IslaMuelle", "reload_2", true);
			LAi_KillCharacter(characterFromID("Mystery_Man_01"));
			characterFromID("Mystery_Man_01").location = "none";
			Locations[FindLocation("muelle_ANIMISTS")].locators_radius.goto.goto37 = 2.2;
			pchar.quest.final_battle_with_dark_teacher.win_condition.l1 = "locator";
			pchar.quest.final_battle_with_dark_teacher.win_condition.l1.location = "Muelle_ANIMISTS";
			pchar.quest.final_battle_with_dark_teacher.win_condition.l1.locator_group = "goto";
			pchar.quest.final_battle_with_dark_teacher.win_condition.l1.locator = "goto37";
			pchar.quest.final_battle_with_dark_teacher.win_condition = "final_battle_with_dark_teacher";
			LAi_group_FightGroups("ANIMISTS_SOLDIERS", LAI_GROUP_PLAYER, true);
		break;

		case "exit_from_prison_with_teacher":
			SetNationRelation2MainCharacter(ENGLAND, RELATION_ENEMY);
			LAi_group_FightGroups("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, true);
		break;

		case "prison_commander_captured":
			pchar.quest.ANIMISTS = "force_freedom";
			LAi_SetStayType(characterFromID("Mystery_man_01"));
			LAi_SetHP(characterFromID("Mystery_Man_01"), 80.0, 80.0);
			ChangeCharacterAddress(characterFromID("Mystery_Man_01"), "Greenford_prison", "goto9");
		break;

		case "with_teacher_to_muelle":
			ChangeCharacterAddress(characterFromID("Mystery_Man_01"), "denielle_deck", "goto1");
			DoQuestCheckDelay("with_teacher_to_muelle_2", 1.0);
			DisableFastTravel(true);
			DisableMenuLaunch(true);
		break;

		case "with_teacher_to_muelle_2":
			DoQuestReloadToLocation("denielle_deck", "reload", "locator2", "with_teacher_to_muelle_21");
		break;

		case "with_teacher_to_muelle_21":
			DisableFastTravel(false);
			DisableMenuLaunch(false);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Mystery_man_01"));
			ChangeCharacterAddress(characterFromID("Mystery_man_01"), "denielle_deck", "goto6");
			LAi_SetActorType(characterFromID("Mystery_man_01"));
			LAi_ActorDialog(characterFromID("Mystery_man_01"), pchar, "with_teacher_to_muelle_3", 2.0, 1.0);
		break;

		case "with_teacher_to_muelle_3":
			pchar.quest.ANIMISTS = "with_teacher_in_tavern";
			ChangeCharacterAddress(characterFromID("Mystery_Man_01"), "Muelle_tavern_upstairs", "goto4");
			DoQuestReloadToLocation("Muelle_tavern_upstairs", "goto", "goto3", "with_teacher_to_muelle_4");
			if (GetNationRelation2MainCharacter(SPAIN) != RELATION_ENEMY)
			{
				pchar.location.from_sea = "Muelle_port";
			}
			else
			{
				pchar.location.from_sea = "Muelle_shore_01";
			}
		break;

		case "with_teacher_to_muelle_4":
			LAi_ActorDialog(characterFromID("Mystery_man_01"), pchar, "with_teacher_to_muelle_5", 2.0, 1.0);
		break;

		case "with_teacher_to_muelle_5":
			LAi_LocationFightDisable("Muelle_tavern_upstairs", false);
			LAi_ActorAttack(characterFromID("Mystery_man_01"), pchar, "");
			Lai_SetPlayerType(pchar);
			pchar.quest.destroy_ANIMISTS.win_condition.l1 = "NPC_Death";
			pchar.quest.destroy_ANIMISTS.win_condition.l1.character = "Mystery_man_01";
			pchar.quest.destroy_ANIMISTS.win_condition = "to_ANIMISTS";
			LAi_group_FightGroups(LAI_GROUP_PLAYER, "ANIMISTS_SOLDIERS", true);
			Locations[FindLocation("muelle_ANIMISTS")].locators_radius.goto.goto37 = 2.2;
		break;

		case "to_ANIMISTS":
			Island_SetReloadEnableLocal("IslaMuelle", "reload_2", true);
			pchar.quest.final_battle_with_dark_teacher.win_condition.l1 = "locator";
			pchar.quest.final_battle_with_dark_teacher.win_condition.l1.location = "muelle_ANIMISTS";
			pchar.quest.final_battle_with_dark_teacher.win_condition.l1.locator_group = "goto";
			pchar.quest.final_battle_with_dark_teacher.win_condition.l1.locator = "goto37";
			pchar.quest.final_battle_with_dark_teacher.win_condition = "final_battle_with_dark_teacher";
			LAi_group_FightGroups("ANIMISTS_SOLDIERS", LAI_GROUP_PLAYER, true);
		break;

		case "final_battle_with_dark_teacher":
			LAi_SetStayType(pchar);
			LAi_SetActorType(characterFromID("Dark teacher"));
			LAi_ActorDialogNow(characterFromID("Dark teacher"), pchar, "pchar_back_to_player", 1.0);
			pchar.quest.destroy_ANIMISTS_complete.win_condition.l1 = "NPC_Death";
			pchar.quest.destroy_ANIMISTS_complete.win_condition.l1.character = "Dark Teacher";
			pchar.quest.destroy_ANIMISTS_complete.win_condition = "destroy_ANIMISTS_complete";
		break;

		case "dark_teacher_WANT_kill_YOU":
			LAi_SetWarriorType(characterFromID("Dark teacher"));
			LAi_group_MoveCharacter(characterFromID("Dark teacher"), "LURKING_BOSS");
			LAi_group_FightGroups(LAI_GROUP_PLAYER, "LURKING_BOSS", true);
			//LAi_ActorAttack(characterFromID("Dark teacher"), pchar, "");
		break;

		case "destroy_ANIMISTS_complete":
			pchar.quest.ANIMISTS = "completed";
			AddPartyExp(pchar, 50000);
			ChangeCharacterReputation(pchar, 10);
			//pchar.reputation = makeint(pchar.reputation) +10;
			changeCharacterAddress(characterfromID("padre Domingues"), "Muelle_church", "goto11");
			changeCharacterAddress(characterfromID("second_spaniard_priest"), "none", "goto11");
			GiveItem2Character(pchar, "blade20");

			pchar.quest.fight_with_mefisto.win_condition.l1 = "location";
			pchar.quest.fight_with_mefisto.win_condition.l1.location = "IslaMuelle";
			pchar.quest.fight_with_mefisto.win_condition = "fight_with_mefisto";
			AddQuestRecord("ANIMISTS", "36");
		break;
		
		case "fight_with_mefisto":
			bQuestDisableMapEnter = true;
			Island_SetReloadEnableGlobal("IslaMuelle", false);
			
			Group_CreateGroup("Mefisto");
			Group_AddCharacter("Mefisto", "Dark Captain");
			Group_SetGroupCommander("Mefisto", "Dark Captain");
			Group_SetPursuitGroup("Mefisto", PLAYER_GROUP);
			Group_SetTaskAttack("Mefisto", PLAYER_GROUP);
			Group_SetAddress("Mefisto", Characters[GetMainCharacterIndex()].location, "", "");
			Group_LockTask("Mefisto");
			
			pchar.quest.destroy_mefisto_complete.win_condition.l1 = "NPC_Death";
			pchar.quest.destroy_mefisto_complete.win_condition.l1.character = "Dark Captain";
			pchar.quest.destroy_mefisto_complete.win_condition = "destroy_mefisto_complete";
			AddQuestRecord("ANIMISTS", "37");
		break;
		
		case "destroy_mefisto_complete":
			AddPartyExp(pchar, 15000);
			ChangeCharacterReputation(pchar, 10);
			bQuestDisableMapEnter = false
			Island_SetReloadEnableGlobal("IslaMuelle", true);
			CloseQuestHeader("ANIMISTS");
		break;

		case "womens_leave_town":
			ChangeCharacterReputation(pchar, 4);
			LAi_SetActorType(characterFromID("Rian Dekkers"));
			LAi_SetActorType(characterFromID("Janneke Blinkerhof"));
			LAi_SetActorType(characterFromID("Lisebet Schefold"));
			LAi_ActorGoToLocation(characterFromID("Rian Dekkers"), "reload", "reload1", "none", "", "", "", 15.0);
			LAi_ActorGoToLocation(characterFromID("Janneke Blinkerhof"), "reload", "reload1", "none", "", "", "", 15.0);
			LAi_ActorGoToLocation(characterFromID("Lisebet Schefold"), "reload", "reload1", "none", "", "", "", 15.0);
		break;

		///////////////////////////////////////////////////////////////
		// квестовая линейка игры в кости
		///////////////////////////////////////////////////////////////

		case "to_the_room_for_see_girl":
			//Locations[FindLocation(pchar.location + "_upstairs")].reload.l1.disable = 1;
			locations[FindLocation(pchar.location + "_upstairs")].reload.l1.disable = 1;
			DoQuestReloadToLocation(pchar.location + "_upstairs", "reload", "reload1", "to_the_room_for_see_girl_2");
		break;

		case "to_the_room_for_see_girl_2":
			LAi_SetActorType(characterFromID(pchar.quest.friend_in_tavern));
			PlaceCharacter(characterFromID(pchar.quest.friend_in_tavern), "goto", pchar.location);
			PlaceCharacter(CharacterFromID("Virginie d'Espivant"), "goto", pchar.location);
			LAi_ActorDialog(characterFromID(pchar.quest.friend_in_tavern), pchar, "", 2.0, 1.0);
		break;

		case "fight_in_upstairs_for_girl":
			GiveItem2Character(CharacterFromId(pchar.quest.friend_in_tavern), "blade5");
			EquipCharacterByItem(CharacterFromId(pchar.quest.friend_in_tavern), "blade5");
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], 0);
			LAi_ActorAttack(characterFromID(pchar.quest.friend_in_tavern), pchar, "");
			pchar.quest.kill_man_in_upstairs_for_girl.win_condition.l1 = "NPC_Death";
			pchar.quest.kill_man_in_upstairs_for_girl.win_condition.l1.character = pchar.quest.friend_in_tavern;
			pchar.quest.kill_man_in_upstairs_for_girl.win_condition = "kill_man_in_upstairs_for_girl";
		break;

		case "kill_man_in_upstairs_for_girl":
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], 0);
			LAi_SetFightMode(pchar, false);
			pchar.quest.gambling_with_girl = "gambled";
			LAi_SetActorType(characterFromID("Virginie d'Espivant"));
			LAi_ActorDialog(characterFromID("Virginie d'Espivant"), pchar, "open_room", 2.0, 1.0);
		break;
		
		case "open_room":
			locations[FindLocation(pchar.location + "_upstairs")].reload.l1.disable = 0;
		break;

		case "girl_for_sale":
			pchar.quest.not_to_the_ship_2.win_condition.l1 = "ExitFromLocation";
			pchar.quest.not_to_the_ship_2.win_condition.l1.location = pchar.location;
			pchar.quest.not_to_the_ship_2.win_condition = "girl_for_sale_2";
		break;

		case "girl_for_sale_2":
			LAi_SetHP(characterFromID("danielle_quests_corsair_1"), 80.0, 80.0);
			ChangeCharacterAddressGroup(characterFromID("danielle_quests_corsair_1"), pchar.location, "reload", "reload1");
			LAi_SetActorType(characterFromID("danielle_quests_corsair_1"));
			LAi_ActorDialog(characterFromID("danielle_quests_corsair_1"), pchar, "", 2.0, 1.0);
		break;

		case "habitue_exit_from_room":
			LAi_ActorGoToLocator(characterFromID(pchar.quest.friend_in_tavern), "reload", "reload1", "habitue_exit_from_room_2_complete", 4.0);
			LAi_SetActorType(characterFromID("Virginie d'Espivant"));
			LAi_ActorDialog(characterFromID("Virginie d'Espivant"), pchar, "open_room", 2.0, 1.0);
		break;

		case "girl_exit_from_room":
			pchar.quest.cure_bag_girl_exit_from_room_2.win_condition.l1 = "ExitFromLocation";
			pchar.quest.cure_bag_girl_exit_from_room_2.win_condition.l1.location = pchar.location;
			pchar.quest.cure_bag_girl_exit_from_room_2.win_condition = "girl_exit_from_room_2_complete";

			LAi_ActorGoToLocator(characterFromID("Virginie d'Espivant"), "reload", "reload1", "girl_exit_from_room_2_complete", 4.0);
		break;

		case "girl_exit_from_room_2_complete":
			AddPartyExp(pchar, 5000);
			pchar.quest.gambling_with_girl = "done";
			ChangeCharacterAddress(CharacterFromID("Virginie d'Espivant"), "none", "none");
		break;

		case "habitue_exit_from_room_2_complete":
			switch(pchar.location)
			{
				case "Oxbay_tavern_upstairs":
					ChangeCharacterAddressGroup(&characters[getCharacterIndex(pchar.quest.friend_in_tavern)], "Oxbay_tavern", "sit", characters[getCharacterIndex(pchar.quest.friend_in_tavern)].quest.locator);
				break;

				case "Greenford_tavern_upstairs":
					ChangeCharacterAddressGroup(&characters[getCharacterIndex(pchar.quest.friend_in_tavern)], "Greenford_tavern", "sit", characters[getCharacterIndex(pchar.quest.friend_in_tavern)].quest.locator);
				break;

				case "Redmond_tavern_upstairs":
					ChangeCharacterAddressGroup(&characters[getCharacterIndex(pchar.quest.friend_in_tavern)], "Redmond_tavern", "sit", characters[getCharacterIndex(pchar.quest.friend_in_tavern)].quest.locator);
				break;

				case "Muelle_tavern_upstairs":
					ChangeCharacterAddressGroup(&characters[getCharacterIndex(pchar.quest.friend_in_tavern)], "Muelle_tavern", "sit", characters[getCharacterIndex(pchar.quest.friend_in_tavern)].quest.locator);
				break;

				case "Douwesen_tavern_upstairs":
					ChangeCharacterAddressGroup(&characters[getCharacterIndex(pchar.quest.friend_in_tavern)], "Douwesen_tavern", "sit", characters[getCharacterIndex(pchar.quest.friend_in_tavern)].quest.locator);
				break;

				case "Conceicao_tavern_upstairs":
					ChangeCharacterAddressGroup(&characters[getCharacterIndex(pchar.quest.friend_in_tavern)], "Conceicao_tavern", "sit", characters[getCharacterIndex(pchar.quest.friend_in_tavern)].quest.locator);
				break;

				case "Smugglers_tavern_upstairs":
					ChangeCharacterAddressGroup(&characters[getCharacterIndex(pchar.quest.friend_in_tavern)], "Smugglers_tavern", "sit", characters[getCharacterIndex(pchar.quest.friend_in_tavern)].quest.locator);
				break;

				case "Pirate_tavern_upstairs":
					ChangeCharacterAddressGroup(&characters[getCharacterIndex(pchar.quest.friend_in_tavern)], "Pirate_tavern", "sit", characters[getCharacterIndex(pchar.quest.friend_in_tavern)].quest.locator);
				break;

				case "QC_tavern_upstairs":
					ChangeCharacterAddressGroup(&characters[getCharacterIndex(pchar.quest.friend_in_tavern)], "QC_tavern", "sit", characters[getCharacterIndex(pchar.quest.friend_in_tavern)].quest.locator);
				break;

				case "Falaise_de_fleur_tavern_upstairs":
					ChangeCharacterAddressGroup(&characters[getCharacterIndex(pchar.quest.friend_in_tavern)], "Falaise_De_fleur_tavern", "sit", characters[getCharacterIndex(pchar.quest.friend_in_tavern)].quest.locator);
				break;
			}
			LAi_SetSitType(characterFromID(pchar.quest.friend_in_tavern));
		break;

		case "gambled_girl_to_FdF":
			AddPassenger(pchar, CharacterFromID("Virginie d'Espivant"), 0);
			SetCharacterRemovable(characterFromID("Virginie d'Espivant"), false);			
			OfficersReaction("good");
			pchar.quest.gambling_with_girl = "to_FDF";
			pchar.quest.gambled_girl_comes_to_FDF_tavern.win_condition.l1 = "location";
			pchar.quest.gambled_girl_comes_to_FDF_tavern.win_condition.l1.location = "Falaise_De_fleur_tavern";
			pchar.quest.gambled_girl_comes_to_FDF_tavern.win_condition = "gambled_girl_comes_to_FDF_tavern_complete";
			Locations[FindLocation("Falaise_De_Fleur_tavern")].reload.l1.disable = 1;
			Locations[FindLocation(pchar.location)].reload.l1.disable = 0;
		break;

		case "gambled_girl_comes_to_FDF_tavern_complete":
			ChangeCharacterAddress(characterFromID("Raymond Bouchez"), "Falaise_De_Fleur_Tavern", "goto4");
			ChangeCharacterAddress(characterFromID("Virginie d'Espivant"), "Falaise_De_Fleur_Tavern", "goto5");
			
			LAi_SetActorType(characterFromID("Virginie d'Espivant"));
			LAi_SetActorType(characterFromID("Falaise_De_Fleur_officiant"));
			LAi_SetActorType(characterFromID("Raymond Bouchez"));
			LAi_SetActorType(pchar);
			//LAi_ActorTurnToCharacter(characterFromID("Raymond Bouchez"), characterFromID("Falaise_De_Fleur_officiant"));
			LAi_ActorFollow(pchar, characterFromID("Raymond Bouchez"), "", 2.0);
			LAi_ActorFollow(characterFromID("Virginie d'Espivant"), characterFromID("Raymond Bouchez"), "gambled_girl_comes_to_FDF_tavern_2_complete", 2.0);
			LAi_ActorFollow(characterFromID("Falaise_De_Fleur_officiant"), characterFromID("Raymond Bouchez"), "", 3.0);
		break;

		case "gambled_girl_comes_to_FDF_tavern_2_complete":
			LAi_type_actor_Reset(pchar);
			LAi_type_actor_Reset(characterFromID("Raymond Bouchez"));
			LAi_ActorWaitDialog(pchar, characterFromID("Raymond Bouchez"));
			LAi_ActorDialog(characterFromID("Raymond Bouchez"), pchar, "", 2.0, 1.0);
		break;

		case "virginie_speak":
			LAi_QuestDelay("virginie_speak_2", 0.3);
		break;

		case "virginie_speak_2":
			LAi_type_actor_Reset(pchar);
			LAi_type_actor_Reset(characterFromID("Virginie d'Espivant"));
			LAi_ActorWaitDialog(pchar, characterFromID("Virginie d'Espivant"));
			LAi_ActorDialog(characterFromID("Virginie d'Espivant"), pchar, "", 2.0, 1.0);
		break;

		case "Raymond_speak":
			LAi_QuestDelay("Raymond_speak_2", 0.3);
		break;

		case "Raymond_speak_2":
			LAi_type_actor_Reset(pchar);
			LAi_type_actor_Reset(characterFromID("Raymond Bouchez"));
			LAi_ActorWaitDialog(pchar, characterFromID("Raymond Bouchez"));
			LAi_ActorDialog(characterFromID("Raymond Bouchez"), pchar, "", 2.0, 1.0);
		break;

		case "sister_speak":
			LAi_QuestDelay("sister_speak_2", 0.3);
		break;

		case "sister_speak_2":
			LAi_type_actor_Reset(pchar);
			LAi_type_actor_Reset(characterFromID("Falaise_De_Fleur_officiant"));
			LAi_ActorWaitDialog(pchar, characterFromID("Falaise_De_Fleur_officiant"));
			LAi_ActorDialog(characterFromID("Falaise_De_Fleur_officiant"), pchar, "", 2.0, 1.0);
		break;

		case "gambled_girl_exit_from_FDF_tavern":
			AddPartyExp(pchar, 5000);
			LAi_SetCitizenType(characterFromID("Falaise_De_Fleur_officiant"));
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(pchar, "reload", "reload1", "gambled_girl_exit_from_tavern_complete", 3.0);
		break;

		case "gambled_girl_exit_from_tavern_complete":
			DoQuestReloadToLocation("Falaise_de_fleur_location_03", "reload", "Falaise_de_fleur_tavern", "last_speak_with_virginia");
			characters[GetCharacterIndex("Raymond Bouchez")].location = "none";
			Locations[FindLocation("Falaise_De_Fleur_tavern")].reload.l1.disable = 0;
		break;

		case "last_speak_with_virginia":
			pchar.quest.gambling_with_girl = "to_hovernor";
			ChangeCharacterAddress(characterFromID("Virginie d'Espivant"), "Falaise_de_fleur_location_03", "locator9");
			LAi_SetPlayerType(pchar);
			LAi_type_actor_Reset(characterFromID("Virginie d'Espivant"));
			LAi_ActorDialog(characterFromID("Virginie d'Espivant"), pchar, "", 2.0, 1.0);
			characters[getCharacterIndex("joseph claude le moigne")].dialog.currentnode = "quest";
		break;

		case "remove_virginie_complete":
			RemovePassenger(pchar, characterFromID("Virginie d'Espivant"));
		break;

		///////////////////////////////////////////////////////////////
		// квестовая линейка спасения девушки
		///////////////////////////////////////////////////////////////

		case "to_ship_of_Bernardo_Gamboa":
			LAi_SetActorType(pchar);
			LAi_ActorSelfDialog(pchar, "pchar_back_to_player");
		break;

		case "not_to_the_ship":
			LAi_SetPlayerType(pchar);
			pchar.quest.not_to_the_ship_2.win_condition.l1 = "ExitFromLocation";
			pchar.quest.not_to_the_ship_2.win_condition.l1.location = "Douwesen_port";
			pchar.quest.not_to_the_ship_2.win_condition = "not_to_the_ship_2";
		break;

		case "not_to_the_ship_2":
			pchar.quest.to_ship_of_Bernardo_Gamboa.win_condition.l1 = "location";
			pchar.quest.to_ship_of_Bernardo_Gamboa.win_condition.l1.location = "douwesen_port";
			pchar.quest.to_ship_of_Bernardo_Gamboa.win_condition = "to_ship_of_Bernardo_Gamboa";
		break;

		case "to_the_ship":
			DoQuestReloadToLocation("Gamboa_ship", "reload", "locator2", "to_the_ship_2");
		break;

		case "to_the_ship_2":
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Bernardo Gamboa"));
			LAi_ActorFollow(pchar, characterFromID("Bernardo Gamboa"), "", 1.5);
			LAi_ActorFollow(characterFromID("Bernardo Gamboa"), pchar, "to_the_ship_3", 1.5);
		break;
		
		case "to_the_ship_3":
			LAi_type_actor_Reset(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("Bernardo Gamboa"));
			LAi_ActorDialog(characterFromID("Bernardo Gamboa"), pchar, "", 2.0, 1.0);
		break;

		case "from_the_ship":
			DoQuestReloadToLocation("Douwesen_port", "reload", "reload2", "not_to_the_ship");
		break;

		case "back_to_the_port":
			DoQuestReloadToLocation("Douwesen_port", "reload", "reload2", "pchar_back_to_player");
		break;

		case "bad_fight_in_ship":
			LAi_SetPlayerType(pchar);
			LAi_group_MoveCharacter(characterFromID("Bernardo Gamboa"), "PIRATES_ON_GAMBOA_SHIP");
			LAi_group_MoveCharacter(characterFromID("Corentin Lucay"), "PIRATES_ON_GAMBOA_SHIP");
			LAi_group_FightGroups("PIRATES_ON_GAMBOA_SHIP", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("PIRATES_ON_GAMBOA_SHIP", "kill_him_all_in_gamboa_ship_complete");
		break;

		case "kill_him_all_in_gamboa_ship_complete":
			LAi_QuestDelay("kill_him_all_in_gamboa_ship_2_complete", 2.0);
		break;

		case "kill_him_all_in_gamboa_ship_2_complete":
			AddQuestRecord("daughter", "3");
			LAi_SetActorType(pchar);
			LAi_ActorSelfDialog(pchar, "pchar_back_to_player");
		break;

		case "teneken_in_the_ship":
			LAi_fade("teneken_in_the_ship_2", "");
		break;

		case "teneken_in_the_ship_2":
			ChangeCharacterAddress(characterFromID("Tanneken Oremans"), "Gamboa_ship", "goto2");
			LAi_SetActorType(characterFromID("Tanneken Oremans"));
			LAi_SetActorType(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("Tanneken Oremans"));
			LAi_ActorDialog(characterFromID("Tanneken Oremans"), pchar, "pchar_back_to_player", 2.0, 1.0);
		break;

		case "talk_in_gamboa_ship":
			LAi_Type_Actor_Reset(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("Corentin Lucay"));
			LAi_SetActorType(characterFromID("Corentin Lucay"));
			LAi_ActorDialog(characterFromID("Corentin Lucay"), pchar, "", 2.0, 1.0);
		break;

		case "second_talk_in_gamboa_ship":
			LAi_Type_Actor_Reset(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("Bernardo Gamboa"));
			LAi_ActorDialog(characterFromID("Bernardo Gamboa"), pchar, "", 2.0, 1.0);
		break;

		case "gamboa_died":
			LAi_SetPlayerType(pchar);
			LAi_group_MoveCharacter(characterFromID("Bernardo Gamboa"), "PIRATES_ON_GAMBOA_SHIP");
			LAi_group_MoveCharacter(characterFromID("Corentin Lucay"), LAI_GROUP_PLAYER);
			LAi_group_FightGroups("PIRATES_ON_GAMBOA_SHIP", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("PIRATES_ON_GAMBOA_SHIP", "gamboa_died_complete");
		break;

		case "gamboa_died_complete":
			LAi_QuestDelay("gamboa_died_2_complete", 1.0);
		break;

		case "gamboa_died_2_complete":
			if (!LAi_isDead(characterFromID("Corentin Lucay")))
			{
				characters[GetCharacterIndex("Corentin Lucay")].dialog.currentnode = "three";
				LAi_SetActorType(characterFromID("Corentin Lucay"));
				LAi_SetActorType(pchar);
				LAi_ActorWaitDialog(pchar, characterFromID("Corentin Lucay"));
				LAi_ActorDialog(characterFromID("Corentin Lucay"), pchar, "pchar_back_to_player", 2.0, 1.0);
				AddQuestRecord("daughter", "4");
			}
			else
			{
				LAi_QuestDelay("teneken_in_the_ship", 1.0);
			}
		break;

		///////////////////////////////////////////////////////////////
		// квестовая линейка заида муро
		///////////////////////////////////////////////////////////////
		case "Mendes_go_away_from_muelle_store":
			pchar.quest.death_of_vigila_mendes.win_condition.l1 = "NPC_death";
			pchar.quest.death_of_vigila_mendes.win_condition.l1.character = "Vigila Mendes";
			pchar.quest.death_of_vigila_mendes.win_condition = "death_of_vigila_mendes_complete";
			
			LAi_SetActorType(characterFromID("Vigila Mendes"));

			Lai_ActorGoToLocator(characterFromID("Vigila Mendes"), "reload", "locator2", "Mendes_go_away_from_muelle_store_complete", 2.0);
		break;

		case "Mendes_go_away_from_muelle_store_complete":
			SetCompanionIndex(pchar,-1, GetCharacterIndex("Vigila Mendes"));
			SetCharacterRemovable(characterFromID("Vigila Mendes"), false);
			ChangeCharacterAddress(CharacterFromID("Zaid Murro"), "none", "none");
			ChangeCharacterAddress(characterFromID("Vigila Mendes"), "Falaise_De_Fleur_Store", "goto5");
			LAi_ActorWaitDialog(characterFromID("Vigila Mendes"), pchar);
			AddCharacterGoods(CharacterFromID("Vigila Mendes"), GOOD_EBONY, 500);
		break;

		case "Mendes_go_away_from_falaise_de_fleur_store":
			Lai_ActorGoToLocator(characterFromID("Vigila Mendes"), "reload", "reload1", "Mendes_go_away_from_falaise_de_fleur_store_complete", 2.0);
		break;

		case "vigila_to_muelle_tavern":
			Lai_ActorWaitDialog(characterFromID("Vigila Mendes"), pchar);
		break;

		case "Mendes_go_away_from_falaise_de_fleur_store_complete":
			ChangeCharacterAddress(characterFromID("Vigila Mendes"), "Muelle_store", "locator5");
			LAi_ActorWaitDialog(characterFromID("Vigila Mendes"), pchar);
			AddCharacterGoods(characterFromID("Vigila Mendes"), GOOD_LINEN, 500);
		break;

		case "death_of_vigila_mendes_complete":
			ChangeCharacterAddress(CharacterFromID("Zaid Murro"), "none", "none");
			AddQuestRecord("mendes", "4");
			CloseQuestHeader("mendes");
			ChangeCharacterReputation(pchar, -2);
		break;

		case "zaid_to_muelle_town":
			LAi_ActorGoToLocator(characterFromID("Zaid Murro"),"reload", "reload2", "zaid_to_muelle_town_complete", 2.0);
		break;

		case "zaid_to_muelle_town_complete":
			ChangeCharacterAddress(CharacterFromID("Zaid Murro"), "Muelle_town_01", "goto4");
			LAi_SetStayType(CharacterFromID("Zaid Murro"));
		break;

		case "revenge_for_bandits":
			ChangeCharacterAddress(CharacterFromID("danielle_quests_corsair_1"), "Muelle_town_exit", "locator9");
			ChangeCharacterAddress(CharacterFromID("danielle_quests_corsair_2"), "Muelle_town_exit", "citizen01");
		break;

		case "fight_with_bandits_in_muelle_town_exit":
			AddQuestrecord("murro", "2");
			LAi_group_MoveCharacter(characterFromID("danielle_quests_corsair_1"), "BANDITS");
			LAi_group_MoveCharacter(characterFromID("danielle_quests_corsair_2"), "BANDITS");
			LAi_group_FightGroups("BANDITS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("PIRATES_ON_GAMBOA_SHIP", "fight_with_other_bandits_in_muelle_town_exit");
		break;

		case "fight_with_other_bandits_in_muelle_town_exit":
			DisableFastTravel(true);
			DisableMenuLaunch(true);
			DoQuestCheckDelay("fight_with_other_bandits_in_muelle_town_exit_2", 3.0);
		break;

		case "fight_with_other_bandits_in_muelle_town_exit_2":
			DisableFastTravel(false);
			DisableMenuLaunch(false);
			AddQuestrecord("murro", "3");
			ReanimateCharacter("danielle_quests_corsair_1");
			ReanimateCharacter("danielle_quests_corsair_2");
			ReanimateCharacter("danielle_quests_corsair_3");
			ChangeCharacterAddressGroup(CharacterFromID("danielle_quests_corsair_1"), "Muelle_town_exit", "reload", "reload1");
			ChangeCharacterAddressGroup(CharacterFromID("danielle_quests_corsair_2"), "Muelle_town_exit", "reload", "reload1");
			ChangeCharacterAddressGroup(CharacterFromID("danielle_quests_corsair_3"), "Muelle_town_exit", "reload", "reload1");
			characters[GetCharacterIndex("Zaid Murro")].quest.bandits = "2";
			LAi_SetActorType(CharacterFromID("danielle_quests_corsair_1"));
			LAi_ActorDialog(CharacterFromID("danielle_quests_corsair_1"), pchar, "", 4.0, 1.0);
		break;

		case "fight_with_other_bandits_in_muelle_town_exit_3":
			LAi_group_MoveCharacter(characterFromID("danielle_quests_corsair_1"), "BANDITS");
			LAi_group_MoveCharacter(characterFromID("danielle_quests_corsair_2"), "BANDITS");
			LAi_group_MoveCharacter(characterFromID("danielle_quests_corsair_3"), "BANDITS");
			LAi_group_FightGroups("BANDITS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("PIRATES_ON_GAMBOA_SHIP", "fight_with_other_bandits_in_muelle_town_exit_4");
		break;

		case "fight_with_other_bandits_in_muelle_town_exit_4":
			AddQuestrecord("murro", "4");
			characters[GetCharacterIndex("Zaid Murro")].quest.bandits = "3";
		break;

		///////////////////////////////////////////////////////////////
		// квестовая линейка золотой шахты
		///////////////////////////////////////////////////////////////

		case "to_oxbay_mines_with_larrouse_complete":
			characters[GetCharacterIndex("Clair Larrouse")].dialog.currentnode = "in_canyon";
			pchar.quest.to_canvoy_with_larouse.win_condition.l1 = "location";
			pchar.quest.to_canvoy_with_larouse.win_condition.l1.location = "Oxbay_canyon";
			pchar.quest.to_canvoy_with_larouse.win_condition = "to_oxbay_mines_with_larrouse_3_complete";
			DisableFastTravel(true);
			DisableMenuLaunch(true);
			DoQuestCheckDelay("to_oxbay_mines_with_larrouse_complete_2", 2.0);
		break;

		case "to_oxbay_mines_with_larrouse_complete_2":
			if(GetOfficersIndex(Pchar, 1) == -1)
			{
				Pchar.Temp.Officer.idx1 = GetCharacterIndex("Blaze_Crewmember_01");
				SetOfficersIndex(pchar, -1, GetCharacterIndex("Blaze_Crewmember_01"));
			}
			else
			{
				Pchar.Temp.Officer.idx1 = getOfficersIndex(Pchar, 1);
			}
			if(GetOfficersIndex(Pchar, 2) == -1)
			{
				Pchar.Temp.Officer.idx2 = GetCharacterIndex("Blaze_Crewmember_02");
				SetOfficersIndex(pchar, -1, GetCharacterIndex("Blaze_Crewmember_02"));
			}
			else
			{
				Pchar.Temp.Officer.idx2 = getOfficersIndex(Pchar, 2);
			}
			if(GetOfficersIndex(Pchar, 3) == -1)
			{
				Pchar.Temp.Officer.idx3 = GetCharacterIndex("Blaze_Crewmember_03");
				SetOfficersIndex(pchar, -1, GetCharacterIndex("Blaze_Crewmember_03"));
			}
			else
			{
				Pchar.Temp.Officer.idx3 = getOfficersIndex(Pchar, 3);
			}
			DoReloadFromSeaToLocation("Oxbay_canyon", "reload", "reload6");
		break;

		case "to_oxbay_mines_with_larrouse_3_complete":
			DisableFastTravel(false);
			DisableMenuLaunch(false);
			pchar.quest.remove_faked_officers.win_condition.l1 = "location";
			pchar.quest.remove_faked_officers.win_condition.l1.location = "Oxbay";
			pchar.quest.remove_faked_officers.win_condition = "remove_faked_officers";
			
			LAi_SetOfficerType(&characters[getOfficersIndex(Pchar, 1)]);
			LAi_SetOfficerType(&characters[getOfficersIndex(Pchar, 2)]);
			LAi_SetOfficerType(&characters[getOfficersIndex(Pchar, 3)]);
			locations[FindLocation("Oxbay_canyon")].reload.l1.disable = 1;
			locations[FindLocation("Oxbay_canyon")].reload.l2.disable = 1;
			locations[FindLocation("Oxbay_canyon")].reload.l3.disable = 1;
			locations[FindLocation("Oxbay_canyon")].reload.l4.disable = 1;

			LAi_SetHP(characterFromID("quest_pirate_01"), 80.0, 80.0);
			LAi_SetHP(characterFromID("quest_smuggler_01"), 80.0, 80.0);
			ChangeCharacterAddress(characterFromID("quest_pirate_01"), "Oxbay_canyon", "goto24");
			ChangeCharacterAddress(characterFromID("quest_smuggler_01"), "Oxbay_canyon", "goto28");
			ChangeCharacterAddress(characterFromID("Clair Larrouse"), "Oxbay_canyon", "goto26");
			characters(GetCharacterIndex("quest_pirate_01")).dialog.filename = "quest_pirate_01_dialog.c";
			characters(GetCharacterIndex("quest_pirate_01")).dialog.currentnode = "mines";
			characters(GetCharacterIndex("quest_smuggler_01")).dialog.filename = "quest_pirate_01_dialog.c";
			characters(GetCharacterIndex("quest_smuggler_01")).dialog.currentnode = "mines";
			characters[GetCharacterIndex("Blaze_Crewmember_01").dialog.filename = "quest_pirate_01_dialog.c";
			characters(GetCharacterIndex("Blaze_Crewmember_01")).dialog.currentnode = "mines";
			characters[GetCharacterIndex("Blaze_Crewmember_02").dialog.filename = "quest_pirate_01_dialog.c";
			characters(GetCharacterIndex("Blaze_Crewmember_02")).dialog.currentnode = "mines";
			characters[GetCharacterIndex("Blaze_Crewmember_03").dialog.filename = "quest_pirate_01_dialog.c";
			characters(GetCharacterIndex("Blaze_Crewmember_03")).dialog.currentnode = "mines";
			Locations[FindLocation("Oxbay_canyon")].reload.l4.disable = true;

			LAi_SetOfficerType(characterFromID("quest_pirate_01"));
			LAi_SetOfficerType(characterFromID("quest_smuggler_01"));

			LAi_SetImmortal(characterfromID("Clair Larrouse"), true);
			LAi_SetActorType(characterfromID("Clair Larrouse"));

			pchar.location.from_sea = "Oxbay_lighthouse";

			LAi_ActorDialog(characterFromID("Clair Larrouse"), pchar, "", 3.0, 1.0);
		break;
		
		case "remove_faked_officers":
			iPassenger = makeint(Pchar.Temp.Officer.idx1);
			if(FindFellowTravellers(PChar, &characters[iPassenger]) == FELLOWTRAVEL_OFFICER || FindFellowTravellers(PChar, &characters[iPassenger]) == FELLOWTRAVEL_PASSENGER)
			{
				if (characters[iPassenger].id == "Blaze_Crewmember_01" || characters[iPassenger].id == "Blaze_Crewmember_02" || characters[iPassenger].id == "Blaze_Crewmember_03")
				{
					RemovePassenger(pchar, &characters[iPassenger]);
				}
			}
			iPassenger = makeint(Pchar.Temp.Officer.idx2);
			if(FindFellowTravellers(PChar, &characters[iPassenger]) == FELLOWTRAVEL_OFFICER || FindFellowTravellers(PChar, &characters[iPassenger]) == FELLOWTRAVEL_PASSENGER)
			{
				if (characters[iPassenger].id == "Blaze_Crewmember_01" || characters[iPassenger].id == "Blaze_Crewmember_02" || characters[iPassenger].id == "Blaze_Crewmember_03")
				{
					RemovePassenger(pchar, &characters[iPassenger]);
				}
			}
			iPassenger = makeint(Pchar.Temp.Officer.idx3);
			
			if(FindFellowTravellers(PChar, &characters[iPassenger]) == FELLOWTRAVEL_OFFICER || FindFellowTravellers(PChar, &characters[iPassenger]) == FELLOWTRAVEL_PASSENGER)
			{
				if (characters[iPassenger].id == "Blaze_Crewmember_01" || characters[iPassenger].id == "Blaze_Crewmember_02" || characters[iPassenger].id == "Blaze_Crewmember_03")
				{
					RemovePassenger(pchar, &characters[iPassenger]);
				}
			}
			characters(GetCharacterIndex("Blaze_Crewmember_01")).dialog.currentnode = "first time";
			characters(GetCharacterIndex("Blaze_Crewmember_02")).dialog.currentnode = "first time";
			characters(GetCharacterIndex("Blaze_Crewmember_03")).dialog.currentnode = "first time";
			ChangeCharacterAddress(characterFromID("quest_pirate_01"), "none", "");
			ChangeCharacterAddress(characterFromID("quest_smuggler_01"), "none", "");
			characters(GetCharacterIndex("quest_smuggler_01")).dialog.filename = "quest_smuggler_01_dialog.c";
			characters(GetCharacterIndex("quest_smuggler_01")).dialog.currentnode = "First time";
			characters(GetCharacterIndex("quest_pirate_01")).dialog.filename = "quest_pirate_01_dialog.c";
			characters(GetCharacterIndex("quest_pirate_01")).dialog.currentnode = "First time";
		break;

		case "to_the_gold_for_fight":
			LAi_NoRebirthEnable(characterFromID("mine_soldier_05"));
			LAi_NoRebirthEnable(characterFromID("mine_soldier_06"));
			// 1 enemy soldier
			LAi_SetOfficerType(characterFromID("clair larrouse"));

			sld = LAi_CreateFantomCharacter("Soldier_eng", "goto", "goto9");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "MINE_KEEPERS");

			sld = LAi_CreateFantomCharacter("Soldier_eng2", "goto", "goto9");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "MINE_KEEPERS");

			sld = LAi_CreateFantomCharacter("Soldier_eng3", "goto", "goto9");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "MINE_KEEPERS");
			
			sld = LAi_CreateFantomCharacter("Soldier_eng4", "goto", "goto9");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "MINE_KEEPERS");

			LAi_group_MoveCharacter(characterFromID("mine_soldier_05"), "MINE_KEEPERS");
			LAi_group_MoveCharacter(characterFromID("mine_soldier_06"), "MINE_KEEPERS");

			LAi_group_FightGroups("MINE_KEEPERS", LAI_GROUP_PLAYER, true);

			LAi_group_SetCheck("MINE_KEEPERS", "abording_mines_with_larrouse_complete");
		break;

		case "abording_mines_with_larrouse_complete":
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterfromID("Clair Larrouse"));
			characters[GetCharacterIndex("Clair Larrouse")].dialog.currentnode = "abording_mine";
			LAi_ActorFollow(pchar, characterfromID("Clair Larrouse"), "", 1.0);
			LAi_ActorFollow(characterfromID("Clair Larrouse"), pchar, "abording_mines_with_larrouse_complete_2", 1.0);
		break;
		
		case "abording_mines_with_larrouse_complete_2":
			LAi_SetPlayerType(pchar);
			LAi_ActorDialog(characterfromID("Clair Larrouse"), pchar, "", 3.0, 1.0);
		break;

		case "abording_bad_fight_exit":
			LAi_SetImmortal(characterfromID("Clair Larrouse"), false);
			LAi_group_MoveCharacter(characterfromID("Clair Larrouse"), "LARROUSE");
			LAi_group_MoveCharacter(characterfromID("quest_pirate_01"), "LARROUSE");
			LAi_group_MoveCharacter(characterfromID("quest_smuggler_01"), "LARROUSE");

			LAi_group_FightGroups("LARROUSE", LAI_GROUP_PLAYER, true);

			LAi_group_SetCheck("LARROUSE", "fight_with_larrouse_complete");
		break;

		case "fight_with_larrouse_complete":
			pchar.quest.exit_from_oxbay_to_sea.win_condition.l1 = "location";
			pchar.quest.exit_from_oxbay_to_sea.win_condition.l1.location = "Oxbay";
			pchar.quest.exit_from_oxbay_to_sea.win_condition = "exit_from_oxbay_to_sea_complete";
			if (pchar.location == "Oxbay_shore_02")
			{
				iPassenger = makeint(characters[GetCharacterIndex("clair larrouse")].quest.goldmine)*10000/2;
				AddMoneyToCharacter(pchar, iPassenger);
				OfficersReaction("bad");
				AddQuestRecord("larrouse", "12");
				AddPartyExp(pchar, 5000);
			}
			else
			{
				AddQuestRecord("larrouse", "5");
				AddPartyExp(pchar, 2500);
			}
		break;

		case "exit_from_oxbay_to_sea_complete":
			iPassenger = makeint(Pchar.Temp.Officer.idx1);
			if (characters[iPassenger].id == "Blaze_Crewmember_01" || characters[iPassenger].id == "Blaze_Crewmember_02" || characters[iPassenger].id == "Blaze_Crewmember_03") 
			{
				RemovePassenger(pchar, &characters[iPassenger]);
			}
			iPassenger = makeint(Pchar.Temp.Officer.idx2);
			if (characters[iPassenger].id == "Blaze_Crewmember_01" || characters[iPassenger].id == "Blaze_Crewmember_02" || characters[iPassenger].id == "Blaze_Crewmember_03") 
			{
				RemovePassenger(pchar, &characters[iPassenger]);
			}
			iPassenger = makeint(Pchar.Temp.Officer.idx3);
			if (characters[iPassenger].id == "Blaze_Crewmember_01" || characters[iPassenger].id == "Blaze_Crewmember_02" || characters[iPassenger].id == "Blaze_Crewmember_03")
			{
				RemovePassenger(pchar, &characters[iPassenger]);
			}

			LAi_SetHP(characterFromID("Clair Larrouse"), 80.0, 80.0);

			characters[GetCharacterIndex("Clair Larrouse")].name = "First officer of Clair";
			bQuestDisableMapEnter = true;
			Island_SetReloadEnableGlobal(PChar.location, false);

			RemoveCharacterCompanion(Pchar, &Characters[GetCharacterIndex("Clair Larrouse")]);

			SetCharacterRelation(GetCharacterIndex("Clair Larrouse"),GetMainCharacterIndex(),RELATION_ENEMY);
			
			Group_CreateGroup("Clair Larrouse");
			Group_AddCharacter("Clair Larrouse", "Clair Larrouse");
			Group_SetGroupCommander("Clair Larrouse", "Clair Larrouse");
			Group_SetPursuitGroup("Clair Larrouse", PLAYER_GROUP);
			Group_SetTaskAttack("Clair Larrouse", PLAYER_GROUP);
			Group_SetAddress("Clair Larrouse", Characters[GetMainCharacterIndex()].location, "", "");
			Group_LockTask("Clair Larrouse");

			UpdateRelations();

			pchar.quest.killing_clair_in_sea.win_condition.l1 = "NPC_Death";
			pchar.quest.killing_clair_in_sea.win_condition.l1.character = "Clair Larrouse";
			pchar.quest.killing_clair_in_sea.win_condition = "killing_clair_in_sea_complete";
			
			Locations[FindLocation("Oxbay_canyon")].reload.l4.disable = false;
		break;

		case "killing_clair_in_sea_complete":
			bQuestDisableMapEnter = false;
			Island_SetReloadEnableGlobal(PChar.location, true);
			locations[FindLocation("Oxbay_canyon")].reload.l1.disable = 0;
			locations[FindLocation("Oxbay_canyon")].reload.l2.disable = 0;
			if (!LAI_IsDead(characterFromID("Ferro cerezo")) && makeint(characters[GetCharacterIndex("danielle")].rank) < 9)
			{
				locations[FindLocation("Oxbay_canyon")].reload.l3.disable = 0;
			}
			locations[FindLocation("Oxbay_canyon")].reload.l4.disable = 0;
			AddQuestRecord("larrouse", "6");
			CloseQuestHeader("larrouse");
			AddPartyExp(pchar, 5000);
			LAi_group_MoveCharacter(characterFromID("mine_soldier_05"), "ENGLAND_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("mine_soldier_06"), "ENGLAND_SOLDIERS");
			LAi_NoRebirthDisable(characterFromID("mine_soldier_05"));
			LAi_NoRebirthDisable(characterFromID("mine_soldier_06"));
		break;

		case "larrouse_becomes_officer":
			LAi_ActorFollowEverywhere(characterFromID("clair larrouse"), "", 60.0);
			AddQuestRecord("larrouse", "7");
		break;

		case "to_gold_konvoy_complete":
			Locations[FindLocation("Oxbay_canyon")].reload.l4.disable = false;
			
			LAi_LocationMonstersGen(&locations[FindLocation("Oxbay_jungle_02")], false);
			LAi_SetOfficerType(characterFromID("Clair Larrouse"));
			LAi_SetOfficerType(characterFromID("quest_pirate_01"));
			LAi_SetOfficerType(characterFromID("quest_smuggler_01"));
			AddQuestRecord("larrouse", "8");
			locations[FindLocation("Oxbay_jungle_02")].reload.l1.disable = 1;
			locations[FindLocation("Oxbay_jungle_02")].reload.l2.disable = 1;
			locations[FindLocation("Oxbay_jungle_02")].reload.l3.disable = 1;

			sld = LAi_CreateFantomCharacter("Soldier_eng", "goto", "citizen03");
			sld.id = "soldier1";
			LAi_SetActorType(sld);
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_SetCheckMinHP(sld, 79.0, false, "fight_in_jungles");
			pchar.quest.kill_konvoyer_01.win_condition.l1 = "NPC_Death";
			pchar.quest.kill_konvoyer_01.win_condition.l1.character = "soldier1";
			pchar.quest.kill_konvoyer_01.win_condition = "kill_konvoyer_01";

			sld = LAi_CreateFantomCharacter("Soldier_eng2", "goto", "citizen08");
			sld.id = "soldier2";
			LAi_SetActorType(sld);
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_SetCheckMinHP(sld, 79.0, false, "fight_in_jungles");
			pchar.quest.kill_konvoyer_02.win_condition.l1 = "NPC_Death";
			pchar.quest.kill_konvoyer_02.win_condition.l1.character = "soldier2";
			pchar.quest.kill_konvoyer_02.win_condition = "kill_konvoyer_02";

			sld = LAi_CreateFantomCharacter("Soldier_eng3", "goto", "citizen07");
			sld.id = "soldier3";
			LAi_SetActorType(sld);
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_SetCheckMinHP(sld, 79.0, false, "fight_in_jungles");
			pchar.quest.kill_konvoyer_03.win_condition.l1 = "NPC_Death";
			pchar.quest.kill_konvoyer_03.win_condition.l1.character = "soldier3";
			pchar.quest.kill_konvoyer_03.win_condition = "kill_konvoyer_03";

			sld = LAi_CreateFantomCharacter("Soldier_eng4", "goto", "citizen04");
			sld.id = "soldier4";
			LAi_SetActorType(sld);
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_SetCheckMinHP(sld, 79.0, false, "fight_in_jungles");
			pchar.quest.kill_konvoyer_04.win_condition.l1 = "NPC_Death";
			pchar.quest.kill_konvoyer_04.win_condition.l1.character = "soldier4";
			pchar.quest.kill_konvoyer_04.win_condition = "kill_konvoyer_04";

			characters[GetCharacterIndex("Clair Larrouse")].dialog.currentnode = "kill_konvoy";
			LAi_SetActorType(characterFromID("Clair Larrouse"));
			LAi_ActorDialog(characterFromID("Clair Larrouse"), pchar, "", 2.0, 1.0);
		break;

		case "fight_in_jungles":
			LAi_RemoveCheckMinHP(characterFromID("soldier1"));
			LAi_RemoveCheckMinHP(characterFromID("soldier2"));
			LAi_RemoveCheckMinHP(characterFromID("soldier3"));
			LAi_RemoveCheckMinHP(characterFromID("soldier4"));
			
			LAi_group_MoveCharacter(characterfromID("soldier1"), "KONVOYERS");
			LAi_group_MoveCharacter(characterfromID("soldier2"), "KONVOYERS");
			LAi_group_MoveCharacter(characterfromID("soldier3"), "KONVOYERS");
			LAi_group_MoveCharacter(characterfromID("soldier4"), "KONVOYERS");

			LAi_group_FightGroups("KONVOYERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("KONVOYERS", "wait_for_kill");
		break;

		case "konvoy_go_away":
			LAi_SetOfficerType(characterFromID("Clair Larrouse"));
			LAi_QuestDelay("konvoy_go_away_2", 8.5);
		break;

		case "konvoy_go_away_2":
			pchar.quest.konvoyers = 0;
			LAi_ActorGoToLocator(characterFromID("soldier1"), "reload", "reload2", "konvoyer_01_exit", 30.0);
			LAi_ActorGoToLocator(characterFromID("soldier2"), "reload", "reload2", "konvoyer_02_exit", 30.0);
			LAi_ActorGoToLocator(characterFromID("soldier3"), "reload", "reload2", "konvoyer_03_exit", 30.0);
			LAi_ActorGoToLocator(characterFromID("soldier4"), "reload", "reload2", "konvoyer_04_exit", 30.0);
		break;

		case "konvoyer_01_exit":
			pchar.quest.kill_konvoyer_01.over = "yes";
			ChangeCharacterAddress(characterFromID("soldier1"), "none", "");
			pchar.quest.konvoyers = makeint(pchar.quest.konvoyers) + 1;
			if (makeint(pchar.quest.konvoyers) == 4)
			{
				characters[GetCharacterIndex("Clair Larrouse")].dialog.currentnode = "konvoy_away";
				LAi_SetActorType(characterFromID("Clair Larrouse"));
				LAi_SetActorType(pchar);
				LAi_ActorWaitDialog(pchar, characterFromID("Clair Larrouse"));
				LAi_SetActorType(characterFromID("Clair Larrouse"));
				LAi_ActorDialog(characterFromID("Clair Larrouse"), pchar, "pchar_back_to_player", 2.0, 1.0);
			}
		break;

		case "konvoyer_02_exit":
			pchar.quest.kill_konvoyer_02.over = "yes";
			ChangeCharacterAddress(characterFromID("soldier2"), "none", "");
			pchar.quest.konvoyers = makeint(pchar.quest.konvoyers) + 1;
			if (makeint(pchar.quest.konvoyers) == 4)
			{
				characters[GetCharacterIndex("Clair Larrouse")].dialog.currentnode = "konvoy_away";
				LAi_SetActorType(pchar);
				LAi_ActorWaitDialog(pchar, characterFromID("Clair Larrouse"));
				LAi_SetActorType(characterFromID("Clair Larrouse"));
				LAi_ActorDialog(characterFromID("Clair Larrouse"), pchar, "pchar_back_to_player", 2.0, 1.0);
			}
		break;

		case "konvoyer_03_exit":
			pchar.quest.kill_konvoyer_03.over = "yes";
			ChangeCharacterAddress(characterFromID("soldier3"), "none", "");
			pchar.quest.konvoyers = makeint(pchar.quest.konvoyers) + 1;
			if (makeint(pchar.quest.konvoyers) == 4)
			{
				characters[GetCharacterIndex("Clair Larrouse")].dialog.currentnode = "konvoy_away";
				LAi_SetActorType(pchar);
				LAi_ActorWaitDialog(pchar, characterFromID("Clair Larrouse"));
				LAi_SetActorType(characterFromID("Clair Larrouse"));
				LAi_ActorDialog(characterFromID("Clair Larrouse"), pchar, "pchar_back_to_player", 2.0, 1.0);
			}
		break;

		case "konvoyer_04_exit":
			pchar.quest.kill_konvoyer_04.over = "yes";
			ChangeCharacterAddress(characterFromID("soldier4"), "none", "");
			pchar.quest.konvoyers = makeint(pchar.quest.konvoyers) + 1;
			if (makeint(pchar.quest.konvoyers) == 4)
			{
				characters[GetCharacterIndex("Clair Larrouse")].dialog.currentnode = "konvoy_away";
				LAi_SetActorType(pchar);
				LAi_ActorWaitDialog(pchar, characterFromID("Clair Larrouse"));
				LAi_SetActorType(characterFromID("Clair Larrouse"));
				LAi_ActorDialog(characterFromID("Clair Larrouse"), pchar, "pchar_back_to_player", 2.0, 1.0);
			}
		break;

		case "Clair_away":
			AddQuestRecord("larrouse", "9");
			LAi_ActorRunToLocation(characterFromID("clair larrouse"), "reload", "reload1", "Muelle_tavern", "sit", "sit6", "clair_to_muelle", 20.0);
	
			pchar.quest.clair_away.win_condition.l1 = "location";
			pchar.quest.clair_away.win_condition.l1.location = "Oxbay";
			pchar.quest.clair_away.win_condition = "clair_to_muelle";
			locations[FindLocation("Oxbay_jungle_02")].reload.l1.disable = 0;
			locations[FindLocation("Oxbay_jungle_02")].reload.l2.disable = 0;
			locations[FindLocation("Oxbay_jungle_02")].reload.l3.disable = 0;
			locations[FindLocation("Oxbay_jungle_03")].reload.l1.disable = 0;
			locations[FindLocation("Oxbay_jungle_03")].reload.l2.disable = 0;
			locations[FindLocation("Oxbay_jungle_03")].reload.l3.disable = 0;
			LAi_LocationMonstersGen(&locations[FindLocation("Oxbay_jungle_02")], true);
			//pchar.reputation = makeint(pchar.reputation) - 5;
			ChangeCharacterReputation(pchar, -10);
			LAi_group_MoveCharacter(characterFromID("mine_soldier_05"), "ENGLAND_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("mine_soldier_06"), "ENGLAND_SOLDIERS");
			LAi_NoRebirthDisable(characterFromID("mine_soldier_05"));
			LAi_NoRebirthDisable(characterFromID("mine_soldier_06"));
			LAi_SetImmortal(characterfromID("Clair Larrouse"), false);
		break;

		case "kill_konvoyer_01":
			characters[GetCharacterIndex("Clair larrouse")].quest.goldmine = makeint(characters[GetCharacterIndex("Clair larrouse")].quest.goldmine) + 1;
		break;

		case "kill_konvoyer_02":
			characters[GetCharacterIndex("Clair larrouse")].quest.goldmine = makeint(characters[GetCharacterIndex("Clair larrouse")].quest.goldmine) + 1;
		break;

		case "kill_konvoyer_03":
			characters[GetCharacterIndex("Clair larrouse")].quest.goldmine = makeint(characters[GetCharacterIndex("Clair larrouse")].quest.goldmine) + 1;
		break;

		case "kill_konvoyer_04":
			characters[GetCharacterIndex("Clair larrouse")].quest.goldmine = makeint(characters[GetCharacterIndex("Clair larrouse")].quest.goldmine) + 1;
		break;

		case "wait_for_kill":
			pchar.quest.kill_konvoyer_01.over = "yes";
			pchar.quest.kill_konvoyer_02.over = "yes";
			pchar.quest.kill_konvoyer_03.over = "yes";
			pchar.quest.kill_konvoyer_04.over = "yes";
			
			locations[FindLocation("Oxbay_jungle_02")].reload.l1.disable = 1;
			locations[FindLocation("Oxbay_jungle_02")].reload.l2.disable = 1;
			locations[FindLocation("Oxbay_jungle_02")].reload.l3.disable = 1;
			locations[FindLocation("Oxbay_jungle_03")].reload.l1.disable = 1;
			locations[FindLocation("Oxbay_jungle_03")].reload.l2.disable = 1;
			locations[FindLocation("Oxbay_jungle_03")].reload.l3.disable = 1;
			
			characters[GetCharacterIndex("Clair Larrouse")].dialog.currentnode = "konvoy_killed";
			LAi_SetActorType(characterFromID("Clair Larrouse"));
			LAi_SetStayType(pchar);
			LAi_ActorDialog(characterFromID("Clair Larrouse"), pchar, "larrouse_follow_us_again", 4.0, 1.0);
			AddQuestRecord("larrouse", "10");
		break;

		case "escape_to_shore":
			locations[FindLocation("Oxbay_jungle_02")].reload.l1.disable = 0;
			locations[FindLocation("Oxbay_jungle_02")].reload.l2.disable = 0;
			locations[FindLocation("Oxbay_jungle_02")].reload.l3.disable = 0;
			locations[FindLocation("Oxbay_jungle_03")].reload.l1.disable = 0;
			locations[FindLocation("Oxbay_jungle_03")].reload.l2.disable = 0;
			locations[FindLocation("Oxbay_jungle_03")].reload.l3.disable = 0;
			locations[FindLocation("Oxbay_shore_02")].reload.l1.disable = 1;
			locations[FindLocation("Oxbay_shore_02")].reload.l2.disable = 1;
			locations[FindLocation("Oxbay_shore_02")].reload.l3.disable = 1;
			locations[FindLocation("Oxbay_shore_02")].reload.l4.disable = 1;
			
			characters[GetCharacterIndex("Clair Larrouse")].dialog.currentnode = "escape_to_shore";
			LAi_SetActorType(characterFromID("Clair Larrouse"));
			LAi_ActorDialog(characterFromID("Clair Larrouse"), pchar, "", 2.0, 1.0);
		break;

		case "larrouse_follow_us_again":
			LAi_SetPlayerType(pchar);
			LAi_ActorFollowEverywhere(characterFromID("clair larrouse"), "", 60.0);
		break;

		case "fighting_in_shore":
			LAi_SetOfficerType(characterFromID("clair larrouse"));
			LAi_QuestDelay("fighting_in_shore_2", 10.0);
		break;

		case "fighting_in_shore_2":
			sld = LAi_CreateFantomCharacter("Soldier_eng", "reload", "reload2_back");
			LAi_group_MoveCharacter(sld, "MINE_KEEPERS");

			sld = LAi_CreateFantomCharacter("Soldier_eng2", "reload", "reload2_back");
			LAi_group_MoveCharacter(sld, "MINE_KEEPERS");

			sld = LAi_CreateFantomCharacter("Soldier_eng3", "reload", "reload2_back");
			LAi_group_MoveCharacter(sld, "MINE_KEEPERS");
			
			sld = LAi_CreateFantomCharacter("Soldier_eng4", "reload", "reload2_back");
			LAi_group_MoveCharacter(sld, "MINE_KEEPERS");

			sld = LAi_CreateFantomCharacter("Soldier_eng5", "reload", "reload2_back");
			LAi_group_MoveCharacter(sld, "MINE_KEEPERS");

			sld = LAi_CreateFantomCharacter("Soldier_eng6", "reload", "reload2_back");
			LAi_group_MoveCharacter(sld, "MINE_KEEPERS");

			LAi_group_FightGroups("MINE_KEEPERS", LAI_GROUP_PLAYER, true);

			LAi_group_SetCheck("MINE_KEEPERS", "fight_in_shore_completed");
		break;

		case "fight_in_shore_completed":
			LAi_QuestDelay("fight_in_shore_completed_almost", 6.0);
		break;
		
		case "fight_in_shore_completed_almost":
			locations[FindLocation("Oxbay_shore_02")].reload.l1.disable = 0;
			locations[FindLocation("Oxbay_shore_02")].reload.l2.disable = 0;
			locations[FindLocation("Oxbay_shore_02")].reload.l3.disable = 0;
			locations[FindLocation("Oxbay_shore_02")].reload.l4.disable = 0;
			pchar.location.from_sea = "Oxbay_shore_02";
			DoQuestReloadToLocation("Oxbay_shore_02", "reload", "reload2_back", "fight_in_shore_2_completed");
		break;

		case "fight_in_shore_2_completed":
			LAi_SetStayType(pchar);
			AddQuestRecord("larrouse", "11");
			characters[GetCharacterIndex("Clair Larrouse")].dialog.currentnode = "fight_in_shore_completed";
			LAi_SetActorType(characterFromID("Clair Larrouse"));
			LAi_ActorDialog(characterFromID("Clair Larrouse"), pchar, "pchar_back_to_player", 4.0, 1.0);
			LAi_SetImmortal(characterfromID("Clair Larrouse"), false);
		break;

		case "clair_to_muelle":
			LAi_SetSitType(characterFromID("clair Larrouse"));
			characters[getCharacterIndex("Clair Larrouse")].location	= "Muelle_tavern";
			characters[getCharacterIndex("Clair Larrouse")].location.group = "sit";
			characters[getCharacterIndex("Clair Larrouse")].location.locator = "sit6";
			characters[getCharacterIndex("Clair Larrouse")].dialog.currentnode = "for_hire";
		break;

		case "from_shore_to_ship":
			iPassenger = makeint(Pchar.Temp.Officer.idx1);
			
			if(FindFellowTravellers(PChar, &characters[iPassenger]) == FELLOWTRAVEL_OFFICER || FindFellowTravellers(PChar, &characters[iPassenger]) == FELLOWTRAVEL_PASSENGER)
			{
				if (characters[iPassenger].id == "Blaze_Crewmember_01" || characters[iPassenger].id == "Blaze_Crewmember_02" || characters[iPassenger].id == "Blaze_Crewmember_03")
				{
					RemovePassenger(pchar, &characters[iPassenger]);
				}
			}
			iPassenger = makeint(Pchar.Temp.Officer.idx2);
			if(FindFellowTravellers(PChar, &characters[iPassenger]) == FELLOWTRAVEL_OFFICER || FindFellowTravellers(PChar, &characters[iPassenger]) == FELLOWTRAVEL_PASSENGER)
			{
				if (characters[iPassenger].id == "Blaze_Crewmember_01" || characters[iPassenger].id == "Blaze_Crewmember_02" || characters[iPassenger].id == "Blaze_Crewmember_03")
				{
					RemovePassenger(pchar, &characters[iPassenger]);
				}
			}
			iPassenger = makeint(Pchar.Temp.Officer.idx3);
			if(FindFellowTravellers(PChar, &characters[iPassenger]) == FELLOWTRAVEL_OFFICER || FindFellowTravellers(PChar, &characters[iPassenger]) == FELLOWTRAVEL_PASSENGER)
			{
				if (characters[iPassenger].id == "Blaze_Crewmember_01" || characters[iPassenger].id == "Blaze_Crewmember_02" || characters[iPassenger].id == "Blaze_Crewmember_03")
				{
					RemovePassenger(pchar, &characters[iPassenger]);
				}
			}
			CloseQuestHeader("larrouse");
			AddPartyExp(pchar, 20000);
			LAi_SetOfficerType(characterFromID("clair larrouse"));
			characters[GetCharacterIndex("clair larrouse")].location = "none";
			//pchar.reputation = makeint(pchar.reputation) + 1;
			ChangeCharacterReputation(pchar, -5);
			LAi_group_MoveCharacter(characterFromID("mine_soldier_05"), "ENGLAND_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("mine_soldier_06"), "ENGLAND_SOLDIERS");
			LAi_NoRebirthDisable(characterFromID("mine_soldier_05"));
			LAi_NoRebirthDisable(characterFromID("mine_soldier_06"));
		break;


	//Hitman

		case "Hit_start":
			SetEnterLocationQuest("Conceicao_tavern", "Hit_start_check", 0);
			chrEnableReloadLocator("Muelle_town_01", "Reload21", 0);
			chrEnableReloadLocator("Greenford_town", "reload5", 0);
			chrEnableReloadLocator("Conceicao_town", "reload15", 0);
		break;

		case "Hit_start_check":
			if(makeint(PChar.rank) >= 5)
			{
				StartQuestMovie(true, false, false);

				bDisableFastReload = 1;

				ChangeCharacterAddressGroup(CharacterFromID("Ambroz Bricenos"), "Conceicao_tavern", "goto", "goto4");
				ChangeCharacterAddressGroup(CharacterFromID("Mateus Santos"), "Hit_house", "goto", "goto4");
				ChangeCharacterAddressGroup(CharacterFromID("Thug1"), "Hit_house", "goto", "goto1");
				ChangeCharacterAddressGroup(CharacterFromID("Thug2"), "Hit_house", "goto", "goto2");
				ChangeCharacterAddressGroup(CharacterFromID("Thug3"), "Hit_house", "goto", "goto3");
				ChangeCharacterAddressGroup(CharacterFromID("Geffrey Bampfylde"), "Hit_house1", "goto", "goto1");
				ChangeCharacterAddressGroup(CharacterFromID("Bucho"), "Hit_house1", "goto", "goto2");
				ChangeCharacterAddressGroup(CharacterFromID("Amerigo Vieira"), "Hit_house2", "goto", "goto4");

				LAi_SetImmortal(CharacterFromID("Ambroz Bricenos"), 1);
				LAi_SetImmortal(CharacterFromID("Mateus Santos"), 1);
				LAi_SetImmortal(CharacterFromID("Thug1"), 1);
				LAi_SetImmortal(CharacterFromID("Thug2"), 1);
				LAi_SetImmortal(CharacterFromID("Thug3"), 1);
				LAi_SetImmortal(CharacterFromID("Geffrey Bampfylde"), 1);
				LAi_SetImmortal(CharacterFromID("Bucho"), 1);
				LAi_SetImmortal(CharacterFromID("Pepin Bertillon"), 1);
				LAi_SetImmortal(CharacterFromID("Bertillon's guard1"), 1);
				LAi_SetImmortal(CharacterFromID("Bertillon's guard2"), 1);
				LAi_SetImmortal(CharacterFromID("Amerigo Vieira"), 1);
				LAi_SetImmortal(CharacterFromID("Vito Leone"), 1);

				LAi_SetWarriorType(CharacterFromID("Mateus Santos"));
				LAi_SetWarriorType(CharacterFromID("Thug1"));
				LAi_SetWarriorType(CharacterFromID("Thug2"));
				LAi_SetWarriorType(CharacterFromID("Thug3"));

				LAi_warrior_SetStay(CharacterFromID("Mateus Santos"), 1);
				LAi_warrior_SetStay(CharacterFromID("Thug1"), 1);
				LAi_warrior_SetStay(CharacterFromID("Thug2"), 1);
				LAi_warrior_SetStay(CharacterFromID("Thug3"), 1);

				LAi_warrior_DialogEnable(CharacterFromID("Mateus Santos"), 1);
				LAi_warrior_DialogEnable(CharacterFromID("Thug1"), 1);
				LAi_warrior_DialogEnable(CharacterFromID("Thug2"), 1);
				LAi_warrior_DialogEnable(CharacterFromID("Thug3"), 1);

				LAi_group_MoveCharacter(CharacterFromID("Mateus Santos"), "santos_group");
				LAi_group_MoveCharacter(CharacterFromID("Thug1"), "santos_group");
				LAi_group_MoveCharacter(CharacterFromID("Thug2"), "santos_group");
				LAi_group_MoveCharacter(CharacterFromID("Thug3"), "santos_group");

				LAi_group_SetRelation("santos_group", "santos_group", LAI_GROUP_FRIEND);

				LAi_SetActorType(CharacterFromID("Ambroz Bricenos"));

				Characters[GetCharacterIndex("Ambroz Bricenos")].dialog.currentnode = "wetjob";

				LAi_ActorDialog(CharacterFromID("Ambroz Bricenos"), PChar, "", 15.0, -1);
			}
		break;

		case "Hit_END":
			Characters[GetCharacterIndex("Ambroz Bricenos")].Location = "none";
			Characters[GetCharacterIndex("Mateus Santos")].Location = "none";
			Characters[GetCharacterIndex("Thug1")].Location = "none";
			Characters[GetCharacterIndex("Thug2")].Location = "none";
			Characters[GetCharacterIndex("Thug3")].Location = "none";
			Characters[GetCharacterIndex("Geffrey Bampfylde")].Location = "none";
			Characters[GetCharacterIndex("Bucho")].Location = "none";
			Characters[GetCharacterIndex("Pepin Bertillon")].Location = "none";
			Characters[GetCharacterIndex("Bertillon's guard1")].Location = "none";
			Characters[GetCharacterIndex("Bertillon's guard2")].Location = "none";
			Characters[GetCharacterIndex("Amerigo Vieira")].Location = "none";
			Characters[GetCharacterIndex("Vito Leone")].Location = "none";

			chrEnableReloadLocator("Muelle_town_01", "Reload21", 0);
			chrEnableReloadLocator("Greenford_town", "reload5", 0);
			chrEnableReloadLocator("Conceicao_town", "reload15", 0);

			PChar.quest.Hitman = "end";
			PChar.quest.Hitman.over = "yes";
			CloseQuestHeader("Hitman");
		break;

		case "Hit_END_timer":

			Characters[GetCharacterIndex("Ambroz Bricenos")].Location = "none";
			Characters[GetCharacterIndex("Mateus Santos")].Location = "none";
			Characters[GetCharacterIndex("Thug1")].Location = "none";
			Characters[GetCharacterIndex("Thug2")].Location = "none";
			Characters[GetCharacterIndex("Thug3")].Location = "none";
			Characters[GetCharacterIndex("Geffrey Bampfylde")].Location = "none";
			Characters[GetCharacterIndex("Bucho")].Location = "none";
			Characters[GetCharacterIndex("Pepin Bertillon")].Location = "none";
			Characters[GetCharacterIndex("Bertillon's guard1")].Location = "none";
			Characters[GetCharacterIndex("Bertillon's guard2")].Location = "none";
			Characters[GetCharacterIndex("Amerigo Vieira")].Location = "none";
			Characters[GetCharacterIndex("Vito Leone")].Location = "none";

			chrEnableReloadLocator("Muelle_town_01", "Reload21", 0);
			chrEnableReloadLocator("Greenford_town", "reload5", 0);
			chrEnableReloadLocator("Conceicao_town", "reload15", 0);

			PChar.quest.Hitman = "end";

			//Add journal entry

			AddQuestRecord("Hitman", "21");
			CloseQuestHeader("Hitman");

		break;

		case "Hit_timer1":

			PChar.quest.Hit_timer1.win_condition.l1 = "Timer";
			PChar.quest.Hit_timer1.win_condition.l1.date.day = GetAddingDataDay(0, 1, 0);
			PChar.quest.Hit_timer1.win_condition.l1.date.month = GetAddingDataMonth(0, 1, 0);
			PChar.quest.Hit_timer1.win_condition.l1.date.year = GetAddingDataYear(0, 1, 0);
			PChar.quest.Hit_timer1.win_condition = "Hit_END_timer";

		break;

		case "Hit_timer2":

			PChar.quest.Hit_timer2.win_condition.l1 = "Timer";
			PChar.quest.Hit_timer2.win_condition.l1.date.day = GetAddingDataDay(0, 1, 0);
			PChar.quest.Hit_timer2.win_condition.l1.date.month = GetAddingDataMonth(0, 1, 0);
			PChar.quest.Hit_timer2.win_condition.l1.date.year = GetAddingDataYear(0, 1, 0);
			PChar.quest.Hit_timer2.win_condition = "Hit_END_timer";

		break;

		case "Hit_timer3":

			PChar.quest.Hit_timer3.win_condition.l1 = "Timer";
			PChar.quest.Hit_timer3.win_condition.l1.date.day = GetAddingDataDay(0, 1, 0);
			PChar.quest.Hit_timer3.win_condition.l1.date.month = GetAddingDataMonth(0, 1, 0);
			PChar.quest.Hit_timer3.win_condition.l1.date.year = GetAddingDataYear(0, 1, 0);
			PChar.quest.Hit_timer3.win_condition = "Hit_END_timer";

		break;

		case "Hit_timer4":

			PChar.quest.Hit_timer4.win_condition.l1 = "Timer";
			PChar.quest.Hit_timer4.win_condition.l1.date.day = GetAddingDataDay(0, 1, 0);
			PChar.quest.Hit_timer4.win_condition.l1.date.month = GetAddingDataMonth(0, 1, 0);
			PChar.quest.Hit_timer4.win_condition.l1.date.year = GetAddingDataYear(0, 1, 0);
			PChar.quest.Hit_timer4.win_condition = "Hit_END_timer";

		break;

		case "Hit_timer5":

			PChar.quest.Hit_timer5.win_condition.l1 = "Timer";
			PChar.quest.Hit_timer5.win_condition.l1.date.day = GetAddingDataDay(0, 1, 0);
			PChar.quest.Hit_timer5.win_condition.l1.date.month = GetAddingDataMonth(0, 1, 0);
			PChar.quest.Hit_timer5.win_condition.l1.date.year = GetAddingDataYear(0, 1, 0);
			PChar.quest.Hit_timer5.win_condition = "Hit_END_timer";

		break;

		case "Hit_refused_Ambroz":

		// dialog exit from Ambroz

			DeleteEnterLocationQuest("Conceicao_tavern", "Hit_start_check");

			LAi_ActorGoToLocation(CharacterFromID("Ambroz Bricenos"), "reload", "reload1", "none", "", "", "Hit_refused_Ambroz_end", 3.0);

		break;

		case "Hit_refused_Ambroz_end":

			EndQuestMovie();

			bDisableFastReload = 0;

			//END QUEST

			LAi_QuestDelay("Hit_END", 0.0);

		break;

		case "Hit_start1":

		// dialog exit from Ambroz

			DeleteEnterLocationQuest("Conceicao_tavern", "Hit_start_check");

			PChar.quest.Hitman = "goto_mateus";

			LAi_ActorGoToLocation(CharacterFromID("Ambroz Bricenos"), "reload", "reload1", "Conceicao_shore_02", "goto", "citizen06", "Hit_start2", 3.0);

			chrEnableReloadLocator("Muelle_town_01", "reload21", 1);

			//Add journal entry

			SetQuestHeader("Hitman");
			AddQuestRecord("Hitman", "1");

		break;

		case "Hit_start2":

			EndQuestMovie();

			bDisableFastReload = 0;

			LAi_SetWarriorType(CharacterFromID("Ambroz Bricenos"));
			LAi_warrior_SetStay(CharacterFromID("Ambroz Bricenos"), 1);
			LAi_warrior_DialogEnable(CharacterFromID("Ambroz Bricenos"), 1);

			PChar.quest.Hit_start3.win_condition.l1 = "location";
			PChar.quest.Hit_start3.win_condition.l1.location = "Hit_house";
			PChar.quest.Hit_start3.win_condition = "Hit_start3";

		break;

		case "Hit_start3":

			StartQuestMovie(true, false, false);

			LAi_SetActorType(PChar);

			Characters[GetCharacterIndex("Mateus Santos")].dialog.currentnode = "start";

			LAi_ActorDialog(PChar, CharacterFromID("Mateus Santos"), "", 10.0, -1);

		break;

		case "Hit_refused_Mateus":

		// dialog exit from Mateus

			EndQuestMovie();

			bDisableFastReload = 1;

			LAi_SetPlayerType(PChar);
/*
			LAi_SetWarriorType(CharacterFromID("Mateus Santos"));
			LAi_SetWarriorType(CharacterFromID("Thug1"));
			LAi_SetWarriorType(CharacterFromID("Thug2"));
			LAi_SetWarriorType(CharacterFromID("Thug3"));
*/
			LAi_warrior_DialogEnable(CharacterFromID("Mateus Santos"), 0);
			LAi_warrior_DialogEnable(CharacterFromID("Thug1"), 4);
			LAi_warrior_DialogEnable(CharacterFromID("Thug2"), 0);
			LAi_warrior_DialogEnable(CharacterFromID("Thug3"), 0);

			PChar.quest.Hit_refused_Mateus_end.win_condition.l1 = "location";
			PChar.quest.Hit_refused_Mateus_end.win_condition.l1.character = PChar.id;
			PChar.quest.Hit_refused_Mateus_end.win_condition.l1.location = "Muelle_town_01";
			PChar.quest.Hit_refused_Mateus_end.win_condition = "Hit_refused_Mateus_end";

		break;

		case "Hit_refused_Mateus_end":

			bDisableFastReload = 0;

			//END QUEST

			LAi_QuestDelay("Hit_END", 0.0);

			//Add journal entry

			AddQuestRecord("Hitman", "20");

		break;

		case "Hit_die":

		// dialog exit from Mateus

			EndQuestMovie();

			LAi_SetPlayerType(PChar);

			StartQuestMovie(true, false, false);

			bDisableFastReload = 1;

			LAi_SetImmortal(CharacterFromID("Mateus Santos"), 1);
			LAi_SetImmortal(CharacterFromID("Thug1"), 1);
			LAi_SetImmortal(CharacterFromID("Thug2"), 1);
			LAi_SetImmortal(CharacterFromID("Thug3"), 1);

			LAi_SetActorType(CharacterFromID("Mateus Santos"));
			LAi_SetActorType(CharacterFromID("Thug1"));
			LAi_SetActorType(CharacterFromID("Thug2"));
			LAi_SetActorType(CharacterFromID("Thug3"));

			LAi_ActorAttack(CharacterFromID("Mateus Santos"), PChar, "");
			LAi_ActorAttack(CharacterFromID("Thug1"), PChar, "");
			LAi_ActorAttack(CharacterFromID("Thug2"), PChar, "");
			LAi_ActorAttack(CharacterFromID("Thug3"), PChar, "");

		break;

		case "Hit_mark_Ambroz":

		// dialog exit from Mateus

			EndQuestMovie();

			LAi_SetPlayerType(PChar);

			PChar.quest.Hitman = "mark_ambroz";

			LAi_SetImmortal(CharacterFromID("Ambroz Bricenos"), 0);

			LAi_SetCheckMinHP(CharacterFromID("Ambroz Bricenos"), 0.0, 0, "Hit_killed_Ambroz");

			//TIMER 1

			LAi_QuestDelay("Hit_timer1", 0.0);

			//Add journal entry

			AddQuestRecord("Hitman", "2");

		break;

		case "Hit_kill_Ambroz":

		// dialog exit from Ambroz

			StartQuestMovie(true, false, false);

			bDisableFastReload = 1;

			LAi_SetPlayerType(PChar);

			LAi_SetActorType(CharacterFromID("Ambroz Bricenos"));

			LAi_ActorAttack(CharacterFromID("Ambroz Bricenos"), PChar, "");

		break;

		case "Hit_killed_Ambroz":

			EndQuestMovie();

			bDisableFastReload = 0;

			PChar.quest.Hitman = "hit_ambroz";

			Characters[GetCharacterIndex("Ambroz Bricenos")].Location = "none";

			//KILL TIMER 1

			Pchar.quest.Hit_timer1.over = "yes";

			//Add journal entry

			AddQuestRecord("Hitman", "3");

			//Give XP

			AddPartyExp(PChar, 2500);

		break;

		case "Hit_spared_Ambroz":

		// dialog exit from Ambroz

			StartQuestMovie(true, false, false);

			bDisableFastReload = 1;

			LAi_SetPlayerType(PChar);

			LAi_SetActorType(CharacterFromID("Ambroz Bricenos"));

			LAi_ActorRunToLocation(CharacterFromID("Ambroz Bricenos"), "reload", "locator3", "none", "", "", "Hit_spared_Ambroz_end", 7.0);

		break;

		case "Hit_spared_Ambroz_end":

			EndQuestMovie();

			bDisableFastReload = 0;

			//END QUEST

			LAi_QuestDelay("Hit_END", 0.0);

			//KILL TIMER 1

			Pchar.quest.Hit_timer1.over = "yes";

			//Add journal entry

			AddQuestRecord("Hitman", "4");

			//Give XP

			AddPartyExp(pchar, 2500);

		break;

		case "Hit_mark_Geffrey":

		// dialog exit from Mateus

			PChar.quest.Hitman = "mark_geffrey";

			PChar.quest.Hit_Geffrey.win_condition.l1 = "location";
			PChar.quest.Hit_Geffrey.win_condition.l1.character = PChar.id;
			PChar.quest.Hit_Geffrey.win_condition.l1.location = "Hit_house1";
			PChar.quest.Hit_Geffrey.win_condition = "Hit_Geffrey";

			chrEnableReloadLocator("Greenford_town", "reload5", 1);

			//TIMER 2

			LAi_QuestDelay("Hit_timer2", 0.0);

			//Add journal entry

			AddQuestRecord("Hitman", "5");

		break;

		case "Hit_Geffrey":

			StartQuestMovie(true, false, false);

			bDisableFastReload = 1;

			LAi_LocationFightDisable(&Locations[FindLocation("Hit_house1")], 1);

			LAi_SetActorType(PChar);

			LAi_SetActorType(CharacterFromID("Bucho"));

			LAi_ActorTurnToCharacter(CharacterFromID("Bucho"), PChar);

			LAi_ActorDialog(PChar, CharacterFromID("Geffrey Bampfylde"), "", 2.0, -1);

		break;

		case "Hit_talk_to_Bucho":

		// dialog exit from Geffrey

			LAi_SetPlayerType(PChar);

			LAi_ActorDialog(CharacterFromID("Bucho"), PChar, "", 1.0, -1);

		break;

		case "Hit_kill_Bucho":

		// dialog exit from Bucho

			LAi_LocationFightDisable(&Locations[FindLocation("Hit_house1")], 0);

			LAi_SetImmortal(CharacterFromID("Bucho"), 0);

			LAi_ActorAttack(CharacterFromID("Bucho"), PChar, "");

			LAi_SetCheckMinHP(CharacterFromID("Bucho"), 0.0, 0, "Hit_killed_Bucho");

		break;

		case "Hit_killed_Bucho":

			Characters[GetCharacterIndex("Bucho")].Location = "none";

			Characters[GetCharacterIndex("Geffrey Bampfylde")].dialog.currentnode = "plea";

			LAi_SetActorType(CharacterFromID("Geffrey Bampfylde"));

			LAi_SetStayType(PChar);

			LAi_SetPlayerType(PChar);

			LAi_ActorDialog(CharacterFromID("Geffrey Bampfylde"), PChar, "", 4.0, -1);

			//Give XP

			AddPartyExp(pchar, 1750);

		break;

		case "Hit_spare_Geffrey":

		// dialog exit from Geffrey

			LAi_ActorRunToLocation(CharacterFromID("Geffrey Bampfylde"), "reload", "reload1", "none", "", "", "Hit_spared_Geffrey", 4.0);

		break;

		case "Hit_spared_Geffrey":

			EndQuestMovie();

			bDisableFastReload = 0;

			//END QUEST

			LAi_QuestDelay("Hit_END", 0.0);

			//KILL TIMER

			Pchar.quest.Hit_timer2.over = "yes";

			//Add journal entry

			AddQuestRecord("Hitman", "7");

			//Give XP

			AddPartyExp(pchar, 3000);

		break;

		case "Hit_kill_Geffrey":

		// dialog exit from Geffrey

			LAi_CharacterDisableDialog(CharacterFromID("Geffrey Bampfylde"));
			LAi_SetImmortal(CharacterFromID("Geffrey Bampfylde"), 0);
			GiveItem2Character(CharacterFromId("Geffrey Bampfylde"), "blade5");
			EquipCharacterByItem(CharacterFromId("Geffrey Bampfylde"), "blade5");

			LAi_ActorAttack(CharacterFromID("Geffrey Bampfylde"), PChar, "");

			LAi_SetCheckMinHP(CharacterFromID("Geffrey Bampfylde"), 0.0, 0, "Hit_killed_Geffrey");

		break;

		case "Hit_killed_Geffrey":

			EndQuestMovie();

			bDisableFastReload = 0;

			PChar.quest.Hitman = "hit_geffrey";

			Characters[GetCharacterIndex("Geffrey Bampfylde")].Location = "none";

			//KILL TIMER

			Pchar.quest.Hit_timer2.over = "yes";

			//Add journal entry

			AddQuestRecord("Hitman", "6");

			//Give XP

			AddPartyExp(pchar, 3000);

		break;

		case "Hit_mark_Pepin":

		// dialog exit from Mateus

			PChar.quest.Hitman = "mark_pepin";

			ChangeCharacterAddressGroup(CharacterFromID("Pepin Bertillon"), "QC_port", "goto", "goto12");
			ChangeCharacterAddressGroup(CharacterFromID("Bertillon's guard1"), "QC_port", "goto", "character11");
			ChangeCharacterAddressGroup(CharacterFromID("Bertillon's guard2"), "QC_port", "goto", "character12");

			LAi_SetImmortal(CharacterFromID("Pepin Bertillon"), 0);
			LAi_SetImmortal(CharacterFromID("Bertillon's guard1"), 0);
			LAi_SetImmortal(CharacterFromID("Bertillon's guard2"), 0);

			LAi_SetWarriorType(CharacterFromID("Pepin Bertillon"));
			LAi_SetWarriorType(CharacterFromID("Bertillon's guard1"));
			LAi_SetWarriorType(CharacterFromID("Bertillon's guard2"));

			LAi_warrior_DialogEnable(CharacterFromID("Pepin Bertillon"), 1);
			LAi_warrior_DialogEnable(CharacterFromID("Bertillon's guard1"), 1);
			LAi_warrior_DialogEnable(CharacterFromID("Bertillon's guard2"), 1);

			LAi_group_MoveCharacter(CharacterFromID("Pepin Bertillon"), "Bertillon_Group");
			LAi_group_MoveCharacter(CharacterFromID("Bertillon's guard1"), "Bertillon_Group");
			LAi_group_MoveCharacter(CharacterFromID("Bertillon's guard2"), "Bertillon_Group");

			PChar.quest.Hit_goto_QC_port.win_condition.l1 = "location";
			PChar.quest.Hit_goto_QC_port.win_condition.l1.character = PChar.id;
			PChar.quest.Hit_goto_QC_port.win_condition.l1.location = "QC_port";
			PChar.quest.Hit_goto_QC_port.win_condition = "Hit_goto_QC_port";

			//TIMER 3

			LAi_QuestDelay("Hit_timer3", 0.0);

			//Add journal entry

			AddQuestRecord("Hitman", "8");

		break;

		case "Hit_goto_QC_port":

			LAi_warrior_SetCommander(CharacterFromID("Bertillon's guard1"), CharacterFromID("Pepin Bertillon"));
			LAi_warrior_SetCommander(CharacterFromID("Bertillon's guard2"), CharacterFromID("Pepin Bertillon"));

			LAi_group_SetCheck("Bertillon_Group", "Hit_killed_Pepin");

			LAi_SetActorType(PChar);

			LAi_ActorSelfDialog(PChar, "Hit_goto_QC_port1");

		break;

		case "Hit_goto_QC_port1":

			LAi_SetPlayerType(PChar);

		break;

		case "Hit_spare_Pepin":

		// dialog exit from Pepin

			LAi_SetImmortal(CharacterFromID("Pepin Bertillon"), 1);
			LAi_SetImmortal(CharacterFromID("Bertillon's guard1"), 1);
			LAi_SetImmortal(CharacterFromID("Bertillon's guard2"), 1);

			LAi_SetActorType(CharacterFromID("Pepin Bertillon"));
			LAi_SetActorType(CharacterFromID("Bertillon's guard1"));
			LAi_SetActorType(CharacterFromID("Bertillon's guard2"));

			LAi_ActorGoToLocation(CharacterFromID("Pepin Bertillon"), "reload", "reload2", "none", "", "", "", 7.0);
			LAi_ActorGoToLocation(CharacterFromID("Bertillon's guard1"), "reload", "reload2", "none", "", "", "", 7.0);
			LAi_ActorGoToLocation(CharacterFromID("Bertillon's guard2"), "reload", "reload2", "none", "", "", "", 7.0);

			LAi_QuestDelay("Hit_spared_Pepin", 0.0);

		break;

		case "Hit_spared_Pepin":

			//END QUEST

			LAi_QuestDelay("Hit_END", 0.0);

			//KILL TIMER

			Pchar.quest.Hit_timer3.over = "yes";

			//Add journal entry

			AddQuestRecord("Hitman", "10");

			//Give XP

			AddPartyExp(pchar, 2000);

		break;

		case "Hit_kill_Pepin":

		// dialog exit from Pepin

			LAi_warrior_DialogEnable(CharacterFromID("Pepin Bertillon"), 0);
			LAi_warrior_DialogEnable(CharacterFromID("Bertillon's guard1"), 0);
			LAi_warrior_DialogEnable(CharacterFromID("Bertillon's guard2"), 0);

			LAi_group_FightGroups("Bertillon_Group", LAI_GROUP_PLAYER, 1);

		break;

		case "Hit_killed_Pepin":

			EndQuestMovie();

			PChar.quest.Hitman = "hit_pepin";

			Characters[GetCharacterIndex("Pepin Bertillon")].Location = "none";
			Characters[GetCharacterIndex("Bertillon's guard1")].Location = "none";
			Characters[GetCharacterIndex("Bertillon's guard2")].Location = "none";

			//KILL TIMER

			Pchar.quest.Hit_timer3.over = "yes";

			//Add journal entry

			AddQuestRecord("Hitman", "9");

			//Give XP

			AddPartyExp(pchar, 4500);

		break;

		case "Hit_mark_Amerigo":

		// dialog exit from Mateus

			PChar.quest.Hitman = "mark_amerigo";

			PChar.quest.Hit_Amerigo.win_condition.l1 = "location";
			PChar.quest.Hit_Amerigo.win_condition.l1.character = PChar.id;
			PChar.quest.Hit_Amerigo.win_condition.l1.location = "Hit_house2";
			PChar.quest.Hit_Amerigo.win_condition = "Hit_Amerigo";

			chrEnableReloadLocator("Conceicao_town", "reload15", 1);

			//TIMER 4

			LAi_QuestDelay("Hit_timer4", 0.0);

			//Add journal entry

			AddQuestRecord("Hitman", "11");

		break;

		case "Hit_Amerigo":

			StartQuestMovie(true, false, false);

			bDisableFastReload = 1;

			LAi_SetActorType(PChar);

			LAi_ActorDialog(PChar, CharacterFromID("Amerigo Vieira"), "", 4.0, -1);

		break;

		case "Hit_kill_Amerigo":

		// dialog exit from Amerigo

			LAi_SetPlayerType(PChar);

			LAi_SetActorType(CharacterFromID("Amerigo Vieira"));

			LAi_SetImmortal(CharacterFromID("Amerigo Vieira"), 0);

			LAi_ActorAttack(CharacterFromID("Amerigo Vieira"), PChar, "");

			LAi_SetCheckMinHP(CharacterFromID("Amerigo Vieira"), 0.0, 0, "Hit_killed_Amerigo");

		break;

		case "Hit_killed_Amerigo":

			EndQuestMovie();

			bDisableFastReload = 0;

			PChar.quest.Hitman = "hit_amerigo";

			Characters[GetCharacterIndex("Amerigo Vieira")].Location = "none";

			//KILL TIMER

			Pchar.quest.Hit_timer4.over = "yes";

			//Add journal entry

			AddQuestRecord("Hitman", "12");

			//Give XP

			AddPartyExp(pchar, 6000);

		break;

		case "Hit_spare_Amerigo":

		// dialog exit from Amerigo

			LAi_SetPlayerType(PChar);

			LAi_SetActorType(CharacterFromID("Amerigo Vieira"));

			LAi_ActorRunToLocation(CharacterFromID("Amerigo Vieira"), "reload", "reload1", "none", "", "", "Hit_spared_Amerigo", 3.0);

		break;

		case "Hit_spared_Amerigo":

			EndQuestMovie();

			bDisableFastReload = 0;

			//END QUEST

			LAi_QuestDelay("Hit_END", 0.0);

			//KILL TIMER

			Pchar.quest.Hit_timer4.over = "yes";

			//Add journal entry

			AddQuestRecord("Hitman", "13");

			//Give XP

			AddPartyExp(pchar, 4000);

		break;

		case "Hit_join_Amerigo":

		// dialog exit from Amerigo

			EndQuestMovie();

			bDisableFastReload = 0;

			LAi_SetPlayerType(PChar);

			LAi_SetOfficerType(CharacterFromID("Amerigo Vieira"));

			LAi_SetImmortal(CharacterFromID("Amerigo Vieira"), 0);

			SetOfficersIndex(PChar, -1, GetCharacterIndex("Amerigo Vieira"));

			//END QUEST

			LAi_QuestDelay("Hit_END", 0.0);

			//KILL TIMER

			Pchar.quest.Hit_timer4.over = "yes";

			//Add journal entry

			AddQuestRecord("Hitman", "14");

			//Give XP

			AddPartyExp(pchar, 5000);

		break;

		case "Hit_mark_Vito":

		// dialog exit from Mateus

			PChar.quest.Hitman = "mark_vito";

			LAi_SetSitType(CharacterFromID("Vito Leone"));

			ChangeCharacterAddressGroup(CharacterFromID("Vito Leone"), "Conceicao_church", "sit", "sit14");

			//TIMER 5

			LAi_QuestDelay("Hit_timer5", 0.0);

			//Add journal entry

			AddQuestRecord("Hitman", "15");

		break;

		case "Hit_kill_Vito":

		// dialog exit from Vito

			bDisableFastReload = 1;

			LAi_LocationFightDisable(&Locations[FindLocation("Conceicao_church")], 0);

			LAi_SetActorType(CharacterFromID("Vito Leone"));
			LAi_SetImmortal(CharacterFromID("Vito Leone"), 0);
			LAi_CharacterDisableDialog(CharacterFromID("Vito Leone"));

			LAi_SetCheckMinHP(CharacterFromID("Vito Leone"), 0.0, 0, "Hit_killed_Vito");

		break;

		case "Hit_killed_Vito":

			PChar.quest.Hitman = "hit_vito";

			bDisableFastReload = 0;

			LAi_LocationFightDisable(&Locations[FindLocation("Conceicao_church")], 1);

			Characters[GetCharacterIndex("Vito Leone")].Location = "none";

			//KILL TIMER

			Pchar.quest.Hit_timer5.over = "yes";

			//Add journal entry

			AddQuestRecord("Hitman", "16");

			//Give XP

			AddPartyExp(pchar, 7000);

		break;

		case "Hit_spare_Vito":

		// dialog exit from Vito

			bDisableFastReload = 1;

			LAi_CharacterDisableDialog(CharacterFromID("Vito Leone"));

			Characters[GetCharacterIndex("Vito Leone")].Location = "none";

			PChar.quest.Hit_spared_Vito.win_condition.l1 = "location";
			PChar.quest.Hit_spared_Vito.win_condition.l1.character = PChar.id;
			PChar.quest.Hit_spared_Vito.win_condition.l1.location = "Conceicao_town";
			PChar.quest.Hit_spared_Vito.win_condition = "Hit_spared_Vito";

		break;

		case "Hit_spared_Vito":

			bDisableFastReload = 0;

			//END QUEST

			LAi_QuestDelay("Hit_END", 0.0);

			//KILL TIMER

			Pchar.quest.Hit_timer5.over = "yes";

			//Add journal entry

			AddQuestRecord("Hitman", "17");

			//Give XP

			AddPartyExp(pchar, 4000);

		break;

		case "Hit_mark_Mateus":

		// dialog exit from Vito

			PChar.quest.Hitman = "mark_mateus";

			ChangeCharacterAddressGroup(CharacterFromID("Mateus Santos"), "Muelle_tavern_upstairs", "goto", "goto4");

			PChar.quest.Hit_Mateus.win_condition.l1 = "location";
			PChar.quest.Hit_Mateus.win_condition.l1.character = PChar.id;
			PChar.quest.Hit_Mateus.win_condition.l1.location = "Muelle_tavern_upstairs";
			PChar.quest.Hit_Mateus.win_condition = "Hit_Mateus";

			//KILL TIMER

			Pchar.quest.Hit_timer5.over = "yes";

			//Add journal entry

			AddQuestRecord("Hitman", "18");

		break;

		case "Hit_Mateus":

			StartQuestMovie(true, false, false);

			bDisableFastReload = 1;

			LAi_SetActorType(PChar);

			LAi_ActorDialog(PChar, CharacterFromID("Mateus Santos"), "", 4.0, -1);

		break;

		case "Hit_kill_Mateus":

		// dialog exit from Mateus

			LAi_SetPlayerType(PChar);

			LAi_SetActorType(CharacterFromID("Mateus Santos"));

			LAi_SetImmortal(CharacterFromID("Mateus Santos"), 0);

			LAi_ActorAttack(CharacterFromID("Mateus Santos"), PChar, "");

			LAi_SetCheckMinHP(CharacterFromID("Mateus Santos"), 0.0, 0, "Hit_killed_Mateus");

		break;

		case "Hit_killed_Mateus":

			EndQuestMovie();

			PChar.quest.Hitman = "hit_mateus";

			Characters[GetCharacterIndex("Mateus Santos")].Location = "none";

			LAi_SetStayType(CharacterFromID("Vito Leone"));
			ChangeCharacterAddressGroup(CharacterFromID("Vito Leone"), "Muelle_tavern", "goto", "goto4");

			PChar.quest.Hit_congrats.win_condition.l1 = "locator";
			PChar.quest.Hit_congrats.win_condition.l1.location = "Muelle_tavern";
			PChar.quest.Hit_congrats.win_condition.l1.locator_group = "goto";
			PChar.quest.Hit_congrats.win_condition.l1.locator = "goto7";
			PChar.quest.Hit_congrats.win_condition.l1.character = PChar.id;
			PChar.quest.Hit_congrats.win_condition = "Hit_congrats";

			//Give XP

			AddPartyExp(pchar, 7000);

		break;

		case "Hit_congrats":

			StartQuestMovie(true, false, false);

			LAi_SetActorType(PChar);

			LAi_ActorDialog(PChar, CharacterFromID("Vito Leone"), "", 4.0, -1);

		break;

		case "Hit_complete":

		// dialog exit from Vito

			LAi_SetPlayerType(PChar);

			LAi_SetActorType(CharacterFromID("Vito Leone"));

			LAi_ActorGoToLocation(CharacterFromID("Vito Leone"), "reload", "reload1", "none", "", "", "Hit_complete_end", 2.0);

		break;

		case "Hit_complete_end":

			EndQuestMovie();

			bDisableFastReload = 0;

			//END QUEST

			LAi_QuestDelay("Hit_END", 0.0);

			//Add journal entry

			AddQuestRecord("Hitman", "19");
			CloseQuestHeader("Hitman");

		break;

//Hitman


	//Lucas

		case "Luc_start":
			SetEnterLocationQuest("Muelle_residence", "Luc_start_check", 0);
		break;

		case "Luc_start_check":
			if(makeint(PChar.rank) >= 4)
			{
				ChangeCharacterAddressGroup(CharacterFromID("Joaquin Da Saldanha"), "Muelle_Residence", "goto", "goto6");
			}
		break;

		case "Lucas_search_refused":
			PChar.quest.Lucas = "refused";

			DeleteEnterLocationQuest("Muelle_residence", "Luc_start_check");
		break;

		case "Lucas_search_start":
			PChar.quest.Lucas = "search";

			DeleteEnterLocationQuest("Muelle_residence", "Luc_start_check");

			//JOURNAL
			SetQuestHeader("Lucas");
			AddQuestRecord("Lucas", "1");
		break;

		case "Lucas_search1":

			PChar.quest.Lucas = "search1";

			ChangeCharacterAddressGroup(CharacterFromID("Arabella Silehard"), "Redmond_jungle_01", "goto", "goto9");
			ChangeCharacterAddressGroup(CharacterFromID("Arabella's guard 1"), "Redmond_jungle_01", "goto", "goto10");
			ChangeCharacterAddressGroup(CharacterFromID("Arabella's guard 2"), "Redmond_jungle_01", "goto", "goto11");
			LAi_group_MoveCharacter(CharacterFromID("Arabella Silehard"), "ARABELLA");
			LAi_group_MoveCharacter(CharacterFromID("Arabella's guard 1"), "ARABELLA");
			LAi_group_MoveCharacter(CharacterFromID("Arabella's guard 2"), "ARABELLA");
			LAi_SetImmortal(CharacterFromID("Arabella Silehard"), true);
			LAi_SetImmortal(CharacterFromID("Arabella's guard 1"), true);
			LAi_SetImmortal(CharacterFromID("Arabella's guard 2"), true);
			LAi_group_SetRelation("ARABELLA", "ARABELLA", LAI_GROUP_FRIEND);
			LAi_group_SetAlarmReaction("ARABELLA", LAI_GROUP_PLAYER, LAI_GROUP_NEITRAL, LAI_GROUP_NEITRAL);

			//JOURNAL
			AddQuestRecord("Lucas", "2");

		break;

		case "Lucas_search2":

			PChar.quest.Lucas = "search2";

			//JOURNAL
			AddQuestRecord("Lucas", "3");

		break;

		case "Lucas_ransom_refused":

			StartQuestMovie(true, false, false);
			bDisableFastReload = 1;

			LAi_SetActorType(CharacterFromID("Joaquin Da Saldanha"));
			LAi_CharacterDisableDialog(CharacterFromID("Joaquin Da Saldanha"));
			LAi_ActorGoToLocation(CharacterFromID("Joaquin Da Saldanha"), "reload", "reload1", "none", "", "", "Lucas_ransom_refused1", 3.0);

			//JOURNAL
			AddQuestRecord("Lucas", "4");
			CloseQuestHeader("Lucas");

		break;

		case "Lucas_ransom_refused1":

			EndQuestMovie();
			bDisableFastReload = 0;

		break;

		case "Lucas_ransom_start":
			PChar.quest.Lucas = "ransom";

			AddMoneyToCharacter(PChar, 20000);

			ChangeCharacterAddressGroup(CharacterFromID("Billy Brock"), "Falaise_de_fleur_tavern", "goto", "goto3");
			ChangeCharacterAddressGroup(CharacterFromID("Snorri Baldursson"), "Falaise_de_fleur_tavern", "goto", "goto2");
			ChangeCharacterAddressGroup(CharacterFromID("Francis Snake"), "Ransom_house_f2", "goto", "goto1");
			ChangeCharacterAddressGroup(CharacterFromID("Lucas Da Saldanha"), "Ransom_house_f2", "goto", "goto4");
			Locations[FindLocation("Falaise_De_Fleur_location_03")].reload.l12.close_for_night = 0;
			Locations[FindLocation("Falaise_De_Fleur_location_03")].reload.l12.label = "Kidnappers' Hideout";

			PChar.quest.Lucas_ransom_deadline.win_condition.l1 = "Timer";
			PChar.quest.Lucas_ransom_deadline.win_condition.l1.date.day = GetAddingDataDay(0, 1, 0);
			PChar.quest.Lucas_ransom_deadline.win_condition.l1.date.month = GetAddingDataMonth(0, 1, 0);
			PChar.quest.Lucas_ransom_deadline.win_condition.l1.date.year = GetAddingDataYear(0, 1, 0);
			PChar.quest.Lucas_ransom_deadline.win_condition = "Lucas_ransom_deadline";

			PChar.quest.Lucas_ransom_delivery.win_condition.l1 = "location";
			PChar.quest.Lucas_ransom_delivery.win_condition.l1.character = PChar.id;
			PChar.quest.Lucas_ransom_delivery.win_condition.l1.location = "Falaise_de_fleur_tavern";
			PChar.quest.Lucas_ransom_delivery.win_condition = "Lucas_ransom_delivery";

			//JOURNAL
			AddQuestRecord("Lucas", "5");
		break;

		case "Lucas_ransom_deadline":
			DisableFastTravel(false);
			DisableMenuLaunch(false);
			SetNationRelation2MainCharacter(SPAIN, RELATION_ENEMY);

			ChangeCharacterAddressGroup(CharacterFromID("Joaquin Da Saldanha"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Arabella Silehard"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Arabella's guard 1"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Arabella's guard 2"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Billy Brock"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Snorri Baldursson"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Francis Snake"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Lucas Da Saldanha"), "none", "", "");

			//JOURNAL
			AddQuestRecord("Lucas", "14");
			CloseQuestHeader("Lucas");
		break;

		case "Lucas_ransom_delivery":
			StartQuestMovie(true, false, false);
			bDisableFastReload = 1;

			LAi_SetActorType(CharacterFromID("Billy Brock"));
			LAi_SetActorType(CharacterFromID("Snorri Baldursson"));

			LAi_ActorTurnToCharacter(CharacterFromID("Billy Brock"), CharacterFromID("Snorri Baldursson"));
			LAi_ActorTurnToCharacter(CharacterFromID("Snorri Baldursson"), CharacterFromID("Billy Brock"));

			LAi_SetActorType(PChar);
			LAi_ActorSelfDialog(PChar, "");
		break;

		case "Lucas_ransom_delivery1":
		//dialog exit from self
			LAi_ActorGoToLocator(PChar, "goto", "goto6", "Lucas_ransom_delivery2", 3.0);
		break;

		case "Lucas_ransom_delivery2":
			Pchar.dialog.CurrentNode = "Eavesdrop1";
			LAi_ActorTurnToCharacter(PChar, CharacterFromID("Billy Brock"));
			LAi_ActorSelfDialog(PChar, "");
		break;

		case "Lucas_sign1":
		//dialog exit from Self
			PChar.quest.Lucas = "sign";
			LAi_SetPlayerType(PChar);
			LAi_ActorDialog(CharacterFromID("Billy Brock"), PChar, "", 4.0, -1);
		break;

		case "Lucas_sign2":
		//dialog exit from Brock
			LAi_ActorGoToLocation(CharacterFromID("Billy Brock"), "reload", "reload1", "Falaise_de_fleur_location_03", "goto", "sitizen04", "Lucas_sign3", 5.0);
		break;

		case "Lucas_sign3":
			EndQuestMovie();
			PChar.quest.Lucas_sign4.win_condition.l1 = "location";
			PChar.quest.Lucas_sign4.win_condition.l1.character = PChar.id;
			PChar.quest.Lucas_sign4.win_condition.l1.location = "Falaise_de_fleur_location_03";
			PChar.quest.Lucas_sign4.win_condition = "Lucas_sign4";
		break;

		case "Lucas_sign4":
			StartQuestMovie(true, false, false);
			LAi_ActorGoToLocation(CharacterFromID("Billy Brock"), "reload", "home7", "Ransom_house_f1", "goto", "goto3", "Lucas_sign5", 10.0);
		break;

		case "Lucas_sign5":
			EndQuestMovie();
			bDisableFastReload = 0;
			PChar.quest.Lucas_sign6.win_condition.l1 = "location";
			PChar.quest.Lucas_sign6.win_condition.l1.character = PChar.id;
			PChar.quest.Lucas_sign6.win_condition.l1.location = "Ransom_house_f1";
			PChar.quest.Lucas_sign6.win_condition = "Lucas_sign6";
		break;

		case "Lucas_sign6":
			StartQuestMovie(true, false, false);
			bDisableFastReload = 1;
			LAi_LocationFightDisable(&Locations[FindLocation("Ransom_house_f1")], 1);
			PChar.quest.Lucas = "sign1";
			LAi_ActorDialog(CharacterFromID("Billy Brock"), PChar, "", 4.0, -1);
		break;

		case "Lucas_sign7":
		//dialog exit from Brock
			PChar.quest.Lucas = "sign2";
			LAi_ActorGoToLocation(CharacterFromID("Billy Brock"), "reload", "reload2", "none", "", "", "Lucas_sign8", 10.0);
		break;

		case "Lucas_sign8":
			LAi_QuestDelay("Lucas_sign9", 3.0);
		break;

		case "Lucas_sign9":
			ChangeCharacterAddressGroup(CharacterFromID("Francis Snake"), "Ransom_house_f1", "reload", "reload2");
			LAi_SetActorType(CharacterFromID("Francis Snake"));
			LAi_ActorGoToLocator(CharacterFromID("Francis Snake"), "goto", "goto2", "Lucas_sign9_1", 10.0);

			LAi_QuestDelay("Lucas_sign10", 2.5);
		break;

		case "Lucas_sign9_1":
			LAi_ActorTurnToCharacter(CharacterFromID("Francis Snake"), PChar);
		break;


		case "Lucas_sign10":
			ChangeCharacterAddressGroup(CharacterFromID("Lucas Da Saldanha"), "Ransom_house_f1", "reload", "reload2");
			LAi_SetActorType(CharacterFromID("Lucas Da Saldanha"));
			LAi_ActorGoToLocator(CharacterFromID("Lucas Da Saldanha"), "goto", "goto1", "Lucas_sign10_1", 10.0);

			LAi_QuestDelay("Lucas_sign11", 2.5);
		break;

		case "Lucas_sign10_1":
			LAi_ActorTurnToCharacter(CharacterFromID("Lucas Da Saldanha"), PChar);
		break;

		case "Lucas_sign11":
			ChangeCharacterAddressGroup(CharacterFromID("Billy Brock"), "Ransom_house_f1", "reload", "reload2");
			LAi_ActorGoToLocator(CharacterFromID("Billy Brock"), "goto", "goto3", "Lucas_sign12", 10.0);
		break;

		case "Lucas_sign12":
			EndQuestMovie();

			LAi_ActorDialog(CharacterFromID("Billy Brock"), PChar, "", 3.0, -1);
		break;

		case "Lucas_kill":
			StartQuestMovie(true, false, false);

			LAi_LocationFightDisable(&Locations[FindLocation("Ransom_house_f1")], 0);

			LAi_KillCharacter(CharacterFromID("Lucas Da Saldanha"));

			LAi_SetWarriorType(CharacterFromID("Billy Brock"));
			LAi_SetWarriorType(CharacterFromID("Francis Snake"));

			LAi_group_MoveCharacter(CharacterFromID("Billy Brock"), "kidnappers");
			LAi_group_MoveCharacter(CharacterFromID("Francis Snake"), "kidnappers");

			LAi_group_FightGroups("kidnappers", LAI_GROUP_PLAYER, 1);

			LAi_group_SetCheck("kidnappers", "Lucas_killed");
		break;

		case "Lucas_killed":
			EndQuestMovie();

			DisableFastTravel(true);
			DisableMenuLaunch(true);

			DoQuestCheckDelay("Lucas_ransom_deadline", 3.0);
		break;

		case "Lucas_sign13":
		//dialog exit from Brock
			StartQuestMovie(true, false, false);

			AddMoneyToCharacter(PChar, -20000);
			LAi_type_actor_Reset(CharacterFromID("Billy Brock"));
			LAi_type_actor_Reset(CharacterFromID("Francis Snake"));
			LAi_ActorGoToLocation(CharacterFromID("Billy Brock"), "reload", "reload1", "none", "", "", "", 3.0);
			LAi_ActorGoToLocation(CharacterFromID("Francis Snake"), "reload", "reload1", "none", "", "", "Lucas_talk1", 4.0);
		break;

		case "Lucas_talk1":
			Characters[GetCharacterIndex("Lucas Da Saldanha")].dialog.CurrentNode = "free";
			LAi_type_actor_Reset(CharacterFromID("Lucas Da Saldanha"));
			LAi_ActorDialog(CharacterFromID("Lucas Da Saldanha"), PChar, "", 3.0, -1);
		break;

		case "Lucas_talk1_1":
		//dialog exit from Lucas
			EndQuestMovie();

			PChar.quest.Lucas = "return";

			GiveItem2Character(CharacterFromId("Lucas Da Saldanha"), "blade16");
			GiveItem2Character(CharacterFromId("Lucas Da Saldanha"),"pistol3");
			EquipCharacterByItem(CharacterFromId("Lucas Da Saldanha"), "blade16");
			EquipCharacterByItem(CharacterFromId("Lucas Da Saldanha"), "pistol3");

			LAi_SetImmortal(CharacterFromID("Lucas Da Saldanha"), 1);

			LAi_ActorFollowEverywhere(CharacterFromID("Lucas Da Saldanha"), "", 0.0);

			PChar.quest.Lucas_talk2.win_condition.l1 = "location";
			PChar.quest.Lucas_talk2.win_condition.l1.character = PChar.id;
			PChar.quest.Lucas_talk2.win_condition.l1.location = "Falaise_de_fleur_location_03";
			PChar.quest.Lucas_talk2.win_condition = "Lucas_talk2";

			//JOURNAL
			AddQuestRecord("Lucas", "7");
		break;

		case "Lucas_talk2":
			StartQuestMovie(true, false, false);

			LAi_LocationFightDisable(&Locations[FindLocation("Ransom_house_f1")], 0);
			Characters[GetCharacterIndex("Lucas Da Saldanha")].dialog.CurrentNode = "free1";

			LAi_ActorDialog(CharacterFromID("Lucas Da Saldanha"), PChar, "", 2.0, -1);
		break;

		case "Lucas_talk2_1":
			EndQuestMovie();

			bDisableFastReload = 0;

			LAi_ActorFollowEverywhere(CharacterFromID("Lucas Da Saldanha"), "", 0.0);

			PChar.quest.Lucas_return.win_condition.l1 = "location";
			PChar.quest.Lucas_return.win_condition.l1.character = PChar.id;
			PChar.quest.Lucas_return.win_condition.l1.location = "Muelle_Residence";
			PChar.quest.Lucas_return.win_condition = "Lucas_return";

			PChar.quest.Lucas_ransom_deadline.over = "yes";
		break;

		case "Lucas_return":
			StartQuestMovie(true, false, false);

			LAi_Type_Actor_Reset(CharacterFromID("Lucas Da Saldanha"));

			LAi_SetActorType(characterFromID("Joaquin Da Saldanha"));

			LAi_SetActorType(PChar);

			LAi_ActorGoToLocator(PChar, "goto", "goto7", "Lucas_return1", 1.0);

			LAi_ActorGoToLocator(CharacterFromID("Lucas Da Saldanha"), "goto", "goto9", "Lucas_return_1", 2.0);

			LAi_SetImmortal(CharacterFromID("Lucas Da Saldanha"), 0);
		break;

		case "Lucas_return_1":
			LAi_ActorTurnToCharacter(CharacterFromID("Joaquin Da Saldanha"), CharacterFromID("Lucas Da Saldanha"));
			LAi_ActorTurnToCharacter(CharacterFromID("Lucas Da Saldanha"), CharacterFromID("Joaquin Da Saldanha"));

			LAi_QuestDelay("Lucas_return1", 1.0);
		break;

		case "Lucas_return1":
			LAi_ActorTurnToCharacter(PChar, CharacterFromID("Joaquin Da Saldanha"));

			LAi_QuestDelay("Lucas_return1_1", 1.0);
		break;

		case "Lucas_return1_1":
		//dialog exit from self
			LAi_SetPlayerType(PChar);

			LAi_ActorDialog(CharacterFromID("Joaquin Da Saldanha"), PChar, "", 2.0, -1);
		break;

		case "Lucas_end":

		//dialog exit from Joaquin
			AddPartyExp(pchar, 20000);
			ChangeCharacterReputation(pchar, 20);
			SetNationRelation2MainCharacter(SPAIN, RELATION_FRIEND);
			AddMoneyToCharacter(PChar, +10000);

			LAi_CharacterDisableDialog(CharacterFromID("Joaquin Da Saldanha"));
			LAi_Type_Actor_Reset(CharacterFromID("Joaquin Da Saldanha"));
			LAi_ActorGoToLocation(CharacterFromID("Joaquin Da Saldanha"), "reload", "reload1", "none", "", "", "", 3.0);

			Characters[GetCharacterIndex("Lucas Da Saldanha")].dialog.CurrentNode = "join";
			LAi_ActorDialog(CharacterFromID("Lucas Da Saldanha"), PChar, "", 2.0, -1);

			//JOURNAL
			AddQuestRecord("Lucas", "9");
			CloseQuestHeader("Lucas");
		break;

		case "Lucas_join":
		//dialog exit from Lucas

			EndQuestMovie();

			LAi_Type_Actor_Reset(CharacterFromID("Lucas Da Saldanha"));
			SetOfficersIndex(PChar, -1, GetCharacterIndex("Lucas Da Saldanha"));
		break;

		case "Lucas_no_join":
		//dialog exit from Lucas
			LAi_ActorGoToLocator(CharacterFromID("Lucas Da Saldanha"), "goto", "goto4", "Lucas_no_join1", 3.0);
		break;

		case "Lucas_no_join1":
			EndQuestMovie();

			ChangeCharacterAddressGroup(CharacterFromID("Lucas Da Saldanha"), "Muelle_Residence", "goto", "goto4");

			Characters[GetCharacterIndex("Lucas Da Saldanha")].dialog.CurrentNode = "join_loop";

			LAi_SetStayType(CharacterFromID("Lucas Da Saldanha"));
		break;

//Lucas

//Artois Voysey
		case "Story_Artois":
			if (CheckQuestAttribute("main_line", "ines_info_denied"))
			{
				LAi_QuestDelay("Story_Artois", 4.0);
			}
			else
			{
				LAi_SetHP(characterFromID("Artois Voysey"), 50.0, 50.0);
				LAi_SetHP(characterFromID("Nigel Blythe"), 50.0, 50.0);
				LAi_SetActorType(CharacterFromID("Artois Voysey"));
				LAi_SetActorType(CharacterFromID("Nigel Blythe"));
				LAi_group_MoveCharacter(CharacterFromID("Artois Voysey"), "Artois");
				LAi_group_MoveCharacter(CharacterFromID("Nigel Blythe"), "Nigel");
				LAi_SetImmortal(CharacterFromID("Nigel Blythe"), true);
				LAi_ActorAttack(characterFromID("Nigel Blythe"), characterFromID("Artois Voysey"), "");
				LAi_ActorAttack(characterFromID("Artois Voysey"), characterFromID("Nigel Blythe"), "");
				LAi_SetCheckMinHP(characterFromID("Artois Voysey"), 20.0, true, "Story_Artois_2");
				LAi_SetActorType(pchar);
				LAi_ActorFollow(pchar, characterFromID("Nigel Blythe"), "", 25.0);
			}
			StartQuestMovie(true, false, false);
		break;
	
		case "Story_Artois_2":
			LAi_SetStayType(pchar);
			LAi_type_actor_Reset(characterFromID("Artois Voysey"));
			LAi_type_actor_Reset(characterFromID("Nigel Blythe"));
			LAi_ActorDialog(characterFromID("Nigel Blythe"), pchar, "", 2.0, 1.0);
		break;
		
		case "saving_artois":
			LAi_SetImmortal(characterFromID("Nigel Blythe"), false);
			LAi_SetPlayerType (Pchar);
			LAi_group_MoveCharacter(CharacterFromID("Nigel Blythe"), "nigel_2");
			//LAi_group_MoveCharacter(CharacterFromID("Artois Voysey"), "Artois");
			LAi_group_FightGroups("nigel_2", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("nigel_2", "Artois_saved");
		break;
		
		case "Artois_saved":
			EndQuestMovie();
			SetQuestHeader("Artois");
			AddQuestRecord("artois", "1");
			LAi_SetActorType(pchar);
			LAi_SetActorType(CharacterFromID("Artois Voysey"));
			LAi_ActorWaitDialog(CharacterFromID("Artois Voysey"), PChar);
			LAi_ActorDialog(PChar, CharacterFromID("Artois Voysey"), "", 2.0, 1.0);
		break;
	
		case "Voysey_listed":
			LAi_SetImmortal(characterFromID("Artois Voysey"), false);
		
			Pchar.quest.Artois_Voysey.win_condition.l1 = "location";
			Pchar.quest.Artois_Voysey.win_condition.l1.character = "Artois Voysey";
			Pchar.quest.Artois_Voysey.win_condition.l1.location = "Conceicao_port";
			PChar.quest.Artois_Voysey.win_condition = "Artois_missed";
	
			LAi_SetPlayerType(Pchar);
			SetOfficersIndex(Pchar, -1, GetCharacterIndex("Artois Voysey"));
			LAi_SetOfficerType(characterFromID("Artois Voysey"));
		break;
		
		case "Voysey_listed_2":
			LAi_SetImmortal(characterFromID("Artois Voysey"), false);
		
			LAi_SetPlayerType(Pchar);
			SetOfficersIndex(Pchar, -1, GetCharacterIndex("Artois Voysey"));
		break;
		
		case "Artois_missed":
			if(FindFellowTravellers(PChar, CharacterFromId("Artois Voysey")) == FELLOWTRAVEL_OFFICER || FindFellowTravellers(PChar, CharacterFromId("Artois Voysey")) == FELLOWTRAVEL_PASSENGER)
			{
				LAi_LocationMonstersGen(&locations[FindLocation("Conceicao_town_exit")], false);
				pchar.quest.Voysey_lost = "1";
				RemovePassenger(pchar, characterFromID("Artois Voysey"));
				
				LAi_SetActorType(Pchar);
				Pchar.Temp.self.dialog = Pchar.dialog.currentnode;
				Pchar.dialog.currentnode = "Artois_lost";
				LAi_ActorSelfDialog(Pchar, "player_back");
				AddQuestRecord("artois", "4");
				characters[GetCharacterIndex("Artois Voysey")].location = "Redmond_store";
				ChangeCharacterAddress(characterFromID("Artois Voysey"), "none", "");
			}
		break;
		
		case "artois_before_room_on_second_floor":
			AddQuestRecord("artois", "5");
			Locations[FindLocation("Conceicao_tavern")].reload.l2.disable = false;
			Pchar.quest.Blaze_arrest.win_condition.l1 = "location";
			Pchar.quest.Blaze_arrest.win_condition.l1.location = "Conceicao_tavern_upstairs";
			PChar.quest.Blaze_arrest.win_condition = "Blaze_arrest";
			pchar.quest.Voysey_lost = "2";
		break;
	
		case "Blaze_arrest":
			AddQuestRecord("artois", "6");
			Locations[FindLocation("Conceicao_tavern")].reload.l2.disable = true;
			sld = LAi_CreateFantomCharacter("brodyaga", "goto", "goto4");
			sld.dialog.filename = "anacleto_dialog.c";
			sld.dialog.currentnode = "ask_about_artois";
			LAi_SetActorType(sld);
			LAi_ActorSetLayMode(sld);
			LAi_ActorWaitDialog(sld, pchar);
			LAi_SetActorType(pchar);
			LAi_ActorDialog(pchar, sld, "", 4.0, 1.0);
	  	break;
	
		case "Blaze_cop_dialog":
			Locations[FindLocation("Conceicao_tavern_upstairs")].reload.l1.disable = true;
			LAi_SetPlayerType(pchar);
			sld = LAi_CreateFantomCharacter("soldier_por", "reload", "reload1");
			sld.Dialog.Filename = "Cops_dialog.c";
			sld.dialog.currentnode = "First time";
			sld.id = "solja";
			sld.greeting = "Gr_Solja";
	
			sld = LAi_CreateFantomCharacter("soldier_por", "reload", "reload1");
			LAi_SetActorType(sld);
			LAi_ActorFollow (sld, pchar, "", 10);
			sld.id = "solja1";
			LAi_group_MoveCharacter(sld, "CONCEICAO_SOLDIERS");
			
			LAi_SetActorType(characterfromID("solja"));
			LAi_ActorDialog(characterfromID("solja"), PChar, "", 10, 10);
			LAi_SetPlayerType(Pchar);
		break;
		
		case "artois_fight_in_tavern_upstairs":
			LAi_SetWarriorType(characterfromID("solja"));
			LAi_SetWarriorType(characterfromID("solja1"));
			LAi_group_MoveCharacter(characterFromID("solja"), "CONCEICAO_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("solja1"), "CONCEICAO_SOLDIERS");
			LAi_group_SetCheck("CONCEICAO_SOLDIERS", "Open_Locators");
			LAi_group_FightGroups("CONCEICAO_SOLDIERS", LAI_GROUP_PLAYER, true);
			
			SetNationRelation2MainCharacter(PORTUGAL, RELATION_ENEMY);
			AddQuestRecord("artois", "7");
		break;
		
		case "Open_Locators":
			Locations[FindLocation("Conceicao_tavern_upstairs")].reload.l1.disable = false;
			
			Pchar.quest.fight.win_condition.l1 = "location";
			Pchar.quest.fight.win_condition.l1.location = "Conceicao_town";
			PChar.quest.fight.win_condition = "Blaze_fight_the_world";
			
			Pchar.quest.artois_captured.win_condition.l1 = "location";
			Pchar.quest.artois_captured.win_condition.l1.location = "Conceicao_town_exit";
			PChar.quest.artois_captured.win_condition = "artois_captured";
		break;
		
		case "Blaze_fight_the_world":
			pchar.quest.escape_from_conceicao.win_condition.l1 = "location";
			pchar.quest.escape_from_conceicao.win_condition.l1.location = "conceicao";
			pchar.quest.escape_from_conceicao.win_condition = "escape_from_conceicao";
			
			Locations[FindLocation("Conceicao_town")].reload.l3.disable = true;
			
			if (GetCharacterSkill(pchar, SKILL_SNEAK) < 3)
			{
				sld = LAi_CreateFantomCharacter("soldier_por", "goto", "goto3");
				LAi_SetActorType(sld);
				LAi_group_MoveCharacter(sld, "CONCEICAO_SOLDIERS");
		
				sld = LAi_CreateFantomCharacter("soldier_por", "goto", "goto5");
				LAi_group_MoveCharacter(sld, "CONCEICAO_SOLDIERS");
		
				sld = LAi_CreateFantomCharacter("soldier_por", "goto", "goto5");
				LAi_group_MoveCharacter(sld, "CONCEICAO_SOLDIERS");
		
				sld = LAi_CreateFantomCharacter("soldier_por", "goto", "goto3");
				LAi_group_MoveCharacter(sld, "CONCEICAO_SOLDIERS");
				
				LAi_group_FightGroups("CONCEICAO_SOLDIERS", LAI_GROUP_PLAYER, true);
			}
		break;
		
		case "escape_from_conceicao":
			Locations[FindLocation("Conceicao_town")].reload.l3.disable = false;
			
			PChar.quest.possible_for_resque_artois.win_condition.l1 = "Timer";
			PChar.quest.possible_for_resque_artois.win_condition.l1.date.day = GetAddingDataDay(0,0,4);
			PChar.quest.possible_for_resque_artois.win_condition.l1.date.month = GetAddingDataMonth(0,0,4);
			PChar.quest.possible_for_resque_artois.win_condition.l1.date.year = GetAddingDataYear(0,0,4);
			PChar.quest.possible_for_resque_artois.win_condition = "possible_for_resque_artois";
		break;
		
		case "possible_for_resque_artois":
			pchar.quest.artois_captured.over = "yes";
			ChangeCharacterAddress(CharacterFromID("Artois Voysey"), "none", "");
			ChangeCharacterAddress(CharacterFromID("Pirates_1"), "none", "");
			ChangeCharacterAddress(CharacterFromID("Pirates_2"), "none", "");
			ChangeCharacterAddress(CharacterFromID("Pirates_3"), "none", "");
			CloseQuestHeader("Artois");
		break;
		
		case "artois_captured":
			LAi_SetImmortal(characterFromID("Artois Voysey"), true);
			ChangeCharacterAddress(CharacterFromID("Artois Voysey"), "Conceicao_town_exit", "goto14");
			characters[GetCharacterIndex("Artois Voysey")].dialog.currentnode = "Captured";
			LAi_SetActorType(characterfromID("Artois Voysey"));
			LAi_ActorSetLayMode(characterfromID("Artois Voysey"));
			characters[GetCharacterIndex("Pirates_1")].dialog.filename = "anacleto_dialog.c";
			characters[GetCharacterIndex("Pirates_1")].dialog.currentnode = "artois_lay";
			characters[GetCharacterIndex("Pirates_2")].dialog.filename = "anacleto_dialog.c";
			characters[GetCharacterIndex("Pirates_2")].dialog.currentnode = "artois_lay";
			characters[GetCharacterIndex("Pirates_3")].dialog.filename = "anacleto_dialog.c";
			characters[GetCharacterIndex("Pirates_3")].dialog.currentnode = "artois_lay";
			ChangeCharacterAddress(CharacterFromID("Pirates_1"), "Conceicao_town_exit", "goto8");
			ChangeCharacterAddress(CharacterFromID("Pirates_2"), "Conceicao_town_exit", "goto9");
			ChangeCharacterAddress(CharacterFromID("Pirates_3"), "Conceicao_town_exit", "goto10");
			LAi_SetActorType(CharacterFromID("Pirates_1"));
			LAi_SetActorType(CharacterFromID("Pirates_2"));
			LAi_SetActorType(CharacterFromID("Pirates_3"));
			LAi_ActorFollow(CharacterFromID("Pirates_1"), CharacterFromID("Artois Voysey"), "reset_pirates", 7.0);
			LAi_ActorFollow(CharacterFromID("Pirates_2"), CharacterFromID("Artois Voysey"), "reset_pirates", 7.0);
			LAi_ActorFollow(CharacterFromID("Pirates_3"), CharacterFromID("Artois Voysey"), "reset_pirates", 7.0);
			//LAi_QuestDelay("go_to_artois", 20.0);
			DeleteAttribute(pchar, "quest.voysey_lost");
			LAi_SetHP(CharacterFromID("Pirates_1"), 80.0, 80.0);
			LAi_SetHP(CharacterFromID("Pirates_2"), 80.0, 80.0);
			LAi_SetHP(CharacterFromID("Pirates_3"), 80.0, 80.0);
			LAi_SetCheckMinHP(CharacterFromID("Pirates_1"), 79.0, false, "fight_for_artois_with_child_of_giens");
			LAi_SetCheckMinHP(CharacterFromID("Pirates_2"), 79.0, false, "fight_for_artois_with_child_of_giens");
			LAi_SetCheckMinHP(CharacterFromID("Pirates_3"), 79.0, false, "fight_for_artois_with_child_of_giens");
		break;
		
		case "reset_pirates":
			LAi_SetStayType(CharacterFromID("Pirates_1"));
			LAi_SetStayType(CharacterFromID("Pirates_2"));
			LAi_SetStayType(CharacterFromID("Pirates_3"));
			AddQuestRecord("artois", "10");
		break;
		
		case "fight_for_artois_with_child_of_giens":
			LAi_RemoveCheckMinHP(CharacterFromID("Pirates_1"));
			LAi_RemoveCheckMinHP(CharacterFromID("Pirates_2"));
			LAi_RemoveCheckMinHP(CharacterFromID("Pirates_3"));
			LAi_SetPlayerType(pchar);
			LAi_group_MoveCharacter(characterFromID("Pirates_1"), "CHILD_OF_GIEN");
			LAi_group_MoveCharacter(characterFromID("Pirates_2"), "CHILD_OF_GIEN");
			LAi_group_MoveCharacter(characterFromID("Pirates_3"), "CHILD_OF_GIEN");
			LAi_group_FightGroups("CHILD_OF_GIEN", LAI_GROUP_PLAYER, true);
			
			LAi_group_SetCheck("CHILD_OF_GIEN", "Artois_resque_in_jungles");
			pchar.quest.possible_for_resque_artois.over = "yes";
		break;
		
		case "portugal_becomes_neutral":
			SetNationRelation2MainCharacter(PORTUGAL, RELATION_NEUTRAL);
			LAi_group_SetRelation("CONCEICAO_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_NEITRAL);
		break;
		
		case "Artois_resque_in_jungles":
			pchar.quest.artois_line = "resqued";
			LAi_fade("Artois_resque_in_jungles_2", "Artois_resque_in_jungles_3");
		break;
		
		case "Artois_resque_in_jungles_2":
			LAi_ActorSetStayMode(characterFromID("Artois Voysey"));
			LAi_ActorWaitDialog(characterFromID("Artois Voysey"), pchar);
		break;
		
		case "Artois_resque_in_jungles_3":
			LAi_SetActorType(pchar);
			LAi_ActorDialog(pchar, characterFromID("Artois Voysey"), "pchar_back_to_player", 5.0, 1.0);
			AddPartyExp(pchar, 5000);
		break;
		
		case "pause":
			AddQuestRecord("artois", "8");
			Locations[FindLocation("Conceicao_townhall")].reload.l1.disable = 1;
			DoQuestReloadToLocation ("Conceicao_townhall", "goto", "goto7", "pause2");
		break;
	
		case "pause2":
			Locations[FindLocation("Conceicao_tavern_upstairs")].reload.l1.disable = false;
			sld = LAi_CreateFantomCharacter("soldier_por", "goto", "goto8");
			LAi_SetActorType(sld);
			
			sld = LAi_CreateFantomCharacter("soldier_por", "goto", "goto1");
			LAi_SetActorType(sld);
			sld.id = "guard";
	
			sld = LAi_CreateFantomCharacter("man6", "goto", "goto2");
			LAi_SetActorType(sld);
			sld.id = "witness";
			sld.Dialog.Filename = "witness-dialog.c";
			LAi_SetActorType(CharacterFromID("Jacinto Arcibaldo Barreto"));
			LAi_ActorSetSitMode(CharacterFromID("Jacinto Arcibaldo Barreto"));
			characters[GetCharacterIndex("Jacinto Arcibaldo Barreto")].dialog.currentnode = "j_day";
			LAi_ActorDialog(characterfromID("Jacinto Arcibaldo Barreto"), PChar, "", 2.0, 1.0);
		break;
	
		case "ex_dialog":
			LAi_ActorDialog(characterfromID("witness"), PChar, "", 1.0, 1.0);
			LAi_ActorGoToLocator(CharacterFromID("guard"), "goto", "goto9", "ex_dialog2_3", 3.0);
		break;
	
		case "ex_dialog2_3":
			//LAi_SetActorType(characterfromID("Jacinto Arcibaldo Barreto"));
			LAi_ActorWaitDialog(characterfromID("Jacinto Arcibaldo Barreto"), characterfromID("guard"));
			LAi_ActorDialog(characterfromID("guard"), characterfromID("Jacinto Arcibaldo Barreto"), "ex_dialog2_4", 1.0, 2.0);
		break;
	
		case "ex_dialog2_4":
			LAi_ActorGoToLocator(CharacterFromID("guard"), "goto", "goto1", "ex_dialog2_5", 3.0);
		break;
	
		case "ex_dialog2_5":
			LAi_ActorDialog(characterfromID("Jacinto Arcibaldo Barreto"), PChar, "acrcibaldo_back_to_hub_type", 1.0, 1.0);
			Pchar.quest.artois_captured.win_condition.l1 = "location";
			Pchar.quest.artois_captured.win_condition.l1.location = "Conceicao_town_exit";
			PChar.quest.artois_captured.win_condition = "artois_captured";
			
			PChar.quest.possible_for_resque_artois.win_condition.l1 = "Timer";
			PChar.quest.possible_for_resque_artois.win_condition.l1.date.day = GetAddingDataDay(0,0,4);
			PChar.quest.possible_for_resque_artois.win_condition.l1.date.month = GetAddingDataMonth(0,0,4);
			PChar.quest.possible_for_resque_artois.win_condition.l1.date.year = GetAddingDataYear(0,0,4);
			PChar.quest.possible_for_resque_artois.win_condition = "possible_for_resque_artois";
			AddQuestRecord("artois", "9");
		break;
		
		case "acrcibaldo_back_to_hub_type":
			Locations[FindLocation("Conceicao_townhall")].reload.l1.disable = 0;
			LAi_SetHuberType(characterfromID("Jacinto Arcibaldo Barreto"));
		break;
		
		case "prepare_shoot_in_artois":
			LAi_SetImmortal(characterFromID("Artois Voysey"), false);
			
			LAi_SetPlayerType(Pchar);
			SetOfficersIndex(Pchar, -1, GetCharacterIndex("Artois Voysey"));
			
			Officersreaction("good");
			pchar.quest.shoot_in_artois.win_condition.l1 = "location";
			pchar.quest.shoot_in_artois.win_condition.l1.location = "QC_port";
			pchar.quest.shoot_in_artois.win_condition = "shoot_in_artois";
			
			pchar.quest.shoot_in_artois1.win_condition.l1 = "location";
			pchar.quest.shoot_in_artois1.win_condition.l1.location = "Redmond_port";
			pchar.quest.shoot_in_artois1.win_condition = "shoot_in_artois";
			
			pchar.quest.shoot_in_artois2.win_condition.l1 = "location";
			pchar.quest.shoot_in_artois2.win_condition.l1.location = "Greenford_port";
			pchar.quest.shoot_in_artois2.win_condition = "shoot_in_artois";
			
			if (pchar.location != "Oxbay_port" && !CheckAttribute(PChar, "Quest.Story_OxbayCaptured"))
			{
				pchar.quest.shoot_in_artois3.win_condition.l1 = "location";
				pchar.quest.shoot_in_artois3.win_condition.l1.location = "Oxbay_port";
				pchar.quest.shoot_in_artois3.win_condition = "shoot_in_artois";
			}
			
			pchar.quest.shoot_in_artois4.win_condition.l1 = "location";
			pchar.quest.shoot_in_artois4.win_condition.l1.location = "Douwesen_port";
			pchar.quest.shoot_in_artois4.win_condition = "shoot_in_artois";
			
			pchar.quest.shoot_in_artois5.win_condition.l1 = "location";
			pchar.quest.shoot_in_artois5.win_condition.l1.location = "Muelle_port";
			pchar.quest.shoot_in_artois5.win_condition = "shoot_in_artois";
		break;
		
		case "shoot_in_artois":
			if (CheckQuestAttribute("generate_convoy_quest_progress", ""))
			{				
				for (int l=1; l<4; l++)
				{
					if (GetOfficersIndex(Pchar, l) > 0)
					{
						if (characters[GetOfficersIndex(Pchar, l)].id == "Artois Voysey")
						{
							pchar.quest.shoot_in_artois_complete = "complete";
						}
					}
				}
				if (CheckQuestAttribute("shoot_in_artois_complete", "complete"))
				{
					pchar.quest.shoot_in_artois.over = "yes";
					pchar.quest.shoot_in_artois1.over = "yes";
					pchar.quest.shoot_in_artois2.over = "yes";
					pchar.quest.shoot_in_artois3.over = "yes";
					pchar.quest.shoot_in_artois4.over = "yes";
					pchar.quest.shoot_in_artois5.over = "yes";
					
					GetCharacterPos(GetMainCharacter(), &locx, &locy, &locz);
					homelocator = LAi_FindFarLocator("goto", locx, locy, locz);
					sld = LAi_CreateFantomCharacter("corsair1", "goto", homelocator);
					sld.id = "gunman";
					
					LAi_QuestDelay("shooting_in_artois_begin", 2.0);
					pchar.quest.location = pchar.location;
					pchar.quest.locator = pchar.location.locator;
				}
				else
				{
					pchar.quest.shoot_in_artois.win_condition.l1 = "location";
					pchar.quest.shoot_in_artois.win_condition.l1.location = "QC_port";
					pchar.quest.shoot_in_artois.win_condition = "shoot_in_artois";
					
					pchar.quest.shoot_in_artois1.win_condition.l1 = "location";
					pchar.quest.shoot_in_artois1.win_condition.l1.location = "Redmond_port";
					pchar.quest.shoot_in_artois1.win_condition = "shoot_in_artois";
					
					pchar.quest.shoot_in_artois2.win_condition.l1 = "location";
					pchar.quest.shoot_in_artois2.win_condition.l1.location = "Greenford_port";
					pchar.quest.shoot_in_artois2.win_condition = "shoot_in_artois";
					
					pchar.quest.shoot_in_artois3.win_condition.l1 = "location";
					pchar.quest.shoot_in_artois3.win_condition.l1.location = "Oxbay_port";
					pchar.quest.shoot_in_artois3.win_condition = "shoot_in_artois";
					
					pchar.quest.shoot_in_artois4.win_condition.l1 = "location";
					pchar.quest.shoot_in_artois4.win_condition.l1.location = "Douwesen_port";
					pchar.quest.shoot_in_artois4.win_condition = "shoot_in_artois";
					
					pchar.quest.shoot_in_artois5.win_condition.l1 = "location";
					pchar.quest.shoot_in_artois5.win_condition.l1.location = "Muelle_port";
					pchar.quest.shoot_in_artois5.win_condition = "shoot_in_artois";
				}
			}
			else
			{
				LAi_QuestDelay("shoot_in_artois", 3.0);
			}
		break;
		
		case "shooting_in_artois_begin":
			GetCharacterPos(GetMainCharacter(), &locx, &locy, &locz);
			homelocator = LAi_FindFarLocator("goto", locx, locy, locz);
			homelocation = pchar.location;
			CreateParticleSystemOnLocator(homelocation, homelocator, "gunfire");
			LAi_SetActorType(characterFromID("Artois Voysey"));
			LAi_ActorAnimation(characterFromID("Artois Voysey"), "death_1", "almost_killed_artois", 4.0);
			Play3DSound("objects\duel\pistol_shot1.wav", locx, locy, locz) ;
		break;
		
		case "almost_killed_artois":
			GetCharacterPos(GetMainCharacter(), &locx, &locy, &locz);
			homelocator = LAi_FindFarLocator("reload", locx, locy, locz);
			LAi_SetActorType(characterFromID("gunman"));
			LAi_ActorRunToLocation(characterFromID("gunman"), "reload", homelocator, "none", "", "", "", 10.0);
			LAi_ActorAnimation(characterFromID("Artois Voysey"), "lay_2", "", 4.0);
			LAi_SetActorType(Pchar);
			Pchar.Temp.self.dialog = Pchar.dialog.currentnode;
			Pchar.dialog.currentnode = "artois_shooted";
			LAi_ActorSelfDialog(Pchar, "player_back");
			AddQuestRecord("artois", "14");
		break;
		
		case "to_tavern_with_almost_dead_artois":
			RemoveOfficersIndex(pchar, GetCharacterIndex("Artois Voysey"));
			RemovePassenger(pchar, characterFromID("Artois Voysey"));
			ChangeCharacterAddress(characterFromID("Artois Voysey"), "none", "");
			DoQuestReloadToLocation("Muelle_tavern_upstairs", "goto", "goto2", "talk_with_doctor");
		break;
		
		case "talk_with_doctor":
			GetCharacterPos(GetMainCharacter(), &locx, &locy, &locz);
			homelocator = LAi_FindNearestFreeLocator("goto", locx, locy, locz);
			sld = LAi_CreateFantomCharacter("fatman2", "goto", homelocator);
			sld.id = "doctor";
			sld.dialog.filename = "anacleto_dialog.c";
			sld.dialog.currentnode = "doctor";
			LAi_SetActorType(sld);
			LAi_ActorDialog(sld, pchar, "", 2.0, 1.0);
			LAi_SetStayType(pchar);
		break;
		
		case "exit_doctor_bad":
			AddQuestRecord("artois", "15");
			CloseQuestHeader("artois");
			homelocation = pchar.quest.location;
			homelocator = pchar.quest.locator;
			DoQuestReloadToLocation(homelocation, "reload", homelocator, "pchar_back_to_player");
			Officersreaction("bad");
			ChangeCharacterReputation(pchar, -2);
		break;
		
		case "exit_doctor_good":
			environment.date.day = GetAddingDataDay(0,0,14);
			environment.date.month = GetAddingDataMonth(0,0,14);
			environment.date.year = GetAddingDataYear(0,0,14);
			AddQuestRecord("artois", "16");
			homelocation = pchar.quest.location;
			homelocator = pchar.quest.locator;
			DoQuestReloadToLocation(homelocation, "reload", homelocator, "final_talk_with_artois");
			Officersreaction("good");
			ChangeCharacterReputation(pchar, 2);
		break;
		
		case "final_talk_with_artois":
			LAi_SetPlayerType(pchar);
			homelocation = pchar.location;
			PlaceCharacter(characterFromID("Artois Voysey"), "goto", homelocation);
			LAi_SetActorType(characterFromID("Artois Voysey"));
			LAi_type_actor_Reset(characterFromID("Artois Voysey"));
			Characters[GetCharacterIndex("Artois Voysey")].dialog.currentnode = "final_talk";
			LAi_ActorDialog(characterFromID("Artois Voysey"), pchar, "Voysey_listed_2", 3.0, 1.0);
			
			pchar.quest.treasure_found.win_condition.l1 = "locator";
			pchar.quest.treasure_found.win_condition.l1.location = "Douwesen_Shore_ship";
			pchar.quest.treasure_found.win_condition.l1.locator_group = "randitem";
			pchar.quest.treasure_found.win_condition.l1.locator = "randitem1";
			pchar.quest.treasure_found.win_condition = "treasure_found";
			AddQuestRecord("artois", "17");
			AddPartyExp(pchar, 5000);
			//AddPassenger(Pchar, characterFromID("Artois Voysey"), 0);
		break;
		
		case "treasure_found":
			AddMoneyToCharacter(PChar, 50000);
			Log_SetStringToLog(GlobalStringConvert("QUEST_MESSAGE4"));
			AddQuestRecord("artois", "18");
			AddPartyExp(pchar, 15000);
			if (CheckQuestAttribute("artois_line", "completed"))
			{
				PChar.quest.Wait_For_donate.win_condition.l1 = "Timer";
				PChar.quest.Wait_For_donate.win_condition.l1.date.day = GetAddingDataDay(0,1,0);
				PChar.quest.Wait_For_donate.win_condition.l1.date.month = GetAddingDataMonth(0,1,0);
				PChar.quest.Wait_For_donate.win_condition.l1.date.year = GetAddingDataYear(0,1,0);
				PChar.quest.Wait_For_donate.win_condition = "Wait_For_donate";
				pchar.quest.artois_line = "found_gold";
			}
			else
			{
				CloseQuestHeader("artois");
			}		
		break;
		
		case "Wait_For_donate":
			OfficersReaction("bad");
			ChangeCharacterReputation(pchar, -2);
			pchar.quest.artois_line = "final_state";
			AddQuestRecord("artois", "20");
			CloseQuestHeader("artois");
		break;
		
		case "artois_donate_done":
			pchar.quest.Wait_For_donate.over = "yes";
			OfficersReaction("good");
			ChangeCharacterReputation(pchar, 4);
			AddMoneyToCharacter(PChar, -4000);
			AddQuestRecord("artois", "19");
			CloseQuestHeader("artois");
			AddPArtyExp(pchar, 7000);
		break;
	
	//Nigel Blythe
		case "voysey_No_Fight":
			LAi_ActorAttack(CharacterFromID("Pirates_1"), CharacterFromID("Artois Voysey"), "");
		break;
	
		case "voysey_Fight":
			LAi_ActorAttack(CharacterFromID("Pirates_1"), PChar, "");
			LAi_ActorAttack(CharacterFromID("Pirates_2"), PChar, "");
			LAi_ActorAttack(CharacterFromID("Pirates_3"), PChar, "");
			Pchar.quest.Story_KillNygelBlythe4.win_condition.l1 = "NPC_Death";
			Pchar.quest.Story_KillNygelBlythe4.win_condition.l1.character = "Pirates_1";
			Pchar.quest.Story_KillNygelBlythe4.win_condition.l2 = "NPC_Death";
			Pchar.quest.Story_KillNygelBlythe4.win_condition.l2.character = "Pirates_2";
			Pchar.quest.Story_KillNygelBlythe4.win_condition.l3 = "NPC_Death";
			Pchar.quest.Story_KillNygelBlythe4.win_condition.l3.character = "Pirates_3";
			PChar.quest.Story_KillNygelBlythe4.win_condition = "Voysey_death";
		break;
	
		case "voysey_found_treasure":
			pchar.quest.treasure_found.win_condition.l1 = "locator";
			pchar.quest.treasure_found.win_condition.l1.location = "Douwesen_Shore_ship";
			pchar.quest.treasure_found.win_condition.l1.locator_group = "randitem";
			pchar.quest.treasure_found.win_condition.l1.locator = "randitem1";
			pchar.quest.treasure_found.win_condition = "treasure_found";
		break;
	
		case "Leave_Voysey":
			LAi_SetPlayerType(PChar);
			LAi_SetCitizenType(CharacterFromID("Artois Voysey")); 
		break;
	
		case "Leave_Nigel":
			AddQuestRecord("nigel", "3");
			//CloseQuestHeader("nigel");
			LAi_SetPlayerType(PChar);
			LAi_SetCitizenType(CharacterFromID("Nigel Blythe")); 
		break;
	
		case "change_Maxwell_adress":
			AddQuestrecord("nigel", "24");
			characters[GetCharacterIndex("Friedrich Maxwell")].Dialog.Filename = "Maxwell_dialog.c";
			Pchar.quest.Nigel_Blythe6.win_condition.l1 = "location";
			Pchar.quest.Nigel_Blythe6.win_condition.l1.location = "QC_tavern";
			Pchar.quest.Nigel_Blythe6.win_condition = "Maxwell_talk";
		break;
	
		case "voysey_final_nofight":
			LAi_ActorAttack(CharacterFromID("Pirates_1"), CharacterFromID("Artois Voysey"), "");
		break;
	
		case "voysey_final_fight":
			LAi_ActorAttack(CharacterFromID("Pirates_1"), PChar, "");
			LAi_ActorAttack(CharacterFromID("Pirates_2"), PChar, "");
			LAi_ActorAttack(CharacterFromID("Pirates_3"), PChar, "");
			Pchar.quest.Story_KillNygelBlythe4.win_condition.l1 = "NPC_Death";
			Pchar.quest.Story_KillNygelBlythe4.win_condition.l1.character = "Pirates_1";
			Pchar.quest.Story_KillNygelBlythe4.win_condition.l2 = "NPC_Death";
			Pchar.quest.Story_KillNygelBlythe4.win_condition.l2.character = "Pirates_2";
			Pchar.quest.Story_KillNygelBlythe4.win_condition.l3 = "NPC_Death";
			Pchar.quest.Story_KillNygelBlythe4.win_condition.l3.character = "Pirates_3";
			PChar.quest.Story_KillNygelBlythe4.win_condition = "Voysey_death";
		break;
	
		case "change_clauss_adress":
			AddMoneyToCharacter(Pchar, -5000);
			SetCharacterToNearLocatorFromMe("Florens Clauss", 3);
			ChangeCharacterAddressGroup(CharacterFromID("Friedrich Maxwell"), "", "sit", "sit2");
		break;
	
		case "Nigel_listed":
			AddQuestRecord("nigel", "2");
			Pchar.quest.Nigel_Blythe.win_condition.l1 = "location";
			Pchar.quest.Nigel_Blythe.win_condition.l1.location = "Oxbay_Port";
			PChar.quest.Nigel_Blythe.win_condition = "Nigel_Adventure";
	
			AddMoneyToCharacter(PChar, -3000);
			LAi_SetPlayerType(pchar);
			SetOfficersIndex(Pchar, -1, GetCharacterIndex("Nigel Blythe"));
			LAi_SetOfficerType(CharacterFromID("Nigel Blythe"));
		break;
		
		case "Nigel_listed2":
			AddQuestRecord("nigel", "2");
			Pchar.quest.Nigel_Blythe.win_condition.l1 = "location";
			Pchar.quest.Nigel_Blythe.win_condition.l1.location = "Oxbay_Port";
			PChar.quest.Nigel_Blythe.win_condition = "Nigel_Adventure";
	
			AddMoneyToCharacter(PChar, -300);
			LAi_SetPlayerType(pchar);
			SetOfficersIndex(Pchar, -1, GetCharacterIndex("Nigel Blythe"));
			LAi_SetOfficerType(CharacterFromID("Nigel Blythe"));
		break;
		
		case "nigel_second_encounter":
			Pchar.quest.Nigel_Blythe2.win_condition.l1 = "location";
			Pchar.quest.Nigel_Blythe2.win_condition.l1.location = "Conceicao_port";
			Pchar.quest.Nigel_Blythe2.win_condition = "Nigel_Adventure_Conc";
		break;
		
		case "nigel_third_encounter":
			Pchar.quest.Nigel_Blythe6.win_condition.l1 = "location";
			Pchar.quest.Nigel_Blythe6.win_condition.l1.location = "Douwesen";
			Pchar.quest.Nigel_Blythe6.win_condition = "Blythe_Battle";
		break;
		
		case "nigel_fourth_encounter":
			Pchar.quest.Nigel_Blythe3.win_condition.l1 = "location";
			Pchar.quest.Nigel_Blythe3.win_condition.l1.location = "IslaMuelle";
			Pchar.quest.Nigel_Blythe3.win_condition = "Blythe_gone_ship";
		break;
	
		case "Nigel_dissmissed":
			AddQuestRecord("nigel", "5");
			CloseQuestheader("nigel");
			ChangeCharacterReputation(pchar, -1);
			//RemovePassenger(pchar, characterFromID("Nigel Blythe"));
			LAi_fade("Nigel_dissmissed_2", "");
		break;
		
		case "Nigel_dissmissed_2":
			homelocation = characters[GetCharacterIndex("Nigel Blythe")].homelocation;
			homegroup = characters[GetCharacterIndex("Nigel Blythe")].homelocation.group;
			homelocator = characters[GetCharacterIndex("Nigel Blythe")].homelocation.locator;
			ChangeCharacterAddressGroup(characterFromID("Nigel Blythe"), homelocation, homegroup, homelocator), 
			characters[GetCharacterIndex("Nigel Blythe")].dialog.currentnode = "Fired";
		break;
	
		case "Nigel_cargo_off":
			AddQuestRecord("nigel", "6");
			characters[GetCharacterIndex("Nigel Blythe")].loyality = makeint(characters[GetCharacterIndex("Nigel Blythe")].loyality) - 1;
			ChangeCharacterReputation(pchar, -2);
			AddPassenger(Pchar, characterFromID("Nigel Blythe"), 0);
			characters[GetCharacterIndex("nigel blythe")].Dialog.CurrentNode = "officer_Nig";
		break;
		
		case "con_parri_off":
			characters[GetCharacterIndex("Nigel Blythe")].loyality = makeint(characters[GetCharacterIndex("Nigel Blythe")].loyality) - 1;
			ChangeCharacterReputation(pchar, -2);
			//SetOfficersIndex(Pchar, -1, GetCharacterIndex("Nigel Blythe"));
			AddPassenger(Pchar, characterFromID("Nigel Blythe"), 0);
			characters[GetCharacterIndex("nigel blythe")].Dialog.CurrentNode = "officer_Nig";
		break;
		
		case "con_parri_prepare":
			AddPassenger(Pchar, characterFromID("Nigel Blythe"), 0);
			characters[GetCharacterIndex("nigel blythe")].Dialog.CurrentNode = "officer_Nig";
			
			characters[GetCharacterIndex("Ethilrede Claar")].name = "Shuggy";
			characters[GetCharacterIndex("Ethilrede Claar")].lastname = "Garry";
			
			pchar.quest.exit_to_conceicao_sea.win_condition.l1 = "location";
			pchar.quest.exit_to_conceicao_sea.win_condition.l1.location = "Conceicao";
			pchar.quest.exit_to_conceicao_sea.win_condition = "exit_to_conceicao_sea";
			
			pchar.quest.nigel_con_parri_checker = "begin";
			pchar.quest.con_parri.win_condition.l1 = "NPC_Death";
			pchar.quest.con_parri.win_condition.l1.character = "Ethilrede Claar";
			pchar.quest.con_parri.win_condition = "con_parri";
			
			PChar.quest.con_parri_expired.win_condition.l1 = "Timer";
			PChar.quest.con_parri_expired.win_condition.l1.date.day = GetAddingDataDay(0,30,0);
			PChar.quest.con_parri_expired.win_condition.l1.date.month = GetAddingDataMonth(0,30,0);
			PChar.quest.con_parri_expired.win_condition.l1.date.year = GetAddingDataYear(0,30,0);
			PChar.quest.con_parri_expired.win_condition = "con_parri_expired";
		break;
		
		case "exit_to_conceicao_sea":
			Group_CreateGroup("Ethilrede Claar");
			Group_AddCharacter("Ethilrede Claar", "Ethilrede Claar");
			Group_SetGroupCommander("Ethilrede Claar", "Ethilrede Claar");
			Group_SetTaskAttack("Ethilrede Claar", PLAYER_GROUP);
			//Group_SetPursuitGroup("Nigel Blythe", "PLAYER_GROUP");
			Group_SetAddress("Ethilrede Claar", "Conceicao", "quest_ships", "quest_ship_2");
			Group_LockTask("Ethilrede Claar");
		break;
		
		case "con_parri_expired":
			PChar.quest.nigel_con_parri_checker = "failed";
			ChangeCharacterReputation(pchar, -2);
			AddQuestrecord("nigel", "13");
		break;
		
		case "con_parri":
			if (CheckQuestAttribute("nigel_con_parri_checker", "failed"))
			{
				pchar.quest.nigel_con_parri_checker = "win";
			}
			else
			{
				pchar.quest.nigel_con_parri_checker = "win_win";
			}
			AddQuestrecord("nigel", "14");
		break;
	
		case "nigel_first_cargo_on":
			PChar.quest.nigel_first_cargo_on_expired.win_condition.l1 = "Timer";
			PChar.quest.nigel_first_cargo_on_expired.win_condition.l1.date.day = GetAddingDataDay(0,1,0);
			PChar.quest.nigel_first_cargo_on_expired.win_condition.l1.date.month = GetAddingDataMonth(0,1,0);
			PChar.quest.nigel_first_cargo_on_expired.win_condition.l1.date.year = GetAddingDataYear(0,1,0);
			PChar.quest.nigel_first_cargo_on_expired.win_condition = "nigel_first_cargo_on_expired";
			pchar.quest.nigel_first_cargo_checker = "begin";
			AddPassenger(Pchar, characterFromID("Nigel Blythe"), 0);
			characters[GetCharacterIndex("nigel blythe")].Dialog.CurrentNode = "officer_Nig";
			AddQuestRecord("nigel", "7");
		break;
		
		case "nigel_first_cargo_on_expired":
			ChangeCharacterReputation(pchar, -2);
			pchar.quest.nigel_first_cargo_checker = "failed";
			AddQuestRecord("nigel", "8");
			LAi_QuestDelay("nigel_second_encounter", 1.0);
		break;
		
		case "clauss_to_tavern":
			AddQuestrecord("nigel", "26");
			pchar.quest.clauss_to_tavern_complete.win_condition.l1 = "location";
			pchar.quest.clauss_to_tavern_complete.win_condition.l1.location = "QC_tavern";
			pchar.quest.clauss_to_tavern_complete.win_condition = "clauss_to_tavern_complete";
		break;
		
		case "clauss_to_tavern_complete":
			PlaceCharacter(characterFromID("Florens Clauss"), "goto", "QC_tavern");
			LAi_SetStayType(characterFromID("Florens Clauss"));
		break;
		
		case "prepare_for_final_fight_with_nigel":
			AddQuestrecord("nigel", "27");
			pchar.quest.nigel_treasure_found.win_condition.l1 = "location";
			pchar.quest.nigel_treasure_found.win_condition.l1.location = "Douwesen_Shore_ship";
			pchar.quest.nigel_treasure_found.win_condition = "nigel_treasure_found";
			AddPassenger(Pchar, characterFromID("Florens Clauss"), 0);
			LAi_LocationMonstersGen(&locations[FindLocation("Douwesen_Shore_ship")], false);
		break;
		
		case "nigel_treasure_found":
			ChangeCharacterAddressGroup(characterFromID("nigel Blythe"), "Douwesen_Shore_ship", "monsters", "monster1");
			LAi_group_MoveCharacter(characterFromID("nigel Blythe"), "NIGEL");
			sld = LAi_CreateFantomCharacter("corsair1", "monsters", "monster2");
			LAi_group_MoveCharacter(sld, "NIGEL");
			sld = LAi_CreateFantomCharacter("corsair2", "monsters", "monster3");
			LAi_group_MoveCharacter(sld, "NIGEL");
			sld = LAi_CreateFantomCharacter("corsair3", "monsters", "monster4");
			LAi_group_MoveCharacter(sld, "NIGEL");
			LAi_group_FightGroups("NIGEL", LAI_GROUP_PLAYER, true);
			
			LAi_group_SetCheck("NIGEL", "nigel_treasure_found_complete");
		break;
		
		case "nigel_treasure_found_complete":
			AddMoneyToCharacter(PChar, 50000);
			AddPartyExp(pchar, 25000);
			AddQuestrecord("nigel", "28");
			CloseQuestHeader("nigel");
		break;
	
		case "Set_Edgar_Free":
			AddMoneyToCharacter(Pchar,-5000);
	
			ChangeCharacterAddressGroup(CharacterFromID("Jack Greenfield"), "", "sit", "sit2");
			ChangeCharacterAddressGroup(CharacterFromID("Martin Warner"), "", "sit", "sit2");
			PChar.quest.Story_Artois.win_condition.l1 = "location";
			PChar.quest.Story_Artois.win_condition.l1.location = "Redmond_town_04";
			PChar.quest.Story_Artois.win_condition = "Let_my_edgar_go";
		break;
	
		case "Small_Pause_Before_Convoy":
			WaitDate("", 0, 0, 0, 0, 3);
			LAi_ActorSetStayMode(CharacterFromID("Jack Greenfield"));
			ChangeCharacterAddressGroup(CharacterFromID("Jack Greenfield"), "", "sit", "sit10");
			AddMoneyToCharacter(PChar, -1000);
			LAi_QuestDelay("soldier_in_tavern4", 4.0);
		break;
	
		case "Artois_kill":
			SetQuestHeader("nigel");
			AddQuestRecord("nigel", "1");
			LAi_SetPlayerType(PChar);
			LAi_SetActorType(CharacterFromID("Nigel Blythe"));
			LAi_ActorDialog(CharacterFromID("Nigel Blythe"), PChar, "", 2.0, 1.0);
			EndQuestMovie();
		break;
	
		case "Artois_Blythe":
			SendMessage(&Characters[GetCharacterIndex("Nigel Blythe")],"lsl", MSG_CHARACTER_EX_MSG , "SetFightMode", true);
			LAi_SetActorType(PChar);
			LAi_ActorWaitDialog(CharacterFromID("Nigel Blythe"), PChar);
			LAi_ActorDialog(PChar, CharacterFromID("Nigel Blythe"), "", 10, 10);
		break;
	
		case "killing_artois":
			LAi_SetImmortal(characterFromID("Artois Voysey"), false);
			LAi_SetImmortal(characterFromID("Nigel Blythe"), false);
			LAi_SetActorType(pchar);
			LAi_ActorTurnToCharacter(pchar, characterFromID("Nigel Blythe"));
			LAi_ActorAnimation(CharacterFromID("Artois Voysey"), "afraid","", 10);
			LAi_ActorAttack(CharacterFromID("Nigel Blythe"), CharacterFromID("Artois Voysey"), "Artois_kill");
		break;
	
		case "Nigel_Adventure":
			if (!LAi_IsDead(characterFromID("Nigel Blythe")) && !CheckAttribute(PChar, "Quest.Story_OxbayCaptured"))
			{
				if(FindFellowTravellers(PChar, CharacterFromID("Nigel Blythe")) == FELLOWTRAVEL_PASSENGER || FindFellowTravellers(PChar, CharacterFromID("Nigel Blythe")) == FELLOWTRAVEL_OFFICER)
				{
					AddQuestRecord("nigel", "4");
					Pchar.quest.Nigel_Blythe1.win_condition.l1 = "location";
					Pchar.quest.Nigel_Blythe1.win_condition.l1.location = "Oxbay_Tavern";
					Pchar.quest.Nigel_Blythe1.win_condition = "Blythe_Setup";
					pchar.quest.Nigel_lost = "1";
	
					LAi_SetActorType(Pchar);
					Pchar.Temp.self.dialog = Pchar.dialog.currentnode;
					Pchar.dialog.currentnode = "nigel_lost";
					LAi_ActorSelfDialog(Pchar, "player_back");
					RemoveOfficersIndex(pchar, GetCharacterIndex("Nigel Blythe"));
					RemovePassenger(pchar, characterFromID("Nigel Blythe"));
					LAi_SetActorType(CharacterFromID("Nigel Blythe"));
					LAi_SetSitType(CharacterFromID("Nigel Blythe"));
					ChangeCharacterAddressGroup(CharacterFromID("Nigel Blythe"), "Oxbay_tavern", "sit", "sit12");
				}
			}
		break;
	
		case "Nigel_Adventure_Conc":
			if (!CharacterIsDead(&characters[GetCharacterIndex("Nigel Blythe")]))
			{
				if(FindFellowTravellers(PChar, CharacterFromId("Nigel Blythe")) == FELLOWTRAVEL_PASSENGER || FindFellowTravellers(PChar, CharacterFromId("Nigel Blythe")) == FELLOWTRAVEL_OFFICER)
				{	
					AddQuestRecord("nigel", "10");
					Pchar.quest.Nigel_Blythe5.win_condition.l1 = "location";
					Pchar.quest.Nigel_Blythe5.win_condition.l1.location = "Conceicao_Tavern";
					Pchar.quest.Nigel_Blythe5.win_condition = "Blythe_Setup_Conc";
					pchar.quest.Nigel_lost = "1";
		
					LAi_SetActorType(Pchar);
					Pchar.Temp.self.dialog = Pchar.dialog.currentnode;
					Pchar.dialog.currentnode = "nigel_lost";
					LAi_ActorSelfDialog(Pchar, "player_back");
					RemoveOfficersIndex(pchar, GetCharacterIndex("Nigel Blythe"));
					RemovePassenger(pchar, characterFromID("Nigel Blythe"));
					LAi_SetSitType(CharacterFromID("Nigel Blythe"));
					ChangeCharacterAddressGroup(CharacterFromID("Nigel Blythe"), "Conceicao_tavern", "sit", "sit12");
				}
			}
		break;
	
		case "player_back":
			LAi_SetPlayerType(Pchar);
			Pchar.dialog.currentnode = Pchar.Temp.self.dialog;
		break;
	
		case "Blythe_Setup":
			characters[GetCharacterIndex("Nigel Blythe")].dialog.currentnode = "Setup1";
			pchar.quest.Nigel_lost = "0";
		break;
	
	
		case "Blythe_Setup_Conc":
			characters[GetCharacterIndex("Nigel Blythe")].dialog.currentnode = "Setup2";
			pchar.quest.Nigel_lost = "0";
		break;
		
		case "Blythe_Battle":
			if (characters[GetCharacterIndex("Nigel Blythe")].ship.type != SHIP_NOTUSED && (FindFellowTravellers(PChar, CharacterFromId("Nigel Blythe")) == FELLOWTRAVEL_COMPANION))
			{	
				RemoveCharacterCompanion(Pchar, characterFromID("Nigel Blythe"));
				
				AddQuestrecord("nigel", "16");
				bQuestDisableMapEnter = true;
				Island_SetReloadEnableGlobal(PChar.location, false);
		
				Log_SetStringToLog(GlobalStringConvert("QUEST_MESSAGE5"));
		
				SetCharacterRelationBoth(GetCharacterIndex("Nigel Blythe"),GetMainCharacterIndex(),RELATION_FRIEND);
				SetCharacterRelationBoth(GetCharacterIndex("Nigel Blythe"),GetCharacterIndex("Pirates_7"),RELATION_ENEMY);
					
				Group_CreateGroup("Nigel Blythe");
				Group_AddCharacter("Nigel Blythe", "Nigel Blythe");
				Group_SetGroupCommander("Nigel Blythe", "Nigel Blythe");
				Group_SetTaskAttack("Nigel Blythe", "Smugglers_corvette");
				Group_SetPursuitGroup("Nigel Blythe", PLAYER_GROUP);
				Group_SetAddress("Nigel Blythe", "Douwesen", "quest_ships", "quest_ship_2");
				Group_LockTask("Nigel Blythe");
		
				Group_CreateGroup("Smugglers_corvette");
				Group_AddCharacter("Smugglers_corvette", "Pirates_7");
				Group_SetGroupCommander("Smugglers_corvette", "Pirates_7");
				Group_SetTaskAttack("Smugglers_corvette", "Nigel Blythe");
				Group_LockTask("Smugglers_corvette");
				Group_SetPursuitGroup("Smugglers_corvette", PLAYER_GROUP);
				Group_SetAddress("Smugglers_corvette", "Douwesen", "quest_ships", "quest_ship_1");
	
		
				Pchar.quest.Battle.win_condition.l1 = "NPC_Death";
				Pchar.quest.Battle.win_condition.l1.character = "Pirates_7";
				PChar.quest.Battle.win_condition = "Finish_battle";
		
				Pchar.quest.Battle1.win_condition.l1 = "NPC_Death";
				Pchar.quest.Battle1.win_condition.l1.character = "Nigel Blythe";
				PChar.quest.Battle1.win_condition = "Finish_battle";
			}
			else
			{
				Pchar.quest.Nigel_Blythe_third_encounter_recharge.win_condition.l1 = "ExitFromLocation";
				Pchar.quest.Nigel_Blythe_third_encounter_recharge.win_condition.l1.location = "Douwesen";
				Pchar.quest.Nigel_Blythe_third_encounter_recharge.win_condition = "Nigel_Blythe_third_encounter_recharge";
			}
		break;
		
		case "Nigel_Blythe_third_encounter_recharge":
			Pchar.quest.Nigel_Blythe6.win_condition.l1 = "location";
			Pchar.quest.Nigel_Blythe6.win_condition.l1.location = "Douwesen";
			Pchar.quest.Nigel_Blythe6.win_condition = "Blythe_Battle";
		break;
	
		case "Finish_battle":
			Island_SetReloadEnableGlobal(PChar.location, true);
		
			if (!LAi_IsDead(characterFromID("Nigel Blythe")))
			{
				//SetCompanionIndex(Pchar, -1, GetCharacterIndex("Nigel Blythe"));
				Pchar.quest.Battle2.win_condition.l1 = "location";
				Pchar.quest.Battle2.win_condition.l1.location = "Douwesen_port";
				Pchar.quest.Battle2.win_condition = "Smugglers_vs_Blythe";
				AddQuestrecord("nigel", "18");
			}
			else
			{
				bQuestDisableMapEnter = false;
				AddQuestrecord("nigel", "17");
			}
			pchar.quest.Battle.over = "yes";
			pchar.quest.Battle1.over = "yes";
		break;
	
		case "Smugglers_vs_Blythe":
			pchar.quest.Battle1.over = "yes";
			bQuestDisableMapEnter = false;
			//RemoveCharacterCompanion(Pchar, characterFromID("Nigel Blythe"));
			ChangeCharacterAddress(CharacterFromID("Nigel Blythe"), "Douwesen_port", "goto1");
			LAi_SetActorType(characterFromID("nigel blythe"));
	
			sld = LAi_CreateFantomCharacter("corsair1", "goto", "goto2");
			LAi_SetActorType(sld);
			sld.id = "offended_sm1";
	
			sld = LAi_CreateFantomCharacter("corsair1_1", "goto", "goto1");
			LAi_SetActorType(sld);
			sld.id = "offended_sm";
			sld.Dialog.Filename = "Smugglers_vs_Blythe.c";
	
			sld = LAi_CreateFantomCharacter("corsair1_2", "goto", "goto3");
			LAi_SetActorType(sld);
			sld.id = "offended_sm2";
	
			LAi_ActorDialog(CharacterFromID("offended_sm"), PChar, "", 10.0, 1.0);
			LAi_ActorFollow(CharacterFromID("offended_sm1"), pchar, "", 5.0);
			LAi_ActorFollow(CharacterFromID("offended_sm2"), pchar, "", 5.0);
	  break;
  
	  case "nigel_answer_to_smuggler":
	  	LAi_SetActorType(characterFromID("Nigel Blythe"));
	  	characters[GetCharacterIndex("Nigel Blythe")].dialog.currentnode = "smugglers";
	  	LAi_ActorDialog(characterFromID("Nigel Blythe"), pchar, "", 1.0, 1.0);
	  break;
	  	
	  case "nigel_smugglers_fight_prepare":
	  	characters[GetCharacterIndex("offended_sm")].dialog.currentnode = "nigel_fight";
	  	LAi_ActorDialog(characterFromID("offended_sm"), pchar, "", 1.0, 1.0);
	  break;
	  	
	  case "nigel_fight_with_smugglers":
	  	OfficersReaction("bad");
	  	RemoveCharacterCompanion(Pchar, characterFromID("Nigel Blythe"));
		RemoveOfficersIndex(pchar, GetCharacterIndex("Nigel Blythe"));
	  	LAi_ActorAttack(characterFromID("offended_sm"), characterFromID("nigel blythe"), "");
	  	LAi_ActorAttack(characterFromID("offended_sm1"), characterFromID("nigel blythe"), "");
	  	LAi_ActorAttack(characterFromID("offended_sm2"), characterFromID("nigel blythe"), "");
	 	LAi_ActorAttack(characterFromID("nigel blythe"), characterFromID("offended_sm"), "");
	 	LAi_group_MoveCharacter(characterFromID("offended_sm"), "SMUGGLERS_IN_CONCEICAO_PORT");
	  	LAi_group_MoveCharacter(characterFromID("offended_sm1"), "SMUGGLERS_IN_CONCEICAO_PORT");
	  	LAi_group_MoveCharacter(characterFromID("offended_sm2"), "SMUGGLERS_IN_CONCEICAO_PORT");
	  	LAi_group_MoveCharacter(characterFromID("Nigel Blythe"), "NIGEL");
	 	LAi_QuestDelay("nigel_killed", 1.0);
	  break;
	  
	  case "nigel_kiled":
	  	LAi_KillCharacter(characterFromID("nigel blythe"));
	  	AddQuestrecord("nigel", "20");
	  	CloseQuestHeader("nigel");
	break;
  	
	case "we_and_nigel_fight_with_smugglers":
		LAi_group_MoveCharacter(characterFromID("offended_sm"), "SMUGGLERS_IN_CONCEICAO_PORT");
	  	LAi_group_MoveCharacter(characterFromID("offended_sm1"), "SMUGGLERS_IN_CONCEICAO_PORT");
	  	LAi_group_MoveCharacter(characterFromID("offended_sm2"), "SMUGGLERS_IN_CONCEICAO_PORT");
	  	
	  	LAi_group_MoveCharacter(characterFromID("Nigel Blythe"), LAI_GROUP_PLAYER);
	  	
	  	LAi_group_FightGroups("SMUGGLERS_IN_CONCEICAO_PORT", LAI_GROUP_PLAYER, true);
	  	LAi_group_SetCheck("SMUGGLERS_IN_CONCEICAO_PORT", "nigel_after_fight_with_smugglers_in_conceicao_port");
	break;
  	
	case "nigel_after_fight_with_smugglers_in_conceicao_port":
		if (!LAi_IsDead(characterFromID("Nigel Blythe")))
	  	{
	  		LAi_SetActorType(characterFromID("Nigel Blythe"));
	  		characters[GetCharacterIndex("Nigel Blythe")].dialog.currentnode = "smugglers_thanks";
	  		LAi_ActorDialog(characterFromID("Nigel Blythe"), pchar, "", 1.0, 1.0);
	  	}
	  	else
	  	{
	  		AddQuestrecord("nigel", "20");
	  		CloseQuestHeader("nigel");
	  	}	  		
	  	AddQuestrecord("nigel", "19");
	break;
	  	
	  	case "we_and_nigel_smugglers_fight_prepare":
	  		characters[GetCharacterIndex("offended_sm")].dialog.currentnode = "we_and_nigel_fight";
	  		LAi_ActorDialog(characterFromID("offended_sm"), pchar, "", 1.0, 1.0);
	  	break;
	
	
		case "Blythe_gone_ship":
			if ((GetCharacterShipClass(CharacterFromID("Nigel Blythe")) < 5) && (GetCharacterShipClass(CharacterFromID("Nigel Blythe")) != -1))
			{
				AddQuestrecord("nigel", "21");
				RemoveCharacterCompanion(Pchar, &Characters[GetCharacterIndex("Nigel Blythe")]);
				RemoveOfficersIndex(pchar, GetCharacterIndex("Nigel Blythe"));
			
				//characters[GetCharacterIndex("Claudio Murena")].Dialog.Filename = "Murena_dialog.c";
				//ChangeCharacterAddressGroup(CharacterFromID("Claudio Murena"), "Muelle_tavern", "sit", "sit2");
				//LAi_SetSitType(CharacterFromID("Claudio Murena")); 
				characters[GetCharacterIndex("Ermegildo Caminero")].Dialog.Filename = "Caminero_dialog.c";
				pchar.quest.nigel_away_for_ship = "begin";
				Log_SetStringToLog(GlobalStringConvert("QUEST_MESSAGE6"));
				Pchar.quest.Nigel_Blythe1.win_condition.l1 = "location";
				Pchar.quest.Nigel_Blythe1.win_condition.l1.location = "Muelle_port";
				Pchar.quest.Nigel_Blythe1.win_condition = "Muelle_Blythe";
			}
			else
			{
				Pchar.quest.Nigel_Blythe_fourth_encounter_recharge.win_condition.l1 = "ExitFromLocation";
				Pchar.quest.Nigel_Blythe_fourth_encounter_recharge.win_condition.l1.location = "IslaMuelle";
				Pchar.quest.Nigel_Blythe_fourth_encounter_recharge.win_condition = "nigel_fourth_encounter";
			}
		break;
	
		case "Muelle_Blythe":
			if ((GetOfficersIndex(Pchar, 1) == -1) && (GetOfficersIndex(Pchar, 2) == -1) && (GetOfficersIndex(Pchar, 3) == -1))
			{
				sld = LAi_CreateFantomCharacter("corsair2", "goto", "goto10");
				LAi_SetActorType(sld);
				sld.id = "offended_sm3";;
				sld.id = "to_say";
				sld.Dialog.Filename = "to_say.c";
	
				LAi_ActorDialog(characterfromID("to_say"), pchar, "", 10.0, 10.0);
			}
			if (GetOfficersIndex(Pchar, 1) != -1)
			{
				sld = &Characters[GetOfficersIndex(Pchar, 1)];
				Pchar.Temp.Officer.dialog = sld.Dialog.Filename;
				Pchar.Temp.Officer.dialognode = characters[GetOfficersIndex(Pchar, 1)].dialog.currentnode;
				sld.Dialog.Filename = "to_say.c";
				characters[GetOfficersIndex(Pchar, 1)].dialog.currentnode = "First time";
				LAi_ActorDialog(&Characters[GetOfficersIndex(Pchar, 1)], pchar, "", 10.0, 10.0);
				LAi_QuestDelay("Muelle_Blythe2", 10.0);
			}
			else 
			{
				if (GetOfficersIndex(Pchar, 2) != -1)
				{
					sld = &Characters[GetOfficersIndex(Pchar, 2)];
					Pchar.Temp.Officer.dialog = sld.Dialog.Filename;
					Pchar.Temp.Officer.dialognode = characters[GetOfficersIndex(Pchar, 2)].dialog.currentnode;
					sld.Dialog.Filename = "to_say.c";
					characters[GetOfficersIndex(Pchar, 2)].dialog.currentnode = "First time";
					LAi_ActorDialog(&Characters[GetOfficersIndex(Pchar, 2)], pchar, "", 10.0, 10.0);
					LAi_QuestDelay("Muelle_Blythe3", 4.0);
				}
				else 
				{
					if (GetOfficersIndex(Pchar, 3) != -1)
					{
						sld = &Characters[GetOfficersIndex(Pchar, 3)];
						Pchar.Temp.Officer.dialog = sld.Dialog.Filename;
						Pchar.Temp.Officer.dialognode = characters[GetOfficersIndex(Pchar, 3)].dialog.currentnode;
						sld.Dialog.Filename = "to_say.c";
						characters[GetOfficersIndex(Pchar, 3)].dialog.currentnode = "First time";
						LAi_ActorDialog(&Characters[GetOfficersIndex(Pchar, 3)], pchar, "", 10.0, 10.0);
						LAi_QuestDelay("Muelle_Blythe4", 4.0);
					}
				}
			}
			AddQuestrecord("nigel", "22");
		break;
	
		case "Muelle_Blythe2":
			sld = &Characters[GetOfficersIndex(Pchar, 1)];
			sld.Dialog.Filename = Pchar.Temp.Officer.dialog;
			characters[GetOfficersIndex(Pchar, 1)].dialog.currentnode = Pchar.Temp.Officer.dialognode;
		break;
	
		case "Muelle_Blythe3":
			sld = &Characters[GetOfficersIndex(Pchar, 1)];
			sld.Dialog.Filename = Pchar.Temp.Officer.dialog;
			characters[GetOfficersIndex(Pchar, 1)].dialog.currentnode = Pchar.Temp.Officer.dialognode;
		break;
	
		case "Muelle_Blythe4":
			sld = &Characters[GetOfficersIndex(Pchar, 1)];
			sld.Dialog.Filename = Pchar.Temp.Officer.dialog;
			characters[GetOfficersIndex(Pchar, 1)].dialog.currentnode = Pchar.Temp.Officer.dialognode;
		break;
	
	
		case "Maxwell_talk":
			PlaceCharacter(characterFromID("Friedrich Maxwell"), "goto", "QC_tavern");
			LAi_SetActorType(CharacterFromID("Friedrich Maxwell")); 
			LAi_ActorDialog(CharacterFromID("Friedrich Maxwell"), pchar, "", 3.0, 1.0);
		break;
	
		case "Maxwell_talk2":
			//characters[GetCharacterIndex("Lambrecht Fobes")].dialog.currentnode = "continue";
			LAi_ActorDialog (characterfromID("Friedrich Maxwell"), PChar, "", 1.0, 1.0);
		break;
	
		case "Pirates_vs_Blaze":
			startquestMovie(true, true, false);
	
			sld = LAi_CreateFantomCharacter("corsair1", "goto", "goto23");
			sld.id = "offended_pirate1";
			sld.skill.Fencing = "1";
			LAi_SetActorType(CharacterFromID("offended_pirate1"));
	
			sld = LAi_CreateFantomCharacter("corsair1_1", "goto", "character3");
			sld.id = "offended_pirate2";
			sld.skill.Fencing = "1";
			sld.Dialog.Filename = "Pirates_vs_Blaze.c";
			LAi_SetActorType(CharacterFromID("offended_pirate2"));
	
			sld = LAi_CreateFantomCharacter("bocman4", "goto", "goto19");
			sld.id = "offended_pirate3";
			sld.skill.Fencing = "1";
			LAi_SetActorType(CharacterFromID("offended_pirate3"));
	
			sld = LAi_CreateFantomCharacter("bocman", "goto", "goto33");
			sld.id = "offended_pirate5";
			sld.skill.Fencing = "1";
			LAi_SetActorType(CharacterFromID("offended_pirate5"));
	
			LAi_ActorDialog(characterfromID("offended_pirate2"), PChar, "", 10.0, 1.0);
		break;
	
	
		case "Voysey_death":
			characters[GetCharacterIndex("Artois Voysey")].dialog.currentnode = "continue3";
		break;
	
		//___________EDGAR ATTWOOD QUEST--------------
	
		/*case "Attwood_Adventure":
			if(FindFellowTravellers(PChar, CharacterFromId("Edgar Attwood")) == FELLOWTRAVEL_OFFICER)
			{
			LAi_SetActorType(Pchar);
			Pchar.Temp.self.dialog = Pchar.dialog.currentnode;
			Pchar.dialog.currentnode = "Attwood_lost";
			LAi_ActorSelfDialog(Pchar, "player_back");
			RemovePassenger(pchar, &characters[GetCharacterIndex("Edgar Attwood")]);
			ChangeCharacterAddressGroup(CharacterFromID("Edgar Attwood"), "Greenford_tavern", "goto", "goto5");
			Pchar.quest.Artois2.win_condition.l1 = "location";
			Pchar.quest.Artois2.win_condition.l1.character = "Blaze";
			Pchar.quest.Artois2.win_condition.l1.location = "Greenford_tavern";
			PChar.quest.Artois2.win_condition = "Attwood_fight";
			}
		break;
	
		case "Attwood_fight":
			sld = LAi_CreateFantomCharacter("bocman", "goto", "goto17");
			sld.id = "guy_in_tavern";
			sld.skill.Fencing = "1";
			LAi_SetActorType(CharacterFromID("guy_in_tavern"));
	
			sld = LAi_CreateFantomCharacter("bocman3", "goto", "goto6");
			sld.id = "guy_in_tavern1";
			sld.skill.Fencing = "1";
			LAi_SetActorType(CharacterFromID("guy_in_tavern1"));
	
			LAi_SetActorType(CharacterFromID("Edgar Attwood"));
			LAi_SetActorType(Pchar);
			LAi_ActorWaitDialog(CharacterFromID("Edgar Attwood"), Pchar); 
			characters[GetCharacterIndex("Edgar Attwood")].dialog.currentnode = "Setup1";
			LAi_ActorDialog(pchar, CharacterFromID("Edgar Attwood"), "", 10, 10);
	
		break;
	
		case "Attwood_fight1":
			LAi_QuestDelay("Attwood_fight2", 0.01);
		break;
	
		case "Attwood_fight2":
			SetOfficersIndex(Pchar, -1, GetCharacterIndex("Edgar Attwood"));
			LAi_SetOfficerType(CharacterFromID("Edgar Attwood"));
			LAi_SetPlayerType(PChar);
			LAi_group_Register("bandits");
			LAi_group_MoveCharacter(CharacterFromID("guy_in_tavern"), "bandits"); 
			LAi_group_MoveCharacter(CharacterFromID("guy_in_tavern1"), "bandits"); 
			LAi_group_MoveCharacter(CharacterFromID("Edgar Attwood"), LAI_GROUP_PLAYER);
			LAi_group_FightGroups("bandits", LAI_GROUP_PLAYER, true);
		break;
	
		case "Smugglers_fight1":
			LAi_QuestDelay("Smugglers_fight2", 0.01);
		break;
	
		case "Smugglers_fight2":
			SetOfficersIndex(Pchar, -1, GetCharacterIndex("Edgar Attwood"));
			LAi_SetOfficerType(CharacterFromID("Edgar Attwood"));
			LAi_SetPlayerType(PChar);
			LAi_group_Register("bandits");
			LAi_group_MoveCharacter(CharacterFromID("offended_sm"), "bandits"); 
			LAi_group_MoveCharacter(CharacterFromID("offended_sm1"), "bandits"); 
			LAi_group_MoveCharacter(CharacterFromID("offended_sm2"), "bandits"); 
			LAi_group_MoveCharacter(CharacterFromID("offended_sm3"), "bandits"); 
			LAi_group_MoveCharacter(CharacterFromID("Edgar Attwood"), LAI_GROUP_PLAYER);
			LAi_group_FightGroups("bandits", LAI_GROUP_PLAYER, true);
		break;
	
		case "Smugglers_fight3":
			LAi_QuestDelay("Smugglers_fight4", 0.01);
		break;
	
		case "Smugglers_fight4":
			SetOfficersIndex(Pchar, -1, GetCharacterIndex("Edgar Attwood"));
			LAi_SetOfficerType(CharacterFromID("Edgar Attwood"));
			LAi_SetPlayerType(PChar);
			LAi_group_Register("bandits");
			LAi_group_MoveCharacter(CharacterFromID("offended_sm"), "bandits"); 
			LAi_group_MoveCharacter(CharacterFromID("offended_sm1"), "bandits"); 
			LAi_group_MoveCharacter(CharacterFromID("offended_sm2"), "bandits"); 
			LAi_group_MoveCharacter(CharacterFromID("offended_sm3"), "bandits"); 
			LAi_group_MoveCharacter(CharacterFromID("Edgar Attwood"), "Good_boys");
			LAi_group_FightGroups("bandits", "Good_boys", true);
		break;
	
		case "Pirates_fight1":
			LAi_QuestDelay("Pirates_fight2", 0.01);
		break;
	
		case "Pirates_fight2":
			LAi_SetPlayerType(PChar);
			LAi_group_Register("bandits");
			LAi_group_MoveCharacter(CharacterFromID("offended_pirate1"), "bandits"); 
			LAi_group_MoveCharacter(CharacterFromID("offended_pirate2"), "bandits"); 
			LAi_group_MoveCharacter(CharacterFromID("offended_pirate3"), "bandits"); 
			LAi_group_MoveCharacter(CharacterFromID("offended_pirate5"), "bandits"); 
			LAi_group_FightGroups("bandits", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("bandits", "Come_to_papa");
		break;
	
		case "Attwood_win":
			endQuestMovie();
		break;
	
		case "Attwood_listed":
			SetOfficersIndex(Pchar, -1, GetCharacterIndex("Edgar Attwood"));
			LAi_SetOfficerType(CharacterFromID("Edgar Attwood"));
		break;
	
		case "redmond_Attwood":
			if (!CharacterIsDead(&characters[GetCharacterIndex("Edgar Attwood")]))
			{
				if(FindFellowTravellers(PChar, CharacterFromId("Edgar Attwood")) == FELLOWTRAVEL_OFFICER)
				{
					RemovePassenger(pchar, &characters[GetCharacterIndex("Edgar Attwood")]);
					LAi_SetActorType(CharacterFromID("Edgar Attwood"));
					LAi_SetSitType(CharacterFromID("Edgar Attwood"));
					ChangeCharacterAddressGroup(CharacterFromID("Edgar Attwood"), "none", "sit", "sit2");
					characters[GetCharacterIndex("Edgar Attwood")].blade = "";
					ChangeCharacterAddressGroup(CharacterFromID("Jack Greenfield"), "Redmond_tavern", "sit", "sit10");
					ChangeCharacterAddressGroup(CharacterFromID("Martin Warner"), "Redmond_tavern", "sit", "sit5");
					LAi_CharacterDisableDialog(CharacterFromID("Martin Warner"));
					characters[GetCharacterIndex("Redmond prison commendant")].dialog.currentnode = "continue2";
	
					if ((GetOfficersIndex(Pchar, 1) == -1) && (GetOfficersIndex(Pchar, 2) == -1) && (GetOfficersIndex(Pchar, 3) == -1))
					{
						sld = LAi_CreateFantomCharacter("corsair2", "goto", "goto_43");
						LAi_SetActorType(sld);
						sld.id = "to_say1";
						sld.Dialog.Filename = "to_say1.c";
						LAi_ActorDialog(characterfromID("to_say1"), pchar, "", 10, 40);
					}
					if (GetOfficersIndex(Pchar, 1) != -1)
					{
						sld = &Characters[GetOfficersIndex(Pchar, 1)];
						Pchar.Temp.Officer.dialog = sld.Dialog.Filename;
						Pchar.Temp.Officer.dialognode = characters[GetOfficersIndex(Pchar, 1)].dialog.currentnode;
						sld.Dialog.Filename = "to_say1.c";
						characters[GetOfficersIndex(Pchar, 1)].dialog.currentnode = "First time";
						LAi_ActorDialog(&Characters[GetOfficersIndex(Pchar, 1)], pchar, "", 10, 10);
						LAi_QuestDelay("Muelle_Blythe2", 10.0);
					}
					else 
					{
						if (GetOfficersIndex(Pchar, 2) != -1)
						{
							sld = &Characters[GetOfficersIndex(Pchar, 2)];
							Pchar.Temp.Officer.dialog = sld.Dialog.Filename;
							Pchar.Temp.Officer.dialognode = characters[GetOfficersIndex(Pchar, 2)].dialog.currentnode;
							sld.Dialog.Filename = "to_say1.c";
							characters[GetOfficersIndex(Pchar, 2)].dialog.currentnode = "First time";
							LAi_ActorDialog(&Characters[GetOfficersIndex(Pchar, 2)], pchar, "", 10, 10);
							LAi_QuestDelay("Muelle_Blythe3", 4.0);
						}
						else 
						{
							if (GetOfficersIndex(Pchar, 3) != -1)
							{
								sld = &Characters[GetOfficersIndex(Pchar, 3)];
								Pchar.Temp.Officer.dialog = sld.Dialog.Filename;
								Pchar.Temp.Officer.dialognode = characters[GetOfficersIndex(Pchar, 3)].dialog.currentnode;
								sld.Dialog.Filename = "to_say1.c";
								characters[GetOfficersIndex(Pchar, 3)].dialog.currentnode = "First time";
								LAi_ActorDialog(&Characters[GetOfficersIndex(Pchar, 3)], pchar, "", 10, 10);
								LAi_QuestDelay("Muelle_Blythe4", 4.0);
							}
						}
					}
				}
			}	
		break;
	
		case "Let_my_edgar_go":
			SetCharacterToNearLocatorFromMe("Edgar Attwood", 10);
			SetOfficersIndex(Pchar, -1, GetCharacterIndex("Edgar Attwood"));
			LAi_SetOfficerType(CharacterFromID("Edgar Attwood"));
		break;
		
		case "soldier_in_tavern0":
			LAi_QuestDelay("soldier_in_tavern", 0.01);
		break;
	
		case "soldier_in_tavern":
			LAi_ActorDialog(Pchar, CharacterFromID("Jack Greenfield"), "", 10, 4);
			LAi_Fade("soldier_in_tavern0.51", "soldier_in_tavern0.52");
		break;
	
		case "soldier_in_tavern0.51":
			TeleportCharacterToLocator(Pchar, "sit", "sit4");
			LAi_SetActorType(Pchar);
			LAi_SetActorType(CharacterFromID("Jack Greenfield"));
			LAi_ActorSetSitMode(CharacterFromID("Jack Greenfield"));
			LAi_SetActorType(CharacterFromID("Martin Warner"));
			LAi_ActorSetSitMode(CharacterFromID("Martin Warner"));
		break;
	
		case "soldier_in_tavern0.52":
			LAi_ActorSetSitMode(Pchar);
			LAi_ActorWaitDialog(CharacterFromID("Jack Greenfield"), Pchar);
			LAi_ActorDialog(Pchar, CharacterFromID("Jack Greenfield"), "", 10, 4);
		break;
		
		case "soldier_in_tavern1":
			LAi_QuestDelay("soldier_in_tavern2", 2);
		break;
	
		case "soldier_in_tavern2":
			LAi_ActorWaitDialog(CharacterFromID("Martin Warner"), Pchar);
			LAi_ActorDialog(Pchar, CharacterFromID("Martin Warner"), "", 10, 4);
		break;
	
		case "soldier_in_tavern3":
			LAi_ActorWaitDialog(CharacterFromID("Jack Greenfield"), Pchar);
			LAi_ActorDialog(Pchar, CharacterFromID("Jack Greenfield"), "", 10, 4);
		break;
	
		case "soldier_in_tavern4":
			LAi_ActorWaitDialog(CharacterFromID("Martin Warner"), Pchar);
			LAi_ActorDialog(Pchar, CharacterFromID("Martin Warner"), "", 10, 4);
	 	break;
	
		case "convoy":
			LAi_Fade("fight_with_convoy", "convoy_fight1");
		break;
	
		case "fight_with_convoy":
			ChangeCharacterAddressGroup(CharacterFromID("Jack Greenfield"), "none", "sit", "sit10");
			ChangeCharacterAddressGroup(CharacterFromID("Martin Warner"), "none", "sit", "sit5");
	
			DoQuestReloadToLocation("redmond_port", "goto", "goto_2", "");
		break;
	
		case "convoy_fight1":
			sld = LAi_CreateFantomCharacter("soldier_Eng2", "goto", "goto_66");
			LAi_SetActorType(sld);
			sld.id = "sold1";
	
			sld = LAi_CreateFantomCharacter("soldier_Eng3", "goto", "goto_51");
			LAi_SetActorType(sld);
			sld.id = "sold2";
	
			sld = LAi_CreateFantomCharacter("soldier_Eng4", "goto", "goto_50");
			LAi_SetActorType(sld);
			sld.id = "sold3";
	
			sld = LAi_CreateFantomCharacter("soldier_Eng5", "goto", "goto_60");
			LAi_SetActorType(sld);
			sld.id = "sold4";
	
			sld = LAi_CreateFantomCharacter("soldier_Eng6", "goto", "goto_63");
			LAi_SetActorType(sld);
			sld.id = "sold5";
	
			LAi_SetActorType(CharacterFromID("Edgar Attwood"));
			LAi_SetActorType(CharacterFromID("zek"));
			LAi_SetActorType(CharacterFromID("zek2"));
			ChangeCharacterAddressGroup(CharacterFromID("Edgar Attwood"), "Redmond_port", "goto", "goto_64");
			ChangeCharacterAddressGroup(CharacterFromID("zek2"), "Redmond_port", "goto", "goto_62");
			ChangeCharacterAddressGroup(CharacterFromID("zek"), "Redmond_port", "goto", "goto_61");
	
			LAi_ActorGoToLocator(CharacterFromID ("Edgar Attwood"), "goto", "goto_34", "Edgar_is_on_board", -1);
			LAi_ActorGoToLocator(CharacterFromID ("zek2"), "goto", "goto_34", "Edgar_is_on_board", -1);
			LAi_ActorGoToLocator(CharacterFromID ("zek"), "goto", "goto_34", "Edgar_is_on_board", -1);
			LAi_ActorGoToLocator(CharacterFromID ("sold5"), "goto", "goto_34", "Edgar_is_on_board", -1);
			LAi_ActorGoToLocator(CharacterFromID ("sold4"), "goto", "goto_34", "Edgar_is_on_board", -1);
			LAi_ActorGoToLocator(CharacterFromID ("sold3"), "goto", "goto_34", "Edgar_is_on_board", -1);
			LAi_ActorGoToLocator(CharacterFromID ("sold2"), "goto", "goto_34", "Edgar_is_on_board", -1);
			LAi_ActorGoToLocator(CharacterFromID ("sold1"), "goto", "goto_34", "Edgar_is_on_board", -1);
	
			LAi_group_MoveCharacter(CharacterFromID ("sold5"), "convoy"); 
			LAi_group_MoveCharacter(CharacterFromID ("sold4"), "convoy");
			LAi_group_MoveCharacter(CharacterFromID ("sold3"), "convoy");
			LAi_group_MoveCharacter(CharacterFromID ("sold2"), "convoy"); 
	
			LAi_SetActorType(Pchar);
			LAi_QuestDelay("make_player", 1); 
		break;
	
		case "make_player":
			LAi_SetPlayerType(Pchar);
	
			LAi_SetCheckMinHP(CharacterFromID ("sold1"), 35, false, "convoy_is_angry");
			LAi_SetCheckMinHP(CharacterFromID ("sold2"), 35, false, "convoy_is_angry"); 
			LAi_SetCheckMinHP(CharacterFromID ("sold3"), 35, false, "convoy_is_angry");
			LAi_SetCheckMinHP(CharacterFromID ("sold4"), 35, false, "convoy_is_angry");
			LAi_SetCheckMinHP(CharacterFromID ("sold5"), 35, false, "convoy_is_angry");
		break;
	
		case "stand_up":
			LAi_Fade("stand_up1", "stand_up2");
			LAi_SetPlayerType(Pchar); 
		break;
	
		case "stand_up1":
			ChangeCharacterAddressGroup(CharacterFromID("Jack Greenfield"), "none", "sit", "sit10");
			ChangeCharacterAddressGroup(CharacterFromID("Martin Warner"), "none", "sit", "sit5");
	
			TeleportCharacterToLocator(Pchar, "goto", "goto20");
			LAi_ActorSetStayMode(Pchar);
		break;
	
		case "stand_up2":
			LAi_SetPlayerType(Pchar); 
		break;
	
		case "Edgar_is_on_board":
			WaitDate("", 0, 0, 0, 0, 1);
			SetCharacterShipLocation( Pchar, "Redmond_port" );
	
			Group_CreateGroup("Jack Greenfield");
			Group_AddCharacter("Jack Greenfield", "Jack Greenfield");
			Group_SetGroupCommander("Jack Greenfield", "Jack Greenfield");
			Group_SetTaskMove("Jack Greenfield", 10000, 10000);
			Group_SetPursuitGroup("Jack Greenfield", PLAYER_GROUP);
			Group_SetAddress("Jack Greenfield", "redmond", "", "");
	
			TeleportCharacterFromCurLocationToLocation("sea_1_back", "", "");
	
			Pchar.quest.Battle.win_condition.l1 = "NPC_Death";
			Pchar.quest.Battle.win_condition.l1.character = "Jack Greenfield";
			PChar.quest.Battle.win_condition = "list_Attwood";
		break;
	
		case "list_Attwood":
			if (characters[GetCharacterIndex("Jack Greenfield")].Killer.status == KILL_BY_ABORDAGE)
			{
			SetOfficersIndex(Pchar, -1, GetCharacterIndex("Edgar Attwood"));
			LAi_SetOfficerType(CharacterFromID("Edgar Attwood"));
			}
		break;
	
		case "convoy_is_angry":
			LAi_group_MoveCharacter(CharacterFromID ("sold5"), "convoy"); 
			LAi_group_MoveCharacter(CharacterFromID ("sold4"), "convoy");
			LAi_group_MoveCharacter(CharacterFromID ("sold3"), "convoy");
			LAi_group_MoveCharacter(CharacterFromID ("sold2"), "convoy"); 
			LAi_type_actor_Reset(CharacterFromID ("sold2"));
			LAi_type_actor_Reset(CharacterFromID ("sold1"));
			LAi_type_actor_Reset(CharacterFromID ("sold3"));
			LAi_type_actor_Reset(CharacterFromID ("sold4"));
			LAi_type_actor_Reset(CharacterFromID ("sold5"));
			LAi_type_actor_Reset(CharacterFromID ("Edgar Attwood"));
			LAi_type_actor_Reset(CharacterFromID ("zek"));
			LAi_type_actor_Reset(CharacterFromID ("zek2"));
			LAi_group_FightGroups("convoy", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("convoy", "list_Attwood2"); 
		break;
	
		case "list_Attwood2":
			SetOfficersIndex(Pchar, -1, GetCharacterIndex("Edgar Attwood"));
			LAi_SetOfficerType(CharacterFromID("Edgar Attwood"));
		break;*/
			
		case "removed_officer_runaway":
			GetCharacterPos(GetMainCharacter(), &locx, &locy, &locz);
			string sorlocator = LAi_FindNearestFreeLocator("reload", locx, locy, locz);
			int remOff = pchar.removed_officer;
			homelocation = characters[remOff].homelocation;
			homegroup = characters[remOff].homelocation.group;
			homelocator = characters[remOff].homelocation.locator;
			LAi_ActorRunToLocation(&characters[remOff], "reload", sorlocator, homelocation, homegroup, homelocator, "removing_officer_comleted", 10.0);
		break;
			
		case "removing_officer_comleted":
			int remOffr = pchar.removed_officer;
			switch (characters[remOffr].homestate)
			{
				case "sit": LAi_SetSitType(&characters[remOffr]); break;
				case "citizen": LAi_SetCitizenType(&characters[remOffr]); break;
			}
			characters[remOffr].dialog.currentnode = "hired_again";
		break;
		
		case "trade_quest_open":		
			iTradeGoods = pchar.quest.iTradeGoods;
			iQuantityGoods = pchar.quest.iQuantityGoods;
			iTradeNation = pchar.quest.iTradeNation;
			
			//Log_SetStringToLog(iTradeNation);
			
			AddCharacterGoods(pchar, iTradeGoods, iQuantityGoods);
			//задаем квест
			pchar.quest.generate_trade_quest.win_condition.l1 = "Timer";
			pchar.quest.generate_trade_quest.win_condition.l1.date.day = GetAddingDataDay(0, 20, 0);
    			pchar.quest.generate_trade_quest.win_condition.l1.date.month = GetAddingDataMonth(0, 20, 0);
			pchar.quest.generate_trade_quest.win_condition.l1.date.year = GetAddingDataYear(0, 20, 0);
			pchar.quest.generate_trade_quest.win_condition = "generate_trade_quest";
			pchar.quest.generate_trade_quest_progress = "begin";
			
			switch (iTradeNation)
			{
				case FRANCE: DeleteQuestHeader("trade_fra"); SetQuestHeader("trade_fra"); AddQuestRecord("trade_fra", "1"); break;
				case SPAIN: DeleteQuestHeader("trade_spa"); SetQuestHeader("trade_spa"); AddQuestRecord("trade_spa", "1"); break;
				case HOLLAND: DeleteQuestHeader("trade_hol"); SetQuestHeader("trade_hol"); AddQuestRecord("trade_hol", "1"); break;
				case PORTUGAL: DeleteQuestHeader("trade_por"); SetQuestHeader("trade_por"); AddQuestRecord("trade_por", "1"); break;
				case ENGLAND: 
					iColony = rand(2);
					switch (iColony)
					{
						case 0: DeleteQuestHeader("trade_red"); SetQuestHeader("trade_red"); AddQuestRecord("trade_red", "1"); pchar.colony = 0; break;
						case 1: DeleteQuestHeader("trade_green"); SetQuestHeader("trade_green"); AddQuestRecord("trade_green", "1"); pchar.colony = 1; break;
						case 2: DeleteQuestHeader("trade_ox"); SetQuestHeader("trade_ox"); AddQuestRecord("trade_ox", "1"); pchar.colony = 2; break;
					}
				break;
			}	
		break;
		
		case "close_trade_quest":
			iTradeNation = pchar.quest.iTradeNation;
			switch (iTradeNation)
			{
				case FRANCE: CloseQuestHeader("trade_fra"); break;
				case SPAIN: CloseQuestHeader("trade_spa"); break;
				case HOLLAND: CloseQuestHeader("trade_hol"); break;
				case PORTUGAL: CloseQuestHeader("trade_por"); break;
				case ENGLAND: 
					iColony = pchar.colony;
					switch (iColony)
					{
						case 0: CloseQuestHeader("trade_red"); break;
						case 1: CloseQuestHeader("trade_green"); break;
						case 2: CloseQuestHeader("trade_ox"); break;
					}
				break;
			}	
		break;
		
		case "amiel_go_away":
			LAi_SetActorType(characterFromID("Amiel Berangere"));
			LAi_ActorGoToLocation(characterFromID("Amiel Berangere"), "reload", "reload1", "none", "", "", "", 10.0);
			AddPartyExp(pchar, 1500);
		break;
		
		case "donation":
			int iDonation = makeint(pchar.quest.donate);
			int iRep = makeint(pchar.reputation);
			int iRepIncr;
			if (iRep <10)
			{
				if (iDonation > 1000)
				{
					iRepIncr = iDonation/250;
					ChangeCharacterReputation(pchar, iRepIncr);
					pchar.quest.donate = 0;
				}
			}
			if (iRep <20 && iRep >=10)
			{
				if (iDonation > 2000)
				{
					iRepIncr = iDonation/500;
					ChangeCharacterReputation(pchar, iRepIncr);
					pchar.quest.donate = 0;
				}
			}
			if (iRep <30 && iRep >=20)
			{
				if (iDonation > 3000)
				{
					iRepIncr = iDonation/750;
					ChangeCharacterReputation(pchar, iRepIncr);
					pchar.quest.donate = 0;
				}
			}
			if (iRep <40 && iRep >=30)
			{
				if (iDonation > 4000)
				{
					iRepIncr = iDonation/1000;
					ChangeCharacterReputation(pchar, iRepIncr);
					pchar.quest.donate = 0;
				}
			}
			if (iRep <50 && iRep >=40)
			{
				if (iDonation > 5000)
				{
					iRepIncr = iDonation/1250;
					ChangeCharacterReputation(pchar, iRepIncr);
					pchar.quest.donate = 0;
				}
			}
			if (iRep <60 && iRep >=50)
			{
				if (iDonation > 6000)
				{
					iRepIncr = iDonation/1500;
					ChangeCharacterReputation(pchar, iRepIncr);
					pchar.quest.donate = 0;
				}
			}
			if (iRep <70 && iRep >=60)
			{
				if (iDonation > 7000)
				{
					iRepIncr = iDonation/1750;
					ChangeCharacterReputation(pchar, iRepIncr);
					pchar.quest.donate = 0;
				}
			}
			if (iRep <80 && iRep >=70)
			{
				if (iDonation > 8000)
				{
					iRepIncr = iDonation/2000;
					ChangeCharacterReputation(pchar, iRepIncr);
					pchar.quest.donate = 0;
				}
			}
			if (iRep <90 && iRep >=80)
			{
				if (iDonation > 9000)
				{
					iRepIncr = iDonation/2250;
					ChangeCharacterReputation(pchar, iRepIncr);
					pchar.quest.donate = 0;
				}
			}
		break;
	
		case "prepare_for_convoy_quest":
			iPassenger = rand(3);
			switch (iPassenger)
			{
				case 0: 
					characters[getCharacterIndex("Quest trader")].model = "storeman";
					characters[getCharacterIndex("Quest trader")].headmodel = "h_storeman";
					characters[getCharacterIndex("Quest trader")].faceID = 42;
				break;
				case 1: 
					characters[getCharacterIndex("Quest trader")].model = "storeman2";
					characters[getCharacterIndex("Quest trader")].headmodel = "h_storeman2";
					characters[getCharacterIndex("Quest trader")].faceID = 43;
				break;
				case 2: 
					characters[getCharacterIndex("Quest trader")].model = "old_man1";
					characters[getCharacterIndex("Quest trader")].headmodel = "h_old_man1";
					characters[getCharacterIndex("Quest trader")].faceID = 32;
				break;
				case 3: 
					characters[getCharacterIndex("Quest trader")].model = "old_man2";
					characters[getCharacterIndex("Quest trader")].headmodel = "h_old_man2";
					characters[getCharacterIndex("Quest trader")].faceID = 33;
				break;
			}			
			homelocation = pchar.location;
			ChangeCharacterAddressGroup(characterFromID("Quest trader"), homelocation, "reload", "reload1");
			//PlaceCharacter(characterFromID("Quest trader"), "reload", homelocation);
			iPassenger = rand(5);
			if (iPassenger == 3) { iPassenger = 4; }
			characters[GetCharacterIndex("quest trader")].nation = iPassenger;
			pchar.quest.generate_convoy_quest_progress = "begin";
			LAi_SetActorType(characterFromID("Quest trader"));
			LAi_SetActorType(pchar);
			LAi_ActorFollow(pchar, characterFromID("quest trader"), "", 5.0);
			LAi_ActorFollow(characterFromID("quest trader"), pchar, "prepare_for_convoy_quest_2", 5.0);
		break;
		
		case "prepare_for_convoy_quest_2":
			LAi_SetPlayerType(pchar);
			LAi_ActorDialog(characterFromID("Quest trader"), pchar, "", 10.0, 1.0);
			characters[GetCharacterIndex("quest trader")].dialog.currentnode = "prepare_convoy_quest";
		break;
		
		case "convoy_refused":
			pchar.quest.generate_convoy_quest.over = "yes";
			pchar.quest.generate_convoy_quest_failed.over = "yes";
			pchar.quest.generate_convoy_quest_completed.over = "yes";
			GetCharacterPos(GetMainCharacter(), &locx, &locy, &locz);
			homelocator = LAi_FindNearestFreeLocator("reload", locx, locy, locz);
			LAi_SetActorType(characterFromID("quest trader"));
			LAi_ActorGoToLocation(characterFromID("quest trader"), "reload", homelocator, "none", "", "", "", 10.0);
		
			if (checkquestattribute("generate_convoy_quest_progress", "completed"))
			{
				iPassenger = makeint(pchar.quest.convoymoney) + makeint(pchar.rank)*100;
				AddPartyExp(pchar, iPassenger);
				iPassenger = makeint(pchar.quest.convoymoney)
				AddMoneyToCharacter(pchar, iPassenger);
				ChangeCharacterReputation(pchar, 1);
				RemoveCharacterCompanion(Pchar, characterFromID("quest trader"));
				pchar.quest.generate_convoy_quest_progress = "";
			}
			if (!checkquestattribute("generate_convoy_quest_progress", "begin"))
			{
				homelocation = pchar.quest.destination;
				switch (homelocation)
				{
					case "Falaise de Fleur": CloseQuestHeader("convoy_fra"); break;
					case "Isla Muelle": CloseQuestHeader("convoy_spa"); break;
					case "Douwesen": CloseQuestHeader("convoy_hol"); break;
					case "Conceicao": CloseQuestHeader("convoy_por"); break;
					case "Redmond": CloseQuestHeader("convoy_red"); break;
					case "Oxbay": CloseQuestHeader("convoy_ox"); break;
					case "Conceicao smugglers": CloseQuestHeader("convoy_smg"); break;
				}	
			}
			pchar.quest.generate_convoy_quest_progress = "";
		break;
		
		case "generate_convoy_quest":
			ChangeCharacterReputation(pchar, -3);
			DoQuestCheckDelay("convoy_failed", 0.0);
		break;
		
		case "generate_convoy_quest_failed":
			ChangeCharacterReputation(pchar, -5);
			DoQuestCheckDelay("convoy_failed", 0.0);
		break;
		
		case "convoy_failed":
			RemoveCharacterCompanion(Pchar, characterFromID("quest trader"));
			pchar.quest.generate_convoy_quest_progress = "";
			pchar.quest.generate_convoy_quest.over = "yes";
			pchar.quest.generate_convoy_quest_failed.over = "yes";
			pchar.quest.generate_convoy_quest_completed.over = "yes";
			homelocation = pchar.quest.destination;
			switch (homelocation)
			{
				case "Falaise de Fleur": CloseQuestHeader("convoy_fra"); break;
				case "Isla Muelle": CloseQuestHeader("convoy_spa"); break;
				case "Douwesen": CloseQuestHeader("convoy_hol"); break;
				case "Conceicao": CloseQuestHeader("convoy_por"); break;
				case "Redmond": CloseQuestHeader("convoy_red"); break;
				case "Oxbay": CloseQuestHeader("convoy_ox"); break;
				case "Conceicao smugglers": CloseQuestHeader("convoy_smg"); break;
			}
		break;
		
		case "generate_convoy_quest_completed":
			homelocation = pchar.location;
			PlaceCharacter(characterFromID("quest trader"), "goto", homelocation);
			LAi_SetActorType(characterFromID("quest trader"));
			LAi_SetActorType(pchar);
			LAi_ActorFollow(pchar, characterFromID("quest trader"), "", 2.0);
			LAi_ActorFollow(characterFromID("quest trader"), pchar, "generate_convoy_quest_completed_2", 2.0);
		break;
		
		case "generate_convoy_quest_completed_2":
			LAi_type_actor_Reset(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("quest trader"));
			LAi_ActorDialog(characterFromID("quest trader"), pchar, "pchar_back_to_player", 2.0, 1.0);
			characters[GetCharacterIndex("quest trader")].dialog.currentnode = "complete_convoy_quest";
			pchar.quest.generate_convoy_quest_progress = "completed";
		break;
		
		case "convoy_agreeded":
			SetCompanionIndex(Pchar, -1, GetCharacterIndex("quest trader"));
			SetCharacterRemovable(characterFromID("quest trader"), false);
			
			GetCharacterPos(GetMainCharacter(), &locx, &locy, &locz);
			homelocator = LAi_FindNearestFreeLocator("reload", locx, locy, locz);
			LAi_SetActorType(characterFromID("quest trader"));
			LAi_ActorGoToLocation(characterFromID("quest trader"), "reload", homelocator, "none", "", "", "", 10.0);
			
			string sdest;

			switch (pchar.quest.destination)
			{
				case "Falaise De Fleur": DeleteQuestHeader("convoy_fra"); SetQuestHeader("convoy_fra"); AddQuestRecord("convoy_fra", "1"); sDest = "Falaise_de_fleur_port_01"; break;
				case "Isla Muelle": DeleteQuestHeader("convoy_spa"); SetQuestHeader("convoy_spa"); AddQuestRecord("convoy_spa", "1"); sDest = "Muelle_port"; break;
				case "Douwesen": DeleteQuestHeader("convoy_hol"); SetQuestHeader("convoy_hol"); AddQuestRecord("convoy_hol", "1"); sDest = "Douwesen_port"; break;
				case "Conceicao": DeleteQuestHeader("convoy_por"); SetQuestHeader("convoy_por"); AddQuestRecord("convoy_por", "1"); sDest = "Conceicao_port"; break;
				case "Redmond": DeleteQuestHeader("convoy_red"); SetQuestHeader("convoy_red"); AddQuestRecord("convoy_red", "1"); sDest = "Redmond_port"; break;
				case "Oxbay": DeleteQuestHeader("convoy_ox"); SetQuestHeader("convoy_ox"); AddQuestRecord("convoy_ox", "1"); sDest = "Oxbay_port"; break;
				case "Conceicao smugglers": DeleteQuestHeader("convoy_smg"); SetQuestHeader("convoy_smg"); AddQuestRecord("convoy_smg", "1"); sDest = "Conceicao_shore_02"; break;
			}
			pchar.quest.generate_convoy_quest_completed.win_condition.l1 = "Location";
			pchar.quest.generate_convoy_quest_completed.win_condition.l1.location = sDest;
			pchar.quest.generate_convoy_quest_completed.win_condition = "generate_convoy_quest_completed";
		break;
		
		case "prepare_gen_convoy_quest":
			GenerateConvoyQuest();
			characters[GetCharacterIndex("quest trader")].dialog.currentnode = "prepare_convoy_quest_4";
			LAi_ActorDialog(characterfromID("quest trader"), pchar, "", 1.0, 1.0);
		break;
		
		case "danielle_sailor_statuets_exit":
			LAi_Fade("danielle_sailor_statuets_exit_2", "");
		break;
		
		case "danielle_sailor_statuets_exit_2":
			ChangeCharacterAddress(characterFromID("danielle_sailor"), "none", "none");
			Locations[FindLocation("Douwesen_shore_01")].reload.l1.disable = 0;
			Locations[FindLocation("Douwesen_shore_01")].reload.l2.disable = 0;
		break;
		
		case "danielle_join_to_us_when_we_are_swimm_to_douwesen_fo_search_rheims":
			pchar.quest.main_line = "blaze_goto_douwesen_with_danielle";
			pchar.quest.to_douwesen_port_search_blaze.win_condition.l1 = "location";
			pchar.quest.to_douwesen_port_search_blaze.win_condition.l1.location = "douwesen_port";
			pchar.quest.to_douwesen_port_search_blaze.win_condition = "to_douwesen_port_search_blaze_complete";

			pchar.quest.to_douwesen_shore_1_search_blaze.win_condition.l1 = "location";
			pchar.quest.to_douwesen_shore_1_search_blaze.win_condition.l1.location = "douwesen_shore_01";
			pchar.quest.to_douwesen_shore_1_search_blaze.win_condition = "to_douwesen_shore_1_search_blaze_complete";

			pchar.quest.to_douwesen_shore_2_search_blaze.win_condition.l1 = "location";
			pchar.quest.to_douwesen_shore_2_search_blaze.win_condition.l1.location = "douwesen_shore_02";
			pchar.quest.to_douwesen_shore_2_search_blaze.win_condition = "to_douwesen_shore_2_search_blaze_complete";
			SetCompanionIndex(pchar, -1, GetCharacterIndex("danielle"));
			SetCharacterRemovable(characterFromID("danielle"), false);
			
			pchar.quest.danielle_death.win_condition.l1 = "npc_death";
			pchar.quest.danielle_death.win_condition.l1.character = "danielle";
			pchar.quest.danielle_death.win_condition = "danielle_death";
		break;
		
		case "prepare_for_meet_ferro":
			AddQuestrecord("search_danielle", "2");
			pchar.quest.main_line = "search_for_Ferro_Cerezo";

			pchar.quest.kill_ferro_cerezo.win_condition.l1 = "NPC_Death";
			pchar.quest.kill_ferro_cerezo.win_condition.l1.character = "ferro cerezo";
			pchar.quest.kill_ferro_cerezo.win_condition = "kill_ferro_cerezo_complete";

			pchar.quest.abording_ferro_cerezo.win_condition.l1 = "Character_Capture";
			pchar.quest.abording_ferro_cerezo.win_condition.l1.character = "ferro cerezo";
			pchar.quest.abording_ferro_cerezo.win_condition = "abording_ferro_cerezo_complete";
			
			ChangeCharacterAddressGroup(characterFromID("ferro cerezo"), "Muelle_tavern", "sit", "sit5");
			
			pchar.quest.ferro_to_conceicao.win_condition.l1 = "Timer";
			PChar.quest.ferro_to_conceicao.win_condition.l1.date.day = GetAddingDataDay(0, 0, 6);
			PChar.quest.ferro_to_conceicao.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 6);
			PChar.quest.ferro_to_conceicao.win_condition.l1.date.year = GetAddingDataYear(0, 0, 6);
			pchar.quest.ferro_to_conceicao.win_condition = "ferro_to_conceicao";
		break;
		
		case "ferro_to_conceicao":
			characters[GetCharacterIndex("Ferro Cerezo")].location = "Conceicao_tavern";
			characters[GetCharacterIndex("Ferro Cerezo")].location.group = "sit";
			characters[GetCharacterIndex("Ferro Cerezo")].location.locator = "sit5";
		break;
		
		case "prepare_ferro_to_Sea":
			pchar.quest.main_line = "killing_ferro_cerezo";
			pchar.quest.to_sea_for_capture_cerezo.win_condition.l1 = "location";
			if (pchar.location == "Muelle_tavern")
			{
				pchar.quest.to_sea_for_capture_cerezo.win_condition.l1.location = "IslaMuelle";
			}
			else
			{
				pchar.quest.to_sea_for_capture_cerezo.win_condition.l1.location = "Conceicao";
			}
			pchar.quest.to_sea_for_capture_cerezo.win_condition = "to_sea_for_capture_cerezo";
			AddQuestRecord("search_danielle", "6");
		break;
		
		case "to_sea_for_capture_cerezo":
			Group_AddCharacter("ferro cerezo", "ferro cerezo");
			Group_SetGroupCommander("ferro cerezo", "ferro cerezo");
			Group_SetPursuitGroup("ferro cerezo", PLAYER_GROUP);
			Group_SetTaskAttack("ferro cerezo", PLAYER_GROUP);
			Group_LockTask("ferro cerezo");
			Group_SetAddress("ferro cerezo", Characters[GetMainCharacterIndex()].location, "", "");
			SetCharacterRelation(GetCharacterIndex("IslaMuelle Commander"),GetCharacterIndex("Ferro cerezo"),RELATION_FRIEND);
			SetCharacterRelation(GetCharacterIndex("Conceicao Commander"),GetCharacterIndex("Ferro Cerezo"),RELATION_FRIEND);
		break;
		
		case "rys_becomes_officer":
			AddMoneyToCharacter(pchar, -500);
			AddPassenger(Pchar, characterFromID("Rys Bloom"), 0);
			LAi_SetOfficerType(characterFromID("Rys Bloom"));
			characters[getCharacterIndex("Rys bloom")].location = "none";
		break;
		
		case "come_to_library":
			bMainMenuLaunchAfterVideo = true;
			PostVideoAndQuest("sunrise",1,"come_to_library_2");
			WaitDate("", 0,0,1,0,0);
		break;
		
		case "come_to_library_2":
			PostEvent("DoInfoShower",100,"s","");
			pchar.quest.main_line = "after_library";
			pchar.quest.to_oxbay_mine_2.win_condition.l1 = "location";
			pchar.quest.to_oxbay_mine_2.win_condition.l1.location = "Oxbay_canyon";
			pchar.quest.to_oxbay_mine_2.win_condition = "to_oxbay_mine_complete";
			pchar.quest.ferro_to_conceicao.over = "yes";
			if (CheckCharacterItem(Pchar, COMPRAMAT_TO_DOMIGUES))
			{
				TakeItemFromCharacter(pchar, COMPRAMAT_TO_DOMIGUES);
			}
			AddQuestRecord("search_danielle", "9");
		break;
		
		case "edgar_go_on_the_port":
			LAi_SetCitizenType(characterFromID("edgar attwood"));
			LAi_group_MoveCharacter(characterFromID("edgar attwood"), "ENGLAND_CITIZENS");
		break;
		
		case "Wifred_give_to_us_ship":
			characters[GetCharacterIndex("Wilfred Bythesea")].quest.kill_Ogarrio = "wait";
			pchar.location.from_sea = "Douwesen_shore_01";
			pchar.ship.type = SHIP_BRIG_HOLLAND;
			pchar.ship.name = "Lucky";
			SetCrewQuantity(pchar, 200);
			AddCharacterGoods(pchar, GOOD_BALLS, 600);
			AddCharacterGoods(pchar, GOOD_GRAPES, 300);
			AddCharacterGoods(pchar, GOOD_KNIPPELS, 470);
			AddCharacterGoods(pchar, GOOD_BOMBS, 300);
			//pchar.quest.main_line = "blaze_search_danielle_again";
			pchar.quest.kill_Ogario.win_condition.l1 = "NPC_death";
			pchar.quest.kill_Ogario.win_condition.l1.character = "Sidonio Ogarrio";
			pchar.quest.kill_Ogario.win_condition = "kill_Ogario_complete";

			Locations[FindLocation("Sidonio Ogarrio House")].reload.l1.name = "reload1";
			Locations[FindLocation("Sidonio Ogarrio House")].reload.l1.go = "Sidonio Ogarrio House";
			Locations[FindLocation("Sidonio Ogarrio House")].reload.l1.emerge = "reload1";
			Locations[FindLocation("Sidonio Ogarrio House")].reload.l1.autoreload = "0";
			AddQuestRecord("Where_are_i", "7");
			CloseQuestHeader("Where_are_i");
			SetQuestHeader("Kill_Ogario");
			AddQuestRecord("Kill_Ogario", "1");
			bQuestDisableMapEnter = false;
			LAi_SetStayType(characterFromID("Wilfred Bythesea"));
		break;
		
		case "God_hit_us":
			GetCharacterPos(GetMainCharacter(), &locx, &locy, &locz);
			CreateParticleSystemX("blast", locx, locy, locz, locx, locy, locz,0);
			LAi_ApplyCharacterDamage(pchar, 20);
		break;
		
		case "Ewan_sunk_Boon":
			LAi_SetActorType(characterFromID("Amiel Berangere"));
			LAi_ActorGoToLocation(characterFromID("Amiel Berangere"), "reload", "reload1", "none", "", "", "", 10.0);
					
			AddPartyExp(pchar, 4500);
			SetCharacterShipLocation(characterFromID("Virgile boon"), "none");
			AddQuestrecord("Story_1stTaskReceived", "10");
			
			pchar.quest.Convoy_Virgile_Boon.over = "yes";
			pchar.quest.Convoy_Virgile_Boon2.over = "yes";
			Pchar.quest.Story_Convoy_Virgile_Boon_1.over = "yes";
			Pchar.quest.Story_Convoy_Virgile_Boon_2.over = "yes";
			Pchar.quest.Story_Convoy_Virgile_Boon_3.over = "yes";
			Pchar.quest.Story_Convoy_Virgile_Boon_4.over = "yes";
			Pchar.quest.Story_Convoy_Virgile_Boon_5.over = "yes";
			Pchar.quest.Story_Convoy_Virgile_Boon_6.over = "yes";
			Pchar.quest.Story_Convoy_Virgile_Boon_7.over = "yes";
			Pchar.quest.Story_Convoy_Virgile_Boon_8.over = "yes";
			Pchar.quest.Story_Blaze_and_Boon_leaving.over = "yes";

			bQuestDisableMapEnter = false;
			Island_SetReloadEnableGlobal(PChar.location, true);
			AddQuestRecord("Story_1stTaskReceived", "12");
			ChangeCharacterAddress(characterFromID("Faust Gasquet"), "none", "");
			ChangeCharacterAddress(characterFromID("Virgile Boon"), "none", "");
			Pchar.quest.Story_1stTaskComplete = "Complete";
			pchar.quest.story_askaboutberangere.over = "yes";
		break;
		
		case "mendes_away_forewer":
			LAi_SetActorType(characterFromID("Vigila Mendes"));
			LAi_ActorGoToLocation(characterFromID("Vigila Mendes"), "reload", "locator2", "none", "", "", "", 3.0);
			//ZAID MURRO - закрываем возможность проходить этот квест
			ChangeCharacterAddress(characterFromID("Zaid Murro"), "none", "");
		break;
		
		case "hire_baldewyn":
			LAi_Fade("", "hire_baldewyn_2");
		break;
		
		case "hire_baldewyn_2":
			ChangeCharacterAddress(characterFromID("Baldewyn Coffier"), "none", "");
		break;
		
		case "baldewyn_wait_month":
			characters[GetCharacterIndex("Baldewyn Coffier")].quest.hire = "wait_month";
			PChar.quest.baldewyn_wait_month_timer.win_condition.l1 = "Timer";
			PChar.quest.baldewyn_wait_month_timer.win_condition.l1.date.day = GetAddingDataDay(0, 1, 0);
			PChar.quest.baldewyn_wait_month_timer.win_condition.l1.date.month = GetAddingDataMonth(0, 1, 0);
			PChar.quest.baldewyn_wait_month_timer.win_condition.l1.date.year = GetAddingDataYear(0, 1, 0);
			PChar.quest.baldewyn_wait_month_timer.win_condition = "baldewyn_wait_month_timer_complete";
		break;
		
		case "baldewyn_wait_month_timer_complete":
			if (characters[GetCharacterIndex("Baldewyn Coffier")].quest.hire == "0")
			{
				characters[GetCharacterIndex("Baldewyn Coffier")].quest.hire = "money_3";
			}
			else
			{
				characters[GetCharacterIndex("Baldewyn Coffier")].quest.hire =  "money_2";
			}
		break;
		case "leborio_hire_denied":
			LAi_Fade("", "");
			ChangeCharacterAddressGroup(characterFromID("Leborio Drago"), "Falaise_de_fleur_tavern", "sit", "sit5");
			LAi_SetSitType(characterFromID("leborio Drago"));
		break;
	}
}
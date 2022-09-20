object	Sail, Rope, Flag, Vant;

#define MIN_ENEMY_DISTANCE_TO_DISABLE_MAP_ENTER				400.0
#define MIN_ENEMY_DISTANCE_TO_DISABLE_ENTER_2_LOCATION		400.0

bool	bAbordageShipCanBe = false;
int		iAbordageShipEnemyCharacter;

bool	bNoDamage2Us = false;
bool	bCanEnterToLand = false;
aref	arIslandReload;
string	sIslandLocator;
string	sIslandID;
int		iShipPriority = 31;

int		iNumShips = 0;
int		Ships[32];

#define SHIP_DETONATE_SMALL		"ShipDetonateSmall"

#event_handler("Ship_StartLoad", "Ship_StartLoad");
#event_handler("Ship_EndLoad", "Ship_EndLoad");

void CreateRiggingEnvironment()
{
	CreateEntity(&Sail, "Sail");
	LayerAddObject(sCurrentSeaExecute, &Sail, iShipPriority + 1);
	LayerAddObject(sCurrentSeaRealize, &Sail, iShipPriority + 1);
	LayerAddObject(SAILS_TRACE, &Sail, 10);
	LayerAddObject(SEA_REFLECTION, &Sail, 3);
	Sail.MinSpeed = 0.05;

	CreateEntity(&Rope, "Rope");
	LayerAddObject(sCurrentSeaExecute, &Rope, iShipPriority + 2);
	LayerAddObject(sCurrentSeaRealize, &Rope, iShipPriority + 2);

	CreateEntity(&Flag, "Flag");
	LayerAddObject(sCurrentSeaExecute, &Flag, iShipPriority + 3);
	LayerAddObject(sCurrentSeaRealize, &Flag, iShipPriority + 3);
	LayerAddObject(SEA_REFLECTION, &Flag, 3);

	CreateEntity(&Vant, "Vant");
	LayerAddObject(sCurrentSeaExecute, &Vant, iShipPriority + 4);
	LayerAddObject(sCurrentSeaRealize, &Vant, iShipPriority + 4);

	iNumShips = 0;
}

void DeleteRiggingEnvironment()
{
	DeleteClass(&Sail);
	DeleteClass(&Rope);
	DeleteClass(&Flag);
	DeleteClass(&Vant);
}

void DeleteShipEnvironment()
{
	DeleteRiggingEnvironment();

	DelEventHandler(SHIP_CHANGE_CHARGE, "Ship_ChangeChargeEvent");
	DelEventHandler(SHIP_HULL_HIT, "Ship_HullHitEvent");
	DelEventHandler(SHIP_CHECK_RELOAD_ENABLE, "Ship_CheckMainCharacter");
	DelEventHandler(SHIP_DETONATE_SMALL, "Ship_DetonateSmall");
	DelEventHandler(SHIP_BRANDER_DETONATE, "Ship_BranderDetonate");
	DelEventHandler(SHIP_FIRE_DAMAGE, "Ship_FireDamage");
	DelEventHandler(SHIP_TO_STRAND_NEXT, "Ship_OnStrandNext");
	DelEventHandler(SHIP_ACTIVATE_FIRE_PLACE, "Ship_ActivateFirePlace");
	DelEventHandler(SHIP_UPDATE_PARAMETERS, "Ship_UpdateParameters");
	DelEventHandler(WHR_LIGHTNING, "Ship_Lightning");
	DelEventHandler("eSwitchPerks", "Ship_UpdatePerks");
	DelEventHandler("TornadoDamage", "Ship_TornadoDamage");

	// scan characters for delete snd id's
}

void CreateShipEnvironment()
{
	bAbordageFortCanBe = false;
	bAbordageShipCanBe = false;
	bCanEnterToLand = false;
	sIslandLocator = "";
	sIslandID = "";

	CreateRiggingEnvironment();

	SetEventHandler(SEA_GET_LAYERS, "SeaAI_GetLayers", 0);

	SetEventHandler(SHIP_NOT_ENOUGH_BALLS, "Ship_NotEnoughBalls", 0);
	SetEventHandler(SHIP_GET_CURRENT_BALLS_NUM, "Ship_GetCurrentBallsNum", 0);
	SetEventHandler(SHIP_SHIP2ISLAND_COLLISION, "Ship_Ship2IslandCollision", 0);
	SetEventHandler(SHIP_SHIP2SHIP_COLLISION, "Ship_Ship2ShipCollision", 0);
	SetEventHandler(SHIP_SAIL_DAMAGE, "Ship_SailDamage", 0);
	SetEventHandler(SHIP_FIRE_DAMAGE, "Ship_FireDamage", 0);
	SetEventHandler(SHIP_CHECK_SITUATION, "Ship_CheckSituation", 0);
	SetEventHandler(SHIP_TO_STRAND, "Ship_OnStrand", 0);
	SetEventHandler(SHIP_TO_STRAND_NEXT, "Ship_OnStrandNext", 0);
	SetEventHandler(SHIP_DEAD, "Ship_OnDead", 0);
	SetEventHandler(SHIP_UPDATE_PARAMETERS, "Ship_UpdateParameters", 0);
	SetEventHandler(SHIP_CREATE, "Ship_OnCreate", 0);
	SetEventHandler(SHIP_CHANGE_CHARGE, "Ship_ChangeChargeEvent", 0);
	SetEventHandler(SHIP_HULL_HIT, "Ship_HullHitEvent", 0);
	SetEventHandler(SHIP_CHECK_RELOAD_ENABLE, "Ship_CheckMainCharacter", 0);
	SetEventHandler(SHIP_FIRE_ACTION, "Ship_FireAction", 0);
	SetEventHandler(SHIP_GET_BORT_FIRE_DELTA, "Ship_GetBortFireDelta", 0);
	SetEventHandler(SHIP_DETONATE_SMALL, "Ship_DetonateSmall", 0);
	SetEventHandler(SHIP_ACTIVATE_FIRE_PLACE, "Ship_ActivateFirePlace", 0);
	SetEventHandler(WHR_LIGHTNING, "Ship_Lightning", 0);
	SetEventHandler("TornadoDamage", "Ship_TornadoDamage", 0);

	SetEventHandler(SHIP_BRANDER_DETONATE, "Ship_BranderDetonate", 0);

	SetEventHandler(SHIP_MAST_DAMAGE, "Ship_MastDamage", 0);

	SetEventHandler("eSwitchPerks", "Ship_UpdatePerks", 0);
}

float Ship_GetBortFireDelta()
{
	aref aCharacter = GetEventData();
	float x = GetEventData();
	float y = GetEventData();
	float z = GetEventData();
	float fDistance = GetDistance2D(x, z, stf(aCharacter.Ship.Pos.x), stf(aCharacter.Ship.Pos.z));

	float fAccuracy = 1.0 - stf(aCharacter.TmpSkill.Accuracy);

	float fRadius = fAccuracy * Bring2Range(0.0, 140.0, 0.0, 800.0, fDistance);

	return fRadius;
}

string Ship_GetGroupID(ref rCharacter)
{
	return rCharacter.SeaAI.Group.Name;
}

void Ship_FireAction()
{
	aref rCharacter = GetEventData();				// we attack this character
	aref rMainGroupCharacter = GetEventData();		// commander character for rCharacter
	int iRelation = GetEventData();

	ref rMainCharacter = GetMainCharacter();
	// if companion - decrease reputation
	if (IsCompanion(rCharacter))
	{
		ChangeCharacterReputation(GetMainCharacter(), -1);

		if (CheckAttribute(rCharacter, "CompanionEnemyEnable") && sti(rCharacter.CompanionEnemyEnable))
		{
			SeaAI_SetCompanionEnemy(rCharacter);
			// disconnect companion from our group and set it enemy to us
		}

		return;
	}

	if (iRelation != RELATION_ENEMY)
	{
		if (bIslandLoaded) { SetNationRelation2MainCharacter(sti(rMainGroupCharacter.nation), RELATION_ENEMY); }
		SetCharacterRelationBoth(GetMainCharacterIndex(), sti(rMainGroupCharacter.index), RELATION_ENEMY);
	}

	UpdateRelations();

	RefreshBattleInterface();

	// if fort - return
	if (sti(rCharacter.Ship.Type) == SHIP_FORT) { return; }

	string sGroupID = Ship_GetGroupID(rMainGroupCharacter);
	string sGroupType = Group_GetType(sGroupID);
	ref rGroup = Group_GetGroupByID(sGroupID);

	Group_SetTaskAttack(PLAYER_GROUP, sGroupID);
}

float Ship_MastDamage()
{
	int iDamageType = GetEventData();
	int iMastNum = GetEventData();
	float x = GetEventData();
	float y = GetEventData();
	float z = GetEventData();
	float fDamage = GetEventData();
	aref rCharacter = GetEventData();

	switch (iDamageType)
	{
		case SHIP_MAST_TOUCH_ISLAND:
			fDamage = fDamage + 0.15;
		break;
		case SHIP_MAST_TOUCH_SHIP:
			//aref rCollideCharacter = GetEventData();

			fDamage = fDamage + 0.1;
		break;
	}

	fDamage = Clampf(fDamage);

	// if mast fall - play sound
	if (fDamage >= 1.0)
	{
		Play3DSound("mast_fall", x, y, z);
	}

	return fDamage;
}

void Ship_SetSailState(int iCharacterIndex, float fSailState)
{
	SendMessage(&AISea, "laf", AI_MESSAGE_SHIP_SET_SAIL_STATE, &Characters[iCharacterIndex], fSailState);
}

void Ship_SetTaskNone(int iTaskPriority, int iCharacterIndex)
{
	ref rCharacter = GetCharacter(iCharacterIndex);
	rCharacter.SeaAI.Task = AITASK_NONE;
}

void Ship_SetTaskBrander(int iTaskPriority, int iCharacterIndex, int iCharacterIndexBranderTo)
{
	ref rCharacter = GetCharacter(iCharacterIndex);
	rCharacter.SeaAI.Task = AITASK_BRANDER;
	rCharacter.SeaAI.Task.Target = iCharacterIndexBranderTo;
	SendMessage(&AISea, "lllaa", AI_MESSAGE_SHIP_SET_TASK, AITASK_BRANDER, iTaskPriority, &Characters[iCharacterIndex], &Characters[iCharacterIndexBranderTo]);
}

void Ship_SetTaskMove(int iTaskPriority, int iCharacterIndex, float x, float z)
{
	ref rCharacter = GetCharacter(iCharacterIndex);
	rCharacter.SeaAI.Task = AITASK_MOVE;
	rCharacter.SeaAI.Task.Target = "";
	rCharacter.SeaAI.Task.Pos.x = x;
	rCharacter.SeaAI.Task.Pos.z = z;
	SendMessage(&AISea, "lllaff", AI_MESSAGE_SHIP_SET_TASK, AITASK_MOVE, iTaskPriority, &Characters[iCharacterIndex], x, z);
}

void Ship_SetTaskRunaway(int iTaskPriority, int iCharacterIndex)
{
	ref rCharacter = GetCharacter(iCharacterIndex);
	rCharacter.SeaAI.Task = AITASK_RUNAWAY;
	rCharacter.SeaAI.Task.Target = "";
	SendMessage(&AISea, "llla", AI_MESSAGE_SHIP_SET_TASK, AITASK_RUNAWAY, iTaskPriority, &Characters[iCharacterIndex]);
}

void Ship_SetTaskAttack(int iTaskPriority, int iCharacterIndex, int iCharacterIndexVictim)
{
	ref rCharacter = GetCharacter(iCharacterIndex);
	rCharacter.SeaAI.Task = AITASK_ATTACK;
	rCharacter.SeaAI.Task.Target = iCharacterIndexVictim;
	SendMessage(&AISea, "lllaa", AI_MESSAGE_SHIP_SET_TASK, AITASK_ATTACK, iTaskPriority, &Characters[iCharacterIndex], &Characters[iCharacterIndexVictim]);
}

void Ship_SetTaskSailTo(int iTaskPriority, int iCharacterIndex, int iCharacterIndexSailTo)
{
	ref rCharacter = GetCharacter(iCharacterIndex);
	rCharacter.SeaAI.Task = AITASK_MOVE;
	rCharacter.SeaAI.Task.Target = iCharacterIndexSailTo;
	SendMessage(&AISea, "lllaa", AI_MESSAGE_SHIP_SET_TASK, AITASK_MOVE, iTaskPriority, &Characters[iCharacterIndex], &Characters[iCharacterIndexSailTo]);
}

void Ship_SetTaskDrift(int iTaskPriority, int iCharacterIndex)
{
	ref rCharacter = GetCharacter(iCharacterIndex);
	rCharacter.SeaAI.Task = AITASK_DRIFT;
	rCharacter.SeaAI.Task.Target = "";
	SendMessage(&AISea, "llla", AI_MESSAGE_SHIP_SET_TASK, AITASK_DRIFT, iTaskPriority, &Characters[iCharacterIndex]);
}

void Ship_SetTaskDefendGroup(int iTaskPriority, int iCharacterIndex, string sDefendGroup)
{
	SendMessage(&AISea, "lllas", AI_MESSAGE_SHIP_SET_TASK, AITASK_DEFEND_GROUP, iTaskPriority, &Characters[iCharacterIndex], sDefendGroup);
}

void Ship_SetTaskDefend(int iTaskPriority, int iCharacterIndex, int iCharacterIndex2Defend)
{
	ref rCharacter = GetCharacter(iCharacterIndex);
	rCharacter.SeaAI.Task = AITASK_DEFEND;
	rCharacter.SeaAI.Task.Target = iCharacterIndex2Defend;
	SendMessage(&AISea, "lllaa", AI_MESSAGE_SHIP_SET_TASK, AITASK_DEFEND, iTaskPriority, &Characters[iCharacterIndex], &Characters[iCharacterIndex2Defend]);
}

void Ship_DoFire()
{
	int bCameraOutside = SeaCameras_isCameraOutside();
	SendMessage(&AISea, "lal", AI_MESSAGE_CANNON_FIRE, &Characters[GetMainCharacterIndex()], bCameraOutside);
}

void Ship_Add2Sea(int iCharacterIndex, bool bFromCoast, string sFantomType)
{
	ref		rCharacter = GetCharacter(iCharacterIndex);
	aref	arCharacter; makearef(arCharacter, Characters[sti(rCharacter.index)]);

	int iShipType = sti(rCharacter.Ship.Type);
	if (iShipType >= SHIP_TYPES_QUANTITY_WITH_FORT)
	{
		Trace("Character.id = " + rCharacter.id + ", have invalid ship type = " + iShipType + ", and try load to sea");
		return;
	}

	if (iCharacterIndex >= FANTOM_CHARACTERS)
	{
		SetBaseShipData(rCharacter);
		Ship_SetFantomData(rCharacter);

		Fantom_SetBalls(rCharacter, sFantomType);
		Fantom_SetGoods(rCharacter, sFantomType);
	}

	rCharacter.TmpPerks.Turn = false;

	CharacterUpdateShipFromBaseShip(iCharacterIndex);

	rCharacter.Ship.Ang.y = 0.0;

	Ship_ClearImpulseStrength(rCharacter);

	rCharacter.Ship.LastBallCharacter = -1;
	rCharacter.Ship.Speed.z = 0.0;
	rCharacter.Ship.Strand = false;
	rCharacter.Ship.Strand.SndID = SOUND_INVALID_ID;
	rCharacter.Ship.Stopped = false;
	rCharacter.Ship.POS.Mode = SHIP_SAIL;
	if (bFromCoast == false) { rCharacter.Ship.Speed.z = 1.0; }
	Event("eSwitchPerks", "l", iCharacterIndex);							// Perks
	Event(SHIP_UPDATE_PARAMETERS, "lf", iCharacterIndex, stf(rCharacter.Ship.Speed.z));		// Parameters
	CreateEntity(&Characters[iCharacterIndex], "Ship");
	SendMessage(&AISea, "liaa", AI_MESSAGE_ADD_SHIP, &Characters[iCharacterIndex], &Characters[iCharacterIndex], &ShipsTypes[iShipType]);

	ReloadProgressUpdate();

	Ships[iNumShips] = iCharacterIndex;
	iNumShips++;
}

void Ship_ChangeChargeEvent()
{
	string	sBallName;

	ref rCharacter = GetCharacter(GetEventData());

	SendMessage(&AISea, "la", AI_MESSAGE_CANNON_RELOAD, rCharacter);
	sBallName = GetEventData();
	rCharacter.Ship.Cannons.Charge = sBallName;
	Cannon_RecalculateParameters(sti(rCharacter.index));
}

void Ship_ChangeCharge(ref rCharacter, int iNewChargeType)
{
	SendMessage(&AISea, "la", AI_MESSAGE_CANNON_RELOAD, &rCharacter); // must be first line in this function

	ref rGood = GetGoodByType(iNewChargeType);
	rCharacter.Ship.Cannons.Charge = rGood.name;
	rCharacter.Ship.Cannons.Charge.Type = iNewChargeType;

	Cannon_RecalculateParameters(sti(rCharacter.index));
}

void Ship_OnCreate()
{
	ref rCharacter = GetCharacter(GetEventData());
	//Trace("Ship_OnCreate rCharacter = " + rCharacter.id);

	rCharacter.Ship.Speed.z = 0.0;
	rCharacter.Ship.Speed.y = 0.0;
	rCharacter.Ship.Speed.x = 0.0;
}

void Ship_CheckSituation()
{
	ref		rShip;
	aref	rSituation;

	aref	rCharacter = GetEventData();
	aref	rShipObject = GetEventData();

	if (sti(rCharacter.index) == GetMainCharacterIndex()) { return; }

	rShip = GetShipByType(sti(rCharacter.Ship.Type));
	makearef(rSituation, rCharacter.SeaAI.Update.Situation);

	float	fMinEnemyDistance = stf(rSituation.MinEnemyDistance);

	// check for enought quantity of balls
	int iShipCannonsNum = sti(rShip.CannonsQuantity);
	int iCurrentBallType = sti(rCharacter.Ship.Cannons.Charge.Type);
	bool bBalls, bKnippels, bBombs, bGrapes;
	bBalls = true; bKnippels = true; bBombs = true; bGrapes = true;
	if (GetCargoGoods(rCharacter,GOOD_BALLS) < iShipCannonsNum) { bBalls = false; }
	if (GetCargoGoods(rCharacter,GOOD_BOMBS) < iShipCannonsNum) { bBombs = false; }
	if (GetCargoGoods(rCharacter,GOOD_KNIPPELS) < iShipCannonsNum) { bKnippels = false; }
	if (GetCargoGoods(rCharacter,GOOD_GRAPES) < iShipCannonsNum) { bGrapes = false; }

	int iNewBallType = iCurrentBallType;
	bool bFindNewBallType = false;
	switch (iCurrentBallType)
	{
		case GOOD_BALLS:
			if (bBalls) { break; }
			bFindNewBallType = true;
		break;
		case GOOD_BOMBS:
			if (bBombs) { break; }
			bFindNewBallType = true;
		break;
		case GOOD_GRAPES:
			if (bGrapes) { break; }
			bFindNewBallType = true;
		break;
		case GOOD_KNIPPELS:
			if (bKnippels) { break; }
			bFindNewBallType = true;
		break;
	}

	if (bFindNewBallType)
	{
		iNewBallType = Ship_FindOtherBallType(rCharacter, fMinEnemyDistance, bBalls, bBombs, bGrapes, bKnippels);
	}

	if (iNewBallType < 0)
	{
		if (!IsCompanion(rCharacter))
		{
			// maybe we can abordage???
			Ship_SetTaskRunaway(SECONDARY_TASK,sti(rCharacter.index));
		}
		return;
	}

	if (iNewBallType >= 0 && iNewBallType != iCurrentBallType)
	{
		Ship_ChangeCharge(rCharacter, iNewBallType);
	}

	// check some tasks
	if (CheckAttribute(rCharacter, "SeaAI.Task"))
	{
		switch (sti(rCharacter.SeaAI.Task))
		{
			case AITASK_BRANDER:
				ref rCharacter2Brander = GetCharacter(sti(rCharacter.SeaAI.Task.Target));
				ref rBaseShip = GetShipByType(sti(rCharacter2Brander.Ship.Type));
				float fBranderDistance = 30.0 + (7.0 - stf(rBaseShip.Class)) * 40.0;
				float fDistance = Ship_GetDistance2D(rCharacter, rCharacter2Brander);
				if (fBranderDistance > fDistance)
				{
					// fire ship
					int iNumFirePlaces = 0;
					SendMessage(rShipObject, "le", MSG_SHIP_GET_NUM_FIRE_PLACES, &iNumFirePlaces);
					for (int i=0; i<iNumFirePlaces / 3; i++)
					{
						PostEvent(SHIP_ACTIVATE_FIRE_PLACE, rand(10000), "ialsf", rShipObject, rCharacter, i, "ship_onfire", 30.0);
					}
					PostEvent(SHIP_BRANDER_DETONATE, 10000, "l", sti(rCharacter.index));

					Ship_SetTaskNone(SECONDARY_TASK, sti(rCharacter.index));
				}
				//Trace("test1 rCharacter2Brander = " + rCharacter2Brander.index);
			break;
		}
	}
}

void Ship_ActivateFirePlace()
{
	aref	arShipObject = GetEventData();
	aref	arCharacter = GetEventData();
	int		iFirePlaceIndex = GetEventData();
	string	sSoundName = GetEventData();
	float	fFireTime = GetEventData();

	aref	arPos; makearef(arPos, arCharacter.Ship.Pos);

	int iSoundID = Play3DSoundComplex(sSoundName, stf(arPos.x), 0.0, stf(arPos.z), true, false);
	SendMessage(arShipObject, "llsslf", MSG_SHIP_ACTIVATE_FIRE_PLACE, iFirePlaceIndex, "ship_smoke", "ship_fire", iSoundID, fFireTime);
}

void Ship_BranderDetonate()
{
	ref		rCharacter = GetCharacter(GetEventData());

	ref		rBranderBaseShip = GetShipByType(sti(rCharacter.Ship.Type));
	float	fBranderDistance = 2.5 * (30.0 + (7.0 - stf(rBranderBaseShip.Class)) * 40.0);
	float	fMaxDamage = 1000.0 + (7.0 - stf(rBranderBaseShip.Class)) * 1000.0;

	aref	arShipObjects[64];
	int		iNumShips = 1;

	if (!FindEntity(&arShipObjects[0], "ship")) { return; }// can't be
	while (FindEntityNext(&arShipObjects[iNumShips])) { iNumShips++; }

	// enumerate ship and do damage
	for (int i=0; i<iNumShips; i++)
	{
		int iCharacterIndex = -1;
		SendMessage(arShipObjects[i], "le", MSG_SHIP_GET_CHARACTER_INDEX, &iCharacterIndex);
		if (iCharacterIndex == sti(rCharacter.index)) { continue; }
		ref rOtherCharacter = GetCharacter(iCharacterIndex);
		ref	rOtherBaseShip = GetShipByType(sti(rOtherCharacter.Ship.Type));
		float fDistance = Ship_GetDistance2D(rCharacter, rOtherCharacter);
		if (fDistance > fBranderDistance) { continue; }
		float fDamageMultiply = Bring2Range(1.0, 0.0, 10.0, fBranderDistance, fDistance);
		Ship_ApplyHullHitpoints(rOtherCharacter, fMaxDamage * fDamageMultiply, KILL_BY_SPY, sti(rBranderBaseShip.index));

		// fire random fire places
		int iNumFirePlaces = 0;
		SendMessage(&arShipObjects[i], "le", MSG_SHIP_GET_NUM_FIRE_PLACES, &iNumFirePlaces);

		// add move impulse to ship
		float x = stf(rOtherCharacter.Ship.Pos.x) - stf(rCharacter.Ship.Pos.x);
		float z = stf(rOtherCharacter.Ship.Pos.z) - stf(rCharacter.Ship.Pos.z);
		float fLen = stf(rOtherBaseShip.Class) * fDamageMultiply * (1.0 / sqrt(x * x + z * z));
		SendMessage(&arShipObjects[i], "llffffff", MSG_SHIP_ADD_MOVE_IMPULSE, false, x * fLen, 0.0, z * fLen, 0.0, 0.0, 0.0);
	}

	Ship_Detonate(rCharacter, true, true);
}

float Ship_GetDistance2D(ref rCharacter1, ref rCharacter2)
{
	return GetDistance2D(stf(rCharacter1.Ship.Pos.x), stf(rCharacter1.Ship.Pos.z), stf(rCharacter2.Ship.Pos.x), stf(rCharacter2.Ship.Pos.z));
}

int Ship_FindOtherBallType(ref rCharacter, float fMinEnemyDistance, bool bBalls, bool bBombs, bool bGrapes, bool bKnippels)
{
	if (bBombs) return GOOD_BOMBS;
	if (bBalls) return GOOD_BALLS;
	if (bGrapes) return GOOD_GRAPES;
	if (bKnippels) return GOOD_KNIPPELS;

	return -1;
}

// event: indicate that ball is not enough for fire for main character
void Ship_NotEnoughBalls()
{
	bNotEnoughBalls = GetEventData();
}

int Ship_GetCurrentBallsNum()
{
	aref aCharacter = GetEventData();
	return GetCargoGoods(aCharacter,sti(aCharacter.Ship.Cannons.Charge.Type));
}

void Ship_SailDamage()
{
	float x, y, z;
	int iCharacterIndex = GetEventData();
	x = GetEventData();
	y = GetEventData();
	z = GetEventData();
	Play3DSound("sail_damage", x, y, z);
}

void Ship_Ship2IslandCollision()
{
	float	fPower, fSlide, x, y, z;
	int		iOurCharacterIndex, iEnemyCharacterIndex, iTouchPoint;

	iOurCharacterIndex = GetEventData();
	iEnemyCharacterIndex = GetEventData();
	fPower = abs(GetEventData());
	fSlide = abs(GetEventData());
	iTouchPoint = GetEventData();
	x = GetEventData();
	y = GetEventData();
	z = GetEventData();

	ref rOurCharacter = GetCharacter(iOurCharacterIndex);

	float fHP = (1.0 - fSlide) * fPower * 3.0;
	//Trace("Ship->Island touch: fpower = " + fPower + ", fHP = " + fHP + ", fSlide = " + fSlide);
	Ship_ApplyHullHitpoints(rOurCharacter, fHP, KILL_BY_ISLAND, -1);

	if (fPower > 1.0) { Play3DSound("coll_ship2rock", x, y, z); }
}

float Ship_GetAttackHP(int iCharacterIndex, float fDistance)
{
	float fAttackHP = 0.0;
	if (bSeaActive)
	{
		SendMessage(&AISea, "lafe", AI_MESSAGE_SHIP_GET_ATTACK_HP, &Characters[iCharacterIndex], fDistance, &fAttackHP);
	}
	return fAttackHP;
}

float Ship_GetHP(ref rCharacter) { return stf(rCharacter.Ship.HP); }

void Ship_Ship2ShipCollision()
{
	int		iOurCharacterIndex, iEnemyCharacterIndex, iTouchPoint;
	float	fPower, fSlide, x, y, z;

	iOurCharacterIndex = GetEventData();
	iEnemyCharacterIndex = GetEventData();
	fPower = abs(GetEventData());
	fSlide = abs(GetEventData());
	iTouchPoint = GetEventData();
	x = GetEventData();
	y = GetEventData();
	z = GetEventData();

	ref rOurCharacter = GetCharacter(iOurCharacterIndex);

	float fHP = (1.0 - fSlide) * fPower * 20.0;
	//Trace("Ship->Ship touch: idx = " + iOurCharacterIndex + ", fpower = " + fPower + ", fHP = " + fHP + ", fSlide = " + fSlide);
	Ship_ApplyHullHitpoints(rOurCharacter, fHP, KILL_BY_TOUCH, iEnemyCharacterIndex);
	if (fPower>1.0) { Play3DSound("coll_ship2ship", x, y, z); }
}

void Ship_ApplyCrewHitpoints(ref rOurCharacter, float fCrewHP)
{
	ref rBaseShip = GetShipByType(GetCharacterShipType(rOurCharacter));
	float fMultiply = Bring2Range(1.0, 0.2, 0.0, 1.0, stf(rOurCharacter.TmpSkill.Defence));
	float fNewCrewQuantity = stf(rOurCharacter.Ship.Crew.Quantity) - fCrewHP * fMultiply;
	float f5Percent = stf(rBaseShip.MinCrew) * 0.05;
	if (fNewCrewQuantity < f5Percent) { fNewCrewQuantity = f5Percent; }
	if (fNewCrewQuantity < 1.0) { fNewCrewQuantity = 1.0; }
	rOurCharacter.Ship.Crew.Quantity = fNewCrewQuantity;
}

void Ship_ApplyHullHitpoints(ref rOurCharacter, float fHP, int iKillStatus, int iKillerCharacterIndex)
{
	float fCurHP;
	float fMinus = 0.0;
	float fPlus = 0.0;

	if (bSeaReloadStarted) { return; }
	if (fHP <= 0.0) { return; }

	if (bNoDamage2Us)
	{
		ref rMainCharacter = GetMainCharacter();
		if (sti(rOurCharacter.index) == GetMainCharacterIndex()) { return; }
		if (FindFellowTravellers(rMainCharacter, rOurCharacter) == FELLOWTRAVEL_COMPANION) { return; }
	}

	if (LAi_IsImmortal(rOurCharacter)) { return; }

	if (iKillerCharacterIndex >= 0)
	{
		if (sti(Characters[iKillerCharacterIndex].TmpPerks.HullDamageUp)) fPlus = 0.15;
		if (sti(Characters[iKillerCharacterIndex].TmpPerks.CannonProfessional)) fPlus = 0.3;
	}

	if (sti(rOurCharacter.TmpPerks.BasicBattleState))			fMinus = 0.15;
	if (sti(rOurCharacter.TmpPerks.AdvancedBattleState))		fMinus = 0.25;
	if (sti(rOurCharacter.TmpPerks.ShipDefenseProfessional))	fMinus = 0.40;

	if (LAi_IsDead(rOurCharacter)) { return; }
	fCurHP = stf(rOurCharacter.Ship.HP) - fHP * (1.0 + fPlus - fMinus);
	//Trace("idx = " + rOurCharacter.index + ", fCurHP = " + fCurHP);
	if (fCurHP <= 0.0)
	{
		fCurHP = 0.0;
		//Trace("Player dead = " + rOurCharacter.index + ", id = " + rOurCharacter.id);
		ShipDead(sti(rOurCharacter.index), iKillStatus, iKillerCharacterIndex);
	}

	rOurCharacter.Ship.HP = fCurHP;
}

void Ship_AddCharacterExp(ref rCharacter, int iExpQuantity)
{
	AddCharacterExp(rCharacter, iExpQuantity);

	if (sti(rCharacter.index) == GetMainCharacterIndex())
	{
		fSeaExp = fSeaExp + iExpQuantity;
	}
}

void ShipDead(int iDeadCharacterIndex, int iKillStatus, int iKillerCharacterIndex)
{
	ref rDead, rKillerCharacter, rMainCharacter, rBaseShip, rKillerBaseShip;

	rDead = GetCharacter(iDeadCharacterIndex);
	rBaseShip = GetShipByType(sti(rDead.Ship.Type));

	if (iKillerCharacterIndex != -1)
	{
		rKillerCharacter = GetCharacter(iKillerCharacterIndex);
		rKillerBaseShip = GetShipByType(sti(rKillerCharacter.Ship.Type));
	}

	rMainCharacter = GetMainCharacter();
	int iQuantity = GetCompanionQuantity(rMainCharacter);

	float fX = stf(rDead.Ship.Pos.x);
	float fY = stf(rDead.Ship.Pos.y);
	float fZ = stf(rDead.Ship.Pos.z);

	rDead.Ship.HP = 0;
	rDead.Killer.Status = iKillStatus;
	rDead.Killer.Index = iKillerCharacterIndex;

	LAi_SetCurHP(rDead, 0.0);
	//LAi_KillCharacter(rDead);

	bool bDeadCompanion = IsCompanion(rDead);

	int iExp = 0;
	if (iKillerCharacterIndex != -1) { iExp = 2 * MakeInt(stf(rBaseShip.HP) * stf(rKillerBaseShip.Class) / stf(rBaseShip.Class)); }

	bool bCompanion = false;
	if (iKillerCharacterIndex != -1) { bCompanion = IsCompanion(rKillerCharacter); }

	if (bCompanion && bDeadCompanion) { iExp = 0; }

	bool bRealKill = false;
	switch (iKillStatus)
	{
		case KILL_BY_TOUCH:
			if (iKillerCharacterIndex != -1) { bRealKill = true; }
		break;
		case KILL_BY_BALL:
			bRealKill = true;
		break;
		case KILL_BY_ABORDAGE:
			bRealKill = true;
		break;
	}

	// Ship sunk log
	if (iDeadCharacterIndex != GetMainCharacterIndex())
	{
		object oRes;
		string sSunkString;
		string sSunkShipType = XI_ConvertString(rBaseShip.Name);

		if (bCompanion && !bDeadCompanion && bRealKill)
		{
			sSunkString = LanguageConvertString(iSeaSectionLang, "Ship_sunk");
			string sExp = iExp / iQuantity;

			Event(PARSE_STRING, "aslsss", &oRes, sSunkString, 3, sSunkShipType, rDead.Ship.Name, sExp);
			Log_SetStringToLog(oRes.Str);
		}
		else
		{
			sSunkString = LanguageConvertString(iSeaSectionLang, "Ship_sunk_other");

			Event(PARSE_STRING, "aslss", &oRes, sSunkString, 2, sSunkShipType, rDead.Ship.Name);
			Log_SetStringToLog(oRes.Str);
		}
	}

	if (bRealKill && iKillerCharacterIndex != -1)
	{
		int iRelation = SeaAI_GetRelation(iDeadCharacterIndex, iKillerCharacterIndex);
		switch (iRelation)
		{
			case RELATION_FRIEND:
			break;
			case RELATION_NEUTRAL:
			break;
			case RELATION_ENEMY:
				if (bCompanion)
				{
					for (int i=0; i<COMPANION_MAX; i++)
					{
						int iIndex = GetCompanionIndex(rMainCharacter, i);
						if (iIndex >= 0)
						{
							AddCharacterExp(&Characters[i], iExp / iQuantity);
						}
					}
				}
				else
				{
					AddCharacterExp(rKillerCharacter, iExp);
				}
			break;
		}
	}

	if (rand(10) >= 6 && sti(rBaseShip.Class) <= 6)
	{
		bool bDetonate = false;
		switch (iKillStatus)
		{
			case KILL_BY_BALL:	bDetonate = true; break;
			case KILL_BY_SPY:	bDetonate = true; break;
		}
		if (bDetonate) { Ship_Detonate(rDead, true, false); }
	}

	// set attributes for sinking effect
	rDead.Ship.Sink = "";
	aref aSink; makearef(aSink, rDead.Ship.Sink);
	aSink.Speed.y = 0.35;	// speed of sink y
	aSink.Speed.x = 0.017 * (frnd() * 2.0 - 1.0);	// speed sink angle rotate around x
	aSink.Speed.z = 0.017 * (frnd() * 2.0 - 1.0);	// speed sink angle rotate around z

	if (iDeadCharacterIndex == GetMainCharacterIndex())
	{
		SeaCameras_SetDieCamera();
		FadeOutMusic(2000);
		PlayStereoOGG("music_ship_dead");
		PostEvent(GAME_OVER_EVENT, 15000);
	}

	Play3DSound("ship_sink", fX, fY, fZ);

	// Message to AI
		SendMessage(AISea, "la", AI_MESSAGE_CHARACTER_DEAD, rDead);

	// Event
		Event(SHIP_DEAD, "l", iDeadCharacterIndex);
}

void Ship_SailHitEvent()
{
}

void Ship_HullHitEvent()
{
	float	fHP;

	int		iBallType = sti(AIBalls.CurrentBallType);

	aref	rShipObject = GetEventData();

	int		iBallCharacterIndex = GetEventData();
	int		iOurCharacterIndex = GetEventData();

	ref		rBallCharacter = GetCharacter(iBallCharacterIndex);
	ref		rOurCharacter = GetCharacter(iOurCharacterIndex);

	rOurCharacter.Ship.LastBallCharacter = iBallCharacterIndex;

	int		iCompanion = GetCompanionNumber(rBallCharacter, iOurCharacterIndex);

	float	x = GetEventData();
	float	y = GetEventData();
	float	z = GetEventData();

	int		iFirePlaceIndex = GetEventData();
	float	fFirePlaceDistance = GetEventData();

	bool	bDead = LAi_IsDead(rOurCharacter);

	bool	bSeriousBoom = false;
	bool	bInflame = false;

	// Cannon damage multiply
	ref rCannon = GetCannonByType(sti(rBallCharacter.Ship.Cannons.Type));
	float fCannonDamageMultiply = stf(rCannon.DamageMultiply);

	if (sti(rBallCharacter.TmpPerks.CriticalShoot) && rand(19)==10) { bSeriousBoom = true; }		// +5%
	if (sti(rBallCharacter.TmpPerks.CannonProfessional) && rand(9)==4) { bSeriousBoom = true; }		// +10%

	ref rBall = GetGoodByType(iBallType);
	switch (iBallType)
	{
		case GOOD_BALLS:
			if (rand(35) == 17) { bSeriousBoom = true; }
			if (rand(30) == 15) { bInflame = true; }
			Play3DSound("ball2bort", x, y, z);
			CreateParticleSystem("blast", x, y, z, 0.0, 0.0, 0.0, 0);
		break;
		case GOOD_GRAPES:
			bSeriousBoom = false;
			Play3DSound("grapes2bort", x, y, z);
			CreateParticleSystem("blast", x, y, z, 0.0, 0.0, 0.0, 0);
		break;
		case GOOD_KNIPPELS:
			bSeriousBoom = false;
			Play3DSound("knippel2bort", x, y, z);
			CreateParticleSystem("blast", x, y, z, 0.0, 0.0, 0.0, 0);
		break;
		case GOOD_BOMBS:
			if (rand(20) == 10) { bSeriousBoom = true; }
			if (rand(2) == 1) { bInflame = true; }
			Play3DSound("bomb2bort", x, y, z);
			CreateParticleSystem("blast", x, y, z, 0.0, 0.0, 0.0, 0);
		break;
	}

	if (sti(rOurCharacter.TmpPerks.ShipDefenseProfessional)) { bSeriousBoom = false; }				// no seriouse boom

	if (!bDead)
	{
		float fCrewDamage = stf(rBall.DamageCrew) * fCannonDamageMultiply * AIShip_isPerksUse(rBallCharacter.TmpPerks.CrewDamageUp, 1.0, 1.15);

		if (bSeriousBoom)
		{
			fCrewDamage = fCrewDamage * 2.0;
			fHP = fCannonDamageMultiply * stf(rBall.DamageHull) * (4.0 + frnd() * 2.0);
			Ship_ApplyHullHitpoints(rOurCharacter, fHP, KILL_BY_BALL, iBallCharacterIndex);
			Ship_ApplyCrewHitpoints(rOurCharacter, fCrewDamage * 1.5);
			if (iCompanion == - 1) { Ship_AddCharacterExp(rBallCharacter, 150); }

			if (iBallCharacterIndex == GetMainCharacterIndex())
			{
				Log_SetStringToLog(LanguageConvertString(iSeaSectionLang, "Ship_critical"));
			}
		}
		else
		{
			fHP = fCannonDamageMultiply * stf(rBall.DamageHull);
			Ship_ApplyHullHitpoints(rOurCharacter, fHP, KILL_BY_BALL, iBallCharacterIndex);
			if (iCompanion == - 1) { Ship_AddCharacterExp(rBallCharacter, 20); }
		}

		Ship_ApplyCrewHitpoints(rOurCharacter, fCrewDamage);
	}

	if (bInflame == true && fFirePlaceDistance < 4.0 && iFirePlaceIndex >= 0)
	{
		int iRandStartTime = rand(1000);
		float fTotalFireTime = Ship_GetTotalFireTime(rOurCharacter);

		PostEvent(SHIP_ACTIVATE_FIRE_PLACE, iRandStartTime, "ialsf", rShipObject, rOurCharacter, iFirePlaceIndex, "ship_onfire", fTotalFireTime);
		PostEvent(SHIP_FIRE_DAMAGE, iRandStartTime, "lllf", iOurCharacterIndex, iBallCharacterIndex, iFirePlaceIndex, fTotalFireTime);
	}

	if (bSeriousBoom == true) { Ship_Serious_Boom(x, y, z); }
}

float Ship_GetTotalFireTime(ref rCharacter)
{
	int iRepairSkill = MakeInt(stf(rCharacter.TmpSkill.Repair) * 10.0);
	return MakeFloat(5 + 3 * (10 - iRepairSkill));
}

void Ship_FireDamage()
{
	int iOurCharacterIndex = GetEventData();
	int iBallCharacterIndex = GetEventData();

	int iFirePlaceIndex = GetEventData();
	float fTotalFireTime = GetEventData();

	ref rOurCharacter = GetCharacter(iOurCharacterIndex);
	ref rBallCharacter = GetCharacter(iBallCharacterIndex);

	int iSClass = GetCharacterShipClass(rOurCharacter);

	float fHP = (8 - iSClass) * (0.5 + frnd() * 0.5);

	int iTime = 1000 + rand(500);

	// if abordage or interface launched
	if (!bAbordageStarted && !sti(InterfaceStates.Launched))
	{
		Ship_ApplyHullHitpoints(rOurCharacter, fHP, KILL_BY_BALL, iBallCharacterIndex);

		fTotalFireTime = fTotalFireTime - MakeFloat(iTime) / 1000.0;
	}

	if (fTotalFireTime > 0.0)
	{
		PostEvent(SHIP_FIRE_DAMAGE, iTime, "lllf", iOurCharacterIndex, iBallCharacterIndex, iFirePlaceIndex, fTotalFireTime);
	}
}

void Ship_Serious_Boom(float x, float y, float z)
{
	CreateBlast(x,y,z);
	CreateParticleSystem("blast_inv", x, y, z, 0.0, 0.0, 0.0, 0);
	Play3DSound("ship_explosion", x, y, z);
}

void Ship_SetFantomData(ref rFantom)
{
	ref		rCannon, rBaseShip;

	rBaseShip = GetShipByType(sti(rFantom.Ship.Type));

	int iMinCrew = sti(rBaseShip.MinCrew);
	int iMaxCrew = sti(rBaseShip.MaxCrew);

	int iBaseHP = sti(rBaseShip.HP);
	int iCapacity = sti(rBaseShip.Capacity);

	rFantom.Ship.Crew.Quantity = iMinCrew + rand(iMaxCrew - iMinCrew - 1);
	rFantom.Ship.HP = iBaseHP;
	if (rand(3) == 2) { rFantom.Ship.HP = iBaseHP - rand(iBaseHP / 2)};

	if (CheckAttribute(rFantom, "Ship.Masts")) { DeleteAttribute(rFantom, "Ship.Masts"); }
	if (CheckAttribute(rFantom, "Ship.Blots")) { DeleteAttribute(rFantom, "Ship.Blots"); }
	if (CheckAttribute(rFantom, "Ship.Sails")) { DeleteAttribute(rFantom, "Ship.Sails"); }

}

void CharacterUpdateShipFromBaseShip(int iCharacterIndex)
{
	ref rCharacter, rCannon, rBaseShip;

	rCharacter = GetCharacter(iCharacterIndex);
	rBaseShip = GetShipByType(sti(rCharacter.Ship.Type));

	int iMinCrew = sti(rBaseShip.MinCrew);
	int iMaxCrew = sti(rBaseShip.MaxCrew);

	if (!CheckAttribute(rCharacter,"Ship.Crew.Quantity")) { rCharacter.Ship.Crew.Quantity = iMinCrew + rand(iMaxCrew - iMinCrew - 1); }
	if (!CheckAttribute(rCharacter,"Ship.HP")) { rCharacter.Ship.HP = rBaseShip.HP; }
	if (!CheckAttribute(rCharacter,"Ship.SP")) { rCharacter.Ship.SP = rBaseShip.SP; }

	if (!CheckAttribute(rCharacter,"Ship.Cannons.Charge.Type")) { rCharacter.Ship.Cannons.Charge.Type = GOOD_BOMBS; }

	//Trace("Init cindex = " + iCharacterIndex + ", ship HP = " + rCharacter.Ship.HP + ", id = " + rCharacter.id + ", idx = " + rCharacter.index);
	if (!CheckAttribute(rCharacter,"Ship.Cannons.Type")) { rCharacter.Ship.Cannons.Type = CANNON_TYPE_CULVERINE_LBS12; };

	rCharacter.Ship.Cannons.Borts = "";
}

void Ship_CheckMainCharacter()
{
	aref	arUpdate;
	ref		rIsland;
	int		i, iRelation;
	float	x, z, fBestDistance, fDistance;
	float	fMinEnemyDistance = 1000000.0;
	bool	bAbordageStartNow = false;

	PostEvent(SHIP_CHECK_RELOAD_ENABLE, 1000);

	ref rCharacter = GetMainCharacter();

	// if abordage launched, return
	if (bAbordageStarted) { return; }

	// if interface launched, return
	if (sti(InterfaceStates.Launched)) { return; }

	// if main character is dead - skip
	if (LAi_IsDead(rCharacter)) { return; };

	iStormLockSeconds = iStormLockSeconds - 1;
	if (iStormLockSeconds < 0) { iStormLockSeconds = 0; }

	bAbordageFortCanBe = false;
	bAbordageShipCanBe = false;
	bCanEnterToLand = false;
	bDisableSailTo = false;
	sIslandLocator = "";
	sIslandID = "";

	makearef(arUpdate, rCharacter.SeaAI.Update);

	if (!CheckAttribute(arUpdate, "Ships")) { return; }
	if (!CheckAttribute(arUpdate, "Forts")) { return; }

	x = stf(rCharacter.Ship.Pos.x);
	z = stf(rCharacter.Ship.Pos.z);

	float fOurHP = Ship_GetHP(rCharacter);
	float fOurFencing = stf(rCharacter.TmpSkill.Fencing);
	float fOurGrappling = stf(rCharacter.TmpSkill.Grappling);
	float fOurCrewFencing = (0.1 + fOurFencing * stf(rCharacter.Ship.Crew.Quantity));

	float fOurBoxSizeX = stf(rCharacter.Ship.BoxSize.x) / 2.0;

	bool bGrapplingProfessional = sti(rCharacter.TmpPerks.GrapplingProfessional);

	// max abordage parameters for our player
		float fGrapplingPerk = AIShip_isPerksUse(rCharacter.TmpPerks.LongRangeGrappling, 1.0, 1.15);
		fGrapplingPerk = AIShip_isPerksUse(rCharacter.TmpPerks.GrapplingProfessional, fGrapplingPerk, 1.25);

		float fOurMaxAbordageDistance = fGrapplingPerk * Bring2Range(15.0, 40.0, 0.0, 1.0, fOurGrappling);
		float fOurMaxAbordageAngle = Bring2Range(0.70, 0.45, 0.0, 1.0, fOurGrappling);
		float fOurMaxAbordageSpeed = Bring2Range(3.0, 5.0, 0.0, 1.0, fOurGrappling);

	string sPlayerLocation = rCharacter.location;
	string sPlayerLocator = rCharacter.location.locator;

	// find island
	int iIslandIndex = FindIsland(sPlayerLocation);
	if (iIslandIndex >= 0)
	{
		rIsland = GetIslandByIndex(iIslandIndex);
	}

	aref aShips, aForts;
	makearef(aShips, arUpdate.Ships);
	makearef(aForts, arUpdate.Forts);

	// check forts for abordage
		int iFortsNum = GetAttributesNum(aForts);
		fBestDistance = 10000000.0;
		for (i=0; i<iFortsNum; i++)
		{
			aref aFort = GetAttributeN(aForts, i);
			iRelation = sti(aFort.relation);
			if (iRelation == RELATION_FRIEND) { continue; }
			ref rFortCharacter = GetCharacter(sti(aFort.idx));
			if (LAi_IsDead(rFortCharacter)) { continue; }
			aref aRLoc = FindIslandReloadLocator(sPlayerLocation, rFortCharacter.location.locator);
			float fRadius = stf(aRLoc.Radius);
			fDistance = stf(aFort.Distance);
			int iFortMode = sti(rFortCharacter.Fort.Mode);

			switch (iFortMode)
			{
				case FORT_NORMAL:
					if (iRelation == RELATION_ENEMY)
					{
						if (fMinEnemyDistance > fDistance) { fMinEnemyDistance = fDistance; }
					}
				break;
				case FORT_DEAD:
					if (fDistance > fRadius) { continue; }
					if (fBestDistance > fDistance)
					{
						fBestDistance = fDistance;

						bCanEnterToLand = true;

						sIslandID = rIsland.id;
						makearef(arIslandReload, rIsland.reload);
						sIslandLocator = aRLoc.GoAfterBoard.location;
					}
				break;
				case FORT_ABORDAGE:
					if (iRelation == RELATION_ENEMY)
					{
						if (fMinEnemyDistance > fDistance) { fMinEnemyDistance = fDistance; }
					}
					if (fDistance > fRadius) { continue; }
					if (!Character_IsAbordageEnable(rFortCharacter)) { continue; }

					if (fBestDistance > fDistance)
					{
						fBestDistance = fDistance;

						bAbordageFortCanBe = true;
						sAbordageLocator = rFortCharacter.location.locator;
						iAbordageFortEnemyCharacter = sti(rFortCharacter.index);
					}
				break;
			}
		}

	// check ships for abordage
		int iShipsNum = GetAttributesNum(aShips);
		fBestDistance = 10000000.0;
		for (i=0; i<iShipsNum; i++)
		{
			aref aShip = GetAttributeN(aShips, i);

			ref rShipCharacter = GetCharacter(sti(aShip.idx));
			fDistance = stf(aShip.Distance);		// distance between player ship and this ship
			iRelation = sti(aShip.relation);

			if (LAi_IsDead(rShipCharacter)) { continue; }
			if (iRelation != RELATION_ENEMY) { continue; }
			if (fMinEnemyDistance > fDistance) { fMinEnemyDistance = fDistance; }

			if (!Character_IsAbordageEnable(rShipCharacter)) { continue; }

			float fAng = stf(aShip.d_ay);						// it's dot.ay between ships
			float fRelativeSpeed = stf(aShip.RelativeSpeed);	// it's relative speed about player ship
			float fEnemyBoxSizeX = stf(rShipCharacter.Ship.BoxSize.x) / 2.0;

			bool bAngleTest = abs(fAng) > fOurMaxAbordageAngle && fRelativeSpeed < fOurMaxAbordageSpeed;

			if (bGrapplingProfessional || bAngleTest)
			//if (abs(fAng) > fOurMaxAbordageAngle && fRelativeSpeed < fOurMaxAbordageSpeed)
			{
				float fAbordageDistance = fDistance - fEnemyBoxSizeX - fOurBoxSizeX;
				if (fAbordageDistance < fOurMaxAbordageDistance && fBestDistance > fDistance)
				{
					// abordage enable
					fBestDistance = fDistance;
					bAbordageShipCanBe = true;
					iAbordageShipEnemyCharacter = sti(rShipCharacter.index);

					// maybe other character want abordage us?
					float fEnemyFencing = stf(rCharacter.TmpSkill.Fencing);
					float fEnemyCrewFencing = (0.1 + fEnemyFencing * stf(rShipCharacter.Ship.Crew.Quantity));
					float fRatio = fEnemyCrewFencing / fOurCrewFencing;
					if (sti(rShipCharacter.nation) == PIRATE) { fRatio = fRatio * 1.4; }
					if (fRatio > 1.2)
					{
						bAbordageStartNow = true;
						break;
					}
				}
				continue;
			}
		}

	// check reload to locations possibility
		if (iIslandIndex >= 0 && fMinEnemyDistance > MIN_ENEMY_DISTANCE_TO_DISABLE_ENTER_2_LOCATION)
		{
			if (Island_isReloadEnableGlobal(sPlayerLocation))
			{
				aref arReload;
				makearef(arReload, rIsland.Reload);

				int iNumLocators = GetAttributesNum(arReload);
				for (int j=0; j<iNumLocators; j++)
				{
					aref arLocator;
					arLocator = GetAttributeN(arReload, j);
					string sLocatorName = GetAttributeName(arLocator);
					if (Island_isReloadFort(sPlayerLocation, arLocator.name)) { continue; }
					if (!Island_isReloadEnableLocal(sPlayerLocation, arLocator.name)) { continue; }
					float x1 = stf(rIsland.reload.(sLocatorName).x);
					float z1 = stf(rIsland.reload.(sLocatorName).z);
					float r = stf(rIsland.reload.(sLocatorName).radius);
					if (sqrt(sqr(x1 - x) + sqr(z1 - z)) < r)
					{
						bCanEnterToLand = true;
						sIslandID = rIsland.id;
						makearef(arIslandReload, rIsland.reload);
						sIslandLocator = rIsland.reload.(sLocatorName).name;
						break;
					}
				}
			}
		}

	// disable any abordage if storm
		if (Whr_IsStorm())
		{
			bAbordageStartNow = false;
			bAbordageFortCanBe = false;
			bAbordageShipCanBe = false;
		}

	// Enter 2 map enable/disable
	// Peoples on ship mode update
		int iPrevShipPOSMode = sti(rCharacter.Ship.POS.Mode);
		rCharacter.Ship.POS.Mode = SHIP_SAIL;

		bDisableMapEnter = false;
		if (fMinEnemyDistance < MIN_ENEMY_DISTANCE_TO_DISABLE_MAP_ENTER)
		{
			bCanEnterToLand = false;
			bDisableMapEnter = true;

			rCharacter.Ship.POS.Mode = SHIP_WAR;
		}

		if (iStormLockSeconds)
		{
			bDisableMapEnter = true;
			bCanEnterToLand = false;
			bDisableSailTo = true;

			rCharacter.Ship.POS.Mode = SHIP_STORM;
		}

		// new music
		if (sti(rCharacter.Ship.POS.Mode) != iPrevShipPOSMode)
		{
			switch (sti(rCharacter.Ship.POS.Mode))
			{
				case SHIP_SAIL:
					if (!Whr_IsStorm()) { Sound_OnSeaAlarm(false); }
					if (iPrevShipPOSMode == SHIP_WAR) { PlayStereoOGG("music_ship_victory"); }
					if (iPrevShipPOSMode == SHIP_STORM)
					{
						FadeOutMusic(3000);
						PlayStereoOGG("music_End_storm");
					}
				break;
				case SHIP_WAR:
					Sound_OnSeaAlarm(true);
				break;
			}
		}

	// if quest disable enter 2 map
		if (bQuestDisableMapEnter) { bDisableMapEnter = true; }

	// Start abordage automatically
		if (bAbordageStartNow) { Sea_AbordageLoad(SHIP_ABORDAGE, false); }
}

void Ship_OnStrandNext()
{
	ref	rCharacter = GetCharacter(GetEventData());
	if (LAi_IsDead(rCharacter)) { return; }

	bool bOnStrand = sti(rCharacter.Ship.Strand);
	if (!bOnStrand)
	{
		int iSoundID = sti(rCharacter.Ship.Strand.SndID);
		if (iSoundID != 0) { StopSound(sti(rCharacter.Ship.Strand.SndID), 3000); }
		rCharacter.Ship.Strand.SndID = SOUND_INVALID_ID;
		return;
	}

	if (!sti(rCharacter.TmpPerks.SandbankManeuver))
	{
		float fCurrentSpeedZ = stf(rCharacter.Ship.Speed.z);

		float fHP = 4.0 * fCurrentSpeedZ / 7.0;
		Ship_ApplyHullHitpoints(rCharacter, fHP, KILL_BY_ISLAND, -1);
	}
	PostEvent(SHIP_TO_STRAND_NEXT, 100 + rand(100), "l", sti(rCharacter.index));
}

void Ship_OnStrand()
{
	ref rCharacter = GetCharacter(GetEventData());
	bool bNewStrand = GetEventData();

	bool bPrevStrand = sti(rCharacter.Ship.Strand);

	rCharacter.Ship.Strand = bNewStrand;

	float x = stf(rCharacter.Ship.Pos.x);
	float y = stf(rCharacter.Ship.Pos.y);
	float z = stf(rCharacter.Ship.Pos.z);

	if (bPrevStrand == 0 && bNewStrand == 1)
	{
		PostEvent(SHIP_TO_STRAND_NEXT, 100, "l", sti(rCharacter.index));
		rCharacter.Ship.Strand.SndID = Play3DSoundComplex("ship_aground", x, y, z, true, false);
	}
}

// Small boom
void Ship_DetonateSmall()
{
	ref		rCharacter = GetCharacter(GetEventData());
	aref	arCharShip; makearef(arCharShip, rCharacter.Ship);

	float x = stf(arCharShip.Pos.x);
	float y = stf(arCharShip.Pos.y);
	float z = stf(arCharShip.Pos.z);

	if (y > -3.0)
	{
		int iSClass = GetCharacterShipClass(rCharacter);
		PostEvent(SHIP_DETONATE_SMALL, 200 + iSClass * 300 + rand(900), "l", sti(rCharacter.index));
	}

	if (bAbordageStarted) { return; }
	if (sti(InterfaceStates.Launched)) { return; }

	float bx = arCharShip.BoxSize.x;
	float by = arCharShip.BoxSize.y;
	float bz = arCharShip.BoxSize.z;

	float fCos = cos(stf(arCharShip.Ang.y));
	float fSin = sin(stf(arCharShip.Ang.y));

	for (int i=0; i < 1 + rand(1); i++)
	{
		float x1, y1, z1;
		x1 = (frnd() - 0.5) * bx;
		z1 = (frnd() - 0.5) * bz;

		RotateAroundY(&x1, &z1, fCos, fSin);

		y1 = 1.0 + y + frnd() * 3.0;
		Ship_Serious_Boom(x1 + x, y1, z1 + z);
		CreateParticleSystem("blast", x1 + x, y1, z1 + z, 0.0, 0.0, 0.0, 0);
	}
}

void Ship_Turn180(ref rCharacter)
{
	rCharacter.TmpPerks.Turn = true;
	rCharacter.TmpPerks.Turn.Angle = PI;
}

// Big Boom on ship
void Ship_Detonate(ref rCharacter, bool bMakeSmallBoom, bool bMakeDead)
{
	if (!CheckAttribute(rCharacter, "Ship.Pos.x"))
	{
		Trace("Ship_Detonate: Can't find Ship.Pos in character with id: " + rCharacter.id);
		return;
	}
	aref	arCharShip; makearef(arCharShip, rCharacter.Ship);

	float x = stf(arCharShip.Pos.x);
	float y = stf(arCharShip.Pos.y);
	float z = stf(arCharShip.Pos.z);

	int iMinBoom = MakeInt(Bring2Range(6.0, 2.0, 1.0, 7.0, stf(GetCharacterShipClass(rCharacter))));

	float bx = arCharShip.BoxSize.x;
	float by = arCharShip.BoxSize.y;
	float bz = arCharShip.BoxSize.z;

	float fCos = cos(stf(arCharShip.Ang.y));
	float fSin = sin(stf(arCharShip.Ang.y));

	for (int i=0; i<iMinBoom + rand(2); i++)
	{
		float x1, y1, z1;
		x1 = (frnd() - 0.5) * bx;
		z1 = (frnd() - 0.5) * bz;

		RotateAroundY(&x1, &z1, fCos, fSin);

		y1 = 1.0 + y + frnd() * 3.0;
		Ship_Serious_Boom(x1 + x, y1, z1 + z);
		CreateParticleSystem("blast", x1 + x, y1, z1 + z, 0.0, 0.0, 0.0, 0);
	}
	if (bMakeDead) { ShipDead(sti(rCharacter.Index), KILL_BY_SPY, -1); }

	if (bMakeSmallBoom) { PostEvent(SHIP_DETONATE_SMALL, 600 + rand(1000), "l", sti(rCharacter.index)); }
}

float AIShip_isPerksUse(string sPerk, float fOff, float fOn)
{
	if (sti(sPerk)) { return fOn; }
	return fOff;
}

// EVENT, calculate dynamic parameters for ship, one per second
void Ship_UpdateParameters()
{
	int		iCharacterIndex = GetEventData();
	ref		rCharacter = GetCharacter(iCharacterIndex);
	float	fSailState = GetEventData();

	bool	bStrand = sti(rCharacter.Ship.Strand);

	bool	bDead = LAi_IsDead(rCharacter);

	aref	arTmpPerks; makearef(arTmpPerks, rCharacter.TmpPerks);

	// update temporary skill storage
		Ship_UpdateTmpSkills(rCharacter);

		Cannon_RecalculateParameters(sti(rCharacter.index));

	// some of ship parameters
		aref	arCharShip; makearef(arCharShip, rCharacter.Ship);
		ref		rShip = GetShipByType(sti(arCharShip.Type));

		float	fMaxSpeedZ = stf(rShip.SpeedRate);
		float	fMaxSpeedY = stf(rShip.TurnRate) / 444.444;		// cool magic number :))
		float	fCurrentSpeedZ = stf(arCharShip.Speed.z);
		float	fLoad = Clampf(stf(arCharShip.Cargo.Load) / stf(rShip.Capacity));

	// Calc min crew ratio
		float fCrewMin = stf(rShip.MinCrew);
		float fCrewCur = stf(rCharacter.Ship.Crew.Quantity);
		float fCrewMin25Percent = stf(rShip.MinCrew) * 0.25;
		arCharShip.Crew.MinRatio = Bring2Range(0.0, 1.0, fCrewMin25Percent, fCrewMin, fCrewCur);

	// wind power
		float	fWindPower = Whr_GetWindSpeed() / WIND_NORMAL_POWER;
		float	fWindDotShip = GetDotProduct(Whr_GetWindAngle(), stf(arCharShip.Ang.y));		// Wind.ay | Ship.ay

	// calculate MaxSpeedZ
		float fSpeedPerk = AIShip_isPerksUse(arTmpPerks.ShipSpeedUp, 1.0, 1.15);
		fSpeedPerk = AIShip_isPerksUse(arTmpPerks.SailingProfessional, fSpeedPerk, 1.20);

		float	fK = Clampf(1.0 - stf(rShip.SpeedDependWeight) * fLoad);
		arCharShip.MaxSpeedZ = (fMaxSpeedZ * fWindPower * fK) * fSpeedPerk;
		// ORZEL SECTION :), DELETE /*
		/*if (bStrand) fK = fK * stf(rCharacter.TmpSkill.);
		if (fWindDotShip < -0.98) arCharShip.MaxSpeedZ = 0.0;*/
		// ORZEL SECTION :), DELETE */

	// calculate MaxSpeedY
		float	fTRFromWeight = Clampf(1.0 - stf(rShip.TurnDependWeight) * fLoad);
		float	fTRFromSpeed = 1.0 - stf(rShip.TurnDependSpeed) * (1.0 - Clampf(fCurrentSpeedZ / fMaxSpeedZ));
		float	fTRFromSkill = Bring2Range(0.2, 1.0, 0.0, 2.0, 2.0 * stf(rCharacter.TmpSkill.Sailing));
		float	fTRFromPeople = Bring2Range(0.2, 1.0, 0.0, 1.0, stf(arCharShip.Crew.MinRatio));
		float	fTRFromSailDamage = 1.0;

		// Turn rate depend from sail State
			float	fTRFromSailState = 1.0;
			switch (MakeInt(fSailState * 2.0))
			{
				case 0: fTRFromSailState = 0.3; break;
				case 1: fTRFromSailState = 1.0; break;
				case 2: fTRFromSailState = 0.6; break;
			}

		float	fTRResult = Bring2Range(0.2, 0.85, 0.00001, 1.0, fTRFromWeight * fTRFromSpeed * fTRFromSkill * fTRFromPeople * fTRFromSailDamage * fTRFromSailState);

		float fTurnPerk = AIShip_isPerksUse(arTmpPerks.ShipTurnRateUp, 1.0, 1.15);
		fTurnPerk = AIShip_isPerksUse(arTmpPerks.SailingProfessional, fTurnPerk, 1.20);

		// fast turn 180
		if (sti(arTmpPerks.Turn) == -1)
		{
			CharacterPerkOff(rCharacter, "Turn180");
			arTmpPerks.Turn = false;
		}
		float fFastTurn180 = AIShip_isPerksUse(arTmpPerks.Turn, 1.0, 8.0);

		arCharShip.MaxSpeedY =	fTRResult * fMaxSpeedY * fTurnPerk * fFastTurn180;

	// calculate immersion
		arCharShip.Immersion = (stf(rShip.SubSeaDependWeight) * fLoad);

	// do damage if ship hull < 10%, sinking
		float fBaseSailHP = stf(rShip.SP);
		float fBaseShipHP = stf(rShip.HP);
		float fCurHP = stf(arCharShip.HP);
		if (bSeaActive && (fCurHP / fBaseShipHP < 0.1))
		{
			float fLightRepair = AIShip_isPerksUse(arTmpPerks.LightRepair, 1.0, 0.0);
			if (CheckAttribute(rCharacter, "SinkTenPercent") && !sti(rCharacter.SinkTenPercent)) { fLightRepair = 0.0; }
			float fSinkDamage = fLightRepair * (fBaseShipHP / 100.0) * 0.08;
			if (CheckAttribute(rCharacter, "Ship.LastBallCharacter"))
			{
				Ship_ApplyHullHitpoints(rCharacter, fSinkDamage, KILL_BY_BALL, sti(rCharacter.Ship.LastBallCharacter));
			}
			else
			{
				Ship_ApplyHullHitpoints(rCharacter, fSinkDamage, KILL_BY_TOUCH, -1);
			}
			if (iCharacterIndex == GetMainCharacterIndex()) { AddPerkToActiveList("sink"); }
		}
		else
		{
			if (iCharacterIndex == GetMainCharacterIndex()) { DelPerkFromActiveList("sink"); }
		}

		float fStormProfessional = AIShip_isPerksUse(arTmpPerks.StormProfessional, 1.0, 0.6);

	// do damage if storm or tornado
		if (bStorm && bSeaActive)
		{
			float fWindAttack = 1.0 - abs(fWindDotShip);

			float fDamageMultiply = fStormProfessional * Bring2Range(0.25, 1.0, 0.0, 1.0, fWindAttack);

			// hull damage
			float fDamageHP = (fBaseShipHP / 100.0) * 1.1;
			Ship_ApplyHullHitpoints(rCharacter, fDamageMultiply * fDamageHP, KILL_BY_TOUCH, -1);

			// sails damage
			switch (MakeInt(fSailState * 2.0))
			{
				case 0: MakeSailDmg(iCharacterIndex, fDamageMultiply * (fBaseSailHP / 100.0) * 0.15); break;
				case 1: MakeSailDmg(iCharacterIndex, fDamageMultiply * (fBaseSailHP / 100.0) * 0.55); break;
				case 2: MakeSailDmg(iCharacterIndex, fDamageMultiply * (fBaseSailHP / 100.0) * 1.1); break;
			}

			// experience
			float fExp = (1.0 - fWindAttack) * fDamageHP;
			if (!bDead) { Ship_AddCharacterExp(rCharacter, MakeInt(fExp)); }

			// rotate impulse
			float fRotate = stf(arCharShip.Impulse.Rotate.y) + (frnd() * 0.08 - 0.04);
			if (fRotate > 0.07) { fRotate = 0.07; }
			if (fRotate < -0.07) { fRotate = -0.07; }

			arCharShip.Impulse.Rotate.y = fRotate;
		}

		if (bTornado && bSeaActive)
		{
			float fTornadoDistance = GetDistance2D(stf(Tornado.x), stf(Tornado.z), stf(arCharShip.Pos.x), stf(arCharShip.Pos.z));
			float fTornadoDamageMultiply = fStormProfessional * Bring2Range(1.0, 0.0, 0.0, 100.0, fTornadoDistance);

			// hull damage
			Ship_ApplyHullHitpoints(rCharacter, fTornadoDamageMultiply * (fBaseShipHP / 100.0) * 8.5, KILL_BY_TOUCH, -1);

			// sails damage
			switch (MakeInt(fSailState * 2.0))
			{
				case 0: MakeSailDmg(iCharacterIndex, fTornadoDamageMultiply * (fBaseSailHP / 100.0) * 1.5); break;
				case 1: MakeSailDmg(iCharacterIndex, fTornadoDamageMultiply * (fBaseSailHP / 100.0) * 4.5); break;
				case 2: MakeSailDmg(iCharacterIndex, fTornadoDamageMultiply * (fBaseSailHP / 100.0) * 8.5); break;
			}
		}

	// Expirience log section
		if (iCharacterIndex == GetMainCharacterIndex() && bSeaActive)
		{
			fSeaExpTimer = fSeaExpTimer + 1.0;
			if (fSeaExpTimer >= 15.0 && bStorm)
			{
				if (!bDead) { Ship_PrintExp(MakeInt(fSeaExp)); }

				fSeaExpTimer = 0.0;
				fSeaExp = 0.0;
			}
		}

	// Apply arcade mode
		if (bArcadeMode)
		{
			arCharShip.MaxSpeedZ = 3.0 * stf(arCharShip.MaxSpeedZ);
			arCharShip.MaxSpeedY =	3.0 * stf(arCharShip.MaxSpeedY);
		}

	// Recalculate Cargo Load if need
	if (CheckAttribute(rCharacter, "Ship.Cargo.RecalculateCargoLoad") && sti(rCharacter.Ship.Cargo.RecalculateCargoLoad))
	{
		RecalculateCargoLoad(rCharacter);
		rCharacter.Ship.Cargo.RecalculateCargoLoad = 0;
	}
}

void Ship_PrintExp(int iExp)
{
	if (iExp <= 0) { return; }

	object oRes;
	string sExpQuantity = iExp;
	string sExpString = LanguageConvertString(iSeaSectionLang, "sea_exp_add");

	Event(PARSE_STRING, "asls", &oRes, sExpString, 1, sExpQuantity);

	Log_SetStringToLog(oRes.Str);
}

void Ship_TornadoDamage()
{
	float fTime = GetEventData();

	Tornado.x = GetEventData();
	Tornado.z = GetEventData();
}

void Ship_UpdateTmpSkills(ref rCharacter)
{
	rCharacter.TmpSkill = "";

	aref aTmpSkill; makearef(aTmpSkill, rCharacter.TmpSkill);

	// calc skills for speed optimization
	//aTmpSkill.Commerce = MakeFloat(GetSummonSkillFromName(rCharacter, SKILL_COMMERCE)) / SKILL_MAX;
	//aTmpSkill.Leadership = MakeFloat(GetSummonSkillFromName(rCharacter, SKILL_LEADERSHIP)) / SKILL_MAX;
	aTmpSkill.Sneak = MakeFloat(GetSummonSkillFromName(rCharacter, SKILL_SNEAK)) / SKILL_MAX;
	aTmpSkill.Defence = MakeFloat(GetSummonSkillFromName(rCharacter, SKILL_DEFENCE)) / SKILL_MAX;
	aTmpSkill.Grappling = MakeFloat(GetSummonSkillFromName(rCharacter, SKILL_GRAPPLING)) / SKILL_MAX;
	aTmpSkill.Sailing = MakeFloat(GetSummonSkillFromName(rCharacter, SKILL_SAILING)) / SKILL_MAX;
	aTmpSkill.Repair = MakeFloat(GetSummonSkillFromName(rCharacter, SKILL_REPAIR)) / SKILL_MAX;
	aTmpSkill.Fencing = MakeFloat(GetSummonSkillFromName(rCharacter, SKILL_FENCING)) / SKILL_MAX;
	aTmpSkill.Accuracy = MakeFloat(GetSummonSkillFromName(rCharacter, SKILL_ACCURACY)) / SKILL_MAX;
	aTmpSkill.Cannons = MakeFloat(GetSummonSkillFromName(rCharacter, SKILL_CANNONS)) / SKILL_MAX;

	if (SeaCameras.Camera == "SeaDeckCamera" && sti(rCharacter.index) == GetMainCharacterIndex())
	{
		switch (GetTargetPlatform())
		{
			case "xbox":
				aTmpSkill.Accuracy = 1.0;
			break;
			case "pc":
				aTmpSkill.Accuracy = Clampf(stf(aTmpSkill.Accuracy) + 0.4);
			break;
		}
	}
}

void Ship_UpdatePerks()
{
	int iCharacterIndex = GetEventData();
	ref rCharacter = GetCharacter(iCharacterIndex);

	//Trace("Ship_UpdatePerks: rCharacter.id = " + rCharacter.id);

	rCharacter.TmpPerks = "";
	aref aTmpPerks; makearef(aTmpPerks, rCharacter.TmpPerks);

	// calc perks for speed optimization
	if (!CheckAttribute(rCharacter, "TmpPerks.Turn")) {	rCharacter.TmpPerks.Turn = 0; }

	aTmpPerks.FastReload				= CheckOfficersPerk(rCharacter, "FastReload");
	aTmpPerks.ImmediateReload			= CheckOfficersPerk(rCharacter, "ImmediateReload");
	aTmpPerks.HullDamageUp			 	= CheckOfficersPerk(rCharacter, "HullDamageUp");
	aTmpPerks.CrewDamageUp				= CheckOfficersPerk(rCharacter, "CrewDamageUp");
	aTmpPerks.CriticalShoot				= CheckOfficersPerk(rCharacter, "CriticalShoot");
	aTmpPerks.LongRangeShoot			= CheckOfficersPerk(rCharacter, "LongRangeShoot");
	aTmpPerks.CannonProfessional		= CheckOfficersPerk(rCharacter, "CannonProfessional");
	aTmpPerks.LongRangeGrappling		= CheckOfficersPerk(rCharacter, "LongRangeGrappling");
	//aTmpPerks.MusketsShoot				= CheckOfficersPerk(rCharacter, "MusketsShoot");				// !!!!
	aTmpPerks.GrapplingProfessional		= CheckOfficersPerk(rCharacter, "GrapplingProfessional");
	aTmpPerks.BasicBattleState			= CheckOfficersPerk(rCharacter, "BasicBattleState");
	aTmpPerks.AdvancedBattleState		= CheckOfficersPerk(rCharacter, "AdvancedBattleState");
	aTmpPerks.ShipDefenseProfessional	= CheckOfficersPerk(rCharacter, "ShipDefenseProfessional");
	aTmpPerks.ShipSpeedUp				= CheckOfficersPerk(rCharacter, "ShipSpeedUp");
	aTmpPerks.ShipTurnRateUp			= CheckOfficersPerk(rCharacter, "ShipTurnRateUp");
	aTmpPerks.StormProfessional			= CheckOfficersPerk(rCharacter, "StormProfessional");			// !!!!
	aTmpPerks.SandbankManeuver			= CheckOfficersPerk(rCharacter, "SandbankManeuver");
	aTmpPerks.SailingProfessional		= CheckOfficersPerk(rCharacter, "SailingProfessional");

	aTmpPerks.LightRepair				= CheckOfficersPerk(rCharacter, "LightRepair");

	// update main character if rCharacter is companion
	if (iCharacterIndex != GetMainCharacterIndex() && IsCompanion(rCharacter))
	{
		Event("eSwitchPerks", "l", GetMainCharacterIndex());
	}
}

void Ship_Lightning()
{
	if (!bSeaActive) { return; }

	float x = GetEventData();
	float y = GetEventData();
	float z = GetEventData();

	for (int i=0; i<iNumShips; i++)
	{
		ref rCharacter = GetCharacter(Ships[i]);
		aref arShipChar; makearef(arShipChar, rCharacter.Ship);

		float sx = stf(arShipChar.Pos.x);
		float sy = stf(arShipChar.Pos.y);
		float sz = stf(arShipChar.Pos.z);
		float bx = stf(arShipChar.BoxSize.x);
		float by = stf(arShipChar.BoxSize.y);
		float bz = stf(arShipChar.BoxSize.z);
		float fDist = GetDistance2D(x, z, sx, sz);
		float fMinLightningDist = 20.0 + bz / 1.5;
		if (fDist < fMinLightningDist)
		{
			int iMinBoom = MakeInt(Bring2Range(5.0, 2.0, 1.0, 7.0, stf(GetCharacterShipClass(rCharacter))));
			float fCos = cos(stf(arShipChar.Ang.y));
			float fSin = sin(stf(arShipChar.Ang.y));
			for (int k=0; k<iMinBoom + rand(2); k++)
			{
				float dx = 0.6 * bx * (frnd() - 0.5);
				float dz = 0.7 * bz * (frnd() - 0.5);
				RotateAroundY(&dx, &dz, fCos, fSin);
				Ship_Serious_Boom(sx + dx, sy + 0.1 * by * frnd(), sz + dz);
			}

			Ship_ApplyHullHitpoints(rCharacter, iMinBoom * 40.0, KILL_BY_TOUCH, -1);
			Ship_ApplyCrewHitpoints(rCharacter, MakeFloat(rand(3)));

			int iNumFirePlaces = 0;
			SendMessage(rCharacter, "le", MSG_SHIP_GET_NUM_FIRE_PLACES, &iNumFirePlaces);

			float fFirePlaces = Bring2Range(1.0, 0.1, 0.0, fMinLightningDist, fDist);

			float fCurr = 0.0;
			float fTest = (1.0 - fFirePlaces) * iNumFirePlaces;
			for (int j=0; j<iNumFirePlaces; j++)
			{
				fCurr = fCurr + 1.0;
				if (fCurr < fTest) { continue; }

				fCurr = 0.0;
				int iRandStartTime = rand(10000);
				float fTotalFireTime = Ship_GetTotalFireTime(rCharacter);

				PostEvent(SHIP_ACTIVATE_FIRE_PLACE, iRandStartTime, "ialsf", rCharacter, rCharacter, j, "ship_onfire", fTotalFireTime);
				PostEvent(SHIP_FIRE_DAMAGE, iRandStartTime, "lllf", Ships[i], -1, j, fTotalFireTime);
			}
		}
	}
}

// Create a new ship for character
void Ship_CreateForCharacter(ref rCharacter, int iShipType, string sShipName)
{
	DeleteAttribute(rCharacter, "Ship");

	rCharacter.Ship.Type = iShipType;
	rCharacter.Ship.Name = sShipName;

	rCharacter.Ship.Cannons.Borts = "";
	rCharacter.Ship.Cannons.Charge.Type = GOOD_BOMBS;
	rCharacter.Ship.Ang.y = 0.0;
	rCharacter.Ship.Pos.x = 0.0;
	rCharacter.Ship.Pos.z = 0.0;
	rCharacter.Ship.Speed.z = 0.0;

	SetBaseShipData(rCharacter);
}

void Ship_ClearImpulseStrength(ref rCharacter)
{
	aref arImpulse; makearef(arImpulse, rCharacter.Ship.Impulse);
	arImpulse.Rotate.x = 0.0;
	arImpulse.Rotate.y = 0.0;
	arImpulse.Rotate.z = 0.0;
	arImpulse.Speed.x = 0.0;
	arImpulse.Speed.y = 0.0;
	arImpulse.Speed.z = 0.0;
}

void Ship_PrepareShipForLocation(ref rCharacter)
{
	Ship_ClearImpulseStrength(rCharacter);
}

void Ship_StartLoad()
{
	SetTexturePath(0, "Ships\\")
}

void Ship_EndLoad()
{
	SetTexturePath(0, "");
}

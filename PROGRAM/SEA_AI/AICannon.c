
void DeleteCannonsEnvironment()
{
	DelEventHandler(CANNON_GET_RECHARGE_TIME, "Cannon_GetRechargeTime");
	DelEventHandler(CANNON_GET_FIRE_TIME, "Cannon_GetFireTime");
	DelEventHandler(CANNON_GET_FIRE_HEIGHT, "Cannon_GetFireHeight");
	DelEventHandler(CANNON_FIRE, "Cannon_FireCannon");
	DelEventHandler(CANNON_UNLOAD, "Cannon_UnloadBall");
	DelEventHandler(CANNON_LOAD, "Cannon_LoadBall");
	DelEventHandler(CANNON_RECALCULATE_PARAMETERS, "Cannon_RecalculateParametersEvent");
}

void CreateCannonsEnvironment()
{
	SetEventHandler(CANNON_GET_RECHARGE_TIME, "Cannon_GetRechargeTime", 0);
	SetEventHandler(CANNON_GET_FIRE_TIME, "Cannon_GetFireTime", 0);
	SetEventHandler(CANNON_GET_FIRE_HEIGHT, "Cannon_GetFireHeight", 0);
	SetEventHandler(CANNON_FIRE, "Cannon_FireCannon", 0);
	SetEventHandler(CANNON_UNLOAD, "Cannon_UnloadBall", 0);
	SetEventHandler(CANNON_LOAD, "Cannon_LoadBall", 0);
	SetEventHandler(CANNON_RECALCULATE_PARAMETERS, "Cannon_RecalculateParametersEvent", 0);
}

bool Cannon_LoadBall()
{
	aref	aCharacter = GetEventData();

	int iBallType = sti(aCharacter.Ship.Cannons.Charge.Type);
	int iNumBalls = GetCargoGoodsSimple(aCharacter, iBallType);
	if (iNumBalls > 0)
	{
		AddCharacterGoodsSimple(aCharacter, iBallType, -1);
		return true;
	}
	return false;
}

int GetCargoGoodsSimple(aref aCharacter, int iGood)
{
	string sGoodName = Goods[iGood].name;
	return sti(aCharacter.Ship.Cargo.Goods.(sGoodName));
}

void SetCharacterGoodsSimple(aref aCharacter, int iGood, int iQuantity)
{
	string sGoodName = Goods[iGood].name;
	aCharacter.Ship.Cargo.Goods.(sGoodName) = iQuantity;

	aCharacter.Ship.Cargo.RecalculateCargoLoad = true;
}

void AddCharacterGoodsSimple(aref aCharacter, int iGood, int iQuantity)
{
	aref arGoods;
	string sGoodName = Goods[iGood].name;
	makearef(arGoods, aCharacter.Ship.Cargo.Goods);
	arGoods.(sGoodName) = sti(arGoods.(sGoodName)) + iQuantity;

	aCharacter.Ship.Cargo.RecalculateCargoLoad = true;
}

void Cannon_UnloadBall()
{
	aref aCharacter = GetEventData();

	AddCharacterGoodsSimple(aCharacter, sti(aCharacter.Ship.Cannons.Charge.Type), 1);
}

void Cannon_RecalculateParametersEvent()
{
	int iCharacterIndex = GetEventData();
	Cannon_RecalculateParameters(iCharacterIndex);
}

void Cannon_RecalculateParameters(int iCharacterIndex)
{
	if (sti(Characters[iCharacterIndex].Ship.Cannons.Type) == CANNON_TYPE_NONECANNON) { return; }

	ref	rCharacter = GetCharacter(iCharacterIndex);
	ref	rCannon = GetCannonByType(sti(rCharacter.Ship.Cannons.Type));
	ref	rBall = GetGoodByType(sti(rCharacter.Ship.Cannons.Charge.Type));

	rCharacter.Ship.Cannons.SpeedV0 = stf(rCannon.SpeedV0) * stf(rBall.SpeedV0) * AIShip_isPerksUse(rCharacter.TmpPerks.LongRangeShoot, 1.0, 1.15);
	rCharacter.Ship.Cannons.FireAngMax = rCannon.FireAngMax;
	rCharacter.Ship.Cannons.FireAngMin = rCannon.FireAngMin;
}

float Cannon_GetFireHeight()
{
	aref aCharacter = GetEventData();
	aref aEnemy = GetEventData();
	
	ref rBallType = GetGoodByType(sti(aCharacter.Ship.Cannons.Charge.Type));
	ref rEnemyShip = GetShipByType(sti(aEnemy.Ship.Type));

	string sBallName = rBallType.Name;

	float Y,DY;
	Y = stf(rEnemyShip.Height.(sBallName).Y);
	DY = stf(rEnemyShip.Height.(sBallName).DY);

	// charge/ship depend
	return (Y + (frnd()-0.5) * DY * 2);
}

// calculate recharge time for cannon
float Cannon_GetRechargeTime()
{
	aref	aCharacter = GetEventData();

	float	fCannonSkill = stf(aCharacter.TmpSkill.Cannons);
	ref		rCannon = GetCannonByType(sti(aCharacter.Ship.Cannons.Type));
	float	fReloadTime = sti(rCannon.ReloadTime);

	float fMultiply = AIShip_isPerksUse(aCharacter.TmpPerks.FastReload, 1.0, 0.8); 
	fMultiply = AIShip_isPerksUse(aCharacter.TmpPerks.ImmediateReload, fMultiply, 0.5); 
	fMultiply = fMultiply * Bring2RangeNoCheck(4.0, 1.0, 0.0, 1.0, stf(aCharacter.Ship.Crew.MinRatio));

	return  fMultiply * (fReloadTime - fCannonSkill * (fReloadTime / 2.0));
}

// calculate delay before fire
float Cannon_GetFireTime()
{
	aref aCharacter = GetEventData();

	float fCannonSkill = stf(aCharacter.TmpSkill.Cannons);
	float fFireTime = 1.3 - fCannonSkill;
	fFireTime = fFireTime * Bring2RangeNoCheck(3.0, 1.0, 0.0, 1.0, stf(aCharacter.Ship.Crew.MinRatio));
	fFireTime = frnd() * fFireTime * 6.0;
	if (bArcadeMode) { fFireTime = fFireTime * 0.5; }
	return fFireTime; 
}

void Cannon_FireCannon()
{
	float fX, fY, fZ, fSpeedV0, fDirAng, fHeightAng, fCannonDirAng;

	aref aCharacter = GetEventData();
	fX = GetEventData();
	fY = GetEventData();
	fZ = GetEventData();
	fSpeedV0 = GetEventData();
	fDirAng = GetEventData();
	fHeightAng = GetEventData();
	fCannonDirAng = GetEventData();

	Ball_AddBall(aCharacter, fX, fY, fZ, fSpeedV0, fDirAng, fHeightAng, fCannonDirAng);
}
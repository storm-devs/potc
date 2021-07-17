object	AIBalls;
aref	Grapes, Knippels, Balls, Bombs;

void DeleteBallsEnvironment()
{
	DeleteClass(&AIBalls);

	DelEventHandler(BALL_WATER_HIT,"Ball_WaterHitEvent");
	DelEventHandler(BALL_ISLAND_HIT,"Ball_IslandHit");
	DelEventHandler(BALL_FLY_UPDATE,"Ball_OnFlyUpdate");
	DelEventHandler(BALL_FORT_HIT,"Ball_FortHit");
}

void CreateBallsEnvironment()
{
	CreateEntity(&AIBalls, "AIBalls");
	LayerAddObject(SEA_EXECUTE, &AIBalls, -1);
	LayerAddObject(SEA_REALIZE, &AIBalls, 65532);

	AIBalls.SpeedMultiply = 3.0;
	AIBalls.Texture = "AllBalls.tga";
	AIBalls.SubTexX = 2;
	AIBalls.SubTexY = 2;

	makearef(Grapes,AIBalls.Balls.Grapes);
	makearef(Knippels,AIBalls.Balls.Knippels);
	makearef(Balls,AIBalls.Balls.Balls);
	makearef(Bombs,AIBalls.Balls.Bombs);

	// Bombs
	Bombs.SubTexIndex = 0;		Bombs.Size = 0.3;		Bombs.GoodIndex = GOOD_BOMBS;
	Bombs.Particle = "bomb_smoke";

	// Grapes
	Grapes.SubTexIndex = 1;		Grapes.Size = 0.2;		Grapes.GoodIndex = GOOD_GRAPES;

	// Balls
	Balls.SubTexIndex = 2;		Balls.Size = 0.2;		Balls.GoodIndex = GOOD_BALLS;

	// Knippels
	Knippels.SubTexIndex = 3;	Knippels.Size = 0.2;	Knippels.GoodIndex = GOOD_KNIPPELS;

	AIBalls.isDone = 1;

	SetEventHandler(BALL_WATER_HIT,"Ball_WaterHitEvent",0);
	SetEventHandler(BALL_ISLAND_HIT,"Ball_IslandHit",0);
	SetEventHandler(BALL_FLY_UPDATE,"Ball_OnFlyUpdate",0);
	SetEventHandler(BALL_FORT_HIT,"Ball_FortHit",0);
}

int ballNumber;

void Ball_AddBall(aref aCharacter, float fX, float fY, float fZ, float fSpeedV0, float fDirAng, float fHeightAng, float fCannonDirAng)
{
	EntityUpdate(0);
	AIBalls.x = fX;
	AIBalls.y = fY;
	AIBalls.z = fZ;
	AIBalls.CharacterIndex = aCharacter.Index;
	AIBalls.Type = Goods[sti(aCharacter.Ship.Cannons.Charge.Type)].Name;
	
	float fTempDispersionY = Degree2Radian(10.0);
	float fTempDispersionX = Degree2Radian(5.0);

	float fAccuracy = 1.2 - stf(aCharacter.TmpSkill.Accuracy);
	float fK = Bring2Range(0.5, 1.2, 0.2, 1.2, fAccuracy);
	AIBalls.Dir = fDirAng + fK * fTempDispersionY * (frnd() - 0.5);
	AIBalls.SpdV0 = fSpeedV0 + fAccuracy * (10.0 * fTempDispersionY) * (frnd() - 0.5);
	AIBalls.Ang = fHeightAng + fAccuracy * (fTempDispersionX) * (frnd() - 0.5);

	AIBalls.Event = "";
	/*if (sti(rCharacter.index) == GetMainCharacterIndex())
	{
		if (ballNumber == 1) { AIBalls.Event = BALL_FLY_UPDATE; }
		ballNumber++;
	}*/

	EntityUpdate(1);
	AIBalls.Add = "";

	CreateParticleSystem("cancloud", fX, fY, fZ, -fHeightAng, fDirAng, 0.0, 5);

	Play3DSound("cannon_fire", fX, fY, fZ);
}

void Ball_WaterHitEvent()
{
	int		iCharacterIndex;
	float	x, y, z, vx, vy, vz;

	iCharacterIndex = GetEventData();
	x = GetEventData();
	y = GetEventData();
	z = GetEventData();
	/*vx = GetEventData();
	vy = GetEventData();
	vz = GetEventData();*/

	SendMessage(&BallSplash, "lffffff", MSG_BALLSPLASH_ADD, x, y, z, 0.0, 0.0, 0.0); // vx, vy, vz
	Play3DSound("ball_splash", x, y, z);
}

void Ball_FortHit()
{
	int		iCharacterIndex;
	float	x, y, z;

	iCharacterIndex = GetEventData();

	x = GetEventData();
	y = GetEventData();
	z = GetEventData();

	CreateParticleSystem("blast", x, y, z, 0.0, 0.0, 0.0, 0);
	SendMessage(&AIFort, "llfff", AI_MESSAGE_FORT_HIT, iCharacterIndex, x, y, z);
}

void Ball_IslandHit()
{
	int		iCharacterIndex;
	float	x, y, z;

	iCharacterIndex = GetEventData();

	x = GetEventData();
	y = GetEventData();
	z = GetEventData();

	// CreateBlast(x,y,z);
	// CreateParticleSystem("blast_inv",x,y,z,0.0,0.0,0.0,0);
	CreateParticleSystem("blast", x, y, z, 0.0, 0.0, 0.0, 0);
	//SendMessage(&AIFort,"llfff",AI_MESSAGE_FORT_HIT,iCharacterIndex,x,y,z);
}

void Ball_OnFlyUpdate()
{
	int charIndex = GetEventData();
	int ballAlive = GetEventData();
	float x = GetEventData();
	float y = GetEventData();
	float z = GetEventData();
	float lx = GetEventData();
	float ly = GetEventData();
	float lz = GetEventData();
	SendMessage(&SeaOperator, "lalffffff", MSG_SEA_OPERATOR_BALL_UPDATE, &Characters[charIndex], ballAlive, x, y, z, lx, ly, lz);
}
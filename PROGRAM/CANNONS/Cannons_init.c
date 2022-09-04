void InitBaseCannons_CalcSpeedV0(ref rCannon, float fFireRange)
{
	rCannon.FireRange = fFireRange;
	rCannon.SpeedV0 = sqrt(fFireRange * 9.81 / sin( 2.0 * MakeFloat(rCannon.FireAngMax)) );
	//rCannon.ReloadTime = sti(rCannon.ReloadTime) / 6;
	//Trace("Fire range = " + rCannon.FireRange + ", SpeedV0 = " + rCannon.SpeedV0);
}

void InitCannons()
{
	ref rCannon;
	
	makeref(rCannon,Cannon[CANNON_TYPE_CULVERINE_LBS12]);
	rCannon.type = CANNON_NAME_CULVERINE;
	rCannon.caliber = 12;
	rCannon.ReloadTime = 20;
	rCannon.Cost = 1200;
	rCannon.Weight = 27;
	rCannon.FireAngMax = 0.60;
	rCannon.FireAngMin = -0.35;
	rCannon.DamageMultiply = 1.0;
	InitBaseCannons_CalcSpeedV0(&rCannon,500.0);

	makeref(rCannon,Cannon[CANNON_TYPE_CULVERINE_LBS16]);
	rCannon.type = CANNON_NAME_CULVERINE;
	rCannon.caliber = 16;
	rCannon.ReloadTime = 24;
	rCannon.Cost = 1600;
	rCannon.Weight = 42;
	rCannon.FireAngMax = 0.60;
	rCannon.FireAngMin = -0.35;
	rCannon.DamageMultiply = 2;
	InitBaseCannons_CalcSpeedV0(&rCannon,450.0);

	makeref(rCannon,Cannon[CANNON_TYPE_CULVERINE_LBS24]);
	rCannon.type = CANNON_NAME_CULVERINE;
	rCannon.caliber = 24;
	rCannon.ReloadTime = 30;
	rCannon.Cost = 2000;
	rCannon.Weight = 51;
	rCannon.FireAngMax = 0.60;
	rCannon.FireAngMin = -0.35;
	rCannon.DamageMultiply = 4;
	InitBaseCannons_CalcSpeedV0(&rCannon,400.0);

	makeref(rCannon,Cannon[CANNON_TYPE_CANNON_LBS12]);
	rCannon.type = CANNON_NAME_CANNON;
	rCannon.caliber = 12;
	rCannon.ReloadTime = 12;
	rCannon.Cost = 1000;
	rCannon.Weight = 20;
	rCannon.FireAngMax = 0.60;
	rCannon.FireAngMin = -0.35;
	rCannon.DamageMultiply = 1.0;
	InitBaseCannons_CalcSpeedV0(&rCannon,350.0);

	makeref(rCannon,Cannon[CANNON_TYPE_CANNON_LBS16]);
	rCannon.type = CANNON_NAME_CANNON;
	rCannon.caliber = 16;
	rCannon.ReloadTime = 20;
	rCannon.Cost = 1300;
	rCannon.Weight = 30;
	rCannon.FireAngMax = 0.60;
	rCannon.FireAngMin = -0.35;
	rCannon.DamageMultiply = 2.5;
	InitBaseCannons_CalcSpeedV0(&rCannon,300.0);

	makeref(rCannon,Cannon[CANNON_TYPE_CANNON_LBS24]);
	rCannon.type = CANNON_NAME_CANNON;
	rCannon.caliber = 24;
	rCannon.ReloadTime = 24;
	rCannon.Weight = 38;
	rCannon.Cost = 1650;
	rCannon.FireAngMax = 0.60;
	rCannon.FireAngMin = -0.35;
	rCannon.DamageMultiply = 4;
	InitBaseCannons_CalcSpeedV0(&rCannon,260.0);

	makeref(rCannon,Cannon[CANNON_TYPE_CANNON_LBS32]);
	rCannon.type = CANNON_NAME_SPECIAL_CANNON;
	rCannon.caliber = 32;
	rCannon.ReloadTime = 40;
	rCannon.Cost = 3500;
	rCannon.Weight = 72;
	rCannon.FireAngMax = 0.60;
	rCannon.FireAngMin = -0.35;
	rCannon.DamageMultiply = 3.0;
	rCannon.TradeOff = true;
	InitBaseCannons_CalcSpeedV0(&rCannon,600.0);
}

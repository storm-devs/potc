void Ship_BortFire()
{
	float	dx, dy, dz, d2x, d2y, d2z;
	aref	firedShip;
	string	bortName;

	ref rCharacter = GetCharacter(GetEventData());
	firedShip = GetEventData();
	bortName = GetEventData();
	dx = GetEventData();
	dy = GetEventData();
	dz = GetEventData();
	d2x = GetEventData();
	d2y = GetEventData();
	d2z = GetEventData();

	if (sti(rCharacter.index) == GetMainCharacterIndex())
		ballNumber = 0;
	SendMessage(&SeaOperator, "lisffffff", MSG_SEA_OPERATOR_FIRE, firedShip, bortName, dx, dy, dz, d2x, d2y, d2z);
}
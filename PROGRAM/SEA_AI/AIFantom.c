#define INVALID_SHIP_TYPE			-1

ref Fantom_GetNextFantom()
{
	iNumFantoms++;
	return &Characters[FANTOM_CHARACTERS + iNumFantoms];
}

int Fantom_GenerateEncounter(string sGroupName, object oResult, int iEType) 
{
	aref	aWar, aMerchant;
	ref		rEnc;
	int		i, iNumMerchantShips, iNumWarShips;
	int		iWarClassMax, iWarClassMin, iMerchantClassMax, iMerchantClassMin;

	ref rCharacter = GetMainCharacter();

	makeref(rEnc, EncountersTypes[iEType]);
	makearef(aWar, rEnc.War);
	makearef(aMerchant, rEnc.Merchant);

	iNumMerchantShips = MakeInt(aMerchant.ShipsMin) + rand(MakeInt(aMerchant.ShipsMax) - MakeInt(aMerchant.ShipsMin));
	iNumWarShips = MakeInt(aWar.ShipsMin) + rand(MakeInt(aWar.ShipsMax) - MakeInt(aWar.ShipsMin));
	
	int iRank = sti(rCharacter.Rank);
	Encounter_GetClassesFromRank(iEType, iRank, &iMerchantClassMin, &iMerchantClassMax, &iWarClassMin, &iWarClassMax);
	// 
	/*iWarClassMax = MakeInt(aWar.ClassMax);
	iWarClassMin = MakeInt(aWar.ClassMin);
	iMerchantClassMax = MakeInt(aMerchant.ClassMax);
	iMerchantClassMin = MakeInt(aMerchant.ClassMin);*/

	//Trace("class max = " + iMerchantClassMax + ", class min = " + iMerchantClassMin);

	int iFantomIndex, iShipType;

	//Trace("iNumMerchants = " + iNumMerchantShips);
	//Trace("iNumWars = " + iNumWarShips);

	for (i=0; i<iNumMerchantShips; i++)
	{
		iShipType = Fantom_GetShipType(iMerchantClassMin, iMerchantClassMax, "Merchant");
		if (iShipType == INVALID_SHIP_TYPE) continue;
		//Trace("Merchant ship class = " + ShipsTypes[iShipType].Class + ", name = " + ShipsTypes[iShipType].Name);
		Fantom_AddFantomCharacter(sGroupName, iShipType, "Trade", iEType);
	}

	for (i=0; i<iNumWarShips; i++)
	{
		iShipType = Fantom_GetShipType(iWarClassMin, iWarClassMax, "War");
		if (iShipType == INVALID_SHIP_TYPE) continue;
		//Trace("War ship class = " + ShipsTypes[iShipType].Class + ", name = " + ShipsTypes[iShipType].Name);
		Fantom_AddFantomCharacter(sGroupName, iShipType, "War", iEType);
	}

	return iNumWarShips + iNumMerchantShips;
}

int Fantom_GetShipType(int iClassMin, int iClassMax, string sShipType)
{
	int iShips[512];		// must be careful!!!!
	int i, iShipsNum;

	iShipsNum = 0;

	for (i=0; i<SHIP_TYPES_QUANTITY; i++)
	{
		object rShip = GetShipByType(i);
		int iClass = MakeInt(rShip.Class);
		if (iClass > iClassMin) { continue; }
		if (iClass < iClassMax) { continue; }
		if (sti(rShip.CanEncounter) != true) { continue; }
		if (sti(rShip.Type.(sShipType)) != 1) {  continue; }
		iShips[iShipsNum] = i;
		iShipsNum++;
	}
	if (iShipsNum==0) 
	{
		Trace("Can't find ship type '" + sShipType + "' with ClassMin = " + iClassMin + " and ClassMax = " + iClassMax);
		return INVALID_SHIP_TYPE;
	}
	return iShips[rand(iShipsNum - 1)];
}

// return new added fantom character
void Fantom_AddFantomCharacter(string sGroupName, int iShipType, string sFantomType, int iEncounterType)
{
	ref rFantom = GetFantomCharacter(iNumFantoms);

	DeleteAttribute(rFantom, "relation");

	rFantom.SeaAI.Group.Name = sGroupName;
	rFantom.Ship.Type = iShipType;
	rFantom.Ship.Mode = sFantomType;
	rFantom.Charge.Type = GOOD_BALLS;
	iNumFantoms++;
}

void Fantom_SetRandomMoney(ref rFantom, string sFantomType)
{
	// clear money from character
	rFantom.Money = 0;

	// ship class
	int iSClass = GetCharacterShipClass(rFantom);

	// add money 
	switch (sFantomType)
	{
		case "trade":
			rFantom.Money = (10 - iSClass) * 1000 + rand((10 - iSClass) * 5000);
			return;
		break;
		case "war":
			rFantom.Money = (10 - iSClass) * 100 + rand((10 - iSClass) * 500);
			return;
		break;
		case "pirate":
			rFantom.Money = (10 - iSClass) * 500 + rand((10 - iSClass) * 2000);
			return;
		break;
	}
	//Trace("Fantom index = " + rFantom.index + ", group id = " + rFantom.SeaAI.Group.Name + ", have invalid encounter type = " + sFantomType);
}

int Fantom_CalcSkill(ref rMainCharacter, string sSkill, int iShipClass, int iSkillMin, int iSkillMax, int iSClass1, int iSClass2, int iSClass3, int iSClass4, int iSClass5, int iSClass6, int iSClass7)
{
	int iSkill = GetSummonSkillFromName(rMainCharacter, sSkill);
	//Trace("iSkill = " + iSkill + ", sSkill = " + sSkill);
	iSkill = iSkill + iSkillMin + rand(iSkillMax - iSkillMin);
	switch (iShipClass)
	{
		case 1: iSkill = iSkill + iSClass1; break;
		case 2: iSkill = iSkill + iSClass2; break;
		case 3: iSkill = iSkill + iSClass3; break;
		case 4: iSkill = iSkill + iSClass4; break;
		case 5: iSkill = iSkill + iSClass5; break;
		case 6: iSkill = iSkill + iSClass6; break;
		case 7: iSkill = iSkill + iSClass7; break;
	}

	if (iSkill < 1)			iSkill = 1;
	if (iSkill > SKILL_MAX) iSkill = SKILL_MAX;

	return iSkill;
}

void Fantom_SetRandomSkills(ref rFantom, string sFantomType)
{
	ref rCharacter = GetMainCharacter();

	aref aFSkills; makearef(aFSkills, rFantom.Skill);

	int iSClass = GetCharacterShipClass(rFantom);

	switch (sFantomType)
	{
		case "trade":
			aFSkills.Leadership = Fantom_CalcSkill(rCharacter, SKILL_LEADERSHIP,iSClass, -3, 0, 0, 0, 0, 0, 0, 0, 0);
			aFSkills.Accuracy	= Fantom_CalcSkill(rCharacter, SKILL_ACCURACY,	iSClass, -3, 1, 0, 0, 0, 0, 0, 0, 0);
			aFSkills.Commerce	= Fantom_CalcSkill(rCharacter, SKILL_COMMERCE,	iSClass, -1, 3, 0, 0, 0, 0, 0, 0, 0);
			aFSkills.Cannons	= Fantom_CalcSkill(rCharacter, SKILL_CANNONS,	iSClass, -3, 1, 0, 0, 0, 0, 0, 0, 0);
			aFSkills.Grappling	= Fantom_CalcSkill(rCharacter, SKILL_GRAPPLING, iSClass, -3, 0, 0, 0, 0, 0, 0, 0, 0);
			aFSkills.Fencing	= Fantom_CalcSkill(rCharacter, SKILL_FENCING,	iSClass, -3, 1, 0, 0, 0, 0, 0, 0, 0);
			aFSkills.Repair		= Fantom_CalcSkill(rCharacter, SKILL_REPAIR,	iSClass, -2, 2, 0, 0, 0, 0, 0, 0, 0);
			aFSkills.Sailing	= Fantom_CalcSkill(rCharacter, SKILL_SAILING,	iSClass, -2, 2, 3, 2, 1, 0, 0, 0, 0);
			aFSkills.Sneak		= Fantom_CalcSkill(rCharacter, SKILL_SNEAK,		iSClass, -2, 2, 0, 0, 0, 0, 0, 0, 0);
			aFSkills.Defence	= Fantom_CalcSkill(rCharacter, SKILL_DEFENCE,	iSClass, -2, 2, 3, 2, 1, 0, 0, 0, 0);
			return;
		break;
		case "war":
			aFSkills.Leadership = Fantom_CalcSkill(rCharacter, SKILL_LEADERSHIP,iSClass, -1, 3, 0, 0, 0, 0, 0, 0, 0);
			aFSkills.Accuracy	= Fantom_CalcSkill(rCharacter, SKILL_ACCURACY,	iSClass, -3, 2, 0, 0, 0, 0, 0, 0, 0);
			aFSkills.Commerce	= Fantom_CalcSkill(rCharacter, SKILL_COMMERCE,	iSClass, -3, 1, 0, 0, 0, 0, 0, 0, 0);
			aFSkills.Cannons	= Fantom_CalcSkill(rCharacter, SKILL_CANNONS,	iSClass, -2, 2, 0, 0, 0, 0, 0, 0, 0);
			aFSkills.Grappling	= Fantom_CalcSkill(rCharacter, SKILL_GRAPPLING, iSClass, -2, 2, 0, 0, 0, 0, 0, 0, 0);
			aFSkills.Fencing	= Fantom_CalcSkill(rCharacter, SKILL_FENCING,	iSClass, -2, 2, 3, 2, 1, 0, 0, 0, 0);
			aFSkills.Repair		= Fantom_CalcSkill(rCharacter, SKILL_REPAIR,	iSClass, -2, 2, 0, 0, 0, 0, 0, 0, 0);
			aFSkills.Sailing	= Fantom_CalcSkill(rCharacter, SKILL_SAILING,	iSClass, -2, 2, 3, 2, 1, 0, 0, 0, 0);
			aFSkills.Sneak		= Fantom_CalcSkill(rCharacter, SKILL_SNEAK,		iSClass, -2, 2, 0, 0, 0, 0, 0, 0, 0);
			aFSkills.Defence	= Fantom_CalcSkill(rCharacter, SKILL_DEFENCE,	iSClass, -2, 2, 0, 0, 0, 0, 0, 0, 0);
			return;
		break;
		case "pirate":
			aFSkills.Leadership = Fantom_CalcSkill(rCharacter, SKILL_LEADERSHIP,iSClass, -2, 2, 3, 2, 1, 0, 0, 0, 0);
			aFSkills.Accuracy	= Fantom_CalcSkill(rCharacter, SKILL_ACCURACY,	iSClass, -2, 2, 3, 2, 1, 0, 0, 0, 0);
			aFSkills.Commerce	= Fantom_CalcSkill(rCharacter, SKILL_COMMERCE,	iSClass, -3, 1, 0, 0, 0, 0, 0, 0, 0);
			aFSkills.Cannons	= Fantom_CalcSkill(rCharacter, SKILL_CANNONS,	iSClass, -2, 2, 0, 0, 0, 0, 0, 0, 0);
			aFSkills.Grappling	= Fantom_CalcSkill(rCharacter, SKILL_GRAPPLING, iSClass, -1, 3, 0, 0, 0, 0, 0, 0, 0);
			aFSkills.Fencing	= Fantom_CalcSkill(rCharacter, SKILL_FENCING,	iSClass, -1, 3, 0, 0, 0, 0, 0, 0, 0);
			aFSkills.Repair		= Fantom_CalcSkill(rCharacter, SKILL_REPAIR,	iSClass, -3, 1, 0, 0, 0, 0, 0, 0, 0);
			aFSkills.Sailing	= Fantom_CalcSkill(rCharacter, SKILL_SAILING,	iSClass, -2, 2, 0, 0, 0, 0, 0, 0, 0);
			aFSkills.Sneak		= Fantom_CalcSkill(rCharacter, SKILL_SNEAK,		iSClass, -2, 2, 0, 0, 0, 0, 0, 0, 0);
			aFSkills.Defence	= Fantom_CalcSkill(rCharacter, SKILL_DEFENCE,	iSClass, -1, 3, 0, 0, 0, 0, 0, 0, 0);
			return;
		break;
	}
	Trace("Fantom index = " + rFantom.index + ", group id = " + rFantom.SeaAI.Group.Name + ", have invalid encounter type = " + sFantomType);
}

void Fantom_SetCannons(ref rFantom, string sFantomType)
{
	int iSClass = GetCharacterShipClass(rFantom);
	ref rShip = GetShipByType(GetCharacterShipType(rFantom));

	int iCannonsType = sti(rShip.Cannon);
	string sCannonType = "cannon";
	int iCaliber = sti(rShip.MaxCaliber);

	switch (sFantomType)
	{
		case "trade":
			sCannonType = "culverine";
		break;
		case "war":
			if (rand(1) == 1) { sCannonType = "culverine"; }
		break;
		case "pirate":
			if (iSClass == 6) { sCannonType = "culverine"; }
		break;
	}

	if (sti(rShip.Cannon) == CANNON_TYPE_NONECANNON)
	{
		rFantom.Ship.Cannons.Type = CANNON_TYPE_NONECANNON;
		return;
	}

	//Trace("sCannonType = " + sCannonType);
	rFantom.Ship.Cannons.Type = GetCannonByTypeAndCaliber(sCannonType, iCaliber);
}

void Fantom_SetSails(ref rFantom, string sFantomType)
{
	rFantom.Ship.Sails.Gerald = false;
	if (sFantomType == "war") rFantom.Ship.Sails.Gerald = true;
}

void Fantom_SetBalls(ref rFantom, string sFantomType)
{
	float fKBalls = 1.5 * (7 - GetCharacterShipClass(rFantom));

	switch (sFantomType)
	{
		case "war":
			fKBalls = fKBalls * 1.5;
		break;
		case "trade":
			fKBalls = fKBalls * 0.7;
		break;
		case "pirate":
			fKBalls = fKBalls * 2.0;
		break;
	}

	Fantom_SetCharacterGoods(rFantom, GOOD_BALLS, MakeInt(150 * fKBalls + rand(250 * fKBalls)));
	Fantom_SetCharacterGoods(rFantom, GOOD_BOMBS, MakeInt(100 * fKBalls + rand(200 * fKBalls)));
	Fantom_SetCharacterGoods(rFantom, GOOD_KNIPPELS, MakeInt(100 * fKBalls + rand(50 * fKBalls)));
	Fantom_SetCharacterGoods(rFantom, GOOD_GRAPES, MakeInt(130 * fKBalls + rand(140 * fKBalls)));
}

void Fantom_SetGoods(ref rFantom, string sFantomType)
{
	int iMultiply = 10;
	int iRandMultiply = 1;

	int iShipClass = 7 - GetCharacterShipClass(rFantom); 
	
	switch (sFantomType)
	{
		case "war":
		break;
		case "trade":
			iMultiply = 10 * (rand(iShipClass) + 1);
			iRandMultiply = 2 + rand(iShipClass);
		break;
		case "pirate":
			iMultiply = 5 * (rand(iShipClass / 2) + 1);
			iRandMultiply = 1 + rand(iShipClass / 2);
		break;
	}

	int iStart = GOOD_BOMBS + 1;

	Fantom_SetCharacterGoods(rFantom, iStart + rand(GOODS_QUANTITY - iStart - 1), iMultiply * rand(iRandMultiply * 3));
	Fantom_SetCharacterGoods(rFantom, iStart + rand(GOODS_QUANTITY - iStart - 1), iMultiply * rand(iRandMultiply * 3));
	Fantom_SetCharacterGoods(rFantom, iStart + rand(GOODS_QUANTITY - iStart - 1), iMultiply * rand(iRandMultiply * 3));
	Fantom_SetCharacterGoods(rFantom, iStart + rand(GOODS_QUANTITY - iStart - 1), iMultiply * rand(iRandMultiply * 3));
	Fantom_SetCharacterGoods(rFantom, iStart + rand(GOODS_QUANTITY - iStart - 1), iMultiply * rand(iRandMultiply * 3));
	Fantom_SetCharacterGoods(rFantom, iStart + rand(GOODS_QUANTITY - iStart - 1), iMultiply * rand(iRandMultiply * 3));
	Fantom_SetCharacterGoods(rFantom, iStart + rand(GOODS_QUANTITY - iStart - 1), iMultiply * rand(iRandMultiply * 3));

	RecalculateCargoLoad(rFantom);
}

void Fantom_SetCharacterGoods(ref rFantom, int iGoods, int iQuantity)
{
	if (iQuantity == 0) { return; }

	string sGood = Goods[iGoods].name;
	int iFreeQuantity = GetGoodQuantityByWeight( iGoods, GetCargoFreeSpace(rFantom) );
	if (iFreeQuantity < 0) { iFreeQuantity = 0; }

	if (iQuantity <= iFreeQuantity) { rFantom.Ship.Cargo.Goods.(sGood) = iQuantity; }
							else	{ rFantom.Ship.Cargo.Goods.(sGood) = iFreeQuantity;	}
	
	RecalculateCargoLoad(rFantom);
}

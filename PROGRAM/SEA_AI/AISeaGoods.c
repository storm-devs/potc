object	AISeaGoods;

void DeleteSeaGoodsEnvironment()
{
	DeleteClass(&AISeaGoods);

	DelEventHandler(SHIP_DEAD, "AISeaGoods_ShipDead");
}

void CreateSeaGoodsEnvironment()
{
	CreateEntity(&AISeaGoods, "AISeaGoods");
	
	LayerAddObject(SEA_EXECUTE, &AISeaGoods, -1);
	LayerAddObject(SEA_REALIZE, &AISeaGoods, 65532);

	SetEventHandler(SHIP_DEAD, "AISeaGoods_ShipDead", 0);
	SetEventHandler(SHIP_EAT_SWIM_GOOD, "AISeaGoods_ShipEatGood", 0);

	AISeaGoods.ModelsPath = "SwimGoods";
	AISeaGoods.DeleteGoodAnyway = true;
	AISeaGoods.DistanceMultiply = 0.5;
}

void AISeaGoods_ShipDead()
{
	ref rCharacter = GetCharacter(GetEventData());

	aref aGoods; makearef(aGoods, rCharacter.Ship.Cargo.Goods);
	for (int i=0; i<GetAttributesNum(aGoods); i++)
	{
		aref aGood = GetAttributeN(aGoods, i);
		int	iQuantity = sti(GetAttributeValue(aGood));
		ref	rGood = GetGoodByID(GetAttributeName(aGood));

		if (!CheckAttribute(rGood, "Swim")) { continue; }
		
		iQuantity = iQuantity / sti(rGood.Units);
		if (iQuantity <= 1) { continue; }

		if (rand(100) > 90) { continue; }

		int iSwimQuantity = 0; 
		while (iSwimQuantity == 0) { iSwimQuantity = MakeInt(iQuantity / 4 + rand(MakeInt(iQuantity * 2 / 4))); }
		float fTime = stf(rGood.Swim.Time);
		string sModel = rGood.Swim.Model;

		fTime = fTime + (frnd() - 0.5) * fTime / 2.0;

		AISeaGoods_AddGood(rCharacter, GetAttributeName(aGood), sModel, fTime * 60.0, iSwimQuantity);
	}
}

void AISeaGoods_AddGood(ref rCharacter, string sGood, string sModel, float fTime, int iQuantity)
{
	if (!bSeaActive) return;

	Trace("Add good : " + sGood + ", rCharacter.id = " + rCharacter.id + ", iQuantity = " + iQuantity);

	// calculate random position
		float fAng = stf(rCharacter.Ship.Ang.y);
		float x = (frnd() - 0.5) * 20.0;
		float z = (frnd() - 0.5) * 40.0;
		RotateAroundY(&x, &z, cos(fAng), sin(fAng));

	AISeaGoods.Good = sGood;
	AISeaGoods.Pos.x = stf(rCharacter.Ship.Pos.x) + x;
	AISeaGoods.Pos.z = stf(rCharacter.Ship.Pos.z) + z;
	AISeaGoods.CharIndex = rCharacter.Index;
	AISeaGoods.Time = fTime;
	AISeaGoods.Quantity = iQuantity;
	AISeaGoods.Model = sModel;
	AISeaGoods.Add = "";
}

bool AISeaGoods_ShipEatGood()
{
	object oRes;

	int iCharacterIndex = GetEventData();
	int iGoodCharacterIndex = GetEventData();
	string sGood = GetEventData();
	int iQuantity = GetEventData();

	ref rCharacter = GetCharacter(iCharacterIndex);

	if (iGoodCharacterIndex == iCharacterIndex) return false;
	if (LAi_IsDead(rCharacter)) return false;

	ref rShip = GetShipByType(sti(rCharacter.Ship.Type));
	ref rGood = GetGoodByID(sGood);

	int iLoad = sti(rCharacter.Ship.Cargo.Load);
	int iCapacity = sti(rShip.Capacity);
	int iGoodWeight = sti(rGood.Weight);
	int iGoodUnits = sti(rGood.Units);

	int iMaxGoodAllow = (iCapacity - iLoad) / iGoodWeight;

	string sGoodName = LanguageConvertString(iSeaSectionLang, "seg_" + sGood);

	if (iMaxGoodAllow == 0)
	{
		string sShipCantGotGood = LanguageConvertString(iSeaSectionLang, "Ship_cant_got_good");
		Event(PARSE_STRING, "asls", &oRes, sShipCantGotGood, 1, sGoodName);
		Log_SetStringToLog(oRes.Str);
		return false;
	}

	if (iQuantity > iMaxGoodAllow) iQuantity = iMaxGoodAllow;

	if (iCharacterIndex == GetMainCharacterIndex())
	{
		string sGoodQuantity = iQuantity * iGoodWeight;
		string sShipGotGood = LanguageConvertString(iSeaSectionLang, "Ship_got_good");
		Event(PARSE_STRING, "aslss", &oRes, sShipGotGood, 2, sGoodQuantity, sGoodName);
		Log_SetStringToLog(oRes.Str);
	}

	AddCharacterGoods(rCharacter, FindGood(sGood), iQuantity * iGoodUnits);
	return true;
}
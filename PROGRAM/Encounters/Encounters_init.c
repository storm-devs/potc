void Enc_ExcludeNation(ref rEnc, int iNation)
{
	string sNation = Nations[iNation].Name;
	rEnc.Nation.Exclude.(sNation) = true;
}

void Enc_AddShips(ref rEnc, string sEType, int iShipsMin, int iShipsMax)
{
	rEnc.(sEType).ShipsMin = iShipsMin;		rEnc.(sEType).ShipsMax = iShipsMax;
}

void Enc_AddClasses(ref rEnc, int iRank, int iMClassMin, int iMClassMax, int iWClassMin, int iWClassMax)
{
	string sRank = "Rank." + iRank;
	rEnc.(sRank).0 = iMClassMin; rEnc.(sRank).1 = iMClassMax;
	rEnc.(sRank).2 = iWClassMin; rEnc.(sRank).3 = iWClassMax;
}

void InitEncounters()
{
	int i;
	ref rEnc;

	for (i=0; i<MAX_ENCOUNTER_TYPES; i++)
	{
		makeref(rEnc, EncountersTypes[i]);
		rEnc.Index = i;
		rEnc.Chance = 100;
		rEnc.Skip = false;
		rEnc.MinRank = 1;
		rEnc.MaxRank = 1000;
		rEnc.Merchant.ShipsMin = 0;		rEnc.Merchant.ShipsMax = 0;
		rEnc.War.ShipsMin = 0;			rEnc.War.ShipsMax = 0;
		rEnc.Type = ENCOUNTER_TRADE;
	}

	// ======================== TRADE ENCOUNTERS ========================

	// small merchant
		makeref(rEnc, EncountersTypes[ENCOUNTER_TYPE_MERCHANT0]);	// 3 + 0
		rEnc.Type = ENCOUNTER_TRADE;
		rEnc.MinRank = 1;
		Enc_AddShips(rEnc, "Merchant", 1, 3);
		Enc_ExcludeNation(rEnc, PIRATE);

		Enc_AddClasses(rEnc, 1, 5, 6, 0, 0);
		Enc_AddClasses(rEnc, 2, 5, 6, 0, 0);
		Enc_AddClasses(rEnc, 3, 4, 6, 0, 0);
		Enc_AddClasses(rEnc, 4, 4, 6, 0, 0);
		Enc_AddClasses(rEnc, 5, 3, 6, 0, 0);
		Enc_AddClasses(rEnc, 6, 3, 6, 0, 0);
		Enc_AddClasses(rEnc, 7, 3, 6, 0, 0);
		Enc_AddClasses(rEnc, 8, 3, 5, 0, 0);
		Enc_AddClasses(rEnc, 9, 3, 5, 0, 0);
		Enc_AddClasses(rEnc, 10,3, 5, 0, 0);

	// 
		makeref(rEnc, EncountersTypes[ENCOUNTER_TYPE_MERCHANT1]);	// 2 + 1
		rEnc.Type = ENCOUNTER_TRADE;
		rEnc.MinRank = 3;
		Enc_AddShips(rEnc, "Merchant", 2, 3);
		Enc_AddShips(rEnc, "War", 1, 1);
		Enc_ExcludeNation(rEnc, PIRATE);

		Enc_AddClasses(rEnc, 3, 4, 6, 4, 6);
		Enc_AddClasses(rEnc, 4, 4, 6, 4, 6);
		Enc_AddClasses(rEnc, 5, 3, 6, 3, 5);
		Enc_AddClasses(rEnc, 6, 3, 6, 3, 5);
		Enc_AddClasses(rEnc, 7, 3, 6, 2, 4);
		Enc_AddClasses(rEnc, 8, 3, 5, 2, 4);
		Enc_AddClasses(rEnc, 9, 3, 5, 2, 4);
		Enc_AddClasses(rEnc, 10,3, 5, 2, 4);

	// 
		makeref(rEnc, EncountersTypes[ENCOUNTER_TYPE_MERCHANT2]);	// 1 + 3
		rEnc.Type = ENCOUNTER_TRADE;
		rEnc.MinRank = 4;
		Enc_AddShips(rEnc, "Merchant", 1, 1);
		Enc_AddShips(rEnc, "War", 2, 3);
		Enc_ExcludeNation(rEnc, PIRATE);

		Enc_AddClasses(rEnc, 4, 4, 5, 3, 5);
		Enc_AddClasses(rEnc, 5, 4, 5, 3, 5);
		Enc_AddClasses(rEnc, 6, 3, 5, 2, 5);
		Enc_AddClasses(rEnc, 7, 3, 5, 2, 5);
		Enc_AddClasses(rEnc, 8, 3, 5, 2, 4);
		Enc_AddClasses(rEnc, 9, 3, 5, 2, 4);
		Enc_AddClasses(rEnc, 10,3, 5, 2, 4);

	// ======================== WAR ENCOUNTERS ========================
		makeref(rEnc, EncountersTypes[ENCOUNTER_TYPE_PATROL]);	// 0 + 3
		rEnc.Type = ENCOUNTER_WAR;
		rEnc.MinRank = 2;
		Enc_AddShips(rEnc, "War", 1, 3);

		Enc_AddClasses(rEnc, 3, 0, 0, 5, 6);
		Enc_AddClasses(rEnc, 4, 0, 0, 4, 6);
		Enc_AddClasses(rEnc, 5, 0, 0, 4, 6);
		Enc_AddClasses(rEnc, 6, 0, 0, 3, 5);
		Enc_AddClasses(rEnc, 7, 0, 0, 3, 5);
		Enc_AddClasses(rEnc, 8, 0, 0, 2, 4);
		Enc_AddClasses(rEnc, 9, 0, 0, 2, 4);
		Enc_AddClasses(rEnc, 10,0, 0, 2, 4);

	// 
		makeref(rEnc, EncountersTypes[ENCOUNTER_TYPE_FLEET]);	// 0 + 4
		rEnc.Type = ENCOUNTER_WAR;
		rEnc.MinRank = 5;
		Enc_AddShips(rEnc, "War", 3, 4);
		Enc_ExcludeNation(rEnc, PIRATE);

		Enc_AddClasses(rEnc, 5, 0, 0, 2, 4);
		Enc_AddClasses(rEnc, 6, 0, 0, 1, 4);
		Enc_AddClasses(rEnc, 7, 0, 0, 1, 4);
		Enc_AddClasses(rEnc, 8, 0, 0, 1, 3);
		Enc_AddClasses(rEnc, 9, 0, 0, 1, 3);
		Enc_AddClasses(rEnc, 10,0, 0, 1, 2);

	// 
		makeref(rEnc, EncountersTypes[ENCOUNTER_TYPE_CORSAR]);	// 0 + 3
		Enc_AddShips(rEnc, "War", 1, 3);
		rEnc.MinRank = 3;
		rEnc.Type = ENCOUNTER_WAR;

		Enc_AddClasses(rEnc, 3, 0, 0, 4, 6);
		Enc_AddClasses(rEnc, 4, 0, 0, 4, 6);
		Enc_AddClasses(rEnc, 5, 0, 0, 3, 5);
		Enc_AddClasses(rEnc, 6, 0, 0, 3, 5);
		Enc_AddClasses(rEnc, 7, 0, 0, 2, 4);
		Enc_AddClasses(rEnc, 8, 0, 0, 2, 4);
		Enc_AddClasses(rEnc, 9, 0, 0, 2, 4);
		Enc_AddClasses(rEnc, 10,0, 0, 2, 4);

	// 
		makeref(rEnc, EncountersTypes[ENCOUNTER_TYPE_PIRATE]);	// 0 + 2
		Enc_AddShips(rEnc, "War", 1, 2);
		rEnc.MinRank = 1;
		rEnc.MaxRank = 3;
		rEnc.Type = ENCOUNTER_WAR;
		rEnc.Chance = 80;

		Enc_AddClasses(rEnc, 1, 0, 0, 6, 6);
		Enc_AddClasses(rEnc, 2, 0, 0, 5, 6);
		Enc_AddClasses(rEnc, 3, 0, 0, 5, 6);

	// Punitive squadron
		makeref(rEnc, EncountersTypes[ENCOUNTER_TYPE_PUNITIVE_SQUADRON]);	// 0 + 2
		Enc_AddShips(rEnc, "War", 2, 3);
		rEnc.Skip = true;
		rEnc.MinRank = 1;
		rEnc.Type = ENCOUNTER_WAR;
		Enc_ExcludeNation(rEnc, PIRATE);

		Enc_AddClasses(rEnc, 1, 0, 0, 5, 6);
		Enc_AddClasses(rEnc, 2, 0, 0, 5, 5);
		Enc_AddClasses(rEnc, 3, 0, 0, 4, 5);
		Enc_AddClasses(rEnc, 4, 0, 0, 4, 4);
		Enc_AddClasses(rEnc, 5, 0, 0, 3, 5);
		Enc_AddClasses(rEnc, 6, 0, 0, 3, 4);
		Enc_AddClasses(rEnc, 7, 0, 0, 3, 3);
		Enc_AddClasses(rEnc, 8, 0, 0, 2, 3);
		Enc_AddClasses(rEnc, 9, 0, 0, 2, 2);
		Enc_AddClasses(rEnc, 10, 0, 0, 1, 2);

	Trace("Init encounters complete.");
}
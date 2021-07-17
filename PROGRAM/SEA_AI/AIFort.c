#include "sail_msg.h"

#define		MAX_FORTS						16
#define		MIN_CANNON_DAMAGE_DISTANCE		20.0

object		AIFort;
object		Forts[MAX_FORTS];
object		FortsBlots[MAX_FORTS];
int			iNumForts = 0;

void DeleteFortEnvironment()
{
	if (isEntity(&AIFort)) { DeleteClass(&AIFort); }
	for (int i=0; i<iNumForts; i++)
	{
		DeleteClass(&Forts[i]);
		DeleteClass(&FortsBlots[i]);
	}
	iNumForts = 0;
}

void CreateFortEnvironment()
{
	iNumForts = 0;

	SetEventHandler(FORT_CANNON_DAMAGE, "Fort_CannonDamage", 0);
	SetEventHandler(FORT_CREATE, "Fort_CreateEvent", 0);
}

int Fort_FindCharacter(string sLocationID, string sLocationGroup, string sLocationLocator)
{
	for (int i=0; i<MAX_CHARACTERS; i++)
	{
		if (Characters[i].location == sLocationID) 
		{
			if (Characters[i].location.group == sLocationGroup) 
			{
				if (Characters[i].location.locator == sLocationLocator) 
				{
					return i;
				}
			}
		}
	}
	return -1;
}

int Fort_GetDeadDays(ref rCharacter)
{
	int		iDYear = sti(rCharacter.Fort.DieTime.Year);
	int		iDMonth = sti(rCharacter.Fort.DieTime.Month);
	int		iDDay = sti(rCharacter.Fort.DieTime.Day);
	float	fTime = stf(rCharacter.Fort.DieTime.Time);
	
	return GetPastTime("day", iDYear, iDMonth, iDDay, fTime, GetDataYear(), GetDataMonth(), GetDataDay(), GetTime());
}

void Fort_Login(int iIslandIndex)
{
	// search fort's in current island
	ref rIsland = GetIslandByIndex(iIslandIndex);
	aref arReload; makearef(arReload,rIsland.reload);
	int iNumReloads = GetAttributesNum(arReload);
	for (int i=0; i<iNumReloads; i++)
	{
		aref arLocator = GetAttributeN(arReload,i);
		ReloadProgressUpdate();
		if (CheckAttribute(arLocator,"fort"))
		{
			if (!CheckAttribute(arLocator,"fort.model") || arLocator.fort.model == "")
			{
				Trace("Island.id = " + rIsland.id + ", and reload." + GetAttributeName(arLocator) + ", doesn't have fort.model value.");
				continue;
			}
			CreateEntity(&Forts[iNumForts], "MODELR");
			string sFortModel = rIsland.filespath.models + "\" + arLocator.fort.model;
			SendMessage(&Forts[iNumForts], "ls", MSG_MODEL_SET_LIGHT_PATH, GetLightingPath());
			SendMessage(&Forts[iNumForts], "ls", MSG_MODEL_LOAD_GEO, sFortModel);
			LayerAddObject(SEA_REALIZE, &Forts[iNumForts], 10000);
			LayerAddObject("fort_cannon_trace", &Forts[iNumForts], 1);
			SendMessage(SeaLighter, "ssi", "AddModel", arLocator.fort.model, &Forts[iNumForts]);
			iNumForts++;

			int iFortCharacter = Fort_FindCharacter(rIsland.id, "reload", arLocator.name);
			if (iFortCharacter < 0)
			{
				Trace("FortLogin: Can't find character for fort: '" + arLocator.name + "', on island with id: '" + rIsland.id + "'");
				continue;
			}
			if (isEntity(&AIFort) == 0)
			{
				CreateEntity(&AIFort, "AIFort");
				LayerAddObject(SEA_EXECUTE, &AIFort, 2);
				LayerAddObject(SEA_REALIZE, &AIFort, -1);
			}
			// Add fort to AIFort
			ref rCharacter = GetCharacter(iFortCharacter);

			int iFortMode = FORT_NORMAL;
			if (CheckAttribute(rCharacter, "Fort.Mode"))
			{
				iFortMode = sti(rCharacter.Fort.Mode);
			}

			bool	bFortRessurect = false;
			int		iDeadDays = 0;
			switch (iFortMode)
			{
				case FORT_NORMAL:
				break;
				case FORT_ABORDAGE:
					iDeadDays = Fort_GetDeadDays(rCharacter);
					if (iDeadDays >= 3) { bFortRessurect = true; }
				break;
				case FORT_DEAD:
					iDeadDays = Fort_GetDeadDays(rCharacter);
					if (iDeadDays >= 7) { bFortRessurect = true; }
				break;
			}

			if (iDeadDays > 0) 
			{ 
				rCharacter.Ship.Crew.Quantity = iDeadDays * 200 + rand(100); 
			}

			if (bFortRessurect)
			{
				SetFortCharacterCaptured(rCharacter, false);
				iFortMode = FORT_NORMAL;
				rCharacter.Ship.Crew.Quantity = 900 + rand(600);
			}

			rCharacter.Fort.Mode = iFortMode;
			rCharacter.Fort.PlayerDamage = 0.0;								// player damage

			Event("eSwitchPerks", "l", iFortCharacter);							// Perks
			Ship_UpdateTmpSkills(rCharacter);

			Fort_CheckAttributes(rCharacter);

			AIFort.MinCannonDamageDistance = MIN_CANNON_DAMAGE_DISTANCE;		// in meters
			rCharacter.Ship.Crew.MinRatio = 1.0;
			rCharacter.Ship.Name = arLocator.fortname;
			rCharacter.Ship.Type = SHIP_FORT;
			SetCharacterGoods(rCharacter, GOOD_BOMBS, 34000);
	
			// create fort blot
			CreateEntity(&FortsBlots[iNumForts - 1], "blots");
			SendMessage(&FortsBlots[iNumForts - 1], "lia", MSG_BLOTS_SETMODEL, &Forts[iNumForts - 1], rCharacter);
			LayerAddObject(SEA_EXECUTE, &Forts[iNumForts], 10001);
			LayerAddObject(SEA_REALIZE, &Forts[iNumForts], 10001);
			
			SendMessage(&AIFort, "laaaii", AI_MESSAGE_ADD_FORT, rIsland, arLocator, rCharacter, &Forts[iNumForts-1], &FortsBlots[iNumForts-1]);

			// flags
			int iNation = sti(rCharacter.nation);
			ref rNation = GetNationByType(iNation);
			
			SendMessage(&Flag, "lil", MSG_FLAG_INIT, &Forts[iNumForts - 1], iNation); // install flag on fort
			//Trace("Character with id: '" + rCharacter.id + "' and nation: '" + rNation.Name + "', assigned to fort: '" + arLocator.name + "'");
			ReloadProgressUpdate();
		}
	}
}

void Fort_CreateEvent()
{
	int		iCannonsNum;
	aref	rCharacter;

	rCharacter = GetEventData();
	iCannonsNum = GetEventData();

	rCharacter.Fort.Cannons.Quantity = iCannonsNum;

	rCharacter.Ship.HP = iCannonsNum * 100;
	rCharacter.Fort.HP = rCharacter.Ship.HP;
}

int Fort_GetCannonsQuantity(ref rFortCharacter)
{
	if (!CheckAttribute(rFortCharacter, "Fort.Cannons.Quantity")) { return 0; }
	return sti(rFortCharacter.Fort.Cannons.Quantity);
}

float Fort_CannonDamage()
{
	float	x, y, z;
	aref	aFortLabel;
	ref		rBallCharacter, rFortCharacter;
	int		iNumAllCannons, iNumDamagedCannons;
	int		iExp = 0;
	float	fDistance, fDamage;

	int iBallCharacterIndex = GetEventData();
	int iFortCharacterIndex = GetEventData();

	rBallCharacter = GetCharacter(iBallCharacterIndex);
	rFortCharacter = GetCharacter(iFortCharacterIndex);

	aFortLabel = GetEventData();

	iNumAllCannons = GetEventData();
	iNumDamagedCannons = GetEventData();
	x = GetEventData();
	y = GetEventData();
	z = GetEventData();
	fDistance = GetEventData();	// distance to cannon
	fDamage = GetEventData();	// current cannon damage 0.0% .. 100.0%

	if (iBallCharacterIndex == iFortCharacterIndex) { return fDamage; }

	int iCompanionQuantity = GetCompanionQuantity(rBallCharacter);

	int iFortMode = sti(rFortCharacter.Fort.Mode);
	if (iFortMode != FORT_NORMAL) { return fDamage; }

	float fDistanceMul = pow(0.035, fDistance / MIN_CANNON_DAMAGE_DISTANCE);

	ref rCannon = GetCannonByType(sti(rBallCharacter.Ship.Cannons.Type));
	float fCannonDamageMultiply = stf(rCannon.DamageMultiply) * fDistanceMul;

	ref rBall = GetGoodByType(sti(AIBalls.CurrentBallType));

	//CreateParticleSystem("blast",x,y,z,0.0,0.0,0.0,0);
	
	float fHullDamage = stf(rBall.DamageHull) * fCannonDamageMultiply * 0.4;
	float fCrewDamage = stf(rBall.DamageCrew) * fCannonDamageMultiply;

	rFortCharacter.Ship.HP = (1.0 - MakeFloat(iNumDamagedCannons) / MakeFloat(iNumAllCannons)) * stf(rFortCharacter.Fort.HP);
	rFortCharacter.Ship.Crew.Quantity = stf(rFortCharacter.Ship.Crew.Quantity) - fCrewDamage;
	if (sti(rFortCharacter.Ship.Crew.Quantity) < 10) rFortCharacter.Ship.Crew.Quantity = 10;

	float fDamagePiece = fHullDamage + (frnd() - 0.5) * fHullDamage * 0.4;
	fDamage = fDamage + fDamagePiece;
	
	if (iBallCharacterIndex == GetMainCharacterIndex())
	{
		int iRelation = SeaAI_GetRelation(iFortCharacterIndex, iBallCharacterIndex);
		if (iRelation != RELATION_ENEMY)
		{
			float fCurPlayerDamage = stf(rFortCharacter.Fort.PlayerDamage);

			if (iRelation == RELATION_FRIEND)	{ fCurPlayerDamage = fCurPlayerDamage + fDamagePiece * 0.8; }
			if (iRelation == RELATION_NEUTRAL)	{ fCurPlayerDamage = fCurPlayerDamage + fDamagePiece * 0.5; }

			if (fCurPlayerDamage >= 100.0)
			{
				SetCharacterRelationBoth(iBallCharacterIndex, iFortCharacterIndex, RELATION_ENEMY);
				SetNationRelation2MainCharacter(sti(rFortCharacter.Nation), RELATION_ENEMY);
				UpdateRelations();
			}

			rFortCharacter.Fort.PlayerDamage = fCurPlayerDamage;
		}
	}
	//AddCharacterExp(rBallCharacter, MakeInt(fHullDamage));
	bool bImmortal = LAi_IsImmortal(rFortCharacter);
	if (fDamage >= 100.0) 
	{ 
		Play3DSound("fort_cann_explode", x, y, z);
		CreateBlast(x, y, z);
		CreateParticleSystem("blast_inv", x, y, z, 0.0, 0.0, 0.0, 0);
		CreateParticleSystem("blast", x, y, z, 0.0, 0.0, 0.0, 0);

		if (!bImmortal)
		{
			iNumDamagedCannons++;
			fDamage = 100.0;

			switch (rand(1))
			{
				case 0:
					CreateParticleSystem("fort_fire", x, y, z, -1.57, 0.0, 0.0, 0);
					CreateParticleSystem("fort_smoke", x, y, z, -1.57, 0.0, 0.0, 0);
				break;
				case 1:
					CreateParticleSystem("fort_fire", x, y, z, -1.57, 0.0, 0.0, 0);
					CreateParticleSystem("fort_gray_smoke", x, y, z, -1.57, 0.0, 0.0, 0);
				break;
			}
		}
		else
		{
			fDamage = 0.0;
		}

		iExp = MakeInt(1000 / iCompanionQuantity);
		if (iBallCharacterIndex == GetMainCharacterIndex())
		{
			object oRes;
			string sCannonString = LanguageConvertString(iSeaSectionLang, "Fort_cannon");
			string sExp = iExp;

			Event(PARSE_STRING, "asls", &oRes, sCannonString, 1, sExp);
			Log_SetStringToLog(oRes.Str);
		}
		AddCharacterExp(rBallCharacter, iExp);
	}

	if (iNumDamagedCannons >= iNumAllCannons / 2)
	{
		Fort_SetAbordageMode(rBallCharacter, rFortCharacter);
	}

	return fDamage;
}

void Fort_SetAbordageMode(ref rKillerCharacter, ref rFortCharacter)
{
	// open for abordage
	rFortCharacter.Fort.Mode = FORT_ABORDAGE;

	// data of frot die
	rFortCharacter.Fort.DieTime.Year = GetDataYear();
	rFortCharacter.Fort.DieTime.Month = GetDataMonth();
	rFortCharacter.Fort.DieTime.Day = GetDataDay();
	rFortCharacter.Fort.DieTime.Time = GetTime();

	Event(FORT_DESTROYED, "l", sti(rFortCharacter.index));
	int iExp = 20000;
	AddCharacterExp(rKillerCharacter, iExp);

	// Fort destroy log
		object oRes;
		string sFortName = XI_ConvertString(rFortCharacter.Ship.Name);
		string sFortString = LanguageConvertString(iSeaSectionLang, "Fort_destroy");
		string sExp = iExp;

		Event(PARSE_STRING, "aslss", &oRes, sFortString, 2, sFortName, sExp);
		Log_SetStringToLog(oRes.Str);
}

void Fort_SetCharacter(ref rCharacter, string sIslandID, string sLocationGroup, string sLocationLocator)
{
	int iCharacterIndex = Fort_FindCharacter(sIslandID, sLocationGroup, sLocationLocator);
	if (iCharacterIndex != -1)
	{
		ChangeCharacterAddress(&Characters[iCharacterIndex], "None", "");
	}

	ChangeCharacterAddressGroup(rCharacter, sIslandID, sLocationGroup, sLocationLocator);

	rCharacter.Ship.Type = SHIP_FORT;

	Fort_CheckAttributes(rCharacter);
}

void Fort_CheckAttributes(ref rCharacter)
{
	if (!CheckAttribute(rCharacter, "Ship.Cannons.Type")) { rCharacter.Ship.Cannons.Type = CANNON_TYPE_CULVERINE_LBS24; }
	
	if (!CheckAttribute(rCharacter, "Ship.Cannons.Charge.Type")) { rCharacter.Ship.Cannons.Charge.Type = GOOD_BOMBS; }
	if (!CheckAttribute(rCharacter, "Fort.Cannons.Type.1")) { rCharacter.Fort.Cannons.Type.1 = CANNON_TYPE_CULVERINE_LBS24; }
	if (!CheckAttribute(rCharacter, "Fort.Cannons.Type.2")) { rCharacter.Fort.Cannons.Type.2 = CANNON_TYPE_CANNON_LBS32; }
}
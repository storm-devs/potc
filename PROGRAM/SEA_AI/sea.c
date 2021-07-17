#include "sea_ai\Script_defines.h"
#include "sea_ai\SeaPeople.h"

#include "sea_ai\AIGroup.c"
#include "sea_ai\AIShip.c"
#include "sea_ai\AIFort.c"
#include "sea_ai\AISea.c"
#include "sea_ai\AICameras.c"
#include "sea_ai\AIAbordage.c"
#include "sea_ai\AIFantom.c"
#include "sea_ai\AICannon.c"
#include "sea_ai\AIBalls.c"
#include "sea_ai\AIIsland.c"
#include "sea_ai\AISeaGoods.c"
#include "sea_ai\AITasks\AITasks.c"

#include "sea_ai\ShipBortFire.c"
#include "sea_ai\ShipDead.c"
#include "sea_ai\ShipWalk.c"

#include "sea_ai\Telescope.c"

#include "battle_interface\BattleInterface.c"

#event_handler("Sea_FirstInit", "Sea_FirstInit");

#define PLAYER_GROUP	"OurGroup"

string	sCurrentSeaExecute = EXECUTE;
string	sCurrentSeaRealize = REALIZE;

int		iAITemplatesNum;
bool	bSeaActive;
bool 	bSkipSeaLogin = false;
bool	bIslandLoaded = false;
bool	bSeaReloadStarted = false;
bool	bNotEnoughBalls;
bool	bStorm, bTornado;
bool	bSeaQuestGroupHere = false;

int		iStormLockSeconds = 0;

object	Island, IslandReflModel;
object	Touch, AISea;
object	SeaFader;
object	Seafoam, BallSplash, SinkEffect, PeopleOnShip, Telescope, SeaOperator, Artifact;
object	Sharks;
object	SeaLighter;

object	SeaLocatorShow;
object	LoginGroupsNow;
bool	bSeaShowLocators = true;
bool	bQuestDisableMapEnter = false;
bool	bFromCoast = false;

float	SeaMapLoadX = -1570.99;
float	SeaMapLoadZ = 950.812;
float	SeaMapLoadAY = 10.54;

float	fSeaExp = 0.0;
float	fSeaExpTimer = 0.0;

int	iSeaSectionLang = -1;

void DeleteSeaEnvironment()
{
	ref rPlayer = GetMainCharacter();

	StopMusic();
	bSeaActive = false;
	sCurrentSeaExecute = "execute";
	sCurrentSeaRealize = "realize";

	rPlayer.Ship.Stopped = true;
	DeleteBattleInterface();

	DelEventHandler(SHIP_BORT_FIRE, "Ship_BortFire");
	DelEventHandler(BALL_FLY_UPDATE, "Ball_OnFlyUpdate");

	SendMessage(&AISea, "l", AI_MESSAGE_UNLOAD);

	DeleteSea();

	DeleteClass(&Island);
	DeleteClass(&IslandReflModel);
	DeleteClass(&Touch);
	DeleteClass(&Seafoam);
	DeleteClass(&BallSplash);
	DeleteClass(&SinkEffect);
	DeleteClass(&PeopleOnShip);
	DeleteClass(&SeaLocatorShow);
	DeleteClass(&SeaOperator);
	DeleteClass(&Telescope);
	DeleteClass(&Sharks);

	DeleteClass(&SeaLighter);

	if (IsEntity(&Artifact))
		DeleteClass(&Artifact);

	DeleteBallsEnvironment();
	DeleteCannonsEnvironment();
	DeleteSeaCamerasEnvironment();
	DeleteShipEnvironment();
	DeleteFortEnvironment();
	DeleteAbordageEnvironment();
	DeleteSeaGoodsEnvironment();

	DeleteWeatherEnvironment();

	DeleteAttribute(&AISea,"");

	LayerFreeze(SEA_EXECUTE, true);
	LayerFreeze(SEA_REALIZE, true);

	LayerFreeze(REALIZE, false);
	LayerFreeze(EXECUTE, false);

	DeleteClass(&AISea);

	DeleteAnimals();
	
	// delete masts fall modules
		DeleteEntitiesByType("mast");

	// delete particle system
		DeleteParticles();

	// delete our group
		Group_DeleteGroup(PLAYER_GROUP);

	// delete fantom and dead groups
		Group_DeleteUnusedGroup();

	// 
		LanguageCloseFile(iSeaSectionLang); iSeaSectionLang = -1;

	//
		Encounter_DeleteDeadQuestMapEncounters();

}

void CreateSeaEnvironment()
{
	sCurrentSeaExecute = SEA_EXECUTE;
	sCurrentSeaRealize = SEA_REALIZE;

	iSeaSectionLang = LanguageOpenFile("SeaSection.txt");

	CreateParticleEntity();

	Ship_Walk_Init();

	LayerFreeze(REALIZE, true);
	LayerFreeze(EXECUTE, true);
	LayerFreeze(SEA_REFLECTION, false);

	InterfaceStates.Buttons.Resume.enable = true;
	
	bSeaActive = true;

	LayerFreeze(SEA_EXECUTE, false);
	LayerFreeze(SEA_REALIZE, false);

	CreateSea(SEA_EXECUTE, SEA_REALIZE);			ReloadProgressUpdate();
	CreateWeather(SEA_EXECUTE, SEA_REALIZE);		ReloadProgressUpdate();
	
	CreateEntity(&AISea, "sea_ai");					ReloadProgressUpdate();
	LayerAddObject(SEA_EXECUTE, &AISea, 1);
	LayerAddObject(SEA_REALIZE, &AISea, -1);

	CreateEntity(&Touch, "touch");					ReloadProgressUpdate();
	LayerAddObject(SEA_EXECUTE, &Touch, 1);
	Touch.CollisionDepth = -10.0;
	//LayerAddObject(SEA_REALIZE, &Touch, -1);		// for collision debug

	CreateEntity(&BallSplash, "BallSplash");		ReloadProgressUpdate();
	LayerAddObject(SEA_EXECUTE, &BallSplash, -1);
	LayerAddObject(SEA_REALIZE, &BallSplash, 65535);

	CreateEntity(&SinkEffect, "SINKEFFECT");		ReloadProgressUpdate();
	LayerAddObject(SEA_EXECUTE, &SinkEffect, 65531);
	LayerAddObject(SEA_REALIZE, &SinkEffect, 65531);

	CreateEntity(&PeopleOnShip, "PEOPLE_ON_SHIP");	ReloadProgressUpdate();
	LayerAddObject(SEA_EXECUTE, &PeopleOnShip, 100);
	LayerAddObject(SEA_REALIZE, &PeopleOnShip, 100);

	CreateEntity(&SeaLocatorShow, "SeaLocatorShow"); ReloadProgressUpdate();
	LayerAddObject(SEA_REALIZE, &SeaLocatorShow, -1);

	CreateEntity(&Telescope, "TELESCOPE");			ReloadProgressUpdate();
	LayerAddObject(SEA_EXECUTE, &Telescope, -1);
	LayerAddObject(SEA_REALIZE, &Telescope, -3);
	TelescopeInitParameters(&Telescope);

	CreateSeaAnimals();								ReloadProgressUpdate();

	// create all other environment
	CreateBallsEnvironment();						ReloadProgressUpdate();
	CreateCannonsEnvironment();						ReloadProgressUpdate();
	CreateSeaCamerasEnvironment();					ReloadProgressUpdate();
	CreateShipEnvironment();						ReloadProgressUpdate();
	CreateFortEnvironment();						ReloadProgressUpdate();
	CreateAbordageEnvironment();					ReloadProgressUpdate();
	CreateSeaGoodsEnvironment();					ReloadProgressUpdate();

	SetEventHandler(SHIP_CREATE, "Ship_Walk_Create", 0);
	SetEventHandler("MSG_TELESCOPE_REQUEST", "Telescope_Request", 0);
	SetEventHandler(SHIP_BORT_FIRE, "Ship_BortFire", 0);

	bNotEnoughBalls = false;

	Sharks.execute = SEA_EXECUTE;
	Sharks.realize = SEA_REALIZE;
	Sharks.executeModels = 75;
	Sharks.realizeModels = 75;
	Sharks.executeParticles = 78;
	Sharks.realizeParticles = 100001;

	CreateEntity(&Sharks, "Sharks");				ReloadProgressUpdate();

	PeopleOnShip.isNight = Whr_IsNight();
}

void Sea_LandLoad()
{
	bSeaReloadStarted = true;
	PauseAllSounds();
	ResetSoundScheme();

	if (bSeaActive == false) return;
	if (bCanEnterToLand == true)
	{
		LayerFreeze(REALIZE, false);
		LayerFreeze(EXECUTE, false);
		Reload(arIslandReload, sIslandLocator, sIslandID);
	}
}

void Sea_MapStartFade()
{
	DelEventHandler("FaderEvent_StartFade", "Sea_MapStartFade");
	DeleteSeaEnvironment();
}

void Sea_MapEndFade()
{
	DelEventHandler("FaderEvent_EndFade", "Sea_MapEndFade");

	wdmCreateMap(SeaMapLoadX, SeaMapLoadZ, SeaMapLoadAY);
}

void Sea_MapLoadXZ_AY(float x, float z, float ay)
{
	Sea_MapLoad();

	SeaMapLoadX = x;
	SeaMapLoadZ = z;
	SeaMapLoadAY = ay;
}

void Sea_MapLoad()
{
	bSeaReloadStarted = true;
	PauseAllSounds();

	ResetSoundScheme();

	SetEventHandler("FaderEvent_StartFade", "Sea_MapStartFade", 0);
	SetEventHandler("FaderEvent_EndFade", "Sea_MapEndFade", 0);

	CreateEntity(&SeaFader, "fader");
	SendMessage(&SeaFader, "lfl", FADER_OUT, 0.7, true);
	SendMessage(&SeaFader, "l", FADER_STARTFRAME);
	SendMessage(&SeaFader, "ls", FADER_PICTURE, "loading\sea.tga");

	bSkipSeaLogin = true;

	ref rPlayer = GetMainCharacter();

	SeaMapLoadX = stf(rPlayer.Ship.Pos.x);
	SeaMapLoadZ = stf(rPlayer.Ship.Pos.z);
	SeaMapLoadAY = stf(rPlayer.Ship.Ang.y);
}

string	sTaskList[2];

void Sea_FreeTaskList()
{
	ref rMassive; 
	makeref(rMassive, sTaskList);
	SetArraySize(rMassive, 2);
}

void Sea_AddGroup2TaskList(string sGroupID)
{
	ref rMassive; 
	makeref(rMassive, sTaskList);
	int iSize = GetArraySize(rMassive);
	SetArraySize(rMassive, iSize + 1);
	sTaskList[iSize-2] = sGroupID;
}

void Sea_LoginGroupNow(string sGroupID)
{
	LoginGroupsNow.QuestGroups = "";
	aref arGroups; makearef(arGroups, LoginGroupsNow.QuestGroups);
	string sID = "n" + GetAttributesNum(arGroups);
	arGroups.(sID) = sGroupID;
}


void SeaLogin(ref Login)
{
	int		i, j, iShipType;
	float	x, y, z, ay;
	ref		rCharacter, rGroup, rEncounter;
	aref	rRawGroup;
	aref	arQCGroups; 
	string	sGName;
	int		iNumQCGroups;

	int iRDTSC = RDTSC_B();

	// clear load groups now object
	DeleteAttribute(&LoginGroupsNow, "");

	iStormLockSeconds = 0;
	iNumFantoms = 0;
	bSkipSeaLogin = false;
	bSeaReloadStarted = false;
	bSeaQuestGroupHere = false;
	bIslandLoaded = false;

	fSeaExp = 0.0;
	fSeaExpTimer = 0.0;

	Sea_FreeTaskList();	
	Encounter_DeleteDeadQuestMapEncounters();

	// weather parameters
		WeatherParams.Tornado = false; 
		WeatherParams.Storm = false; 
		if (CheckAttribute(&Login,"Storm")) { WeatherParams.Storm = Login.Storm; } 
		if (CheckAttribute(&Login,"Tornado")) { WeatherParams.Tornado = Login.Tornado; } 
		bStorm = sti(WeatherParams.Storm);
		bTornado = sti(WeatherParams.Tornado); 
		if (bStorm)
		{
			iStormLockSeconds = 60;
		}

	// Island
		int iIslandIndex = FindIsland(Login.Island);
		//Trace("Island id = " + Login.Island + ", Island index = " + iIslandIndex);
		string sIslandID = "";
		if (iIslandIndex != -1) { sIslandID = Islands[iIslandIndex].id; }

	// main character
		ref rPlayer = GetMainCharacter();
		rPlayer.Ship.Stopped = false;
		rPlayer.Ship.POS.Mode = SHIP_SAIL;
		rPlayer.location = sIslandID;

	// clear old fantom relations in our character
		if (CheckAttribute(rPlayer, "Relation"))
		{
			aref	arRelations; makearef(arRelations, rPlayer.Relation);
			int		iNumRelations = GetAttributesNum(arRelations);
			for (i=0; i<iNumRelations; i++)
			{
				aref arRelation = GetAttributeN(arRelations, i);
				string sRName = GetAttributeName(arRelation);
				if (sti(sRName) >= FANTOM_CHARACTERS)
				{
					DeleteAttribute(arRelations, sRName);
					iNumRelations--;
					i--;
				}
			}
		}

	// Quest check
		Event(EVENT_SEA_LOGIN, "");
		if (bSkipSeaLogin) return;

	// Sea Fader start
		if (!CheckAttribute(&Login,"ImageName")) { Login.ImageName = "loading\sea.tga"; }

		CreateEntity(&SeaFader, "fader");
		SendMessage(&SeaFader, "lfl", FADER_IN, 0.5, true);
		SendMessage(&SeaFader, "ls", FADER_PICTURE0, Login.ImageName);

	// create all sea modules
		CreateSeaEnvironment();

	// delete our group
		Group_DeleteGroup(PLAYER_GROUP);

	// set commander to group
		Group_SetGroupCommander(PLAYER_GROUP, Characters[GetMainCharacterIndex()].id);

	// set our group position
		Group_SetXZ_AY(PLAYER_GROUP, stf(Login.PlayerGroup.x), stf(Login.PlayerGroup.z), stf(Login.PlayerGroup.ay) );
		//Trace("Set group : " + PLAYER_GROUP + ", x = " + Login.PlayerGroup.x + ", z = " + Login.PlayerGroup.z + ", ay = " + Login.PlayerGroup.ay);

	Sea.MaxSeaHeight = 50.0;

	ReloadProgressUpdate();

	// login island if exist
		if (sIslandID != "")
		{
			CreateEntity(&Island, "Island");
			Island.LightingPath = GetLightingPath();

			if (GetTargetPlatform() != "xbox") 
			{ 
				//CreateEntity(&SeaLighter, "lighter"); 
				SendMessage(&SeaLighter, "ss", "ModelsPath", Islands[iIslandIndex].filespath.models);
				SendMessage(&SeaLighter, "ss", "LightPath", GetLightingPath());
			}

			SendMessage(&Island, "lsss", MSG_ISLAND_LOAD_GEO, "islands", Islands[iIslandIndex].filespath.models, Islands[iIslandIndex].model);
			LayerAddObject(SEA_REALIZE, &Island, 65529);
			LayerAddObject("mast_island_trace", &Island, 1);
			LayerAddObject("sun_trace", &Island, 1);

			CreateEntity(&IslandReflModel, "MODELR");
			string sReflModel = Islands[iIslandIndex].filespath.models + "\" + Islands[iIslandIndex].refl_model;
			SendMessage(&IslandReflModel, "ls", MSG_MODEL_SET_LIGHT_PATH, GetLightingPath());
			SendMessage(&IslandReflModel, "ls", MSG_MODEL_LOAD_GEO, sReflModel);
			LayerAddObject("sea_reflection", &IslandReflModel, -1);
			SendMessage(SeaLighter, "ssi", "AddModel", Islands[iIslandIndex].refl_model, &IslandReflModel);
			
			bIslandLoaded = true;

			SendMessage(&SeaLocatorShow, "a", &Islands[iIslandIndex]);

			Fort_Login(iIslandIndex);

			Sea.MaxSeaHeight = 3.0;
		} 
		AISea.Island = sIslandID;

	// clear some of group attributes
		for (i=0; i<MAX_SHIP_GROUPS; i++) 
		{
			rGroup = Group_GetGroupByIndex(i);
			if (CheckAttribute(rGroup, "AlreadyLoaded")) { DeleteAttribute(rGroup, "AlreadyLoaded"); }
		}

	ReloadProgressUpdate();

	// from coast check (move / stop)
		bFromCoast = false;
		if (CheckAttribute(&Login, "FromCoast")) { bFromCoast = sti(Login.FromCoast); }

	// login main player and his friends
		int iMainCharacter,iCompanionIndex;
		iMainCharacter = GetMainCharacterIndex();

		rPlayer.SeaAI.Group.Name = PLAYER_GROUP;
		rPlayer.Ship.Type = Characters[iMainCharacter].Ship.Type;
		rPlayer.Ship.Stopped = false;
		Ship_Add2Sea(iMainCharacter, bFromCoast, "");
		Group_AddCharacter(PLAYER_GROUP, Characters[iMainCharacter].id);
		for (i=1; i<COMPANION_MAX; i++)
		{
			iCompanionIndex = GetCompanionIndex(&Characters[iMainCharacter],i);
			if (iCompanionIndex == -1) { continue; }
			Characters[iCompanionIndex].SeaAI.Group.Name = PLAYER_GROUP;
			Ship_Add2Sea(iCompanionIndex, bFromCoast, "");

			// add companion to player group
			Group_AddCharacter(PLAYER_GROUP, Characters[iCompanionIndex].id);
		}
	
	// set ship for sea camera
		SeaCameras_SetShipForSeaCamera(&rPlayer);

	// login encounters
		object oResult;
		int iFantomIndex;

	// login quest group if island exist
		ReloadProgressUpdate();
		if (sIslandID != "")
		{
			for (i=0; i<MAX_SHIP_GROUPS; i++) 
			{
				rGroup = Group_GetGroupByIndex(i);
				if (!CheckAttribute(rGroup,"AlreadyLoaded")) { DeleteAttribute(rGroup,"AlreadyLoaded");	}

				if (!CheckAttribute(rGroup, "id")) { continue; }
				if (!CheckAttribute(rGroup, "location")) { continue; }
				if (rGroup.location != sIslandID) { continue; }

				Sea_LoginGroup(rGroup.id);
			}
		}

	// login quest groups to sea 
		if (CheckAttribute(&Login, "QuestGroups"))
		{
			arQCGroups; makearef(arQCGroups, Login.QuestGroups);
			iNumQCGroups = GetAttributesNum(arQCGroups);
			for (i=0; i<iNumQCGroups; i++)
			{
				Sea_LoginGroup(GetAttributeValue(GetAttributeN(arQCGroups, i)));
			}
		}

		ReloadProgressUpdate();

	// login quest groups to sea from LoginGroupsNow object
		if (CheckAttribute(&LoginGroupsNow, "QuestGroups"))
		{
			makearef(arQCGroups, LoginGroupsNow.QuestGroups);
			iNumQCGroups = GetAttributesNum(arQCGroups);
			for (i=0; i<iNumQCGroups; i++)
			{
				Sea_LoginGroup(GetAttributeValue(GetAttributeN(arQCGroups, i)));
			}
		}

		ReloadProgressUpdate();

	// login fantom groups
		aref arEncounters;
		makearef(arEncounters,Login.Encounters);
		int iNumGroups = GetAttributesNum(arEncounters);

		for (i=0; i<iNumGroups; i++)
		{
			rRawGroup = GetAttributeN(arEncounters, i);
			rEncounter = GetMapEncounterRef(sti(rRawGroup.type));
			sGName = rEncounter.GroupName;

			x = stf(rRawGroup.x);
			z = stf(rRawGroup.z);
			ay = stf(rRawGroup.ay);

			ReloadProgressUpdate();

			// check for Quest fantom
			if (CheckAttribute(rEncounter, "qID"))
			{
				Trace("SEA: Login quest encounter " + rEncounter.qID);
				Group_SetAddressNone(rEncounter.qID);
				Group_SetXZ_AY(rEncounter.qID, x, z, ay);
				Sea_LoginGroup(rEncounter.qID);
				
				continue;
			}

			if (bSeaQuestGroupHere) { continue; }

			Sea_AddGroup2TaskList(sGName);

			rGroup = Group_GetGroupByIndex(Group_CreateGroup(sGName));
			Group_SetXZ_AY(sGName, x, z, ay);
			Group_SetType(sGName, rEncounter.Type);
			Group_DeleteAtEnd(sGName);

			// copy task attributes from map encounter to fantom group
			if (CheckAttribute(rEncounter, "Task"))							{ rGroup.Task = rEncounter.Task; }
			if (CheckAttribute(rEncounter, "Task.Target"))					{ rGroup.Task.Target = rEncounter.Task.Target; }
			if (CheckAttribute(rEncounter, "Task.Pos")) 
			{
				rGroup.Task.Target.Pos.x = rEncounter.Task.Pos.x;
				rGroup.Task.Target.Pos.z = rEncounter.Task.Pos.z;
			}
			if (CheckAttribute(rEncounter, "Lock") && sti(rEncounter.Lock)) { Group_LockTask(sGName); }

			int iEncounterType = sti(rEncounter.RealEncounterType);
			int iNumShips = Fantom_GenerateEncounter(sGName, &oResult, iEncounterType);

			//Trace("Set group : " + sGName + ", x = " + x + ", z = " + z);

			// load ship to sea
			if (iNumShips) 
			{
				for (j=0; j<iNumShips; j++)
				{
					iFantomIndex = FANTOM_CHARACTERS + iNumFantoms - iNumShips + j;
					ref rFantom = &Characters[iFantomIndex];

					rFantom.id = "fenc_" + iFantomIndex;

					// set commander to group
					if (j==0) { Group_SetGroupCommander(sGName, Characters[iFantomIndex].id); }
					
					// set random character and ship names, face id
					rFantom.sex = "man";
					rFantom.Nation = rEncounter.Nation; 
					
					SetRandomNameToCharacter(rFantom);
					SetRandomNameToShip(rFantom);
					SetRandomFaceToCharacter(rFantom);
					
					Fantom_SetRandomSkills(rFantom, rEncounter.Type);
					Fantom_SetRandomMoney(rFantom, rEncounter.Type);
					Fantom_SetCannons(rFantom, rEncounter.Type);
					Fantom_SetSails(rFantom, rEncounter.Type);

					rFantom.SeaAI.Group.Name = sGName;
					rFantom.Experience = 0;
					rFantom.Skill.FreeSkill = 0;

					rFantom.Features.GeraldSails = false;
					if (CheckAttribute(rEncounter, "GeraldSails")) { rFantom.Features.GeraldSails = sti(rEncounter.GeraldSails); }

					int iSClass = GetCharacterShipClass(rFantom);

					rFantom.Rank = MakeInt(sti(rPlayer.rank) + rand(4) - 2 + (7 - iSClass) / 2);
					if (sti(rFantom.Rank) < 1) { rFantom.Rank = 1; }

					// restore fantom HP
					LAi_SetHP(rFantom, LAI_DEFAULT_HP_MAX, 50.0 + stf(rFantom.rank) * 3.0);
					LAi_SetCurHPMax(rFantom);

					// add fantom
					Group_AddCharacter(sGName, rFantom.id);
					
					// add to sea
					Ship_Add2Sea(iFantomIndex, 0, rEncounter.Type);
				}
			}
		}
		
	ReloadProgressUpdate();

	// set tasks 2 all groups
	for (i=0; i<GetArraySize(&sTaskList)-2; i++)
	{
		string sGroupID = sTaskList[i];

		rGroup = Group_GetGroupByID(sGroupID);
		
		// set task 
		switch (sti(rGroup.Task))
		{
			case AITASK_RUNAWAY:
				Group_SetTaskRunAway(sGroupID);
			break;
			case AITASK_ATTACK:
				Group_SetTaskAttack(sGroupID, rGroup.Task.Target);
			break;
			case AITASK_MOVE:
				if (CheckAttribute(rGroup, "Task.Target.Pos"))
				{
					Group_SetTaskMove(sGroupID, stf(rGroup.Task.Target.Pos.x), stf(rGroup.Task.Target.Pos.z));
				}
				else
				{
					x = 10000.0 * sin(stf(rGroup.Pos.ay));
					z = 10000.0 * cos(stf(rGroup.Pos.ay));
					Group_SetTaskMove(sGName, x, z);
				}
			break;
		}
		
		rCharacter = Group_GetGroupCommanderR(rGroup);
		int iRelation = GetRelation(GetMainCharacterIndex(), sti(rCharacter.index));

		// set relations to all characters in this group
		i = 0;
		while (true)
		{
			int iCharacterIndex = Group_GetCharacterIndexR(rGroup, i); i++;
			if (iCharacterIndex < 0) { break; }
			SetCharacterRelationBoth(iCharacterIndex, GetMainCharacterIndex(), iRelation);
		}
	}

	// update AISea 
	AISea.isDone = "";
	
	InitBattleInterface();							ReloadProgressUpdate();
	StartBattleInterface();							ReloadProgressUpdate();
	RefreshBattleInterface();						ReloadProgressUpdate();
	
	CreateEntity(&Seafoam,"Seafoam");				ReloadProgressUpdate();
	LayerAddObject(SEA_EXECUTE, &Seafoam, -1);
	LayerAddObject(SEA_REALIZE, &Seafoam, -1);
	if (Whr_IsStorm()) { Seafoam.storm = "true"; }

	/*CreateEntity(&SeaOperator, "SEA_OPERATOR");
	LayerAddObject(SEA_EXECUTE, &SeaOperator, -1);
	LayerAddObject(SEA_REALIZE, &SeaOperator, 3);*/
   	
	SendMessage(&Telescope, "leee", MSG_TELESCOPE_INIT_ARRAYS, &Nations, &ShipsTypes, &Goods);

	PostEvent(SHIP_CHECK_RELOAD_ENABLE, 100);
	
	SetSchemeForSea();								ReloadProgressUpdate();

	iRDTSC = RDTSC_E(iRDTSC);
	//Trace("SeaLogin RDTSC = " + iRDTSC);
	//Trace("iNumShips = " + iNumShips);

	PostEvent("Sea_FirstInit", 100);
}

void Sea_LoginGroup(string sGroupID)
{
	if (!isEntity(&Sea)) { Trace("Error: Sea_LoginGroup sGroupID = " + sGroupID + ", but Sea is not active!"); return; }

	if (Group_FindGroup(sGroupID) < 0)
	{
		Trace("Not find group '" + sGroupID + "' in groups massive, but login try spotted");
		return;
	}

	ref rGroup = Group_GetGroupByID(sGroupID); 
	if (!CheckAttribute(rGroup, "Quest"))			{ Trace("Error: Sea_LoginGroup sGroupID = " + sGroupID + ", but group doesn't contain any quest ships!"); return; }
	if (CheckAttribute(rGroup, "AlreadyLoaded"))	{ Trace("Error: Group sGroupID = " + sGroupID + ", already loaded... check for duplicate group login"); return; }

	aref arQuestShips; makearef(arQuestShips, rGroup.Quest);

	int iNumShips = GetAttributesNum(arQuestShips);
	if (iNumShips == 0) { return; }

	float x, z, ay; x = 0.0; z = 0.0; ay = 0.0;

	// find group position
	if (CheckAttribute(rGroup, "location") && CheckAttribute(rGroup, "location.group") && rGroup.location != "none")
	{
		string sLocationGroup = rGroup.location.group;
		string sLocationLocator = rGroup.location.locator;

		ref rIsland = GetIslandByID(rGroup.location);

		string sTst = sLocationGroup + "." + sLocationLocator + ".x";
		if (CheckAttribute(rIsland, sTst))
		{
			x = stf(rIsland.(sLocationGroup).(sLocationLocator).x);
			z = stf(rIsland.(sLocationGroup).(sLocationLocator).z);
			ay = stf(rIsland.(sLocationGroup).(sLocationLocator).ay);
		}
		else
		{
			x = 0.0; z = 0.0; ay = 0.0;
			Trace("ERR: Group " + sGroupID + ", Island " + rGroup.location);
			Trace("ERR: Find locators Group " + sLocationGroup + ", Locator " + sLocationLocator);
		}
	}
	else
	{
		if (CheckAttribute(rGroup, "Pos"))
		{
			x = stf(rGroup.Pos.x);
			z = stf(rGroup.Pos.z);
			ay = stf(rGroup.Pos.ay);
		}
		else
		{
			Trace("Error: Sea_LoginGroup sGroupID = " + sGroupID + ", I can't find any locators or position for this group, maybe you can check this???");
		}
	}

	// set group position
	Group_SetXZ_AY(sGroupID, x, z, ay);

	// set group commander
	ref rGroupCommander = Group_GetGroupCommander(sGroupID);
	// update commander for SEA AI
	Group_SetGroupCommander(sGroupID, rGroupCommander.id);

	// set location near 
	if (CheckAttribute(rGroup, "location.neargroup"))			
	{
		Group_SetPursuitGroup(sGroupID, rGroup.location.neargroup);
	}
	
	// load group ships
	int iNumDeadCharacters = 0;
	for (int i=0; i<iNumShips; i++)
	{
		aref arShip;
		
		arShip = GetAttributeN(arQuestShips, i);
		ref rCharacter = GetCharacter(GetCharacterIndex(GetAttributeValue(arShip)));
		int iCharacterIndex = sti(rCharacter.index);

		if (LAi_IsDead(rCharacter)) { iNumDeadCharacters++; continue; }
		if (iCharacterIndex == GetMainCharacterIndex()) { Trace("Error: You assigned main character to quest group... This is a error!"); continue; }
		
		rCharacter.SeaAI.Group.Name = sGroupID;
		
		Ship_Add2Sea(sti(rCharacter.index), bFromCoast, "");

		ReloadProgressUpdate();
	}

	rGroup.AlreadyLoaded = "";

	if (iNumDeadCharacters == iNumShips)
	{
		Trace("Warn: I am automatic delete group '" + sGroupID +"', because it's empty");
		Group_DeleteAtEnd(sGroupID);
		//Group_DeleteGroup(sGroupID);
		return;
	}

	bSeaQuestGroupHere = true;

	Sea_AddGroup2TaskList(sGroupID);
}

void Sea_FirstInit()
{ 
	RefreshBattleInterface();
}

void Sea_Reload()
{
	DelEventHandler("Sea_Reload", "Sea_Reload");

	object Login;
	Login.PlayerGroup.ay = 0.0;
	Login.PlayerGroup.x = 0.0;
	Login.PlayerGroup.y = 0.0;
	Login.PlayerGroup.z = 0.0;
	Login.Island = Characters[0].location;

	SeaLogin(&Login);
}

void Sea_ReloadStart()
{
	if (!bSeaActive) { return; }
	DeleteSeaEnvironment();
	SetEventHandler("Sea_Reload", "Sea_Reload", 0);
	PostEvent("Sea_Reload", 1);
}
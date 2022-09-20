#include "storm-engine\layers.h"

#include "storm-engine\events.h"
#include "globals.c"
#include "animals.c"
#include "sea_ai\sea.c"
#include "ships\ships.c"
#include "Encounters\Encounters.c"
#include "worldmap\worldmap.c"
#include "locations\locations.c"
#include "Loc_ai\LAi_init.c"
#include "store\goods.h"
#include "cannons\cannons.c"
#include "nations\nations.c"
#include "particles.c"
#include "initinterface.c"
#include "characters\characters.c"
#include "interface\interface.h"
#include "store\storeutilite.c"
#include "dialog.c"
#include "quests\quests.c"
#include "islands\islands.c"
#include "reload.c"
#include "situations.c"
#include "battle_interface\loginterface.c"
#include "calendar.c"
#include "teleport.c"
#include "utils.c"
#include "ITEMS\items.h"
#include "ITEMS\itemLogic.c"
#include "ITEMS\items_utilite.c"
#include "weather\WhrWeather.c"
#include "controls\controls.c"
#include "landencounters\landencounters.c"

extern void wdmInitWorldMap();
extern void InitGoods();
extern void InitStores();
extern void InitItems();
extern void InitCharactersTables();
extern void InitCharactersNames();
extern void CreateCharacters();


native float Bring2RangeNoCheck(float fMin1, float fMax1, float fMin2, float fMax2, float fValue);
native float Bring2Range(float fMin1, float fMax1, float fMin2, float fMax2, float fValue);
native float Degree2Radian(float fDegree);
native float Clampf(float fValue);
native int RDTSC_B();
native int RDTSC_E(int iRDTSC);

native int SetTexturePath(int iLevel, string sPath);

#libriary "script_libriary_test"
#libriary "dx9render_script_libriary"

#event_handler(NEW_GAME_EVENT,"NewGame");
#event_handler(GAME_OVER_EVENT,"GameOverE");
#event_handler("Control Activation","ProcessControls");
#event_handler("MainMenuKey","ProcessMainMenuKey");
#event_handler("InterfaceKey","ProcessInterfaceKey");
#event_handler("CameraPosAng","ProcessCameraPosAng");
#event_handler("Cheat","ProcessCheat");
#event_handler("SeaDogs_ClearSaveData", "ClearLocationsSaveData");

object Render;

void ProcessCheat()
{
	string sCheatName;
	ref mc;
	sCheatName = GetEventData();
	mc = GetMainCharacter();

	switch(sCheatName)
	{
		case "Immortal":
			if(LAi_IsImmortal(GetMainCharacter()))
			{
				LAi_SetImmortal(GetMainCharacter(), false);
				Log_SetStringToLog("God mode OFF");
			}else{

				LAi_SetImmortal(GetMainCharacter(), true);
				Log_SetStringToLog("God mode ON");
			}
		break;
		case "ShotGun":
			if(globalSGMode != false)
			{
				globalSGMode = false;
				Log_SetStringToLog("Shotgun mode OFF");
			}else{
				globalSGMode = true;
				Log_SetStringToLog("Shotgun mode ON");
			}
		break;

		case "Gold":
			mc.money = sti(mc.money) + 100000;
			Log_SetStringToLog(" + 100000 G");
		break;
		case "Skill":
			mc.skill.freeskill = 1;

			mc.skill.freeskill = sti(mc.skill.freeskill) + 50;
			Log_SetStringToLog(" + 50 SP");
		break;
		case "Reputation":
			mc.reputation = REPUTATION_NEUTRAL;
			Log_SetStringToLog("Reputation Set to NEUTRAL");
		break;
		case "Morale":

		break;
		case "Encounters":
			if(CheckAttribute(mc,"worldmapencountersoff") == 0)
			{
				mc.worldmapencountersoff = "1";
				Log_SetStringToLog("Worldmap encounters OFF");
			}
			else
			{
				if(mc.worldmapencountersoff == "1")
				{
					mc.worldmapencountersoff = "0";
					Log_SetStringToLog("Worldmap encounters ON");
				}
				else
				{
					mc.worldmapencountersoff = "1";
					Log_SetStringToLog("Worldmap encounters OFF");
				}
			}
		break;
		case "MainCharacter":
			mc.model	= "Danielle";
			mc.sex = "woman";
			mc.FaceId = 30;
			mc.model.animation = "woman";
			mc.model.height = 1.75;
		break;
		case "soundoff":
			SendMessage(&Sound,"ll",MSG_SOUND_SET_ENABLED,0);
			Log_SetStringToLog("Sound OFF");
		break;
	}
}

object Camera;

void ProcessCameraPosAng()
{
	Camera.Pos.x = GetEventData();
	Camera.Pos.y = GetEventData();
	Camera.Pos.z = GetEventData();

	Camera.Ang.x = GetEventData();
	Camera.Ang.y = GetEventData();
	Camera.Ang.z = GetEventData();
}

void proc_break_video()
{
	trace("proc_break_video()");
	InterfaceStates.videoIdx = -1;
	Event("ievntEndVideo");
}

void Main()
{
//	LocationTestProcess();
//	return;

	ReloadProgressStart();
	ControlsInit(GetTargetPlatform(),true);
	nTeleportLocation = 1;
	sTeleportLocName = "Falaise_de_fleur_port_01";
	sTeleportLocName = "Oxbay_port";



	NationsInit();
	EncountersInit();
	CannonsInit();
	ShipsInit();
	IslandsInit();
	WeatherInit();
	InitPerks();

	if(LoadSegment("store\initGoods.c"))
	{
		InitGoods();
		UnloadSegment("store\initGoods.c");
	}

	if(LoadSegment("Interface\BaseInterface.c"))
	{
		InitBaseInterfaces_main();
		InitBaseInterfaces();
		UnloadSegment("Interface\BaseInterface.c");
	}


	SetEventHandler("Control Activation","proc_break_video",0);
	InterfaceStates.Launched = false;
	SetEventHandler(EVENT_END_VIDEO,"Main_LogoVideo",0);
	InterfaceStates.videoIdx = 0;
	Event(EVENT_END_VIDEO);
	ReloadProgressEnd();
}

void Main_LogoVideo()
{

	int i = sti(InterfaceStates.videoIdx);
	switch(i)
	{
	case 0:
		{
			InterfaceStates.videoIdx = 1;
			StartPostVideo("WaltDisneyLogo",1);
			return;
		}
	break;

	case 1:
		{
			InterfaceStates.videoIdx = 2;
			if( LanguageGetLanguage()=="Russian" ) {
				StartPostVideo("1CLogo",1);
			} else {
				StartPostVideo("BethesdaLogo",1);
			}
			return;
		}
	break;

	case 2:
		{
			InterfaceStates.videoIdx = 3;
			StartPostVideo("AkellaLogo",1);
			return;
		}
	break;

	case 3:
		if( GetTargetPlatform()=="pc" && LanguageGetLanguage()!="russian" )
		{
			InterfaceStates.videoIdx = 4;
			StartPostVideo("UBI",1);
			return;
		}
	break;

	}

	DelEventHandler(EVENT_END_VIDEO,"Main_LogoVideo");
	DeleteClass(&aviVideoObj);
	Event("DoInfoShower","sl","game prepare",true);
	SetEventHandler("frame","Main_Start",1);
}
//*/

void Main_Start()
//void Main()
{
	ReloadProgressStart();


	DelEventHandler("Control Activation","proc_break_video");
	DelEventHandler("frame","Main_Start");

	if( GetTargetPlatform()=="pc" )	ControlsInit(GetTargetPlatform(),false);
/*
	ControlsInit(GetTargetPlatform(),false);

	nTeleportLocation = 1;
	sTeleportLocName = "Falaise_de_fleur_port_01";
	sTeleportLocName = "Oxbay_port";

	NationsInit();
	EncountersInit();
	CannonsInit();
	ShipsInit();
	IslandsInit();
	WeatherInit();
	InitPerks();

	if(LoadSegment("store\initGoods.c"))
	{
		InitGoods();
		UnloadSegment("store\initGoods.c");
	}

	if(LoadSegment("Interface\BaseInterface.c"))
	{
		InitBaseInterfaces_main();
		InitBaseInterfaces();
		UnloadSegment("Interface\BaseInterface.c");
	}

	if(LoadSegment("Characters\Characters_names.c"))
	{
		InitCharactersNames();
		UnloadSegment("Characters\Characters_names.c");
	}

*/

	ReloadProgressUpdate();
	InitGame();
	ReloadProgressUpdate();

	Environment.date.hour = worldMap.date.hour;
	Environment.date.min = worldMap.date.min;
	Environment.date.sec = worldMap.date.sec;
	Environment.time = stf(worldMap.date.hour) + stf(worldMap.date.min)/60.0 + stf(worldMap.date.sec)/3600.0;
	Environment.date.year = worldMap.date.year;
	Environment.date.month = worldMap.date.month;
	Environment.date.day = worldMap.date.day;


	InterfaceStates.Buttons.Load.enable = true;

	Event("DoInfoShower","sl","game prepare",false);

	StartLanguageSetting(LanguageGetLanguage());
	LaunchMainMenu();
	//LaunchLoadGame();

	CharacterIsDead(GetMainCharacter());

	//SetMainCharacterIndex(1);
	//LoadMainCharacterInFirstLocation("Oxbay_town", "", "");

	ReloadProgressEnd();

}

void SaveGame()
{
	DelEventHandler("evntSave","SaveGame");
	string saveName = GetEventData();
	string saveData = GetEventData();
	SaveEngineState(saveName);
	ISetSaveData(saveName,saveData);
	PostEvent("DoInfoShower",1,"sl","save game",false);
}

void LoadGame()
{
	string saveName = GetEventData();

	DeleteEntities();
	ClearEvents();
	ClearPostEvents();

	CreateEntity(&LanguageObject,"obj_strservice");
	CreateEntity(&reload_fader, "fader");
	SendMessage(&reload_fader, "ls",FADER_PICTURE,"loading\load.tga");
	SendMessage(&reload_fader, "lfl", FADER_IN, RELOAD_TIME_FADE_IN, true);
	ReloadProgressStart();
	Characters[0].savegamename = saveName;
	SetEventHandler("frame","LoadGame_continue",1);
}

void LoadGame_continue()
{
	DelEventHandler("frame","LoadGame_continue");
	LoadEngineState(Characters[0].savegamename);
}

void InterfaceDoExit()
{
	DelEventHandler("frame","InterfaceDoExit");
	InterfaceStates.Launched=false;
	if(sti(InterfaceStates.doUnFreeze)==true)
	{
		SendMessage(&GameInterface,"l",MSG_INTERFACE_RELEASE);
		if(!IsEntity(&aviVideoObj))
		{
			if( bSeaActive && !bAbordageStarted )
			{
				LayerFreeze(SEA_REALIZE, false);
				LayerFreeze(SEA_EXECUTE, false);
			}
			else
			{
				LayerFreeze(realize, false);
				LayerFreeze(execute, false);
			}
		}
		DeleteAttribute(&GameInterface,"");
	}
	switch(interfaceResultCommand)
	{
		case RC_INTERFACE_FORTCAPTURE_EXIT:
			ReloadAfterFortCapture();
			break;

		case RC_INTERFACE_DO_NOTHING:
			break;
		case RC_INTERFACE_MAIN_MENU_EXIT:
			break;
		case RC_INTERFACE_DO_NEW_GAME:
			InterfaceStates.doUnFreeze = false;
			DeleteEntities();
			//DeleteSeaEnvironment();
			musicName = "";
			oldMusicName = "";
			ResetSoundScheme();
			StopSound(0,0);
			ReleaseSound(0);
			ClearEvents();
			ClearPostEvents();

			if(LoadSegment("Interface\BaseInterface.c"))
			{
				InitBaseInterfaces_main();
				InitBaseInterfaces();
				UnloadSegment("Interface\BaseInterface.c");
			}


			LaunchSelectCharacter();

			//SetEventHandler("frame","NewGame",1);
			break;
		case RC_INTERFACE_DO_LOAD_GAME:
			//LoadGame();
			LaunchLoadGame();
			break;
		case RC_INTERFACE_DO_SAVE_GAME:
			LaunchSaveGame();
			break;

		case RC_INTERFACE_DO_OPTIONS:
			LaunchOptionScreen();
			break;
		case RC_INTERFACE_DO_CONTROLS:
			LaunchControlsScreen();
			break;
		case RC_INTERFACE_DO_CREDITS:
			break;
		case RC_INTERFACE_DO_RESUME_GAME:
			break;
		case RC_INTERFACE_RANSACK_MAIN_EXIT:
			Return2SeaAfterAbordage();
			//wdmCreateMap(0.0,0.0,0.0);
			break;
		case RC_INTERFACE_CHARACTER_SELECT_EXIT:
			DeleteEntities();
			ClearEvents();
			SetEventHandler("frame","NewGame",1);
			InterfaceStates.doUnFreeze = false;
			break;
	}
}

void EngineLayersOffOn(bool on)
{
	on = !on;
	LayerFreeze(REALIZE,on);
	LayerFreeze(EXECUTE,on);
	LayerFreeze(SEA_REALIZE,on);
	LayerFreeze(SEA_EXECUTE,on);
}

string seadogs_saveFrom = "";

void OnSave()
{
	seadogs_saveFrom = "";
	if(IsEntity(&worldMap) != 0)
	{
		seadogs_saveFrom = "world map";
	}else{
		int ldLoc = FindLoadedLocation();
		if(ldLoc >= 0)
		{
			seadogs_saveFrom = "location";
			SendMessage(&Locations[ldLoc], "l", MSG_LOCATION_SETCHRPOSITIONS);
			LAi_SaveInfo();
			PostEvent("SeaDogs_ClearSaveData", 400, "a", &Locations[ldLoc]);
		}else{
			Trace("OnSave() -> unknow character location");
		}
	}

}

void ClearLocationsSaveData()
{
	aref loc = GetEventData();
	SendMessage(loc, "l", MSG_LOCATION_CLRCHRPOSITIONS);
}

int actLoadFlag = 0;
void OnLoad()
{
	actLoadFlag = 1;


	//NationsInit();
	ResetSound();

	//CreateClass("dummy");

	if(LoadSegment("Interface\BaseInterface.c"))
	{
		//InitBaseInterfaces_main();
		InitBaseInterfaces();
		UnloadSegment("Interface\BaseInterface.c");
	}

	ReloadProgressUpdate();

	DialogsInit();
	//IslandsInit();
	//LocationInit();

	ReloadProgressUpdate();

	InitCharacterEvents();
	ReloadProgressUpdate();
	QuestsInit();
	ReloadProgressUpdate();
	InitTeleport();
	ReloadProgressUpdate();
	InitParticles();
	ReloadProgressUpdate();
	//ImportFuncTest();


	InterfaceStates.Buttons.Resume.enable = true;
	InterfaceStates.Buttons.Save.enable = true;
	InterfaceStates.Buttons.Load.enable = true;

	if(seadogs_saveFrom == "location")
	{
		ref mainchar;
		mainchar = GetMainCharacter();
		LoadMainCharacterInFirstLocation(mainchar.location,"", mainchar.location.from_sea);
		//LoadMainCharacterInFirstLocation(sTeleportLocName, "", "Falaise_de_fleur_location_01");
		int ldLoc = FindLoadedLocation();
		if(ldLoc >= 0)
		{
			SendMessage(&Locations[ldLoc], "l", MSG_LOCATION_TLPCHRPOSITIONS);
		}
	}else{
		if(seadogs_saveFrom == "world map")
		{
			wdmLoadSavedMap();
		}else{
			Trace("Unknow seadogs_saveFrom == " + seadogs_saveFrom);
		}
	}

	//ReloadEndFade();
	EngineLayersOffOn(true);
	//NewGame();
	DialogRun = false;
	InterfaceStates.Launched = false;

	ReloadProgressUpdate();

	PerkLoad();

	ReloadProgressUpdate();
	LoadGameOptions();

	ReloadProgressEnd();

	actLoadFlag = 0;
}

void NewGame()
{
	DeleteEntities();
	DelEventHandler("frame","NewGame");

	CreateEntity(&LanguageObject,"obj_strservice");
	CreateEntity(&reload_fader, "fader");
	SendMessage(&reload_fader, "ls",FADER_PICTURE,"loading\new_game.tga");
	SendMessage(&reload_fader, "lfl", FADER_IN, RELOAD_TIME_FADE_IN, true);

	SetEventHandler("frame","NewGame_continue",1);
}

void NewGame_continue()
{

	ReloadProgressStart();

	DelEventHandler("frame","NewGame_continue");

	if(LoadSegment("Interface\BaseInterface.c"))
	{
		InitBaseInterfaces();
		UnloadSegment("Interface\BaseInterface.c");
	}

	InitGame();

	Environment.date.hour = worldMap.date.hour;
	Environment.date.min = worldMap.date.min;
	Environment.date.sec = worldMap.date.sec;
	Environment.time = stf(worldMap.date.hour) + stf(worldMap.date.min)/60.0 + stf(worldMap.date.sec)/3600.0;
	Environment.date.year = worldMap.date.year;
	Environment.date.month = worldMap.date.month;
	Environment.date.day = worldMap.date.day;

	InterfaceStates.Buttons.Resume.enable = true;
	InterfaceStates.Buttons.Save.enable = true;
	InterfaceStates.Buttons.Load.enable = true;
	//PlayMusic("MW battle2.mp3");
	sTeleportLocName = "Tutorial_deck";

	ReloadProgressUpdate();

	LoadMainCharacterInFirstLocation(sTeleportLocName, "reload1", "Oxbay_port");

	ReloadProgressEnd();
}

/*
void NewGame()
{
	DeleteEntities();
	Environment.date.hour = 14.0;
	Environment.date.min = 0.0;
	Environment.date.sec = 0.0;
	Environment.time = 14.0;
	Environment.date.year = 1630;
	Environment.date.month = 8;
	Environment.date.day = 15;

	DelEventHandler("frame","NewGame");
	if(LoadSegment("Interface\BaseInterface.c"))
	{
		InitBaseInterfaces();
		UnloadSegment("Interface\BaseInterface.c");
	}
	InitGame();

	InterfaceStates.Buttons.Resume.enable = true;
	InterfaceStates.Buttons.Save.enable = true;
	InterfaceStates.Buttons.Load.enable = true;
	//PlayMusic("MW battle2.mp3");
	sTeleportLocName = "Oxbay_port";
	LoadMainCharacterInFirstLocation(sTeleportLocName, "reload2", sTeleportLocName);

}
*/
void InitGame()
{
	if(LoadSegment("store\initStore.c"))
	{
		InitStores();
		UnloadSegment("store\initStore.c");
	}
	InitSound();

	ReloadProgressUpdate();

	DeleteSeaEnvironment();
	//CharactersInit();
	if(LoadSegment("worldmap\worldmap_init.c"))
	{
		wdmInitWorldMap();
		UnloadSegment("worldmap\worldmap_init.c");
	}

	IslandsInit();
	ReloadProgressUpdate();
	//return;
	LocationInit();
	ReloadProgressUpdate();
	DialogsInit();
	ReloadProgressUpdate();
	InitTeleport();
	ReloadProgressUpdate();
	InitParticles();
	ReloadProgressUpdate();

    if(LoadSegment("items\initItems.c"))
	{
		InitItems();
		UnloadSegment("items\initItems.c");
	}

	ReloadProgressUpdate();
	CharactersInit();
	ReloadProgressUpdate();
	QuestsInit();
	ReloadProgressUpdate();
	SeaAIGroupsInit();
	ReloadProgressUpdate();
	InitQuestMapEncounters();
	ReloadProgressUpdate();
	InitLandRandomEncounters();
	ReloadProgressUpdate();

	SetNextWeather("Blue Sky");
	//SetNextWeather("Violet Sky");


	ResetQuestMovie();

	ReloadProgressUpdate();

	LoadGameOptions();

	ReloadProgressUpdate();
	InfoShowSetting();
}

int counter = 0;
void ProcessControls()
{
	string ControlName;
	ControlName = GetEventData();
	//trace("ProcessControls() : " + ControlName);
	//if (ControlName == "WhrPrevWeather")	{ Whr_LoadNextWeather(-1); }
	//if (ControlName == "WhrNextWeather")	{ Whr_LoadNextWeather(1); }
	//if (ControlName == "WhrUpdateWeather")	{ Whr_UpdateWeather(); }

	if (ControlName == "Help") RunHelpChooser();

	if(bSeaActive && !bAbordageStarted)
	{
		switch(ControlName)
		{
			case "MainMenu": ProcessMainMenuKey();	break;
			case "MainMenuDouble": ProcessMainMenuKey(); break;
			case "Interface": ProcessInterfaceKey();break;

			case "Sea_CameraSwitch": SeaCameras_Switch(); break;
			case "Ship_Fire": Ship_DoFire(); break;

			//case "Tele": Sea_ReloadStart(); break;
		}
	}
	else
	{
		switch(ControlName)
		{
			case "MainMenu": ProcessMainMenuKey();	break;
			case "MainMenuDouble": ProcessMainMenuKey(); break;
			case "Interface": ProcessInterfaceKey();break;
			case "Tele":
				StartQuickTeleport();
				break;
			case "TeleBack": Teleport(-1); break;
			case "Action":
				//DumpAttributes(loadedLocation/*loadedLocation.reload.reload1.x*/);
				//trace("Y: " + loadedLocation.reload.reload1.y);
				//trace("Z: " + loadedLocation.reload.reload1.z);
			break;
		}
	}


	/*switch(ControlName)
	{
		counter++;
		if(counter > 3) counter = 0;
		case "CameraSwitch":
			switch(counter)
			{
			case 0: SetDayTime(DAY_TIME_NIGHT); break;
			case 1: SetDayTime(DAY_TIME_MORNING); break;
			case 2: SetDayTime(DAY_TIME_DAY); break;
			case 3: SetDayTime(DAY_TIME_EVENING); break;
			}
		break;
	}*/

}

void Teleport(int step)
{
	nTeleportLocation = nTeleportLocation + step;
	if(nTeleportLocation >=	nLocationsNum) nTeleportLocation = 1;
	if(nTeleportLocation <=	0) nTeleportLocation = nLocationsNum - 1;

	sTeleportLocName = Locations[nTeleportLocation].id;
	Trace("Teleport to '" + sTeleportLocName + "'");

	ReleaseSound(0);
	ClearEvents();
	ClearPostEvents();
	DeleteEntities();
	SetEventHandler("frame","NewGame",1);
}

void ProcessMainMenuKey()
{
	LaunchMainMenu();
}

void ProcessInterfaceKey()
{
	if(bSeaActive && !bAbordageStarted)
	{
		if( CheckAttribute(&BattleInterface,"ComState") && sti(BattleInterface.ComState) != 0 )
			{return;}
	}
	else
	{
		if( SendMessage(GetMainCharacter(),"ls",MSG_CHARACTER_EX_MSG,"IsFightMode") != 0 )
			{return;}
		if( CheckAttribute(&objLandInterface,"ComState") && sti(objLandInterface.ComState) != 0 )
			{return;}
	}
	if( IsEntity(&worldMap) ) return;
	LaunchSelectMenu();
	//LaunchCharacter(GetMainCharacter());
}

void GameOverE()
{
	GameOver("sea");
	DeleteSeaEnvironment();
	/*EngineLayersOffOn(false);
	SetEventHandler(EVENT_END_VIDEO,"LaunchMainMenu",0);
	StartVideo("blaze_grasses_dead");
	InterfaceStates.Buttons.Resume.enable = false;
	InterfaceStates.Buttons.Save.enable = false;
	SetEventHandler(EVENT_END_VIDEO,"LaunchMainMenu",0);*/
	//LaunchMainMenu();
}

void GameOver(string sName)
{
	ref mc;
	int nSelect;
	string sFileName;
	//ResetSoundScheme();
	//PauseAllSounds();
	ResetSound();
	EngineLayersOffOn(false);

	mc = GetMainCharacter();

	ClearEvents();
	ClearPostEvents();
	DeleteEntities();

	if(sti(InterfaceStates.Launched)) {
		UnloadSegment(Interfaces[CurrentInterface].SectionName);
	}

	if(LoadSegment("Interface\BaseInterface.c"))
	{
		InitBaseInterfaces();
		UnloadSegment("Interface\BaseInterface.c");
	}
	InitSound();

	SetEventHandler(EVENT_END_VIDEO,"LaunchMainMenu_afterVideo",0);


	switch(sName)
	{
		case "sea":
			nSelect = rand(1);
			sFileName = "skeleton_on_beach";
			switch(nSelect)
			{
				case 0: sFileName = "skeleton_on_beach"; break;
				case 1: sFileName = "undersea"; break;
			}
			StartPostVideo(sFileName,1);
		break;

		case "boarding":
			StartPostVideo("skeleton_on_beach",1);
		break;

		case "land":
			StartPostVideo("blaze_land_dead",1);
		break;

		case "mutiny":
			StartPostVideo("blaze_mutiny_dead",1);
		break;
	}
	InterfaceStates.Buttons.Resume.enable = false;
	InterfaceStates.Buttons.Save.enable = false;
}

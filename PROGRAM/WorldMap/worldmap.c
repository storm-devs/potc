/*
	Programm interface:

	Init world map in start
		void wdmInitWorldMap();
	Create world map object
		void wdmCreateMap();
	Release world map object
		void wdmReleaseMap();


	SPI (Script program interface):
	Получение данных от карты
	(const) поля только для прочтения
	(var) поля только для записи и прочтения, запись в них приводит к обновления остальных полей,
	      принадлежащих этой группе

	Шторма
	worldMap.storm.num - текущие количество штормов в карте (const)
	worldMap.storm.cur - индекс текущего шторма 0..num-1, надо перезаписывать для обновления полей (var)
	worldMap.storm.x - позиция шторма по x (const)
	worldMap.storm.z - позиция шторма по z (const)
	worldMap.storm.time - оставшееся время жизни в секундах (const)

	Кораблики событий
	worldMap.encounter.num - текущие количество корабликов в карте (const)
	worldMap.encounter.cur - индекс текущего кораблика в карте (var)
	worldMap.encounter.x - позиция кораблика по x (const)
	worldMap.encounter.z - позиция кораблика по z (const)
	worldMap.encounter.time - оставшееся время жизни в секундах (const)
	worldMap.encounter.type - тип события, обозначаемый этим корабликом (define в таблице типов энкоунтеров)
	worldMap.encounter.attack - индекс кораблика, который атакуем (стоя на месте)

	Разная информация
	worldMap.info.playerInStorm - если 1 то плеер находиться в шторме
	worldMap.info.updateinfo - апдейт информации


	//Внутреняя информация - !!!Осторожно, ни каких проверок!!!
	worldMap.enemyshipViewDistMin;		//Растояние на котором корабль начинает исчезать
	worldMap.enemyshipViewDistMax;		//Растояние на котором корабль исчезает полностью
	worldMap.enemyshipDistKill;			//Расстояние на котором убиваем корабль
	worldMap.enemyshipBrnDistMin;		//Минимальное растояние на котором рожается корабль
	worldMap.enemyshipBrnDistMax;		//Максимальное растояние на котором рожается корабль

	worldMap.stormViewDistMin;			//Растояние на котором шторм начинает исчезать
	worldMap.stormViewDistMax;			//Растояние на котором шторм исчезает полностью
	worldMap.stormDistKill;				//Расстояние на котором убиваем шторм
	worldMap.stormBrnDistMin;			//Минимальное растояние на котором рожается шторм
	worldMap.stormBrnDistMax;			//Максимальное растояние на котором рожается шторм

*/

#include "worldmap\worldmap_globals.c"
#include "worldmap\worldmap_events.c"
#include "worldmap\worldmap_reload.c"
#include "worldmap\worldmap_encgen.c"


//=========================================================================================


#event_handler("WorldMap_EncounterCreate", "wdmEvent_EncounterCreate");
#event_handler("WorldMap_inside_islandzone", "wdmEvent_InsideIsland");
#event_handler("WorldMap_outside_islandzone", "wdmEvent_OutsideIsland");
#event_handler("WorldMap_PlayerInStorm", "wdmEvent_PlayerInStorm");
#event_handler("WorldMap_ShipEncounter", "wdmEvent_ShipEncounter");
#event_handler("WorldMap_EventWindowChangeSelectoin", "wdmEvent_EventWindowChangeSelectoin");
#event_handler("WorldMap_EventWindowSelect", "wdmEvent_EventWindowSelect");
#event_handler("WorldMap_WaitMenuChangeSelectoin", "wdmEvent_WaitMenuChangeSelectoin");
#event_handler("WorldMap_WaitMenuSelect", "wdmEvent_WaitMenuSelect");
#event_handler("WorldMap_DeleteShipEncounter", "wdmEvent_DeleteShipEncounter");
#event_handler("WorldMap_UpdateDate", "wdmEvent_UpdateDate");
#event_handler("ExitFromWorldMap", "wdmReloadToSea");
#event_handler("EventLoadLocation", "wdmOpenLocation");


//=========================================================================================
// Programm interface
//=========================================================================================
bool wdmNoClearEncountersTable = false;

void wdmCreateMap(float dx, float dz, float ay)
{
	wdmDisableTornadoGen = true;
	worldMap.playerShipAY = ay;
	ClearAllLogStrings();
	wdmDisableRelease = true;
	//Create world map engine object
	ReloadProgressStart();
	CreateEntity(&worldMap,"worldmap");
	worldMap.isLoaded = "true";
	//Set player ship position
	worldMap.playerShipDispX = dx/WDM_MAP_TO_SEA_SCALE;
	worldMap.playerShipDispZ = dz/WDM_MAP_TO_SEA_SCALE;
	//Update parameters
	worldMap.update = "";
	//Reset encounters data
	wdmReset();
	worldMap.playerShipUpdateDisp = "";
	if(wdmNoClearEncountersTable == false) ReleaseMapEncounters();
	wdmNoClearEncountersTable = false;
	//Fade in
	CreateEntity(&wdm_fader, "fader");
	if(IsEntity(wdm_fader) == 0) Trace("Fader not created!!!");	
	float fadeInTime = 0.5;
	SendMessage(&wdm_fader, "lfl", FADER_IN, fadeInTime, true);
	SendMessage(&wdm_fader, "ls",FADER_PICTURE0,"loading\sea.tga");
	SetSchemeForMap();
	PostEvent("EventWorldMapInit", 0);
	ReloadProgressEnd();
}

void wdmCreateWorldMap()
{
	float dshipX = MakeFloat(worldMap.playerShipDispX)*WDM_MAP_TO_SEA_SCALE;
	float dshipZ = MakeFloat(worldMap.playerShipDispZ)*WDM_MAP_TO_SEA_SCALE;
	float shipAY = MakeFloat(worldMap.playerShipAY);
	wdmCreateMap(dshipX, dshipZ, shipAY);
}

void wdmLoadSavedMap()
{
	float dshipX = MakeFloat(worldMap.playerShipDispX)*WDM_MAP_TO_SEA_SCALE;
	float dshipZ = MakeFloat(worldMap.playerShipDispZ)*WDM_MAP_TO_SEA_SCALE;
	float shipAY = MakeFloat(worldMap.playerShipAY);
	wdmNoClearEncountersTable = true;
	wdmCreateMap(dshipX, dshipZ, shipAY);
}

void wdmOpenLocation()
{
	//Проскочим ненужные локации
	if(!TestRef(loadedLocation)) return;
	if(!IsEntity(loadedLocation)) return;	
	if(!CheckAttribute(loadedLocation, "worldmap")) return;
	//Переберём все острова
	aref islands;
	makearef(islands, worldMap.islands);
	int num = GetAttributesNum(islands);
	for(int i = 0; i < num; i++)
	{
		aref isl = GetAttributeN(islands, i);
		if(!CheckAttribute(isl, "locations")) continue;
		aref locations;
		makearef(locations, isl.locations);
		wdmOpenIslandLocation(locations, loadedLocation.worldmap);
	}
}

void wdmOpenIslandLocation(aref locations, string name)
{
	//Переберём все города
	int num = GetAttributesNum(locations);
	for(int i = 0; i < num; i++)
	{
		aref loc = GetAttributeN(locations, i);
		if(!CheckAttribute(loc, "name")) continue;
		if(loc.name == name)
		{
			loc.visible = "true";
			if(CheckAttribute(loc, "label"))
			{
				loc.label.visible = "true";
			}
		}
	}
}

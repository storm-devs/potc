

object wdmLoginToSea;
object wdm_fader;
bool wdmLockReload = false;

void wdmReloadToSea()
{
	SetReloadNextTipsImage();
	if(wdmLockReload)
	{
		wdmDisableTornadoGen = true;
		return;
	}
	worldMap.encounter.type = "";
	//Clrear login object
	DeleteAttribute(&wdmLoginToSea, "");
	//Reload to island
	float baseX, baseZ;
	//Player ship coordinates
	worldMap.playerShipUpdate = "";
	float psX = MakeFloat(worldMap.playerShipX);
	float psZ = MakeFloat(worldMap.playerShipZ);

	//Trace("\");
	//Trace("\");
	//Trace("psX = " + psX + "   psZ = " + psZ);


	//
	if(wdmCurrentIsland !=	WDM_NONE_ISLAND)
	{
		//Island
		wdmLoginToSea.island = worldMap.islands.(wdmCurrentIsland).name;
		float ix = MakeFloat(worldMap.islands.(wdmCurrentIsland).position.rx);
		float iz = MakeFloat(worldMap.islands.(wdmCurrentIsland).position.rz);

		//Trace("ix = " + ix + "   iz = " + iz);
		

		//Player ship
		worldMap.playerShipDispX = (psX - ix);
		worldMap.playerShipDispZ = (psZ - iz);

		//Trace("worldMap.playerShipDispX = " + worldMap.playerShipDispX + "   worldMap.playerShipDispZ = " + worldMap.playerShipDispZ);

		wdmLoginToSea.playerGroup.x = (psX - ix)*WDM_MAP_TO_SEA_SCALE;
		wdmLoginToSea.playerGroup.z = (psZ - iz)*WDM_MAP_TO_SEA_SCALE;
		wdmLoginToSea.playerGroup.ay = worldMap.playerShipAY;
		baseX = ix;
		baseZ = iz;
		//trace("ISL: - id" + wdmCurrentIsland + "  " +  wdmLoginToSea.playerGroup.x + "  " +  wdmLoginToSea.playerGroup.z);
	}else{
		//Island
		wdmLoginToSea.island = "";
		worldMap.playerShipDispX = 0;
		worldMap.playerShipDispZ = 0;
		//Player ship
		wdmLoginToSea.playerGroup.x = 0;
		wdmLoginToSea.playerGroup.z = 0;	
		wdmLoginToSea.playerGroup.ay = worldMap.playerShipAY;
		baseX = psX;
		baseZ = psZ;
		//trace("SEA: " + wdmLoginToSea.playerGroup.x + "  " +  wdmLoginToSea.playerGroup.z);
	}
	//Encounters
	int numEncounters = wdmGetNumberShipEncounters();
	string grp;
	float plsX = MakeFloat(wdmLoginToSea.playerGroup.x);
	float plsZ = MakeFloat(wdmLoginToSea.playerGroup.z);
	bool isShipEncounterType = false;
	for(int i = 0; i < numEncounters; i++)
	{
		if(wdmSetCurrentShipData(i))
		{
			if(MakeInt(worldMap.encounter.select) == 0) continue;			
			isShipEncounterType = true;
			grp = "group" + i;
			float encX = MakeFloat(worldMap.encounter.x);
			float encZ = MakeFloat(worldMap.encounter.z);
			wdmLoginToSea.encounters.(grp).x = plsX + (encX - psX)*WDM_MAP_TO_SEA_ENCOUNTERS_SCALE;
			wdmLoginToSea.encounters.(grp).z = plsZ + (encZ - psZ)*WDM_MAP_TO_SEA_ENCOUNTERS_SCALE;
			wdmLoginToSea.encounters.(grp).ay = worldMap.encounter.ay;
			wdmLoginToSea.encounters.(grp).type = worldMap.encounter.type;
		}
	}
	//Weather
	worldMap.info.updateinfo = "";
	wdmLoginToSea.storm = worldMap.info.playerInStorm;
	//Fade out
	SetEventHandler("FaderEvent_StartFade", "WdmStartFade", 0);
	SetEventHandler("FaderEvent_EndFade", "WdmEndFade", 0);
	wdm_fader.thisWorldMapFader = "";
	CreateEntity(&wdm_fader, "fader");
	if(IsEntity(wdm_fader) == 0) Trace("Fader not created!!!");	
	float fadeOutTime = 0.5;
	SendMessage(&wdm_fader, "lfl", FADER_OUT, fadeOutTime, true);
	SendMessage(&wdm_fader, "l", FADER_STARTFRAME);
	string imageName = "WorldMap\reload\sea.tga";
	//Trace("worldMap.encounter.type = " + worldMap.encounter.type);
	if(isShipEncounterType)
	{
		imageName = "WorldMap\reload\Battle.tga";
	}
	if(wdmLoginToSea.storm != "0")
	{
		imageName = "WorldMap\reload\Storm.tga";
		wdmLoginToSea.tornado = 0;
		if(wdmTornadoGenerator() != false)
		{
			imageName = "WorldMap\reload\Twister.tga";
			wdmLoginToSea.tornado = 1;
		}		
	}
	wdmLoginToSea.imageName = imageName;
	SendMessage(&wdm_fader, "ls",FADER_PICTURE, imageName);
	wdmDisableTornadoGen = true;
}

void WdmStartFade()
{
	PauseAllSounds();
	wdmDisableTornadoGen = true;
	wdmDisableRelease = false;
	//Delete EventHandler
	DelEventHandler("FaderEvent_StartFade", "WdmStartFade");
	//Delete entity
	worldMap.playerShipUpdate = "";
	DeleteClass(&worldMap);
	worldMap.isLoaded = "false";
}

void WdmEndFade()
{
	int a = GetEventData();
	aref reload_fader = GetEventData();

	wdmDisableRelease = true;
	//Delete EventHandler
	DelEventHandler("FaderEvent_EndFade", "WdmEndFade");
	//Switch to sea
	ReloadProgressStart();
	SeaLogin(&wdmLoginToSea);
	LayerAddObject(SEA_REALIZE, &reload_fader, -1);
	ReloadProgressEnd();
}

void QuitFromWorldMap()
{
	//Fade out
	SetEventHandler("FaderEvent_StartFade", "WdmStartFade", 0);
	SetEventHandler("FaderEvent_EndFade", "WdmEndFadeA", 0);
	wdm_fader.thisWorldMapFader = "";
	CreateEntity(&wdm_fader, "fader");
	if(IsEntity(wdm_fader) == 0) Trace("Fader not created!!!");	
	float fadeOutTime = 0.5;
	SendMessage(&wdm_fader, "lfl", FADER_OUT, fadeOutTime, true);
	SendMessage(&wdm_fader, "l", FADER_STARTFRAME);
}

void WdmEndFadeA()
{
	wdmDisableRelease = true;
	//Delete EventHandler
	DelEventHandler("FaderEvent_EndFade", "WdmEndFadeA");
	//Switch to sea
	Event("QuitFromWorldMap");

}


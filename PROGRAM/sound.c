// DEFINES
#define MUSIC_CHANGE_TIME  3000
#define MUSIC_SILENCE_TIME 180000.0
#define SOUNDS_FADE_TIME   200

#event_handler ("LoadSceneSound", "LoadSceneSound")
// PLAY
int Play3DSound(string name, float x, float y, float z)
{
	InitSound();
	//Trace("Play3DSound : "+name);
	return SendMessage(Sound,"lsllllllfff",MSG_SOUND_PLAY, name, SOUND_WAV_3D, VOLUME_FX, false, false, false, 0, x, y, z);
}

int Play3DSoundCached(string name, float x, float y, float z)
{
	InitSound();
	//Trace("Play3DSoundCached : "+name);
	return SendMessage(Sound,"lsllllllfff",MSG_SOUND_PLAY, name, SOUND_WAV_3D, VOLUME_FX, false, false, true, 0, x, y, z);
}

int Play3DSoundComplex(string name, float x, float y, float z, bool bLooped, bool bCached)
{
	InitSound();
	return SendMessage(Sound,"lsllllllfff",MSG_SOUND_PLAY, name, SOUND_WAV_3D, VOLUME_FX, false, bLooped, bCached, 0, x, y, z);
}

int PlayStereoSound(string name)
{
	InitSound();
	//Trace("PlayStereoSound : "+name);
	return SendMessage(Sound,"lslllll",MSG_SOUND_PLAY, name, SOUND_WAV_STEREO, VOLUME_FX, false, false, false);
}

int PlayStereoSoundLooped(string name)
{
	InitSound();
	//Trace("PlayStereoSoundLooped : "+name);
	return SendMessage(Sound,"lsllll",MSG_SOUND_PLAY, name, SOUND_WAV_STEREO, VOLUME_FX, false, true, false);
}

int PlayStereoSoundLooped_JustCache(string name)
{
	InitSound();
	//Trace("PlayStereoSoundLooped : "+name);
	return SendMessage(Sound,"lslllll",MSG_SOUND_PLAY, name, SOUND_WAV_STEREO, VOLUME_FX, true, true, false);
}

int PlayStereoOGG(string name)
{
	InitSound();
	//Trace("PlayStereoSound : "+name);
	return SendMessage(Sound,"lslllll",MSG_SOUND_PLAY, name, SOUND_MP3_STEREO, VOLUME_FX, false, false, false);
}

// OTHER METHODS
void StopSound(int id,int fade)
{
	InitSound();
	//Trace("StopSound : "+id);
	SendMessage(Sound,"lll",MSG_SOUND_STOP,id,fade);
}

void ResumeSound(int id,int fade)
{
	InitSound();
	//Trace("ResumeSound : "+id);
	SendMessage(Sound,"lll",MSG_SOUND_RESUME,id,fade);
}

void ReleaseSound(int id)
{
	InitSound();
	//Trace("ReleaseSound : "+id);
	SendMessage(Sound,"ll",MSG_SOUND_RELEASE,id);
}

// SOUND SCHEMES
void ResetSoundScheme()
{
	InitSound();
	Trace("ResetSoundScheme");
	SendMessage(Sound,"l",MSG_SOUND_SCHEME_RESET);
}

void SetSoundScheme(string schemeName)
{
	InitSound();
	Trace("SetSoundScheme: "+schemeName);
	SendMessage(Sound,"ls",MSG_SOUND_SCHEME_SET,schemeName);
}

void AddSoundScheme(string schemeName)
{
	InitSound();
	Trace("AddSoundScheme: "+schemeName);
	SendMessage(Sound,"ls",MSG_SOUND_SCHEME_ADD,schemeName);
}

void SetWeatherScheme(string scheme)
{
	if (Whr_IsStorm())
	{
		AddSoundScheme(scheme+"_storm");
		PlayStereoSoundLooped("rain_storm");
	}
	else 
	{ 
		if (Whr_IsRain())
		{
			AddSoundScheme(scheme+"_rain");
			PlayStereoSoundLooped("rain");
		}
		else
		{
			AddSoundScheme(scheme);
		}
	}
}

void SetTimeScheme(string scheme)
{
	if (Whr_IsNight())
	{
		AddSoundScheme(scheme+"_night");
	}
	else
	{
		AddSoundScheme(scheme+"_day");
	}
}

void SetSchemeForLocation (ref loc)
{
	if(CheckAttribute(loc,"type")) 
	{
		ResetSoundScheme();
		switch (loc.type)
		{
		case "port":
			SetSoundScheme("port");
			SetTimeScheme("land");
			SetWeatherScheme("seashore_weather");
			SetMusicAlarm("music_gorod");
			break;
		case "town":
			SetSoundScheme("town");
			SetTimeScheme("land");
			SetWeatherScheme("land");
			SetMusicAlarm("music_gorod");
			break;
		case "jungle":
			SetSoundScheme("jungle");
			SetTimeScheme("land");
			SetWeatherScheme("land");
			SetMusicAlarm("music_jungle");
			break;
		case "seashore":
			ResetSoundScheme();
			SetTimeScheme("land");
			SetWeatherScheme("seashore_weather");
			SetMusicAlarm("music_jungle");
			break;
		case "cave":
			SetSoundScheme("cave");
			SetMusicAlarm("music_coridor");
			break;
		case "inca_temple":
			SetSoundScheme("inca_temple");
			SetMusicAlarm("music_coridor");
			break;
		case "house":
			SetSoundScheme("house");
			SetMusicAlarm("music_gorod");
			break;
		case "tavern":
			SetSoundScheme("tavern");
			SetMusicAlarm("music_tavern");
			break;
		case "shop":
			SetSoundScheme("shop");
			SetMusicAlarm("music_shop");
			break;
		case "residence":
			SetSoundScheme("residence");
			SetMusicAlarm("music_gubernator");
			break;
		case "church":
			SetSoundScheme("church");
			SetMusicAlarm("music_church");
			break;
		case "jail":
			SetSoundScheme("jail");
			SetMusicAlarm("music_coridor");
			break;
		case "deck":
			SetSoundScheme("deck");
			SetMusicAlarm("music_gorod");
			break;
		}
	}
	SetStaticSounds(loc);
}

void SetStaticSounds (ref loc)
{
	if(IsEntity(loc) != true) return;
	string locatorGroupName = "locators.sound";
	if(CheckAttribute(loadedLocation, locatorGroupName) == 0) return;
	aref locatorGroup;
	makearef(locatorGroup, loc.(locatorGroupName));
	int locatorCount = GetAttributesNum(locatorGroup);
	if(locatorCount <= 0) return;
	string locatorName, locatorType;
	int locatorNameLength;

	for(int i = 0; i < locatorCount; i++)
	{
		aref locator = GetAttributeN(locatorGroup, i);
		locatorName = GetAttributeName(locator);
		locatorNameLength = strlen(locatorName);
		locatorType = strcut(locatorName, 0, locatorNameLength-3);
		if ((locatorType == "nightinsects") || (locatorType == "tree"))
		{
			continue;
		}
		SendMessage(Sound, "lsllllllfff", MSG_SOUND_PLAY, locatorType, SOUND_WAV_3D, VOLUME_FX, 0, 1, 0, 0, stf(locator.x), stf(locator.y), stf(locator.z));
	}
	
}

void SetSchemeForAbordage ()
{
	ResetSoundScheme();
	SetMusic("music_abordaz");
	ResumeAllSounds();
	int abordageSoundID = PlayStereoSoundLooped_JustCache("abordage");
	SendMessage(Sound,"llf",MSG_SOUND_SET_VOLUME, abordageSoundID, 0.5);
	SendMessage(Sound,"lll",MSG_SOUND_RESUME, abordageSoundID, 0);
}

void SetSchemeForSea ()
{
	ResetSoundScheme();

	AddSoundScheme("sea");
	if (Whr_IsStorm())
	{
		AddSoundScheme("sea_weather_storm");
		int rainSoundID = PlayStereoSoundLooped_JustCache("rain_storm");
		SendMessage(Sound,"llf",MSG_SOUND_SET_VOLUME, rainSoundID, 0.5);
		SendMessage(Sound,"lll",MSG_SOUND_RESUME, rainSoundID, 0);
		int windSoundID = PlayStereoSoundLooped_JustCache("water_sea_storm");
		SendMessage(Sound,"llf",MSG_SOUND_SET_VOLUME, windSoundID, 0.45);
		SendMessage(Sound,"lll",MSG_SOUND_RESUME, windSoundID, 0);
		SetMusic("music_storm");
	}
	else 
	{ 
		SetMusic("music_spokplavanie");
		if (Whr_IsRain())
		{
			AddSoundScheme("sea_weather_rain");
			PlayStereoSoundLooped("rain");
			int waterSoundID = PlayStereoSoundLooped_JustCache("water_sea");
			SendMessage(Sound,"llf",MSG_SOUND_SET_VOLUME, waterSoundID, 0.6);
			SendMessage(Sound,"lll",MSG_SOUND_RESUME, waterSoundID, 0);
		}
		else
		{
			AddSoundScheme("sea_weather");
			int water2SoundID = PlayStereoSoundLooped_JustCache("water_sea");
			SendMessage(Sound,"llf",MSG_SOUND_SET_VOLUME, water2SoundID, 0.35);
			SendMessage(Sound,"lll",MSG_SOUND_RESUME, water2SoundID, 0);
		}
	}
	ResumeAllSounds();
}

void SetSchemeForMap ()
{
	ResetSoundScheme();
	AddSoundScheme("sea_map");
	SetMusic("music_map");
	ResumeAllSounds();

	int water2SoundID = PlayStereoSoundLooped_JustCache("water_sea");
	SendMessage(Sound,"llf",MSG_SOUND_SET_VOLUME, water2SoundID, 0.05);
	SendMessage(Sound,"lll",MSG_SOUND_RESUME, water2SoundID, 0);
}

// MUSIC
int musicID = 0;
int oldMusicID = 0;
string musicName = "";
string oldMusicName = "";
void SetMusic(string name)
{
	//return;
	InitSound();
	Trace("SETTING MUSIC: "+name);
	if (name == musicName)
	{
		SendMessage(Sound,"lll",MSG_SOUND_RESUME, musicID, SOUNDS_FADE_TIME);
		return;
	}

	//Trace("SetMusic : "+name);
	if (oldMusicID)
	{
		SendMessage(Sound,"ll",MSG_SOUND_RELEASE, oldMusicID);
	}

	if (musicID)
	{
		SendMessage(Sound,"lll",MSG_SOUND_STOP, musicID, MUSIC_CHANGE_TIME);
		oldMusicID = musicID;
	}

	int silenceTime = 20000 + MakeInt(frnd()*MUSIC_SILENCE_TIME);
	musicID = SendMessage(Sound,"lslllllll",MSG_SOUND_PLAY, name, SOUND_MP3_STEREO, VOLUME_MUSIC, true, true, false, MUSIC_CHANGE_TIME, silenceTime);
	SendMessage(Sound,"llf",MSG_SOUND_SET_VOLUME, musicID, 0.55);
	SendMessage(Sound,"lll",MSG_SOUND_RESUME, musicID, MUSIC_CHANGE_TIME);
	
	oldMusicName = musicName;
	musicName = name;
}

void FadeOutMusic(int _time)
{
	if (musicID)
	{
		StopSound(musicID,_time);
		musicID = 0;
		musicName = "";
	}
}

// RELOAD
void PauseAllSounds()
{
	Trace("PauseAllSounds");
	SendMessage(Sound,"lll",MSG_SOUND_STOP, 0, SOUNDS_FADE_TIME);
}

void ResumeAllSounds()
{
	Trace("ResumeAllSounds");
	SendMessage(Sound,"lll",MSG_SOUND_RESUME, musicID, SOUNDS_FADE_TIME);
}

// OLD VERSIONS
int PlaySoundDist3D(string name, float x, float y, float z)
{
	return Play3DSound(name, x,y,z);
}

int PlaySoundLoc3D(string name, float x, float y, float z)
{
	return Play3DSoundCached(name, x,y,z);
}

int PlaySound3D(string name, float x, float y, float z)
{
	return Play3DSound(name, x,y,z);
}

int PlaySound(string name)
{
	return PlayStereoSound(name);
}

int PlaySoundComplex(string sSoundName, bool bSimpleCache, bool bLooped, bool bCached, int iFadeTime)
{
	return SendMessage(Sound,"lsllllll",MSG_SOUND_PLAY,VOLUME_FX,sSoundName,SOUND_WAV_3D,bSimpleCache,bLooped,bCached,iFadeTime);
}

void StopMusic()
{
}

void PlayMusic(string n)
{
}
//--------------------------------------------------------------------
// Sound Section
//--------------------------------------------------------------------
object Sound;

int alarmed = 0;
int oldAlarmed = 0;
bool seaAlarmed = false;
bool oldSeaAlarmed = false;
void SetMusicAlarm(string name)
{
	if (alarmed == 0)
	{
		SetMusic(name);
	}
	else
	{
		SetMusic("music_bitva");
	}
}

void Sound_OnAllarm()
{
	Sound_OnAlarm(GetEventData());
}

void Sound_OnAlarm(bool _alarmed)
{
	alarmed = _alarmed;
	if (alarmed == oldAlarmed)
		return;

	if (alarmed != 0)
	{ //alarm on!
		SetMusic("music_bitva");
	}
	else
	{ //alarm off
		SetMusic(oldMusicName);
	}
	oldAlarmed = alarmed;
}

void Sound_OnSeaAlarm(bool _seaAlarmed)
{
	seaAlarmed = _seaAlarmed;
	if (seaAlarmed == oldSeaAlarmed)
		return;

	if (seaAlarmed)
	{ //alarm on!
		SetMusic("music_sea_battle");
	}
	else
	{ //alarm off
		SetMusic(oldMusicName);
	}
	oldSeaAlarmed = seaAlarmed;
}

void InitSound()
{
	//Trace("InitSound");
	if (!IsEntity(&Sound))
	{
		CreateEntity(&Sound, "Sound");
		SetEventHandler("eventAllarm", "Sound_OnAllarm", 0);
	}
	//SendMessage(Sound,"lf",MSG_SOUND_SET_MASTER_VOLUME,1.0);
}

void ResetSound()
{
	ResetSoundScheme();
	StopSound(0,0);
	ReleaseSound(0);
	musicName = "";
	oldMusicName = "";
}

void LoadSceneSound()
{
	int i = FindLoadedLocation();
	if (i != -1)
		SetSchemeForLocation(&Locations[i]);
}

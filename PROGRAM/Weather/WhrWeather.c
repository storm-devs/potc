#include "weather\WhrUtils.c"
#include "weather\WhrLightning.c"
#include "weather\WhrRain.c"
#include "weather\WhrSea.c"
#include "weather\WhrSky.c"
#include "weather\WhrSun.c"
#include "weather\WhrTornado.c"

#define WIND_NORMAL_POWER		20.0

#define MAX_WEATHERS			16

object	Weather, WeatherParams, WhrCommonParams;
int		iNextWeatherNum = -1;
int		iCurWeatherNum = -1;
int		iCurWeatherHour = -1;
bool	bCurWeatherStorm = false;
int		iTotalNumWeathers = 0;
string	sLightingPath = "day";
string	sLmLightingPath = "day";
string	sInsideBack = "";
int	sNewExecuteLayer, sNewRealizeLayer;
string	sCurrentFog;
float	fWeatherDelta = 0.0;
float	fWeatherAngle, fWeatherSpeed;
float	fFogDensity;
int		iShadowDensity[2];
bool	bWeatherLoaded = false;
bool	bWeatherIsNight = false;
bool	bWeatherIsLight = false;
bool	bWeatherIsRain = false;
bool	bWeatherIsStorm = false;

object Weathers[MAX_WEATHERS];

extern int InitWeather();

#event_handler("EWhr_GetWindAngle", "Whr_GetWindAngle");
#event_handler("EWhr_GetWindSpeed", "Whr_GetWindSpeed");
#event_handler("EWhr_GetShadowDensity", "Whr_GetShadowDensity");
#event_handler("EWhr_GetFogDensity", "Whr_GetFogDensity");

void SetNextWeather(string sWeatherID)
{
	// find weather
	iNextWeatherNum = -1;
	for (int i=0; i<MAX_WEATHERS; i++)
	{
		if (!CheckAttribute(&Weathers[i], "id")) { continue; }
		if (Weathers[i].id == sWeatherID)
		{
			iNextWeatherNum = i;
			//Trace("iNextWeatherNum = " + iNextWeatherNum);
			return;
		}
	}
}

void WeatherInit()
{
	DeleteAttribute(&WeatherParams,"");

	if (LoadSegment("weather\WhrInit.c"))
	{
		iTotalNumWeathers = InitWeather();
		UnloadSegment("weather\WhrInit.c");
	}
}

void DeleteWeatherEnvironment()
{
	if (isEntity(&Weather))
	{
		DeleteClass(&Weather);
	}
	DeleteAttribute(&Weather,"");
	WeatherParams.Tornado = false;
	//DeleteAttribute(&WeatherParams,"");

	WhrDeleteRainEnvironment();
	WhrDeleteSkyEnvironment();
	WhrDeleteSunGlowEnvironment();
	WhrDeleteLightningEnvironment();
	WhrDeleteTornadoEnvironment();
	WhrDeleteSeaEnvironment();

	DelEventHandler(WEATHER_CALC_FOG_COLOR,"Whr_OnCalcFogColor");
	DelEventHandler("frame","Whr_OnWindChange");

	bWeatherLoaded = false;
}

aref GetCurrentWeather()
{
	aref arWeather;
	makearef(arWeather,Weathers[iCurWeatherNum]);
	return arWeather;
}

void CreateWeatherEnvironment()
{
	int iWeatherFound[MAX_WEATHERS];
	int iNumWeatherFound = 0;
	int iHour = MakeInt(GetHour());

	bool bWhrStorm = false;
	bool bWhrTornado = false;
	if (CheckAttribute(&WeatherParams,"Storm")) { bWhrStorm = sti(WeatherParams.Storm); }
	if (CheckAttribute(&WeatherParams,"Tornado")) { bWhrTornado = sti(WeatherParams.Tornado); }

	//Trace("bCurWeatherStorm = " + bCurWeatherStorm);
	if (iNextWeatherNum != -1)
	{
		iCurWeatherHour = iHour;
		iCurWeatherNum = iNextWeatherNum;
		iNextWeatherNum = -1;
	}
	else
	{
		if (iCurWeatherHour == iHour && bCurWeatherStorm == bWhrStorm)
		{
		}
		else
		{
			// search weather for hour
			for (int i=0;i<MAX_WEATHERS;i++)
			{
				if (!CheckAttribute(&Weathers[i], "hour")) { continue; }
				if (CheckAttribute(&Weathers[i], "skip"))
				{
					if (sti(Weathers[i].skip)) { continue; }
				}

				bool bCanStorm = sti(Weathers[i].Storm);
				bool bCanTornado = sti(Weathers[i].Tornado);
				int iMin = sti(Weathers[i].Hour.Min);
				int iMax = sti(Weathers[i].Hour.Max);
				if (iMin == iMax && iMin != iHour) { continue; }
				if (iMin > iMax)
				{
					if (iHour < iMin && iHour > iMax) { continue; }
				}
				if (iMin < iMax)
				{
					if (iHour < iMin || iHour > iMax) { continue; }
				}
				if (bWhrStorm != bCanStorm) { continue; }
				if (bWhrTornado == true && bWhrTornado != bCanTornado) { continue; }

				iWeatherFound[iNumWeatherFound] = i;
				iNumWeatherFound++;
			}

			iCurWeatherHour = iHour;
			WeatherParams.Tornado = false;

			if (iNumWeatherFound == 0)
			{
				Trace("Error: iNumWeatherFound = 0, for hour = " + iHour);
				iCurWeatherNum = 0;
			}
			else
			{
				iCurWeatherNum = iWeatherFound[rand(iNumWeatherFound-1)];
			}
		}
	}

	if (bStorm)
	{
		//Trace("Whr: Storm: Hour = " + iHour);
		//Trace("Whr: Storm: Weather num = " + iCurWeatherNum);
	}

	// TEMP TEMP TEMP TEMP TEMP TEMP TEMP TEMP TEMP TEMP TEMP TEMP TEMP TEMP
	/*if (!bSeaActive)
	{
		iCurWeatherHour = iHour;
		iCurWeatherNum = 0;
	}*/
	// TEMP TEMP TEMP TEMP TEMP TEMP TEMP TEMP TEMP TEMP TEMP TEMP TEMP TEMP

	bWeatherIsStorm = bWhrStorm;
	bCurWeatherStorm = bWhrStorm;

	// create main module Weather
	DeleteAttribute(&Weather,"");
	if (!isEntity(&Weather))
	{
		CreateEntity(&Weather, "Weather");
	}

	aref aCurWeather = GetCurrentWeather();

	sLightingPath = Whr_GetString(aCurWeather,"Lighting");
	sLmLightingPath = Whr_GetString(aCurWeather,"LightingLm");
	sInsideBack = Whr_GetString(aCurWeather,"InsideBack");
	bWeatherIsNight = Whr_GetLong(aCurWeather,"Night");
	bWeatherIsLight = Whr_GetLong(aCurWeather,"Lights");

	Weather.Wind.Angle = Whr_GetFloat(aCurWeather,"Wind.Angle");
	Weather.Wind.Speed = Whr_GetFloat(aCurWeather,"Wind.Speed");

	sCurrentFog = "Fog";
	if (bSeaActive)
	{
		if (CheckAttribute(aCurWeather, "SpecialSeaFog")) { sCurrentFog = "SpecialSeaFog"; }
	}

	string sCurFog = Whr_GetCurrentFog();
	Weather.Fog.Enable = Whr_GetLong(aCurWeather, sCurFog + ".Enable");
	Weather.Fog.Start = Whr_GetFloat(aCurWeather, sCurFog + ".Start");
	Weather.Fog.Density = Whr_GetFloat(aCurWeather, sCurFog + ".Density");
	Weather.Fog.Color = Whr_GetColor(aCurWeather, sCurFog + ".Color");

	Weather.Sun.Color = Whr_GetColor(aCurWeather,"Sun.Color");
	Weather.Sun.HeightAngle = Whr_GetFloat(aCurWeather,"Sun.HeightAngle");
	Weather.Sun.AzimuthAngle = Whr_GetFloat(aCurWeather,"Sun.AzimuthAngle");
	Weather.Sun.Ambient = Whr_GetColor(aCurWeather,"Sun.Ambient");

	Weather.isDone = "";

	SetEventHandler(WEATHER_CALC_FOG_COLOR,"Whr_OnCalcFogColor",0);
	SetEventHandler("frame","Whr_OnWindChange",0);

	fFogDensity = stf(Weather.Fog.Density);

	fWeatherDelta = 0.0;
	fWeatherAngle = stf(Weather.Wind.Angle);
	fWeatherSpeed = stf(Weather.Wind.Speed);

	WhrCreateRainEnvironment();
	WhrCreateSunGlowEnvironment();
	WhrCreateLightningEnvironment();
	WhrCreateSkyEnvironment();
	WhrCreateSeaEnvironment();
	if (bWhrTornado) { WhrCreateTornadoEnvironment(); }

	Particles.windpower = 0.05 * Clampf(Whr_GetWindSpeed() / WIND_NORMAL_POWER);
	Particles.winddirection.x = sin(Whr_GetWindAngle());
	Particles.winddirection.z = cos(Whr_GetWindAngle());

	bWeatherLoaded = true;

	//Trace("Whr: Select id = " + aCurWeather.id);
}

void Whr_UpdateWeather()
{
	WeatherInit();

	CreateWeatherEnvironment();
	MoveWeatherToLayers(sNewExecuteLayer, sNewRealizeLayer);
}

void Whr_LoadNextWeather(int nPlus)
{
	WeatherInit();

	iCurWeatherHour = MakeInt(GetHour());
	iCurWeatherNum = iCurWeatherNum + nPlus;

	if (iCurWeatherNum < 0)
	{
		iCurWeatherNum = iTotalNumWeathers - 1;
	}
	if (iCurWeatherNum >= iTotalNumWeathers)
	{
		iCurWeatherNum = 0;
	}

	if (CheckAttribute(&Weathers[iCurWeatherNum], "Skip"))
	{
		if (sti(Weathers[iCurWeatherNum].skip))
		{
			Whr_LoadNextWeather(nPlus);
			return;
		}
	}

	CreateWeatherEnvironment();
	MoveWeatherToLayers(sNewExecuteLayer, sNewRealizeLayer);

	aref	aCurWeather = GetCurrentWeather();
	iCurWeatherHour = sti(aCurWeather.Hour.Min);

	SetCurrentTime(iCurWeatherHour, 0);

	Island.LightingPath = GetLightingPath();
}

void Whr_OnWindChange()
{
	float fDeltaTime = MakeFloat(GetDeltaTime()) * 0.001;
	fWeatherDelta = fWeatherDelta + fDeltaTime;

	float fSpd = fWeatherSpeed + (fWeatherSpeed / 6.0) * 0.1 * (sin(fWeatherDelta) + sin(0.2 * fWeatherDelta) + sin(PI + 0.8 * fWeatherDelta) + cos(1.5 * fWeatherDelta));
	float fAng = fWeatherAngle + 0.02 * (sin(fWeatherDelta) + sin(0.2 * fWeatherDelta) + sin(PI + 0.8 * fWeatherDelta) + cos(1.5 * fWeatherDelta));

	Weather.Wind.Angle = fAng;
	Weather.Wind.Speed = fSpd;
}

int Whr_OnCalcFogColor()
{
	int		iAlpha, iColor;
	float	x, y, z;
	aref	aCurWeather = GetCurrentWeather();

	x = GetEventData();
	y = GetEventData();
	z = GetEventData();

	iAlpha = 255 - MakeInt(255.0 * Clampf(y / stf(aCurWeather.(sCurrentFog).Height)));

	//iColor = argb(0,0,0,0);
	int iFogColor = sti(Weather.Fog.Color);
	iColor = or(shl(iAlpha, 24), iFogColor);
	return iColor;
}

void CreateWeather(int sExecuteLayer, int sRealizeLayer)
{
	CreateWeatherEnvironment();
	MoveWeatherToLayers(sExecuteLayer, sRealizeLayer);
}

void DeleteWeather()
{
	DeleteWeatherEnvironment();
}

void MoveWeatherToLayers(int sExecuteLayer, int sRealizeLayer)
{
	LayerDelObject(EXECUTE, &Weather);
	LayerDelObject(REALIZE, &Weather);
	LayerDelObject(SEA_EXECUTE,&Weather);
	LayerDelObject(SEA_REALIZE,&Weather);

	sNewExecuteLayer = sExecuteLayer;
	sNewRealizeLayer = sRealizeLayer;

	LayerAddObject(sExecuteLayer,&Weather,1000000);
	LayerAddObject(sRealizeLayer,&Weather,65530);

	MoveRainToLayers(sExecuteLayer, sRealizeLayer);
	MoveLightningToLayers(sExecuteLayer, sRealizeLayer);
	MoveSkyToLayers(sExecuteLayer, sRealizeLayer);
	MoveSunGlowToLayers(sExecuteLayer, sRealizeLayer);
}

float Whr_GetFogDensity() { return fFogDensity; }

float Whr_GetWindAngle()
{
	if (!CheckAttribute(Weather,"Wind.Angle")) { return 0.0; }
	return stf(Weather.Wind.Angle);
}

float Whr_GetWindSpeed()
{
	if (!CheckAttribute(Weather,"Wind.Speed")) { return 0.0; }
	return stf(Weather.Wind.Speed);
}

ref Whr_GetShadowDensity()
{
	aref	aCurWeather = GetCurrentWeather();

	iShadowDensity[0] = argb(255,96,96,96);
	iShadowDensity[1] = argb(255,96,96,64);

	if (bWeatherLoaded)
	{
		iShadowDensity[0] = Whr_GetColor(aCurWeather,"Shadow.Density.Head");
		iShadowDensity[1] = Whr_GetColor(aCurWeather,"Shadow.Density.Foot");
	}

	return &iShadowDensity;
}

string	Whr_GetCurrentFog() { return sCurrentFog; }

string	Whr_GetInsideBack() { return sInsideBack; }
string	GetLightingPath()	{ return sLightingPath; }
string	GetLmLightingPath() { return sLmLightingPath; }

bool	Whr_IsDay() { return !bWeatherIsNight; };
bool	Whr_IsNight() { return bWeatherIsNight; };
bool	Whr_IsLight() { return bWeatherIsLight; };
bool	Whr_IsRain() { return bWeatherIsRain; }
bool	Whr_IsStorm() { return bWeatherIsStorm; }

object Sky;

void WhrDeleteSkyEnvironment()
{
	if (isEntity(&Sky))
	{
		DeleteClass(&Sky);
	}
	DeleteAttribute(&Sky,"");
}

void WhrCreateSkyEnvironment()
{
	aref aCurWeather = GetCurrentWeather();
	aref aSky; makearef(aSky,aCurWeather.Sky);

	DeleteAttribute(&Sky,"");
	if (!isEntity(&Sky))
	{
		CreateEntity(&Sky,"Sky");
		LayerAddObject("sea_reflection",&Sky,1);
	}

	Sky.Dir = Whr_GetString(aSky,"Dir");
	Sky.Color = Whr_GetColor(aSky,"Color");
	Sky.RotateSpeed = Whr_GetFloat(aSky,"Rotate");
	Sky.Angle = Whr_GetFloat(aSky,"Angle");
	Sky.Size = Whr_GetFloat(aSky,"Size");

	Sky.isDone = "";
}

void MoveSkyToLayers(string sExecuteLayer, string sRealizeLayer)
{
	LayerDelObject("execute",&Sky);
	LayerDelObject("realize",&Sky);
	LayerDelObject(SEA_EXECUTE,&Sky);
	LayerDelObject(SEA_REALIZE,&Sky);

	LayerAddObject(sExecuteLayer,&Sky,2);
	LayerAddObject(sRealizeLayer,&Sky,2);
}
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
		LayerAddObject(SEA_REFLECTION, &Sky,1);
	}

	DeleteAttribute(&Sky,"Dir");
	Sky.Dir.d1 = aCurWeather.Sky.Dir;
	Sky.Dir = Whr_GetString(aSky,"Dir");

	Sky.Color = Whr_GetColor(aSky,"Color");
	Sky.RotateSpeed = Whr_GetFloat(aSky,"Rotate");
	Sky.Angle = Whr_GetFloat(aSky,"Angle");
	Sky.Size = Whr_GetFloat(aSky,"Size");

	Sky.isDone = "";
}

void MoveSkyToLayers(int sExecuteLayer, int sRealizeLayer)
{
	LayerDelObject(EXECUTE, &Sky);
	LayerDelObject(REALIZE, &Sky);
	LayerDelObject(SEA_EXECUTE,&Sky);
	LayerDelObject(SEA_REALIZE,&Sky);

	LayerAddObject(sExecuteLayer,&Sky,2);
	LayerAddObject(sRealizeLayer,&Sky,2);
}

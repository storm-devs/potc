bool	bAbordageStarted = false;
bool	bAbordageFortCanBe;
bool	bAbordagePlaceShipNear = false;
bool	bMCAbordageInitiator = true;
string	sAbordageLocator;
int		iAbordageFortEnemyCharacter; /*, iAbordageOurCharacter*/
int		iAbordageCharacter;
int		iAbordageMode;
float	fOldMaxSeaHeight;

void DeleteAbordageEnvironment()
{
	DelEventHandler(ABORDAGE_CAN_BE,"Abordage_CanBe");
}

void CreateAbordageEnvironment()
{
	bAbordageStarted = false;
	SetEventHandler(ABORDAGE_CAN_BE,"Abordage_CanBe",0);
	bAbordageFortCanBe = false;
}

void Abordage_CanBe()
{
	//bAbordageCanBe = GetEventData();
	//iAbordageOurCharacter = GetEventData();
	//iAbordageEnemyCharacter = GetEventData();
}

void Abordage_ReloadStartFade()
{
	int a = GetEventData();
	aref reload_fader = GetEventData();
	LayerFreeze(SEA_EXECUTE,true);
	LayerFreeze(SEA_REALIZE,true);
	LayerFreeze("sea_reflection",true);
	LayerFreeze("execute",false);
	LayerFreeze("realize",false);

	MoveWeatherToLayers("execute", "realize");
	MoveSeaToLayers("execute", "realize");

	SendMessage(&AIBalls, "l", MSG_MODEL_RELEASE);

	DelEventHandler("FaderEvent_StartFade", "Abordage_ReloadStartFade");

	fOldMaxSeaHeight = stf(Sea.MaxSeaHeight);
	Sea.MaxSeaHeight = 1.2;						// set maxinum sea height for ship abordage
}

void Go2LocationAfterAbordage()
{
	Sea.MaxSeaHeight = fOldMaxSeaHeight;		// restore old MaxSeaHeight
	bAbordageStarted = false;
	bSeaReloadStarted = false;
	Sea.AbordageMode = false;

	PauseParticles(false);
	LayerFreeze("sea_reflection", false);

	Sea.MaxSeaHeight = fOldMaxSeaHeight;		// restore old MaxSeaHeight
}

void Return2SeaAfterAbordage()
{
	// load all models back to sea
	aref arModel;
	if (FindClass(&arModel, "modelr")) 
	{
		SendMessage(arModel, "l", MSG_MODEL_RESTORE);
		while (FindClassNext(&arModel)) 
		{ 
			//Trace("XYZ");
			SendMessage(arModel, "l", MSG_MODEL_RESTORE); 
		}
	}

	LayerFreeze("execute",true);
	LayerFreeze("realize",true);

	LayerFreeze("sea_reflection", false);
	LayerFreeze(SEA_EXECUTE,false);
	LayerFreeze(SEA_REALIZE,false);

	MoveWeatherToLayers(SEA_EXECUTE, SEA_REALIZE);
	MoveSeaToLayers(SEA_EXECUTE, SEA_REALIZE);

	Sea.MaxSeaHeight = fOldMaxSeaHeight;		// restore old MaxSeaHeight
	bAbordageStarted = false;
	Sea.AbordageMode = false;

	InitBattleInterface();
	StartBattleInterface();
	RefreshBattleInterface();

	SetSchemeForSea();

	PauseParticles(false);

	bSeaReloadStarted = false;
}

void Abordage_ReloadEndFade()
{
	float fHP, fHP1, fHP2;

	// Delete current cannonballs
	AIBalls.Clear = "";

	// unload all models
	aref arModel;
	if (FindClass(&arModel, "modelr")) 
	{
		SendMessage(arModel, "l", MSG_MODEL_RELEASE);
		while (FindClassNext(&arModel)) { SendMessage(arModel, "l", MSG_MODEL_RELEASE); }
	}

	if (bAbordagePlaceShipNear)
	{
		SendMessage(AISea, "laff", AI_MESSAGE_SAIL_2_CHARACTER, &Characters[iAbordageCharacter], 40.0 + frnd() * 60.0, frnd() * PIm2);
	}

	PauseParticles(true);

	// start abordage location
	int a = GetEventData();
	aref reload_fader = GetEventData();
	switch (iAbordageMode)
	{
		case FORT_ABORDAGE:
			DeleteSeaEnvironment();
			LAi_StartBoarding(BRDLT_FORT, &Characters[iAbordageCharacter], true);
		break;
		case SHIP_ABORDAGE:
			// calc & apply abordage damage for ships
				fHP1 = stf(Characters[iAbordageCharacter].Ship.HP);
				fHP2 = stf(Characters[GetMainCharacterIndex()].Ship.HP);
				fHP = 0.1 + frnd() * 0.2;
				if (fHP1 > fHP2) { fHP = fHP * fHP2; }
				if (fHP1 < fHP2) { fHP = fHP * fHP1; }

				bSeaReloadStarted = false;
				Ship_ApplyHullHitpoints(&Characters[iAbordageCharacter], fHP * (1.05 - stf(Characters[iAbordageCharacter].TmpSkill.Sneak)), KILL_BY_TOUCH, -1);
				Ship_ApplyHullHitpoints(&Characters[GetMainCharacterIndex()], fHP * (1.05 - stf(Characters[GetMainCharacterIndex()].TmpSkill.Sneak)), KILL_BY_TOUCH, -1);
				bSeaReloadStarted = true;

			// load boarding
				LAi_StartBoarding(BRDLT_SHIP, &Characters[iAbordageCharacter], bMCAbordageInitiator);
		break;
	}
	DelEventHandler("FaderEvent_EndFade", "Abordage_ReloadEndFade");
	SendMessage(&reload_fader, "lfl", FADER_IN, RELOAD_TIME_FADE_IN, true);
}

void Sea_AbordageLoad(int _iAbordageMode, bool _bMCAbordageInitiator)
{
	if (bSeaActive == false) { return; }

	if (_iAbordageMode == FORT_ABORDAGE && !bAbordageFortCanBe) { return; }
	if (_iAbordageMode == SHIP_ABORDAGE && !bAbordageShipCanBe) { return; }

	int _iAbordageCharacter = iAbordageShipEnemyCharacter;
	if (_iAbordageMode == FORT_ABORDAGE) { _iAbordageCharacter = iAbordageFortEnemyCharacter; }

	Sea_AbordageStartNow(_iAbordageMode, _iAbordageCharacter, false, _bMCAbordageInitiator);
}

void Sea_AbordageStartNow(int _iAbordageMode, int _iAbordageCharacter, bool _bPlaceOurShipNear, bool _bMCAbordageInitiator)
{
	bSeaReloadStarted = true;

	iAbordageCharacter = _iAbordageCharacter;
	iAbordageMode = _iAbordageMode;
	bAbordagePlaceShipNear = _bPlaceOurShipNear;
	bMCAbordageInitiator = _bMCAbordageInitiator;

	object reload_fader;
	CreateEntity(&reload_fader, "fader");
	SetEventHandler("FaderEvent_StartFade", "Abordage_ReloadStartFade", 0);
	SetEventHandler("FaderEvent_EndFade", "Abordage_ReloadEndFade", 0);

	SendMessage(&reload_fader, "ls", FADER_PICTURE, LAi_GetBoardingImage(GetCharacter(iAbordageCharacter), bMCAbordageInitiator));
	SendMessage(&reload_fader, "lfl", FADER_OUT, 1.0, false);
	SendMessage(&reload_fader, "l", FADER_STARTFRAME);

	PauseAllSounds();
	ResetSoundScheme();

	Event(ABORDAGE_START_EVENT, "ll", GetMainCharacterIndex(), iAbordageCharacter);

	bAbordageStarted = true;
	Sea.AbordageMode = true;
}


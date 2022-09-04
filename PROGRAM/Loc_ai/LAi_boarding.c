

#define BRDLT_SHIP	0
#define BRDLT_FORT	1

#define BRDLT_MAXCREW	24

#define LOCINITBRD_DEFAULTLOCATION "ship default deck"
#define LOCINITBRD_DEFAULTLOCATION_FORT "fort default deck"


int boarding_location = -1;
int boarding_location_type = -1;
object boarding_fader;
int boarding_enemy_crew = 0;
int boarding_player_crew = 0;
int boarding_enemy_base_crew = 0;
int boarding_officers = 0;
float boarding_player_crew_per_chr = 1.0;
ref boarding_enemy;
object boarding_adr[4];
float boarding_exp = 0;
float boarding_player_hp = 40;
float boarding_enemy_hp = 40;
int boarding_echr_index = -1;
int boarding_erank = 10;

bool LAi_boarding_process = false;

//Процес абордажа
bool LAi_IsBoardingProcess()
{
	return LAi_boarding_process;
}

//Получить картинку для перехода в абордаж
string LAi_GetBoardingImage(ref echr, bool isMCAttack)
{
	ref mchr = GetMainCharacter();
	string deckID = "";
	if(isMCAttack)
	{
		deckID = GetShipLocationID(echr);
	}else{
		deckID = GetShipLocationID(mchr);
	}
	int locID = -1;
	if(deckID != "")
	{
		locID = FindLocation(deckID);
		if(locID < 0)
		{
			Trace("Boarding: ship location not found <" + deckID + ">, set default");
			deckID = "";
		}
	}
	if(locID >= 0)
	{
		if(CheckAttribute(&Locations[locID], "image"))
		{
			if(Locations[locID].image != "")
			{
				return Locations[locID].image;
			}
		}
	}
	return "loading\battle.tga";
}

//Начать абордаж с главным персонажем
void LAi_StartBoarding(int locType, ref echr, bool isMCAttack)
{
	ResetSoundScheme();
	PauseAllSounds();
	if(locType == BRDLT_FORT) isMCAttack = true;
	//Установим обработчик на убийство группы
	SetEventHandler("LAi_event_GroupKill", "LAi_BoardingGroupKill", 1);
	//Настроим интерфейс
	DeleteBattleInterface();
	StartBattleLandInterface();
	//Сохраним индекс врага
	boarding_echr_index = sti(echr.index);
	//Параметры сражающихся сторон	
	ref mchr = GetMainCharacter();
	int mclass = GetCharacterShipClass(mchr);
	int mcrew = GetCrewQuantity(mchr);
	int eclass = GetCharacterShipClass(echr);
	int ecrew = GetCrewQuantity(echr) + 1;
	if(ecrew < 1) ecrew = 1;
	boarding_erank = sti(echr.rank);
	boarding_enemy_base_crew = ecrew;
	//Количество хитпойнтов
	boarding_player_hp = LAi_GetCharacterMaxHP(mchr);
	float moral;
	if(CheckAttribute(mchr, "ship.crew.moral"))
	{
		moral = (stf(mchr.ship.crew.moral) - MORALE_NORMAL)/(MORALE_MAX - MORALE_MIN);
		if(moral < -0.5) moral = -0.5;
		if(moral > 0.5) moral = 0.5;
		boarding_player_hp = boarding_player_hp*(moral*0.3 + 1.0);
	}
	boarding_enemy_hp = LAi_GetCharacterMaxHP(echr);
	if(CheckAttribute(echr, "ship.crew.moral"))
	{
		moral = (stf(echr.ship.crew.moral) - MORALE_NORMAL)/(MORALE_MAX - MORALE_MIN);
		if(moral < -0.5) moral = -0.5;
		if(moral > 0.5) moral = 0.5;
		boarding_enemy_hp = boarding_enemy_hp*(moral*0.3 + 1.2);
	}
	//Расчитаем получаемый опыт в случае победы
	boarding_exp = 0.0;
	if(CheckAttribute(echr, "rank"))
	{
		boarding_exp = stf(echr.rank)*100.0;
		if(boarding_exp < 0.0) boarding_exp = 0.0;
	}
	boarding_exp = 100.0 + boarding_exp + 10.0*ecrew*(LAi_GetCharacterFightLevel(echr)*9.0 + 1.0)/(LAi_GetCharacterFightLevel(mchr)*9.0 + 1.0);
	//Определяем цепь локаций для абордажа
	boarding_location = -1;
	boarding_location_type = locType;
	string deckID = "";
	if(isMCAttack)
	{
		deckID = GetShipLocationID(echr);
	}else{
		deckID = GetShipLocationID(mchr);
	}
	int locID = -1;
	if(deckID != "")
	{
		locID = FindLocation(deckID);
		if(locID < 0)
		{
			Trace("Boarding: ship location not found <" + deckID + ">, set default");
			deckID = "";
		}
	}
	if(deckID == "")
	{
		if(locType == BRDLT_FORT)
		{
			deckID = LOCINITBRD_DEFAULTLOCATION_FORT;
		}else{
			deckID = LOCINITBRD_DEFAULTLOCATION;
		}
		locID = FindLocation(deckID);
	}
	if(locID < 0)
	{
		Trace("Boarding: ship location not found <" + deckID + ">, no start boarding");
		if(boarding_location_type == BRDLT_SHIP)
		{
			LaunchRansackMain(GetMainCharacter(), echr, "");
			LAi_boarding_process = false;
		}else{
			if(boarding_location_type == BRDLT_FORT)
			{
				LaunchFortCapture(echr);
				LAi_boarding_process = false;
			}else{
				Trace("Boarding: unknow boarding location type");
			}
		}
		return;
	}
	//Определяем размеры команд
	boarding_enemy = echr;
	//Максимальное количество человек на корабле
	int maxcrew = 4;
	while(maxcrew < BRDLT_MAXCREW)
	{
		if(!CheckAttribute(&Locations[locID], "boarding.nextdeck")) break;
		if(Locations[locID].boarding.nextdeck == "") break;
		locID = FindLocation(Locations[locID].boarding.nextdeck);
		if(locID < 0) break;
		maxcrew = maxcrew + 4;
	}
	//Отношение сторон
	float curplayercrew = mcrew;
	if(mcrew < 1) mcrew = 1;
	if(ecrew < 1) ecrew = 1;
	//Максимальное количество человек
	float rel;
	if(mcrew > ecrew)
	{
		if(mcrew > maxcrew)
		{
			rel = mcrew/maxcrew;
			mcrew = maxcrew;
			ecrew = MakeInt(ecrew/rel + 0.5);
		}
	}else{
		if(ecrew > maxcrew)
		{
			rel = ecrew/maxcrew;
			ecrew = maxcrew;
			mcrew = MakeInt(mcrew/rel + 0.5);
		}
	}
	if(mcrew < 1) mcrew = 1;
	if(ecrew < 1) ecrew = 1;
	boarding_enemy_crew = ecrew;
	boarding_player_crew = mcrew;
	//Количество офицеров
	boarding_officers = 0;
	for(int i = 1; i < 4; i++)
	{
		if(GetOfficersIndex(GetMainCharacter(), i) >= 0)
		{
			boarding_officers = boarding_officers + 1;
		}
	}
	boarding_player_crew_per_chr = (curplayercrew + boarding_officers + 1)/(mcrew + boarding_officers + 1);
	//Выставим игроку и офицерам максимальную жизнь и запомним адреса
	LAi_SetCurHPMax(mchr);
	boarding_adr[0].location = mchr.location;
	boarding_adr[0].group = mchr.location.group;
	boarding_adr[0].locator = mchr.location.locator;
	for(i = 1; i < 4; i++)
	{
		int idx = GetOfficersIndex(GetMainCharacter(), i);
		if(idx < 0)
		{
			boarding_adr[i].location = "";
			boarding_adr[i].group = "";
			boarding_adr[i].locator = "";
			continue;
		}
		LAi_SetCurHPMax(&Characters[idx]);
		boarding_adr[i].location = Characters[idx].location;
		boarding_adr[i].group = Characters[idx].location.group;
		boarding_adr[i].locator = Characters[idx].location.locator;
	}
	//Стартуем
	LAi_boarding_process = true;
	LAi_LoadLocation(deckID);
	CreateEntity(&boarding_fader, "fader");
	SendMessage(&boarding_fader, "lfl", FADER_IN, RELOAD_TIME_FADE_IN, true);
	//!!!
	//LAi_SetImmortal(mchr, true);
}

//Загрузить локацию абордажа
void LAi_LoadLocation(string locationID)
{
	ReloadProgressStart();
	//Ищем локацию
	int locIndex = FindLocation(locationID);
	Log_SetActiveAction("Nothing");
	if(locIndex >= 0)
	{
		//Устанавливаем главного персонажа
		ref mchr = GetMainCharacter();
		mchr.location = locationID;
		mchr.location.group = "rld";
		mchr.location.locator = "loc0";
		//Устанавливаем офицеров, если такие есть
		int logined = 1;
		for(int i = 1; i < 4; i++)
		{
			int idx = GetOfficersIndex(GetMainCharacter(), i);
			if(idx < 0) continue;
			DeleteAttribute(&Characters[idx], "location");
			Characters[idx].location = locationID;
			Characters[idx].location.group = "rld";
			Characters[idx].location.locator = "loc" + logined;
			logined = logined + 1;
		}
		//Перегружаемся в локацию
		boarding_location = locIndex;
		if(LoadLocation(&Locations[boarding_location]))
		{
			//Вытащим саблю
			SendMessage(&mchr, "lsl", MSG_CHARACTER_EX_MSG, "SetFightMode", 1);
			//Расставляем персонажей
			LAi_SetBoardingActors(locationID);
			//Запретим диалог
			dialogDisable = true;
		}else{
			Trace("Boarding: Boarding location not loaded, current loc <" + locationID + ">");
		}
	}else{
		Trace("Boarding: Boarding location not found, current loc <" + locationID + ">");
	}
	ReloadProgressEnd();
	PostEvent("LoadSceneSound", 500);
}

//Перегрузиться в следующую локации
void LAi_ReloadBoarding()
{
	//Разрешим диалоги
	dialogDisable = false;
	//Проверим предыдущую локацию
	if(boarding_location < 0)
	{
		Trace("Boarding: No loaded current boarding location");
		LAi_boarding_process = false;
		return;
	}
	//Установить хендлеры для обработки
	SetEventHandler("FaderEvent_StartFade", "LAi_ReloadStartFade", 0);
	SetEventHandler("FaderEvent_EndFade", "LAi_ReloadEndFade", 0);
	//Создаём фейдер и запускаем
	CreateEntity(&boarding_fader, "fader");
	if(CheckAttribute(&Locations[boarding_location], "image"))
	{
		SendMessage(&boarding_fader, "ls", FADER_PICTURE, Locations[boarding_location].image);
	}
	float fadeOutTime = RELOAD_TIME_FADE_OUT;
	SendMessage(&boarding_fader, "lfl", FADER_OUT, fadeOutTime, false);
	SendMessage(&boarding_fader, "l", FADER_STARTFRAME);
}

void LAi_ReloadStartFade()
{
	//Выгружаем локацию
	ResetSoundScheme();
	PauseAllSounds();
	DelEventHandler("FaderEvent_StartFade", "LAi_ReloadStartFade");
	if(boarding_location >= 0) UnloadLocation(&Locations[boarding_location]);
}

void LAi_ReloadEndFade()
{
	//Загружаем следующую локацию
	DelEventHandler("FaderEvent_EndFade", "LAi_ReloadEndFade");
	SendMessage(&boarding_fader, "lfl", FADER_IN, RELOAD_TIME_FADE_IN, true);
	//Определим возможность продолжения перегрузок
	bool canReload = true;
	if(boarding_enemy_crew <= 0) canReload = false;
	if(!CheckAttribute(&Locations[boarding_location], "boarding.nextdeck")) canReload = false;
	if(Locations[boarding_location].boarding.nextdeck == "") canReload = false;
	if(canReload)
	{
		//Продолжаем абордаж
		LAi_LoadLocation(Locations[boarding_location].boarding.nextdeck);
	}else{
		//Следующей локации нет
		DelEventHandler("LAi_event_GroupKill", "LAi_BoardingGroupKill");
		boarding_location = -1;
		//Пересчитываем команду игрока
		float crew = (boarding_player_crew + boarding_officers + 1)*boarding_player_crew_per_chr;
		SetCrewQuantity(GetMainCharacter(), MakeInt(crew + 0.5));
		//Пересчитываем команду соперника
		crew = boarding_enemy_base_crew*(0.1 + rand(20)*0.01);
		if(boarding_echr_index >= 0)
		{
			SetCrewQuantity(&Characters[boarding_echr_index], MakeInt(crew + 0.5));
			boarding_echr_index = -1;
		}
		//Начислим опыт
		AddCharacterExp(GetMainCharacter(), MakeInt(boarding_exp));
		//Настроим интерфейс
		Log_SetActiveAction("Nothing");
		EndBattleLandInterface();
		//InitBattleInterface();
		//StartBattleInterface();
		//RefreshBattleInterface();
		//Востановим адреса
		ref mchr = GetMainCharacter();
		mchr.location = boarding_adr[0].location;
		mchr.location.group = boarding_adr[0].group;
		mchr.location.locator = boarding_adr[0].locator;
		for(int i = 1; i < 4; i++)
		{
			int idx = GetOfficersIndex(GetMainCharacter(), i);
			if(idx < 0) continue;
			Characters[idx].location = boarding_adr[i].location;
			Characters[idx].location.group = boarding_adr[i].group;
			Characters[idx].location.locator = boarding_adr[i].locator;
		}
		//Выгружаемся в интерфейс		
		LAi_boarding_process = false;
		if(boarding_location_type == BRDLT_SHIP)
		{
			LaunchRansackMain(GetMainCharacter(), boarding_enemy, "");
			LAi_boarding_process = false;
		}else{
			if(boarding_location_type == BRDLT_FORT)
			{
				LaunchFortCapture(boarding_enemy);
				LAi_boarding_process = false;
			}else{
				Trace("Boarding: unknow boarding location type");
			}
		}
	}
}

//Разрешить перегрузку на следующую палубу
#event_handler("LAi_event_boarding_EnableReload", "LAi_EnableReload");
void LAi_EnableReload()
{
	SetEventHandler("Control Activation","LAi_ActivateReload",1);
	Log_SetActiveAction("Reload");
	//Уберём саблю
	ref mchr = GetMainCharacter();
	SendMessage(&mchr, "lsl", MSG_CHARACTER_EX_MSG, "ChangeFightMode", 0);
	//Вернём выживших обратно в кучу
	for(int i = 0; i < LAi_numloginedcharacters; i++)
	{
		int index = LAi_loginedcharacters[i];
		if(index >= 0)
		{
			if(index != GetMainCharacterIndex())
			{
				ref chr = &Characters[index];
				if(LAi_IsDead(chr) == false)
				{
					if(chr.chr_ai.group == LAI_GROUP_PLAYER)
					{
						boarding_player_crew = boarding_player_crew + 1;
					}
				}
			}
		}
	}
}

//Активация перегрузки на следующую палубу
void LAi_ActivateReload()
{
	string controlName = GetEventData();
	if(controlName != "ChrAction") return;
	DelEventHandler("Control Activation", "LAi_ActivateReload");
	Log_SetActiveAction("Nothing");
	LAi_ReloadBoarding();
}

//Расставить персонажей для боя
void LAi_SetBoardingActors(string locID)
{
	int i;
	ref chr;
	string model;
	string ani;
	chr = GetMainCharacter();
	int mchr_rank = sti(chr.rank) - 1;
	int xhp;
	//Установим союзников из команды
	for(i = LAi_numloginedcharacters; i < 4; i++)
	{
		if(boarding_player_crew <= 0) break;
		model = LAi_GetBoardingModel(GetMainCharacter(), &ani);
		chr = LAi_CreateFantomCharacterEx(model, ani, "rld", "loc" + i);
		chr.blade = "saber";
		chr.blade.itemID = BLADE_SABER;
		chr.blade.time = 0.1;
		chr.blade.colorstart = argb(128, 22, 46, 190);
		chr.blade.colorend = argb(0, 20, 60, 100);
		LAi_group_MoveCharacter(chr, LAI_GROUP_PLAYER);
		boarding_player_crew = boarding_player_crew - 1;
		LAi_SetAdjustFencingSkill(chr, 2.0, 5.0);
		LAi_AdjustFencingSkill(chr);
		xhp = boarding_player_hp + rand(25) - 10;
		LAi_SetHP(chr, xhp, xhp);
		LAi_NPC_Equip(chr, mchr_rank, true, true);
	}
	//Установим врагов
	for(i = 0; i < 4; i++)
	{
		if(boarding_enemy_crew <= 0) break;
		model = LAi_GetBoardingModel(boarding_enemy, &ani);
		chr = LAi_CreateFantomCharacterEx(model, ani, "rld", "aloc" + i);
		chr.blade = "saber";
		chr.blade.itemID = BLADE_SABER;
		chr.blade.time = 0.1;
		chr.blade.colorstart = argb(128, 22, 46, 190);
		chr.blade.colorend = argb(0, 20, 60, 100);
		LAi_group_MoveCharacter(chr, LAI_GROUP_BRDENEMY);
		boarding_enemy_crew = boarding_enemy_crew - 1;
		LAi_SetAdjustFencingSkill(chr, 2.0, 5.0);
		LAi_AdjustFencingSkill(chr);
		xhp = boarding_enemy_hp + rand(20) - 10;
		LAi_SetHP(chr, xhp, xhp);
		LAi_NPC_Equip(chr, boarding_erank, true, true);
	}
	//Заставим драться эти 2 группы
	LAi_group_FightGroupsEx(LAI_GROUP_PLAYER, LAI_GROUP_BRDENEMY, true, GetMainCharacterIndex(), -1, false, false);
	LAi_group_SetCheckEvent(LAI_GROUP_BRDENEMY);
}

//Убийство группы
void LAi_BoardingGroupKill()
{
	string group = GetEventData();
	if(group != LAI_GROUP_BRDENEMY) return;
	PostEvent("LAi_event_boarding_EnableReload", 5000);
}

//Моделька для абордажного персонажа
string LAi_GetBoardingModel(ref rCharacter, ref ani)
{
	ani = "man";
	int iNation = sti(rCharacter.nation);
	if (iNation < 0) iNation = PIRATE;
	Nations[iNation].boardingModel.player = "";
	Nations[iNation].boardingModel.enemy = "";
	string atr;
	if(sti(rCharacter.index) == GetMainCharacterIndex())
	{
		atr = "boardingModel.player";
	}else{
		atr = "boardingModel.enemy";
	}
	aref models;
	makearef(models, Nations[iNation].(atr));
	int num = GetAttributesNum(models);
	if(num <= 0) return "";
	int i = rand(num - 1);
	atr = GetAttributeName(GetAttributeN(models, i));
	string model = models.(atr);
	atr = atr + ".ani";
	if(CheckAttribute(models, atr))
	{
		if(models.(atr) != "")
		{
			ani = models.(atr);
		}
	}
	return model;
}


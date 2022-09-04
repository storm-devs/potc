//Monsters, fantoms & encounters


string LAi_monsters_group = "monsters";

void LAi_CreateMonsters(ref location)
{
	//Возможность логина монстров в локацию
	if(LAi_LocationIsMonstersGen(location) == false) return;
	//Сообщим о начале логина монстров
	if(!LEnc_MonstersLoginStart(location)) return;
	//Наличие группы для логина монстров
	string group = "locators." + LAi_monsters_group;
	if(CheckAttribute(location, group) == 0) return;
	//Максимально возможное количество монстров
	int maxMonsters = 20 - LAi_numloginedcharacters;
	if(maxMonsters <= 0) return;
	//Перебераем локаторы, выбирая свободные
	aref grp;
	makearef(grp, location.(group));
	int num = GetAttributesNum(grp);
	if(num <= 0) return;
	if(maxMonsters > num) maxMonsters = num;
	int locatorPos = 0;
	int loginedMonsters = 0;
	for(int i = 0; i < maxMonsters; i++)
	{
		//Количество локаторов на текущего монстра
		int locnum = (num - locatorPos)/(maxMonsters - loginedMonsters);
		if(locnum < 1) locnum = 1;
		//Выбираем локатор из доступных
		locnum = rand(locnum - 1);
		locatorPos = locatorPos + locnum + 1;
		//Позиция локатора
		aref loc = GetAttributeN(grp, locatorPos - 1);
		float lx = stf(loc.x);
		float ly = stf(loc.y);
		float lz = stf(loc.z);
		if(CheckLocationPosition(loadedLocation, lx, ly, lz))
		{
			if(LAi_MonsterLogin(location, LAi_monsters_group, GetAttributeName(GetAttributeN(grp, i))))
			{
				loginedMonsters = loginedMonsters + 1;
			}
		}
	}
	//Сообщим об окончании логина монстров
	LEnc_MonstersLoginEnd(location);
}

object LAi_MonsterInfo;
bool LAi_MonsterLogin(ref location, string group, string locator)
{
	//Запросим модель
	string defModel = "Skel1";
	string defAni = "man";
	LAi_MonsterInfo.model = defModel;
	LAi_MonsterInfo.ani = defAni;
	aref ainfo;
	makearef(ainfo, LAi_MonsterInfo);
	if(!LEnc_MonstersLoginSelectModel(location, ainfo, group, locator)) return false;
	//Проверим модельку
	if(!CheckAttribute(LAi_MonsterInfo, "model")) return false;	
	if(LAi_MonsterInfo.model == "") return false;
	if(!CheckAttribute(LAi_MonsterInfo, "ani")) LAi_MonsterInfo.ani = defModel;
	if(LAi_MonsterInfo.ani == "") LAi_MonsterInfo.ani = defModel;
	//Создаём фантома и заполняем поля по умолчанию
	ref chr = LAi_CreateFantomCharacterEx(LAi_MonsterInfo.model, LAi_MonsterInfo.ani, group, locator);
	LAi_CharacterReincarnationEx(chr, true, true, LAi_monsters_group);
	LAi_SetWarriorType(chr);
	LAi_warrior_SetStay(chr, true);
	LAi_group_MoveCharacter(chr, LAI_GROUP_MONSTERS);
	//Операемся на уровень персонажа
	ref mchr = GetMainCharacter();
	//Определяем уровень жизни
	int hp = 20 + rand(5)*10;
	if(CheckAttribute(mchr, "rank") != 0)
	{
		int rank = sti(mchr.rank);
		if(rank < 1) rank = 1;
		hp = hp*(1.0 + rank*0.1);
	}
	LAi_SetHP(chr, hp, hp);
	//Определяем скил фектования
	if(CheckAttribute(mchr, "skill.Fencing") != 0)
	{
		int flevel = sti(mchr.skill.Fencing);
		if(flevel < 1) flevel = 1;
		if(flevel > 10) flevel = 10;
		flevel = rand(flevel) + 1;
		if(flevel > 10) flevel = 10;
		chr.skill.Fencing = flevel;
	}
	//Корректируем поля модельки
	LEnc_MonstersLoginCorrectParams(location, chr, group, locator);
	return true;
}

//Создать фантома основываясь на характуристиках данного персонажа в самом дальнем углу
void LAi_GenerateFantomFromMe(aref chr)
{
	//Проверяем возможность генерации фантома в данной локации
	if(!TestRef(loadedLocation)) return;
	if(!IsEntity(loadedLocation)) return;
	if(LAi_LocationIsFantomsGen(loadedLocation) == false) return;
	//Проверяем возможность перерождения персонажа
	if(LAi_CharacterIsReincarnation(chr) == false) return;
	//Проверяем какую модельку использовать для перерождения
	bool isGen = LAi_CharacterReincarnationMode(chr);
	if(CheckAttribute(chr, "model") == false) isGen = true;
	if(CheckAttribute(chr, "model.animation") == false) isGen = true;
	if(chr.model == "") isGen = true;
	if(chr.model.animation == "") isGen = true;
	string model, ani;
	if(isGen)
	{
		int nat = GetLocationNation(loadedLocation)
		if(nat < 0) nat = PIRATE;
		if(nat >= MAX_NATIONS) nat = PIRATE;
		if(CheckAttribute(&Nations[nat], "fantomModel") == false)
		{
			Trace("Nation (Nations[" + nat + "]) by name " + Nations[nat].name + " not include fantoms");
			return;
		}
		aref fantoms;
		makearef(fantoms, Nations[nat].fantomModel);
		int num = GetAttributesNum(fantoms);
		if(num <= 0)
		{
			Trace("Nation (Nations[" + nat + "]) by name " + Nations[nat].name + " not include have fantoms");
			return;
		}
		num = rand(num - 1);
		string m = GetAttributeName(GetAttributeN(fantoms, num));
		model = fantoms.(m);
		ani = "man";
		m = m + ".ani";
		if(CheckAttribute(fantoms, m) != false)
		{
			ani = fantoms.(m);
		}
	}else{
		model = chr.model;
		ani = chr.model.animation;
	}
	//Сохраняем параметры персонажа
	object tmp;
	CopyAttributes(&tmp, chr);
	//Создаём фантома	
	ref fnt = LAi_CreateFantomCharacterEx(model, ani, LAi_CharacterReincarnationGroup(chr), "");
	string curidx = fnt.index;
	//Устанавливаем параметры предыдущего персонажа
	CopyAttributes(fnt, &tmp);
	LAi_SetCurHPMax(fnt);
	if(CheckAttribute(fnt, "chr_ai.group"))
	{
		LAi_group_MoveCharacter(fnt, fnt.chr_ai.group);
	}else{
		LAi_group_MoveCharacter(fnt, "");
	}
	//Сохраняем модельку и анимацию
	fnt.model = model;
	fnt.model.animation = ani;
	//Инициализируем тип
	if(!CheckAttribute(fnt, "chr_ai.type")) fnt.chr_ai.type = "";	
	string chrtype = fnt.chr_ai.type;
	SetRandomNameToCharacter(fnt);
	fnt.id = tmp.id;
	fnt.index = curidx;
	LAi_tmpl_stay_InitTemplate(fnt);
	fnt.chr_ai.type = "";
	if(chrtype != "")
	{
		chrtype = "LAi_type_" + chrtype + "_Init";
		call chrtype(fnt);
	}
}

bool LAi_CreateEncounters(ref location)
{
	bool retValue = false;
	string encGroup, str;
	aref grp;
	int num = 0;
	for(int i = 0; i < 5; i++)
	{
		//Выбираем группу локаторов
		encGroup = LAi_FindRandomLocator("encdetector");
		if(encGroup == "") return retValue;
		//Проверяем на существование
		if(CheckAttribute(location, "locators." + encGroup))
		{
			//Проверим на содержание локатотров
			str = "locators." + encGroup;
			makearef(grp, location.(str));
			num = GetAttributesNum(grp);			
			if(num > 0) break;
		}
	}
	if(num <= 0) return retValue;
	//Максимально возможное количество персонажей в энкоунтере
	int maxChr = 16 - LAi_numloginedcharacters;
	if(maxChr <= 0) return retValue;
	if(maxChr > num) maxChr = num;
	//Есть группа пробуем завести энкоунтеров
	if(!LEnc_LoginStart(location, "encdetector", encGroup, maxChr)) return retValue;
	//Начинаем перебирать локаторы и логинить фантомов
	for(i = 0; i < maxChr; i++)
	{
		//Получим локатор для логина
		string locator = GetAttributeName(GetAttributeN(grp, i));
		//Запросим модель
		string defModel = "man1";
		string defAni = "man";
		LAi_MonsterInfo.model = defModel;
		LAi_MonsterInfo.ani = defAni;
		aref ainfo;
		makearef(ainfo, LAi_MonsterInfo);
		LEnc_LoginSelectModel(location, ainfo, encGroup, locator);
		//Проверим модельку
		if(!CheckAttribute(LAi_MonsterInfo, "model")) break;
		if(LAi_MonsterInfo.model == "") break;
		if(!CheckAttribute(LAi_MonsterInfo, "ani")) LAi_MonsterInfo.ani = defModel;
		if(LAi_MonsterInfo.ani == "") LAi_MonsterInfo.ani = defModel;
		//Создаём фантома
		ref chr = LAi_CreateFantomCharacterEx(LAi_MonsterInfo.model, LAi_MonsterInfo.ani, encGroup, locator);
		//Скорректируем параметры
		LEnc_LoginCorrectParams(location, chr, encGroup, locator);
		retValue = true;
		//Прекращение логина
		if(!LEnc_IsContinueLogin(location, chr, encGroup, locator)) break;
	}
	//Завершить загрузку энкоунтера в локацию
	LEnc_LoginEnd(location, "encdetector", encGroup);
	return retValue;
}




















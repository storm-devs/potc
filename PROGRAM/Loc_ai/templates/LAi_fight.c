

#define LAI_TMPL_FIGHT	"fight"

/*
	Возможные состояния:
		"wait"		ждёт цели
		"go"		идёт к цели
		"fight"		дерётся с целью
		"stop"		ждёт возможности пройти к цели
*/


bool LAi_tmpl_SetFight(aref chr, aref tagret)
{
	if(!LAi_tmpl_fight_InitTemplate(chr)) return false;
	LAi_tmpl_fight_SetTarget(chr, tagret);
	return true;
}

bool LAi_tmpl_fight_LostTarget(aref chr)
{
	if(!CheckAttribute(chr, "chr_ai.tmpl.state")) return true;
	string state = chr.chr_ai.tmpl.state;
	if(state == "wait") return true;
	return false;
}

bool LAi_tmpl_fight_NoActive(aref chr)
{
	if(!CheckAttribute(chr, "chr_ai.tmpl.state")) return true;
	if(chr.chr_ai.tmpl.state != "fight") return true;
	return false;
}

bool LAi_tmpl_fight_IsGo(aref chr)
{
	if(!CheckAttribute(chr, "chr_ai.tmpl.state")) return false;
	if(chr.chr_ai.tmpl.state == "go") return true;
	return false;
}

bool LAi_tmpl_fight_InitTemplate(aref chr)
{
	bool isRes = SendMessage(&chr, "ls", MSG_CHARACTER_EX_MSG, "IsFightMode");
	if(!LAi_IsInitedAI) isRes = true;
	CharacterPlayAction(chr, "");
	bool isNew = false;
	if(CheckAttribute(chr, "chr_ai.tmpl"))
	{
		if(chr.chr_ai.tmpl != LAI_TMPL_FIGHT) isNew = true;
	}else{
		isNew = true;
	}
	if(isNew)
	{
		DeleteAttribute(chr, "chr_ai.tmpl");
		chr.chr_ai.tmpl = LAI_TMPL_FIGHT;
		chr.chr_ai.tmpl.target = "";
		chr.chr_ai.tmpl.state = "wait";
		chr.chr_ai.tmpl.time = "0";
		if(LAi_IsInitedAI)
		{
			LAi_tmpl_fight_SetWaitState(chr);
		}
	}else{
		if(!CheckAttribute(chr, "chr_ai.tmpl.state")) chr.chr_ai.tmpl.state = "wait";
		if(!CheckAttribute(chr, "chr_ai.tmpl.time")) chr.chr_ai.tmpl.time = "0";
		if(!CheckAttribute(chr, "chr_ai.tmpl.target"))
		{
			chr.chr_ai.tmpl.target = "";
			chr.chr_ai.tmpl.state = "wait";
		}else{
			if(chr.chr_ai.tmpl.target == "") chr.chr_ai.tmpl.state = "wait";
		}
		LAi_tmpl_fight_updatetemplate(chr);
	}
	chr.chr_ai.tmpl.nostop = "5";
	SendMessage(&chr, "lsl", MSG_CHARACTER_EX_MSG, "ChangeFightMode", true);
	SendMessage(&chr, "lsl", MSG_CHARACTER_EX_MSG, "LockFightMode", true);
	return LAi_IsInitedAI;
}

//Процессирование шаблона персонажа
void LAi_tmpl_fight_CharacterUpdate(aref chr, float dltTime)
{
	//Если не в режиме боя переведём в него
	if(SendMessage(&chr, "ls", MSG_CHARACTER_EX_MSG, "IsFightMode") == 0)
	{
		SendMessage(&chr, "lsl", MSG_CHARACTER_EX_MSG, "LockFightMode", false);
		SendMessage(&chr, "lsl", MSG_CHARACTER_EX_MSG, "ChangeFightMode", true);
		SendMessage(&chr, "lsl", MSG_CHARACTER_EX_MSG, "LockFightMode", true);
	}
	float time;
	aref tmpl;
	makearef(tmpl, chr.chr_ai.tmpl);
	int idx;
	if(tmpl.target != "")
	{
		//Если есть цель, то отслеживаем её смерть
		if(LAi_IsDead(&Characters[sti(tmpl.target)]))
		{
			LAi_tmpl_fight_SetWaitState(chr);
			LAi_Character_TemplateComplite(chr, LAI_TMPL_FIGHT);
			return;
		}
		//Анализируем действие стояния
		if(tmpl.state == "stop")
		{
			//Определим дистанцию до противника
			if(!LAi_tmpl_fight_CheckEnemy(chr))
			{
				time = stf(tmpl.time) - dltTime;
				if(time < 0)
				{
					LAi_tmpl_fight_StopRestore(chr);
					tmpl.time = -1;
				}else{
					tmpl.time = time;
				}
			}else{
				LAi_tmpl_fight_StopRestore(chr);
				tmpl.time = -1;
			}
		}else{
			time = stf(tmpl.nostop) - dltTime;
			if(time <= 0.0) time = -1.0;
			tmpl.nostop = time;
		}
	}else{
		//Если цели нет, переходим в режим ожидания
		if(tmpl.state != "wait")
		{
			LAi_tmpl_fight_SetWaitState(chr);
		}
	}
}

//Персонаж выполнил команду  go to point
void LAi_tmpl_fight_EndGoToPoint(aref chr)
{
	LAi_tmpl_fight_updatetemplate(chr);
}

//Персонаж провалил команду  go to point
void LAi_tmpl_fight_FailureGoToPoint(aref chr)
{
	LAi_tmpl_fight_updatetemplate(chr);
}


//Персонаж выполнил команду  run to point
void LAi_tmpl_fight_EndRunToPoint(aref chr)
{	
	LAi_tmpl_fight_updatetemplate(chr);
}

//Персонаж провалил команду  run to point
void LAi_tmpl_fight_FailureRunToPoint(aref chr)
{	
	LAi_tmpl_fight_updatetemplate(chr);
}

//Персонаж не может добраться до точки назначения
void LAi_tmpl_fight_BusyPos(aref chr, float x, float y, float z)
{
	LAi_tmpl_fight_Stop(chr, 1.0 + rand(3));
}

//Персонаж начал перемещение за другим
void LAi_tmpl_fight_FollowGo(aref chr)
{
	LAi_tmpl_fight_updatetemplate(chr);
}

//Персонаж начал дошёл до другого персонажа
void LAi_tmpl_fight_FollowStay(aref chr)
{	
	LAi_tmpl_fight_updatetemplate(chr);
}

//Персонаж провалил команду  follow character
void LAi_tmpl_fight_FailureFollow(aref chr)
{	
	LAi_tmpl_fight_updatetemplate(chr);
}


//Персонаж начал перемещение за другим
void LAi_tmpl_fight_FightGo(aref chr)
{
	chr.chr_ai.tmpl.state = "go";
}

//Персонаж начал дошёл до другого персонажа
void LAi_tmpl_fight_FightStay(aref chr)
{
	chr.chr_ai.tmpl.state = "fight";
}

//Персонаж провалил команду  Fight
void LAi_tmpl_fight_FailureFight(aref chr)
{
	LAi_tmpl_fight_SetWaitState(chr);
}

//Можно ли стрелять
bool LAi_tmpl_fight_IsFire(aref chr)
{	
	return LAi_CharacterCanFrie(chr);
}

//Можно ли использовать оружие
bool LAi_tmpl_fight_IsFight(aref chr)
{
	return LAi_LocationCanFight();
}


//Персонаж выполнил команду  escape
void LAi_tmpl_fight_EndEscape(aref chr)
{
	LAi_tmpl_fight_updatetemplate(chr);
}

//Персонаж скользит вдоль патча
void LAi_tmpl_fight_EscapeSlide(aref chr)
{
	LAi_tmpl_fight_updatetemplate(chr);
}

//Персонаж провалил команду  escape
void LAi_tmpl_fight_FailureEscape(aref chr)
{
	LAi_tmpl_fight_updatetemplate(chr);
}


//Персонаж толкается с другими персонажами
void LAi_tmpl_fight_ColThreshold(aref chr)
{
	LAi_tmpl_fight_Stop(chr, 1.0 + rand(3));
}

//Персонаж закончил проигрывать анимацию
void LAi_tmpl_fight_EndAction(aref chr)
{
	LAi_tmpl_fight_updatetemplate(chr);
}


//Персонажа просят освободить место
void LAi_tmpl_fight_FreePos(aref chr, aref who)
{
}

//------------------------------------------------------------------------------------------
//Внутреннии функции
//------------------------------------------------------------------------------------------

//Перейти в режим боя и ожидать указание цели
void LAi_tmpl_fight_SetWaitState(aref chr)
{
	SetCharacterTask_Stay(chr);
	chr.chr_ai.tmpl.target = "";
	chr.chr_ai.tmpl.state = "wait";
}

//Атаковать цель
void LAi_tmpl_fight_SetTarget(aref chr, aref tagret)
{
	chr.chr_ai.tmpl.target = tagret.index;
	chr.chr_ai.tmpl.state = "go";
	if(LAi_IsInitedAI)
	{
	   SetCharacterTask_Fight(chr, tagret);
	}
}

//Получить цель
int LAi_tmpl_fight_GetTarget(aref chr)
{
	if(!CheckAttribute(chr, "chr_ai.tmpl.target")) return -1;
	if(chr.chr_ai.tmpl.target == "") return -1;
	return sti(chr.chr_ai.tmpl.target);
}

void LAi_tmpl_fight_Stop(aref chr, float stopTime)
{
	if(stf(chr.chr_ai.tmpl.nostop) > 0.0) return;
	if(chr.chr_ai.tmpl.state != "go") return;
	if(stopTime <= 0) return;
	if(chr.chr_ai.tmpl.target == "") return;
	//Определяем в близи наличие врагов
	if(LAi_tmpl_fight_CheckEnemy(chr)) return;
	//Оставим в режиме боя
	SetCharacterTask_Stay(chr);
	chr.chr_ai.tmpl.state = "stop";
	chr.chr_ai.tmpl.time = stopTime;
	chr.chr_ai.tmpl.nostop = 5 + rand(10);
}

void LAi_tmpl_fight_StopRestore(aref chr)
{
	chr.chr_ai.tmpl.state = "go";
	int idx = sti(chr.chr_ai.tmpl.target);
	LAi_tmpl_fight_SetTarget(chr, &Characters[idx]);
}

void LAi_tmpl_fight_updatetemplate(aref chr)
{
	if(chr.chr_ai.tmpl.state == "wait")
	{
		LAi_tmpl_fight_SetWaitState(chr);
	}else{
		int idx = sti(chr.chr_ai.tmpl.target);
		LAi_tmpl_fight_SetTarget(chr, &Characters[idx]);
	}
}

bool LAi_tmpl_fight_CheckEnemy(aref chr)
{
	int num = FindNearCharacters(chr, 4.5, -1.0, -1.0, 0.001, false, false);
	if(num <= 0) return false;
	for(int i = 0; i < num; i++)
	{
		int idx = sti(chrFindNearCharacters[i].index);
		if(LAi_group_IsEnemy(chr, &Characters[idx])) return true;
	}	
	return false;
}


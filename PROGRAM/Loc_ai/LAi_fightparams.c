
//--------------------------------------------------------------------------------
//Blade parameters
//--------------------------------------------------------------------------------

//Получить повреждение от сабли
float LAi_BladeCalcDamage(aref attack)
{
	//Расчитываем повреждение от сабли
	float min = 10.0;
	float max = 10.0;
	if(CheckAttribute(attack, "chr_ai.dmgbldmin"))
	{
		min = stf(attack.chr_ai.dmgbldmin);
	}
	if(CheckAttribute(attack, "chr_ai.dmgbldmax"))
	{
		max = stf(attack.chr_ai.dmgbldmax);
	}
	float dmg = min + (max - min)*(rand(100)*0.01);
	return dmg;
}

//Модифицировать повреждение от сабли с учётом скилов
float LAi_BladeApplySkills(aref attack, aref enemy, float dmg)
{
	//Учитываем скилы
	float aSkill = LAi_GetCharacterFightLevel(attack);
	float eSkill = LAi_GetCharacterFightLevel(enemy);
	if(aSkill >= eSkill)
	{
		dmg = dmg*(1.0 + 2.0*(aSkill - eSkill));
	}else{
		dmg = dmg*(1.0 + 0.5*(aSkill - eSkill));
	}
	return dmg;
}

//Расчитать полученный опыт при ударе саблей
float LAi_BladeCalcExperience(aref attack, aref enemy, float dmg)
{
	//Вычисляем полученый опыт
	float ra = 1.0;
	float re = 1.0;
	if(CheckAttribute(attack, "rank"))
	{
		ra = stf(attack.rank);
	}
	if(CheckAttribute(enemy, "rank"))
	{
		re = stf(enemy.rank);
	}
	if(ra < 1.0) ra = 1.0;
	if(re < 1.0) re = 1.0;
	dmg = dmg*((1.0 + re*0.5)/(1.0 + ra*0.5));
	return dmg;
}

//Расчитать вероятность пробивки блока
float LAi_BladeFindPiercingProbability(aref attack, aref enemy, float hitDmg)
{
	float piercing = 0.05;
	float block = 0.01;
	if(CheckAttribute(attack, "chr_ai.piercing"))
	{
		piercing = stf(attack.chr_ai.piercing);
	}
	if(CheckAttribute(enemy, "chr_ai.block"))
	{
		block = stf(enemy.chr_ai.block);
	}
	float aSkill = LAi_GetCharacterFightLevel(attack);
	float eSkill = LAi_GetCharacterFightLevel(enemy);
	if(aSkill < eSkill) aSkill = eSkill;
	float p = piercing - block + (aSkill - eSkill)*0.5;
	float k = 1.0;
	if(IsCharacterPerkOn(enemy, "BasicDefense")) k = 0.75;
	if(IsCharacterPerkOn(enemy, "AdvancedDefense")) k = 0.5;
	hitDmg = hitDmg*0.5 + 0.5;
	p = p*k*hitDmg*hitDmg;
	return p;
}

//--------------------------------------------------------------------------------
//Gun parameters
//--------------------------------------------------------------------------------

//Расчитаем вероятность попадания
float LAi_GunCalcProbability(aref attack, float kDist)
{
	//Если близко, то попадём точно
	if(kDist >= 0.9) return 1.0;
	//Расчитаем вероятность на конце отрезка
	float pmin = 0.3;
	if(CheckAttribute(attack, "chr_ai.accuracy"))
	{
		pmin = stf(attack.chr_ai.accuracy);
	}
	//Применим разброс от скила
	float aSkill = LAi_GetCharacterFightLevel(attack);
	pmin = pmin + 0.3*aSkill;
	//Вероятность попадания в текущей позиции
	float p = pmin + (1.0 - pmin)*(kDist/0.9);
	//Учесть абилити
	if(IsCharacterPerkOn(attack, "GunProfessional"))
	{
		p = p + 0.25;
	}else{
		if(IsCharacterPerkOn(attack, "Gunman"))
		{
			p = p + 0.1;
		}
	}
	return p;
}

//Получить повреждение от пистолета
float LAi_GunCalcDamage(aref attack)
{
	//Расчитываем повреждение от сабли
	float min = 10.0;
	float max = 10.0;
	if(CheckAttribute(attack, "chr_ai.dmggunmin"))
	{
		min = stf(attack.chr_ai.dmggunmin);
	}
	if(CheckAttribute(attack, "chr_ai.dmggunmax"))
	{
		max = stf(attack.chr_ai.dmggunmax);
	}
	float dmg = min + (max - min)*(rand(100)*0.01);
	return dmg;
}

//Расчитать полученный опыт при попадании из пистолета
float LAi_GunCalcExperience(aref attack, aref enemy, float dmg)
{
	//Вычисляем полученый опыт
	float ra = 1.0;
	float re = 1.0;
	if(CheckAttribute(attack, "rank"))
	{
		ra = stf(attack.rank);
	}
	if(CheckAttribute(enemy, "rank"))
	{
		re = stf(enemy.rank);
	}	
	if(ra < 1.0) ra = 1.0;
	if(re < 1.0) re = 1.0;
	dmg = dmg*((1.0 + re*0.5)/(1.0 + ra*0.5));
	return dmg;
}

//Расчитаем текущую скорость перезарядки пистолета
float LAi_GunReloadSpeed(aref chr)
{
	//Получим текущее состояние скорости зарядки
	float charge_dlt = LAI_DEFAULT_DLTCHRG;
	if(CheckAttribute(chr, "chr_ai.charge_dlt"))
	{
		charge_dlt = stf(chr.chr_ai.charge_dlt);
	}
	//Модифицируем скилом
	float skill = LAi_GetCharacterFightLevel(chr);
	charge_dlt = charge_dlt*(1.0 + 0.25*skill);
	//Учтём абилити
	if(IsCharacterPerkOn(chr, "GunProfessional"))
	{
		charge_dlt = charge_dlt*1.5;
	}else{
		if(IsCharacterPerkOn(chr, "Gunman"))
		{
			charge_dlt = charge_dlt*1.1;
		}
	}
	return charge_dlt;
}

//--------------------------------------------------------------------------------
//All
//--------------------------------------------------------------------------------

float LAi_CalcDeadExp(aref attack, aref enemy)
{
	//Вычисляем полученый опыт
	float ra = 1.0;
	float re = 1.0;
	if(CheckAttribute(attack, "rank"))
	{
		ra = stf(attack.rank);
	}
	if(CheckAttribute(enemy, "rank"))
	{
		re = stf(enemy.rank);
	}	
	if(ra < 1.0) ra = 1.0;
	if(re < 1.0) re = 1.0;		
	float dmg = (0.5 + 4.0*LAi_GetCharacterFightLevel(enemy))*LAi_GetCharacterMaxHP(enemy);
	dmg = dmg*((1.0 + re*0.5)/(1.0 + ra*0.5));
	return dmg*0.5;
}

//--------------------------------------------------------------------------------
//Calculate
//--------------------------------------------------------------------------------


//Начисление повреждений при незаблокированной атаке
void LAi_ApplyCharacterAttackDamage(aref attack, aref enemy, float attackDmg, float hitDmg)
{
	LAi_ApplyCharacterBladeDamage(attack, enemy, attackDmg, hitDmg, false);
}

//Начисление повреждений при заблокированной атаке
void LAi_ApplyCharacterBlockDamage(aref attack, aref enemy, float attackDmg, float hitDmg)
{
	LAi_ApplyCharacterBladeDamage(attack, enemy, attackDmg, hitDmg, true);
}

//Начисление повреждений при атаке мечём
void LAi_ApplyCharacterBladeDamage(aref attack, aref enemy, float attackDmg, float hitDmg, bool isBlocked)
{
	//Если неубиваемый, то нетрогаем его
	if(CheckAttribute(enemy, "chr_ai.immortal"))
	{
		if(sti(enemy.chr_ai.immortal) != 0) return;
	}
	//Применяем абилити
	float pBreak = 0.0;
	float critical = 0.0;
	if(IsCharacterPerkOn(attack, "SwordplayProfessional"))
	{
		pBreak = pBreak + 0.25;
		if(rand(100) <= 25)
		{
			if(CheckAttribute(enemy, "rank"))
			{
				critical = 20.0 + stf(enemy.rank)*2.0;
			}
		}
	}else{
		if(IsCharacterPerkOn(attack, "CriticalHit"))
		{
			if(rand(100) <= 5)
			{
				if(CheckAttribute(enemy, "rank"))
				{
					critical = 20.0 + stf(enemy.rank)*1.5;
				}
			}
		}
	}
	float kDmg = 1.0;
	if(IsCharacterPerkOn(attack, "Rush"))
	{
		kDmg = 1.5;
		pBreak = pBreak + 0.5;
	}
	if(IsCharacterPerkOn(enemy, "Rush"))
	{
		pBreak = pBreak + 0.9;
	}
	if(critical > 0.0)
	{
		if(sti(attack.index) == GetMainCharacterIndex())
		{
			Log_SetStringToLog(XI_ConvertString("Critical Hit"));
		}
	}
	if(isBlocked)
	{
		//Вероятность пробивки
		float p = LAi_BladeFindPiercingProbability(attack, enemy, hitDmg);
		p = p + pBreak;
		//Если шансов пробить нет, то ненаносим провреждения
		if(p < 0.0) return;
		//Если шансов пробить нет, то ненаносим провреждения
		if(rand(10000) > p*10000) return;
	}
	//Вычисляем повреждение
	float dmg = LAi_BladeCalcDamage(attack);
	dmg = dmg*kDmg;
	//Аттака своей группы
	bool noExp = false;
	if(CheckAttribute(attack, "chr_ai.group"))
	{
		if(CheckAttribute(enemy, "chr_ai.group"))
		{
			if(attack.chr_ai.group == enemy.chr_ai.group)
			{
				LAi_ChangeReputation(attack, -1);
				dmg = 0.0;
				critical = 0.0;
				noExp = true;
			}
		}
	}
	kDmg = 1.0;
	if(IsCharacterPerkOn(enemy, "BasicDefense")) kDmg = 0.9;
	if(IsCharacterPerkOn(enemy, "AdvancedDefense")) kDmg = 0.8;
	if(IsCharacterPerkOn(enemy, "SwordplayProfessional")) kDmg = 0.6;
	dmg = dmg*kDmg;
	float damage = LAi_BladeApplySkills(attack, enemy, dmg);
	if(isBlocked)
	{
		damage = damage*0.3;
	}
	//Наносим повреждение
	LAi_ApplyCharacterDamage(enemy, MakeInt(damage + critical + 0.5));
	//Проверим на смерть
	LAi_CheckKillCharacter(enemy);
	//Есть ли оружие у цели
	bool isSetBalde = (SendMessage(enemy, "ls", MSG_CHARACTER_EX_MSG, "IsSetBalde") != 0);
	//Начисляем опыта
	float exp = LAi_BladeCalcExperience(attack, enemy, dmg);
	if(LAi_IsDead(enemy))
	{
		//Начислим за убийство
		exp = exp + LAi_CalcDeadExp(attack, enemy);
		if(!isSetBalde)
		{
			LAi_ChangeReputation(attack, -3);
		}
	}
	if(!isSetBalde)
	{
		LAi_ChangeReputation(attack, -1);
		exp = 0.0;
	}
	if(!noExp) AddCharacterExp(attack, MakeInt(exp*0.5 + 0.5));
}

//Начисление повреждений при попадании
void LAi_ApplyCharacterFireDamage(aref attack, aref enemy, float kDist)
{
	//Если неубиваемый, то нетрогаем его
	if(CheckAttribute(enemy, "chr_ai.immortal"))
	{
		if(sti(enemy.chr_ai.immortal) != 0) return;
	}
	//Вероятность поподания
	float p = LAi_GunCalcProbability(attack, kDist);
	//Если промахнулись, то выйдем
	if(rand(10000) > p*10000) return;	
	//Начисляем повреждение
	float damage = LAi_GunCalcDamage(attack);
	//Аттака своей группы
	bool noExp = false;
	if(CheckAttribute(attack, "chr_ai.group"))
	{
		if(CheckAttribute(enemy, "chr_ai.group"))
		{
			if(attack.chr_ai.group == enemy.chr_ai.group)
			{
				LAi_ChangeReputation(attack, -1);
				damage = 0.0;
				noExp = true;
			}
		}
	}
	LAi_ApplyCharacterDamage(enemy, MakeInt(damage + 0.5));	
	//Проверим на смерть
	LAi_CheckKillCharacter(enemy);
	//Есть ли оружие у цели
	bool isSetBalde = (SendMessage(enemy, "ls", MSG_CHARACTER_EX_MSG, "IsSetBalde") != 0);
	//Начисляем опыт
	float exp = LAi_GunCalcExperience(attack, enemy, damage);
	if(LAi_IsDead(enemy))
	{
		//Начислим за убийство
		exp = exp + LAi_CalcDeadExp(attack, enemy);
		if(!isSetBalde)
		{
			LAi_ChangeReputation(attack, -3);
			exp = exp*0.05;
		}
	}
	if(!isSetBalde)
	{
		LAi_ChangeReputation(attack, -1);
		exp = 0.0;
	}
	if(!noExp) AddCharacterExp(attack, MakeInt(exp*0.5 + 0.5));
}

//--------------------------------------------------------------------------------
//NPC parameters
//--------------------------------------------------------------------------------

#event_handler("NPC_Event_GetAttackActive","LAi_NPC_GetAttackActive");
#event_handler("NPC_Event_GetDefenceActive","LAi_NPC_GetAttackDefence");
#event_handler("NPC_Event_GetAggresive","LAi_NPC_GetAggresive");
#event_handler("NPC_Event_GetFireActive","LAi_NPC_GetFireActive");
#event_handler("NPC_Event_EnableFire","LAi_NPC_EnableFire");

float npc_return_tmp;
bool npc_return_tmpb;

//probability of attack. Value per sec. > 0
float LAi_NPC_GetAttackActive()
{
	aref chr = GetEventData();
	float level = LAi_GetCharacterFightLevel(chr);
	npc_return_tmp = 0.3 + level*0.7;
	return npc_return_tmp;
}

//probability of defence. Value per sec. > 0
float LAi_NPC_GetAttackDefence()
{
	aref chr = GetEventData();
	float level = LAi_GetCharacterFightLevel(chr);
	npc_return_tmp = 0.008 + level*0.08;
	return npc_return_tmp;
}

//balance between defence and attack 0..1
float LAi_NPC_GetAggresive()
{
	aref chr = GetEventData();
	float level = LAi_GetCharacterFightLevel(chr);
	npc_return_tmp = rand(10)*0.1*(0.4 + level*0.6);
	return npc_return_tmp;
}

//probability of fire. Value per sec. > 0
float LAi_NPC_GetFireActive()
{
	aref chr = GetEventData();
	float level = LAi_GetCharacterFightLevel(chr);
	npc_return_tmp = 0.001 + level*0.06;
	return npc_return_tmp;
}

//is fire enable?
bool LAi_NPC_EnableFire()
{
	aref chr = GetEventData();
	float level = LAi_GetCharacterFightLevel(chr);
	npc_return_tmpb = false;
	if(level > 0.1) npc_return_tmpb = true;	
	return npc_return_tmpb;
}

#event_handler("Location_CharacterSGFire","LAi_Location_CharacterSGFire");
void LAi_Location_CharacterSGFire()
{
	aref attack = GetEventData();
	aref enemy = GetEventData();
	float kDmg = GetEventData();
	if(LAi_IsDead(enemy)) return;
	//Реакция груп на атаку
	LAi_group_Attack(attack, enemy);
	AddCharacterExp(attack, 100*kDmg);
	//Наносим повреждение
	LAi_ApplyCharacterDamage(enemy, MakeInt((5 + rand(5))*kDmg));
	//Проверим на смерть
	LAi_CheckKillCharacter(enemy);
}


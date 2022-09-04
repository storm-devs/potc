bool TestIntValue(int nValue, int nCompareValue, string sOperation)
{
	switch(sOperation)
	{
	case ">=":
			if(nValue >= nCompareValue) return true;
			return false;
	break;
	case "<=":
			if(nValue <= nCompareValue) return true;
			return false;
	break;
	case "=":
			if(nValue == nCompareValue) return true;
			return false;
	break;
	case ">":
			if(nValue > nCompareValue) return true;
			return false;
	break;
	case "<":
			if(nValue < nCompareValue) return true;
			return false;	
	break;
	}
	trace("ERROR: invalid operation(" + sOperation + ")");
	return false;
}

bool ProcessCondition(aref condition)
{
	bool bTmp;
	int i;
	ref tmpRef;
	ref refCharacter;
	string sConditionName;
	string sTmpString;
	string locGroup;
	float fx,fy,fz;

	sConditionName = GetAttributeValue(condition);
	if(CheckAttribute(condition,"character"))
	{
		condition.characterIdx = "" + GetCharacterIndex(condition.character);
		DeleteAttribute(condition,"character");
	}
	if(CheckAttribute(condition,"characterIdx"))
	{
		refCharacter = GetCharacter(sti(condition.characterIdx));
	}
	else
	{
		refCharacter = GetMainCharacter();
	}

	switch(sConditionName)
	{
	case "Goods":
		return TestIntValue(GetCargoGoods(refCharacter,sti(condition.goods)),sti(condition.quantity),condition.operation);
	break;
	case "party_goods":
		return TestIntValue(GetSquadronGoods(refCharacter,sti(condition.goods)),sti(condition.quantity),condition.operation);
	break;
	case "item":
		return CheckCharacterItem(refCharacter,condition.item);
	break;
	case "passenger":
		if(CheckAttribute(condition,"npc"))
		{
			condition.npcIdx = "" + GetCharacterIndex(condition.npc);
			DeleteAttribute(condition,"npc");
		}
		i = FindFellowtravellers(refCharacter,GetCharacter(sti(condition.npcIdx)));
		if(i==FELLOWTRAVEL_PASSENGER) return true;
		if(i==FELLOWTRAVEL_OFFICER) return true;
		if(i==FELLOWTRAVEL_CAPTIVE) return true;
		return false;
	break;
	case "prisoner":
		if(CheckAttribute(condition,"npc"))
		{
			condition.npcIdx = "" + GetCharacterIndex(condition.npc);
			DeleteAttribute(condition,"npc");
		}
		i = FindFellowtravellers(refCharacter,GetCharacter(sti(condition.npcIdx)));
		return i==FELLOWTRAVEL_CAPTIVE;
	break;
	case "officer":
		if(CheckAttribute(condition,"npc"))
		{
			condition.npcIdx = "" + GetCharacterIndex(condition.npc);
			DeleteAttribute(condition,"npc");
		}
		i = FindFellowtravellers(refCharacter,GetCharacter(sti(condition.npcIdx)));
		return i==FELLOWTRAVEL_OFFICER;
	break;
	case "companion":
		if(CheckAttribute(condition,"npc"))
		{
			condition.npcIdx = "" + GetCharacterIndex(condition.npc);
			DeleteAttribute(condition,"npc");
		}
		i = FindFellowtravellers(refCharacter,GetCharacter(sti(condition.npcIdx)));
		return i==FELLOWTRAVEL_COMPANION;
	break;
	case "ship_class":
		i = GetCharacterShipClass(refCharacter);
		if(i==-1) return false;
		return TestIntValue(i,sti(condition.class),condition.operation);
	break;
	case "ship":
		return GetCharacterShipType(refCharacter) == sti(condition.type);
	break;
	case "cannons":
		return GetCaracterShipCannonsType(refCharacter) == sti(condition.type);
	break;
	case "hold_space":
		return TestIntValue(GetCargoFreeSpace(refCharacter),sti(condition.quantity),condition.operation);
	break;
	case "party_hold_space":
		i = GetSquadronFreeSpace(refCharacter,sti(condition.goods));
		return TestIntValue(i,sti(condition.quantity),condition.operation);
	break;
	case "Crew_Space":
		return TestIntValue(GetFreeCrewQuantity(refCharacter),sti(condition.quantity),condition.operation);
	break;
	case "Party_Crew_Space":
		return TestIntValue(GetFreePartyCrewQuantity(refCharacter),sti(condition.quantity),condition.operation);
	break;
	case "Skill":
		i = GetCharacterSkill(refCharacter,condition.skill);
		return TestIntValue(i,sti(condition.value),condition.operation);
	break;
	case "Party_Skill":
		i = GetSummonSkillFromName(refCharacter,condition.skill);
		return TestIntValue(i,sti(condition.value),condition.operation);
	break;
	case "Rank":
		return TestIntValue(sti(refCharacter.rank),sti(condition.value),condition.operation);
	break;
	case "Reputation":
		return TestIntValue(sti(refCharacter.reputation),sti(condition.value),condition.operation);
	break;
	case "relation":
		i = GetNationRelation2Character(GetNationTypeByName(condition.nation),sti(refCharacter.index));
		bTmp = false;
		switch(condition.relation)
		{
		case "Friendly":	bTmp = i==RELATION_FRIEND; break;
		case "Hostile":		bTmp = i==RELATION_ENEMY; break;
		case "Neutral":		bTmp = i==RELATION_NEUTRAL; break;
		}
		return bTmp;
	break;
	
	case "location":
		if(refCharacter.location==condition.location) return !CharacterIsDead(refCharacter);
		return false;
	break;

	case "locator":
		if(refCharacter.location == condition.location)
		{
			locGroup = condition.locator_group;
			if( !CheckAttribute(refCharacter,"Quests.LocatorCheck."+locGroup) )
			{
				if(IsEntity(refCharacter))
				{
					refCharacter.Quests.LocatorCheck.(locGroup) = "";
					if( GetCharacterPos(refCharacter,&fx,&fy,&fz) )
					{
						if( CheckCurLocator(locGroup,condition.locator, fx,fy,fz) )
							refCharacter.Quests.LocatorCheck.(locGroup) = condition.locator;
					}
					AddCharacterLocatorGroup(refCharacter,locGroup);
				}
				else
				{
					Trace("character "+refCharacter.id+" not entity");
					return false;
				}
			}
			if(refCharacter.Quests.LocatorCheck.(locGroup)==condition.locator)	return true;
		}
		return false;
	break;
	case "NPC_Death":
		return CharacterIsDead(refCharacter);
	break;
	case "Nation_Ship_sink":
		return TestIntValue(GetNationShipKilled(refCharacter,condition.nation),sti(condition.quantity),condition.operation);
	break;
	case "Nation_Ship_Capture":
		return TestIntValue(GetNationShipCaptured(refCharacter,condition.nation),sti(condition.quantity),condition.operation);
	break;
	case "Class_Ship_sink":
		return TestIntValue(GetClassShipKilled(refCharacter,sti(condition.class)),sti(condition.quantity),condition.operation);
	break;
	case "Class_Ship_Capture":
		return TestIntValue(GetClassShipCaptured(refCharacter,sti(condition.class)),sti(condition.quantity),condition.operation);
	break;
	case "Time":
		return GetDayTime() == condition.time;
	break;
	case "Timer":
		if( GetDataYear() < sti(condition.date.year) ) return false;
		if( GetDataYear() > sti(condition.date.year) ) return true;
		if( GetDataMonth() < sti(condition.date.month) ) return false;
		if( GetDataMonth() > sti(condition.date.month) ) return true;
		if( GetDataDay() < sti(condition.date.day) ) return false;
		return true;
	break;
	case "Ship_HP":
		return TestIntValue(GetCurrentShipHP(refCharacter),sti(condition.quantity),condition.operation);
	break;
	case "Quest":
		return CheckActiveQuest(condition.quest);
	break;
	case "Character_Capture":
		if( CheckAttribute(refCharacter,"Killer.status") && sti(refCharacter.Killer.status)==KILL_BY_ABORDAGE ) return true;
		return false;
	break;
	case "MapEnter":
		return IsEntity(worldMap);
	break;
	case "ExitFromLocation":
		return refCharacter.location != condition.location;
	break;
	case "Ship_location":
		if( CheckAttribute(refCharacter,"location.from_sea") && refCharacter.location.from_sea==condition.location ) return true;
		return false;
	break;
	case "Fort_destroy":
		if( CheckAttribute(refCharacter,"FortDestroy") && refCharacter.FortDestroy=="1" ) return true;
		return false;
	break;
	case "Group_Death":
		sTmpString = condition.group;
		aref grdeath; makearef(grdeath,refCharacter.GroupDeath);
		if( CheckAttribute(refCharacter,"GroupDeath."+sTmpString) && refCharacter.GroupDeath.(sTmpString)=="1" ) return true;
		return false;
	break;
	case "ActIntoLocator":
		if(refCharacter.location == condition.location)
		{
			locGroup = condition.locator_group;
			if( !CheckAttribute(refCharacter,"Quests.LocatorCheck."+locGroup) )
			{
				if(IsEntity(refCharacter))
				{
					refCharacter.Quests.LocatorCheck.(locGroup) = "";
					if( GetCharacterPos(refCharacter,&fx,&fy,&fz) )
					{
						if( CheckCurLocator(locGroup,condition.locator, fx,fy,fz) )
							refCharacter.Quests.LocatorCheck.(locGroup) = condition.locator;
					}
					AddCharacterLocatorGroup(refCharacter,locGroup);
				}
				else
				{
					Trace("character "+refCharacter.id+" not entity");
					return false;
				}
			}
			if(refCharacter.Quests.LocatorCheck.(locGroup)==condition.locator)
			{
				SetPossibleAction(refCharacter,condition,true);
			}
			else
			{
				SetPossibleAction(refCharacter,condition,false);
			}
		}
		return false;
	break;
	}
	trace("ERROR: unidentified condition type()" + condition);
	return false;
}

bool bQuestCheckProcess = false;
void QuestsCheck()
{
	if(bQuestCheckProcess) return;
	bQuestCheckProcess = true;
	aref quests;
	aref quest;
	aref conditions;
	aref condition;
	int  nQuestsNum;
	int  nConditionsNum;
	int  n,m;
	string sQuestName;
	bool bQuestCompleted;
	
	
	makearef(quests,Characters[GetMainCharacterIndex()].quest);
		
	nQuestsNum = GetAttributesNum(quests);
	
	for(n = 0; n < nQuestsNum; n++)
	{
		quest = GetAttributeN(quests,n);

		sQuestName = GetAttributeName(quest);

		if(CheckAttribute(quest,"win_condition"))
		{
			if(quest.win_condition == "no")
			{
				// quest with no win condition; completed on first check
				OnQuestComplete(quest);
				nQuestsNum = GetAttributesNum(quests);
				continue;
			}
			makearef(conditions,quest.win_condition);
			nConditionsNum = GetAttributesNum(conditions);
			if(nConditionsNum == 0)
			{
				// quest with no win condition; completed on first check
				OnQuestComplete(quest);
				nQuestsNum = GetAttributesNum(quests);
				continue;
			}
			bQuestCompleted = true;
			for(m = 0; m < nConditionsNum; m++)
			{
				condition = GetAttributeN(conditions,m);
				if(ProcessCondition(condition) == false) 
				{
					bQuestCompleted = false;
					break;
				}
			}
			if(bQuestCompleted) 
			{
				OnQuestComplete(quest);
				nQuestsNum = GetAttributesNum(quests);
			}
		}
		
		if(CheckAttribute(quest,"fail_condition"))
		{
			makearef(conditions,quest.fail_condition);
			nConditionsNum = GetAttributesNum(conditions);
			if(nConditionsNum == 0) continue;
			for(m = 0; m < nConditionsNum; m++)
			{
				condition = GetAttributeN(conditions,m);
				if(ProcessCondition(condition) == true) 
				{
					OnQuestFailed(quest);
					nQuestsNum = GetAttributesNum(quests);
					break;
				}
			}
		}
	}

	for(n = 0; n < GetAttributesNum(quests); n++)
	{
		quest = GetAttributeN(quests,n);
		if(CheckAttribute(quest,"over") && quest.over=="yes")
		{
			// delete quests already completed or failed
			DeleteAttribute(quests,GetAttributeName(quest));
			n--;
		}
	}
	bQuestCheckProcess = false;
}

void OnQuestComplete(aref quest)
{
	if(!CheckAttribute(quest,"over") && CheckAttribute(quest,"win_condition"))
	{
		quest.over = "yes";
		QuestComplete(quest.win_condition);
		BothQuestComplete(quest.win_condition);
	}
}

void OnQuestFailed(aref quest)
{
	if(CheckAttribute(quest,"fail_condition"))
	{
		quest.over = "yes";
		QuestComplete(quest.fail_condition);
		BothQuestComplete(quest.win_condition);
	}
}

void QC_DoUnloadLocation()
{
	DeleteAttribute(GetMainCharacter(),"GroupDeath");
	for(int n=0; n<MAX_CHARACTERS; n++)
	{
		DeleteAttribute(GetCharacter(n),"Quests.LocatorCheck");
	}
}

void SetPossibleAction(ref chref, aref condition, bool setting)
{
	if(setting)
	{
		if(CheckAttribute(condition,"act"))
		{
			condition.oldact = g_ActiveActionName;
			Log_SetActiveAction(condition.act);
		}
		chref.Quests.quest_act = GetAttributeName(condition);
	}
	else
	{
		if(CheckAttribute(condition,"oldact"))
		{
			Log_SetActiveAction(condition.oldact);
			DeleteAttribute(condition,"oldact");
		}
		DeleteAttribute(chref,"Quests.quest_act");
	}
}

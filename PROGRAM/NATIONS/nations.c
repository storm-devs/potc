extern void InitNations();

#event_handler(GET_RELATION_EVENT,"GetRelationEvent");

void Nations_SetAllFriends()
{
	int i;
	
	for(i=0;i<MAX_NATIONS_SQR;i++)
	{
		NationsRelations[i] = RELATION_FRIEND;
	}

	for(i=0;i<MAX_NATIONS;i++)
	{
		NationsRelations2MainCharacter[i] = RELATION_FRIEND;
	}
}

void NationsInit()
{
	if(LoadSegment("nations\nations_init.c"))
	{
		InitNations();
		UnloadSegment("nations\nations_init.c");
	}
    
	Nations_SetAllFriends();

	/*SetNationRelation2MainCharacter(PIRATE,RELATION_ENEMY);
	SetNationRelation2MainCharacter(FRANCE,RELATION_ENEMY);
	SetNationRelation(FRANCE,ENGLAND,RELATION_ENEMY);
	SetNationRelation(FRANCE,PIRATE,RELATION_ENEMY);
	SetNationRelation(PIRATE,FRANCE,RELATION_ENEMY);
	SetNationRelation(FRANCE,HOLLAND,RELATION_ENEMY);
	SetNationRelation(HOLLAND,FRANCE,RELATION_ENEMY);*/
}

void SetNationRelation2MainCharacter(int iNation, int iRelationType)
{
	NationsRelations2MainCharacter[iNation] = iRelationType;
}

void SetNationRelationBoth(int iNation1, int iNation2, int iRelationType)
{
	NationsRelations[iNation1 * MAX_NATIONS + iNation2] = iRelationType;
	NationsRelations[iNation2 * MAX_NATIONS + iNation1] = iRelationType;
}

void SetNationRelation(int iNation1, int iNation2, int iRelationType)
{
	NationsRelations[iNation1 * MAX_NATIONS + iNation2] = iRelationType;
}

// =================================================================================================
// Character Relation
// =================================================================================================
void SetCharacterRelationAsOtherCharacter(int iCharacterIndex1, int iCharacterIndex2)
{
	Characters[iCharacterIndex1].relation.UseOtherCharacter = iCharacterIndex2;
}

void SetCharacterRelationBoth(int iCharacterIndex1, int iCharacterIndex2, int iRelationType)
{
	SetCharacterRelation(iCharacterIndex1, iCharacterIndex2, iRelationType);
	SetCharacterRelation(iCharacterIndex2, iCharacterIndex1, iRelationType);
}

void SetCharacterRelation(int iCharacterIndex1, int iCharacterIndex2, int iRelationType)
{
	string sTemp1 = "" + iCharacterIndex2;
	Characters[iCharacterIndex1].relation.(sTemp1) = iRelationType;
}

// =================================================================================================
// Get Relation Methods
// =================================================================================================
int GetNationRelation(int iNation1, int iNation2)
{
	return NationsRelations[iNation1 * MAX_NATIONS + iNation2];
}

int GetNationRelation2MainCharacter(int iNation)
{
	return NationsRelations2MainCharacter[iNation];
}

int GetNationRelation2Character(int iNation, int iCharacterIndex)
{
	ref rCharacter = GetCharacter(iCharacterIndex);

	if (CheckAttribute(&rCharacter, "relation.UseOtherCharacter"))
	{
		if (sti(rCharacter.relation.UseOtherCharacter) >= 0)
		{
			rCharacter = GetCharacter(sti(rCharacter.relation.UseOtherCharacter));
		}
	}

	int iMCI = GetMainCharacterIndex();
	int iNation2 = sti(rCharacter.nation);
	if (iMCI == sti(rCharacter.index))
	{
		return NationsRelations2MainCharacter[iNation];
	}
	return NationsRelations[iNation * MAX_NATIONS + iNation2];
}

int GetRelation(int iCharacterIndex1, int iCharacterIndex2)
{
	int iMCI = GetMainCharacterIndex();

	ref rCharacter1 = GetCharacter(iCharacterIndex1);
	ref rCharacter2 = GetCharacter(iCharacterIndex2);

	if (CheckAttribute(&rCharacter1, "relation.UseOtherCharacter"))
	{
		if (sti(rCharacter1.relation.UseOtherCharacter) >= 0)
		{
			rCharacter1 = GetCharacter(sti(rCharacter1.relation.UseOtherCharacter));
		}
	}
	if (CheckAttribute(&rCharacter2, "relation.UseOtherCharacter"))
	{
		if (sti(rCharacter2.relation.UseOtherCharacter) >= 0)
		{
			rCharacter2 = GetCharacter(sti(rCharacter2.relation.UseOtherCharacter));
		}
	}

	if (rCharacter1.index == rCharacter2.index) return RELATION_FRIEND;

	// character 2 character relation
	{
		string sTemp = "relation." + rCharacter2.index;
		if (CheckAttribute(&rCharacter1,sTemp))
		{
			return sti(rCharacter1.(sTemp));
		}
	}
	//Trace("iNation1 = " + iNation1 + ", iNation2 = " + iNation2);

	int iNation1 = sti(rCharacter1.nation);
	int iNation2 = sti(rCharacter2.nation);

	// nation 2 character relation
	if (iMCI == sti(rCharacter1.index))
	{
		//Trace("iMainCharacterRelation = " + NationsRelations2MainCharacter[iNation2]);
		return NationsRelations2MainCharacter[iNation2];
	}
	if (iMCI == sti(rCharacter2.index))
	{
		//Trace("iMainCharacterRelation = " + NationsRelations2MainCharacter[iNation1]);
		return NationsRelations2MainCharacter[iNation1];
	}

	// nation 2 nation relation
	return NationsRelations[iNation1 * MAX_NATIONS + iNation2];
}

int GetRelationEvent()
{
	int iCharacterIndex1 = GetEventData();
	int iCharacterIndex2 = GetEventData();
	return GetRelation(iCharacterIndex1, iCharacterIndex2);
}

int FindEnemyNation2Nation(int iNation)
{
	int iNations[MAX_NATIONS];
	int iNumNations = 0;

	for (int i=0;i<MAX_NATIONS;i++)
	{
		if (GetNationRelation(i,iNation) == RELATION_ENEMY)
		{
			iNations[iNumNations] = i;
			iNumNations++;
		}
	}
	if (iNumNations == 0) return -1;
	return iNations[rand(iNumNations - 1)];
}

int FindEnemyNation2Character(int iCharacterIndex)
{
	int iNations[MAX_NATIONS];
	int iNumNations = 0;

	for (int i=0; i<MAX_NATIONS; i++)
	{
		if (GetNationRelation2Character(i, iCharacterIndex) == RELATION_ENEMY)
		{
			iNations[iNumNations] = i;
			iNumNations++;
		}
	}
	if (iNumNations == 0) return -1;
	return iNations[rand(iNumNations - 1)];
}

int GetNationTypeByName(string nationName)
{
	for(int i=0; i<MAX_NATIONS; i++)
	{
		if(Nations[i].Name==nationName) return i;
	}
	return -1;
}

string GetNationNameByType(int iNationType)
{
	if (iNationType < MAX_NATIONS)
	{
		return Nations[iNationType].Name;
	}
	return -1;
}

ref GetNationByType(int iNationType)
{
	return &Nations[iNationType];
}
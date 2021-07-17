object	Sea;

void SeaAI_GetLayers()
{
	aref oTmp = GetEventData();
	SendMessage(oTmp, "lss", AI_MESSAGE_SET_LAYERS, sCurrentSeaExecute, sCurrentSeaRealize);
}

void DeleteSea()
{
	DeleteClass(&Sea);
}

void CreateSea(string sExecuteLayer, string sRealizeLayer)
{
	if (IsEntity(&Sea)) { Trace("ERROR: Sea Already Loaded!!!"); return; }

	CreateEntity(&Sea, "sea");
	MoveSeaToLayers(sExecuteLayer, sRealizeLayer);

	LayerFreeze("sea_reflection", false);

	Sea.AbordageMode = false;
}

void MoveSeaToLayers(string sExecuteLayer, string sRealizeLayer)
{
	LayerDelObject("execute", &Sea);
	LayerDelObject("realize", &Sea);
	LayerDelObject(SEA_EXECUTE, &Sea);
	LayerDelObject(SEA_REALIZE, &Sea);

	LayerAddObject(sExecuteLayer, &Sea, 4);
	LayerAddObject(sRealizeLayer, &Sea, 65530);
}

#define SAIL_TO_LOCATOR			0
#define SAIL_TO_CHARACTER		1

object	SailToFader;
int		iSailToType;
string	sSailToString;

void SeaAI_SailToEndFade()
{
	DelEventHandler("FaderEvent_EndFade", "SeaAI_SailToEndFade");
	SendMessage(SailToFader, "lfl", FADER_IN, 0.5, true);

	// delete current cannonballs
	AIBalls.Clear = "";

	switch (iSailToType)
	{
		case SAIL_TO_LOCATOR:
			ref rCharacter = GetMainCharacter();
			aref rIslLoc = FindIslandReloadLocator(rCharacter.Location, sSailToString);
			SendMessage(AISea,"lfff", AI_MESSAGE_SAIL_2_LOCATOR, stf(rIslLoc.x), stf(rIslLoc.y), stf(rIslLoc.z));
		break;
		case SAIL_TO_CHARACTER:
			SendMessage(AISea, "laff", AI_MESSAGE_SAIL_2_CHARACTER, &Characters[sti(sSailToString)], 40.0 + frnd() * 60.0, frnd() * PIm2);
		break;
	}
}

void SeaAI_SailToCreateFader()
{
	SetEventHandler("FaderEvent_EndFade", "SeaAI_SailToEndFade", 0);

	CreateEntity(&SailToFader, "fader");
	SendMessage(SailToFader, "lfl", FADER_OUT, 0.5, false);
	SendMessage(SailToFader, "l", FADER_STARTFRAME);
	SendMessage(SailToFader, "ls", FADER_PICTURE, "loading\sea.tga");
}

void SeaAI_SailToLocator(string sLocName)
{
	iSailToType = SAIL_TO_LOCATOR;
	sSailToString = sLocName;
	SeaAI_SailToCreateFader();
}

void SeaAI_SailToCharacter(int iCharacterIndex)
{
	iSailToType = SAIL_TO_CHARACTER;
	sSailToString = "" + iCharacterIndex;
	SeaAI_SailToCreateFader();
}

void AISea_ReturnFromAbordage()
{
	MoveSeaToLayers(SEA_EXECUTE,SEA_REALIZE);
	MoveWeatherToLayers(SEA_EXECUTE,SEA_REALIZE);

	LayerFreeze("realize",true);
	LayerFreeze("execute",true);

	LayerFreeze(SEA_EXECUTE,false);
	LayerFreeze(SEA_REALIZE,false);

	Sea.MaxSeaHeight = 50.0;

}

void SeaAI_SwapShipsAttributes(ref refMyCharacter, ref refEnemyCharacter)
{
	aref	arShipMy, arShipEnemy;
	object	oTmp;

	makearef(arShipMy,refMyCharacter.Ship);
	makearef(arShipEnemy,refEnemyCharacter.Ship);

	CopyAttributes(&oTmp,arShipMy);
	DeleteAttribute(arShipMy,"");
	CopyAttributes(arShipMy,arShipEnemy);
	DeleteAttribute(arShipEnemy,"");
	CopyAttributes(arShipEnemy,&oTmp);
}

bool SeaAI_SwapShipWithCompanion(ref refMyCharacter, ref refEnemyCharacter)
{
	if (!IsEntity(AISea)) return false;
	SendMessage(&AISea, "laa", AI_MESSAGE_SWAP_SHIPS, refMyCharacter, refEnemyCharacter);
	UpdateRelations();
	return true;
}

bool SeaAI_SwapShipAfterAbordage(ref refMyCharacter, ref refEnemyCharacter)
{
	if (bSeaActive)
	{
		SendMessage(&AISea, "laa", AI_MESSAGE_SWAP_SHIPS, refMyCharacter, refEnemyCharacter);
		UpdateRelations();
	}
	return true;
}

void SeaAI_SetCompanionEnemy(ref rCharacter)
{
	int		iCharacterIndex = sti(rCharacter.index);
	string	sGroupName = "cmpenemy_" + rCharacter.index;

	RemoveCharacterCompanion(GetMainCharacter(), rCharacter);

	Group_DelCharacter(rCharacter.SeaAI.Group.Name, rCharacter.id);

	rCharacter.SeaAI.Group.Name = sGroupName;
	Group_AddCharacter(sGroupName, rCharacter.id);
	Group_SetGroupCommander(sGroupName, rCharacter.id);

	SendMessage(&AISea, "la", AI_MESSAGE_SET_COMPANION_ENEMY, rCharacter);
	
	Group_SetTaskAttack(sGroupName, PLAYER_GROUP);
	Group_DeleteAtEnd(sGroupName);

	SetCharacterRelationBoth(iCharacterIndex, GetMainCharacterIndex(), RELATION_ENEMY);

	Event("eSwitchPerks", "l", iCharacterIndex);
	Event("eSwitchPerks", "l", GetMainCharacterIndex());

	Event(SHIP_UPDATE_PARAMETERS, "lf", iCharacterIndex, 1.0);				// Parameters
	Event(SHIP_UPDATE_PARAMETERS, "lf", GetMainCharacterIndex(), 1.0);		// Parameters

	UpdateRelations();
	RefreshBattleInterface();
}

bool SeaAI_SetOfficer2ShipAfterAbordage(ref refMyCharacter, ref refEnemyCharacter)
{
	int iMyCharacterIndex = sti(refMyCharacter.index);
	if (bSeaActive)
	{
		Group_DelCharacter(refEnemyCharacter.SeaAI.Group.Name, refEnemyCharacter.id);
		SendMessage(&AISea, "laa", AI_MESSAGE_SET_OFFICER_2_SHIP, refMyCharacter, refEnemyCharacter);
		Event("eSwitchPerks", "l", iMyCharacterIndex);
		Event(SHIP_UPDATE_PARAMETERS, "lf", iMyCharacterIndex, 1.0);		// Parameters
		UpdateRelations();
	}
	return true;
}

int SeaAI_GetRelation(int iCharacterIndex1, int iCharacterIndex2)
{
	int iRelation = RELATION_NEUTRAL; 
	if (bSeaActive)
	{
		SendMessage(&AISea, "laae", AI_MESSAGE_GET_RELATION, &Characters[iCharacterIndex1], &Characters[iCharacterIndex2], &iRelation);
		return iRelation;
	}
	return GetRelation(iCharacterIndex1, iCharacterIndex2);
}

void UpdateRelations()
{
	if (bSeaActive)
	{
		SendMessage(&AISea, "l", AI_MESSAGE_UPDATE_RELATIONS);
	}
}

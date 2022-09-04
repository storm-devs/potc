void CreateReloadPaths(string groupID)
{
	if(CheckAttribute(&objFastReloadTable,"Paths.table") && objFastReloadTable.Paths.table == groupID) return;
	DeleteAttribute(&objFastReloadTable,"Paths");
	objFastReloadTable.Paths.table = groupID;
	objFastReloadTable.Paths.shipLocation = Characters[GetMainCharacterIndex()].location.from_sea;
	aref tbl; makearef(tbl,objFastReloadTable.Paths.table);

	int i,j,n;
	string outLocName,goLocName;
	aref reloadList,curReload;

	// запишем все переходы в локациях используемой группы
	for(i=0; i<MAX_LOCATIONS; i++)
	{
		if( !CheckAttribute(&Locations[i],"fastreload") ) continue;
		if( Locations[i].fastreload != groupID ) continue;
		outLocName = Locations[i].id;
		makearef(reloadList,Locations[i].reload);
		tbl.(outLocName) = i;
		for(j=0; j<GetAttributesNum(reloadList); j++)
		{
			curReload = GetAttributeN(reloadList,j);
			goLocName = curReload.go;
			if(outLocName == goLocName) continue;
			if( !CheckAttribute(tbl,outLocName+"."+goLocName) )
			{
				tbl.(outLocName).(goLocName) = goLocName;
				tbl.(outLocName).(goLocName).goLocator = curReload.emerge;
				tbl.(outLocName).(goLocName).outLocator = curReload.name;
			}
		}
	}

	// заполним все пути перехода из одной локации в другую
	aref outLoc,goLoc, tmpLoc;
	bool yesChange = true;
	string tmpLocName;
	while(yesChange)
	{
		yesChange = false;
		for(i=0; i<GetAttributesNum(tbl); i++)
		{
			outLoc = GetAttributeN(tbl,i);
			outLocName = GetAttributeName(outLoc);
			for(j=0; j<i; j++)
			{
				if(j==i) continue;
				goLoc = GetAttributeN(tbl,j);
				goLocName = GetAttributeName(goLoc);
				if( CheckAttribute(outLoc,goLocName) ) continue;
				for(n=0; n<GetAttributesNum(outLoc); n++)
				{
					tmpLoc = GetAttributeN(outLoc,n);
					tmpLocName = GetAttributeName(tmpLoc);
					if( CheckAttribute(tbl,tmpLocName+"."+goLocName) )
					{
						yesChange = true;
						outLoc.(goLocName) = tmpLocName;
						outLoc.(goLocName).goLocator = tbl.(tmpLocName).(goLocName).goLocator;
						outLoc.(goLocName).outLocator = tmpLoc.outLocator;
						break;
					}
				}
			}
		}
	}
}

// получить идентификатор следующей локации для перехода из одной локации в другую
// возвращает true, если поиск пути завершен
bool GetNextLocationForPath(string outLocName, string goLocName, ref nextLocName, ref reloadName)
{
	aref tbl; makearef(tbl,objFastReloadTable.Paths.table);

	string finalLocation = goLocName;
	nextLocName = "";
	reloadName = "";

	while(outLocName!=goLocName)
	{
		// Прописан прямой путь от стартовой локации до искомой
		if( CheckAttribute(tbl,outLocName+"."+goLocName) )
		{
			nextLocName = tbl.(outLocName).(goLocName);
			reloadName = tbl.(outLocName).(goLocName).outLocator;
			break;
		}

		// Обратный путь так же не прописан
		if( !CheckAttribute(tbl,goLocName+"."+outLocName) ) {break;}

		// Из искомой локации мы можем непосредственно попасть в стартовую локацию
		if( tbl.(goLocName).(outLocName) == finalLocation )
		{
			nextLocName = goLocName;
			reloadName = tbl.(goLocName).(outLocName).goLocator;
			break;
		}

		if( goLocName == tbl.(goLocName).(outLocName) ) {break;}

		goLocName = tbl.(goLocName).(outLocName)
	}

	if(nextLocName=="" || nextLocName==finalLocation) return true;
	return false;
}

string GetFastReloadName(string outLocName, string goLocName)
{
	aref tbl; makearef(tbl,objFastReloadTable.Paths.table);
	if( CheckAttribute(tbl,outLocName+"."+goLocName) )
		return tbl.(outLocName).(goLocName).goLocator;
	if( CheckAttribute(tbl,goLocName+"."+outLocName) )
		return tbl.(goLocName).(outLocName).outLocator;
	return "";
}

bool CheckQuestPresents(string locationName)
{
	int  n,m;
	aref quest;
	string sQuestName;
	aref conditions;

	aref quests;	makearef(quests,Characters[GetMainCharacterIndex()].quest);
	int  nQuestsNum = GetAttributesNum(quests);

	for(n = 0; n < nQuestsNum; n++)
	{
		quest = GetAttributeN(quests,n);
		sQuestName = GetAttributeName(quest);
		if(CheckAttribute(quest,"win_condition"))
		{
			makearef(conditions,quest.win_condition);
			if( CheckConditionPresents(conditions,locationName) ) return true;
		}
		if(CheckAttribute(quest,"fail_condition"))
		{
			makearef(conditions,quest.fail_condition);
			if( CheckConditionPresents(conditions,locationName) ) return true;
		}
	}
	return false;
}

bool CheckConditionPresents(aref conditions, string locationName)
{
	int n;
	aref condition;
	int  nConditionsNum = GetAttributesNum(conditions);
	for(n = 0; n < nConditionsNum; n++)
	{
		condition = GetAttributeN(conditions,n);
		switch(GetAttributeValue(condition))
		{
		case "location":
			if(condition.location==locationName) return true;
		break;
		case "locator":
			if(condition.location==locationName) return true;
		break;
		case "ExitFromLocation":
			if(condition.location==locationName) return true;
		break;
		}
	}
	return false;
}

void PlayerFastTravel(int startLocIdx, string finishLocName)
{
	if(startLocIdx<0 || startLocIdx>=MAX_LOCATIONS || finishLocName=="") return;

	string checkLocation, nextLocName, reloadName;

	checkLocation = Locations[startLocIdx].id;
	if(checkLocation==finishLocName)
	{
		Log_SetStringToLog(XI_ConvertString("You are already there"));
		return;
	}

	while(checkLocation!=finishLocName)
	{
		if( CheckQuestPresents(checkLocation) ) {break;}
		if( GetNextLocationForPath(checkLocation, finishLocName, &nextLocName, &reloadName) )
		{
			if(nextLocName=="") {break;}
			checkLocation = nextLocName;
			break;
		}
		if(checkLocation == nextLocName) break;
		checkLocation = nextLocName;
	}

	if(checkLocation!=Locations[startLocIdx].id)
	{
		reloadName = GetFastReloadName(Locations[startLocIdx].id,checkLocation);
		if(reloadName=="") {
			Log_SetStringToLog(XI_ConvertString("There is no way there now"));
			return;
		} else {
			DoReloadCharacterToLocation(checkLocation,"reload",reloadName);
		}
	}

	if(checkLocation!=finishLocName)
	{
		if(checkLocation==Locations[startLocIdx].id)
			Log_SetStringToLog(XI_ConvertString("You can't leave this location now"));
		else
			Log_SetStringToLog(XI_ConvertString("Your walk was interrupted"));

		Log_SetStringToLog(XI_ConvertString("Looks like something is going to happen here"));
	}
}

int GetLocationNation(aref arLocation)
{
	if( CheckAttribute(arLocation,"ItsNation") )	return sti(arLocation.ItsNation);
	if( CheckAttribute(arLocation,"fastreload") )
	{
		string islName,locName;
		if( GetFortReloadFromTable(arLocation.fastreload, &islName, &locName) )
		{
			int chidx = Fort_FindCharacter(islName,"reload",locName);
			if(chidx>=0)
			{
				ref chref = GetCharacter(chidx);
				return sti(chref.nation);
			}
		}
	}
	return -1;
}

bool GetFortReloadFromTable(string tblName, ref refIslName, ref refLocName)
{
	switch (tblName)
	{
	case "Conceicao":
		refIslName="Conceicao";
		refLocName="reload_fort1";
		return true; break;
	case "Douwesen":
		refIslName="Douwesen";
		refLocName="reload_fort1";
		return true; break;
	case "Falaise_de_fleur":
		refIslName="FalaiseDeFleur";
		refLocName="reload_fort1";
		return true; break;
	case "Muelle":
		refIslName="IslaMuelle";
		refLocName="reload_fort1";
		return true; break;
	case "Oxbay":
		refIslName="Oxbay";
		refLocName="reload_fort2";
		return true; break;
	case "Greenford":
		refIslName="Oxbay";
		refLocName="reload_fort1";
		return true; break;
	/*case "QC":
		refIslName="";
		refLocName="";
		return true; break;*/
	case "Redmond":
		refIslName="Redmond";
		refLocName="reload_fort1";
		return true; break;
	}
	refIslName = "";
	refLocName = "";
	return false;
}

void SetTownCapturedState(string townName, bool captured)
{
	aref arTown,arTownsList;
	makearef(arTownsList,objTownStateTable.towns);
	int i,q;
	q = GetAttributesNum(arTownsList);

	for(i=0; i<q; i++)
	{
		arTown = GetAttributeN(arTownsList,i);
		if(arTown.name == townName)
		{
			arTown.captured = captured;
		}
	}
	trace("WARNING!!! Town name " + townName + " not found");
}

void SetLocationCapturedState(string locationID, bool captured)
{
	int locIdx = FindLocation(locationID);
	if(locIdx<0)
	{	trace("WARNING!!! location ID " + locationID + " not found");
		return;
	}
	if( CheckAttribute(&Locations[locIdx],"townsack") )
	{
		SetTownCapturedState(Locations[locIdx].townsack,captured);
	}
}

bool IsLocationCaptured(string locationID)
{
	int locIdx = FindLocation(locationID);
	if(locIdx<0)
	{
		trace("WARNING!!! location ID " + locationID + " not found");
		return false;
	}

	if( !CheckAttribute(&Locations[locIdx],"townsack") ) return false;

	string townName = Locations[locIdx].townsack;
	aref arTown,arTownsList;
	makearef(arTownsList,objTownStateTable.towns);
	int i,q;
	q = GetAttributesNum(arTownsList);

	for(i=0; i<q; i++)
	{
		arTown = GetAttributeN(arTownsList,i);
		if(arTown.name == townName)
		{
			return sti(arTown.captured);
		}
	}

	return false;
}

void SetFortCharacterCaptured(ref chref, bool captured)
{
	string sToLocation = "";
	aref ar_FindLoc = FindIslandReloadLocator(chref.location,chref.location.locator);
	if(CheckAttribute(ar_FindLoc,"GoAfterBoard.location"))
	{
		ar_FindLoc = FindIslandReloadLocator(chref.location,ar_FindLoc.GoAfterBoard.location);
		if( CheckAttribute(ar_FindLoc,"go") )
		{	sToLocation = ar_FindLoc.go;
		}
	}
	SetLocationCapturedState(sToLocation,captured);
}

void RecalculateHireCrew(int locIdx)
{
	if(locIdx<0 || !CheckAttribute(&Locations[locIdx],"townsack")) return;

	string townName = Locations[locIdx].townsack;
	aref arTown,arTownsList;
	makearef(arTownsList,objTownStateTable.towns);
	int i,q;
	q = GetAttributesNum(arTownsList);

	for(i=0; i<q; i++)
	{
		arTown = GetAttributeN(arTownsList,i);
		if(arTown.name == townName)
		{
			break;
		}
	}

	if(i>=q)  return;
	aref arData;
	if(!CheckAttribute(arTown,"crew.data")) return;
	makearef(arData,arTown.crew.data);

	int nYear = 1;
	int nMonth = 1;
	int nDay = 1;
	if( CheckAttribute(arData,"year") ) nYear = sti(arData.year);
	if( CheckAttribute(arData,"month") ) nMonth = sti(arData.month);
	if( CheckAttribute(arData,"day") ) nDay = sti(arData.day);

	int pastDays = GetPastTime( "day", nYear,nMonth,nDay,0.0,
		GetDataYear(),GetDataMonth(),GetDataDay(),0.0 );
	if(pastDays<10) return;

	arData.year = GetDataYear();
	arData.month = GetDataMonth();
	arData.day = GetDataDay();

	int nPastQ = 0;
	int nPastM = MORALE_NORMAL;
	if(CheckAttribute(arTown,"crew.quantity"))	nPastQ = sti(arTown.crew.quantity);
	if(CheckAttribute(arTown,"crew.morale"))	nPastM = sti(arTown.crew.morale);

	int nNeedCrew = 0;
	int cn;
	for(i=0; i<4; i++)
	{
		cn = GetCompanionIndex(GetMainCharacter(),i);
		if(cn>=0)
		{
			nNeedCrew += GetMaxCrewQuantity(GetCharacter(cn));
		}
	}

	if(nPastQ>nNeedCrew)
	{	nPastM = MORALE_NORMAL + rand(MORALE_MAX-MORALE_NORMAL);
		nPastQ = nNeedCrew + rand(nNeedCrew);
	}
	else
	{	nPastM = MORALE_NORMAL/3 + rand(MORALE_NORMAL/3*2);
		nPastQ = nNeedCrew/2 + rand(nNeedCrew);
	}

	arTown.crew.quantity = nPastQ;
	arTown.crew.morale = nPastM;
}

void RecalculateJumpTable()
{
	string outGroupName = "";
	if( CheckAttribute(&objFastReloadTable,"Paths.table") )
		outGroupName = objFastReloadTable.Paths.table;
	objFastReloadTable.Paths.table = "";
	CreateReloadPaths(outGroupName);
}

bool CheckFastJump(string sFromLocation, string sToLocation)
{
	if(sFromLocation==sToLocation) return false;
	string curLocName, nextLocName, reloadName;

	bool bNoBreak = true;
	curLocName = sFromLocation;
	while(bNoBreak && curLocName!=sToLocation)
	{
		bNoBreak = !GetNextLocationForPath(curLocName, sToLocation, &nextLocName, &reloadName);
		if(nextLocName=="" || reloadName=="") {return false;}
		if( !IsEnableLocToLocReload(curLocName,nextLocName,reloadName) ) {return false;}
		curLocName = nextLocName;
	}

	return true;
}

bool IsEnableLocToLocReload(string sFromLocName, string sToLocName, string locatorName)
{
	aref tbl;
	makearef(tbl,objFastReloadTable.Paths.table);
	if( !CheckAttribute(tbl,sFromLocName) ) return false;

	return chrCheckReload( &Locations[sti(tbl.(sFromLocName))], locatorName );
/*
	int n, q, nFromIdx;
	aref arRootReload, arReload;

	nFromIdx = sti(tbl.(sFromLocName));
	makearef(arRootReload, Locations[nFromIdx].reload);

	q = GetAttributesNum(arRootReload);
	for(n=0; n<q; n++)
	{
		arReload = GetAttributeN(arRootReload,n);
		if( CheckAttribute(arReload,"name") && arReload.name==locatorName )
		{
			if( CheckAttribute(arReload,"disable") && sti(arReload.disable)>0 ) {return false;}
			return true;
		}
	}

	return false;*/
}

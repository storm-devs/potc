#include "quests\quests_abordage.c"
#include "quests\quests_check.c"
#include "quests\quests_movie.c"
#include "quests\characters_task.c"
#include "quests\quests_scenes.c"
#include "quests\both_reaction.c"
#include "quests\quests_reaction.c"

#event_handler("LocationWaitNihgtEnd","WaitDatePostEventControl");
#event_handler("evntQuestCameraRestore","QuestCameraRestore");
#event_handler("QuestDelayExit","DoQuestDelayExit");
#event_handler("QuitFromWorldMap","ReloadFromWMtoL_complete");
#event_handler(FORT_DESTROYED,"QuestFortDestroyed");
#event_handler(EVENT_CHARACTER_GROUPDEAD,"QuestGroupDeath");
#event_handler("wdmCreateMap","QuestsCheck");
#event_handler("evntQuestsCheck","QuestsCheck");
#event_handler("evntQuestComplete","procEvntQuestComplete");

void QuestsInit()
{
	ref rch = GetMainCharacter();
	aref postEvDelay, arTmp;
	makearef(postEvDelay,rch.PostEventQuest.questDelay);
	int q = GetAttributesNum(postEvDelay);
	for(int i=0; i<q; i++)
	{
		arTmp = GetAttributeN(postEvDelay,i);
		DoQuestCheckDelay(arTmp.qname, stf(arTmp.delay));
	}

	SetEventHandler(EVENT_CHARACTER_DEAD,"CharacterDeadProcess",0);
	SetEventHandler(EVENT_LOCATION_LOAD,"QuestsCheck_forLocEnter",0);
	SetEventHandler(EVENT_LOCATION_LOAD,"ExecuteLocationEntryActivity",0);
	SetEventHandler(EVENT_LOCATION_UNLOAD,"QC_DoUnloadLocation",0);
	SetEventHandler(EVENT_SEA_LOGIN,"QuestsCheck",0);
	SetEventHandler(EVENT_DIALOG_EXIT,"QuestDialogExitProcedure",0);
	SetEventHandler("NextDay","QuestsCheck",0);
	SetEventHandler(SHIP_DEAD,"QuestsCheck",0);

	SetEventHandler(ABORDAGE_START_EVENT,"QuestAbordageStartEvent",0);
}

void QuestsCheck_forLocEnter()
{
	QC_DoUnloadLocation();
	QuestsCheck();
}

void CharacterDeadProcess()
{
	aref charef = GetEventData();
	ref chref = GetCharacter(sti(charef.index));

	int charType = FindFellowtravellers(GetMainCharacter(),chref);
	switch(charType)
	{
	case FELLOWTRAVEL_COMPANION:
		RemoveCharacterCompanion(GetMainCharacter(),chref);
	break;
	case FELLOWTRAVEL_OFFICER:
		RemoveOfficersIndex(GetMainCharacter(),sti(chref.index));
		RemovePassenger(GetMainCharacter(),chref);
	break;
	case FELLOWTRAVEL_PASSENGER:
		RemovePassenger(GetMainCharacter(),chref);
	break;
	case FELLOWTRAVEL_CAPTIVE:
		RemovePassenger(GetMainCharacter(),chref);
	break;
	}
	QuestsCheck();
}

//*****************************************************
// Quest information utilite
//*****************************************************
aref GetQuestData(string idQuest)
{
	aref qdat;
	ref mainCh = GetMainCharacter();
	makearef(qdat,mainCh.QuestInfo.(idQuest));
	return qdat;
}
bool CheckQuestRecord(aref qref,string textId)
{
	/*if( CheckAttribute(qref,"Text") )
	{
		int pos0,pos1;
		string strpatch;
		pos0 = 0;
		while(true)
		{
			pos1 = findSubStr(qref.Text,",",pos0));
			if(pos1==-1)
			{
			}
			else
			{
			}
		}
	}
	else return false;*/
	bool retVal = SendMessage(&GameInterface,"las",MSG_INTERFACE_CHECK_QRECORD,qref,textId);
	return retVal;
}
void SetQuestHeader(string idQuest)
{
	ref mainCh = GetMainCharacter();
	if(!CheckAttribute(mainCh,"QuestInfo."+idQuest))
	{
		object refNewAttr;
		refNewAttr.(idQuest).Complete = false;
		refNewAttr.(idQuest).Text = "";

		aref refOldAttr; makearef(refOldAttr,mainCh.QuestInfo);
		string qName;
		aref curQ, newQ,oldQ;
		for(int i=0; i<GetAttributesNum(refOldAttr); i++)
		{
			curQ = GetAttributeN(refOldAttr,i);
			qName = GetAttributeName(curQ);
			refNewAttr.(qName) = "";
			makearef(newQ,refNewAttr.(qName));
			makearef(oldQ,refOldAttr.(qName));
			CopyAttributes(newQ,oldQ);
		}
		CopyAttributes(refOldAttr,&refNewAttr);
	}
}
void AddQuestRecord(string idQuest,string idText)
{
	if(CheckAttribute(GetMainCharacter(),"QuestInfo."+idQuest)==false)
	{
		SetQuestHeader(idQuest);
	}
	ref mc = GetMainCharacter();
	if( CheckAttribute(mc,"QuestInfo."+idQuest+".Text") && mc.QuestInfo.(idQuest).Text!="")
	{
		aref questRef; makearef(questRef,mc.QuestInfo.(idQuest));
		if( !CheckQuestRecord(questRef,idText) )
		{
			string tmpStr = idText+","+questRef.Text;
			questRef.Text = tmpStr;
			Log_SetStringToLog(XI_ConvertString("Logbook Update"));
			AddMsgToCharacter(mc,MSGICON_LOGBOOK);
			PlayStereoSound("notebook");
		}
	}
	else
	{
		mc.QuestInfo.(idQuest).Text=idText;
		Log_SetStringToLog(XI_ConvertString("Logbook Update"));
		AddMsgToCharacter(mc,MSGICON_LOGBOOK);
		PlayStereoSound("notebook");
	}
}
void CloseQuestHeader(string idQuest)
{
	ref mc = GetMainCharacter();
	if(CheckAttribute(mc,"QuestInfo."+idQuest)==false) return;
	object questRef;
	CopyAttributes(&questRef,GetQuestData(idQuest));
	questRef.Complete = true;
	DeleteAttribute(mc,"QuestInfo."+idQuest);
	aref newAttr; makearef(newAttr,mc.QuestInfo.(idQuest));
	CopyAttributes(newAttr,questRef);
}
bool CheckActiveQuest(string idQuest)
{
	if(CheckAttribute(GetMainCharacter(),"QuestInfo."+idQuest)==false) return false;
	return true;
}
void DeleteQuestHeader(string idQuest)
{
	DeleteAttribute(GetMainCharacter(), "QuestInfo."+idQuest);
}

//**********************************************************************************
// Утилиты для работы с квестами
//==================================================================================

// проверить флаг состояния квеста
//-----------------------------------------
bool CheckQuestAttribute(string attributeName, string attributeValue)
{
	ref pchar = GetMainCharacter();
	if( CheckAttribute(pchar,"quest."+attributeName) )
		return (pchar.quest.(attributeName)==attributeValue);
	return false;
}

// удалить флаг состояния квеста
//------------------------------------------
void DeleteQuestAttribute(string attributeName)
{
	ref pchar = GetMainCharacter();
	if( CheckAttribute(pchar,"quest."+attributeName) )
		DeleteAttribute(pchar,"quest."+attributeName);
}

float GetLocatorSqrDistanceToMe(aref locatorRef)
{
	float x,y,z;
	GetCharacterPos(GetMainCharacter(),&x,&y,&z);
	x = stf(locatorRef.x)-x;
	y = stf(locatorRef.y)-y;
	z = stf(locatorRef.z)-z;
	return (x*x+y*y+z*z);
}
bool GetNearLocator(string groupName, ref float_dist, ref findedLocator, float minDistance)
{
	int loadLocationIndex = FindLoadedLocation();
	if(loadLocationIndex==-1) return false;
	ref refLoadLocation; makeref(refLoadLocation,Locations[loadLocationIndex]);
	if(!CheckAttribute(refLoadLocation,"locators."+groupName)) return false;
	aref refLocators; makearef(refLocators,refLoadLocation.locators.(groupName));
	int locatorsCount = GetAttributesNum(refLocators);
	int n;
	aref refCurLocator;
	bool  bYesFind = false;
	float minDist = 4000000.0;
	float curDist;
	for(n=0;n<locatorsCount;n++)
	{
		refCurLocator = GetAttributeN( refLocators, n );
		curDist = GetLocatorSqrDistanceToMe(refCurLocator);
		if(curDist<minDistance) continue;
		if(curDist>=minDist) continue;
		minDist = curDist;
		findedLocator = refCurLocator;
		bYesFind = true;
	}
	return bYesFind;
}

// установить персонажа в ближайший локатор группы goto (но не ближе минимальной дистанции)
//--------------------------------------------------------------------------------------------
bool SetCharacterToNearLocatorFromMe(string characterID, float minDistance)
{
	int loadLocationIndex = FindLoadedLocation();
	if(loadLocationIndex==-1) return false;
	float dist;
	aref findedLocator;
	if( !GetNearLocator( "goto", &dist, &findedLocator, minDistance) )
	{
		Trace("Can't goto group locators into location "+Locations[loadLocationIndex].id);
		return false;
	}
	ChangeCharacterAddress(CharacterFromID(characterID), Locations[loadLocationIndex].id, GetAttributeName(findedLocator));
	return true;
}

// получить ссылку на персонаж через его ID-шник
//------------------------------------------------------
ref CharacterFromID(string characterID)
{
	return &characters[GetCharacterIndex(characterID)];
}

string sPostWaitName;
int postWaitYear,postWaitMonth,postWaitDay,postWaitHour,postWaitMinute;
void WaitDatePostEventControl()
{
	AddDataToCurrent(postWaitYear,postWaitMonth,postWaitDay);
	AddTimeToCurrent(postWaitHour,postWaitMinute);
	if(sPostWaitName!="")	CompleteQuestName(sPostWaitName);
	QuestsCheck();
}

// пропустить некоторое время с фэйдом экрана
//----------------------------------------------------
void WaitDate(string postName,int year, int month, int day, int hour, int minute)
{
	sPostWaitName = postName;
	postWaitYear = year;
	postWaitMonth = month;
	postWaitDay = day;
	postWaitHour = hour;
	postWaitMinute = minute;
	WaitDatePostEventControl();
}

// установить камеру на просмотр корабля персонажа и вызвать квест через заданное число секунд
//---------------------------------------------------------------------------------------------
bool SetCameraToShipView(string characterName, string questCheckName, float viewTimeInSec)
{
	int chrIdx = GetCharacterIndex(characterName);
	if(chrIdx==-1) return false;
	ref chrRef = GetCharacter(chrIdx);

	float xship = stf(chrRef.ship.pos.x);
	float zship = stf(chrRef.ship.pos.z);

	float xchar,ychar,zchar;
	if( false==GetCharacterPos(GetMainCharacter(),&xchar,&ychar,&zchar) ) return false;

	float dx = xchar-xship;
	float dz = zchar-zship;
	float dist = sqrt(dx*dx+dz*dz);
	dx = dx/dist;
	dz = dz/dist;

	float xcam = xchar+dx*6.0;
	float zcam = zchar+dz*6.0;

	PostEvent("evntQuestCameraRestore",makeint(viewTimeInSec*1000),"s",questCheckName);

	return locCameraToPos(xcam,ychar+3.0,zcam,false);
}

void QuestCameraRestore()
{
	string sCameraQuestCheckName = GetEventData();
	locCameraFollow();
	if(sCameraQuestCheckName!="")
	{
		CompleteQuestName(sCameraQuestCheckName);
		QuestsCheck();
	}
}

// Закрыть все выходы на море в районе расположения своего корабля
//-----------------------------------------------------------------
bool QuestCloseSeaExit()
{
	ref mcRef = GetMainCharacter();
	int locIdx = FindLocation(mcRef.location.from_sea);
	if(locIdx==-1) return false;

	aref reloadRef;
	makearef(reloadRef,Locations[locIdx].reload);

	int n = GetAttributesNum(reloadRef);
	aref locRef;
	for(int i=0;i<n;i++)
	{
		locRef = GetAttributeN(reloadRef,i);
		if( FindIsland(locRef.go) != -1 )
		{
			chrEnableReloadLocator(Locations[locIdx].id, locRef.name, false);
		}
	}
	return true;
}

// Открыть все выходы на море в районе расположения своего корабля
//-----------------------------------------------------------------
bool QuestOpenSeaExit()
{
	ref mcRef = GetMainCharacter();
	int locIdx = FindLocation(mcRef.location.from_sea);
	if(locIdx==-1) return false;

	aref reloadRef;
	makearef(reloadRef,Locations[locIdx].reload);

	int n = GetAttributesNum(reloadRef);
	aref locRef;
	for(int i=0;i<n;i++)
	{
		locRef = GetAttributeN(reloadRef,i);
		if( FindIsland(locRef.go) != -1 )	chrEnableReloadLocator(Locations[locIdx].id, locRef.name, true);
	}
	return true;
}

// найти локатор в локации по имени
//-----------------------------------
bool FindLocator(string locationName, string locatorName, ref locatorRef, bool fromRealLoadedLocators)
{
	int i,j,n,m,locIdx;
	aref reloadRef,locRef,locGroupRef;

	locIdx = FindLocation(locationName);
	if(locIdx==-1)	return false;

	if(!IsEntity(&Locations[locIdx]) && fromRealLoadedLocators)	return false;

	if(locatorName=="")	return false;

	if(!fromRealLoadedLocators)
	{
		makearef(reloadRef,Locations[locIdx].reload);
		n = GetAttributesNum(reloadRef);
		for(i=0;i<n;i++)
		{
			locRef = GetAttributeN(reloadRef,i);
			if(locRef.name==locatorName)
			{
				locatorRef = locRef;
				return true;
			}
		}
		return false;
	}

	makearef(reloadRef,Locations[locIdx].locators);
	m = GetAttributesNum(reloadRef);
	for(j=0;j<m;j++)
	{
		locGroupRef = GetAttributeN(reloadRef,j);
		n = GetAttributesNum(locGroupRef);
		for(i=0;i<n;i++)
		{
			locRef = GetAttributeN(locGroupRef,i);
			if(GetAttributeName(locRef)==locatorName)
			{
				locatorRef = locRef;
				return true;
			}
		}
	}
	return false;
}

// проверить попадает ли координата в заданный локатор в текущей локации
bool CheckCurLocator(string group,string locator,float x,float y,float z)
{
	int locIdx = FindLoadedLocation();
	if(locIdx==-1) return false;
	if( !CheckAttribute(&Locations[locIdx],"locators."+group+"."+locator) ) return false;
	aref curloc; makearef(curloc,Locations[locIdx].locators.(group).(locator));
	float xloc = makefloat(curloc.x) - x;
	float yloc = makefloat(curloc.y) - y;
	float zloc = makefloat(curloc.z) - z;
	float rad = makefloat(curloc.radius);
	if( rad*rad > xloc*xloc+yloc*yloc+zloc*zloc ) return true;
	else return false;
}

// заменить один локатор на новый адрес перегрузкии
//---------------------------------------------------
bool ChangeReloadData(string locationName,string locatorName, string toLocationName,string toLocatorName)
{
	aref locRef;
	if( !FindLocator(locationName,locatorName, &locRef, false) )
	{
		return false;
	}

	if(!CheckAttribute(locRef,"old.go")) locRef.old.go = locRef.go;
	if(!CheckAttribute(locRef,"old.emerge")) locRef.old.emerge = locRef.emerge;

	if(toLocationName=="") toLocationName=locRef.go;
	if(toLocatorName=="") toLocatorName=locRef.emerge;

	locRef.go = toLocationName;
	locRef.emerge = toLocatorName;
	return true;
}

// вернуть локатору старый адрес перегрузки
bool ChangeBackReloadData(string locationName,string locatorName)
{
	aref locRef;
	if( !FindLocator(locationName,locatorName, &locRef, false) ) return false;

	if(CheckAttribute(locRef,"old.go"))	locRef.go = locRef.old.go;
	if(CheckAttribute(locRef,"old.emerge")) locRef.emerge = locRef.old.emerge;

	if(CheckAttribute(locRef,"old"))	DeleteAttribute(locRef,"old");
	return true;
}

// вызвать проверку квеста через заданное число секунд
//------------------------------------------------------
void DoQuestCheckDelay(string questCheckName, float delayInSecond)
{
	bool deleteOldQuest=false;
	ref mc = GetMainCharacter();
	if( CheckAttribute(mc,"quest."+questCheckName) )	deleteOldQuest=true;
	mc.PostEventQuest.questDelay.(questCheckName).delay = delayInSecond;
	mc.PostEventQuest.questDelay.(questCheckName).qname = questCheckName;
	PostEvent("QuestDelayExit",makeint(delayInSecond*1000),"sl",questCheckName,deleteOldQuest);
}

void DoQuestDelayExit()
{
	string stmp = GetEventData();
	bool deleteOldQuest = GetEventData();
	ref mc = GetMainCharacter();
	DeleteAttribute(mc,"PostEventQuest.questDelay."+stmp);
	if(stmp!="")
	{
		if(deleteOldQuest)
		{
			if( CheckAttribute(mc,"quest."+stmp) )
			{
				CompleteQuestName(stmp);
				mc.quest.(stmp).over = "yes";
				QuestsCheck();
				return;
			}
		}
		CompleteQuestName(stmp);
		QuestsCheck();
	}
}

void ExitActAnimation()
{
	aref arch = GetEventData();
	if(!CheckAttribute(arch,"activity.endAnimationQuest")) return;
	ref chref = GetCharacter(sti(arch.index));
	CharacterPlayAction(chref,"");
	string endAniQuestName = chref.activity.endAnimationQuest.Name;
	DeleteAttribute(chref,"activity.endAnimationQuest");
	if(endAniQuestName!="")
	{
		CompleteQuestName(endAniQuestName);
		QuestsCheck();
	}
}

// Временно сохранить все данные о нашем корабле в памяти
//--------------------------------------------------------
bool ShipTempRemove(ref _refCharacter)
{
	if( CheckAttribute(_refCharacter,"TmpShipHolder") ) return false;
	if( !CheckAttribute(_refCharacter,"Ship") ) return false;

	aref dstRef; makearef(dstRef, _refCharacter.TmpShipHolder);
	aref srcRef; makearef(srcRef, _refCharacter.Ship);

	CopyAttributes(dstRef,srcRef);
	return true;
}

// Восстановить данные о нашем старом корабле из памяти
//------------------------------------------------------
bool RestoreTempRemovedShip(ref _refCharacter)
{
	if( !CheckAttribute(_refCharacter,"TmpShipHolder") ) return false;

	aref dstRef; makearef(dstRef, _refCharacter.Ship);
	aref srcRef; makearef(srcRef, _refCharacter.TmpShipHolder);

	DeleteAttribute(_refCharacter,"Ship");
	CopyAttributes(dstRef,srcRef);
	DeleteAttribute(_refCharacter,"TmpShipHolder");
	return true;
}

// Обменять двух персонажей кораблями
//------------------------------------
void ExchangeCharacterShip(ref oneCharacter, ref twoCharacter)
{
	object tmpObj;
	aref oneShip; makearef(oneShip,oneCharacter.Ship);
	aref twoShip; makearef(twoShip,twoCharacter.Ship);

	CopyAttributes(&tmpObj,oneShip);
	CopyAttributes(oneShip,twoShip);
	CopyAttributes(twoShip,&tmpObj);
}

void QuestProcessDialogExit()
{
	aref one_aref = GetEventData();
	aref two_aref = GetEventData();

	DeleteAttribute(one_aref,"act.disableDialog");
	DeleteAttribute(two_aref,"act.disableDialog");
}

// Задать квест, выполняемый после выхода из диалога
//---------------------------------------------------
void AddDialogExitQuest(string questName)
{
	string attrName;
	aref ar;
	ref mc = GetMainCharacter();

	if( CheckAttribute(mc,"DialogExitQuests") )
	{
		makearef(ar,mc.DialogExitQuests);
		attrName = "l" + GetAttributesNum(ar);
	}
	else
	{
		attrName = "l0";
	}
	mc.DialogExitQuests.(attrName) = questName;
}

void QuestDialogExitProcedure()
{
	int i = GetEventData();
	ref otherCh = GetCharacter(i);
	aref ar, lref;
	string attrName;
	ref mc = GetMainCharacter();

	// может быть выполним какую нибудь задачу
	ExecuteAfterDialogTask(otherCh);
	ExecuteAfterDialogTask(mc);

	if( CheckAttribute(mc,"DialogExitQuests") )
	{
		makearef(ar,mc.DialogExitQuests);
		for(i=0; i<GetAttributesNum(ar); i++)
		{
			lref = GetAttributeN(ar,i);
			attrName = GetAttributeValue(lref);
			CompleteQuestName(attrName);
			if( CheckAttribute(mc,"quest."+attrName+".win_condition") )	mc.quest.(attrName).over = "yes";
		}
		DeleteAttribute(mc,"DialogExitQuests");
	}

	QuestsCheck();
}

int idxOldLocation = -1;
string sQuestNameAfterReload = "_";
void DoDeleteFakeLocation()
{
	DelEventHandler(EVENT_LOCATION_LOAD,"DoDeleteFakeLocation");
	if(idxOldLocation!=-1)	DeleteAttribute(&Locations[idxOldLocation],"reload.fake1");
	if(sQuestNameAfterReload!="_")
	{
		ref mc = GetMainCharacter();
		CompleteQuestName(sQuestNameAfterReload);
		if( CheckAttribute(mc,"quest."+sQuestNameAfterReload+".win_condition") )
			mc.quest.(sQuestNameAfterReload).over = "yes";
		QuestsCheck();
		sQuestNameAfterReload = "_";
	}
}

// Перегрузить главного персонажа в другую локацию и по завершению вызвать квест
//-------------------------------------------------------------------------------
bool DoQuestReloadToLocation(string idLocation, string idGroup, string idLocator, string questName)
{
	if(sQuestNameAfterReload!="_") return false;
	sQuestNameAfterReload = questName;
	if(bSeaActive)
	{
		idxOldLocation = -1;
		SetEventHandler(EVENT_LOCATION_LOAD,"DoDeleteFakeLocation",0);
		return DoReloadFromSeaToLocation(idLocation,idGroup,idLocator);
	}
	if(IsEntity(worldMap))
	{
		idxOldLocation = -1;
		SetEventHandler(EVENT_LOCATION_LOAD,"DoDeleteFakeLocation",0);
		return DoReloadFromWorldMapToLocation(idLocation,idGroup,idLocator);
	}
	return DoReloadCharacterToLocation(idLocation,idGroup,idLocator);
}

// Перегрузить главного персонажа в другую локацию
//-------------------------------------------------------------------------------
bool DoReloadCharacterToLocation(string idLocation, string idGroup, string idLocator)
{
	idxOldLocation = FindLoadedLocation();
	if(idxOldLocation==-1)
	{
		idxOldLocation = 0;
		loadedLocation = &Locations[idxOldLocation];
	}
	else
	{
		if(Locations[idxOldLocation].id!=loadedLocation.id)
		{
			trace("WARNING!!! FindLocation is not same loadedLocation");
			if(IsEntity(loadedLocation))
			{	idxOldLocation = FindLocation(loadedLocation.id);
			}
		}
	}
	Locations[idxOldLocation].reload.fake1.name = "fakeReload";
	Locations[idxOldLocation].reload.fake1.go = idLocation;
	Locations[idxOldLocation].reload.fake1.emerge = idLocator;
	ref pchar = GetMainCharacter();
	aref rloc;
	if( FindLocator ( pchar.location, pchar.location.locator, &rloc, true ) )
	{
		Event("Location_CharacterExitFromLocator","aassf", rloc,pchar, pchar.location.group,pchar.location.locator, 1.0);
	}

	SetEventHandler(EVENT_LOCATION_LOAD,"DoDeleteFakeLocation",0);
	return TeleportCharacterFromCurLocationToLocation("fakeReload",idGroup,idLocator);
}

// Перегрузить главного персонажа в другую локацию из карты мира
//-------------------------------------------------------------------------------
bool DoReloadFromWorldMapToLocation(string idLocation, string idGroup, string idLocator)
{
	ref pchar = GetMainCharacter();
	if(FindLocation(idLocation)==-1) return false;
	pchar.tmpWDMtoLand.location = idLocation;
	pchar.tmpWDMtoLand.group = idGroup;
	pchar.tmpWDMtoLand.locator = idLocator;
	QuitFromWorldMap();
	return true;
}
void ReloadFromWMtoL_complete()
{
	ref pchar = GetMainCharacter();
	if( !CheckAttribute(pchar,"tmpWDMtoLand") ) return;
	ChangeCharacterAddressGroup( pchar, pchar.tmpWDMtoLand.location, pchar.tmpWDMtoLand.group, pchar.tmpWDMtoLand.locator );
	LoadLocation(&Locations[FindLocation(pchar.tmpWDMtoLand.location)]);
	DeleteAttribute(pchar,"tmpWDMtoLand");
}

// Перегрузить главного персонажа в другую локацию из моря
//-------------------------------------------------------------------------------
bool DoReloadFromSeaToLocation(string idLocation, string idGroup, string idLocator)
{
	
	if(bSeaActive)	{ DeleteSeaEnvironment(); }
	else {bSkipSeaLogin = true;}

	ref pchar = GetMainCharacter();
	pchar.tmpWDMtoLand.location = idLocation;
	pchar.tmpWDMtoLand.group = idGroup;
	pchar.tmpWDMtoLand.locator = idLocator;

	SetEventHandler("FaderEvent_EndFade", "EndReloadToLocation", 0);
	CreateEntity(&reload_fader, "fader");
	if(IsEntity(&reload_fader) == 0) Trace("Reload fader not created!!!");
	float fadeOutTime = 0.5;
	SendMessage(&reload_fader, "lfl", FADER_OUT, fadeOutTime, true);
	SendMessage(&reload_fader, "l", FADER_STARTFRAME);
	return true;
}
void EndReloadToLocation()
{
	DelEventHandler("FaderEvent_EndFade", "EndReloadToLocation");
	ReloadFromWMtoL_complete();
}

// Удалить квест из списка проверяемых квестов
//---------------------------------------------
void DeleteQuestCheck(string sQuestName)
{
	ref mc = GetMainCharacter();
	if(sQuestName=="") return;
	if( CheckAttribute(mc,"quest."+sQuestName+".win_condition") )	mc.quest.(sQuestName).over = "yes";
}

// Получить полное имя персонажа
//----------------------------------
string GetCharacterFullName(string idCharacter)
{
	int idxCh = GetCharacterIndex(idCharacter);
	if(idxCh==-1) return "";
	ref chref = GetCharacter(idxCh);
	string retStr = "";
	if(CheckAttribute(chref,"name")) retStr = chref.name;
	if(CheckAttribute(chref,"middlename")) retStr = retStr + " " + chref.middlename;
	if(CheckAttribute(chref,"lastname")) retStr = retStr + " " + chref.lastname;
	return retStr;
}

// Сохранить состояние о пассажирах во временной переменной и временно удалить их всех
//-------------------------------------------------------------------------------------
bool StorePassengers(string idCharacter)
{
	int idxCh = GetCharacterIndex(idCharacter);
	if(idxCh==-1) return false;
	ref refCh = GetCharacter(idxCh);
	if(CheckAttribute(refCh,"Fellows.Old")) return false;

	string sTmp;
	aref arTmp;
	int i,idx;
	// сохраним офицеров
	makearef(arTmp,refCh.Fellows.Old.Officers);
	for(i=1; i<4; i++)
	{
		idx = GetOfficersIndex(refCh,i);
		if(idx==-1) continue;
		sTmp = "id"+i;
		arTmp.(sTmp) = idx;
	}
	// сохраним пассажиров
	makearef(arTmp,refCh.Fellows.Old.Passengers);
	for(i=0; GetPassengersQuantity(refCh)>0; i++)
	{
		idx = GetPassenger(refCh,0);
		if(idx==-1) break;
		sTmp = "id"+i;
		arTmp.(sTmp) = idx;
		RemovePassenger(refCh,GetCharacter(idx));
		ChangeCharacterAddress(GetCharacter(idx),"none","");
	}
	return true;
}

// Восстановить запомненных ранее пассажиров и по возможности офицеров
//----------------------------------------------------------------------
bool RestorePassengers(string idCharacter)
{
	int idxCh = GetCharacterIndex(idCharacter);
	if(idxCh==-1) return false;
	ref refCh = GetCharacter(idxCh);
	if(!CheckAttribute(refCh,"Fellows.Old")) return false;

	int i,idx;
	aref arTmp,arCur;
	// Восстановление пассажиров
	makearef(arTmp,refCh.Fellows.Old.Passengers);
	for(i=0; i<GetAttributesNum(arTmp); i++)
	{
		arCur = GetAttributeN(arTmp,i);
		idx = sti(GetAttributeValue(arCur));
		AddPassenger(refCh,GetCharacter(idx),false);
	}
	// Восстановление офицеров
	makearef(arTmp,refCh.Fellows.Old.Officers);
	for(i=0; i<GetAttributesNum(arTmp); i++)
	{
		arCur = GetAttributeN(arTmp,i);
		idx = sti(GetAttributeValue(arCur));
		if(idx==-1) continue;
		SetOfficersIndex(refCh,-1,idx);
	}

	// удаление временного хранилища пассажиров
	DeleteAttribute(refCh,"Fellows.Old");
	return true;
}

// Смотрим на какого нибудь персонажа
//--------------------------------------
bool StartLookAfterCharacter(string idCharacter)
{
	int chIdx = GetCharacterIndex(idCharacter);
	if(chIdx==-1) return false;

	CharacterTurnByChr(GetMainCharacter(),GetCharacter(chIdx));
	SetEventHandler("evntLookAfterCharacter","LookAfterCharacterProc",0);
	PostEvent("evntLookAfterCharacter",100,"l",chIdx);
	return true;
}
void LookAfterCharacterProc()
{
	int idxCh = GetEventData();
	CharacterTurnByChr(GetMainCharacter(),GetCharacter(idxCh));
	PostEvent("evntLookAfterCharacter",100,"l",idxCh);
}

// Прекратили смотреть на персонаж
//-----------------------------------
void EndLookAfterCharacter()
{
	DelEventHandler("evntLookAfterCharacter","LookAfterCharacterProc");
}

// восстановить персонаж (на случай, если он был до этого убит)
bool ReanimateCharacter(string characterID)
{
	int idx = GetCharacterIndex(characterID);
	if(idx==-1)
	{
		trace("Not found character for function : ReanimateCharacter(" + characterID + ")");
		return false;
	}
	ref chref = GetCharacter(idx);
	LAi_SetCurHP(chref,LAi_GetCharacterMaxHP(chref));
	return true;
}

//extern void SetRandomNameToCharacter(ref chref);
// установить случайное имя для персонажа
bool SetCharacterRandomName(string characterID)
{
	int idx = GetCharacterIndex(characterID);
	if(idx==-1)
	{
		trace("Warning!!! Missing character id = " + characterID);
		return false;
	}
	SetRandomNameToCharacter(GetCharacter(idx));
	return true;
}


// обработка события об уничтожении форта
void QuestFortDestroyed()
{
	int idx = GetEventData();
	if(idx==-1) return;
	ref chref = GetCharacter(idx);
	chref.FortDestroy = "1";
	QuestsCheck();
}

void QuestGroupDeath()
{
	aref chref = GetEventData();
	if( !CheckAttribute(chref,"act.team") ) return;
	ref mc = GetMainCharacter();
	string groupName = chref.act.team;
	mc.GroupDeath.(groupName) = "1";
}

// подготовиться к выгрузке в море по квесту
object questToSeaLoginer;
void QuestToSeaLogin_PrepareLoc(string islandID, string locGroup, string locName, bool sailUP)
{
	questToSeaLoginer.PlayerGroup.x = 0.0;
	questToSeaLoginer.PlayerGroup.ay = 0.0;
	questToSeaLoginer.PlayerGroup.z = 0.0;
	questToSeaLoginer.Island = islandID;
	if(!sailUP)	questToSeaLoginer.FromCoast = true;

	int		iIsland = FindIsland(islandID);
	if (iIsland >= 0)
	{
		if(locGroup=="") {locGroup="reload";}
		aref	arGroup, arLocator;
		ref		rIsland = GetIslandByIndex(iIsland);
		makearef(arGroup, rIsland.(locGroup));

		int		iGroupSize = GetAttributesNum(arGroup);
		for (int i=0; i<iGroupSize; i++)
		{
			arLocator = GetAttributeN(arGroup, i);
			if (GetAttributeName(arLocator) == locName)	break;
		}

		if(i<iGroupSize)
		{
			if(CheckAttribute(arLocator,"x"))	{questToSeaLoginer.PlayerGroup.x = arLocator.x;}
			if(CheckAttribute(arLocator,"z"))	{questToSeaLoginer.PlayerGroup.z = arLocator.z;}
			if(CheckAttribute(arLocator,"ay"))	{questToSeaLoginer.PlayerGroup.ay = arLocator.ay;}
		}
	}
}

void QuestToSeaLogin_Prepare(float x, float z, string islandID)
{
	DeleteAttribute(&questToSeaLoginer,"");
	questToSeaLoginer.PlayerGroup.x = x;
	questToSeaLoginer.PlayerGroup.ay = 0.0;
	questToSeaLoginer.PlayerGroup.z = z;
	questToSeaLoginer.Island = islandID;
}
// подготовить персонажа для выгрузки в море по квесту
void QuestToSeaLogin_Add(string groupName)
{
	aref arql,ar;
	makearef(arql,questToSeaLoginer.QuestGroups);
	for(int i=0; i<GetAttributesNum(arql); i++)
	{
		if( GetAttributeValue(GetAttributeN(arql,i))==groupName ) break;
	}
	if(i==GetAttributesNum(arql))
	{
		string newAttrName;
		for(i=0; i<=1000; i++)
		{
			newAttrName = "l"+i;
			if(!CheckAttribute(arql,newAttrName))
			{
				arql.(newAttrName) = groupName;
				break;
			}
		}
	}
}
// запустить квестовую выгрузку в море
void QuestToSeaLogin_Launch()
{
	SetEventHandler("FaderEvent_EndFade", "QuestToSeaLoginFade", 0);
	object fader;
	CreateEntity(&fader, "fader");
	SendMessage(&fader, "ls",FADER_PICTURE,"loading\sea.tga");
	SendMessage(&fader, "lfl", FADER_OUT, 1.0, true);
	int idxLoadLoc = FindLoadedLocation();
	if( idxLoadLoc!=-1 )
	{
		UnloadLocation(&Locations[idxLoadLoc]);
	}
}
void QuestToSeaLoginFade()
{
	DelEventHandler("FaderEvent_EndFade", "QuestToSeaLoginFade");
	SeaLogin(&questToSeaLoginer);
}

// Получить следующего персонажа одной группы
int	GetCharacterFromFantom(ref chref)
{
	/*int tmpi = FindLoadedLocation();
	if(tmpi==-1) return -1;
	string locID = Locations[tmpi].id;
	int retVal = -1;
	ref fantRef;
	int startVal = sti(chref.index)+1;
	if ( startVal < FANTOM_CHARACTERS ) startVal = FANTOM_CHARACTERS;
	for(int i=startVal; i<BOARDING_CHARACTERS; i++)
	{
		fantRef = GetCharacter(i);
		if(fantRef.location!=locID) continue;
		if(CharacterIsDead(fantRef)) continue;
		if ( CheckAttribute(fantRef,"act.team") && fantRef.act.team==chref.act.team )
		{
			retVal = sti(fantRef.index);
			break;
		}
	}
	return retVal;*/
	return -1;
}

// убрать из локации всех персов указанного типа
void RemoveCharactersFromLocation(string idLocation, string modelName, string type)
{
	for(int i=0; i<MAX_CHARACTERS; i++)
	{
		if( Characters[i].location!=idLocation ) continue;
		if( modelName!="" && modelName!=Characters[i].model ) continue;
		if( type!="" && type!=Characters[i].act.type ) continue;
		ChangeCharacterAddress(&Characters[i], "none", "");
	}
}

void CompleteQuestName(string sQuestName)
{
	if( CheckAttribute(&objQuestScene,"list."+sQuestName+".chrIdx") )
	{
		Event("qprocTaskEnd","a",GetCharacter(sti(objQuestScene.list.(sQuestName).chrIdx)));
	}
	else
	{
		QuestComplete(sQuestName);
		BothQuestComplete(sQuestName);
	}
}

void procEvntQuestComplete()
{
	string qname = GetEventData();
	ref mch = GetMainCharacter();

	if( CheckAttribute(mch,"quest."+qname) )
	{
		if( CheckAttribute(mch,"quest."+qname+".win_condition") )
		{
			CompleteQuestName(mch.quest.(qname).win_condition);
			QuestsCheck();
		}
		else
		{
			trace("WARNING! Not win condition for quest " + qname);
		}
	}
	else
	{
		trace("WARNING! Not found quest name: " + qname);
	}
}

///////////////////////////////////
///  Это старая фигня - за использование буду бить морду... сильно
///////////////////////////////////

// Проиграть анимацию и по ее завершению вызвать квест
//------------------------------------------------------------
void ActAnimation(ref chref, string action, string questName)
{
//	chref.activity.endAnimationQuest.Name = questName;
//	actAction(chref, action, "ExitActAnimation");
}

// Всем воюющим персам убрать оружие, солдатам вернуться на свои позиции.
void BreakAllAttack()
{
//	actAllarm = 0.0;
//	int idxCurLoc = FindLoadedLocation();
//	if(idxCurLoc==-1) return;
//	string curLocName = Locations[idxCurLoc].id;
//
//	for(int n=0; n<MAX_CHARACTERS; n++)
//	{
//		if(Characters[n].location == curLocName)
//		{
//			actReset(&Characters[n]);
//			if( Characters[n].act.type == "soldier" ) SetCharacterTask_GotoPoint(&Characters[n],Characters[n].location.group,Characters[n].location.locator);
//		}
//	}
}


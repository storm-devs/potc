

#include "characters\characters_reload_check.c"


string lockedReloadLocator;

string chrWaitReloadLocator;
aref chrWaitReloadRef;
aref chrWaitLocationRef;
bool chrWaitReloadIsNoLink = false;

void InitCharacterEvents()
{
	SetEventHandler("Location_CharacterEntryToLocator", "chrCharacterEntryToLocator", 0);
	SetEventHandler("Location_CharacterInLocator", "chrCharacterInLocator", 0);
	SetEventHandler("Location_CharacterExitFromLocator", "chrCharacterExitFromLocator", 0);


	lockedReloadLocator = "";
	chrWaitReloadLocator = "";
	
	chrWaitReloadIsNoLink = false;
}

bool AddCharacterLocatorGroup(aref chr, string group)
{
	bool res;
	res = SendMessage(chr, "ls", MSG_CHARACTER_ADD_DETECTOR, group);
	return res;
}

bool DelCharacterLocatorGroup(aref chr, string group)
{
	bool res;
	res = SendMessage(chr, "ls", MSG_CHARACTER_DEL_DETECTOR, group);
	return res;
}


void chrCharacterEntryToLocator()
{
	aref loc = GetEventData();	
	aref chr = GetEventData();
	string group = GetEventData();
	string locator = GetEventData();
	aref tmp;
	string locAttr;
	float x, y, z;
	ref mc = GetMainCharacter();
	int result;

	switch(group)
	{
	case "reload":
		chrWaitReloadIsNoLink = false;
		if(sti(chr.index) != GetMainCharacterIndex()){ break; }
		chrWaitReloadLocator = locator;
		chrWaitLocationRef = loc;
		makearef(chrWaitReloadRef, loc.reload);
		result = chrCheckReloadLink(loc, locator);
		if(result != 1)
		{
			chrWaitReloadIsNoLink = true;
			if(result == 0) Log_SetActiveAction("Closed");
			break;
		}
		if(chrCheckAutoReload(loc, locator) == true)
		{
			if(chrIsNowEnableReload() != true)
			{
				lockedReloadLocator = "";
				Log_SetActiveAction("Closed");
				break;
			}
			Reload(chrWaitReloadRef, chrWaitReloadLocator, mc.location);
			chrWaitReloadLocator = "";
			chrWaitReloadIsNoLink = false;
		}else{
			lockedReloadLocator = "";
			if(chrIsNowEnableReload() != true)
			{
				Log_SetActiveAction("Closed");
			}else{
				Log_SetActiveAction("Reload");
			}
		}
		break;
	case "camdetector":
		locAttr = "locators.camera." + locator;
		if(CheckAttribute(loc, locAttr) != 0)
		{
			x = MakeFloat(loc.(locAttr).x);
			y = MakeFloat(loc.(locAttr).y);
			z = MakeFloat(loc.(locAttr).z);
			locCameraToPos(x, y, z, false);
		}
		break;
	case "item":
		Item_OnEnterLocator(loc, locator);
		break;
	case "randitem":
		RandItem_OnEnterLocator(loc, locator);
		break;
	case "box":	
		Box_EnterToLocator(loc, locator);	
		break;
	}
	
	if( CheckAttribute(chr,"Quests.LocatorCheck." + group) )
	{
		chr.Quests.LocatorCheck.(group) = locator;
		QuestsCheck();
	}
}

void chrCharacterInLocator()
{
	return;

	aref loc = GetEventData();	
	aref chr = GetEventData();
	string group = GetEventData();
	string locator = GetEventData();
	float timeInLocator = GetEventData();

}

void chrCharacterExitFromLocator()
{
	aref loc = GetEventData();
	aref chr = GetEventData();
	string group = GetEventData();
	string locator = GetEventData();
	float timeInLocator = GetEventData();

	switch(group)
	{
	case "reload":
		Log_SetActiveAction("Nothing");
		chrWaitReloadLocator = "";
		chrWaitReloadIsNoLink = false;
		if(locator == lockedReloadLocator)
		{
			lockedReloadLocator = "";
			return;
		}
		break;
	case "camdetector":
		locCameraFollow();
		break;
	case "item":
		Item_OnExitLocator(loc, locator);
		break;
	case "randitem":
		Item_OnExitLocator(loc, locator);
		break;
	case "box":
		Box_ExitFromLocator(loc, locator);
		break;
	}

	if( CheckAttribute(chr,"Quests.LocatorCheck." + group) )
	{
		chr.Quests.LocatorCheck.(group) = "";
	}
}

void chrCharacterKeys()
{
	string controlName = GetEventData();
	if(controlName != "ChrAction") return;
	//Skip if interface active
	if(sti(InterfaceStates.Launched)==true) return;
	//Skip is disable reload
	bool noReload = false;
	if(chrIsNowEnableReload() != true) noReload = true;
	//Skip free links
	if(chrWaitReloadIsNoLink != false) noReload = true;
	if(chrWaitReloadLocator == "") noReload = true;
	if(noReload)
	{
		if(chrWaitReloadLocator != "")
		{
			PlayStereoSound("knock");
		}
		return;
	}
	//trace(" &&&&&&&&&&&&&&&&&&&&&&&&&&& ");
	//Remove icon
	Log_SetActiveAction("Nothing");
	//Start reload
	ref mc = GetMainCharacter();
	Reload(chrWaitReloadRef, chrWaitReloadLocator, mc.location);
	chrWaitReloadLocator = "";
	chrWaitReloadIsNoLink = false;
}

bool chrIsNowEnableReload()
{
	//Skip if not set reload locator
	if(chrWaitReloadLocator == "") return false;
	//Skip if active dialog
	if(DialogRun != 0) return false;
	//Skip
	if(chrCheckReload(chrWaitLocationRef, chrWaitReloadLocator) == 0) return false;
	//Skip if disabled in quest movie
	if(chrIsEnableReload() != true) return false;	
	return true;
}


#event_handler("EventStartQuestMovie","chrChangeReloadStateHndl");
#event_handler("EndStartQuestMovie","chrChangeReloadStateHndl");
#event_handler(EVENT_DIALOG_START,"chrChangeReloadStateHndl");
#event_handler(EVENT_DIALOG_EXIT,"chrChangeReloadStateHndl");
#event_handler("EnableReloadLocatorEvent","chrChangeReloadStateHndl");
#event_handler("chrCheckChangeOpenStateEvent","chrCheckChangeOpenState");

void chrChangeReloadStateHndl()
{
	PostEvent("chrCheckChangeOpenStateEvent", 1);
}

void chrCheckChangeOpenState()
{
	if(chrWaitReloadLocator == "") return;
	if(chrIsNowEnableReload() != true)
	{
		Log_SetActiveAction("Closed");
	}else{
		Log_SetActiveAction("Reload");
	}
}

bool chrIsEnableReload()
{
	if(DialogRun != 0) return false;
	if(qmIsNoReload() != false) return false;
	return true;
}

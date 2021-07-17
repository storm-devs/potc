int g_LocLngFileID = -1;

object objLandInterface;
object objFastReloadTable;
object objTownStateTable;
int g_intRetVal;

bool bDisableFastReload = false;

#define	BLI_UPDATE_PERIOD	500
#event_handler("evntBattleCommandSound","procBattleCommandSound");

bool bLandInterfaceStart = false;

void procBattleCommandSound()
{
	string comName = GetEventData();
	if(comName=="deactivate")
	{
		PlaySound("interface\ok.wav");
	}
	if(comName=="activate")
	{
		PlaySound("interface\ok.wav");
	}
	if(comName=="right" || comName=="left")
	{
		PlaySound("interface\ok.wav");
	}
}

void InitBattleLandInterface()
{
	bLandInterfaceStart = false;
	SetEventHandler(EVENT_LOCATION_LOAD,"StartBattleLandInterface",0);
	SetEventHandler(EVENT_LOCATION_UNLOAD,"EndBattleLandInterface",0);
	LoadLIStates();
}

void BLI_EnableShow()
{
	SetLandInterfaceShow(sti(InterfaceStates.BattleShow.Command));
}

void BLI_DisableShow()
{
	SetLandInterfaceShow(false);
}

void StartBattleLandInterface()
{
	if(bLandInterfaceStart)
	{
		BLI_SetObjectData();
		return;
	}
	bLandInterfaceStart = true;

	BLI_SetShowParameters();
	CreateEntity(&objLandInterface,"battle_land_interface");
	DeleteAttribute(&objLandInterface,"");
	LayerAddObject(EXECUTE, &objLandInterface,-1);
	LayerAddObject(REALIZE, &objLandInterface,-1);

	SetEventHandler(EVENT_CHANGE_OFFICERS,"BLI_UpdateOfficers",0);
	SetEventHandler(EVENT_DIALOG_START,"BLI_DisableShow",0);
	SetEventHandler(EVENT_DIALOG_EXIT,"BLI_EnableShow",0);

	BLI_SetObjectData();

	if(dialogRun) BLI_DisableShow();
	else BLI_EnableShow();

	SetEventHandler("evntBLI_Update","BLI_UpdateObjectData",0);
	SetEventHandler("BI_CommandEndChecking","BLI_CheckCommand",0);
	SetEventHandler("BI_LaunchCommand","BLI_ExecuteCommand",0);
	SetEventHandler("BI_SetPossibleCommands","BLI_SetPossibleCommands",0);
	SetEventHandler("evntFindDialogChar","procFindDialogChar",0);
	SetEventHandler("Location_CharacterEntryToLocator", "BLI_ChrEnterToLocation", 0);
	SetEventHandler("Location_CharacterExitFromLocator", "BLI_ChrExitFromLocation", 0);
	SetEventHandler("evntPerkAgainUsable","BLI_RefreshCommandMenu",0);

	Event("evntBLI_Update");
	Event("evntFindDialogChar");
}

ref BLI_CheckCommand()
{
	string commandName = GetEventData();

	aref uiref;	makearef(uiref,objLandInterface.UserIcons);
	aref ar;
	int nq = GetAttributesNum(uiref);
	int i;

	bool bUsed = false;
	for(i=0; i<nq; i++)
	{
		ar = GetAttributeN(uiref,i);
		ar.enable = false;
	}
	g_intRetVal = BI_COMMODE_USER_ICONS;

	switch(commandName)
	{
	case "cancel":
		g_intRetVal = 0;
	break;

	case "BI_FastReload":
		bUsed = SetReloadIcons();
	break;

	case "BI_ItemsUse":
		bUsed = SetUsedPotionIcons();
	break;

	case "BI_DialogStart":
		g_intRetVal = 0;
	break;

	case "BI_ItemsChange":
		g_intRetVal = 0;
	break;

	case "BI_TakeItem":
		g_intRetVal = 0;
	break;

	case "BI_PlaceItem":
		g_intRetVal = 0;
	break;

	case "BI_OutDoor":
		g_intRetVal = 0;
	break;

	case "BI_UseBox":
		g_intRetVal = 0;
	break;

	case "BI_ActivateRush":
		g_intRetVal = 0;
	break;
	}

	if(!bUsed)	objLandInterface.UserIcons.cancel.enable = true;
	return &g_intRetVal;
}

void BLI_ExecuteCommand()
{
	int		chrIdx = GetEventData();
	string	commName = GetEventData();
	int		targChrIdx = GetEventData();
	string	evntName = GetEventData();

	aref	uiref;
	int		curLocIdx;
	int		tmpi;

	if( commName=="cancel" || evntName=="cancel" ) return;

	switch(commName)
	{
	case "BI_FastReload":
		{
			curLocIdx = FindLoadedLocation();
			if(curLocIdx==-1) return;
			if( FindUserIcon(evntName,&uiref) )
			{
				if(CheckAttribute(uiref,"location"))
				{
					PlayerFastTravel(curLocIdx, uiref.location);
				}
			}
		}
	break;
	case "BI_ItemsUse":
		if( FindUserIcon(evntName,&uiref) )
		{
			if(CheckAttribute(uiref,"potion"))
			{
				aref arItm;
				if( Items_FindItem(uiref.potion,&arItm) >= 0 )
				{
					if( CheckAttribute(arItm,"potion") )
					{
						DoCharacterUsedItem(GetMainCharacter(),arItm.id);
					}
				}
			}
		}
	break;
	case "BI_DialogStart":
		tmpi = SendMessage(GetMainCharacter(),"ls",MSG_CHARACTER_EX_MSG,"FindDialogCharacter");
		if(tmpi>=0)	Event("dlgReady","l",tmpi);
	break;
	case "BI_ItemsChange":
		tmpi = SendMessage(GetMainCharacter(),"ls",MSG_CHARACTER_EX_MSG,"FindDialogCharacter");
		if(tmpi>=0)	LaunchCharacterItemChange(GetCharacter(tmpi));
	break;
	case "BI_TakeItem":
		Item_OnPickItem();
	break;
	case "BI_PlaceItem":
		Item_OnUseItem();
	break;
	case "BI_OutDoor":
		Event("Control Activation","s","ChrAction");
	break;
	case "BI_UseBox":
		OpenBoxProcedure();
	break;
	case "BI_ActivateRush":
		ActivateCharacterPerk(GetMainCharacter(),"Rush");
	break;
	}

}

void EndBattleLandInterface()
{
	if(!bLandInterfaceStart) return;
	bLandInterfaceStart = false;

	DeleteAttribute( GetMainCharacter(), "boxname" );

	BLI_DisableShow();
	SendMessage(&objLandInterface,"l",MSG_BATTLE_LAND_END);

	DeleteClass(&objLandInterface);

	DelEventHandler(EVENT_CHANGE_OFFICERS,"BLI_UpdateOfficers");
	DelEventHandler(EVENT_DIALOG_START,"BLI_DisableShow");
	DelEventHandler(EVENT_DIALOG_EXIT,"BLI_EnableShow");

	DelEventHandler("evntBLI_Update","BLI_UpdateObjectData");
	DelEventHandler("BI_CommandEndChecking","BLI_CheckCommand");
	DelEventHandler("BI_LaunchCommand","BLI_ExecuteCommand");
	DelEventHandler("BI_SetPossibleCommands","BLI_SetPossibleCommands");
	DelEventHandler("evntFindDialogChar","procFindDialogChar");
	DelEventHandler("Location_CharacterEntryToLocator", "BLI_ChrEnterToLocation");
	DelEventHandler("Location_CharacterExitFromLocator", "BLI_ChrExitFromLocation");
	DelEventHandler("evntPerkAgainUsable","BLI_RefreshCommandMenu");

	Log_SetActiveAction("Nothing");
}

void BLI_SetObjectData()
{
	DeleteAttribute(&objLandInterface,"");
	objLandInterface.data.riskAlarm = 0;
	// индикатор тревоги
	objLandInterface.data.alarm = 0.0;
	// персы вместе с нами
	ref mainCh = GetMainCharacter();
	aref ar;
	int i,cn;
	ref curCh;
	string attrName;
	for(i=0; i<4; i++)
	{
		cn = GetOfficersIndex(mainCh,i);
		if(cn==-1) continue;
		curCh = GetCharacter(cn);
		attrName = "id"+i;
		makearef(ar,objLandInterface.data.icons.(attrName));
		ar.picture = curCh.FaceId;
		ar.health = 0.0;
		ar.charge = 0.0;
	}
	BLI_SetCommandParameters();
	BLI_SetMassageParameters();
	// текстуры
	int idLngFile = LanguageOpenFile("commands_name.txt");
	objLandInterface.CommandTextures.list.t0.name = "battle_interface\LandCommands.tga";
	objLandInterface.CommandTextures.list.t0.xsize = 2;
	objLandInterface.CommandTextures.list.t0.ysize = 4;
	objLandInterface.CommandTextures.list.t1.name = "battle_interface\LandTarget4.tga";
	objLandInterface.CommandTextures.list.t1.xsize = 4;
	objLandInterface.CommandTextures.list.t1.ysize = 1;
	objLandInterface.CommandTextures.list.t2.name = "battle_interface\LandTarget1.tga";
	objLandInterface.CommandTextures.list.t2.xsize = 1;
	objLandInterface.CommandTextures.list.t2.ysize = 1;
	objLandInterface.CommandTextures.list.t3.name = "battle_interface\Cancel.tga";
	objLandInterface.CommandTextures.list.t3.xsize = 1;
	objLandInterface.CommandTextures.list.t3.ysize = 1;
	objLandInterface.CommandTextures.list.t4.name = "battle_interface\UsedItems1.tga";
	objLandInterface.CommandTextures.list.t4.xsize = 2;
	objLandInterface.CommandTextures.list.t4.ysize = 2;
	objLandInterface.CommandTextures.list.t5.name = "battle_interface\UsedItems2.tga";
	objLandInterface.CommandTextures.list.t5.xsize = 1;
	objLandInterface.CommandTextures.list.t5.ysize = 2;
	objLandInterface.CommandTextures.CommandTexNum = 0;
	//
	DeleteAttribute(&objIconsNote,"");
	objIconsNote.1x0 = LanguageConvertString(idLngFile, "go_store");
	objIconsNote.1x1 = LanguageConvertString(idLngFile, "go_shipyard");
	objIconsNote.1x2 = LanguageConvertString(idLngFile, "go_tavern");
	objIconsNote.1x3 = LanguageConvertString(idLngFile, "go_residence");
	objIconsNote.2x0 = LanguageConvertString(idLngFile, "go_port");
	// список команд
	objLandInterface.Commands.Cancel.enable		= false;
	objLandInterface.Commands.Cancel.picNum		= 0;
	objLandInterface.Commands.Cancel.texNum		= 3;
	objLandInterface.Commands.Cancel.event		= "Cancel";
	objLandInterface.Commands.FastReload.enable		= true;
	objLandInterface.Commands.FastReload.picNum		= 3;
	objLandInterface.Commands.FastReload.event		= "BI_FastReload";
	objLandInterface.Commands.FastReload.note		= LanguageConvertString(idLngFile, "land_FastReload");
	objLandInterface.Commands.ItemsUse.enable		= true;
	objLandInterface.Commands.ItemsUse.picNum		= 0;
	objLandInterface.Commands.ItemsUse.event		= "BI_ItemsUse";
	objLandInterface.Commands.ItemsUse.note			= LanguageConvertString(idLngFile, "land_ItemsUse");
	objLandInterface.Commands.DialogStart.enable	= true;
	objLandInterface.Commands.DialogStart.picNum	= 4;
	objLandInterface.Commands.DialogStart.event		= "BI_DialogStart";
	objLandInterface.Commands.DialogStart.note		= LanguageConvertString(idLngFile, "land_DialogStart");
	objLandInterface.Commands.ItemsChange.enable	= true;
	objLandInterface.Commands.ItemsChange.picNum	= 1;
	objLandInterface.Commands.ItemsChange.event		= "BI_ItemsChange";
	objLandInterface.Commands.ItemsChange.note		= LanguageConvertString(idLngFile, "land_ItemsChange");
	objLandInterface.Commands.TakeItem.enable		= true;
	objLandInterface.Commands.TakeItem.picNum		= 5;
	objLandInterface.Commands.TakeItem.event		= "BI_TakeItem";
	objLandInterface.Commands.TakeItem.note			= LanguageConvertString(idLngFile, "land_TakeItem");
	objLandInterface.Commands.PlaceItem.enable		= true;
	objLandInterface.Commands.PlaceItem.picNum		= 5;
	objLandInterface.Commands.PlaceItem.event		= "BI_PlaceItem";
	objLandInterface.Commands.PlaceItem.note		= LanguageConvertString(idLngFile, "land_PlaceItem");
	objLandInterface.Commands.OutDoor.enable		= true;
	objLandInterface.Commands.OutDoor.picNum		= 2;
	objLandInterface.Commands.OutDoor.event			= "BI_OutDoor";
	objLandInterface.Commands.OutDoor.note			= LanguageConvertString(idLngFile, "land_OutDoor");
	objLandInterface.Commands.UseBox.enable			= true;
	objLandInterface.Commands.UseBox.picNum			= 1;
	objLandInterface.Commands.UseBox.event			= "BI_UseBox";
	objLandInterface.Commands.UseBox.note			= LanguageConvertString(idLngFile, "land_UseBox");
	objLandInterface.Commands.ActivateRush.enable	= true;
	objLandInterface.Commands.ActivateRush.picNum	= 6;
	objLandInterface.Commands.ActivateRush.event	= "BI_ActivateRush";
	objLandInterface.Commands.ActivateRush.note		= LanguageConvertString(idLngFile, "land_ActivateRush");
	// список пользовательских картинок
		// cancel icon
	objLandInterface.UserIcons.cancel.enable = true;
	objLandInterface.UserIcons.cancel.pic = 0;
	objLandInterface.UserIcons.cancel.tex = 3;
	objLandInterface.UserIcons.cancel.name = "cancel";

	LanguageCloseFile(idLngFile);
		// go to icons
	int idxloc = FindLoadedLocation();
	string outGroupName = "";
	RecalculateHireCrew(idxloc);
	if(idxloc>=0 && CheckAttribute(&Locations[idxloc],"fastreload"))
	{
		outGroupName = Locations[idxloc].fastreload;
		CreateReloadPaths(outGroupName);
	}

	SendMessage(&objLandInterface,"l",MSG_BATTLE_LAND_START);
}

bool FindUserIcon(string id,ref uiref)
{
	aref arroot,ar; makearef(arroot,objLandInterface.UserIcons);
	for(int i=0; i<GetAttributesNum(arroot); i++)
	{
		ar = GetAttributeN(arroot,i);
		if(ar.name != id) continue;
		uiref = ar;
		return true;
	}
	return false;
}

void BLI_SetShowParameters()
{
	aref ar; makearef(ar,objLandInterface.Parameters);

	ar.shadowH = RecalculateVIcon(28);
	ar.shadowW = RecalculateHIcon(20);
	ar.shadowTOP = RecalculateVIcon(18);
	ar.widthCom = RecalculateHIcon(64);
	ar.heightCom = RecalculateVIcon(64);
	ar.leftPosCom = sti(showWindow.left)+RecalculateHIcon(16);
	ar.topPosCom = sti(showWindow.bottom)-RecalculateVIcon(80);
	ar.distCom = RecalculateHIcon(8);

	ar.widthHealth = RecalculateHIcon(64);
	ar.heightHealth = RecalculateVIcon(16);
	ar.distHealth = RecalculateVIcon(4);

	// высота и отступ для количества зарядов пистолета
	ar.GunShootHeight = RecalculateHIcon(16);
	ar.GunShootSpace = RecalculateVIcon(2);

	ar.AlarmColorLight	= argb(255,128,128,128);
	ar.AlarmColorDark	= argb(255,148,38,38);
	ar.PoisonColorLight	= argb(255,128,128,128);
	ar.PoisonColorDark	= argb(255,38,148,38);
	ar.AlarmBlindUpTime		= 0.3;
	ar.AlarmBlindDownTime	= 0.7;

	ar.DoShowCommandos = true;
	ar.CommandosQuantity = 4;

	ar.shadowTexture = "battle_interface\portraits_shadow.tga";

	SetOfficerTexture(0);
	SetOfficerTexture(1);
	SetOfficerTexture(2);
	SetOfficerTexture(3);

	ar.stateTexture = "battle_interface\officerstate.tga";
	ar.gunChargeTexture = "battle_interface\guncharge.tga";

	ar.iconHorzQuantity = 8;
	ar.iconVertQuantity = 4;
	BLI_SetCommandParameters();
	BLI_SetMassageParameters();
}

void BLI_SetCommandParameters()
{
	objLandInterface.CommandShowParam.maxShowQuantity = 5;
	objLandInterface.CommandShowParam.iconDistance = RecalculateHIcon(4);
	objLandInterface.CommandShowParam.iconWidth = RecalculateHIcon(64);
	objLandInterface.CommandShowParam.iconHeight = RecalculateVIcon(64);
	objLandInterface.CommandShowParam.leftIconsOffset = sti(showWindow.left)+RecalculateHIcon(16);
	objLandInterface.CommandShowParam.downIconsOffset = sti(showWindow.bottom)-RecalculateVIcon(80);
	objLandInterface.CommandShowParam.buttonWidth = RecalculateHIcon(8);
	objLandInterface.CommandShowParam.buttonHeight = RecalculateVIcon(64);
	objLandInterface.CommandShowParam.buttonOffset = RecalculateHIcon(4);
	objLandInterface.CommandShowParam.buttonTexture = "battle_interface\lr_buttons.tga";
	objLandInterface.CommandShowParam.shipStateWidth = RecalculateHIcon(64);
	objLandInterface.CommandShowParam.shipStateHeight = RecalculateVIcon(16);
	objLandInterface.CommandShowParam.shipStateTexture = "battle_interface\indicators.tga";
	objLandInterface.CommandShowParam.shipStateOffset = RecalculateVIcon(0);
	objLandInterface.CommandShowParam.commandFont = "bold_numbers";
	objLandInterface.CommandShowParam.printXOffset = RecalculateHIcon(32);
	objLandInterface.CommandShowParam.printYOffset = RecalculateVIcon(-26);
	objLandInterface.CommandShowParam.commandNoteFont = "interface_normal";
	objLandInterface.CommandShowParam.noteXOffset = RecalculateHIcon(0);
	objLandInterface.CommandShowParam.noteYOffset = RecalculateVIcon(-30);
	objLandInterface.CommandShowParam.argbTFactorColor = argb(256,64,64,64);
}

void BLI_SetMassageParameters()
{
	objLandInterface.MessageIcons.IconWidth = RecalculateHIcon(64);
	objLandInterface.MessageIcons.IconHeight = RecalculateVIcon(24);
	objLandInterface.MessageIcons.IconDist = RecalculateVIcon(2);
	objLandInterface.MessageIcons.IconBottom = sti(showWindow.bottom)-RecalculateHIcon(80+40);
	objLandInterface.MessageIcons.IconMaxQuantity = 4;
	objLandInterface.MessageIcons.BlendTime = 3.0;
	objLandInterface.MessageIcons.FallSpeed = 22.0;
	objLandInterface.MessageIcons.argbHighBlind = argb(255,128,128,128);
	objLandInterface.MessageIcons.argbLowBlind = argb(255,68,68,68);
	objLandInterface.MessageIcons.BlindUpTime = 0.5;
	objLandInterface.MessageIcons.BlindDownTime = 1.0;
	objLandInterface.MessageIcons.texture = "battle_interface\MessageIcons.tga";
	objLandInterface.MessageIcons.TexHSize = 2;
	objLandInterface.MessageIcons.TexVSize = 2;
}

void BLI_UpdateObjectData()
{
	objLandInterface.data.alarm = LAi_group_GetPlayerAlarm();
	bool bIsRiskAlarm = LAi_group_IsActivePlayerAlarm();
	if(sti(objLandInterface.data.riskAlarm)!=bIsRiskAlarm) BLI_RefreshCommandMenu();
	objLandInterface.data.riskAlarm = bIsRiskAlarm;
	ref mainCh = GetMainCharacter();
	aref ar,arItm;
	int i,cn;
	ref curCh;
	string attrName;
	for(i=0; i<4; i++)
	{
		attrName = "id"+i;
		cn = GetOfficersIndex(mainCh,i);
		if(cn==-1 || !IsEntity(&Characters[cn]))
		{
			DeleteAttribute(&objLandInterface,"data.icons."+attrName);
			continue;
		}
		curCh = GetCharacter(cn);
		makearef(ar,objLandInterface.data.icons.(attrName));
		ar.picture = curCh.FaceId;
		ar.health = LAi_GetCharacterRelHP(curCh);
		ar.charge = LAi_GetCharacterRelCharge(curCh);
		ar.shootMax = LAi_GetCharacterChargeQuant(curCh);
		ar.shootCur = LAi_GetCharacterChargeCur(curCh);
		ar.poison = LAi_IsPoison(curCh);
	}

	PostEvent("evntBLI_Update",BLI_UPDATE_PERIOD);
}

void SetLandInterfaceShow(bool commandosShow)
{
	SendMessage(&objLandInterface,"ll",MSG_BATTLE_LAND_SET_SHOW,commandosShow);
}

void BLI_SetPossibleCommands()
{
	ref mchref = GetMainCharacter();
	int chrMode = SendMessage(mchref,"ls",MSG_CHARACTER_EX_MSG,"IsFightMode");

	bool bTmpBool;
	bool bUseCommand = false;
	int i;
	aref rootcom,curcom;
	makearef(rootcom,objLandInterface.Commands);
	for(i=0; i<GetAttributesNum(rootcom); i++)
	{
		curcom = GetAttributeN(rootcom,i);
		curcom.enable = false;
	}

	if(chrMode==0)
	{
		bTmpBool = true;
		if(LAi_group_IsActivePlayerAlarm()) bTmpBool = false;
		if(!LAi_IsCharacterControl(mchref)) bTmpBool = false;
		if(bDisableFastReload)	bTmpBool = false;
		if(!IsEnableFastTravel()) bTmpBool = false;
		objLandInterface.Commands.FastReload.enable	= bTmpBool;
		i = -1;
		if(CheckAttribute(mchref,"dialogready")) i=sti(mchref.dialogready);
		if(i>=0)
		{
			objLandInterface.Commands.DialogStart.enable	= true;
			if( IsOfficer(&Characters[i]) )
			{
				objLandInterface.Commands.ItemsChange.enable = true;
			}
			else
			{
				if( CheckAttribute(&Characters[i],"InterfaceFlags.ItemsChange") &&
					Characters[i].InterfaceFlags.ItemsChange != "0" )
				{
					objLandInterface.Commands.ItemsChange.enable = true;
				}
			}
		}
		bUseCommand = true;
	}

	if(GetCharacterPerkUsing(mchref,"Rush"))
	{
		objLandInterface.Commands.ActivateRush.enable = true;
		bUseCommand = true;
	}

	if( CanBeUseItem(mchref) )
	{
		objLandInterface.Commands.ItemsUse.enable = true;
		bUseCommand = true;
	}

	if(CheckAttribute(mchref,"boxname"))
	{
		objLandInterface.Commands.UseBox.enable	= true;
		bUseCommand = true;
	}

	if( CheckAttribute(mchref,"activeItem") && mchref.activeItem!="" )
	{
		bUseCommand = true;
		if( CheckAttribute(mchref,"activeItem.pick") && mchref.activeItem.pick=="1" )
		{
			objLandInterface.Commands.TakeItem.enable = true;
		}
		else
		{
			objLandInterface.Commands.PlaceItem.enable = true;
		}
	}

	if( chrWaitReloadLocator != "" )
	{
		bUseCommand = true;
		objLandInterface.Commands.OutDoor.enable = true;
	}

	if(!bUseCommand)
	{
		SendMessage(&objLandInterface,"llllll",BI_IN_SET_COMMAND_MODE,0,-1,-1,-1,-1);
	}
	//objLandInterface.Commands.OutDoor.enable		= true;
}

void BLI_evntRefreshCommandMenu()
{
	DelEventHandler("frame","BLI_evntRefreshCommandMenu");
	BLI_RefreshCommandMenu();
}
void BLI_RefreshCommandMenu()
{
	SendMessage(&objLandInterface,"lllll",BI_IN_SET_COMMAND_MODE,-1,-1,-1,-1,-1);
}

void procFindDialogChar()
{
	ref mchref = GetMainCharacter();
	int dlgChar = -1;
	if(!LAi_IsBoardingProcess())
		dlgChar = SendMessage(mchref,"ls",MSG_CHARACTER_EX_MSG,"FindDialogCharacter");

	int oldDlgChar = -1;
	if(CheckAttribute(mchref,"dialogready")) oldDlgChar = sti(mchref.dialogready);

	if(dlgChar!=oldDlgChar)
	{
		mchref.dialogready = dlgChar;
		BLI_RefreshCommandMenu();
	}

	PostEvent("evntFindDialogChar",1000);
}

void BLI_ChrEnterToLocation()
{
	aref loc = GetEventData();	
	aref chr = GetEventData();
	string group = GetEventData();
	string locator = GetEventData();
	aref locList,locCur;
	int i,n;

	if(sti(chr.index) != GetMainCharacterIndex()) return;

	if(group=="reload")
	{
		makearef(locList,loc.reload);
		n = GetAttributesNum(locList);
		for(i=0;i<n;i++)
		{
			locCur = GetAttributeN(locList,i);
			if(locCur.name == locator) break;
		}
		if(i<n)
		{
			i = FindLocation(locCur.go);
			if(i>=0)
			{
				if(CheckAttribute(&locations[i],"id.label"))
				{
					Log_SetStringToLog( LanguageConvertString(g_LocLngFileID,locations[i].id.label) );
				}
			}
		}
		SetEventHandler("frame","BLI_evntRefreshCommandMenu",1);
	}
}

void BLI_ChrExitFromLocation()
{
	SetEventHandler("frame","BLI_evntRefreshCommandMenu",1);
}

void LI_Reload()
{
/*	SetEvemt
	chrCharacterKeys
	ref mc = GetMainCharacter();
	Reload(chrWaitReloadRef, chrWaitReloadLocator, mc.location);
	chrWaitReloadLocator = "";
	chrWaitReloadIsNoLink = false;*/
	Event("Control Activation","s","ChrAction");
}

bool SetUsedPotionIcons()
{
	aref arItm, ar, uiref;
	int i, itmIdx, nq;
	ref mc = GetMainCharacter();

	bool bUsed = false;

	makearef(uiref,objLandInterface.UserIcons);
	nq = GetAttributesNum(uiref);
	for(i=0; i<nq; i++)
	{
		ar = GetAttributeN(uiref,i);
		if( CheckAttribute(ar,"potion") ) {
			DeleteAttribute(uiref,GetAttributeName(ar));
			nq--; i--;
		}
	}

	string UI_name;
	int UI_idx = 0;

	itmIdx = FindPotionFromChr(mc, &arItm, 0);
	while(itmIdx>=0)
	{
		if( EnablePotionUsing(mc,arItm) )
		{
			UI_idx++;
			UI_name = "potion"+UI_idx;
			objLandInterface.UserIcons.(UI_name).enable = true;
			objLandInterface.UserIcons.(UI_name).pic = GetPotionPicture(arItm);
			objLandInterface.UserIcons.(UI_name).tex = GetPotionTexture(arItm);
			objLandInterface.UserIcons.(UI_name).name = UI_name;
			objLandInterface.UserIcons.(UI_name).potion = arItm.id;
			bUsed = true;
		}
		itmIdx = FindPotionFromChr(mc, &arItm, itmIdx+1);
	}

	return bUsed;
}

bool SetReloadIcons()
{
	int i, nq, locidx;
	aref ar, curloc, locref, locList, uiref;
	ref mc = GetMainCharacter();

	bool bUse = false;

	makearef(uiref,objLandInterface.UserIcons);
	nq = GetAttributesNum(uiref);
	for(i=0; i<nq; i++)
	{
		ar = GetAttributeN(uiref,i);
		if( CheckAttribute(ar,"location") ) {
			DeleteAttribute(uiref,GetAttributeName(ar));
			nq--; i--;
		}
	}

	int idxloc = FindLoadedLocation();
	string str1,str2,fastLocName;
	string outGroupName = "";
	if(idxloc>=0 && CheckAttribute(&Locations[idxloc],"fastreload"))
	{
		outGroupName = Locations[idxloc].fastreload;
		if( CheckAttribute(&objFastReloadTable,"table."+outGroupName) )
		{
			makearef(locList,objFastReloadTable.table.(outGroupName));
			nq = GetAttributesNum(locList);
			for(i=0; i<nq; i++)
			{
				curloc = GetAttributeN(locList,i);
				if( !CheckFastJump(Locations[idxloc].id, curloc.location) ) {continue;}
				fastLocName = "fr_"+(i+1);
				objLandInterface.UserIcons.(fastLocName).enable = true;
				objLandInterface.UserIcons.(fastLocName).pic = curloc.pic;
				objLandInterface.UserIcons.(fastLocName).tex = 1+sti(curloc.tex);
				objLandInterface.UserIcons.(fastLocName).name = "reload"+i;
				objLandInterface.UserIcons.(fastLocName).location = curloc.location;
				objLandInterface.UserIcons.(fastLocName).note = GetNodeForIcon(1+sti(curloc.tex), sti(curloc.pic));
				bUse = true;
			}
		}
		// to port icon
		if( GetCharacterShipType(mc)!=SHIP_NOTUSED )
		{
			if( CheckFastJump(Locations[idxloc].id, mc.location.from_sea) )
			{
				objLandInterface.UserIcons.port.enable = true;
				objLandInterface.UserIcons.port.pic = 0;
				objLandInterface.UserIcons.port.tex = 2;
				objLandInterface.UserIcons.port.name = "reloadtoport";
				objLandInterface.UserIcons.port.location = mc.location.from_sea;
				objLandInterface.UserIcons.port.note = GetNodeForIcon(2, 0);
				bUse = true;
			}
		}
	}

	return bUse;
}

void SetOfficerTexture(int officerIdx)
{
	aref ar; makearef(ar,objLandInterface.Parameters);
	string attrName = "iconTexture"+officerIdx;

	int cn = GetOfficersIndex(GetMainCharacter(),officerIdx);
	if(cn<0) {
		DeleteAttribute(ar,attrName);
		ar.(attrName) = "";
	} else {
		ar.(attrName) = "interfaces\portraits\64\face_"+Characters[cn].FaceID+".tga";
	}
}

void BLI_UpdateOfficers()
{
	BLI_SetObjectData();

	SetOfficerTexture(0);
	SetOfficerTexture(1);
	SetOfficerTexture(2);
	SetOfficerTexture(3);

	SendMessage(&objLandInterface, "lls", MSG_BATTLE_LAND_SET_ICONTEX, 0, objLandInterface.Parameters.iconTexture0);
	SendMessage(&objLandInterface, "lls", MSG_BATTLE_LAND_SET_ICONTEX, 1, objLandInterface.Parameters.iconTexture1);
	SendMessage(&objLandInterface, "lls", MSG_BATTLE_LAND_SET_ICONTEX, 2, objLandInterface.Parameters.iconTexture2);
	SendMessage(&objLandInterface, "lls", MSG_BATTLE_LAND_SET_ICONTEX, 3, objLandInterface.Parameters.iconTexture3);
}

int GetPotionPicture(aref arItm)
{
	if( CheckAttribute(arItm,"potion.pic") ) {
		return sti(arItm.potion.pic);
	}
	trace("Item "+arItm.id+ " hav`t POTION.PIC attribute");
	return 0;
}

int GetPotionTexture(aref arItm)
{
	if( !CheckAttribute(arItm,"potion.tex") ) {
		trace("Item "+arItm.id+ " hav`t POTION.TEX attribute");
		return 0;
	}
	return 3+sti(arItm.potion.tex);
}

bool CanBeUseItem(ref chref)
{
	for(int i=0; i<ITEMS_QUANTITY; i++)
	{
		if( CheckAttribute(&Items[i],"potion") && CheckAttribute(chref,"items."+Items[i].id) ) {
			if( EnablePotionUsing(chref,&Items[i]) ) {return true;}
		}
	}
	return false;
}

object objIconsNote;
string GetNodeForIcon(int nTex, int nPic)
{
	string attrName = nTex+"x"+nPic;
	if( CheckAttribute(objIconsNote,attrName) ) return objIconsNote.(attrName);
	return "";
}

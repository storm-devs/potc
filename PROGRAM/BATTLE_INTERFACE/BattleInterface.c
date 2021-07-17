#include "battle_interface\msg_control.h"
#include "sea_ai\script_defines.h"
#include "battle_interface\landinterface.c"
#include "battle_interface\ispyglass.c"
#include "battle_interface\reload_tables.c"
#include "battle_interface\utils.c"
#include "battle_interface\ActivePerksShow.c"

#define BI_ICONS_SHIPS_TEXTURE_NAME "battle_interface\icons.tga"

#define BI_ICONS_ST_NONE		0
#define BI_ICONS_ST_MYSHIPS		1
#define BI_ICONS_ST_COMMAND		2
#define BI_ICONS_ST_TARGETING	3

int bi_icons_ShowType;
int bi_icons_CommandMode;

int bi_idxSelectedPicture;

object BattleInterface;

bool bDisableSailTo = false;

bool bDisableMapEnter = false;

bool bReloadCanBe = false;
bool bMapEnter = false;
bool bSailTo=false;
bool bAttack=false;
bool bDefend=false;

bool bEnableIslandSailTo=false;

int BI_intRetValue;
int BI_retComValue;
int BI_ChargeState[5];
float BI_g_fRetVal;

int BI_intNRetValue[4];

object BI_objRetValue;
object objShipPointer;

#event_handler("DoSailHole","ProcessSailDamage");
#event_handler("evntRandomSailDmg","ProcessRandomSailDmg");
#event_handler("NextDay","ProcessDayRepair");
#event_handler("GetSailTextureData","procGetSailTextureData");
#event_handler("GetRiggingData","procGetRiggingData");
#event_handler("EventMastFall","procMastFall");
#event_handler("evntBISelectShip","procBISelectShip");

#event_handler(SHIP_CREATE,"BI_CreateShip");

void InitBattleInterface()
{
	ref chMain = GetMainCharacter();
	BI_InitializeCommands();
	bi_icons_CommandMode = 0;
	BattleInterface.SelCharacter = -1;
	bi_idxSelectedPicture = -1;
	BattleInterface.boardRadius = 50;
	BattleInterface.freeDistance = MIN_ENEMY_DISTANCE_TO_DISABLE_MAP_ENTER;

	SetParameterData();
	BattleInterface.blindSpeed = 0.003;
	BattleInterface.MaxWind = 30.0;
	BattleInterface.MaxShipSpeed = 20.0;
	BattleInterface.ShowNavigator = InterfaceStates.BattleShow.Navigator;
	BattleInterface.ShowCommands = InterfaceStates.BattleShow.Command;
    CreateEntity(&BattleInterface,"battle_interface");
	DeleteAttribute(&BattleInterface,"CommandTextures");
	DeleteAttribute(&BattleInterface,"CommandShowParam");
	LayerAddObject(SEA_EXECUTE,&BattleInterface,-1);
	LayerAddObject(SEA_REALIZE,&BattleInterface,-1);

	SetEventHandler(SHIP_DELETE,"BI_DeleteShip",0);
	SetEventHandler(SHIP_DEAD,"BI_DeadShip",0);

	SetEventHandler("BI_CommandEndChecking","BI_CommandEndChecking",0);
	SetEventHandler("BI_LaunchCommand","BI_LaunchCommand",0);
	SetEventHandler("BI_GetChargeQuantity","BI_GetChargeQuantity",0);
	SetEventHandler("BI_SetPossibleCommands","BI_SetPossibleCommands",0);
	SetEventHandler("GetCurrentCharge","GetCurrentCharge",0);
	SetEventHandler(BI_EVENT_SET_VISIBLE,"BI_CommandVisible",0);
	SetEventHandler(BI_EVENT_SET_SEA_STATE,"BI_SetSeaState",0);
	SetEventHandler(BI_EVENT_GET_DATA,"BI_GetData",0);
	SetEventHandler(BI_EVENT_CHECK_SHIPSTATE_SHOW,"BI_GetSSShow",0);
	SetEventHandler("evntGetLandData","BI_GetLandData",0);
	SetEventHandler(BI_EVENT_GET_FORT_RELATION,"BI_GetFortRelation",0);
	SetEventHandler(EVENT_CHANGE_COMPANIONS,"RefreshBattleInterface",0);
	SetEventHandler("BI_CallUpdateShip","BI_UpdateShip",0);
	SetEventHandler("frame","BI_Frame",1);
	SetEventHandler("evntPerkAgainUsable","BI_PerkAgainUsable",0);
	SetEventHandler("evntSetUsingAbility","procSetUsingAbility",0);
	SetEventHandler("evntCheckEnableLocator","procCheckEnableLocator",0);
	SetEventHandler("evntCheckEnableShip","procCheckEnableShip",0);
	SetEventHandler("evntGetSRollSpeed","procGetSRollSpeed",0);

	procLoadIntoNew(); // Проинитим таблицу активных перков
	SetEventHandler("Control Activation","BI_ProcessControlPress",0);

	CreateILogAndActions(LOG_FOR_SEA);
	Log_SetActiveAction("Nothing");
}

ref BI_GetFortRelation()
{
	BI_intRetValue = BI_RELATION_NEUTRAL;
	aref arLoc = GetEventData();
	int chrIdx = Fort_FindCharacter(AISea.Island,"reload",arLoc.name);
	if(chrIdx>=0)
	{
		switch( SeaAI_GetRelation(chrIdx,GetMainCharacterIndex()) )
		{
		case RELATION_FRIEND:	BI_intRetValue = BI_RELATION_FRIEND;	break;
		case RELATION_NEUTRAL:	BI_intRetValue = BI_RELATION_NEUTRAL;	break;
		case RELATION_ENEMY:	BI_intRetValue = BI_RELATION_ENEMY;		break;
		}
	}
	return &BI_intRetValue;
}

ref BI_GetSSShow()
{
	BI_intRetValue = false;
	int charIdx = GetEventData();
	ref mchref = GetMainCharacter();
	switch( GetCharacterEquipByGroup(GetMainCharacter(), SPYGLASS_ITEM_TYPE) )
	{
	case CHEAP_SPYGLASS:	BI_intRetValue = false;	break;
	case COMMON_SPYGLASS:	BI_intRetValue = true;	break;
	case GOOD_SPYGLASS:		BI_intRetValue = true;	break;
	case SUPERIOR_SPYGLASS:	BI_intRetValue = true;	break;
	}
	return &BI_intRetValue;
}

void BI_CommandVisible()
{
	int visibleFlag = GetEventData();
	SendMessage(&BattleInterface,"ll",BI_SET_VISIBLE,visibleFlag);
}

int bi_nReloadTarget=-1;
bool biold_bCanEnterToLand = false;
bool biold_bAbordageShipCanBe = false;
bool biold_bAbordageFortCanBe = false;
bool biold_bReloadCanBe = false;
bool biold_bMapEnter = false;
bool bOldNotEnoughBalls = false;
void BI_Frame()
{
	bool bYesUpdateCommand = false;
	if(bNotEnoughBalls!=bOldNotEnoughBalls)
	{
		bOldNotEnoughBalls = bNotEnoughBalls;
		if(bNotEnoughBalls)
		{
			SendMessage(&BattleInterface,"ll",BI_MSG_NOT_ENOUGH_BALLS_FLAG,true);
		}
		else
		{
			SendMessage(&BattleInterface,"ll",BI_MSG_NOT_ENOUGH_BALLS_FLAG,false);
		}
	}

	if(biold_bAbordageShipCanBe!=bAbordageShipCanBe)
	{
		bYesUpdateCommand = true;
		biold_bAbordageShipCanBe = bAbordageShipCanBe;
	}
	if(biold_bAbordageFortCanBe!=bAbordageFortCanBe)
	{
		bYesUpdateCommand = true;
		biold_bAbordageFortCanBe = bAbordageFortCanBe;
	}
	if(biold_bCanEnterToLand!=bCanEnterToLand)
	{
		bYesUpdateCommand = true;
		biold_bCanEnterToLand = bCanEnterToLand;
	}
	if(biold_bReloadCanBe!=bReloadCanBe)
	{
		bYesUpdateCommand = true;
		biold_bReloadCanBe = bReloadCanBe;
	}
	if(biold_bMapEnter!=bMapEnter)
	{
		bYesUpdateCommand = true;
		biold_bMapEnter = bMapEnter;
	}

	if(bYesUpdateCommand)
	{
		BI_SetCommandMode(-1,-1,-1,-1);
	}

	if(bAbordageShipCanBe)
	{
		Log_SetActiveAction("Board");
		return;
	}
	if(bAbordageFortCanBe)
	{
		Log_SetActiveAction("LandTroops");
		return;
	}
	if(bReloadCanBe)
	{
		Log_SetActiveAction("Reload");
		return;
	}
	if(bCanEnterToLand)
	{
		Log_SetActiveAction("Moor");
		return;
	}
	if(bMapEnter)
	{
		Log_SetActiveAction("Map");
		return;
	}
	Log_SetActiveAction("Nothing");
}

void StartBattleInterface()
{
	bi_nReloadTarget = -1;
	bi_icons_ShowType = BI_ICONS_ST_MYSHIPS;
	BI_SetCommandMode(BI_COMMODE_MY_SHIP_SELECT,-1,-1,-1);
	BI_SetIslandData();
	InterfaceSpyGlassInit();
	objShipPointer.textures.friend = "battle_interface\Frendly.tga";
	objShipPointer.textures.enemy = "battle_interface\Enemy.tga";
	CreateEntity(&objShipPointer,"shippointer");
	LayerAddObject(SEA_EXECUTE,&objShipPointer,222222);
	LayerAddObject(SEA_REALIZE,&objShipPointer,222222);
}

void RefreshBattleInterface()
{
	BI_SetCommandMode(0,-1,-1,-1);
	SendMessage(&BattleInterface,"l",BI_MSG_REFRESH);
	BI_SetCommandMode(BI_COMMODE_MY_SHIP_SELECT,-1,-1,-1);
}

void DeleteBattleInterface()
{
	Log_SetActiveAction("Nothing");
	InterfaceSpyGlassRelease();

	DelEventHandler(SHIP_DELETE, "BI_DeleteShip");
	DelEventHandler(SHIP_DEAD,"BI_DeadShip");
	DelEventHandler("BI_CommandEndChecking", "BI_CommandEndChecking");
	DelEventHandler("BI_LaunchCommand", "BI_LaunchCommand");
	DelEventHandler("BI_GetChargeQuantity","BI_GetChargeQuantity");
	DelEventHandler("BI_SetPossibleCommands","BI_SetPossibleCommands");
	DelEventHandler("GetCurrentCharge","GetCurrentCharge");
	DelEventHandler(BI_EVENT_SET_VISIBLE,"BI_CommandVisible");
	DelEventHandler(BI_EVENT_SET_SEA_STATE,"BI_SetSeaState");
	DelEventHandler(BI_EVENT_GET_DATA,"BI_GetData");
	DelEventHandler(BI_EVENT_CHECK_SHIPSTATE_SHOW,"BI_GetSSShow");
	DelEventHandler("evntGetLandData","BI_GetLandData");
	DelEventHandler(BI_EVENT_GET_FORT_RELATION,"BI_GetFortRelation");
	DelEventHandler(EVENT_CHANGE_COMPANIONS,"RefreshBattleInterface");
	DelEventHandler("BI_CallUpdateShip","BI_UpdateShip");
	DelEventHandler("frame","BI_Frame");
	DelEventHandler("evntPerkAgainUsable","BI_PerkAgainUsable");
	DelEventHandler("evntSetUsingAbility","procSetUsingAbility");
	DelEventHandler("evntCheckEnableLocator","procCheckEnableLocator");
	DelEventHandler("evntCheckEnableShip","procCheckEnableShip");
	DelEventHandler("evntGetSRollSpeed","procGetSRollSpeed");
	DelEventHandler("Control Activation","BI_ProcessControlPress");

	SetTimeScale(1.0);
	if(IsPerkIntoList("TimeSpeed"))
	{	DelPerkFromActiveList("TimeSpeed");
	}

	DeleteClass(&BattleInterface);
	DeleteClass(&objShipPointer);
}

ref BI_CommandEndChecking()
{
	BI_retComValue = 0;
	string comName = GetEventData();

	switch(comName)
	{
	case "BI_Moor":
		BI_retComValue = 0;
		break;
	case "BI_SailTo":
		if(bEnableIslandSailTo) {
			BI_retComValue = BI_COMMODE_MY_SHIP_SELECT+BI_COMMODE_NEUTRAL_SHIP_SELECT+BI_COMMODE_FRIEND_SHIP_SELECT+BI_COMMODE_ENEMY_SHIP_SELECT+BI_COMMODE_FRIEND_FORT_SELECT+BI_COMMODE_NEUTRAL_FORT_SELECT+BI_COMMODE_ENEMY_FORT_SELECT+BI_COMMODE_LAND_SELECT+BI_COMMODE_ALLLOCATOR_SELECT;
			BattleInterface.Commands.SailTo.EffectRadius	= -1.0;
		} else {
			BI_retComValue = BI_COMMODE_MY_SHIP_SELECT+BI_COMMODE_NEUTRAL_SHIP_SELECT+BI_COMMODE_FRIEND_SHIP_SELECT+BI_COMMODE_ENEMY_SHIP_SELECT+BI_COMMODE_ALLLOCATOR_SELECT;
			BattleInterface.Commands.SailTo.EffectRadius	= MIN_ENEMY_DISTANCE_TO_DISABLE_MAP_ENTER;
		}
		break;
	case "BI_Board":
		BI_retComValue = 0;
		break;
	case "BI_LandTroops":
		BI_retComValue = 0;
		break;
	case "BI_Map":
		BI_retComValue = 0;
		break;
	case "BI_Attack":
		BI_retComValue = BI_COMMODE_ENEMY_SHIP_SELECT+BI_COMMODE_ENEMY_FORT_SELECT+BI_COMMODE_ALLLOCATOR_SELECT;
		break;
	case "BI_Defend":
		BI_retComValue = BI_COMMODE_MY_SHIP_SELECT+BI_COMMODE_FRIEND_SHIP_SELECT+BI_COMMODE_FRIEND_FORT_SELECT+BI_COMMODE_ALLLOCATOR_SELECT;
		break;
	case "BI_SailAway":
		BI_retComValue = 0;
		break;
	case "BI_HeaveToDrift":
		BI_retComValue = 0;
		break;
	case "BI_Reload":
		BI_retComValue = 0;
		break;
	case "BI_Charge":
		BI_retComValue = BI_COMMODE_CANNON_CHARGE;
		break;
	case "BI_Speed":
		BI_retComValue = BI_COMMODE_USER_ICONS;
		break;
	case "BI_CompanionCommand":
		BI_retComValue = BI_COMMODE_MY_SHIP_SELECT+BI_COMMODE_ALLLOCATOR_SELECT;
		break;
	case "BI_Brander":
		BI_retComValue = BI_COMMODE_ENEMY_SHIP_SELECT+BI_COMMODE_ALLLOCATOR_SELECT;
		break;
	case "BI_ImmediateReload":
		BI_retComValue = 0;
		break;
	case "BI_InstantBoarding":
		BI_retComValue = BI_COMMODE_ENEMY_SHIP_SELECT+BI_COMMODE_ALLLOCATOR_SELECT;
		break;
	case "BI_LightRepair":
		BI_retComValue = 0;
		break;
	case "BI_InstantRepair":
		BI_retComValue = 0;
		break;
	case "BI_Turn180":
		BI_retComValue = 0;
		break;
	case "BI_SandbankManeuver":
		BI_retComValue = 0;
		break;
	case "BI_Troopers":
		BI_retComValue = BI_COMMODE_ENEMY_FORT_SELECT+BI_COMMODE_ALLLOCATOR_SELECT;
		break;
	case "BI_Ability":
		BI_retComValue = BI_COMMODE_ABILITY_ICONS;
		break;
	case "BI_ImmDeath":
		BI_retComValue = BI_COMMODE_ENEMY_SHIP_SELECT+BI_COMMODE_ENEMY_FORT_SELECT+BI_COMMODE_ALLLOCATOR_SELECT;
		break;
	}

	return &BI_retComValue;
}

void BI_LaunchCommand()
{
	int charIdx = GetEventData();
	string commandName = GetEventData();
	int targetNum = GetEventData();
	string locName = GetEventData();
	ref chRef = GetCharacter(charIdx);
	if( LAi_IsDead(chRef) ) return;

	if(targetNum==-1 && locName=="cancel") commandName = "";

	string alternativeCommand;
	if( CheckAttribute( &BattleInterface, "AbilityIcons."+commandName+".quest" ) )
	{
		alternativeCommand = commandName;
		commandName = "BI_UseItemAbilitie";
	}

	switch(commandName)
	{
	case "BI_Charge":
		int chargeType=GOOD_BALLS;
		switch(targetNum)
		{
		case 1:
			//Log_SetStringToLog("Cannonballs");
			chargeType=GOOD_BALLS;
			break;
		case 2:
			//Log_SetStringToLog("Grapes");
			chargeType=GOOD_GRAPES;
			break;
		case 3:
			//Log_SetStringToLog("Knippels");
			chargeType=GOOD_KNIPPELS;
			break;
		case 4:
			//Log_SetStringToLog("Bombs");
			chargeType=GOOD_BOMBS;
			break;
		}
		Ship_ChangeCharge(chRef, chargeType);
		break;
	case "BI_Map":
		Sea_MapLoad();
		break;
	case "BI_Moor":
		Sea_LandLoad();
		break;
	case "BI_Board":
		Sea_AbordageLoad(SHIP_ABORDAGE,true);
		break;
	case "BI_LandTroops":
		Sea_AbordageLoad(FORT_ABORDAGE,true);
		break;
	case "BI_SailAway":
		Ship_SetTaskRunAway(SECONDARY_TASK,charIdx);
		break;
	case "BI_HeaveToDrift":
		Ship_SetTaskDrift(SECONDARY_TASK,charIdx);
		break;
	case "BI_Defend":
		Ship_SetTaskDefend(SECONDARY_TASK,charIdx,GetTargChrIndex(targetNum,locName));
		break;
	case "BI_Attack":
		Ship_SetTaskAttack(SECONDARY_TASK,charIdx,GetTargChrIndex(targetNum,locName));
		break;
	case "BI_Reload":
		if(bi_nReloadTarget!=-1)
		{
			LaunchTransferMain(chRef,GetCharacter(bi_nReloadTarget),"");
		}
		break;
	case "BI_SailTo":
		if(targetNum==-1)
		{ // приплыть в локатор с именем locName
			SeaAI_SailToLocator(locName);
		}
		else
		{ // догнать перса с индексом targetNum
			SeaAI_SailToCharacter(targetNum);
		}
		break;
	case "BI_Speed":
		switch(locName)
		{
		case "sail_none":
			Ship_SetSailState(charIdx,0.0);
		break;
		case "sail_midi":
			Ship_SetSailState(charIdx,0.5);
		break;
		case "sail_fast":
			Ship_SetSailState(charIdx,1.0);
		break;
		}
		break;
	case "BI_CompanionCommand":
		BI_SetSpecCommandMode(BI_COMMODE_COMMAND_SELECT,-1,-1,targetNum,1);
		return;
		break;
	case "BI_ImmDeath":
		if(targetNum==-1)
		{ // смерть форта
			targetNum = Fort_FindCharacter(AISea.Island,"reload",locName);
			if(targetNum>=0)
			{
				Fort_SetAbordageMode(GetMainCharacter(), GetCharacter(targetNum));
			}
		}
		else
		{
			ShipDead(targetNum,KILL_BY_BALL,GetMainCharacterIndex());
		}
		break;

	case "BI_Brander":
		ActivateCharacterPerk(GetMainCharacter(),"Brander");
		Ship_SetTaskBrander(SECONDARY_TASK, charIdx, targetNum);
		break;
	case "BI_ImmediateReload":
		ActivateCharacterPerk(GetCharacter(charIdx),"ImmediateReload");
		break;
	case "BI_InstantBoarding":
		ActivateCharacterPerk(GetCharacter(charIdx),"InstantBoarding");
		CharacterPerkOff(GetCharacter(charIdx),"InstantBoarding");
		if( CheckSuccesfullBoard(GetCharacter(charIdx),GetCharacter(targetNum)) ) {
			Sea_AbordageStartNow(SHIP_ABORDAGE,targetNum,true,true);
		} else {
			Log_SetStringToLog( XI_ConvertString("failed to board") );
			Event("BI_LaunchCommand","lsls", charIdx, "BI_SailTo", targetNum, locName);
			return;
		}
		break;
	case "BI_LightRepair":
		ActivateCharacterPerk(GetCharacter(charIdx),"LightRepair");
		ActivateSpecRepair(GetCharacter(charIdx),0);
		break;
	case "BI_InstantRepair":
		ActivateCharacterPerk(GetCharacter(charIdx),"InstantRepair");
		ActivateSpecRepair(GetCharacter(charIdx),1);
		break;
	case "BI_Turn180":
		ActivateCharacterPerk(GetCharacter(charIdx),"Turn180");
		Ship_Turn180(GetCharacter(charIdx));
		break;
	case "BI_SandbankManeuver":
		ActivateCharacterPerk(GetCharacter(charIdx),"SandbankManeuver");
		break;
	case "BI_Troopers":
		ActivateCharacterPerk(GetMainCharacter(),"Troopers");
		break;

	// items abilities
	case "BI_UseItemAbilitie":
		CompleteQuestName( BattleInterface.AbilityIcons.(alternativeCommand).quest );
		break;
	}

	BI_SetCommandMode(BI_COMMODE_MY_SHIP_SELECT,-1,-1,-1);
}

void BI_SetIslandData()
{
	int isln = FindIsland(AISea.Island);
	if(isln==-1) return;

	ref atmp;
	atmp = GetIslandByIndex(isln);
	SendMessage(&BattleInterface,"la",BI_MSG_SET_ISLAND,atmp);
}

void BI_UpdateShip()
{
	int charIndex = GetEventData();
	AddShipToInterface(charIndex);
}

void BI_CreateShip()
{
	int charIndex = GetEventData();
	if(charIndex>=0) ClearActiveChrPerks(GetCharacter(charIndex));
	if( IsEntity(&BattleInterface) ) {
		AddShipToInterface(charIndex);
	}
}

void AddShipToInterface(int charIndex)
{
	if(charIndex==-1)
	{
		Trace("ERROR: Invalid character index for create ship");
		return;
	}
	ref chRef = GetCharacter(charIndex);
	int st = GetCharacterShipType(chRef);
	if( st==SHIP_NOTUSED )
	{
		Trace("WARNING!!! Character id = "+chRef.id+" hav`t ship.");
		return;
	}
	ref shipRef = GetShipByType(st);
	int myShip = false;
	int shipRelation = BI_RELATION_NEUTRAL;
	switch( SeaAI_GetRelation(charIndex,GetMainCharacterIndex()) )
	{
	case RELATION_FRIEND:
		shipRelation = BI_RELATION_FRIEND;
		break;
	case RELATION_ENEMY:
		shipRelation = BI_RELATION_ENEMY;
		break;
	}

	ref mainChRef = GetMainCharacter();
	for(int i=0; i<4; i++)
	{
		if(GetCompanionIndex(mainChRef,i) == charIndex)
		{
			myShip = true;
		}
	}

	if( CharacterIsDead(chRef) )
	{
		if( !CheckAttribute(chRef,"ship.shipsink") || sti(chRef.ship.shipsink)==false )
			return;
	}

	SendMessage(&BattleInterface,"llaall",BI_IN_CREATE_SHIP,charIndex,chRef,shipRef,myShip,shipRelation);
}

void BI_DeleteShip()
{
	int charIndex = GetEventData();
	if(charIndex==-1)
	{
		Trace("ERROR: Invalid character index");
		return;
	}
	if( IsCompanion(GetCharacter(charIndex)) )
	{
		RemoveCharacterCompanion(GetMainCharacter(),GetCharacter(charIndex));
	}
	DeleteAttribute(GetCharacter(charIndex),"ship.shipsink");
	RefreshBattleInterface();
}

void BI_DeadShip()
{
	int charIndex = GetEventData();
	if(charIndex==-1)
	{
		Trace("ERROR: Invalid character index");
		return;
	}
	if( IsCompanion(GetCharacter(charIndex)) )
	{
		RemoveCharacterCompanion(GetMainCharacter(),GetCharacter(charIndex));
	}
	Characters[charIndex].ship.shipsink = true;
	RefreshBattleInterface();
}

void BI_SetCommandMode(int commode, int texNum, int picNum, int chIdx)
{
	bi_icons_CommandMode = commode;
	SendMessage(&BattleInterface,"llllll",BI_IN_SET_COMMAND_MODE,commode,texNum,picNum,chIdx,-1);
}

void BI_SetSpecCommandMode(int commode, int texNum, int picNum, int chIdx, int comState)
{
	bi_icons_CommandMode = commode;
	SendMessage(&BattleInterface,"llllll",BI_IN_SET_COMMAND_MODE,commode,texNum,picNum,chIdx,comState);
}

void BI_SetPossibleCommands()
{
	int chIdx = GetEventData();
	ref mainCh = GetMainCharacter();
	int mainIdx = sti(mainCh.index);

	if( chIdx<0 || CharacterIsDead(GetCharacter(chIdx)) )
	{
		aref aroot,arcur;
		makearef(aroot,BattleInterface.Commands);
		int q = GetAttributesNum(aroot);
		for(int i=0; i<q; i++)
		{
			arcur = GetAttributeN(aroot,i);
			arcur.enable = false;
		}
		BattleInterface.Commands.Cancel.enable = true;
		return;
	}

	// для главного персонажа
	if(mainIdx==chIdx)
	{
		BattleInterface.Commands.Moor.enable			= bCanEnterToLand;
		BattleInterface.Commands.Board.enable			= bAbordageShipCanBe;
		BattleInterface.Commands.SailAway.enable		= false;
		BattleInterface.Commands.HeaveToDrift.enable	= false;
		BattleInterface.Commands.Charge.enable			= CheckAttribute(mainCh,"Ship.Cannons.Charge.Type");
		BattleInterface.Commands.LandTroops.enable		= bAbordageFortCanBe;
		BattleInterface.Commands.Attack.enable			= false;
		BattleInterface.Commands.Defend.enable			= false;
		BattleInterface.Commands.Reload.enable			= bReloadCanBe;
		BattleInterface.Commands.SailTo.enable			= !bDisableSailTo && bSailTo;
		BattleInterface.Commands.Map.enable				= bMapEnter;
		BattleInterface.Commands.Speed.enable			= true;
		BattleInterface.Commands.CCommand.enable		= GetCompanionQuantity(mainCh)>1;
		BattleInterface.Commands.Ability.enable			= true;
	}
	// для спутников
	else
	{
		BattleInterface.Commands.Moor.enable			= false;
		BattleInterface.Commands.Board.enable			= false;
		BattleInterface.Commands.SailAway.enable		= true;
		BattleInterface.Commands.HeaveToDrift.enable	= true;
		BattleInterface.Commands.Charge.enable			= false;
		BattleInterface.Commands.LandTroops.enable		= false;
		BattleInterface.Commands.Attack.enable			= bAttack;
		BattleInterface.Commands.Defend.enable			= bDefend;
		BattleInterface.Commands.Reload.enable			= false;
		BattleInterface.Commands.SailTo.enable			= false;
		BattleInterface.Commands.Map.enable				= false;
		BattleInterface.Commands.Speed.enable			= false;
		BattleInterface.Commands.CCommand.enable		= false;
		BattleInterface.Commands.Ability.enable			= true;
	}
}

void BI_InitializeCommands()
{
	int idLngFile = LanguageOpenFile("commands_name.txt");

	BattleInterface.Commands.Cancel.enable			= false;
	BattleInterface.Commands.Cancel.picNum			= 0;
	BattleInterface.Commands.Cancel.event			= "Cancel";
	BattleInterface.Commands.Cancel.note			= LanguageConvertString(idLngFile, "sea_Cancel");
	BattleInterface.Commands.Moor.enable			= false;
	BattleInterface.Commands.Moor.picNum			= 1;
	BattleInterface.Commands.Moor.event				= "BI_Moor";
	BattleInterface.Commands.Moor.note				= LanguageConvertString(idLngFile, "sea_Moor");
	BattleInterface.Commands.SailTo.enable			= false;
	BattleInterface.Commands.SailTo.picNum			= 3;
	BattleInterface.Commands.SailTo.event			= "BI_SailTo";
	BattleInterface.Commands.SailTo.note			= LanguageConvertString(idLngFile, "sea_SailTo");
	BattleInterface.Commands.Board.enable			= false;
	BattleInterface.Commands.Board.picNum			= 2;
	BattleInterface.Commands.Board.event			= "BI_Board";
	BattleInterface.Commands.Board.note				= LanguageConvertString(idLngFile, "sea_Board");
	BattleInterface.Commands.LandTroops.enable		= false;
	BattleInterface.Commands.LandTroops.picNum		= 4;
	BattleInterface.Commands.LandTroops.event		= "BI_LandTroops";
	BattleInterface.Commands.LandTroops.note		= LanguageConvertString(idLngFile, "sea_LandTroops");
	BattleInterface.Commands.Map.enable				= false;
	BattleInterface.Commands.Map.picNum				= 5;
	BattleInterface.Commands.Map.event				= "BI_Map";
	BattleInterface.Commands.Map.note				= LanguageConvertString(idLngFile, "sea_Map");
	BattleInterface.Commands.Attack.enable			= false;
	BattleInterface.Commands.Attack.picNum			= 7;
	BattleInterface.Commands.Attack.event			= "BI_Attack";
	BattleInterface.Commands.Attack.note			= LanguageConvertString(idLngFile, "sea_Attack");
	BattleInterface.Commands.Defend.enable			= false;
	BattleInterface.Commands.Defend.picNum			= 8;
	BattleInterface.Commands.Defend.event			= "BI_Defend";
	BattleInterface.Commands.Defend.note			= LanguageConvertString(idLngFile, "sea_Defend");
	BattleInterface.Commands.SailAway.enable		= false;
	BattleInterface.Commands.SailAway.picNum		= 9;
	BattleInterface.Commands.SailAway.event			= "BI_SailAway";
	BattleInterface.Commands.SailAway.note			= LanguageConvertString(idLngFile, "sea_SailAway");
	BattleInterface.Commands.HeaveToDrift.enable	= false;
	BattleInterface.Commands.HeaveToDrift.picNum	= 10;
	BattleInterface.Commands.HeaveToDrift.event		= "BI_HeaveToDrift";
	BattleInterface.Commands.HeaveToDrift.note		= LanguageConvertString(idLngFile, "sea_HeaveToDrift");
	BattleInterface.Commands.Reload.enable			= false;
	BattleInterface.Commands.Reload.picNum			= 6;
	BattleInterface.Commands.Reload.event			= "BI_Reload";
	BattleInterface.Commands.Reload.note			= LanguageConvertString(idLngFile, "sea_Reload");
	BattleInterface.Commands.Charge.enable			= false;
	BattleInterface.Commands.Charge.picNum			= 11;
	BattleInterface.Commands.Charge.event			= "BI_Charge";
	BattleInterface.Commands.Charge.note			= LanguageConvertString(idLngFile, "sea_Charge");
	BattleInterface.Commands.Speed.enable			= false;
	BattleInterface.Commands.Speed.picNum			= 12;
	BattleInterface.Commands.Speed.event			= "BI_Speed";
	BattleInterface.Commands.Speed.note				= LanguageConvertString(idLngFile, "sea_Speed");
	BattleInterface.Commands.CCommand.enable		= false;
	BattleInterface.Commands.CCommand.picNum		= 14;
	BattleInterface.Commands.CCommand.event			= "BI_CompanionCommand";
	BattleInterface.Commands.CCommand.note			= LanguageConvertString(idLngFile, "sea_CCommand");
	BattleInterface.Commands.Ability.enable			= false;
	BattleInterface.Commands.Ability.picNum			= 13;
	BattleInterface.Commands.Ability.event			= "BI_Ability";
	BattleInterface.Commands.Ability.note			= LanguageConvertString(idLngFile, "sea_Ability");
	BattleInterface.Commands.ImmediateDeath.enable	= false;
	BattleInterface.Commands.ImmediateDeath.picNum	= 0;
	BattleInterface.Commands.ImmediateDeath.event	= "BI_ImmDeath";
	BattleInterface.Commands.ImmediateDeath.texNum	= 7;
	BattleInterface.Commands.ImmediateDeath.note	= LanguageConvertString(idLngFile, "sea_ImmediateDeath");

	BattleInterface.AbilityIcons.Brander.enable			= false;
	BattleInterface.AbilityIcons.Brander.picNum			= 0;
	BattleInterface.AbilityIcons.Brander.texNum			= 6;
	BattleInterface.AbilityIcons.Brander.event			= "BI_Brander";

	BattleInterface.AbilityIcons.ImmediateReload.enable			= false;
	BattleInterface.AbilityIcons.ImmediateReload.picNum			= 6;
	BattleInterface.AbilityIcons.ImmediateReload.texNum			= 6;
	BattleInterface.AbilityIcons.ImmediateReload.event			= "BI_ImmediateReload";
	BattleInterface.AbilityIcons.InstantBoarding.enable			= false;
	BattleInterface.AbilityIcons.InstantBoarding.picNum			= 7;
	BattleInterface.AbilityIcons.InstantBoarding.texNum			= 6;
	BattleInterface.AbilityIcons.InstantBoarding.event			= "BI_InstantBoarding";

	BattleInterface.AbilityIcons.LightRepair.enable			= false;
	BattleInterface.AbilityIcons.LightRepair.picNum			= 5;
	BattleInterface.AbilityIcons.LightRepair.texNum			= 6;
	BattleInterface.AbilityIcons.LightRepair.event			= "BI_LightRepair";
	BattleInterface.AbilityIcons.InstantRepair.enable		= false;
	BattleInterface.AbilityIcons.InstantRepair.picNum		= 1;
	BattleInterface.AbilityIcons.InstantRepair.texNum		= 6;
	BattleInterface.AbilityIcons.InstantRepair.event		= "BI_InstantRepair";
	BattleInterface.AbilityIcons.Turn180.enable				= false;
	BattleInterface.AbilityIcons.Turn180.picNum				= 2;
	BattleInterface.AbilityIcons.Turn180.texNum				= 6;
	BattleInterface.AbilityIcons.Turn180.event				= "BI_Turn180";
	BattleInterface.AbilityIcons.SandbankManeuver.enable	= false;
	BattleInterface.AbilityIcons.SandbankManeuver.picNum	= 3;
	BattleInterface.AbilityIcons.SandbankManeuver.texNum	= 6;
	BattleInterface.AbilityIcons.SandbankManeuver.event		= "BI_SandbankManeuver";
	BattleInterface.AbilityIcons.Troopers.enable			= false;
	BattleInterface.AbilityIcons.Troopers.picNum			= 4;
	BattleInterface.AbilityIcons.Troopers.texNum			= 6;
	BattleInterface.AbilityIcons.Troopers.event				= "BI_Troopers";

	LanguageCloseFile(idLngFile);
}

ref BI_GetChargeQuantity()
{
	int chIdx = GetEventData();
	ref refChar = GetCharacter(chIdx);
	BI_ChargeState[0] = 4;
	BI_ChargeState[1] = GetCargoGoods(refChar,GOOD_BALLS);
	BI_ChargeState[2] = GetCargoGoods(refChar,GOOD_GRAPES);
	BI_ChargeState[3] = GetCargoGoods(refChar,GOOD_KNIPPELS);
	BI_ChargeState[4] = GetCargoGoods(refChar,GOOD_BOMBS);

	return &BI_ChargeState;
}

ref GetCurrentCharge()
{
	ref refChar = GetMainCharacter();
	BI_intRetValue = -1;

	if( CheckAttribute(refChar,"Ship.Cannons.Charge.Type") )
	{
		switch(sti(refChar.Ship.Cannons.Charge.Type))
		{
		case GOOD_BALLS:
			BI_intRetValue = 2;
			break;
		case GOOD_GRAPES:
			BI_intRetValue = 3;
			break;
		case GOOD_KNIPPELS:
			BI_intRetValue = 0;
			break;
		case GOOD_BOMBS:
			BI_intRetValue = 1;
			break;
		}
	}

	return &BI_intRetValue;
}

void BI_SetSeaState()
{
	bool bTmp;
	bSailTo = GetEventData();
	bTmp = GetEventData();
	bMapEnter = GetEventData();
	bAttack = GetEventData();
	bDefend = GetEventData();
	bReloadCanBe = GetEventData();
	bi_nReloadTarget = GetEventData();
	bEnableIslandSailTo = bMapEnter;
	if(bDisableMapEnter)	bMapEnter = false;
}

ref BI_GetData()
{
	int dataType = GetEventData();
	int chrIdx;
	ref chRef;

	switch(dataType)
	{
	// Получаем номер картинки корабля
	case BIDT_SHIPPICTURE:
		chRef = GetCharacter(GetEventData());
		if( CharacterIsDead(chRef) )
		{
			BI_intNRetValue[0] = 0;
			BI_intNRetValue[1] = 7;
			BI_intNRetValue[2] = true;
			break;
		}
		int st = sti(chRef.Ship.Type);
		if(st>=0 && st<SHIP_TYPES_QUANTITY)
		{
			switch(ShipsTypes[st].name)
			{
			case "tartane1":
				BI_intNRetValue[0] = 11;
				BI_intNRetValue[1] = 2;
				break;
			case "tartane2":
				BI_intNRetValue[0] = 11;
				BI_intNRetValue[1] = 2;
				break;
			case "yacht1":
				BI_intNRetValue[0] = 9;
				BI_intNRetValue[1] = 2;
				break;
			case "yacht2":
				BI_intNRetValue[0] = 9;
				BI_intNRetValue[1] = 2;
				break;
			case "barque1":
				BI_intNRetValue[0] = 7;
				BI_intNRetValue[1] = 2;
				break;
			case "barque2":
				BI_intNRetValue[0] = 7;
				BI_intNRetValue[1] = 2;
				break;
			case "lugger1":
				BI_intNRetValue[0] = 15;
				BI_intNRetValue[1] = 2;
				break;
			case "lugger2":
				BI_intNRetValue[0] = 15;
				BI_intNRetValue[1] = 2;
				break;
			case "galeoth1":
				BI_intNRetValue[0] = 0;
				BI_intNRetValue[1] = 3;
				break;
			case "galeoth2":
				BI_intNRetValue[0] = 0;
				BI_intNRetValue[1] = 3;
				break;
			case "xebec1":
				BI_intNRetValue[0] = 10;
				BI_intNRetValue[1] = 2;
				break;
			case "xebec2":
				BI_intNRetValue[0] = 10;
				BI_intNRetValue[1] = 2;
				break;
			case "sloop1":
				BI_intNRetValue[0] = 8;
				BI_intNRetValue[1] = 2;
				break;
			case "sloop2":
				BI_intNRetValue[0] = 8;
				BI_intNRetValue[1] = 2;
				break;
			case "schooner1":
				BI_intNRetValue[0] = 12;
				BI_intNRetValue[1] = 2;
				break;
			case "schooner2":
				BI_intNRetValue[0] = 12;
				BI_intNRetValue[1] = 2;
				break;
			case "caravel1":
				BI_intNRetValue[0] = 4;
				BI_intNRetValue[1] = 2;
				break;
			case "caravel2":
				BI_intNRetValue[0] = 4;
				BI_intNRetValue[1] = 2;
				break;
			case "fleut1":
				BI_intNRetValue[0] = 2;
				BI_intNRetValue[1] = 2;
				break;
			case "fleut2":
				BI_intNRetValue[0] = 2;
				BI_intNRetValue[1] = 2;
				break;
			case "brig1":
				BI_intNRetValue[0] = 5;
				BI_intNRetValue[1] = 2;
				break;
			case "brig2":
				BI_intNRetValue[0] = 5;
				BI_intNRetValue[1] = 2;
				break;
			case "galeon1":
				BI_intNRetValue[0] = 0;
				BI_intNRetValue[1] = 2;
				break;
			case "galeon2":
				BI_intNRetValue[0] = 0;
				BI_intNRetValue[1] = 2;
				break;
			case "pinnace1":
				BI_intNRetValue[0] = 13;
				BI_intNRetValue[1] = 2;
				break;
			case "pinnace2":
				BI_intNRetValue[0] = 13;
				BI_intNRetValue[1] = 2;
				break;
			case "frigate1":
				BI_intNRetValue[0] = 1;
				BI_intNRetValue[1] = 2;
				break;
			case "frigate2":
				BI_intNRetValue[0] = 1;
				BI_intNRetValue[1] = 2;
				break;
			case "frigate_sat":
				BI_intNRetValue[0] = 1;
				BI_intNRetValue[1] = 2;
				break;
			case "corvette1":
				BI_intNRetValue[0] = 3;
				BI_intNRetValue[1] = 2;
				break;
			case "corvette2":
				BI_intNRetValue[0] = 3;
				BI_intNRetValue[1] = 2;
				break;
			case "battleship1":
				BI_intNRetValue[0] = 6;
				BI_intNRetValue[1] = 2;
				break;
			case "battleship2":
				BI_intNRetValue[0] = 6;
				BI_intNRetValue[1] = 2;
				break;
			case "manowar1":
				BI_intNRetValue[0] = 14;
				BI_intNRetValue[1] = 2;
				break;
			case "manowar2":
				BI_intNRetValue[0] = 14;
				BI_intNRetValue[1] = 2;
				break;
			case "manowar_gub":
				BI_intNRetValue[0] = 14;
				BI_intNRetValue[1] = 2;
				break;
			case "BlackPearl":
				BI_intNRetValue[0] = 0;
				BI_intNRetValue[1] = 4;
				break;
			case "Fearless":
				BI_intNRetValue[0] = 1;
				BI_intNRetValue[1] = 4;
				break;
			}
			BI_intNRetValue[2] = false;
		}	
		break;

	case BIDT_GERALD_DATA:
		{
			chrIdx = GetEventData();
			if(chrIdx<0) break;
			chRef = GetCharacter(chrIdx);
			BI_intNRetValue[0] = 8;
			switch( SeaAI_GetRelation(chrIdx,GetMainCharacterIndex()) )
			{
			case RELATION_FRIEND:	BI_intNRetValue[1] = 7; break;
			case RELATION_NEUTRAL:	BI_intNRetValue[1] = -1; break;
			case RELATION_ENEMY:	BI_intNRetValue[1] = 6; break;
			}
			BI_intNRetValue[2] = 8;
			switch( sti(chRef.nation) )
			{
			case ENGLAND:		BI_intNRetValue[3] = 3; break;
			case FRANCE:		BI_intNRetValue[3] = 2; break;
			case SPAIN:			BI_intNRetValue[3] = 0; break;
			case PIRATE:		BI_intNRetValue[3] = 5; break;
			case HOLLAND:		BI_intNRetValue[3] = 4; break;
			case PORTUGAL:		BI_intNRetValue[3] = 1; break;
			}
		}
		break;
	}
	return &BI_intNRetValue;
}

void SetParameterData()
{
	BattleInterface.CommandTextures.list.t0.name = "battle_interface\cicons_charge.tga";
	BattleInterface.CommandTextures.list.t0.xsize = 1;
	BattleInterface.CommandTextures.list.t0.ysize = 4;

	BattleInterface.CommandTextures.list.t1.name = "battle_interface\cicons_command.tga";
	BattleInterface.CommandTextures.list.t1.xsize = 4;
	BattleInterface.CommandTextures.list.t1.ysize = 4;

	BattleInterface.CommandTextures.list.t2.name = "battle_interface\ships_16.tga";
	BattleInterface.CommandTextures.list.t2.xsize = 4;
	BattleInterface.CommandTextures.list.t2.ysize = 4;
	BattleInterface.CommandTextures.list.t3.name = "battle_interface\ships_1.tga";
	BattleInterface.CommandTextures.list.t3.xsize = 1;
	BattleInterface.CommandTextures.list.t3.ysize = 1;
	BattleInterface.CommandTextures.list.t4.name = "battle_interface\ships_2.tga";
	BattleInterface.CommandTextures.list.t4.xsize = 1;
	BattleInterface.CommandTextures.list.t4.ysize = 2;

	BattleInterface.CommandTextures.list.t5.name = "battle_interface\SailControls.tga";
	BattleInterface.CommandTextures.list.t5.xsize = 4;
	BattleInterface.CommandTextures.list.t5.ysize = 1;

	BattleInterface.CommandTextures.list.t6.name = "battle_interface\sea_abilitys.tga";
	BattleInterface.CommandTextures.list.t6.xsize = 4;
	BattleInterface.CommandTextures.list.t6.ysize = 2;

	BattleInterface.CommandTextures.list.t7.name = "battle_interface\scull.tga";
	BattleInterface.CommandTextures.list.t7.xsize = 1;
	BattleInterface.CommandTextures.list.t7.ysize = 1;

	BattleInterface.CommandTextures.list.t8.name = "battle_interface\small_nations.tga";
	BattleInterface.CommandTextures.list.t8.xsize = 8;
	BattleInterface.CommandTextures.list.t8.ysize = 1;

	BattleInterface.CommandTextures.list.t9.name = "battle_interface\Artefact.tga";
	BattleInterface.CommandTextures.list.t9.xsize = 1;
	BattleInterface.CommandTextures.list.t9.ysize = 1;

	BattleInterface.CommandTextures.ChargeTexNum = 0;
	BattleInterface.CommandTextures.CommandTexNum = 1;

	BattleInterface.CommandShowParam.maxShowQuantity = 5;
	BattleInterface.CommandShowParam.iconDistance = 4;
	BattleInterface.CommandShowParam.iconWidth = RecalculateHIcon(64);
	BattleInterface.CommandShowParam.iconHeight = RecalculateVIcon(64);
	BattleInterface.CommandShowParam.leftIconsOffset = sti(showWindow.left)+RecalculateHIcon(16);
	BattleInterface.CommandShowParam.downIconsOffset = sti(showWindow.bottom)-RecalculateVIcon(80);
	BattleInterface.CommandShowParam.buttonWidth = RecalculateHIcon(8);
	BattleInterface.CommandShowParam.buttonHeight = RecalculateVIcon(64);
	BattleInterface.CommandShowParam.buttonOffset = RecalculateHIcon(4);
	BattleInterface.CommandShowParam.buttonTexture = "battle_interface\lr_buttons.tga";
	BattleInterface.CommandShowParam.shipStateWidth = RecalculateHIcon(64);
	BattleInterface.CommandShowParam.shipStateHeight = RecalculateVIcon(16);
	BattleInterface.CommandShowParam.shipStateTexture = "battle_interface\indicators.tga";
	BattleInterface.CommandShowParam.shipStateOffset = RecalculateVIcon(0);
	BattleInterface.CommandShowParam.GeraldWidth = RecalculateHIcon(32);
	BattleInterface.CommandShowParam.GeraldHeight = RecalculateVIcon(32);
	BattleInterface.CommandShowParam.commandFont = "bold_numbers";
	BattleInterface.CommandShowParam.printXOffset = RecalculateHIcon(32);
	BattleInterface.CommandShowParam.printYOffset = RecalculateVIcon(-26);
	BattleInterface.CommandShowParam.commandNoteFont = "interface_normal";
	BattleInterface.CommandShowParam.noteXOffset = RecalculateHIcon(0);
	BattleInterface.CommandShowParam.noteYOffset = RecalculateVIcon(-30);
	BattleInterface.CommandShowParam.argbTFactorColor = argb(256,64,64,64);

	BattleInterface.UserIcons.ui1.enable = true;
	BattleInterface.UserIcons.ui1.pic = 0;
	BattleInterface.UserIcons.ui1.tex = 5;
	BattleInterface.UserIcons.ui1.name = "sail_none";
	//----------------------------------------------
	BattleInterface.UserIcons.ui2.enable = true;
	BattleInterface.UserIcons.ui2.pic = 1;
	BattleInterface.UserIcons.ui2.tex = 5;
	BattleInterface.UserIcons.ui2.name = "sail_midi";
	//----------------------------------------------
	BattleInterface.UserIcons.ui3.enable = true;
	BattleInterface.UserIcons.ui3.pic = 2;
	BattleInterface.UserIcons.ui3.tex = 5;
	BattleInterface.UserIcons.ui3.name = "sail_fast";

	//===============================================
	BattleInterface.MessageIcons.IconWidth = RecalculateHIcon(64);
	BattleInterface.MessageIcons.IconHeight = RecalculateVIcon(24);
	BattleInterface.MessageIcons.IconDist = RecalculateVIcon(2);
	BattleInterface.MessageIcons.IconBottom = sti(showWindow.bottom)-RecalculateVIcon(80+20);
	BattleInterface.MessageIcons.IconMaxQuantity = 4;
	BattleInterface.MessageIcons.BlendTime = 3.0;
	BattleInterface.MessageIcons.FallSpeed = 22.0;
	BattleInterface.MessageIcons.argbHighBlind = argb(255,128,128,128);
	BattleInterface.MessageIcons.argbLowBlind = argb(255,68,68,68);
	BattleInterface.MessageIcons.BlindUpTime = 0.5;
	BattleInterface.MessageIcons.BlindDownTime = 1.0;
	BattleInterface.MessageIcons.texture = "battle_interface\MessageIcons.tga";
	BattleInterface.MessageIcons.TexHSize = 2;
	BattleInterface.MessageIcons.TexVSize = 2;

	BattleInterface.navigation.aspectRatio				= showWindow.aspectRatio;
	BattleInterface.navigation.navigatorWidth			= RecalculateHIcon(192);
	BattleInterface.navigation.navigatorHeight			= RecalculateVIcon(192);
	BattleInterface.navigation.rightPos					= showWindow.right;
	BattleInterface.navigation.topPos					= showWindow.top;
	BattleInterface.navigation.speedShowFont			= "bold_numbers";
	BattleInterface.navigation.speedOutYOffset			= RecalculateVIcon(-88);
	BattleInterface.navigation.shipSpeedXOffset			= RecalculateHIcon(80);
	BattleInterface.navigation.windSpeedXOffset			= RecalculateHIcon(-80);
	BattleInterface.navigation.fontScale				= 0.75;
	BattleInterface.navigation.windWidth				= 30;
	BattleInterface.navigation.windHeight				= 120;
	BattleInterface.navigation.compasTexture			= "battle_interface\compass.tga";
	BattleInterface.navigation.speedTexture				= "battle_interface\indicators_wind_and_ship.tga";
	BattleInterface.navigation.cannonsTexture			= "battle_interface\indicators_cannons_reload.tga";
	BattleInterface.navigation.emptyTexture				= "battle_interface\indicators_dark_and_center_ship.tga";
	BattleInterface.navigation.windTexture				= "battle_interface\wind_pointer.tga";
	BattleInterface.navigation.leftChargeBegAngle		= 215;
	BattleInterface.navigation.leftChargeEndAngle		= 325;
	BattleInterface.navigation.rightChargeBegAngle		= 145;
	BattleInterface.navigation.rightChargeEndAngle		= 35;
	BattleInterface.navigation.forwardChargeBegAngle	= 335;
	BattleInterface.navigation.forwardChargeEndAngle	= 385;
	BattleInterface.navigation.backwardChargeBegAngle	= 205;
	BattleInterface.navigation.backwardChargeEndAngle	= 155;
	BattleInterface.navigation.shipSpeedBegAngle		= 175;
	BattleInterface.navigation.shipSpeedEndAngle		= 55;
	BattleInterface.navigation.windSpeedBegAngle		= 180;
	BattleInterface.navigation.windSpeedEndAngle		= 410;
	BattleInterface.navigation.mapRadius				= 54;
	BattleInterface.navigation.horizontRadius			= 400;
	BattleInterface.navigation.minScale					= 0.5;
	BattleInterface.navigation.maxScale					= 4;
	BattleInterface.navigation.scaleStep				= 0.1;
	BattleInterface.navigation.argbReadyCannonColor		= argb(255,0,155,0);
	BattleInterface.navigation.argbChargeCannonColor	= argb(255,255,0,0);
	BattleInterface.navigation.argbSeaColor				= argb(255,10,30,80);
	BattleInterface.navigation.argbFireZoneColor		= argb(60,250,250,250);
	BattleInterface.navigation.argbEnemyShipColor		= argb(255,255,0,0);
	BattleInterface.navigation.argbFrendShipColor		= argb(255,0,255,0);
	BattleInterface.navigation.argbNeutralShipColor		= argb(255,128,128,128);
	BattleInterface.navigation.argbDeadShipColor		= argb(255,0,0,255);
	BattleInterface.navigation.argbBackMaxColor			= argb(255,0,0,128);
	BattleInterface.navigation.argbBackMinColor			= argb(0,0,0,128);
	BattleInterface.navigation.shipShowRadius			= 8.0;
	BattleInterface.navigation.chargeTexture			= "battle_interface\small_cannons.tga";
	BattleInterface.navigation.chargeTextureGreed		= "1,4";
	BattleInterface.navigation.chargePos				= RecalculateHIcon(160)+","+RecalculateVIcon(174);
	BattleInterface.navigation.chargePictureSize		= "32,32";
}

ref ProcessSailDamage()
{
	// от кого удар
	int shootIdx = GetEventData();
	// перс
	int chrIdx = GetEventData();
	string sMastName = GetEventData();
	// координаты паруса
	string reyName = GetEventData();
	int groupNum = GetEventData();
	// данные о дырках
	int holeCount = GetEventData();
	int holeData = GetEventData();
	int maxHoleCount = GetEventData();
	// мощность паруса
	float sailPower = GetEventData();

	ref chref = GetCharacter(chrIdx);
	string groupName = ""+groupNum;
	aref arSail;
	makearef(arSail,chref.ship.sails.(reyName).(groupName));

	float sailDmg = 0.0;
	float sailDmgMax = GetCharacterShipSP(chref) * sailPower;
	if( !CheckAttribute(arSail,"dmg") )	{ sailDmg = 0.0; }

	if(sMastName=="*")
	{
		sailDmg += GetRigDamage(shootIdx,sti(AIBalls.CurrentBallType),chref);
		if(sailDmg>sailDmgMax)	{ sailDmg = sailDmgMax; }
		int needHole = GetNeedHoleFromDmg(sailDmg,sailDmgMax,maxHoleCount);
		if(holeCount!=needHole)
		{
			if(holeCount<needHole)
			{
				holeData = RandomHole2Sail(chrIdx,reyName,groupNum, maxHoleCount, holeData, needHole-holeCount);
				holeCount = needHole;
			}
			else
			{
				sailDmg = GetNeedDmgFromHole(holeCount,sailDmgMax,maxHoleCount);
			}
		}
	}
	else
	{
		if(sMastName!="#")	{ arSail.mastFall = sMastName; }
		sailDmg = sailDmgMax;
	}

	arSail.hc = holeCount;
	arSail.hd = holeData;
	arSail.mhc = maxHoleCount;
	arSail.sp = sailPower;
	arSail.dmg = sailDmg;

	chref.ship.SP = CalculateShipSP(chref);
	BI_g_fRetVal = sailDmg;
	return &BI_g_fRetVal;
}

void ProcessDayRepair()
{
	int i, cn;
	float matQ, tmpf, repPercent;
	ref chref;
	for(i=0; i<4; i++)
	{
		cn = GetCompanionIndex(GetMainCharacter(),i);
		if(cn==-1) continue;
		chref = GetCharacter(cn);

		// расчет починки корпуса
		if( GetHullPercent(chref)<100.0 )
		{
			repPercent = GetHullRPD(chref);
			matQ = repPercent*GetHullPPP(chref);
			tmpf = GetRepairGoods(true,chref);
			if(tmpf<matQ)	{ repPercent = tmpf/GetHullPPP(chref); }
			repPercent = ProcessHullRepair(chref,repPercent);
			matQ = repPercent*GetHullPPP(chref);
			RemoveRepairGoods(true,chref,matQ);
		}

		// расчет починки парусов
		if( GetSailPercent(chref)<100.0 )
		{
			repPercent = GetSailRPD(chref);
			matQ = repPercent*GetSailSPP(chref);
			tmpf = GetRepairGoods(false,chref);
			if(tmpf<matQ)	{ repPercent = tmpf/GetSailSPP(chref); }
			repPercent = ProcessSailRepair(chref,repPercent);
			matQ = repPercent*GetSailSPP(chref);
			RemoveRepairGoods(false,chref,matQ);
		}
	}
}

ref procGetSailTextureData()
{
	int st,i,sq;
	ref shref;
	aref arEmbl,arSail;
	string attrName;

	int chrIdx = GetEventData();

	DeleteAttribute(&BI_objRetValue,"");
	BI_objRetValue.normalTex = "ships\parus_common.tga";

	string nationFileName = "ships\parus_common.tga";
	string tmpStr;

	if(chrIdx>=0)
	{
		switch(sti(Characters[chrIdx].nation))
		{
		case ENGLAND:		nationFileName = "ships\parus_england.tga";		break;
		case FRANCE:		nationFileName = "ships\parus_france.tga";		break;
		case SPAIN:			nationFileName = "ships\parus_spain.tga";		break;
		case PIRATE:
			nationFileName = "ships\parus_pirate.tga";
			BI_objRetValue.normalTex = "ships\sail_Pirates.tga";
			break;
		case HOLLAND:		nationFileName = "ships\parus_holland.tga";		break;
		case PORTUGAL:		nationFileName = "ships\parus_portugal.tga";	break;
		}

		st = GetCharacterShipType(GetCharacter(chrIdx));
		if(st!=SHIP_NOTUSED)
		{
			shref = GetShipByType(st);
			if( CheckAttribute(&Characters[chrIdx],"Features.GeraldSails") &&
				sti(Characters[chrIdx].Features.GeraldSails)==true ) {
				makearef(arEmbl,shref.GeraldSails);
			} else {
				makearef(arEmbl,shref.EmblemedSails);
			}
			sq = GetAttributesNum(arEmbl);
			for(i=0; i<sq; i++)
			{
				arSail = GetAttributeN(arEmbl,i);
				attrName = GetAttributeName(arSail);
				tmpStr = GetAttributeValue(arSail);
				if(tmpStr=="1")	{BI_objRetValue.(attrName) = nationFileName;}
				else	{BI_objRetValue.(attrName) = tmpStr;}
			}
		}
	}

	return &BI_objRetValue;
}

ref procGetRiggingData()
{
	int i,n;

	int retVal = 0;

	string datName = GetEventData();
	if(datName=="GetFlagTexNum")
	{
		i = GetEventData();
		n = GetEventData();
		if(i==true)
		{
			switch(n)
			{
			case ENGLAND: retVal = 1; break;
			case FRANCE: retVal = 2; break;
			case SPAIN: retVal = 4; break;
			case PIRATE: retVal = 5; break;
			case HOLLAND: retVal = 0; break;
			case PORTUGAL: retVal = 3; break;
			}
		}
		else
		{
			switch(n)
			{
			case ENGLAND: retVal = 1; break;
			case FRANCE: retVal = 2; break;
			case SPAIN: retVal = 4; break;
			case PIRATE: retVal = 5; break;
			case HOLLAND: retVal = 0; break;
			case PORTUGAL: retVal = 3; break;
			}
		}
	}
	return &retVal;
}

void procBISelectShip()
{
	int chrIdx = GetEventData();
	int isMyChr = GetEventData();

	if(chrIdx==GetMainCharacterIndex())	chrIdx = -1;

	float fShSpeed = 0.005;
	float fShAmp = 1.0;
	float fShW = 1.0;
	float fShH = 1.0;
	float fTop = 10.0;

	SendMessage(&objShipPointer,"lllfffff",MSG_SP_CHANGESHIP,chrIdx,isMyChr,fShSpeed,fShAmp,fShW,fShH,fTop);
}

void procMastFall()
{
	int chrIdx = GetEventData();
	string mastName = GetEventData();
	int bFirstFall = GetEventData();

	if(chrIdx<0) return;
	int mastNum = strcut(mastName,4,strlen(mastName)-1);

	trace("For character "+chrIdx+" fall Mast name "+mastName+" has index "+mastNum);
	SendMessage(&PeopleOnShip, "lal", MSG_PEOPLES_ON_SHIP_MASTFALL, GetCharacter(chrIdx), mastNum);
}

bool CheckInstantRepairCondition(ref chref)
{
	if(!GetCharacterPerkUsing(chref,"InstantRepair")) return false;

	float chrShipHP = GetHullPercent(chref);
	float chrShipSP = GetSailPercent(chref);

	bool bYesHPRepair = chrShipHP<90.0;
	bool bYesSPRepair = chrShipSP<90.0;

	if( bYesHPRepair )	{ bYesHPRepair = GetCargoGoods(chref,GOOD_PLANKS)>0; }
	if( bYesSPRepair )	{ bYesSPRepair = GetCargoGoods(chref,GOOD_SAILCLOTH)>0; }

	return bYesHPRepair || bYesSPRepair;
}

void BI_PerkAgainUsable()
{
	BI_SetCommandMode(-1,-1,-1,-1);
}

float GetRepairGoods(bool bIsHull, ref chref)
{
	float fGoodsQ = 0.0;

	if( bIsHull )
	{
		fGoodsQ = GetCargoGoods(chref,GOOD_PLANKS);
		if( CheckAttribute(chref,"RepairMaterials.forHull") )
		{	fGoodsQ += stf(chref.RepairMaterials.forHull);
		}
	}
	else
	{
		fGoodsQ = GetCargoGoods(chref,GOOD_SAILCLOTH);
		if( CheckAttribute(chref,"RepairMaterials.forSails") )
		{	fGoodsQ += stf(chref.RepairMaterials.forSails);
		}
	}

	return fGoodsQ;
}

void RemoveRepairGoods(bool bIsHull, ref chref, float matQ)
{
	int nGoodsQ = 0;
	float fGoodsQ = GetRepairGoods(bIsHull,chref);

	if( bIsHull )
	{
		if(fGoodsQ<=matQ)	{ DeleteAttribute(chref,"RepairMaterials.forHull"); }
		else
		{
			fGoodsQ -= matQ;
			nGoodsQ = makeint(fGoodsQ);
			chref.RepairMaterials.forHull = fGoodsQ - nGoodsQ;
		}
		SetCharacterGoods(chref,GOOD_PLANKS,nGoodsQ);
	}
	else
	{
		if(fGoodsQ<=matQ)	{ DeleteAttribute(chref,"RepairMaterials.forSails"); }
		else
		{
			fGoodsQ -= matQ;
			nGoodsQ = makeint(fGoodsQ);
			chref.RepairMaterials.forSails = fGoodsQ - nGoodsQ;
		}
		SetCharacterGoods(chref,GOOD_SAILCLOTH,nGoodsQ);
	}

}

float GetRigDamage(int shootIdx, int iBallType, ref damage_chr)
{
	ref rBall = GetGoodByType(iBallType);
	float fDmgRig = stf(rBall.DamageRig);

	if( shootIdx>=0 )
	{
		ref shoot_chr = GetCharacter(shootIdx);
		if( IsCharacterPerkOn(shoot_chr,"CannonProfessional") )	{ fDmgRig *= 1.3; }
		else
		{
			if( IsCharacterPerkOn(shoot_chr,"SailsDamageUp") )	{ fDmgRig *= 1.15; }
		}
	}

	if( IsCharacterPerkOn(shoot_chr,"ShipDefenseProfessional") )	{ fDmgRig *= 0.6; }
	else
	{
		if( IsCharacterPerkOn(shoot_chr,"AdvancedBattleState") )	{ fDmgRig *= 0.75; }
		else
		{
			if( IsCharacterPerkOn(shoot_chr,"BasicBattleState") )	{ fDmgRig *= 0.85; }
		}
	}

	return fDmgRig;
}

void MakeSailDmg(int chrIdx, float dmg)
{
	object objSail;
	if( !FindClass(&objSail,"sail") ) return;
	SendMessage(&objSail,"lslf", MSG_SAIL_SCRIPT_PROCESSING,"RandomSailsDmg", chrIdx,dmg);
}

ref ProcessRandomSailDmg()
{
	BI_g_fRetVal = 0.0;
	//"lslfflll"
	int chrIdx = GetEventData();
	string nodeName = GetEventData();
	int grNum = GetEventData();
	float fDmg = GetEventData();
	float fSPow = GetEventData();
	int hc_new = GetEventData();
	int mhc = GetEventData();
	int hdat_new = GetEventData();

	if(chrIdx<0) return &BI_g_fRetVal;
	ref chref = GetCharacter(chrIdx);

	aref arSail;
	string groupName = ""+grNum;
	makearef(arSail,chref.ship.sails.(nodeName).(groupName));

	int hc_old = 0;
	if( CheckAttribute(arSail,"hc") )	hc_old = sti(arSail.hc);
	float fDmg_old = 0.0;
	if( CheckAttribute(arSail,"dmg") )	fDmg_old = stf(arSail.dmg);

	int itmp = hc_new;
	float sailDmgMax = GetCharacterShipSP(chref) * fSPow;

	float fTopDmg = sailDmgMax;
	if(itmp<mhc)	fTopDmg = GetNeedDmgFromHole(itmp+1,sailDmgMax,mhc) - 0.0001;
	if(fTopDmg>fDmg_old+fDmg)	fTopDmg = fDmg_old+fDmg;

	fDmg = fTopDmg-fDmg_old;
	if(fDmg<=0.0)	return &BI_g_fRetVal;
	chref.ship.SP = stf(chref.ship.SP)-fDmg;

	itmp = GetNeedHoleFromDmg(fTopDmg,sailDmgMax,mhc);
	if(itmp>hc_old)
	{
		BI_g_fRetVal = fDmg;
		arSail.hc = hc_new;
		arSail.hd = hdat_new;
	}
	else
	{
		BI_g_fRetVal = -fDmg;
		if( !CheckAttribute(arSail,"hc") )	arSail.hc = 0;
		if( !CheckAttribute(arSail,"hd") )	arSail.hd = 0;
	}

	arSail.mhc = mhc;
	arSail.sp = fSPow;
	arSail.dmg = fTopDmg;

	return &BI_g_fRetVal;
}

void procSetUsingAbility()
{
	int q;
	int chIdx = GetEventData();
	ref mainCh = GetMainCharacter();
	int mainIdx = sti(mainCh.index);
	aref aroot,arcur;
	string tmpStr;

	if( chIdx<0 || CharacterIsDead(GetCharacter(chIdx)) )
	{
		makearef(aroot,BattleInterface.AbilityIcons);
		q = GetAttributesNum(aroot);
		for(int i=0; i<q; i++)
		{
			arcur = GetAttributeN(aroot,i);
			arcur.enable = false;
		}
		return;
	}

	// для главного персонажа
	if(mainIdx==chIdx)
	{
		BattleInterface.AbilityIcons.Brander.enable			= false;
		BattleInterface.AbilityIcons.Troopers.enable		= false;

		BattleInterface.AbilityIcons.ImmediateReload.enable	= GetCharacterPerkUsing(mainCh,"ImmediateReload");
		BattleInterface.AbilityIcons.InstantBoarding.enable	= GetCharacterPerkUsing(mainCh,"InstantBoarding") && bAttack;

		BattleInterface.AbilityIcons.LightRepair.enable		= false;
		if(GetCharacterPerkUsing(mainCh,"LightRepair"))
		{	if(GetHullPercent(mainCh)<10.0 || GetSailPercent(mainCh)<10.0)
			{	BattleInterface.AbilityIcons.LightRepair.enable = true;
			}
		}
		BattleInterface.AbilityIcons.InstantRepair.enable	= CheckInstantRepairCondition(mainCh);
		BattleInterface.AbilityIcons.Turn180.enable			= GetCharacterPerkUsing(mainCh,"Turn180");
		BattleInterface.AbilityIcons.SandbankManeuver.enable= GetCharacterPerkUsing(mainCh,"SandbankManeuver");

		// Set items abilities
		q = FindQuestUsableItem(&arcur,0);
		while( q>0 )
		{
			tmpStr = arcur.id;
			if( GetCharacterItem(mainCh,arcur.id)>0 )
			{
				BattleInterface.AbilityIcons.(tmpStr).enable	= true;
				BattleInterface.AbilityIcons.(tmpStr).picNum	= arcur.quest.pic;
				BattleInterface.AbilityIcons.(tmpStr).texNum	= 9;
				BattleInterface.AbilityIcons.(tmpStr).event		= arcur.id;
				BattleInterface.AbilityIcons.(tmpStr).quest		= arcur.quest;
			}
			else
			{
				BattleInterface.AbilityIcons.(tmpStr).enable	= false;
			}
			q = FindQuestUsableItem(&arcur,q+1);
		}
	}

	else
	{
		BattleInterface.AbilityIcons.Brander.enable			= false;
		if(bAttack && GetRemovable(GetCharacter(chIdx)) && GetCharacterPerkUsing(mainCh,"Brander"))
			BattleInterface.AbilityIcons.Brander.enable		= true;

		BattleInterface.AbilityIcons.Troopers.enable		= GetCharacterPerkUsing(GetMainCharacter(),"Troopers");

		BattleInterface.AbilityIcons.ImmediateReload.enable	= false;
		BattleInterface.AbilityIcons.InstantBoarding.enable	= false;
		BattleInterface.AbilityIcons.LightRepair.enable		= false;
		BattleInterface.AbilityIcons.InstantRepair.enable	= false;
		BattleInterface.AbilityIcons.Turn180.enable			= false;
		BattleInterface.AbilityIcons.SandbankManeuver.enable= false;
	}
}

ref procCheckEnableLocator()
{
	BI_intRetValue = true;

	string comName = GetEventData();
	aref arLoc = GetEventData();

	if(comName=="BI_SailTo")
	{
		if( CheckAttribute(&AISea,"Island") && CheckAttribute(arLoc,"name") )
		{
			BI_intRetValue = Island_isGotoEnableLocal(AISea.Island,arLoc.name);
		}
	}

	return &BI_intRetValue;
}

ref procCheckEnableShip()
{
	BI_intRetValue = true;

	string comName = GetEventData();
	int cn = GetEventData();

	if(cn>=0)
	{
		switch(comName)
		{
		case "BI_InstantBoarding":
			BI_intRetValue = Character_IsAbordageEnable(GetCharacter(cn));
		break;
		}
	}

	return &BI_intRetValue;
}

void BI_ProcessControlPress()
{
	string ControlName = GetEventData();

	if(ControlName=="TimeScale")
	{
		if(IsPerkIntoList("TimeSpeed"))
		{
			SetTimeScale(1.0);
			DelPerkFromActiveList("TimeSpeed");
		}
		else
		{
			SetTimeScale(GetSeaTimeScale());
			AddPerkToActiveList("TimeSpeed");
		}
	}
}

ref procGetSRollSpeed()
{
	int chrIdx = GetEventData();
	BI_g_fRetVal = 0.0;
	if(chrIdx>=0) BI_g_fRetVal = GetRSRollSpeed(GetCharacter(chrIdx));
	return &BI_g_fRetVal;
}

float GetRSRollSpeed(ref chref)
{
	float fRollSpeed = 0.5 + 0.05 * makefloat( GetCharacterSkill(chref,SKILL_SAILING) );
	int crewQ = GetCrewQuantity(chref);
	int crewMin = GetMinCrewQuantity(chref);
	if(crewQ<crewMin) fRollSpeed *= makefloat(crewQ)/makefloat(crewMin);
	return fRollSpeed;
}

ref BI_GetLandData()
{
	string attrName;
	aref arLoc, arIsl, arList;
	arLoc = GetEventData();

	BI_intNRetValue[0] = 0;
	BI_intNRetValue[1] = BI_RELATION_NEUTRAL;
	BI_intNRetValue[2] = -1;
	BI_intNRetValue[3] = -1;

	if( CheckAttribute(arLoc,"fort.model") )
	{
		BI_intNRetValue[0] = 1;
		int chrIdx = Fort_FindCharacter(AISea.Island,"reload",arLoc.name);
		if(chrIdx>=0)
		{
			switch( SeaAI_GetRelation(chrIdx,GetMainCharacterIndex()) )
			{
			case RELATION_FRIEND:	BI_intNRetValue[1] = BI_RELATION_FRIEND;	break;
			case RELATION_NEUTRAL:	BI_intNRetValue[1] = BI_RELATION_NEUTRAL;	break;
			case RELATION_ENEMY:	BI_intNRetValue[1] = BI_RELATION_ENEMY;		break;
			}
		}
	}

	if( CheckAttribute(arLoc,"tex") && CheckAttribute(arLoc,"pic") )
	{
		makearef( arIsl, Islands[FindIsland(AISea.Island)] );
		attrName = "InterfaceTextures." + arLoc.tex;
		if( CheckAttribute(arIsl,attrName) )
		{
			BI_intNRetValue[2] = AddTextureToList( &BattleInterface, arIsl.(attrName), sti(arIsl.(attrName).h), sti(arIsl.(attrName).v) );
			BI_intNRetValue[3] = sti(arLoc.pic);
		}
	}

	if( CheckAttribute(arLoc,"label") ) {
		arLoc.labelLoc = LanguageConvertString(g_LocLngFileID,arLoc.label);
		if( arLoc.labelLoc == "" ) {
			Trace("Warning! Language: string <"+arLoc.label+"> hav`t translation into file <LocLables.txt>");
		}
	}

	// Заглушка
	if( BI_intNRetValue[2]<0 || BI_intNRetValue[3]<0 )
	{
		BI_intNRetValue[2] = AddTextureToList( &BattleInterface, "battle_interface\cicons_locators.tga", 4, 1 );
		if( BI_intNRetValue[0]==0 ) {
			BI_intNRetValue[3] = 0;
		} else {
			BI_intNRetValue[3] = 1;
		}
	}

	return &BI_intNRetValue;
}

int GetTargChrIndex(int targNum, string locName)
{
	if(targNum==-1) {
		return Fort_FindCharacter(AISea.Island,"reload",locName);
	} else {
		return targNum;
	}
}

bool CheckSuccesfullBoard(ref rBoarderChr, ref rSieger)
{
	// skill = 1 -> k = 0.5; skill = 10 -> k = 2.0
	float k = 0.333 + GetSummonSkillFromName(rBoarderChr, SKILL_SNEAK)*0.167;

	// skill = 1 -> limit = 0.45 -> 0.2^0.5 (20%);   skill = 10 -> limit = 0.81 -> 0.9^2 (90%)
	float topLimit = 0.41 + GetSummonSkillFromName(rBoarderChr, SKILL_GRAPPLING)*0.04;

	if( pow(rand(1000)/1000.0, k) < topLimit ) return true;
	return false;
}

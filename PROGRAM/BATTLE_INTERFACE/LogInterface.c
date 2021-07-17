#include "battle_interface\log_msg.h"

#define LOG_FOR_SEA		1
#define LOG_FOR_LAND	2

object showWindow;

object ILogAndActions;
object IBoardingStatus;
bool   bYesBoardStatus;
string g_ActiveActionName;

#event_handler("blieGetMsgIconRoot","BI_GetMsgIconRoot");

void InitLogInterface()
{
	SetEventHandler("SetWindowSize","LI_SetWindowSize",0);
	CreateEntity(&ILogAndActions,"ILogAndActions");
	DelEventHandler("SetWindowSize","LI_SetWindowSize");
	DeleteAttribute(&ILogAndActions,"");
	CreateLogEnvironment();
	SendMessage(&ILogAndActions,"lll",LOG_AND_ACTIONS_INIT,sti(InterfaceStates.BattleShow.FastCommand),sti(InterfaceStates.BattleShow.LogString));
	SetEventHandler(EVENT_LOCATION_LOAD,"LI_LocationLoad",0);
	SetEventHandler("BI_FastCommand","BI_FastCommand",0);
	SetEventHandler(BI_EVENT_SET_VISIBLE,"SetLogInterfaceVisible",0);
	LayerAddObject("execute",&ILogAndActions,-257);
	LayerAddObject("realize",&ILogAndActions,-257);
	LayerAddObject(SEA_EXECUTE,&ILogAndActions,-257);
	LayerAddObject(SEA_REALIZE,&ILogAndActions,-257);

	InitActivePerkShower();
}

void LI_SetWindowSize()
{
	int w = GetEventData();
	int h = GetEventData();
	int bTVused = GetEventData();
	if(bTVused)	SetShowWindowParameters(bTVused,w,h,40,24,w-40,h-24);
	else	SetShowWindowParameters(bTVused,w,h,0,0,w,h);
}

void SetLogInterfaceVisible()
{
	int visibleFlag = GetEventData();
	SendMessage(&ILogAndActions,"ll",LI_SET_VISIBLE,visibleFlag);
}

void LI_LocationLoad()
{
	CreateILogAndActions(LOG_FOR_LAND);
}

void InitBattleInterfacesParameters()
{
	DeleteClass(&IBoardingStatus);
	DeleteAttribute(&IBoardingStatus,"");
	bYesBoardStatus = false;
}

void CreateILogAndActions(int loadType)
{
	DeleteAttribute(&IBoardingStatus,"ActiveActions");
	if(loadType==LOG_FOR_SEA)
	{
		CreateSeaActionsEnvironment();
	}
	if(loadType==LOG_FOR_LAND)
	{
		CreateLandActionsEnvironment();
	}
	SendMessage(&ILogAndActions,"lll",LOG_AND_ACTIONS_CHANGE,sti(InterfaceStates.BattleShow.FastCommand),sti(InterfaceStates.BattleShow.LogString));
	Log_SetActiveAction(g_ActiveActionName);
}

void Log_SetActiveAction(string actionName)
{
	g_ActiveActionName = actionName;
	SendMessage(&ILogAndActions,"ls",LOG_SET_ACTIVE_ACTION,actionName);
}

void Log_SetStringToLog(string strLog)
{
	SendMessage(&ILogAndActions,"lls",LOG_ADD_STRING, false, strLog);
}

void Log_SetEternalString(string strLog)
{
	SendMessage(&ILogAndActions,"lls",LOG_ADD_STRING, true, strLog);
}

void CreateLogEnvironment()
{
	ILogAndActions.Log.width = sti(showWindow.sw)/2;
	ILogAndActions.Log.height = sti(showWindow.sh)-80;
	ILogAndActions.Log.left = sti(showWindow.left)+88;
	ILogAndActions.Log.up = sti(showWindow.top)+16;
	ILogAndActions.Log.font = "interface_normal";
	ILogAndActions.Log.color = argb(0,255,255,255);
	ILogAndActions.Log.offsetString = 24;
	ILogAndActions.Log.speed = 0.05;
	ILogAndActions.Log.color_speed = 0.02;
}

void CreateSeaActionsEnvironment()
{
	ILogAndActions.ActiveActions.TextureName = "battle_interface\cicons_command.tga";
	ILogAndActions.ActiveActions.horzQ = 8;
	ILogAndActions.ActiveActions.vertQ = 4;
	ILogAndActions.ActiveActions.width = RecalculateHIcon(64);
	ILogAndActions.ActiveActions.height = RecalculateVIcon(64);
	ILogAndActions.ActiveActions.left = sti(showWindow.left)+16;
	ILogAndActions.ActiveActions.top = sti(showWindow.top)+16;

	ILogAndActions.ActiveActions.Moor.IconNum		= 1;
	ILogAndActions.ActiveActions.Board.IconNum		= 2;
	ILogAndActions.ActiveActions.LandTroops.IconNum	= 8;
	ILogAndActions.ActiveActions.Map.IconNum		= 9;
	ILogAndActions.ActiveActions.Reload.IconNum		= 10;
	ILogAndActions.ActiveActions.Nothing.IconNum	= -1;
}

void CreateLandActionsEnvironment()
{
	ILogAndActions.ActiveActions.TextureName = "battle_interface\land_fast_commands.tga";
	ILogAndActions.ActiveActions.horzQ = 8;
	ILogAndActions.ActiveActions.vertQ = 1;
	ILogAndActions.ActiveActions.width = RecalculateHIcon(64);
	ILogAndActions.ActiveActions.height = RecalculateVIcon(64);
	ILogAndActions.ActiveActions.left = sti(showWindow.left)+16;
	ILogAndActions.ActiveActions.top = sti(showWindow.top)+16;

	ILogAndActions.ActiveActions.ToSea.IconNum		= 5;
	ILogAndActions.ActiveActions.Talk.IconNum		= 4;
	ILogAndActions.ActiveActions.Look.IconNum		= 3;
	ILogAndActions.ActiveActions.Pick.IconNum		= 2;
	ILogAndActions.ActiveActions.Action.IconNum		= 2;
	ILogAndActions.ActiveActions.OpenBox.IconNum	= 2;
	ILogAndActions.ActiveActions.Reload.IconNum		= 1;
	ILogAndActions.ActiveActions.Closed.IconNum		= 0;
	ILogAndActions.ActiveActions.Nothing.IconNum	= -1;
}

void DrawCharacterHP(float myHP,float enemyHP)
{
	if(bYesBoardStatus==false)
	{
		CreateEntity(&IBoardingStatus,"IBoardingStatus");
		IBoardingStatus.myLeft = sti(showWindow.left)+16;
		IBoardingStatus.myTop = sti(showWindow.bottom)-140;
		IBoardingStatus.enemyLeft = sti(showWindow.left)+16;
		IBoardingStatus.enemyTop = sti(showWindow.bottom)-128;
		IBoardingStatus.height = RecalculateVIcon(8);
		IBoardingStatus.width = RecalculateHIcon(120);
		IBoardingStatus.myColor = argb(255,0,0,128);
		IBoardingStatus.enemyColor = argb(255,128,0,0);
		SendMessage(&IBoardingStatus,"l",LOG_INIT_CHARCTER_HP);
		bYesBoardStatus = true;
	}
	if(myHP==0)
	{
		bYesBoardStatus=false;
		DeleteClass(&IBoardingStatus);
		DeleteAttribute(&IBoardingStatus,"");
	}
	if(enemyHP==0)
	{
		bYesBoardStatus=false;
		DeleteClass(&IBoardingStatus);
		DeleteAttribute(&IBoardingStatus,"");
	}
	SendMessage(&IBoardingStatus,"lff",LOG_SET_CHARCTER_HP,myHP,enemyHP);
}

void BI_FastCommand()
{
	int tmpi;
	string FComName = GetEventData();

	if( LAi_IsDead(GetMainCharacter()) ) return;

	if(bSeaActive && !bAbordageStarted)
	{
		switch(FComName)
		{
		case "Moor":		Sea_LandLoad();	break;
		case "Board":		Sea_AbordageLoad(SHIP_ABORDAGE,true);	break;
		case "LandTroops":	Sea_AbordageLoad(FORT_ABORDAGE,true);	break;
		case "Map":			Sea_MapLoad();	break;
		case "Reload":
			if(bi_nReloadTarget!=-1)
			{
				LaunchTransferMain(GetMainCharacter(),GetCharacter(bi_nReloadTarget),"");
			}
		break;
		}
	}
	else
	{
		if(CheckAttribute(GetMainCharacter(),"Quests.quest_act"))
		{
			Event("evntQuestComplete","s",Characters[GetMainCharacterIndex()].Quests.quest_act);
			return;
		}
		switch(FComName)
		{
		case "OpenBox":	OpenBoxProcedure();	break;
		case "Pick": Item_OnPickItem(); break;
		case "Action": Item_OnUseItem(); break;
		case "Talk":
			tmpi = SendMessage(GetMainCharacter(),"ls",MSG_CHARACTER_EX_MSG,"FindDialogCharacter");
			if(tmpi>=0)	Event("dlgReady","l",tmpi);
		break;
		case "Reload": Event("Control Activation","s","ChrAction"); break;
		//case "Closed": break;
		//case "Look": break;
		case "ToSea": Event("Control Activation","s","ChrAction"); break;
		}
	}
}

void ClearAllLogStrings()
{
	SendMessage(&ILogAndActions,"l",LI_CLEAR_STRINGS);
}

void BI_GetMsgIconRoot()
{
	aref arTmp;
	aref pARef[4];
	int i,idx,cn;
	idx = 0;

	if(bSeaActive && !bAbordageStarted)
	{
		for(i=0; i<4; i++)
		{
			cn = GetCompanionIndex(GetMainCharacter(),i);
			if(cn<0) {continue;}
			Characters[cn].MessageIcons = true;
			makearef(arTmp,Characters[cn].MessageIcons);
			pARef[idx] = arTmp;
			idx++;
		}
		SendMessage(&BattleInterface,"le", BI_MSG_SET_MSG_ICONS, &pARef);
	}


	else
	{
		for(i=0; i<4; i++)
		{
			cn = GetOfficersIndex(GetMainCharacter(),i);
			if(cn<0) {continue;}
			Characters[cn].MessageIcons = true;
			makearef(arTmp,Characters[cn].MessageIcons);
			pARef[idx] = arTmp;
			idx++;
		}
		SendMessage(&objLandInterface,"le", MSG_BATTLE_LAND_SET_MSGICONS, &pARef);
	}
}

void LoadLIStates()
{
	if(GetMainCharacterIndex()<0) return;
	int i,cn;
	ref mc = GetMainCharacter();
	ref chref;

	DeleteAttribute(mc,"MessageIcons");
	for(i=1; i<4; i++)
	{
		cn = GetOfficersIndex(mc,i);
		if(cn>=0)
		{
			chref = GetCharacter(cn);
			DeleteAttribute(chref,"MessageIcons");
		}
		cn = GetCompanionIndex(mc,i);
		if(cn>=0)
		{
			chref = GetCharacter(cn);
			DeleteAttribute(chref,"MessageIcons");
		}
	}
}

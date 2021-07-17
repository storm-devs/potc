#include "interface\messages.h"
#include "interface\utilite.c"
#include "interface\perks\perks.c"

#define FONT_NORMAL	"interface_normal"
#define FONT_BOLD_NUMBERS	"bold_numbers"

#define COLOR_DESELECT	4286611584
#define COLOR_NORMAL	4294967295
#define COLOR_MONEY		4292915296

#define MONEY_SIGN		""
#define MONEY_DELIVER	"."

#event_handler("LaunchIAfterFrame","ILaunchAfterFrame");
#event_handler("ievent_GameOver","IProcEventGameOver");
#event_handler("ievent_SetGameTime","IProcEventSetGameTime");
#event_handler("evntPreLoad","procPreLoad");

#event_handler("FaderEvent_StartFade","ProcBreakInterface");
#event_handler("FaderEvent_StartFadeIn","ProcBreakInterface");
#event_handler("FaderEvent_EndFade","ProcBreakInterface");
#event_handler("FaderEvent_EndFadeIn","ProcBreakInterface");

#event_handler("Fader_GetTipsPath","procGetTipsPath");
#event_handler("Fader_GetFaderPicture","procGetFaderPicture");

#event_handler("evntOptionsBreak","procOptionsBreak");

bool EnableVideoBreak = false;

int CurrentInterface;
int gStoreNum;

extern void InitInterface(string iniFile);
extern void InitInterface_R(string iniFile, ref rParam);
extern void InitInterface_RR(string iniFile, ref rParam1, ref rParam2);
extern void InitInterface_S(string iniFile, string sParam1);
extern void InitInterface_RS(string iniFile, ref rParam1, string sParam2);
extern void InitInterface_I(string iniFile, int iParam1);
extern void InitInterface_B(string iniFile, bool bParam1);
extern void InitInterface_RRS(string iniFile, ref rParam1, ref rParam2, string sParam3);

extern ref GetMyCharacterRef();
extern ref GetEnemyCharacterRef();
string ICurNode;
int	   nPrevInterface;

bool bGamePadChangeEnable = false;
bool bPlayVideoNow = false;
bool bMainMenuLaunchAfterVideo = false;

void LaunchLanguageSelect()
{
	if(procInterfacePrepare(INTERFACE_LANGUAGESET))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_LANGUAGESET;
		InitInterface(Interfaces[CurrentInterface].IniFile);
	}
}

void LaunchEndGameMenu()
{
	if(procInterfacePrepare(INTERFACE_ENDGAME))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_ENDGAME;
		InitInterface(Interfaces[CurrentInterface].IniFile);
	}
}

void LaunchPlayGame(ref chref)
{
	if(procInterfacePrepare(INTERFACE_PLAYGAME))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_PLAYGAME;
		InitInterface_R(Interfaces[CurrentInterface].IniFile, chref);
	}
}

void LaunchSalayScreen()
{
	if(procInterfacePrepare(INTERFACE_SALARY))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_SALARY;
		InitInterface(Interfaces[CurrentInterface].IniFile);
	}
}

void LaunchPerksScreen(ref chref)
{
	if(procInterfacePrepare(INTERFACE_PERKS))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_PERKS;
		InitInterface_R(Interfaces[CurrentInterface].IniFile,chref);
	}
}

void LaunchControlsScreen()
{
	if(procInterfacePrepare(INTERFACE_CONTROLS))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_CONTROLS;
		InitInterface(Interfaces[CurrentInterface].IniFile);
	}
}

void LaunchItemsTrade(ref chref)
{
	if(procInterfacePrepare(INTERFACE_ITEMSTRADE))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_ITEMSTRADE;
		InitInterface_RR(Interfaces[CurrentInterface].IniFile,GetMainCharacter(),chref);
	}
}

void LaunchSelectMenu()
{
	if( curKeyGroupName=="WorldMapControls" || curKeyGroupName=="FightModeControls" ) return;
	if( sti(InterfaceStates.Buttons.Resume.enable)==false ) return;
	bool bDisable = false;
	if( !IsEnableMenuLaunch() ) bDisable = true;
	if( bSeaActive && bAbordageStarted ) bDisable = true;
	if( bDisable )
	{
		Log_SetStringToLog(XI_ConvertString("You can`t launch menu"));
		return;
	}
	if(procInterfacePrepare(INTERFACE_SELECTMENU))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_SELECTMENU;
		InitInterface(Interfaces[CurrentInterface].IniFile);
		if(CheckAttribute(&InterfaceStack,"SelectMenu_node"))
		{
			SetCurrentNode(InterfaceStack.SelectMenu_node);
		}
	}
}

void LaunchOptionScreen()
{
	if(procInterfacePrepare(INTERFACE_OPTIONSCREEN))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_OPTIONSCREEN;
		InitInterface(Interfaces[CurrentInterface].IniFile);
	}
}

void LaunchHelpScreen(string help_section)
{
	if(procInterfacePrepare(INTERFACE_HELPSCREEN))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_HELPSCREEN;
		InitInterface_S(Interfaces[CurrentInterface].IniFile,help_section);
	}
}

void LaunchCharacterItemChange(ref chref)
{
	if(procInterfacePrepare(INTERFACE_ITEMSBOX))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_ITEMSBOX;
		aref charef; makearef(charef,chref);
		InitInterface_RS(Interfaces[CurrentInterface].IniFile,&charef,chref.FaceID);
	}
}

void LaunchItemsBox(ref boxRef)
{
	if(procInterfacePrepare(INTERFACE_ITEMSBOX))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_ITEMSBOX;
		InitInterface_RS(Interfaces[CurrentInterface].IniFile,boxRef,"");
	}
}

void LaunchFortCapture(ref chref)
{
	if(procInterfacePrepare(INTERFACE_FORTCAPTURE))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_FORTCAPTURE;
		InitInterface_R(Interfaces[CurrentInterface].IniFile,chref);
	}
}

void LaunchShipState()
{
	if(procInterfacePrepare(INTERFACE_SHIP_CHOOSE))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_SHIP_CHOOSE;
		InitInterface_I(Interfaces[CurrentInterface].IniFile,true);
	}
}

void LaunchStore(int storeNum)
{
    if(storeNum<0)	return;
    if(storeNum>STORE_QUANTITY-1)	return;
	gStoreNum=storeNum;
	if(procInterfacePrepare(INTERFACE_SHIP_CHOOSE))
	{
		nPrevInterface = INTERFACE_STORE;
		CurrentInterface = INTERFACE_SHIP_CHOOSE;
		InitInterface_I(Interfaces[CurrentInterface].IniFile,false);
	}
}

void LaunchShipyard(ref shipmaster)
{
	if(procInterfacePrepare(INTERFACE_SHIPYARD))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_SHIPYARD;
		InitInterface_R(Interfaces[CurrentInterface].IniFile,shipmaster);
	}
}

void LaunchCannons()
{
	if(procInterfacePrepare(INTERFACE_CANNONS))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_CANNONS;
		InitInterface(Interfaces[CurrentInterface].IniFile);
	}
}

void LaunchCharacter(ref refCharacter)
{
	if(procInterfacePrepare(INTERFACE_CHARACTER))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_CHARACTER;
		InitInterface_R(Interfaces[CurrentInterface].IniFile,refCharacter);
	}
}

void LaunchMainMenu_afterVideo()
{
	DelEventHandler(EVENT_END_VIDEO,"LaunchMainMenu_afterVideo");
	InterfaceStates.LaunchAnyway = true;
	LaunchMainMenu();
}

void LaunchMainMenu()
{
	if(procEnableInterfaceLaunch(INTERFACE_MAINMENU)==false)
	{
		if( CheckAttribute(&InterfaceStates,"LaunchAnyway") && sti(InterfaceStates.LaunchAnyway)==true )
		{
			PostEvent("LaunchIAfterFrame",1,"sl","I_MAINMENU",1);
			InterfaceStates.LaunchAfterFrame = "I_MAINMENU";
		}
		return;
	}
	DeleteAttribute(&InterfaceStates,"LaunchAnyway");
	if(g_ibVideoExecuting) return;
	InterfaceStates.Launched = true;
	InterfaceStates.doUnFreeze = false;

	SetEventHandler("makescrshot","LaunchMainMenuContinue",0);
	if( !CheckAttribute(&InterfaceStates,"MakeScreenShot") || sti(InterfaceStates.MakeScreenShot)==true )
	{
		DeleteEntitiesByType("scrshoter");
		object scrshoter;
		LayerCreate("realize",1);
		LayerSetRealize("realize",1);
		CreateEntity(&scrshoter,"scrshoter");
		scrshoter.SavePath = "SAVE";
		LayerAddObject(SEA_REALIZE,&scrshoter,-1);
		LayerAddObject("realize",&scrshoter,-1);
		if(!IsEntity(scrshoter)) PostEvent("makescrshot",1);
		else PostEvent("makescrshot",1);
	}
	else Event("makescrshot");
}

void LaunchMainMenuContinue()
{
	DelEventHandler("makescrshot","LaunchMainMenuContinue");
	DeleteAttribute(&InterfaceStates,"MakeScreenShot");
	ISetSoundEvents();
	nPrevInterface = -1;
    CurrentInterface = INTERFACE_MAINMENU;
	EngineLayersOffOn(false);

	bGamePadChangeEnable = true;
    LoadSegment(Interfaces[CurrentInterface].SectionName);
    InitInterface(Interfaces[CurrentInterface].IniFile);
	SetTimeScale(1.0);
}

void LaunchSaveGame()
{
	if(procInterfacePrepare(INTERFACE_SAVELOAD))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_SAVELOAD;
		InitInterface_B(Interfaces[CurrentInterface].IniFile,true);
	}
}

void LaunchLoadGame()
{
	if(procInterfacePrepare(INTERFACE_SAVELOAD))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_SAVELOAD;
		InitInterface_B(Interfaces[CurrentInterface].IniFile,false);
	}
}

void LaunchShipHold()
{
	if(procInterfacePrepare(INTERFACE_SHIPHOLD))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_SHIPHOLD;
		InitInterface(Interfaces[CurrentInterface].IniFile);
	}
}

void LaunchHireCrew()
{
	if(procInterfacePrepare(INTERFACE_HIRECREW))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_HIRECREW;
		InitInterface(Interfaces[CurrentInterface].IniFile);
	}
}

void LaunchPassengers(ref _refCharacter)
{
	if(procInterfacePrepare(INTERFACE_PASSENGERS))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_PASSENGERS;
		InitInterface_R(Interfaces[CurrentInterface].IniFile,_refCharacter);
	}
}

void LaunchRansackJoin(ref _refMy,ref _refEnemy)
{
	if(procInterfacePrepare(INTERFACE_RANSACK_JOIN))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_RANSACK_JOIN;
		InitInterface_RR(Interfaces[CurrentInterface].IniFile,_refMy,_refEnemy);
	}
}

void LaunchRansackCrew(ref _refMy,ref _refEnemy)
{
	if(procInterfacePrepare(INTERFACE_RANSACK_CREW))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_RANSACK_CREW;
		InitInterface_RR(Interfaces[CurrentInterface].IniFile,_refMy,_refEnemy);
	}
}

void LaunchRansackCaptain(ref _refMy,ref _refEnemy)
{
	if(procInterfacePrepare(INTERFACE_RANSACK_CAPTAIN))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_RANSACK_CAPTAIN;
		InitInterface_RR(Interfaces[CurrentInterface].IniFile,_refMy,_refEnemy);
	}
}

void LaunchRansackMain(ref _refMy,ref _refEnemy,string newCurNod)
{
	if(procInterfacePrepare(INTERFACE_RANSACK_MAIN))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_RANSACK_MAIN;
		InitInterface_RRS(Interfaces[CurrentInterface].IniFile,_refMy,_refEnemy,newCurNod);
	}
}

void LaunchTransferMain(ref _refMy,ref _refEnemy,string newCurNod)
{
	if(procInterfacePrepare(INTERFACE_TRANSFER_MAIN))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_TRANSFER_MAIN;
		InitInterface_RRS(Interfaces[CurrentInterface].IniFile,_refMy,_refEnemy,newCurNod);
	}
}

void LaunchTransferGoods(ref _refMy,ref _refOther)
{
	if(procInterfacePrepare(INTERFACE_TRANSFER_GOODS))
	{
		nPrevInterface = CurrentInterface;
		CurrentInterface = INTERFACE_TRANSFER_GOODS;
		InitInterface_RR(Interfaces[CurrentInterface].IniFile,_refMy,_refOther);
	}
}

void LaunchTransferCharacter(ref _refMy,ref _refEnemy)
{
	if(procInterfacePrepare(INTERFACE_TRANSFER_CHARACTER))
	{
		nPrevInterface = CurrentInterface;
		CurrentInterface = INTERFACE_TRANSFER_CHARACTER;
		InitInterface_RR(Interfaces[CurrentInterface].IniFile,_refMy,_refEnemy);
	}
}

void LaunchTransferCrew(ref _refMy,ref _refEnemy)
{
	if(procInterfacePrepare(INTERFACE_TRANSFER_CREW))
	{
		nPrevInterface = CurrentInterface;
		CurrentInterface = INTERFACE_TRANSFER_CREW;
		InitInterface_RR(Interfaces[CurrentInterface].IniFile,_refMy,_refEnemy);
	}
}

void LaunchQuestBook()
{
	if(procInterfacePrepare(INTERFACE_QUESTBOOK))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_QUESTBOOK;
		InitInterface(Interfaces[CurrentInterface].IniFile);
	}
}

void LaunchTradeBook()
{
	if(procInterfacePrepare(INTERFACE_TRADEBOOK))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_TRADEBOOK;
		InitInterface(Interfaces[CurrentInterface].IniFile);
	}
}

void LaunchNationRelation()
{
	if(procInterfacePrepare(INTERFACE_NATIONRELATION))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_NATIONRELATION;
		InitInterface(Interfaces[CurrentInterface].IniFile);
	}
}

void LaunchItems()
{
	if(procInterfacePrepare(INTERFACE_ITEMS))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_ITEMS;
		InitInterface(Interfaces[CurrentInterface].IniFile);
	}
}

void LaunchSelectCharacter()
{
	//if(procEnableInterfaceLaunch(INTERFACE_CHARACTER_SELECT)==false) return;
	//InterfaceStates.Launched = true;
	//InterfaceStates.doUnFreeze = false;
	//EngineLayersOffOn(false);

	SetEventHandler(EVENT_END_VIDEO,"ISTART_SelCharacter",0);
	PostEvent(EVENT_END_VIDEO,0);
	//StartVideo("3Ship");
}

void ISTART_SelCharacter()
{
	DelEventHandler(EVENT_END_VIDEO,"ISTART_SelCharacter");
	//ISetSoundEvents();
	//nPrevInterface = -1;
    //CurrentInterface = INTERFACE_CHARACTER_SELECT;
    //LoadSegment(Interfaces[CurrentInterface].SectionName);
    //InitInterface(Interfaces[CurrentInterface].IniFile);
	SetMainCharacterIndex(0);
	interfaceResultCommand = RC_INTERFACE_CHARACTER_SELECT_EXIT;
	Start_InterfaceDoExit();
}

void EndOkInterface()
{
    UnloadSegment(Interfaces[CurrentInterface].SectionName);

	if(nPrevInterface == INTERFACE_STORE)
	{
		int cn = GetCompanionIndex(GetMainCharacter(),sti(GameInterface.FourImage.current));
		if(cn!=-1)
		{
			DeleteAttribute(&GameInterface,"");
			CurrentInterface = INTERFACE_STORE;
			LoadSegment(Interfaces[CurrentInterface].SectionName);
			InitInterface_RR(Interfaces[CurrentInterface].IniFile,GetCharacter(cn),&stores[gStoreNum]);
		}
		else
		{
			IDeleteSoundEvents();
			Start_InterfaceDoExit();
		}
	}
	else
	{
		IDeleteSoundEvents();
	    Start_InterfaceDoExit();
	}
}

void EndCancelInterface(bool bYesRelease)
{
	ref refObj1,refObj2;
	bGamePadChangeEnable = false;
	switch(interfaceResultCommand)
	{
	case RC_INTERFACE_RANSACK_JOIN_EXIT: refObj1 = GetMyCharacterRef(); refObj2 = GetEnemyCharacterRef(); break;
	case RC_INTERFACE_RANSACK_CREW_EXIT: refObj1 = GetMyCharacterRef(); refObj2 = GetEnemyCharacterRef(); break;
	case RC_INTERFACE_RANSACK_CAPTAIN_EXIT: refObj1 = GetMyCharacterRef(); refObj2 = GetEnemyCharacterRef(); break;
	case RC_INTERFACE_TRANSFER_START_GOODS: refObj1 = GetMyCharacterRef(); refObj2 = GetEnemyCharacterRef(); ICurNode = GetCurrentNode(); break;
	case RC_INTERFACE_TRANSFER_START_CHARACTERS: refObj1 = GetMyCharacterRef(); refObj2 = GetEnemyCharacterRef(); ICurNode = GetCurrentNode(); break;
	case RC_INTERFACE_TRANSFER_START_CREW: refObj1 = GetMyCharacterRef(); refObj2 = GetEnemyCharacterRef(); ICurNode = GetCurrentNode(); break;
	case RC_INTERFACE_TRANSFER_MAIN_RETURN: refObj1 = GetMyCharacterRef(); refObj2 = GetEnemyCharacterRef(); break;
	}
	InterfaceStates.doUnFreeze = bYesRelease;
    UnloadSegment(Interfaces[CurrentInterface].SectionName);
	IDeleteSoundEvents();
	switch(interfaceResultCommand)
	{
	case RC_INTERFACE_RANSACK_JOIN_EXIT: InterfaceStates.Launched=false; LaunchRansackCrew(refObj1,refObj2); return; break;
	case RC_INTERFACE_RANSACK_CREW_EXIT: InterfaceStates.Launched=false; LaunchRansackCaptain(refObj1,refObj2); return; break;
	case RC_INTERFACE_RANSACK_CAPTAIN_EXIT: InterfaceStates.Launched=false; LaunchRansackMain(refObj1,refObj2,""); return; break;
	case RC_INTERFACE_TRANSFER_START_GOODS: InterfaceStates.Launched=false; LaunchTransferGoods(&Characters[sti(refObj1.index)],&Characters[sti(refObj2.index)]); return; break;
	case RC_INTERFACE_TRANSFER_START_CHARACTERS: InterfaceStates.Launched=false; LaunchTransferCharacter(refObj1,refObj2); return; break;
	case RC_INTERFACE_TRANSFER_START_CREW: InterfaceStates.Launched=false; LaunchTransferCrew(refObj1,refObj2); return; break;
	case RC_INTERFACE_TRANSFER_MAIN_RETURN:
		if(nPrevInterface==INTERFACE_RANSACK_MAIN)
		{
			InterfaceStates.Launched=false; LaunchRansackMain(refObj1,refObj2,ICurNode);
		}
		else
		{
			InterfaceStates.Launched=false; LaunchTransferMain(refObj1,refObj2,ICurNode);
		}
		return;
		break;
	}
    Start_InterfaceDoExit();
	if(bYesRelease)	PostEvent("evntQuestsCheck",1);
}

// стек для вложенных интерфейсов
object InterfaceStack;
void ClearInterfaceStack()
{
	DeleteAttribute(InterfaceStack,"");
	InterfaceStack.size=0;
}
void PushInterface(int iIndex,string iTitle,string iStartNod)
{
	if(!CheckAttribute(&InterfaceStack,"size"))	InterfaceStack.size = 0;
	string StackSlot = "Slot"+InterfaceStack.size;
	InterfaceStack.(StackSlot).index = iIndex;
	InterfaceStack.(StackSlot).title = iTitle;
	InterfaceStack.(StackSlot).start = iStartNod;
	InterfaceStack.size = sti(InterfaceStack.size)+1;
}
bool PopInterface()
{
	if(!CheckAttribute(&InterfaceStack,"size"))	InterfaceStack.size = 0;
	if(sti(InterfaceStack.size)<1) return false;
	InterfaceStack.size = sti(InterfaceStack.size)-1;
	string StackSlot = "Slot"+InterfaceStack.size;
	CurrentInterface = sti(InterfaceStack.(StackSlot).index);
	switch(CurrentInterface)
	{
	case INTERFACE_STORE:
		break;
	case INTERFACE_RANSACK_MAIN:
		break;
	case INTERFACE_TRANSFER_MAIN:
		break;
	}
	DeleteAttribute(&InterfaceStack,StackSlot);
	return true;
}
void I_PushString(string str)
{
	aref arStrStack;
	makearef(arStrStack,InterfaceStack.strings);
	int q = GetAttributesNum(arStrStack);
	string stackSlotName = "s"+q;
	InterfaceStack.strings.(stackSlotName) = str;
}
string I_PopString()
{
	aref arStrStack;
	makearef(arStrStack,InterfaceStack.strings);
	int q = GetAttributesNum(arStrStack)-1;
	if(q<0) return "";
	string stackSlotName = "s"+q;
	string retStr = InterfaceStack.strings.(stackSlotName);
	DeleteAttribute(&InterfaceStack,"strings."+stackSlotName);
	return retStr;
}

void ISetSoundEvents()
{
	SetEventHandler(ISOUND_EVENT,"IDoSoundEvent",0);
}
void IDeleteSoundEvents()
{
	DelEventHandler(ISOUND_EVENT,"IDoSoundEvent");
}
void IDoSoundEvent()
{
	int comCode = GetEventData();
	if(comCode=="ACTION_DEACTIVATE")
	{
		PlaySound("interface\cancel.wav");
	}
	else
	{
		PlaySound("interface\ok.wav");
	}
}

//#event_handler("evntPostVideo","stPostVideo");
object aviVideoObj;
void StartPostVideo(string vidName,int n)
{
	SetEventHandler("evntPostVideo","stPostVideo",0);
	PostEvent("evntPostVideo",n,"s",vidName);
}
void stPostVideo()
{
	DelEventHandler("evntPostVideo","stPostVideo");
	string sVidName = GetEventData();
	StartVideo(sVidName);
}
void PostVideoAndQuest(string vidName,int n,string sQuestName)
{
	aviVideoObj.afterQuestName = sQuestName;
	StartPostVideo(vidName,n);
}
bool g_ibVideoExecuting = false;
void StartVideo(string vidName)
{
	if(IsEntity(&aviVideoObj))
	{
		DeleteClass(&aviVideoObj);
		StartPostVideo(vidName,1);
	}
	g_ibVideoExecuting = true;
	PauseAllSounds();
	ResetSoundScheme();
	if(sti(InterfaceStates.Launched))
	{
		InterfaceStates.InstantExit = true;
		Event("exitCancel");
		DeleteAttribute(&InterfaceStates,"InstantExit");
	}
	SetEventHandler("ievntEndVideo","_Procedure_EndVideoPlay",0);
	EngineLayersOffOn(false);
	if(bSeaActive && !bAbordageStarted)
	{
		aviVideoObj.layer = "sea";
	}
	else
	{
		aviVideoObj.layer = "land";
	}
	if( GetTargetPlatform()=="pc" )	{CreateEntity(&aviVideoObj,"CAviPlayer");}
	else	{CreateEntity(&aviVideoObj,"WMVideoPlay");}
	SendMessage(&aviVideoObj,"ls",MSG_SET_VIDEO_PLAY,GetVideoFileName(vidName));
	bGamePadChangeEnable = true;
	bPlayVideoNow = true;

	if( vidName=="Artefact" ||
		vidName=="BlackPearl" ||
		vidName=="Ending" ||
		vidName=="Invasion" ||
		vidName=="Temple"
		) {bBreakVideoDisable = true;}
	else {bBreakVideoDisable = false;}

	SetEventHandler("Control Activation","IVideoBreak",0);
	if(!IsEntity(aviVideoObj))
	{
		Trace("Can`t create video player");
		PostEvent("ievntEndVideo",0);
	}
}
bool bBreakVideoDisable = false;
void IVideoBreak()
{
	string ControlName = GetEventData();
	bool bMakeBreak = false;
	if( ControlName=="ICancel" )	{bMakeBreak = true;}
	if( !bBreakVideoDisable )
	{
		if( ControlName=="IStartButton" || ControlName=="IAllCancel" ||
			ControlName=="IAction" ) {bMakeBreak = true;}
	} else {
		if(!EnableVideoBreak) {bMakeBreak = false;}
	}
	if(bMakeBreak)
	{
		DelEventHandler("Control Activation","IVideoBreak");
		Event("ievntEndVideo");
	}
}
void _Procedure_EndVideoPlay()
{
	g_ibVideoExecuting = false;
	bBreakVideoDisable = false;
	DelEventHandler("Control Activation","IVideoBreak");
	//ResumeAllSounds();
	DeleteClass(&aviVideoObj);
	if(bMainMenuLaunchAfterVideo)
	{
		bMainMenuLaunchAfterVideo = false;
		Event("DoInfoShower","sl","MainMenuLaunch",true);
	} else {InfoShowSetting();}
	bGamePadChangeEnable = false;
	bPlayVideoNow = false;
	DelEventHandler("ievntEndVideo","_Procedure_EndVideoPlay");
	if(aviVideoObj.layer == "land")
	{
		LayerFreeze("realize",false);
		LayerFreeze("execute",false);
	}
	if(aviVideoObj.layer == "sea")
	{
		LayerFreeze(SEA_REALIZE,false);
		LayerFreeze(SEA_EXECUTE,false);
	}
	if(sti(InterfaceStates.Launched)) EngineLayersOffOn(false);
	if(CheckAttribute(&aviVideoObj,"afterQuestName"))
	{
		DoQuestCheckDelay(aviVideoObj.afterQuestName,0.1);
		//QuestComplete(aviVideoObj.afterQuestName);
		//QuestsCheck();
		DeleteAttribute(&aviVideoObj,"afterQuestName");
	}
	PostEvent(EVENT_END_VIDEO,1);
}

int GetCurrentInterface()
{
	return CurrentInterface;
}

void ISetSaveData(string saveName, string saveData)
{
	SendMessage(&GameInterface,"lss",MSG_INTERFACE_DO_SAVE_DATA,saveName,saveData);
}

string IGetSaveString(string saveName)
{
	string retStr;
	SendMessage(&GameInterface,"lse",MSG_INTERFACE_GET_SAVE_DATA,saveName,&retStr);
	return retStr;
}

bool procEnableInterfaceLaunch(int _interfaceCode)
{
	if(sti(InterfaceStates.Launched)==true) return false;
	if(IsEntity(reload_fader)) return false;
	if(DialogRun!=0)
	{
		if(_interfaceCode!=INTERFACE_HELPSCREEN)	return false;
	}
	return true;
}

bool bRunHelpChooser = false;
void RunHelpChooser()
{
	string chooserName = "";
	if(bSeaActive && !bAbordageStarted)	chooserName = "sea_interface";
	else if( IsEntity(worldMap) )	chooserName = "world_map";
	else if( DialogRun )	chooserName = "Dialog_window";
	else chooserName = "land_interface";

	if(chooserName=="")
	{
		LaunchHelpScreen("");
		return;
	}

	DeleteEntitiesByType("HELPCHOOSER");
	SetEventHandler("EventEndHelpChooser","ProcEndHelpChooser",0);
	object objHelpChooser;
	CreateEntity(&objHelpChooser,"HELPCHOOSER");
	if( !IsEntity(&objHelpChooser) )
	{
		Event("EventEndHelpChooser","s","");
		return;
	}
	if( !SendMessage(&objHelpChooser,"ls",MSG_HELPCHOOSER_START,chooserName) )
	{
		Event("EventEndHelpChooser","s","");
	}
	bRunHelpChooser = true;
	EngineLayersOffOn(false);
	InterfaceStates.Launched=true;
	LayerAddObject("iExecute",&objHelpChooser,10000);
	LayerAddObject("iRealize",&objHelpChooser,10000);
}

void ProcEndHelpChooser()
{
	string HelpSectionName = GetEventData();
	DelEventHandler("EventEndHelpChooser","ProcEndHelpChooser");
	DeleteEntitiesByType("HELPCHOOSER");
	bRunHelpChooser = false;
	InterfaceStates.Launched=false;
	if(HelpSectionName!="")	LaunchHelpScreen(HelpSectionName);
	else EngineLayersOffOn(true);
}

void ReturnToMainMenu()
{
	/*if(sti(InterfaceStates.Buttons.Resume.enable)==true)
	{
		if(bSeaActive) return;
		if(IsEntity(&worldMap)) return;
		if(FindLoadedLocation()!=-1) return;
	}*/
	DelEventHandler("frame","InterfaceDoExit");
	EngineLayersOffOn(false);
	InterfaceStates.Launched = false;
	InterfaceStates.MakeScreenShot = false;
	LaunchMainMenu();
}

void ILaunchAfterFrame()
{
	string nodName = GetEventData();
	int n = GetEventData();
	if( CheckAttribute(&InterfaceStates,"LaunchAfterFrame") && InterfaceStates.LaunchAfterFrame!=nodName ) {
		return;
	}
	if(n>0 || sti(InterfaceStates.Launched))
	{
		PostEvent("LaunchIAfterFrame",1,"sl", nodName, n-1);
		return;
	}

	switch(nodName)
	{
	case "I_SELECTMENU":	LaunchSelectMenu();	return; break;
	case "I_CHARACTER":		LaunchCharacter(GetMainCharacter());	return; break;
	case "I_SHIP":			LaunchShipState();	return; break;
	case "I_SHIPHOLD":		LaunchShipHold();	return; break;
	case "I_PASSENGER":		LaunchPassengers(GetMainCharacter());	return; break;
	case "I_QUESTBOOK":		LaunchQuestBook();	return; break;
	case "I_TRADEBOOK":		LaunchTradeBook();	return; break;
	case "I_NATIONS":		LaunchNationRelation();	return; break;
	case "I_ITEMS":			LaunchItems();	return; break;
	case "I_MAINMENU":		LaunchMainMenu(); return; break;
	case "AbilityView":
		if(CheckAttribute(&GameInterface,"AbilityChr"))
		{
			LaunchPerksScreen(GetCharacter(sti(GameInterface.AbilityChr)));
		}
		return;
	break;
	}
}

bool procInterfacePrepare(int interfaceCode)
{
	if(procEnableInterfaceLaunch(interfaceCode)==false) return false;
	if(g_ibVideoExecuting) return false;
    if( LoadSegment(Interfaces[interfaceCode].SectionName) )
	{
		InterfaceStates.Launched = true;
		InterfaceStates.doUnFreeze = false;
		EngineLayersOffOn(false);
		ISetSoundEvents();
		DeleteAttribute(&GameInterface,"");
		if(IsPerkIntoList("TimeSpeed")) {SetTimeScale(1.0);}
		return true;
	}
	else
	{
		interfaceResultCommand = RC_INTERFACE_ERROR;
		Start_InterfaceDoExit();
		return false;
	}
}

void Start_InterfaceDoExit()
{
	if(IsPerkIntoList("TimeSpeed")) {SetTimeScale(GetSeaTimeScale());}
	SetEventHandler("frame","InterfaceDoExit",1);
}

extern void OSL_WriteGameOption();
extern void OSL_ReadGameOption();

void LoadGameOptions()
{
	if( LoadSegment("interface\option_sl.c") )
	{
		OSL_ReadGameOption();
		UnloadSegment("interface\option_sl.c");
	}
}

void SaveGameOptions()
{
	if( LoadSegment("interface\option_sl.c") )
	{
		OSL_WriteGameOption();
		UnloadSegment("interface\option_sl.c");
	}
}

void ReloadAfterFortCapture()
{
	ref mchref = GetMainCharacter();
	int fortChr = sti(mchref.from_interface.fortCharacterIdx);
	DeleteAttribute(mchref,"from_interface");
	ref chref = GetCharacter(fortChr);

	string sToLocation = "";
	string sToLocator = "";
	aref ar_FindLoc = FindIslandReloadLocator(chref.location,chref.location.locator);
	if(CheckAttribute(ar_FindLoc,"GoAfterBoard.location"))
	{
		ar_FindLoc = FindIslandReloadLocator(chref.location,ar_FindLoc.GoAfterBoard.location);
		if( CheckAttribute(ar_FindLoc,"go") )
		{	sToLocation = ar_FindLoc.go;
		}
		if( CheckAttribute(ar_FindLoc,"emerge") )
		{	sToLocator = ar_FindLoc.emerge;
		}
	}

	chref.Fort.Mode = FORT_DEAD;
	// data of frot die
	chref.Fort.DieTime.Year = GetDataYear();
	chref.Fort.DieTime.Month = GetDataMonth();
	chref.Fort.DieTime.Day = GetDataDay();
	chref.Fort.DieTime.Time = GetTime();

	SetLocationCapturedState(sToLocation,true);
	Go2LocationAfterAbordage();
	mchref.location.from_sea = sToLocation;
	DoQuestReloadToLocation(sToLocation,"reload",sToLocator,"");
}

void IProcEventGameOver()
{
	string str = GetEventData();
	if( sti(InterfaceStates.Launched) )
	{
		InterfaceStates.InstantExit = true;
		Event("exitCancel");
		DeleteAttribute(&InterfaceStates,"InstantExit");
	}
	GameOver(str);
}

void IProcEventSetGameTime()
{
	int itmp = GetEventData();
	InterfaceStates.GameTime.hour = itmp;

	itmp = GetEventData();
	InterfaceStates.GameTime.min = itmp;

	itmp = GetEventData();
	InterfaceStates.GameTime.sec = itmp;
}

//==============================================================
//	Секция Показывающая какую либо инфо на экране
//==============================================================
#event_handler("DoInfoShower", "procInfoShow");
object objInfoList[10];

void procInfoShow()
{
	string sInfoID = GetEventData();
	int nInfoSet = false;
	if( sInfoID=="" ) {
		sInfoID = "MainMenuLaunch";
	} else {
		nInfoSet = GetEventData();
	}

	int nInfoIdx = 0;
	switch(sInfoID)
	{
	case "MainMenuLaunch":	nInfoIdx = 0; break;
	case "save game":		nInfoIdx = 1; break;
	case "Low Storage":		nInfoIdx = 2; break;
	case "game prepare":	nInfoIdx = 3; break;
	case "OptionsBreak":	nInfoIdx = 4; break;
	case "lost controller":	nInfoIdx = 5; break;
	}

	int prevQ = 0;
	if( CheckAttribute(&objInfoList[nInfoIdx],"refr") && IsEntity(&objInfoList[nInfoIdx]) ) {
		prevQ = sti(objInfoList[nInfoIdx].refr);
	}

	if( nInfoSet!=0 ) prevQ++;
	else prevQ--;
	if(prevQ<0) prevQ=0;
	objInfoList[nInfoIdx].refr = prevQ;

	if( prevQ>0 )
	{
		if( !IsEntity(&objInfoList[nInfoIdx]) )
		{
			objInfoList[nInfoIdx].backColor = 0;
			objInfoList[nInfoIdx].foreColor = 0;
			objInfoList[nInfoIdx].borderWidth = 32;
			objInfoList[nInfoIdx].scale = 1.0;
			objInfoList[nInfoIdx].offset = 30;

			switch(sInfoID)
			{
			case "save game":
				objInfoList[nInfoIdx].picfilename = "loading\" + LanguageGetLanguage() + "\save_game.tga";
			break;

			case "lost controller":
				objInfoList[nInfoIdx].picfilename = "loading\" + LanguageGetLanguage() + "\lost_controller.tga";
			break;

			case "Low Storage":
				objInfoList[nInfoIdx].picfilename = "loading\" + LanguageGetLanguage() + "\low_storage.tga";
			break;

			case "game prepare":
				objInfoList[nInfoIdx].picfilename = "loading\" + LanguageGetLanguage() + "\start_loading.tga";
			break;

			case "MainMenuLaunch":
				objInfoList[nInfoIdx].picfilename = "interfaces\mainmenu_ss.tga";
			break;

			case "OptionsBreak":
				objInfoList[nInfoIdx].picfilename = "loading\" + LanguageGetLanguage() + "\options.tga";
			break;
			}

			CreateEntity(&objInfoList[nInfoIdx],"InfoHandler");

			LayerCreate("inf_realize", 1);
			LayerSetRealize("inf_realize", 1);
		}
	}
	else
	{
		if( IsEntity(&objInfoList[nInfoIdx]) )
		{
			DeleteClass(&objInfoList[nInfoIdx]);
		}
	}

	InfoShowSetting();
}

void InfoShowSetting()
{
	bool bAlreadySet = false;
	bool bMakeSet;
	for(int i=5; i>=0; i--)
	{
		bMakeSet = false;
		if( IsEntity(&objInfoList[i]) )
		{
			if(!bAlreadySet) {
				bMakeSet = true;
				if( i==5 )
				{
					if( g_ibVideoExecuting || !CheckAttribute(&InterfaceStates,"Buttons.Resume.enable") ||
						sti(InterfaceStates.Buttons.Resume.enable)==false )
					{
						bMakeSet = false;
					}
				}
			}
		}

		if( bMakeSet ) {
			LayerAddObject("inf_realize",&objInfoList[i],-1);
			bAlreadySet = true;
		} else {
			LayerDelObject("inf_realize",&objInfoList[i]);
		}

		if(i==2) {
			if(bMakeSet) {
				SetEventHandler("Control Activation","InfoShow_Control",0);
			} else {
				DelEventHandler("Control Activation","InfoShow_Control");
			}
		}
		if(i==4) {
			if(bMakeSet) {
				SetEventHandler("Control Activation","InfoShow_Control2",0);
			} else {
				DelEventHandler("Control Activation","InfoShow_Control2");
			}
		}
		if(i==5) {
			if(bMakeSet) {
				SetTimeScale(0.0);
			} else {
				if(IsPerkIntoList("TimeSpeed")) {
					if( sti(InterfaceStates.Launched) == true ) {
						SetTimeScale(GetSeaTimeScale());
					} else { SetTimeScale(1.0); }
				} else {SetTimeScale(1.0);}
			}
		}
	}

	if(bAlreadySet) {
		LayerFreeze("irealize",true);
		LayerFreeze("iexecute",true);
	} else {
		LayerFreeze("irealize",false);
		LayerFreeze("iexecute",false);
	}
}


void InfoShow_Control()
{
	string ControlName = GetEventData();

	if(ControlName=="IAction" || ControlName=="ICancel")
	{
		PostEvent("DoInfoShower",0,"sl","Low Storage",false);
		if(ControlName=="ICancel")
		{
			SendMessage(&GameInterface,"l",MSG_INTERFACE_LAUNCH_DASHBOARD);
		}
		else Event("evntLowStorageBreak");
		LayerFreeze("irealize",false);
		LayerFreeze("iexecute",false);
	}
}

void InfoShow_Control2()
{
	string ControlName = GetEventData();

	if(ControlName=="IAction" || ControlName=="IStartButton")
	{
		PostEvent("DoInfoShower",0,"sl","OptionsBreak",false);
		Event("evntOptionsBreak");
		LayerFreeze("irealize",false);
		LayerFreeze("iexecute",false);
	}
}

void procAttractExit()
{
	PostEvent("ievntEndVideo",1);
	DelEventHandler("Control Activation","procAttractExit");
}

float GetSeaTimeScale()
{
	if(bArcadeMode) return 2.0;
	return 3.0;
}

void SetShowWindowParameters(bool TVused, int w,int h, int l,int t,int r,int b)
{
	showWindow.TVused = TVused;
	showWindow.width = w;
	showWindow.height = h;
	showWindow.aspectRatio = (h*4.0)/(w*3.0);
	showWindow.left = RecalculateHIcon(l);
	showWindow.top = RecalculateVIcon(t);
	showWindow.right = w - RecalculateHIcon(w-r);
	showWindow.bottom = h - RecalculateVIcon(h-b);
	showWindow.sw = r-l;
	showWindow.sh = b-t;
}

int RecalculateHIcon(int curHSize)
{
	return curHSize;
}

int RecalculateVIcon(int curVSize)
{
	return makeint(stf(showWindow.aspectRatio)*curVSize);
}

string GetVideoFileName(string baseName)
{
	if( baseName=="Invasion" ) {
		baseName = LanguageGetLanguage() + "\Invasion";
	}
	if(baseName=="Ending" && LanguageGetLanguage() == "english")
	{
		baseName = "Ending_eng";
	}
	if(baseName=="Credits" && LanguageGetLanguage() == "russian")
	{
		baseName = "Credits_ru";
	}

	if( GetTargetPlatform()=="pc" ) return baseName+".wmv";
	return baseName+".xmv";
}

void DisableMenuLaunch(bool bDisable)
{
	if(bDisable) {
		InterfaceStates.LaunchDisable = true;
	} else {
		DeleteAttribute(&InterfaceStates,"LaunchDisable");
	}
}
bool IsEnableMenuLaunch()
{
	if( CheckAttribute(&InterfaceStates,"LaunchDisable") ) {
		return !sti(InterfaceStates.LaunchDisable);
	}
	return true;
}

void DisableFastTravel(bool bDisable)
{
	if(bDisable) {
		InterfaceStates.DisFastTravel = true;
	} else {
		DeleteAttribute(&InterfaceStates,"DisFastTravel");
	}
}
bool IsEnableFastTravel()
{
	if( CheckAttribute(&InterfaceStates,"DisFastTravel") ) {
		return !sti(InterfaceStates.DisFastTravel);
	}
	return true;
}

void procPreLoad()
{
	DeleteAttribute(&objActivePerkShower,"PerkList");
	SetTimeScale(1.0);
}

void ProcBreakInterface()
{
	if( CheckAttribute(&InterfaceStates,"Launched") &&
		sti(InterfaceStates.Launched)==true )
	{
		if( CurrentInterface==INTERFACE_RANSACK_MAIN ||
			CurrentInterface==INTERFACE_FORTCAPTURE ||
			CurrentInterface==INTERFACE_TRANSFER_GOODS ||
			CurrentInterface==INTERFACE_TRANSFER_CHARACTER ||
			CurrentInterface==INTERFACE_TRANSFER_CREW )
		{
			return;
		}
	}
	InterfaceStates.InstantExit = true;
	Event("exitCancel");
	DeleteAttribute(&InterfaceStates,"InstantExit");
}

bool g_bOptionsBreak = false;
void procOptionsBreak()
{
	g_bOptionsBreak = true;
}

string g_sTipsPath;
ref procGetTipsPath()
{
	string sLngID = LanguageGetLanguage();
	if(sLngID=="")	g_sTipsPath = "tips";
	else g_sTipsPath = "tips\" + sLngID;
	return &g_sTipsPath;
}

string g_sFaderPic;
ref procGetFaderPicture()
{
	string sPicName = GetEventData();
	g_sFaderPic = LanguageGetFaderPic(sPicName);
	return &g_sFaderPic;
}

void StartLanguageSetting(string lngID)
{
	if(lngID!="") LanguageSetLanguage(lngID);

	string segmentName = "Characters\" + LanguageGetLanguage() + "\Characters_names.c";
	if( LoadSegment(segmentName) )
	{
		InitCharactersNames();
		UnloadSegment(segmentName);
	}

	segmentName = "Ships\" + LanguageGetLanguage() + "\ships_name.c";
	if ( LoadSegment(segmentName) )
	{
		InitRandomShipsNames();
		UnloadSegment(segmentName);
	}

	SendMessage( &Sound, "ls", MSG_SOUND_ALIAS_ADD, "Greetings_" + LanguageGetLanguage() + ".lng" );
	SendMessage( &Sound, "ls", MSG_SOUND_ALIAS_ADD, "talk_" + LanguageGetLanguage() + ".lng" );
}

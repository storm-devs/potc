#define MAINMENU_TIME_DELAY		45

string isUsersName="";

void InitInterface(string iniName)
{
    GameInterface.title = "# ";
	SetEventHandler("CriptData","DatSet",0);
	SetEventHandler("evntCheckFailure","ProcStop",0);

    SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);

	SetSelectable("B_NEWGAME",sti(InterfaceStates.Buttons.New.enable));
	SetSelectable("B_RESUMEGAME",sti(InterfaceStates.Buttons.Resume.enable));
	SetSelectable("B_LOAD",sti(InterfaceStates.Buttons.Load.enable));
	SetSelectable("B_SAVE",sti(InterfaceStates.Buttons.Save.enable));
	SetSelectable("B_OPTIONS",sti(InterfaceStates.Buttons.Options.enable));
	SetSelectable("B_CONTROLS",sti(InterfaceStates.Buttons.Controls.enable));
	SetSelectable("B_CREDITS",sti(InterfaceStates.Buttons.Credits.enable));
	SetSelectable("B_QUIT",sti(InterfaceStates.Buttons.Quit.enable));

	if(bSeaActive)	SetSelectable("B_SAVE",false);
	if(LAi_IsBoardingProcess())	SetSelectable("B_SAVE",false);

	SendMessage(&GameInterface,"lsls",MSG_INTERFACE_MSG_TO_NODE,"BACKPICTURE",3, "interfaces\mainback");

//    CreateString(true,"Logo","Pirates of the Caribbean, beta version",FONT_NORMAL,COLOR_NORMAL,610,420,SCRIPT_ALIGN_RIGHT,0.5);
//    CreateString(true,"Version","beta version",FONT_NORMAL,COLOR_NORMAL,620,450,SCRIPT_ALIGN_RIGHT,0.5);
    CreateString(true,"Name",isUsersName,FONT_NORMAL,COLOR_NORMAL,20,430,SCRIPT_ALIGN_LEFT,0.5);

	SetEventHandler("InterfaceBreak","ProcessBreakExit",0)
	SetEventHandler("exitCancel","ProcessCancelExit",0);
	SetEventHandler("ConfirmYes","ProcessDelete_yes",0);
	SetEventHandler("ConfirmNo","ProcessDelete_no",0);
	SetEventHandler("ResumeGamePress","ResumeGamePress",0);
	SetEventHandler("QuitPress","QuitPress",0);

	SetEventHandler("evntLowStorageBreak","LowStorageNext",0);

	SetEventHandler("UpPress","UpPress",0);
	SetEventHandler("DownPress","DownPress",0);
	SetEventHandler("ievnt_command","ProcCommand",0);
	SetEventHandler("BreakExit","procBreakExit",0);

	string saveName;
	GameInterface.SavePath = "SAVE";
	int ntmp;
    //if( SendMessage(&GameInterface,"llee",MSG_INTERFACE_SAVE_FILE_FIND,0,&saveName,&ntmp)!=0 )
	if( SendMessage(&GameInterface,"l",MSG_INTERFACE_IS_READY_LOAD)!=0 )
	{
		SetCurrentNode("B_LOAD");
	}
	else
	{
		SetCurrentNode("B_NEWGAME");
		SetSelectable("B_LOAD",false);
	}

	if(!sti(InterfaceStates.Buttons.Resume.enable))
	{
		GameInterface.mainmenu.timeclock = MAINMENU_TIME_DELAY;
		SetEventHandler("evntTimeCalculate","procTimeCalculate",0);
		PostEvent("evntTimeCalculate",1000);
		SetMusic("music\Coridor.ogg");
	}
	PostEvent("DoInfoShower",1,"sl","MainMenuLaunch",false);
	SetEventHandler("CheckAgain","procCheckAgain",0);
	SetEventHandler("CheckCancel","procCheckCancel",0);
}

void UpPress()
{
	SetCurrentUpNode(GetCurrentNode());
}

void DownPress()
{
	SetCurrentDownNode(GetCurrentNode());
}

void SetCurrentUpNode(string curNode)
{
	string nextNode="";

	switch(curNode)
	{
	case "B_NEWGAME":		nextNode = "B_QUIT";		break;
	case "B_RESUMEGAME":	nextNode = "B_NEWGAME";		break;
	case "B_LOAD":			nextNode = "B_RESUMEGAME";	break;
	case "B_SAVE":			nextNode = "B_LOAD";		break;
	case "B_OPTIONS":		nextNode = "B_SAVE";		break;
	case "B_CREDITS":		nextNode = "B_CONTROLS";	break;
	case "B_CONTROLS":		nextNode = "B_OPTIONS";		break;
	case "B_QUIT":			nextNode = "B_CREDITS";		break;
	}

	if(GetSelectable(nextNode))
	{
		SetCurrentNode(nextNode);
	}
	else
	{
		if(nextNode!=GetCurrentNode())
		{
			SetCurrentUpNode(nextNode);
		}
	}
}

void SetCurrentDownNode(string curNode)
{
	string nextNod;

	switch(curNode)
	{
	case "B_NEWGAME":		nextNod = "B_RESUMEGAME";	break;
	case "B_RESUMEGAME":	nextNod = "B_LOAD";			break;
	case "B_LOAD":			nextNod = "B_SAVE";			break;
	case "B_SAVE":			nextNod = "B_OPTIONS";		break;
	case "B_OPTIONS":		nextNod = "B_CONTROLS";		break;
	case "B_CONTROLS":		nextNod = "B_CREDITS";		break;
	case "B_CREDITS":		nextNod = "B_QUIT";			break;
	case "B_QUIT":			nextNod = "B_NEWGAME";		break;
	}

	if(GetSelectable(nextNod))
	{
		SetCurrentNode(nextNod);
	}
	else
	{
		if(nextNod!=GetCurrentNode())
		{
			SetCurrentDownNode(nextNod);
		}
	}
}

void ProcessCancelExit()
{
	IDoExit( RC_INTERFACE_MAIN_MENU_EXIT, true );
	if(!sti(InterfaceStates.Buttons.Resume.enable))
	{
		ResetSound();
	}
}

void ProcessBreakExit()
{
	if( GetSelectable("B_RESUMEGAME") )	IDoExit( RC_INTERFACE_MAIN_MENU_EXIT, true );
}

void NewGamePress()
{
	IDoExit( RC_INTERFACE_DO_NEW_GAME, true );
}

void NewGameConfirm()
{
	if( sti(InterfaceStates.Buttons.Resume.enable) )
	{
		SetNodeUsing("CONFIRM_RECTANGLE",true);
		SetNodeUsing("TEXTWINDOW",true);
		SetNodeUsing("CONFIRM_YES_BUTTON",true);
		SetNodeUsing("CONFIRM_NO_BUTTON",true);
		SetCurrentNode("CONFIRM_NO_BUTTON");
		SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 1, "CONFIRM_NO_BUTTON");
		SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 2, "CONFIRM_YES_BUTTON");

		int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
		SetFormatedText("TEXTWINDOW",LanguageConvertString(tmpLangFileID,"New game confirm"));
		LanguageCloseFile(tmpLangFileID);
	}
	else NewGamePress();
}

void ProcessDelete_no()
{
	SetNodeUsing("CONFIRM_RECTANGLE",false);
	SetNodeUsing("TEXTWINDOW",false);
	SetNodeUsing("CONFIRM_YES_BUTTON",false);
	SetNodeUsing("CONFIRM_NO_BUTTON",false);
	SendMessage(&GameInterface,"ll", MSG_INTERFACE_LOCK_NODE, 0);

	SetCurrentNode("B_NEWGAME");
}

void ProcessDelete_yes()
{
	SetNodeUsing("CONFIRM_RECTANGLE",false);
	SetNodeUsing("TEXTWINDOW",false);
	SetNodeUsing("CONFIRM_YES_BUTTON",false);
	SetNodeUsing("CONFIRM_NO_BUTTON",false);
	SetCurrentNode("DEL_BUTTON");
	SendMessage(&GameInterface,"ll", MSG_INTERFACE_LOCK_NODE, 0);

	NewGamePress();
}

void LoadPress()
{
	IDoExit( RC_INTERFACE_DO_LOAD_GAME, false );
}

void SavePress()
{
	IDoExit( RC_INTERFACE_DO_SAVE_GAME, false );
}

void OptionsPress()
{
	IDoExit( RC_INTERFACE_DO_OPTIONS, false );
}

void ControlsPress()
{
	IDoExit( RC_INTERFACE_DO_CONTROLS, false );
}

void CreditsPress()
{
	SetEventHandler(EVENT_END_VIDEO,"LaunchMainMenu_afterVideo",0);
	bMainMenuLaunchAfterVideo = true;
	StartPostVideo("credits",1);
}

void QuitPress()
{
	ExitProgram();
}

void ResumeGamePress()
{
	IDoExit( RC_INTERFACE_DO_RESUME_GAME, true );
}

void IDoExit(int exitCode, bool bClear)
{
	DelEventHandler("InterfaceBreak","ProcessBreakExit");
	DelEventHandler("exitCancel","ProcessCancelExit");
	DelEventHandler("ConfirmYes","ProcessDelete_yes");
	DelEventHandler("ConfirmNo","ProcessDelete_no");
	DelEventHandler("ResumeGamePress","ResumeGamePress");
	DelEventHandler("QuitPress","QuitPress");
	DelEventHandler("evntLowStorageBreak","LowStorageNext");
	DelEventHandler("CriptData","DatSet");
	DelEventHandler("evntCheckFailure","ProcStop");
	DelEventHandler("UpPress","UpPress");
	DelEventHandler("DownPress","DownPress");
	DelEventHandler("ievnt_command","ProcCommand");
	DelEventHandler("evntTimeCalculate","procTimeCalculate");
	DelEventHandler("BreakExit","procBreakExit");
	DelEventHandler("CheckAgain","procCheckAgain");

	interfaceResultCommand = exitCode;
	EndCancelInterface(bClear);
}

void DatSet()
{
	isUsersName = GetEventData();
}

void procTimeCalculate()
{
	int n = sti(GameInterface.mainmenu.timeclock) - 1;

	if(n>0)
	{
		GameInterface.mainmenu.timeclock = n;
		PostEvent("evntTimeCalculate",1000);
		return;
	}

	SetEventHandler(EVENT_END_VIDEO,"LaunchMainMenu_afterVideo",0);
	StartPostVideo("trailer",1);
	SetEventHandler("Control Activation","procAttractExit",1);
}

void ProcCommand()
{
	GameInterface.mainmenu.timeclock = MAINMENU_TIME_DELAY;

	string comName = GetEventData();
	string nodName = GetEventData();

	if(comName=="activate" || comName=="click")
	{
		switch(nodName)
		{
		case "B_NEWGAME":	CheckStorageSpace("newgame"); break;
		case "B_LOAD":		CheckStorageSpace("load"); break;
		case "B_SAVE":		CheckStorageSpace("save"); break;
		case "B_OPTIONS":	CheckStorageSpace("options"); break;
		case "B_CONTROLS":	CheckStorageSpace("controls"); break;
		case "B_CREDITS":	CheckStorageSpace("credits"); break;
		}
	}
}

void procBreakExit()
{
	if( GetSelectable("B_RESUMEGAME") ) ProcessCancelExit();
}

string confirmAction="";
void CheckStorageSpace(string action)
{
	confirmAction = action;
	if( g_bOptionsBreak )
	{
		SetEventHandler("evntOptionsBreak","OptionsBreakOk",0);
		PostEvent("DoInfoShower",1,"sl","OptionsBreak",true);
		return;
	}
	if( GetTargetPlatform()=="xbox" )
	{
		int nFreeBlocks = SendMessage(&GameInterface, "l", MSG_INTERFACE_GET_FREE_SPACE);
		if( nFreeBlocks < MAX_SAVE_STORE_BLOCKS ) {
			PostEvent("DoInfoShower",1,"sl","Low Storage",true);
			return;
		}
	}
	PostEvent("evntLowStorageBreak",1);
}
void LowStorageNext()
{
	switch(confirmAction)
	{
	case "newgame":		NewGameConfirm(); break;
	case "load":		LoadPress(); break;
	case "save":		SavePress(); break;
	case "options":		OptionsPress(); break;
	case "controls":	ControlsPress(); break;
	case "credits":		CreditsPress(); break;
	}
}

void OptionsBreakOk()
{
	DelEventHandler("evntOptionsBreak","OptionsBreakOk");
	SaveGameOptions();
	g_bOptionsBreak = false;
	CheckStorageSpace(confirmAction);
	LoadGameOptions();
}

void ProcStop()
{
	SetNodeUsing("CONFIRM_RECTANGLE", true);
	SetNodeUsing("TEXTWINDOW", true);
	SetNodeUsing("STOP_OK", true);
	SetNodeUsing("STOP_EXIT", true);
	SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 1, "STOP_OK");
	SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 2, "STOP_EXIT");

	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	SetFormatedText("TEXTWINDOW",LanguageConvertString(tmpLangFileID,"Insert Disk Ok"));
	LanguageCloseFile(tmpLangFileID);

	SetCurrentNode("STOP_OK");
}

void procCheckAgain()
{
	if ( SendMessage(&GameInterface,"l", MSG_INTERFACE_CHECK_AGAIN)!=0 )
	{
		SetNodeUsing("CONFIRM_RECTANGLE", false);
		SetNodeUsing("TEXTWINDOW", false);
		SetNodeUsing("STOP_OK", false);
		SetNodeUsing("STOP_EXIT", false);
		SendMessage(&GameInterface,"ll", MSG_INTERFACE_LOCK_NODE, 0);
		SetCurrentNode("B_NEWGAME");
	}
}

void procCheckCancel()
{
	ExitProgram();
}

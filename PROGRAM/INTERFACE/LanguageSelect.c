string g_sNewSelectedLanguage = "";

void InitInterface(string iniName)
{
    GameInterface.title = "titleLanguageSelect";

	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);

	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
    SetEventHandler("exitCancel","ProcessCancelExit",0);
	SetEventHandler("ievnt_command","ProcessCommandExecute",0);

	PostEvent("DoInfoShower",1,"sl","MainMenuLaunch",false);
}

void ProcessCancelExit()
{
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
    DelEventHandler("exitCancel","ProcessCancelExit");
	DelEventHandler("ievnt_command","ProcessCommandExecute");

	StartLanguageSetting(g_sNewSelectedLanguage);

	interfaceResultCommand = RC_INTERFACE_LANGUAGESET_EXIT;
    EndCancelInterface(false);
	PostEvent("LaunchIAfterFrame",1,"sl","I_MAINMENU",0);
}

void ProcessCommandExecute()
{
	string comName = GetEventData();
	string nodName = GetEventData();
	string tmpNodName;

	if(comName=="upstep")
	{
		tmpNodName = nodName;
		while(true)
		{
			tmpNodName = GetUpperNode(tmpNodName);
			if(tmpNodName=="" || tmpNodName==nodName) {break;}
			if( GetSelectable(tmpNodName) ) {break;}
		}
		SetCurrentNode( tmpNodName );
		return;
	}

	if(comName=="downstep")
	{
		tmpNodName = nodName;
		while(true)
		{
			tmpNodName = GetDownerNode(tmpNodName);
			if(tmpNodName=="" || tmpNodName==nodName) {break;}
			if( GetSelectable(tmpNodName) ) {break;}
		}
		SetCurrentNode( tmpNodName );
		return;
	}

	if(comName=="activate" || comName=="click")
	{
		switch(nodName)
		{
		case "B_ENGLISH": g_sNewSelectedLanguage="English"; break;
		case "B_SPANISH": g_sNewSelectedLanguage="Spanish"; break;
		case "B_GERMAN": g_sNewSelectedLanguage="German"; break;
		case "B_FRENCH": g_sNewSelectedLanguage="French"; break;
		case "B_RUSSIAN": g_sNewSelectedLanguage="Russian"; break;
		}
		ProcessCancelExit();
	}
}

string GetUpperNode(string nodName)
{
	switch(nodName)
	{
	case "B_ENGLISH":	return "B_RUSSIAN"; break;
	case "B_SPANISH":	return "B_ENGLISH"; break;
	case "B_GERMAN":	return "B_SPANISH"; break;
	case "B_FRENCH":	return "B_GERMAN"; break;
	case "B_RUSSIAN":	return "B_FRENCH"; break;
	}
	return "";
}

string GetDownerNode(string nodName)
{
	switch(nodName)
	{
	case "B_ENGLISH":	return "B_SPANISH"; break;
	case "B_SPANISH":	return "B_GERMAN"; break;
	case "B_GERMAN":	return "B_FRENCH"; break;
	case "B_FRENCH":	return "B_RUSSIAN"; break;
	case "B_RUSSIAN":	return "B_ENGLISH"; break;
	}
	return "";
}

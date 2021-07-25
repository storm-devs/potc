#define NONEISLAND_TEXTURE_NAME	"interfaces\empty_sea.tga"
#define MAX_SAVE_GAME_LIMIT 20

int nCurScroll;
bool bThisSave;

aref scrshot;

bool bSaveConfirm;
bool bLoadConfirm;
bool bEnableNewSave;

int FreeSpace;

int g_nLablesFileID = -1;

void InitInterface_B(string iniName, bool isSave)
{
	bThisSave = isSave;
	if(bThisSave)	GameInterface.title = "titleSave";
	else	GameInterface.title = "titleLoad";

	g_nLablesFileID = LanguageOpenFile("LocLables.txt");

	FindScrshotClass();
	SetEventHandler("GetInterfaceTexture","NewInterfaceTexture",0);
	SetEventHandler("DelInterfaceTexture","ReleaseInterfaceTexture",0);

	if(GetTargetPlatform()=="xbox")
		FreeSpace = SendMessage(&GameInterface, "l", MSG_INTERFACE_GET_FREE_SPACE);
	else FreeSpace = 50000;
	bEnableNewSave = FreeSpace>=MAX_SAVE_STORE_BLOCKS;

	FillScroll();
	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);

	CreateString(true,"SaveName","",FONT_NORMAL,COLOR_NORMAL,50,273,SCRIPT_ALIGN_LEFT,1.0);

	if(bThisSave) SetNodeUsing("LOAD_BUTTON",false);
	else SetNodeUsing("SAVE_BUTTON",false);

	CreateImage("face1","EMPTYFACE","emptyface",34,323,162,451);
	CreateImage("face2","EMPTYFACE","emptyface",183,323,311,451);
	CreateImage("face3","EMPTYFACE","emptyface",332,323,460,451);
	CreateImage("face4","EMPTYFACE","emptyface",481,323,609,451);

	if(GetTargetPlatform()=="xbox")
	{
		string sFreeSpace = "Free Space: "+FreeSpace+" blocks";
		if(FreeSpace>50000) sFreeSpace = "Free Space: 50000+ blocks";
		CreateString(true,"FreeSpace",sFreeSpace,FONT_NORMAL,COLOR_NORMAL,320,178,SCRIPT_ALIGN_CENTER,1.0);
		SetNodeUsing("FREESPACE_IMG",true);
	}

	SetNodeUsing("CONFIRM_RECTANGLE",false);
	SetNodeUsing("TEXTWINDOW",false);
	SetNodeUsing("CONFIRM_YES_BUTTON",false);
	SetNodeUsing("CONFIRM_NO_BUTTON",false);

	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	SetFormatedText("LOWSTORAGE_WINDOW",LanguageConvertString(tmpLangFileID,"save game limit"));
	LanguageCloseFile(tmpLangFileID);

	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
	SetEventHandler("frame","FrameProcess",1);
	SetEventHandler("exitCancel","ProcessCancelExit",0);
	SetEventHandler("SavePress","ProcessSaveConfirm",0);
	SetEventHandler("LoadPress","ProcessLoadConfirm",0);
	SetEventHandler("DelPress","ProcessDelete",0);
	SetEventHandler("DelNo","ProcessDelete_no",0);
	SetEventHandler("DelYes","ProcessDelete_yes",0);
	SetEventHandler("bleft","ButtonToLeft",0);
	SetEventHandler("bright","ButtonToRight",0);
	SetEventHandler("slistdown","SetFirstButton",0);
}

void FrameProcess()
{
	if(nCurScroll!=sti(GameInterface.saveslist.current))
	{
		nCurScroll = sti(GameInterface.saveslist.current);
		string attrName = "pic"+(nCurScroll+1);
		bool bFilePresent = false;
		bool bCorrupted = false;
		if( CheckAttribute(&GameInterface,"saveslist."+attrName+".descr") &&
			GameInterface.saveslist.(attrName).descr!="" )
		{
			bFilePresent = true;
			if( GameInterface.saveslist.(attrName).savestr=="" ) bCorrupted = true;
		}

		SetSelectable("SAVE_BUTTON",true);
		SetSelectable("DEL_BUTTON",bFilePresent);
		if(bFilePresent) {
			if( !bThisSave )	SetSelectable("LOAD_BUTTON",!bCorrupted);
		}
		else {
			SetSelectable("SAVE_BUTTON",bEnableNewSave);
		}

		if( bFilePresent )
		{
			if( bCorrupted ) {SettingDataForSave("");}
			else {SettingDataForSave(GameInterface.saveslist.(attrName).descr);}
		}
		else
		{
			if(bThisSave) {SettingDataForSave("NewSave");}
			else	{
				SetSelectable("LOAD_BUTTON",false);
				SettingDataForSave("");
			}
		}

		ShowLowStorage( !CheckAvailablePlace() );

		if( CheckLimited() ) {
			SetNodeUsing("LOWSTORAGE_WINDOW",false);
		} else {
			SetNodeUsing("LOWSTORAGE_WINDOW",true);
			DisableString("SaveName");
			SetSelectable("SAVE_BUTTON",false);
		}
		if( !GetSelectable(GetCurrentNode()) ) SetCurrentNode("SAVESLIST");
	}
}

void FillScroll()
{
    int i=0;
    string attributeName;

	nCurScroll = -1;
	GameInterface.SavePath = "SAVE";
	GameInterface.saveslist.current = 0;
	GameInterface.saveslist.BadPicture1 = "interfaces\Disketa_Empty.tga";
	GameInterface.saveslist.ImagesGroup.t0 = "CORRUPTSAVE";
	GameInterface.saveslist.NotUsed = 5;

	int nSaveNum=0;
	if(bThisSave)
	{
		GameInterface.saveslist.pic1.name1 = "newsave";
		if( !bEnableNewSave ) {
			GameInterface.saveslist.pic1.str1 = "Low Storage";
		}
		GameInterface.saveslist.pic1.saveSize = 0;
		i++;
	}
	string saveName;
	string saveString;
	int nSaveSize;
    while( SendMessage(&GameInterface,"llee",MSG_INTERFACE_SAVE_FILE_FIND,nSaveNum,&saveName,&nSaveSize)!=0 )
    {
		nSaveNum++;
		attributeName = "pic" + (i+1);
		GameInterface.saveslist.(attributeName).img1 = "corruptsave";
		GameInterface.saveslist.(attributeName).tex1 = 0;
		GameInterface.saveslist.(attributeName).name1 = saveName;
		GameInterface.saveslist.(attributeName).descr = saveName;
		GameInterface.saveslist.(attributeName).savestr = "";
		GameInterface.saveslist.(attributeName).saveSize = nSaveSize;
		i++;
    }
	GameInterface.saveslist.ListSize = i;
}

void ProcessCancelExit()
{
	IDoExit(RC_INTERFACE_SAVELOAD_EXIT);
	if( !CheckAttribute(&InterfaceStates,"InstantExit") || sti(InterfaceStates.InstantExit)==false )
	{
		ReturnToMainMenu();
	}
}

void IDoExit(int exitCode)
{
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
	DelEventHandler("frame","FrameProcess");
	DelEventHandler("exitCancel","ProcessCancelExit");
	DelEventHandler("SavePress","ProcessSaveConfirm");
	DelEventHandler("LoadPress","ProcessLoadConfirm");
	DelEventHandler("DelPress","ProcessDelete");
	DelEventHandler("DelNo","ProcessDelete_no");
	DelEventHandler("DelYes","ProcessDelete_yes");
	DelEventHandler("bleft","ButtonToLeft");
	DelEventHandler("bright","ButtonToRight");
	DelEventHandler("slistdown","SetFirstButton");
	DelEventHandler("GetInterfaceTexture","NewInterfaceTexture");
	DelEventHandler("DelInterfaceTexture","ReleaseInterfaceTexture");

	LanguageCloseFile(g_nLablesFileID);

	SetNodeUsing("SAVESLIST",false);

    interfaceResultCommand = exitCode;
	if( CheckAttribute(&InterfaceStates,"InstantExit") && sti(InterfaceStates.InstantExit)==true ) {
		EndCancelInterface(false);
	} else {
		EndCancelInterface(true);
	}
}

void ProcessSaveConfirm()
{
	string attributeName = "saveslist.pic" + (nCurScroll+1);
	if( CheckAttribute(&GameInterface,attributeName+".descr") )
	{
		bSaveConfirm = true;
		bLoadConfirm = false;

		SetNodeUsing("CONFIRM_RECTANGLE",true);
		SetNodeUsing("TEXTWINDOW",true);
		SetNodeUsing("CONFIRM_YES_BUTTON",true);
		SetNodeUsing("CONFIRM_NO_BUTTON",true);
		SetCurrentNode("CONFIRM_NO_BUTTON");
		SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 1, "CONFIRM_NO_BUTTON");
		SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 2, "CONFIRM_YES_BUTTON");

		int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
		SetFormatedText("TEXTWINDOW",LanguageConvertString(tmpLangFileID,"Overwrite savefile confirm"));
		LanguageCloseFile(tmpLangFileID);
	}
	else
	{
		ProcessSave();
	}
}

void ProcessSave()
{
	string curSave = GetCurSaveName();
	if(nCurScroll>0)
	{
		SendMessage(&GameInterface,"ls",MSG_INTERFACE_DELETE_SAVE_FILE,curSave);
		nCurScroll = 0;
		curSave = GetCurSaveName();
	}

	ref PChar = GetMainCharacter();
	string locLabel = PChar.location;
	int locidx = FindLocation(PChar.location);
	if( locidx>=0 && CheckAttribute(&Locations[locidx],"id.label") ) locLabel = Locations[locidx].id.label;
	else locLabel = XI_ConvertString("Open Sea");
	string sSaveDescriber = locLabel+"@"+GetOfficersIndex(PChar,0)+"@"+GetOfficersIndex(PChar,1)+"@"+GetOfficersIndex(PChar,2)+"@"+GetOfficersIndex(PChar,3)+"@"+GetStringTime(GetTime())+"  "+GetStringDate(GetDataYear(),GetDataMonth(),GetDataDay())+"@"+LanguageGetLanguage();

	SetEventHandler("evntSave","SaveGame",1);

	if(GetTargetPlatform()=="pc") {
		PostEvent("evntSave",0,"ss", GameInterface.SavePath+"\"+curSave, sSaveDescriber);
	} else {
		PostEvent("evntSave",0,"ss", curSave, sSaveDescriber);
		Event("DoInfoShower","sl","save game",true);
	}

	IDoExit(RC_INTERFACE_SAVELOAD_EXIT);
}

void ProcessLoadConfirm()
{
	bLoadConfirm = true;
	bSaveConfirm = false;

	SetNodeUsing("CONFIRM_RECTANGLE",true);
	SetNodeUsing("TEXTWINDOW",true);
	SetNodeUsing("CONFIRM_YES_BUTTON",true);
	SetNodeUsing("CONFIRM_NO_BUTTON",true);
	SetCurrentNode("CONFIRM_NO_BUTTON");
	SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 1, "CONFIRM_NO_BUTTON");
	SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 2, "CONFIRM_YES_BUTTON");

	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	SetFormatedText("TEXTWINDOW",LanguageConvertString(tmpLangFileID,"Load game confirm"));
	LanguageCloseFile(tmpLangFileID);
}

void ProcessLoad()
{
	string sCurSave = GetCurSaveName();

	IDoExit(RC_INTERFACE_SAVELOAD_EXIT);
	ResetSound();

	SetEventHandler("evntLoad","LoadGame",1);
	if(GetTargetPlatform()=="pc") {
		PostEvent("evntLoad",0,"s",GameInterface.SavePath+"\"+sCurSave);
	} else {
		PostEvent("evntLoad",0,"s",sCurSave);
	}
	Event("evntPreLoad");
}

void ProcessDelete()
{
	bSaveConfirm = false;
	bLoadConfirm = false;

	SetNodeUsing("CONFIRM_RECTANGLE",true);
	SetNodeUsing("TEXTWINDOW",true);
	SetNodeUsing("CONFIRM_YES_BUTTON",true);
	SetNodeUsing("CONFIRM_NO_BUTTON",true);
	SetCurrentNode("CONFIRM_NO_BUTTON");
	SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 1, "CONFIRM_NO_BUTTON");
	SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 2, "CONFIRM_YES_BUTTON");

	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	SetFormatedText("TEXTWINDOW",LanguageConvertString(tmpLangFileID,"Delete savefile confirm"));
	LanguageCloseFile(tmpLangFileID);
}

void ProcessDelete_no()
{
	SetNodeUsing("CONFIRM_RECTANGLE",false);
	SetNodeUsing("TEXTWINDOW",false);
	SetNodeUsing("CONFIRM_YES_BUTTON",false);
	SetNodeUsing("CONFIRM_NO_BUTTON",false);
	SendMessage(&GameInterface,"ll", MSG_INTERFACE_LOCK_NODE, 0);

	if(	bSaveConfirm )	{SetCurrentNode("SAVE_BUTTON");}
	else {
		if(bLoadConfirm) {SetCurrentNode("LOAD_BUTTON");}
		else {SetCurrentNode("DEL_BUTTON");}
	}
}

void ProcessDelete_yes()
{
	SetNodeUsing("CONFIRM_RECTANGLE",false);
	SetNodeUsing("TEXTWINDOW",false);
	SetNodeUsing("CONFIRM_YES_BUTTON",false);
	SetNodeUsing("CONFIRM_NO_BUTTON",false);
	SetCurrentNode("DEL_BUTTON");
	SendMessage(&GameInterface,"ll", MSG_INTERFACE_LOCK_NODE, 0);

	if(	bSaveConfirm )
	{
		ProcessSave();
		return;
	}
	if( bLoadConfirm )
	{
		ProcessLoad();
		return;
	}

	string curSave = GetCurSaveName();
	SendMessage(&GameInterface,"ls",MSG_INTERFACE_DELETE_SAVE_FILE,curSave);
	DelFromScroll("SAVESLIST",nCurScroll);

	if( GetTargetPlatform()!="pc" )
	{
		FreeSpace = SendMessage(&GameInterface, "l", MSG_INTERFACE_GET_FREE_SPACE);
		string sFreeSpace = "Free Space: "+FreeSpace+" blocks";
		if(FreeSpace>50000) sFreeSpace = "Free Space: 50000+ blocks";
		GameInterface.strings.FreeSpace = sFreeSpace;
	}
	if( bThisSave && !bEnableNewSave && FreeSpace>=MAX_SAVE_STORE_BLOCKS )
	{
		bEnableNewSave = true;
		DeleteAttribute( &GameInterface,"saveslist.pic1.str1" );
		SendMessage(&GameInterface,"lsl", MSG_INTERFACE_SCROLL_CHANGE, "SAVESLIST", 0);
	}
	nCurScroll = -1;
}

string GetCurSaveName()
{
	string attrName = "pic"+(nCurScroll+1);
	if( CheckAttribute(&GameInterface,"saveslist."+attrName+".descr") &&
		GameInterface.saveslist.(attrName).descr != "" )	return GameInterface.saveslist.(attrName).descr;

	string curLocName = GetCurLocationName();
	string saveName;
	saveName = GetClampedSaveName(curLocName,0);

	int idx = 0;
	while( SendMessage(&GameInterface,"ls", MSG_INTERFACE_NEW_SAVE_FILE_NAME, saveName)==1 )
	{
		saveName = GetClampedSaveName(curLocName,idx+1);
		idx++;
	}

	return saveName;
}

void ButtonToLeft()
{
	if( GetCurrentNode() == "DEL_BUTTON" )
	{
		if(bThisSave) {
			if( GetSelectable("SAVE_BUTTON") ) SetCurrentNode("SAVE_BUTTON");
		} else {
			if( GetSelectable("LOAD_BUTTON") )	SetCurrentNode("LOAD_BUTTON");
		}
	}
	else
	{
		if( GetSelectable("DEL_BUTTON") ) SetCurrentNode("DEL_BUTTON");
		else
		{
			if(bThisSave) {
				if( GetSelectable("SAVE_BUTTON") )	SetCurrentNode("SAVE_BUTTON");
			} else {
				if( GetSelectable("LOAD_BUTTON") )	SetCurrentNode("LOAD_BUTTON");
			}
		}
	}
}

void ButtonToRight()
{
	if( GetCurrentNode() == "DEL_BUTTON" ) SetCurrentNode("CANCEL_BUTTON");
	else
	{
		if( GetSelectable("DEL_BUTTON") ) SetCurrentNode("DEL_BUTTON");
		else SetCurrentNode("CANCEL_BUTTON");
	}
}

void SetFirstButton()
{
	if( bThisSave )
	{
		if( GetSelectable("SAVE_BUTTON") ) {
			SetCurrentNode("SAVE_BUTTON");
			return;
		}
	}
	else
	{
		if( GetSelectable("LOAD_BUTTON") ) {
			SetCurrentNode("LOAD_BUTTON");
			return;
		}
	}
	if( GetSelectable("DELETE_BUTTON") ) SetCurrentNode("DELETE_BUTTON");
	else SetCurrentNode("CANCEL_BUTTON");
}

string GetStringTime(float time)
{
	int hour = makeint(time);
	int minute = makeint( (time-makefloat(hour)) * 60.0 + 0.01);
	string retVal;
	if(hour<10) retVal = "0"+hour;
	else retVal = hour;
	retVal += ":";
	if(minute<10) retVal += "0"+minute;
	else retVal += minute;
	return retVal;
}

string GetStringDate(int year,int month,int day)
{
	string retVal = day + "." + month + "." + year;
	return retVal;
}

void SettingDataForSave(string saveFileName)
{
	string pic1,pic2,pic3,pic4;
	string locationStr, timeStr, tmpStr;
	int locidx;

	if( saveFileName=="" )
	{
		EnableString("SaveName");
		timeStr = GetCurSaveName();
		SendMessage(&GameInterface, "lse", MSG_INTERFACE_FILENAME2DATASTR, GetCurSaveName(), &timeStr);
		GameInterface.strings.SaveName = XI_ConvertString("Unable to load") + " " + timeStr;
		pic1 = -1;
		pic2 = -1;
		pic3 = -1;
		pic4 = -1;
		return;
	}

	EnableString("SaveName");
	tmpStr = "";
	if( saveFileName=="NewSave" )
	{
		if(GetMainCharacterIndex()>=0)
		{
			locidx = FindLocation(Characters[GetMainCharacterIndex()].location);
			if( locidx>=0 && CheckAttribute(&Locations[locidx],"id.label") )
				locationStr = Locations[locidx].id.label;
			else	locationStr = XI_ConvertString("Open Sea");
			pic1 = GetOfficersIndex(GetMainCharacter(),0);
			pic2 = GetOfficersIndex(GetMainCharacter(),1);
			pic3 = GetOfficersIndex(GetMainCharacter(),2);
			pic4 = GetOfficersIndex(GetMainCharacter(),3);
		}
		else
		{
			locationStr = "none";
			pic1 = -1;
			pic2 = -1;
			pic3 = -1;
			pic4 = -1;
		}
		//timeStr = GetCurSaveName();
		//SendMessage(&GameInterface, "lse", MSG_INTERFACE_FILENAME2DATASTR, GetCurSaveName(), &timeStr);
		timeStr = LanguageConvertString(g_nLablesFileID,locationStr);
		SendMessage(&GameInterface, "lse", MSG_INTERFACE_GETTIME, "", &tmpStr);
	}
	else
	{
		if( !ParseSaveData(IGetSaveStringFromScroll(), &pic1,&pic2,&pic3,&pic4, &locationStr, &timeStr, &tmpStr) )
			ParseSaveData("none@-1@-1@-1@-1@not implemented", &pic1,&pic2,&pic3,&pic4, &locationStr, &timeStr, &tmpStr);
		tmpStr = "";
		//timeStr = saveFileName;
		timeStr = LanguageConvertString(g_nLablesFileID,locationStr);
		//SendMessage(&GameInterface, "lse", MSG_INTERFACE_FILENAME2DATASTR, saveFileName, &timeStr);
		if( GetTargetPlatform()=="xbox" ) {
			SendMessage(&GameInterface, "lse", MSG_INTERFACE_GETTIME, saveFileName, &tmpStr);
		} else {
			SendMessage(&GameInterface, "lse", MSG_INTERFACE_GETTIME, GameInterface.SavePath+"\"+saveFileName, &tmpStr);
		}
	}

	if( GetStringWidth(timeStr, FONT_NORMAL, 1.0)>440 )
	{
		while(true)
		{
			timeStr = strcut(timeStr,0,strlen(timeStr)-2);
			if( GetStringWidth(timeStr, FONT_NORMAL, 1.0) < 430 )
			{
				timeStr += "...";
				break;
			}
		}
	}
	GameInterface.strings.SaveName = timeStr + " " + tmpStr;

	GameInterface.pictures.face1.pic = GetFacePictureName(sti(pic1));
	GameInterface.pictures.face1.tex = GetFaceGroupName(sti(pic1));

	GameInterface.pictures.face2.pic = GetFacePictureName(sti(pic2));
	GameInterface.pictures.face2.tex = GetFaceGroupName(sti(pic2));

	GameInterface.pictures.face3.pic = GetFacePictureName(sti(pic3));
	GameInterface.pictures.face3.tex = GetFaceGroupName(sti(pic3));

	GameInterface.pictures.face4.pic = GetFacePictureName(sti(pic4));
	GameInterface.pictures.face4.tex = GetFaceGroupName(sti(pic4));
}

bool ParseSaveData(string fullSaveData, ref pic1,ref pic2,ref pic3,ref pic4, ref locationStr, ref timeStr, ref languageID)
{
	string lastStr;
	if( !GetNextSubStr(fullSaveData, locationStr, &lastStr) ) return false;
	if( !GetNextSubStr(lastStr, pic1, &lastStr) ) return false;
	if( !GetNextSubStr(lastStr, pic2, &lastStr) ) return false;
	if( !GetNextSubStr(lastStr, pic3, &lastStr) ) return false;
	if( !GetNextSubStr(lastStr, pic4, &lastStr) ) return false;
	if( !GetNextSubStr(lastStr, timeStr, &lastStr) ) return false;
	GetNextSubStr(lastStr, languageID, &lastStr);
	return true;
}

bool GetNextSubStr(string inStr, ref outStr, ref lastStr)
{
	if(inStr=="")
	{
		outStr="";
		lastStr="";
		return false;
	}
	int strSize = strlen(inStr)-1;
	if(strSize<=0)
	{
		outStr="";
		lastStr="";
		return false;
	}
	int sympos = findsubstr(inStr,"@",0);
	if(sympos==-1)
	{
		outStr = inStr;
		lastStr = "";
		return true;
	}
	if(sympos>0)	outStr = strcut(inStr,0,sympos-1);
	else	outStr = "";
	if(strSize>sympos+1) lastStr = strcut(inStr,sympos+1,strSize);
	else lastStr = "";
	return true;
}

int sl_tmp_var;
ref NewInterfaceTexture()
{
	string str = GetEventData();
	int nStartPic = GetEventData();
	string strSaveData;

	if(GetTargetPlatform()=="pc") {
		sl_tmp_var = SendMessage(&scrshot,"lsse", MSG_SCRSHOT_READ, GameInterface.SavePath, str, &strSaveData);
	} else {
		sl_tmp_var = SendMessage(&scrshot,"lsse", MSG_SCRSHOT_READ,"", str, &strSaveData);
	}

	SetDataIntoList(str,strSaveData);

	if(strSaveData!="")
	{
		string tmpStr;
		string lngID = "";
		ParseSaveData(strSaveData, &tmpStr,&tmpStr,&tmpStr,&tmpStr, &tmpStr, &tmpStr, &lngID);
		if( lngID!="" && lngID!=LanguageGetLanguage() ) {
			sl_tmp_var = -1;

			aref arList; makearef(arList,GameInterface.saveslist);
			int qn = sti(arList.ListSize)-1;
			aref inar,outar;
			string attrName;
			for(int i=nStartPic; i<qn; i++)
			{
				attrName = "pic"+(i+1);
				makearef(inar,arList.(attrName));
				attrName = "pic"+(i+2);
				makearef(outar,arList.(attrName));
				DeleteAttribute(inar,"");
				CopyAttributes(inar,outar);
			}
			attrName = "pic"+(i+1);
			DeleteAttribute(arList,attrName);
			if(qn>=0) arList.ListSize = qn;
		}
	}

	return &sl_tmp_var;
}

void ReleaseInterfaceTexture()
{
	string str = GetEventData();
	sl_tmp_var = SendMessage(&scrshot,"ls",MSG_SCRSHOT_RELEASE,str);
}

void FindScrshotClass()
{
	string layerName;
	if(bSeaActive && !bAbordageStarted) layerName = SEA_REALIZE;
	else layerName = "realize";
	aref refObj;
	if( GetEntity(layerName,&refObj) )
	{
		while(true)
		{
			if(GetEntityName(&refObj)=="scrshoter")
			{
				scrshot = refObj;
				break;
			}
			if( !GetEntityNext(&refObj) ) break;
		}
	}
}

string _IGetSaveString(string saveName)
{
	if(GetTargetPlatform()=="pc") {
		return IGetSaveString(GameInterface.SavePath+"\"+saveName);
	} else {
		return IGetSaveString(saveName);
	}
}

string IGetSaveStringFromScroll()
{
	string attributeName = "pic" + (nCurScroll+1);
	if( CheckAttribute(&GameInterface,"saveslist."+attributeName) )
		return GameInterface.saveslist.(attributeName).savestr;
	return "";
}

bool CheckAvailablePlace()
{
	if( GetTargetPlatform() == "pc" ) return true;
	string attributeName = "pic" + (nCurScroll+1);
	int nOldBlocks = 0;
	if( CheckAttribute(&GameInterface,"saveslist."+attributeName+".saveSize") ) {
		nOldBlocks = sti( GameInterface.saveslist.(attributeName).saveSize );
	}
	int availableBlocks = FreeSpace + nOldBlocks;
	if( availableBlocks >= MAX_SAVE_STORE_BLOCKS ) return true;
	return false;
}

void ShowLowStorage(bool bStartShow)
{
	if(bStartShow)	DisableString("SaveName");
}

void SetDataIntoList(string saveName, string strSaveData)
{
	aref aRoot;
	makearef(aRoot,GameInterface.saveslist);

	int n=1;
	string attributeName = "pic1";
	while( CheckAttribute(aRoot,attributeName) )
	{
		if( aRoot.(attributeName).name1 == saveName )
		{
			aRoot.(attributeName).savestr = strSaveData;
			return;
		}
		n++;
		attributeName = "pic"+n;
	}
}

string GetCurLocationName()
{
	if( GetMainCharacterIndex()<0 ) return "";
	ref PChar = GetMainCharacter();
	if( !CheckAttribute(PChar,"location") ) return "";
	string locLabel = PChar.location;
	int locidx = FindLocation(PChar.location);
	if( locidx>=0 )
	{
		if( CheckAttribute(&Locations[locidx],"id.label") ) {
			locLabel = Locations[locidx].id.label;
		}
	}
	else
	{
		locLabel = "Open Sea";
	}
	return locLabel;
}

string GetClampedSaveName(string sInName, int nNumber)
{
	if( GetTargetPlatform()!="xbox" ) {
		if(nNumber>0) {return sInName + " " + nNumber;}
		else {return sInName;}
	}

	string retStr = sInName;
	int nLen = strlen(sInName)+1;
	int n = nNumber;
	int nAdd = 0;
	if(n>0) nAdd=1;
	while(n>0)
	{
		nAdd++;
		n = n/10;
	}
	if(nLen+nAdd>30)
	{
		int lastNum = nLen - sInName;
		retStr = strcut(sInName,0,30-nAdd);
	}

	if(nNumber>0) retStr += " " + nNumber;
	return retStr;
}

bool CheckLimited()
{
	if( nCurScroll>0 ) return true;
	if( !CheckAttribute(&GameInterface,"saveslist.pic1.descr") ||
		GameInterface.saveslist.pic1.descr!="" )
	{
		if( sti(GameInterface.saveslist.ListSize) > MAX_SAVE_GAME_LIMIT ) {
			SetNodeUsing("LOWSTORAGE_WINDOW",true);
			return false;
		} else {return true;}
	}

	return true;
}

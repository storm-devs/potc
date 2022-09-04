
int lngFileID = -1;
ref refUsedCharacter;
int chrPerksQ = 0;
string strPerkName;
string newLine;

int imageQuantity = 0;
int perksIconsQ = 0;

int g_nGroup = 0;
int g_nLine = 0;

void InitInterface_R(string iniName, ref chref)
{
    GameInterface.title = "titleAbilitys";
	refUsedCharacter = chref;

    SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);

    CreateString(true,"ChrName",refUsedCharacter.name+" "+refUsedCharacter.lastname,FONT_NORMAL,COLOR_NORMAL,320,38,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(true,"FreeAbilitys","",FONT_NORMAL,COLOR_NORMAL,320,72,SCRIPT_ALIGN_CENTER,1.0);
	lngFileID = LanguageOpenFile("AbilityDescribe.txt");
	newLine = LanguageConvertString(lngFileID,"newLine");

	SetNodeUsing("DESCRIBEWINDOW",false);
	SetNodeUsing("PERK_NAME",false);
	SetNodeUsing("PERK_IMAGE",false);
	SetNodeUsing("OK_BUTTON",false);
	SetNodeUsing("CANCEL_BUTTON",false);
	SetNodeUsing("DESCRIBE_RECT",false);

	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
    SetEventHandler("exitCancel","ProcessCancelExit",0);
	SetEventHandler("ievnt_command","ProcessCommandExecute",0);

	SetEventHandler("FormatedTextActivate","procFTActivate",0);
	SetEventHandler("SetScrollerPos","procFTSetScrollPos",0);
	SetEventHandler("ScrollPosChange","ProcScrollPosChange",0);
	SetEventHandler("evntUpdateFormtText","procFTUpdate",0);
	SetEventHandler("ScrollTopChange","ProcScrollChange",0);

	SetAbilitesList();
}

void ProcessCancelExit()
{
	DoIExit(RC_INTERFACE_PERKS_EXIT);
}

void DoIExit(int exitCode)
{
	LanguageCloseFile(lngFileID);

	DelEventHandler("InterfaceBreak","ProcessCancelExit");
    DelEventHandler("exitCancel","ProcessCancelExit");
	DelEventHandler("ievnt_command","ProcessCommandExecute");
	DelEventHandler("FormatedTextActivate","procFTActivate");
	DelEventHandler("SetScrollerPos","procFTSetScrollPos");
	DelEventHandler("ScrollPosChange","ProcScrollPosChange");
	DelEventHandler("evntUpdateFormtText","procFTUpdate");
	DelEventHandler("ScrollTopChange","ProcScrollChange");

	interfaceResultCommand = exitCode;
	if( CheckAttribute(&InterfaceStates,"InstantExit") && sti(InterfaceStates.InstantExit)==true )
	{
		EndCancelInterface(true);
	}
	else
	{
		PostEvent("LaunchIAfterFrame",1,"sl", "I_CHARACTER", 1);
		EndCancelInterface(false);
	}
}

void ProcessCommandExecute()
{
	string comName = GetEventData();
	string nodName = GetEventData();

	switch(nodName)
	{
	case "OK_BUTTON":
		if(comName=="deactivate")
		{	ReturnToPerksView();
		}
		if(comName=="activate" || comName=="click")
		{	SetPerkToCharacter();
			ReturnToPerksView();
		}
	break;

	case "CANCEL_BUTTON":
		if(comName=="deactivate" || comName=="activate" || comName=="click")	{ReturnToPerksView();}
		if(comName=="leftstep")
		{	if(GetSelectable("OK_BUTTON"))
			{	SetCurrentNode("OK_BUTTON");
			}
		}
	break;
	}
}

void SetAbilitesList()
{
	int perksQ,i;
	string tmpStr,perkName;
	aref arPerksRoot,arChrPerk;

	chrPerksQ = 0;
	// Варианты перков, которые можно добавить
	makearef(arPerksRoot,ChrPerksList.list);
	perksQ = GetAttributesNum(arPerksRoot);
	for(i=0; i<perksQ; i++)
	{
		perkName = GetAttributeName(GetAttributeN(arPerksRoot,i));
		if(CheckPerkAvailable(perkName))
		{
			tmpStr = "perk"+chrPerksQ;
			GameInterface.perklist.(tmpStr) = perkName;
			tmpStr = LanguageConvertString(lngFileID,perkName);
			if(tmpStr=="") {tmpStr=" ";}
			SendMessage(&GameInterface,"lsle",MSG_INTERFACE_MSG_TO_NODE,"PERKSWINDOW", 0,&tmpStr);
			chrPerksQ++;
		}
	}

	// Варианты перков, которые имеются у нас
	makearef(arPerksRoot,refUsedCharacter.Perks.list);
	perksQ = GetAttributesNum(arPerksRoot);
	for(i=0; i<perksQ; i++)
	{
		perkName = GetAttributeName(GetAttributeN(arPerksRoot,i));
		if( !CheckPerkAvailable(perkName) )
		{
			tmpStr = "perk"+chrPerksQ;
			GameInterface.perklist.(tmpStr) = perkName;
			tmpStr = LanguageConvertString(lngFileID,perkName);
			if(tmpStr=="") {tmpStr=" ";}
			SendMessage(&GameInterface,"lsle",MSG_INTERFACE_MSG_TO_NODE,"PERKSWINDOW", 0,&tmpStr);
			chrPerksQ++;
		}
	}

	GameInterface.strings.FreeAbilitys = GetFreeAbilitysStr();

	Event("evntUpdateFormtText","sll","PERKSWINDOW",0,0);
}

bool CheckPerkAvailable(string perkName)
{
	return true;
	//if( CheckCharacterPerk(refUsedCharacter,perkName) ) return false;
	//return true;
}

void procFTActivate()
{
	string nodName = GetEventData();
	int texNum = GetEventData(); // номер текста
	if(nodName!="PERKSWINDOW") return;

	bool bEnableOk = texNum<chrPerksQ;
	if( !CheckAttribute(refUsedCharacter,"perks.FreePoints") || sti(refUsedCharacter.perks.FreePoints)<=0 )
		bEnableOk = false;
	if( GetPerkState(GetPerkName(texNum))!=1 )	bEnableOk = false;
	DoViewDescribe(GetPerkName(texNum),bEnableOk);
}

void procFTSetScrollPos()
{
	string nodName = GetEventData();
	float fpos = GetEventData();

	if(nodName!="PERKSWINDOW") return;
	SendMessage(&GameInterface,"lsf",MSG_INTERFACE_SET_SCROLLER,"SCROLL",fpos);
}

void ProcScrollPosChange()
{
	float newPos = GetEventData();
	SendMessage(&GameInterface,"lslf",MSG_INTERFACE_MSG_TO_NODE,"PERKSWINDOW",2, newPos);
}

string GetPerkName(int perkNum)
{
	string tmpstr = "perk"+perkNum;
	if(CheckAttribute(&GameInterface,"perklist."+tmpstr)) {
		return GameInterface.perklist.(tmpstr);
	}
	return "";
}

void DoViewDescribe(string perkName,bool enableOK)
{
	if(perkName=="") return;
	strPerkName = perkName;

	SetNodeUsing("DESCRIBEWINDOW",true);
	SetNodeUsing("PERK_NAME",true);
	SetNodeUsing("PERK_IMAGE",true);
	SetNodeUsing("OK_BUTTON",true);
	SetNodeUsing("CANCEL_BUTTON",true);
	SetNodeUsing("DESCRIBE_RECT",true);

	SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 1, "DESCRIBEWINDOW");
	SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 2, "OK_BUTTON");
	SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 2, "CANCEL_BUTTON");

	SendMessage(&GameInterface,"lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE,"PERK_NAME",0,
		"PerkName", LanguageConvertString(lngFileID,perkName), FONT_NORMAL,
		384,108, argb(255,255,255,255),0, SCRIPT_ALIGN_CENTER, true, 1.5, 420);

	SetNewPicture("PERK_IMAGE","interfaces\perks\128\" + perkName + ".tga");

	SetSelectable("OK_BUTTON",makeint(enableOK));

	SetCurrentNode("CANCEL_BUTTON");

	SetFormatedText("DESCRIBEWINDOW",LanguageConvertString(lngFileID,ChrPerksList.list.(perkName).descr));
	SendMessage(&GameInterface,"lsl",MSG_INTERFACE_MSG_TO_NODE,"DESCRIBEWINDOW", 5);

	perksIconsQ = 0;
	aref perkARef; makearef(perkARef,ChrPerksList.list.(perkName).condition);
	perksIconsQ = GetAttributesNum(perkARef);
	string abilName;
	for(int i=0; i<perksIconsQ; i++)
	{
		SetNodeUsing("CONDITION_"+i,true);
		SetNodeUsing("PLUS_"+i,true);
		abilName = GetAttributeName(GetAttributeN(perkARef,i));
		if( CheckCharacterPerk(refUsedCharacter,abilName) ) {
			SetNewPicture("CONDITION_"+i,"interfaces\perks\64\" + abilName + ".tga");
		} else {
			SetNewPicture("CONDITION_"+i,"interfaces\perks\64Disable\" + abilName + ".tga");
		}
	}
}

void ReturnToPerksView()
{
	SendMessage(&GameInterface,"ll", MSG_INTERFACE_LOCK_NODE, 0);

	string tmpstr;
	for(int i=0; i<perksIconsQ; i++)
	{
		SetNodeUsing("CONDITION_"+i,false);
		SetNodeUsing("PLUS_"+i,false);
	}
	perksIconsQ = 0;

	SetNodeUsing("DESCRIBEWINDOW",false);
	SetNodeUsing("PERK_NAME",false);
	SetNodeUsing("PERK_IMAGE",false);
	SetNodeUsing("OK_BUTTON",false);
	SetNodeUsing("CANCEL_BUTTON",false);
	SetNodeUsing("DESCRIBE_RECT",false);

	SetCurrentNode("PERKSWINDOW");
}

void SetPerkToCharacter()
{
	if(strPerkName=="") return;
	refUsedCharacter.perks.list.(strPerkName) = true;
	refUsedCharacter.perks.FreePoints = sti(refUsedCharacter.perks.FreePoints) - 1;
	Event("eSwitchPerks","l",sti(refUsedCharacter.index));

	GameInterface.strings.FreeAbilitys = GetFreeAbilitysStr();
	Event("evntUpdateFormtText","sll","PERKSWINDOW",g_nGroup,g_nLine);
}

void procFTUpdate()
{
	string nodName = GetEventData();
	if(nodName!="PERKSWINDOW") return;
	int grNum = GetEventData(); // первая группа в изменениях
	int strNum = GetEventData(); // первая строка в изменениях
	g_nGroup = grNum;
	g_nLine = strNum;

	object objPos;
	DeleteAttribute(&objPos,"");
	SendMessage(&GameInterface,"lsla",MSG_INTERFACE_MSG_TO_NODE,"PERKSWINDOW", 4,&objPos);

	string tmpstr;
	int imgQ = 0;
	int i,qn,topVal;
	int argbColor;
	int nPerkState;
	qn = GetAttributesNum(&objPos);
	for(i=0; i<qn; i++)
	{
		topVal = sti( GetAttributeValue(GetAttributeN(&objPos,i)) );
		if(topVal>=0)
		{
			tmpstr = GetPerkName(grNum);
			nPerkState = GetPerkState(tmpstr);
			switch(nPerkState)
			{
			case 0:		argbColor = argb(255,128,128,128); tmpstr = "64\"+tmpstr; break;
			case 1:		argbColor = argb(255,128,128,128); tmpstr = "64Disable\"+tmpstr; break;
			case 2:		argbColor = argb(255,128,128,128); tmpstr = "64Disable\"+tmpstr; break;
			}
			SetNodeUsing("PERK_ICON_"+imgQ,true);
			SetNodeUsing("PERK_STATE_"+imgQ, nPerkState==0);
			SetNewPicture("PERK_ICON_"+imgQ,"interfaces\perks\" + tmpstr + ".tga");
			SendMessage(&GameInterface,"lsll",MSG_INTERFACE_MSG_TO_NODE,"PERK_ICON_"+imgQ, 4,argbColor);
			imgQ++;
		}
		grNum++;
	}

	for(i=imgQ; i<imageQuantity; i++)
	{
		SetNodeUsing("PERK_ICON_"+i,false);
		SetNodeUsing("PERK_STATE_"+i,false);
	}
	imageQuantity = imgQ;
}

string GetFreeAbilitysStr()
{
	int nFreeAbilitys = 0;
	if( CheckAttribute(refUsedCharacter,"perks.FreePoints") )
		nFreeAbilitys = sti(refUsedCharacter.perks.FreePoints);
	return XI_ConvertString("Free points for abilitys") + ": " + nFreeAbilitys;
}

// 0 - уже есть, 1 - можно взять, 2 - нельзя получить
int GetPerkState(string perkName)
{
	if( CheckCharacterPerk(refUsedCharacter,perkName) ) return 0;

	int i,qn;
	aref arCondition, arCur;
	makearef(arCondition,ChrPerksList.list.(perkName).condition);
	qn = GetAttributesNum(arCondition);
	string needName;

	for(i=0; i<qn; i++)
	{
		arCur = GetAttributeN(arCondition,i);
		needName = GetAttributeName(arCur);
		if(needName=="rank") {
			if( sti(refUsedCharacter.rank) < sti(GetAttributeValue(arCur)) ) {
				break;
			}
		} else { if( CheckCharacterPerk(refUsedCharacter,needName)==false ) {break;}
		}
	}
	if(i<qn) return 2;

	return 1;
}

void ProcScrollChange()
{
	int changeNum = GetEventData();
	if(changeNum==0) return;
	if(changeNum>0) {
		SendMessage(&GameInterface,"lslll",MSG_INTERFACE_MSG_TO_NODE,"PERKSWINDOW",-1, 0,ACTION_DOWNSTEP);
	} else {
		SendMessage(&GameInterface,"lslll",MSG_INTERFACE_MSG_TO_NODE,"PERKSWINDOW",-1, 0,ACTION_UPSTEP);
	}
}


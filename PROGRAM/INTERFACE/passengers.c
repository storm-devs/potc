
#define NONEFACE_TEXTURE_NAME "interfaces\empty_face.tga"

#define ISHOW_MODE_CAPTIVE		0
#define ISHOW_MODE_SUMSKILL		1
#define ISHOW_MODE_CHRSKILL		2

string oldCurNode = "";
int oldShowMode = -1;

int nCurScrollNum;
int nFourImageNum;
ref _refCh;

int prisonFlag;
int prisonRansomCost;

string curLocNation = "";

void InitInterface_R(string iniName,ref _refCharacter)
{
    _refCh = _refCharacter;

    GameInterface.title = "titlePassengers";

    FillScroll();
	FillFourImages();

    SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);

    CreateString(true,"skillLeadership","",FONT_BOLD_NUMBERS,COLOR_NORMAL,300,232,SCRIPT_ALIGN_RIGHT,1.0);
    CreateString(true,"skillFencing","",FONT_BOLD_NUMBERS,COLOR_NORMAL,300,266,SCRIPT_ALIGN_RIGHT,1.0);
    CreateString(true,"skillSailing","",FONT_BOLD_NUMBERS,COLOR_NORMAL,300,300,SCRIPT_ALIGN_RIGHT,1.0);
    CreateString(true,"skillAccuracy","",FONT_BOLD_NUMBERS,COLOR_NORMAL,300,334,SCRIPT_ALIGN_RIGHT,1.0);
    CreateString(true,"skillCannons","",FONT_BOLD_NUMBERS,COLOR_NORMAL,300,368,SCRIPT_ALIGN_RIGHT,1.0);
    CreateString(true,"skillGrappling","",FONT_BOLD_NUMBERS,COLOR_NORMAL,434,232,SCRIPT_ALIGN_RIGHT,1.0);
    CreateString(true,"skillRepair","",FONT_BOLD_NUMBERS,COLOR_NORMAL,434,266,SCRIPT_ALIGN_RIGHT,1.0);
    CreateString(true,"skillDefence","",FONT_BOLD_NUMBERS,COLOR_NORMAL,434,300,SCRIPT_ALIGN_RIGHT,1.0);
    CreateString(true,"skillCommerce","",FONT_BOLD_NUMBERS,COLOR_NORMAL,434,334,SCRIPT_ALIGN_RIGHT,1.0);
    CreateString(true,"skillSneak","",FONT_BOLD_NUMBERS,COLOR_NORMAL,434,368,SCRIPT_ALIGN_RIGHT,1.0);

	CreateString(false,"CharacterName","",FONT_NORMAL,COLOR_NORMAL,320,196,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(false,"CharacterNation","",FONT_NORMAL,COLOR_NORMAL,320,230,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(false,"RansomCost","0",FONT_NORMAL,COLOR_NORMAL,320,266,SCRIPT_ALIGN_LEFT,1.0);

	SetNodeUsing("CAPTIVE_STRINGS",false);
	SetNodeUsing("CAPTIVE_IMAGES",false);
    SetNodeUsing("RELEASE_CAPTIVE",false);

	SetSelectable("RELEASE_CAPTIVE",false);

    SetVariable();

	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
    SetEventHandler("frame","ProcessFrame",1);
    SetEventHandler("exitCancel","ProcessCancelExit",0);

	SetEventHandler("PassengerDown","PassengerDown",0);
	SetEventHandler("ReleaseCaptive","PressReleaseCaptive",0);
	SetEventHandler("RemoveOfficer","ProcessOfficerRemove",0);
	SetEventHandler("ievnt_command","ProcessCommandExecute",0);
}

void FillFourImages()
{
	int i,cn;
	string attrName;
	ref refCurChar;
    nFourImageNum = -1;
	GameInterface.FourImage.current = 0;
	GameInterface.FourImage.ImagesGroup.t0 = "EMPTYFACE";
	GameInterface.FourImage.BadOnePicture = NONEFACE_TEXTURE_NAME;
	FillFaceList( "FourImage.ImagesGroup", _refCh, 0 ); // officers
	FillFaceList( "FourImage.ImagesGroup", _refCh, 2 ); // passengers

	for(i=0; i<4; i++)
	{
		attrName = "pic"+(i+1);
		cn = GetOfficersIndex(_refCh,i);
		GameInterface.FourImage.(attrName).selected = true;
		if(cn==-1)
		{
			GameInterface.FourImage.(attrName).img1 = "emptyface";
			GameInterface.FourImage.(attrName).tex1 = 0;
		}
		else
		{
			GameInterface.FourImage.(attrName).img1 = GetFacePicName(GetCharacter(cn));
			GameInterface.FourImage.(attrName).tex1 = FindFaceGroupNum("FourImage.ImagesGroup","FACE128_"+Characters[cn].FaceID);
		}
	}
}

void FillScroll()
{
    int i;
    string faceName;
    string attributeName;
	string PsgAttrName;
	int _curCharIdx;
	ref _refCurChar;
    aref pRef;

    nCurScrollNum = -1;
	GameInterface.passengerslist.current = 0;
	makearef(pRef,_refCh.Fellows.Passengers);
	int nListSize = GetPassengersQuantity(_refCh);
	GameInterface.passengerslist.NotUsed = 5;
	GameInterface.passengerslist.ListSize = nListSize;

	GameInterface.passengerslist.ImagesGroup.t0 = "EMPTYFACE";

	FillFaceList( "passengerslist.ImagesGroup", _refCh, 0 ); // officers
	FillFaceList( "passengerslist.ImagesGroup", _refCh, 2 ); // passengers

	GameInterface.passengerslist.BadTex1 = 0;
	GameInterface.passengerslist.BadPic1 = "emptyface";

    for(i=0; i<nListSize; i++)
    {
		attributeName = "pic" + (i+1);
		PsgAttrName = "id"+(i+1);
        _curCharIdx = sti(pRef.(PsgAttrName));
		if(_curCharIdx!=-1)
		{
			GameInterface.passengerslist.(attributeName).img1 = GetFacePicName(GetCharacter(_curCharIdx));
			GameInterface.passengerslist.(attributeName).tex1 = FindFaceGroupNum("passengerslist.ImagesGroup","FACE128_"+Characters[_curCharIdx].FaceID);
		}
		else
		{
			GameInterface.passengerslist.(attributeName).img1 = "emptyface";
			GameInterface.passengerslist.(attributeName).tex1 = 0;
		}
    }
}

void ProcessFrame()
{
	string curName = GetCurrentNode();
	if(oldCurNode!=curName)
	{
		oldCurNode = curName;
		if(curName=="PASSENGERSLIST")
		{
			nCurScrollNum = -1;
		}
		if(curName=="OFFICERSLIST")
		{
			nFourImageNum = -1;
		}
	}

    if(sti(GameInterface.passengerslist.current)!=nCurScrollNum)
    {
		DoScrollChange();
    }

    if(sti(GameInterface.FourImage.current)!=nFourImageNum)
    {
		DoFourImageChange();
    }
}

void DoScrollChange()
{
	nCurScrollNum   = sti(GameInterface.passengerslist.current);

	ref chPsgn;
	int psgIdx = GetPassenger(_refCh,nCurScrollNum);
	prisonFlag = false;
	if(psgIdx>=0)
	{
		chPsgn = GetCharacter(psgIdx);
		if(CheckAttribute(chPsgn,"prisoned")==true)
		{
			prisonFlag = sti(chPsgn.prisoned);
		}
	}

	if(prisonFlag==true)
	{
		SetShowMode(ISHOW_MODE_CAPTIVE);
		if( GetRemovable(chPsgn) && CheckAttribute(chPsgn,"nation") && chPsgn.nation==curLocNation )
		{
			SetSelectable("RELEASE_CAPTIVE",true);
		}
		else
		{
			SetSelectable("RELEASE_CAPTIVE",false);
		}
		SetCaptiveData(chPsgn);
	}
	else
	{
		if(psgIdx<0)
		{
			SetShowMode(ISHOW_MODE_SUMSKILL);
			SetSumSkillData();
		}
		else
		{
			SetShowMode(ISHOW_MODE_CHRSKILL);
			SetChrSkillData(GetCharacter(psgIdx));
		}
	}
}

int GetPrisonRansomCost(object refCharacter)
{
	return sti(refCharacter.money);
}

void DoFourImageChange()
{
	int cn = -1;
	nFourImageNum = sti(GameInterface.FourImage.current);
	SetSelectable("REMOVE_OFFICER",false);
	if(nFourImageNum>0)
	{
		cn = GetOfficersIndex(_refCh,nFourImageNum);
		if(cn>=0)
		{
			SetSelectable("REMOVE_OFFICER",GetRemovable(GetCharacter(cn)));
		}
	}

	if(cn<0)
	{
		SetShowMode(ISHOW_MODE_SUMSKILL);
		SetSumSkillData();
	}
	else
	{
		SetShowMode(ISHOW_MODE_CHRSKILL);
		SetChrSkillData(GetCharacter(cn));
	}
}

void SetVariable()
{
	prisonFlag = false;
	prisonRansomCost = 0;
	curLocNation = GetCurrentLocationNation();
	SetSumSkillData();
}

void ProcessCancelExit()
{
	IDoExit(RC_INTERFACE_PASSENGERS_EXIT);
}

void ProcessOfficerRemove()
{
	if(nFourImageNum==0)
	{
		ShowHelpString("chelp_passengers#10");
	}
	else
	{
		int cn = GetOfficersIndex(_refCh,nFourImageNum);
		if(cn==-1)
		{
			ShowHelpString("chelp_passengers#11");
		}
		else
		{
			ref _refComp = GetCharacter(cn);
			if( GetRemovable(_refComp)==false )
			{
				ShowHelpString("chelp_passengers#15");
				return;
			}

			XI_ChangeOfficer(nFourImageNum,-1);

			ShowHelpString("chelp_passengers#12");
			SetCurrentNode("OFFICERSLIST");
			SetSelectable("REMOVE_OFFICER",false);
		}
	}
}

int XI_ChangeOfficer(int OfficerNum, int idxNew)
{
	int tmpIdx = GetOfficersIndex(_refCh,OfficerNum);
	if(tmpIdx!=-1)
	{
		ref chref = GetCharacter(tmpIdx);
		if( CheckAttribute(chref,"NonRemovable") && sti(chref.NonRemovable)==true ) return idxNew;
	}
	string attrName = "pic"+(OfficerNum+1);
	GameInterface.FourImage.(attrName).selected = true;
	int changeIdx = OfficerNum;
	if(idxNew==-1)
	{
		GameInterface.FourImage.(attrName).img1 = "emptyface";
		GameInterface.FourImage.(attrName).tex1 = 0;
	}
	else
	{
		for(int i=1;i<4;i++)
		{
			if(idxNew==GetOfficersIndex(_refCh,i))
			{
				XI_ChangeOfficer(i,-1);
			}
		}
		GameInterface.FourImage.(attrName).img1 = GetFacePicName(GetCharacter(idxNew));
		GameInterface.FourImage.(attrName).tex1 = FindFaceGroupNum("FourImage.ImagesGroup","FACE128_"+Characters[idxNew].FaceID);
	}
	SendMessage(&GameInterface,"lsl", MSG_INTERFACE_FOURIMAGE_CHANGE, "OFFICERSLIST", changeIdx);
	nFourImageNum = -1;
	int retVal = SetOfficersIndex(_refCh,OfficerNum,idxNew);
	SetSumSkillData();
	return retVal;
}

void ProcessOfficerSet()
{
	int cn;
	int oldIdx;
	ref chref;

	if(nFourImageNum==0)
	{
		ShowHelpString("chelp_passengers#13");
	}
	else
	{
		cn = GetPassenger(_refCh,nCurScrollNum);
		if(cn==-1)
		{
			ShowHelpString("chelp_passengers#14");
		}
		else
		{
			chref = GetCharacter(cn);
			if( CheckAttribute(chref,"prisoned") && sti(chref.prisoned)==true )
			{
				ShowHelpString("chelp_passengers#16");
				return;
			}
			if( GetRemovable(chref)==false )
			{
				ShowHelpString("chelp_passengers#16");
				return;
			}
			oldIdx = GetOfficersIndex(_refCh,nFourImageNum);
			if(oldIdx!=-1)
			{
				if( GetRemovable(GetCharacter(oldIdx))==false )
				{
					ShowHelpString("chelp_passengers#15");
					return;
				}
			}
			XI_ChangeOfficer(nFourImageNum,cn);
		}
	}
}

void PressReleaseCaptive()
{
	if(prisonFlag!=true) return;
	int captiveIdx = GetPassenger(_refCh,nCurScrollNum);
	if(captiveIdx==-1) return;
	ref captiveCharacter = GetCharacter(captiveIdx);
	if( !GetRemovable(captiveCharacter) ) return;
	AddMoneyToCharacter(_refCh,prisonRansomCost);
	DeleteAttribute(captiveCharacter,"prisoned"); // освободили пленника
	DelFromScroll("PASSENGERSLIST",nCurScrollNum);
	SetCurrentNode("PASSENGERSLIST");
	for(int i=1;i<4;i++)
	{
		if(captiveIdx==GetOfficersIndex(_refCh,i))
		{
			XI_ChangeOfficer(i,-1);
		}
	}
	RemovePassenger(_refCh,captiveCharacter);
	nCurScrollNum=-1;
}

void PassengerDown()
{
	if(nFourImageNum==0) return;
	int cn = GetOfficersIndex(_refCh,nFourImageNum);
	if(cn==-1) return;
	if( GetRemovable(_refCh) ) SetCurrentNode("REMOVE_OFFICER");
}

void IDoExit(int exitCode)
{
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
    DelEventHandler("frame","ProcessFrame");
    DelEventHandler("exitCancel","ProcessCancelExit");
	DelEventHandler("PassengerDown","PassengerDown");
	DelEventHandler("ReleaseCaptive","PressReleaseCaptive");
	DelEventHandler("RemoveOfficer","ProcessOfficerRemove");
	DelEventHandler("ievnt_command","ProcessCommandExecute");

	interfaceResultCommand = exitCode;
	if( CheckAttribute(&InterfaceStates,"InstantExit") && sti(InterfaceStates.InstantExit)==true )
	{
		EndCancelInterface(true);
	}
	else
	{
		PostEvent("LaunchIAfterFrame",1,"sl", "I_SELECTMENU", 1);
		EndCancelInterface(false);
	}
}

void SetShowMode(int sm)
{
	if(oldShowMode==sm) return;

	switch(oldShowMode)
	{

	case ISHOW_MODE_CAPTIVE:
		DisableString("CharacterName");
		DisableString("CharacterNation");
		DisableString("RansomCost");
		SetNodeUsing("CAPTIVE_STRINGS",false);
		SetNodeUsing("CAPTIVE_IMAGES",false);
		SetNodeUsing("RELEASE_CAPTIVE",false);
	break;

	case ISHOW_MODE_SUMSKILL:
		DisableString("skillLeadership");
		DisableString("skillFencing");
		DisableString("skillSailing");
		DisableString("skillAccuracy");
		DisableString("skillCannons");
		DisableString("skillGrappling");
		DisableString("skillRepair");
		DisableString("skillDefence");
		DisableString("skillCommerce");
		DisableString("skillSneak");
		SetNodeUsing("SUMMARYSTRINGS",false);
		SetNodeUsing("SUMMARYIMAGES",false);
	break;

	case ISHOW_MODE_CHRSKILL:
		DisableString("skillLeadership");
		DisableString("skillFencing");
		DisableString("skillSailing");
		DisableString("skillAccuracy");
		DisableString("skillCannons");
		DisableString("skillGrappling");
		DisableString("skillRepair");
		DisableString("skillDefence");
		DisableString("skillCommerce");
		DisableString("skillSneak");
		DisableString("CharacterName");
		SetNodeUsing("SUMMARYIMAGES",false);
	break;

	}

	oldShowMode = sm;

	switch(sm)
	{

	case ISHOW_MODE_CAPTIVE:
		EnableString("CharacterName");
		EnableString("CharacterNation");
		EnableString("RansomCost");
		SetNodeUsing("CAPTIVE_STRINGS",true);
		SetNodeUsing("CAPTIVE_IMAGES",true);
		SetNodeUsing("RELEASE_CAPTIVE",true);
	break;

	case ISHOW_MODE_SUMSKILL:
		EnableString("skillLeadership");
		EnableString("skillFencing");
		EnableString("skillSailing");
		EnableString("skillAccuracy");
		EnableString("skillCannons");
		EnableString("skillGrappling");
		EnableString("skillRepair");
		EnableString("skillDefence");
		EnableString("skillCommerce");
		EnableString("skillSneak");
		SetNodeUsing("SUMMARYSTRINGS",true);
		SetNodeUsing("SUMMARYIMAGES",true);
	break;

	case ISHOW_MODE_CHRSKILL:
		EnableString("skillLeadership");
		EnableString("skillFencing");
		EnableString("skillSailing");
		EnableString("skillAccuracy");
		EnableString("skillCannons");
		EnableString("skillGrappling");
		EnableString("skillRepair");
		EnableString("skillDefence");
		EnableString("skillCommerce");
		EnableString("skillSneak");
		EnableString("CharacterName");
		SetNodeUsing("SUMMARYIMAGES",true);
	break;

	}
}

void SetSumSkillData()
{
	ref chref = _refCh;

	GameInterface.strings.skillLeadership = GetSummonSkillFromName(chref,SKILL_LEADERSHIP);
	GameInterface.strings.skillFencing = GetSummonSkillFromName(chref,SKILL_FENCING);
	GameInterface.strings.skillSailing = GetSummonSkillFromName(chref,SKILL_SAILING);
	GameInterface.strings.skillAccuracy = GetSummonSkillFromName(chref,SKILL_ACCURACY);
	GameInterface.strings.skillCannons = GetSummonSkillFromName(chref,SKILL_CANNONS);
	GameInterface.strings.skillGrappling = GetSummonSkillFromName(chref,SKILL_GRAPPLING);
	GameInterface.strings.skillRepair = GetSummonSkillFromName(chref,SKILL_REPAIR);
	GameInterface.strings.skillDefence = GetSummonSkillFromName(chref,SKILL_DEFENCE);
	GameInterface.strings.skillCommerce = GetSummonSkillFromName(chref,SKILL_COMMERCE);
	GameInterface.strings.skillSneak = GetSummonSkillFromName(chref,SKILL_SNEAK);
}

void SetChrSkillData(ref chref)
{
	GameInterface.strings.skillLeadership = GetCharacterSkill(chref,SKILL_LEADERSHIP);
	GameInterface.strings.skillFencing = GetCharacterSkill(chref,SKILL_FENCING);
	GameInterface.strings.skillSailing = GetCharacterSkill(chref,SKILL_SAILING);
	GameInterface.strings.skillAccuracy = GetCharacterSkill(chref,SKILL_ACCURACY);
	GameInterface.strings.skillCannons = GetCharacterSkill(chref,SKILL_CANNONS);
	GameInterface.strings.skillGrappling = GetCharacterSkill(chref,SKILL_GRAPPLING);
	GameInterface.strings.skillRepair = GetCharacterSkill(chref,SKILL_REPAIR);
	GameInterface.strings.skillDefence = GetCharacterSkill(chref,SKILL_DEFENCE);
	GameInterface.strings.skillCommerce = GetCharacterSkill(chref,SKILL_COMMERCE);
	GameInterface.strings.skillSneak = GetCharacterSkill(chref,SKILL_SNEAK);
	GameInterface.strings.CharacterName = chref.name + " " + chref.lastname;
}

void SetCaptiveData(ref chref)
{
	GameInterface.strings.CharacterName = chref.name + " " + chref.lastname;
	GameInterface.strings.CharacterNation = Nations[sti(chref.nation)].Name;
	prisonRansomCost = GetPrisonRansomCost(chref);
	GameInterface.strings.RansomCost = MakeMoneyShow(prisonRansomCost,"",MONEY_DELIVER);
}

void ProcessCommandExecute()
{
	string comName = GetEventData();
	string nodName = GetEventData();

	switch(nodName)
	{

	case "PASSENGERSLIST":
		if(comName=="activate")
		{
			if( GetSelectable("RELEASE_CAPTIVE") )	SetCurrentNode("RELEASE_CAPTIVE");
			else
			{
				if(prisonFlag==false)	{ProcessOfficerSet();}
			}
		}
		if(comName=="downstep")
		{
			if( GetSelectable("RELEASE_CAPTIVE") )	{SetCurrentNode("RELEASE_CAPTIVE");}
			else
			{
				if( GetSelectable("REMOVE_OFFICER") )	{SetCurrentNode("REMOVE_OFFICER");}
			}
		}
	break;

	case "RELEASE_CAPTIVE":
		if(comName=="downstep")
		{
			if( GetSelectable("REMOVE_OFFICER") )	{SetCurrentNode("REMOVE_OFFICER");}
		}
	break;

	case "REMOVE_OFFICER":
		if(comName=="upstep")
		{
			if( GetSelectable("RELEASE_CAPTIVE") )	{SetCurrentNode("RELEASE_CAPTIVE");}
			else	{SetCurrentNode("PASSENGERSLIST");}
		}
	break;

	}
}

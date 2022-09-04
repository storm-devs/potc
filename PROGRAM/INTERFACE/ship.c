#define	SM_NONE		0
#define	SM_CANNONS	1
#define	SM_SKILLS	2
#define	SM_CREW		3
#define	SM_SAILS	4
#define	SM_HULL		5

// 0xFF606060
#define minBlindColor	4281348144	//4284506208
// 0xFF808080
#define maxBlindColor	4288716960

int nShowMode;

bool bEnableInterfaceChange;
int	nCurFourNum;
string oldCurNode;

void InitInterface_I(string iniName,int bIState)
{
	nShowMode = SM_NONE;
	bEnableInterfaceChange = bIState;
	if(bIState==false)
	{
	    GameInterface.title = "titleStore";
	}
	else
	{
	    GameInterface.title = "titleShip";
	}
    GameInterface.FourImage.current = 0;

    FillFourImages();

    SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);

	ref refMyCh = GetMainCharacter();
	CreateString(true,"CharName",XI_ConvertString("Noname"),FONT_NORMAL,COLOR_NORMAL,320,196,SCRIPT_ALIGN_CENTER,1.0);
    CreateString(true,"Hull","100%",FONT_BOLD_NUMBERS,COLOR_NORMAL,63,144,SCRIPT_ALIGN_CENTER,1.0);
    CreateString(true,"Sails","100%",FONT_BOLD_NUMBERS,COLOR_NORMAL,191,144,SCRIPT_ALIGN_CENTER,1.0);
    CreateString(true,"Crew","0",FONT_BOLD_NUMBERS,COLOR_NORMAL,447,144,SCRIPT_ALIGN_CENTER,1.0);
    CreateString(true,"Cannons","0",FONT_BOLD_NUMBERS,COLOR_NORMAL,575,144,SCRIPT_ALIGN_CENTER,1.0);
    CreateString(true,"Money",MakeMoneyShow(sti(refMyCh.money),MONEY_SIGN,MONEY_DELIVER),FONT_NORMAL,COLOR_MONEY,320,391,SCRIPT_ALIGN_CENTER,1.0);

    CreateString(true,"THull",XI_ConvertString("Hull"),FONT_NORMAL,COLOR_NORMAL,63,34,SCRIPT_ALIGN_CENTER,1.0);
    CreateString(true,"TSails",XI_ConvertString("Sails"),FONT_NORMAL,COLOR_NORMAL,191,34,SCRIPT_ALIGN_CENTER,1.0);
    CreateString(true,"TCrew",XI_ConvertString("Crew"),FONT_NORMAL,COLOR_NORMAL,447,34,SCRIPT_ALIGN_CENTER,1.0);
    CreateString(true,"TCannons",XI_ConvertString("Cannons"),FONT_NORMAL,COLOR_NORMAL,575,34,SCRIPT_ALIGN_CENTER,1.0);

	// none strings
    CreateString(true,"ShipSpeed","0",FONT_NORMAL,COLOR_NORMAL,220,279,SCRIPT_ALIGN_LEFT,1.0);
    CreateString(true,"ShipManeuver","0",FONT_NORMAL,COLOR_NORMAL,220,314,SCRIPT_ALIGN_LEFT,1.0);
    CreateString(true,"ShipMaxCaliber","0",FONT_NORMAL,COLOR_NORMAL,220,349,SCRIPT_ALIGN_LEFT,1.0);
    CreateString(true,"ShipMaxCrew","0",FONT_NORMAL,COLOR_NORMAL,416,279,SCRIPT_ALIGN_LEFT,1.0);
    CreateString(true,"ShipMinCrew","0",FONT_NORMAL,COLOR_NORMAL,416,314,SCRIPT_ALIGN_LEFT,1.0);
    CreateString(true,"ShipCapacity","0",FONT_NORMAL,COLOR_NORMAL,416,349,SCRIPT_ALIGN_LEFT,1.0);
	// summary strings
    CreateString(false,"SummarySkill",XI_ConvertString("Summary Skills")+":",FONT_NORMAL,COLOR_NORMAL,320,264,SCRIPT_ALIGN_CENTER,1.0);
    CreateString(false,"SLeadership","0",FONT_BOLD_NUMBERS,COLOR_NORMAL,252,294,SCRIPT_ALIGN_LEFT,1.0);
    CreateString(false,"SFencing","0",FONT_BOLD_NUMBERS,COLOR_NORMAL,252,326,SCRIPT_ALIGN_LEFT,1.0);
    CreateString(false,"SSailing","0",FONT_BOLD_NUMBERS,COLOR_NORMAL,252,358,SCRIPT_ALIGN_LEFT,1.0);
    CreateString(false,"SAccuracy","0",FONT_BOLD_NUMBERS,COLOR_NORMAL,252,390,SCRIPT_ALIGN_LEFT,1.0);
    CreateString(false,"SCannons","0",FONT_BOLD_NUMBERS,COLOR_NORMAL,252,422,SCRIPT_ALIGN_LEFT,1.0);
    CreateString(false,"SGrappling","0",FONT_BOLD_NUMBERS,COLOR_NORMAL,416,294,SCRIPT_ALIGN_LEFT,1.0);
    CreateString(false,"SRepair","0",FONT_BOLD_NUMBERS,COLOR_NORMAL,416,326,SCRIPT_ALIGN_LEFT,1.0);
    CreateString(false,"SDefence","0",FONT_BOLD_NUMBERS,COLOR_NORMAL,416,358,SCRIPT_ALIGN_LEFT,1.0);
    CreateString(false,"SCommerce","0",FONT_BOLD_NUMBERS,COLOR_NORMAL,416,390,SCRIPT_ALIGN_LEFT,1.0);
    CreateString(false,"SSneak","0",FONT_BOLD_NUMBERS,COLOR_NORMAL,416,422,SCRIPT_ALIGN_LEFT,1.0);
	// cannons strings
    CreateString(false,"CannonsName","",FONT_NORMAL,COLOR_NORMAL,320,266,SCRIPT_ALIGN_CENTER,1.25);
    CreateString(false,"FireRange","0",FONT_NORMAL,COLOR_NORMAL,416,310,SCRIPT_ALIGN_RIGHT,1.0);
    CreateString(false,"ReloadTime","0",FONT_NORMAL,COLOR_NORMAL,416,346,SCRIPT_ALIGN_RIGHT,1.0);
	// crew strings
    CreateString(false,"CrewMorale","",FONT_NORMAL,COLOR_NORMAL,320,272,SCRIPT_ALIGN_CENTER,1.0);
    CreateString(false,"RaiseCost","",FONT_NORMAL,COLOR_NORMAL,320,352,SCRIPT_ALIGN_CENTER,1.0);
	// sail strings
	CreateString(false,"SailSpeeding","",FONT_NORMAL,COLOR_NORMAL,320,268,SCRIPT_ALIGN_CENTER,1.0);
		// can`repair of out sailcloth
	CreateString(false,"SRepCantMain",XI_ConvertString("Cannot start repair"),FONT_NORMAL,COLOR_NORMAL,320,300,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(false,"SRepCantSailcloth",XI_ConvertString("Out of sailcloth"),FONT_NORMAL,COLOR_NORMAL,320,328,SCRIPT_ALIGN_CENTER,1.0);
		// can`repair skill not enough
	CreateString(false,"SRepCantSkill1",XI_ConvertString("Repair skill is not"),FONT_NORMAL,COLOR_NORMAL,320,328,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(false,"SRepCantSkill2",XI_ConvertString("high enough"),FONT_NORMAL,COLOR_NORMAL,320,356,SCRIPT_ALIGN_CENTER,1.0);
		// undamaged
	CreateString(false,"SailsUndamaged1",XI_ConvertString("Sails are in"),FONT_NORMAL,COLOR_NORMAL,320,298,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(false,"SailsUndamaged2",XI_ConvertString("a perfect condition"),FONT_NORMAL,COLOR_NORMAL,320,328,SCRIPT_ALIGN_CENTER,1.0);
		// repairing
	CreateString(false,"SRepairing1",XI_ConvertString("Repairing")+"...",FONT_NORMAL,COLOR_NORMAL,320,300,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(false,"SRepairing2","",FONT_NORMAL,COLOR_NORMAL,320,328,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(false,"SRepairing3","",FONT_NORMAL,COLOR_NORMAL,320,356,SCRIPT_ALIGN_CENTER,1.0);
	// hull strings
	CreateString(false,"HullSpeeding","",FONT_NORMAL,COLOR_NORMAL,320,268,SCRIPT_ALIGN_CENTER,1.0);
		// can`repair of out plank
	CreateString(false,"HRepCantMain",XI_ConvertString("Cannot start repair"),FONT_NORMAL,COLOR_NORMAL,320,300,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(false,"HRepCantPlank",XI_ConvertString("Out of planks"),FONT_NORMAL,COLOR_NORMAL,320,328,SCRIPT_ALIGN_CENTER,1.0);
		// can`repair skill not enough
	CreateString(false,"HRepCantSkill1",XI_ConvertString("Repair skill is not"),FONT_NORMAL,COLOR_NORMAL,320,328,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(false,"HRepCantSkill2",XI_ConvertString("high enough"),FONT_NORMAL,COLOR_NORMAL,320,356,SCRIPT_ALIGN_CENTER,1.0);
		// undamaged
	CreateString(false,"HullUndamaged1",XI_ConvertString("Hull is in"),FONT_NORMAL,COLOR_NORMAL,320,298,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(false,"HullUndamaged2",XI_ConvertString("a perfect condition"),FONT_NORMAL,COLOR_NORMAL,320,328,SCRIPT_ALIGN_CENTER,1.0);
		// repairing
	CreateString(false,"HRepairing1",XI_ConvertString("Repairing")+"...",FONT_NORMAL,COLOR_NORMAL,320,300,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(false,"HRepairing2","",FONT_NORMAL,COLOR_NORMAL,320,328,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(false,"HRepairing3","",FONT_NORMAL,COLOR_NORMAL,320,356,SCRIPT_ALIGN_CENTER,1.0);

	if(bIState==false)
	{
		SetNodeUsing("RHULL",false);
		SetNodeUsing("RSAILS",false);
		SetNodeUsing("RFACE",false);
		SetNodeUsing("RCREW",false);
		SetNodeUsing("RCANNONS",false);
	}

    CreateImage("face","FACE128_"+refMyCh.FaceId,"face",256,42,384,170);
	CreateImage("Hull","SHIP_STATE_ICONS","Hull",0,42,128,170);
	CreateImage("Sails","SHIP_STATE_ICONS","Sails",128,42,256,170);
	CreateImage("Crew","SHIP_STATE_ICONS","Crew",384,42,512,170);
	CreateImage("Cannons","SHIP_STATE_ICONS","Cannons",512,42,640,170);

	GameInterface.renamebox.strdata = "";
	GameInterface.renamebox.maxlen = 32;
	GameInterface.renamebox.maxwidth = 240;

	SetNodeUsing("CANNONS_STRINGS",false);
	SetNodeUsing("CANNONS_LINES",false);
	SetNodeUsing("SKILL_IMAGES",false);
	SetNodeUsing("CREW_BUTTON",false);
	SetNodeUsing("SAILS_LINES",false);
	SetNodeUsing("RENAMEBOX",false);

	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
    SetEventHandler("frame","ProcessFrame",1);
    SetEventHandler("exitOk","ProcessOkExit",0);
    SetEventHandler("exitCancel","ProcessCancelExit",0);
	SetEventHandler("RaiseItPress","ProcessRaiseIt",0);
	SetEventHandler("RaiseSelectPress","ProcessRaiseSelect",0);
	SetEventHandler("NodeOk","ProcessNodeOk",0);
	SetEventHandler("NodeCancel","ProcessNodeCancel",0);
	SetEventHandler("ShipNameChange","ProcessShipNameChange",0);
	SetEventHandler("ievntGetHelpTexture","iprocGetHelpTexture",0);

	oldCurNode = "SHIPSLIST";
	ProcessFrame();
}

void FillFourImages()
{
    int i;
    string tmp1,tmp2,tmpStr;
    int tmpID;
	int bSelected;

    GameInterface.FourImage.current = 0;
	GameInterface.FourImage.BadTwoPicture = "interfaces\blank_ship.tga";
	GameInterface.FourImage.ImagesGroup.t0 = "ICONS";
	GameInterface.FourImage.ImagesGroup.t1 = "SHIPS16";
	GameInterface.FourImage.ImagesGroup.t2 = "SHIPS1";
	ref refMainCh = GetMainCharacter();
    for(i=0; i<4; i++)
    {
		bSelected=true;
		tmpID = GetCompanionIndex(refMainCh,i);
		if(tmpID!=-1)	tmpID = sti(Characters[tmpID].Ship.Type);
		else
		{
			tmpStr = "shipslot"+i;
			if(CheckAttribute(refMainCh,tmpStr+".Type"))
				tmpID = sti(refMainCh.(tmpStr).Type);
			else	tmpID = SHIP_NOTUSED;
		}
		if(tmpID==SHIP_NOTUSED)
		{
			tmp1="";
			tmp2="";
			bSelected=false;
		}
		else
		{
			tmp1 = ShipsTypes[tmpID].Class;
			tmp2 = ShipsTypes[tmpID].Name;
		}
		tmpStr = "pic"+(i+1);
		GameInterface.FourImage.(tmpStr).selected	= bSelected;
		GameInterface.FourImage.(tmpStr).img1		= "ship back";
		if(GetShipTexture(tmp2)!=-1)	GameInterface.FourImage.(tmpStr).img2 = tmp2;
		GameInterface.FourImage.(tmpStr).str1		= "#"+tmp1;
		GameInterface.FourImage.(tmpStr).str2		= XI_ConvertString(tmp2);
		GameInterface.FourImage.(tmpStr).tex1		= 0;
		GameInterface.FourImage.(tmpStr).tex2		= 1+GetShipTexture(tmp2);
    }
	nCurFourNum = -1;
}

void ProcessFrame()
{
	float ftmp;
	if(oldCurNode!=GetCurrentNode())
	{
		switch(oldCurNode)
		{
		case "RFACE":		SetPictureBlind("face",false,0,0); break;
		case "RHULL":		SetPictureBlind("Hull",false,0,0); break;
		case "RSAILS":		SetPictureBlind("Sails",false,0,0); break;
		case "RCREW":		SetPictureBlind("Crew",false,0,0); break;
		case "RCANNONS":	SetPictureBlind("Cannons",false,0,0); break;
		case "RENAMEBOX":	SendMessage(&GameInterface,"ll", MSG_INTERFACE_LOCK_NODE, 0); break;
		}
		oldCurNode=GetCurrentNode();
		switch(oldCurNode)
		{
		case "SHIPSLIST":
			SetShowMode(SM_NONE);
		break;
		case "RFACE":
			SetShowMode(SM_SKILLS);
			SetPictureBlind("face",true,minBlindColor,maxBlindColor);
		break;
		case "RHULL":
			SetShowMode(SM_HULL);
			SetPictureBlind("Hull",true,minBlindColor,maxBlindColor);
		break;
		case "RSAILS":
			SetShowMode(SM_SAILS);
			SetPictureBlind("Sails",true,minBlindColor,maxBlindColor);
		break;
		case "RCREW":
			SetShowMode(SM_CREW);
			SetPictureBlind("Crew",true,minBlindColor,maxBlindColor);
		break;
		case "RCANNONS":
			SetShowMode(SM_CANNONS);
			SetPictureBlind("Cannons",true,minBlindColor,maxBlindColor);
		break;
		}
	}
    if(sti(GameInterface.FourImage.current)!=nCurFourNum)
    {
		nCurFourNum = sti(GameInterface.FourImage.current);

		ref refMyCh = GetMainCharacter();
		int cn = GetCompanionIndex(refMyCh,nCurFourNum);
		int shipType = SHIP_NOTUSED;
		if(cn==-1)
		{
			GameInterface.pictures.face.tex = "";
			string slotName = "ShipSlot"+nCurFourNum;
			if(CheckAttribute(refMyCh,slotName))	shipType = sti(refMyCh.(slotName).Type);
		}
		else
		{
			ref otherCh = GetCharacter(cn);
			GameInterface.pictures.face.tex = "FACE128_"+otherCh.FaceId;
			shipType = sti(otherCh.ship.Type);
		}

		if(shipType!=SHIP_NOTUSED)
		{
			ref refBaseShip = GetShipByType(shipType);
			if(cn==-1)
			{
				SendMessage(&GameInterface,"lsls", MSG_INTERFACE_MSG_TO_NODE, "B_SHIPNAME", 0, refMyCh.(slotName).Name);
				if(CheckAttribute(refMyCh,slotName+".HP"))
				{
					ftmp = GetHullPercent(refMyCh);
					if(ftmp<1.0) {
						GameInterface.strings.Hull = FloatToString(ftmp,1)+"%";
					} else {
						GameInterface.strings.Hull = MakeInt(ftmp)+"%";
					}
				} else {
					GameInterface.strings.Hull = "100%";
				}

				if(CheckAttribute(refMyCh,slotName+".SP"))
				{
					ftmp = GetSailPercent(refMyCh);
					if(ftmp<1.0) {
						GameInterface.strings.Sails = FloatToString(ftmp,1)+"%";
					} else {
						GameInterface.strings.Sails = MakeInt(ftmp)+"%";
					}
				} else {
					GameInterface.strings.Sails = "100%";
				}

				if(CheckAttribute(refMyCh,slotName+".Crew")) {
					GameInterface.strings.Crew = MakeInt(refMyCh.(slotName).Crew);
				} else {
					GameInterface.strings.Crew = 0;
				}

				GameInterface.strings.CharName = XI_ConvertString("Noname");
			}
			else
			{
				SendMessage(&GameInterface,"lsls", MSG_INTERFACE_MSG_TO_NODE, "B_SHIPNAME", 0, otherCh.Ship.Name);
				ftmp = GetHullPercent(otherCh);
				if(ftmp<1.0) {
					GameInterface.strings.Hull = FloatToString(ftmp,1)+"%";
				} else {
					GameInterface.strings.Hull = MakeInt(ftmp)+"%";
				}

				ftmp = GetSailPercent(otherCh);
				if(ftmp<1.0) {
					GameInterface.strings.Sails = FloatToString(ftmp,1)+"%";
				} else {
					GameInterface.strings.Sails = MakeInt(ftmp)+"%";
				}

				GameInterface.strings.Crew = MakeInt(otherCh.Ship.Crew.Quantity);
				GameInterface.strings.CharName = otherCh.name+" "+otherCh.lastname;
			}
			GameInterface.strings.Cannons = refBaseShip.CannonsQuantity;
		}
		else
		{
			SendMessage(&GameInterface,"lsls", MSG_INTERFACE_MSG_TO_NODE, "B_SHIPNAME", 0, XI_ConvertString("Not Used"));
			GameInterface.strings.Hull = "100%";
			GameInterface.strings.Sails = "100%";
			GameInterface.strings.Crew = 0;
			GameInterface.strings.CharName = XI_ConvertString("Noname");
			GameInterface.strings.Cannons = 0;
		}

		switch(nShowMode)
		{
		case SM_NONE:		SetNoneData();		break;
		case SM_CANNONS:	SetCannonsData();	break;
		case SM_SKILLS:		SetSkillData();		break;
		case SM_CREW:		SetCrewData();		break;
		case SM_SAILS:		SetSailsData();		break;
		case SM_HULL:		SetHullsData();		break;
		}

		if( GetCurrentNode()=="CREW_BUTTON" && !GetSelectable("CREW_BUTTON") ) SetCurrentNode("RCREW");
    }
}

void ProcessCancelExit()
{
	IDoExit(RC_INTERFACE_SHIPSTATE_EXIT);
}

void ProcessOkExit()
{
	if(!bEnableInterfaceChange)
	{
		if( GetRemovable(GetCharacter(GetCompanionIndex(GetMainCharacter(),nCurFourNum))) )
		{
			interfaceResultCommand = RC_INTERFACE_SHIPSTATE_OK;
			EndOkInterface();
		}
		else
		{
			ShowHelpString("chelp_store#6");
		}
	}
	else
	{
		//oldCurNode = "RFACE";
		SetCurrentNode("RFACE");
		SetShowMode(SM_SKILLS);
	}
}

void IDoExit(int exitCode)
{
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
    DelEventHandler("frame","ProcessFrame");
    DelEventHandler("exitOk","ProcessOkExit");
    DelEventHandler("exitCancel","ProcessCancelExit");
	DelEventHandler("RaiseItPress","ProcessRaiseIt");
	DelEventHandler("RaiseSelectPress","ProcessRaiseSelect");
	DelEventHandler("NodeOk","ProcessNodeOk");
	DelEventHandler("NodeCancel","ProcessNodeCancel");
	DelEventHandler("ShipNameChange","ProcessShipNameChange");
	DelEventHandler("ievntGetHelpTexture","iprocGetHelpTexture");

	interfaceResultCommand = exitCode;
	if(bEnableInterfaceChange)
	{
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
	else
	{
		EndCancelInterface(true);
	}
}

void SetShowMode(int showMode)
{
	if(nShowMode == showMode) return;

	switch(nShowMode)
	{
	case SM_NONE:
		SetNodeUsing("NONE_IMAGES",false);
		SetNodeUsing("NONE_LINES",false);
		DisableString("ShipSpeed");
		DisableString("ShipManeuver");
		DisableString("ShipMaxCaliber");
		DisableString("ShipMaxCrew");
		DisableString("ShipMinCrew");
		DisableString("ShipCapacity");
	break;
	case SM_CANNONS:
		SetNodeUsing("CANNONS_STRINGS",false);
		SetNodeUsing("CANNONS_LINES",false);
		DisableString("CannonsName");
		DisableString("FireRange");
		DisableString("ReloadTime");
	break;
	case SM_SKILLS:
		SetNodeUsing("SKILL_IMAGES",false);
		SetNodeUsing("MONEY_IMAGES",true);
		SetNodeUsing("CONTEXTHELP",true);
		EnableString("Money");
		DisableString("SummarySkill");
		DisableString("SLeadership");
		DisableString("SFencing");
		DisableString("SSailing");
		DisableString("SAccuracy");
		DisableString("SCannons");
		DisableString("SGrappling");
		DisableString("SRepair");
		DisableString("SDefence");
		DisableString("SCommerce");
		DisableString("SSneak");
	break;
	case SM_CREW:
		SetNodeUsing("CREW_BUTTON",false);
		DisableString("CrewMorale");
		DisableString("RaiseCost");
	break;
	case SM_SAILS:
		SetNodeUsing("SAILS_LINES",false);
		DisableString("SailSpeeding");
		DisableString("SRepCantMain");
		DisableString("SRepCantSailcloth");
		DisableString("SRepCantSkill1");
		DisableString("SRepCantSkill2");
		DisableString("SailsUndamaged1");
		DisableString("SailsUndamaged2");
		DisableString("SRepairing1");
		DisableString("SRepairing2");
		DisableString("SRepairing3");
	break;
	case SM_HULL:
		SetNodeUsing("SAILS_LINES",false);
		DisableString("HullSpeeding");
		DisableString("HRepCantMain");
		DisableString("HRepCantPlank");
		DisableString("HRepCantSkill1");
		DisableString("HRepCantSkill2");
		DisableString("HullUndamaged1");
		DisableString("HullUndamaged2");
		DisableString("HRepairing1");
		DisableString("HRepairing2");
		DisableString("HRepairing3");
	break;
	}

	switch(showMode)
	{
	case SM_NONE:
		SetNodeUsing("NONE_IMAGES",true);
		SetNodeUsing("NONE_LINES",true);
		EnableString("ShipSpeed");
		EnableString("ShipManeuver");
		EnableString("ShipMaxCaliber");
		EnableString("ShipMaxCrew");
		EnableString("ShipMinCrew");
		EnableString("ShipCapacity");
		SetNoneData();
	break;
	case SM_CANNONS:
		SetNodeUsing("CANNONS_STRINGS",true);
		SetNodeUsing("CANNONS_LINES",true);
		EnableString("CannonsName");
		EnableString("FireRange");
		EnableString("ReloadTime");
	break;
	case SM_SKILLS:
		SetNodeUsing("SKILL_IMAGES",true);
		SetNodeUsing("MONEY_IMAGES",false);
		SetNodeUsing("CONTEXTHELP",false);
		DisableString("Money");
		EnableString("SummarySkill");
		EnableString("SLeadership");
		EnableString("SFencing");
		EnableString("SSailing");
		EnableString("SAccuracy");
		EnableString("SCannons");
		EnableString("SGrappling");
		EnableString("SRepair");
		EnableString("SDefence");
		EnableString("SCommerce");
		EnableString("SSneak");
	break;
	case SM_CREW:
		SetNodeUsing("CREW_BUTTON",true);
		SetSelectable("CREW_BUTTON",false);
		EnableString("CrewMorale");
		EnableString("RaiseCost");
	break;
	case SM_SAILS:
	break;
	case SM_HULL:
	break;
	}

	nShowMode = showMode;
	nCurFourNum = -1;
}

void SetNoneData()
{
	ref otherCh;
	ref refMyCh = GetMainCharacter();
	int shipType = SHIP_NOTUSED;

	int cn = GetCompanionIndex(refMyCh,nCurFourNum);
	if(cn==-1)
	{
		string slotName = "ShipSlot"+nCurFourNum;
		if(CheckAttribute(refMyCh,slotName))	shipType = sti(refMyCh.(slotName).Type);
	}
	else
	{
		otherCh = GetCharacter(cn);
		if( CheckAttribute(otherCh,"ship.Type") )	shipType = sti(otherCh.ship.Type);
	}

	if(shipType!=SHIP_NOTUSED)
	{
		ref refBaseShip = GetShipByType(shipType);
		GameInterface.strings.ShipSpeed = fts(stf(refBaseShip.SpeedRate),3);
		GameInterface.strings.ShipManeuver = sti(refBaseShip.TurnRate);
		GameInterface.strings.ShipMaxCaliber = sti(refBaseShip.MaxCaliber);
		GameInterface.strings.ShipMaxCrew = sti(refBaseShip.MaxCrew);
		GameInterface.strings.ShipMinCrew = sti(refBaseShip.MinCrew);
		GameInterface.strings.ShipCapacity = sti(refBaseShip.Capacity);
	}
	else
	{
		GameInterface.strings.ShipSpeed = 0;
		GameInterface.strings.ShipManeuver = 0;
		GameInterface.strings.ShipMaxCaliber = 0;
		GameInterface.strings.ShipMaxCrew = 0;
		GameInterface.strings.ShipMinCrew = 0;
		GameInterface.strings.ShipCapacity = 0;
	}
}

void SetSkillData()
{
	int cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum);
	if(cn==-1)
	{
		GameInterface.strings.SLeadership = 0;
		GameInterface.strings.SFencing = 0;
		GameInterface.strings.SSailing = 0;
		GameInterface.strings.SAccuracy = 0;
		GameInterface.strings.SCannons = 0;
		GameInterface.strings.SGrappling = 0;
		GameInterface.strings.SRepair = 0;
		GameInterface.strings.SDefence = 0;
		GameInterface.strings.SCommerce = 0;
		GameInterface.strings.SSneak = 0;
	}
	else
	{
		ref otherCh = GetCharacter(cn);
		GameInterface.strings.SLeadership = GetSummonSkillFromName(otherCh,SKILL_LEADERSHIP);
		GameInterface.strings.SFencing = GetSummonSkillFromName(otherCh,SKILL_FENCING);
		GameInterface.strings.SSailing = GetSummonSkillFromName(otherCh,SKILL_SAILING);
		GameInterface.strings.SAccuracy = GetSummonSkillFromName(otherCh,SKILL_ACCURACY);
		GameInterface.strings.SCannons = GetSummonSkillFromName(otherCh,SKILL_CANNONS);
		GameInterface.strings.SGrappling = GetSummonSkillFromName(otherCh,SKILL_GRAPPLING);
		GameInterface.strings.SRepair = GetSummonSkillFromName(otherCh,SKILL_REPAIR);
		GameInterface.strings.SDefence = GetSummonSkillFromName(otherCh,SKILL_DEFENCE);
		GameInterface.strings.SCommerce = GetSummonSkillFromName(otherCh,SKILL_COMMERCE);
		GameInterface.strings.SSneak = GetSummonSkillFromName(otherCh,SKILL_SNEAK);
	}
}

void SetCannonsData()
{
	ref cref;
	int ct = CANNON_TYPE_NONECANNON;
	int cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum);
	if(cn!=-1)	ct = GetCaracterShipCannonsType(GetCharacter(cn));

	GameInterface.strings.CannonsName = GetCannonName(ct);
	if(ct==CANNON_TYPE_NONECANNON)
	{
		GameInterface.strings.FireRange = "0";
		GameInterface.strings.ReloadTime = "0";
	}
	else
	{
		cref = GetCannonByType(ct);
		GameInterface.strings.FireRange = FloatToString(stf(cref.FireRange),1);
		GameInterface.strings.ReloadTime = FloatToString(stf(cref.ReloadTime),1);
	}
}

void SetCrewData()
{
	int cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum);
	if(cn==-1)
	{
		GameInterface.strings.CrewMorale = XI_ConvertString("Crew Morale")+": " + XI_ConvertString("NotData");
		GameInterface.strings.RaiseCost = XI_ConvertString("Cost")+": " + "0";
		return;
	}
	ref chref = GetCharacter(cn);
	if( !CheckAttribute(chref,"Ship.Crew.Morale") )
	{
		GameInterface.strings.CrewMorale = XI_ConvertString("Crew Morale")+": " + XI_ConvertString("NotData");
		GameInterface.strings.RaiseCost = XI_ConvertString("Cost")+": " + "0";
		return;
	}
	int crewQuantity = GetCrewQuantity(chref);
	int crewMorale = sti(chref.Ship.Crew.Morale);
	if( crewQuantity==0 ) crewMorale = MORALE_MAX;
	GameInterface.strings.CrewMorale = XI_ConvertString("Crew Morale")+": " + XI_ConvertString(GetMoraleName(crewMorale));
	if(GetMoraleName(crewMorale)==MoraleTable[MORALET_HEROIC])	GameInterface.strings.RaiseCost = XI_ConvertString("Cost")+": " + "0";
	else
	{
		GameInterface.strings.RaiseCost = XI_ConvertString("Cost")+": " + GetRaiseMoraleCost(crewQuantity);
		if( GetRaiseMoraleCost(crewQuantity) <= sti(Characters[GetMainCharacterIndex()].money) )
			SetSelectable("CREW_BUTTON",true);
	}
}

void SetSailsData()
{
	SetNodeUsing("SAILS_LINES",false);
	DisableString("SailSpeeding");
	DisableString("SRepCantMain");
	DisableString("SRepCantSailcloth");
	DisableString("SRepCantSkill1");
	DisableString("SRepCantSkill2");
	DisableString("SailsUndamaged1");
	DisableString("SailsUndamaged2");
	DisableString("SRepairing1");
	DisableString("SRepairing2");
	DisableString("SRepairing3");

	int cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum);
	if(cn==-1)
	{
		EnableString("SailsUndamaged1");
		EnableString("SailsUndamaged2");
		return;
	}

	ref chref = GetCharacter(cn);
	int sailsPercent = makeint(GetSailPercent(chref));

	if(sailsPercent>=100)
	{
		EnableString("SailsUndamaged1");
		EnableString("SailsUndamaged2");
		return;
	}

	SetNodeUsing("SAILS_LINES",true);
	EnableString("SailSpeeding");
	if(GetSpeedPercentDecreased(chref)>0)
		GameInterface.strings.SailSpeeding = XI_ConvertString("Ship speed decreased by")+" " + GetSpeedPercentDecreased(chref)+"%";
	else
		GameInterface.strings.SailSpeeding = XI_ConvertString("full speed");

	if( !AvalableForRepairSails(chref) )
	{
		EnableString("SRepCantMain");
		return;
	}

	if( GetCargoGoods(chref,GOOD_SAILCLOTH)<=0 )
	{
		EnableString("SRepCantMain");
		EnableString("SRepCantSailcloth");
		return;
	}

	EnableString("SRepairing1");
	EnableString("SRepairing2");
	EnableString("SRepairing3");
	GameInterface.strings.SRepairing2 = XI_ConvertString("Skill")+" ----- "+GetSummonSkillFromName(chref,SKILL_REPAIR);
	GameInterface.strings.SRepairing3 = FloatToString(GetSailRPD(chref),2)+"% " + XI_ConvertString("per day");
}

void SetHullsData()
{
	SetNodeUsing("SAILS_LINES",false);
	DisableString("HullSpeeding");
	DisableString("HRepCantMain");
	DisableString("HRepCantPlank");
	DisableString("HRepCantSkill1");
	DisableString("HRepCantSkill2");
	DisableString("HullUndamaged1");
	DisableString("HullUndamaged2");
	DisableString("HRepairing1");
	DisableString("HRepairing2");
	DisableString("HRepairing3");

	int cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum);
	if(cn==-1)
	{
		EnableString("HullUndamaged1");
		EnableString("HullUndamaged2");
		return;
	}

	ref chref = GetCharacter(cn);
	int hullPercent = makeint(GetHullPercent(chref));
	if(hullPercent>=100)
	{
		EnableString("HullUndamaged1");
		EnableString("HullUndamaged2");
		return;
	}

	SetNodeUsing("SAILS_LINES",true);
	EnableString("HullSpeeding");
	if(GetSpeedPercentDecreased(chref)>0)
		GameInterface.strings.HullSpeeding = XI_ConvertString("Ship speed decreased by")+" " + GetSpeedPercentDecreased(chref)+"%";
	else
		GameInterface.strings.HullSpeeding = XI_ConvertString("full speed");

	if( GetCargoGoods(chref,GOOD_PLANKS)<=0 )
	{
		EnableString("HRepCantMain");
		EnableString("HRepCantPlank");
		return;
	}

	EnableString("HRepairing1");
	EnableString("HRepairing2");
	EnableString("HRepairing3");
	GameInterface.strings.HRepairing2 = XI_ConvertString("Skill")+" ----- "+GetSummonSkillFromName(chref,SKILL_REPAIR);
	GameInterface.strings.HRepairing3 = FloatToString(GetHullRPD(chref),2)+"% " + XI_ConvertString("per day");
}

string GetCannonName(int ct)
{
	if(ct==CANNON_TYPE_NONECANNON)	return XI_ConvertString("NoneCannons");
	ref cref = GetCannonByType(ct);
	string cname;
	if(cref.type==CANNON_NAME_CULVERINE)	cname = XI_ConvertString("Culverine");
	else	cname = XI_ConvertString("Cannon");
	string retVal = XI_ConvertString("caliber"+cref.caliber) + " " + cname;
	return retVal;
}

int GetSpeedPercentDecreased(ref chref)
{
	if( !CheckAttribute(chref,"Ship.SP") ) return 0;
	if( GetSailPercent(chref)>=100.0 ) return 0;
	aref aroot,agr,asail;
	makearef(aroot,chref.ship.sails);
	int i,j;
	float fspeed = 0.0;
	for(i=0; i<GetAttributesNum(aroot); i++)
	{
		agr = GetAttributeN(aroot,i);
		for(j=0; j<GetAttributesNum(agr); j++)
		{
			asail = GetAttributeN(agr,j);
			fspeed += funcGetSailSpeed( sti(asail.hc), sti(asail.mhc), stf(asail.sp) );
		}
	}
	return makeint(fspeed*100.0+0.5);
}

void ProcessRaiseIt()
{
	if( !GetSelectable("CREW_BUTTON") ) return;
	int cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum);
	if(cn==-1)	return;
	ref chref = GetCharacter(cn);
	int crewQuantity = GetCrewQuantity(chref);
	if( GetRaiseMoraleCost(crewQuantity) > sti(Characters[GetMainCharacterIndex()].money) ) return;

	if( !CheckAttribute(chref,"Ship.Crew.Morale") ) return;
	int crewMorale = sti(chref.Ship.Crew.Morale);

	AddMoneyToCharacter(GetMainCharacter(),-GetRaiseMoraleCost(crewQuantity));
	crewMorale += 10;
	if(crewMorale>MORALE_MAX)	crewMorale = MORALE_MAX;
	chref.Ship.Crew.Morale = crewMorale;
	GameInterface.strings.Money = MakeMoneyShow(sti(characters[GetMainCharacterIndex()].money),MONEY_SIGN,MONEY_DELIVER);
	nCurFourNum = -1;
	SetSelectable("CREW_BUTTON",false);
}

void ProcessRaiseSelect()
{
	if( GetSelectable("CREW_BUTTON") )
	{
		SetCurrentNode("CREW_BUTTON");
	}
}

int GetRaiseMoraleCost(int crewQuantity)
{
	int nLeaderShip = GetSummonSkillFromName(GetMainCharacter(),SKILL_LEADERSHIP);
	int nPaymentQ = 15 + crewQuantity*(16-nLeaderShip);
	return nPaymentQ;
}

bool AvalableForRepairSails(ref chref)
{
	int i,j;
	aref sroot,snod,sref;
	string tmpstr;
	bool IsAvalable = true;

	int avlCount=0;
	makearef(sroot,chref.ship.sails);
	for(i=0;i<GetAttributesNum(sroot);i++)
	{
		snod = GetAttributeN(sroot,i);
		for(j=0;j<GetAttributesNum(snod);j++)
		{
			sref = GetAttributeN(snod,j);
			if( CheckAttribute(sref,"mastFall") )
			{
				tmpstr = "ship.masts."+sref.mastFall;
				if( CheckAttribute(chref,tmpstr) && stf(chref.(tmpstr))>=1.0 )
				{
					IsAvalable = false;
					continue;
				}
			}
			return true;
		}
	}
	return IsAvalable;
}

void ProcessNodeOk()
{
	string nodName = GetEventData();
	SendMessage(&GameInterface,"ll", MSG_INTERFACE_LOCK_NODE, 0);
	if( CheckAttribute(&GameInterface,nodName+".strdata") )
	{
		string str = GameInterface.(nodName).strdata;
		SendMessage(&GameInterface,"lsls", MSG_INTERFACE_MSG_TO_NODE, "B_SHIPNAME", 0, str);
		SetCurrentNode("B_SHIPNAME");
		SetShipName(str);
	}
	DeleteAttribute(&GameInterface,nodName+".strdata");
	SetNodeUsing("RENAMEBOX",false);
}

void ProcessNodeCancel()
{
	string nodName = GetEventData();
	SendMessage(&GameInterface,"ll", MSG_INTERFACE_LOCK_NODE, 0);
	DeleteAttribute(&GameInterface,nodName+".strdata");
	SetNodeUsing("renamebox",false);
	SetCurrentNode("B_SHIPNAME");
}

void ProcessShipNameChange()
{
	GameInterface.renamebox.strdata = "";
	SetNodeUsing("RENAMEBOX",true);
	SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 1, "RENAMEBOX");
	SetCurrentNode("RENAMEBOX");
}

void SetCharacterName(string newName)
{
	int cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum);
	if(cn==-1)	return;
	ref chref = GetCharacter(cn);
	int fndNum = findSubStr(newName," ",0);
	string fname = newName;
	string lname = "";
	int slen;
	if(fndNum>0)
	{
		fname = strcut(newName,0,fndNum-1);
		slen = strlen(newName);
		lname = strcut(newName,fndNum+1,slen-1);
	}
	chref.name = fname;
	if(lname!="")	chref.lastname = lname;
}

void SetShipName(string newName)
{
	ref chref = GetMainCharacter();
	int cn = GetCompanionIndex(chref,nCurFourNum);
	if(cn!=-1)
	{
		chref = GetCharacter(cn);
		chref.ship.name = newName;
	}
}

string I_strRetVal;
ref iprocGetHelpTexture()
{
	string nodName = GetEventData();

	I_strRetVal = "";

	if(!bEnableInterfaceChange)
	{
		I_strRetVal = "interfaces\help\store\store_prepare.tga";
	}

	return &I_strRetVal;
}

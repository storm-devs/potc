#define SHOW_HIRE	0
#define SHOW_FIRE	1

int nShowType;

int nCurFourNum;

int idShipType;
int nPlayerMoney;
int nPlayerID;
string sPlayerName;
aref refMyCrew;

int nMaxCrew;
int nMinCrew;
int nCurCrew;
int nMyMorale;

int nCrewCost;
int nCrewMorale;
int nCrewQuantity;

int nAllCrewCost;
int nHireQuantity;
int nHireMax;
int nSumMorale;

void InitInterface(string iniName)
{
	GetHireCrewInfo();

    GameInterface.title = "titleHireCrew";
    GameInterface.FourImage.current = 0;

    FillFourImage();

    SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);

    CreateString(true,"Money","",FONT_NORMAL,COLOR_MONEY,320,389,SCRIPT_ALIGN_CENTER,1.0);
    CreateString(true,"Onboard","",FONT_NORMAL,COLOR_NORMAL,210,148,SCRIPT_ALIGN_CENTER,1.0);
    CreateString(true,"MyMorale","",FONT_NORMAL,COLOR_NORMAL,430,148,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(true,"ShipName","",FONT_NORMAL,COLOR_NORMAL,320,199,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(true,"Available","",FONT_NORMAL,COLOR_NORMAL,320,233,SCRIPT_ALIGN_CENTER,1.0);
    CreateString(false,"Cost","",FONT_NORMAL,COLOR_NORMAL,320,299,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(false,"BuyMorale",XI_ConvertString("Morale:") + " " + XI_ConvertString(GetMoraleName(nCrewMorale)),FONT_NORMAL,COLOR_NORMAL,320,321,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(false,"HireQuantity","",FONT_NORMAL,COLOR_NORMAL,320,267,SCRIPT_ALIGN_CENTER,1.0);

	CreateImage("CrewPicture","SHIP_STATE_ICONS","Crew",146,34,274,162);
	CreateImage("MoralePicture","MORALE","medium morale",366,34,494,162);

	SetNodeUsing("HIRE_OK",false);
	SetNodeUsing("HIRE_CANCEL",false);
	SetNodeUsing("HIRE_COUNTER",false);
	SetNodeUsing("HIRESTRINGS",false);

    SetVariable();
    ProcessFrame();

	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
    SetEventHandler("frame","ProcessFrame",1);
    SetEventHandler("exitCancel","ProcessCancelExit",0);
    SetEventHandler("HirePress","HireProcess",0);
    SetEventHandler("FirePress","FireProcess",0);
    SetEventHandler("HireOk","HireOk",0);
    SetEventHandler("HireCancel","HireCancel",0);
    SetEventHandler("DecreaseHire","DecreaseHire",0);
    SetEventHandler("IncreaseHire","IncreaseHire",0);
	SetEventHandler("ievnt_command","ProcessCommandExecute",0);
}

void ProcessFrame()
{
    if(MakeInt(GameInterface.FourImage.current)!=nCurFourNum)
    {
		aref refMyShip;

        nCurFourNum = MakeInt(GameInterface.FourImage.current);
        nPlayerID = GetCompanionIndex(GetMainCharacter(),nCurFourNum);
		if(nPlayerID<0)
		{
			trace("WARNING!!! Choose not used companion");
			return;
		}

		SetSelectable( "FIRE_BUTTON", GetRemovable(&Characters[nPlayerID]) );
        sPlayerName = Characters[nPlayerID].name;
		makearef(refMyShip,Characters[nPlayerID].Ship);
        makearef(refMyCrew,refMyShip.Crew);
		nMyMorale = sti(refMyCrew.Morale);
        idShipType = sti(refMyShip.Type);
        if(idShipType!=SHIP_NOTUSED)
		{
			nMaxCrew = MakeInt(ShipsTypes[idShipType].MaxCrew);
			nMinCrew = MakeInt(ShipsTypes[idShipType].MinCrew);
		}
        else
		{
			nMaxCrew = 0;
			nMinCrew = 0;
		}
		nCurCrew = MakeInt(refMyCrew.Quantity);

		GameInterface.strings.Onboard = nCurCrew+"/"+nMaxCrew;
		GameInterface.strings.ShipName = Characters[nPlayerID].Ship.Name;
		GameInterface.strings.MyMorale = XI_ConvertString(GetMoraleName(nMyMorale));
		GameInterface.pictures.morale.MoralePicture = GetMoralePicture(nMyMorale);
    }
}

void SetVariable()
{
	ref tmpref = GetMainCharacter();
    nPlayerMoney = MakeInt(tmpref.Money);
    GameInterface.strings.Money = MakeMoneyShow(nPlayerMoney,MONEY_SIGN,MONEY_DELIVER);
    nCurFourNum = -1;
	GameInterface.strings.Available = XI_ConvertString("Available for hire:") + " " + nCrewQuantity;
}

void FillFourImage()
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
		if(i==0)
		{
			tmpID = GetMainCharacterIndex();
		}
		else
		{
			tmpID = GetCompanionIndex(refMainCh,i);
		}
		if(tmpID!=-1)
		{
			tmpID = sti(Characters[tmpID].Ship.Type);
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
		}
		else
		{
			tmp1="";
			tmp2="";
			bSelected=false;
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
}

void ProcessCancelExit()
{
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
    DelEventHandler("frame","ProcessFrame");
    DelEventHandler("exitCancel","ProcessCancelExit");
    DelEventHandler("HirePress","HireProcess");
    DelEventHandler("FirePress","FireProcess");
    DelEventHandler("HireOk","HireOk");
    DelEventHandler("HireCancel","HireCancel");
    DelEventHandler("DecreaseHire","DecreaseHire");
    DelEventHandler("IncreaseHire","IncreaseHire");
	DelEventHandler("ievnt_command","ProcessCommandExecute");

	SetHireCrewInfo();

	interfaceResultCommand = RC_INTERFACE_HIRECREW_EXIT;
    EndCancelInterface(true);
}

void HireProcess()
{
	nShowType = SHOW_HIRE;
	SetQuantityProcess();
}

void FireProcess()
{
	nShowType = SHOW_FIRE;
	SetQuantityProcess();
}

void SetQuantityProcess()
{
	nAllCrewCost = 0;
	nHireQuantity = 0;
	if(nShowType==SHOW_HIRE)
	{
		nHireMax = nMaxCrew-nCurCrew;
	}
	else
	{
		nHireMax = nCurCrew-1;
	}

	GameInterface.strings.HireQuantity = nHireQuantity;
	GameInterface.strings.Cost = XI_ConvertString("Cost:") + " " + nAllCrewCost;

	SetNodeUsing("HIRE_BUTTON",false);
	SetNodeUsing("FIRE_BUTTON",false);
	SetNodeUsing("HIRE_COUNTER",true);
	SetNodeUsing("HIRE_OK",true);
	SetNodeUsing("HIRE_CANCEL",true);

	EnableString("HireQuantity");

	if(nShowType==SHOW_HIRE)
	{
		EnableString("Cost");
		EnableString("BuyMorale");
		SetNodeUsing("HIRESTRINGS",true);
	}
}

void StopQuantityProcess()
{
	SetNodeUsing("HIRE_BUTTON",true);
	SetNodeUsing("FIRE_BUTTON",true);
	SetNodeUsing("HIRE_OK",false);
	SetNodeUsing("HIRE_CANCEL",false);
	SetNodeUsing("HIRE_COUNTER",false);
	if(nShowType==SHOW_HIRE)
	{
		DisableString("Cost");
		DisableString("BuyMorale");
		SetNodeUsing("HIRESTRINGS",false);
	}
	DisableString("HireQuantity");
	SetCurrentNode("HIRE_BUTTON");
}

void HireOk()
{
	ref tmpref = GetMainCharacter();
	if(nShowType==SHOW_HIRE)
	{
		nCrewQuantity = nCrewQuantity - nHireQuantity;
		nCurCrew = nCurCrew + nHireQuantity;
		nMyMorale = nSumMorale;
		nPlayerMoney = nPlayerMoney - nAllCrewCost;

		refMyCrew.Quantity = nCurCrew;
		refMyCrew.Morale = nMyMorale;

		tmpref.Money = nPlayerMoney;
	}
	else
	{
		nCrewQuantity = nCrewQuantity + nHireQuantity;
		nCurCrew = nCurCrew - nHireQuantity;

		refMyCrew.Quantity = nCurCrew;
	}
	StopQuantityProcess();
}

void HireCancel()
{
	GameInterface.strings.MyMorale = XI_ConvertString(GetMoraleName(nMyMorale));
	GameInterface.strings.Onboard = nCurCrew+"/"+nMaxCrew;
	GameInterface.strings.Available = XI_ConvertString("Available for hire:") + " " + nCrewQuantity;
	GameInterface.strings.Money = MakeMoneyShow(nPlayerMoney,MONEY_SIGN,MONEY_DELIVER);
	StopQuantityProcess();
}

void DecreaseHire()
{
	if(nHireQuantity>0)
	{
		nHireQuantity--;
		ChangeHireQuantity();
	}
}

void IncreaseHire()
{
	if(nHireQuantity<nHireMax)
	{
		if(nShowType==SHOW_HIRE)
		{
			if(nPlayerMoney<nAllCrewCost+nCrewCost)
			{
				ShowHelpString("chelp_hirecrew#10");
				return;
			}
			if(nHireQuantity>nCrewQuantity-1)
			{
				ShowHelpString("chelp_hirecrew#11");
				return;
			}
		}
		nHireQuantity++;
		ChangeHireQuantity();
	}
}

void ChangeHireQuantity()
{
	int tmpcrew;
	nAllCrewCost = nCrewCost*nHireQuantity;
	GameInterface.strings.HireQuantity = nHireQuantity;
	GameInterface.strings.Cost = XI_ConvertString("Cost:") + " " + nAllCrewCost;
	if(nShowType==SHOW_HIRE)
	{
		tmpcrew = nCurCrew+nHireQuantity;
		nSumMorale = ((nMyMorale*nCurCrew)+(nCrewMorale*nHireQuantity))/tmpcrew;
		GameInterface.strings.MyMorale = XI_ConvertString(GetMoraleName(nSumMorale));
		GameInterface.strings.Onboard = tmpcrew+"/"+nMaxCrew;
		GameInterface.strings.Available = XI_ConvertString("Available for hire:") + " " + (nCrewQuantity-nHireQuantity);
		GameInterface.strings.Money = MakeMoneyShow(nPlayerMoney - nAllCrewCost,MONEY_SIGN,MONEY_DELIVER);
	}
	else
	{
		tmpcrew = nCurCrew-nHireQuantity;
		GameInterface.strings.Onboard = tmpcrew+"/"+nMaxCrew;
		GameInterface.strings.Available = XI_ConvertString("Available for hire:") + " " + (nCrewQuantity+nHireQuantity);
	}
}

string GetMoralePicture(int moraleValue)
{
	if(moraleValue<33) return "low morale";
	if(moraleValue<66) return "medium morale";
	return "high morale";
}

void ProcessCommandExecute()
{
	string comName = GetEventData();
	string nodName = GetEventData();

	switch(nodName)
	{
	case "HIRE_BUTTON":
		if(comName=="downstep" || comName=="speeddown")
		{
			if(GetSelectable("FIRE_BUTTON"))
			{
				SetCurrentNode("FIRE_BUTTON");
			}
		}
	break;
	}
}

void GetHireCrewInfo()
{
	nCrewCost = 16 - GetSummonSkillFromName(GetMainCharacter(),SKILL_LEADERSHIP);
	nCrewMorale = MORALE_NORMAL;
	nCrewQuantity = 0;

	int locIdx = FindLoadedLocation();
	if(locIdx<0) return;

	if( !CheckAttribute(&Locations[locIdx],"townsack") ) return;
	string townName = Locations[locIdx].townsack;

	aref arTown,arTownsList;
	makearef(arTownsList,objTownStateTable.towns);
	int i,q;
	q = GetAttributesNum(arTownsList);

	for(i=0; i<q; i++)
	{
		arTown = GetAttributeN(arTownsList,i);
		if(arTown.name == townName)
		{
			break;
		}
	}

	if(i>=q) return;

	if( CheckAttribute(arTown,"crew.quantity") ) nCrewQuantity = sti(arTown.crew.quantity);
	if( CheckAttribute(arTown,"crew.morale") ) nCrewMorale = sti(arTown.crew.morale);
}

void SetHireCrewInfo()
{
	int locIdx = FindLoadedLocation();
	if(locIdx<0) return;

	if( !CheckAttribute(&Locations[locIdx],"townsack") ) return;
	string townName = Locations[locIdx].townsack;

	aref arTown,arTownsList;
	makearef(arTownsList,objTownStateTable.towns);
	int i,q;
	q = GetAttributesNum(arTownsList);

	for(i=0; i<q; i++)
	{
		arTown = GetAttributeN(arTownsList,i);
		if(arTown.name == townName)
		{
			break;
		}
	}

	if(i>=q) return;

	arTown.crew.quantity = nCrewQuantity;
	arTown.crew.morale = nCrewMorale;
}

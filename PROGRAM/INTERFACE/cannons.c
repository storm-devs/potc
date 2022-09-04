int nCurScrollNum;
int nCurFourNum;

void InitInterface(string iniName)
{
    GameInterface.title = "titleCannons";

    FillFourImage();
    FillScroll();
    GameInterface.FourImage.current = 0;	nCurFourNum = -1;
    GameInterface.scrollcannons.current = 0;		nCurScrollNum = -1;

    SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);

    CreateString(TRUE,"Money",MakeMoneyShow(sti(Characters[GetMainCharacterIndex()].Money),"","."),FONT_NORMAL,COLOR_MONEY,320,392,SCRIPT_ALIGN_CENTER,1.0);
    CreateString(TRUE,"ShipName","",FONT_NORMAL,COLOR_NORMAL,320,198,SCRIPT_ALIGN_CENTER,1.0);
    CreateString(TRUE,"FireRange","",FONT_NORMAL,COLOR_NORMAL,400,245,SCRIPT_ALIGN_RIGHT,1.0);
    CreateString(TRUE,"ReloadTime","",FONT_NORMAL,COLOR_NORMAL,400,275,SCRIPT_ALIGN_RIGHT,1.0);
    CreateString(TRUE,"Cost","",FONT_NORMAL,COLOR_NORMAL,400,305,SCRIPT_ALIGN_RIGHT,1.0);

    ProcessFrame();

	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
    SetEventHandler("frame","ProcessFrame",1);
    SetEventHandler("exitCancel","ProcessCancelExit",0);
    SetEventHandler("InstallPress","ProcessInstall",0);
	SetEventHandler("installSelect","ProcessInstallSelect",0);
}

void ProcessFrame()
{
    if(sti(GameInterface.scrollcannons.current)!=nCurScrollNum)
    {
        nCurScrollNum = sti(GameInterface.scrollcannons.current);
		ref rcann = GetCannonByType(GetChoosedCannonType());
        GameInterface.strings.FireRange = sti(rcann.FireRange);
        GameInterface.strings.ReloadTime = sti(rcann.ReloadTime);
		nCurFourNum = -1;
    }

    if(sti(GameInterface.FourImage.current)!=nCurFourNum)
    {
        nCurFourNum = sti(GameInterface.FourImage.current);
		ref rcn = GetCannonByType(GetChoosedCannonType());
		ref refMyCh = GetMainCharacter();
		int cn = GetCompanionIndex(refMyCh,nCurFourNum);
		if(cn==-1)
		{
			SetSelectable("INSTALL_BUTTON",false);
			GameInterface.strings.ShipName = "";
			GameInterface.strings.Cost = "0";
		}
		else
		{
			GameInterface.strings.ShipName = GetCharShipName(GetCharacter(cn));
			GameInterface.strings.Cost = GetCannonDeltaPrice(GetCharacter(cn),GetChoosedCannonType());
		}
		SetSelectable("INSTALL_BUTTON",CheckInstallEnable());
    }
}

void FillScroll()
{
	int i, idx;
	string attributeName;
    aref pRef;

	GameInterface.scrollcannons.ImagesGroup.t1 = "ICONS";
	GameInterface.scrollcannons.ImagesGroup.t2 = "CANNONS";

	idx=0;
	for(i=0; i<CANNON_TYPES_QUANTITY; i++)
	{
		if( CheckAttribute(&cannon[i],"TradeOff") && sti(cannon[i].TradeOff)==true ) continue;

		idx++;
		attributeName = "pic" + idx;
        makearef(pRef,GameInterface.scrollcannons.(attributeName));
		switch(sti(cannon[i].type))
		{
		case CANNON_NAME_CULVERINE:
			pRef.str1 = "Culverine";
			pRef.img2 = "culverine"+cannon[i].caliber;
			pRef.img1 = "culverine back";
			break;
		case CANNON_NAME_CANNON:
			pRef.str1 = "Cannon";
			pRef.img2 = "cannon"+cannon[i].caliber;
			pRef.img1 = "cannon back";
			break;
		case CANNON_NAME_SPECIAL_CANNON:
			pRef.str1 = "Cannon";
			pRef.img2 = "cannon"+cannon[i].caliber;
			pRef.img1 = "special cannon back";
			break;
		}
		pRef.cannon = i;
		pRef.str2 = "caliber"+cannon[i].caliber;
		pRef.tex1 = 0;
		pRef.tex2 = 1;
	}

	GameInterface.scrollcannons.ListSize = idx;
}

void FillFourImage()
{
    int i;
    string tmp1,tmp2,tmpStr;
    int tmpID;
	int bSelected;

	ref refMainCh = GetMainCharacter();
	GameInterface.FourImage.BadTwoPicture = "interfaces\blank_ship.tga";
	GameInterface.FourImage.ImagesGroup.t0 = "ICONS";
	GameInterface.FourImage.ImagesGroup.t1 = "SHIPS16";
	GameInterface.FourImage.ImagesGroup.t2 = "SHIPS1";
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
    DelEventHandler("InstallPress","ProcessInstall");
	DelEventHandler("installSelect","ProcessInstallSelect");

	interfaceResultCommand = RC_INTERFACE_CANNONS_EXIT;
    EndCancelInterface(true);
}

void ProcessInstall()
{
	int cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum);
	if(cn==-1) return;
	if( !CheckInstallEnable() ) return;
	AddMoneyToCharacter( GetMainCharacter(), 0 - GetCannonDeltaPrice(GetCharacter(cn),GetChoosedCannonType()) );
	SetCharacterCannonType( GetCharacter(cn), GetChoosedCannonType() );
	GameInterface.strings.Money = MakeMoneyShow(sti(Characters[GetMainCharacterIndex()].Money),"",".");
	nCurScrollNum = -1;
	ShowHelpString("chelp_cannons#13");
}

int GetCannonDeltaPrice(ref rChar,int nCannonType)
{
	int ncq = GetCannonQuantity(rChar);
	if(ncq==0) return 0;
	int nMyCannonType = GetCaracterShipCannonsType(rChar);
	if(nMyCannonType==nCannonType) return 0;
	return (GetCannonPrice(nCannonType)-GetCannonPrice(nMyCannonType))*ncq;
}

int GetCannonPrice(int nCannonType)
{
	if(nCannonType==CANNON_TYPE_NONECANNON) return 0;
	ref rCannon = GetCannonByType(nCannonType);
	return sti(rCannon.Cost);
}

string GetCharShipName(ref rCharacter)
{
	if( CheckAttribute(rCharacter,"Ship.Name") )	return rCharacter.Ship.Name;
	return SHIP_NAME_NOTUSED;
}

void SetCharacterCannonType(ref rCharacter,int nCannonType)
{
	rCharacter.Ship.Cannons.Type = nCannonType;
}

bool CheckInstallEnable()
{
	int cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum);
	if(cn==-1) return false;
	if( GetRemovable(GetCharacter(cn))==false )
	{
		ShowHelpString("chelp_shipyard#12");
		return false;
	}
	if( GetCannonDeltaPrice(GetCharacter(cn),GetChoosedCannonType()) > GetCharacterMoney(GetMainCharacter()) )
	{
		ShowHelpString("chelp_cannons#12");
		return false;
	}
	if( GetCaracterShipCannonsType(GetCharacter(cn)) == GetChoosedCannonType() )
	{
		ShowHelpString("chelp_cannons#11");
		return false;
	}
	if( GetMaximumCaliber(GetCharacter(cn)) < GetCannonCaliber(GetChoosedCannonType()) )
	{
		ShowHelpString("chelp_cannons#10");
		return false;
	}
	ShowHelpString("chelp_cannons#2");
	return true;
}

void ProcessInstallSelect()
{
	if( GetSelectable("INSTALL_BUTTON") ) SetCurrentNode("INSTALL_BUTTON");
}

int GetChoosedCannonType()
{
	string attributeName = "pic" + (nCurScrollNum+1);
	if( !CheckAttribute(&GameInterface,"scrollcannons."+attributeName) ) return 0;
	return sti(GameInterface.scrollcannons.(attributeName).cannon);
}

int GetCharacterMoney(ref rChr)
{
	ref mc = GetMainCharacter();
	if( CheckAttribute(mc,"money") ) return sti(mc.money);
	return 0;
}

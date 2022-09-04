#define UNKNOWN_FORT_NAME	"UnknownFortName"

ref glob_captref;

void InitInterface_R(string iniName,ref captref)
{
	glob_captref = captref;
	ref mchref = GetMainCharacter();
	mchref.from_interface.fortCharacterIdx = captref.index;

	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);

    CreateString(true,"Exp","",FONT_NORMAL,COLOR_NORMAL,20,180,SCRIPT_ALIGN_LEFT,1.2);
    CreateString(true,"Booty","",FONT_NORMAL,COLOR_NORMAL,20,260,SCRIPT_ALIGN_LEFT,1.2);

	CalculateData(captref);

	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
    SetEventHandler("exitCancel","ProcessCancelExit",0);
}

void ProcessCancelExit()
{
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
    DelEventHandler("exitCancel","ProcessCancelExit");
	interfaceResultCommand = RC_INTERFACE_FORTCAPTURE_EXIT;
    EndCancelInterface(true);
}

void CalculateData(ref chref)
{
	int nationType = sti(chref.nation);
	int nBooty = 25000;
	int nExp = 25000;
	string sColonyName = GetColonyNameFromCh(chref);

	string	sGoodsName[8];
	int		nGoodsQnt[8];
	int nUsedGoods = FillGoodsFromIslands(GetIslandNameFromColony(chref.location),&sGoodsName,&nGoodsQnt);

	GameInterface.strings.Exp = XI_ConvertString("Experience Bonus") + ": " + nExp;
	GameInterface.strings.Booty = XI_ConvertString("Booty")+": "+ nBooty;
	string tmpStr = GameInterface.strings.Booty;
	int sw = GetStringWidth(tmpStr,FONT_NORMAL,1.2);
	if(sw>0)	CreateImage("money","icons","commerce skill icon", 32+sw, 260, 64+sw, 292);
	CreateImage( "Blazonry",GetBlazonryGroup(nationType),GetNationNameByType(nationType),70,70,148,148);
	CreateString(true,"ColonyName",XI_ConvertString(sColonyName),FONT_NORMAL,COLOR_NORMAL,160,95,SCRIPT_ALIGN_LEFT,1.2);

	if(nUsedGoods>0)
	{
		CreateImage( "goods1","GOODS",sGoodsName[0],34,296,98,360);
		CreateString(true,"goods1",nGoodsQnt[0]+"",FONT_BOLD_NUMBERS,COLOR_NORMAL,66,338,SCRIPT_ALIGN_CENTER,1.0);
	}
	if(nUsedGoods>1)
	{
		CreateImage( "goods2","GOODS",sGoodsName[1],98,296,162,360);
		CreateString(true,"goods2",nGoodsQnt[1]+"",FONT_BOLD_NUMBERS,COLOR_NORMAL,130,338,SCRIPT_ALIGN_CENTER,1.0);
	}
	if(nUsedGoods>2)
	{
		CreateImage( "goods3","GOODS",sGoodsName[2],162,296,226,360);
		CreateString(true,"goods3",nGoodsQnt[2]+"",FONT_BOLD_NUMBERS,COLOR_NORMAL,194,338,SCRIPT_ALIGN_CENTER,1.0);
	}
	if(nUsedGoods>3)
	{
		CreateImage( "goods4","GOODS",sGoodsName[3],226,296,290,360);
		CreateString(true,"goods4",nGoodsQnt[3]+"",FONT_BOLD_NUMBERS,COLOR_NORMAL,258,338,SCRIPT_ALIGN_CENTER,1.0);
	}
	if(nUsedGoods>4)
	{
		CreateImage( "goods5","GOODS",sGoodsName[4],34,378,98,442);
		CreateString(true,"goods5",nGoodsQnt[4]+"",FONT_BOLD_NUMBERS,COLOR_NORMAL,66,420,SCRIPT_ALIGN_CENTER,1.0);
	}
	if(nUsedGoods>5)
	{
		CreateImage( "goods6","GOODS",sGoodsName[5],98,378,162,442);
		CreateString(true,"goods6",nGoodsQnt[5]+"",FONT_BOLD_NUMBERS,COLOR_NORMAL,130,420,SCRIPT_ALIGN_CENTER,1.0);
	}
	if(nUsedGoods>6)
	{
		CreateImage( "goods7","GOODS",sGoodsName[6],162,378,226,442);
		CreateString(true,"goods7",nGoodsQnt[6]+"",FONT_BOLD_NUMBERS,COLOR_NORMAL,194,420,SCRIPT_ALIGN_CENTER,1.0);
	}
	if(nUsedGoods>7)
	{
		CreateImage( "goods8","GOODS",sGoodsName[7],226,378,290,442);
		CreateString(true,"goods8",nGoodsQnt[7]+"",FONT_BOLD_NUMBERS,COLOR_NORMAL,258,420,SCRIPT_ALIGN_CENTER,1.0);
	}

	AddCharacterExp(GetMainCharacter(),nExp);
	AddMoneyToCharacter(GetMainCharacter(),nBooty);
	i_RepairAllShips();
}

string GetBlazonryGroup(int nationIdx)
{
	switch(nationIdx)
	{
	case ENGLAND:	return "NATIONS_2";	break;
	case FRANCE:	return "NATIONS_2";	break;
	case SPAIN:		return "NATIONS_1";	break;
	case PIRATE:	return "NATIONS_2";	break;
	case HOLLAND:	return "NATIONS_2";	break;
	case PORTUGAL:	return "NATIONS_1";	break;
	}
	return "";
}

string GetIslandNameFromColony(string colonyName)
{
	string islName = colonyName;
	if(colonyName=="Greenford") islName = "Oxbay";
	return islName;
}

int FillGoodsFromIslands(string islName,ref sGoodsName,ref nGoodsQuantity)
{
	int idxIsl = FindIsland(islName);
	if(idxIsl==-1) return 0;
	ref islRef = GetIslandByIndex(idxIsl);

	aref tmpRef;
	int i,nGoodsType,nAddGoods;
	int retVal=0;
	ref refGoods;

	int nFreeTypes = GOODS_QUANTITY;
	int tmpGoodsTypes[GOODS_QUANTITY];
	for(i=0; i<GOODS_QUANTITY; i++)	{tmpGoodsTypes[i] = 0;}
	tmpGoodsTypes[GOOD_BALLS] = -1;
	tmpGoodsTypes[GOOD_GRAPES] = -1;
	tmpGoodsTypes[GOOD_KNIPPELS] = -1;
	tmpGoodsTypes[GOOD_BOMBS] = -1;
	nFreeTypes = nFreeTypes-4;

	if( CheckAttribute(islRef,"Trade.Export") )
	{
		makearef(tmpRef,islRef.Trade.Export);
		for(i=0; i<GetAttributesNum(tmpRef); i++)
		{
			nGoodsType = sti(GetAttributeValue(GetAttributeN(tmpRef,i)));
			tmpGoodsTypes[nGoodsType] = 1;
		}
	}
	if( CheckAttribute(islRef,"Trade.Import") )
	{
		makearef(tmpRef,islRef.Trade.Import);
		for(i=0; i<GetAttributesNum(tmpRef); i++)
		{
			nGoodsType = sti(GetAttributeValue(GetAttributeN(tmpRef,i)));
			tmpGoodsTypes[nGoodsType] = -1; nFreeTypes--;
		}
	}
	if( CheckAttribute(islRef,"Trade.Contraband") )
	{
		makearef(tmpRef,islRef.Trade.Contraband);
		for(i=0; i<GetAttributesNum(tmpRef); i++)
		{
			nGoodsType = sti(GetAttributeValue(GetAttributeN(tmpRef,i)));
			tmpGoodsTypes[nGoodsType] = -1; nFreeTypes--;
		}
	}

	while(retVal<8)
	{
		if(nFreeTypes<=0) break;
		nGoodsType = Rand(GOODS_QUANTITY-1);
		while(tmpGoodsTypes[nGoodsType]<0)
		{
			nGoodsType++;
			if(nGoodsType>=GOODS_QUANTITY) nGoodsType = nGoodsType-GOODS_QUANTITY;
		}
		refGoods = GetGoodByType(nGoodsType);
		if(tmpGoodsTypes[nGoodsType]==1)	nAddGoods = (10+Rand(25))*sti(refGoods.Units);
		else	nAddGoods = (1+Rand(12))*sti(refGoods.Units);
		sGoodsName[retVal] = refGoods.Name;
		nGoodsQuantity[retVal] = nAddGoods;
		AddCharacterGoods(GetMainCharacter(),nGoodsType,nAddGoods);
		tmpGoodsTypes[nGoodsType] = -1; nFreeTypes--;
		retVal++;
	}

	return retVal;
}

string GetColonyNameFromCh(ref chref)
{
	aref fortReload = FindIslandReloadLocator(chref.location,chref.location.locator);
	if(CheckAttribute(fortReload,"FortName")) return fortReload.FortName;
	return UNKNOWN_FORT_NAME;
}

void i_RepairAllShips()
{
	ref chref;
	ref mchref = GetMainCharacter();

	int i,cn;

	for(i=0; i<4; i++)
	{
		cn = GetCompanionIndex(mchref,i);
		if(cn>=0)
		{
			chref = GetCharacter(cn);
			chref.ship.hp = GetCharacterShipHP(chref);

			chref.ship.sp = GetCharacterShipSP(chref);
			DeleteAttribute(chref,"ship.sails");
			DeleteAttribute(chref,"ship.masts");
		}
	}
}

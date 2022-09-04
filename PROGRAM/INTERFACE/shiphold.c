#define SHOW_TYPE_MAIN		0
#define SHOW_TYPE_DISCARD	1
#define SHOW_TYPE_INFO		2

int nCurShowType = 0;

int nCurScrollNum;
int nCurFourNum;

ref  refCharacter;

int nDiscardQuantity;
string strCurNodeName;

void InitInterface(string iniName)
{
    GameInterface.title = "titleShipHold";

    FillFourImage();
    FillScroll();

    SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);

	refCharacter = GetMainCharacter();
    CreateString(true,"Money",MakeMoneyShow(sti(refCharacter.Money),MONEY_SIGN,MONEY_DELIVER),FONT_NORMAL,COLOR_MONEY,320,391,SCRIPT_ALIGN_CENTER,1.0);
    CreateString(true,"GoodsName","",FONT_NORMAL,COLOR_NORMAL,320,197,SCRIPT_ALIGN_CENTER,1.0);
    CreateString(true,"Weight","",FONT_NORMAL,COLOR_NORMAL,304,234,SCRIPT_ALIGN_LEFT,1.0);
    CreateString(true,"FreeSpace","",FONT_NORMAL,COLOR_NORMAL,304,270,SCRIPT_ALIGN_LEFT,1.0);
    CreateString(false,"Discarding","",FONT_NORMAL,COLOR_NORMAL,320,310,SCRIPT_ALIGN_CENTER,1.0);

    SetNodeUsing("DISCARD_COUNTER",false);
    SetNodeUsing("ALL_DISCARD",false);
    SetNodeUsing("OK_DISCARD",false);
	SetNodeUsing("GOODS_DESCRIBE",false);

    SetVariable();
    ProcessFrame();
	ChangeScroll();

	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
    SetEventHandler("frame","ProcessFrame",1);
    SetEventHandler("exitCancel","ProcessCancelExit",0);
	SetEventHandler("ievnt_command","ProcessCommandExecute",0);
}

void SelectDiscard()
{
	if(GetSelectable("DISCARD_BUTTON")==true)	SetCurrentNode("DISCARD_BUTTON");
	else	SetCurrentNode("INFO_BUTTON");
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

void ProcessFrame()
{
	int cn;
    string sPlayerName;

	if(GetCurrentNode()!=strCurNodeName)
	{
		strCurNodeName = GetCurrentNode();
		switch(strCurNodeName)
		{
		case "SHIPSLIST":	SetShowType(SHOW_TYPE_MAIN); break;
		case "GOODSLIST":	SetShowType(SHOW_TYPE_MAIN); break;
		case "DISCARD_BUTTON":	SetShowType(SHOW_TYPE_MAIN); break;
		case "INFO_BUTTON":	SetShowType(SHOW_TYPE_MAIN); break;
		case "DISCARD_COUNTER":	SetShowType(SHOW_TYPE_DISCARD); break;
		case "ALL_DISCARD":	SetShowType(SHOW_TYPE_DISCARD); break;
		case "OK_DISCARD":	SetShowType(SHOW_TYPE_DISCARD); break;
		case "GOODS_DESCRIBE":	SetShowType(SHOW_TYPE_INFO); break;
		}
	}

    if(sti(GameInterface.FourImage.current)!=nCurFourNum)
    {
        nCurFourNum = sti(GameInterface.FourImage.current);
		refCharacter = GetMainCharacter();
		if(nCurFourNum>0)
		{
			cn = GetCompanionIndex(refCharacter,nCurFourNum);
			if(cn==-1)
			{
				nCurFourNum=0;
			}
			else
			{
				refCharacter = GetCharacter(cn);
			}
		}

		if(CheckAttribute(refCharacter,"Ship.Name"))
		{
			CreateString(true,"ShipName",refCharacter.Ship.Name,FONT_NORMAL,COLOR_NORMAL,GetXForShipName(),GetYForShipName(),SCRIPT_ALIGN_CENTER,1.0);
		}
		else
		{
			DisableString("ShipName");
		}

		GameInterface.strings.FreeSpace = GetCargoLoad(refCharacter) + "/" + GetCargoMaxSpace(refCharacter);
        ChangeScroll();
    }

    if(sti(GameInterface.goodslist.current)!=nCurScrollNum)
    {
        nCurScrollNum = sti(GameInterface.goodslist.current);
		int n = GetGoodsIndexForI(nCurScrollNum);
		SetSelectable("DISCARD_BUTTON",GetCargoGoods(refCharacter,n)>0 && GetRemovable(refCharacter));
		GameInterface.strings.Weight = GetGoodWeightByType(n,1) + " " + XI_ConvertString("cwt");
		if(n<0) {
			GameInterface.strings.GoodsName = "";
		} else {
			GameInterface.strings.GoodsName = XI_ConvertString(Goods[n].name);
		}
    }
}

void SetVariable()
{
    nCurScrollNum = -1;
    nCurFourNum = -1;
}

void FillScroll()
{
	int i;
	string attributeName;
    aref pRef;
    string goodsName, showName;

    GameInterface.goodslist.current = 0;
	GameInterface.goodslist.ListSize = GOODS_QUANTITY;
	GameInterface.goodslist.ImagesGroup.t1 = "ICONS";
	GameInterface.goodslist.ImagesGroup.t2 = "GOODS";
	GameInterface.goodslist.SpecTechniqueColor = argb(55,255,255,255);
	GameInterface.goodslist.SpecTechniqueName = "iSpec1";
	for(i=0; i<GOODS_QUANTITY; i++)
	{
		attributeName = "pic" + (i+1);
        makearef(pRef,GameInterface.goodslist.(attributeName));
        goodsName = Goods[i].Name;
		showName = GetShowGoodsName(goodsName);
		pRef.str1 = "#"+showName;
		pRef.str2 = "";
		pRef.img2 = goodsName;
		pRef.img1 = "cannon back";
		pRef.tex2 = 1;
		pRef.tex1 = 0;
		pRef.goodsNum = i;
	}
}

void ChangeScroll()
{
    int i;
    string attributeName;
    string showName;

	// fill visible goods
	int idx = 1;
	for(i=0; i<GOODS_QUANTITY; i++)
	{
		if(GetCargoGoods(refCharacter,i)==0) continue;
		attributeName = "pic" + idx;
		showName = GetShowGoodsName(Goods[i].Name);
		GameInterface.goodslist.(attributeName).str1 = "#"+showName;
		GameInterface.goodslist.(attributeName).str2 = "#"+GetCargoGoods(refCharacter,i);
		GameInterface.goodslist.(attributeName).spec2 = false;
		GameInterface.goodslist.(attributeName).img2 = Goods[i].Name;
		GameInterface.goodslist.(attributeName).goodsNum = i;
		idx++;
	}
	// fill invisible goods
	for(i=0; i<GOODS_QUANTITY; i++)
	{
		if(GetCargoGoods(refCharacter,i)!=0) continue;
		attributeName = "pic" + idx;
		GameInterface.goodslist.(attributeName).str1 = "";
		GameInterface.goodslist.(attributeName).str2 = "";
		GameInterface.goodslist.(attributeName).spec2 = true;
		GameInterface.goodslist.(attributeName).img2 = Goods[i].Name;
		GameInterface.goodslist.(attributeName).goodsNum = i;
		idx++;
	}
    SendMessage(&GameInterface,"lsl",MSG_INTERFACE_SCROLL_CHANGE,"GOODSLIST",-1);
	if(GetRemovable(refCharacter) && GetCargoGoods(refCharacter,GetGoodsIndexForI(nCurScrollNum))>0)
	{
		SetSelectable("DISCARD_BUTTON",true);
	}
	else
	{
		SetSelectable("DISCARD_BUTTON",false);
	}
	GameInterface.strings.Weight = GetGoodWeightByType(GetGoodsIndexForI(nCurScrollNum),1) + " " + XI_ConvertString("cwt");
}

void ProcessCancelExit()
{
	interfaceResultCommand = RC_INTERFACE_SHIPHOLD_EXIT;
	IDoExit();
}

void IDoExit()
{
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
    DelEventHandler("frame","ProcessFrame");
    DelEventHandler("exitCancel","ProcessCancelExit");
	DelEventHandler("ievnt_command","ProcessCommandExecute");

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

void ProcessDiscard()
{
	SetShowType(SHOW_TYPE_DISCARD);
    nDiscardQuantity = 0;
    GameInterface.strings.Discarding = "0";
}

void DiscardOk()
{
	RemoveCharacterGoods(refCharacter,GetGoodsIndexForI(nCurScrollNum),nDiscardQuantity);
	SetShowType(SHOW_TYPE_MAIN);
    GameInterface.strings.FreeSpace = GetCargoLoad(refCharacter)+"/"+GetCargoMaxSpace(refCharacter);
	ChangeScroll();
}

void DiscardAll()
{
    nDiscardQuantity = GetCargoGoods(refCharacter,GetGoodsIndexForI(nCurScrollNum));
    DiscardOk();
}

void DiscardCancel()
{
	SetShowType(SHOW_TYPE_MAIN);
    GameInterface.strings.FreeSpace = GetCargoLoad(refCharacter) + "/" + GetCargoMaxSpace(refCharacter);
	SetCurrentNode("GOODSLIST");
}

void DecreaseDiscard()
{
    if(nDiscardQuantity>0)
    {
        nDiscardQuantity = nDiscardQuantity - GetGoodsUnitSize();
		if(nDiscardQuantity<0) nDiscardQuantity = 0;
        GameInterface.strings.Discarding = ""+nDiscardQuantity;
		int oldGoodsQ = GetCargoGoods(refCharacter,GetGoodsIndexForI(nCurScrollNum));
		int deltaGoodsW = GetGoodWeightByType(GetGoodsIndexForI(nCurScrollNum),oldGoodsQ-nDiscardQuantity) - GetGoodWeightByType(GetGoodsIndexForI(nCurScrollNum),oldGoodsQ);
        GameInterface.strings.FreeSpace = (GetCargoLoad(refCharacter)+deltaGoodsW) + "/" + GetCargoMaxSpace(refCharacter);
    }
}

void IncreaseDiscard()
{
    if( nDiscardQuantity<GetCargoGoods(refCharacter,GetGoodsIndexForI(nCurScrollNum)) )
    {
		nDiscardQuantity = nDiscardQuantity + GetGoodsUnitSize();
		if( nDiscardQuantity > GetCargoGoods(refCharacter,GetGoodsIndexForI(nCurScrollNum)) )
		{
			nDiscardQuantity = GetCargoGoods(refCharacter,GetGoodsIndexForI(nCurScrollNum));
		}
        GameInterface.strings.Discarding = ""+nDiscardQuantity;
		int oldGoodsQ = GetCargoGoods(refCharacter,GetGoodsIndexForI(nCurScrollNum));
		int deltaGoodsW = GetGoodWeightByType(GetGoodsIndexForI(nCurScrollNum),oldGoodsQ-nDiscardQuantity) - GetGoodWeightByType(GetGoodsIndexForI(nCurScrollNum),oldGoodsQ);
        GameInterface.strings.FreeSpace = (GetCargoLoad(refCharacter)+deltaGoodsW) + "/" + GetCargoMaxSpace(refCharacter);
    }
}

int GetGoodsIndexForI(int n)
{
	if(n<0) return 0;
	string attrName = "pic"+(n+1);
	return sti(GameInterface.goodslist.(attrName).goodsNum);
}

int GetGoodsUnitSize()
{
	if(nCurScrollNum<0) return 0;
	return sti( Goods[GetGoodsIndexForI(nCurScrollNum)].Units );
}

void ProcessInfo()
{
	SetShowType(SHOW_TYPE_INFO);

	string goodName;
	int lngFileID = LanguageOpenFile("GoodsDescribe.txt");
	goodName = Goods[GetGoodsIndexForI(nCurScrollNum)].Name;
	//string goodsDescr = LanguageConvertString(lngFileID,goodName) + LanguageConvertString(lngFileID,"newline");
	string goodsDescr = GetAssembledString( LanguageConvertString(lngFileID,goodName+"_descr"), &Goods[GetGoodsIndexForI(nCurScrollNum)]);
	SetFormatedText("GOODS_DESCRIBE",goodsDescr);
	LanguageCloseFile(lngFileID);

	SetCurrentNode("GOODS_DESCRIBE");
}

void SetShowType(int newShowType)
{
	if(newShowType==nCurShowType) return;

	switch(nCurShowType)
	{
	case SHOW_TYPE_MAIN:
		SetNodeUsing("DISCARD_BUTTON",false);
		SetNodeUsing("INFO_BUTTON",false);
		SetNodeUsing("MAIN_IMAGES",false);
		DisableString("Weight");
		DisableString("FreeSpace");
	break;
	case SHOW_TYPE_DISCARD:
		SetNodeUsing("DISCARD_COUNTER",false);
		SetNodeUsing("ALL_DISCARD",false);
		SetNodeUsing("OK_DISCARD",false);
		SetNodeUsing("MAIN_IMAGES",false);
		DisableString("Discarding");
		DisableString("Weight");
		DisableString("FreeSpace");
	break;
	case SHOW_TYPE_INFO:
		SetNodeUsing("GOODS_DESCRIBE",false);
	break;
	}

	nCurShowType = newShowType;
	switch(nCurShowType)
	{
	case SHOW_TYPE_MAIN:
		SetNodeUsing("DISCARD_BUTTON",true);
		SetNodeUsing("INFO_BUTTON",true);
		SetNodeUsing("MAIN_IMAGES",true);
		EnableString("Weight");
		EnableString("FreeSpace");
	break;
	case SHOW_TYPE_DISCARD:
		SetNodeUsing("DISCARD_COUNTER",true);
		SetNodeUsing("ALL_DISCARD",true);
		SetNodeUsing("OK_DISCARD",true);
		SetNodeUsing("MAIN_IMAGES",true);
		EnableString("Discarding");
		EnableString("Weight");
		EnableString("FreeSpace");
	break;
	case SHOW_TYPE_INFO:
		SetNodeUsing("GOODS_DESCRIBE",true);
	break;
	}
}

void ProcessCommandExecute()
{
	string comName = GetEventData();
	string nodName = GetEventData();

	switch(nodName)
	{
	case "GOODSLIST":
		if(comName=="activate" || comName=="downstep")	{SelectDiscard();}
	break;

	case "DISCARD_BUTTON":
		if(comName=="activate" || comName=="click")
		{
			ProcessDiscard();
			SetCurrentNode("DISCARD_COUNTER");
		}
	break;

	case "INFO_BUTTON":
		if(comName=="activate" || comName=="click")	{ProcessInfo();}
		if(comName=="leftstep")	{SelectDiscard();}
	break;

	case "DISCARD_COUNTER":
		if(comName=="deactivate")	{DiscardCancel();}
		if(comName=="leftstep")		{DecreaseDiscard();}
		if(comName=="rightstep")	{IncreaseDiscard();}
	break;

	case "ALL_DISCARD":
		if(comName=="deactivate")	{DiscardCancel();}
		if(comName=="activate" || comName=="click")
		{
			DiscardAll();
			SetCurrentNode("GOODSLIST");
		}
	break;

	case "OK_DISCARD":
		if(comName=="deactivate")	{DiscardCancel();}
		if(comName=="activate" || comName=="click")
		{
			DiscardOk();
			SetCurrentNode("GOODSLIST");
		}
	break;
	}
}

int GetXForShipName()
{
	if(nCurFourNum==0 || nCurFourNum==2) return 79;
	return 561;
}

int GetYForShipName()
{
	if(nCurFourNum==0 || nCurFourNum==1) return 300;
	return 448;
}

string GetShowGoodsName(string baseName)
{
	int n;
	string tmpStr;
	string showName = XI_ConvertString(baseName);
	if( GetStringWidth(showName,"interface_normal",1.0) > 128 )
	{
		for( n=strlen(showName)-1; n>0; n-- )
		{
			tmpStr = strcut(showName,0,n) + "...";
			if( GetStringWidth(tmpStr,"interface_normal",1.0) <= 128 ) {
				break;
			}
		}
		showName = tmpStr;
	}
	return showName;
}

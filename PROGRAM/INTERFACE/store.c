#define SHOW_MAIN	0
#define SHOW_BUY	1
#define SHOW_SELL	2
#define SHOW_INFO	3

int showType;

int	nCurScrollNum;
string oldCurNode="";

ref refCharacter;
ref refStore;

int nPlayerMoney;
int nTradeQuantity;

void InitInterface_RR(string iniName,ref pChar,ref pStore)
{
    refStore = pStore;
	refCharacter = pChar;
    showType = SHOW_MAIN;

    GameInterface.title = "titleStore";

    FillScroll();
    SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);
    SetVariable();

    CreateString(true,"Money","",FONT_NORMAL,COLOR_MONEY,320,389,SCRIPT_ALIGN_CENTER,1.0);
    CreateString(true,"ShipName","",FONT_NORMAL,COLOR_NORMAL,320,199,SCRIPT_ALIGN_CENTER,1.0);
    CreateString(true,"GoodsName","",FONT_NORMAL,COLOR_NORMAL,320,235,SCRIPT_ALIGN_CENTER,1.0);
    CreateString(true,"GoodsWeight","",FONT_NORMAL,COLOR_NORMAL,324,267,SCRIPT_ALIGN_LEFT,1.0);
    CreateString(true,"BuyPrice","",FONT_BOLD_NUMBERS,COLOR_NORMAL,260,301,SCRIPT_ALIGN_RIGHT,0.75);
    CreateString(true,"SellPrice","",FONT_BOLD_NUMBERS,COLOR_NORMAL,380,301,SCRIPT_ALIGN_LEFT,0.75);
    CreateString(true,"OnShipQuantity","",FONT_BOLD_NUMBERS,COLOR_NORMAL,79,360,SCRIPT_ALIGN_CENTER,1.0);
    CreateString(true,"OnShipSpaceQuantity","",FONT_BOLD_NUMBERS,COLOR_NORMAL,79,415,SCRIPT_ALIGN_CENTER,1.0);
    CreateString(true,"OnStoreQuantity","",FONT_BOLD_NUMBERS,COLOR_NORMAL,561,413,SCRIPT_ALIGN_CENTER,1.0);

    CreateString(false,"PriceSum","",FONT_NORMAL,COLOR_NORMAL,324,245,SCRIPT_ALIGN_LEFT,1.0);
    CreateString(false,"TradeQuantity","",FONT_NORMAL,COLOR_NORMAL,320,275,SCRIPT_ALIGN_CENTER,1.0);
    CreateString(false,"GoodWeightSum","",FONT_NORMAL,COLOR_NORMAL,324,350,SCRIPT_ALIGN_LEFT,1.0);

	SetNodeUsing("BUYSELL_IMAGES",false);
    SetNodeUsing("OK_BUTTON",false);
    SetNodeUsing("CANCEL_BUTTON",false);
    SetNodeUsing("TRADEQUANTITY",false);

	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
    SetEventHandler("frame","ProcessFrame",1);
    SetEventHandler("BuyPress","ProcessBuy",0);
    SetEventHandler("SellPress","ProcessSell",0);
    SetEventHandler("OkPress","ProcessOk",0);
    SetEventHandler("CancelPress","ProcessCancel",0);
    SetEventHandler("decreaseTrade","ProcessTradeDecrease",0);
    SetEventHandler("increaseTrade","ProcessTradeIncrease",0);
    SetEventHandler("exitCancel","ProcessCancelExit",0);
    SetEventHandler("ievntGetHelpTexture","iprocGetHelpTexture",0);
	SetEventHandler("ievnt_command","ProcessCommandExecute",0);
}

void ProcessFrame()
{
    if(sti(GameInterface.scrollitems.current)!=nCurScrollNum)
    {
		nCurScrollNum = sti(GameInterface.scrollitems.current);
		SetShowMode(SHOW_MAIN);
		RefreshAllStrings();
		SetBuySellEnable();
		return;
    }

	if(oldCurNode!=GetCurrentNode())
	{
		oldCurNode = GetCurrentNode();
		switch(oldCurNode)
		{
		case "SCROLLITEMS": SetShowMode(SHOW_MAIN); break;
		case "BUY_BUTTON": SetShowMode(SHOW_MAIN); break;
		case "SELL_BUTTON": SetShowMode(SHOW_MAIN); break;
		}
		RefreshAllStrings();
	}
}

void RefreshAllStrings()
{
	if(showType==SHOW_MAIN)
	{
		GameInterface.strings.Money = MakeMoneyShow(nPlayerMoney,MONEY_SIGN,MONEY_DELIVER);
		GameInterface.strings.GoodsName = XI_ConvertString(Goods[GetGoodsIndexForI(nCurScrollNum)].Name);
		GameInterface.strings.GoodsWeight = Goods[GetGoodsIndexForI(nCurScrollNum)].Weight;
		GameInterface.strings.BuyPrice = "" + GetStoreGoodsPrice(refStore,GetGoodsIndexForI(nCurScrollNum),PRICE_TYPE_BUY,refCharacter);
		GameInterface.strings.SellPrice = "" + GetStoreGoodsPrice(refStore,GetGoodsIndexForI(nCurScrollNum),PRICE_TYPE_SELL,refCharacter);
		GameInterface.strings.OnShipQuantity = "" + GetCargoGoods(refCharacter,GetGoodsIndexForI(nCurScrollNum));
		GameInterface.strings.OnShipSpaceQuantity = "" + GetCargoFreeSpace(refCharacter);
		GameInterface.strings.OnStoreQuantity = "" + GetStoreGoodsQuantity(refStore,GetGoodsIndexForI(nCurScrollNum));
		if( CheckAttribute(refCharacter,"Ship.Name") ) {
			GameInterface.strings.ShipName = refCharacter.Ship.Name;
		} else {
			GameInterface.strings.ShipName = XI_ConvertString(SHIP_NAME_NOTUSED);
		}
	}
	else
	{
	    GameInterface.strings.TradeQuantity = "" + nTradeQuantity;
	    GameInterface.strings.GoodWeightSum = "" + GetGoodWeightByType(GetGoodsIndexForI(nCurScrollNum),nTradeQuantity);
		int priceSum;
		if(showType==SHOW_BUY) {
			priceSum = GetGoodPriceByType(GetGoodsIndexForI(nCurScrollNum),nTradeQuantity,GetStoreGoodsPrice(refStore,GetGoodsIndexForI(nCurScrollNum),PRICE_TYPE_BUY,refCharacter));
		} else {
			priceSum = GetGoodPriceByType(GetGoodsIndexForI(nCurScrollNum),nTradeQuantity,GetStoreGoodsPrice(refStore,GetGoodsIndexForI(nCurScrollNum),PRICE_TYPE_SELL,refCharacter));
		}
		GameInterface.strings.priceSum = "" + priceSum;
	}
}

void SetVariable()
{
    nCurScrollNum = -1;

	ref mainRef = GetMainCharacter();
	nPlayerMoney = sti(mainRef.Money);
	nTradeQuantity = 0;
}

void FillScroll()
{
    int i;
    string goodName;
    string attributeName;
    aref pRef;

    GameInterface.scrollitems.current = 0;
	GameInterface.scrollitems.ImagesGroup.t0 = "ICONS";
	GameInterface.scrollitems.ImagesGroup.t1 = "TRADE_STATE";
	GameInterface.scrollitems.ImagesGroup.t2 = "GOODS";

	int idx = 1;
    for(i=0; i<GOODS_QUANTITY; i++)
    {
		if( !GetStoreGoodsUsed(refStore,i) ) continue;
        attributeName = "pic" + idx;
        goodName = Goods[i].Name;

        makearef(pRef,GameInterface.scrollitems.(attributeName));
        pRef.str1 = "#" + GetShowGoodsName(goodName);
        pRef.img1 = "cannon back";
        pRef.img2 = goodName;
		pRef.img3 = GetGoodStatus(goodName, true);
		pRef.img4 = GetGoodStatus(goodName, false);
		pRef.tex1 = 0;
		pRef.tex2 = 2;
		pRef.tex3 = 1;
		pRef.tex4 = 1;
		pRef.goodsIndex = i;
		idx++;
    }
	GameInterface.scrollitems.ListSize = idx-1;
}

void ProcessBuy()
{
    nTradeQuantity = 0;
	SetShowMode(SHOW_BUY);
	RefreshAllStrings();
}

void ProcessSell()
{
    nTradeQuantity  = GetCargoGoods(refCharacter,GetGoodsIndexForI(nCurScrollNum));
	SetShowMode(SHOW_SELL);
	RefreshAllStrings();
}

void ProcessOk()
{
	if(nTradeQuantity<0) return;

	if(showType==SHOW_BUY)
	{
		SetStoreGoods(refStore,GetGoodsIndexForI(nCurScrollNum),GetStoreGoodsQuantity(refStore,GetGoodsIndexForI(nCurScrollNum))-nTradeQuantity);
		AddCharacterGoods(refCharacter,GetGoodsIndexForI(nCurScrollNum),nTradeQuantity);
		nPlayerMoney = nPlayerMoney - GetGoodPriceByType(GetGoodsIndexForI(nCurScrollNum),nTradeQuantity,GetStoreGoodsPrice(refStore,GetGoodsIndexForI(nCurScrollNum),PRICE_TYPE_BUY,refCharacter));
	}
	if(showType==SHOW_SELL)
	{
		SetStoreGoods(refStore,GetGoodsIndexForI(nCurScrollNum),GetStoreGoodsQuantity(refStore,GetGoodsIndexForI(nCurScrollNum))+nTradeQuantity);
		RemoveCharacterGoods(refCharacter,GetGoodsIndexForI(nCurScrollNum),nTradeQuantity);
		nPlayerMoney = nPlayerMoney + GetGoodPriceByType(GetGoodsIndexForI(nCurScrollNum),nTradeQuantity,GetStoreGoodsPrice(refStore,GetGoodsIndexForI(nCurScrollNum),PRICE_TYPE_SELL,refCharacter));
	}
	ref tmpref = GetMainCharacter();
	tmpref.Money = nPlayerMoney;
    ScrollChange();

	SetShowMode(SHOW_MAIN);
	RefreshAllStrings();
	SetBuySellEnable();
	SetCurrentNode("SCROLLITEMS");
}

void ProcessCancel()
{
	nTradeQuantity = 0;
	SetShowMode(SHOW_MAIN);
	RefreshAllStrings();
	SetCurrentNode("SCROLLITEMS");
}

void ProcessTradeDecrease()
{
    if(nTradeQuantity<=0) return;
	nTradeQuantity = nTradeQuantity - GetGoodsUnitSize();
	if(nTradeQuantity<0) nTradeQuantity = 0;
	RefreshAllStrings();
}

void ProcessTradeIncrease()
{
	int nCurQuantity = GetCargoGoods(refCharacter,GetGoodsIndexForI(nCurScrollNum));
	int unitSize = GetGoodsUnitSize();
    if(showType==SHOW_BUY)
    {
        int max1 = GetGoodQuantityByWeight(GetGoodsIndexForI(nCurScrollNum),GetCargoFreeSpace(refCharacter)+GetGoodWeightByType(GetGoodsIndexForI(nCurScrollNum),nCurQuantity)) - nCurQuantity;
		int max2 = GetGoodQuantityByPrice(GetGoodsIndexForI(nCurScrollNum),nPlayerMoney,GetStoreGoodsPrice(refStore,GetGoodsIndexForI(nCurScrollNum),PRICE_TYPE_BUY,refCharacter));
		int max3 = GetStoreGoodsQuantity(refStore,GetGoodsIndexForI(nCurScrollNum));
		if(nTradeQuantity>=max1) return;
		if(nTradeQuantity>=max2) return;
		if(nTradeQuantity>=max3) return;

		if(max1-nTradeQuantity < unitSize) unitSize = max1-nTradeQuantity;
		if(max2-nTradeQuantity < unitSize) unitSize = max2-nTradeQuantity;
		if(max3-nTradeQuantity < unitSize) unitSize = max3-nTradeQuantity;
		nTradeQuantity = nTradeQuantity + unitSize;
    }
    if(showType==SHOW_SELL)
    {
        if(nTradeQuantity>=nCurQuantity) return;
		nTradeQuantity = nTradeQuantity + unitSize;
		if(nTradeQuantity>nCurQuantity) nTradeQuantity = nCurQuantity;
    }
	RefreshAllStrings();
}

void ScrollChange()
{
	int n = GetGoodsIndexForI(nCurScrollNum);
	if(n<0) return;
	aref pRef;
    string attributeName = "pic" + (nCurScrollNum+1);
	makearef(pRef,GameInterface.scrollitems.(attributeName));
	pRef.img3 = GetGoodStatus(Goods[n].name, true);
	pRef.img4 = GetGoodStatus(Goods[n].name, false);
	pRef.tex3 = 1;
	pRef.tex4 = 1;
    SendMessage(&GameInterface,"lsl",MSG_INTERFACE_SCROLL_CHANGE,"SCROLLITEMS",nCurScrollNum);
}

void ProcessCancelExit()
{
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
    DelEventHandler("frame","ProcessFrame");
    DelEventHandler("BuyPress","ProcessBuy");
    DelEventHandler("SellPress","ProcessSell");
    DelEventHandler("OkPress","ProcessOk");
    DelEventHandler("CancelPress","ProcessCancel");
    DelEventHandler("decreaseTrade","ProcessTradeDecrease");
    DelEventHandler("increaseTrade","ProcessTradeIncrease");
    DelEventHandler("exitCancel","ProcessCancelExit");
	DelEventHandler("ievntGetHelpTexture","iprocGetHelpTexture");
	DelEventHandler("ievnt_command","ProcessCommandExecute");

	interfaceResultCommand = RC_INTERFACE_STORE_EXIT;
    EndCancelInterface(true);
}

int GetGoodPriceByType(int iGoodType,int quantity,int price)
{
	int unitSize = sti(Goods[iGoodType].Units);
	int sumPrice = (quantity*price + unitSize-1) / unitSize;
	return sumPrice;
}

int GetGoodQuantityByPrice(int iGoodType,int sumPrice,int price)
{
	int unitSize = sti(Goods[iGoodType].Units);
	int resQ = (sumPrice*unitSize) / price;
	return resQ;
}

void SetShowMode(int st)
{
	if(showType==st) return;

	switch(showType)
	{
	case SHOW_MAIN:
		DisableString("GoodsName");
		DisableString("GoodsWeight");
		DisableString("BuyPrice");
		DisableString("SellPrice");
		SetNodeUsing("BUY_BUTTON",false);
		SetNodeUsing("INFO_BUTTON",false);
		SetNodeUsing("SELL_BUTTON",false);
		SetNodeUsing("MAIN_IMAGES",false);
	break;

	case SHOW_BUY:
		DisableString("PriceSum");
		DisableString("TradeQuantity");
		DisableString("GoodWeightSum");
		SetNodeUsing("BUYSELL_IMAGES",false);
		SetNodeUsing("OK_BUTTON",false);
		SetNodeUsing("CANCEL_BUTTON",false);
		SetNodeUsing("TRADEQUANTITY",false);
		CreateImage("TradeType","","",0,0,0,0);
	break;

	case SHOW_SELL:
		DisableString("PriceSum");
		DisableString("TradeQuantity");
		DisableString("GoodWeightSum");
		SetNodeUsing("BUYSELL_IMAGES",false);
		SetNodeUsing("OK_BUTTON",false);
		SetNodeUsing("CANCEL_BUTTON",false);
		SetNodeUsing("TRADEQUANTITY",false);
		CreateImage("TradeType","","",0,0,0,0);
	break;

	case SHOW_INFO:
		SetNodeUsing("GOODS_DESCRIBE",false);
	break;
	}

	showType=st;
	switch(st)
	{
	case SHOW_MAIN:
		EnableString("GoodsName");
		EnableString("GoodsWeight");
		EnableString("BuyPrice");
		EnableString("SellPrice");
		SetNodeUsing("BUY_BUTTON",true);
		SetNodeUsing("INFO_BUTTON",true);
		SetNodeUsing("SELL_BUTTON",true);
		SetNodeUsing("MAIN_IMAGES",true);
	break;

	case SHOW_BUY:
		EnableString("PriceSum");
		EnableString("TradeQuantity");
		EnableString("GoodWeightSum");
		SetNodeUsing("BUYSELL_IMAGES",true);
		SetNodeUsing("OK_BUTTON",true);
		SetNodeUsing("CANCEL_BUTTON",true);
		SetNodeUsing("TRADEQUANTITY",true);
		CreateImage("TradeType","BUY_SELL","buy",126,242,190,306);
	break;

	case SHOW_SELL:
		EnableString("PriceSum");
		EnableString("TradeQuantity");
		EnableString("GoodWeightSum");
		SetNodeUsing("BUYSELL_IMAGES",true);
		SetNodeUsing("OK_BUTTON",true);
		SetNodeUsing("CANCEL_BUTTON",true);
		SetNodeUsing("TRADEQUANTITY",true);
		CreateImage("TradeType","BUY_SELL","sell",450,242,514,306);
	break;

	case SHOW_INFO:
		SetNodeUsing("GOODS_DESCRIBE",true);
		SetCurrentNode("GOODS_DESCRIBE");
		DoGoodsDescribe();
	break;
	}
}

int GetGoodsIndexForI(int n)
{
	string attrName = "pic"+(n+1);
	return sti(GameInterface.scrollitems.(attrName).goodsIndex);
}

int GetGoodsUnitSize()
{
	if(nCurScrollNum<0) return 0;
	return sti( Goods[GetGoodsIndexForI(nCurScrollNum)].Units );
}

string I_strRetVal;
ref iprocGetHelpTexture()
{
	string nodName = GetEventData();

	I_strRetVal = "";
	switch(nodName)
	{
	case "OK_BUTTON":
		if(showType==SHOW_BUY)
		{	I_strRetVal = "interfaces\help\store\store_buy_ok.tga";
		}
		else
		{	I_strRetVal = "interfaces\help\store\store_sell_ok.tga";
		}
	break;

	case "CANCEL_BUTTON":
		if(showType==SHOW_BUY)
		{	I_strRetVal = "interfaces\help\store\store_buy_cancel.tga";
		}
		else
		{	I_strRetVal = "interfaces\help\store\store_sell_cancel.tga";
		}
	break;

	case "TRADEQUANTITY":
		if(showType==SHOW_BUY)
		{	I_strRetVal = "interfaces\help\store\store_buy_quantity.tga";
		}
		else
		{	I_strRetVal = "interfaces\help\store\store_sell_quantity.tga";
		}
	break;
	}

	return &I_strRetVal;
}

void DoGoodsDescribe()
{
	string goodName;
	int lngFileID = LanguageOpenFile("GoodsDescribe.txt");
	goodName = Goods[GetGoodsIndexForI(nCurScrollNum)].Name;
	//string goodsDescr = LanguageConvertString(lngFileID,goodName) + LanguageConvertString(lngFileID,"newline");
	string goodsDescr = GetAssembledString( LanguageConvertString(lngFileID,goodName+"_descr"), &Goods[GetGoodsIndexForI(nCurScrollNum)]);
	SetFormatedText("GOODS_DESCRIBE",goodsDescr);
	LanguageCloseFile(lngFileID);
}

void SetBuySellEnable()
{
	bool sellEnable = false;
	bool buyEnable = false;

	int goodsIdx = GetGoodsIndexForI(nCurScrollNum);
	if(goodsIdx>=0)
	{
		if( GetCargoGoods(refCharacter,goodsIdx)>0 )	{sellEnable = true;}
		if( GetStoreGoodsQuantity(refStore,goodsIdx)>0 )	{buyEnable = true;}
	}

	SetSelectable("SELL_BUTTON",sellEnable);
	SetSelectable("BUY_BUTTON",buyEnable);
}

void ProcessCommandExecute()
{
	string comName = GetEventData();
	string nodName = GetEventData();

	switch(nodName)
	{
	case "INFO_BUTTON":
		if(comName=="activate" || comName=="click")
		{	SetShowMode(SHOW_INFO);
		}
		if(comName=="rightstep")
		{	if(GetSelectable("SELL_BUTTON")) {SetCurrentNode("SELL_BUTTON");}
		}
		if(comName=="leftstep")
		{	if(GetSelectable("BUY_BUTTON")) {SetCurrentNode("BUY_BUTTON");}
		}
	break;
	}
}

string GetGoodStatus(string goodName, bool bIsForMy)
{
	int nGoodIdx = FindGood(goodName);

	if(bIsForMy) {
		if( GetCargoGoods(refCharacter,nGoodIdx)>0 ) {return "sell";}
		return "";
	}

	else {
		if( GetStoreGoodsQuantity(refStore,nGoodIdx)>0 ) {return "buy";}
		return "";
	}
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

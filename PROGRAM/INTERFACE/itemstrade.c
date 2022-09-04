#define SHOW_MAIN		0
#define SHOW_BUY		1
#define SHOW_SELL		2
#define SHOW_DESCRIBE	3

int	nCurScrollNum = -1;
int showType = -1;
string oldCurNode = "";

ref refMyCh;
ref refTrader;

int nTradeQuantity = 0;

int idLngFile = -1;
int buyPrice = 0;
int sellPrice = 0;

bool bEnableDown = true;

void InitInterface_RR(string iniName,ref pChar,ref pTrader)
{
    refTrader = pTrader;
	refMyCh = pChar;

    GameInterface.title = "titleItemsTrade";

    FillScroll();
    SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);

	SetCurrentNode("ITEMSLIST");

    CreateString(true,"Money","",FONT_NORMAL,COLOR_MONEY,320,389,SCRIPT_ALIGN_CENTER,1.0);
    CreateString(true,"ChrName",refMyCh.name + " " + refMyCh.lastname,FONT_NORMAL,COLOR_NORMAL,320,199,SCRIPT_ALIGN_CENTER,1.0);
    CreateString(true,"ItemsName","",FONT_NORMAL,COLOR_NORMAL,320,245,SCRIPT_ALIGN_CENTER,1.0);
    CreateString(true,"BuyPrice","",FONT_BOLD_NUMBERS,COLOR_NORMAL,260,307,SCRIPT_ALIGN_RIGHT,0.75);
    CreateString(true,"SellPrice","",FONT_BOLD_NUMBERS,COLOR_NORMAL,380,307,SCRIPT_ALIGN_LEFT,0.75);
    CreateString(true,"OnMyQuantity","",FONT_BOLD_NUMBERS,COLOR_NORMAL,79,413,SCRIPT_ALIGN_CENTER,1.0);
    CreateString(true,"OnTraderQuantity","",FONT_BOLD_NUMBERS,COLOR_NORMAL,561,413,SCRIPT_ALIGN_CENTER,1.0);

    CreateString(false,"PriceSum","",FONT_NORMAL,COLOR_NORMAL,324,245,SCRIPT_ALIGN_LEFT,1.0);
    CreateString(false,"TradeQuantity","",FONT_NORMAL,COLOR_NORMAL,320,288,SCRIPT_ALIGN_CENTER,1.0);

	SetNodeUsing("BUYSELL_IMAGES",false);
    SetNodeUsing("OK_BUTTON",false);
    SetNodeUsing("CANCEL_BUTTON",false);
    SetNodeUsing("TRADEQUANTITY",false);
	SetNodeUsing("TEXTWINDOW",false);

	idLngFile = LanguageOpenFile("ItemsDescribe.txt");

	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
    SetEventHandler("frame","ProcessFrame",1);
    SetEventHandler("exitCancel","ProcessCancelExit",0);
	SetEventHandler("ievnt_command","ProcessCommandExecute",0);
}

void ProcessFrame()
{
	if(oldCurNode!=GetCurrentNode())
	{
		oldCurNode = GetCurrentNode();
		if(oldCurNode=="ITEMSLIST")
		{
			nCurScrollNum = -1;
		}
	}

    if(sti(GameInterface.itemslist.current)!=nCurScrollNum)
    {
		nCurScrollNum = sti(GameInterface.itemslist.current);
		SetShowMode(SHOW_MAIN);
		RefreshAllStrings();
		return;
    }
}

void RefreshAllStrings()
{
	int priceSum;
	string itmName = GetItemsID(nCurScrollNum);
	aref refitm;
	int itmIdx = Items_FindItem(itmName,&refitm);
	ref mchref = GetMainCharacter();

	if(itmIdx>=0)
	{
		GameInterface.strings.Money = MakeMoneyShow(sti(mchref.money),MONEY_SIGN,MONEY_DELIVER);
		if(CheckAttribute(refitm,"name"))
			{GameInterface.strings.ItemsName = LanguageConvertString(idLngFile,refitm.name);}
		else
			{GameInterface.strings.ItemsName = "";}
		buyPrice = GetTradeItemPrice(itmIdx,PRICE_TYPE_BUY);
		sellPrice = GetTradeItemPrice(itmIdx,PRICE_TYPE_SELL);
		GameInterface.strings.BuyPrice = buyPrice;
		GameInterface.strings.SellPrice = sellPrice;
		GameInterface.strings.OnMyQuantity = GetCharacterItem(refMyCh,itmName);
		GameInterface.strings.OnTraderQuantity = GetCharacterItem(refTrader,itmName);

		GameInterface.strings.TradeQuantity = nTradeQuantity;
		if(showType==SHOW_BUY)
		{	priceSum = nTradeQuantity * GetTradeItemPrice(itmIdx,PRICE_TYPE_BUY);
		}
		else
		{	priceSum = nTradeQuantity * GetTradeItemPrice(itmIdx,PRICE_TYPE_SELL);
		}
		GameInterface.strings.priceSum = priceSum;

		if(showType==SHOW_DESCRIBE)
		{
			SetItemDescribe(refitm);
		}

		SetSelectable("BUY_BUTTON",true);
		SetSelectable("SELL_BUTTON",true);
		if(buyPrice <= 0)
		{
			SetSelectable("BUY_BUTTON",false);
			SetSelectable("SELL_BUTTON",false);
			ShowHelpString("chelp_itemstrade#10");
			return;
		}
		if( GetCharacterItem(refMyCh,itmName)==1 && ItemUsedByCharacter(itmIdx) )
		{
			SetSelectable("SELL_BUTTON",false);
			ShowHelpString("chelp_itemstrade#11");
			return;
		}
		SendMessage(&GameInterface,"lsl",MSG_INTERFACE_MSG_TO_NODE,"CONTEXTHELP", 0);

		SetSelectable("BUY_BUTTON",GetCharacterItem(refTrader,itmName)>0);
		SetSelectable("SELL_BUTTON",GetCharacterItem(refMyCh,itmName)>0);
	}
	else
	{
		SetSelectable("BUY_BUTTON",false);
		SetSelectable("SELL_BUTTON",false);
	}
}

bool ItemUsedByCharacter(int itmIdx)
{
	if(itmIdx<0 || itmIdx>=ITEMS_QUANTITY) return false;
	return IsEquipCharacterByItem(GetMainCharacter(),Items[itmIdx].id);
}

int GetTradeItemPrice(int itmIdx, int tradeType)
{
	int itmprice = 0;
	if(itmIdx<0 || itmIdx>ITEMS_QUANTITY) return 0;

	if(CheckAttribute(&Items[itmIdx],"price"))
	{
		itmprice = sti(Items[itmIdx].price);
	}

	int skillDelta = GetSummonSkillFromName(refMyCh,SKILL_COMMERCE);
	float skillModify;
	if(tradeType==PRICE_TYPE_BUY)
	{
		skillModify = 1.4 - skillDelta*0.019;
		if(CheckOfficersPerk(refMyCh,"AdvancedCommerce"))	{ skillModify -= 0.2; }
		else
		{
			if(CheckOfficersPerk(refMyCh,"BasicCommerce"))	{ skillModify -= 0.1; }
		}
	}
	else
	{
		skillModify = 0.75 + skillDelta*0.019;
		if(CheckOfficersPerk(refMyCh,"AdvancedCommerce"))	skillModify += 0.05;
	}

	return makeint(makefloat(itmprice)*skillModify);
}

void FillScroll()
{
    int idx,i,j;
    string attributeName;
	string itemName;

	aref arImgGrp;
	makearef(arImgGrp,GameInterface.itemslist.ImagesGroup);
	arImgGrp.t0 = "ICONS";
	arImgGrp.t1 = "usedflag";
	arImgGrp.t2 = "TRADE_STATE";
	FillImagesGroupForItems(arImgGrp);
	GameInterface.itemslist.NotUsed = 5;
	GameInterface.itemslist.BadTex1 = GetItemPictureTexture("itemslist.ImagesGroup","");
	GameInterface.itemslist.BadPic1 = GetItemPictureName("");

	idx = 0;
	aref curItem,arItem;
	aref rootItems;

	makearef(rootItems,refMyCh.Items);
    for(i=0; i<GetAttributesNum(rootItems); i++)
    {
		attributeName = "pic" + (idx+1);
		curItem = GetAttributeN(rootItems,i);
		itemName = GetAttributeName(curItem);
		j = GetCharacterItem(refTrader,itemName);

		GameInterface.itemslist.(attributeName).img1 = GetItemPictureName(itemName);
		GameInterface.itemslist.(attributeName).tex1 = GetItemPictureTexture("itemslist.ImagesGroup",itemName);
		GameInterface.itemslist.(attributeName).str1 = "#"+j;
		GameInterface.itemslist.(attributeName).itemID = itemName;
		if( IsEquipCharacterByItem(refMyCh,itemName) )
		{
			GameInterface.itemslist.(attributeName).img2 = "usedflag";
			GameInterface.itemslist.(attributeName).tex2 = 1;
		}
		GameInterface.itemslist.(attributeName).img3 = GetItemStatus(itemName, true);
		GameInterface.itemslist.(attributeName).tex3 = 2;
		GameInterface.itemslist.(attributeName).img4 = GetItemStatus(itemName, false);
		GameInterface.itemslist.(attributeName).tex4 = 2;
		idx++;
    }

	makearef(rootItems,refTrader.Items);
    for(i=0; i<GetAttributesNum(rootItems); i++)
    {
		attributeName = "pic" + (idx+1);
		curItem = GetAttributeN(rootItems,i);
		itemName = GetAttributeName(curItem);
		if( CheckAttribute(refMyCh,"items."+itemName) ) continue;
		j = GetCharacterItem(refTrader,itemName);

		GameInterface.itemslist.(attributeName).img1 = GetItemPictureName(itemName);
		GameInterface.itemslist.(attributeName).tex1 = GetItemPictureTexture("itemslist.ImagesGroup",itemName);
		GameInterface.itemslist.(attributeName).str1 = "#"+j;
		GameInterface.itemslist.(attributeName).itemID = itemName;

		GameInterface.itemslist.(attributeName).img3 = GetItemStatus(itemName, true);
		GameInterface.itemslist.(attributeName).tex3 = 2;
		GameInterface.itemslist.(attributeName).img4 = GetItemStatus(itemName, false);
		GameInterface.itemslist.(attributeName).tex4 = 2;
		idx++;
    }

	GameInterface.itemslist.ListSize = idx;
	if(nCurScrollNum>=idx) nCurScrollNum = idx-1;
	if(nCurScrollNum<0)	nCurScrollNum = 0;
	GameInterface.itemslist.current = nCurScrollNum;
	nCurScrollNum = -1;
}

void ProcessCancelExit()
{
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
    DelEventHandler("frame","ProcessFrame");
    DelEventHandler("exitCancel","ProcessCancelExit");
	DelEventHandler("ievnt_command","ProcessCommandExecute");

	interfaceResultCommand = RC_INTERFACE_ITEMSTRADE_EXIT;
	LanguageCloseFile(idLngFile);
    EndCancelInterface(true);
}

void SetShowMode(int st)
{
	if(st==showType) return;

	switch(showType)
	{
	case SHOW_MAIN:
		DisableString("ItemsName");
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
		SetNodeUsing("BUYSELL_IMAGES",false);
		SetNodeUsing("OK_BUTTON",false);
		SetNodeUsing("CANCEL_BUTTON",false);
		SetNodeUsing("TRADEQUANTITY",false);
		CreateImage("TradeType","","",0,0,0,0);
	break;
	case SHOW_SELL:
		DisableString("PriceSum");
		DisableString("TradeQuantity");
		SetNodeUsing("BUYSELL_IMAGES",false);
		SetNodeUsing("OK_BUTTON",false);
		SetNodeUsing("CANCEL_BUTTON",false);
		SetNodeUsing("TRADEQUANTITY",false);
		CreateImage("TradeType","","",0,0,0,0);
	break;
	case SHOW_DESCRIBE:
		SetNodeUsing("TEXTWINDOW",false);
	break;
	}

	showType = st;

	switch(showType)
	{
	case SHOW_MAIN:
		EnableString("ItemsName");
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
		SetNodeUsing("BUYSELL_IMAGES",true);
		SetNodeUsing("OK_BUTTON",true);
		SetNodeUsing("CANCEL_BUTTON",true);
		SetNodeUsing("TRADEQUANTITY",true);
		CreateImage("TradeType","BUY_SELL","buy",126,242,190,306);
	break;
	case SHOW_SELL:
		EnableString("PriceSum");
		EnableString("TradeQuantity");
		SetNodeUsing("BUYSELL_IMAGES",true);
		SetNodeUsing("OK_BUTTON",true);
		SetNodeUsing("CANCEL_BUTTON",true);
		SetNodeUsing("TRADEQUANTITY",true);
		CreateImage("TradeType","BUY_SELL","sell",450,242,514,306);
	break;
	case SHOW_DESCRIBE:
		SetNodeUsing("TEXTWINDOW",true);
	break;
	}

}

string GetItemsID(int scrollIdx)
{
	if(scrollIdx<0) return "";
	string attributeName = "pic" + (scrollIdx+1);
	if( CheckAttribute(&GameInterface,"itemslist."+attributeName+".itemID") )
	{
		return GameInterface.itemslist.(attributeName).itemID;
	}
	return "";
}

void ProcessCommandExecute()
{
	string comName = GetEventData();
	string nodName = GetEventData();

	switch(nodName)
	{
	case "ITEMSLIST":
		if(comName=="deactivate")
		{
			PostEvent("exitCancel",1);
		}
		if(comName=="downstep" || comName=="speeddown")
		{
			if(GetSelectable("BUY_BUTTON"))
			{
				SetCurrentNode("BUY_BUTTON");
				return;
			}
			if(GetSelectable("SELL_BUTTON"))
			{
				SetCurrentNode("SELL_BUTTON");
				return;
			}
		}
	break;

	case "INFO_BUTTON":
		if(comName=="activate" || comName=="click")
		{
			SetShowMode(SHOW_DESCRIBE);
			RefreshAllStrings();
			SetCurrentNode("TEXTWINDOW");
			return;
		}
		if(comName=="leftstep")
		{
			if( GetSelectable("BUY_BUTTON") )
			{
				SetCurrentNode("BUY_BUTTON");
			}
			return;
		}
		if(comName=="rightstep")
		{
			if( GetSelectable("SELL_BUTTON") )
			{
				SetCurrentNode("SELL_BUTTON");
			}
			return;
		}
	break;

	case "BUY_BUTTON":
		if(comName=="activate" || comName=="click")
		{
			SetShowMode(SHOW_BUY);
			SetStartTradeQuantity();
			RefreshAllStrings();
			SetCurrentNode("TRADEQUANTITY");
		}
	break;

	case "SELL_BUTTON":
		if(comName=="activate" || comName=="click")
		{
			SetShowMode(SHOW_SELL);
			SetStartTradeQuantity();
			RefreshAllStrings();
			SetCurrentNode("TRADEQUANTITY");
		}
	break;

	case "TRADEQUANTITY":
		if(comName=="activate")
		{
			DoTradeOperation();
			SetShowMode(SHOW_MAIN);
			SetCurrentNode("ITEMSLIST");
			RefreshAllStrings();
		}
		switch(comName)
		{
		case "rightstep":	AddTradeQuantity(1); break;
		case "speedright":	AddTradeQuantity(10); break;
		case "leftstep":	AddTradeQuantity(-1); break;
		case "speedleft":	AddTradeQuantity(-10); break;
		}
	break;

	case "OK_BUTTON":
		if(comName=="activate" || comName=="click")
		{
			DoTradeOperation();
			SetShowMode(SHOW_MAIN);
			SetCurrentNode("ITEMSLIST");
			RefreshAllStrings();
		}
	break;

	case "CANCEL_BUTTON":
		if(comName=="activate" || comName=="click")
		{
			SetShowMode(SHOW_MAIN);
			SetCurrentNode("ITEMSLIST");
		}
	break;

	case "TEXTWINDOW":
		if(comName=="downstep")
		{
			if(!bEnableDown)
			{
				SendMessage(&GameInterface,"lslll",MSG_INTERFACE_MSG_TO_NODE,"TEXTWINDOW",-1, 0,ACTION_UPSTEP);
			} else {
				bEnableDown = SendMessage(&GameInterface,"lsll",MSG_INTERFACE_MSG_TO_NODE,"TEXTWINDOW", 6, 0);
			}
		}
		if(comName=="upstep")
		{
			bEnableDown = SendMessage(&GameInterface,"lsll",MSG_INTERFACE_MSG_TO_NODE,"TEXTWINDOW", 6, 0);
		}
	break;
	}
}

void DoTradeOperation()
{
	if(nTradeQuantity<=0) return;
	string itmName = GetItemsID(nCurScrollNum);
	ref mchref = GetMainCharacter();

	if(showType==SHOW_SELL)
	{
		TakeNItems(refTrader,itmName,nTradeQuantity);
		TakeNItems(refMyCh,itmName,-nTradeQuantity);
		AddMoneyToCharacter(mchref,nTradeQuantity*sellPrice);
	}

	if(showType==SHOW_BUY)
	{
		TakeNItems(refTrader,itmName,-nTradeQuantity);
		TakeNItems(refMyCh,itmName,nTradeQuantity);
		AddMoneyToCharacter(mchref,-nTradeQuantity*buyPrice);
	}

	nTradeQuantity = 0;
	if(sti(mchref.money)<0)
	{
		mchref.money = 0;
	}

	ChangeScroll();
}

void AddTradeQuantity(int incrVal)
{
	ref mchref = GetMainCharacter();
	nTradeQuantity = nTradeQuantity + incrVal;
	if(nTradeQuantity<0)
	{
		nTradeQuantity = 0;
		RefreshAllStrings();
		return;
	}

	if(buyPrice == 0)
	{
		nTradeQuantity = 0;
	}

	string itmName = GetItemsID(nCurScrollNum);
	if(showType==SHOW_SELL)
	{
		int realQ = GetCharacterItem(refMyCh,itmName);
		if( realQ>0 && IsEquipCharacterByItem(refMyCh,itmName) ) {realQ--;}
		if(realQ<nTradeQuantity)
		{
			nTradeQuantity = realQ;
		}
	}

	if(showType==SHOW_BUY)
	{
		if(GetCharacterItem(refTrader,itmName)<nTradeQuantity)
		{
			nTradeQuantity = GetCharacterItem(refTrader,itmName);
		}

		if(buyPrice*nTradeQuantity > sti(mchref.money))
		{
			nTradeQuantity = sti(mchref.money) / buyPrice;
		}
	}

	RefreshAllStrings();
}

void ChangeScroll()
{
	if(nCurScrollNum<0) return;
    string attributeName = "pic"+(nCurScrollNum+1);
	string itemName = GetItemsID(nCurScrollNum);
	GameInterface.itemslist.(attributeName).str1 = "#"+GetCharacterItem(refTrader,itemName);
	GameInterface.itemslist.(attributeName).img3 = GetItemStatus(itemName, true);
	GameInterface.itemslist.(attributeName).img4 = GetItemStatus(itemName, false);
	SendMessage(&GameInterface,"lsl", MSG_INTERFACE_SCROLL_CHANGE, "ITEMSLIST", nCurScrollNum);
}

void SetItemDescribe(aref arItm)
{
	string describeStr = "";
	if( CheckAttribute(arItm,"groupID") )
	{
		if(arItm.groupID==GUN_ITEM_TYPE)
		{
			describeStr += GetAssembledString(
				LanguageConvertString(idLngFile,"weapon gun parameters"),
				arItm) + LanguageConvertString(idLngFile,"new_string");
		}
		if(arItm.groupID==BLADE_ITEM_TYPE)
		{
			describeStr += GetAssembledString(
				LanguageConvertString(idLngFile,"weapon blade parameters"),
				arItm) + LanguageConvertString(idLngFile,"new_string");
		}
	}
	if( CheckAttribute(arItm,"describe") )
	{
		describeStr += LanguageConvertString(idLngFile,arItm.describe);
	}
	SetFormatedText("TEXTWINDOW",describeStr);

	bEnableDown = SendMessage(&GameInterface,"lsll",MSG_INTERFACE_MSG_TO_NODE,"TEXTWINDOW", 6, 0);
}

void SetStartTradeQuantity()
{
	if( showType == SHOW_SELL )
	{
		nTradeQuantity = GetCharacterItem(refMyCh,GetItemsID(nCurScrollNum));
		if( nTradeQuantity>0 && IsEquipCharacterByItem(refMyCh, GetItemsID(nCurScrollNum)) ) {
			nTradeQuantity--;
		}
		return;
	}

	nTradeQuantity = 0;
	AddTradeQuantity(1);
}

string GetItemStatus(string itemName, bool bIsForMy)
{
	if(bIsForMy) {
		if( GetCharacterItem(refMyCh,itemName)>0 ) {return "sell";}
		return "";
	}

	else {
		if( GetCharacterItem(refTrader,itemName)>0 ) {return "buy";}
		return "";
	}
}

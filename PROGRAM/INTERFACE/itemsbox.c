#define ITEM_MODE_SWAP		0
#define ITEM_MODE_TAKE		1
#define ITEM_MODE_NONE		2
#define ITEM_MODE_INFO		3

aref g_refItems;

int nCurScroll1;
int nCurScroll2;

string oldNodeName="";
int oldItemMode = -1;

bool g_bIBoxUsed;

string oldCurScrollName = "ONE_ITEMSLIST";

int idLngFile;

bool bEnableDown = false;

void InitInterface_RS(string iniName,ref itemsRef,string faceID)
{
	if(faceID=="") {
		GameInterface.title = "titleItemsBox";
	}
	else {
		GameInterface.title = "titleExchangeItems";
	}
	g_refItems = itemsRef;

	idLngFile = LanguageOpenFile("ItemsDescribe.txt");

	FillScroll();
	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);

	CreateImage("MyPic",GetFaceGroupName(GetMainCharacterIndex()),GetFacePictureName(GetMainCharacterIndex()),5,39,133,167);

	GameInterface.pictures.OtherPic.tex = "";
	GameInterface.pictures.OtherPic.pic = "";
	SetNodeUsing( "FACEPICT", faceID!="" );
	if(faceID=="")
	{
		g_bIBoxUsed = true;
		CreateImage("OtherPic","BOX_IMAGE","BoxImage",5,302,133,430);
	}
	else
	{
		g_bIBoxUsed = false;
		SetNewPicture("FACEPICT", "interfaces\portraits\128\face_" + faceID + ".tga");
	}

	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
	SetEventHandler("exitCancel","ProcessCancelExit",0);
	SetEventHandler("frame","FrameProcess",1);

	SetEventHandler("ievnt_command","ProcInterfaceCommand",0);

	SetItemMode(ITEM_MODE_SWAP);

	IGotoNewNode("TWO_ITEMSLIST");
	IGotoNewNode("ONE_ITEMSLIST");

	SetUpDownUsed();
	SetScrollsUsing();
}

void FrameProcess()
{
	IGotoNewNode(GetCurrentNode());

	if( nCurScroll1 != sti(GameInterface.one_itemslist.current) ||
		nCurScroll2 != sti(GameInterface.two_itemslist.current) )
	{
		nCurScroll1 = sti(GameInterface.one_itemslist.current);
		nCurScroll2 = sti(GameInterface.two_itemslist.current);
		if(oldItemMode!=ITEM_MODE_SWAP)	{SetItemMode(ITEM_MODE_SWAP);}
		SetUpDownUsed();
	}
}

void FillScroll()
{
    int i,j,q;
    string attributeName;
	aref curItem,arItem,rootItems;
	aref arImgGrp;
	ref mchref = GetMainCharacter();

	if(CheckAttribute(&GameInterface,"one_itemslist.current"))
		nCurScroll1 = sti(GameInterface.one_itemslist.current);
	else	nCurScroll1 = 0;
	if(CheckAttribute(&GameInterface,"two_itemslist.current"))
		nCurScroll2 = sti(GameInterface.two_itemslist.current);
	else	nCurScroll2 = 0;

	DeleteAttribute(&GameInterface,"one_itemslist");
	DeleteAttribute(&GameInterface,"two_itemslist");

	//============================================================================
	// Наши вещи
	//============================================================================
	GameInterface.one_itemslist.NotUsed = 5;
	GameInterface.one_itemslist.current = nCurScroll1;
	makearef(arImgGrp,GameInterface.one_itemslist.ImagesGroup);
	FillImagesGroupForItems(arImgGrp);

	i=0;
	// Пропишем деньги
	if( sti(mchref.Money)>0 )
	{
		GameInterface.one_itemslist.pic1.img1 = GetItemPictureName("Gold");
		GameInterface.one_itemslist.pic1.tex1 = GetItemPictureTexture("one_itemslist.ImagesGroup","Gold");
		GameInterface.one_itemslist.pic1.itemID = "Money";
		GameInterface.one_itemslist.pic1.str1 = "#"+mchref.Money;
		i++;
	}
	// Заполним вещами от нас
	makearef(rootItems,mchref.Items);
    for(j=0; j<GetAttributesNum(rootItems); j++)
    {
		attributeName = "pic" + (i+1);
		curItem = GetAttributeN(rootItems,j);

		if( Items_FindItem(GetAttributeName(curItem),&arItem)>=0 )
		{
			GameInterface.one_itemslist.(attributeName).img1 = GetItemPictureName(arItem.id);
			GameInterface.one_itemslist.(attributeName).tex1 = GetItemPictureTexture("one_itemslist.ImagesGroup",arItem.id);
			GameInterface.one_itemslist.(attributeName).itemID = arItem.id;
			if(CheckConsumedItem(arItem.id))
				GameInterface.one_itemslist.(attributeName).str1 = "#"+sti(GetAttributeValue(curItem));
		}
		else
		{
			trace("WARNING! Can`t find item ID = "+GetAttributeName(curItem));
			GameInterface.one_itemslist.(attributeName).img1 = "itm16";
			GameInterface.one_itemslist.(attributeName).tex1 = 0;
		}
		i++;
    }
	GameInterface.one_itemslist.ListSize = i;

	//============================================================================
	// Чужие вещи
	//============================================================================
	GameInterface.two_itemslist.NotUsed = 5;
	GameInterface.two_itemslist.current = nCurScroll2;
	makearef(arImgGrp,GameInterface.two_itemslist.ImagesGroup);
	FillImagesGroupForItems(arImgGrp);

	i=0;
	// Пропишем деньги
	if(!CheckAttribute(g_refItems,"Money"))	g_refItems.Money = 0;

	makearef(rootItems,g_refItems.Items);
	q = GetAttributesNum(rootItems);

	// Найдем все монеты и переведем их в деньги
	for(j=0; j<q; j++)
	{
		curItem = GetAttributeN(rootItems,j);
		if(sti(GetAttributeValue(curItem))<=0)	continue;
		if( Items_FindItem(GetAttributeName(curItem),&arItem)>=0 )
		{
			if( CheckAttribute(arItem,"Gold") )
			{
				g_refItems.Money = sti(g_refItems.Money) + sti(arItem.Gold)*GetCharacterItem(g_refItems,arItem.Gold);
				DeleteAttribute(rootItems,arItem.id);
				j--; q--;
			}
		}
	}
	if( sti(g_refItems.Money)>0 )
	{
		GameInterface.two_itemslist.pic1.img1 = GetItemPictureName("Gold");
		GameInterface.two_itemslist.pic1.tex1 = GetItemPictureTexture("two_itemslist.ImagesGroup","Gold");
		GameInterface.two_itemslist.pic1.itemID = "Money";
		GameInterface.two_itemslist.pic1.str1 = "#"+g_refItems.Money;
		i++;
	}

	for(j=0; j<q; j++)
	{
		attributeName = "pic" + (i+1);
		curItem = GetAttributeN(rootItems,j);

		if(sti(GetAttributeValue(curItem))<=0)	continue;

		if( Items_FindItem(GetAttributeName(curItem),&arItem)>=0 )
		{
			GameInterface.two_itemslist.(attributeName).img1 = GetItemPictureName(arItem.id);
			GameInterface.two_itemslist.(attributeName).tex1 = GetItemPictureTexture("two_itemslist.ImagesGroup",arItem.id);
			GameInterface.two_itemslist.(attributeName).itemID = arItem.id;
			if(CheckConsumedItem(arItem.id)) {
				GameInterface.two_itemslist.(attributeName).str1 = "#"+sti(GetAttributeValue(curItem));
			}
		}
		else
		{
			trace("WARNING! Can`t find item ID = "+GetAttributeName(curItem));
			GameInterface.two_itemslist.(attributeName).img1 = "itm16";
			GameInterface.two_itemslist.(attributeName).tex1 = 0;
		}
		i++;
	}
	GameInterface.two_itemslist.ListSize = i;

	nCurScroll1 = sti(GameInterface.one_itemslist.current);
	nCurScroll2 = sti(GameInterface.two_itemslist.current);
}

void ProcessCancelExit()
{
	if(oldItemMode==ITEM_MODE_INFO) SetItemMode(ITEM_MODE_SWAP);
	else	IDoExit(RC_INTERFACE_ITEMSBOX_EXIT);
}

void IDoExit(int exitCode)
{
	LanguageCloseFile(idLngFile);
	if(!g_bIBoxUsed)
	{
		if( GetCharacterSkill(g_refItems,"fencing") > 0 )
		{
			EquipCharacterByItem(g_refItems, FindCharacterItemByGroup(g_refItems,BLADE_ITEM_TYPE));
			EquipCharacterByItem(g_refItems, FindCharacterItemByGroup(g_refItems,GUN_ITEM_TYPE));
		}
	}
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
	DelEventHandler("exitCancel","ProcessCancelExit");
	DelEventHandler("frame","FrameProcess");
	DelEventHandler("ievnt_command","ProcInterfaceCommand");

    interfaceResultCommand = exitCode;
    EndCancelInterface(true);
}

void IGotoNewNode(string newNode)
{
	if(oldNodeName==newNode) return;
	oldNodeName=newNode;
	if(newNode=="ONE_ITEMSLIST")	SetScroll(true);
	if(newNode=="TWO_ITEMSLIST")	SetScroll(false);

	if(oldItemMode==ITEM_MODE_SWAP)
	{
		if(newNode=="DESCRIBEWINDOW")	{SetItemMode(ITEM_MODE_INFO);}
	}
	else
	{
		if(newNode!="DESCRIBEWINDOW")
		{
			SetItemMode(ITEM_MODE_SWAP);
			SetUpDownUsed();
		}
	}
}

void SetScroll(bool bIsOne)
{
	if(bIsOne)
	{
		if(oldCurScrollName=="TWO_ITEMSLIST")
		{
			SetNodeUsing("TWO_LEFTSCROLLBUTTON",false);
			SetNodeUsing("TWO_RIGHTSCROLLBUTTON",false);
		}
		SetNodeUsing("ONE_LEFTSCROLLBUTTON",true);
		SetNodeUsing("ONE_RIGHTSCROLLBUTTON",true);
		oldCurScrollName = "ONE_ITEMSLIST";
	}
	else
	{
		if(oldCurScrollName=="ONE_ITEMSLIST")
		{
			SetNodeUsing("ONE_LEFTSCROLLBUTTON",false);
			SetNodeUsing("ONE_RIGHTSCROLLBUTTON",false);
		}
		SetNodeUsing("TWO_LEFTSCROLLBUTTON",true);
		SetNodeUsing("TWO_RIGHTSCROLLBUTTON",true);
		oldCurScrollName = "TWO_ITEMSLIST";
	}
}

void SetItemMode(int mode)
{
	switch(oldItemMode)
	{
	case ITEM_MODE_SWAP:
		SetNodeUsing("INFO_BUTTON",false);
		SetNodeUsing("SWAP_BUTTON",false);
		SetNodeUsing("ONEUP_BUTTON",false);
		SetNodeUsing("ONEDOWN_BUTTON",false);
		SetNodeUsing("ALLUP_BUTTON",false);
		SetNodeUsing("ALLDOWN_BUTTON",false);
	break;
	case ITEM_MODE_INFO:	SetNodeUsing("DESCRIBEWINDOW",false);	break;
	}

	oldItemMode = mode;

	switch(mode)
	{
	case ITEM_MODE_SWAP:
		SetNodeUsing("INFO_BUTTON",true);
		SetNodeUsing("SWAP_BUTTON",true);
		SetNodeUsing("ONEUP_BUTTON",true);
		SetNodeUsing("ONEDOWN_BUTTON",true);
		SetNodeUsing("ALLUP_BUTTON",true);
		SetNodeUsing("ALLDOWN_BUTTON",true);
	break;
	case ITEM_MODE_INFO:	SetNodeUsing("DESCRIBEWINDOW",true);	break;
	}
}

void ProcInterfaceCommand()
{
	string comName = GetEventData();
	string nodeName = GetEventData();

	switch(nodeName)
	{
	case "INFO_BUTTON":
		if(comName=="upstep") {GoToTopScroll();}
		if(comName=="downstep") {GoToBottomScroll();}
		if(comName=="rightstep") {SelectButtonRight("ONEDOWN_BUTTON");}
		if(comName=="deactivate")	{SetCurrentNode(oldCurScrollName);}
		if(comName=="activate" || comName=="click")
		{
			SetItemMode(ITEM_MODE_INFO);
			SetDescribeText();
			SetCurrentNode("DESCRIBEWINDOW");
		}
	break;

	case "ONEDOWN_BUTTON":
		if(comName=="upstep") {GoToTopScroll();}
		if(comName=="downstep") {GoToBottomScroll();}
		if(comName=="leftstep") {SelectButtonLeft("INFO_BUTTON");}
		if(comName=="rightstep") {SelectButtonRight("ONEUP_BUTTON");}
		if(comName=="activate" || comName=="click")	{GiveOneItem();}
		if(comName=="deactivate")	{SetCurrentNode(oldCurScrollName);}
	break;

	case "ONEUP_BUTTON":
		if(comName=="upstep") {GoToTopScroll();}
		if(comName=="downstep") {GoToBottomScroll();}
		if(comName=="leftstep") {SelectButtonLeft("ONEDOWN_BUTTON");}
		if(comName=="rightstep") {SelectButtonRight("SWAP_BUTTON");}
		if(comName=="activate" || comName=="click")	{TakeOneItem();}
		if(comName=="deactivate")	{SetCurrentNode(oldCurScrollName);}
	break;

	case "SWAP_BUTTON":
		if(comName=="upstep") {GoToTopScroll();}
		if(comName=="downstep") {GoToBottomScroll();}
		if(comName=="leftstep") {SelectButtonLeft("ONEUP_BUTTON");}
		if(comName=="rightstep") {SelectButtonRight("ALLUP_BUTTON");}
		if(comName=="activate" || comName=="click")	{ChangeItemsSlot();}
		if(comName=="deactivate")	{SetCurrentNode(oldCurScrollName);}
	break;

	case "ALLUP_BUTTON":
		if(comName=="upstep") {GoToTopScroll();}
		if(comName=="downstep") {GoToBottomScroll();}
		if(comName=="leftstep") {SelectButtonLeft("SWAP_BUTTON");}
		if(comName=="rightstep") {SelectButtonRight("ALLDOWN_BUTTON");}
		if(comName=="activate" || comName=="click")	{TakeItemsCollection();}
		if(comName=="deactivate")	{SetCurrentNode(oldCurScrollName);}
	break;

	case "ALLDOWN_BUTTON":
		if(comName=="upstep") {GoToTopScroll();}
		if(comName=="downstep") {GoToBottomScroll();}
		if(comName=="leftstep") {SelectButtonLeft("ALLUP_BUTTON");}
		if(comName=="activate" || comName=="click")	{GiveItemsCollection();}
		if(comName=="deactivate")	{SetCurrentNode(oldCurScrollName);}
	break;

	case "ONE_ITEMSLIST":
		if(comName=="downstep")	{SelectButtonLeft("SWAP_BUTTON");}
	break;

	case "TWO_ITEMSLIST":
		if(comName=="upstep")	{SelectButtonLeft("SWAP_BUTTON");}
	break;

	case "DESCRIBEWINDOW":
		if(comName=="downstep")
		{
			if(!bEnableDown)
			{
				SendMessage(&GameInterface,"lslll",MSG_INTERFACE_MSG_TO_NODE,"DESCRIBEWINDOW",-1, 0,ACTION_UPSTEP);
			} else {
				bEnableDown = SendMessage(&GameInterface,"lsll",MSG_INTERFACE_MSG_TO_NODE,"DESCRIBEWINDOW", 6, 0);
			}
		}
		if(comName=="upstep")
		{
			bEnableDown = SendMessage(&GameInterface,"lsll",MSG_INTERFACE_MSG_TO_NODE,"DESCRIBEWINDOW", 6, 0);
		}
	break;
	}
}

void ChangeItemsSlot()
{
	string itm1 = GetItemIDByOrder(true,nCurScroll1);
	string itm2 = GetItemIDByOrder(false,nCurScroll2);
	if(itm1=="" || itm1!=itm2)
	{
		if( !CanCharacterTakeItem(true,itm2) ) return;
	}

	int iq1 = GetItemQntByOrder(true,nCurScroll1);
	int iq2 = GetItemQntByOrder(false,nCurScroll2);

	aref mchref; makearef(mchref,Characters[GetMainCharacterIndex()]);

	if(iq1>0)
	{
		if(itm1=="Money")
		{
			mchref.Money = 0;
			g_refItems.Money = iq1+sti(g_refItems.Money);
		}
		else
		{
			TakeNItems(GetMainCharacter(),itm1,-iq1);
			if( CheckAttribute(g_refItems,"Items."+itm1) )
			{
				iq1 = iq1 + sti(g_refItems.Items.(itm1));
			}
			g_refItems.Items.(itm1) = iq1;
		}
	}
	if(iq2>0)
	{
		if(itm2=="Money")
		{
			mchref.Money = sti(mchref.Money)+iq2;
			g_refItems.Money = sti(g_refItems.Money)-iq2;
		}
		else
		{
			TakeNItems(GetMainCharacter(),itm2,iq2);
			g_refItems.Items.(itm2) = sti(g_refItems.Items.(itm2))-iq2;
			if( sti(g_refItems.Items.(itm2))<=0 ) DeleteAttribute(g_refItems,"Items."+itm2);
		}
	}

	FillScroll();
	SendMessage(&GameInterface,"lsl",MSG_INTERFACE_SCROLL_CHANGE,"ONE_ITEMSLIST",-1);
	SendMessage(&GameInterface,"lsl",MSG_INTERFACE_SCROLL_CHANGE,"TWO_ITEMSLIST",-1);
	SetUpDownUsed();
	SetScrollsUsing();
}
void TakeOneItem()
{
	string itm2 = GetItemIDByOrder(false,nCurScroll2);
	int iq2 = GetItemQntByOrder(false,nCurScroll2);
	if(iq2<=0) return;

	aref mchref; makearef(mchref,Characters[GetMainCharacterIndex()]);
	iq2--;
	if(itm2=="Money")
	{
		mchref.Money = sti(mchref.Money)+1;
		g_refItems.Money = iq2;
	}
	else
	{
		TakeNItems(GetMainCharacter(),itm2,1);
		g_refItems.Items.(itm2) = iq2;
		if( iq2<=0 ) DeleteAttribute(g_refItems,"Items."+itm2);
	}

	FillScroll();
	SendMessage(&GameInterface,"lsl",MSG_INTERFACE_SCROLL_CHANGE,"ONE_ITEMSLIST",-1);
	SendMessage(&GameInterface,"lsl",MSG_INTERFACE_SCROLL_CHANGE,"TWO_ITEMSLIST",-1);
	SetUpDownUsed();
	SetScrollsUsing();
}
void GiveOneItem()
{
	string itm1 = GetItemIDByOrder(true,nCurScroll1);
	int iq1 = GetItemQntByOrder(true,nCurScroll1);
	if(iq1<=0) return;

	aref mchref; makearef(mchref,Characters[GetMainCharacterIndex()]);
	iq1--;
	if(itm1=="Money")
	{
		mchref.Money = sti(mchref.Money)-1;
		g_refItems.Money = sti(g_refItems.Money)+1;
	}
	else
	{
		TakeNItems(GetMainCharacter(),itm1,-1);
		if( CheckAttribute(g_refItems,"Items."+itm1) )
			g_refItems.Items.(itm1) = 1 + sti(g_refItems.Items.(itm1));
		else	g_refItems.Items.(itm1) = 1;
	}

	FillScroll();
	SendMessage(&GameInterface,"lsl",MSG_INTERFACE_SCROLL_CHANGE,"ONE_ITEMSLIST",-1);
	SendMessage(&GameInterface,"lsl",MSG_INTERFACE_SCROLL_CHANGE,"TWO_ITEMSLIST",-1);
	SetUpDownUsed();
	SetScrollsUsing();
}
void TakeItemsCollection()
{
	string itm2 = GetItemIDByOrder(false,nCurScroll2);
	int iq2 = GetItemQntByOrder(false,nCurScroll2);
	if(iq2<=0) return;

	aref mchref; makearef(mchref,Characters[GetMainCharacterIndex()]);
	if(itm2=="Money")
	{
		mchref.Money = sti(mchref.Money)+iq2;
		g_refItems.Money = 0;
	}
	else
	{
		TakeNItems(GetMainCharacter(),itm2,iq2);
		DeleteAttribute(g_refItems,"Items."+itm2);
	}

	FillScroll();
	SendMessage(&GameInterface,"lsl",MSG_INTERFACE_SCROLL_CHANGE,"ONE_ITEMSLIST",-1);
	SendMessage(&GameInterface,"lsl",MSG_INTERFACE_SCROLL_CHANGE,"TWO_ITEMSLIST",-1);
	SetUpDownUsed();
	SetScrollsUsing();
}
void GiveItemsCollection()
{
	string itm1 = GetItemIDByOrder(true,nCurScroll1);
	int iq1 = GetItemQntByOrder(true,nCurScroll1);
	if(iq1<=0) return;

	aref mchref; makearef(mchref,Characters[GetMainCharacterIndex()]);
	if(itm1=="Money")
	{
		mchref.Money = 0;
		g_refItems.Money = sti(g_refItems.Money)+iq1;
	}
	else
	{
		DeleteAttribute(mchref,"Items."+itm1);
		if( CheckAttribute(g_refItems,"Items."+itm1) )
			g_refItems.Items.(itm1) = iq1 + sti(g_refItems.Items.(itm1));
		else	g_refItems.Items.(itm1) = iq1;
	}

	FillScroll();
	SendMessage(&GameInterface,"lsl",MSG_INTERFACE_SCROLL_CHANGE,"ONE_ITEMSLIST",-1);
	SendMessage(&GameInterface,"lsl",MSG_INTERFACE_SCROLL_CHANGE,"TWO_ITEMSLIST",-1);
	SetUpDownUsed();
	SetScrollsUsing();
}

void SetDescribeText()
{
	aref arItem;
	string descrStr="";
	bool bYesDescribe = false;

	if(oldCurScrollName=="ONE_ITEMSLIST") {
		bYesDescribe = GetItemRefByOrder(true,nCurScroll1,&arItem);
	}
	if(oldCurScrollName=="TWO_ITEMSLIST") {
		bYesDescribe = GetItemRefByOrder(false,nCurScroll2,&arItem);
	}

	if( !bYesDescribe ) {
		SetFormatedText("DESCRIBEWINDOW","");
		bEnableDown = false;
		return;
	}

	if( CheckAttribute(arItem,"groupID") )
	{
		if(arItem.groupID==GUN_ITEM_TYPE)
		{
			descrStr = GetAssembledString(
				LanguageConvertString(idLngFile,"weapon gun parameters"),
				arItem);
		}
		if(arItem.groupID==BLADE_ITEM_TYPE)
		{
			descrStr = GetAssembledString(
				LanguageConvertString(idLngFile,"weapon blade parameters"),
				arItem);
		}
	}
	if( CheckAttribute(arItem,"describe") )
	{
		if(descrStr!="") {
			descrStr += LanguageConvertString(idLngFile,"new_string");
		}
		descrStr += LanguageConvertString(idLngFile,arItem.describe);
	}

	SetFormatedText("DESCRIBEWINDOW",descrStr);
	bEnableDown = SendMessage(&GameInterface,"lsll",MSG_INTERFACE_MSG_TO_NODE,"DESCRIBEWINDOW", 6, 0);
}

//==============================
// items utilites
//==============================
string GetItemIDByOrder(bool my,int num)
{
	string attrName = "pic"+(num+1);
	if(my)
	{
		if( CheckAttribute(&GameInterface,"one_itemslist."+attrName+".itemID") )
			return GameInterface.one_itemslist.(attrName).itemID;
	}
	else
	{
		if( CheckAttribute(&GameInterface,"two_itemslist."+attrName+".itemID") )
			return GameInterface.two_itemslist.(attrName).itemID;
	}
	return "";
}

bool GetItemRefByOrder(bool my,int num, ref refItem)
{
	aref ar;
	string itemID = GetItemIDByOrder(my,num);
	if(itemID=="Money") itemID=GOLD;
	if( Items_FindItem(itemID,&ar)<0 ) return false;
	refItem = ar;
	return true;
}

int GetItemQntByOrder(bool my,int num)
{
	string itmName = GetItemIDByOrder(my,num);
	if(my)
	{
		if(itmName=="Money") return sti(Characters[GetMainCharacterIndex()].Money);
		return GetCharacterItem(GetMainCharacter(),itmName);
	}
	if(itmName=="Money") return sti(g_refItems.Money);
	if( CheckAttribute(g_refItems,"items."+itmName) )
		return sti(g_refItems.items.(itmName));
	return 0;
}

bool CheckConsumedItem(string itemID)
{
	aref arone;
	makearef(arone,Characters[GetMainCharacterIndex()].items);
	aref artwo;
	makearef(artwo,g_refItems.items);

	int n=0;
	if( CheckAttribute(arone,itemID) ) n = sti(arone.(itemID));
	if( CheckAttribute(artwo,itemID) ) n = n + sti(artwo.(itemID));

	if(n>1) return true;
	return false;
}

bool CanCharacterTakeItem(bool myCh,string itemName)
{
	if(!myCh) return true;
	aref chref;
	makearef(chref,Characters[GetMainCharacterIndex()]);
	if( CheckAttribute(chref,"items."+itemName) ) return true;
	if( GetChrItemQuantity(GetMainCharacter())<MAX_ITEM_TAKE ) return true;
	return false;
}

void SetUpDownUsed()
{
	aref iref; makearef(iref,Characters[GetMainCharacterIndex()].items);

	string itmName1 = GetItemIDByOrder(true,nCurScroll1);
	int iq1 = GetItemQntByOrder(true,nCurScroll1);
	string itmName2 = GetItemIDByOrder(false,nCurScroll2);
	int iq2 = GetItemQntByOrder(false,nCurScroll2);

	if(iq1<=0)
	{
		SetSelectable("ONEDOWN_BUTTON",false);
		SetSelectable("ALLDOWN_BUTTON",false);
	}
	else
	{
		SetSelectable("ONEDOWN_BUTTON",true);
		SetSelectable("ALLDOWN_BUTTON",true);
	}

	if(iq2<=0)
	{
		SetSelectable("ONEUP_BUTTON",false);
		SetSelectable("ALLUP_BUTTON",false);
	}
	else
	{
		if( CheckAttribute(iref,itmName2) || GetAttributesNum(iref)<MAX_ITEM_TAKE )
		{
			SetSelectable("ONEUP_BUTTON",true);
			SetSelectable("ALLUP_BUTTON",true);
		}
		else
		{
			SetSelectable("ONEUP_BUTTON",false);
			SetSelectable("ALLUP_BUTTON",false);
		}
	}

	if(itmName2=="" || itmName2=="Money" || GetAttributesNum(iref)<MAX_ITEM_TAKE)
	{
		SetSelectable("SWAP_BUTTON",true);
	}
	else
	{
		if( CheckAttribute(iref,itmName2) )	SetSelectable("SWAP_BUTTON",true);
		else
		{
			if(itmName1!="" && itmName1!="Money") SetSelectable("SWAP_BUTTON",true);
			else SetSelectable("SWAP_BUTTON",false);
		}
	}

	if( IsQuestUsedItem(itmName1) )
	{
		SetSelectable("SWAP_BUTTON",false);
		SetSelectable("ONEDOWN_BUTTON",false);
		SetSelectable("ALLDOWN_BUTTON",false);
	}

	ThatOneAndEquiped(itmName1,itmName2);

	if(!GetSelectable(GetCurrentNode()))	SetCurrentNode(oldCurScrollName);
}

void SelectButtonLeft(string startBtnNode)
{
	if(GetSelectable(startBtnNode))	SetCurrentNode(startBtnNode);
	else
	{
		switch(startBtnNode)
		{
		case "ONEDOWN_BUTTON":	SelectButtonLeft("INFO_BUTTON"); break;
		case "ONEUP_BUTTON":	SelectButtonLeft("ONEDOWN_BUTTON"); break;
		case "SWAP_BUTTON":		SelectButtonLeft("ONEUP_BUTTON"); break;
		case "ALLUP_BUTTON":	SelectButtonLeft("SWAP_BUTTON"); break;
		case "ALLDOWN_BUTTON":	SelectButtonLeft("ALLUP_BUTTON"); break;
		}
	}
}

void SelectButtonRight(string startBtnNode)
{
	if(GetSelectable(startBtnNode))	SetCurrentNode(startBtnNode);
	else
	{
		switch(startBtnNode)
		{
		case "INFO_BUTTON":		SelectButtonRight("ONEDOWN_BUTTON"); break;
		case "ONEDOWN_BUTTON":	SelectButtonRight("ONEUP_BUTTON"); break;
		case "ONEUP_BUTTON":	SelectButtonRight("SWAP_BUTTON"); break;
		case "SWAP_BUTTON":		SelectButtonRight("ALLUP_BUTTON"); break;
		case "ALLUP_BUTTON":	SelectButtonRight("ALLDOWN_BUTTON"); break;
		}
	}
}

void ThatOneAndEquiped(string itmName1, string itmName2)
{
	if( !GetRemovable(g_refItems) )
	{
		SetSelectable("ONEDOWN_BUTTON",false);
		SetSelectable("ALLDOWN_BUTTON",false);
		SetSelectable("SWAP_BUTTON",false);
		SetSelectable("ONEUP_BUTTON",false);
		SetSelectable("ALLUP_BUTTON",false);
		return;
	}

	if( IsEquipCharacterByItem(GetMainCharacter(),itmName1) )
	{
		if( GetCharacterItem(GetMainCharacter(),itmName1)<=1 )
		{
			SetSelectable("ONEDOWN_BUTTON",false);
		}
		SetSelectable("ALLDOWN_BUTTON",false);
		SetSelectable("SWAP_BUTTON",false);
	}

	if( IsEquipCharacterByItem(g_refItems,itmName2) )
	{
		if( GetCharacterItem(g_refItems,itmName2)<=1 )
		{
			SetSelectable("ONEUP_BUTTON",false);
		}
		SetSelectable("ALLUP_BUTTON",false);
		SetSelectable("SWAP_BUTTON",false);
	}
}

void SetScrollsUsing()
{
	if( CheckAttribute(&GameInterface,"two_itemslist.pic1") ) {
		SendMessage(&GameInterface,"lsll", MSG_INTERFACE_MSG_TO_NODE,"TWO_ITEMSLIST",0, true);
		SetSelectable("TWO_ITEMSLIST",true);
		SetSelectable("TWO_LEFTSCROLLBUTTON",true);
		SetSelectable("TWO_RIGHTSCROLLBUTTON",true);
	} else {
		SendMessage(&GameInterface,"lsll", MSG_INTERFACE_MSG_TO_NODE,"TWO_ITEMSLIST",0, false);
		SetSelectable("TWO_ITEMSLIST",false);
		SetSelectable("TWO_LEFTSCROLLBUTTON",false);
		SetSelectable("TWO_RIGHTSCROLLBUTTON",false);
		if( GetCurrentNode()=="TWO_ITEMSLIST" ) {
			SetCurrentNode("ONE_ITEMSLIST");
		}
	}

	if( CheckAttribute(&GameInterface,"one_itemslist.pic1") ) {
		SendMessage(&GameInterface,"lsll", MSG_INTERFACE_MSG_TO_NODE,"ONE_ITEMSLIST",0, true);
		SetSelectable("ONE_ITEMSLIST",true);
		SetSelectable("ONE_LEFTSCROLLBUTTON",true);
		SetSelectable("ONE_RIGHTSCROLLBUTTON",true);
	} else {
		SendMessage(&GameInterface,"lsll", MSG_INTERFACE_MSG_TO_NODE,"ONE_ITEMSLIST",0, false);
		SetSelectable("ONE_ITEMSLIST",false);
		SetSelectable("ONE_LEFTSCROLLBUTTON",false);
		SetSelectable("ONE_RIGHTSCROLLBUTTON",false);
		if( GetCurrentNode()=="ONE_ITEMSLIST" ) {
			if( GetSelectable("TWO_ITEMSLIST") ) {SetCurrentNode("TWO_ITEMSLIST");}
		}
	}
}

void GoToTopScroll()
{
	if( GetSelectable("ONE_ITEMSLIST") ) SetCurrentNode("ONE_ITEMSLIST");
}

void GoToBottomScroll()
{
	if( GetSelectable("TWO_ITEMSLIST") ) SetCurrentNode("TWO_ITEMSLIST");
}

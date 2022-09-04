int nCurScroll;

int lngFileID;

object objNewItemsEquip;

void InitInterface(string iniName)
{
	GameInterface.title = "titleItems";

	lngFileID = LanguageOpenFile("ItemsDescribe.txt");

	nCurScroll=-1;
	SetUsedItems();
	FillScroll();
	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);

	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
	SetEventHandler("frame","FrameProcess",1);
	SetEventHandler("exitCancel","ProcessCancelExit",0);
	SetEventHandler("EquipPress","ProcEquipPress",0);
	SetEventHandler("ievnt_command","ProcessCommandExecute",0);

	FrameProcess();
}

void FrameProcess()
{
	if(nCurScroll!=sti(GameInterface.itemslist.current))
	{
		nCurScroll = sti(GameInterface.itemslist.current);
		UpdateItemData();
	}
}

void ProcessCommandExecute()
{
	string comName = GetEventData();
	string nodName = GetEventData();

	switch(nodName)
	{
	case "EQUIP_BUTTON":
		if(comName=="activate" || comName=="click")
		{
			I_EquipItem();
		}
		if(comName=="upstep" || comName=="deactivate")
		{
			SetCurrentNode("ITEMSLIST");
		}
	break;
	case "ITEMSLIST":
		if(comName=="activate")
		{
			if(GetSelectable("EQUIP_BUTTON"))
			{
				SetCurrentNode("EQUIP_BUTTON");
			}
		}
		if(comName=="upstep")
		{
			if( SendMessage(&GameInterface,"lsll",MSG_INTERFACE_MSG_TO_NODE,"TEXTWINDOW",6, true) )
			{	SendMessage(&GameInterface,"lslls",MSG_INTERFACE_MSG_TO_NODE,"TEXTWINDOW",-1,3, comName);
			}
		}
		if(comName=="downstep")
		{
			if( SendMessage(&GameInterface,"lsll",MSG_INTERFACE_MSG_TO_NODE,"TEXTWINDOW",6, false) )
			{	SendMessage(&GameInterface,"lslls",MSG_INTERFACE_MSG_TO_NODE,"TEXTWINDOW", -1,3, comName);
			}
		}
	break;
	}
}

void I_EquipItem()
{
	ProcEquipPress();
	DeleteAttribute(&GameInterface,"itemslist");
	FillScroll();
	SendMessage(&GameInterface,"lsl",MSG_INTERFACE_SCROLL_CHANGE,"ITEMSLIST",-1);
	SetCurrentNode("ITEMSLIST");
}

void UpdateItemData()
{
	SetSelectable("EQUIP_BUTTON",false);
	SendMessage(&GameInterface,"lsl",MSG_INTERFACE_MSG_TO_NODE,"CONTEXTHELP",0);

	string attributeName = "pic" + (nCurScroll+1);
	if( !CheckAttribute(&GameInterface,"itemslist."+attributeName+".itemID") )
	{
		SetFormatedText("TEXTWINDOW","");
		return;
	}

	aref itemARef;
	if( Items_FindItem(GameInterface.itemslist.(attributeName).itemID,&itemARef)<0 )
	{
		SetFormatedText("TEXTWINDOW","");
		return;
	}

	string newLineStr = LanguageConvertString(lngFileID,"new_string");
	string itmDescribe = "";
	string strTmp;
	if( CheckAttribute(itemARef,"describe") )
	{	itmDescribe = LanguageConvertString(lngFileID,itemARef.name) + newLineStr;
	}
	if( CheckAttribute(itemARef,"groupID") )
	{
		switch(itemARef.groupID)
		{
		case GUN_ITEM_TYPE:
			itmDescribe += GetAssembledString(
				LanguageConvertString(lngFileID,"weapon gun parameters"),
				itemARef) + newLineStr;
		break;
		case BLADE_ITEM_TYPE:
			string ttttstr = LanguageConvertString(lngFileID,"weapon blade parameters");
			itmDescribe += GetAssembledString( ttttstr,	itemARef) + newLineStr;
		break;
		}
	}
	else
	{	if( CheckAttribute(itemARef,"potion") )
		{
			itmDescribe += LanguageConvertString(lngFileID,"Potion parameters")+":";
			if( CheckAttribute(itemARef,"potion.health") )
			{
				itmDescribe += " "+LanguageConvertString(lngFileID,"health value");
				if(stf(itemARef.potion.health)>=0)
				{	itmDescribe += "+" + sti(itemARef.potion.health) + ".";
				} else
				{	itmDescribe += sti(itemARef.potion.health) + ".";
				}
			}
			itmDescribe += newLineStr;
		}
	}
	itmDescribe += newLineStr;
	if( CheckAttribute(itemARef,"describe") )	itmDescribe = itmDescribe + LanguageConvertString(lngFileID,itemARef.describe);
	SetFormatedText("TEXTWINDOW",itmDescribe);

	if( CheckAttribute(itemARef,"groupID") )
	{
		SetSelectable("EQUIP_BUTTON",ThisItemCanBeEquip(itemARef));

		if(IsEquipedItem(itemARef.id))
		{
			SendMessage(&GameInterface,"lsls",MSG_INTERFACE_MSG_TO_NODE,"EQUIP_BUTTON",0, XI_ConvertString("Release that"));
			if(itemARef.groupID==BLADE_ITEM_TYPE || itemARef.groupID==SPYGLASS_ITEM_TYPE)
			{
				SetSelectable("EQUIP_BUTTON",false);
			}
		}
		else
		{
			SendMessage(&GameInterface,"lsls",MSG_INTERFACE_MSG_TO_NODE,"EQUIP_BUTTON",0, XI_ConvertString("Equip that"));
		}
	}
}

void FillScroll()
{
    int i,j;
    string attributeName;

	if(nCurScroll<0)	nCurScroll = 0;
	GameInterface.itemslist.current = nCurScroll;
	nCurScroll = -1;
	GameInterface.itemslist.ImagesGroup.t0 = "usedflag";
	GameInterface.itemslist.ImagesGroup.t1 = "ICONS";
	aref arImgGrp;
	makearef(arImgGrp,GameInterface.itemslist.ImagesGroup);
	FillImagesGroupForItems(arImgGrp);
	GameInterface.itemslist.NotUsed = 5;

	GameInterface.itemslist.BadTex1 = GetItemPictureTexture("itemslist.ImagesGroup","");
	GameInterface.itemslist.BadPic1 = GetItemPictureName("");

	aref curItem,arItem;
	aref rootItems; makearef(rootItems,Characters[GetMainCharacterIndex()].Items);
    for(i=0; i<GetAttributesNum(rootItems); i++)
    {
		attributeName = "pic" + (i+1);
		curItem = GetAttributeN(rootItems,i);
		j = sti(GetAttributeValue(curItem));

		if( Items_FindItem(GetAttributeName(curItem),&arItem) >= 0 )
		{
			GameInterface.itemslist.(attributeName).img1 = GetItemPictureName(arItem.id);
			GameInterface.itemslist.(attributeName).tex1 = GetItemPictureTexture("itemslist.ImagesGroup",arItem.id);
			if(j>1)	GameInterface.itemslist.(attributeName).str1 = "#"+j;
			GameInterface.itemslist.(attributeName).itemID = arItem.id;
			if(IsEquipedItem(arItem.id))
			{
				GameInterface.itemslist.(attributeName).img2 = "usedflag";
				GameInterface.itemslist.(attributeName).tex2 = 0;
			}
		}
		else
		{
			GameInterface.itemslist.(attributeName).img1 = GameInterface.itemslist.BadPic1;
			GameInterface.itemslist.(attributeName).tex1 = GameInterface.itemslist.BadTex1;
		}
    }
	GameInterface.itemslist.ListSize = i;
	DumpAttributes(&GameInterface);
}

void ProcessCancelExit()
{
	IDoExit(RC_INTERFACE_ITEMS_EXIT);
}

void IDoExit(int exitCode)
{
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
	DelEventHandler("frame","FrameProcess");
	DelEventHandler("exitCancel","ProcessCancelExit");
	DelEventHandler("EquipPress","ProcEquipPress");
	DelEventHandler("ievnt_command","ProcessCommandExecute");

	LanguageCloseFile(lngFileID);

	RefreshUsedItems();
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

void ProcEquipPress()
{
	ref chref = GetMainCharacter();
	string itmName = GetItemIDByOrder(nCurScroll);
	aref itmRef;
	if( Items_FindItem(itmName,&itmRef)>=0 && CheckAttribute(itmRef,"groupID") )
	{
		string itmGroup = itmRef.groupID;
		if( IsEquipedItem(itmName) )
		{
			objNewItemsEquip.(itmGroup) = "";
		}
		else
		{
			objNewItemsEquip.(itmGroup) = itmName;
		}
	}
}

string GetItemIDByOrder(int num)
{
	string attrName = "pic"+(num+1);
	if( CheckAttribute(&GameInterface,"itemslist."+attrName+".itemID") )
		return GameInterface.itemslist.(attrName).itemID;
	return "";
}

void SetUsedItems()
{
	ref mchref = GetMainCharacter();
	DeleteAttribute(&objNewItemsEquip,"");
	aref arEquip;
	makearef(arEquip,mchref.equip);
	CopyAttributes(&objNewItemsEquip,arEquip);
}

bool IsEquipedItem(string itemID)
{
	int q = GetAttributesNum(&objNewItemsEquip);

	aref arEquip;
	for(int i=0; i<q; i++)
	{
		arEquip = GetAttributeN(&objNewItemsEquip,i);
		if( GetAttributeValue(arEquip)==itemID ) return true;
	}

	return false;
}

void RefreshUsedItems()
{
	ref mchref = GetMainCharacter();
	aref arItm;

	string sItemName;
	string sGroupName;
	aref arEquip;
	int q = GetAttributesNum(&objNewItemsEquip);

	for(int i=0; i<q; i++)
	{
		arEquip = GetAttributeN(&objNewItemsEquip,i);
		sGroupName = GetAttributeName(arEquip);
		sItemName = GetAttributeValue(arEquip);
		if(sItemName=="")
		{	RemoveCharacterEquip(mchref,sGroupName);
		}
		else
		{	EquipCharacterByItem(mchref,sItemName);
		}
	}
}

bool ThisItemCanBeEquip( aref arItem )
{
	if( !CheckAttribute(arItem,"groupID") )
	{
		trace("WARNING!!! item "+arItem.id+" hav`t attr. groupID");
		return false;
	}
	if( !IsCanEquiping(GetMainCharacter(),arItem.groupID) )
	{
		ShowHelpString("chelp_items#10");
		return false;
	}
	if(arItem.groupID!=GUN_ITEM_TYPE) return true;

	if( !CheckAttribute(arItem,"chargeQ") )
	{
		trace("WARNING!!! item "+arItem.id+" hav`t attr. chargeQ");
		return false;
	}
	int chrgQ = sti(arItem.chargeQ);

	if(chrgQ<2) return true;
	if( !IsCharacterPerkOn(GetMainCharacter(),"Gunman") )
	{
		ShowHelpString("chelp_items#11");
		return false;
	}

	if(chrgQ<4) return true;
	if( !IsCharacterPerkOn(GetMainCharacter(),"GunProfessional") )
	{
		ShowHelpString("chelp_items#11");
		return false;
	}

	return true;
}

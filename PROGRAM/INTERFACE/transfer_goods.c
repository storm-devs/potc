ref refMyCharacter;
ref refEnemyCharacter;

int curNum;

void InitInterface_RR(string iniName,ref myCh,ref enemyCh)
{
	refMyCharacter = myCh;
	refEnemyCharacter = enemyCh;
    GameInterface.title = "titleTransferGoods";

	FillScroll();
    SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);
    SetVariable();

	ref shipRef = GetShipByType(sti(refMyCharacter.ship.Type));
	CreateImage("myShip",GetShipTextureName(shipRef.name),shipRef.name,40,240,168,368);
    CreateString(TRUE,"MyShipType",XI_ConvertString(shipRef.Name),FONT_NORMAL,COLOR_NORMAL,104,342,SCRIPT_ALIGN_CENTER,1.0);

	shipRef = GetShipByType(sti(refEnemyCharacter.ship.Type));
	CreateImage("enemyShip",GetShipTextureName(shipRef.name),shipRef.name,472,240,600,368);
    CreateString(TRUE,"EnemyShipType",XI_ConvertString(shipRef.Name),FONT_NORMAL,COLOR_NORMAL,536,342,SCRIPT_ALIGN_CENTER,1.0);

    CreateString(TRUE,"MyShipName",refMyCharacter.ship.Name,FONT_NORMAL,COLOR_NORMAL,177,198,SCRIPT_ALIGN_CENTER,1.0);
    CreateString(TRUE,"EnemyShipName",refEnemyCharacter.ship.Name,FONT_NORMAL,COLOR_NORMAL,463,198,SCRIPT_ALIGN_CENTER,1.0);

    CreateString(TRUE,"GoodsName","",FONT_NORMAL,COLOR_NORMAL,320,234,SCRIPT_ALIGN_CENTER,1.0);
    CreateString(TRUE,"MyCargo","",FONT_NORMAL,COLOR_NORMAL,104,372,SCRIPT_ALIGN_CENTER,1.0);
    CreateString(TRUE,"EnemyCargo","",FONT_NORMAL,COLOR_NORMAL,536,372,SCRIPT_ALIGN_CENTER,1.0);
    CreateString(TRUE,"MyGoods","",FONT_BOLD_NUMBERS,COLOR_NORMAL,280,272,SCRIPT_ALIGN_RIGHT,1.0);
    CreateString(TRUE,"EnemyGoods","",FONT_BOLD_NUMBERS,COLOR_NORMAL,360,272,SCRIPT_ALIGN_LEFT,1.0);

	WasGoodsChange();
	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
    SetEventHandler("InterfaceCancel","ProcessCancelExit",0);
	SetEventHandler("TakeAllPress","TakeAllProcess",0);
	SetEventHandler("frame","WasGoodsChange",0);
	SetEventHandler("ChangerLeft","DoChangeLeft",0);
	SetEventHandler("ChangerRight","DoChangeRight",0);
	SetEventHandler("IEvnt_MouseClick","IProcMouseClick",0);
	SetEventHandler("ievnt_command","ProcessCommandExecute",0);

	if(!GetRemovable(enemyCh))
	{
		SetSelectable("GOODS_CHANGER",false);
		SetSelectable("TAKEALL_BUTTON",false);
	}
}

void DoChangeLeft()
{
	if( !GetSelectable("TAKEALL_BUTTON") )
	{	return;
	}

	int goodsIdx = GetGoodsIndexForI(curNum);
	int changeQ = sti(Goods[goodsIdx].Units);
	for(int i=0; i<changeQ; i++)
	{
		if(GetCargoGoods(refEnemyCharacter,goodsIdx)<=0) break;
		if( !CoreGoodAdding(refMyCharacter,goodsIdx,1) ) break;
		RemoveCharacterGoods(refEnemyCharacter,goodsIdx,1);
	}
	if(i>0)
	{
		curNum = -1;
		WasGoodsChange();
	}
}

void DoChangeRight()
{
	int goodsIdx = GetGoodsIndexForI(curNum);
	int changeQ = sti(Goods[goodsIdx].Units);
	for(int i=0; i<changeQ; i++)
	{
		if(GetCargoGoods(refMyCharacter,goodsIdx)<=0) break;
		if( !CoreGoodAdding(refEnemyCharacter,goodsIdx,1) ) break;
		RemoveCharacterGoods(refMyCharacter,goodsIdx,1);
	}
	if(i>0)
	{
		curNum = -1;
		WasGoodsChange();
	}
}

void SetVariable()
{
	curNum=-1;
	GameInterface.goodslist.current = 0;
}

void WasGoodsChange()
{
	if(curNum != sti(GameInterface.goodslist.current))
	{
		curNum = sti(GameInterface.goodslist.current);
		GameInterface.strings.MyCargo = GetCargoLoad(refMyCharacter) + "/" + GetCargoMaxSpace(refMyCharacter);
		GameInterface.strings.EnemyCargo = GetCargoLoad(refEnemyCharacter) + "/" + GetCargoMaxSpace(refEnemyCharacter);
		GameInterface.strings.GoodsName = XI_ConvertString(Goods[GetGoodsIndexForI(curNum)].Name);
		GameInterface.strings.MyGoods = GetCargoGoods(refMyCharacter,GetGoodsIndexForI(curNum));
		GameInterface.strings.EnemyGoods = GetCargoGoods(refEnemyCharacter,GetGoodsIndexForI(curNum));
	}
}

void ProcessCancelExit()
{
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
    DelEventHandler("InterfaceCancel","ProcessCancelExit");
	DelEventHandler("TakeAllPress","TakeAllProcess");
	DelEventHandler("frame","WasGoodsChange");
	DelEventHandler("ChangerLeft","DoChangeLeft");
	DelEventHandler("ChangerRight","DoChangeRight");
	DelEventHandler("IEvnt_MouseClick","IProcMouseClick");
	DelEventHandler("ievnt_command","ProcessCommandExecute");

	interfaceResultCommand = RC_INTERFACE_TRANSFER_MAIN_RETURN;
	EndCancelInterface(true);
}

void TakeAllProcess()
{
	int i;
	int itmp;
	int freeSpace;
	int freeQuantity;

	for(i=0;i<GOODS_QUANTITY;i++)
	{
		freeSpace = GetCargoFreeSpace(refMyCharacter);
		freeQuantity = GetGoodQuantityByWeight(i,freeSpace);
		itmp = GetCargoGoods(refEnemyCharacter,i);
		if(itmp<=freeQuantity)
		{
			AddCharacterGoods(refMyCharacter,i,itmp);
			RemoveCharacterGoods(refEnemyCharacter,i,itmp);
		}
		else
		{
			AddCharacterGoods(refMyCharacter,i,freeQuantity);
			RemoveCharacterGoods(refEnemyCharacter,i,freeQuantity);
		}
	}
	ProcessCancelExit();
}

ref GetMyCharacterRef()
{
	return refMyCharacter;
}

ref GetEnemyCharacterRef()
{
	return refEnemyCharacter;
}

void FillScroll()
{
	int i;
	string attributeName;
    aref pRef;
    string goodsName;

    GameInterface.goodslist.current = 0;
	GameInterface.goodslist.ListSize = GOODS_QUANTITY;
	GameInterface.goodslist.ImagesGroup.t1 = "ICONS";
	GameInterface.goodslist.ImagesGroup.t2 = "GOODS";
	GameInterface.goodslist.SpecTechniqueColor = argb(55,255,255,255);
	GameInterface.goodslist.SpecTechniqueName = "iSpec1";
	// fill visible goods
	int idx = 1;
	for(i=0; i<GOODS_QUANTITY; i++)
	{
		if(GetCargoGoods(refMyCharacter,i)==0 && GetCargoGoods(refEnemyCharacter,i)==0) continue;
		attributeName = "pic" + idx;
		GameInterface.goodslist.(attributeName).str2 = "#" + GetShowGoodsName(Goods[i].Name);
		GameInterface.goodslist.(attributeName).spec2 = false;
		GameInterface.goodslist.(attributeName).img1 = "cannon back";
		GameInterface.goodslist.(attributeName).img2 = Goods[i].Name;
		GameInterface.goodslist.(attributeName).goodsNum = i;
		GameInterface.goodslist.(attributeName).tex1 = 0;
		GameInterface.goodslist.(attributeName).tex2 = 1;
		idx++;
	}
	// fill invisible goods
	for(i=0; i<GOODS_QUANTITY; i++)
	{
		if(GetCargoGoods(refMyCharacter,i)!=0 || GetCargoGoods(refEnemyCharacter,i)!=0) continue;
		attributeName = "pic" + idx;
		GameInterface.goodslist.(attributeName).str2 = "";
		GameInterface.goodslist.(attributeName).spec2 = true;
		GameInterface.goodslist.(attributeName).img1 = "cannon back";
		GameInterface.goodslist.(attributeName).img2 = Goods[i].Name;
		GameInterface.goodslist.(attributeName).goodsNum = i;
		GameInterface.goodslist.(attributeName).tex1 = 0;
		GameInterface.goodslist.(attributeName).tex2 = 1;
		idx++;
	}
}

int CoreGoodAdding(ref charRef, int goodType, int goodQuantity)
{
	int oldGood = GetCargoGoods(charRef,goodType);
	int newGoodWeight = GetGoodWeightByType(goodType,oldGood+goodQuantity);
	int oldGoodWeight = GetGoodWeightByType(goodType,oldGood);
	int freeSpace = GetCargoFreeSpace(charRef);
	if( freeSpace > (newGoodWeight-oldGoodWeight) )
	{
		SetCharacterGoods(charRef, goodType, oldGood+goodQuantity);
		return true;
	}
	return false;
}

int GetGoodsIndexForI(int n)
{
	if(n<0) return 0;
	string attrName = "pic"+(n+1);
	return sti(GameInterface.goodslist.(attrName).goodsNum);
}

void IProcMouseClick()
{
	string nodName = GetEventData();
	int btnCode = GetEventData();

	if(nodName=="GOODS_CHANGER")
	{
		if(btnCode==0) DoChangeLeft();
		if(btnCode==1) DoChangeRight();
	}
}

void ProcessCommandExecute()
{
	string comName = GetEventData();
	string nodName = GetEventData();

	switch(nodName)
	{
	case "GOODSLIST":
		if(comName=="activate" || comName=="downstep")
		{	if( GetSelectable("GOODS_CHANGER") )
			{	SetCurrentNode("GOODS_CHANGER");
			}
		}
	break;
	case "GOODS_CHANGER":
		if(comName=="downstep")
		{	if( GetSelectable("TAKEALL_BUTTON") )
			{	SetCurrentNode("TAKEALL_BUTTON");
			}
		}
	break;
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

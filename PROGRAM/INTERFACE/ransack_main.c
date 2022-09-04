ref refMyCharacter;
ref refEnemyCharacter;

void InitInterface_RRS(string iniName,ref myCh,ref enemyCh,string newCurNod)
{
	int i;
	refMyCharacter = myCh;
	refEnemyCharacter = enemyCh;
    GameInterface.title = "titleRansack";

    SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);

	if(newCurNod!="")
	{
		SetCurrentNode(newCurNod);
	}
	else
	{
		RecalculateCargoLoad( refMyCharacter );
		RecalculateCargoLoad( refEnemyCharacter );
		DeleteAttribute(myCh,"InterfaceParam");
		for(i=1;i<4;i++)
		{
			if(GetCompanionIndex(myCh,i)==-1)
			{
				myCh.InterfaceParam.i1 = i;
				break;
			}
		}
	}

	int picCharIndex = -1;
	if(!CheckAttribute(myCh,"InterfaceParam.i1"))
	{
		SetSelectable("CHARACTERS_BUTTON",false);
	}
	else
	{
		picCharIndex = GetCompanionIndex(refMyCharacter,sti(myCh.InterfaceParam.i1));
	}
	if(picCharIndex<0)
	{
		picCharIndex = sti(refEnemyCharacter.index);
		if(GetNotCaptivePassenger(refMyCharacter,0)<0)
			SetSelectable("CHARACTERS_BUTTON",false);
	}

	ref shipRef = GetShipByType(sti(refMyCharacter.ship.Type));
	CreateImage("myShip",GetShipTextureName(shipRef.name),shipRef.name,32,39,160,167);
    CreateImage("myFace",GetFaceGroupName(sti(refMyCharacter.index)),GetFacePictureName(sti(refMyCharacter.index)),164,39,292,167);
    CreateString(TRUE,"MyShipType",XI_ConvertString(shipRef.Name),FONT_NORMAL,COLOR_NORMAL,96,140,SCRIPT_ALIGN_CENTER,1.0);
    CreateString(TRUE,"MyShipName",refMyCharacter.ship.Name,FONT_NORMAL,COLOR_NORMAL,177,198,SCRIPT_ALIGN_CENTER,1.0);

	CreateString(TRUE,"MyMaxHull",shipRef.HP,FONT_NORMAL,COLOR_NORMAL,100,232,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(TRUE,"MyHull","",FONT_NORMAL,COLOR_NORMAL,100,270,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(TRUE,"MyRig","",FONT_NORMAL,COLOR_NORMAL,100,308,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(TRUE,"MyCrew","",FONT_NORMAL,COLOR_NORMAL,100,346,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(TRUE,"MyCannons","",FONT_NORMAL,COLOR_NORMAL,100,384,SCRIPT_ALIGN_LEFT,1.0);

	shipRef = GetShipByType(sti(refEnemyCharacter.ship.Type));
	CreateImage("enemyShip",GetShipTextureName(shipRef.name),shipRef.name,480,39,608,167);
	CreateImage("enemyFace",GetFaceGroupName(picCharIndex),GetFacePictureName(picCharIndex),348,39,476,167);
    CreateString(TRUE,"EnemyShipType",XI_ConvertString(shipRef.Name),FONT_NORMAL,COLOR_NORMAL,544,140,SCRIPT_ALIGN_CENTER,1.0);
    CreateString(TRUE,"EnemyShipName",refEnemyCharacter.ship.Name,FONT_NORMAL,COLOR_NORMAL,463,198,SCRIPT_ALIGN_CENTER,1.0);

	CreateString(TRUE,"EnemyMaxHull",shipRef.HP,FONT_NORMAL,COLOR_NORMAL,540,232,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(TRUE,"EnemyHull","",FONT_NORMAL,COLOR_NORMAL,540,270,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(TRUE,"EnemyRig","",FONT_NORMAL,COLOR_NORMAL,540,308,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(TRUE,"EnemyCrew","",FONT_NORMAL,COLOR_NORMAL,540,346,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(TRUE,"EnemyCannons","",FONT_NORMAL,COLOR_NORMAL,540,384,SCRIPT_ALIGN_RIGHT,1.0);

	WasChangeData();

	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
    SetEventHandler("exitCancel","ProcessCancelExit",0);
	SetEventHandler("GoodsPress","GoodsProcess",0);
	SetEventHandler("CharactersPress","CharactersProcess",0);
	SetEventHandler("CrewPress","CrewProcess",0);
	SetEventHandler("SwapPress","SwapProcess",0);
	SetEventHandler("UpPress","UpProcess",0);
	SetEventHandler("DownPress","DownProcess",0);

	if( !GetShipRemovable(refMyCharacter) || !GetShipRemovable(refEnemyCharacter) ) {
		SetSelectable("SWAP_BUTTON",false);
	}

	SetCurrentNode("GOODS_BUTTON");
}

void WasChangeData()
{
	ref shipRef = GetShipByType(sti(refMyCharacter.ship.Type));
	GameInterface.pictures.myShip.tex = GetShipTextureName(shipRef.name);
	GameInterface.pictures.myShip.pic = shipRef.name;
	GameInterface.strings.MyShipType = XI_ConvertString(shipRef.name);
	GameInterface.strings.MyShipName = refMyCharacter.ship.Name;
	GameInterface.strings.MyMaxHull = shipRef.HP;
	GameInterface.strings.MyHull = MakeInt(refMyCharacter.ship.HP);
	GameInterface.strings.MyRig = MakeInt(refMyCharacter.ship.SP);
	GameInterface.strings.MyCrew = MakeInt(refMyCharacter.ship.Crew.Quantity)+"/"+shipRef.MaxCrew;
	GameInterface.strings.MyCannons = shipRef.CannonsQuantity;

	shipRef = GetShipByType(sti(refEnemyCharacter.ship.Type));
	GameInterface.pictures.enemyShip.tex = GetShipTextureName(shipRef.name);
	GameInterface.pictures.enemyShip.pic = shipRef.name;
	GameInterface.strings.EnemyShipType = XI_ConvertString(shipRef.name);
	GameInterface.strings.EnemyShipName = refEnemyCharacter.ship.Name;
	GameInterface.strings.EnemyMaxHull = shipRef.HP;
	GameInterface.strings.EnemyHull = MakeInt(refEnemyCharacter.ship.HP);
	GameInterface.strings.EnemyRig = MakeInt(refEnemyCharacter.ship.SP);
	GameInterface.strings.EnemyCrew = makeint(refEnemyCharacter.ship.Crew.Quantity)+"/"+shipRef.MaxCrew;
	GameInterface.strings.EnemyCannons = shipRef.CannonsQuantity;
}

void ProcessCancelExit()
{
	int n = -1;
	if(CheckAttribute(refMyCharacter,"InterfaceParam.i1"))
	{
		n = GetCompanionIndex(refMyCharacter,sti(refMyCharacter.InterfaceParam.i1));
		DeleteAttribute(refMyCharacter,"InterfaceParam");
	}
	if(n<0)
	{
		ShipDead(sti(refEnemyCharacter.index),KILL_BY_ABORDAGE,sti(refMyCharacter.index));
	}
	else
	{
		ISetShipAttributes(GetCharacter(n));
		SeaAI_SetOfficer2ShipAfterAbordage(GetCharacter(n),refEnemyCharacter);
		LAi_SetCurHP(refEnemyCharacter, 0.0);
		refEnemyCharacter.Killer.Status = KILL_BY_ABORDAGE;
		refEnemyCharacter.Killer.Index = GetMainCharacterIndex();
		PostEvent("evntQuestsCheck",1);
	}

	interfaceResultCommand = RC_INTERFACE_RANSACK_MAIN_EXIT;
	Exit();

	RefreshBattleInterface();
	if( CheckAttribute(&PeopleOnShip,"IsOnDeck") && sti(PeopleOnShip.IsOnDeck) )
	{
		PeopleOnShip.IsOnDeck = true;
	}
}

void Exit()
{
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
    DelEventHandler("exitCancel","ProcessCancelExit");
	DelEventHandler("GoodsPress","GoodsProcess");
	DelEventHandler("CharactersPress","CharactersProcess");
	DelEventHandler("CrewPress","CrewProcess");
	DelEventHandler("SwapPress","SwapProcess");
	DelEventHandler("UpPress","UpProcess");
	DelEventHandler("DownPress","DownProcess");

	EndCancelInterface(true);
}

void GoodsProcess()
{
	interfaceResultCommand = RC_INTERFACE_TRANSFER_START_GOODS;
	Exit();
}

void CharactersProcess()
{
	interfaceResultCommand = RC_INTERFACE_TRANSFER_START_CHARACTERS;
	Exit();
}

void CrewProcess()
{
	interfaceResultCommand = RC_INTERFACE_TRANSFER_START_CREW;
	Exit();
}

void SwapProcess()
{
	//string tmp;

	SeaAI_SwapShipsAttributes(refMyCharacter, refEnemyCharacter);
	SeaAI_SwapShipAfterAbordage(refMyCharacter, refEnemyCharacter);
	ReturnMyCrew(refMyCharacter, refEnemyCharacter);

	if(CheckAttribute(refMyCharacter,"InterfaceParam.i1"))
	{
		int cn = GetCompanionIndex(refMyCharacter,sti(refMyCharacter.InterfaceParam.i1));
		if(cn>=0 && cn!=sti(refEnemyCharacter.index))
		{
			ISetShipAttributes(GetCharacter(cn));
		}
	}

	WasChangeData();
}

void UpProcess()
{
	string tmp = NextUp(GetCurrentNode());
	SetCurrentNode(tmp);
}

void DownProcess()
{
	string tmp = NextDown(GetCurrentNode());
	SetCurrentNode(tmp);
}

string NextUp(string curNod)
{
	switch(curNod)
	{
	case "CHARACTERS_BUTTON":
		if(GetSelectable("GOODS_BUTTON")==true)	return "GOODS_BUTTON";
		else return NextUp("GOODS_BUTTON");
		break;
	case "CREW_BUTTON":
		if(GetSelectable("CHARACTERS_BUTTON")==true) return "CHARACTERS_BUTTON";
		else return NextUp("CHARACTERS_BUTTON");
		break;
	case "SWAP_BUTTON":
		if(GetSelectable("CREW_BUTTON")==true) return "CREW_BUTTON";
		else return NextUp("CREW_BUTTON");
		break;
	}
	return " ";
}

string NextDown(string curNod)
{
	switch(curNod)
	{
	case "GOODS_BUTTON":
		if(GetSelectable("CHARACTERS_BUTTON")==true) return "CHARACTERS_BUTTON";
		else return NextDown("CHARACTERS_BUTTON");
		break;
	case "CHARACTERS_BUTTON":
		if(GetSelectable("CREW_BUTTON")==true) return "CREW_BUTTON";
		else return NextDown("CREW_BUTTON");
		break;
	case "CREW_BUTTON":
		if(GetSelectable("SWAP_BUTTON")==true) return "SWAP_BUTTON";
		else return "SWAP_BUTTON";
		break;
	}
	return " ";
}

ref GetMyCharacterRef()
{
	return refMyCharacter;
}

ref GetEnemyCharacterRef()
{
	return refEnemyCharacter;
}

void ISetShipAttributes(ref chref)
{
	DeleteAttribute(chref,"ship");
	aref arToChar;	makearef(arToChar,chref.ship);
	aref arFromChar;	makearef(arFromChar,refEnemyCharacter.ship);
	CopyAttributes(arToChar,arFromChar);
}

void ReturnMyCrew(ref rMC, ref rEC)
{
	int nMyCrew = GetCrewQuantity(rEC);
	int nMyMaxCrew = GetMaxCrewQuantity(rMC);

	int nEnemyCrew = GetCrewQuantity(rMC);
	int nEnemyMaxCrew = GetMaxCrewQuantity(rEC);

	if(nEnemyCrew>nEnemyMaxCrew) {
		nMyCrew += nEnemyCrew - nEnemyMaxCrew;
		nEnemyCrew = nEnemyMaxCrew;
	}
	if(nMyCrew>nMyMaxCrew) {
		nEnemyCrew += nMyCrew - nMyMaxCrew;
		nMyCrew = nMyMaxCrew;
	}

	if(nEnemyCrew>nEnemyMaxCrew) {
		nEnemyCrew = nEnemyMaxCrew;
	}

	rMC.ship.crew.quantity = nMyCrew;
	rEC.ship.crew.quantity = nEnemyCrew;
}

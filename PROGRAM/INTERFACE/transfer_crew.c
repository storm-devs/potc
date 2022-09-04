ref refMyCharacter;
ref refEnemyCharacter;

int nMyCharacterCompanionPlace;
int nCompanionIndex;

void InitInterface_RR(string iniName,ref myCh,ref enemyCh)
{
	refMyCharacter = myCh;
	refEnemyCharacter = enemyCh;
    GameInterface.title = "titleTransferCrew";

	nCompanionIndex = -1;
	nMyCharacterCompanionPlace = -1;
	if(CheckAttribute(myCh,"InterfaceParam.i1")) {
		nMyCharacterCompanionPlace = sti(myCh.InterfaceParam.i1);
		nCompanionIndex = GetCompanionIndex(refMyCharacter,nMyCharacterCompanionPlace);
	}

    SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);
    SetVariable();

	ref shipRef = GetShipByType(sti(refMyCharacter.ship.Type));
	CreateImage("myShip",GetShipTextureName(shipRef.name),shipRef.name,32,39,160,167);
    CreateImage("myFace",GetFaceGroupName(sti(refMyCharacter.index)),GetFacePictureName(sti(refMyCharacter.index)),164,39,292,167);
    CreateString(TRUE,"MyShipType",XI_ConvertString(shipRef.Name),FONT_NORMAL,COLOR_NORMAL,96,140,SCRIPT_ALIGN_CENTER,1.0);
    CreateString(TRUE,"MyShipName",refMyCharacter.ship.Name,FONT_NORMAL,COLOR_NORMAL,177,198,SCRIPT_ALIGN_CENTER,1.0);

	shipRef = GetShipByType(sti(refEnemyCharacter.ship.Type));
	CreateImage("enemyShip",GetShipTextureName(shipRef.name),shipRef.name,480,39,608,167);
	if(nCompanionIndex<0) {
		CreateImage("enemyFace",GetFaceGroupName(sti(refEnemyCharacter.index)),GetFacePictureName(sti(refEnemyCharacter.index)),348,39,476,167);
	} else {
		CreateImage("enemyFace",GetFaceGroupName(nCompanionIndex),GetFacePictureName(nCompanionIndex),348,39,476,167);
	}
    CreateString(TRUE,"EnemyShipType",XI_ConvertString(shipRef.Name),FONT_NORMAL,COLOR_NORMAL,544,140,SCRIPT_ALIGN_CENTER,1.0);
    CreateString(TRUE,"EnemyShipName",refEnemyCharacter.ship.Name,FONT_NORMAL,COLOR_NORMAL,463,198,SCRIPT_ALIGN_CENTER,1.0);

	CreateString(TRUE,"MyHull","",FONT_NORMAL,COLOR_NORMAL,92,260,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(TRUE,"MyRig","",FONT_NORMAL,COLOR_NORMAL,92,298,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(TRUE,"MyCrew","",FONT_NORMAL,COLOR_NORMAL,92,336,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(TRUE,"MyCannons","",FONT_NORMAL,COLOR_NORMAL,92,374,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(TRUE,"EnemyHull","",FONT_NORMAL,COLOR_NORMAL,548,260,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(TRUE,"EnemyRig","",FONT_NORMAL,COLOR_NORMAL,548,298,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(TRUE,"EnemyCrew","",FONT_NORMAL,COLOR_NORMAL,548,336,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(TRUE,"EnemyCannons","",FONT_NORMAL,COLOR_NORMAL,548,374,SCRIPT_ALIGN_RIGHT,1.0);

	CreateString(TRUE,"LeftCrew","",FONT_BOLD_NUMBERS,COLOR_NORMAL,280,302,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(TRUE,"RightCrew","",FONT_BOLD_NUMBERS,COLOR_NORMAL,360,302,SCRIPT_ALIGN_LEFT,1.0);

	WasChangeData();

	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
    SetEventHandler("InterfaceCancel","ProcessCancelExit",0);
	SetEventHandler("ChangerLeft","ProcessChangeLeft",0);
	SetEventHandler("ChangerRight","ProcessChangeRight",0);
	SetEventHandler("IEvnt_MouseClick","IProcMouseClick",0);
}

void SetVariable()
{
}

void WasChangeData()
{
	ref shipRef = GetShipByType(sti(refMyCharacter.ship.Type));
	GameInterface.pictures.myShip.tex = GetShipTextureName(shipRef.name);
	GameInterface.pictures.myShip.pic = shipRef.name;
	GameInterface.strings.MyShipType = XI_ConvertString(shipRef.name);
	GameInterface.strings.MyHull = makeint(refMyCharacter.ship.HP);
	GameInterface.strings.MyRig = makeint(refMyCharacter.ship.SP);
	GameInterface.strings.MyCrew = GetCrewQuantity(refMyCharacter)+"/"+GetMaxCrewQuantity(refMyCharacter);
	GameInterface.strings.MyCannons = shipRef.CannonsQuantity;

	shipRef = GetShipByType(sti(refEnemyCharacter.ship.Type));
	GameInterface.pictures.enemyShip.tex = GetShipTextureName(shipRef.name);
	GameInterface.pictures.enemyShip.pic = shipRef.name;
	GameInterface.strings.EnemyShipType = XI_ConvertString(shipRef.name);
	GameInterface.strings.EnemyHull = makeint(refEnemyCharacter.ship.HP);
	GameInterface.strings.EnemyRig = makeint(refEnemyCharacter.ship.SP);
	GameInterface.strings.EnemyCrew = GetCrewQuantity(refEnemyCharacter)+"/"+GetMaxCrewQuantity(refEnemyCharacter);
	GameInterface.strings.EnemyCannons = shipRef.CannonsQuantity;

	GameInterface.strings.LeftCrew = GetCrewQuantity(refMyCharacter);
	GameInterface.strings.RightCrew = GetCrewQuantity(refEnemyCharacter);
}

void ProcessCancelExit()
{
	interfaceResultCommand = RC_INTERFACE_TRANSFER_MAIN_RETURN;
	Exit();
}

void Exit()
{
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
    DelEventHandler("InterfaceCancel","ProcessCancelExit");
	DelEventHandler("ChangerLeft","ProcessChangeLeft");
	DelEventHandler("ChangerRight","ProcessChangeRight");
	DelEventHandler("IEvnt_MouseClick","IProcMouseClick");

	EndCancelInterface(true);
}

void ProcessChangeLeft()
{
	if(GetCrewQuantity(refEnemyCharacter)<=0) return;
	if(GetMaxCrewQuantity(refMyCharacter)<=GetCrewQuantity(refMyCharacter)) return;
	AddCharacterCrew(refMyCharacter,1);
	RemoveCharacterCrew(refEnemyCharacter,1);
	WasChangeData();
}

void ProcessChangeRight()
{
	if(GetCrewQuantity(refMyCharacter)<=0) return;
	if(GetMaxCrewQuantity(refEnemyCharacter)<=GetCrewQuantity(refEnemyCharacter)) return;
	AddCharacterCrew(refEnemyCharacter,1);
	RemoveCharacterCrew(refMyCharacter,1);
	WasChangeData();
}

void IProcMouseClick()
{
	string nodName = GetEventData();
	int btnCode = GetEventData();

	if(nodName=="CREW_CHANGER")
	{
		if(btnCode==0) ProcessChangeLeft();
		if(btnCode==1) ProcessChangeRight();
	}
}

ref GetMyCharacterRef()
{
	return refMyCharacter;
}

ref GetEnemyCharacterRef()
{
	return refEnemyCharacter;
}

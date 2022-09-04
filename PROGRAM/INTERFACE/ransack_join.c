#define str1	"Enemy Surrendered"
#define str2	"surrendered men wishes"
#define str3	"to join your crew"

ref refMyCharacter;
ref refEnemyCharacter;

int nSurrenderedMen;
int nResultMorale;

void InitInterface_RR(string iniName,ref myCh,ref enemyCh)
{
	refMyCharacter = myCh;
	refEnemyCharacter = enemyCh;
    GameInterface.title = "titleRansack";

    SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);
    SetVariable();

	ref shipRef = GetShipByType(sti(refMyCharacter.ship.Type));
	CreateImage("myShip","SHIPS",shipRef.name,32,39,160,167);
    CreateString(TRUE,"MyShipType",XI_ConvertString(shipRef.Name),FONT_NORMAL,COLOR_NORMAL,96,140,SCRIPT_ALIGN_CENTER,1.0);

	shipRef = GetShipByType(sti(refEnemyCharacter.ship.Type));
	CreateImage("enemyShip","SHIPS",shipRef.name,480,39,608,167);
    CreateString(TRUE,"EnemyShipType",XI_ConvertString(shipRef.Name),FONT_NORMAL,COLOR_NORMAL,544,140,SCRIPT_ALIGN_CENTER,1.0);

    CreateString(TRUE,"MyShipName",refMyCharacter.ship.Name,FONT_NORMAL,COLOR_NORMAL,177,198,SCRIPT_ALIGN_CENTER,1.0);
    CreateString(TRUE,"EnemyShipName",refEnemyCharacter.ship.Name,FONT_NORMAL,COLOR_NORMAL,463,198,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(TRUE,"String1",XI_ConvertString(str1),FONT_NORMAL,COLOR_NORMAL,320,240,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(TRUE,"String2",nSurrenderedMen+" "+XI_ConvertString(str2),FONT_NORMAL,COLOR_NORMAL,320,268,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(TRUE,"String3",XI_ConvertString(str3),FONT_NORMAL,COLOR_NORMAL,320,296,SCRIPT_ALIGN_CENTER,1.0);

    CreateImage("myFace","FACE128_"+refMyCharacter.FaceId,"face",164,39,292,167);
    CreateImage("enemyFace","FACE128_"+refEnemyCharacter.FaceId,"face",348,39,476,167);

	CreateImage("BeginMorale","MORALE",GetMoralePicture(sti(refMyCharacter.Ship.Crew.Morale)),56,282,184,410);
	CreateImage("FinishMorale","MORALE",GetMoralePicture(nResultMorale),472,282,600,410);
	CreateString(TRUE,"bMorale",refMyCharacter.Ship.Crew.Morale,FONT_NORMAL,COLOR_NORMAL,120,378,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(TRUE,"fMorale",nResultMorale,FONT_NORMAL,COLOR_NORMAL,536,378,SCRIPT_ALIGN_CENTER,1.0);

	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
    SetEventHandler("InterfaceCancel","ProcessCancelExit",0);
	SetEventHandler("AgreePress","AgreeProcess",0);
	SetEventHandler("RefusePress","RefuseProcess",0);
}

string GetMoralePicture(int morale)
{
	if(morale<33) return "low morale";
	if(morale<66) return "medium morale";
	return "high morale";
}

void SetVariable()
{
	int SurrenderedProcent = GetSummonSkillFromName(refMyCharacter,SKILL_LEADERSHIP)*8 + 10 + rand(10);
	nSurrenderedMen = (sti(refEnemyCharacter.ship.Crew.Quantity)*SurrenderedProcent)/100;
	nResultMorale = 5+rand(80);
	nResultMorale = (nResultMorale*nSurrenderedMen + sti(refMyCharacter.Ship.Crew.Quantity)*sti(refMyCharacter.Ship.Crew.Morale))/(sti(refMyCharacter.Ship.Crew.Quantity)+nSurrenderedMen);
}

void ProcessCancelExit()
{
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
    DelEventHandler("InterfaceCancel","ProcessCancelExit");
	DelEventHandler("AgreePress","AgreeProcess");
	DelEventHandler("RefusePress","RefuseProcess");

	interfaceResultCommand = RC_INTERFACE_RANSACK_JOIN_EXIT;
	EndCancelInterface(true);
}

void AgreeProcess()
{
	ref refBaseShip = GetShipByType(sti(refMyCharacter.ship.Type));
	if(sti(refMyCharacter.ship.Crew.Quantity) + nSurrenderedMen>sti(refBaseShip.MaxCrew))
	{
		nSurrenderedMen = sti(refBaseShip.MaxCrew) - sti(refMyCharacter.ship.Crew.Quantity);
	}
	refMyCharacter.ship.Crew.Quantity = sti(refMyCharacter.ship.Crew.Quantity) + nSurrenderedMen;
	refMyCharacter.ship.Crew.Morale = nResultMorale;
	refEnemyCharacter.ship.Crew.Quantity = sti(refEnemyCharacter.ship.Crew.Quantity) - nSurrenderedMen;
	ProcessCancelExit();
}

void RefuseProcess()
{
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

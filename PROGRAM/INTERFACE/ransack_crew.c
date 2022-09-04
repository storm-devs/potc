#define str1	"Enemy Surrendered"
#define str2	"You must choose the destiny"
#define str3_1	"of"
#define str3_2  "surrendered men"

ref refMyCharacter;
ref refEnemyCharacter;

int nSurrenderedMen;

void InitInterface_RR(string iniName,ref myCh,ref enemyCh)
{
	refMyCharacter = myCh;
	refEnemyCharacter = enemyCh;
    GameInterface.title = "titleRansack";

    SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);
    SetVariable();

	ref shipRef = GetShipByType(sti(refMyCharacter.ship.Type));
	CreateImage("myShip","SHIPS",shipRef.name,32,39,160,167);
    CreateImage("myFace","FACE128_"+refMyCharacter.FaceId,"face",164,39,292,167);
    CreateString(TRUE,"MyShipType",XI_ConvertString(shipRef.Name),FONT_NORMAL,COLOR_NORMAL,96,140,SCRIPT_ALIGN_CENTER,1.0);
    CreateString(TRUE,"MyShipName",refMyCharacter.ship.Name,FONT_NORMAL,COLOR_NORMAL,177,198,SCRIPT_ALIGN_CENTER,1.0);

	shipRef = GetShipByType(sti(refEnemyCharacter.ship.Type));
	CreateImage("enemyShip","SHIPS",shipRef.name,480,39,608,167);
    CreateImage("enemyFace","FACE128_"+refEnemyCharacter.FaceId,"face",348,39,476,167);
    CreateString(TRUE,"EnemyShipType",XI_ConvertString(shipRef.Name),FONT_NORMAL,COLOR_NORMAL,544,140,SCRIPT_ALIGN_CENTER,1.0);
    CreateString(TRUE,"EnemyShipName",refEnemyCharacter.ship.Name,FONT_NORMAL,COLOR_NORMAL,463,198,SCRIPT_ALIGN_CENTER,1.0);

	CreateString(TRUE,"String1",XI_ConvertString(str1),FONT_NORMAL,COLOR_NORMAL,320,240,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(TRUE,"String2",XI_ConvertString(str2),FONT_NORMAL,COLOR_NORMAL,320,268,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(TRUE,"String3",XI_ConvertString(str3_1)+" "+nSurrenderedMen+" "+XI_ConvertString(str3_2),FONT_NORMAL,COLOR_NORMAL,320,296,SCRIPT_ALIGN_CENTER,1.0);

	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
    SetEventHandler("InterfaceCancel","ProcessCancelExit",0);
	SetEventHandler("KillPress","KillProcess",0);
	SetEventHandler("SlavesPress","SlavesProcess",0);
}

void SetVariable()
{
	nSurrenderedMen = sti(refEnemyCharacter.Ship.Crew.Quantity);
}

void ProcessCancelExit()
{
	refEnemyCharacter.Ship.Crew.Quantity = 0;
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
    DelEventHandler("InterfaceCancel","ProcessCancelExit");
	DelEventHandler("KillPress","KillProcess");
	DelEventHandler("SlavesPress","SlavesProcess");

	interfaceResultCommand = RC_INTERFACE_RANSACK_CREW_EXIT;
	EndCancelInterface(true);
}

void KillProcess()
{
	ProcessCancelExit();
}

void SlavesProcess()
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

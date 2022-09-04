#include "storm-engine\sound.h"
#include "storm-engine\messages.h"
#include "sound.c"

//--------------------------------------------------------------------
// Math section
//--------------------------------------------------------------------
#define PI		3.14159265
#define PIm2	6.28318530
#define PId2	1.57079632
#define INVALID_SOUND_ID	0

int ngMusicID = 0;
string sgMusicName = "?";

float FRAND(float _x) { return rand(32768) / 32768.0 * _x; }

//--------------------------------------------------------------------
// Bool section
//--------------------------------------------------------------------
#define false			0
#define true			1			

//--------------------------------------------------------------------
// Nation section
//--------------------------------------------------------------------
#define	MAX_NATIONS		6
#define MAX_NATIONS_SQR		36

#define ENGLAND			0
#define FRANCE			1
#define SPAIN			2
#define PIRATE			3
#define HOLLAND			4
#define PORTUGAL		5

object	Nations[MAX_NATIONS];
int		NationsRelations[MAX_NATIONS_SQR];
int		NationsRelations2MainCharacter[MAX_NATIONS];

object  GameState;

//--------------------------------------------------------------------
// Characters section
//--------------------------------------------------------------------
#define TOTAL_CHARACTERS			1000
#define MAX_CHARACTERS				850
#define LOC_FANTOM_CHARACTERS		860	//32 max
#define FANTOM_CHARACTERS			900
#define BOARDING_CHARACTERS			800

#define	MAX_LOCATIONS		400
#define	MAX_ISLANDS			8
#define	MAX_BOARDING		16

string 	sEnManNames[2], sEnWomenNames[2], sEnFamilies[2];
string 	sHoManNames[2], sHoWomenNames[2], sHoFamilies[2];
string 	sPoManNames[2], sPoWomenNames[2], sPoFamilies[2];
string 	sFrManNames[2], sFrWomenNames[2], sFrFamilies[2];
string 	sSpManNames[2], sSpWomenNames[2], sSpFamilies[2];

object  NullCharacter;
object	Boarding[MAX_BOARDING];
object	Characters[TOTAL_CHARACTERS];
object	Locations[MAX_LOCATIONS];
object	Islands[MAX_ISLANDS];
object  Environment;
int		nMainCharacterIndex = 0;//-1;
int		iNumFantoms;

int		nLocationsNum;
int		nTeleportLocation;
string	sTeleportLocName;

bool	bArcadeMode = false;

bool isCharacterDead(int iIndex) { return sti(Characters[iIndex].Dead); }
ref GetFantomCharacter(int iIndex) { return &Characters[FANTOM_CHARACTERS + iIndex]; }
ref GetCharacter(int iIndex) { if(iIndex >= TOTAL_CHARACTERS || iIndex < 0) return &NullCharacter; return &Characters[iIndex]); }
ref GetMainCharacter() { return &Characters[nMainCharacterIndex]; }
int	GetMainCharacterIndex() { return nMainCharacterIndex; }
int	GetCharacterIndex(string string_id) 
{
	return NativeFindCharacter(&Characters, string_id);
/*	int n;
	for(n=0;n<TOTAL_CHARACTERS;n++)
	{
		if(string_id == Characters[n].id) return n; 
	}
	return -1;*/
}

void SetMainCharacterIndex(int index) 
{ 
	if (nMainCharacterIndex!=-1)
	{
		Characters[nMainCharacterIndex].MainCharacter = "0";
		Characters[nMainCharacterIndex].model.entity = "NPCharacter";
	}
	nMainCharacterIndex = index; 
	Characters[nMainCharacterIndex].MainCharacter = "1";
	Characters[nMainCharacterIndex].model.entity = "Player";
}

#define SHIPNAME_QUANTITY 8
string sShipNameTable[SHIPNAME_QUANTITY];

//--------------------------------------------------------------------
// Land Encounters section
//--------------------------------------------------------------------
#define MAX_LANDENCTEMPLATES 5
#define MAX_LAND_ENCOUNTERS 3

object LandEncTemplate[MAX_LANDENCTEMPLATES];
object LandEncounters[MAX_LAND_ENCOUNTERS];
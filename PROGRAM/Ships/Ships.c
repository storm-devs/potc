#include "ships\ships.h"

extern void InitShips();
extern void InitRandomShipsNames();

string	sRndShpSpName[2], sRndShpEnName[2], sRndShpFrName[2], sRndShpPiName[2], sRndShpHoName[2], sRndShpPoName[2];

void ShipsInit()
{
	if (LoadSegment("ships\ships_init.c"))
	{
		InitShips();
		UnloadSegment("ships\ships_init.c");
	}
}

void SetRandomNameToShip(ref rCharacter)
{
	ref rMassiveOfNames;
	//breakpoint();
	switch (sti(rCharacter.nation))
	{
		case ENGLAND:	makeref(rMassiveOfNames, sRndShpEnName); break;
		case FRANCE:	makeref(rMassiveOfNames, sRndShpFrName); break;
		case SPAIN:		makeref(rMassiveOfNames, sRndShpSpName); break;
		case PIRATE:	makeref(rMassiveOfNames, sRndShpPiName); break;
		case HOLLAND:	makeref(rMassiveOfNames, sRndShpHoName); break;
		case PORTUGAL:	makeref(rMassiveOfNames, sRndShpPoName); break;
	}
	int iMassiveOfNamesSize = GetArraySize(rMassiveOfNames);
	rCharacter.Ship.Name = GetRandSubString(rMassiveOfNames[rand(iMassiveOfNamesSize-2)]);
}

string GetShipLocationID(ref chref)
{
	if(!CheckAttribute(chref,"ship.type")) return "";
	int st = sti(chref.ship.type);
	if(st==SHIP_NOTUSED) return "";
	if(st==SHIP_FORT)
	{
		aref ar_FindLoc = FindIslandReloadLocator(chref.location,chref.location.locator);
		if( CheckAttribute(ar_FindLoc,"go") ) return ar_FindLoc.go;
		return "";
	}
	if(!CheckAttribute(&ShipsTypes[st],"AbordageLocation"))
	{
		trace("WARNING!!! Ship ("+st+") " + ShipsTypes[st].name + " hav`t attribute AbordageLocation");
		return "";
	}
	return ShipsTypes[st].AbordageLocation;
}

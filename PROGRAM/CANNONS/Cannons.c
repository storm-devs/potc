#include "cannons\cannons.h"

extern void InitCannons();

void CannonsInit()
{
	if(LoadSegment("cannons\cannons_init.c"))
	{
		InitCannons();
		UnloadSegment("cannons\cannons_init.c");
	}

	SetEventHandler(GET_CANNON_BY_TYPE_EVENT,"CannonGetByTypeEvent",0);
}

aref CannonGetByTypeEvent()
{
	int iCannonType = GetEventData();
	return &Cannon[iCannonType];
}

int GetCannonByTypeAndCaliber(string sCannonType, int iCaliber)
{
	switch (sCannonType)
	{
		case "cannon":
			switch (iCaliber)
			{
				case 12:
					return CANNON_TYPE_CANNON_LBS12;
				break;
				case 16:
					return CANNON_TYPE_CANNON_LBS16;
				break;
				case 24:
					return CANNON_TYPE_CANNON_LBS24;
				break;
				case 32:
					return CANNON_TYPE_CANNON_LBS32;
				break;
			}
		break;
		case "culverine":
			switch (iCaliber)
			{
				case 12:
					return CANNON_TYPE_CULVERINE_LBS12;
				break;
				case 16:
					return CANNON_TYPE_CULVERINE_LBS16;
				break;
				case 24:
					return CANNON_TYPE_CULVERINE_LBS24;
				break;
			}
		break;
	}

	return CANNON_TYPE_NONECANNON;
}
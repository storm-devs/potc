#define CANNON_TYPES_QUANTITY		7

#define CANNON_TYPE_CULVERINE_LBS12	0
#define CANNON_TYPE_CULVERINE_LBS16	1
#define CANNON_TYPE_CULVERINE_LBS24	2
#define CANNON_TYPE_CANNON_LBS12	3
#define CANNON_TYPE_CANNON_LBS16	4
#define CANNON_TYPE_CANNON_LBS24	5
#define CANNON_TYPE_CANNON_LBS32	6

#define CANNON_TYPE_NONECANNON		1000

#define CANNON_NAME_CANNON              1
#define CANNON_NAME_CULVERINE           2
#define CANNON_NAME_SPECIAL_CANNON		3

object  Cannon[CANNON_TYPES_QUANTITY];

ref GetCannonByType(int iCannonType) { return &Cannon[iCannonType]; }

int GetCannonCaliber(int nCannon)
{
    switch(nCannon)
    {
    case CANNON_TYPE_NONECANNON:
        return 0;
        break;
    case CANNON_TYPE_CULVERINE_LBS12:
        return 12;
        break;
    case CANNON_TYPE_CANNON_LBS12:
        return 12;
        break;
    case CANNON_TYPE_CULVERINE_LBS16:
        return 16;
        break;
    case CANNON_TYPE_CANNON_LBS16:
        return 16;
        break;
    case CANNON_TYPE_CULVERINE_LBS24:
        return 24;
        break;
    case CANNON_TYPE_CANNON_LBS24:
        return 24;
        break;
    case CANNON_TYPE_CANNON_LBS32:
        return 32;
        break;
    }
}

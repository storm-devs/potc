#define GOODS_QUANTITY  27

#define GOOD_BALLS	0
#define GOOD_GRAPES	1
#define GOOD_KNIPPELS	2
#define GOOD_BOMBS	3

#define GOOD_SAILCLOTH	4
#define GOOD_PLANKS	5
#define GOOD_WHEAT	6
#define GOOD_EBONY	7
#define GOOD_CHOCOLATE	8
#define GOOD_SUGAR	9
#define GOOD_WINE	10
#define GOOD_LINEN	11
#define GOOD_RUM	12
#define GOOD_TOBACCO	13
#define GOOD_COFFEE	14
#define GOOD_MAHOGANY	15
#define GOOD_CINNAMON	16
#define GOOD_COPRA	17
#define GOOD_PAPRIKA	18
#define GOOD_FRUITS	19
#define GOOD_ALE	20
#define GOOD_SILK	21
#define GOOD_CLOTHES	22
#define GOOD_COTTON	23
#define GOOD_SANDAL	24
#define GOOD_LEATHER	25
#define GOOD_OIL	26

object  Goods[GOODS_QUANTITY];

ref GetGoodByType(int iGoodType)
{
	return &Goods[iGoodType];
}

int FindGood(string sGood)
{
	for (int i=0; i<GOODS_QUANTITY; i++) { if (Goods[i].Name == sGood) return i; }
	return -1;
}

ref GetGoodByID(string sGood)
{
	for (int i=0; i<GOODS_QUANTITY; i++) { if (Goods[i].Name == sGood) return &Goods[i]; }
	trace("WARNING! Goods ID (" + sGood +") not found!");
}

int GetGoodWeightByType(int iGoodType,int quantity)
{
	int unitSize = sti(Goods[iGoodType].Units);
	int unitQuantity = (quantity+unitSize-1)/unitSize;
	int weight = unitQuantity*sti(Goods[iGoodType].Weight);
	return weight;
}

int GetGoodQuantityByWeight(int iGoodType,int weight)
{
	int unitSize = sti(Goods[iGoodType].Units);
	int uqnt = weight/sti(Goods[iGoodType].Weight);
	return unitSize*uqnt;
}

#define PRICE_TYPE_BUY	0
#define PRICE_TYPE_SELL	1

#event_handler("NextDay","StoreDayUpdateStart");
#event_handler("EvStoreDayUpdate","StoreDayUpdate");

void SetStoreGoods(object _refStore,int _Goods,int _Quantity)
{
	string tmpstr = Goods[_Goods].name;
	_refStore.Goods.(tmpstr).Quantity = _Quantity;
}

void AddStoreGoods(object _refStore,int _Goods,int _Quantity)
{
	aref refGoods;
	string tmpstr = Goods[_Goods].name;
	makearef(refGoods,_refStore.Goods.(tmpstr));
	int q = 0;
	if( CheckAttribute(refGoods,"Quantity") ) {q = sti(refGoods.Quantity);}
	refGoods.Quantity = q +_Quantity;
}

void RemoveStoreGoods(object _refStore,int _Goods,int _Quantity)
{
	aref refGoods;
	string tmpstr = Goods[_Goods].name;
	makearef(refGoods,_refStore.Goods.(tmpstr));
	int q = 0;
	if( CheckAttribute(refGoods,"Quantity") ) q = sti(refGoods.Quantity);
	if(q<_Quantity) {refGoods.Quantity = 0;}
	else {refGoods.Quantity = q - _Quantity;}
}

int GetStoreGoodsQuantity(object _refStore,int _Goods)
{
	string tmpstr = Goods[_Goods].name;
	int q = 0;
	if( CheckAttribute(_refStore,"Goods."+tmpstr) )
		q = sti(_refStore.Goods.(tmpstr).Quantity);
	return q;
}

int GetStoreGoodsPrice(object _refStore,int _Goods,int _PriceType,ref chref)
{
	int _TradeSkill = GetSummonSkillFromName(chref,SKILL_COMMERCE);
	aref refGoods;
	string tmpstr = Goods[_Goods].name;
	int basePrice = MakeInt(Goods[_Goods].Cost);
	if( !CheckAttribute(_refStore,"Goods."+tmpstr) ) return 0;
	makearef(refGoods,_refStore.Goods.(tmpstr));
 	int tradeType = MakeInt(refGoods.TradeType);

	float tradeModify=1.0;
	switch(tradeType)
	{
	case TRADE_TYPE_NORMAL:
		tradeModify=0.8+stf(refGoods.RndPriceModify);
		break;
	case TRADE_TYPE_EXPORT:
		tradeModify=0.3+stf(refGoods.RndPriceModify);
		break;
	case TRADE_TYPE_IMPORT:
		tradeModify=1.3+stf(refGoods.RndPriceModify);
		break;
	case TRADE_TYPE_CONTRABAND:
		tradeModify=2.5+stf(refGoods.RndPriceModify);
		break;
	case TRADE_TYPE_AMMUNITION:
		return basePrice;
		break;
	}

	float skillModify;
	if(_PriceType==PRICE_TYPE_BUY)
	{
		skillModify = 1.4 - _TradeSkill*0.019;
		if(CheckOfficersPerk(chref,"AdvancedCommerce"))	{ skillModify -= 0.2; }
		else
		{
			if(CheckOfficersPerk(chref,"BasicCommerce"))	{ skillModify -= 0.1; }
		}
	}
	else
	{
		skillModify = 0.75 + _TradeSkill*0.019;
		if(CheckOfficersPerk(chref,"AdvancedCommerce"))	skillModify += 0.05;
	}

	return MakeInt(basePrice*tradeModify*skillModify);
}

string GetStoreGoodsType(ref _refStore,int _Goods)
{
	string tmpstr = Goods[_Goods].name;
	int tradeType = TRADE_TYPE_NORMAL;
	if( CheckAttribute(_refStore,"Goods."+tmpstr) ) {
		tradeType = sti(_refStore.Goods.(tmpstr).TradeType);
	}

	switch(tradeType)
	{
	case TRADE_TYPE_NORMAL:
		return TRADE_TYPE_NORMAL_NAME;
		break;
	case TRADE_TYPE_EXPORT:
		return TRADE_TYPE_EXPORT_NAME;
		break;
	case TRADE_TYPE_IMPORT:
		return TRADE_TYPE_IMPORT_NAME;
		break;
	case TRADE_TYPE_CONTRABAND:
		return TRADE_TYPE_CONTRABAND_NAME;
		break;
	case TRADE_TYPE_AMMUNITION:
		return TRADE_TYPE_AMMUNITION_NAME;
		break;
	}
	Trace("Missing trade type");
	return TRADE_TYPE_NORMAL_NAME;
}

bool GetStoreGoodsUsed(ref _refStore,int _Goods)
{
	string tmpstr = Goods[_Goods].name;
	if( !CheckAttribute(_refStore,"Goods."+tmpstr) ) return false;
	if( sti(_refStore.Goods.(tmpstr).NotUsed)==true ) return false;
	if( sti(_refStore.Goods.(tmpstr).TradeType) == TRADE_TYPE_CONTRABAND )
	{	if( !CheckOfficersPerk(GetMainCharacter(),"Trustworthy") ) return false;
	}
	return true;
}

void SetStoresTradeUsed(int StoreNum,int GoodsNum,bool goodsUsed)
{
	string tmpstr = Goods[GoodsNum].Name;
	Stores[StoreNum].Goods.(tmpstr).NotUsed = !goodsUsed;
}

int storeDayUpdateCnt = -1;
void StoreDayUpdateStart()
{
	if(storeDayUpdateCnt >= 0) return;
	storeDayUpdateCnt = 0;
	PostEvent("EvStoreDayUpdate", 30);
}
void StoreDayUpdate()
{
	if(storeDayUpdateCnt >= 0)
	{
		UpdateStore(&Stores[storeDayUpdateCnt]);
		storeDayUpdateCnt++;
		if(storeDayUpdateCnt >= STORE_QUANTITY) storeDayUpdateCnt = -1;
		PostEvent("EvStoreDayUpdate", 30);
	}
}

void UpdateStore(ref pStore)
{
	bool bigSize = pStore.StoreSize=="large";
	aref gref,curref;
	makearef(gref,pStore.Goods);
	int nq = GetAttributesNum(gref);
	int n;
	string tmpstr;
	for(int i=0; i<GOODS_QUANTITY; i++)
	{
		tmpstr = Goods[i].name;
		if( !CheckAttribute(gref,tmpstr) ) continue;
		makearef(curref,gref.(tmpstr));
		if( sti(curref.TradeType)==TRADE_TYPE_AMMUNITION ) {
			curref.Quantity = 1000+Rand(50)*20;
			continue;
		}
		if( i==GOOD_SAILCLOTH || i==GOOD_PLANKS ) {
			curref.Quantity = 600+Rand(100);
			continue;
		}
		n = sti(curref.Quantity) - GetConsumeGoods(sti(curref.TradeType),bigSize);
		if(n<0) n=0;
		n += GetProductGoods(sti(curref.TradeType),bigSize);
		curref.RndPriceModify = AddPriceModify(stf(curref.RndPriceModify),sti(curref.TradeType));
		curref.Quantity = n;
	}
}

float AddPriceModify(float curModify, int tradeType)
{
	float fMaxModify = 0.39;
	if(tradeType==TRADE_TYPE_CONTRABAND) fMaxModify = 0.99;
	if(curModify>0.01)
	{
		if(curModify<fMaxModify)	curModify += 0.01 - 0.02*frnd();
		else	curModify -= 0.01*frnd();
	}
	else	curModify += 0.01*frnd();
	return curModify;
}

int GetProductGoods(int tradeType,bool bLarge)
{
	if(bLarge)
	{
		switch(tradeType)
		{
			case TRADE_TYPE_NORMAL:		return 24+rand(6);	break;
			case TRADE_TYPE_EXPORT:		return 30+rand(6);	break;
			case TRADE_TYPE_IMPORT:		return 20+rand(6);	break;
			case TRADE_TYPE_CONTRABAND: return 24+rand(6);	break;
		}
	}
	switch(tradeType)
	{
		case TRADE_TYPE_NORMAL:		return 10+rand(5);	break;
		case TRADE_TYPE_EXPORT:		return 15+rand(5);	break;
		case TRADE_TYPE_IMPORT:		return 5+rand(5);	break;
		case TRADE_TYPE_CONTRABAND: return 10+rand(5);	break;
	}
	return 0;
}

int GetConsumeGoods(int tradeType,bool bLarge)
{
	if(bLarge)
	{
		switch(tradeType)
		{
			case TRADE_TYPE_NORMAL:		return 22+rand(6);	break;
			case TRADE_TYPE_EXPORT:		return 26+rand(6);	break;
			case TRADE_TYPE_IMPORT:		return 22+rand(6);	break;
			case TRADE_TYPE_CONTRABAND: return 24+rand(6);	break;
		}
	}
	switch(tradeType)
	{
		case TRADE_TYPE_NORMAL:		return 8+rand(5);	break;
		case TRADE_TYPE_EXPORT:		return 10+rand(6);	break;
		case TRADE_TYPE_IMPORT:		return 7+rand(5);	break;
		case TRADE_TYPE_CONTRABAND: return 10+rand(5);	break;
	}
	return 0;
}

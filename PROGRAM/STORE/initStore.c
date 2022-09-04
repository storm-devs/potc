extern void StoreInit();

void InitStores()
{
    int i;

    for(i=0; i<STORE_QUANTITY; i++)
    {
		stores[i].index = i;
        StoreVoidFill(&stores[i]);
    }

	if(LoadSegment("store\store_init.c"))
	{
		StoreInit();
		UnloadSegment("store\store_init.c");
	}

    for(i=0; i<STORE_QUANTITY; i++)
    {
        FillStoreGoods(&stores[i]);
    }
}

void SetStoresTradeType(int StoreNum,int GoodsNum,int TradeType)
{
	string tmpstr = Goods[GoodsNum].Name;
	Stores[StoreNum].Goods.(tmpstr).TradeType = TradeType;
}

void FillStoreGoods(ref pRef)
{
    int i,j,nq,n,tt;
	string goodName;
	int goodBasePrice;

	int islandIdx = FindIsland(pRef.Island);
	aref arTypes,arCurGoods,arCurType;
	if(islandIdx!=-1)
	{
		ref rIsland = GetIslandByIndex(islandIdx);
		makearef(arTypes,rIsland.Trade);
		nq = GetAttributesNum(arTypes);
		for(i=0;i<nq;i++)
		{
			arCurType = GetAttributeN(arTypes,i);
			tt=TRADE_TYPE_NORMAL;
			switch(GetAttributeName(arCurType))
			{
			case "Export":		tt=TRADE_TYPE_EXPORT;		break;
			case "Import":		tt=TRADE_TYPE_IMPORT;		break;
			case "Contraband":	tt=TRADE_TYPE_CONTRABAND;	break;
			}
			n = GetAttributesNum(arCurType);
			for(j=0;j<n;j++)
			{
				goodName = Goods[sti(GetAttributeValue(GetAttributeN(arCurType,j)))].name;
				pRef.Goods.(goodName).TradeType = tt;
			}
		}
	}
	else
	{
		trace("Mistake island id into store:  id="+pRef.Island);
	}

	for(i=0; i<GOODS_QUANTITY; i++)
	{
	    goodName = Goods[i].Name;
		if( i==GOOD_BALLS || i==GOOD_GRAPES || i==GOOD_KNIPPELS || i==GOOD_BOMBS )
		{
			pRef.Goods.(goodName).Quantity = 1000+Rand(50)*sti(goods[i].Units);
			pRef.Goods.(goodName).RndPriceModify = 1.0;
			pRef.Goods.(goodName).TradeType = TRADE_TYPE_AMMUNITION;
			continue;
		}
		if( i==GOOD_PLANKS || i==GOOD_SAILCLOTH )
		{
			pRef.Goods.(goodName).Quantity = 500+Rand(50)*sti(goods[i].Units);
			pRef.Goods.(goodName).RndPriceModify = 1.0;
			//pRef.Goods.(goodName).TradeType = TRADE_TYPE_AMMUNITION;
			continue;
		}
		goodBasePrice = MakeInt(goods[i].Cost);
		switch(sti(pRef.Goods.(goodName).TradeType))
		{
		case TRADE_TYPE_NORMAL:
		    pRef.Goods.(goodName).Quantity = (100 + Rand(20))*sti(goods[i].Units);
			pRef.Goods.(goodName).RndPriceModify = frnd() * 0.4;
			break;

		case TRADE_TYPE_EXPORT:
		    pRef.Goods.(goodName).Quantity = (150 + Rand(30))*sti(goods[i].Units);
			pRef.Goods.(goodName).RndPriceModify = frnd() * 0.4;
			break;

		case TRADE_TYPE_IMPORT:
		    pRef.Goods.(goodName).Quantity = (50+Rand(10))*sti(goods[i].Units);
			pRef.Goods.(goodName).RndPriceModify = frnd() * 0.4;
			break;

		case TRADE_TYPE_CONTRABAND:
		    pRef.Goods.(goodName).Quantity = Rand(5)*sti(goods[i].Units);
			pRef.Goods.(goodName).RndPriceModify = frnd();
			break;
		}
	}
}

void StoreVoidFill(ref pRef)
{
	string goodName;
	pRef.StoreSize = "large"; // "small"
	pRef.Island = "";
	for(int i=0; i<GOODS_QUANTITY; i++)
	{
	    goodName = Goods[i].Name;
	    pRef.Goods.(goodName).TradeType = TRADE_TYPE_NORMAL;
		pRef.Goods.(goodName).NotUsed = false;
	}
}

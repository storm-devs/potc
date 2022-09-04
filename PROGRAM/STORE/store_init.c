//===========================================================================================
//			RULE:
//	pStore.StoreSize	- размер магазина ("large" или "small") - влияет на кол-во товара,
//						по умолчанию берется равным "large".
//	pStore.Island		- id острова к которому принадлежит магазин.
//	pStore.Goods.имя_товара.NotUsed		- устанавливается в TRUE для тех товаров, которыми
//										нельзя торговать в данном магазине.
//										(по умолчанию false).
//===========================================================================================
void StoreInit()
{
	ref pStore;

	// Falaise de fleur
	Stores[FALAISE_DE_FLEUR_STORE].Island	= "FalaiseDeFleur";
	Stores[FALAISE_DE_FLEUR_STORE].group	= "Falaise_de_fleur";

	// Redmond
	Stores[REDMOND_STORE].Island	= "Redmond";
	Stores[REDMOND_STORE].group	= "Redmond";

	// Isla Muelle
	Stores[ISLA_MUELLE_STORE].Island	= "IslaMuelle";
	Stores[ISLA_MUELLE_STORE].group	= "Muelle";

	// Oxbay
	Stores[OXBAY_STORE].Island	= "Oxbay";
	Stores[OXBAY_STORE].Group	= "Oxbay";

	// незахваченный город в Oxbay
	Stores[GREENFORD_STORE].Island	= "Oxbay";
	Stores[GREENFORD_STORE].Group	= "Greenford";	

	// Conceicao
	Stores[CONCEICAO_STORE].Island	= "Conceicao";
	Stores[CONCEICAO_STORE].Group	= "Conceicao";

	// контрабандисты
	Stores[SMUGGLERS_STORE].Island	= "Conceicao";
	Stores[SMUGGLERS_STORE].group	= "Conceicao";

	// Douwesen
	Stores[DOUWESEN_STORE].Island	= "Douwesen";
	Stores[DOUWESEN_STORE].group	= "Douwesen";

	// Quebradas
	Stores[PIRATES_STORE].Island	= "QuebradasCostillas";
	Stores[PIRATES_STORE].group	= "QC";
}

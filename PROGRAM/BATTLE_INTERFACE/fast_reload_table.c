#define FRP_STORE		0
#define FRT_STORE		0

#define FRP_SHIPYARD	1
#define FRT_SHIPYARD	0

#define FRP_TAVERN		2
#define FRT_TAVERN		0

#define FRP_RESIDENCE	3
#define FRT_RESIDENCE	0

void initFastReloadTable()
{
	InitTownTable();

	objFastReloadTable.reloadEnable = true;
	aref curTable;

	makearef(curTable,objFastReloadTable.table.Conceicao);
	// store
	curTable.l1.pic = FRP_STORE;
	curTable.l1.tex = FRT_STORE;
	curTable.l1.location = "Conceicao_Store";
	// shipyard
	curTable.l2.pic = FRP_SHIPYARD;
	curTable.l2.tex = FRT_SHIPYARD;
	curTable.l2.location = "Conceicao_Shipyard";
	// tavern
	curTable.l3.pic = FRP_TAVERN;
	curTable.l3.tex = FRT_TAVERN;
	curTable.l3.location = "Conceicao_Tavern";
	// residence
	curTable.l4.pic = FRP_RESIDENCE;
	curTable.l4.tex = FRT_RESIDENCE;
	curTable.l4.location = "Conceicao_townhall";

	makearef(curTable,objFastReloadTable.table.Douwesen);
	// store
	curTable.l1.pic = FRP_STORE;
	curTable.l1.tex = FRT_STORE;
	curTable.l1.location = "Douwesen_Store";
	// shipyard
	curTable.l2.pic = FRP_SHIPYARD;
	curTable.l2.tex = FRT_SHIPYARD;
	curTable.l2.location = "Douwesen_shipyard";
	// tavern
	curTable.l3.pic = FRP_TAVERN;
	curTable.l3.tex = FRT_TAVERN;
	curTable.l3.location = "Douwesen_tavern";
	// residence
	curTable.l4.pic = FRP_RESIDENCE;
	curTable.l4.tex = FRT_RESIDENCE;
	curTable.l4.location = "Douwesen_townhall";

	makearef(curTable,objFastReloadTable.table.Falaise_de_fleur);
	// store
	curTable.l1.pic = FRP_STORE;
	curTable.l1.tex = FRT_STORE;
	curTable.l1.location = "Falaise_de_Fleur_store";
	// shipyard
	curTable.l2.pic = FRP_SHIPYARD;
	curTable.l2.tex = FRT_SHIPYARD;
	curTable.l2.location = "Falaise_de_fleur_shipyard";
	// tavern
	curTable.l3.pic = FRP_TAVERN;
	curTable.l3.tex = FRT_TAVERN;
	curTable.l3.location = "Falaise_de_fleur_tavern";
	// residence
	curTable.l4.pic = FRP_RESIDENCE;
	curTable.l4.tex = FRT_RESIDENCE;
	curTable.l4.location = "Falaise_de_fleur_townhall";

	makearef(curTable,objFastReloadTable.table.Muelle);
	// store
	curTable.l1.pic = FRP_STORE;
	curTable.l1.tex = FRT_STORE;
	curTable.l1.location = "Muelle_Store";
	// shipyard
	curTable.l2.pic = FRP_SHIPYARD;
	curTable.l2.tex = FRT_SHIPYARD;
	curTable.l2.location = "Muelle_Shipyard";
	// tavern
	curTable.l3.pic = FRP_TAVERN;
	curTable.l3.tex = FRT_TAVERN;
	curTable.l3.location = "Muelle_Tavern";
	// residence
	curTable.l4.pic = FRP_RESIDENCE;
	curTable.l4.tex = FRT_RESIDENCE;
	curTable.l4.location = "Muelle_Residence";

	makearef(curTable,objFastReloadTable.table.KhaelRoa); // нет ничего, кроме причала

	makearef(curTable,objFastReloadTable.table.Oxbay);
	// store
	curTable.l1.pic = FRP_STORE;
	curTable.l1.tex = FRT_STORE;
	curTable.l1.location = "Oxbay_Store";
	// shipyard
	curTable.l2.pic = FRP_SHIPYARD;
	curTable.l2.tex = FRT_SHIPYARD;
	curTable.l2.location = "Oxbay_Shipyard";
	// tavern
	curTable.l3.pic = FRP_TAVERN;
	curTable.l3.tex = FRT_TAVERN;
	curTable.l3.location = "Oxbay_Tavern";

	makearef(curTable,objFastReloadTable.table.Greenford);
	// store
	curTable.l1.pic = FRP_STORE;
	curTable.l1.tex = FRT_STORE;
	curTable.l1.location = "Greenford_Store";
	// shipyard
	curTable.l2.pic = FRP_SHIPYARD;
	curTable.l2.tex = FRT_SHIPYARD;
	curTable.l2.location = "Greenford_Shipyard";
	// tavern
	curTable.l3.pic = FRP_TAVERN;
	curTable.l3.tex = FRT_TAVERN;
	curTable.l3.location = "Greenford_tavern";

	makearef(curTable,objFastReloadTable.table.QC);
	// store
	curTable.l1.pic = FRP_STORE;
	curTable.l1.tex = FRT_STORE;
	curTable.l1.location = "QC_store";
	// tavern
	curTable.l3.pic = FRP_TAVERN;
	curTable.l3.tex = FRT_TAVERN;
	curTable.l3.location = "QC_tavern";
	// residence
	curTable.l4.pic = FRP_RESIDENCE;
	curTable.l4.tex = FRT_RESIDENCE;
	curTable.l4.location = "QC_Residence";

	makearef(curTable,objFastReloadTable.table.Redmond);
	// store
	curTable.l1.pic = FRP_STORE;
	curTable.l1.tex = FRT_STORE;
	curTable.l1.location = "Redmond_store";
	// shipyard
	curTable.l2.pic = FRP_SHIPYARD;
	curTable.l2.tex = FRT_SHIPYARD;
	curTable.l2.location = "Redmond_shipyard";
	// tavern
	curTable.l3.pic = FRP_TAVERN;
	curTable.l3.tex = FRT_TAVERN;
	curTable.l3.location = "Redmond_tavern";
	// residence
	curTable.l4.pic = FRP_RESIDENCE;
	curTable.l4.tex = FRT_RESIDENCE;
	curTable.l4.location = "Redmond_residence";
}

void InitTownTable()
{
	//loc.townsack
	objTownStateTable.towns.t1.name = "Conceicao";
	objTownStateTable.towns.t1.captured = false;
	objTownStateTable.towns.t1.crew.quantity = 200 + Rand(300);
	objTownStateTable.towns.t1.crew.morale = MORALE_NORMAL - 20 + Rand(40);
	objTownStateTable.towns.t1.crew.data.year = 1;
	objTownStateTable.towns.t1.crew.data.month = 1;
	objTownStateTable.towns.t1.crew.data.day = 1;

	objTownStateTable.towns.t2.name = "Douwesen";
	objTownStateTable.towns.t2.captured = false;
	objTownStateTable.towns.t2.crew.quantity = 200 + Rand(300);
	objTownStateTable.towns.t2.crew.morale = MORALE_NORMAL - 20 + Rand(40);
	objTownStateTable.towns.t2.crew.data.year = 1;
	objTownStateTable.towns.t2.crew.data.month = 1;
	objTownStateTable.towns.t2.crew.data.day = 1;

	objTownStateTable.towns.t3.name = "Falaise de Fleur";
	objTownStateTable.towns.t3.captured = false;
	objTownStateTable.towns.t3.crew.quantity = 200 + Rand(300);
	objTownStateTable.towns.t3.crew.morale = MORALE_NORMAL - 20 + Rand(40);
	objTownStateTable.towns.t3.crew.data.year = 1;
	objTownStateTable.towns.t3.crew.data.month = 1;
	objTownStateTable.towns.t3.crew.data.day = 1;

	objTownStateTable.towns.t4.name = "Isla Muelle";
	objTownStateTable.towns.t4.captured = false;
	objTownStateTable.towns.t4.crew.quantity = 200 + Rand(300);
	objTownStateTable.towns.t4.crew.morale = MORALE_NORMAL - 20 + Rand(40);
	objTownStateTable.towns.t4.crew.data.year = 1;
	objTownStateTable.towns.t4.crew.data.month = 1;
	objTownStateTable.towns.t4.crew.data.day = 1;

	objTownStateTable.towns.t5.name = "Oxbay";
	objTownStateTable.towns.t5.captured = false;
	objTownStateTable.towns.t5.crew.quantity = 200 + Rand(300);
	objTownStateTable.towns.t5.crew.morale = MORALE_NORMAL - 20 + Rand(40);
	objTownStateTable.towns.t5.crew.data.year = 1;
	objTownStateTable.towns.t5.crew.data.month = 1;
	objTownStateTable.towns.t5.crew.data.day = 1;

	objTownStateTable.towns.t6.name = "Greenford";
	objTownStateTable.towns.t6.captured = false;
	objTownStateTable.towns.t6.crew.quantity = 200 + Rand(300);
	objTownStateTable.towns.t6.crew.morale = MORALE_NORMAL - 20 + Rand(40);
	objTownStateTable.towns.t6.crew.data.year = 1;
	objTownStateTable.towns.t6.crew.data.month = 1;
	objTownStateTable.towns.t6.crew.data.day = 1;

	objTownStateTable.towns.t7.name = "Redmond";
	objTownStateTable.towns.t7.captured = false;
	objTownStateTable.towns.t7.crew.quantity = 200 + Rand(300);
	objTownStateTable.towns.t7.crew.morale = MORALE_NORMAL - 20 + Rand(40);
	objTownStateTable.towns.t7.crew.data.year = 1;
	objTownStateTable.towns.t7.crew.data.month = 1;
	objTownStateTable.towns.t7.crew.data.day = 1;
}

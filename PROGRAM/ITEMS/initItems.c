void InitItems()
{
	InitButtons();
	InitRandItems();
	ref itm;
	int n;

	for(n=0; n<ITEMS_QUANTITY; n++)
	{
		makeref(itm,Items[n]);
		itm.id = "item"+(n+1);
		itm.describe = "";
		itm.model = "";
		itm.shown = false;
		itm.startLocation = "";
		itm.startLocator = "";
		itm.useLocation = "";
		itm.useLocator = "";
		itm.describe = "";
	}
	n = 0;

//PICKUP GOLD

	makeref(itm,Items[n]);
	itm.id = "100gp";
	itm.name = "itmname_100gp";
	itm.model = "purse";
	itm.minlevel = 0;
	itm.rare = 0.3;
//	itm.shown = false;
	itm.gold = 100;
	n++;

	makeref(itm,Items[n]);
	itm.id = "250gp";
	itm.name = "itmname_250gp";
	itm.model = "pursem";
	itm.minlevel = 0;
	itm.rare = 0.2;
//	itm.shown = false;
	itm.gold = 250;
	n++;

	makeref(itm,Items[n]);
	itm.id = "500gp";
	itm.name = "itmname_100gp";
	itm.model = "pursel";
	itm.minlevel = 0;
	itm.rare = 0.1;
//	itm.shown = false;
	itm.gold = 500;
	n++;

//QUEST ITEMS

	//===================

	makeref(itm,Items[n]);
	itm.id = "gold";
	itm.name = "itmname_gold";
	itm.describe = "itmdescr_gold";
	itm.model = "";
	itm.picIndex = 2;
	itm.picTexture = "ITEMS_4";
//	itm.shown = 0;
	itm.price = 0;
	n++;

	makeref(itm,Items[n]);
	itm.id = "Chest";
	itm.name = "itmname_chest";
	itm.describe = "itmdescr_chest";
	itm.model = "";
	itm.picIndex = 1;
	itm.picTexture = "ITEMS_4";
//	itm.shown = 0;
	itm.price = 0;
	n++;

	makeref(itm,Items[n]);
	itm.id = "coins";
	itm.name = "itmname_coins";
	itm.describe = "itmdescr_coins";
	itm.model = "purse";
	itm.picIndex = 15;
	itm.picTexture = "ITEMS_4";
//	itm.shown = 0;
	itm.price = 0;
	n++;

	makeref(itm,Items[n]);
	itm.id = "gov_letter";
	itm.name = "itmname_gov_letter";
	itm.describe = "itmdescr_gov_letter";
	itm.model = "";
	itm.picIndex = 3;
	itm.picTexture = "ITEMS_4";
//	itm.shown = 0;
	itm.price = 0;
	n++;

	makeref(itm,Items[n]);
	itm.id = "idol";
	itm.name = "itmname_incas_idol";
	itm.describe = "itmdescr_incas_idol";
	itm.model = "stat1";
	itm.picIndex = 4;
	itm.picTexture = "ITEMS_4";
	itm.shown = 0;
	itm.useLocation = "Labirint_3";
	itm.useLocator = "button01";
	itm.price = 0;
	n++;

	makeref(itm,Items[n]);
	itm.id = "icollection";
	itm.name = "itmname_incas_collection";
	itm.describe = "itmdescr_incas_collection";
	itm.model = "";
	itm.picIndex = 5;
	itm.picTexture = "ITEMS_4";
//	itm.shown = 0;
	itm.price = 0;
	n++;

	makeref(itm,Items[n]);
	itm.id = "legend_piece";
	itm.name = "itmname_piece_of_legend";
	itm.describe = "itmdescr_piece_of_legend";
	itm.model = "";
	itm.picIndex = 6;
	itm.picTexture = "ITEMS_4";
//	itm.shown = 0;
	itm.price = 0;
	n++;

	makeref(itm,Items[n]);
	itm.id = "legend_notes";
	itm.name = "itmname_notes_of_legend";
	itm.describe = "itmdescr_notes_of_legend";
	itm.model = "";
	itm.picIndex = 7;
	itm.picTexture = "ITEMS_4";
//	itm.shown = 0;
	itm.price = 0;
	n++;

	makeref(itm,Items[n]);
	itm.id = "legend_copy";
	itm.name = "itmname_copyes_of_legend";
	itm.describe = "itmdescr_copyes_of_legend";
	itm.model = "";
	itm.picIndex = 7;
	itm.picTexture = "ITEMS_4";
//	itm.shown = 0;
	itm.price = 0;
	n++;

	makeref(itm,Items[n]);
	itm.id = "rheims_journal";
	itm.name = "itmname_rheims_journal";
	itm.describe = "itmdescr_rheims_journal";
	itm.model = "";
	itm.picIndex = 8;
	itm.picTexture = "ITEMS_4";
//	itm.shown = 0;
	itm.price = 0;
	n++;

	makeref(itm,Items[n]);
	itm.id = "domingues_fucked";
	itm.name = "itmname_compramat_to_domigues";
	itm.describe = "itmdescr_compramat_to_domigues";
	itm.model = "";
	itm.picIndex = 9;
	itm.picTexture = "ITEMS_4";
//	itm.shown = 0;
	itm.price = 0;
	n++;

	makeref(itm,Items[n]);
	itm.id = "rheims_letter";
	itm.name = "itmname_rheims_letter";
	itm.describe = "itmdescr_rheims_letter";
	itm.model = "";
	itm.picIndex = 10;
	itm.picTexture = "ITEMS_4";
//	itm.shown = 0;
	itm.price = 0;
	n++;

	makeref(itm,Items[n]);
	itm.id = "pornushka";
	itm.name = "itmname_love_letters_of_priest";
	itm.describe = "itmdescr_love_letters_of_priest";
	itm.model = "";
	itm.picIndex = 16;
	itm.picTexture = "ITEMS_4";
//	itm.shown = 0;
	itm.price = 0;
	n++;

	makeref(itm,Items[n]);
	itm.id = "animists_amulet";
	itm.name = "itmname_ANIMISTS_amulet";
	itm.describe = "itmdescr_ANIMISTS_amulet";
	itm.model = "";
	itm.picIndex = 12;
	itm.picTexture = "ITEMS_4";
//	itm.shown = 0;
	itm.price = 0;
	n++;

	makeref(itm,Items[n]);
	itm.id = "letter_to_domingues";
	itm.name = "itmname_letter_to_domingues";
	itm.describe = "itmdescr_letter_to_domingues";
	itm.model = "";
	itm.picIndex = 11;
	itm.picTexture = "ITEMS_4";
//	itm.shown = 0;
	itm.price = 0;
	n++;

	makeref(itm,Items[n]);
	itm.id = "letter_to_bernard";
	itm.name = "itmname_letter_to_bernard";
	itm.describe = "itmdescr_letter_to_bernard";
	itm.model = "";
	itm.picIndex = 11;
	itm.picTexture = "ITEMS_4";
//	itm.shown = 0;
	itm.price = 0;
	n++;

	makeref(itm,Items[n]);
	itm.id = "letter_prison";
	itm.name = "itmname_prison_letter";
	itm.describe = "itmdescr_prison_letter";
	itm.model = "";
	itm.picIndex = 10;
	itm.picTexture = "ITEMS_4";
//	itm.shown = 0;
	itm.price = 0;
	n++;
/*	makeref(itm,Items[n]);
	itm.id = STATUE1;
	itm.name = "itmname_statue1";
	itm.describe = "itmdescr_statue1";
	itm.model = "stat1";
	itm.picIndex = 15;
	itm.picTexture = "ITEMS_1";
	itm.shown = 1;
	itm.startLocation = "Labirint_3";
	itm.startLocator = "item1";
	itm.useLocation = "Labirint_3";
	itm.useLocator = "b_1";
	itm.price = 0;
	n++;

	makeref(itm,Items[n]);
	itm.id = STATUE2;
	itm.name = "itmname_statue2";
	itm.describe = "itmdescr_statue2";
	itm.model = "stat2";
	itm.picIndex = 15;
	itm.picTexture = "ITEMS_1";
	itm.shown = 1;
	itm.startLocation = "Labirint_3";
	itm.startLocator = "item2";
	itm.useLocation = "Labirint_3";
	itm.useLocator = "b_2";
	itm.price = 0;
	n++;

	makeref(itm,Items[n]);
	itm.id = STATUE3;
	itm.name = "itmname_statue3";
	itm.describe = "itmdescr_statue3";
	itm.model = "stat3";
	itm.picIndex = 15;
	itm.picTexture = "ITEMS_1";
	itm.shown = 1;
	itm.startLocation = "Labirint_3";
	itm.startLocator = "item3";
	itm.useLocation = "Labirint_3";
	itm.useLocator = "b_3";
	itm.price = 0;
	n++;
*/
	makeref(itm,Items[n]);
	itm.id = "Massoni_papers";
	itm.name = "itmname_massoni_papers";
	itm.describe = "itmdescr_massoni_papers";
	itm.model = "";
	itm.picIndex = 13;
	itm.picTexture = "ITEMS_4";
//	itm.shown = 0;
	itm.price = 0;
	n++;

	makeref(itm,Items[n]);
	itm.id = "artefact";
	itm.name = "itmname_artefact";
	itm.describe = "itmdescr_artefact";
	itm.model = "";
	itm.quest = "onuseartefact";
	itm.quest.tex = "questcommands";
	itm.quest.pic = 0;
	itm.picIndex = 16;
	itm.picTexture = "ITEMS_1";
//	itm.shown = 0;
	itm.price = 0;
	n++;

	//==========================

	makeref(itm,Items[n]);
	itm.id = "Story_Gramota";
	itm.name = "itmname_story_gramota";
	itm.describe = "itmdescr_story_gramota";
	itm.model = "";
	itm.picIndex = 3;
	itm.picTexture = "ITEMS_4";
//	itm.shown = false;
	itm.price = 0;
	n++;


//WEAPONS

	makeref(itm,Items[n]);
	itm.id = "blade1";
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "itmname_blade1";
	itm.describe = "itmdescr_blade1";
	itm.model = "blade1";
	itm.folder = "items";
	itm.picIndex = 11;
	itm.picTexture = "ITEMS_6";
	itm.price = 500;
	itm.dmg_min = 10.0;
	itm.dmg_max = 15.0;
	itm.piercing = 10;
	itm.minlevel = 0;
	itm.rare = 0.1;
	itm.block = 10;
	itm.param.time = 0.05;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
	n++;

	makeref(itm,Items[n]);
	itm.id = "blade2";
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "itmname_blade2";
	itm.describe = "itmdescr_blade2";
	itm.folder = "items";
	itm.model = "blade2";
	itm.picIndex = 10;
	itm.picTexture = "ITEMS_6";
	itm.price = 500;
	itm.dmg_min = 10.0;
	itm.dmg_max = 12.0;
	itm.piercing = 15;
	itm.minlevel = 0;
	itm.rare = 0.1;
	itm.block = 10;
	itm.param.time = 0.1;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
	n++;

	makeref(itm,Items[n]);
	itm.id = "blade3";
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "itmname_blade3";
	itm.describe = "itmdescr_blade3";
	itm.folder = "items";
	itm.model = "blade3";
	itm.picIndex = 8;
	itm.picTexture = "ITEMS_6";
	itm.price = 500;
	itm.dmg_min = 12.0;
	itm.dmg_max = 16.0;
	itm.piercing = 10;
	itm.minlevel = 0;
	itm.rare = 0.1;
	itm.block = 5;
	itm.param.time = 0.1;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
	n++;

	makeref(itm,Items[n]);
	itm.id = "blade4";
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "itmname_blade4";
	itm.describe = "itmdescr_blade4";
	itm.folder = "items";
	itm.model = "blade4";
	itm.picIndex = 7;
	itm.picTexture = "ITEMS_6";
	itm.price = 500;
	itm.dmg_min = 14.0;
	itm.dmg_max = 19.0;
	itm.piercing = 10;
	itm.minlevel = 0;
	itm.rare = 0.1;
	itm.block = 0;
	itm.param.time = 0.1;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
	n++;

	makeref(itm,Items[n]);
	itm.id = "blade5";
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "itmname_blade5";
	itm.describe = "itmdescr_blade5";
	itm.folder = "items";
	itm.model = "blade5";
	itm.picIndex = 9;
	itm.picTexture = "ITEMS_6";
	itm.price = 250;
	itm.dmg_min = 6.0;
	itm.dmg_max = 10.0;
	itm.piercing = 25;
	itm.minlevel = 0;
	itm.rare = 0.1;
	itm.block = 0;
	itm.param.time = 0.1;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
	n++;

	makeref(itm,Items[n]);
	itm.id = "blade6";
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "itmname_blade6";
	itm.describe = "itmdescr_blade6";
	itm.folder = "items";
	itm.model = "blade6";
	itm.picIndex = 12;
	itm.picTexture = "ITEMS_6";
	itm.price = 1000;
	itm.dmg_min = 13.0;
	itm.dmg_max = 18.0;
	itm.piercing = 15;
	itm.minlevel = 2;
	itm.rare = 0.1;
	itm.block = 15;
	itm.param.time = 0.1;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
	n++;

	makeref(itm,Items[n]);
	itm.id = "blade7";
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "itmname_blade7";
	itm.describe = "itmdescr_blade7";
	itm.folder = "items";
	itm.model = "blade7";
	itm.picIndex = 13;
	itm.picTexture = "ITEMS_6";
	itm.price = 1000;
	itm.dmg_min = 15.0;
	itm.dmg_max = 20.0;
	itm.piercing = 15;
	itm.minlevel = 2;
	itm.rare = 0.1;
	itm.block = 5;
	itm.param.time = 0.1;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
	n++;

	makeref(itm,Items[n]);
	itm.id = "blade8";
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "itmname_blade8";
	itm.describe = "itmdescr_blade8";
	itm.folder = "items";
	itm.model = "blade8";
	itm.picIndex = 1;
	itm.picTexture = "ITEMS_3";
	itm.price = 1000;
	itm.dmg_min = 18.0;
	itm.dmg_max = 23.0;
	itm.piercing = 15;
	itm.minlevel = 2;
	itm.rare = 0.1;
	itm.block = 10;
	itm.param.time = 0.1;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
	n++;

	makeref(itm,Items[n]);
	itm.id = "blade9";
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "itmname_blade9";
	itm.describe = "itmdescr_blade9";
	itm.folder = "items";
	itm.model = "blade9";
	itm.picIndex = 2;
	itm.picTexture = "ITEMS_3";
	itm.price = 1000;
	itm.dmg_min = 13.0;
	itm.dmg_max = 15.0;
	itm.piercing = 20;
	itm.minlevel = 2;
	itm.rare = 0.1;
	itm.block = 15;
	itm.param.time = 0.1;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
	n++;

	makeref(itm,Items[n]);
	itm.id = "blade10";
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "itmname_blade10";
	itm.describe = "itmdescr_blade10";
	itm.folder = "items";
	itm.model = "blade10";
	itm.picIndex = 3;
	itm.picTexture = "ITEMS_3";
	itm.price = 1500;
	itm.dmg_min = 21.0;
	itm.dmg_max = 26.0;
	itm.piercing = 20;
	itm.minlevel = 4;
	itm.rare = 0.1;
	itm.block = 10;
	itm.param.time = 0.1;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
	n++;

	makeref(itm,Items[n]);
	itm.id = "blade11";
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "itmname_blade11";
	itm.describe = "itmdescr_blade11";
	itm.folder = "items";
	itm.model = "blade11";
	itm.picIndex = 4;
	itm.picTexture = "ITEMS_3";
	itm.price = 1500;
	itm.dmg_min = 18.0;
	itm.dmg_max = 22.0;
	itm.piercing = 20;
	itm.minlevel = 4;
	itm.rare = 0.1;
	itm.block = 15;
	itm.param.time = 0.1;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
	n++;

	makeref(itm,Items[n]);
	itm.id = "blade12";
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "itmname_blade12";
	itm.describe = "itmdescr_blade12";
	itm.folder = "items";
	itm.model = "blade12";
	itm.picIndex = 5;
	itm.picTexture = "ITEMS_3";
	itm.price = 1500;
	itm.dmg_min = 16.0;
	itm.dmg_max = 21.0;
	itm.piercing = 20;
	itm.minlevel = 4;
	itm.rare = 0.1;
	itm.block = 20;
	itm.param.time = 0.1;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
	n++;

	makeref(itm,Items[n]);
	itm.id = "blade13";
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "itmname_blade13";
	itm.describe = "itmdescr_blade13";
	itm.folder = "items";
	itm.model = "blade13";
	itm.picIndex = 6;
	itm.picTexture = "ITEMS_3";
	itm.price = 1500;
	itm.dmg_min = 16.0;
	itm.dmg_max = 18.0;
	itm.piercing = 25;
	itm.minlevel = 4;
	itm.rare = 0.1;
	itm.block = 20;
	itm.param.time = 0.1;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
	n++;

	makeref(itm,Items[n]);
	itm.id = "blade14";
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "itmname_blade14";
	itm.describe = "itmdescr_blade14";
	itm.folder = "items";
	itm.model = "blade14";
	itm.picIndex = 7;
	itm.picTexture = "ITEMS_3";
	itm.price = 10000;
	itm.dmg_min = 15.0;
	itm.dmg_max = 20.0;
	itm.piercing = 20;
	itm.minlevel = 10;
	itm.rare = 0.1;
	itm.block = 90;
	itm.param.time = 0.1;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
	n++;

	makeref(itm,Items[n]);
	itm.id = "blade15";
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "itmname_blade15";
	itm.describe = "itmdescr_blade15";
	itm.folder = "items";
	itm.model = "blade15";
	itm.picIndex = 8;
	itm.picTexture = "ITEMS_3";
	itm.price = 3000;
	itm.dmg_min = 19.0;
	itm.dmg_max = 21.0;
	itm.piercing = 30;
	itm.minlevel = 6;
	itm.rare = 0.1;
	itm.block = 25;
	itm.param.time = 0.1;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
	n++;

	makeref(itm,Items[n]);
	itm.id = "blade16";
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "itmname_blade16";
	itm.describe = "itmdescr_blade16";
	itm.folder = "items";
	itm.model = "blade16";
	itm.picIndex = 9;
	itm.picTexture = "ITEMS_3";
	itm.price = 3000;
	itm.dmg_min = 21.0;
	itm.dmg_max = 25.0;
	itm.piercing = 25;
	itm.minlevel = 6;
	itm.rare = 0.1;
	itm.block = 20;
	itm.param.time = 0.1;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
	n++;

	makeref(itm,Items[n]);
	itm.id = "blade17";
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "itmname_blade17";
	itm.describe = "itmdescr_blade17";
	itm.folder = "items";
	itm.model = "blade17";
	itm.picIndex = 10;
	itm.picTexture = "ITEMS_3";
	itm.price = 5000;
	itm.dmg_min = 25.0;
	itm.dmg_max = 30.0;
	itm.piercing = 25;
	itm.minlevel = 8;
	itm.rare = 0.1;
	itm.block = 10;
	itm.param.time = 0.1;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
	n++;

	makeref(itm,Items[n]);
	itm.id = "blade18";
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "itmname_blade18";
	itm.describe = "itmdescr_blade18";
	itm.folder = "items";
	itm.model = "blade18";
	itm.picIndex = 11;
	itm.picTexture = "ITEMS_3";
	itm.price = 3000;
	itm.dmg_min = 19.0;
	itm.dmg_max = 24.0;
	itm.piercing = 25;
	itm.minlevel = 6;
	itm.rare = 0.1;
	itm.block = 25;
	itm.param.time = 0.1;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
	n++;

	makeref(itm,Items[n]);
	itm.id = "blade19";
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "itmname_blade19";
	itm.describe = "itmdescr_blade19";
	itm.folder = "items";
	itm.model = "blade19";
	itm.picIndex = 12;
	itm.picTexture = "ITEMS_3";
	itm.price = 5000;
	itm.dmg_min = 10.0;
	itm.dmg_max = 30.0;
	itm.piercing = 10;
	itm.minlevel = 8;
	itm.rare = 0.1;
	itm.block = 40;
	itm.param.time = 0.1;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
	n++;

	makeref(itm,Items[n]);
	itm.id = "blade20";
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "itmname_blade20";
	itm.describe = "itmdescr_blade20";
	itm.folder = "items";
	itm.model = "blade20";
	itm.picIndex = 13;
	itm.picTexture = "ITEMS_3";
	itm.price = 5000;
	itm.dmg_min = 22.0;
	itm.dmg_max = 27.0;
	itm.piercing = 30;
	itm.minlevel = 8;
	itm.rare = 0.1;
	itm.block = 30;
	itm.param.time = 0.1;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
	n++;

	makeref(itm,Items[n]);
	itm.id = "blade21";
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "itmname_blade21";
	itm.describe = "itmdescr_blade21";
	itm.folder = "items";
	itm.model = "blade21";
	itm.picIndex = 14;
	itm.picTexture = "ITEMS_3";
	itm.price = 3000;
	itm.dmg_min = 24.0;
	itm.dmg_max = 29.0;
	itm.piercing = 25;
	itm.minlevel = 6;
	itm.rare = 0.1;
	itm.block = 15;
	itm.param.time = 0.1;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
	n++;

	makeref(itm,Items[n]);
	itm.id = "blade22";
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "itmname_blade22";
	itm.describe = "itmdescr_blade22";
	itm.folder = "items";
	itm.model = "blade22";
	itm.picIndex = 15;
	itm.picTexture = "ITEMS_3";
	itm.price = 10000;
	itm.dmg_min = 10.0;
	itm.dmg_max = 20.0;
	itm.piercing = 100;
	itm.minlevel = 10;
	itm.rare = 0.1;
	itm.block = 20;
	itm.param.time = 0.1;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
	n++;

	makeref(itm,Items[n]);
	itm.id = "blade23";
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "itmname_blade23";
	itm.describe = "itmdescr_blade23";
	itm.folder = "items";
	itm.model = "blade23";
	itm.picIndex = 16;
	itm.picTexture = "ITEMS_3";
	itm.price = 10000;
	itm.dmg_min = 30.0;
	itm.dmg_max = 50.0;
	itm.piercing = 0;
	itm.minlevel = 10;
	itm.rare = 0.1;
	itm.block = 20;
	itm.param.time = 0.1;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
	n++;

//GUNS

	makeref(itm,Items[n]);
	itm.id = "pistol1";
	itm.groupID = GUN_ITEM_TYPE;
	itm.name = "itmname_pistol1";
	itm.describe = "itmdescr_pistol1";
	itm.folder = "items";
	itm.model = "pistol1";
	itm.picIndex = 1;
	itm.picTexture = "ITEMS_6";
	itm.price = 1500;
	itm.chargeQ = 1;
	itm.chargespeed = 8;
	itm.dmg_min = 30.0;
	itm.dmg_max = 45.0;
	itm.accuracy = 30;
	itm.minlevel = 2;
	itm.rare = 0.1;
	n++;

	makeref(itm,Items[n]);
	itm.id = "pistol2";
	itm.groupID = GUN_ITEM_TYPE;
	itm.name = "itmname_pistol2";
	itm.describe = "itmdescr_pistol2";
	itm.folder = "items";
	itm.model = "pistol2";
	itm.picIndex = 2;
	itm.picTexture = "ITEMS_6";
	itm.price = 2000;
	itm.chargeQ = 1;
	itm.chargespeed = 12;
	itm.dmg_min = 40.0;
	itm.dmg_max = 55.0;
	itm.accuracy = 50;
	itm.minlevel = 3;
	itm.rare = 0.1;
	n++;

	makeref(itm,Items[n]);
	itm.id = "pistol3";
	itm.groupID = GUN_ITEM_TYPE;
	itm.name = "itmname_pistol3";
	itm.describe = "itmdescr_pistol3";
	itm.folder = "items";
	itm.model = "pistol3";
	itm.picIndex = 3;
	itm.picTexture = "ITEMS_6";
	itm.price = 4000;
	itm.chargeQ = 1;
	itm.chargespeed = 20;
	itm.dmg_min = 70.0;
	itm.dmg_max = 90.0;
	itm.accuracy = 20;
	itm.minlevel = 5;
	itm.rare = 0.1;
	n++;

	makeref(itm,Items[n]);
	itm.id = "pistol4";
	itm.groupID = GUN_ITEM_TYPE;
	itm.name = "itmname_pistol4";
	itm.describe = "itmdescr_pistol4";
	itm.folder = "items";
	itm.model = "pistol4";
	itm.picIndex = 4;
	itm.picTexture = "ITEMS_6";
	itm.shown = 1;
	itm.price = 10000;
	itm.chargeQ = 4;
	itm.chargespeed = 24;
	itm.dmg_min = 35.0;
	itm.dmg_max = 45.0;
	itm.accuracy = 50;
	itm.minlevel = 10;
	itm.rare = 0.1;
	n++;


	makeref(itm,Items[n]);
	itm.id = "pistol5";
	itm.groupID = GUN_ITEM_TYPE;
	itm.name = "itmname_pistol5";
	itm.describe = "itmdescr_pistol5";
	itm.folder = "items";
	itm.model = "pistol5";
	itm.picIndex = 5;
	itm.picTexture = "ITEMS_6";
	itm.price = 7500;
	itm.chargeQ = 1;
	itm.chargespeed = 16;
	itm.dmg_min = 60.0;
	itm.dmg_max = 80.0;
	itm.accuracy = 70;
	itm.minlevel = 7;
	itm.rare = 0.1;
	n++;


	makeref(itm,Items[n]);
	itm.id = "pistol6";
	itm.groupID = GUN_ITEM_TYPE;
	itm.name = "itmname_pistol6";
	itm.describe = "itmdescr_pistol6";
	itm.folder = "items";
	itm.model = "pistol6";
	itm.picIndex = 6;
	itm.picTexture = "ITEMS_6";
	itm.price = 10000;
	itm.chargeQ = 2;
	itm.chargespeed = 20;
	itm.dmg_min = 45.0;
	itm.dmg_max = 55.0;
	itm.accuracy = 60;
	itm.minlevel = 10;
	itm.rare = 0.1;
	n++;

//SPYGLASSES

	makeref(itm,Items[n]);
	itm.id = "spyglass1";
	itm.groupID = SPYGLASS_ITEM_TYPE;
	itm.name = "itmname_spyglass1";
	itm.describe = "itmdescr_spyglass1";
	itm.picIndex = 14;
	itm.picTexture = "ITEMS_6";
	itm.price = 300;
	itm.folder = "items";
	itm.scope.texture = "eye_BadTub.tga";
	itm.scope.zoom = 2.5;
	itm.scope.time_activate = 500;
	itm.scope.time_update = 150;
	itm.scope.show.nation = 1;
	itm.scope.show.cannons = 0;
	itm.scope.show.ship_name = 1;
	itm.scope.show.ship_type = 1;
	itm.scope.show.hull = 0;
	itm.scope.show.sail = 0;
	itm.scope.show.crew = 0;
	itm.scope.show.speed = 0;
	itm.scope.show.charge = 0;
	itm.minlevel = 1;
	itm.rare = 0.1;
	n++;

	makeref(itm,Items[n]);
	itm.id = "spyglass2";
	itm.groupID = SPYGLASS_ITEM_TYPE;
	itm.name = "itmname_spyglass2";
	itm.describe = "itmdescr_spyglass2";
	itm.picIndex = 15;
	itm.picTexture = "ITEMS_6";
	itm.price = 800;
	itm.folder = "items";
	itm.scope.texture = "eye_CommonTub.tga";
	itm.scope.zoom = 4.0;
	itm.scope.time_activate = 500;
	itm.scope.time_update = 150;
	itm.scope.show.nation = 1;
	itm.scope.show.cannons = 0;
	itm.scope.show.ship_name = 1;
	itm.scope.show.ship_type = 1;
	itm.scope.show.hull = 1;
	itm.scope.show.sail = 1;
	itm.scope.show.crew = 0;
	itm.scope.show.speed = 0;
	itm.scope.show.charge = 0;
	itm.minlevel = 2;
	itm.rare = 0.07;
	n++;

	makeref(itm,Items[n]);
	itm.id = "spyglass3";
	itm.groupID = SPYGLASS_ITEM_TYPE;
	itm.name = "itmname_spyglass3";
	itm.describe = "itmdescr_spyglass3";
	itm.picIndex = 16;
	itm.picTexture = "ITEMS_6";
	itm.price = 3000;
	itm.folder = "items";
	itm.scope.texture = "eye_GoodTub.tga";
	itm.scope.zoom = 5.5;
	itm.scope.time_activate = 500;
	itm.scope.time_update = 150;
	itm.scope.show.nation = 1;
	itm.scope.show.cannons = 1;
	itm.scope.show.ship_name = 1;
	itm.scope.show.ship_type = 1;
	itm.scope.show.hull = 1;
	itm.scope.show.sail = 1;
	itm.scope.show.crew = 1;
	itm.scope.show.speed = 0;
	itm.scope.show.charge = 0;
	itm.minlevel = 5;
	itm.rare = 0.05;
	n++;

	makeref(itm,Items[n]);
	itm.id = "spyglass4";
	itm.groupID = SPYGLASS_ITEM_TYPE;
	itm.name = "itmname_spyglass4";
	itm.describe = "itmdescr_spyglass4";
	itm.picIndex = 14;
	itm.picTexture = "ITEMS_1";
	itm.folder = "items";
	itm.model = "spyglass4";
	itm.price = 5000;
	itm.scope.texture = "eye_BestTub.tga";
	itm.scope.zoom = 7.0;
	itm.scope.time_activate = 500;
	itm.scope.time_update = 150;
	itm.scope.show.nation = 1;
	itm.scope.show.cannons = 1;
	itm.scope.show.ship_name = 1;
	itm.scope.show.ship_type = 1;
	itm.scope.show.hull = 1;
	itm.scope.show.sail = 1;
	itm.scope.show.crew = 1;
	itm.scope.show.speed = 1;
	itm.scope.show.charge = 1;
	itm.minlevel = 7;
	itm.rare = 0.01;
	n++;

//POTIONS

	makeref(itm,Items[n]);
	itm.id = "potion1";
	itm.name = "itmname_potion1";
	itm.describe = "itmdescr_potion1";
	itm.model = "potion";
	itm.picIndex = 7;
	itm.picTexture = "ITEMS_1";
//	itm.shown = false;
	itm.price = 300;
	itm.potion.pic = 1;
	itm.potion.tex = 1; // battle_interface\useditems1.tga
	itm.potion.health = 40.0;
	itm.minlevel = 0;
	itm.rare = 0.3;
	n++;

	makeref(itm,Items[n]);
	itm.id = "potion2";
	itm.name = "itmname_potion2";
	itm.describe = "itmdescr_potion2";
	itm.model = "potionbig";
	itm.picIndex = 1;
	itm.picTexture = "ITEMS_1";
//	itm.shown = false;
	itm.price = 850;
	itm.potion.pic = 0;
	itm.potion.tex = 1; // battle_interface\useditems1.tga
	itm.potion.health = 150.0;
	itm.minlevel = 3;
	itm.rare = 0.1;
	n++;

	makeref(itm,Items[n]);
	itm.id = "potion3";
	itm.name = "itmname_potion3";
	itm.describe = "itmdescr_potion3";
	itm.model = "Antidote";
	itm.picIndex = 5;
	itm.picTexture = "ITEMS_1";
//	itm.shown = false;
	itm.price = 450;
	itm.potion.pic = 0;
	itm.potion.tex = 2; // battle_interface\useditems2.tga
	itm.potion.antidote = true;
	itm.minlevel = 3;
	itm.rare = 0.1;
	n++;

	makeref(itm,Items[n]);
	itm.id = "potion4";
	itm.name = "itmname_potion4";
	itm.describe = "itmdescr_potion4";
	itm.model = "balsam";
	itm.picIndex = 4;
	itm.picTexture = "ITEMS_1";
//	itm.shown = false;
	itm.price = 1000;
	itm.potion.pic = 3;
	itm.potion.tex = 1; // battle_interface\useditems1.tga
	itm.potion.health = 60.0;
	itm.potion.antidote = true;
	itm.minlevel = 3;
	itm.rare = 0.1;
	n++;

//JEWELRY

	makeref(itm,Items[n]);
	itm.id = "jewelry1";
	itm.name = "itmname_jewelry1";
	itm.describe = "itmdescr_jewelry1";
	itm.model = "sapphire";
	itm.picIndex = 1;
	itm.picTexture = "ITEMS_2";
//	itm.shown = false;
	itm.price = 800;
	itm.minlevel = 0;
	itm.rare = 0.1;

	n++;

	makeref(itm,Items[n]);
	itm.id = "jewelry2";
	itm.name = "itmname_jewelry2";
	itm.describe = "itmdescr_jewelry2";
	itm.model = "diamond";
	itm.picIndex = 2;
	itm.picTexture = "ITEMS_2";
//	itm.shown = false;
	itm.price = 2000;
	itm.minlevel = 1;
	itm.rare = 0.05;

	n++;

	makeref(itm,Items[n]);
	itm.id = "jewelry3";
	itm.name = "itmname_jewelry3";
	itm.describe = "itmdescr_jewelry3";
	itm.model = "ruby";
	itm.picIndex = 3;
	itm.picTexture = "ITEMS_2";
//	itm.shown = false;
	itm.price = 1000;
	itm.minlevel = 0;
	itm.rare = 0.1;
	n++;

	makeref(itm,Items[n]);
	itm.id = "jewelry4";
	itm.name = "itmname_jewelry4";
	itm.describe = "itmdescr_jewelry4";
	itm.model = "emerald";
	itm.picIndex = 4;
	itm.picTexture = "ITEMS_2";
//	itm.shown = false;
	itm.price = 1500;
	itm.minlevel = 0;
	itm.rare = 0.1;
	n++;

	makeref(itm,Items[n]);
	itm.id = "jewelry5";
	itm.name = "itmname_jewelry5";
	itm.describe = "itmdescr_jewelry5";
	itm.model = "";
	itm.picIndex = 5;
	itm.picTexture = "ITEMS_2";
//	itm.shown = false;
	itm.price = 2000;
	itm.minlevel = 1;
	itm.rare = 0.05;
	n++;

	makeref(itm,Items[n]);
	itm.id = "jewelry6";
	itm.name = "itmname_jewelry6";
	itm.describe = "itmdescr_jewelry6";
	itm.model = "";
	itm.picIndex = 6;
	itm.picTexture = "ITEMS_2";
//	itm.shown = false;
	itm.price = 1000;
	itm.minlevel = 0;
	itm.rare = 0.1;
	n++;

	makeref(itm,Items[n]);
	itm.id = "jewelry7";
	itm.name = "itmname_jewelry7";
	itm.describe = "itmdescr_jewelry7";
	itm.model = "";
	itm.picIndex = 7;
	itm.picTexture = "ITEMS_2";
//	itm.shown = false;
	itm.price = 1250;
	itm.minlevel = 0;
	itm.rare = 0.1;
	n++;

	makeref(itm,Items[n]);
	itm.id = "jewelry8";
	itm.name = "itmname_jewelry8";
	itm.describe = "itmdescr_jewelry8";
	itm.model = "";
	itm.picIndex = 8;
	itm.picTexture = "ITEMS_2";
//	itm.shown = false;
	itm.price = 500;
	itm.minlevel = 0;
	itm.rare = 0.2;
	n++;

	makeref(itm,Items[n]);
	itm.id = "jewelry9";
	itm.name = "itmname_jewelry9";
	itm.describe = "itmdescr_jewelry9";
	itm.model = "";
	itm.picIndex = 9;
	itm.picTexture = "ITEMS_2";
//	itm.shown = false;
	itm.price = 400;
	itm.minlevel = 0;
	itm.rare = 0.2;
	n++;

	makeref(itm,Items[n]);
	itm.id = "jewelry10";
	itm.name = "itmname_jewelry10";
	itm.describe = "itmdescr_jewelry10";
	itm.model = "";
	itm.picIndex = 10;
	itm.picTexture = "ITEMS_2";
//	itm.shown = false;
	itm.price = 2000;
	itm.minlevel = 1;
	itm.rare = 0.1;
	n++;

	makeref(itm,Items[n]);
	itm.id = "jewelry11";
	itm.name = "itmname_jewelry11";
	itm.describe = "itmdescr_jewelry11";
	itm.model = "pearlbig";
	itm.picIndex = 11;
	itm.picTexture = "ITEMS_2";
//	itm.shown = false;
	itm.price = 1000;
	itm.minlevel = 0;
	itm.rare = 0.1;
	n++;

	makeref(itm,Items[n]);
	itm.id = "jewelry12";
	itm.name = "itmname_jewelry12";
	itm.describe = "itmdescr_jewelry12";
	itm.model = "pearlsmall";
	itm.picIndex = 12;
	itm.picTexture = "ITEMS_2";
//	itm.shown = false;
	itm.price = 500;
	itm.minlevel = 0;
	itm.rare = 0.2;
	n++;

	makeref(itm,Items[n]);
	itm.id = "jewelry13";
	itm.name = "itmname_jewelry13";
	itm.describe = "itmdescr_jewelry13";
	itm.model = "";
	itm.picIndex = 13;
	itm.picTexture = "ITEMS_2";
//	itm.shown = false;
	itm.price = 2000;
	itm.minlevel = 1;
	itm.rare = 0.1;
	n++;

	makeref(itm,Items[n]);
	itm.id = "jewelry14";
	itm.name = "itmname_jewelry14";
	itm.describe = "itmdescr_jewelry14";
	itm.model = "";
	itm.picIndex = 14;
	itm.picTexture = "ITEMS_2";
//	itm.shown = false;
	itm.price = 1000;
	itm.minlevel = 2;
	itm.rare = 0.05;
	n++;

	makeref(itm,Items[n]);
	itm.id = "jewelry15";
	itm.name = "itmname_jewelry15";
	itm.describe = "itmdescr_jewelry15";
	itm.model = "";
	itm.picIndex = 15;
	itm.picTexture = "ITEMS_2";
//	itm.shown = false;
	itm.price = 1000;
	itm.minlevel = 2;
	itm.rare = 0.05;
	n++;

	makeref(itm,Items[n]);
	itm.id = "jewelry16";
	itm.name = "itmname_jewelry16";
	itm.describe = "itmdescr_jewelry16";
	itm.model = "";
	itm.picIndex = 16;
	itm.picTexture = "ITEMS_2";
//	itm.shown = false;
	itm.price = 500;
	itm.minlevel = 2;
	itm.rare = 0.05;
	n++;

//INDIAN TRINKETS

	makeref(itm,Items[n]);
	itm.id = "indian1";
	itm.name = "itmname_indian1";
	itm.describe = "itmdescr_indian1";
	itm.model = "";
	itm.picIndex = 1;
	itm.picTexture = "ITEMS_5";
//	itm.shown = false;
	itm.price = 100;
	itm.minlevel = 3;
	itm.rare = 0.03;
	n++;

	makeref(itm,Items[n]);
	itm.id = "indian2";
	itm.name = "itmname_indian2";
	itm.describe = "itmdescr_indian2";
	itm.model = "";
	itm.picIndex = 2;
	itm.picTexture = "ITEMS_5";
//	itm.shown = false;
	itm.price = 300;
	itm.minlevel = 1;
	itm.rare = 0.05;
	n++;

	makeref(itm,Items[n]);
	itm.id = "indian3";
	itm.name = "itmname_indian3";
	itm.describe = "itmdescr_indian3";
	itm.model = "";
	itm.picIndex = 3;
	itm.picTexture = "ITEMS_5";
//	itm.shown = false;
	itm.price = 100;
	itm.minlevel = 0;
	itm.rare = 0.1;
	n++;

	makeref(itm,Items[n]);
	itm.id = "indian4";
	itm.name = "itmname_indian4";
	itm.describe = "itmdescr_indian4";
	itm.model = "";
	itm.picIndex = 4;
	itm.picTexture = "ITEMS_5";
//	itm.shown = false;
	itm.price = 50;
	itm.minlevel = 0;
	itm.rare = 0.2;
	n++;

	makeref(itm,Items[n]);
	itm.id = "indian5";
	itm.name = "itmname_indian5";
	itm.describe = "itmdescr_indian5";
	itm.model = "";
	itm.picIndex = 5;
	itm.picTexture = "ITEMS_5";
//	itm.shown = false;
	itm.price = 600;
	itm.minlevel = 3;
	itm.rare = 0.05;
	n++;

	makeref(itm,Items[n]);
	itm.id = "indian6";
	itm.name = "itmname_indian6";
	itm.describe = "itmdescr_indian6";
	itm.model = "";
	itm.picIndex = 6;
	itm.picTexture = "ITEMS_5";
//	itm.shown = false;
	itm.price = 400;
	itm.minlevel = 2;
	itm.rare = 0.05;
	n++;

	makeref(itm,Items[n]);
	itm.id = "indian7";
	itm.name = "itmname_indian7";
	itm.describe = "itmdescr_indian7";
	itm.model = "";
	itm.picIndex = 7;
	itm.picTexture = "ITEMS_5";
//	itm.shown = false;
	itm.price = 120;
	itm.minlevel = 4;
	itm.rare = 0.03;
	n++;

	makeref(itm,Items[n]);
	itm.id = "indian8";
	itm.name = "itmname_indian8";
	itm.describe = "itmdescr_indian8";
	itm.model = "";
	itm.picIndex = 8;
	itm.picTexture = "ITEMS_5";
//	itm.shown = false;
	itm.price = 140;
	itm.minlevel = 4;
	itm.rare = 0.03;
	n++;

	makeref(itm,Items[n]);
	itm.id = "indian9";
	itm.name = "itmname_indian9";
	itm.describe = "itmdescr_indian9";
	itm.model = "";
	itm.picIndex = 9;
	itm.picTexture = "ITEMS_5";
//	itm.shown = false;
	itm.price = 160;
	itm.minlevel = 5;
	itm.rare = 0.03;
	n++;

	makeref(itm,Items[n]);
	itm.id = "indian10";
	itm.name = "itmname_indian10";
	itm.describe = "itmdescr_indian10";
	itm.model = "";
	itm.picIndex = 10;
	itm.picTexture = "ITEMS_5";
//	itm.shown = false;
	itm.price = 270;
	itm.minlevel = 7;
	itm.rare = 0.03;
	n++;

	makeref(itm,Items[n]);
	itm.id = "indian11";
	itm.name = "itmname_indian11";
	itm.describe = "itmdescr_indian11";
	itm.model = "";
	itm.picIndex = 11;
	itm.picTexture = "ITEMS_5";
//	itm.shown = false;
	itm.price = 150;
	itm.minlevel = 5;
	itm.rare = 0.03;
	n++;

	makeref(itm,Items[n]);
	itm.id = "indian12";
	itm.name = "itmname_indian12";
	itm.describe = "itmdescr_indian12";
	itm.model = "";
	itm.picIndex = 12;
	itm.picTexture = "ITEMS_5";
//	itm.shown = false;
	itm.price = 380;
	itm.minlevel = 9;
	itm.rare = 0.01;
	n++;

	makeref(itm,Items[n]);
	itm.id = "indian13";
	itm.name = "itmname_indian13";
	itm.describe = "itmdescr_indian13";
	itm.model = "";
	itm.picIndex = 13;
	itm.picTexture = "ITEMS_5";
//	itm.shown = false;
	itm.price = 200;
	itm.minlevel = 1;
	itm.rare = 0.1;
	n++;

	makeref(itm,Items[n]);
	itm.id = "indian14";
	itm.name = "itmname_indian14";
	itm.describe = "itmdescr_indian14";
	itm.model = "";
	itm.picIndex = 14;
	itm.picTexture = "ITEMS_5";
//	itm.shown = false;
	itm.price = 490;
	itm.minlevel = 10;
	itm.rare = 0.005;
	n++;

	makeref(itm,Items[n]);
	itm.id = "indian15";
	itm.name = "itmname_indian15";
	itm.describe = "itmdescr_indian15";
	itm.model = "";
	itm.picIndex = 15;
	itm.picTexture = "ITEMS_5";
//	itm.shown = false;
	itm.price = 600;
	itm.minlevel = 3;
	itm.rare = 0.05;
	n++;

	makeref(itm,Items[n]);
	itm.id = "indian16";
	itm.name = "itmname_indian16";
	itm.describe = "itmdescr_indian16";
	itm.model = "";
	itm.picIndex = 16;
	itm.picTexture = "ITEMS_5";
//	itm.shown = false;
	itm.price = 450;
	itm.minlevel = 3;
	itm.rare = 0.05;
	n++;

	//CURSED COINS
	makeref(itm,Items[n]);
	itm.id = "CursedCoin";
	itm.name = "itmname_cursedcoin";
	itm.describe = "itmdescr_cursedcoin";
	itm.model = "";
	itm.picIndex = 15;
	itm.picTexture = "ITEMS_4";
//	itm.shown = false;
	itm.price = 0;
	itm.minlevel = 3;
	itm.rare = 0.05;
	n++;
}

void InitButtons()
{
	aref lab3;
	makearef(lab3, Locations[FindLocation("Labirint_3")]);

	lab3.items.b_1.locator = "button01";
	lab3.items.b_1.model   = "b1";
	lab3.items.b_1.itemDeltaY  = 0.0;
	lab3.items.b_1.deltaY  = -0.05;
	lab3.items.b_1.trigged  = false;

/*
	lab3.items.b_2.locator = "b_2";
	lab3.items.b_2.model   = "items\b2";
	lab3.items.b_2.itemDeltaY  = 0.1;
	lab3.items.b_2.deltaY  = -0.1;
	lab3.items.b_2.trigged  = false;

	lab3.items.b_3.locator = "b_3";
	lab3.items.b_3.model   = "items\b3";
	lab3.items.b_3.itemDeltaY  = 0.1;
	lab3.items.b_3.deltaY  = -0.1;
	lab3.items.b_3.trigged  = false;

	lab3.items.b_4.locator = "b_4";
	lab3.items.b_4.model   = "items\b4";
	lab3.items.b_4.deltaY  = -0.1;
	lab3.items.b_4.trigged  = 0;

	lab3.items.b_5.locator = "b_5";
	lab3.items.b_5.model   = "items\b5";
	lab3.items.b_5.deltaY  = -0.1;
	lab3.items.b_5.trigged  = false;

	lab3.items.b_6.locator = "b_6";
	lab3.items.b_6.model   = "items\b6";
	lab3.items.b_6.deltaY  = -0.3;
	lab3.items.b_6.trigged  = false;

	lab3.items.b_7.locator = "b_7";
	lab3.items.b_7.model   = "items\b7";
	lab3.items.b_7.deltaY  = -0.1;
	lab3.items.b_7.trigged  = false;

	lab3.items.b_8.locator = "b_8";
	lab3.items.b_8.model   = "items\b8";
	lab3.items.b_8.deltaY  = -0.1;
	lab3.items.b_8.trigged  = false;

	lab3.items.b_9.locator = "b_9";
	lab3.items.b_9.model   = "items\b9";
	lab3.items.b_9.deltaY  = -0.3;
	lab3.items.b_9.trigged  = false;
*/
}

void InitRandItems()
{
	ref rnditem;

	makeref(rnditem,RandItems[0]);
	rnditem.id = POTION;
	rnditem.maxQuantity = 1;

	makeref(rnditem,RandItems[1]);
	rnditem.id = "100gp";
	rnditem.maxQuantity = 1;

	makeref(rnditem,RandItems[2]);
	rnditem.id = "250gp";
	rnditem.maxQuantity = 1;

	makeref(rnditem,RandItems[3]);
	rnditem.id = "500gp";
	rnditem.maxQuantity = 1;

	makeref(rnditem,RandItems[4]);
	rnditem.id = "jewelry1";
	rnditem.maxQuantity = 1;

	makeref(rnditem,RandItems[5]);
	rnditem.id = "jewelry2";
	rnditem.maxQuantity = 1;

	makeref(rnditem,RandItems[6]);
	rnditem.id = "jewelry3";
	rnditem.maxQuantity = 1;

	makeref(rnditem,RandItems[7]);
	rnditem.id = "jewelry4";
	rnditem.maxQuantity = 1;

	makeref(rnditem,RandItems[8]);
	rnditem.id = "jewelry5";
	rnditem.maxQuantity = 1;

	makeref(rnditem,RandItems[9]);
	rnditem.id = "jewelry6";
	rnditem.maxQuantity = 1;

	makeref(rnditem,RandItems[10]);
	rnditem.id = "jewelry7";
	rnditem.maxQuantity = 1;

	makeref(rnditem,RandItems[11]);
	rnditem.id = "jewelry8";
	rnditem.maxQuantity = 1;

	makeref(rnditem,RandItems[12]);
	rnditem.id = "jewelry9";
	rnditem.maxQuantity = 1;

	makeref(rnditem,RandItems[13]);
	rnditem.id = "jewelry10";
	rnditem.maxQuantity = 1;

	makeref(rnditem,RandItems[14]);
	rnditem.id = "jewelry11";
	rnditem.maxQuantity = 1;

	makeref(rnditem,RandItems[15]);
	rnditem.id = "jewelry12";
	rnditem.maxQuantity = 1;

	makeref(rnditem,RandItems[16]);
	rnditem.id = "jewelry13";
	rnditem.maxQuantity = 1;

	makeref(rnditem,RandItems[17]);
	rnditem.id = "100gp";
	rnditem.maxQuantity = 1;

	makeref(rnditem,RandItems[18]);
	rnditem.id = "potion1";
	rnditem.maxQuantity = 1;

	makeref(rnditem,RandItems[19]);
	rnditem.id = "250gp";
	rnditem.maxQuantity = 1;

	makeref(rnditem,RandItems[20]);
	rnditem.id = "potion1";
	rnditem.maxQuantity = 1;

	makeref(rnditem,RandItems[21]);
	rnditem.id = "indian2";
	rnditem.maxQuantity = 1;

	makeref(rnditem,RandItems[22]);
	rnditem.id = "indian3";
	rnditem.maxQuantity = 1;

	makeref(rnditem,RandItems[23]);
	rnditem.id = "indian4";
	rnditem.maxQuantity = 1;

	makeref(rnditem,RandItems[24]);
	rnditem.id = "500gp";
	rnditem.maxQuantity = 1;

	makeref(rnditem,RandItems[25]);
	rnditem.id = "potion1";
	rnditem.maxQuantity = 1;

	makeref(rnditem,RandItems[26]);
	rnditem.id = "100gp";
	rnditem.maxQuantity = 1;

	makeref(rnditem,RandItems[27]);
	rnditem.id = "potion1";
	rnditem.maxQuantity = 1;

	makeref(rnditem,RandItems[28]);
	rnditem.id = "100gp";
	rnditem.maxQuantity = 1;

	makeref(rnditem,RandItems[29]);
	rnditem.id = "250gp";
	rnditem.maxQuantity = 1;

	makeref(rnditem,RandItems[30]);
	rnditem.id = "potion2";
	rnditem.maxQuantity = 1;

	makeref(rnditem,RandItems[31]);
	rnditem.id = "100gp";
	rnditem.maxQuantity = 1;

	makeref(rnditem,RandItems[32]);
	rnditem.id = "indian13";
	rnditem.maxQuantity = 1;

	makeref(rnditem,RandItems[33]);
	rnditem.id = "potion3";
	rnditem.maxQuantity = 1;

	makeref(rnditem,RandItems[34]);
	rnditem.id = "potion2";
	rnditem.maxQuantity = 1;

	makeref(rnditem,RandItems[35]);
	rnditem.id = "potion4";
	rnditem.maxQuantity = 1;

}

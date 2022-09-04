
int LocationInitDouwesen(int n)
{

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\town_Douwesen\port";
	Locations[n].image = "loading\Douwesen_Port.tga";
	locations[n].worldmap = "Douwesen";
	Locations[n].id = "Douwesen_port";
	locations[n].id.label = "Douwesen port";

	//Town sack
	Locations[n].townsack = "Douwesen";

	//Sound
	locations[n].type = "port";
	locations[n].fastreload = "Douwesen";
	//Models
	//Always
	Locations[n].models.always.locators = "DouPort_l";
	Locations[n].models.always.seabed = "DouPort_sb";
	Locations[n].models.always.seabed.foam = "1";
	Locations[n].models.always.l1 = "DouPort";
	Locations[n].models.always.l1.foam = "1";
	Locations[n].models.always.grasspatch = "DouPort_g";
	//Day
	Locations[n].models.day.rinok = "DouPort_e01";
	Locations[n].models.day.charactersPatch = "DouPort_pd";
	Locations[n].models.day.fonar = "DouPort_fd";
	//Night
	Locations[n].models.night.fonar = "DouPort_fn";
	Locations[n].models.night.charactersPatch = "DouPort_pn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map

	Locations[n].reload.l1.name = "reload3";
	Locations[n].reload.l1.go = "Douwesen_town";
	Locations[n].reload.l1.emerge = "reload9";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Douwesen.";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Douwesen";
	Locations[n].reload.l2.emerge = "reload_1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].locators_radius.reload.reload2 = 3;
	Locations[n].reload.l2.label = "Sea.";


	Locations[n].reload.l3.name = "reload1_back";
	Locations[n].reload.l3.go = "Douwesen";
	Locations[n].reload.l3.emerge = "reload_1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Sea.";
	Locations[n].locators_radius.reload.reload1_back = 3;

	Locations[n].reload.l4.name = "reload2_back";
	Locations[n].reload.l4.go = "Douwesen";
	Locations[n].reload.l4.emerge = "reload_1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].locators_radius.reload.reload2_back = 3;
	Locations[n].reload.l4.label = "Sea.";


	Locations[n].reload.l5.name = "reload1";
	Locations[n].reload.l5.go = "Douwesen";
	Locations[n].reload.l5.emerge = "reload_1";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "Sea.";
	Locations[n].locators_radius.reload.reload1 = 3;

	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\town_Douwesen\town";

	Locations[n].id = "Douwesen_town";
	locations[n].id.label = "Douwesen town";
	Locations[n].image = "loading\Douwesen_Town.tga";
	locations[n].worldmap = "Douwesen";

	//Town sack
	Locations[n].townsack = "Douwesen";

	//Sound
	locations[n].type = "town";
	locations[n].fastreload = "Douwesen";
	//Models
	//Always
	Locations[n].models.always.locators = "DouTown_l";
	Locations[n].models.always.grassPatch = "DouTown_g";
	Locations[n].models.always.town = "DouTown";
	Locations[n].models.always.l1 = "plan_1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan_2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "plan_3";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";

	//Day
	//Locations[n].models.day.rinok = "DouTown_e01";
	Locations[n].models.day.fonar = "DouTown_fd";
	Locations[n].models.day.charactersPatch = "DouTown_p";
	Locations[n].models.day.jumppatch = "DouTown_j";

	//Night
	Locations[n].models.night.fonar = "DouTown_fn";
	Locations[n].models.night.charactersPatch = "DouTown_p";
	Locations[n].models.night.jumppatch = "DouTown_j";

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload9";
	Locations[n].reload.l1.go = "Douwesen_port";
	Locations[n].reload.l1.emerge = "Reload3";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Port.";

	/*Locations[n].reload.l2.name = "reload12";
	Locations[n].reload.l2.go = "Douwesen_town_exit";
	Locations[n].reload.l2.emerge = "reload3";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Jungle.";*/

	Locations[n].reload.l3.name = "reload11";
	Locations[n].reload.l3.go = "Douwesen_shipyard";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Shipyard.";
	Locations[n].reload.l3.close_for_night = 1;

	Locations[n].reload.l4.name = "reload3";
	Locations[n].reload.l4.go = "Douwesen_tavern";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "Tavern.";

	Locations[n].reload.l6.name = "reload6";
	Locations[n].reload.l6.go = "Douwesen_UsurerHouse";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "Loanshark's Office.";
	Locations[n].reload.l6.close_for_night = 1;

	Locations[n].reload.l7.name = "reload4";
	Locations[n].reload.l7.go = "Douwesen_Store";
	Locations[n].reload.l7.emerge = "reload1";
	Locations[n].reload.l7.autoreload = "0";
	Locations[n].reload.l7.label = "Store.";
	Locations[n].reload.l7.close_for_night = 1;

	Locations[n].reload.l8.name = "reload19";
	Locations[n].reload.l8.go = "Douwesen_town_exit";
	Locations[n].reload.l8.emerge = "reload2";
	Locations[n].reload.l8.autoreload = "0";
	Locations[n].reload.l8.label = "Jungle.";

	Locations[n].reload.l9.name = "reload15";
	Locations[n].reload.l9.go = "Douwesen_townhall";
	Locations[n].reload.l9.emerge = "reload1";
	Locations[n].reload.l9.autoreload = "0";
	Locations[n].reload.l9.label = "Residence.";
	Locations[n].reload.l9.close_for_night = 1;

	Locations[n].reload.l10.name = "reload18";
	Locations[n].reload.l10.go = "Douwesen_HouseInsideR18";
	Locations[n].reload.l10.emerge = "reload1";
	Locations[n].reload.l10.autoreload = "0";
	Locations[n].reload.l10.label = "House.";

	Locations[n].reload.l11.name = "reload1";
	Locations[n].reload.l11.go = "Douwesen_HouseInsideR1";
	Locations[n].reload.l11.emerge = "reload1";
	Locations[n].reload.l11.autoreload = "0";
	Locations[n].reload.l11.label = "House.";

	Locations[n].reload.l11.name = "reload5";
	Locations[n].reload.l11.go = "Douwesen_Dungeon";
	Locations[n].reload.l11.emerge = "reload1";
	Locations[n].reload.l11.autoreload = "0";
	Locations[n].reload.l11.label = "????";

//	Locations[n].reload.l10.close_for_night = 1;


	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\inside\Residence4";

	Locations[n].id = "Douwesen_townhall";
	locations[n].id.label = "Douwesen townhall";
	Locations[n].image = "loading\Douwesen_Townhall.tga";

	//Town sack
	Locations[n].townsack = "Douwesen";

	//Sound
	locations[n].type = "residence";
	locations[n].fastreload = "Douwesen";
	//Models
	//Always
	Locations[n].models.always.locators = "Res04_l";
	Locations[n].models.always.l1 = "Res04";
	Locations[n].models.always.window = "Res04_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;

	//Day
	Locations[n].models.day.charactersPatch = "Res04_p";

	//Night
	Locations[n].models.night.charactersPatch = "Res04_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\dour4_";

	//Reload map
	Locations[n].reload.l1.name = "Reload1";
	Locations[n].reload.l1.go = "Douwesen_town";
	Locations[n].reload.l1.emerge = "reload15";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Douwesen.";
	LAi_LocationFightDisable(&Locations[n], true);

	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\town_Douwesen\exit";

	Locations[n].id = "Douwesen_town_exit";
	locations[n].id.label = "Exit from Douwesen";
	Locations[n].image = "loading\Douwesen_Exit.tga";

	//Town sack
	Locations[n].townsack = "Douwesen";

	//Sound
	locations[n].type = "jungle";
//	locations[n].fastreload = "Douwesen";
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);
	//Models
	//Always
	Locations[n].models.always.locators = "DouExit_l";

	Locations[n].models.always.Waterfall1 = "waterfall";
    Locations[n].models.always.Waterfall1.uvslide.u0 = 0.3;
	Locations[n].models.always.Waterfall1.tech = "LocationWaterFall";
	Locations[n].models.always.Waterfall1.level = 50;
    //Locations[n].models.always.Waterfall2 = "waterfall1";
    //Locations[n].models.always.Waterfall2.uvslide.u0 = 0.4;
	//Locations[n].models.always.Waterfall2.tech = "LocationWaterFall";
	//Locations[n].models.always.Waterfall2.level = 51;
    Locations[n].models.always.Waterfall3 = "waterfall2";
    Locations[n].models.always.Waterfall3.uvslide.u0 = 0.2;
	Locations[n].models.always.Waterfall3.tech = "LocationWaterFall";
	Locations[n].models.always.Waterfall3.level = 52;

	Locations[n].models.always.exit = "DouExit";
	Locations[n].models.always.grassPatch = "DouExit_g";
	Locations[n].models.always.l0 = "plan_4";
	Locations[n].models.always.l0.level = 9;
	Locations[n].models.always.l0.tech = "LocationModelBlend";
	Locations[n].models.always.l1 = "plan_1";
	Locations[n].models.always.l1.level = 8;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan_2";
	Locations[n].models.always.l2.level = 7;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "plan_3";
	Locations[n].models.always.l3.level = 6;
	Locations[n].models.always.l3.tech = "LocationModelBlend";


	//Day
	Locations[n].models.day.charactersPatch = "DouExit_p";
	Locations[n].models.day.fonar = "DouExit_fd";
	//Night
	Locations[n].models.night.charactersPatch = "DouExit_p";
	Locations[n].models.night.fonar = "DouExit_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "Reload1";
	Locations[n].reload.l1.go = "Douwesen_Jungle_03";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].locators_radius.reload.reload1 = 4;
	Locations[n].reload.l1.label = "Jungle.";

	Locations[n].reload.l2.name = "Reload2";
	Locations[n].reload.l2.go = "Douwesen_town";
	Locations[n].reload.l2.emerge = "reload19";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Douwesen.";

	Locations[n].reload.l3.name = "Reload1_back";
	Locations[n].reload.l3.go = "Douwesen_Jungle_03";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].locators_radius.reload.Reload1_back = 4;
	Locations[n].reload.l3.label = "Jungle.";

	Locations[n].reload.l4.name = "Reload6";
	Locations[n].reload.l4.go = "Douwesen_Cavern";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "????";

	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\shipyard";

	Locations[n].id = "Douwesen_shipyard";
	locations[n].id.label = "Douwesen shipyard";
	Locations[n].image = "loading\shipyard_01.tga";

	//Town sack
	Locations[n].townsack = "Douwesen";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Douwesen";
	//Models
	//Always
	Locations[n].models.always.locators = "sh01_l";
	Locations[n].models.always.shipyard = "sh01";
	Locations[n].models.always.window = "sh01_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "sh01_p";
	Locations[n].models.day.fd = "sh01_fd";

	//Night
	Locations[n].models.night.charactersPatch = "sh01_p";
	Locations[n].models.night.fn = "sh01_fn";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\doush1_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Douwesen_town";
	Locations[n].reload.l1.emerge = "Reload11";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Douwesen.";
	LAi_LocationFightDisable(&Locations[n], true);

	n = n + 1;


	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\LargeStore";
	Locations[n].image = "loading\store_03.tga";

	Locations[n].id = "Douwesen_Store";
	locations[n].id.label = "Douwesen store";

	//Town sack
	Locations[n].townsack = "Douwesen";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Douwesen";
	//Models
	//Always
	Locations[n].models.always.locators = "LS_l";
	Locations[n].models.always.tavern = "LS";
	//Locations[n].models.always.env = "largestore_env";
	Locations[n].models.always.window = "LS_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	Locations[n].models.always.fonar = "ls_fn";

	//Day
	Locations[n].models.day.charactersPatch = "LS_p";

	//Night
	Locations[n].models.night.charactersPatch = "LS_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\douls_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Douwesen_town";
	Locations[n].reload.l1.emerge = "Reload4";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Douwesen.";
	LAi_LocationFightDisable(&Locations[n], true);

	n = n + 1;


	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\SmallTavern";

	Locations[n].id = "Douwesen_Tavern";
	locations[n].id.label = "Douwesen tavern";
	Locations[n].image = "loading\tavern_03.tga";

	//Town sack
	Locations[n].townsack = "Douwesen";

	//Sound
	locations[n].type = "tavern";
	locations[n].fastreload = "Douwesen";
	//Models
	//Always
	Locations[n].models.always.locators = "ST_l";
	Locations[n].models.always.tavern = "ST";
	Locations[n].models.always.window = "St_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "ST_p";

	//Night
	Locations[n].models.night.charactersPatch = "ST_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\doust_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Douwesen_Town";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Douwesen.";
	LAi_LocationFightDisable(&Locations[n], true);

	n = n + 1;

// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\Doubleflour_house";
	Locations[n].id = "Douwesen_tavern_upstairs";
	locations[n].id.label = "Room in Douwesen tavern";
	Locations[n].image = "loading\Tavern_Upstairs_01.tga";

	//Town sack
	Locations[n].townsack = "Douwesen";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Douwesen";
	//Models
	//Always
	Locations[n].models.always.locators = "LH_F2_l";
	Locations[n].models.always.tavern = "LH_F2";
	Locations[n].models.always.window = "LH_F2_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Locations[n].models.always.env = "smalltavern_env";
	//Day
	Locations[n].models.day.charactersPatch = "LH_F2_p";

	//Night
	Locations[n].models.night.charactersPatch = "LH_F2_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\doulf2_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Douwesen_tavern";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Tavern.";

	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\MediumHouse";
	Locations[n].id = "Douwesen_UsurerHouse";
	locations[n].id.label = "Loanshark's Office.";
	Locations[n].image = "loading\room.tga";

	//Town sack
	Locations[n].townsack = "Douwesen";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Douwesen";
	//Models
	//Always
	Locations[n].models.always.locators = "MH_l";
	Locations[n].models.always.house = "MH";
	//Locations[n].models.always.env = "smalltavern_env";
	Locations[n].models.always.window = "MH_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "MH_p";

	//Night
	Locations[n].models.night.charactersPatch = "MH_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\doumh_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Douwesen_town";
	Locations[n].reload.l1.emerge = "reload6";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Douwesen.";
	LAi_LocationFightDisable(&Locations[n], true);

	n = n + 1;


	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\mh3";
	Locations[n].id = "Douwesen_HouseInsideR1";
	locations[n].id.label = "House.";
	Locations[n].image = "loading\house_04.tga";

	//Town sack
	Locations[n].townsack = "Douwesen";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Douwesen";
	//Models
	//Always
	Locations[n].models.always.locators = "MH3_l";
	Locations[n].models.always.house = "MH3";
	//Locations[n].models.always.env = "smalltavern_env";
	Locations[n].models.always.window = "MH3_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "MH3_p";

	//Night
	Locations[n].models.night.charactersPatch = "MH3_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\doumh3_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Douwesen_town";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Douwesen.";

	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\Doubleflour_house";
	Locations[n].id = "Douwesen_HouseInsideR18";
	locations[n].id.label = "House.";
	Locations[n].image = "loading\house_08.tga";

	//Town sack
	Locations[n].townsack = "Douwesen";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Douwesen";
	//Models
	//Always
	Locations[n].filespath.models = "locations\inside\Doubleflour_house";
	Locations[n].models.always.locators = "LH_F1_l";
	Locations[n].models.always.house = "LH_F1";
	Locations[n].models.always.window = "LF1_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "LH_F1_p";
//	Locations[n].models.day.fonar = "LH_F1_fn";

	//Night
	Locations[n].models.night.charactersPatch = "LH_F1_p";
//	Locations[n].models.night.fonar = "LH_F1_fn";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\doulf1_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Douwesen_town";
	Locations[n].reload.l1.emerge = "reload18";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Douwesen.";

	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Pirate Fort";

	Locations[n].id = "Pirate_Fort";
	locations[n].id.label = "Pirate Fort";
	Locations[n].image = "loading\Pirate_Fort.tga";
	//Sound
	locations[n].type = "jungle";

	//Models
	//Always
	Locations[n].models.always.locators = "PiF_l";
	Locations[n].models.always.town = "PiF";
	Locations[n].models.always.grasspatch = "PiF_g";
	Locations[n].models.always.l1 = "pif_b01";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "pif_b02";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "pif_b03";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";
	Locations[n].models.always.l4 = "pif_b04";
	Locations[n].models.always.l4.level = 6;
	Locations[n].models.always.l4.tech = "LocationModelBlend";


	//Day
	Locations[n].models.day.fonar = "PiF_fd";
	Locations[n].models.day.charactersPatch = "PiF_p";
	//Night
	Locations[n].models.night.fonar = "PiF_fn";
	Locations[n].models.night.charactersPatch = "PiF_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "Reload1";
	Locations[n].reload.l1.go = "Douwesen_Jungle_01";
	Locations[n].reload.l1.emerge = "Reload1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].reload.l1.autoreload = 1;
	Locations[n].locators_radius.reload.reload1 = 1;

	Locations[n].reload.l5.name = "Reload1_back";
	Locations[n].reload.l5.go = "Douwesen_Jungle_01";
	Locations[n].reload.l5.emerge = "Reload1";
	Locations[n].reload.l5.label = "Jungle.";
	Locations[n].reload.l5.autoreload = 1;
	Locations[n].locators_radius.reload.reload1_back = 2;

	Locations[n].reload.l2.name = "Reload5";
	Locations[n].reload.l2.go = "Douwesen_Pirate_Residence";
	Locations[n].reload.l2.emerge = "Reload1";
	Locations[n].reload.l2.label = "Chief's House.";

	Locations[n].reload.l3.name = "Reload6";
	Locations[n].reload.l3.go = "Pirate_tavern";
	Locations[n].reload.l3.emerge = "Reload1";
	Locations[n].reload.l3.label = "Tavern.";

	Locations[n].reload.l4.name = "Reload2";
	Locations[n].reload.l4.go = "Douwesen_Pirate_HouseInsideR2";
	Locations[n].reload.l4.emerge = "Reload1";
	Locations[n].reload.l4.label = "House.";

	n = n + 1;

		//---------------------------------------------------

	Locations[n].filespath.models = "locations\inside\mediumHouse";

	Locations[n].id = "Douwesen_Pirate_Residence";
	locations[n].id.label = "House of leader of Douwesen pirates";
	Locations[n].image = "loading\room.tga";
	//Sound
	locations[n].type = "house";

	//Models
	//Always
	Locations[n].models.always.locators = "MH_l";
	Locations[n].models.always.house = "MH";
	//Locations[n].models.always.env = "smalltavern_env";
	Locations[n].models.always.window = "MH_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "MH_p";

	//Night
	Locations[n].models.night.charactersPatch = "MH_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\doumh_";
	//Reload map
	Locations[n].reload.l1.name = "Reload1";
	Locations[n].reload.l1.go = "Pirate_Fort";
	Locations[n].reload.l1.emerge = "Reload5";
	Locations[n].reload.l1.label = "????????? ????.";
	//fake reload
	/*
	Locations[n].reload.l2.name = "to_Ship_deck";
	Locations[n].reload.l2.go = "Ship_deck";
	Locations[n].reload.l2.emerge = "locator2";
	*/
	n = n + 1;


	// -------------------------------------------------

	Locations[n].filespath.models = "locations\inside\Smallhome";

	Locations[n].id = "Douwesen_Pirate_HouseInsideR2";
	locations[n].id.label = "House";
		Locations[n].image = "loading\house_03.tga";
	//Models
		//Always
	Locations[n].models.always.locators = "sH_l";
	Locations[n].models.always.house = "sh";
	Locations[n].models.always.window = "sh_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "sh_p";

	//Night
	Locations[n].models.night.charactersPatch = "sh_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\pifsh_";
	//Reload map
	Locations[n].reload.l1.name = "Reload1";
	Locations[n].reload.l1.go = "Pirate_Fort";
	Locations[n].reload.l1.emerge = "Reload2";
	Locations[n].reload.l1.label = "Pirate Fort.";

	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Jungle_2";

	Locations[n].id = "Douwesen_Jungle_01";
	locations[n].id.label = "Douwesen jungles";
	Locations[n].image = "loading\Douwesen_Jungle_01.tga";
	//Sound
	locations[n].type = "jungle";
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);

	//Models
	//Always
	Locations[n].models.always.locators = "Jungle02_l";
	Locations[n].models.always.jungle = "Jungle02";
	Locations[n].models.always.grassPatch = "JUNGLE02_g";
	Locations[n].models.always.l1 = "plan_1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan_2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "plan_3";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";

	//Day
	Locations[n].models.day.charactersPatch = "Jungle02_p";
	//Night
	Locations[n].models.night.charactersPatch = "Jungle02_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Pirate_Fort";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Pirate Fort.";
	Locations[n].locators_radius.reload.reload1 = 4;

	Locations[n].reload.l4.name = "reload1_back";
	Locations[n].reload.l4.go = "Pirate_Fort";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Pirate Fort.";
	Locations[n].locators_radius.reload.reload1_back = 4;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Douwesen_Shore_01";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Palm Beach.";
	Locations[n].locators_radius.reload.reload2 = 4;

	Locations[n].reload.l5.name = "reload2_back";
	Locations[n].reload.l5.go = "Douwesen_Shore_01";
	Locations[n].reload.l5.emerge = "reload2";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].reload.l5.label = "Palm Beach.";
	Locations[n].locators_radius.reload.reload2_back = 3;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Douwesen_jungle_02";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload3 = 4;

	Locations[n].reload.l6.name = "reload3_back";
	Locations[n].reload.l6.go = "Douwesen_jungle_02";
	Locations[n].reload.l6.emerge = "reload2";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].reload.l6.label = "Jungle.";
	Locations[n].locators_radius.reload.reload3_back = 4;
	n = n + 1;


	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Shore_5";

	Locations[n].id = "Douwesen_shore_01";
	locations[n].id.label = "Douwesen shore";
	Locations[n].image = "loading\Douwesen_Shore_01.tga";
	Locations[n].name = "Palm Beach";
	locations[n].worldmap = "DShore 1";

	//Sound
	locations[n].type = "seashore";

	//Models
	//Always
	Locations[n].models.always.jungle = "Shore05";
	Locations[n].models.always.jungle.foam = "1";
	Locations[n].models.always.locators = "Shore05_l";
	Locations[n].models.always.grassPatch = "Shore05_g";
	Locations[n].models.always.seabed = "Shore05_sb";
	Locations[n].models.always.seabed.foam = "1";
	Locations[n].models.always.l1 = "plan_1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan_2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "plan_3";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";


	//Day
	Locations[n].models.day.charactersPatch = "Shore05_p";
	//Night
	Locations[n].models.night.charactersPatch = "Shore05_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map
	Locations[n].reload.l1.name = "reload2";
	Locations[n].reload.l1.go = "Douwesen_Jungle_01";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2 = 3;

	Locations[n].reload.l3.name = "reload2_back";
	Locations[n].reload.l3.go = "Douwesen_Jungle_01";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2_back = 3;

	Locations[n].reload.l2.name = "boat";
	Locations[n].reload.l2.go = "Douwesen";
	Locations[n].reload.l2.emerge = "reload_2";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Sea.";
    Locations[n].locators_radius.reload.boat = 9.0;

	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Jungle_7";

	Locations[n].id = "Douwesen_Jungle_02";
	locations[n].id.label = "Douwesen jungles";
	Locations[n].image = "loading\Douwesen_Jungle_02.tga";
	//Sound
	locations[n].type = "jungle";
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);


	//Models
	//Always
	Locations[n].models.always.locators = "Jungle07_l";
	Locations[n].models.always.jungle = "Jungle07";
	Locations[n].models.always.grassPatch = "JUNGLE07_g";
	Locations[n].models.always.l1 = "plan_1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan_2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "plan_3";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";

	//Day
	Locations[n].models.day.charactersPatch = "Jungle07_p";
	//Night
	Locations[n].models.night.charactersPatch = "Jungle07_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Rheims_house";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "House.";
	Locations[n].locators_radius.reload.reload1 = 4;

	Locations[n].reload.l5.name = "reload1_back";
	Locations[n].reload.l5.go = "Rheims_house";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].reload.l5.label = "House.";
	Locations[n].locators_radius.reload.reload1_back = 1;

	Locations[n].reload.l4.name = "reload2";
	Locations[n].reload.l4.go = "Douwesen_jungle_01";
	Locations[n].reload.l4.emerge = "reload3";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2 = 4;

	Locations[n].reload.l2.name = "reload2_back";
	Locations[n].reload.l2.go = "Douwesen_jungle_01";
	Locations[n].reload.l2.emerge = "reload3";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2_back = 2;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Douwesen_Jungle_03";
	Locations[n].reload.l3.emerge = "reload3";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload3 = 4;

	Locations[n].reload.l6.name = "reload3_back";
	Locations[n].reload.l6.go = "Douwesen_Jungle_03";
	Locations[n].reload.l6.emerge = "reload3";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].reload.l6.label = "Jungle.";
	Locations[n].locators_radius.reload.reload3_back = 2;

	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Shore_10";

	Locations[n].id = "Douwesen_shore_02";
	locations[n].id.label = "Douwesen shore";
	Locations[n].image = "loading\Douwesen_Shore_02.tga";
	Locations[n].name = "Crab Cliffs";
	Locations[n].worldmap = "DShore 2";
	//Sound
	locations[n].type = "seashore";

	//Models
	//Always
	Locations[n].models.always.jungle = "shore10";
	Locations[n].models.always.jungle.foam = "1";
	Locations[n].models.always.locators = "shore10_l";
    Locations[n].models.always.seabed = "shore10_sb";
	Locations[n].models.always.seabed.foam = "1";
	Locations[n].models.always.grassPatch = "Shore10_g";
	Locations[n].models.always.l1 = "plan_1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan_2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "plan_3";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";
	//Day
	Locations[n].models.day.charactersPatch = "shore10_p";
	//Night
	Locations[n].models.night.charactersPatch = "shore10_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map
	Locations[n].reload.l1.name = "reload2";
	Locations[n].reload.l1.go = "Douwesen_Jungle_03";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2 = 3;

	Locations[n].reload.l3.name = "reload2_back";
	Locations[n].reload.l3.go = "Douwesen_Jungle_03";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2_back = 2;

	Locations[n].reload.l2.name = "boat";
	Locations[n].reload.l2.go = "Douwesen";
	Locations[n].reload.l2.emerge = "reload_3";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Sea.";
	Locations[n].locators_radius.reload.boat = 9.0;
	n = n + 1;

// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Jungle_4";

	Locations[n].id = "Douwesen_Jungle_03";
	locations[n].id.label = "Douwesen jungles";
	Locations[n].image = "loading\Douwesen_Jungle_03.tga";
	//Sound
	locations[n].type = "jungle";
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);


	//Models
	//Always
	Locations[n].models.always.locators = "Jungle04_l";
	Locations[n].models.always.jungle = "Jungle04";
	Locations[n].models.always.grassPatch = "JUNGLE04_g";
	Locations[n].models.always.l1 = "plan_1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan_2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "plan_3";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";


	//Day
	Locations[n].models.day.charactersPatch = "Jungle04_p";
	//Night
	Locations[n].models.night.charactersPatch = "Jungle04_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Douwesen_town_exit";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1 = 4;

	Locations[n].reload.l4.name = "reload1_back";
	Locations[n].reload.l4.go = "Douwesen_town_exit";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1_back = 2;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Douwesen_Shore_02";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Crab Cliffs.";
	Locations[n].locators_radius.reload.reload2 = 4;

	Locations[n].reload.l5.name = "reload2_back";
	Locations[n].reload.l5.go = "Douwesen_Shore_02";
	Locations[n].reload.l5.emerge = "reload2";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].reload.l5.label = "Crab Cliffs.";
	Locations[n].locators_radius.reload.reload2_back = 2;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Douwesen_jungle_02";
	Locations[n].reload.l3.emerge = "reload3";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload3 = 4;

	Locations[n].reload.l6.name = "reload3_back";
	Locations[n].reload.l6.go = "Douwesen_jungle_02";
	Locations[n].reload.l6.emerge = "reload3";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].reload.l6.label = "Jungle.";
	Locations[n].locators_radius.reload.reload3_back = 3;

	n = n + 1;


	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Rheims House";

	Locations[n].id = "Rheims_House";
	locations[n].id.label = "House in Jungle";
	Locations[n].image = "loading\Rheims_House.tga";
	//Sound
	locations[n].type = "house";

	//Models
	//Always
	Locations[n].models.always.locators = "Rhouse_l";
	Locations[n].models.always.house = "Rhouse";
	Locations[n].models.always.grassPatch = "Rhouse_g";
	Locations[n].models.always.l1 = "rhouse_b01";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "rhouse_b02";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "rhouse_b03";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";
	Locations[n].models.always.l4 = "rhouse_b04";
	Locations[n].models.always.l4.level = 6;
	Locations[n].models.always.l4.tech = "LocationModelBlend";

	//Day
	Locations[n].models.day.charactersPatch = "Rhouse_p";
	//Night
	Locations[n].models.night.charactersPatch = "Rhouse_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Douwesen_jungle_02";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1 = 3;

	Locations[n].reload.l3.name = "reload1_back";
	Locations[n].reload.l3.go = "Douwesen_jungle_02";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1_back = 3;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Rheims_house_inside";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "House";

/*
	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "";
	Locations[n].reload.l3.emerge = "";*/

	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\inside\mediumHouse";

	Locations[n].id = "Rheims_House_inside";
	locations[n].id.label = "Rheims house on Douwesen";
	Locations[n].image = "loading\room.tga";
	//Sound
	locations[n].type = "house";

	//Models
	//Always
	Locations[n].models.always.locators = "MH_l";
	Locations[n].models.always.house = "MH";
	//Locations[n].models.always.env = "smalltavern_env";
	Locations[n].models.always.window = "MH_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "MH_p";

	//Night
	Locations[n].models.night.charactersPatch = "MH_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\smumh_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Rheims_House";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Exit.";

	n = n + 1;

// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\MediumTavern";

	Locations[n].id = "Pirate_Tavern";
	locations[n].id.label = "Tavern";
	Locations[n].image = "loading\Tavern_02.tga";
	//Sound
	locations[n].type = "tavern";

	//Models
	//Always
	Locations[n].models.always.locators = "MT_l";
	Locations[n].models.always.l1 = "MT";
	Locations[n].models.always.window = "MT_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;

	//Day
	Locations[n].models.day.charactersPatch = "MT_p";

	//Night
	Locations[n].models.night.charactersPatch = "MT_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\smumt_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Pirate_Fort";
	Locations[n].reload.l1.emerge = "reload6";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Pirate Fort.";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Pirate_tavern_upstairs";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Room.";
	Locations[n].reload.l2.disable = 1;

	LAi_LocationFightDisable(&Locations[n], true);

	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\Doubleflour_house";
	Locations[n].id = "Pirate_tavern_upstairs";
	locations[n].id.label = "Room in Pirate tavern";
	Locations[n].image = "loading\Tavern_Upstairs_01.tga";

	//Town sack
	Locations[n].townsack = "Douwesen";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Douwesen";
	//Models
	//Always
	Locations[n].models.always.locators = "LH_F2_l";
	Locations[n].models.always.tavern = "LH_F2";
	Locations[n].models.always.window = "LH_F2_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "LH_F2_p";

	//Night
	Locations[n].models.night.charactersPatch = "LH_F2_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\smumt_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Pirate_tavern";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Tavern.";
	Locations[n].reload.l1.disable = 0;
	LAi_LocationFightDisable(&Locations[n], true);

	n = n + 1;

	// ------------------------------------------------- Корабль с сокровищами для квеста про Найджела Блайта

	Locations[n].filespath.models = "locations\Outside\Shore_ship";

	Locations[n].id = "Douwesen_shore_ship";
	locations[n].id.label = "Douwesen shore";
//	locations[n].worldmap = "DShore 3";
	Locations[n].image = "loading\Douwesen_Shore_Ship.tga";
	Locations[n].name = "Ship";
	//Sound
	locations[n].type = "seashore";

	//Models
	//Always
	Locations[n].models.always.jungle = "ShoreShip";
	Locations[n].models.always.jungle.foam = "1";
	Locations[n].models.always.locators = "ShoreShip_l";
	Locations[n].models.always.grassPatch = "ShoreShip_g";
	Locations[n].models.always.seabed = "ShoreShip_sb";
	Locations[n].models.always.seabed.foam = "1";
	Locations[n].models.always.l1 = "plan_1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan_2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "plan_3";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";

	//Day
	Locations[n].models.day.charactersPatch = "ShoreShip_p";
	//Night
	Locations[n].models.night.charactersPatch = "ShoreShip_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Douwesen_cavern";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "The cavern";
	Locations[n].locators_radius.reload.reload2 = 1;

	Locations[n].reload.l2.name = "reload1_back";
	Locations[n].reload.l2.go = "Douwesen_cavern";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "The cavern";
	Locations[n].locators_radius.reload.reload2_back = 3;

	Locations[n].items.randitem1 = "pistol4";

	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 0, 24);

	n = n + 1;

	// -----------------Mosh D24--------------------
	Locations[n].filespath.models = "locations\Inside\Dungeon_4";
	Locations[n].id = "Douwesen_dungeon";
	Locations[n].image = "loading\Dungeon 04.tga";
//	Locations[n].monsters = "1";

	//Sound
	locations[n].type = "dungeon";
	//Models
	Locations[n].models.back = "back\d04env_";
	//Always
	Locations[n].models.always.locators = "d04_l";
	Locations[n].models.always.house = "d04";
	//Day
	Locations[n].models.day.charactersPatch = "d04_p";
	//Night
	Locations[n].models.night.charactersPatch = "d04_p";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Douwesen_town";//Mosh
	Locations[n].reload.l1.emerge = "reload5";

	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 0, 24);

	Locations[n].items.randitem1 = "blade12";

	n = n + 1;


// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\Cavern";

	Locations[n].id = "Douwesen_Cavern";
	locations[n].id.label = "Douwesen Cavern";
	Locations[n].image = "loading\Douwesen_Cavern.tga";

	//Sound
	locations[n].type = "cave";
	//Models
	//Always
	Locations[n].models.always.locators = "cavern_l";
	Locations[n].models.always.l1 = "cavern";
	Locations[n].models.always.l2 = "Crystals";
	Locations[n].models.always.l2.tech = "EnvironmentShader";
	Locations[n].models.always.l2.reflection = 0.25;


	Locations[n].models.always.Waterfall1 = "water";
	Locations[n].models.always.Waterfall1.uvslide.v0 = 0.0;
    Locations[n].models.always.Waterfall1.uvslide.v1 = 0.0;
    Locations[n].models.always.Waterfall1.tech = "LocationWaterFall";
	Locations[n].models.always.Waterfall1.level = 50;

	Locations[n].models.always.Waterfall2 = "cfall";
	Locations[n].models.always.Waterfall2.uvslide.v0 = 0.3;
    Locations[n].models.always.Waterfall2.uvslide.v1 = 0.0;
	Locations[n].models.always.Waterfall2.tech = "LocationWaterFall";
	Locations[n].models.always.Waterfall2.level = 50;


	//Day
	Locations[n].models.day.charactersPatch = "cavern_p";
	//Night
	Locations[n].models.night.charactersPatch = "cavern_p";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Douwesen_town_exit";
	Locations[n].reload.l1.emerge = "reload6";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Douwesen Outskirts.";

	Locations[n].reload.l2.name = "reload1_back";
	Locations[n].reload.l2.go = "Douwesen_town_exit";
	Locations[n].reload.l2.emerge = "reload6";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Douwesen Outskirts";

	Locations[n].reload.l3.name = "reload2";
	Locations[n].reload.l3.go = "Douwesen_shore_ship";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "?????";

	Locations[n].reload.l4.name = "reload2_back";
	Locations[n].reload.l4.go = "Douwesen_shore_ship";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "?????";
	Locations[n].locators_radius.reload.reload2_back = 2;

	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 0, 24);


	n = n + 1;

	return n;
}
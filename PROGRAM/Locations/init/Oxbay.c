
int LocationInitOxbay(int n)
{

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\town_Oxbay\port";
	Locations[n].image = "loading\oxbay_port.tga";

	Locations[n].id = "Oxbay_port";
	locations[n].id.label = "Oxbay port";
	locations[n].worldmap = "Oxbay";

	//Town sack
	Locations[n].townsack = "Oxbay";

	//Sound
	locations[n].type = "port";
	locations[n].fastreload = "Oxbay";
	LAi_LocationFantomsGen(&locations[n], true);
	//Models
	//Always
	Locations[n].models.always.locators = "OXport_l";
	Locations[n].models.always.l1 = "OXport";
	Locations[n].models.always.l1.foam = "1";
	Locations[n].models.always.l2 = "OXport_sb";
	Locations[n].models.always.l2.foam = "1";
	Locations[n].models.always.grassPatch = "OXport_g";
	//Day
	Locations[n].models.day.fonar = "OXport_fd";
	Locations[n].models.day.charactersPatch = "OXport_pd";
	Locations[n].models.day.rinok = "OXport_e1";
	Locations[n].models.day.jumpPatch = "OXport_j";
	//Night
	Locations[n].models.night.fonar = "OXport_fn";
	Locations[n].models.night.charactersPatch = "OXport_pn";
	Locations[n].models.night.jumpPatch = "OXport_j";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map

	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Oxbay_town";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Oxbay.";

	Locations[n].reload.l3.name = "reload2";
	Locations[n].reload.l3.go = "Oxbay";
	Locations[n].reload.l3.emerge = "reload_2";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Sea";

	Locations[n].reload.l2.name = "reload2_back";
	Locations[n].reload.l2.go = "Oxbay";
	Locations[n].reload.l2.emerge = "reload_2";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Sea.";
	Locations[n].locators_radius.reload.relo1ad2_back = 3;

	Locations[n].reload.l4.name = "reload3";
	Locations[n].reload.l4.go = "Dungeon 1";
	Locations[n].reload.l4.emerge = "reload2";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "Cave.";
	Locations[n].locators_radius.reload.reload2_back = 3;


	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\town_Oxbay\town";
	Locations[n].image = "loading\oxbay_town.tga";

	Locations[n].id = "Oxbay_town";
	locations[n].id.label = "Oxbay";
	locations[n].worldmap = "Oxbay";

	//Town sack
	Locations[n].townsack = "Oxbay";

	//Sound
	locations[n].type = "town";
	locations[n].fastreload = "Oxbay";
	LAi_LocationFantomsGen(&locations[n], true);
	//Models
	//Always
	Locations[n].models.always.locators = "OXtown_l";
	Locations[n].models.always.grassPatch = "OXtown_g";
	Locations[n].models.always.town = "OXtown";
	Locations[n].models.always.l1 = "oxtown_b04";
	Locations[n].models.always.l1.level = 6;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	//Day
	Locations[n].models.day.fonar = "OXtown_fd";
	Locations[n].models.day.charactersPatch = "OXtown_pd";
	Locations[n].models.day.jumpPatch = "OXtown_j";
	Locations[n].models.day.rinok = "OXtown_e1";
	//Night
	Locations[n].models.night.fonar = "OXtown_fn";
	Locations[n].models.night.charactersPatch = "OXtown_pn";
	Locations[n].models.night.jumpPatch = "OXtown_j";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Oxbay_port";
	Locations[n].reload.l1.emerge = "Reload1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Port.";

	Locations[n].reload.l9.name = "reload7";
	Locations[n].reload.l9.go = "Oxbay_HouseInsideR7";
	Locations[n].reload.l9.emerge = "reload1";
	Locations[n].reload.l9.autoreload = "0";
	Locations[n].reload.l9.label = "House.";

	Locations[n].reload.l10.name = "reload5";
	Locations[n].reload.l10.go = "Oxbay_HouseInsideR5";
	Locations[n].reload.l10.emerge = "reload1";
	Locations[n].reload.l10.autoreload = "0";
	Locations[n].reload.l10.label = "House.";

	Locations[n].reload.l20.name = "reload9";
	Locations[n].reload.l20.go = "Oxbay_HouseInsideR9";
	Locations[n].reload.l20.emerge = "reload1";
	Locations[n].reload.l20.autoreload = "0";
	Locations[n].reload.l20.label = "House.";

	Locations[n].reload.l21.name = "reload8";
	Locations[n].reload.l21.go = "Oxbay_HouseInsideR8";
	Locations[n].reload.l21.emerge = "reload1";
	Locations[n].reload.l21.autoreload = "0";
	Locations[n].reload.l21.label = "House.";

	Locations[n].reload.l22.name = "reload17";
	Locations[n].reload.l22.go = "Oxbay_HouseInsideR17";
	Locations[n].reload.l22.emerge = "reload1";
	Locations[n].reload.l22.autoreload = "0";
	Locations[n].reload.l22.label = "House.";

	Locations[n].reload.l2.name = "reload12";
	Locations[n].reload.l2.go = "Oxbay_town_exit";
	Locations[n].reload.l2.emerge = "reload3";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Jungle.";

	Locations[n].reload.l3.name = "reload15";
	Locations[n].reload.l3.go = "Oxbay_store";
	Locations[n].reload.l3.emerge = "locator2";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Store.";
	Locations[n].reload.l3.close_for_night = 1;

	Locations[n].reload.l4.name = "reload13";
	Locations[n].reload.l4.go = "Oxbay_tavern";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "Tavern.";

	Locations[n].reload.l18.name = "reload18";
	Locations[n].reload.l18.go = "Oxbay_UsurerHouse";
	Locations[n].reload.l18.emerge = "reload1";
	Locations[n].reload.l18.autoreload = "0";
	Locations[n].reload.l18.label = "Loanshark's Office.";
	Locations[n].reload.l18.close_for_night = 1;

	Locations[n].reload.l7.name = "reload3";
	Locations[n].reload.l7.go = "Oxbay_Shipyard";
	Locations[n].reload.l7.emerge = "reload1";
	Locations[n].reload.l7.autoreload = "0";
	Locations[n].reload.l7.label = "Shipyard.";
	Locations[n].reload.l7.close_for_night = 1;

	Locations[n].reload.l55.name = "reload19";
	Locations[n].reload.l55.go = "Dungeon 1";
	Locations[n].reload.l55.emerge = "reload1";
	Locations[n].reload.l55.autoreload = "0";
	Locations[n].reload.l55.label = "Underworld.";
	Locations[n].reload.l55.close_for_night = 0;


	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\town_Oxbay\exit";

	Locations[n].id = "Oxbay_town_exit";
	locations[n].id.label = "Exit from Oxbay";
	Locations[n].image = "loading\oxbay_exit.tga";

	//Town sack
	Locations[n].townsack = "Oxbay";

	//Sound
	locations[n].type = "jungle";
//	locations[n].fastreload = "Oxbay";
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);

	//Models
	//Always
	Locations[n].models.always.locators = "OXexit_l";
	Locations[n].models.always.exit = "oxexit";
	Locations[n].models.always.grassPatch = "OXexit_g";
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
	Locations[n].models.day.charactersPatch = "OXexit_p";
	Locations[n].models.day.fonar = "OXexit_fd";
	//Night
	Locations[n].models.night.charactersPatch = "OXexit_p";
	Locations[n].models.night.fonar = "OXexit_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "Reload3";
	Locations[n].reload.l1.go = "Oxbay_town";
	Locations[n].reload.l1.emerge = "reload12";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Oxbay.";

	Locations[n].reload.l2.name = "Reload2";
	Locations[n].reload.l2.go = "Oxbay_Jungle_01";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2 = 2.0;

	Locations[n].reload.l3.name = "Reload1";
	Locations[n].reload.l3.go = "Oxbay_Jungle_02";
	Locations[n].reload.l3.emerge = "Reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload1 = 4.0;

	Locations[n].reload.l4.name = "Reload2_back";
	Locations[n].reload.l4.go = "Oxbay_Jungle_01";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload2_back = 2.0;

	Locations[n].reload.l5.name = "Reload1_back";
	Locations[n].reload.l5.go = "Oxbay_Jungle_02";
	Locations[n].reload.l5.emerge = "Reload2";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].reload.l5.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload1_back = 3.0;



	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\shipyard";

	Locations[n].id = "Oxbay_shipyard";
	locations[n].id.label = "Oxbay shipyard";
	Locations[n].image = "loading\Shipyard_01.tga";

	//Town sack
	Locations[n].townsack = "Oxbay";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Oxbay";
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
	Locations[n].models.back = "back\oxsh1_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Oxbay_town";
	Locations[n].reload.l1.emerge = "Reload3";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Oxbay.";
	LAi_LocationFightDisable(&Locations[n], true);

	n = n + 1;


	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\StoreSmall";
	Locations[n].image = "loading\store_04.tga";

	Locations[n].id = "Oxbay_Store";
	locations[n].id.label = "Oxbay store";

	//Town sack
	Locations[n].townsack = "Oxbay";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Oxbay";
	//Models
	//Always
	Locations[n].models.always.locators = "SS_l";
	Locations[n].models.always.store = "SS";
	Locations[n].models.always.window = "SS_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;

	//Day
	Locations[n].models.day.charactersPatch = "SS_p";
	Locations[n].models.day.fonar = "SS_fn";

	//Night
	Locations[n].models.night.charactersPatch = "SS_p";
	Locations[n].models.night.fonar = "ss_fn";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\oxss_";
	//Reload map
	Locations[n].reload.l1.name = "locator2";
	Locations[n].reload.l1.go = "Oxbay_town";
	Locations[n].reload.l1.emerge = "Reload15";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Oxbay.";
	Locations[n].locators_radius.reload.locator2 = 0.7;
	LAi_LocationFightDisable(&Locations[n], true);

	n = n + 1;


	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\LargeTavern";

	Locations[n].id = "Oxbay_Tavern";
	locations[n].id.label = "Oxbay tavern";
	Locations[n].image = "loading\Tavern_01.tga";

	//Town sack
	Locations[n].townsack = "Oxbay";

	//Sound
	locations[n].type = "tavern";
	locations[n].fastreload = "Oxbay";
	//Models
	//Always
	Locations[n].models.always.tavern = "LT";
	Locations[n].models.always.locators = "LT_l";
	Locations[n].models.always.window = "LT_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "LT_p";

	//Night
	Locations[n].models.night.charactersPatch = "LT_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\oxlt_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Oxbay_Town";
	Locations[n].reload.l1.emerge = "reload13";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Oxbay.";

	//Fake locators
	Locations[n].reload.l10.name = "reload_to_town_for_Massoni";
	Locations[n].reload.l10.go = "Oxbay_Town";
	Locations[n].reload.l10.emerge = "goto39";
	LAi_LocationFightDisable(&Locations[n], true);

	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "Oxbay_tavern_upstairs";
	locations[n].id.label = "Room in Oxbay tavern";
	Locations[n].image = "loading\Tavern_Upstairs_01.tga";

	//Town sack
	Locations[n].townsack = "Oxbay";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Oxbay";
	//Models
	//Always
	Locations[n].filespath.models = "locations\inside\Doubleflour_house";
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
	Locations[n].models.back = "back\oxlf2_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Oxbay_tavern";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Tavern.";
	Locations[n].locators_radius.reload.reload1 = 0.8;
	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "Oxbay_UsurerHouse";
	locations[n].id.label = "Loanshark's Office";
	Locations[n].image = "loading\house_08.tga";

	//Town sack
	Locations[n].townsack = "Oxbay";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Oxbay";
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

	//Night
	Locations[n].models.night.charactersPatch = "LH_F1_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\oxlf1_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Oxbay_town";
	Locations[n].reload.l1.emerge = "reload18";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Oxbay";
	Locations[n].locators_radius.reload.reload1 = 0.8;
	LAi_LocationFightDisable(&Locations[n], true);

	n = n + 1;

	// -------------------------------------------------

	Locations[n].id = "Oxbay_HouseInsideR7";
	locations[n].id.label = "House";
	Locations[n].image = "loading\house_06.tga";

	//Town sack
	Locations[n].townsack = "Oxbay";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Oxbay";
	//Models
	//Always
	Locations[n].filespath.models = "locations\inside\mh5";
	Locations[n].models.always.locators = "mh5_l";
	Locations[n].models.always.house = "mh5";
	Locations[n].models.always.window = "mh5_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;

	//Day
	Locations[n].models.day.charactersPatch = "mh5_p";

	//Night
	Locations[n].models.night.charactersPatch = "mh5_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\oxmh5_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Oxbay_town";
	Locations[n].reload.l1.emerge = "reload7";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Oxbay";
	Locations[n].locators_radius.reload.reload1 = 0.8;
	n = n + 1;

	// -------------------------------------------------

	Locations[n].id = "Oxbay_HouseInsideR5";
	Locations[n].id.label = "House";
	Locations[n].image = "loading\House_03.tga";

	//Town sack
	Locations[n].townsack = "Oxbay";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Oxbay";
	//Models
	//Always
	Locations[n].filespath.models = "locations\inside\Smallhome";
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
	Locations[n].models.back = "back\oxsh_";

	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Oxbay_town";
	Locations[n].reload.l1.emerge = "reload5";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Oxbay";
	Locations[n].locators_radius.reload.reload1 = 0.8;
	n = n + 1;

	// ******************************************************************************************

	Locations[n].id = "Oxbay_HouseInsideR9";
	Locations[n].id.label = "House";
	Locations[n].image = "loading\room.tga";

	//Town sack
	Locations[n].townsack = "Oxbay";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Oxbay";
	//Models
	//Always
	Locations[n].filespath.models = "locations\inside\MediumHouse";
	Locations[n].models.always.locators = "mh_l";
	Locations[n].models.always.house = "mh";
	Locations[n].models.always.window = "mh_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "mh_p";

	//Night
	Locations[n].models.night.charactersPatch = "mh_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\oxmh_";

	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Oxbay_town";
	Locations[n].reload.l1.emerge = "reload9";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Oxbay";
	Locations[n].locators_radius.reload.reload1 = 0.8;
	n = n + 1;

	// -------------------------------------------------

	Locations[n].id = "Oxbay_HouseInsideR8";
	Locations[n].id.label = "House";
	Locations[n].image = "loading\House_04.tga";

	//Town sack
	Locations[n].townsack = "Oxbay";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Oxbay";
	//Models
	//Always
	Locations[n].filespath.models = "locations\inside\mh10";
	Locations[n].models.always.locators = "mh10_l";
	Locations[n].models.always.house = "mh10";
	Locations[n].models.always.window = "mh10_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "mh10_p";

	//Night
	Locations[n].models.night.charactersPatch = "mh10_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\oxmh10_";

	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Oxbay_town";
	Locations[n].reload.l1.emerge = "reload8";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Oxbay";
	Locations[n].locators_radius.reload.reload1 = 0.8;
	n = n + 1;

	// -------------------------------------------------

	Locations[n].id = "Oxbay_HouseInsideR17";
	Locations[n].id.label = "House";
	Locations[n].image = "loading\House_04.tga";

	//Town sack
	Locations[n].townsack = "Oxbay";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Oxbay";
	//Models
	//Always
	Locations[n].filespath.models = "locations\inside\mh7";
	Locations[n].models.always.locators = "mh7_l";
	Locations[n].models.always.house = "mh7";
	Locations[n].models.always.window = "mh7_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "mh7_p";

	//Night
	Locations[n].models.night.charactersPatch = "mh7_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\oxmh7_";

	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Oxbay_town";
	Locations[n].reload.l1.emerge = "reload17";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Oxbay";
	Locations[n].locators_radius.reload.reload1 = 0.8;
	n = n + 1;

	// ************************************************************-------------------------------------------------



	Locations[n].filespath.models = "locations\Outside\Jungle_1";

	Locations[n].id = "Oxbay_Jungle_01";
	locations[n].id.label = "Oxbay jungles";
	Locations[n].image = "loading\Oxbay_Jungle_01.tga";
	//Sound
	locations[n].type = "jungle";

	//Models
	//Always
	Locations[n].models.always.locators = "jungle01_l";
	Locations[n].models.always.jungle = "jungle01";
	Locations[n].models.always.grassPatch = "jungle01_g";
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
	Locations[n].models.day.charactersPatch = "jungle01_p";
	//Night
	Locations[n].models.night.charactersPatch = "jungle01_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";

	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Oxbay_town_exit";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload1 = 3.0;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Oxbay_shore_01";
	Locations[n].reload.l2.emerge = "locator3";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Far Beach.";
	Locations[n].locators_radius.reload.Reload2 = 3.0;

	Locations[n].reload.l3.name = "reload1_back";
	Locations[n].reload.l3.go = "Oxbay_town_exit";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1_back = 2.0;

	Locations[n].reload.l4.name = "reload2_back";
	Locations[n].reload.l4.go = "Oxbay_shore_01";
	Locations[n].reload.l4.emerge = "locator3";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Far Beach.";
	Locations[n].locators_radius.reload.reload2_back = 2.0;

	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Shore_1";

	Locations[n].id = "Oxbay_shore_01";
	locations[n].id.label = "Oxbay shore";
	locations[n].worldmap = "OShore 1";
	Locations[n].image = "loading\oxbay_shore_01.tga";
	Locations[n].name = "Far Beach";
	//Sound
	locations[n].type = "seashore";
	//Models
	//Always
	Locations[n].models.always.locators = "Shore01_l";
	Locations[n].models.always.shore = "Shore01";
	Locations[n].models.always.shore.foam = "1";
	Locations[n].models.always.seabed = "Shore01_sb";
	Locations[n].models.always.seabed.foam = "1";
	Locations[n].models.always.grassPatch = "Shore01_g";
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
	Locations[n].models.day.charactersPatch = "Shore01_p";
	//Night
	Locations[n].models.night.charactersPatch = "Shore01_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map
	Locations[n].reload.l1.name = "locator3";
	Locations[n].reload.l1.go = "Oxbay_Jungle_01";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Джунгли.";
	Locations[n].locators_radius.reload.locator3 = 2.0;

	Locations[n].reload.l2.name = "locator3_back";
	Locations[n].reload.l2.go = "Oxbay_Jungle_01";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Джунгли.";
	Locations[n].locators_radius.reload.locator3_back = 1.0;

	Locations[n].reload.l3.name = "boat";
	Locations[n].reload.l3.go = "Oxbay";
	Locations[n].reload.l3.emerge = "reload_5";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Море.";
	Locations[n].locators_radius.reload.boat = 9.0;

	n = n + 1;


	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Jungle_3";

	Locations[n].id = "Oxbay_Jungle_02";
	locations[n].id.label = "Oxbay jungles";
	Locations[n].image = "loading\oxbay_jungle_02.tga";
	//Sound
	locations[n].type = "jungle";
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);

	//Models
	//Always
	Locations[n].models.always.locators = "Jungle03_l";
	Locations[n].models.always.jungle = "Jungle03";
	Locations[n].models.always.grassPatch = "JUNGLE03_g";
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
	Locations[n].models.day.charactersPatch = "Jungle03_p";
	//Night
	Locations[n].models.night.charactersPatch = "Jungle03_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Oxbay_jungle_03";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload1 = 1.0;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Oxbay_Town_exit";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload2 = 3.0;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Oxbay_Cave_exit";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload3 = 3.0;

	Locations[n].reload.l4.name = "reload1_back";
	Locations[n].reload.l4.go = "Oxbay_jungle_03";
	Locations[n].reload.l4.emerge = "reload2";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1_back = 2.0;

	Locations[n].reload.l5.name = "reload2_back";
	Locations[n].reload.l5.go = "Oxbay_Town_exit";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].reload.l5.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2_back = 3.0;

	Locations[n].reload.l6.name = "reload3_back";
	Locations[n].reload.l6.go = "Oxbay_Cave_exit";
	Locations[n].reload.l6.emerge = "reload2";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].reload.l6.label = "Jungle.";
	Locations[n].locators_radius.reload.reload3_back = 3.0;

	n = n + 1;


	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Cave Entrance";

	Locations[n].id = "Oxbay_Cave_Exit";
	locations[n].id.label = "Oxbay cave entrance";
	Locations[n].image = "loading\Oxbay_Cave.tga";
	//Sound
	locations[n].type = "jungle";
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);

	//Models
	//Always
	Locations[n].models.always.locators = "Cave_l";
	Locations[n].models.always.cave = "Cave";
	Locations[n].models.always.grassPatch = "CAVE_g";
	Locations[n].models.always.l1 = "cave_b01";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "cave_b02";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "cave_b03";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";
	Locations[n].models.always.l4 = "cave_b04";
	Locations[n].models.always.l4.level = 6;
	Locations[n].models.always.l4.tech = "LocationModelBlend";
	//Day
	Locations[n].models.day.charactersPatch = "Cave_p";
	//Night
	Locations[n].models.night.charactersPatch = "Cave_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map

	Locations[n].reload.l3.name = "reload1";
	Locations[n].reload.l3.go = "Oxbay_Cave";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Cave.";
	Locations[n].locators_radius.reload.Reload1 = 1;

	Locations[n].reload.l3.name = "reload1_back";
	Locations[n].reload.l3.go = "Oxbay_Cave";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Cave.";
	Locations[n].locators_radius.reload.Reload1_back = 1.3;

	Locations[n].reload.l1.name = "reload2";
	Locations[n].reload.l1.go = "Oxbay_Jungle_02";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload2 = 2.0;

	Locations[n].reload.l2.name = "reload2_back";
	Locations[n].reload.l2.go = "Oxbay_Jungle_02";
	Locations[n].reload.l2.emerge = "reload3";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2_back = 2.0;

	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Jungle_5";

	Locations[n].id = "Oxbay_jungle_03";
	locations[n].id.label = "Oxbay jungles";
	Locations[n].image = "loading\oxbay_jungle_03.tga";
	//Sound
	locations[n].type = "jungle";
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);

	//Models
	//Always
	Locations[n].models.always.locators = "Jungle05_l";
	Locations[n].models.always.jungle = "Jungle05";
	Locations[n].models.always.grassPatch = "JUNGLE05_g";
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
	Locations[n].models.day.charactersPatch = "Jungle05_p";
	//Night
	Locations[n].models.night.charactersPatch = "Jungle05_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Oxbay_shore_02";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Gray Rock Bay.";
	Locations[n].locators_radius.reload.Reload1 = 3.0;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Oxbay_Jungle_02";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload2 = 3.0;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Greenford_town_exit";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "To Greenford.";
	Locations[n].locators_radius.reload.Reload3 = 3.0;

	Locations[n].reload.l4.name = "reload1_back";
	Locations[n].reload.l4.go = "Oxbay_shore_02";
	Locations[n].reload.l4.emerge = "reload2";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Gray Rock Bay.";
	Locations[n].locators_radius.reload.Reload1_back = 2.0;

	Locations[n].reload.l5.name = "reload2_back";
	Locations[n].reload.l5.go = "Oxbay_Jungle_02";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].reload.l5.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload2_back = 2.0;

	Locations[n].reload.l6.name = "reload3_back";
	Locations[n].reload.l6.go = "Greenford_town_exit";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].reload.l6.label = "To Greenford.";
	Locations[n].locators_radius.reload.Reload3_back = 2.0;

	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Shore_2";

	Locations[n].id = "Oxbay_shore_02";
	locations[n].id.label = "Oxbay shore";
	locations[n].worldmap = "OShore 2";
	Locations[n].image = "loading\Oxbay_Shore_02.tga";
	Locations[n].name = "Gray Rock Bay";
	//Sound
	locations[n].type = "seashore";
	//Models
	//Always
	Locations[n].models.always.jungle = "Shore02";
	Locations[n].models.always.jungle.foam = "1";
	Locations[n].models.always.locators = "Shore02_l";
	Locations[n].models.always.grassPatch = "Shore02_g";
	Locations[n].models.always.seabed = "Shore02_sb";
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
	Locations[n].models.day.charactersPatch = "Shore02_p";
	//Night
	Locations[n].models.night.charactersPatch = "Shore02_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map
	Locations[n].reload.l1.name = "reload2";
	Locations[n].reload.l1.go = "Oxbay_Jungle_03";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Джунгли.";
	Locations[n].locators_radius.reload.reload2 = 3.0;

	Locations[n].reload.l3.name = "reload2_back";
	Locations[n].reload.l3.go = "Oxbay_Jungle_03";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Джунгли.";
	Locations[n].locators_radius.reload.reload2_back = 3.0;

	Locations[n].reload.l2.name = "boat";
	Locations[n].reload.l2.go = "Oxbay";
	Locations[n].reload.l2.emerge = "reload_3";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Море.";
	Locations[n].locators_radius.reload.boat = 9.0;

	n = n + 1;



//____________________________________________________// -------------------------------------------------

	Locations[n].filespath.models = "locations\town_Greenford\port";
	Locations[n].image = "loading\greenford_port.tga";

	Locations[n].id = "Greenford_port";
	locations[n].id.label = "Greenford port";
	locations[n].worldmap = "Greenford";

	//Town sack
	Locations[n].townsack = "Greenford";

	//Sound
	locations[n].type = "port";
	locations[n].fastreload = "Greenford";
	LAi_LocationFantomsGen(&locations[n], true);
	//Models
	//Always
	Locations[n].models.always.locators = "GrPort_l";
	Locations[n].models.always.l1 = "GrPort";
	Locations[n].models.always.l1.foam = "1";
	Locations[n].models.always.seabed = "GrPort_sb";
	Locations[n].models.always.seabed.foam = "1";
	Locations[n].models.always.grassPatch = "GrPort_g";
	//Day
	Locations[n].models.day.charactersPatch = "GrPort_p";
	Locations[n].models.day.fonar = "GrPort_fd";
	//Night
	Locations[n].models.night.charactersPatch = "GrPort_p";
	Locations[n].models.night.fonar= "GrPort_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map

	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Oxbay";
	Locations[n].reload.l1.emerge = "reload_1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Sea.";
	Locations[n].locators_radius.reload.Reload1 = 3.0;


	Locations[n].reload.l3.name = "reload1_back";
	Locations[n].reload.l3.go = "Oxbay";
	Locations[n].reload.l3.emerge = "reload_1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Sea.";
	Locations[n].locators_radius.reload.reload1_back = 3.0;

	Locations[n].reload.l2.name = "reload4";
	Locations[n].reload.l2.go = "Greenford_town";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Greenford.";

	n = n + 1;


	// -------------------------------------------------

	Locations[n].filespath.models = "locations\town_Greenford\town";
	Locations[n].image = "loading\greenford_town.tga";

	Locations[n].id = "Greenford_town";
	locations[n].id.label = "Greenford";
	locations[n].worldmap = "Greenford";

	//Town sack
	Locations[n].townsack = "Greenford";

	//Sound
	locations[n].type = "town";
	locations[n].fastreload = "Greenford";
	//Models
	//Always
	Locations[n].models.always.locators = "GrTown_l";
	Locations[n].models.always.town = "GrTown";
	Locations[n].models.always.grassPatch = "GrTown_g";
	Locations[n].models.always.l1 = "grtown_b02";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "grtown_b03";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "grtown_b04";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";	//Day
	Locations[n].models.day.rinok = "GrTown_e01";
	Locations[n].models.day.fonar = "GrTown_fd";
	Locations[n].models.day.charactersPatch = "GrTown_pd";
	Locations[n].models.day.jumpPatch = "GrTown_j";
	//Night
	Locations[n].models.night.fonar = "GrTown_fn";
	Locations[n].models.night.charactersPatch = "GrTown_pn";
	Locations[n].models.night.jumpPatch = "GrTown_j";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	LAi_LocationFantomsGen(&locations[n], true);
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Greenford_port";
	Locations[n].reload.l1.emerge = "Reload4";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Port.";

	Locations[n].reload.l2.name = "reload19";
	Locations[n].reload.l2.go = "Greenford_town_exit";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Jungle.";

	Locations[n].reload.l3.name = "reload26";
	Locations[n].reload.l3.go = "Oxbay_Canyon";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Canyon. Mines.";

	Locations[n].reload.l4.name = "reload7";
	Locations[n].reload.l4.go = "Greenford_tavern";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "Tavern.";

	Locations[n].reload.l5.name = "reload6";
	Locations[n].reload.l5.go = "Greenford_InsideHouseR6";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "House.";

	Locations[n].reload.l6.name = "reload14";
	Locations[n].reload.l6.go = "Greenford_InsideHouseR14";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "House.";

	Locations[n].reload.l7.name = "reload23";
	Locations[n].reload.l7.go = "Greenford_Store";
	Locations[n].reload.l7.emerge = "reload1";
	Locations[n].reload.l7.autoreload = "0";
	Locations[n].reload.l7.label = "Store.";
	Locations[n].reload.l7.close_for_night = 1;

	Locations[n].reload.l8.name = "reload3";
	Locations[n].reload.l8.go = "Greenford_Shipyard";
	Locations[n].reload.l8.emerge = "reload1";
	Locations[n].reload.l8.autoreload = "0";
	Locations[n].reload.l8.label = "Shipyard.";
	Locations[n].reload.l8.close_for_night = 1;

  	Locations[n].reload.l9.name = "reload27";
	Locations[n].reload.l9.go = "Greenford_prison";
	Locations[n].reload.l9.emerge = "reload1";
	Locations[n].reload.l9.autoreload = "0";
	Locations[n].reload.l9.label = "Prison.";
	Locations[n].reload.l9.close_for_night = 1;

	Locations[n].reload.l10.name = "reload17";// Mosh
	Locations[n].reload.l10.go = "Greenford_house_Figuiera";
	Locations[n].reload.l10.emerge = "reload1";
	Locations[n].reload.l10.autoreload = "0";
	Locations[n].reload.l10.label = "House.";
	Locations[n].reload.l10.close_for_night = 1;

	Locations[n].reload.l11.name = "reload15";
	Locations[n].reload.l11.go = "Greenford_church";
	Locations[n].reload.l11.emerge = "reload1";
	Locations[n].reload.l11.autoreload = "0";
	Locations[n].reload.l11.label = "Church.";
	Locations[n].reload.l11.close_for_night = 1;

	Locations[n].reload.l12.name = "reload9";
	Locations[n].reload.l12.go = "Greenford_UsurerHouse";
	Locations[n].reload.l12.emerge = "reload1";
	Locations[n].reload.l12.autoreload = "0";
	Locations[n].reload.l12.label = "Loanshark's Office.";
	Locations[n].reload.l12.close_for_night = 1;

	Locations[n].reload.l13.name = "reload11";
	Locations[n].reload.l13.go = "Yedam Kinne_house";
	Locations[n].reload.l13.emerge = "reload1";
	Locations[n].reload.l13.autoreload = "0";
	Locations[n].reload.l13.label = "House of Yedam Kinne.";

	Locations[n].reload.l14.name = "reload28";
	Locations[n].reload.l14.go = "Greenford_InsideHouseR28";
	Locations[n].reload.l14.emerge = "reload1";
	Locations[n].reload.l14.autoreload = "0";
	Locations[n].reload.l14.label = "House.";

	Locations[n].reload.l15.name = "reload25";
	Locations[n].reload.l15.go = "Greenford_InsideHouseR25";
	Locations[n].reload.l15.emerge = "reload1";
	Locations[n].reload.l15.autoreload = "0";
	Locations[n].reload.l15.label = "House.";

	Locations[n].reload.l16.name = "reload22";
	Locations[n].reload.l16.go = "Greenford_InsideHouseR22";
	Locations[n].reload.l16.emerge = "reload1";
	Locations[n].reload.l16.autoreload = "0";
	Locations[n].reload.l16.label = "House.";

//Hitman

	Locations[n].reload.l5.name = "reload5";
	Locations[n].reload.l5.go = "Hit_house1";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "House of Geffrey Bampfylde";

//Hitman

	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\town_Greenford\exit";

	Locations[n].id = "Greenford_town_exit";
	locations[n].id.label = "Exit from Greenford";
	Locations[n].image = "loading\greenford_exit.tga";

	//Town sack
	Locations[n].townsack = "Greenford";

	//Sound
	locations[n].type = "jungle";
//	locations[n].fastreload = "Greenford";
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);

	//Models
	//Always
	Locations[n].models.always.locators = "GrExit_l";
	Locations[n].models.always.exit = "GrExit";
	Locations[n].models.always.grassPatch = "GrExit_g";
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
	Locations[n].models.day.charactersPatch = "GrExit_p";
	Locations[n].models.day.fonar = "GrExit_fd";
	//Night
	Locations[n].models.night.charactersPatch = "GrExit_p";
	Locations[n].models.night.fonar = "GrExit_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "Reload2";
	Locations[n].reload.l1.go = "Greenford_town";
	Locations[n].reload.l1.emerge = "reload19";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Greenford.";

	Locations[n].reload.l2.name = "Reload1";
	Locations[n].reload.l2.go = "Oxbay_Jungle_03";
	Locations[n].reload.l2.emerge = "reload3";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload1 = 3;

	Locations[n].reload.l3.name = "Reload1_back";
	Locations[n].reload.l3.go = "Oxbay_Jungle_03";
	Locations[n].reload.l3.emerge = "reload3";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload1_back = 3;

	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\shipyard3";

	Locations[n].id = "Greenford_shipyard";
	locations[n].id.label = "Greenford shipyard";
	Locations[n].image = "loading\Shipyard_02.tga";

	//Town sack
	Locations[n].townsack = "Greenford";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Greenford";
	//Models
	//Always
	Locations[n].models.always.locators = "sh03_l";
	Locations[n].models.always.l1 = "Sh03";
	Locations[n].models.always.window = "sh03_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;

	//Day
	Locations[n].models.day.charactersPatch = "Sh03_p";

	//Night
	Locations[n].models.night.charactersPatch = "Sh03_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\grsh3_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Greenford_town";
	Locations[n].reload.l1.emerge = "Reload3";
	Locations[n].reload.l1.label = "Greenford.";
	Locations[n].reload.l1.autoreload = "0";
	LAi_LocationFightDisable(&Locations[n], true);

	n = n + 1;


	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\MediumStore";
	Locations[n].image = "loading\store_02.tga";

	Locations[n].id = "Greenford_Store";
	locations[n].id.label = "Greenford store";

	//Town sack
	Locations[n].townsack = "Greenford";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Greenford";
	//Models
	//Always
	Locations[n].models.always.locators = "MS_l";
	Locations[n].models.always.store = "MS";
	Locations[n].models.always.window = "MS_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;

	//Day
	Locations[n].models.day.charactersPatch = "MS_p";

	//Night
	Locations[n].models.night.charactersPatch = "MS_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\grms_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Greenford_town";
	Locations[n].reload.l1.emerge = "Reload23";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Greenford.";
	Locations[n].locators_radius.camdetector.camera1 = 5;
	LAi_LocationFightDisable(&Locations[n], true);

	n = n + 1;


// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\MediumTavern";

	Locations[n].id = "Greenford_Tavern";
	locations[n].id.label = "Greenford tavern";
	Locations[n].image = "loading\Tavern_02.tga";

	//Town sack
	Locations[n].townsack = "Greenford";

	//Sound
	locations[n].type = "tavern";
	locations[n].fastreload = "Greenford";
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
	Locations[n].models.back = "back\grmt_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Greenford_Town";
	Locations[n].reload.l1.emerge = "reload7";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Greenford.";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Greenford_tavern_upstairs";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Room.";
	Locations[n].reload.l2.disable = true;
	LAi_LocationFightDisable(&Locations[n], true);

	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "Greenford_tavern_upstairs";
	locations[n].id.label = "Room in Greenford tavern";
	Locations[n].image = "loading\Tavern_Upstairs_01.tga";

	//Town sack
	Locations[n].townsack = "Greenford";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Oxbay";
	//Models
	//Always
	Locations[n].filespath.models = "locations\inside\Doubleflour_house";
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
	Locations[n].models.back = "back\grlf2_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Greenford_tavern";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Tavern.";
	Locations[n].locators_radius.reload.reload1 = 0.8;
	n = n + 1;

	// -------------------------------------------------

	Locations[n].id = "Greenford_UsurerHouse";
	locations[n].id.label = "Loanshark's Office.";
	Locations[n].filespath.models = "locations\inside\MediumHouse";
	Locations[n].image = "loading\room.tga";

	//Town sack
	Locations[n].townsack = "Greenford";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Greenford";
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
	Locations[n].models.back = "back\grmh_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Greenford_town";
	Locations[n].reload.l1.emerge = "reload9";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Greenford";
	Locations[n].locators_radius.reload.reload1 = 0.8;
	LAi_LocationFightDisable(&Locations[n], true);


	n = n + 1;

	//_____________________________________________________

	Locations[n].filespath.models = "locations\Inside\mh4";

	Locations[n].id = "Greenford_InsideHouseR6";
	locations[n].id.label = "House";
	Locations[n].image = "loading\house_05.tga";

	//Town sack
	Locations[n].townsack = "Greenford";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Greenford";
	//Models
	//Always
	Locations[n].models.always.locators = "mh4_l";
	Locations[n].models.always.l1 = "mh4";
	Locations[n].models.always.window = "mh4_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;

	//Day
	Locations[n].models.day.charactersPatch = "mh4_p";

	//Night
	Locations[n].models.night.charactersPatch = "mh4_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\grmh4_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Greenford_Town";
	Locations[n].reload.l1.emerge = "reload6";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Greenford.";

	n = n + 1;

	//_____________________________________________________

	Locations[n].filespath.models = "locations\Inside\mh9";

	Locations[n].id = "Greenford_InsideHouseR28";
	locations[n].id.label = "House";
	Locations[n].image = "loading\house_05.tga";

	//Town sack
	Locations[n].townsack = "Greenford";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Greenford";
	//Models
	//Always
	Locations[n].models.always.locators = "mh9_l";
	Locations[n].models.always.l1 = "mh9";
	Locations[n].models.always.window = "mh9_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;

	//Day
	Locations[n].models.day.charactersPatch = "mh9_p";

	//Night
	Locations[n].models.night.charactersPatch = "mh9_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\grmh9_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Greenford_Town";
	Locations[n].reload.l1.emerge = "reload28";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Greenford.";

	n = n + 1;

	//--------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\mh8";

	Locations[n].id = "Greenford_InsideHouseR25";
	locations[n].id.label = "House";
	Locations[n].image = "loading\House_06.tga";

	//Town sack
	Locations[n].townsack = "Greenford";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Greenford";
	//Models
	//Always
	Locations[n].models.always.locators = "mh8_l";
	Locations[n].models.always.l1 = "mh8";
	Locations[n].models.always.window = "mh8_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;

	//Day
	Locations[n].models.day.charactersPatch = "mh8_p";

	//Night
	Locations[n].models.night.charactersPatch = "mh8_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\grmh8_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Greenford_Town";
	Locations[n].reload.l1.emerge = "reload25";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Greenford.";

	Locations[n].locators_radius.camdetector.camera1 = 3.0;
	Locations[n].locators_radius.camdetector.camera2 = 1.8;

	n = n + 1;

	//_____________________________________________________

	Locations[n].filespath.models = "locations\Inside\mh9";

	Locations[n].id = "Greenford_InsideHouseR22";
	locations[n].id.label = "House";
	Locations[n].image = "loading\house_05.tga";

	//Town sack
	Locations[n].townsack = "Greenford";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Greenford";
	//Models
	//Always
	Locations[n].models.always.locators = "mh9_l";
	Locations[n].models.always.l1 = "mh9";
	Locations[n].models.always.window = "mh9_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;

	//Day
	Locations[n].models.day.charactersPatch = "mh9_p";

	//Night
	Locations[n].models.night.charactersPatch = "mh9_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\grmh9_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Greenford_Town";
	Locations[n].reload.l1.emerge = "reload22";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Greenford.";

	n = n + 1;


	//_____________________________________________________

	Locations[n].filespath.models = "locations\Inside\Doubleflour_house";

	Locations[n].id = "Greenford_InsideHouseR14";
	locations[n].id.label = "House";
	Locations[n].image = "loading\house_08.tga";

	//Town sack
	Locations[n].townsack = "Greenford";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Greenford";
	//Models
	//Always
	Locations[n].filespath.models = "locations\inside\Doubleflour_house";
	Locations[n].models.always.locators = "LH_F1_l";
	Locations[n].models.always.tavern = "LH_F1";
	Locations[n].models.always.window = "LF1_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "LH_F1_p";

	//Night
	Locations[n].models.night.charactersPatch = "LH_F1_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\grlf1_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Greenford_Town";
	Locations[n].reload.l1.emerge = "reload14";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Greenford.";

	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\outside\Canyon";

	Locations[n].id = "Oxbay_Canyon";
	locations[n].id.label = "Oxbay canyon";
	Locations[n].image = "loading\oxbay_canyon.tga";

	//Town sack
	Locations[n].townsack = "Greenford";

	//Sound
	locations[n].type = "canyon";
//	locations[n].fastreload = "Greenford";
	//Models
	//Always
	Locations[n].models.always.locators = "rift_l";
	Locations[n].models.always.rift = "rift";
	Locations[n].models.always.grassPatch = "rift_g";
	Locations[n].models.always.l1 = "plan_1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan_2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";

	//Day
	Locations[n].models.day.charactersPatch = "rift_p";
	Locations[n].models.day.fonar = "rift_fd";
	//Night
	Locations[n].models.night.charactersPatch = "rift_p";
	Locations[n].models.night.fonar = "rift_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "Reload1";
	Locations[n].reload.l1.go = "Greenford_town";
	Locations[n].reload.l1.emerge = "reload26";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Greenford.";
	Locations[n].locators_radius.reload.reload1 = 1.0;

	Locations[n].reload.l2.name = "reload6_back";
	Locations[n].reload.l2.go = "Oxbay_Lighthouse";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Lighthouse.";
	Locations[n].locators_radius.reload.Reload6_back = 3.0;

	Locations[n].reload.l3.name = "reload4";
	Locations[n].reload.l3.go = "Oxbay_Mine";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Mines.";

	Locations[n].reload.l4.name = "reload5";
	Locations[n].reload.l4.go = "Mines_commander_house";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "Mines Office.";

	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\outside\Mayak";

	Locations[n].id = "Oxbay_Lighthouse";
	Locations[n].name = "Lighthouse";
	locations[n].id.label = "Oxbay lighthouse";
	locations[n].worldmap = "Lighthouse";
	Locations[n].image = "loading\Oxbay_Lighthouse.tga";
	//Sound
	locations[n].type = "seashore";
	//Models
	//Always
	Locations[n].models.always.locators = "mayak_l";
	Locations[n].models.always.shore = "mayak";
	Locations[n].models.always.shore.foam = "1";
	Locations[n].models.always.seabed = "Mayak_sb";
	Locations[n].models.always.seabed.foam = "1";
	Locations[n].models.always.grassPatch = "Mayak_g";

	//Day
	Locations[n].models.day.charactersPatch = "mayak_p";
	Locations[n].models.day.fonar = "Mayak_fd";
	//Night
	Locations[n].models.night.charactersPatch = "mayak_p";
	Locations[n].models.night.fonar = "Mayak_fn";
	Locations[n].models.night.window = "Mayak_win";
	Locations[n].models.night.light = "Mayak_fl";
	Locations[n].models.night.light.level = 80;
	Locations[n].models.night.light.tech = "LighthouseLight";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Oxbay_Canyon";
	Locations[n].reload.l1.emerge = "reload6";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Canyon. Mines.";
	Locations[n].locators_radius.reload.Reload1 = 3.0;

	Locations[n].reload.l3.name = "reload1_back";
	Locations[n].reload.l3.go = "Oxbay_Canyon";
	Locations[n].reload.l3.emerge = "reload6";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Canyon. Mines.";
	Locations[n].locators_radius.reload.reload1_back = 3.0;

	Locations[n].reload.l2.name = "boat";
	Locations[n].reload.l2.go = "Oxbay";
	Locations[n].reload.l2.emerge = "Reload_4";
	Locations[n].reload.l2.label = "Sea.";
	Locations[n].locators_radius.reload.boat = 12.0;

	Locations[n].reload.l4.name = "reload5";
	Locations[n].reload.l4.go = "Lighthouse_Inside";
	Locations[n].reload.l4.emerge = "Reload1";
	Locations[n].reload.l4.label = "Lighthouse Inside.";
//	Locations[n].reload.l4.close_for_night = 1;
	Locations[n].reload.l4.disable = 1;

	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\outside\Mayak_inside";

	Locations[n].id = "Lighthouse_Inside";
	Locations[n].name = "Lighthouse Inside";
	locations[n].id.label = "Oxbay lighthouse Inside";
	Locations[n].image = "loading\Oxbay_Lighthouse.tga";
	//Sound
	locations[n].type = "house";

	Locations[n].models.always.l1 = "plan_1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan_2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.shore = "imayak";
	Locations[n].models.always.shore.foam = "1";
	Locations[n].models.always.seabed = "iMayak_sb";
	Locations[n].models.always.seabed.foam = "1";
	//Models
	//Always
	Locations[n].models.always.locators = "imayak_l";
	Locations[n].models.always.shore = "imayak";
	Locations[n].models.always.window = "iMayak_w";
	//Day
	Locations[n].models.day.charactersPatch = "imayak_p";
	Locations[n].models.day.jumpPatch = "imayak_j";
	//Night
	Locations[n].models.night.charactersPatch = "imayak_p";
	Locations[n].models.night.jumpPatch = "imayak_j";

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Oxbay_Lighthouse";
	Locations[n].reload.l1.emerge = "reload5";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Oxbay_lighthouse";
	Locations[n].locators_radius.reload.Reload1 = 1.5;

	Locations[n].items.randitem1 = "spyglass4";

	n = n + 1;

// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\Mine";

	Locations[n].id = "Oxbay_mine";
	locations[n].id.label = "Oxbay mine";
	Locations[n].image = "loading\Oxbay_Mine.tga";

	//Sound
	locations[n].type = "cave";
	//Models
	//Always
	Locations[n].models.always.locators = "mine_l";
	Locations[n].models.always.l1 = "mine";
	//Day
	Locations[n].models.day.charactersPatch = "mine_p";
	//Night
	Locations[n].models.night.charactersPatch = "mine_p";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Oxbay_Canyon";
	Locations[n].reload.l1.emerge = "reload4";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Canyon. Mines.";

	Locations[n].reload.l2.name = "reload1_back";
	Locations[n].reload.l2.go = "Oxbay_Canyon";
	Locations[n].reload.l2.emerge = "reload4";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Canyon. Mines.";


/*	Locations[n].reload.l2.name = "reload1";
	Locations[n].reload.l2.go = "Oxbay_Lighthouse";
	Locations[n].reload.l2.emerge = "locator1";*/

	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "Greenford_prison";
	locations[n].id.label = "Greenford prison";
	Locations[n].filespath.models = "locations\inside\prison";
	Locations[n].image = "loading\prison_01.tga";

	//Town sack
	Locations[n].townsack = "Greenford";

	//Sound
	locations[n].type = "jail";
	LAi_LocationFantomsGen(&locations[n], true);
	//locations[n].fastreload = "Greenford";

	Locations[n].locators_radius.camdetector.camera13 = 2.5;//Mosh
	Locations[n].locators_radius.camdetector.camera12 = 0.5;//Mosh
	//Models
	//Always
	Locations[n].models.always.prison = "Pri";
	Locations[n].models.always.locators = "Pri_l";
	Locations[n].models.always.window = "Pri_w";
	//Locations[n].models.always.flame = "prison_flame";
	//Day
	Locations[n].models.day.charactersPatch = "Pri_p";
	//Night
	Locations[n].models.night.charactersPatch = "Pri_p";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Greenford_town";
	Locations[n].reload.l1.emerge = "reload27";
	Locations[n].reload.l1.label = "Greenford.";
	LAi_LocationFightDisable(&Locations[n], true);
	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "Mines_commander_house";
	locations[n].label = "House начальника рудников";
	Locations[n].filespath.models = "locations\inside\smallhome\";
	Locations[n].image = "loading\house_03.tga";
	//Sound
	locations[n].type = "house";
	//Models
	//Always
	Locations[n].models.always.locators = "SH_l";
	Locations[n].models.always.house = "SH";
	//Locations[n].models.always.env = "smallhome_FF_02_env";
	Locations[n].models.always.window = "Sh_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "Sh_p";

	//Night
	Locations[n].models.night.charactersPatch = "Sh_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\pifsh_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Oxbay_canyon";
	Locations[n].reload.l1.emerge = "reload5";
	Locations[n].locators_radius.reload.reload1 = 0.8;
	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "Yedam Kinne_house";
	locations[n].label = "Yedam Kinne's house";
	Locations[n].filespath.models = "locations\inside\smallhome\";
	Locations[n].image = "loading\House_02.tga";

	//Town sack
	Locations[n].townsack = "Greenford";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Greenford";
	//Models
	//Always
	Locations[n].models.always.locators = "SH_l";
	Locations[n].models.always.house = "SH";
	//Locations[n].models.always.env = "smallhome_FF_02_env";
	Locations[n].models.always.window = "Sh_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "Sh_p";

	//Night
	Locations[n].models.night.charactersPatch = "Sh_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\grsh_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Greenford_town";
	Locations[n].reload.l1.emerge = "reload11";
	Locations[n].locators_radius.reload.reload1 = 0.8;
	n = n + 1;

	// Greenford_church -------------------------------------------------
	Locations[n].id = "Greenford_church";
	locations[n].id.label = "Greenford's church";
	Locations[n].image = "loading\Small_Churche.tga";
	Locations[n].filespath.models = "locations\inside\Church_2\";

	//Town sack
	Locations[n].townsack = "Greenford";

	//Sound
	locations[n].type = "church";
	locations[n].fastreload = "Greenford";
	//Models
	//Always
	Locations[n].models.always.city = "Church2";
	Locations[n].models.always.locators = "Church2_l";
	Locations[n].models.always.window = "church2_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
//	Locations[n].models.day.lamp = "FalaiseDeFleur05_day";
	Locations[n].models.day.charactersPatch = "Church2_p";

	//Night
//	Locations[n].models.night.lamp = "FalaiseDeFleur05_night";
	Locations[n].models.night.charactersPatch = "Church2_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Greenford_town";
	Locations[n].reload.l1.emerge = "reload15";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Greenford";
	LAi_LocationFightDisable(&Locations[n], true);


	n = n + 1;

	// -----------------Mosh D24--------------------
	Locations[n].filespath.models = "locations\Inside\MediumHouse";
	Locations[n].id = "Greenford_house_Figuiera";
	Locations[n].image = "loading\room.tga";

	//Town sack
	Locations[n].townsack = "Greenford";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Greenford";
	//Models
	//Always
	Locations[n].models.always.locators = "MH_l";
	Locations[n].models.always.house = "MH";
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
	Locations[n].models.back = "back\grmh_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Greenford_town";//Mosh
	Locations[n].reload.l1.emerge = "reload17";
	LAi_LocationFightDisable(&Locations[n], true);

	n = n + 1;

	// -----------------Mosh D24--------------------
	Locations[n].filespath.models = "locations\Inside\Dungeon_1";
	Locations[n].id = "Dungeon 1";
	Locations[n].image = "loading\Dungeon 01.tga";
	Locations[n].monsters = "1";

	//Town sack
	Locations[n].townsack = "Oxbay";

	//Sound
	locations[n].type = "Dungeon";
	locations[n].fastreload = "Oxbay";
	//Models
	//Always
	Locations[n].models.always.locators = "d01_l";
	Locations[n].models.always.house = "d01";
	//Day
	Locations[n].models.day.charactersPatch = "d01_p";
	//Night
	Locations[n].models.night.charactersPatch = "d01_p";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	LAi_LocationFantomsGen(&locations[n], true);

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Oxbay_town";
	Locations[n].reload.l1.emerge = "reload19";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Oxbay_port";
	Locations[n].reload.l2.emerge = "reload3";
	Locations[n].reload.l2.autoreload = "1";

	Locations[n].reload.l3.name = "reload2_back";
	Locations[n].reload.l3.go = "Oxbay_port";
	Locations[n].reload.l3.emerge = "reload3";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].locators_radius.reload.reload2_back = 1.5;

	Locations[n].items.randitem1 = "blade12";

	n = n + 1;

	// -----------------Mosh D24--------------------
	Locations[n].filespath.models = "locations\Inside\Dungeon_3";
	Locations[n].id = "Oxbay_cave";
	Locations[n].image = "loading\Dungeon 03.tga";
//	Locations[n].monsters = "1";

	//Sound
	locations[n].type = "Dungeon";
	//Models
	Locations[n].models.back = "back\d03env_";
	//Always
	Locations[n].models.always.locators = "d03_l";
	Locations[n].models.always.house = "d03";
	//Day
	Locations[n].models.day.charactersPatch = "d03_p";
	//Night
	Locations[n].models.night.charactersPatch = "d03_p";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Oxbay_cave_exit";//Mosh
	Locations[n].reload.l1.emerge = "reload1";

	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 0, 24);

	Locations[n].items.randitem1 = "blade21";

	n = n + 1;


	return n;
}
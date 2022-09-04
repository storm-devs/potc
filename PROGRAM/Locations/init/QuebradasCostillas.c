
int LocationInitQuebradasCostillas(int n)
{

	// -------------------------------------------------
	
	Locations[n].filespath.models = "locations\town_QC\port";	
	Locations[n].image = "loading\Quebradas Costillas_Port.tga";

	Locations[n].id = "QC_port";
	locations[n].id.label = "Quebradas Costillas port";
	locations[n].worldmap = "Quebradas Costillas";
	//Sound
	locations[n].type = "port";
	locations[n].fastreload = "QC";
	LAi_LocationFantomsGen(&locations[n], true);
	//Models
	//Always
	Locations[n].models.always.locators = "QCport_l";
	Locations[n].models.always.port = "QCport";
	Locations[n].models.always.port.foam = "1";
	Locations[n].models.always.sb = "QCport_sb";
	Locations[n].models.always.sb.foam = "1";
	Locations[n].models.always.grassPatch = "QCport_g";
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
	Locations[n].models.day.charactersPatch = "QCport_p";
	Locations[n].models.day.jumpPatch = "QCport_j";
	//Night
	Locations[n].models.night.charactersPatch = "QCport_p";
	Locations[n].models.night.jumpPatch = "QCport_j";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map

	Locations[n].reload.l1.name = "reload3";
	Locations[n].reload.l1.go = "QC_town_exit";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1 = 1.0;

	Locations[n].reload.l2.name = "reload1";
	Locations[n].reload.l2.go = "QuebradasCostillas";
	Locations[n].reload.l2.emerge = "reload_1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Sea.";
	Locations[n].locators_radius.reload.reload1 = 3.0;

	Locations[n].reload.l3.name = "reload2";
	Locations[n].reload.l3.go = "QuebradasCostillas";
	Locations[n].reload.l3.emerge = "reload_1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Sea.";
	Locations[n].locators_radius.reload.reload2 = 3.0;
	
	Locations[n].reload.l4.name = "reload3_back";
	Locations[n].reload.l4.go = "QC_town_exit";
	Locations[n].reload.l4.emerge = "reload2";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Jungle.";
	Locations[n].locators_radius.reload.reload3_back = 1.0;

	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\town_QC\town";	
	Locations[n].image = "loading\Quebradas Costillas_Town.tga";

	Locations[n].id = "QC_town";
	locations[n].id.label = "Quebradas Costillas";
	locations[n].worldmap = "Quebradas Costillas";
	//Town sack
	Locations[n].townsack = "Oxbay";
	//Sound
	locations[n].type = "town";
	locations[n].fastreload = "QC";
	LAi_LocationFantomsGen(&locations[n], true);
	//Models
	//Always
	Locations[n].models.always.locators = "QCtown_l";
	Locations[n].models.always.town = "QCtown";
	Locations[n].models.always.grassPatch = "QCtown_g";
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
	Locations[n].models.day.charactersPatch = "QCtown_p";
	Locations[n].models.day.fonar = "QCtown_fd";
	//Night
	Locations[n].models.night.charactersPatch = "QCtown_p";
	Locations[n].models.night.fonar = "QCtown_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "QC_town_exit";
	Locations[n].reload.l1.emerge = "Reload1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Jungle.";

	Locations[n].reload.l3.name = "reload2";
	Locations[n].reload.l3.go = "QC_tavern";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Tavern.";

	Locations[n].reload.l4.name = "reload5";
	Locations[n].reload.l4.go = "QC_store";
	Locations[n].reload.l4.emerge = "locator2";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "Store.";
	Locations[n].reload.l4.close_for_night = 1;

	Locations[n].reload.l6.name = "reload6";
	Locations[n].reload.l6.go = "QC_UsurerHouse";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "Loanshark's Office.";
	Locations[n].reload.l6.close_for_night = 1;

	Locations[n].reload.l8.name = "Reload4";
	Locations[n].reload.l8.go = "QC_HouseInsideR4";
	Locations[n].reload.l8.emerge = "reload1";
	Locations[n].reload.l8.autoreload = "0";
	Locations[n].reload.l8.label = "House.";
	
	Locations[n].reload.l9.name = "Reload9";
	Locations[n].reload.l9.go = "QC_HouseInsideR9";
	Locations[n].reload.l9.emerge = "reload1";
	Locations[n].reload.l9.autoreload = "0";
	Locations[n].reload.l9.label = "House.";
		
	Locations[n].reload.l7.name = "reload10";
	Locations[n].reload.l7.go = "QC_Residence";
	Locations[n].reload.l7.emerge = "reload1";
	Locations[n].reload.l7.autoreload = "0";
	Locations[n].reload.l7.label = "Pirate Chief's House.";
	Locations[n].reload.l7.close_for_night = 1;

	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\town_QC\exit";	

	Locations[n].id = "QC_town_exit";
	locations[n].id.label = "Exit from Quebradas Costillas";
	Locations[n].image = "loading\Quebradas Costillas_Town_Exit.tga";
	//Sound
	locations[n].type = "jungle";
//	locations[n].fastreload = "QC";
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);

	//Models
	//Always
	Locations[n].models.always.locators = "QCexit_l";
	Locations[n].models.always.exit = "QCexit";
	Locations[n].models.always.grassPatch = "QCexit_g";
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
	Locations[n].models.day.charactersPatch = "QCexit_p";
	//Night
	Locations[n].models.night.charactersPatch = "QCexit_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	
	Locations[n].reload.l1.name = "Reload1";
	Locations[n].reload.l1.go = "QC_town";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Quebradas Costillas.";

	Locations[n].reload.l2.name = "Reload2";
	Locations[n].reload.l2.go = "QC_port";
	Locations[n].reload.l2.emerge = "reload3";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Port.";
	Locations[n].locators_radius.reload.reload2 = 3.0;

	Locations[n].reload.l3.name = "Reload3";
	Locations[n].reload.l3.go = "QC_Pirate_House";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "House.";
	Locations[n].locators_radius.reload.reload3 = 3.0;

	Locations[n].reload.l4.name = "Reload2_back";
	Locations[n].reload.l4.go = "QC_port";
	Locations[n].reload.l4.emerge = "reload3";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Port.";
	Locations[n].locators_radius.reload.Reload2_back = 2.0;

	Locations[n].reload.l5.name = "Reload3_back";
	Locations[n].reload.l5.go = "QC_Pirate_House";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].reload.l5.label = "House.";
	Locations[n].locators_radius.reload.Reload3_back = 2.0;

	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\pirateresidence";	

	Locations[n].id = "QC_residence";
	locations[n].id.label = "House of leader Quebradas Costillas pirates";
	Locations[n].image = "loading\Pirate_Residence.tga";
	//Town sack
	Locations[n].townsack = "Oxbay";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "QC";
	//Models
	//Always
	Locations[n].models.always.locators = "resp_l";
	Locations[n].models.always.l1 = "resp";
	Locations[n].models.always.window = "resp_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;

	//Day
	Locations[n].models.day.charactersPatch = "resp_p";

	//Night
	Locations[n].models.night.charactersPatch = "resp_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\qcresp_";
	//Reload map
	Locations[n].reload.l1.name = "Reload1";
	Locations[n].reload.l1.go = "QC_town";
	Locations[n].reload.l1.emerge = "Reload10";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Кебрадас Костиллас.";

	n = n + 1;


	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\StoreSmall";	
	Locations[n].image = "loading\store_04.tga";

	Locations[n].id = "QC_Store";
	locations[n].id.label = "Quebradas Costillas store";
	//Town sack
	Locations[n].townsack = "Oxbay";
	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "QC";
	//Models
	//Always
	Locations[n].models.always.locators = "SS_l";
	Locations[n].models.always.l1 = "ss";
	Locations[n].models.always.window = "ss_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "ss_p";
	Locations[n].models.day.fonar = "SS_fn";

	//Night
	Locations[n].models.night.charactersPatch = "ss_p";
	Locations[n].models.night.fonar = "SS_fn";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\qcss_";
	//Reload map
	Locations[n].reload.l1.name = "locator2";
	Locations[n].reload.l1.go = "QC_town";
	Locations[n].reload.l1.emerge = "Reload5";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Quebradas Costillas.";
	LAi_LocationFightDisable(&Locations[n], true);

	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\SmallHome";	

	Locations[n].id = "QC_UsurerHouse";
	locations[n].id.label = "Loanshark's Office.";
	Locations[n].image = "loading\house_03.tga";
	//Town sack
	Locations[n].townsack = "Oxbay";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "QC";
	//Models	
	//Always
	Locations[n].models.always.locators = "Sh_L";
	Locations[n].models.always.l1 = "SH";
	Locations[n].models.always.window = "sh_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;

	//Day
	Locations[n].models.day.charactersPatch = "SH_p";

	//Night
	Locations[n].models.night.charactersPatch = "SH_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\qcsh_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "QC_town";
	Locations[n].reload.l1.emerge = "reload6";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Quebradas Costillas.";
	LAi_LocationFightDisable(&Locations[n], true);

	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\SmallTavern";	

	Locations[n].id = "QC_Tavern";
	locations[n].id.label = "Quebradas Costillas tavern";
	Locations[n].image = "loading\tavern_03.tga";
	//Town sack
	Locations[n].townsack = "Oxbay";
	//Sound
	locations[n].type = "tavern";
	locations[n].fastreload = "QC";
	//Models
	//Always
	Locations[n].models.always.locators = "ST_l";
	Locations[n].models.always.l1 = "ST";
	Locations[n].models.always.window = "ST_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;

	//Day
	Locations[n].models.day.charactersPatch = "ST_p";

	//Night
	Locations[n].models.night.charactersPatch = "ST_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\qcst_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "QC_town";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Quebradas Costillas.";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "QC_tavern_upstairs";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.disable = 1;
	Locations[n].reload.l2.label = "Room.";
	LAi_LocationFightDisable(&Locations[n], true);

	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\SmallHome";	

	Locations[n].id = "QC_tavern_upstairs";
	locations[n].id.label = "Room in Quebradas Costillas tavern";
	Locations[n].image = "loading\room.tga";
	//Town sack
	Locations[n].townsack = "Oxbay";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "QC";
	//Models
	//Always
	Locations[n].models.always.locators = "SH_l";
	Locations[n].models.always.l1 = "SH";
	Locations[n].models.always.window = "sh_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;

	//Day
	Locations[n].models.day.charactersPatch = "SH_p";

	//Night
	Locations[n].models.night.charactersPatch = "SH_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\qcsh_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "QC_tavern";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Tavern.";

	n = n + 1;


	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Pirate_Outer_Location";	

	Locations[n].id = "QC_Pirate_house";
	locations[n].id.label = "Entrance to strange house";
	Locations[n].image = "loading\Pirate_House.tga";
	//Sound
	locations[n].type = "jungle";
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);

	//Models
	//Always
	Locations[n].models.always.locators = "Pirl_l";
	Locations[n].models.always.house = "pirl";
	Locations[n].models.always.grassPatch = "pirl_g";
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
	Locations[n].models.day.charactersPatch = "Pirl_p";
	Locations[n].models.day.fonar = "pirl_fd";
	//Night
	Locations[n].models.night.charactersPatch = "pirl_p";
	Locations[n].models.night.fonar = "pirl_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "QC_town_exit";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "1";	
	Locations[n].reload.l1.label = "Jungle.";

	Locations[n].reload.l3.name = "reload1_back";
	Locations[n].reload.l3.go = "QC_town_exit";
	Locations[n].reload.l3.emerge = "reload3";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].locators_radius.reload.reload1_back = 3.0;
	Locations[n].reload.l3.label = "Jungle.";


	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "QC_Pirate_house_inside";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Enter.";

	n = n + 1;

	// -------------------------------------------------
	
	Locations[n].filespath.models = "locations\Inside\Pirate_House";	

	Locations[n].id = "QC_Pirate_house_inside";
	locations[n].id.label = "Inside strange house";
	Locations[n].image = "loading\room.tga";
	//Sound
	locations[n].type = "house";
	//Models
	//Always
	Locations[n].models.always.locators = "pirh_l";
	Locations[n].models.always.house = "pirh";
	Locations[n].models.always.window = "pirh_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "pirh_p";

	//Night
	Locations[n].models.night.charactersPatch = "pirh_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\qcpirh_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "QC_pirate_house";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Exit.";

	n = n + 1; 

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\Smallhome";
	Locations[n].id = "QC_HouseInsideR4";
	locations[n].id.label = "House";
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
	Locations[n].models.back = "back\qcsh_";
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "QC_town";
	Locations[n].reload.l1.emerge = "reload4";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Quebradas Costillas.";


	n = n + 1; 

	// -------------------------------------------------
	Locations[n].id = "QC_HouseInsideR9";
	locations[n].id.label = "House";
	Locations[n].image = "loading\house_07.tga";
	//Sound
	locations[n].type = "house";
	//Models
	//Always
	Locations[n].filespath.models = "locations\inside\Doubleflour_house";
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
	Locations[n].models.back = "back\qclf2_";
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "QC_town";
	Locations[n].reload.l1.emerge = "reload9";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Quebradas Costillas.";


	n = n + 1; 

	// -------------------------------------------------
	return n;
}
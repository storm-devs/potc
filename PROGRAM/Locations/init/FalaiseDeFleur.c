int LocationInitFalaiseDeFleur(int n)
{

	// Falaise_de_fleur_location_01 -------------------------------------------------
	Locations[n].id = "none";
	//Models
	//Always
	n = n + 1;

	Locations[n].id = "Falaise_de_fleur_port_01";
	locations[n].id.label = "Falaise de Fleur Port";
	locations[n].worldmap = "Falaise De Fleur";
	Locations[n].image = "loading\FF_Port_01.tga";
	Locations[n].filespath.models = "locations\Town_FalaiseDeFleur\port";
	Locations[n].music = "town.mp3";

	//Town sack
	Locations[n].townsack = "Falaise de Fleur";

	//Sound
	locations[n].type = "port";
	locations[n].fastreload = "Falaise_De_Fleur";
	//Models
	//Always
	Locations[n].models.always.city = "FFport01";
	Locations[n].models.always.city.foam = "1";
	Locations[n].models.always.seabed = "FFport01_sb";
	Locations[n].models.always.seabed.foam = "1";
	Locations[n].models.always.locators = "FFport01_l";
   	Locations[n].models.always.grassPatch = "FFport01_g";
 	//Day
	Locations[n].models.day.fonar = "FFport01_fd";
	Locations[n].models.day.charactersPatch = "FFport01_p";
  	Locations[n].models.day.jumpPatch = "FFport01_j";
	//Night
	Locations[n].models.night.fonar = "FFport01_fn";
	Locations[n].models.night.charactersPatch = "FFport01_p";
  	Locations[n].models.night.jumpPatch = "FFport01_j";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map
	LAi_LocationFantomsGen(&locations[n], true);
	Locations[n].reload.l1.name = "Falaise_de_fleur_location_01_02";
	Locations[n].reload.l1.go = "Falaise_de_fleur_location_02";
	Locations[n].reload.l1.emerge = "Falaise_de_fleur_location_02_01";
  	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Falaise De Fleur. Slums.";

	Locations[n].reload.l2.name = "werf";
	Locations[n].reload.l2.go = "Falaise_de_fleur_port_02";
	Locations[n].reload.l2.emerge = "locationext";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Beach.";
	Locations[n].locators_radius.reload.werf = 3;

	Locations[n].reload.l3.name = "sea";
	Locations[n].reload.l3.go = "FalaiseDeFleur";
	Locations[n].reload.l3.emerge = "reload_1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Sea.";
	Locations[n].locators_radius.reload.sea = 3;

	Locations[n].reload.l4.name = "werf_back";
	Locations[n].reload.l4.go = "Falaise_de_fleur_port_02";
	Locations[n].reload.l4.emerge = "locationext";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Beach.";
	Locations[n].locators_radius.reload.werf_back = 2;

	Locations[n].reload.l5.name = "sea_back";
	Locations[n].reload.l5.go = "FalaiseDeFleur";
	Locations[n].reload.l5.emerge = "reload_1";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "Sea.";
	Locations[n].locators_radius.reload.sea_back = 2;
	
	Locations[n].reload.l6.name = "shipyard";
	Locations[n].reload.l6.go = "Head_port_house";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "Head port house.";
	n = n + 1;

	// Falaise_de_fleur_location_06 -------------------------------------------------
	Locations[n].id = "Falaise_de_fleur_port_02";
	locations[n].id.label = "Falaise de Fleur beach";
	locations[n].worldmap = "Falaise De Fleur";
	Locations[n].image = "loading\FF_Port_02.tga";
	Locations[n].music = "town.mp3";

	//Town sack
	Locations[n].townsack = "Falaise de Fleur";

	//Sound
	locations[n].type = "port";
	locations[n].fastreload = "Falaise_De_Fleur";
	//Models
	//Always
	Locations[n].filespath.models = "locations\Town_FalaiseDeFleur\port2";
	Locations[n].models.always.city = "FFport02";
	Locations[n].models.always.city.foam = "1";
	Locations[n].models.always.seabed = "FFport02_sb";
	Locations[n].models.always.seabed.foam = "1";
	Locations[n].models.always.locators = "FFport02_l";
	Locations[n].models.always.grassPatch = "FFport02_g";
	//Day
	Locations[n].models.day.fonar = "FFport02_fd";
	Locations[n].models.day.charactersPatch = "FFport02_p";
	//Night
	Locations[n].models.night.fonar = "FFport02_fn";
	Locations[n].models.night.charactersPatch = "FFport02_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map
	LAi_LocationFantomsGen(&locations[n], true);
	Locations[n].reload.l1.name = "Falaise_de_fleur_location_01_05";
	Locations[n].reload.l1.go = "Falaise_de_fleur_location_05";
	Locations[n].reload.l1.emerge = "Falaise_de_fleur_location_05_01";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Falaise De Fleur. Slums.";

	Locations[n].reload.l2.name = "locationext";
	Locations[n].reload.l2.go = "Falaise_De_Fleur_port_01";
	Locations[n].reload.l2.emerge = "werf";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Port.";

	Locations[n].reload.l3.name = "locationext_back";
	Locations[n].reload.l3.go = "Falaise_De_Fleur_port_01";
	Locations[n].reload.l3.emerge = "werf";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Port.";
	Locations[n].locators_radius.reload.locationext_back = 2.5;

/*	Locations[n].reload.l3.name = "sea";
	Locations[n].reload.l3.go = "FalaiseDeFleur";
	Locations[n].reload.l3.emerge = "reload_1";
	Locations[n].reload.l3.autoreload = "1";*/
	n = n + 1;

	// Falaise_de_fleur_location_02 -------------------------------------------------
	Locations[n].id = "Falaise_de_fleur_location_02";
	locations[n].id.label = "Falaise De Fleur";
	locations[n].worldmap = "Falaise De Fleur";
	Locations[n].image = "loading\FF_Town_01.tga";

	//Town sack
	Locations[n].townsack = "Falaise de Fleur";

	//Sound
	locations[n].type = "town";
	LAi_LocationFantomsGen(&locations[n], true);
	locations[n].fastreload = "Falaise_De_Fleur";
	//Models
	//Always
	Locations[n].filespath.models = "locations\Town_FalaiseDeFleur\town_01";
	Locations[n].models.always.city = "FF01";
	Locations[n].models.always.locators = "FF01_l";
	Locations[n].models.always.grassPatch = "FF01_g";
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
	Locations[n].models.day.fonar = "FF01_fd";
	Locations[n].models.day.charactersPatch = "FF01_p";
	//Night
	Locations[n].models.night.fonar = "FF01_fn";
	Locations[n].models.night.charactersPatch = "FF01_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "Falaise_de_fleur_location_02_01";
	Locations[n].reload.l1.go = "Falaise_de_fleur_port_01";
	Locations[n].reload.l1.emerge = "Falaise_de_fleur_location_01_02";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Port.";

	Locations[n].reload.l2.name = "Falaise_de_fleur_location_02_03";
	Locations[n].reload.l2.go = "Falaise_de_fleur_location_03";
	Locations[n].reload.l2.emerge = "Falaise_de_fleur_location_03_02";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Falaise De Fleur. Center.";

	Locations[n].reload.l3.name = "Falaise_de_fleur_location_02_perechod";
	Locations[n].reload.l3.go = "Falaise_de_Fleur_jungle";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Jungle.";

	Locations[n].reload.l4.name = "locator21";
	Locations[n].reload.l4.go = "house_of_Elzire_Ayarai";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "House.";

	Locations[n].reload.l5.name = "locator20";
	Locations[n].reload.l5.go = "HouseInsideR20";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "House.";
	n = n + 1;

	// Falaise_de_fleur_location_03 -------------------------------------------------
	Locations[n].id = "Falaise_de_fleur_location_03";
	locations[n].id.label = "Falaise de Fleur";
	locations[n].worldmap = "Falaise De Fleur";
	Locations[n].image = "loading\FF_Town_02.tga";

	//Town sack
	Locations[n].townsack = "Falaise de Fleur";

	//Sound
	locations[n].type = "town";
	LAi_LocationFantomsGen(&locations[n], true);
	locations[n].fastreload = "Falaise_De_Fleur";
	//Models
	//Always
	Locations[n].filespath.models = "locations\Town_FalaiseDeFleur\town_02";
	Locations[n].models.always.locators = "FF02_l";
	Locations[n].models.always.grassPatch = "FF02_g";
	Locations[n].models.always.city = "FF02";
		//Day
	Locations[n].models.day.fonar = "FF02_fd";
	Locations[n].models.day.charactersPatch = "FF02_pd";
	Locations[n].models.day.jumppatch = "FF02_j";
	Locations[n].models.day.rinok = "FF02_e01";
	//Night
	Locations[n].models.night.fonar = "FF02_fn";
	Locations[n].models.night.charactersPatch = "FF02_pn";
	Locations[n].models.night.jumppatch = "FF02_j";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "Falaise_de_fleur_location_03_02";
	Locations[n].reload.l1.go = "Falaise_de_fleur_location_02";
	Locations[n].reload.l1.emerge = "Falaise_de_fleur_location_02_03";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Falaise De Fleur. Slums.";

	Locations[n].reload.l2.name = "Falaise_de_fleur_location_03_04";
	Locations[n].reload.l2.go = "Falaise_de_fleur_location_04";
	Locations[n].reload.l2.emerge = "Falaise_de_fleur_location_04_03";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Falaise De Fleur.";

	Locations[n].reload.l3.name = "Falaise_de_fleur_townhall";
	Locations[n].reload.l3.go = "Falaise_de_fleur_townhall";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Residence.";
	Locations[n].reload.l3.close_for_night = 1;

	Locations[n].reload.l4.name = "Falaise_de_fleur_tavern";
	Locations[n].reload.l4.go = "Falaise_de_fleur_tavern";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "Tavern.";

	Locations[n].reload.l5.name = "Falaise_de_fleur_shipyard";
	Locations[n].reload.l5.go = "Falaise_de_fleur_shipyard";
	Locations[n].reload.l5.emerge = "locator2";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "Shipyard.";
	Locations[n].reload.l5.close_for_night = 1;

	Locations[n].reload.l6.name = "Falause_de_fleur_smuggler";
	Locations[n].reload.l6.go = "house_of_smuggler_in_FiF";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "House.";

	locations[n].reload.l7.name = "home5";
	Locations[n].reload.l7.go = "Falaise_de_fleur_church";
	Locations[n].reload.l7.emerge = "reload1";
	Locations[n].reload.l7.autoreload = "0";
	Locations[n].reload.l7.label = "Church.";
	Locations[n].reload.l7.close_for_night = 1;

	locations[n].reload.l8.name = "home3";
	Locations[n].reload.l8.go = "FF_usurerHouse";
	Locations[n].reload.l8.emerge = "reload1";
	Locations[n].reload.l8.autoreload = "0";
	Locations[n].reload.l8.label = "Loanshark's Office.";
	Locations[n].reload.l8.close_for_night = 1;

	locations[n].reload.l10.name = "home6";
	Locations[n].reload.l10.go = "Falause_de_fleur_InsideHouseR6";
	Locations[n].reload.l10.emerge = "reload1";
	Locations[n].reload.l10.autoreload = "0";
	Locations[n].reload.l10.label = "House.";
	Locations[n].reload.l10.close_for_night = 1;


	locations[n].reload.l11.name = "home1";
	Locations[n].reload.l11.go = "Falause_de_fleur_InsideHouseR1";
	Locations[n].reload.l11.emerge = "reload1";
	Locations[n].reload.l11.autoreload = "0";
	Locations[n].reload.l11.label = "House.";
	Locations[n].reload.l11.close_for_night = 1;

	//Lucas

	Locations[n].reload.l12.name = "home7";
	Locations[n].reload.l12.go = "Ransom_house_f1";
	Locations[n].reload.l12.emerge = "reload1";
	Locations[n].reload.l12.autoreload = "0";
	Locations[n].reload.l11.label = "House.";
	Locations[n].reload.l11.close_for_night = 0;

	//Lucas

	n = n + 1;

	// Falaise_de_fleur_location_04 -------------------------------------------------
	Locations[n].id = "Falaise_de_fleur_location_04";
	locations[n].id.label = "Falaise de Fleur";
	locations[n].worldmap = "Falaise De Fleur";
	Locations[n].image = "loading\FF_Town_03.tga";

	//Town sack
	Locations[n].townsack = "Falaise de Fleur";

	//Sound
	locations[n].type = "town";
	LAi_LocationFantomsGen(&locations[n], true);
	locations[n].fastreload = "Falaise_De_Fleur";
	//Models
	//Always
	Locations[n].filespath.models = "locations\Town_FalaiseDeFleur\town_03";
	Locations[n].models.always.city = "FF03";
	Locations[n].models.always.locators = "FF03_l";
	Locations[n].models.always.grassPatch = "FF03_g";
	//Day
	Locations[n].models.day.fonar = "FF03_fd";
	Locations[n].models.day.charactersPatch = "FF03_p";
	//Night
	Locations[n].models.night.fonar = "FF03_fn";
	Locations[n].models.night.charactersPatch = "FF03_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "Falaise_de_fleur_location_04_03";
	Locations[n].reload.l1.go = "Falaise_de_fleur_location_03";
	Locations[n].reload.l1.emerge = "Falaise_de_fleur_location_03_04";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Falaise De Fleur. Center.";

	Locations[n].reload.l2.name = "Falaise_de_fleur_location_04_05";
	Locations[n].reload.l2.go = "Falaise_de_fleur_location_05";
	Locations[n].reload.l2.emerge = "Falaise_de_fleur_location_05_04";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Falaise De Fleur. Slums.";

	Locations[n].reload.l3.name = "Falaise_de_fleur_store";
	Locations[n].reload.l3.go = "Falaise_de_Fleur_store";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Store.";
	Locations[n].reload.l3.close_for_night = 1;

	Locations[n].reload.l4.name = "locator21";
	Locations[n].reload.l4.go = "Falause_de_fleur_InsideHouseR21";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "House";

	n = n + 1;

	// Falaise_de_fleur_location_05 -------------------------------------------------
	Locations[n].id = "Falaise_de_fleur_location_05";
	locations[n].id.label = "Falaise De Fleur";
	locations[n].worldmap = "Falaise De Fleur";
	Locations[n].image = "loading\FF_Town_04.tga";

	//Town sack
	Locations[n].townsack = "Falaise de Fleur";

	//Sound
	locations[n].type = "town";
	LAi_LocationFantomsGen(&locations[n], true);
	locations[n].fastreload = "Falaise_De_Fleur";
	//Models
	//Always
	Locations[n].filespath.models = "locations\Town_FalaiseDeFleur\town_04";
	Locations[n].models.always.city = "FF04";
	Locations[n].models.always.locators = "FF04_l";
	Locations[n].models.always.grassPatch = "FF04_g";
	//Day
	Locations[n].models.day.fonar = "FF04_fd";
	Locations[n].models.day.charactersPatch = "FF04_p";
	//Night
	Locations[n].models.night.fonar = "FF04_fn";
	Locations[n].models.night.charactersPatch = "FF04_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "Falaise_de_fleur_location_05_04";
	Locations[n].reload.l1.go = "Falaise_de_fleur_location_04";
	Locations[n].reload.l1.emerge = "Falaise_de_fleur_location_04_05";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Falaise De Fleur.";

	Locations[n].reload.l2.name = "Falaise_de_fleur_location_05_01";
	Locations[n].reload.l2.go = "Falaise_de_fleur_port_02";
	Locations[n].reload.l2.emerge = "Falaise_de_fleur_location_01_05";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Beach.";

	Locations[n].reload.l3.name = "home";
	Locations[n].reload.l3.go = "house_of_laurence";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "House.";

	Locations[n].reload.l4.name = "locator6";
	Locations[n].reload.l4.go = "Falaise_de_fleur_InsideHouseR6(05)";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "House.";

	Locations[n].reload.l5.name = "locator7";
	Locations[n].reload.l5.go = "Falaise_de_fleur_InsideHouseR7(05)";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "House.";

	Locations[n].reload.l6.name = "locator11";
	Locations[n].reload.l6.go = "Falaise_de_fleur_InsideHouseR11(05)";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "House.";

	n = n + 1;

	// -------------------------------------------------

	Locations[n].id = "Falause_de_fleur_InsideHouseR21";
	locations[n].id.label = "House";
	Locations[n].filespath.models = "locations\inside\DoubleFlour_house\";
	Locations[n].image = "loading\house_08.tga";

	//Town sack
	Locations[n].townsack = "Falaise de Fleur";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Falaise_De_Fleur";
	//Models
	//Always
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
	Locations[n].models.back = "back\fflf1_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Falaise_de_fleur_location_04";
	Locations[n].reload.l1.emerge = "locator21";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Falaise De Fleur. Center.";

	n = n + 1;

	// -------------------------------------------------

	Locations[n].id = "Falaise_de_fleur_InsideHouseR6(05)";
	locations[n].id.label = "House";
	Locations[n].filespath.models = "locations\inside\DoubleFlour_house\";
	Locations[n].image = "loading\house_08.tga";

	//Town sack
	Locations[n].townsack = "Falaise de Fleur";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Falaise_De_Fleur";
	//Models
	//Always
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
	Locations[n].models.back = "back\fflf1_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Falaise_de_fleur_location_05";
	Locations[n].reload.l1.emerge = "locator6";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Falaise De Fleur. Slums.";
	Locations[n].locators_radius.reload.reload1 = 0.8;

	n = n + 1;

	// -------------------------------------------------

	Locations[n].id = "Falaise_de_fleur_InsideHouseR7(05)";
	locations[n].id.label = "House";
	Locations[n].filespath.models = "locations\inside\mh5";
	Locations[n].image = "loading\house_06.tga";

	//Town sack
	Locations[n].townsack = "Falaise de Fleur";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Falaise_De_Fleur";
	//Models
	//Always
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
	Locations[n].models.back = "back\ffmh5_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Falaise_de_fleur_location_05";
	Locations[n].reload.l1.emerge = "locator7";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Falaise De Fleur. Slums.";
	Locations[n].locators_radius.reload.reload1 = 0.8;

	n = n + 1;

	// -------------------------------------------------

	Locations[n].id = "Falaise_de_fleur_InsideHouseR11(05)";
	locations[n].id.label = "House";
	Locations[n].filespath.models = "locations\inside\Smallhome";
	Locations[n].image = "loading\house_03.tga";

	//Town sack
	Locations[n].townsack = "Falaise de Fleur";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Falaise_De_Fleur";
	//Models
	//Always
	Locations[n].models.always.locators = "sh_l";
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
	Locations[n].models.back = "back\ffsh_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Falaise_de_fleur_location_05";
	Locations[n].reload.l1.emerge = "locator11";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Falaise De Fleur. Slums.";
	Locations[n].locators_radius.reload.reload1 = 0.8;

	n = n + 1;

	// Falaise_de_fleur_church -------------------------------------------------
	Locations[n].id = "Falaise_de_fleur_church";
	locations[n].id.label = "Falaise De Fleur's church";
	Locations[n].image = "loading\Medium_Churche.tga";
	Locations[n].filespath.models = "locations\inside\Church_inside\";

	//Town sack
	Locations[n].townsack = "Falaise de Fleur";

	//Sound
	locations[n].type = "church";
	locations[n].fastreload = "Falaise_De_Fleur";
	//Models
	//Always
	Locations[n].models.always.city = "Church";
	Locations[n].models.always.locators = "Church_l";
	Locations[n].models.always.window = "church_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
//	Locations[n].models.day.lamp = "FalaiseDeFleur05_day";
	Locations[n].models.day.charactersPatch = "Church_p";

	//Night
//	Locations[n].models.night.lamp = "FalaiseDeFleur05_night";
	Locations[n].models.night.charactersPatch = "Church_p";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Falaise_de_fleur_location_03";
	Locations[n].reload.l1.emerge = "home5";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Falaise De Fleur. Center.";
	LAi_LocationFightDisable(&Locations[n], true);

	n = n + 1;

	// 06 -------------------------------------------------
	Locations[n].id = "Falaise_De_Fleur_Jungle";
	locations[n].id.label = "Falaise de Fleur jungle";
	Locations[n].image = "loading\FF_Jungle_01.tga";
	//Sound
	locations[n].type = "jungle";
//	locations[n].fastreload = "Falaise_De_Fleur";
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);

	//Models
	//Always
	Locations[n].filespath.models = "locations\Town_FalaiseDeFleur\exit";
	Locations[n].models.always.jungle = "FFexit";
	Locations[n].models.always.locators = "FFexit_l";
	Locations[n].models.always.grassPatch = "FFexit_g";
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
	Locations[n].models.day.charactersPatch = "FFexit_p";
	Locations[n].models.day.fonar = "FFexit_fd";
	//Night
	Locations[n].models.night.charactersPatch = "FFexit_p";
	Locations[n].models.night.fonar = "FFexit_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload2";
	Locations[n].reload.l1.go = "Falaise_de_fleur_location_02";
	Locations[n].reload.l1.emerge = "Falaise_de_fleur_location_02_perechod";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Falaise De Fleur. Slums.";

	Locations[n].reload.l2.name = "reload1";
	Locations[n].reload.l2.go = "Falaise_de_fleur_shore";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Octopus Bay.";
	Locations[n].locators_radius.reload.reload1 = 3;

	Locations[n].reload.l3.name = "reload1_back";
	Locations[n].reload.l3.go = "Falaise_de_fleur_shore";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Octopus Bay.";
	Locations[n].locators_radius.reload.reload1_back = 2;

	n = n + 1;

	//  -------------------------------------------------
	Locations[n].id = "Falaise_de_fleur_shore";
	locations[n].id.label = "Falaise de Fleur shore";
	locations[n].worldmap = "FShore 1";
	Locations[n].filespath.models = "locations\Outside\Shore_6";
	Locations[n].image = "loading\FF_Shore_01.tga";
	Locations[n].name = "Octopus Bay";
	//Sound
	locations[n].type = "seashore";

	//Models
	//Always
	Locations[n].models.always.locators = "Shore06_l";
	Locations[n].models.always.shore = "Shore06";
	Locations[n].models.always.shore.foam = "1";
	Locations[n].models.always.seabed = "Shore06_sb";
	Locations[n].models.always.seabed.foam = "1";
	//Locations[n].models.always.grassPatch = "Shore06_g";

	//Day
	Locations[n].models.day.charactersPatch = "Shore06_p";
	//Night
	Locations[n].models.night.charactersPatch = "Shore06_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].environment.sea = "true";

	//Reload map
	Locations[n].reload.l1.name = "reload2";
	Locations[n].reload.l1.go = "Falaise_De_Fleur_Jungle";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.locator3 = 1;

	Locations[n].reload.l3.name = "Reload2_back";
	Locations[n].reload.l3.go = "Falaise_De_Fleur_Jungle";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload2_back = 5;

	Locations[n].reload.l2.name = "boat";
	Locations[n].reload.l2.go = "FalaiseDeFleur";
	Locations[n].reload.l2.emerge = "reload_2";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Sea.";
	Locations[n].locators_radius.reload.boat = 11.0;
	n = n + 1;

	// 06 -------------------------------------------------
	Locations[n].id = "Falaise_De_Fleur_townhall";
	locations[n].id.label = "Falaise De Fleur townhall";
	Locations[n].filespath.models = "locations\inside\Residence1";
	Locations[n].image = "loading\FF_townhall.tga";

	//Town sack
	Locations[n].townsack = "Falaise de Fleur";

	//Sound
	locations[n].type = "residence";
	locations[n].fastreload = "Falaise_De_Fleur";
	//Models
	//Always
	Locations[n].models.always.locators = "res01_l";
	Locations[n].models.always.jungle = "res01";
	Locations[n].models.always.window = "res01_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "res01_p";

	//Night
	Locations[n].models.night.charactersPatch = "res01_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\ffres1_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Falaise_de_fleur_location_03";
	Locations[n].reload.l1.emerge = "Falaise_de_fleur_townhall";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Falaise De Fleur. Center.";
	Locations[n].locators_radius.reload.locator1 = 0.8;
	LAi_LocationFightDisable(&Locations[n], true);

	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "Falaise_de_fleur_tavern";
	Locations[n].filespath.models = "locations\inside\smalltavern";
	locations[n].id.label = "Falaise De Fleur Tavern";
	Locations[n].image = "loading\tavern_03.tga";

	//Town sack
	Locations[n].townsack = "Falaise de Fleur";

	//Sound
	locations[n].type = "tavern";
	locations[n].fastreload = "Falaise_De_Fleur";
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
	Locations[n].models.back = "back\ffst_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Falaise_de_fleur_location_03";
	Locations[n].reload.l1.emerge = "Falaise_de_fleur_tavern";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Falaise De Fleur. Center.";
	Locations[n].locators_radius.reload.reload1 = 0.8;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "";
	Locations[n].reload.l2.emerge = "";
	Locations[n].reload.l2.label = "Room.";
	Locations[n].locators_radius.reload.reload2 = 0.8;
	LAi_LocationFightDisable(&Locations[n], true);

	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "Falaise_de_fleur_tavern_upstairs";
	locations[n].id.label = "Room in Falaise de Fleur tavern";
	Locations[n].filespath.models = "locations\inside\Doubleflour_house";
	Locations[n].image = "loading\Tavern_Upstairs_01.tga";

	//Town sack
	Locations[n].townsack = "Falaise de Fleur";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Falaise_De_Fleur";
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
	Locations[n].models.back = "back\fflf2_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Falaise_de_fleur_tavern";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Tavern.";
	Locations[n].locators_radius.reload.reload1 = 0.8;
	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "Falaise_de_fleur_shipyard";
	Locations[n].filespath.models = "locations\inside\shipyard2";
	locations[n].id.label = "Falaise De Fleur shipyard";
	Locations[n].image = "loading\shipyard_03.tga";

	//Town sack
	Locations[n].townsack = "Falaise de Fleur";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Falaise_De_Fleur";
	//Models
	//Always
	Locations[n].models.always.locators = "sh02_l";
	Locations[n].models.always.tavern = "sh02";
	Locations[n].models.always.window = "sh02_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;

	//Day
	Locations[n].models.day.charactersPatch = "sh02_p";

	//Night
	Locations[n].models.night.charactersPatch = "sh02_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\ffsh2_";
	//Reload map
	Locations[n].reload.l1.name = "locator2";
	Locations[n].reload.l1.go = "Falaise_de_fleur_location_03";
	Locations[n].reload.l1.emerge = "Falaise_de_fleur_shipyard";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Falaise De Fleur. Center.";
	Locations[n].locators_radius.reload.locator2 = 0.8;
	LAi_LocationFightDisable(&Locations[n], true);

	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "Falaise_de_Fleur_store";
	locations[n].id.label = "Falaise de Fleur store";
	Locations[n].filespath.models = "locations\inside\LargeStore\";
	Locations[n].image = "loading\store_03.tga";

	//Town sack
	Locations[n].townsack = "Falaise de Fleur";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Falaise_De_Fleur";
	//Models
	//Always
	Locations[n].models.always.locators = "LS_l";
	Locations[n].models.always.tavern = "LS";
	Locations[n].models.always.window = "LS_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	Locations[n].models.always.fonar = "LS_fn";
	//Day
	Locations[n].models.day.charactersPatch = "LS_p";

	//Night
	Locations[n].models.night.charactersPatch = "LS_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\ffls_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Falaise_de_fleur_location_04";
	Locations[n].reload.l1.emerge = "Falaise_de_fleur_store";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Falaise De Fleur.";
	Locations[n].locators_radius.reload.reload1 = 0.8;
	LAi_LocationFightDisable(&Locations[n], true);

	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "house_of_smuggler_in_FiF";
	locations[n].id.label = "House in Falaise De Fleur";
	Locations[n].filespath.models = "locations\inside\DoubleFlour_house\";
	Locations[n].image = "loading\house_08.tga";

	//Town sack
	Locations[n].townsack = "Falaise de Fleur";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Falaise_De_Fleur";
	//Models
	//Always
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
	Locations[n].models.back = "back\fflf1_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Falaise_de_fleur_location_03";
	Locations[n].reload.l1.emerge = "Falause_de_fleur_smuggler";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Falaise De Fleur. Center.";
	Locations[n].locators_radius.reload.reload1 = 0.8;
	LAi_LocationFightDisable(&Locations[n], true);

	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "FF_usurerHouse";
	locations[n].id.label = "Loanshark's Office.";
	Locations[n].filespath.models = "locations\inside\Doubleflour_house";
	Locations[n].image = "loading\house_08.tga";

	//Town sack
	Locations[n].townsack = "Falaise de Fleur";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Falaise_De_Fleur";
	//Models
	//Always
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
	Locations[n].models.back = "back\fflf1_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Falaise_de_fleur_location_03";
	Locations[n].reload.l1.emerge = "home3";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Falaise De Fleur. Center.";
	Locations[n].locators_radius.reload.reload1 = 0.8;
	LAi_LocationFightDisable(&Locations[n], true);

	n = n + 1;


	// -------------------------------------------------
	Locations[n].id = "house_of_laurence";
	locations[n].id.label = "House in Falaise de Fleur";
	Locations[n].filespath.models = "locations\inside\smallhome\";
	Locations[n].image = "loading\house_03.tga";

	//Town sack
	Locations[n].townsack = "Falaise de Fleur";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Falaise_De_Fleur";
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
	Locations[n].models.back = "back\ffsh_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Falaise_de_fleur_location_05";
	Locations[n].reload.l1.emerge = "home";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Falaise De Fleur. Slums.";
	Locations[n].locators_radius.reload.reload1 = 0.8;

	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "house_of_Elzire_Ayarai";
	locations[n].id.label = "House in Falaise De Fleur";
	Locations[n].filespath.models = "locations\inside\smallhome\";
	Locations[n].image = "loading\house_03.tga";

	//Town sack
	Locations[n].townsack = "Falaise de Fleur";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Falaise_De_Fleur";
	//Models
	//Always
	Locations[n].models.always.locators = "SH_l";
	Locations[n].models.always.house = "SH";
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
	Locations[n].models.back = "back\ffsh_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Falaise_de_fleur_location_02";
	Locations[n].reload.l1.emerge = "locator21";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Falaise De Fleur. Slums.";
	Locations[n].locators_radius.reload.reload1 = 0.8;
	LAi_LocationFightDisable(&Locations[n], true);

	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "HouseInsideR20";
	locations[n].id.label = "House in Falaise De Fleur";
	Locations[n].filespath.models = "locations\inside\mh5";
	Locations[n].image = "loading\house_06.tga";

	//Town sack
	Locations[n].townsack = "Falaise de Fleur";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Falaise_De_Fleur";
	//Models
	//Always
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
	Locations[n].models.back = "back\ffmh5_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Falaise_de_fleur_location_02";
	Locations[n].reload.l1.emerge = "locator20";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Falaise De Fleur. Slums.";
	Locations[n].locators_radius.reload.reload1 = 0.8;

	n = n + 1;

	// -^------------------------------------------------

	Locations[n].id = "Falause_de_fleur_InsideHouseR6";
	locations[n].id.label = "House";
	Locations[n].filespath.models = "locations\inside\mh6";
	Locations[n].image = "loading\room.tga";

	//Town sack
	Locations[n].townsack = "Falaise de Fleur";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Falaise_De_Fleur";
	//Models
	//Always
	Locations[n].models.always.locators = "mh6_l";
	Locations[n].models.always.house = "mh6";
	Locations[n].models.always.window = "mh6_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "mh6_p";

	//Night
	Locations[n].models.night.charactersPatch = "mh6_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\ffmh6_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Falaise_de_fleur_location_03";
	Locations[n].reload.l1.emerge = "home6";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Falaise De Fleur. Center.";

	n = n + 1;

	// -^------------------------------------------------

	Locations[n].id = "Falause_de_fleur_InsideHouseR1";
	locations[n].id.label = "House";
	Locations[n].filespath.models = "locations\inside\mh10";
	Locations[n].image = "loading\House_04.tga";

	//Town sack
	Locations[n].townsack = "Falaise de Fleur";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Falaise_De_Fleur";
	//Models
	//Always
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
	Locations[n].models.back = "back\ffmh10_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Falaise_de_fleur_location_03";
	Locations[n].reload.l1.emerge = "home1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Falaise De Fleur. Center.";

	n = n + 1;

	// -------------------------------------------------

	Locations[n].id = "Falause_de_fleur_InsideHouseR7";
	locations[n].id.label = "House";
	Locations[n].filespath.models = "locations\inside\mh5";
	Locations[n].image = "loading\house_06.tga";

	//Town sack
	Locations[n].townsack = "Falaise de Fleur";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Falaise_De_Fleur";
	//Models
	//Always
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
	Locations[n].models.back = "back\ffmh5_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Falaise_de_fleur_location_03";
	Locations[n].reload.l1.emerge = "home7";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Falaise De Fleur. Center.";

	n = n + 1;
	
	// -------------------------------------------------

	Locations[n].id = "Head_port_house";
	locations[n].id.label = "Head port house";
	//Sound
	Locations[n].filespath.models = "locations\inside\mh5";
	Locations[n].image = "loading\house_06.tga";

	//Town sack
	Locations[n].townsack = "Falaise de Fleur";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Falaise_De_Fleur";
	//Models
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
	Locations[n].models.back = "back\ffmh5_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Falaise_de_fleur_port_01";
	Locations[n].reload.l1.emerge = "shipyard";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Falaise De Fleur. Port.";
	LAi_LocationFightDisable(&Locations[n], true);

	n = n + 1;

	// -------------------------------------------------
	return n;
}
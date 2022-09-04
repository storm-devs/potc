

int LocationInitQuestLocations(int n)
{
	Locations[n].id = "Quest_redmond_tavern";
	locations[n].id.label = "Redmond tavern";
	Locations[n].filespath.models = "locations\inside\Largetavern\";
	Locations[n].image = "loading\Tavern_01.tga";
	//Sound
	locations[n].type = "tavern";
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
	Locations[n].models.back = "back\redlt_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Redmond_Town_01";
	Locations[n].reload.l1.emerge = "door_1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Redmond.Center.";
	LAi_LocationFightDisable(&Locations[n], true);

	n = n + 1; 


	// -------------------------------------------------

	Locations[n].filespath.models = "locations\town_IslaMuelle\town_01";	
	Locations[n].image = "loading\Isla_Muelle_Town_01.tga";

	Locations[n].id = "Quest_Muelle_town_01";
	locations[n].id.label = "Isla Muelle";

	//Sound
	locations[n].type = "town";
	//Models
	//Always
	Locations[n].models.always.l1 = "Mu01";
	Locations[n].models.always.locators = "Mu01_l";
	Locations[n].models.always.grassPatch = "Mu01_g";
	//Day
	Locations[n].models.day.rinok = "Mu01_e1";
	Locations[n].models.day.fonar = "Mu01_fd";
	Locations[n].models.day.jumppatch = "Mu01_j";
	Locations[n].models.day.charactersPatch = "Mu01_pd";
	//Night
	Locations[n].models.night.fonar = "Mu01_fn";
	Locations[n].models.night.charactersPatch = "Mu01_pn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
		
	n = n + 1;

	//  -------------------------------------------------
	Locations[n].id = "Quest_Residence";
	locations[n].id.label = "Redmond Townhall. Silehards's Bedroom";
	Locations[n].filespath.models = "locations\inside\ResBedRoom";
	Locations[n].image = "loading\Bedroom.tga";
	//Sound
	locations[n].type = "residence";
	//Models
	//Always
	Locations[n].models.always.locators = "bed_l";
	Locations[n].models.always.l1 = "bed";
	Locations[n].models.always.window = "bed_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "bed_p";

	//Night
	Locations[n].models.night.charactersPatch = "bed_p";	

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\redb_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Redmond_Town_01";
	Locations[n].reload.l1.emerge = "door_5";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Redmond.Center.";

	n = n + 1;

	//  -------------------------------------------------
	Locations[n].filespath.models = "locations\town_Greenford\port";	
	Locations[n].image = "loading\greenford_port.tga";

	Locations[n].id = "Fake_Greenford_port";
	locations[n].id.label = "Greenford port";
	//Sound
	locations[n].type = "port";
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
	Locations[n].reload.l1.go = "";
	Locations[n].reload.l1.emerge = "";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l2.name = "reload4";
	Locations[n].reload.l2.go = "";
	Locations[n].reload.l2.emerge = "";
	Locations[n].reload.l2.autoreload = "0";

	n = n + 1;


	// -------------------------------------------------

	Locations[n].filespath.models = "locations\town_Greenford\town";	
	Locations[n].image = "loading\greenford_town.tga";

	Locations[n].id = "Fake_Greenford_town";
	locations[n].id.label = "Greenford";
	//Sound
	locations[n].type = "town";
	//Models
	//Always
	Locations[n].models.always.locators = "GrTown_l";
	Locations[n].models.always.l1 = "GrTown";
	Locations[n].models.always.grassPatch = "GrTown_g";
	//Day
	Locations[n].models.day.rinok = "GrTown_e01";
	Locations[n].models.day.fonar = "GrTown_fd";
	Locations[n].models.day.charactersPatch = "GrTown_pd";
	//Night
	Locations[n].models.night.fonar = "GrTown_fn";
	Locations[n].models.night.charactersPatch = "GrTown_pn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map

	n = n + 1;

//---------------------------------------------------------------------------


	Locations[n].id = "Fake_Greenford_prison";
	locations[n].id.label = "Greenford prison";
	Locations[n].filespath.models = "locations\inside\prison";
	//Sound
	locations[n].type = "jail";
	Locations[n].image = "loading\prison_01.tga";
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
	Locations[n].reload.l1.go = "";
	Locations[n].reload.l1.emerge = "";
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Decks\qdeck";
	Locations[n].image = "loading\sea.tga";

	Locations[n].id = "Ship_deck";
	locations[n].id.label = "Pirate bark";
	//Sound
	locations[n].type = "deck";
	//Models
	//Always
	Locations[n].models.always.locators = "qdeck_l";
	Locations[n].models.always.l1 = "qdeck";
	//Day
	Locations[n].models.day.charactersPatch = "qdeck_p";
	//Night
	Locations[n].models.night.charactersPatch = "qdeck_p";
	Locations[n].lockCamAngle = 0.4;
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map
	Locations[n].reload.l1.name = "locator2";
	Locations[n].reload.l1.go = "";
	Locations[n].reload.l1.disable = 1;
	Locations[n].reload.l1.emerge = "reload2";
	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "Denielle_deck";
	Locations[n].filespath.models = "locations\Decks\qdeck";
	//Sound
	locations[n].type = "deck";
	Locations[n].image = "loading\Sea.tga";
	//Models
	//Always
	Locations[n].models.always.locators = "qdeck_l";
	Locations[n].models.always.l1 = "qdeck";
	//Day
	Locations[n].models.day.charactersPatch = "qdeck_p";
	//Night
	Locations[n].models.night.charactersPatch = "qdeck_p";
	Locations[n].lockCamAngle = 0.4;
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map
	Locations[n].reload.l1.name = "locator2";
	Locations[n].reload.l1.go = "";
	Locations[n].reload.l1.disable = 1;
	Locations[n].reload.l1.emerge = "reload2";
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Decks\qdeck";
	Locations[n].image = "loading\sea.tga";

	Locations[n].id = "Gamboa_ship";
	locations[n].id.label = "Gamboa ship";
	//Sound
	Locations[n].models.always.locators = "qdeck_l";
	Locations[n].models.always.l1 = "qdeck";
	//Day
	Locations[n].models.day.charactersPatch = "qdeck_p";
	//Night
	Locations[n].models.night.charactersPatch = "qdeck_p";
	Locations[n].lockCamAngle = 0.4;
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map
	Locations[n].reload.l1.name = "locator2";
	Locations[n].reload.l1.go = "";
	Locations[n].reload.l1.disable = 1;
	Locations[n].reload.l1.emerge = "reload2";
	n = n + 1;

	//Lucas

	//  -------------------------------------------------
	Locations[n].id = "Ransom_house_f1";
	locations[n].id.label = "House";
	Locations[n].filespath.models = "Locations\Inside\Doubleflour_house";
	Locations[n].image = "loading\house_08.tga";
	//Sound
	locations[n].type = "residence";
	//Models
	//Always
	Locations[n].models.always.locators = "LH_F1_l";
	Locations[n].models.always.l1 = "LH_F1";

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
	Locations[n].reload.l1.emerge = "home7";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Street";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Ransom_house_f2";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "2nd floor";

	n = n + 1;

	//  -------------------------------------------------
	Locations[n].id = "Ransom_house_f2";
	locations[n].id.label = "Kidnappers' Hideout, 2nd floor";
	Locations[n].filespath.models = "Locations\Inside\Doubleflour_house";
	Locations[n].image = "loading\house_07.tga";
	//Sound
	locations[n].type = "residence";
	//Models
	//Always
	Locations[n].models.always.locators = "LH_F2_l";
	Locations[n].models.always.l1 = "LH_F2";
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
	Locations[n].reload.l1.go = "Ransom_house_f1";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "1st floor";

	n = n + 1;

//Lucas

//Hitman

	//  -------------------------------------------------
	Locations[n].id = "Hit_house";
	Locations[n].id.label = "House of Mateus Santos";
	Locations[n].filespath.models = "Locations\Inside\Doubleflour_house";
	Locations[n].image = "loading\Santos_home.tga";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Muelle";
	//Models
	//Always
	Locations[n].models.always.locators = "LH_F2_l";
	Locations[n].models.always.l1 = "LH_F2";
/*	Locations[n].models.always.window = "LH_F2_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;  */

	//Day
	Locations[n].models.day.charactersPatch = "LH_F2_p";

	//Night
	Locations[n].models.night.charactersPatch = "LH_F2_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\mulf2_";
	//Reload map
	Locations[n].reload.l1.name = "Reload1";
	Locations[n].reload.l1.go = "Muelle_town_01";
	Locations[n].reload.l1.emerge = "Reload21";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Isla Muelle";
	n = n + 1;


	// -------------------------------------------------
	Locations[n].id = "Hit_house1";
	locations[n].id.label = "House of Geffrey Bampfylde";
	Locations[n].filespath.models = "locations\inside\MediumHouse";
	Locations[n].image = "loading\Bampfyldes_Home.tga";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Greenford";
	//Models
	//Always
	Locations[n].models.always.locators = "MH_l";
	Locations[n].models.always.house = "MH";
/*	Locations[n].models.always.window = "MH_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;    */
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
	Locations[n].reload.l1.emerge = "reload5";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Greenford";
	n = n + 1;

	//  -------------------------------------------------
	Locations[n].id = "Hit_house2";
	Locations[n].id.label = "House of Amerigo Vieira";
	Locations[n].filespath.models = "Locations\Inside\Doubleflour_house";
	Locations[n].image = "loading\Vieras_Home.tga";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Conceicao";
	//Models
	//Always
	Locations[n].models.always.locators = "LH_F2_l";
	Locations[n].models.always.l1 = "LH_F2";
/*	Locations[n].models.always.window = "LH_F2_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;  */

	//Day
	Locations[n].models.day.charactersPatch = "LH_F2_p";

	//Night
	Locations[n].models.night.charactersPatch = "LH_F2_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\colf2_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Conceicao_town";
	Locations[n].reload.l1.emerge = "reload15";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Conceicao";
	n = n + 1;

//Hitman

	Locations[n].id = "Tutorial_Deck";
	Locations[n].id.label = "Tutorial Deck";
	Locations[n].filespath.models = "locations\decks\Tut_deck";
	Locations[n].image = "loading\battle.tga";
	//Sound
	locations[n].type = "residence";	
	//Models
	//Always
	Locations[n].models.always.locators = "tut_Deck_l";
	Locations[n].models.always.l1 = "tut_Deck";
	Locations[n].models.always.window = "tut_deck_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 65531;

	//Day
	Locations[n].models.day.charactersPatch = "tut_Deck_p";
	Locations[n].models.day.fonar = "tut_Deck_fd";

	//Night
	Locations[n].models.night.charactersPatch = "tut_Deck_p";
	Locations[n].models.night.fonar = "tut_Deck_fn";

	//Environment
	Locations[n].environment.sea = "true";
	Locations[n].environment.weather = "true";
//	Locations[n].lockWeather = "Alcove";
	

//	Locations[n].models.back = "back\colf2_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "";
	Locations[n].reload.l1.emerge = "";
	Locations[n].reload.l1.autoreload = "";
	Locations[n].reload.l1.label = "";

	Locations[n].locators_radius.randitem.randitem1 = 1;

	Locations[n].items.randitem1 = "blade1";

	n = n + 1;

	return n;
}

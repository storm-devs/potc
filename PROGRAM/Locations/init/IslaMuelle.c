
int LocationInitIslaMuelle(int n)
{

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\town_IslaMuelle\port";
	Locations[n].image = "loading\Isla_Muelle_Port.tga";

	Locations[n].id = "Muelle_port";
	LAi_LocationFantomsGen(&locations[n], true);
	locations[n].id.label = "Isla Muelle port";
	locations[n].worldmap = "Isla Muelle";

	//Town sack
	Locations[n].townsack = "Isla Muelle";

	//Sound
	locations[n].type = "port";
	locations[n].fastreload = "Muelle";
	//Models
	//Always
	Locations[n].models.always.locators = "MuPort_l";
	Locations[n].models.always.grassPatch = "MuPort_g";
	Locations[n].models.always.l1 = "MuPort";
	Locations[n].models.always.l1.foam = "1";
	Locations[n].models.always.l2 = "MuPort_sb";
	Locations[n].models.always.l2.foam = "1";
	//Day
	Locations[n].models.day.rinok = "MuPort_e1";
	Locations[n].models.day.fonar = "MuPort_fd";
	Locations[n].models.day.charactersPatch = "MuPort_pd";
	//Night
	Locations[n].models.night.fonar = "MuPort_fn";
	Locations[n].models.night.charactersPatch = "MuPort_pn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map

	Locations[n].reload.l1.name = "reload2";
	Locations[n].reload.l1.go = "Muelle_town_01";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Isla Muelle. Trade Square.";
	Locations[n].locators_radius.reload.reload2 = 2.0;


	Locations[n].reload.l2.name = "reload1";
	Locations[n].reload.l2.go = "IslaMuelle";
	Locations[n].reload.l2.emerge = "reload_1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Sea.";
	Locations[n].locators_radius.reload.reload1 = 2.0;

	Locations[n].reload.l4.name = "reload1_back";
	Locations[n].reload.l4.go = "IslaMuelle";
	Locations[n].reload.l4.emerge = "reload_1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "Sea.";
	Locations[n].locators_radius.reload.reload1_back = 2.0;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "IslaMuelle";
	Locations[n].reload.l3.emerge = "reload_1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Sea.";
	Locations[n].locators_radius.reload.reload3 = 2.0;

	Locations[n].reload.l5.name = "reload3_back";
	Locations[n].reload.l5.go = "IslaMuelle";
	Locations[n].reload.l5.emerge = "reload_1";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "Sea.";
	Locations[n].locators_radius.reload.reload3_back = 2.0;

	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\town_IslaMuelle\town_01";

	Locations[n].id = "Muelle_town_01";
	locations[n].id.label = "Isla Muelle";
	locations[n].worldmap = "Isla Muelle";
	Locations[n].image = "loading\Isla_Muelle_Town_01.tga";

	//Town sack
	Locations[n].townsack = "Isla Muelle";

	//Sound
	locations[n].type = "town";
	LAi_LocationFantomsGen(&locations[n], true);
	locations[n].fastreload = "Muelle";
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
	Locations[n].models.night.jumppatch = "Mu01_j";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Muelle_Port";
	Locations[n].reload.l1.emerge = "Reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Port.";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Muelle_town_03";
	Locations[n].reload.l2.emerge = "reload6";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Isla Muelle.";

	Locations[n].reload.l51.name = "reload2_back";
	Locations[n].reload.l51.go = "Muelle_town_03";
	Locations[n].reload.l51.emerge = "reload6";
	Locations[n].reload.l51.autoreload = "1";
	Locations[n].reload.l51.label = "Isla Muelle.";
	Locations[n].locators_radius.reload.reload2_back = 1.5;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Muelle_town_04";
	Locations[n].reload.l3.emerge = "reload3";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Isla Muelle. Center.";

	Locations[n].reload.l31.name = "reload3_back";
	Locations[n].reload.l31.go = "Muelle_town_04";
	Locations[n].reload.l31.emerge = "reload3";
	Locations[n].reload.l31.autoreload = "1";
	Locations[n].reload.l31.label = "Isla Muelle. Center.";
	Locations[n].locators_radius.reload.reload3_back = 1.5;

	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "Muelle_town_03";
	Locations[n].reload.l4.emerge = "reload9";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Isla Muelle.";

	Locations[n].reload.l41.name = "reload4_back";
	Locations[n].reload.l41.go = "Muelle_town_03";
	Locations[n].reload.l41.emerge = "reload9";
	Locations[n].reload.l41.autoreload = "1";
	Locations[n].reload.l41.label = "Isla Muelle.";
	Locations[n].locators_radius.reload.reload4_back = 1.5;

	// Reload to house_of_Sylvie_Bondies
	Locations[n].reload.l5.name = "reload13";
	Locations[n].reload.l5.go = "house_of_Sylvie_Bondies";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "House.";

	Locations[n].reload.l7.name = "reload8";
	Locations[n].reload.l7.go = "Muelle_Store";
	Locations[n].reload.l7.emerge = "locator2";
	Locations[n].reload.l7.autoreload = "0";
	Locations[n].reload.l7.label = "Магазин.";
	Locations[n].reload.l7.close_for_night = 1;

	Locations[n].reload.l10.name = "reload10";
	Locations[n].reload.l10.go = "Muelle_UsurerHouse";
	Locations[n].reload.l10.emerge = "Reload1";
	Locations[n].reload.l10.autoreload = "0";
	Locations[n].reload.l10.label = "Loanshark's Office.";
	Locations[n].reload.l10.close_for_night = 1;

	Locations[n].reload.l14.name = "reload14";
	Locations[n].reload.l14.go = "Muelle_Tavern";
	Locations[n].reload.l14.emerge = "reload1";
	Locations[n].reload.l14.autoreload = "0";
	Locations[n].reload.l14.label = "Tavern.";

	Locations[n].reload.l17.name = "reload17";
	Locations[n].reload.l17.go = "Muelle_Shipyard";
	Locations[n].reload.l17.emerge = "locator2";
	Locations[n].reload.l17.autoreload = "0";
	Locations[n].reload.l17.label = "Shipyard.";
	Locations[n].reload.l17.close_for_night = 1;

	Locations[n].reload.l20.name = "reload20";
	Locations[n].reload.l20.go = "Muelle_town_02";
	Locations[n].reload.l20.emerge = "reload4";
	Locations[n].reload.l20.autoreload = "0";
	Locations[n].reload.l20.label = "Isla Muelle.";

	Locations[n].reload.l21.name = "reload6";
	Locations[n].reload.l21.go = "Muelle_InsideHouseR6";
	Locations[n].reload.l21.emerge = "reload1";
	Locations[n].reload.l21.autoreload = "0";
	Locations[n].reload.l21.label = "House.";

	Locations[n].reload.l22.name = "reload5";
	Locations[n].reload.l22.go = "Muelle_InsideHouseR5";
	Locations[n].reload.l22.emerge = "reload1";
	Locations[n].reload.l22.autoreload = "0";
	Locations[n].reload.l22.label = "House.";

	Locations[n].reload.l23.name = "reload19";
	Locations[n].reload.l23.go = "Muelle_InsideHouseR19";
	Locations[n].reload.l23.emerge = "reload1";
	Locations[n].reload.l23.autoreload = "0";
	Locations[n].reload.l23.label = "House.";


	Locations[n].reload.l24.name = "reload12";
	Locations[n].reload.l24.go = "Muelle_InsideHouseR12";
	Locations[n].reload.l24.emerge = "reload1";
	Locations[n].reload.l24.autoreload = "0";
	Locations[n].reload.l24.label = "House.";

	Locations[n].reload.l25.name = "reload26";
	Locations[n].reload.l25.go = "Muelle_InsideHouseR26";
	Locations[n].reload.l25.emerge = "reload1";
	Locations[n].reload.l25.autoreload = "0";
	Locations[n].reload.l25.label = "House.";

	//Hitman

	Locations[n].reload.l29.name = "Reload21";
	Locations[n].reload.l29.go = "Hit_house";
	Locations[n].reload.l29.emerge = "Reload1";
	Locations[n].reload.l29.autoreload = "0";
	Locations[n].reload.l29.label = "House of Mateus Santos";

	//Hitman


	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\town_IslaMuelle\town_02";

	Locations[n].id = "Muelle_town_02";
	locations[n].id.label = "Isla Muelle";
	locations[n].worldmap = "Isla Muelle";
	Locations[n].image = "loading\Isla_Muelle_Town_02.tga";
	//Sound

	//Town sack
	Locations[n].townsack = "Isla Muelle";

	locations[n].type = "town";
	LAi_LocationFantomsGen(&locations[n], true);
	locations[n].fastreload = "Muelle";
	//Models
	//Always
	Locations[n].models.always.locators = "Mu02_l";
	Locations[n].models.always.l1 = "Mu02";
	Locations[n].models.always.grassPatch = "Mu02_g";
	//Day
	Locations[n].models.day.charactersPatch = "Mu02_p";
	Locations[n].models.day.jumpPatch = "Mu02_j";
	Locations[n].models.day.fonar = "Mu02_fd";
	//Night
	Locations[n].models.night.charactersPatch = "Mu02_p";
	Locations[n].models.night.fonar = "Mu02_fn";
	Locations[n].models.night.jumpPatch = "Mu02_j";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	//Reload map

	Locations[n].reload.l4.name = "Reload4";
	Locations[n].reload.l4.go = "Muelle_town_01";
	Locations[n].reload.l4.emerge = "reload20";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "Isla Muelle. Trade Square.";

	Locations[n].reload.l23.name = "reload3";
	Locations[n].reload.l23.go = "Muelle_InsideHouseR3";
	Locations[n].reload.l23.emerge = "reload1";
	Locations[n].reload.l23.autoreload = "0";
	Locations[n].reload.l23.label = "House.";

	Locations[n].reload.l24.name = "reload2";
	Locations[n].reload.l24.go = "Muelle_InsideHouseR2";
	Locations[n].reload.l24.emerge = "reload1";
	Locations[n].reload.l24.autoreload = "0";
	Locations[n].reload.l24.label = "House.";

	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\town_IslaMuelle\town_03";

	Locations[n].id = "Muelle_town_03";
	locations[n].id.label = "Isla Muelle";
	locations[n].worldmap = "Isla Muelle";
	Locations[n].image = "loading\Isla_Muelle_Town_03.tga";

	//Town sack
	Locations[n].townsack = "Isla Muelle";

	//Sound
	locations[n].type = "town";
	LAi_LocationFantomsGen(&locations[n], true);
	locations[n].fastreload = "Muelle";
	//Models
	//Always
	Locations[n].models.always.l1 = "Mu03";
	Locations[n].models.always.locators = "Mu03_l";
	Locations[n].models.always.grassPatch = "Mu03_g";
	//Day
	Locations[n].models.day.rinok = "Mu03_e1";
	Locations[n].models.day.fonar = "Mu03_fd";
	Locations[n].models.day.jumppatch = "Mu03_j";
	Locations[n].models.day.charactersPatch = "Mu03_pd";
	//Night
	Locations[n].models.night.fonar = "Mu03_fn";
	Locations[n].models.night.jumppatch = "Mu03_j";
	Locations[n].models.night.charactersPatch = "Mu03_pn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map

    Locations[n].reload.l1.name = "Reload1";
	Locations[n].reload.l1.go = "Muelle_town_exit";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Jungle.";

	Locations[n].reload.l2.name = "Reload6";
	Locations[n].reload.l2.go = "Muelle_town_01";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Isla Muelle. Trade Square.";
	Locations[n].locators_radius.reload.reload6 = 2.0;

    Locations[n].reload.l3.name = "Reload9";
	Locations[n].reload.l3.go = "Muelle_town_01";
	Locations[n].reload.l3.emerge = "reload4";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Isla Muelle. Trade Square.";
	Locations[n].locators_radius.reload.reload9 = 2.0;

    Locations[n].reload.l6.name = "Reload6_back";
	Locations[n].reload.l6.go = "Muelle_town_01";
	Locations[n].reload.l6.emerge = "reload2";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].reload.l6.label = "Isla Muelle. Trade Square.";
	Locations[n].locators_radius.reload.reload6_back = 2.0;

    Locations[n].reload.l9.name = "Reload9_back";
	Locations[n].reload.l9.go = "Muelle_town_01";
	Locations[n].reload.l9.emerge = "reload4";
	Locations[n].reload.l9.autoreload = "1";
	Locations[n].reload.l9.label = "Isla Muelle. Trade Square.";
	Locations[n].locators_radius.reload.reload9_back = 2.0;

	Locations[n].reload.l10.name = "Reload2";
	Locations[n].reload.l10.go = "Muelle_InsideHouseR2(03)";
	Locations[n].reload.l10.emerge = "reload1";
	Locations[n].reload.l10.autoreload = "0";
	Locations[n].reload.l10.label = "House.";

	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\town_IslaMuelle\town_04";

	Locations[n].id = "Muelle_town_04";
	locations[n].id.label = "Isla Muelle";
	locations[n].worldmap = "Isla Muelle";
	Locations[n].image = "loading\Isla_Muelle_Town_04.tga";

	//Town sack
	Locations[n].townsack = "Isla Muelle";

	//Sound
	locations[n].type = "town";
	LAi_LocationFantomsGen(&locations[n], true);
	locations[n].fastreload = "Muelle";
	//Models
	//Always
	Locations[n].models.always.locators = "Mu04_l";
	Locations[n].models.always.l1 = "Mu04";
	Locations[n].models.always.grassPatch = "Mu04_g";
	//Day
	Locations[n].models.day.fonar = "Mu04_fd";
	Locations[n].models.day.charactersPatch = "Mu04_pd";
	Locations[n].models.day.jumpPatch = "Mu04_j";
	//Night
	Locations[n].models.night.fonar = "Mu04_fn";
	Locations[n].models.night.charactersPatch = "Mu04_pn";
	Locations[n].models.night.jumpPatch = "Mu04_j";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Muelle_town_01";
	Locations[n].reload.l3.emerge = "reload3";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Isla Muelle. Trade Square.";
	Locations[n].locators_radius.reload.reload3 = 2.0;

	Locations[n].reload.l2.name = "reload3_back";
	Locations[n].reload.l2.go = "Muelle_town_01";
	Locations[n].reload.l2.emerge = "reload3";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Isla Muelle. Trade Square.";
	Locations[n].locators_radius.reload.reload3_back = 1.2;

	Locations[n].reload.l5.name = "reload5";
	Locations[n].reload.l5.go = "Muelle_Residence";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "Residence.";
	Locations[n].reload.l5.close_for_night = 1;

	Locations[n].reload.l6.name = "reload4";
	Locations[n].reload.l6.go = "Muelle_church";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "Church.";
	Locations[n].reload.l6.close_for_night = 1;

	Locations[n].reload.l7.name = "reload1";
	Locations[n].reload.l7.go = "Muelle_HouseInsideR1";
	Locations[n].reload.l7.emerge = "reload1";
	Locations[n].reload.l7.autoreload = "0";
	Locations[n].reload.l7.label = "House.";
	Locations[n].reload.l7.close_for_night = 1;

	Locations[n].reload.l8.name = "reload6";
	Locations[n].reload.l8.go = "Muelle04_HouseInsideR6";
	Locations[n].reload.l8.emerge = "reload1";
	Locations[n].reload.l8.autoreload = "0";
	Locations[n].reload.l8.label = "House.";
	Locations[n].reload.l8.close_for_night = 1;

	n = n + 1;


	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\shipyard2";

	Locations[n].id = "Muelle_shipyard";
	locations[n].id.label = "Isla Muelle shipyard";
	Locations[n].image = "loading\shipyard_03.tga";

	//Town sack
	Locations[n].townsack = "Isla Muelle";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Muelle";
	//Models
	//Always
	Locations[n].models.always.locators = "sh02_l";
	Locations[n].models.always.shipyard = "sh02";
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
	Locations[n].models.back = "back\mush2_";
	//Reload map
	Locations[n].reload.l1.name = "locator2";
	Locations[n].reload.l1.go = "Muelle_town_01";
	Locations[n].reload.l1.emerge = "Reload17";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Isla Muelle. Trade Square.";
	LAi_LocationFightDisable(&Locations[n], true);

	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\mh5";

	Locations[n].id = "Muelle_HouseInsideR1";
	locations[n].id.label = "House";
	Locations[n].image = "loading\house_06.tga";

	//Town sack
	Locations[n].townsack = "Isla Muelle";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Muelle";
	//Models
	//Always
	Locations[n].models.always.locators = "mh5_l";
	Locations[n].models.always.tavern = "mh5";
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
	Locations[n].models.back = "back\mumh5_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Muelle_town_04";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Isla Muelle. Center.";
	n = n + 1;


	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\StoreSmall";
	Locations[n].image = "loading\store_04.tga";

	Locations[n].id = "Muelle_Store";
	locations[n].id.label = "Isla Muelle store";

	//Town sack
	Locations[n].townsack = "Isla Muelle";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Muelle";
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
	Locations[n].models.night.fonar = "SS_fn";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\muss_";
	//Reload map
	Locations[n].reload.l1.name = "locator2";
	Locations[n].reload.l1.go = "Muelle_town_01";
	Locations[n].reload.l1.emerge = "Reload8";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Isla Muelle. Trade Square.";
	LAi_LocationFightDisable(&Locations[n], true);

	n = n + 1;


	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\SmallTavern";

	Locations[n].id = "Muelle_Tavern";
	locations[n].id.label = "Isla Muelle tavern";
	Locations[n].image = "loading\tavern_03.tga";

	//Town sack
	Locations[n].townsack = "Isla Muelle";

	//Sound
	locations[n].type = "tavern";
	locations[n].fastreload = "Muelle";
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
	Locations[n].models.back = "back\must_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Muelle_town_01";
	Locations[n].reload.l1.emerge = "reload14";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Isla Muelle. Trade Square.";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Muelle_tavern_upstairs";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Room.";
	LAi_LocationFightDisable(&Locations[n], true);

	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\Doubleflour_house";
	Locations[n].id = "Muelle_tavern_upstairs";
	locations[n].id.label = "Room in Isla Muelle tavern";
	Locations[n].image = "loading\Tavern_Upstairs_01.tga";

	//Town sack
	Locations[n].townsack = "Isla Muelle";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Muelle";
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
	Locations[n].models.back = "back\mulf2_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Muelle_tavern";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Tavern.";

	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\Doubleflour_house";
	Locations[n].id = "Muelle_InsideHouseR6";
	locations[n].id.label = "House.";
	Locations[n].image = "loading\house_07.tga";

	//Town sack
	Locations[n].townsack = "Isla Muelle";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Muelle";
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
	Locations[n].models.back = "back\mulf2_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Muelle_town_01";
	Locations[n].reload.l1.emerge = "reload6";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "House.";

	n = n + 1;

	// --------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\mh4";
	Locations[n].id = "Muelle_InsideHouseR5";
	locations[n].id.label = "House.";
	Locations[n].image = "loading\house_05.tga";

	//Town sack
	Locations[n].townsack = "Isla Muelle";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Muelle";
	//Models
	//Always
	Locations[n].models.always.locators = "mh4_l";
	Locations[n].models.always.house = "mh4";
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
	Locations[n].models.back = "back\mumh4_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Muelle_town_01";
	Locations[n].reload.l1.emerge = "reload5";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "House.";

	n = n + 1;


	// -----------^--------------------------------------
	Locations[n].filespath.models = "locations\Inside\MH9";
	Locations[n].id = "Muelle_InsideHouseR3";
	locations[n].id.label = "House.";
	Locations[n].image = "loading\house_05.tga";

	//Town sack
	Locations[n].townsack = "Isla Muelle";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Muelle";
	//Models
	//Always
	Locations[n].models.always.locators = "MH9_l";
	Locations[n].models.always.house = "MH9";
	Locations[n].models.always.window = "MH9_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "MH9_p";

	//Night
	Locations[n].models.night.charactersPatch = "MH9_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\mumh9_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Muelle_town_02";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "House.";

	n = n + 1;


	// -----------^--------------------------------------
	Locations[n].filespath.models = "locations\Inside\MH5";
	Locations[n].id = "Muelle_InsideHouseR2";
	locations[n].id.label = "House.";
	Locations[n].image = "loading\house_06.tga";

	//Town sack
	Locations[n].townsack = "Isla Muelle";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Muelle";
	//Models
	//Always
	Locations[n].models.always.locators = "MH5_l";
	Locations[n].models.always.house = "MH5";
	Locations[n].models.always.window = "MH5_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "MH5_p";

	//Night
	Locations[n].models.night.charactersPatch = "MH5_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\mumh5_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Muelle_town_02";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "House.";

	n = n + 1;


	// --------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\mh3";
	Locations[n].id = "Muelle_InsideHouseR19";
	locations[n].id.label = "House.";
	Locations[n].image = "loading\house_04.tga";

	//Town sack
	Locations[n].townsack = "Isla Muelle";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Muelle";
	//Models
	//Always
	Locations[n].models.always.locators = "mh3_l";
	Locations[n].models.always.house = "mh3";
	Locations[n].models.always.window = "mh3_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "mh3_p";

	//Night
	Locations[n].models.night.charactersPatch = "mh3_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\mumh3_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Muelle_town_01";
	Locations[n].reload.l1.emerge = "reload19";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "House.";

	n = n + 1;


	// --------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\mh8";
	Locations[n].id = "Muelle_InsideHouseR12";
	locations[n].id.label = "House.";
	Locations[n].image = "loading\House_06.tga";

	//Town sack
	Locations[n].townsack = "Isla Muelle";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Muelle";
	//Models
	//Always
	Locations[n].models.always.locators = "mh8_l";
	Locations[n].models.always.house = "mh8";
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
	Locations[n].models.back = "back\mumh8_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Muelle_town_01";
	Locations[n].reload.l1.emerge = "reload12";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "House.";

	Locations[n].locators_radius.camdetector.camera1 = 3.0;
	Locations[n].locators_radius.camdetector.camera2 = 1.8;

	n = n + 1;

	// --------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\MH9";
	Locations[n].id = "Muelle_InsideHouseR26";
	locations[n].id.label = "House.";
	Locations[n].image = "loading\house_05.tga";

	//Town sack
	Locations[n].townsack = "Isla Muelle";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Muelle";
	//Models
	//Always
	Locations[n].models.always.locators = "MH9_l";
	Locations[n].models.always.house = "MH9";
	Locations[n].models.always.window = "MH9_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "MH9_p";

	//Night
	Locations[n].models.night.charactersPatch = "MH9_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\mumh9_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Muelle_town_01";
	Locations[n].reload.l1.emerge = "reload26";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "House.";

	n = n + 1;

	// -----------^--------------------------------------
	Locations[n].filespath.models = "locations\Inside\MH8";
	Locations[n].id = "Muelle_InsideHouseR2(03)";
	locations[n].id.label = "House.";
	Locations[n].image = "loading\House_06.tga";

	//Town sack
	Locations[n].townsack = "Isla Muelle";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Muelle";
	//Models
	//Always
	Locations[n].models.always.locators = "MH8_l";
	Locations[n].models.always.house = "MH8";
	Locations[n].models.always.window = "MH8_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "MH8_p";

	//Night
	Locations[n].models.night.charactersPatch = "MH8_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\mumh8_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Muelle_town_03";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Isla Muelle. Center.";

	Locations[n].locators_radius.camdetector.camera1 = 3.0;
	Locations[n].locators_radius.camdetector.camera2 = 1.8;

	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\Doubleflour_house";
	Locations[n].id = "Muelle_UsurerHouse";
	locations[n].id.label = "Loanshark's Office.";
	Locations[n].image = "loading\house_08.tga";

	//Town sack
	Locations[n].townsack = "Isla Muelle";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Muelle";
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
	Locations[n].models.back = "back\mulf1_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Muelle_town_01";
	Locations[n].reload.l1.emerge = "reload10";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Isla Muelle.";
	LAi_LocationFightDisable(&Locations[n], true);

	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\Residence3";

	Locations[n].id = "Muelle_Residence";
	locations[n].id.label = "Isla Muelle townhall";
	Locations[n].image = "loading\Isla_muelle_residence.tga";

	//Town sack
	Locations[n].townsack = "Isla Muelle";

	//Sound
	locations[n].type = "residence";
	locations[n].fastreload = "Muelle";
	//Models
	//Always
	Locations[n].models.always.locators = "Res03_l";
	Locations[n].models.always.l1 = "Res03";
	Locations[n].models.always.window = "Res03_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "Res03_p";

	//Night
	Locations[n].models.night.charactersPatch = "Res03_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\mures3_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Muelle_town_04";
	Locations[n].reload.l1.emerge = "reload5";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Isla Muelle. Center.";
	LAi_LocationFightDisable(&Locations[n], true);

	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\Doubleflour_house";
	Locations[n].id = "house_of_Sylvie_Bondies";
	locations[n].id.label = "House in Isla Muelle";
	Locations[n].image = "loading\room.tga";

	//Town sack
	Locations[n].townsack = "Isla Muelle";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Muelle";
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
	Locations[n].models.back = "back\mulf2_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Muelle_town_01";
	Locations[n].reload.l1.emerge = "reload13";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Isla Muelle. Trade Square.";
	LAi_LocationFightDisable(&Locations[n], true);

	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\town_IslaMuelle\exit";

	Locations[n].id = "Muelle_town_exit";
	locations[n].id.label = "Exit from Isla Muelle";
	Locations[n].image = "loading\Isla_Muelle_Town_exit.tga";

	//Town sack
	Locations[n].townsack = "Isla Muelle";

	//Sound
	locations[n].type = "jungle";
//	locations[n].fastreload = "Muelle";
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);

	//Models
	//Always
	Locations[n].models.always.locators = "muexit_l";
	Locations[n].models.always.l1 = "muexit";
	Locations[n].models.always.grassPatch = "muexit_g";
	Locations[n].models.always.l4 = "plan_1";
	Locations[n].models.always.l4.level = 9;
	Locations[n].models.always.l4.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan_2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "plan_3";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";
	//Day
	Locations[n].models.day.charactersPatch = "muexit_p";
	Locations[n].models.day.fonar = "muexit_fd";
	//Night
	Locations[n].models.night.charactersPatch = "muexit_p";
	Locations[n].models.night.fonar = "muexit_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";

	//Reload map

	Locations[n].reload.l3.name = "Reload1";
	Locations[n].reload.l3.go = "Muelle_passage";
	Locations[n].reload.l3.emerge = "Reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Sea Passage.";

	Locations[n].reload.l1.name = "Reload1_back";
	Locations[n].reload.l1.go = "Muelle_passage";
	Locations[n].reload.l1.emerge = "Reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].locators_radius.reload.reload1_back = 3.5;
	Locations[n].reload.l1.label = "Sea Passage.";

	Locations[n].reload.l2.name = "Reload2";
	Locations[n].reload.l2.go = "Muelle_Town_03";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Isla Muelle.";

	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Passage";

	Locations[n].id = "Muelle_passage";
	locations[n].id.label = "Isla Muelle passage";
	Locations[n].image = "loading\Isla_Muelle_Shore_01.tga";
	//Sound
	locations[n].type = "seashore";

	//Models
	//Always
	Locations[n].models.always.locators = "pass2_l";
	Locations[n].models.always.jungle = "pass2";
	Locations[n].models.always.jungle.foam = "1";
	Locations[n].models.always.seabed = "pass2_sb";
	Locations[n].models.always.seabed.foam = "1";
	Locations[n].models.always.grassPatch = "pass2_g";
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
	Locations[n].models.day.charactersPatch = "pass2_p";
	//Night
	Locations[n].models.night.charactersPatch = "pass2_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map
	Locations[n].reload.l1.name = "reload2";
	Locations[n].reload.l1.go = "Muelle_town_exit";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	//Locations[n].locators_radius.reload.reload2 = 2.0;
	Locations[n].reload.l1.label = "Jungle.";

	Locations[n].reload.l2.name = "reload2_back";
	Locations[n].reload.l2.go = "Muelle_town_exit";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].locators_radius.reload.reload2 = 2.0;
	Locations[n].reload.l2.label = "Jungle.";

	Locations[n].reload.l3.name = "reload1";
	Locations[n].reload.l3.go = "Muelle_shore";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Oyster Beach.";
//	Locations[n].locators_radius.reload.reload1 = 2.0;

	Locations[n].reload.l4.name = "reload1_back";
	Locations[n].reload.l4.go = "Muelle_shore";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Oyster Beach.";
	Locations[n].locators_radius.reload.reload1_back = 2.0;

	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Passage";

	Locations[n].id = "Muelle_shore";
	locations[n].id.label = "Isla Muelle shore";
	locations[n].worldmap = "MShore 1";
	Locations[n].image = "loading\Isla_Muelle_Bridge.tga";
	Locations[n].name = "Oyster Beach";
	//Sound
	locations[n].type = "seashore";

	//Models
	//Always
	Locations[n].models.always.locators = "Pass1_l";
	Locations[n].models.always.shore = "Pass1";
	Locations[n].models.always.shore.foam = "1";
	Locations[n].models.always.seabed = "Pass1_sb";
	Locations[n].models.always.seabed.foam = "1";
	Locations[n].models.always.grassPatch = "Pass1_g";
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
	Locations[n].models.day.charactersPatch = "Pass1_p";
	//Night
	Locations[n].models.night.charactersPatch = "Pass1_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Muelle_passage";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Sea Passage.";

	Locations[n].reload.l3.name = "reload1_back";
	Locations[n].reload.l3.go = "Muelle_passage";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Sea Passage.";

	Locations[n].reload.l2.name = "boat";
	Locations[n].reload.l2.go = "IslaMuelle";
	Locations[n].reload.l2.emerge = "reload_3";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Sea.";
	Locations[n].locators_radius.reload.boat = 9.0;

	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\Doubleflour_house";
	Locations[n].id = "Sidonio Ogarrio House";
	locations[n].id.label = "House in Isla Muelle";
	Locations[n].image = "loading\House_08.tga";

	//Town sack
	Locations[n].townsack = "Isla Muelle";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Muelle";
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
	Locations[n].models.back = "back\mulf1_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Muelle_town_02";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Isla Muelle.";

	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Outside\Shore_9";

	Locations[n].id = "Muelle_shore_02";
	locations[n].id.label = "Isla Muelle shore";
	locations[n].worldmap = "MShore 2";
	Locations[n].image = "loading\Isla_Muelle_Shore_02.tga";
	//Sound
	locations[n].type = "seashore";

	//Models
	//Always
	Locations[n].models.always.locators = "Shore09_l";
	Locations[n].models.always.shore = "Shore09";
	Locations[n].models.always.shore.foam = "1";
	Locations[n].models.always.seabed = "Shore09_sb";
	Locations[n].models.always.seabed.foam = "1";
	Locations[n].models.always.grassPatch = "Shore09_g";
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
	Locations[n].models.day.charactersPatch = "Shore09_p";
	//Night
	Locations[n].models.night.charactersPatch = "Shore09_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map
	Locations[n].reload.l1.name = "locator3";
	Locations[n].reload.l1.go = "Muelle_cave";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.locator3 = 2.0;

	Locations[n].reload.l3.name = "locator3_back";
	Locations[n].reload.l3.go = "Muelle_cave";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.locator3_back = 2.0;

	Locations[n].reload.l2.name = "boat";
	Locations[n].reload.l2.go = "IslaMuelle";
	Locations[n].reload.l2.emerge = "reload_2";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Sea.";
	Locations[n].locators_radius.reload.boat = 9.0;

	n = n + 1;

// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Cave Entrance";

	Locations[n].id = "Muelle_Cave";
	locations[n].id.label = "Entrace to Isla Muelle cave";
	Locations[n].image = "loading\Isla_Muelle_Cave.tga";
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
	Locations[n].reload.l1.name = "reload1_back";
	Locations[n].reload.l1.go = "Muelle_ANIMISTS";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Cave.";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Muelle_shore_02";
	Locations[n].reload.l2.emerge = "locator3";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Shore.";
	Locations[n].locators_radius.reload.reload2 = 2.0;

	Locations[n].reload.l3.name = "reload2_back";
	Locations[n].reload.l3.go = "Muelle_shore_02";
	Locations[n].reload.l3.emerge = "locator3";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Shore.";
	Locations[n].locators_radius.reload.reload2_back = 2.0;

	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\ANIMISTS_Cave";
	Locations[n].id = "Muelle_ANIMISTS";
	locations[n].id.label = "ANIMISTS Lair";
	Locations[n].image = "loading\Isla_Muelle_ANIMISTS_Cave.tga";
	//Sound
	locations[n].type = "cave";

	//Models
	//Always
	Locations[n].models.always.locators = "SCave_l";
	Locations[n].models.always.l1 = "SCave";
	//Day
	Locations[n].models.day.charactersPatch = "SCave_p";
	//Night
	Locations[n].models.night.charactersPatch = "SCave_p";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Muelle_Cave";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";

	Locations[n].reload.l2.name = "reload1_back";
	Locations[n].reload.l2.go = "Muelle_Cave";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1_back = 2.0;

	n = n + 1;

	// Isla Muelle_church -------------------------------------------------
	Locations[n].id = "Muelle_church";
	locations[n].id.label = "Isla Muelle church";
	Locations[n].image = "loading\Isla_Muelle_Church.tga";
	Locations[n].filespath.models = "locations\inside\Church_3\";

	//Town sack
	Locations[n].townsack = "Isla Muelle";

	//Sound
	locations[n].type = "church";
	locations[n].fastreload = "Muelle";
	//Models
	//Always
	Locations[n].models.always.city = "Church3";
	Locations[n].models.always.locators = "Church3_l";
	Locations[n].models.always.window = "church3_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
//	Locations[n].models.day.lamp = "FalaiseDeFleur05_day";
	Locations[n].models.day.charactersPatch = "Church3_p";

	//Night
//	Locations[n].models.night.lamp = "FalaiseDeFleur05_night";
	Locations[n].models.night.charactersPatch = "Church3_p";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Muelle_town_04";
	Locations[n].reload.l1.emerge = "reload4";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Isla Muelle. Center.";
	LAi_LocationFightDisable(&Locations[n], true);

	n = n + 1;


// Isla Muelle_church -------------------------------------------------
	Locations[n].id = "Muelle04_HouseInsideR6";
	locations[n].id.label = "House";
	Locations[n].image = "loading\isla_muelle_house.tga";
	Locations[n].filespath.models = "locations\inside\Residence2\";

	//Town sack
	Locations[n].townsack = "Isla Muelle";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Muelle";
	//Models
	//Always
	Locations[n].models.always.city = "Res02";
	Locations[n].models.always.locators = "Res02_l";
	Locations[n].models.always.window = "Res02_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
//	Locations[n].models.day.lamp = "FalaiseDeFleur05_day";
	Locations[n].models.day.charactersPatch = "Res02_p";

	//Night
//	Locations[n].models.night.lamp = "FalaiseDeFleur05_night";
	Locations[n].models.night.charactersPatch = "Res02_p";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\mures2_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Muelle_town_04";
	Locations[n].reload.l1.emerge = "reload6";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Isla Muelle. Center.";
	LAi_LocationFightDisable(&Locations[n], false);

	Locations[n].items.randitem1 = "pistol6";

	n = n + 1;

	return n;
}
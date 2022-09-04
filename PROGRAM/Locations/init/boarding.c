

int LocationInitBoarding(int n)
{

	// -------------------------------------------------
	//Default
	// -------------------------------------------------
	//ID
	Locations[n].id = LOCINITBRD_DEFAULTLOCATION;
	locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\udeck";
	Locations[n].image = "loading\Boarding.tga";
	//Sound
	locations[n].type = "deck";
	Locations[n].lockCamAngle = 0.4;

	//Models
	//Always
	Locations[n].models.always.locators = "udeck_l";
	Locations[n].models.always.l1 = "udeck";
	//Day
	Locations[n].models.day.charactersPatch = "udeck_p";
	//Night
	Locations[n].models.night.charactersPatch = "udeck_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "true";
	Locations[n].boarding.nextdeck = "ship default deck next";
	
	n = n + 1;
	
	// -------------------------------------------------
	//ID
	Locations[n].id = "ship default deck next";
	Locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\hold";
	Locations[n].image = "loading\Deck_03.tga";
	//Sound
	Locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "hold_l";
	Locations[n].models.always.l1 = "hold";
	//Day
	Locations[n].models.day.charactersPatch = "hold_p";
	Locations[n].models.day.fonar = "hold_fd";
	//Night
	Locations[n].models.night.charactersPatch = "hold_p";
	Locations[n].models.night.fonar = "hold_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "true";
	Locations[n].boarding.nextdeck = Locations[n].id;
	
	n = n + 1;

	// -------------------------------------------------
	//
	// -------------------------------------------------
	// -------------------------------------------------
	// -------------------------------------------------
	// ------------------------------------------6 class
	//ID
	Locations[n].id = "BOARDING_BARQUE";
	locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\udeck";
	Locations[n].image = "loading\Boarding.tga";
	//Sound
	locations[n].type = "deck";
	Locations[n].lockCamAngle = 0.4;

	//Models
	//Always
	Locations[n].models.always.locators = "udeck_l";
	Locations[n].models.always.l1 = "udeck";
	//Day
	Locations[n].models.day.charactersPatch = "udeck_p";
	//Night
	Locations[n].models.night.charactersPatch = "udeck_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "true";
	Locations[n].boarding.nextdeck = "";
	
	n = n + 1;
	// -------------------------------------------------

	//ID
	Locations[n].id = "BOARDING_YACHT";
	locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\udeck";
	Locations[n].image = "loading\Boarding.tga";
	//Sound
	locations[n].type = "deck";
	Locations[n].lockCamAngle = 0.4;

	//Models
	//Always
	Locations[n].models.always.locators = "udeck_l";
	Locations[n].models.always.l1 = "udeck";
	//Day
	Locations[n].models.day.charactersPatch = "udeck_p";
	//Night
	Locations[n].models.night.charactersPatch = "udeck_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "true";
	Locations[n].boarding.nextdeck = "";
	
	n = n + 1;
	// -------------------------------------------------

	//ID
	Locations[n].id = "BOARDING_LUGGER";
	locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\udeck";
	Locations[n].image = "loading\Boarding.tga";
	//Sound
	locations[n].type = "deck";
	Locations[n].lockCamAngle = 0.4;

	//Models
	//Always
	Locations[n].models.always.locators = "udeck_l";
	Locations[n].models.always.l1 = "udeck";
	//Day
	Locations[n].models.day.charactersPatch = "udeck_p";
	//Night
	Locations[n].models.night.charactersPatch = "udeck_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "true";
	Locations[n].boarding.nextdeck = "";
	
	n = n + 1;
	// -------------------------------------------------
	// -------------------------------------------------
	// ------------------------------------------5 class
	//ID
	Locations[n].id = "BOARDING_SLOOP";
	locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\udeck";
	Locations[n].image = "loading\Boarding.tga";
	//Sound
	locations[n].type = "deck";
	Locations[n].lockCamAngle = 0.4;

	//Models
	//Always
	Locations[n].models.always.locators = "udeck_l";
	Locations[n].models.always.l1 = "udeck";
	//Day
	Locations[n].models.day.charactersPatch = "udeck_p";
	//Night
	Locations[n].models.night.charactersPatch = "udeck_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "true";
	Locations[n].boarding.nextdeck = "NEXT_SLOOP";
	
	n = n + 1;
	
	//ID
	Locations[n].id = "NEXT_SLOOP";
	Locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\deck1";
	Locations[n].image = "loading\Deck_01.tga";
	//Sound
	Locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "deck1_l";
	Locations[n].models.always.l1 = "deck1";
	//Day
	Locations[n].models.day.charactersPatch = "deck1_p";
	Locations[n].models.day.fonar = "deck1_fd";
	//Night
	Locations[n].models.night.charactersPatch = "deck1_p";
	Locations[n].models.night.fonar = "deck1_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "true";
	Locations[n].boarding.nextdeck = "";
	
	n = n + 1;
	// -------------------------------------------------
	//ID
	Locations[n].id = "BOARDING_GALEOTH";
	locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\udeck";
	Locations[n].image = "loading\Boarding.tga";
	//Sound
	locations[n].type = "deck";
	Locations[n].lockCamAngle = 0.4;

	//Models
	//Always
	Locations[n].models.always.locators = "udeck_l";
	Locations[n].models.always.l1 = "udeck";
	//Day
	Locations[n].models.day.charactersPatch = "udeck_p";
	//Night
	Locations[n].models.night.charactersPatch = "udeck_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "true";
	Locations[n].boarding.nextdeck = "NEXT_GALEOTH";
	
	n = n + 1;
	
	//ID
	Locations[n].id = "NEXT_GALEOTH";
	Locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\deck1";
	Locations[n].image = "loading\Deck_01.tga";
	//Sound
	Locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "deck1_l";
	Locations[n].models.always.l1 = "deck1";
	//Day
	Locations[n].models.day.charactersPatch = "deck1_p";
	Locations[n].models.day.fonar = "deck1_fd";
	//Night
	Locations[n].models.night.charactersPatch = "deck1_p";
	Locations[n].models.night.fonar = "deck1_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "true";
	Locations[n].boarding.nextdeck = "";
	
	n = n + 1;
	// -------------------------------------------------
	//ID
	Locations[n].id = "BOARDING_XEBEC";
	locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\udeck";
	Locations[n].image = "loading\Boarding.tga";
	//Sound
	locations[n].type = "deck";
	Locations[n].lockCamAngle = 0.4;

	//Models
	//Always
	Locations[n].models.always.locators = "udeck_l";
	Locations[n].models.always.l1 = "udeck";
	//Day
	Locations[n].models.day.charactersPatch = "udeck_p";
	//Night
	Locations[n].models.night.charactersPatch = "udeck_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "true";
	Locations[n].boarding.nextdeck = "NEXT_XEBEC";
	
	n = n + 1;
	
	//ID
	Locations[n].id = "NEXT_XEBEC";
	Locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\hold";
	Locations[n].image = "loading\Deck_03.tga";
	//Sound
	Locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "hold_l";
	Locations[n].models.always.l1 = "hold";
	//Day
	Locations[n].models.day.charactersPatch = "hold_p";
	Locations[n].models.day.fonar = "hold_fd";
	//Night
	Locations[n].models.night.charactersPatch = "hold_p";
	Locations[n].models.night.fonar = "hold_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "true";
	Locations[n].boarding.nextdeck = "";
	
	n = n + 1;
	// -------------------------------------------------
	// -------------------------------------------------
	// ------------------------------------------4 class
	//ID
	Locations[n].id = "BOARDING_SCHOONER";
	locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\udeck";
	Locations[n].image = "loading\Boarding.tga";
	//Sound
	locations[n].type = "deck";
	Locations[n].lockCamAngle = 0.4;

	//Models
	//Always
	Locations[n].models.always.locators = "udeck_l";
	Locations[n].models.always.l1 = "udeck";
	//Day
	Locations[n].models.day.charactersPatch = "udeck_p";
	//Night
	Locations[n].models.night.charactersPatch = "udeck_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "true";
	Locations[n].boarding.nextdeck = "NEXT1_SCHOONER";
	
	n = n + 1;

	//ID
	Locations[n].id = "NEXT1_SCHOONER";
	Locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\deck1";
	Locations[n].image = "loading\Deck_01.tga";
	//Sound
	Locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "deck1_l";
	Locations[n].models.always.l1 = "deck1";
	//Day
	Locations[n].models.day.charactersPatch = "deck1_p";
	Locations[n].models.day.fonar = "deck1_fd";
	//Night
	Locations[n].models.night.charactersPatch = "deck1_p";
	Locations[n].models.night.fonar = "deck1_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "true";
	Locations[n].boarding.nextdeck = "NEXT2_SCHOONER";
	
	n = n + 1;
	
	//ID
	Locations[n].id = "NEXT2_SCHOONER";
	Locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\hold";
	Locations[n].image = "loading\Deck_03.tga";
	//Sound
	Locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "hold_l";
	Locations[n].models.always.l1 = "hold";
	//Day
	Locations[n].models.day.charactersPatch = "hold_p";
	Locations[n].models.day.fonar = "hold_fd";
	//Night
	Locations[n].models.night.charactersPatch = "hold_p";
	Locations[n].models.night.fonar = "hold_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "true";
	Locations[n].boarding.nextdeck = "";
	
	n = n + 1;
	// -------------------------------------------------
	//ID
	Locations[n].id = "BOARDING_CARAVEL";
	locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\udeck";
	Locations[n].image = "loading\Boarding.tga";
	//Sound
	locations[n].type = "deck";
	Locations[n].lockCamAngle = 0.4;

	//Models
	//Always
	Locations[n].models.always.locators = "udeck_l";
	Locations[n].models.always.l1 = "udeck";
	//Day
	Locations[n].models.day.charactersPatch = "udeck_p";
	//Night
	Locations[n].models.night.charactersPatch = "udeck_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "true";
	Locations[n].boarding.nextdeck = "NEXT1_CARAVEL";
	
	n = n + 1;

	//ID
	Locations[n].id = "NEXT1_CARAVEL";
	Locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\deck1";
	Locations[n].image = "loading\Deck_01.tga";
	//Sound
	Locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "deck1_l";
	Locations[n].models.always.l1 = "deck1";
	//Day
	Locations[n].models.day.charactersPatch = "deck1_p";
	Locations[n].models.day.fonar = "deck1_fd";
	//Night
	Locations[n].models.night.charactersPatch = "deck1_p";
	Locations[n].models.night.fonar = "deck1_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "true";
	Locations[n].boarding.nextdeck = "NEXT2_CARAVEL";
	
	n = n + 1;
	
	//ID
	Locations[n].id = "NEXT2_CARAVEL";
	Locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\hold";
	Locations[n].image = "loading\Deck_03.tga";
	//Sound
	Locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "hold_l";
	Locations[n].models.always.l1 = "hold";
	//Day
	Locations[n].models.day.charactersPatch = "hold_p";
	Locations[n].models.day.fonar = "hold_fd";
	//Night
	Locations[n].models.night.charactersPatch = "hold_p";
	Locations[n].models.night.fonar = "hold_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "true";
	Locations[n].boarding.nextdeck = "";
	
	n = n + 1;
	// -------------------------------------------------
	//ID
	Locations[n].id = "BOARDING_FLEUT";
	locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\udeck";
	Locations[n].image = "loading\Boarding.tga";
	//Sound
	locations[n].type = "deck";
	Locations[n].lockCamAngle = 0.4;

	//Models
	//Always
	Locations[n].models.always.locators = "udeck_l";
	Locations[n].models.always.l1 = "udeck";
	//Day
	Locations[n].models.day.charactersPatch = "udeck_p";
	//Night
	Locations[n].models.night.charactersPatch = "udeck_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "true";
	Locations[n].boarding.nextdeck = "NEXT1_FLEUT";
	
	n = n + 1;

	//ID
	Locations[n].id = "NEXT1_FLEUT";
	Locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\deck1";
	Locations[n].image = "loading\Deck_01.tga";
	//Sound
	Locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "deck1_l";
	Locations[n].models.always.l1 = "deck1";
	//Day
	Locations[n].models.day.charactersPatch = "deck1_p";
	Locations[n].models.day.fonar = "deck1_fd";
	//Night
	Locations[n].models.night.charactersPatch = "deck1_p";
	Locations[n].models.night.fonar = "deck1_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "true";
	Locations[n].boarding.nextdeck = "NEXT2_FLEUT";
	
	n = n + 1;
	
	//ID
	Locations[n].id = "NEXT2_FLEUT";
	Locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\hold";
	Locations[n].image = "loading\Deck_03.tga";
	//Sound
	Locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "hold_l";
	Locations[n].models.always.l1 = "hold";
	//Day
	Locations[n].models.day.charactersPatch = "hold_p";
	Locations[n].models.day.fonar = "hold_fd";
	//Night
	Locations[n].models.night.charactersPatch = "hold_p";
	Locations[n].models.night.fonar = "hold_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "true";
	Locations[n].boarding.nextdeck = "";
	
	n = n + 1;
	// -------------------------------------------------
	// -------------------------------------------------
	// ------------------------------------------3 class
	//ID
	Locations[n].id = "BOARDING_PINNACE";
	locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\udeck";
	Locations[n].image = "loading\Boarding.tga";
	//Sound
	locations[n].type = "deck";
	Locations[n].lockCamAngle = 0.4;

	//Models
	//Always
	Locations[n].models.always.locators = "udeck_l";
	Locations[n].models.always.l1 = "udeck";
	//Day
	Locations[n].models.day.charactersPatch = "udeck_p";
	//Night
	Locations[n].models.night.charactersPatch = "udeck_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "true";
	Locations[n].boarding.nextdeck = "NEXT1_PINNACE";
	
	n = n + 1;

	//ID
	Locations[n].id = "NEXT1_PINNACE";
	Locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\deck1";
	Locations[n].image = "loading\Deck_01.tga";
	//Sound
	Locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "deck1_l";
	Locations[n].models.always.l1 = "deck1";
	//Day
	Locations[n].models.day.charactersPatch = "deck1_p";
	Locations[n].models.day.fonar = "deck1_fd";
	//Night
	Locations[n].models.night.charactersPatch = "deck1_p";
	Locations[n].models.night.fonar = "deck1_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "true";
	Locations[n].boarding.nextdeck = "NEXT2_PINNACE";
	
	n = n + 1;
	
	//ID
	Locations[n].id = "NEXT2_PINNACE";
	Locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\hold";
	Locations[n].image = "loading\Deck_03.tga";
	//Sound
	Locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "hold_l";
	Locations[n].models.always.l1 = "hold";
	//Day
	Locations[n].models.day.charactersPatch = "hold_p";
	Locations[n].models.day.fonar = "hold_fd";
	//Night
	Locations[n].models.night.charactersPatch = "hold_p";
	Locations[n].models.night.fonar = "hold_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "true";
	Locations[n].boarding.nextdeck = "NEXT3_PINNACE";
	
	n = n + 1;

	//ID
	Locations[n].id = "NEXT3_PINNACE";
	Locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\cap";
	Locations[n].image = "loading\Cabin.tga";
	//Sound
	Locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "cap_l";
	Locations[n].models.always.l1 = "cap";
	Locations[n].models.always.window = "cap_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 65531;
	//Day
	Locations[n].models.day.charactersPatch = "cap_p";
	Locations[n].models.day.fonar = "cap_fd";
	//Night
	Locations[n].models.night.charactersPatch = "cap_p";
	Locations[n].models.night.fonar = "cap_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "true";
	Locations[n].boarding.nextdeck = "";
	
	n = n + 1;
	// -------------------------------------------------
	//ID
	Locations[n].id = "BOARDING_BRIG";
	locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\udeck";
	Locations[n].image = "loading\Boarding.tga";
	//Sound
	locations[n].type = "deck";
	Locations[n].lockCamAngle = 0.4;

	//Models
	//Always
	Locations[n].models.always.locators = "udeck_l";
	Locations[n].models.always.l1 = "udeck";
	//Day
	Locations[n].models.day.charactersPatch = "udeck_p";
	//Night
	Locations[n].models.night.charactersPatch = "udeck_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "true";
	Locations[n].boarding.nextdeck = "NEXT1_BRIG";
	
	n = n + 1;

	//ID
	Locations[n].id = "NEXT1_BRIG";
	Locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\deck1";
	Locations[n].image = "loading\Deck_01.tga";
	//Sound
	Locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "deck1_l";
	Locations[n].models.always.l1 = "deck1";
	//Day
	Locations[n].models.day.charactersPatch = "deck1_p";
	Locations[n].models.day.fonar = "deck1_fd";
	//Night
	Locations[n].models.night.charactersPatch = "deck1_p";
	Locations[n].models.night.fonar = "deck1_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "true";
	Locations[n].boarding.nextdeck = "NEXT2_BRIG";
	
	n = n + 1;
	
	//ID
	Locations[n].id = "NEXT2_BRIG";
	Locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\hold";
	Locations[n].image = "loading\Deck_03.tga";
	//Sound
	Locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "hold_l";
	Locations[n].models.always.l1 = "hold";
	//Day
	Locations[n].models.day.charactersPatch = "hold_p";
	Locations[n].models.day.fonar = "hold_fd";
	//Night
	Locations[n].models.night.charactersPatch = "hold_p";
	Locations[n].models.night.fonar = "hold_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "true";
	Locations[n].boarding.nextdeck = "NEXT3_BRIG";
	
	n = n + 1;

	//ID
	Locations[n].id = "NEXT3_BRIG";
	Locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\cap";
	Locations[n].image = "loading\Cabin.tga";
	//Sound
	Locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "cap_l";
	Locations[n].models.always.l1 = "cap";
	Locations[n].models.always.window = "cap_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 65531;
	//Day
	Locations[n].models.day.charactersPatch = "cap_p";
	Locations[n].models.day.fonar = "cap_fd";
	//Night
	Locations[n].models.night.charactersPatch = "cap_p";
	Locations[n].models.night.fonar = "cap_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "true";
	Locations[n].boarding.nextdeck = "";
	
	n = n + 1;
	// -------------------------------------------------
	//ID
	Locations[n].id = "BOARDING_GALEON";
	locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\udeck";
	Locations[n].image = "loading\Boarding.tga";
	//Sound
	locations[n].type = "deck";
	Locations[n].lockCamAngle = 0.4;

	//Models
	//Always
	Locations[n].models.always.locators = "udeck_l";
	Locations[n].models.always.l1 = "udeck";
	//Day
	Locations[n].models.day.charactersPatch = "udeck_p";
	//Night
	Locations[n].models.night.charactersPatch = "udeck_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "true";
	Locations[n].boarding.nextdeck = "NEXT1_GALEON";
	
	n = n + 1;

	//ID
	Locations[n].id = "NEXT1_GALEON";
	Locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\deck1";
	Locations[n].image = "loading\Deck_01.tga";
	//Sound
	Locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "deck1_l";
	Locations[n].models.always.l1 = "deck1";
	//Day
	Locations[n].models.day.charactersPatch = "deck1_p";
	Locations[n].models.day.fonar = "deck1_fd";
	//Night
	Locations[n].models.night.charactersPatch = "deck1_p";
	Locations[n].models.night.fonar = "deck1_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "true";
	Locations[n].boarding.nextdeck = "NEXT2_GALEON";
	
	n = n + 1;
	
	//ID
	Locations[n].id = "NEXT2_GALEON";
	Locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\hold";
	Locations[n].image = "loading\Deck_03.tga";
	//Sound
	Locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "hold_l";
	Locations[n].models.always.l1 = "hold";
	//Day
	Locations[n].models.day.charactersPatch = "hold_p";
	Locations[n].models.day.fonar = "hold_fd";
	//Night
	Locations[n].models.night.charactersPatch = "hold_p";
	Locations[n].models.night.fonar = "hold_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "true";
	Locations[n].boarding.nextdeck = "NEXT3_GALEON";
	
	n = n + 1;

	//ID
	Locations[n].id = "NEXT3_GALEON";
	Locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\cap";
	Locations[n].image = "loading\Cabin.tga";
	//Sound
	Locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "cap_l";
	Locations[n].models.always.l1 = "cap";
	Locations[n].models.always.window = "cap_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 65531;
	//Day
	Locations[n].models.day.charactersPatch = "cap_p";
	Locations[n].models.day.fonar = "cap_fd";
	//Night
	Locations[n].models.night.charactersPatch = "cap_p";
	Locations[n].models.night.fonar = "cap_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "true";
	Locations[n].boarding.nextdeck = "";
	
	n = n + 1;

	// -------------------------------------------------
	// -------------------------------------------------
	// ------------------------------------------2 class
	//ID
	Locations[n].id = "BOARDING_CORVETTE";
	locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\udeck";
	Locations[n].image = "loading\Boarding.tga";
	//Sound
	locations[n].type = "deck";
	Locations[n].lockCamAngle = 0.4;

	//Models
	//Always
	Locations[n].models.always.locators = "udeck_l";
	Locations[n].models.always.l1 = "udeck";
	//Day
	Locations[n].models.day.charactersPatch = "udeck_p";
	//Night
	Locations[n].models.night.charactersPatch = "udeck_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "true";
	Locations[n].boarding.nextdeck = "NEXT1_CORVETTE";
	
	n = n + 1;

		//ID
	Locations[n].id = "NEXT1_CORVETTE";
	Locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\deck1";
	Locations[n].image = "loading\Deck_01.tga";
	//Sound
	Locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "deck1_l";
	Locations[n].models.always.l1 = "deck1";
	//Day
	Locations[n].models.day.charactersPatch = "deck1_p";
	Locations[n].models.day.fonar = "deck1_fd";
	//Night
	Locations[n].models.night.charactersPatch = "deck1_p";
	Locations[n].models.night.fonar = "deck1_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "true";
	Locations[n].boarding.nextdeck = "NEXT2_CORVETTE";
	
	n = n + 1;
	
	//ID
	Locations[n].id = "NEXT2_CORVETTE";
	Locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\deck2";
	Locations[n].image = "loading\Deck_02.tga";
	//Sound
	Locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "deck2_l";
	Locations[n].models.always.l1 = "deck2";
	//Day
	Locations[n].models.day.charactersPatch = "deck2_p";
	Locations[n].models.day.fonar = "deck2_fd";
	//Night
	Locations[n].models.night.charactersPatch = "deck2_p";
	Locations[n].models.night.fonar = "deck2_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "true";
	Locations[n].boarding.nextdeck = "NEXT3_CORVETTE";
	
	n = n + 1;

		//ID
	Locations[n].id = "NEXT3_CORVETTE";
	Locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\cap";
	Locations[n].image = "loading\Cabin.tga";
	//Sound
	Locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "cap_l";
	Locations[n].models.always.l1 = "cap";
	Locations[n].models.always.window = "cap_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 65531;
	//Day
	Locations[n].models.day.charactersPatch = "cap_p";
	Locations[n].models.day.fonar = "cap_fd";
	//Night
	Locations[n].models.night.charactersPatch = "cap_p";
	Locations[n].models.night.fonar = "cap_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "true";
	Locations[n].boarding.nextdeck = "";
	
	n = n + 1;
	// -------------------------------------------------
	//ID
	Locations[n].id = "BOARDING_FRIGATE";
	locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\udeck";
	Locations[n].image = "loading\Boarding.tga";
	//Sound
	locations[n].type = "deck";
	Locations[n].lockCamAngle = 0.4;

	//Models
	//Always
	Locations[n].models.always.locators = "udeck_l";
	Locations[n].models.always.l1 = "udeck";
	//Day
	Locations[n].models.day.charactersPatch = "udeck_p";
	//Night
	Locations[n].models.night.charactersPatch = "udeck_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "true";
	Locations[n].boarding.nextdeck = "NEXT1_FRIGATE";
	
	n = n + 1;

		//ID
	Locations[n].id = "NEXT1_FRIGATE";
	Locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\deck1";
	Locations[n].image = "loading\Deck_01.tga";
	//Sound
	Locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "deck1_l";
	Locations[n].models.always.l1 = "deck1";
	//Day
	Locations[n].models.day.charactersPatch = "deck1_p";
	Locations[n].models.day.fonar = "deck1_fd";
	//Night
	Locations[n].models.night.charactersPatch = "deck1_p";
	Locations[n].models.night.fonar = "deck1_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "true";
	Locations[n].boarding.nextdeck = "NEXT2_FRIGATE";
	
	n = n + 1;
	
	//ID
	Locations[n].id = "NEXT2_FRIGATE";
	Locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\deck2";
	Locations[n].image = "loading\Deck_02.tga";
	//Sound
	Locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "deck2_l";
	Locations[n].models.always.l1 = "deck2";
	//Day
	Locations[n].models.day.charactersPatch = "deck2_p";
	Locations[n].models.day.fonar = "deck2_fd";
	//Night
	Locations[n].models.night.charactersPatch = "deck2_p";
	Locations[n].models.night.fonar = "deck2_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "true";
	Locations[n].boarding.nextdeck = "NEXT3_FRIGATE";
	
	n = n + 1;

		//ID
	Locations[n].id = "NEXT3_FRIGATE";
	Locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\cap";
	Locations[n].image = "loading\Cabin.tga";
	//Sound
	Locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "cap_l";
	Locations[n].models.always.l1 = "cap";
	Locations[n].models.always.window = "cap_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 65531;
	//Day
	Locations[n].models.day.charactersPatch = "cap_p";
	Locations[n].models.day.fonar = "cap_fd";
	//Night
	Locations[n].models.night.charactersPatch = "cap_p";
	Locations[n].models.night.fonar = "cap_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "true";
	Locations[n].boarding.nextdeck = "";
	
	n = n + 1;
	// -------------------------------------------------
	// -------------------------------------------------
	// ------------------------------------------1 class
	//ID
	Locations[n].id = "BOARDING_BATTLESHIP";
	locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\udeck";
	Locations[n].image = "loading\Boarding.tga";
	//Sound
	locations[n].type = "deck";
	Locations[n].lockCamAngle = 0.4;

	//Models
	//Always
	Locations[n].models.always.locators = "udeck_l";
	Locations[n].models.always.l1 = "udeck";
	//Day
	Locations[n].models.day.charactersPatch = "udeck_p";
	//Night
	Locations[n].models.night.charactersPatch = "udeck_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "true";
	Locations[n].boarding.nextdeck = "NEXT1_BATTLESHIP";
	
	n = n + 1;

		//ID
	Locations[n].id = "NEXT1_BATTLESHIP";
	Locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\deck1";
	Locations[n].image = "loading\Deck_01.tga";
	//Sound
	Locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "deck1_l";
	Locations[n].models.always.l1 = "deck1";
	//Day
	Locations[n].models.day.charactersPatch = "deck1_p";
	Locations[n].models.day.fonar = "deck1_fd";
	//Night
	Locations[n].models.night.charactersPatch = "deck1_p";
	Locations[n].models.night.fonar = "deck1_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "true";
	Locations[n].boarding.nextdeck = "NEXT2_BATTLESHIP";
	
	n = n + 1;
	
	//ID
	Locations[n].id = "NEXT2_BATTLESHIP";
	Locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\deck2";
	Locations[n].image = "loading\Deck_02.tga";
	//Sound
	Locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "deck2_l";
	Locations[n].models.always.l1 = "deck2";
	//Day
	Locations[n].models.day.charactersPatch = "deck2_p";
	Locations[n].models.day.fonar = "deck2_fd";
	//Night
	Locations[n].models.night.charactersPatch = "deck2_p";
	Locations[n].models.night.fonar = "deck2_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "true";
	Locations[n].boarding.nextdeck = "NEXT3_BATTLESHIP";
	
	n = n + 1;

	//ID
	Locations[n].id = "NEXT3_BATTLESHIP";
	Locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\hold";
	Locations[n].image = "loading\Deck_03.tga";
	//Sound
	Locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "hold_l";
	Locations[n].models.always.l1 = "hold";
	//Day
	Locations[n].models.day.charactersPatch = "hold_p";
	Locations[n].models.day.fonar = "hold_fd";
	//Night
	Locations[n].models.night.charactersPatch = "hold_p";
	Locations[n].models.night.fonar = "hold_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "true";
	Locations[n].boarding.nextdeck = "NEXT4_BATTLESHIP";
	
	n = n + 1;

	//ID
	Locations[n].id = "NEXT4_BATTLESHIP";
	Locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\cap";
	Locations[n].image = "loading\Cabin.tga";
	//Sound
	Locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "cap_l";
	Locations[n].models.always.l1 = "cap";
	Locations[n].models.always.window = "cap_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 65531;
	//Day
	Locations[n].models.day.charactersPatch = "cap_p";
	Locations[n].models.day.fonar = "cap_fd";
	//Night
	Locations[n].models.night.charactersPatch = "cap_p";
	Locations[n].models.night.fonar = "cap_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "true";
	Locations[n].boarding.nextdeck = "";
	
	n = n + 1;
	// -------------------------------------------------
		//ID
	Locations[n].id = "BOARDING_MANOWAR";
	locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\udeck";
	Locations[n].image = "loading\Boarding.tga";
	//Sound
	locations[n].type = "deck";
	Locations[n].lockCamAngle = 0.4;

	//Models
	//Always
	Locations[n].models.always.locators = "udeck_l";
	Locations[n].models.always.l1 = "udeck";
	//Day
	Locations[n].models.day.charactersPatch = "udeck_p";
	//Night
	Locations[n].models.night.charactersPatch = "udeck_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "true";
	Locations[n].boarding.nextdeck = "NEXT1_MANOWAR";
	
	n = n + 1;

		//ID
	Locations[n].id = "NEXT1_MANOWAR";
	Locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\deck1";
	Locations[n].image = "loading\Deck_01.tga";
	//Sound
	Locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "deck1_l";
	Locations[n].models.always.l1 = "deck1";
	//Day
	Locations[n].models.day.charactersPatch = "deck1_p";
	Locations[n].models.day.fonar = "deck1_fd";
	//Night
	Locations[n].models.night.charactersPatch = "deck1_p";
	Locations[n].models.night.fonar = "deck1_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "true";
	Locations[n].boarding.nextdeck = "NEXT2_MANOWAR";
	
	n = n + 1;
	
	//ID
	Locations[n].id = "NEXT2_MANOWAR";
	Locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\deck2";
	Locations[n].image = "loading\Deck_02.tga";
	//Sound
	Locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "deck2_l";
	Locations[n].models.always.l1 = "deck2";
	//Day
	Locations[n].models.day.charactersPatch = "deck2_p";
	Locations[n].models.day.fonar = "deck2_fd";
	//Night
	Locations[n].models.night.charactersPatch = "deck2_p";
	Locations[n].models.night.fonar = "deck2_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "true";
	Locations[n].boarding.nextdeck = "NEXT3_MANOWAR";
	
	n = n + 1;

	//ID
	Locations[n].id = "NEXT3_MANOWAR";
	Locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\hold";
	Locations[n].image = "loading\Deck_03.tga";
	//Sound
	Locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "hold_l";
	Locations[n].models.always.l1 = "hold";
	//Day
	Locations[n].models.day.charactersPatch = "hold_p";
	Locations[n].models.day.fonar = "hold_fd";
	//Night
	Locations[n].models.night.charactersPatch = "hold_p";
	Locations[n].models.night.fonar = "hold_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "true";
	Locations[n].boarding.nextdeck = "NEXT4_MANOWAR";
	
	n = n + 1;

	//ID
	Locations[n].id = "NEXT4_MANOWAR";
	Locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\cap";
	Locations[n].image = "loading\Cabin.tga";
	//Sound
	Locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "cap_l";
	Locations[n].models.always.l1 = "cap";
	Locations[n].models.always.window = "cap_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 65531;
	//Day
	Locations[n].models.day.charactersPatch = "cap_p";
	Locations[n].models.day.fonar = "cap_fd";
	//Night
	Locations[n].models.night.charactersPatch = "cap_p";
	Locations[n].models.night.fonar = "cap_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "true";
	Locations[n].boarding.nextdeck = "";
	
	n = n + 1;
	// -------------------------------------------------
	/////////////////////////////////////////////////////
	////////////////////////////////FORTS////////////////
	/////////////////////////////////////////////////////
	// -------------------------------------------------
	// -------------------------------Falaise_de_Fleur
	//ID
	Locations[n].id = "Falaise_de_Fleur_fort";
	locations[n].id.label = "Fort inside";
	//Info
	Locations[n].filespath.models = "locations\Fort_inside\Fort_1\";
	Locations[n].image = "loading\Fort_01.tga";
	//Sound
	locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "fort1_l";
	Locations[n].models.always.l1 = "fort1";
	//Day
	Locations[n].models.day.charactersPatch = "fort1_p";
	Locations[n].models.day.fonar = "fort1_fd";
	//Night
	Locations[n].models.night.charactersPatch = "fort1_p";
	Locations[n].models.night.fonar = "fort1_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	Locations[n].boarding = "fort";
	Locations[n].boarding.nextdeck = "NEXT1_Falaise_de_Fleur_fort";
	
	n = n + 1;

	//ID
	Locations[n].id = "NEXT1_Falaise_de_Fleur_fort";
	Locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\Fort_inside\Fort_2\";
	Locations[n].image = "loading\Fort_02.tga";
	//Sound
	Locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "fort2_l";
	Locations[n].models.always.l1 = "fort2";
	//Day
	Locations[n].models.day.charactersPatch = "fort2_p";
	Locations[n].models.day.fonar = "fort2_fd";
	//Night
	Locations[n].models.night.charactersPatch = "fort2_p";
	Locations[n].models.night.fonar = "fort2_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "fort";
	Locations[n].boarding.nextdeck = "NEXT2_Falaise_de_Fleur_fort";
	
	n = n + 1;

	//ID
	Locations[n].id = "NEXT2_Falaise_de_Fleur_fort";
	Locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\Fort_inside\Fort_3\";
	Locations[n].image = "loading\Fort_03.tga";
	//Sound
	Locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "fort3_l";
	Locations[n].models.always.l1 = "fort3";
	//Day
	Locations[n].models.day.charactersPatch = "fort3_p";
	Locations[n].models.day.fonar = "fort3_fd";
	//Night
	Locations[n].models.night.charactersPatch = "fort3_p";
	Locations[n].models.night.fonar = "fort3_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "fort";
	Locations[n].boarding.nextdeck = "";
	
	n = n + 1;
	
	
	// -------------------------------------------------
	// ------------------------------------Redmond_fort
	//ID
	Locations[n].id = "Redmond_fort";
	locations[n].id.label = "Fort inside";
	//Info
	Locations[n].filespath.models = "locations\Fort_inside\Fort_1\";
	Locations[n].image = "loading\Fort_01.tga";
	//Sound
	locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "fort1_l";
	Locations[n].models.always.l1 = "fort1";
	//Day
	Locations[n].models.day.charactersPatch = "fort1_p";
	Locations[n].models.day.fonar = "fort1_fd";
	//Night
	Locations[n].models.night.charactersPatch = "fort1_p";
	Locations[n].models.night.fonar = "fort1_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	Locations[n].boarding = "fort";
	Locations[n].boarding.nextdeck = "NEXT1_Redmond_fort";
	
	n = n + 1;

	//ID
	Locations[n].id = "NEXT1_Redmond_fort";
	Locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\Fort_inside\Fort_2\";
	Locations[n].image = "loading\Fort_02.tga";
	//Sound
	Locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "fort2_l";
	Locations[n].models.always.l1 = "fort2";
	//Day
	Locations[n].models.day.charactersPatch = "fort2_p";
	Locations[n].models.day.fonar = "fort2_fd";
	//Night
	Locations[n].models.night.charactersPatch = "fort2_p";
	Locations[n].models.night.fonar = "fort2_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "fort";
	Locations[n].boarding.nextdeck = "NEXT2_Redmond_fort";
	
	n = n + 1;

	//ID
	Locations[n].id = "NEXT2_Redmond_fort";
	Locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\Fort_inside\Fort_3\";
	Locations[n].image = "loading\Fort_03.tga";
	//Sound
	Locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "fort3_l";
	Locations[n].models.always.l1 = "fort3";
	//Day
	Locations[n].models.day.charactersPatch = "fort3_p";
	Locations[n].models.day.fonar = "fort3_fd";
	//Night
	Locations[n].models.night.charactersPatch = "fort3_p";
	Locations[n].models.night.fonar = "fort3_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "fort";
	Locations[n].boarding.nextdeck = "";
	
	n = n + 1;
	
	
	// -------------------------------------------------
	// --------------------------------------Oxbay_fort1
	//ID
	Locations[n].id = "Oxbay_fort1";
	locations[n].id.label = "Fort inside";
	//Info
	Locations[n].filespath.models = "locations\Fort_inside\Fort_1\";
	Locations[n].image = "loading\Fort_01.tga";
	//Sound
	locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "fort1_l";
	Locations[n].models.always.l1 = "fort1";
	//Day
	Locations[n].models.day.charactersPatch = "fort1_p";
	Locations[n].models.day.fonar = "fort1_fd";
	//Night
	Locations[n].models.night.charactersPatch = "fort1_p";
	Locations[n].models.night.fonar = "fort1_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	Locations[n].boarding = "fort";
	Locations[n].boarding.nextdeck = "NEXT1_Oxbay_fort1";
	
	n = n + 1;

	//ID
	Locations[n].id = "NEXT1_Oxbay_fort1";
	Locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\Fort_inside\Fort_2\";
	Locations[n].image = "loading\Fort_02.tga";
	//Sound
	Locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "fort2_l";
	Locations[n].models.always.l1 = "fort2";
	//Day
	Locations[n].models.day.charactersPatch = "fort2_p";
	Locations[n].models.day.fonar = "fort2_fd";
	//Night
	Locations[n].models.night.charactersPatch = "fort2_p";
	Locations[n].models.night.fonar = "fort2_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "fort";
	Locations[n].boarding.nextdeck = "NEXT2_Oxbay_fort1";
	
	n = n + 1;

	//ID
	Locations[n].id = "NEXT2_Oxbay_fort1";
	Locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\Fort_inside\Fort_3\";
	Locations[n].image = "loading\Fort_03.tga";
	//Sound
	Locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "fort3_l";
	Locations[n].models.always.l1 = "fort3";
	//Day
	Locations[n].models.day.charactersPatch = "fort3_p";
	Locations[n].models.day.fonar = "fort3_fd";
	//Night
	Locations[n].models.night.charactersPatch = "fort3_p";
	Locations[n].models.night.fonar = "fort3_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "fort";
	Locations[n].boarding.nextdeck = "";
	
	n = n + 1;

	
	// -------------------------------------------------
	// --------------------------------------Oxbay_fort2
	//ID
	Locations[n].id = "Oxbay_fort2";
	locations[n].id.label = "Fort inside";
	//Info
	Locations[n].filespath.models = "locations\Fort_inside\Fort_1\";
	Locations[n].image = "loading\Fort_01.tga";
	//Sound
	locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "fort1_l";
	Locations[n].models.always.l1 = "fort1";
	//Day
	Locations[n].models.day.charactersPatch = "fort1_p";
	Locations[n].models.day.fonar = "fort1_fd";
	//Night
	Locations[n].models.night.charactersPatch = "fort1_p";
	Locations[n].models.night.fonar = "fort1_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	Locations[n].boarding = "fort";
	Locations[n].boarding.nextdeck = "NEXT1_Oxbay_fort2";
	
	n = n + 1;

	//ID
	Locations[n].id = "NEXT1_Oxbay_fort2";
	Locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\Fort_inside\Fort_2\";
	Locations[n].image = "loading\Fort_02.tga";
	//Sound
	Locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "fort2_l";
	Locations[n].models.always.l1 = "fort2";
	//Day
	Locations[n].models.day.charactersPatch = "fort2_p";
	Locations[n].models.day.fonar = "fort2_fd";
	//Night
	Locations[n].models.night.charactersPatch = "fort2_p";
	Locations[n].models.night.fonar = "fort2_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "fort";
	Locations[n].boarding.nextdeck = "NEXT2_Oxbay_fort2";
	
	n = n + 1;

	//ID
	Locations[n].id = "NEXT2_Oxbay_fort2";
	Locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\Fort_inside\Fort_3\";
	Locations[n].image = "loading\Fort_03.tga";
	//Sound
	Locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "fort3_l";
	Locations[n].models.always.l1 = "fort3";
	//Day
	Locations[n].models.day.charactersPatch = "fort3_p";
	Locations[n].models.day.fonar = "fort3_fd";
	//Night
	Locations[n].models.night.charactersPatch = "fort3_p";
	Locations[n].models.night.fonar = "fort3_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "fort";
	Locations[n].boarding.nextdeck = "";
	
	n = n + 1;
	
	
	// -------------------------------------------------
	// ---------------------------------------IslaMuelle
	//ID
	Locations[n].id = "IslaMuelle_fort";
	locations[n].id.label = "Fort inside";
	//Info
	Locations[n].filespath.models = "locations\Fort_inside\Fort_1\";
	Locations[n].image = "loading\Fort_01.tga";
	//Sound
	locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "fort1_l";
	Locations[n].models.always.l1 = "fort1";
	//Day
	Locations[n].models.day.charactersPatch = "fort1_p";
	Locations[n].models.day.fonar = "fort1_fd";
	//Night
	Locations[n].models.night.charactersPatch = "fort1_p";
	Locations[n].models.night.fonar = "fort1_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	Locations[n].boarding = "fort";
	Locations[n].boarding.nextdeck = "NEXT1_IslaMuelle_fort";
	
	n = n + 1;

	//ID
	Locations[n].id = "NEXT1_IslaMuelle_fort";
	Locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\Fort_inside\Fort_2\";
	Locations[n].image = "loading\Fort_02.tga";
	//Sound
	Locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "fort2_l";
	Locations[n].models.always.l1 = "fort2";
	//Day
	Locations[n].models.day.charactersPatch = "fort2_p";
	Locations[n].models.day.fonar = "fort2_fd";
	//Night
	Locations[n].models.night.charactersPatch = "fort2_p";
	Locations[n].models.night.fonar = "fort2_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "fort";
	Locations[n].boarding.nextdeck = "NEXT2_IslaMuelle_fort";
	
	n = n + 1;

	//ID
	Locations[n].id = "NEXT2_IslaMuelle_fort";
	Locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\Fort_inside\Fort_3\";
	Locations[n].image = "loading\Fort_03.tga";
	//Sound
	Locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "fort3_l";
	Locations[n].models.always.l1 = "fort3";
	//Day
	Locations[n].models.day.charactersPatch = "fort3_p";
	Locations[n].models.day.fonar = "fort3_fd";
	//Night
	Locations[n].models.night.charactersPatch = "fort3_p";
	Locations[n].models.night.fonar = "fort3_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "fort";
	Locations[n].boarding.nextdeck = "";
	
	n = n + 1;


	// -------------------------------------------------
	// ---------------------------------------Conceicao
	//ID
	Locations[n].id = "Conceicao_fort";
	locations[n].id.label = "Fort inside";
	//Info
	Locations[n].filespath.models = "locations\Fort_inside\Fort_1\";
	Locations[n].image = "loading\Fort_01.tga";
	//Sound
	locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "fort1_l";
	Locations[n].models.always.l1 = "fort1";
	//Day
	Locations[n].models.day.charactersPatch = "fort1_p";
	Locations[n].models.day.fonar = "fort1_fd";
	//Night
	Locations[n].models.night.charactersPatch = "fort1_p";
	Locations[n].models.night.fonar = "fort1_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	Locations[n].boarding = "fort";
	Locations[n].boarding.nextdeck = "NEXT1_Conceicao_fort";
	
	n = n + 1;

	//ID
	Locations[n].id = "NEXT1_Conceicao_fort";
	Locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\Fort_inside\Fort_2\";
	Locations[n].image = "loading\Fort_02.tga";
	//Sound
	Locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "fort2_l";
	Locations[n].models.always.l1 = "fort2";
	//Day
	Locations[n].models.day.charactersPatch = "fort2_p";
	Locations[n].models.day.fonar = "fort2_fd";
	//Night
	Locations[n].models.night.charactersPatch = "fort2_p";
	Locations[n].models.night.fonar = "fort2_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "fort";
	Locations[n].boarding.nextdeck = "NEXT2_Conceicao_fort";
	
	n = n + 1;

	//ID
	Locations[n].id = "NEXT2_Conceicao_fort";
	Locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\Fort_inside\Fort_3\";
	Locations[n].image = "loading\Fort_03.tga";
	//Sound
	Locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "fort3_l";
	Locations[n].models.always.l1 = "fort3";
	//Day
	Locations[n].models.day.charactersPatch = "fort3_p";
	Locations[n].models.day.fonar = "fort3_fd";
	//Night
	Locations[n].models.night.charactersPatch = "fort3_p";
	Locations[n].models.night.fonar = "fort3_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "fort";
	Locations[n].boarding.nextdeck = "";
	
	n = n + 1;


	// -------------------------------------------------
	// ---------------------------------------Douwesen
	//ID
	Locations[n].id = "Douwesen_fort";
	locations[n].id.label = "Fort inside";
	//Info
	Locations[n].filespath.models = "locations\Fort_inside\Fort_1\";
	Locations[n].image = "loading\Fort_01.tga";
	//Sound
	locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "fort1_l";
	Locations[n].models.always.l1 = "fort1";
	//Day
	Locations[n].models.day.charactersPatch = "fort1_p";
	Locations[n].models.day.fonar = "fort1_fd";
	//Night
	Locations[n].models.night.charactersPatch = "fort1_p";
	Locations[n].models.night.fonar = "fort1_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	Locations[n].boarding = "fort";
	Locations[n].boarding.nextdeck = "NEXT1_Douwesen_fort";
	
	n = n + 1;

	//ID
	Locations[n].id = "NEXT1_Douwesen_fort";
	Locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\Fort_inside\Fort_2\";
	Locations[n].image = "loading\Fort_02.tga";
	//Sound
	Locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "fort2_l";
	Locations[n].models.always.l1 = "fort2";
	//Day
	Locations[n].models.day.charactersPatch = "fort2_p";
	Locations[n].models.day.fonar = "fort2_fd";
	//Night
	Locations[n].models.night.charactersPatch = "fort2_p";
	Locations[n].models.night.fonar = "fort2_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "fort";
	Locations[n].boarding.nextdeck = "NEXT2_Douwesen_fort";
	
	n = n + 1;

	//ID
	Locations[n].id = "NEXT2_Douwesen_fort";
	Locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\Fort_inside\Fort_3\";
	Locations[n].image = "loading\Fort_03.tga";
	//Sound
	Locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "fort3_l";
	Locations[n].models.always.l1 = "fort3";
	//Day
	Locations[n].models.day.charactersPatch = "fort3_p";
	Locations[n].models.day.fonar = "fort3_fd";
	//Night
	Locations[n].models.night.charactersPatch = "fort3_p";
	Locations[n].models.night.fonar = "fort3_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "fort";
	Locations[n].boarding.nextdeck = "";
	
	n = n + 1;
	// -------------------------------------------------
	return n;
}

#include "locations\init\FalaiseDeFleur.c"
#include "locations\init\Redmond.c"
#include "locations\init\IslaMuelle.c"
#include "locations\init\Oxbay.c"
#include "locations\init\QuebradasCostillas.c"
#include "locations\init\Douwesen.c"
#include "locations\init\KhaelRoa.c"
#include "locations\init\Conceicao.c"
#include "locations\init\QuestLocations.c"
#include "locations\init\boarding.c"



void InitLocations()
{
	ref loc;
	for(int i = 0; i < MAX_LOCATIONS; i++)
	{
		makeref(loc, Locations[i]);
		DeleteAttribute(loc, "");
		loc.id = "";
		loc.index = i;
		loc.image = "loading\sea.tga";
		loc.music = "enplav.ogg";
		loc.locators_radius.reload = 1.0;
		loc.locators_radius.rld = 1.0;
		loc.locators_radius.camdetector = 1.0;
		loc.locators_radius.camera = 0.3;
		loc.locators_radius.characters = 0.5;
		loc.locators_radius.goto = 0.5;		
		loc.locators_radius.sit = 0.5;		
		loc.locators_radius.item = 0.5;		
		loc.locators_radius.officers = 0.5;
		loc.locators_radius.merchant = 1.0;
		loc.locators_radius.box = 1.0;
		loc.locators_radius.candles = 0.1;
		loc.locators_radius.candles_medium = 0.2;
		loc.locators_radius.chandeliers = 0.5;
		loc.locators_radius.heaters = 1.0;
		loc.locators_radius.torchlightes = 0.3;
		loc.locators_radius.torchlightes_o = 0.3;
		loc.locators_radius.fonar = 0.4;
		loc.locators_radius.outside = 2.0;
		loc.locators_radius.incas_light = 0.8;
		loc.locators_radius.incas_sky = 1.0;
		loc.locators_radius.randitem = 1.5;
		loc.locators_radius.waitress = 1.0;
		loc.locators_radius.tables = 0.5;
		loc.locators_radius.barmen = 1.0;
		loc.locators_radius.lamp = 0.2;
		loc.locators_radius.blueteleport = 0.2;
		loc.locators_radius.redteleport = 0.2;
		loc.locators_radius.greenteleport = 0.2;
		loc.locators_radius.magsteleport = 0.2;
		loc.locators_radius.EncDetector = 8.0;
		loc.locators_radius.teleport = 1.0;
		
		//Day dynamic light
		loc.models.day.lights.candles = "candle";
		loc.models.day.lights.candles_medium = "candelabrum";
		loc.models.day.lights.chandeliers = "chandelier";
		loc.models.day.lights.heaters = "heater";
		loc.models.day.lights.torchlightes = "torchlight";		
		loc.models.day.lights.outside = "outside_day";
		loc.models.day.lights.incas_light = "incas";
		loc.models.day.lights.incas_sky = "incasskyday";
		loc.models.day.lights.lamp = "lamp";
		loc.models.day.lights.blueteleport = "blueteleport";
		loc.models.day.lights.redteleport = "redteleport";
		loc.models.day.lights.greenteleport = "greenteleport";
		loc.models.day.lights.magsteleport = "magsteleport";

		//Night dynamic light
		loc.models.night.lights.candles = "candle";
		loc.models.night.lights.candles_medium = "candelabrum";
		loc.models.night.lights.chandeliers = "chandelier";
		loc.models.night.lights.heaters = "heater";
		loc.models.night.lights.torchlightes = "torchlight";
		loc.models.night.lights.torchlightes_o = "torchlight";
		loc.models.night.lights.fonar = "lamp";
		loc.models.night.lights.outside = "outside_night";		
		loc.models.night.lights.incas_light = "incas";
		loc.models.night.lights.incas_sky = "incasskynight";
		loc.models.night.lights.lamp = "lamp";
		loc.models.night.lights.blueteleport = "blueteleport";
		loc.models.night.lights.redteleport = "redteleport";
		loc.models.night.lights.greenteleport = "greenteleport";
		loc.models.night.lights.magsteleport = "magsteleport";
	}


	ReloadProgressUpdate();

	//Init locations
	int n = 0;
	Locations[0].IslandsList.FalaiseDeFleur.begin = n;
	n = LocationInitFalaiseDeFleur(n);
	Locations[0].IslandsList.FalaiseDeFleur.end = n;
	Locations[0].IslandsList.Redmond.begin = n;
	n = LocationInitRedmond(n);
	Locations[0].IslandsList.Redmond.end = n;
	Locations[0].IslandsList.IslaMuelle.begin = n;
	n = LocationInitIslaMuelle(n);
	Locations[0].IslandsList.IslaMuelle.end = n;
	Locations[0].IslandsList.Oxbay.begin = n;
	n = LocationInitOxbay(n);
	Locations[0].IslandsList.Oxbay.end = n;
	Locations[0].IslandsList.QuebradasCostillas.begin = n;
	ReloadProgressUpdate();
	n = LocationInitQuebradasCostillas(n);
	Locations[0].IslandsList.QuebradasCostillas.end = n;
	Locations[0].IslandsList.Douwesen.begin = n;
	n = LocationInitDouwesen(n);
	Locations[0].IslandsList.Douwesen.end = n;
	Locations[0].IslandsList.Conceicao.begin = n;
	n = LocationInitConceicao(n);
	Locations[0].IslandsList.Conceicao.end = n;
	Locations[0].IslandsList.KhaelRoa.begin = n;
	n = LocationInitKhaelRoa(n);
	Locations[0].IslandsList.KhaelRoa.end = n;
	ReloadProgressUpdate();
	n = LocationInitQuestLocations(n);
	n = LocationInitBoarding(n);
	nLocationsNum = n;
	Trace("Number of locations: " + nLocationsNum);

}




void wdmInitWorldMap()
{
	// Open language file for lables
	int idLngFile = LanguageOpenFile("LocLables.txt");

	//Init world map object
	//Debug info
	worldMap.debug = "false";
	worldMap.evwin = "false";
	worldMap.noenc = "false";
	//=========================================================================
	//Set event handlers
/*	SetEventHandler("WorldMap_EncounterCreate", "wdmEvent_EncounterCreate", 0);
	SetEventHandler("WorldMap_inside_islandzone", "wdmEvent_InsideIsland", 0);
	SetEventHandler("WorldMap_outside_islandzone", "wdmEvent_OutsideIsland", 0);
	SetEventHandler("WorldMap_PlayerInStorm", "wdmEvent_PlayerInStorm", 0);
	SetEventHandler("WorldMap_ShipEncounter", "wdmEvent_ShipEncounter", 0);
	SetEventHandler("WorldMap_EventWindowChangeSelectoin", "wdmEvent_EventWindowChangeSelectoin", 0);
	SetEventHandler("WorldMap_EventWindowSelect", "wdmEvent_EventWindowSelect", 0);	
	SetEventHandler("WorldMap_WaitMenuChangeSelectoin", "wdmEvent_WaitMenuChangeSelectoin", 0);
	SetEventHandler("WorldMap_WaitMenuSelect", "wdmEvent_WaitMenuSelect", 0);
	SetEventHandler("WorldMap_DeleteShipEncounter", "wdmEvent_DeleteShipEncounter", 0);
	SetEventHandler("WorldMap_UpdateDate", "wdmEvent_UpdateDate", 0);
	
	SetEventHandler("ExitFromWorldMap", "wdmReloadToSea", 0);
	*/
	//=========================================================================
	//Storm interface
	worldMap.storm.num = 0;
	worldMap.storm.cur = 0;
	worldMap.storm.x = 0;
	worldMap.storm.z = 0;
	worldMap.storm.time = 0;
	//Encounter interface
	worldMap.encounter.num = 0;
	worldMap.encounter.cur = 0;
	worldMap.encounter.x = 0;
	worldMap.encounter.z = 0;
	worldMap.encounter.ay = 0;
	worldMap.encounter.time = 0;
	worldMap.encounter.type = -1;
	worldMap.encounter.attack = -1;
	//=========================================================================
	worldMap.fontIslands = "DIALOG2";
	worldMap.fontLocations = "normal";
	worldMap.labelPivotX = 0.5;
	worldMap.labelPivotY = 1.5;
	worldMap.heightViewLabel = 250.0;
	worldMap.icon.width = 32;
	worldMap.icon.height = 32;
	worldMap.icon.texture = "icons.tga";
	worldMap.icon.num = 8;
	worldMap.icon.frames = 8;
	worldMap.icon.fps = 10;
	//=========================================================================
	worldMap.eventWindow.font.header = "normal";
	worldMap.eventWindow.font.text = "normal";
	worldMap.eventWindow.font.button = "normal";
	//==========================================================================
	//Start date
	worldMap.date.hour = 10;
	worldMap.date.min = 24;
	worldMap.date.sec = 42;	
	worldMap.date.day = 15;
	worldMap.date.month = 4;
	worldMap.date.year = 1630;
	worldMap.date.hourPerSec = 4.0;
	//Output info
	worldMap.date.font = "normal";
	/*worldMap.date.monthnames.m01 = "января";
	worldMap.date.monthnames.m02 = "февраля";
	worldMap.date.monthnames.m03 = "марта";
	worldMap.date.monthnames.m04 = "апреля";
	worldMap.date.monthnames.m05 = "мая";
	worldMap.date.monthnames.m06 = "июня";
	worldMap.date.monthnames.m07 = "июля";
	worldMap.date.monthnames.m08 = "августа";
	worldMap.date.monthnames.m09 = "сентября";
	worldMap.date.monthnames.m10 = "октября";
	worldMap.date.monthnames.m11 = "ноября";
	worldMap.date.monthnames.m12 = "декабря";*/
	//1=========================================================================
	//Name
	worldMap.islands.FaleDeFler.name = "FalaiseDeFleur";
	//Geometry parameters
	worldMap.islands.FaleDeFler.position.x = -245.0;
	worldMap.islands.FaleDeFler.position.y = 30.0;
	worldMap.islands.FaleDeFler.position.z = 370.0;
	worldMap.islands.FaleDeFler.position.rx = -235.7;
	worldMap.islands.FaleDeFler.position.rz = 381.1;
	worldMap.islands.FaleDeFler.radius = 120.0;
	worldMap.islands.FaleDeFler.kradius = 0.75;
	//Island label
	worldMap.islands.FaleDeFler.label.text = CheckingTranslate(idLngFile,"Falaise De Fleur");
	worldMap.islands.FaleDeFler.label.icon = -1;
	worldMap.islands.FaleDeFler.label.visible = "true";
	//Island locations----------------------------------------------------------
	//City
	//Name
	worldMap.islands.FaleDeFler.locations.city.name = "Falaise De Fleur";
	//Geometry parameters
	worldMap.islands.FaleDeFler.locations.city.move = "false";
	worldMap.islands.FaleDeFler.locations.city.position.x = -225.0;
	worldMap.islands.FaleDeFler.locations.city.position.y = 8.0;
	worldMap.islands.FaleDeFler.locations.city.position.z = 380.0;
	worldMap.islands.FaleDeFler.locations.city.position.ay = 0.0;
	worldMap.islands.FaleDeFler.locations.city.modelName = "town";
	worldMap.islands.FaleDeFler.locations.city.visible = "false";
	worldMap.islands.FaleDeFler.locations.city.move = "false";
	//Label
	worldMap.islands.FaleDeFler.locations.city.label.text = CheckingTranslate(idLngFile,"Falaise De Fleur");
	worldMap.islands.FaleDeFler.locations.city.label.icon = FRANCE;
	worldMap.islands.FaleDeFler.locations.city.label.visible = "false";
	//Name
	worldMap.islands.FaleDeFler.locations.city1.name = "FShore 1";
	//Geometry parameters
	worldMap.islands.FaleDeFler.locations.city1.move = "false";
	worldMap.islands.FaleDeFler.locations.city1.position.x = -210.300018;
	worldMap.islands.FaleDeFler.locations.city1.position.y = 2.905003;
	worldMap.islands.FaleDeFler.locations.city1.position.z = 411.800110;
	worldMap.islands.FaleDeFler.locations.city1.position.ay = 0.0;
	worldMap.islands.FaleDeFler.locations.city1.modelName = "leaf";
	worldMap.islands.FaleDeFler.locations.city1.visible = "false";
	worldMap.islands.FaleDeFler.locations.city1.move = "false";
	//Label
	worldMap.islands.FaleDeFler.locations.city1.label.text = CheckingTranslate(idLngFile,"Octopus Bay");
	worldMap.islands.FaleDeFler.locations.city1.label.icon = -1;
	worldMap.islands.FaleDeFler.locations.city1.label.visible = "false";
	//

	//2=========================================================================
	//Name
	worldMap.islands.Redmond.name = "Redmond";
	//Geometry parameters
	worldMap.islands.Redmond.isVisibleName = 0;
	worldMap.islands.Redmond.position.x = 238.0;
	worldMap.islands.Redmond.position.y = 30.0;
	worldMap.islands.Redmond.position.z = 320.0;
	worldMap.islands.Redmond.position.rx = 250.0;
	worldMap.islands.Redmond.position.rz = 335.5;
	worldMap.islands.Redmond.radius = 150.0;	
	worldMap.islands.Redmond.kradius = 0.75;
	//Island label
	worldMap.islands.Redmond.label.text = CheckingTranslate(idLngFile,"Redmond");
	worldMap.islands.Redmond.label.icon = -1;
	worldMap.islands.Redmond.label.visible = "true";

	//City
	//Name
	worldMap.islands.Redmond.locations.city.name = "Redmond";
	//Geometry parameters
	worldMap.islands.Redmond.locations.city.position.x = 192.605331;
	worldMap.islands.Redmond.locations.city.position.y = 5.0;
	worldMap.islands.Redmond.locations.city.position.z = 312.0;
	worldMap.islands.Redmond.locations.city.position.ay = 0.0;
	worldMap.islands.Redmond.locations.city.modelName = "town";
	worldMap.islands.Redmond.locations.city.visible = "false";
	worldMap.islands.Redmond.locations.city.move = "false";
	//Label
	worldMap.islands.Redmond.locations.city.label.text = CheckingTranslate(idLngFile,"Redmond");
	worldMap.islands.Redmond.locations.city.label.icon = ENGLAND;
	worldMap.islands.Redmond.locations.city.label.visible = "false";
	//Name
	worldMap.islands.Redmond.locations.city1.name = "RShore 1";
	//Geometry parameters
	worldMap.islands.Redmond.locations.city1.position.x = 242.745148;
	worldMap.islands.Redmond.locations.city1.position.y = 2.445001;
	worldMap.islands.Redmond.locations.city1.position.z = 311.701599;
	worldMap.islands.Redmond.locations.city1.position.ay = 0.0;
	worldMap.islands.Redmond.locations.city1.modelName = "leaf";
	worldMap.islands.Redmond.locations.city1.visible = "false";
	worldMap.islands.Redmond.locations.city1.move = "false";
	//Label
	worldMap.islands.Redmond.locations.city1.label.text = CheckingTranslate(idLngFile,"Devil's Throat");
	worldMap.islands.Redmond.locations.city1.label.icon = -1;
	worldMap.islands.Redmond.locations.city1.label.visible = "false";
	//Name
	worldMap.islands.Redmond.locations.city2.name = "RShore 2";
	//Geometry parameters
	worldMap.islands.Redmond.locations.city2.position.x = 219.075180;
	worldMap.islands.Redmond.locations.city2.position.y = 2.445001;
	worldMap.islands.Redmond.locations.city2.position.z = 288.556274;
	worldMap.islands.Redmond.locations.city2.position.ay = 0.0;
	worldMap.islands.Redmond.locations.city2.modelName = "leaf";
	worldMap.islands.Redmond.locations.city2.visible = "false";
	worldMap.islands.Redmond.locations.city2.move = "false";
	//Label
	worldMap.islands.Redmond.locations.city2.label.text = CheckingTranslate(idLngFile,"Rocky Shore");
	worldMap.islands.Redmond.locations.city2.label.icon = -1;
	worldMap.islands.Redmond.locations.city2.label.visible = "false";

	//3=========================================================================
	//Name
	worldMap.islands.Oxbay.name = "Oxbay";
	//Geometry parameters
	worldMap.islands.Oxbay.isVisibleName = 0;
	worldMap.islands.Oxbay.position.x = 225.0;
	worldMap.islands.Oxbay.position.y = 30.0;
	worldMap.islands.Oxbay.position.z = 0.0;
	worldMap.islands.Oxbay.position.rx = 263.9;
	worldMap.islands.Oxbay.position.rz = -6.2;
	worldMap.islands.Oxbay.radius = 130.0;	
	worldMap.islands.Oxbay.kradius = 0.75;
	//Island label
	worldMap.islands.Oxbay.label.text = CheckingTranslate(idLngFile,"Oxbay");
	worldMap.islands.Oxbay.label.icon = -1;
	worldMap.islands.Oxbay.label.visible = "true";

	//City
	//Name
	worldMap.islands.Oxbay.locations.city.name = "Oxbay";
	//Geometry parameters
	worldMap.islands.Oxbay.locations.city.position.x = 191.453;
	worldMap.islands.Oxbay.locations.city.position.y = 5.465;
	worldMap.islands.Oxbay.locations.city.position.z = 31.66;
	worldMap.islands.Oxbay.locations.city.position.ay = 2.5765;
	worldMap.islands.Oxbay.locations.city.modelName = "town";
	worldMap.islands.Oxbay.locations.city.visible = "false";
	worldMap.islands.Oxbay.locations.city.move = "false";
	//Label
	worldMap.islands.Oxbay.locations.city.label.text = CheckingTranslate(idLngFile,"Oxbay");
	worldMap.islands.Oxbay.locations.city.label.icon = ENGLAND;
	worldMap.islands.Oxbay.locations.city.label.visible = "false";
	//Name
	worldMap.islands.Oxbay.locations.city1.name = "OShore 2";
	//Geometry parameters
	worldMap.islands.Oxbay.locations.city1.position.x = 236.359940;
	worldMap.islands.Oxbay.locations.city1.position.y = 5.440002;
	worldMap.islands.Oxbay.locations.city1.position.z = 26.674967;
	worldMap.islands.Oxbay.locations.city1.position.ay = 3.442;
	worldMap.islands.Oxbay.locations.city1.modelName = "leaf";
	worldMap.islands.Oxbay.locations.city1.visible = "false";
	worldMap.islands.Oxbay.locations.city1.move = "false";
	//Label
	worldMap.islands.Oxbay.locations.city1.label.text = CheckingTranslate(idLngFile,"Gray Rock Bay");
	worldMap.islands.Oxbay.locations.city1.label.icon = -1;
	worldMap.islands.Oxbay.locations.city1.label.visible = "false";
	//Name
	worldMap.islands.Oxbay.locations.city4.name = "OShore 1";
	//Geometry parameters
	worldMap.islands.Oxbay.locations.city4.position.x = 186.189865;
	worldMap.islands.Oxbay.locations.city4.position.y = 5.084993;
	worldMap.islands.Oxbay.locations.city4.position.z = -25.415068;
	worldMap.islands.Oxbay.locations.city4.position.ay = 3.442;
	worldMap.islands.Oxbay.locations.city4.modelName = "leaf";
	worldMap.islands.Oxbay.locations.city4.visible = "false";
	worldMap.islands.Oxbay.locations.city4.move = "false";
	//Label
	worldMap.islands.Oxbay.locations.city4.label.text = CheckingTranslate(idLngFile,"Far Beach");
	worldMap.islands.Oxbay.locations.city4.label.icon = -1;
	worldMap.islands.Oxbay.locations.city4.label.visible = "false";
	//Name
	worldMap.islands.Oxbay.locations.city2.name = "Lighthouse";
	//Geometry parameters
	worldMap.islands.Oxbay.locations.city2.position.x = 212.709579;
	worldMap.islands.Oxbay.locations.city2.position.y = 5.440002;
	worldMap.islands.Oxbay.locations.city2.position.z = -31.895061;
	worldMap.islands.Oxbay.locations.city2.position.ay = 3.442;
	worldMap.islands.Oxbay.locations.city2.modelName = "leaf";
	worldMap.islands.Oxbay.locations.city2.visible = "false";
	worldMap.islands.Oxbay.locations.city2.move = "false";
	//Label
	worldMap.islands.Oxbay.locations.city2.label.text = CheckingTranslate(idLngFile,"Lighthouse");
	worldMap.islands.Oxbay.locations.city2.label.icon = -1;
	worldMap.islands.Oxbay.locations.city2.label.visible = "false";
	//Name
	worldMap.islands.Oxbay.locations.city3.name = "Greenford";
	//Geometry parameters
	worldMap.islands.Oxbay.locations.city3.position.x = 273.052856;
	worldMap.islands.Oxbay.locations.city3.position.y = 5.665001;
	worldMap.islands.Oxbay.locations.city3.position.z = -3.840000;
	worldMap.islands.Oxbay.locations.city3.position.ay = 2.5765;
	worldMap.islands.Oxbay.locations.city3.modelName = "town";
	worldMap.islands.Oxbay.locations.city3.visible = "false";
	worldMap.islands.Oxbay.locations.city3.move = "false";
	//Label
	worldMap.islands.Oxbay.locations.city3.label.text = CheckingTranslate(idLngFile,"Greenford");
	worldMap.islands.Oxbay.locations.city3.label.icon = ENGLAND;
	worldMap.islands.Oxbay.locations.city3.label.visible = "false";
	
	//4=========================================================================
	//Name
	worldMap.islands.Douwesen.name = "Douwesen";
	//Geometry parameters
	worldMap.islands.Douwesen.isVisibleName = 0;
	worldMap.islands.Douwesen.position.x = -200.0;
	worldMap.islands.Douwesen.position.y = 30.0;
	worldMap.islands.Douwesen.position.z = -110.0;
	worldMap.islands.Douwesen.position.rx = -169.3;
	worldMap.islands.Douwesen.position.rz = -112.3;
	worldMap.islands.Douwesen.radius = 110.0;	
	worldMap.islands.Douwesen.kradius = 0.75;
	//Island label
	worldMap.islands.Douwesen.label.text = CheckingTranslate(idLngFile,"Douwesen");
	worldMap.islands.Douwesen.label.icon = -1;
	worldMap.islands.Douwesen.label.visible = "true";

	//City
	//Name
	worldMap.islands.Douwesen.locations.city.name = "Douwesen";
	//Geometry parameters
	worldMap.islands.Douwesen.locations.city.position.x = -195.439728;
	worldMap.islands.Douwesen.locations.city.position.y = 6.049987;
	worldMap.islands.Douwesen.locations.city.position.z = -106.659912;
	worldMap.islands.Douwesen.locations.city.position.ay = 0.0;
	worldMap.islands.Douwesen.locations.city.modelName = "town";
	worldMap.islands.Douwesen.locations.city.visible = "false";
	worldMap.islands.Douwesen.locations.city.move = "false";
	//Label
	worldMap.islands.Douwesen.locations.city.label.text = CheckingTranslate(idLngFile,"Douwesen");
	worldMap.islands.Douwesen.locations.city.label.icon = HOLLAND;
	worldMap.islands.Douwesen.locations.city.label.visible = "false";
	//Name
	worldMap.islands.Douwesen.locations.city1.name = "DShore 1";
	//Geometry parameters
	worldMap.islands.Douwesen.locations.city1.position.x = -208.739746;
	worldMap.islands.Douwesen.locations.city1.position.y = 1.839987;
	worldMap.islands.Douwesen.locations.city1.position.z = -86.559875;
	worldMap.islands.Douwesen.locations.city1.position.ay = 0.0;
	worldMap.islands.Douwesen.locations.city1.modelName = "leaf";
	worldMap.islands.Douwesen.locations.city1.visible = "false";
	worldMap.islands.Douwesen.locations.city1.move = "false";
	//Label
	worldMap.islands.Douwesen.locations.city1.label.text = CheckingTranslate(idLngFile,"Palm Beach");
	worldMap.islands.Douwesen.locations.city1.label.icon = -1;
	worldMap.islands.Douwesen.locations.city1.label.visible = "false";
	//Name
	worldMap.islands.Douwesen.locations.city2.name = "DShore 2";
	//Geometry parameters
	worldMap.islands.Douwesen.locations.city2.position.x = -156.239685;
	worldMap.islands.Douwesen.locations.city2.position.y = 6.049987;
	worldMap.islands.Douwesen.locations.city2.position.z = -85.859955;
	worldMap.islands.Douwesen.locations.city2.position.ay = 0.0;
	worldMap.islands.Douwesen.locations.city2.modelName = "leaf";
	worldMap.islands.Douwesen.locations.city2.visible = "false";
	worldMap.islands.Douwesen.locations.city2.move = "false";
	//Label
	worldMap.islands.Douwesen.locations.city2.label.text = CheckingTranslate(idLngFile,"Crab Cliffs");
	worldMap.islands.Douwesen.locations.city2.label.icon = -1;
	worldMap.islands.Douwesen.locations.city2.label.visible = "false";

	//5=========================================================================
	//Name
	worldMap.islands.Conceicao.name = "Conceicao";
	//Geometry parameters
	worldMap.islands.Conceicao.isVisibleName = 0;
	worldMap.islands.Conceicao.position.x = -790.0;
	worldMap.islands.Conceicao.position.y = 30.0;
	worldMap.islands.Conceicao.position.z = 410.0;
	worldMap.islands.Conceicao.position.rx = -714.0;
	worldMap.islands.Conceicao.position.rz = 423.1;
	worldMap.islands.Conceicao.radius = 120.0;	
	worldMap.islands.Conceicao.kradius = 0.75;
	//Island label
	worldMap.islands.Conceicao.label.text = CheckingTranslate(idLngFile,"Conceicao");
	worldMap.islands.Conceicao.label.icon = -1;
	worldMap.islands.Conceicao.label.visible = "true";
	//City
	//Name
	worldMap.islands.Conceicao.locations.city.name = "CShore 1";
	//Geometry parameters
	worldMap.islands.Conceicao.locations.city.position.x = -780.399963;
	worldMap.islands.Conceicao.locations.city.position.y = 8.719997;
	worldMap.islands.Conceicao.locations.city.position.z = 377.0;
	worldMap.islands.Conceicao.locations.city.position.ay = 0.0;
	worldMap.islands.Conceicao.locations.city.modelName = "leaf";
	worldMap.islands.Conceicao.locations.city.visible = "false";
	worldMap.islands.Conceicao.locations.city.move = "false";
	//Label
	worldMap.islands.Conceicao.locations.city.label.text = CheckingTranslate(idLngFile,"Sunny Haven");
	worldMap.islands.Conceicao.locations.city.label.icon = -1;
	worldMap.islands.Conceicao.locations.city.label.visible = "false";
	//Name
	worldMap.islands.Conceicao.locations.city1.name = "Conceicao";
	//Geometry parameters
	worldMap.islands.Conceicao.locations.city1.position.x = -799.734070;
	worldMap.islands.Conceicao.locations.city1.position.y = 6.054986;
	worldMap.islands.Conceicao.locations.city1.position.z = 400.279358;
	worldMap.islands.Conceicao.locations.city1.position.ay = 0.0;
	worldMap.islands.Conceicao.locations.city1.modelName = "town";
	worldMap.islands.Conceicao.locations.city1.visible = "false";
	worldMap.islands.Conceicao.locations.city1.move = "false";
	//Label
	worldMap.islands.Conceicao.locations.city1.label.text = CheckingTranslate(idLngFile,"Conceicao");
	worldMap.islands.Conceicao.locations.city1.label.icon = PORTUGAL;
	worldMap.islands.Conceicao.locations.city1.label.visible = "false";
	//Name
	worldMap.islands.Conceicao.locations.city2.name = "CShore 2";
	//Geometry parameters
	worldMap.islands.Conceicao.locations.city2.position.x = -762.856079;
	worldMap.islands.Conceicao.locations.city2.position.y = 4.875000;
	worldMap.islands.Conceicao.locations.city2.position.z = 432.059357;
	worldMap.islands.Conceicao.locations.city2.position.ay = 0.0;
	worldMap.islands.Conceicao.locations.city2.modelName = "leaf";
	worldMap.islands.Conceicao.locations.city2.visible = "false";
	worldMap.islands.Conceicao.locations.city2.move = "false";
	//Label
	worldMap.islands.Conceicao.locations.city2.label.text = CheckingTranslate(idLngFile,"Leviathan Rock");
	worldMap.islands.Conceicao.locations.city2.label.icon = -1;
	worldMap.islands.Conceicao.locations.city2.label.visible = "false";


	//6=========================================================================
	//Name
	worldMap.islands.IslaMuelle.name = "IslaMuelle";
	//Geometry parameters
	worldMap.islands.IslaMuelle.isVisibleName = 0;
	worldMap.islands.IslaMuelle.position.x = -590.0;
	worldMap.islands.IslaMuelle.position.y = 30.0;
	worldMap.islands.IslaMuelle.position.z = -80.0;
	worldMap.islands.IslaMuelle.position.rx = -669.1;
	worldMap.islands.IslaMuelle.position.rz = -70.5;
	worldMap.islands.IslaMuelle.radius = 185.0;	
	worldMap.islands.IslaMuelle.kradius = 0.75;
	//Island label
	worldMap.islands.IslaMuelle.label.text = CheckingTranslate(idLngFile,"Isla Muelle");
	worldMap.islands.IslaMuelle.label.icon = -1;
	worldMap.islands.IslaMuelle.label.visible = "true";

	//City
	//Name
	worldMap.islands.IslaMuelle.locations.city.name = "Isla Muelle";
	//Geometry parameters
	worldMap.islands.IslaMuelle.locations.city.position.x = -569.571899;
	worldMap.islands.IslaMuelle.locations.city.position.y = 6.859980;
	worldMap.islands.IslaMuelle.locations.city.position.z = -72.555008;
	worldMap.islands.IslaMuelle.locations.city.position.ay = 0.0;
	worldMap.islands.IslaMuelle.locations.city.modelName = "town";
	worldMap.islands.IslaMuelle.locations.city.visible = "false";
	worldMap.islands.IslaMuelle.locations.city.move = "false";
	//Label
	worldMap.islands.IslaMuelle.locations.city.label.text = CheckingTranslate(idLngFile,"Isla Muelle");
	worldMap.islands.IslaMuelle.locations.city.label.icon = SPAIN;
	worldMap.islands.IslaMuelle.locations.city.label.visible = "false";
	//Name
	worldMap.islands.IslaMuelle.locations.city1.name = "MShore 1";
	//Geometry parameters
	worldMap.islands.IslaMuelle.locations.city1.position.x = -564.171875;
	worldMap.islands.IslaMuelle.locations.city1.position.y = 6.544977;
	worldMap.islands.IslaMuelle.locations.city1.position.z = 22.595005;
	worldMap.islands.IslaMuelle.locations.city1.position.ay = 0.0;
	worldMap.islands.IslaMuelle.locations.city1.modelName = "leaf";
	worldMap.islands.IslaMuelle.locations.city1.visible = "false";
	worldMap.islands.IslaMuelle.locations.city1.move = "false";
	//Label
	worldMap.islands.IslaMuelle.locations.city1.label.text = CheckingTranslate(idLngFile,"Oyster Beach");
	worldMap.islands.IslaMuelle.locations.city1.label.icon = -1;
	worldMap.islands.IslaMuelle.locations.city1.label.visible = "false";
	//Name
	worldMap.islands.IslaMuelle.locations.city2.name = "MShore 2";
	//Geometry parameters
	worldMap.islands.IslaMuelle.locations.city2.position.x = -661.272522;
	worldMap.islands.IslaMuelle.locations.city2.position.y = 6.544977;
	worldMap.islands.IslaMuelle.locations.city2.position.z =  -50.804977;
	worldMap.islands.IslaMuelle.locations.city2.position.ay = 0.0;
	worldMap.islands.IslaMuelle.locations.city2.modelName = "leaf";
	worldMap.islands.IslaMuelle.locations.city2.visible = "false";
	worldMap.islands.IslaMuelle.locations.city2.move = "false";
	//Label
	worldMap.islands.IslaMuelle.locations.city2.label.text = CheckingTranslate(idLngFile,"Hidden Coast");
	worldMap.islands.IslaMuelle.locations.city2.label.icon = -1;
	worldMap.islands.IslaMuelle.locations.city2.label.visible = "false";

	//7=========================================================================
	//Name
	worldMap.islands.QuebradasCostillas.name = "QuebradasCostillas";
	//Geometry parameters
	worldMap.islands.QuebradasCostillas.isVisibleName = 0;
	worldMap.islands.QuebradasCostillas.position.x = 260.0;
	worldMap.islands.QuebradasCostillas.position.y = 30.0;
	worldMap.islands.QuebradasCostillas.position.z = -390.0;
	worldMap.islands.QuebradasCostillas.position.rx = 293.7;
	worldMap.islands.QuebradasCostillas.position.rz = -357.7;
	worldMap.islands.QuebradasCostillas.radius = 110.0;	
	worldMap.islands.QuebradasCostillas.kradius = 0.75;
	//Island label
	worldMap.islands.QuebradasCostillas.label.text = CheckingTranslate(idLngFile,"Quebradas Costillas");
	worldMap.islands.QuebradasCostillas.label.icon = -1;
	worldMap.islands.QuebradasCostillas.label.visible = "true";

	//City
	//Name
	worldMap.islands.QuebradasCostillas.locations.city.name = "Quebradas Costillas";
	//Geometry parameters
	worldMap.islands.QuebradasCostillas.locations.city.position.x = 268.385010;
	worldMap.islands.QuebradasCostillas.locations.city.position.y = 9.134986;
	worldMap.islands.QuebradasCostillas.locations.city.position.z = -375.290100;
	worldMap.islands.QuebradasCostillas.locations.city.position.ay = 0.0;
	worldMap.islands.QuebradasCostillas.locations.city.modelName = "town";
	worldMap.islands.QuebradasCostillas.locations.city.visible = "false";
	worldMap.islands.QuebradasCostillas.locations.city.move = "false";
	//Label
	worldMap.islands.QuebradasCostillas.locations.city.label.text = CheckingTranslate(idLngFile,"Pirate Port");
	worldMap.islands.QuebradasCostillas.locations.city.label.icon = PIRATE;
	worldMap.islands.QuebradasCostillas.locations.city.label.visible = "false";

	//8=========================================================================
	//Name
	worldMap.islands.KhaelRoa.name = "KhaelRoa";
	//Geometry parameters
	worldMap.islands.KhaelRoa.isVisibleName = 0;
	worldMap.islands.KhaelRoa.position.x = 790.0;
	worldMap.islands.KhaelRoa.position.y = 30.0;
	worldMap.islands.KhaelRoa.position.z = -520.0;
	worldMap.islands.KhaelRoa.position.rx = 793.7;
	worldMap.islands.KhaelRoa.position.rz = -513.6;
	worldMap.islands.KhaelRoa.radius = 90.0;
	worldMap.islands.KhaelRoa.kradius = 0.75;
	//Island label
	worldMap.islands.KhaelRoa.label.text = CheckingTranslate(idLngFile,"Khael Roa");
	worldMap.islands.KhaelRoa.label.icon = -1;
	worldMap.islands.KhaelRoa.label.visible = "true";

	//City
	//Name
	worldMap.islands.KhaelRoa.locations.city.name = "Khael Roa";
	//Geometry parameters
	worldMap.islands.KhaelRoa.locations.city.position.x = 775.444763;
	worldMap.islands.KhaelRoa.locations.city.position.y = 3.545050;
	worldMap.islands.KhaelRoa.locations.city.position.z = -515.020996;
	worldMap.islands.KhaelRoa.locations.city.position.ay = 0.0;
	worldMap.islands.KhaelRoa.locations.city.modelName = "town";
	worldMap.islands.KhaelRoa.locations.city.visible = "false";
	worldMap.islands.KhaelRoa.locations.city.move = "false";
	//Label
	worldMap.islands.KhaelRoa.locations.city.label.text = CheckingTranslate(idLngFile,"Khael Roa");
	worldMap.islands.KhaelRoa.locations.city.label.icon = -1;
	worldMap.islands.KhaelRoa.locations.city.label.visible = "false";
	//=========================================================================
	//Внутреняя информация - !!!Осторожно, ни каких проверок!!!
	//=========================================================================
	//Player ship
	worldMap.playerShipX = 176.27;
	worldMap.playerShipZ = 35.34;
	worldMap.playerShipAY = 3.0;
	worldMap.playerShipActionRadius = 20.0;
	worldMap.playerShipDispX = stf(worldMap.playerShipX) - stf(worldMap.islands.Oxbay.position.rx);
	worldMap.playerShipDispZ = stf(worldMap.playerShipZ) - stf(worldMap.islands.Oxbay.position.rz);	
	//Camera
	worldMap.wdmCameraAY = 0.0;					//Угол поворота камеры
	worldMap.wdmCameraY = 250.0;				//Высота камеры
	//Enemy ship	
	worldMap.enemyshipViewDistMin = 60.0;		//Растояние на котором корабль начинает исчезать
	worldMap.enemyshipViewDistMax = 120.0;		//Растояние на котором корабль исчезает полностью
	worldMap.enemyshipDistKill = 140.0;			//Расстояние на котором убиваем корабль
	worldMap.enemyshipBrnDistMin = 80.0;		//Минимальное растояние на котором рожается корабль
	worldMap.enemyshipBrnDistMax = 130.0;		//Максимальное растояние на котором рожается корабль
	//storm
	worldMap.stormViewDistMin = 90.0;			//Растояние на котором шторм начинает исчезать
	worldMap.stormViewDistMax = 180.0;			//Растояние на котором шторм исчезает полностью
	worldMap.stormDistKill = 190.0;				//Расстояние на котором убиваем шторм
	worldMap.stormBrnDistMin = 100.0;			//Минимальное растояние на котором рожается шторм
	worldMap.stormBrnDistMax = 140.0;			//Максимальное растояние на котором рожается шторм
	worldMap.stormZone = 150.0;					//Общий радиус действия шторма

	LanguageCloseFile(idLngFile);
}

string CheckingTranslate(int idLngFile, string idString)
{
	string retString = LanguageConvertString ( idLngFile, idString );
	if(retString=="") {
		trace("Warning! No text for lable <" + idString + "> into language file <LocLables.txt>");
	}
	return retString;
}

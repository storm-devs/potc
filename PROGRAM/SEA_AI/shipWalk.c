#include "sea_ai\walk\Barque_walk.c"
#include "sea_ai\walk\Galeon1_walk.c"
#include "sea_ai\walk\Galeon2_walk.c"
#include "sea_ai\walk\Frigate_walk.c"
#include "sea_ai\walk\Frigate2_walk.c"
#include "sea_ai\walk\Frigate_sat_walk.c"
#include "sea_ai\walk\Corvette_walk.c"
#include "sea_ai\walk\Battleship_walk.c"
#include "sea_ai\walk\Caravel_walk.c"
#include "sea_ai\walk\Caravel2_walk.c"
#include "sea_ai\walk\Brig_walk.c"
#include "sea_ai\walk\Fleut1_walk.c"
#include "sea_ai\walk\Fleut2_walk.c"
#include "sea_ai\walk\Lugger_walk.c"
#include "sea_ai\walk\Lugger2_walk.c"
#include "sea_ai\walk\Schooner_walk.c"
#include "sea_ai\walk\Tartane_walk.c"
#include "sea_ai\walk\Xebec1_walk.c"
#include "sea_ai\walk\Xebec2_walk.c"
#include "sea_ai\walk\Yacht1_walk.c"
#include "sea_ai\walk\Yacht2_walk.c"
#include "sea_ai\walk\Pinnace_walk.c"
#include "sea_ai\walk\Manowar1_walk.c"
#include "sea_ai\walk\Manowar2_walk.c"
#include "sea_ai\walk\Manowar_gub_walk.c"
#include "sea_ai\walk\Sloop_walk.c"
#include "sea_ai\walk\Sloop2_walk.c"
#include "sea_ai\walk\Galeoth1_walk.c"
#include "sea_ai\walk\Galeoth2_walk.c"
#include "sea_ai\walk\BLACKPEARL_walk.c"

void Ship_Walk_Init()
{
	Barque_walk_init();
	Galeon1_walk_init();
	Galeon2_walk_init();
	Galeoth1_walk_init();
	Galeoth2_walk_init();
	Frigate_walk_init();
	Frigate2_walk_init();
	Frigate_sat_walk_init();
	Corvette_walk_init();
	Battleship_walk_init();
	Caravel_walk_init();
	Caravel2_walk_init();
	Brig_walk_init();
	Fleut1_walk_init();
	Fleut2_walk_init();
	Lugger_walk_init();
	Lugger2_walk_init();
	Schooner_walk_init();
	Tartane_walk_init();
	Xebec1_walk_init();
	Xebec2_walk_init();
	Yacht1_walk_init();
	Yacht2_walk_init();
	Pinnace_walk_init();
	Manowar1_walk_init();
	Manowar2_walk_init();
	Manowar_gub_walk_init();
	Sloop_walk_init();
	Sloop2_walk_init();
	BLACKPEARL_walk_init();
}

void Ship_Walk_Create()
{
	int charIndex = GetEventData();
	aref ship = GetEventData();
	
	ref ch = GetCharacter(charIndex);
	int shipType = sti(ch.Ship.Type);

	//Trace("Adding ship: " + ShipsTypes[shipType].name);

	switch (ShipsTypes[shipType].name)
	{
	case "GALEOTH1":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship, Galeoth1_walk_count, &Galeoth1_walk_verts, &Galeoth1_walk_graph, &Galeoth1_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "GALEOTH1", Galeoth1_walk_count, &Galeoth1_walk_verts, &Galeoth1_walk_graph, &Galeoth1_walk_types);
		break;
	case "GALEOTH2":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship, Galeoth2_walk_count, &Galeoth2_walk_verts, &Galeoth2_walk_graph, &Galeoth2_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "GALEOTH2", Galeoth2_walk_count, &Galeoth2_walk_verts, &Galeoth2_walk_graph, &Galeoth2_walk_types);
		break;
	case "GALEON1":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship, Galeon1_walk_count, &Galeon1_walk_verts, &Galeon1_walk_graph, &Galeon1_walk_types);
		//SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "GALEON1", Galeon1_walk_count, &Galeon1_walk_verts, &Galeon1_walk_graph, &Galeon1_walk_types);
		break;
	case "GALEON2":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship, Galeon2_walk_count, &Galeon2_walk_verts, &Galeon2_walk_graph, &Galeon2_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "GALEON2", Galeon2_walk_count, &Galeon2_walk_verts, &Galeon2_walk_graph, &Galeon2_walk_types);
		break;
	case "FRIGATE1":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,Frigate_walk_count, &Frigate_walk_verts, &Frigate_walk_graph, &Frigate_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "FRIGATE1", Frigate_walk_count, &Frigate_walk_verts, &Frigate_walk_graph, &Frigate_walk_types);
		break;
	case "FRIGATE2":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,Frigate2_walk_count, &Frigate2_walk_verts, &Frigate2_walk_graph, &Frigate2_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "FRIGATE2", Frigate2_walk_count, &Frigate2_walk_verts, &Frigate2_walk_graph, &Frigate2_walk_types);
		break;
	case "FRIGATE_SAT":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,Frigate_sat_walk_count, &Frigate_sat_walk_verts, &Frigate_sat_walk_graph, &Frigate_sat_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "FRIGATE_sat", Frigate_sat_walk_count, &Frigate_sat_walk_verts, &Frigate_sat_walk_graph, &Frigate_sat_walk_types);
		break;
	case "CORVETTE1":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,Corvette_walk_count, &Corvette_walk_verts, &Corvette_walk_graph, &Corvette_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "CORVETTE1", Corvette_walk_count, &Corvette_walk_verts, &Corvette_walk_graph, &Corvette_walk_types);
        break;
	case "CORVETTE2":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,Corvette_walk_count, &Corvette_walk_verts, &Corvette_walk_graph, &Corvette_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "CORVETTE2", Corvette_walk_count, &Corvette_walk_verts, &Corvette_walk_graph, &Corvette_walk_types);
        break;
	case "BARQUE1":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship, Barque_walk_count, &Barque_walk_verts, &Barque_walk_graph, &Barque_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "BARQUE1", Barque_walk_count, &Barque_walk_verts, &Barque_walk_graph, &Barque_walk_types);
        break;
	case "BARQUE2":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship, Barque_walk_count, &Barque_walk_verts, &Barque_walk_graph, &Barque_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "BARQUE2", Barque_walk_count, &Barque_walk_verts, &Barque_walk_graph, &Barque_walk_types);
        break;
	case "BATTLESHIP1":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,Battleship_walk_count, &Battleship_walk_verts, &Battleship_walk_graph, &Battleship_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "BATTLESHIP1", Battleship_walk_count, &Battleship_walk_verts, &Battleship_walk_graph, &Battleship_walk_types);
        break;
	case "BATTLESHIP2":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,Battleship_walk_count, &Battleship_walk_verts, &Battleship_walk_graph, &Battleship_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "BATTLESHIP2", Battleship_walk_count, &Battleship_walk_verts, &Battleship_walk_graph, &Battleship_walk_types);
        break;
 	case "BRIG1":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,Brig_walk_count, &Brig_walk_verts, &Brig_walk_graph, &Brig_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "BRIG1", Brig_walk_count, &Brig_walk_verts, &Brig_walk_graph, &Brig_walk_types);
        break;
 	case "BRIG2":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,Brig_walk_count, &Brig_walk_verts, &Brig_walk_graph, &Brig_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "BRIG2", Brig_walk_count, &Brig_walk_verts, &Brig_walk_graph, &Brig_walk_types);
        break;
	case "CARAVEL1":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,Caravel_walk_count, &Caravel_walk_verts, &Caravel_walk_graph, &Caravel_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "CARAVEL1", Caravel_walk_count, &Caravel_walk_verts, &Caravel_walk_graph, &Caravel_walk_types);
        break;
	case "CARAVEL2":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,Caravel2_walk_count, &Caravel2_walk_verts, &Caravel2_walk_graph, &Caravel2_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "CARAVEL2", Caravel2_walk_count, &Caravel2_walk_verts, &Caravel2_walk_graph, &Caravel2_walk_types);
        break;
	case "FLEUT1":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship, Fleut1_walk_count, &Fleut1_walk_verts, &Fleut1_walk_graph, &Fleut1_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "FLEUT1", Fleut1_walk_count, &Fleut1_walk_verts, &Fleut1_walk_graph, &Fleut1_walk_types);
        break;
	case "FLEUT2":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship, Fleut2_walk_count, &Fleut2_walk_verts, &Fleut2_walk_graph, &Fleut2_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "FLEUT2", Fleut2_walk_count, &Fleut2_walk_verts, &Fleut2_walk_graph, &Fleut2_walk_types);
        break;
	case "LUGGER1":
	    SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship, Lugger_walk_count, &Lugger_walk_verts, &Lugger_walk_graph, &Lugger_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "LUGGER1", Lugger_walk_count, &Lugger_walk_verts, &Lugger_walk_graph, &Lugger_walk_types);
        break;
	case "LUGGER2":
	    SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship, Lugger2_walk_count, &Lugger2_walk_verts, &Lugger2_walk_graph, &Lugger2_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "LUGGER2", Lugger2_walk_count, &Lugger2_walk_verts, &Lugger2_walk_graph, &Lugger2_walk_types);
        break;
	case "SCHOONER1":
	    SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship, Schooner_walk_count, &Schooner_walk_verts, &Schooner_walk_graph, &Schooner_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "SCHOONER1", Schooner_walk_count, &Schooner_walk_verts, &Schooner_walk_graph, &Schooner_walk_types);
        break;
	case "SCHOONER2":
	    SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship, Schooner_walk_count, &Schooner_walk_verts, &Schooner_walk_graph, &Schooner_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "SCHOONER2", Schooner_walk_count, &Schooner_walk_verts, &Schooner_walk_graph, &Schooner_walk_types);
        break;
	case "TARTANE1":
    	SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship, Tartane_walk_count, &Tartane_walk_verts, &Tartane_walk_graph, &Tartane_walk_types);
        ////SendMessage(WALK_TOOL,"ls", AI_MESSAGE_ADD_SHIP, "TARTANE1", Tartane_walk_count, &Tartane_walk_verts, &Tartane_walk_graph, &Tartane_walk_types);
        break;
	case "TARTANE2":
    	SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship, Tartane_walk_count, &Tartane_walk_verts, &Tartane_walk_graph, &Tartane_walk_types);
        ////SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "TARTANE", Tartane_walk_count, &Tartane_walk_verts, &Tartane_walk_graph, &Tartane_walk_types);
        break;
	case "XEBEC1":
	    SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship, Xebec1_walk_count, &Xebec1_walk_verts, &Xebec1_walk_graph, &Xebec1_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "XEBEC1", Xebec1_walk_count, &Xebec1_walk_verts, &Xebec1_walk_graph, &Xebec1_walk_types);
        break;
	case "XEBEC2":
	    SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship, Xebec2_walk_count, &Xebec2_walk_verts, &Xebec2_walk_graph, &Xebec2_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "XEBEC2", Xebec2_walk_count, &Xebec2_walk_verts, &Xebec2_walk_graph, &Xebec2_walk_types);
        break;
	case "YACHT1": 
    	SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship, Yacht1_walk_count, &Yacht1_walk_verts, &Yacht1_walk_graph, &Yacht1_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "YACHT1", Yacht1_walk_count, &Yacht1_walk_verts, &Yacht1_walk_graph, &Yacht1_walk_types);
	break;
	case "YACHT2": 
    	SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship, Yacht2_walk_count, &Yacht2_walk_verts, &Yacht2_walk_graph, &Yacht2_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "YACHT2", Yacht2_walk_count, &Yacht2_walk_verts, &Yacht2_walk_graph, &Yacht2_walk_types);
	break;
	case "PINNACE1": 
    	SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship, Pinnace_walk_count, &Pinnace_walk_verts, &Pinnace_walk_graph, &Pinnace_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "PINNACE1", Pinnace_walk_count, &Pinnace_walk_verts, &Pinnace_walk_graph, &Pinnace_walk_types);
 	break;                                                              
	case "PINNACE2": 
    	SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship, Pinnace_walk_count, &Pinnace_walk_verts, &Pinnace_walk_graph, &Pinnace_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "PINNACE2", Pinnace_walk_count, &Pinnace_walk_verts, &Pinnace_walk_graph, &Pinnace_walk_types);
 	break;
	case "MANOWAR1": 
        SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship, Manowar1_walk_count, &Manowar1_walk_verts, &Manowar1_walk_graph, &Manowar1_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "MANOWAR1", Manowar1_walk_count, &Manowar1_walk_verts, &Manowar1_walk_graph, &Manowar1_walk_types);
	break;
	case "MANOWAR2": 
        SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship, Manowar2_walk_count, &Manowar2_walk_verts, &Manowar2_walk_graph, &Manowar2_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "MANOWAR2", Manowar2_walk_count, &Manowar2_walk_verts, &Manowar2_walk_graph, &Manowar2_walk_types);
	break;
	case "MANOWAR_GUB": 
        SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship, Manowar_gub_walk_count, &Manowar_gub_walk_verts, &Manowar_gub_walk_graph, &Manowar_gub_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "MANOWAR_gub", Manowar_gub_walk_count, &Manowar_gub_walk_verts, &Manowar_gub_walk_graph, &Manowar_gub_walk_types);
	break;
	case "SLOOP1": 
	    SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship, Sloop_walk_count, &Sloop_walk_verts, &Sloop_walk_graph, &Sloop_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "SLOOP1", Sloop_walk_count, &Sloop_walk_verts, &Sloop_walk_graph, &Sloop_walk_types);
	break;
	case "SLOOP2": 
	    SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship, Sloop2_walk_count, &Sloop2_walk_verts, &Sloop2_walk_graph, &Sloop2_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "SLOOP2", Sloop2_walk_count, &Sloop2_walk_verts, &Sloop2_walk_graph, &Sloop2_walk_types);
	break;
	case "BlackPearl": 
	    SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship, BLACKPEARL_walk_count, &BLACKPEARL_walk_verts, &BLACKPEARL_walk_graph, &BLACKPEARL_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "BLACKPEARL", BLACKPEARL_walk_count, &BLACKPEARL_walk_verts, &BLACKPEARL_walk_graph, &BLACKPEARL_walk_types);
	break;
 	}

}
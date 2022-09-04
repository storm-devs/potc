void InitShips()
{
    ref refShip;

	for (int idx=0;idx<SHIP_TYPES_QUANTITY;idx++)
	{
	    makeref(refShip,ShipsTypes[idx]);

		refship.index = idx;

		refship.InertiaAccelerationX = 0.2;		refship.InertiaBrakingX = 0.7;
		refship.InertiaAccelerationY = 0.4;		refship.InertiaBrakingY = 0.4;
		refship.InertiaAccelerationZ = 1.0;		refship.InertiaBrakingZ = 1.0;

		refship.WaterLine = 0.0;
		refship.SpeedDependWeight = 0.0;
		refship.SubSeaDependWeight = 0.0;
		refship.TurnDependWeight = 0.0;
		refship.TurnDependSpeed = 0.0;

		refShip.Height.Bombs.Y		= 3.0;		refShip.Height.Bombs.DY		= 1.0;
		refShip.Height.Grapes.Y		= 4.0;		refShip.Height.Grapes.DY	= 1.0;
		refShip.Height.Knippels.Y	= 25.0;		refShip.Height.Knippels.DY	= 15.0;
		refShip.Height.Balls.Y		= 3.0;		refShip.Height.Balls.DY		= 1.0;

		refShip.MaxCaliber	= 12;
		refShip.Cannon		= CANNON_TYPE_CANNON_LBS12;

		aref cannonl, cannonr, cannonb, cannonf;

		refship.CanEncounter = true;
		refship.Type.Merchant = true;
		refship.Type.War = true;

		refShip.FireHeight = 3.0;

		makearef(cannonl,ShipsTypes[idx].Cannons.Borts.cannonl);
		makearef(cannonr,ShipsTypes[idx].Cannons.Borts.cannonr);
		makearef(cannonf,ShipsTypes[idx].Cannons.Borts.cannonf);
		makearef(cannonb,ShipsTypes[idx].Cannons.Borts.cannonb);

		cannonf.FireZone	= Degree2Radian(30.0);
		cannonf.FireDir		= Degree2Radian(0.0);
		cannonf.FireAngMin	= -0.35;
		cannonf.FireAngMax	= 0.60;

		cannonr.FireZone	= Degree2Radian(80.0);
		cannonr.FireDir		= Degree2Radian(90.0);
		cannonr.FireAngMin	= -0.35;
		cannonr.FireAngMax	= 0.60;

		cannonb.FireZone	= Degree2Radian(30.0);
		cannonb.FireDir		= Degree2Radian(180.0);
		cannonb.FireAngMin	= -0.35;
		cannonb.FireAngMax	= 0.60;

		cannonl.FireZone	= Degree2Radian(80.0);
		cannonl.FireDir		= Degree2Radian(270.0);
		cannonl.FireAngMin	= -0.35;
		cannonl.FireAngMax	= 0.60;
	}

//-------------------------------------------------------------------------
// Boat
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_BOAT]);
    refShip.Name            = "Boat";
    refShip.Class           = 7;
    refShip.Cannon          = CANNON_TYPE_NONECANNON;
    refShip.MaxCaliber      = 0;
    refShip.Weight			= Tonnes2CWT(10);
    refShip.Capacity        = 50;
    refShip.CannonsQuantity = 0;
    refShip.MaxCrew         = 10;
    refShip.MinCrew         = 2;
    refShip.SpeedRate		= 4;
    refShip.TurnRate        = 40;
    refShip.Price           = 1000;
    refShip.HP              = 100;
    refShip.SP              = 100;


	refship.InertiaAccelerationX	= 5.0;	refship.InertiaBrakingX		= 3.0;
	refship.InertiaAccelerationY	= 0.4;	refship.InertiaBrakingY		= 0.2;
	refship.InertiaAccelerationZ	= 0.15;	refship.InertiaBrakingZ		= 0.05;

//-------------------------------------------------------------------------
// Tartane
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_TARTANE]);
    refShip.Name            = "Tartane1";
    refShip.Class			= 7;
    refShip.Cannon          = CANNON_TYPE_NONECANNON;
    refShip.MaxCaliber      = 0;
	refShip.Weight			= Tonnes2CWT(10);
    refShip.Capacity        = 50;
    refShip.CannonsQuantity = 0;
    refShip.MaxCrew         = 12;
    refShip.MinCrew         = 3;
    refShip.SpeedRate		= 7.0;
    refShip.TurnRate        = 50;
    refShip.Price			= 5000;
    refShip.HP              = 100;
    refShip.SP              = 100;

	refship.InertiaAccelerationX	= 3.0;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 14;	refship.InertiaBrakingY		= 5;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 3.0;

	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y			= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY		= 0.5;

//-------------------------------------------------------------------------
// Yacht FRANCE
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_YACHT_FRANCE]);
    refShip.Name            = "Yacht1";
	refShip.Nation			= FRANCE;
    refShip.Class           = 6;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 12;
	refShip.Weight			= Tonnes2CWT(200);
    refShip.Capacity        = 800;
    refShip.CannonsQuantity = 16;
    refShip.MaxCrew         = 60;
    refShip.MinCrew         = 12;
    refShip.SpeedRate		= 9.0;
    refShip.TurnRate        = 30;
    refShip.Price           = 19000;
    refShip.HP              = 700;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_BARQUE";

	refship.WaterLine = 0.03;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.3;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 2.0;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY		= 4.0;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 2.0;


	refShip.Height.Bombs.Y		= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY		= 1.0;



//-------------------------------------------------------------------------
// Yacht SPAIN
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_YACHT_SPAIN]);
    refShip.Name            = "Yacht1";
	refShip.Nation			= SPAIN;
    refShip.Class           = 6;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 12;
	refShip.Weight			= Tonnes2CWT(200);
    refShip.Capacity        = 840;
    refShip.CannonsQuantity = 16;
    refShip.MaxCrew         = 63;
    refShip.MinCrew         = 12;
    refShip.SpeedRate		= 8.55;
    refShip.TurnRate        = 28.5;
    refShip.Price           = 19000;
    refShip.HP              = 735;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_BARQUE";

	refship.WaterLine = 0.03;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.3;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 2.0;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY		= 4.0;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 2.0;

	refShip.Height.Bombs.Y		= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY		= 1.0;

//-------------------------------------------------------------------------
// Yacht ENGLAND
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_YACHT_ENGLAND]);
    refShip.Name            = "Yacht1";
	refShip.Nation			= ENGLAND;
    refShip.Class           = 6;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 12;
	refShip.Weight			= Tonnes2CWT(200);
    refShip.Capacity        = 720;
    refShip.CannonsQuantity = 16;
    refShip.MaxCrew         = 57;
    refShip.MinCrew         = 13;
    refShip.SpeedRate		= 9.45;
    refShip.TurnRate        = 31.5;
    refShip.Price           = 19000;
    refShip.HP              = 700;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_BARQUE";

	refship.WaterLine = 0.03;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.3;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 2.0;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY		= 4.0;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 2.0;

	refShip.Height.Bombs.Y		= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY		= 1.0;

//-------------------------------------------------------------------------
// Yacht HOLLAND
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_YACHT_HOLLAND]);
    refShip.Name            = "Yacht1";
	refShip.Nation			= HOLLAND;
    refShip.Class           = 6;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 12;
	refShip.Weight			= Tonnes2CWT(190);
    refShip.Capacity        = 800;
    refShip.CannonsQuantity = 16;
    refShip.MaxCrew         = 57;
    refShip.MinCrew         = 12;
    refShip.SpeedRate		= 9.45;
    refShip.TurnRate        = 30;
    refShip.Price           = 19000;
    refShip.HP              = 665;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_BARQUE";

	refship.WaterLine = 0.03;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.3;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 2.0;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY		= 4.0;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 2.0;

	refShip.Height.Bombs.Y		= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY		= 1.0;

//-------------------------------------------------------------------------
// Yacht PORTUGAL
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_YACHT_PORTUGAL]);
    refShip.Name            = "Yacht1";
	refShip.Nation			= PORTUGAL;
    refShip.Class           = 6;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 12;
	refShip.Weight			= Tonnes2CWT(210);
    refShip.Capacity        = 800;
    refShip.CannonsQuantity = 16;
    refShip.MaxCrew         = 63;
    refShip.MinCrew         = 12;
    refShip.SpeedRate		= 9.0;
    refShip.TurnRate        = 31.5;
    refShip.Price           = 19000;
    refShip.HP              = 665;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_BARQUE";

	refship.WaterLine = 0.03;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.3;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 2.0;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY		= 4.0;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 2.0;

	refShip.Height.Bombs.Y		= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY		= 1.0;

//-------------------------------------------------------------------------
// Yacht FRANCE
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_YACHT2_FRANCE]);
    refShip.Name            = "Yacht2";
	refShip.Nation			= FRANCE;
    refShip.Class           = 6;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 12;
	refShip.Weight			= Tonnes2CWT(200);
    refShip.Capacity        = 800;
    refShip.CannonsQuantity = 16;
    refShip.MaxCrew         = 60;
    refShip.MinCrew         = 12;
    refShip.SpeedRate		= 9.0;
    refShip.TurnRate        = 30;
    refShip.Price           = 19000;
    refShip.HP              = 700;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_BARQUE";

	refship.WaterLine = -0.1;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.3;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 2.0;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY		= 4.0;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 2.0;

	refShip.Height.Bombs.Y		= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY		= 1.0;

//-------------------------------------------------------------------------
// Yacht SPAIN
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_YACHT2_SPAIN]);
    refShip.Name            = "Yacht2";
	refShip.Nation			= SPAIN;
    refShip.Class           = 6;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 12;
	refShip.Weight			= Tonnes2CWT(200);
    refShip.Capacity        = 840;
    refShip.CannonsQuantity = 16;
    refShip.MaxCrew         = 63;
    refShip.MinCrew         = 12;
    refShip.SpeedRate		= 8.55;
    refShip.TurnRate        = 28.5;
    refShip.Price           = 19000;
    refShip.HP              = 735;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_BARQUE";

	refship.WaterLine = -0.1;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.3;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 2.0;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY		= 4.0;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 2.0;

	refShip.Height.Bombs.Y		= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY		= 1.0;

//-------------------------------------------------------------------------
// Yacht ENGLAND
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_YACHT2_ENGLAND]);
    refShip.Name            = "Yacht2";
	refShip.Nation			= ENGLAND;
    refShip.Class           = 6;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 12;
	refShip.Weight			= Tonnes2CWT(200);
    refShip.Capacity        = 720;
    refShip.CannonsQuantity = 16;
    refShip.MaxCrew         = 57;
    refShip.MinCrew         = 13;
    refShip.SpeedRate		= 9.45;
    refShip.TurnRate        = 31.5;
    refShip.Price           = 19000;
    refShip.HP              = 700;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_BARQUE";

	refship.WaterLine = -0.1;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.3;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 2.0;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY		= 4.0;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 2.0;

	refShip.Height.Bombs.Y		= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY		= 1.0;

//-------------------------------------------------------------------------
// Yacht HOLLAND
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_YACHT2_HOLLAND]);
    refShip.Name            = "Yacht2";
	refShip.Nation			= HOLLAND;
    refShip.Class           = 6;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 12;
	refShip.Weight			= Tonnes2CWT(190);
    refShip.Capacity        = 800;
    refShip.CannonsQuantity = 16;
    refShip.MaxCrew         = 57;
    refShip.MinCrew         = 12;
    refShip.SpeedRate		= 9.45;
    refShip.TurnRate        = 30;
    refShip.Price           = 19000;
    refShip.HP              = 665;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_BARQUE";

	refship.WaterLine = -0.1;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.3;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 2.0;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY		= 4.0;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 2.0;

	refShip.Height.Bombs.Y		= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY		= 1.0;

//-------------------------------------------------------------------------
// Yacht PORTUGAL
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_YACHT2_PORTUGAL]);
    refShip.Name            = "Yacht2";
	refShip.Nation			= PORTUGAL;
    refShip.Class           = 6;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 12;
	refShip.Weight			= Tonnes2CWT(210);
    refShip.Capacity        = 800;
    refShip.CannonsQuantity = 16;
    refShip.MaxCrew         = 63;
    refShip.MinCrew         = 12;
    refShip.SpeedRate		= 9.0;
    refShip.TurnRate        = 31.5;
    refShip.Price           = 19000;
    refShip.HP              = 665;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_BARQUE";

	refship.WaterLine = -0.1;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.3;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 2.0;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY		= 4.0;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 2.0;

	refShip.Height.Bombs.Y		= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY		= 1.0;

//-------------------------------------------------------------------------
// Barque FRANCE
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_BARQUE_FRANCE]);
    refShip.Name            = "Barque1";
	refShip.Nation			= FRANCE;
    refShip.Class           = 6;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 12;
	refShip.Weight			= Tonnes2CWT(350);
    refShip.Capacity        = 1200;
    refShip.CannonsQuantity = 16;
    refShip.MaxCrew         = 80;
    refShip.MinCrew         = 16;
    refShip.SpeedRate		= 7;
    refShip.TurnRate        = 25;
    refShip.Price           = 18000;
    refShip.HP              = 800;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_BARQUE";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.3;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 1.0;	refship.InertiaBrakingX		= 1.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 4.0;
	refship.InertiaAccelerationZ	= 2.0;	refship.InertiaBrakingZ		= 2.0;


//-------------------------------------------------------------------------
// Barque SPAIN
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_BARQUE_SPAIN]);
    refShip.Name            = "Barque1";
	refShip.Nation			= SPAIN;
    refShip.Class           = 6;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 12;
	refShip.Weight			= Tonnes2CWT(350);
    refShip.Capacity        = 1260;
    refShip.CannonsQuantity = 16;
    refShip.MaxCrew         = 84;
    refShip.MinCrew         = 16;
    refShip.SpeedRate		= 6.65;
    refShip.TurnRate        = 23.75;
    refShip.Price           = 18000;
    refShip.HP              = 840;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_BARQUE";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.3;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 1.0;	refship.InertiaBrakingX		= 1.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 4.0;
	refship.InertiaAccelerationZ	= 2.0;	refship.InertiaBrakingZ		= 2.0;

//-------------------------------------------------------------------------
// Barque ENGLAND
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_BARQUE_ENGLAND]);
    refShip.Name            = "Barque1";
	refShip.Nation			= ENGLAND;
    refShip.Class           = 6;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 12;
	refShip.Weight			= Tonnes2CWT(350);
    refShip.Capacity        = 1080;
    refShip.CannonsQuantity = 16;
    refShip.MaxCrew         = 76;
    refShip.MinCrew         = 17;
    refShip.SpeedRate		= 7.35;
    refShip.TurnRate        = 26.25;
    refShip.Price           = 18000;
    refShip.HP              = 800;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_BARQUE";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.3;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 1.0;	refship.InertiaBrakingX		= 1.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 4.0;
	refship.InertiaAccelerationZ	= 2.0;	refship.InertiaBrakingZ		= 2.0;

//-------------------------------------------------------------------------
// Barque HOLLAND
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_BARQUE_HOLLAND]);
    refShip.Name            = "Barque1";
	refShip.Nation			= HOLLAND;
    refShip.Class           = 6;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 12;
	refShip.Weight			= Tonnes2CWT(332);
    refShip.Capacity        = 1200;
    refShip.CannonsQuantity = 16;
    refShip.MaxCrew         = 76;
    refShip.MinCrew         = 16;
    refShip.SpeedRate		= 7.35;
    refShip.TurnRate        = 25;
    refShip.Price           = 18000;
    refShip.HP              = 760;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_BARQUE";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.3;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 1.0;	refship.InertiaBrakingX		= 1.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 4.0;
	refship.InertiaAccelerationZ	= 2.0;	refship.InertiaBrakingZ		= 2.0;

//-------------------------------------------------------------------------
// Barque PORTUGAL
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_BARQUE_PORTUGAL]);
    refShip.Name            = "Barque1";
	refShip.Nation			= PORTUGAL;
    refShip.Class           = 6;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 12;
	refShip.Weight			= Tonnes2CWT(367);
    refShip.Capacity        = 1200;
    refShip.CannonsQuantity = 16;
    refShip.MaxCrew         = 84;
    refShip.MinCrew         = 16;
    refShip.SpeedRate		= 7;
    refShip.TurnRate        = 26.25;
    refShip.Price           = 18000;
    refShip.HP              = 760;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_BARQUE";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.3;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 1.0;	refship.InertiaBrakingX		= 1.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 4.0;
	refship.InertiaAccelerationZ	= 2.0;	refship.InertiaBrakingZ		= 2.0;

//-------------------------------------------------------------------------
// Barque FRANCE
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_BARQUE2_FRANCE]);
    refShip.Name            = "Barque2";
	refShip.Nation			= FRANCE;
    refShip.Class           = 6;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 12;
	refShip.Weight			= Tonnes2CWT(350);
    refShip.Capacity        = 1200;
    refShip.CannonsQuantity = 16;
    refShip.MaxCrew         = 80;
    refShip.MinCrew         = 16;
    refShip.SpeedRate		= 7;
    refShip.TurnRate        = 25;
    refShip.Price           = 18000;
    refShip.HP              = 800;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_BARQUE";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.3;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 1.0;	refship.InertiaBrakingX		= 1.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 4.0;
	refship.InertiaAccelerationZ	= 2.0;	refship.InertiaBrakingZ		= 2.0;

//-------------------------------------------------------------------------
// Barque SPAIN
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_BARQUE2_SPAIN]);
    refShip.Name            = "Barque2";
	refShip.Nation			= SPAIN;
    refShip.Class           = 6;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 12;
	refShip.Weight			= Tonnes2CWT(350);
    refShip.Capacity        = 1260;
    refShip.CannonsQuantity = 16;
    refShip.MaxCrew         = 84;
    refShip.MinCrew         = 16;
    refShip.SpeedRate		= 6.65;
    refShip.TurnRate        = 23.75;
    refShip.Price           = 18000;
    refShip.HP              = 840;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_BARQUE";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.3;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 1.0;	refship.InertiaBrakingX		= 1.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 4.0;
	refship.InertiaAccelerationZ	= 2.0;	refship.InertiaBrakingZ		= 2.0;

//-------------------------------------------------------------------------
// Barque ENGLAND
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_BARQUE2_ENGLAND]);
    refShip.Name            = "Barque2";
	refShip.Nation			= ENGLAND;
    refShip.Class           = 6;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 12;
	refShip.Weight			= Tonnes2CWT(350);
    refShip.Capacity        = 1080;
    refShip.CannonsQuantity = 16;
    refShip.MaxCrew         = 76;
    refShip.MinCrew         = 17;
    refShip.SpeedRate		= 7.35;
    refShip.TurnRate        = 26.25;
    refShip.Price           = 18000;
    refShip.HP              = 800;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_BARQUE";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.3;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 1.0;	refship.InertiaBrakingX		= 1.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 4.0;
	refship.InertiaAccelerationZ	= 2.0;	refship.InertiaBrakingZ		= 2.0;

//-------------------------------------------------------------------------
// Barque HOLLAND
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_BARQUE2_HOLLAND]);
    refShip.Name            = "Barque2";
	refShip.Nation			= HOLLAND;
    refShip.Class           = 6;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 12;
	refShip.Weight			= Tonnes2CWT(332);
    refShip.Capacity        = 1200;
    refShip.CannonsQuantity = 16;
    refShip.MaxCrew         = 76;
    refShip.MinCrew         = 16;
    refShip.SpeedRate		= 7.35;
    refShip.TurnRate        = 25;
    refShip.Price           = 18000;
    refShip.HP              = 760;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_BARQUE";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.3;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 1.0;	refship.InertiaBrakingX		= 1.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 4.0;
	refship.InertiaAccelerationZ	= 2.0;	refship.InertiaBrakingZ		= 2.0;

//-------------------------------------------------------------------------
// Barque PORTUGAL
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_BARQUE2_PORTUGAL]);
    refShip.Name            = "Barque2";
	refShip.Nation			= PORTUGAL;
    refShip.Class           = 6;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 12;
	refShip.Weight			= Tonnes2CWT(367);
    refShip.Capacity        = 1200;
    refShip.CannonsQuantity = 16;
    refShip.MaxCrew         = 84;
    refShip.MinCrew         = 16;
    refShip.SpeedRate		= 7;
    refShip.TurnRate        = 26.25;
    refShip.Price           = 18000;
    refShip.HP              = 760;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_BARQUE";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.3;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 1.0;	refship.InertiaBrakingX		= 1.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 4.0;
	refship.InertiaAccelerationZ	= 2.0;	refship.InertiaBrakingZ		= 2.0;

//-------------------------------------------------------------------------
// Lugger FRANCE
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_LUGGER_FRANCE]);
    refShip.Name            = "Lugger1";
	refShip.Nation			= FRANCE;
    refShip.Class           = 6;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 12;
	refShip.Weight			= Tonnes2CWT(120);
    refShip.Capacity        = 500;
    refShip.CannonsQuantity = 12;
    refShip.MaxCrew         = 50;
    refShip.MinCrew         = 10;
    refShip.SpeedRate       = 16;
    refShip.TurnRate        = 60;
    refShip.Price           = 20000;
    refShip.HP              = 500;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_BARQUE";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 1.0;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 2.0;

	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y			= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY		= 0.5;

//-------------------------------------------------------------------------
// Lugger SPAIN
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_LUGGER_SPAIN]);
    refShip.Name            = "Lugger1";
	refShip.Nation			= SPAIN;
    refShip.Class           = 6;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 12;
	refShip.Weight			= Tonnes2CWT(120);
    refShip.Capacity        = 525;
    refShip.CannonsQuantity = 12;
    refShip.MaxCrew         = 52;
    refShip.MinCrew         = 10;
    refShip.SpeedRate       = 15.2;
    refShip.TurnRate        = 60;
    refShip.Price           = 20000;
    refShip.HP              = 525;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_BARQUE";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.3;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 2.0;

	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y			= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY		= 0.5;

//-------------------------------------------------------------------------
// Lugger ENGLAND
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_LUGGER_ENGLAND]);
    refShip.Name            = "Lugger1";
	refShip.Nation			= ENGLAND;
    refShip.Class           = 6;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 12;
	refShip.Weight			= Tonnes2CWT(120);
    refShip.Capacity        = 450;
    refShip.CannonsQuantity = 12;
    refShip.MaxCrew         = 57;
    refShip.MinCrew         = 11;
    refShip.SpeedRate       = 16.8;
    refShip.TurnRate        = 60;
    refShip.Price           = 20000;
    refShip.HP              = 500;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_BARQUE";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.3;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 2.0;

	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y			= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY		= 0.5;

//-------------------------------------------------------------------------
// Lugger HOLLAND
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_LUGGER_HOLLAND]);
    refShip.Name            = "Lugger1";
	refShip.Nation			= HOLLAND;
    refShip.Class           = 6;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 12;
	refShip.Weight			= Tonnes2CWT(114);
    refShip.Capacity        = 500;
    refShip.CannonsQuantity = 12;
    refShip.MaxCrew         = 47;
    refShip.MinCrew         = 10;
    refShip.SpeedRate       = 16.8;
     refShip.TurnRate        = 60;
    refShip.Price           = 20000;
    refShip.HP              = 475;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_BARQUE";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.3;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 2.0;

	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y			= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY		= 0.5;

//-------------------------------------------------------------------------
// Lugger PORTUGAL
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_LUGGER_PORTUGAL]);
    refShip.Name            = "Lugger1";
	refShip.Nation			= PORTUGAL;
    refShip.Class           = 6;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 12;
	refShip.Weight			= Tonnes2CWT(126);
    refShip.Capacity        = 500;
    refShip.CannonsQuantity = 12;
    refShip.MaxCrew         = 53;
    refShip.MinCrew         = 10;
    refShip.SpeedRate       = 16;
     refShip.TurnRate        = 60;
    refShip.Price           = 20000;
    refShip.HP              = 475;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_BARQUE";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.3;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 2.0;

	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y			= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY		= 0.5;

//-------------------------------------------------------------------------
// Lugger FRANCE
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_LUGGER2_FRANCE]);
    refShip.Name            = "Lugger2";
	refShip.Nation			= FRANCE;
    refShip.Class           = 6;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 12;
	refShip.Weight			= Tonnes2CWT(120);
    refShip.Capacity        = 500;
    refShip.CannonsQuantity = 12;
    refShip.MaxCrew         = 50;
    refShip.MinCrew         = 10;
    refShip.SpeedRate       = 16;
    refShip.TurnRate        = 60;
    refShip.Price           = 20000;
    refShip.HP              = 500;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_BARQUE";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.3;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 2.0;

	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y			= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY		= 0.5;

//-------------------------------------------------------------------------
// Lugger SPAIN
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_LUGGER2_SPAIN]);
    refShip.Name            = "Lugger2";
	refShip.Nation			= SPAIN;
    refShip.Class           = 6;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 12;
	refShip.Weight			= Tonnes2CWT(120);
    refShip.Capacity        = 525;
    refShip.CannonsQuantity = 12;
    refShip.MaxCrew         = 52;
    refShip.MinCrew         = 10;
    refShip.SpeedRate       = 15.2;
     refShip.TurnRate        = 60;
    refShip.Price           = 20000;
    refShip.HP              = 525;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_BARQUE";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.3;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 2.0;

	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y			= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY		= 0.5;

//-------------------------------------------------------------------------
// Lugger ENGLAND
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_LUGGER2_ENGLAND]);
    refShip.Name            = "Lugger2";
	refShip.Nation			= ENGLAND;
    refShip.Class           = 6;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 12;
	refShip.Weight			= Tonnes2CWT(120);
    refShip.Capacity        = 450;
    refShip.CannonsQuantity = 12;
    refShip.MaxCrew         = 57;
    refShip.MinCrew         = 11;
    refShip.SpeedRate       = 16.8;
     refShip.TurnRate        = 60;
    refShip.Price           = 20000;
    refShip.HP              = 500;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_BARQUE";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.3;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 2.0;

	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y			= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY		= 0.5;

//-------------------------------------------------------------------------
// Lugger HOLLAND
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_LUGGER2_HOLLAND]);
    refShip.Name            = "Lugger2";
	refShip.Nation			= HOLLAND;
    refShip.Class           = 6;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 12;
	refShip.Weight			= Tonnes2CWT(114);
    refShip.Capacity        = 500;
    refShip.CannonsQuantity = 12;
    refShip.MaxCrew         = 47;
    refShip.MinCrew         = 10;
    refShip.SpeedRate       = 16.8;
     refShip.TurnRate        = 60;
    refShip.Price           = 20000;
    refShip.HP              = 475;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_BARQUE";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.3;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 2.0;

	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y			= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY		= 0.5;

//-------------------------------------------------------------------------
// Lugger PORTUGAL
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_LUGGER2_PORTUGAL]);
    refShip.Name            = "Lugger2";
	refShip.Nation			= PORTUGAL;
    refShip.Class           = 6;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 12;
	refShip.Weight			= Tonnes2CWT(126);
    refShip.Capacity        = 500;
    refShip.CannonsQuantity = 12;
    refShip.MaxCrew         = 53;
    refShip.MinCrew         = 10;
    refShip.SpeedRate       = 16;
    refShip.TurnRate        = 60;
    refShip.Price           = 20000;
    refShip.HP              = 475;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_BARQUE";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.3;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 2.0;

	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y			= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY		= 0.5;

//-------------------------------------------------------------------------
// Galeoth FRANCE
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_GALEOTH_FRANCE]);
    refShip.Name            = "Galeoth1";
	refShip.Nation			= FRANCE;
    refShip.Class           = 5;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 12;
    refShip.Weight			= Tonnes2CWT(150);
    refShip.Capacity        = 700;
    refShip.CannonsQuantity = 16;
    refShip.MaxCrew         = 90;
    refShip.MinCrew         = 18;
    refShip.SpeedRate		= 13;
    refShip.TurnRate        = 35;
    refShip.Price           = 27000;
    refShip.HP              = 1000;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_SLOOP";

	refship.WaterLine = -0.5;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 1.0;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 9;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 3.0;

//-------------------------------------------------------------------------
// Galeoth SPAIN
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_GALEOTH_SPAIN]);
    refShip.Name            = "Galeoth1";
	refShip.Nation			= SPAIN;
    refShip.Class           = 5;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 12;
    refShip.Weight			= Tonnes2CWT(150);
    refShip.Capacity        = 735;
    refShip.CannonsQuantity = 16;
    refShip.MaxCrew         = 95;
    refShip.MinCrew         = 18;
    refShip.SpeedRate		= 12.35;
    refShip.TurnRate        = 33.25;
    refShip.Price           = 27000;
    refShip.HP              = 1050;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_SLOOP";

	refship.WaterLine = -0.5;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 1.0;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 9;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 3.0;

//-------------------------------------------------------------------------
// Galeoth ENGLAND
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_GALEOTH_ENGLAND]);
    refShip.Name            = "Galeoth1";
	refShip.Nation			= ENGLAND;
    refShip.Class           = 5;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 12;
    refShip.Weight			= Tonnes2CWT(150);
    refShip.Capacity        = 630;
    refShip.CannonsQuantity = 16;
    refShip.MaxCrew         = 85;
    refShip.MinCrew         = 19;
    refShip.SpeedRate		= 13.65;
    refShip.TurnRate        = 36.75;
    refShip.Price           = 27000;
    refShip.HP              = 1000;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_SLOOP";

	refship.WaterLine = -0.5;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 1.0;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 9;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 3.0;

//-------------------------------------------------------------------------
// Galeoth HOLLAND
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_GALEOTH_HOLLAND]);
    refShip.Name            = "Galeoth1";
	refShip.Nation			= HOLLAND;
    refShip.Class           = 5;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 12;
    refShip.Weight			= Tonnes2CWT(142);
    refShip.Capacity        = 700;
    refShip.CannonsQuantity = 16;
    refShip.MaxCrew         = 85;
    refShip.MinCrew         = 18.65;
    refShip.SpeedRate		= 13;
    refShip.TurnRate        = 35;
    refShip.Price           = 27000;
    refShip.HP              = 950;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_SLOOP";

	refship.WaterLine = -0.5;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 1.0;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 9;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 3.0;

//-------------------------------------------------------------------------
// Galeoth PORTUGAL
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_GALEOTH_PORTUGAL]);
    refShip.Name            = "Galeoth1";
	refShip.Nation			= PORTUGAL;
    refShip.Class           = 5;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 12;
    refShip.Weight			= Tonnes2CWT(158);
    refShip.Capacity        = 700;
    refShip.CannonsQuantity = 16;
    refShip.MaxCrew         = 94;
    refShip.MinCrew         = 18;
    refShip.SpeedRate		= 13;
    refShip.TurnRate        = 36.75;
    refShip.Price           = 27000;
    refShip.HP              = 950;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_SLOOP";

	refship.WaterLine = -0.5;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 1.0;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 9;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 3.0;

//-------------------------------------------------------------------------
// Galeoth FRANCE
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_GALEOTH2_FRANCE]);
    refShip.Name            = "Galeoth2";
	refShip.Nation			= FRANCE;
    refShip.Class           = 5;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 12;
    refShip.Weight			= Tonnes2CWT(150);
    refShip.Capacity        = 700;
    refShip.CannonsQuantity = 16;
    refShip.MaxCrew         = 90;
    refShip.MinCrew         = 18;
    refShip.SpeedRate		= 13;
    refShip.TurnRate        = 35;
    refShip.Price           = 27000;
    refShip.HP              = 1000;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_SLOOP";

	refship.WaterLine = -0.5;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.8;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 9;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 3.0;

//-------------------------------------------------------------------------
// Galeoth SPAIN
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_GALEOTH2_SPAIN]);
    refShip.Name            = "Galeoth2";
	refShip.Nation			= SPAIN;
    refShip.Class           = 5;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 12;
    refShip.Weight			= Tonnes2CWT(150);
    refShip.Capacity        = 735;
    refShip.CannonsQuantity = 16;
    refShip.MaxCrew         = 95;
    refShip.MinCrew         = 18;
    refShip.SpeedRate		= 12.35;
    refShip.TurnRate        = 33.25;
    refShip.Price           = 27000;
    refShip.HP              = 1050;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_SLOOP";

	refship.WaterLine = -0.5;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.8;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 9;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 3.0;

//-------------------------------------------------------------------------
// Galeoth ENGLAND
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_GALEOTH2_ENGLAND]);
    refShip.Name            = "Galeoth2";
	refShip.Nation			= ENGLAND;
    refShip.Class           = 5;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 12;
    refShip.Weight			= Tonnes2CWT(150);
    refShip.Capacity        = 630;
    refShip.CannonsQuantity = 16;
    refShip.MaxCrew         = 85;
    refShip.MinCrew         = 19;
    refShip.SpeedRate		= 13.65;
    refShip.TurnRate        = 36.75;
    refShip.Price           = 27000;
    refShip.HP              = 1000;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_SLOOP";

	refship.WaterLine = -0.5;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.8;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 9;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 3.0;

//-------------------------------------------------------------------------
// Galeoth HOLLAND
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_GALEOTH2_HOLLAND]);
    refShip.Name            = "Galeoth2";
	refShip.Nation			= HOLLAND;
    refShip.Class           = 5;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 12;
    refShip.Weight			= Tonnes2CWT(142);
    refShip.Capacity        = 700;
    refShip.CannonsQuantity = 16;
    refShip.MaxCrew         = 85;
    refShip.MinCrew         = 18.65;
    refShip.SpeedRate		= 13;
    refShip.TurnRate        = 35;
    refShip.Price           = 27000;
    refShip.HP              = 950;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_SLOOP";

	refship.WaterLine = -0.5;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.8;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 9;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 3.0;

//-------------------------------------------------------------------------
// Galeoth PORTUGAL
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_GALEOTH2_PORTUGAL]);
    refShip.Name            = "Galeoth2";
	refShip.Nation			= PORTUGAL;
    refShip.Class           = 5;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 12;
    refShip.Weight			= Tonnes2CWT(158);
    refShip.Capacity        = 700;
    refShip.CannonsQuantity = 16;
    refShip.MaxCrew         = 94;
    refShip.MinCrew         = 18;
    refShip.SpeedRate		= 13;
    refShip.TurnRate        = 36.75;
    refShip.Price           = 27000;
    refShip.HP              = 950;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_SLOOP";

	refship.WaterLine = -0.5;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.8;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 9;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 3.0;

//-------------------------------------------------------------------------
// Xebec FRANCE
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_XEBEC_FRANCE]);
    refShip.Name            = "Xebec1";
	refShip.Nation			= FRANCE;
    refShip.Class           = 5;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 16;
	refShip.Weight			= Tonnes2CWT(200);
    refShip.Capacity        = 1000;
    refShip.CannonsQuantity = 20;
    refShip.MaxCrew         = 100;
    refShip.MinCrew         = 20;
    refShip.SpeedRate       = 10;
    refShip.TurnRate        = 45;
    refShip.Price           = 30000;
    refShip.HP              = 1500;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_XEBEC";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.3;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 15;	refship.InertiaBrakingY		= 10;
	refship.InertiaAccelerationZ	= 9.0;	refship.InertiaBrakingZ		= 6.0;

//-------------------------------------------------------------------------
// Xebec SPAIN
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_XEBEC_SPAIN]);
    refShip.Name            = "Xebec1";
	refShip.Nation			= SPAIN;
    refShip.Class           = 5;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 16;
	refShip.Weight			= Tonnes2CWT(200);
    refShip.Capacity        = 1050;
    refShip.CannonsQuantity = 20;
    refShip.MaxCrew         = 105;
    refShip.MinCrew         = 20;
    refShip.SpeedRate       = 9.5;
    refShip.TurnRate        = 42.75;
    refShip.Price           = 30000;
    refShip.HP              = 1575;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_XEBEC";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.3;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 15;	refship.InertiaBrakingY		= 10;
	refship.InertiaAccelerationZ	= 9.0;	refship.InertiaBrakingZ		= 6.0;

//-------------------------------------------------------------------------
// Xebec ENGLAND
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_XEBEC_ENGLAND]);
    refShip.Name            = "Xebec1";
	refShip.Nation			= ENGLAND;
    refShip.Class           = 5;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 16;
	refShip.Weight			= Tonnes2CWT(200);
    refShip.Capacity        = 900;
    refShip.CannonsQuantity = 20;
    refShip.MaxCrew         = 95;
    refShip.MinCrew         = 21;
    refShip.SpeedRate       = 10.5;
    refShip.TurnRate        = 47.25;
    refShip.Price           = 30000;
    refShip.HP              = 1500;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_XEBEC";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.3;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 15;	refship.InertiaBrakingY		= 10;
	refship.InertiaAccelerationZ	= 9.0;	refship.InertiaBrakingZ		= 6.0;
//-------------------------------------------------------------------------
// Xebec HOLLAND
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_XEBEC_HOLLAND]);
    refShip.Name            = "Xebec1";
	refShip.Nation			= HOLLAND;
    refShip.Class           = 5;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 16;
	refShip.Weight			= Tonnes2CWT(190);
    refShip.Capacity        = 1000;
    refShip.CannonsQuantity = 20;
    refShip.MaxCrew         = 95;
    refShip.MinCrew         = 20;
    refShip.SpeedRate       = 10.5;
    refShip.TurnRate        = 45;
    refShip.Price           = 30000;
    refShip.HP              = 1425;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_XEBEC";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.3;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 15;	refship.InertiaBrakingY		= 10;
	refship.InertiaAccelerationZ	= 9.0;	refship.InertiaBrakingZ		= 6.0;

//-------------------------------------------------------------------------
// Xebec PORTUGAL
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_XEBEC_PORTUGAL]);
    refShip.Name            = "Xebec1";
	refShip.Nation			= PORTUGAL;
    refShip.Class           = 5;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 16;
	refShip.Weight			= Tonnes2CWT(210);
    refShip.Capacity        = 1000;
    refShip.CannonsQuantity = 20;
    refShip.MaxCrew         = 105;
    refShip.MinCrew         = 20;
    refShip.SpeedRate       = 10;
    refShip.TurnRate        = 47.25;
    refShip.Price           = 30000;
    refShip.HP              = 1425;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_XEBEC";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.3;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 15;	refship.InertiaBrakingY		= 10;
	refship.InertiaAccelerationZ	= 9.0;	refship.InertiaBrakingZ		= 6.0;

//-------------------------------------------------------------------------
// Xebec FRANCE
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_XEBEC2_FRANCE]);
    refShip.Name            = "Xebec2";
	refShip.Nation			= FRANCE;
    refShip.Class           = 5;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 16;
	refShip.Weight			= Tonnes2CWT(200);
    refShip.Capacity        = 1000;
    refShip.CannonsQuantity = 20;
    refShip.MaxCrew         = 100;
    refShip.MinCrew         = 20;
    refShip.SpeedRate       = 10;
    refShip.TurnRate        = 45;
    refShip.Price           = 30000;
    refShip.HP              = 1500;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_XEBEC";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.3;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 15;	refship.InertiaBrakingY		= 10;
	refship.InertiaAccelerationZ	= 9.0;	refship.InertiaBrakingZ		= 6.0;

//-------------------------------------------------------------------------
// Xebec SPAIN
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_XEBEC2_SPAIN]);
    refShip.Name            = "Xebec2";
	refShip.Nation			= SPAIN;
    refShip.Class           = 5;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 16;
	refShip.Weight			= Tonnes2CWT(200);
    refShip.Capacity        = 1050;
    refShip.CannonsQuantity = 20;
    refShip.MaxCrew         = 105;
    refShip.MinCrew         = 20;
    refShip.SpeedRate       = 9.5;
    refShip.TurnRate        = 42.75;
    refShip.Price           = 30000;
    refShip.HP              = 1575;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_XEBEC";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.3;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 15;	refship.InertiaBrakingY		= 10;
	refship.InertiaAccelerationZ	= 9.0;	refship.InertiaBrakingZ		= 6.0;

//-------------------------------------------------------------------------
// Xebec ENGLAND
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_XEBEC2_ENGLAND]);
    refShip.Name            = "Xebec2";
	refShip.Nation			= ENGLAND;
    refShip.Class           = 5;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 16;
	refShip.Weight			= Tonnes2CWT(200);
    refShip.Capacity        = 900;
    refShip.CannonsQuantity = 20;
    refShip.MaxCrew         = 95;
    refShip.MinCrew         = 21;
    refShip.SpeedRate       = 10.5;
    refShip.TurnRate        = 47.25;
    refShip.Price           = 30000;
    refShip.HP              = 1500;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_XEBEC";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.3;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 15;	refship.InertiaBrakingY		= 10;
	refship.InertiaAccelerationZ	= 9.0;	refship.InertiaBrakingZ		= 6.0;

//-------------------------------------------------------------------------
// Xebec HOLLAND
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_XEBEC2_HOLLAND]);
    refShip.Name            = "Xebec2";
	refShip.Nation			= HOLLAND;
    refShip.Class           = 5;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 16;
	refShip.Weight			= Tonnes2CWT(190);
    refShip.Capacity        = 1000;
    refShip.CannonsQuantity = 20;
    refShip.MaxCrew         = 95;
    refShip.MinCrew         = 20;
    refShip.SpeedRate       = 10.5;
    refShip.TurnRate        = 45;
    refShip.Price           = 30000;
    refShip.HP              = 1425;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_XEBEC";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.3;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 15;	refship.InertiaBrakingY		= 10;
	refship.InertiaAccelerationZ	= 9.0;	refship.InertiaBrakingZ		= 6.0;

//-------------------------------------------------------------------------
// Xebec PORTUGAL
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_XEBEC2_PORTUGAL]);
    refShip.Name            = "Xebec2";
	refShip.Nation			= PORTUGAL;
    refShip.Class           = 5;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 16;
	refShip.Weight			= Tonnes2CWT(210);
    refShip.Capacity        = 1000;
    refShip.CannonsQuantity = 20;
    refShip.MaxCrew         = 105;
    refShip.MinCrew         = 20;
    refShip.SpeedRate       = 10;
    refShip.TurnRate        = 47.25;
    refShip.Price           = 30000;
    refShip.HP              = 1425;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_XEBEC";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.3;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 15;	refship.InertiaBrakingY		= 10;
	refship.InertiaAccelerationZ	= 9.0;	refship.InertiaBrakingZ		= 6.0;

//-------------------------------------------------------------------------
// Sloop FRANCE
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_SLOOP_FRANCE]);
    refShip.Name            = "Sloop1";
	refShip.Nation			= FRANCE;
    refShip.Class           = 5;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 12;
    refShip.Weight			= Tonnes2CWT(170);
    refShip.Capacity        = 800;
    refShip.CannonsQuantity = 16;
    refShip.MaxCrew         = 100;
    refShip.MinCrew         = 20;
    refShip.SpeedRate		= 10;
    refShip.TurnRate        = 40;
    refShip.Price           = 25000;
    refShip.HP              = 1200;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_SLOOP";

	refship.WaterLine = 0.1;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.5;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 10;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 3.0;


//-------------------------------------------------------------------------
// Sloop SPAIN
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_SLOOP_SPAIN]);
    refShip.Name            = "Sloop1";
	refShip.Nation			= SPAIN;
    refShip.Class           = 5;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 12;
    refShip.Weight			= Tonnes2CWT(170);
    refShip.Capacity        = 840;
    refShip.CannonsQuantity = 16;
    refShip.MaxCrew         = 105;
    refShip.MinCrew         = 20;
    refShip.SpeedRate		= 9.5;
    refShip.TurnRate        = 38;
    refShip.Price           = 25000;
    refShip.HP              = 1260;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_SLOOP";

	refship.WaterLine = 0.1;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.5;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 10;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 3.0;


//-------------------------------------------------------------------------
// Sloop ENGLAND
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_SLOOP_ENGLAND]);
    refShip.Name            = "Sloop1";
	refShip.Nation			= ENGLAND;
    refShip.Class           = 5;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 12;
    refShip.Weight			= Tonnes2CWT(170);
    refShip.Capacity        = 720;
    refShip.CannonsQuantity = 16;
    refShip.MaxCrew         = 95;
    refShip.MinCrew         = 21;
    refShip.SpeedRate		= 10.5;
    refShip.TurnRate        = 42;
    refShip.Price           = 25000;
    refShip.HP              = 1200;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_SLOOP";

	refship.WaterLine = 0.1;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.5;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 10;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 3.0;


//-------------------------------------------------------------------------
// Sloop HOLLAND
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_SLOOP_HOLLAND]);
    refShip.Name            = "Sloop1";
	refShip.Nation			= HOLLAND;
    refShip.Class           = 5;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 12;
    refShip.Weight			= Tonnes2CWT(167);
    refShip.Capacity        = 800;
    refShip.CannonsQuantity = 16;
    refShip.MaxCrew         = 95;
    refShip.MinCrew         = 20;
    refShip.SpeedRate		= 10.5;
    refShip.TurnRate        = 40;
    refShip.Price           = 25000;
    refShip.HP              = 1140;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_SLOOP";

	refship.WaterLine = 0.1;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.5;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 10;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 3.0;


//-------------------------------------------------------------------------
// Sloop PORTUGAL
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_SLOOP_PORTUGAL]);
    refShip.Name            = "Sloop1";
	refShip.Nation			= PORTUGAL;
    refShip.Class           = 5;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 12;
    refShip.Weight			= Tonnes2CWT(174);
    refShip.Capacity        = 800;
    refShip.CannonsQuantity = 16;
    refShip.MaxCrew         = 105;
    refShip.MinCrew         = 20;
    refShip.SpeedRate		= 10;
    refShip.TurnRate        = 42;
    refShip.Price           = 25000;
    refShip.HP              = 1140;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_SLOOP";

	refship.WaterLine = 0.1;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.5;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 10;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 3.0;


//-------------------------------------------------------------------------
// Sloop FRANCE
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_SLOOP2_FRANCE]);
    refShip.Name            = "Sloop2";
	refShip.Nation			= FRANCE;
    refShip.Class           = 5;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 12;
    refShip.Weight			= Tonnes2CWT(170);
    refShip.Capacity        = 800;
    refShip.CannonsQuantity = 16;
    refShip.MaxCrew         = 100;
    refShip.MinCrew         = 20;
    refShip.SpeedRate		= 10;
    refShip.TurnRate        = 40;
    refShip.Price           = 25000;
    refShip.HP              = 1200;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_SLOOP";

	refship.WaterLine = 0.1;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.5;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 10;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 3.0;


//-------------------------------------------------------------------------
// Sloop SPAIN
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_SLOOP2_SPAIN]);
    refShip.Name            = "Sloop2";
	refShip.Nation			= SPAIN;
    refShip.Class           = 5;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 12;
    refShip.Weight			= Tonnes2CWT(170);
    refShip.Capacity        = 840;
    refShip.CannonsQuantity = 16;
    refShip.MaxCrew         = 105;
    refShip.MinCrew         = 20;
    refShip.SpeedRate		= 9.5;
    refShip.TurnRate        = 38;
    refShip.Price           = 25000;
    refShip.HP              = 1260;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_SLOOP";

	refship.WaterLine = 0.1;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.5;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 10;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 3.0;


//-------------------------------------------------------------------------
// Sloop ENGLAND
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_SLOOP2_ENGLAND]);
    refShip.Name            = "Sloop2";
	refShip.Nation			= ENGLAND;
    refShip.Class           = 5;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 12;
    refShip.Weight			= Tonnes2CWT(170);
    refShip.Capacity        = 720;
    refShip.CannonsQuantity = 16;
    refShip.MaxCrew         = 95;
    refShip.MinCrew         = 21;
    refShip.SpeedRate		= 10.5;
    refShip.TurnRate        = 42;
    refShip.Price           = 25000;
    refShip.HP              = 1200;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_SLOOP";

	refship.WaterLine = 0.1;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.5;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 10;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 3.0;


//-------------------------------------------------------------------------
// Sloop HOLLAND
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_SLOOP2_HOLLAND]);
    refShip.Name            = "Sloop2";
	refShip.Nation			= HOLLAND;
    refShip.Class           = 5;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 12;
    refShip.Weight			= Tonnes2CWT(167);
    refShip.Capacity        = 800;
    refShip.CannonsQuantity = 16;
    refShip.MaxCrew         = 95;
    refShip.MinCrew         = 20;
    refShip.SpeedRate		= 10.5;
    refShip.TurnRate        = 40;
    refShip.Price           = 25000;
    refShip.HP              = 1140;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_SLOOP";

	refship.WaterLine = 0.1;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.5;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 10;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 3.0;


//-------------------------------------------------------------------------
// Sloop PORTUGAL
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_SLOOP2_PORTUGAL]);
    refShip.Name            = "Sloop2";
	refShip.Nation			= PORTUGAL;
    refShip.Class           = 5;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 12;
    refShip.Weight			= Tonnes2CWT(174);
    refShip.Capacity        = 800;
    refShip.CannonsQuantity = 16;
    refShip.MaxCrew         = 105;
    refShip.MinCrew         = 20;
    refShip.SpeedRate		= 10;
    refShip.TurnRate        = 42;
    refShip.Price           = 25000;
    refShip.HP              = 1140;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_SLOOP";

	refship.WaterLine = 0.1;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.5;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 10;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 3.0;


//-------------------------------------------------------------------------
// Schooner FRANCE
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_SCHOONER_FRANCE]);
    refShip.Name            = "Schooner1";
	refShip.Nation			= FRANCE;
    refShip.Class           = 4;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 16;
	refShip.Weight			= Tonnes2CWT(200);
    refShip.Capacity        = 1200;
    refShip.CannonsQuantity = 20;
    refShip.MaxCrew         = 120;
    refShip.MinCrew         = 24;
    refShip.SpeedRate		= 12;
    refShip.TurnRate        = 35;
    refShip.Price           = 35000;
    refShip.HP              = 1800;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_SCHOONER";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.2;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 4.0;


	refShip.Height.Bombs.Y		= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY		= 1.0;

//-------------------------------------------------------------------------
// Schooner SPAIN
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_SCHOONER_SPAIN]);
    refShip.Name            = "Schooner1";
	refShip.Nation			= SPAIN;
    refShip.Class           = 4;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 16;
	refShip.Weight			= Tonnes2CWT(200);
    refShip.Capacity        = 1260;
    refShip.CannonsQuantity = 20;
    refShip.MaxCrew         = 126;
    refShip.MinCrew         = 24;
    refShip.SpeedRate		= 11.4;
    refShip.TurnRate        = 33.25;
    refShip.Price           = 35000;
    refShip.HP              = 1890;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_SCHOONER";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.2;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.Height.Bombs.Y		= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY		= 1.0;

//-------------------------------------------------------------------------
// Schooner ENGLAND
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_SCHOONER_ENGLAND]);
    refShip.Name            = "Schooner1";
	refShip.Nation			= ENGLAND;
    refShip.Class           = 4;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 16;
	refShip.Weight			= Tonnes2CWT(200);
    refShip.Capacity        = 1080;
    refShip.CannonsQuantity = 20;
    refShip.MaxCrew         = 114;
    refShip.MinCrew         = 26;
    refShip.SpeedRate		= 12.6;
    refShip.TurnRate        = 36.25;
    refShip.Price           = 35000;
    refShip.HP              = 1800;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_SCHOONER";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.2;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.Height.Bombs.Y		= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY		= 1.0;

//-------------------------------------------------------------------------
// Schooner HOLLAND
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_SCHOONER_HOLLAND]);
    refShip.Name            = "Schooner1";
	refShip.Nation			= HOLLAND;
    refShip.Class           = 4;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 16;
	refShip.Weight			= Tonnes2CWT(190);
    refShip.Capacity        = 1200;
    refShip.CannonsQuantity = 20;
    refShip.MaxCrew         = 114;
    refShip.MinCrew         = 24;
    refShip.SpeedRate		= 12.6;
    refShip.TurnRate        = 35;
    refShip.Price           = 35000;
    refShip.HP              = 1710;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_SCHOONER";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.2;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.Height.Bombs.Y		= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY		= 1.0;

//-------------------------------------------------------------------------
// Schooner PORTUGAL
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_SCHOONER_PORTUGAL]);
    refShip.Name            = "Schooner1";
	refShip.Nation			= PORTUGAL;
    refShip.Class           = 4;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 16;
	refShip.Weight			= Tonnes2CWT(210);
    refShip.Capacity        = 1200;
    refShip.CannonsQuantity = 20;
    refShip.MaxCrew         = 126;
    refShip.MinCrew         = 24;
    refShip.SpeedRate		= 12;
    refShip.TurnRate        = 36.25;
    refShip.Price           = 35000;
    refShip.HP              = 1710;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_SCHOONER";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.2;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.Height.Bombs.Y		= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY		= 1.0;

//-------------------------------------------------------------------------
// Schooner FRANCE
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_SCHOONER2_FRANCE]);
    refShip.Name            = "Schooner2";
	refShip.Nation			= FRANCE;
    refShip.Class           = 4;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 16;
	refShip.Weight			= Tonnes2CWT(200);
    refShip.Capacity        = 1200;
    refShip.CannonsQuantity = 20;
    refShip.MaxCrew         = 120;
    refShip.MinCrew         = 24;
    refShip.SpeedRate		= 12;
    refShip.TurnRate        = 35;
    refShip.Price           = 35000;
    refShip.HP              = 1800;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_SCHOONER";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.2;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.Height.Bombs.Y		= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY		= 1.0;

//-------------------------------------------------------------------------
// Schooner SPAIN
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_SCHOONER2_SPAIN]);
    refShip.Name            = "Schooner2";
	refShip.Nation			= SPAIN;
    refShip.Class           = 4;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 16;
	refShip.Weight			= Tonnes2CWT(200);
    refShip.Capacity        = 1260;
    refShip.CannonsQuantity = 20;
    refShip.MaxCrew         = 126;
    refShip.MinCrew         = 24;
    refShip.SpeedRate		= 11.4;
    refShip.TurnRate        = 33.25;
    refShip.Price           = 35000;
    refShip.HP              = 1890;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_SCHOONER";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.2;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.Height.Bombs.Y		= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY		= 1.0;

//-------------------------------------------------------------------------
// Schooner ENGLAND
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_SCHOONER2_ENGLAND]);
    refShip.Name            = "Schooner2";
	refShip.Nation			= ENGLAND;
    refShip.Class           = 4;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 16;
	refShip.Weight			= Tonnes2CWT(200);
    refShip.Capacity        = 1080;
    refShip.CannonsQuantity = 20;
    refShip.MaxCrew         = 114;
    refShip.MinCrew         = 26;
    refShip.SpeedRate		= 12.6;
    refShip.TurnRate        = 36.25;
    refShip.Price           = 35000;
    refShip.HP              = 1800;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_SCHOONER";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.2;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.Height.Bombs.Y		= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY		= 1.0;

//-------------------------------------------------------------------------
// Schooner HOLLAND
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_SCHOONER2_HOLLAND]);
    refShip.Name            = "Schooner2";
	refShip.Nation			= HOLLAND;
    refShip.Class           = 4;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 16;
	refShip.Weight			= Tonnes2CWT(190);
    refShip.Capacity        = 1200;
    refShip.CannonsQuantity = 20;
    refShip.MaxCrew         = 114;
    refShip.MinCrew         = 24;
    refShip.SpeedRate		= 12.6;
    refShip.TurnRate        = 35;
    refShip.Price           = 35000;
    refShip.HP              = 1710;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_SCHOONER";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.2;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.Height.Bombs.Y		= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY		= 1.0;

//-------------------------------------------------------------------------
// Schooner PORTUGAL
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_SCHOONER2_PORTUGAL]);
    refShip.Name            = "Schooner2";
	refShip.Nation			= PORTUGAL;
    refShip.Class           = 4;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 16;
	refShip.Weight			= Tonnes2CWT(210);
    refShip.Capacity        = 1200;
    refShip.CannonsQuantity = 20;
    refShip.MaxCrew         = 126;
    refShip.MinCrew         = 24;
    refShip.SpeedRate		= 12;
    refShip.TurnRate        = 36.25;
    refShip.Price           = 35000;
    refShip.HP              = 1710;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_SCHOONER";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.2;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.Height.Bombs.Y		= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY		= 1.0;

//-------------------------------------------------------------------------
// Caravel FRANCE
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_CARAVEL_FRANCE]);
    refShip.Name            = "Caravel1";
	refShip.Nation			= FRANCE;
    refShip.Class           = 4;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 12;
	refShip.Weight			= Tonnes2CWT(300);
    refShip.Capacity        = 2500;
    refShip.CannonsQuantity = 32;
    refShip.MaxCrew         = 240;
    refShip.MinCrew         = 48;
    refShip.SpeedRate		= 8.0;
    refShip.TurnRate        = 25;
    refShip.Price           = 45000;
    refShip.HP              = 2500;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_SCHOONER";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.5;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 3.0;	refship.InertiaBrakingZ		= 3.0;

	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y			= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY		= 0.5;

//-------------------------------------------------------------------------
// Caravel SPAIN
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_CARAVEL_SPAIN]);
    refShip.Name            = "Caravel1";
	refShip.Nation			= SPAIN;
    refShip.Class           = 4;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 12;
	refShip.Weight			= Tonnes2CWT(300);
    refShip.Capacity        = 2625;
    refShip.CannonsQuantity = 32;
    refShip.MaxCrew         = 252;
    refShip.MinCrew         = 48;
    refShip.SpeedRate		= 7.6;
    refShip.TurnRate        = 23.75;
    refShip.Price           = 45000;
    refShip.HP              = 2625;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_SCHOONER";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.5;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 3.0;	refship.InertiaBrakingZ		= 3.0;

	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y			= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY		= 0.5;

//-------------------------------------------------------------------------
// Caravel ENGLAND
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_CARAVEL_ENGLAND]);
    refShip.Name            = "Caravel1";
	refShip.Nation			= ENGLAND;
    refShip.Class           = 4;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 12;
	refShip.Weight			= Tonnes2CWT(300);
    refShip.Capacity        = 2250;
    refShip.CannonsQuantity = 32;
    refShip.MaxCrew         = 228;
    refShip.MinCrew         = 50;
    refShip.SpeedRate		= 8.4;
    refShip.TurnRate        = 26.25;
    refShip.Price           = 45000;
    refShip.HP              = 2500;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_SCHOONER";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.5;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 3.0;	refship.InertiaBrakingZ		= 3.0;

	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y			= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY		= 0.5;

//-------------------------------------------------------------------------
// Caravel HOLLAND
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_CARAVEL_HOLLAND]);
    refShip.Name            = "Caravel1";
	refShip.Nation			= HOLLAND;
    refShip.Class           = 4;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 12;
	refShip.Weight			= Tonnes2CWT(285);
    refShip.Capacity        = 2500;
    refShip.CannonsQuantity = 32;
    refShip.MaxCrew         = 228;
    refShip.MinCrew         = 48;
    refShip.SpeedRate		= 8.4;
    refShip.TurnRate        = 25;
    refShip.Price           = 45000;
    refShip.HP              = 2375;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_SCHOONER";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.5;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 3.0;	refship.InertiaBrakingZ		= 3.0;

	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y			= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY		= 0.5;

//-------------------------------------------------------------------------
// Caravel PORTUGAL
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_CARAVEL_PORTUGAL]);
    refShip.Name            = "Caravel1";
	refShip.Nation			= PORTUGAL;
    refShip.Class           = 4;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 12;
	refShip.Weight			= Tonnes2CWT(315);
    refShip.Capacity        = 2500;
    refShip.CannonsQuantity = 32;
    refShip.MaxCrew         = 252;
    refShip.MinCrew         = 48;
    refShip.SpeedRate		= 8.0;
    refShip.TurnRate        = 26.25;
    refShip.Price           = 45000;
    refShip.HP              = 2375;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_SCHOONER";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.5;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 3.0;	refship.InertiaBrakingZ		= 3.0;

	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y			= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY		= 0.5;

//-------------------------------------------------------------------------
// Caravel FRANCE
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_CARAVEL2_FRANCE]);
    refShip.Name            = "Caravel2";
	refShip.Nation			= FRANCE;
    refShip.Class           = 4;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 12;
	refShip.Weight			= Tonnes2CWT(300);
    refShip.Capacity        = 2500;
    refShip.CannonsQuantity = 32;
    refShip.MaxCrew         = 240;
    refShip.MinCrew         = 48;
    refShip.SpeedRate		= 8.0;
    refShip.TurnRate        = 25;
    refShip.Price           = 45000;
    refShip.HP              = 2500;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_SCHOONER";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.5;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 3.0;	refship.InertiaBrakingZ		= 3.0;

	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y			= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY		= 0.5;

//-------------------------------------------------------------------------
// Caravel SPAIN
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_CARAVEL2_SPAIN]);
    refShip.Name            = "Caravel2";
	refShip.Nation			= SPAIN;
    refShip.Class           = 4;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 12;
	refShip.Weight			= Tonnes2CWT(300);
    refShip.Capacity        = 2625;
    refShip.CannonsQuantity = 32;
    refShip.MaxCrew         = 252;
    refShip.MinCrew         = 48;
    refShip.SpeedRate		= 7.6;
    refShip.TurnRate        = 23.75;
    refShip.Price           = 45000;
    refShip.HP              = 2625;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_SCHOONER";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.5;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 3.0;	refship.InertiaBrakingZ		= 3.0;

	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y			= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY		= 0.5;

//-------------------------------------------------------------------------
// Caravel ENGLAND
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_CARAVEL2_ENGLAND]);
    refShip.Name            = "Caravel2";
	refShip.Nation			= ENGLAND;
    refShip.Class           = 4;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 12;
	refShip.Weight			= Tonnes2CWT(300);
    refShip.Capacity        = 2250;
    refShip.CannonsQuantity = 32;
    refShip.MaxCrew         = 228;
    refShip.MinCrew         = 50;
    refShip.SpeedRate		= 8.4;
    refShip.TurnRate        = 26.25;
    refShip.Price           = 45000;
    refShip.HP              = 2500;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_SCHOONER";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.5;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 3.0;	refship.InertiaBrakingZ		= 3.0;

	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y			= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY		= 0.5;

//-------------------------------------------------------------------------
// Caravel HOLLAND
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_CARAVEL2_HOLLAND]);
    refShip.Name            = "Caravel2";
	refShip.Nation			= HOLLAND;
    refShip.Class           = 4;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 12;
	refShip.Weight			= Tonnes2CWT(285);
    refShip.Capacity        = 2500;
    refShip.CannonsQuantity = 32;
    refShip.MaxCrew         = 228;
    refShip.MinCrew         = 48;
    refShip.SpeedRate		= 8.4;
    refShip.TurnRate        = 25;
    refShip.Price           = 45000;
    refShip.HP              = 2375;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_SCHOONER";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.5;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 3.0;	refship.InertiaBrakingZ		= 3.0;

	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y			= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY		= 0.5;

//-------------------------------------------------------------------------
// Caravel PORTUGAL
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_CARAVEL2_PORTUGAL]);
    refShip.Name            = "Caravel2";
	refShip.Nation			= PORTUGAL;
    refShip.Class           = 4;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 12;
	refShip.Weight			= Tonnes2CWT(315);
    refShip.Capacity        = 2500;
    refShip.CannonsQuantity = 32;
    refShip.MaxCrew         = 252;
    refShip.MinCrew         = 48;
    refShip.SpeedRate		= 8.0;
    refShip.TurnRate        = 26.25;
    refShip.Price           = 45000;
    refShip.HP              = 2375;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_SCHOONER";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.5;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 3.0;	refship.InertiaBrakingZ		= 3.0;

	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y			= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY		= 0.5;

//-------------------------------------------------------------------------
// Fleut FRANCE
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_FLEUT_FRANCE]);
    refShip.Name            = "Fleut1";
	refShip.Nation			= FRANCE;
    refShip.Class           = 4;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 16;
	refShip.Weight			= Tonnes2CWT(450);
    refShip.Capacity        = 2800;
    refShip.CannonsQuantity = 20;
    refShip.MaxCrew         = 270;
    refShip.MinCrew         = 54;
    refShip.SpeedRate		= 10.0;
    refShip.TurnRate        = 35;
    refShip.Price           = 55000;
    refShip.HP              = 3000;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_SCHOONER";

	refship.WaterLine = 0.1;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.6;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 4.0;

//-------------------------------------------------------------------------
// Fleut SPAIN
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_FLEUT_SPAIN]);
    refShip.Name            = "Fleut1";
	refShip.Nation			= SPAIN;
    refShip.Class           = 4;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 16;
	refShip.Weight			= Tonnes2CWT(450);
    refShip.Capacity        = 2940;
    refShip.CannonsQuantity = 20;
    refShip.MaxCrew         = 283;
    refShip.MinCrew         = 54;
    refShip.SpeedRate		= 9.5;
    refShip.TurnRate        = 33.25;
    refShip.Price           = 55000;
    refShip.HP              = 3150;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_SCHOONER";

	refship.WaterLine = 0.1;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.6;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 4.0;

//-------------------------------------------------------------------------
// Fleut ENGLAND
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_FLEUT_ENGLAND]);
    refShip.Name            = "Fleut1";
	refShip.Nation			= ENGLAND;
    refShip.Class           = 4;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 16;
	refShip.Weight			= Tonnes2CWT(450);
    refShip.Capacity        = 2660;
    refShip.CannonsQuantity = 20;
    refShip.MaxCrew         = 257;
    refShip.MinCrew         = 57;
    refShip.SpeedRate		= 10.5;
    refShip.TurnRate        = 36.75;
    refShip.Price           = 55000;
    refShip.HP              = 3000;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_SCHOONER";

	refship.WaterLine = 0.1;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.6;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 4.0;

//-------------------------------------------------------------------------
// Fleut HOLLAND
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_FLEUT_HOLLAND]);
    refShip.Name            = "Fleut1";
	refShip.Nation			= HOLLAND;
    refShip.Class           = 4;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 16;
	refShip.Weight			= Tonnes2CWT(427);
    refShip.Capacity        = 2800;
    refShip.CannonsQuantity = 20;
    refShip.MaxCrew         = 257;
    refShip.MinCrew         = 54;
    refShip.SpeedRate		= 10.5;
    refShip.TurnRate        = 35;
    refShip.Price           = 55000;
    refShip.HP              = 2850;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_SCHOONER";

	refship.WaterLine = 0.1;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.6;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 4.0;

//-------------------------------------------------------------------------
// Fleut PORTUGAL
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_FLEUT_PORTUGAL]);
    refShip.Name            = "Fleut1";
	refShip.Nation			= PORTUGAL;
    refShip.Class           = 4;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 16;
	refShip.Weight			= Tonnes2CWT(472);
    refShip.Capacity        = 2800;
    refShip.CannonsQuantity = 20;
    refShip.MaxCrew         = 283;
    refShip.MinCrew         = 54;
    refShip.SpeedRate		= 10.0;
    refShip.TurnRate        = 36.75;
    refShip.Price           = 55000;
    refShip.HP              = 2850;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_SCHOONER";

	refship.WaterLine = 0.1;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.6;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 4.0;

//-------------------------------------------------------------------------
// Fleut FRANCE
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_FLEUT2_FRANCE]);
    refShip.Name            = "Fleut2";
	refShip.Nation			= FRANCE;
    refShip.Class           = 4;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 16;
	refShip.Weight			= Tonnes2CWT(450);
    refShip.Capacity        = 2800;
    refShip.CannonsQuantity = 20;
    refShip.MaxCrew         = 270;
    refShip.MinCrew         = 54;
    refShip.SpeedRate		= 10.0;
    refShip.TurnRate        = 35;
    refShip.Price           = 55000;
    refShip.HP              = 3000;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_SCHOONER";

	refship.WaterLine = 0.3;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.9;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 4.0;

//-------------------------------------------------------------------------
// Fleut SPAIN
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_FLEUT2_SPAIN]);
    refShip.Name            = "Fleut2";
	refShip.Nation			= SPAIN;
    refShip.Class           = 4;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 16;
	refShip.Weight			= Tonnes2CWT(450);
    refShip.Capacity        = 2940;
    refShip.CannonsQuantity = 20;
    refShip.MaxCrew         = 283;
    refShip.MinCrew         = 54;
    refShip.SpeedRate		= 9.5;
    refShip.TurnRate        = 33.25;
    refShip.Price           = 55000;
    refShip.HP              = 3150;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_SCHOONER";

	refship.WaterLine = 0.3;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.9;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 4.0;

//-------------------------------------------------------------------------
// Fleut ENGLAND
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_FLEUT2_ENGLAND]);
    refShip.Name            = "Fleut2";
	refShip.Nation			= ENGLAND;
    refShip.Class           = 4;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 16;
	refShip.Weight			= Tonnes2CWT(450);
    refShip.Capacity        = 2660;
    refShip.CannonsQuantity = 20;
    refShip.MaxCrew         = 257;
    refShip.MinCrew         = 57;
    refShip.SpeedRate		= 10.5;
    refShip.TurnRate        = 36.75;
    refShip.Price           = 55000;
    refShip.HP              = 3000;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_SCHOONER";

	refship.WaterLine = 0.3;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.9;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 4.0;

//-------------------------------------------------------------------------
// Fleut HOLLAND
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_FLEUT2_HOLLAND]);
    refShip.Name            = "Fleut2";
	refShip.Nation			= HOLLAND;
    refShip.Class           = 4;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 16;
	refShip.Weight			= Tonnes2CWT(427);
    refShip.Capacity        = 2800;
    refShip.CannonsQuantity = 20;
    refShip.MaxCrew         = 257;
    refShip.MinCrew         = 54;
    refShip.SpeedRate		= 10.5;
    refShip.TurnRate        = 35;
    refShip.Price           = 55000;
    refShip.HP              = 2850;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_SCHOONER";

	refship.WaterLine = 0.3;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.9;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 4.0;

//-------------------------------------------------------------------------
// Fleut PORTUGAL
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_FLEUT2_PORTUGAL]);
    refShip.Name            = "Fleut2";
	refShip.Nation			= PORTUGAL;
    refShip.Class           = 4;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 16;
	refShip.Weight			= Tonnes2CWT(472);
    refShip.Capacity        = 2800;
    refShip.CannonsQuantity = 20;
    refShip.MaxCrew         = 283;
    refShip.MinCrew         = 54;
    refShip.SpeedRate		= 10.0;
    refShip.TurnRate        = 36.75;
    refShip.Price           = 55000;
    refShip.HP              = 2850;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_SCHOONER";

	refship.WaterLine = 0.3;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.9;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 4.0;

//-------------------------------------------------------------------------
// Brig FRANCE
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_BRIG_FRANCE]);
    refShip.Name            = "Brig1";
	refShip.Nation			= FRANCE;
    refShip.Class           = 3;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 16;
	refShip.Weight			= Tonnes2CWT(300);
    refShip.Capacity        = 1500;
    refShip.CannonsQuantity = 24;
    refShip.MaxCrew         = 160;
    refShip.MinCrew         = 32;
    refShip.SpeedRate       = 14.0;
    refShip.TurnRate        = 40;
    refShip.Price           = 80000;
    refShip.HP              = 2500;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_PINNACE";

	refship.WaterLine = 0.1;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.4;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 9;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.Height.Bombs.Y		= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY		= 1.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// Brig SPAIN
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_BRIG_SPAIN]);
    refShip.Name            = "Brig1";
	refShip.Nation			= SPAIN;
    refShip.Class           = 3;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 16;
	refShip.Weight			= Tonnes2CWT(300);
    refShip.Capacity        = 1575;
    refShip.CannonsQuantity = 24;
    refShip.MaxCrew         = 168;
    refShip.MinCrew         = 32;
    refShip.SpeedRate       = 13.3;
    refShip.TurnRate        = 38;
    refShip.Price           = 80000;
    refShip.HP              = 2625;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_PINNACE";

	refship.WaterLine = 0.1;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.4;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 9;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.Height.Bombs.Y		= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY		= 1.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// Brig ENGLAND
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_BRIG_ENGLAND]);
    refShip.Name            = "Brig1";
	refShip.Nation			= ENGLAND;
    refShip.Class           = 3;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 16;
	refShip.Weight			= Tonnes2CWT(300);
    refShip.Capacity        = 1350;
    refShip.CannonsQuantity = 24;
    refShip.MaxCrew         = 152;
    refShip.MinCrew         = 34;
    refShip.SpeedRate       = 14.7;
    refShip.TurnRate        = 42;
    refShip.Price           = 80000;
    refShip.HP              = 2500;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_PINNACE";

	refship.WaterLine = 0.1;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.4;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 9;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.Height.Bombs.Y		= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY		= 1.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// Brig HOLLAND
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_BRIG_HOLLAND]);
    refShip.Name            = "Brig1";
	refShip.Nation			= HOLLAND;
    refShip.Class           = 3;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 16;
	refShip.Weight			= Tonnes2CWT(285);
    refShip.Capacity        = 1500;
    refShip.CannonsQuantity = 24;
    refShip.MaxCrew         = 152;
    refShip.MinCrew         = 32;
    refShip.SpeedRate       = 14.7;
    refShip.TurnRate        = 40;
    refShip.Price           = 80000;
    refShip.HP              = 2375;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_PINNACE";

	refship.WaterLine = 0.1;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.4;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 9;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.Height.Bombs.Y		= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY		= 1.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// Brig PORTUGAL
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_BRIG_PORTUGAL]);
    refShip.Name            = "Brig1";
	refShip.Nation			= PORTUGAL;
    refShip.Class           = 3;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 16;
	refShip.Weight			= Tonnes2CWT(315);
    refShip.Capacity        = 1500;
    refShip.CannonsQuantity = 24;
    refShip.MaxCrew         = 168;
    refShip.MinCrew         = 32;
    refShip.SpeedRate       = 14.0;
    refShip.TurnRate        = 42;
    refShip.Price           = 80000;
    refShip.HP              = 2375;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_PINNACE";

	refship.WaterLine = 0.1;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.4;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 9;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.Height.Bombs.Y		= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY		= 1.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// Brig FRANCE
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_BRIG2_FRANCE]);
    refShip.Name            = "Brig2";
	refShip.Nation			= FRANCE;
    refShip.Class           = 3;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 16;
	refShip.Weight			= Tonnes2CWT(300);
    refShip.Capacity        = 1500;
    refShip.CannonsQuantity = 24;
    refShip.MaxCrew         = 160;
    refShip.MinCrew         = 32;
    refShip.SpeedRate       = 14.0;
    refShip.TurnRate        = 40;
    refShip.Price           = 80000;
    refShip.HP              = 2500;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_PINNACE";

	refship.WaterLine = 0.1;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.4;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 9;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.Height.Bombs.Y		= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY		= 1.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// Brig SPAIN
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_BRIG2_SPAIN]);
    refShip.Name            = "Brig2";
	refShip.Nation			= SPAIN;
    refShip.Class           = 3;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 16;
	refShip.Weight			= Tonnes2CWT(300);
    refShip.Capacity        = 1575;
    refShip.CannonsQuantity = 24;
    refShip.MaxCrew         = 168;
    refShip.MinCrew         = 32;
    refShip.SpeedRate       = 13.3;
    refShip.TurnRate        = 38;
    refShip.Price           = 80000;
    refShip.HP              = 2625;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_PINNACE";

	refship.WaterLine = 0.1;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.4;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 9;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.Height.Bombs.Y		= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY		= 1.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// Brig ENGLAND
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_BRIG2_ENGLAND]);
    refShip.Name            = "Brig2";
	refShip.Nation			= ENGLAND;
    refShip.Class           = 3;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 16;
	refShip.Weight			= Tonnes2CWT(300);
    refShip.Capacity        = 1350;
    refShip.CannonsQuantity = 24;
    refShip.MaxCrew         = 152;
    refShip.MinCrew         = 34;
    refShip.SpeedRate       = 14.7;
    refShip.TurnRate        = 42;
    refShip.Price           = 80000;
    refShip.HP              = 2500;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_PINNACE";

	refship.WaterLine = 0.1;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.4;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 9;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.Height.Bombs.Y		= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY		= 1.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// Brig HOLLAND
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_BRIG2_HOLLAND]);
    refShip.Name            = "Brig2";
	refShip.Nation			= HOLLAND;
    refShip.Class           = 3;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 16;
	refShip.Weight			= Tonnes2CWT(285);
    refShip.Capacity        = 1500;
    refShip.CannonsQuantity = 24;
    refShip.MaxCrew         = 152;
    refShip.MinCrew         = 32;
    refShip.SpeedRate       = 14.7;
    refShip.TurnRate        = 40;
    refShip.Price           = 80000;
    refShip.HP              = 2375;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_PINNACE";

	refship.WaterLine = 0.1;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.4;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 9;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.Height.Bombs.Y		= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY		= 1.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// Brig PORTUGAL
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_BRIG2_PORTUGAL]);
    refShip.Name            = "Brig2";
	refShip.Nation			= PORTUGAL;
    refShip.Class           = 3;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 16;
	refShip.Weight			= Tonnes2CWT(315);
    refShip.Capacity        = 1500;
    refShip.CannonsQuantity = 24;
    refShip.MaxCrew         = 168;
    refShip.MinCrew         = 32;
    refShip.SpeedRate       = 14.0;
    refShip.TurnRate        = 42;
    refShip.Price           = 80000;
    refShip.HP              = 2375;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_PINNACE";

	refship.WaterLine = 0.1;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.4;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 9;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.Height.Bombs.Y		= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY		= 1.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// Galeon FRANCE
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_GALEON_FRANCE]);
    refShip.Name            = "Galeon1";
	refShip.Nation			= FRANCE;
    refShip.Class           = 3;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 16;
	refShip.Weight			= Tonnes2CWT(800);
    refShip.Capacity        = 4000;
    refShip.CannonsQuantity = 38;
    refShip.MaxCrew         = 450;
    refShip.MinCrew         = 90;
    refShip.SpeedRate		= 7.0;
    refShip.TurnRate        = 25;
    refShip.Price           = 90000;
    refShip.HP              = 5000;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_PINNACE";

	refship.WaterLine = 0.2;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 1.0;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 3;
	refship.InertiaAccelerationZ	= 2.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// Galeon SPAIN
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_GALEON_SPAIN]);
    refShip.Name            = "Galeon1";
	refShip.Nation			= SPAIN;
    refShip.Class           = 3;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 16;
	refShip.Weight			= Tonnes2CWT(800);
    refShip.Capacity        = 4200;
    refShip.CannonsQuantity = 38;
    refShip.MaxCrew         = 477;
    refShip.MinCrew         = 90;
    refShip.SpeedRate		= 6.65;
    refShip.TurnRate        = 23.75;
    refShip.Price           = 90000;
    refShip.HP              = 5250;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_PINNACE";

	refship.WaterLine = 0.2;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 1.0;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 3;
	refship.InertiaAccelerationZ	= 2.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// Galeon ENGLAND
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_GALEON_ENGLAND]);
    refShip.Name            = "Galeon1";
	refShip.Nation			= ENGLAND;
    refShip.Class           = 3;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 16;
	refShip.Weight			= Tonnes2CWT(800);
    refShip.Capacity        = 3600;
    refShip.CannonsQuantity = 38;
    refShip.MaxCrew         = 433;
    refShip.MinCrew         = 94;
    refShip.SpeedRate		= 7.35;
    refShip.TurnRate        = 26.25;
    refShip.Price           = 90000;
    refShip.HP              = 5000;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_PINNACE";

	refship.WaterLine = 0.2;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 1.0;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 3;
	refship.InertiaAccelerationZ	= 2.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// Galeon HOLLAND
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_GALEON_HOLLAND]);
    refShip.Name            = "Galeon1";
	refShip.Nation			= HOLLAND;
    refShip.Class           = 3;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 16;
	refShip.Weight			= Tonnes2CWT(760);
    refShip.Capacity        = 4000;
    refShip.CannonsQuantity = 38;
    refShip.MaxCrew         = 433;
    refShip.MinCrew         = 90;
    refShip.SpeedRate		= 7.35;
    refShip.TurnRate        = 25;
    refShip.Price           = 90000;
    refShip.HP              = 4750;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_PINNACE";

	refship.WaterLine = 0.2;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 1.0;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 3;
	refship.InertiaAccelerationZ	= 2.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// Galeon PORTUGAL
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_GALEON_PORTUGAL]);
    refShip.Name            = "Galeon1";
	refShip.Nation			= PORTUGAL;
    refShip.Class           = 3;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 16;
	refShip.Weight			= Tonnes2CWT(840);
    refShip.Capacity        = 4000;
    refShip.CannonsQuantity = 38;
    refShip.MaxCrew         = 477;
    refShip.MinCrew         = 90;
    refShip.SpeedRate		= 7.0;
    refShip.TurnRate        = 26.25;
    refShip.Price           = 90000;
    refShip.HP              = 4750;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_PINNACE";

	refship.WaterLine = 0.2;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 1.0;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 3;
	refship.InertiaAccelerationZ	= 2.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// Heavy Galeon FRANCE
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_GALEON2_FRANCE]);
    refShip.Name            = "Galeon2";
	refShip.Nation			= FRANCE;
    refShip.Class           = 3;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 16;
	refShip.Weight			= Tonnes2CWT(900);
    refShip.Capacity        = 4800;
    refShip.CannonsQuantity = 38;
    refShip.MaxCrew         = 500;
    refShip.MinCrew         = 100;
    refShip.SpeedRate		= 6.5;
    refShip.TurnRate        = 25;
    refShip.Price           = 90000;
    refShip.HP              = 5700;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_PINNACE";

	refship.WaterLine = 0.2;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 1.0;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 3;
	refship.InertiaAccelerationZ	= 2.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;

//-------------------------------------------------------------------------
// Heavy Galeon SPAIN
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_GALEON2_SPAIN]);
    refShip.Name            = "Galeon2";
	refShip.Nation			= SPAIN;
    refShip.Class           = 3;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 16;
	refShip.Weight			= Tonnes2CWT(900);
    refShip.Capacity        = 5040;
    refShip.CannonsQuantity = 38;
    refShip.MaxCrew         = 525;
    refShip.MinCrew         = 100;
    refShip.SpeedRate		= 6.22;
    refShip.TurnRate        = 23.75;
    refShip.Price           = 90000;
    refShip.HP              = 5985;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_PINNACE";

	refship.WaterLine = 0.2;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 1.0;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 3;
	refship.InertiaAccelerationZ	= 2.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;

//-------------------------------------------------------------------------
// Heavy Galeon ENGLAND
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_GALEON2_ENGLAND]);
    refShip.Name            = "Galeon2";
	refShip.Nation			= ENGLAND;
    refShip.Class           = 3;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 16;
	refShip.Weight			= Tonnes2CWT(900);
    refShip.Capacity        = 4320;
    refShip.CannonsQuantity = 38;
    refShip.MaxCrew         = 475;
    refShip.MinCrew         = 105;
    refShip.SpeedRate		= 6.82;
    refShip.TurnRate        = 26.25;
    refShip.Price           = 90000;
    refShip.HP              = 5700;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_PINNACE";

	refship.WaterLine = 0.2;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 1.0;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 3;
	refship.InertiaAccelerationZ	= 2.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;

//-------------------------------------------------------------------------
// Heavy Galeon HOLLAND
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_GALEON2_HOLLAND]);
    refShip.Name            = "Galeon2";
	refShip.Nation			= HOLLAND;
    refShip.Class           = 3;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 16;
	refShip.Weight			= Tonnes2CWT(855);
    refShip.Capacity        = 4800;
    refShip.CannonsQuantity = 38;
    refShip.MaxCrew         = 475;
    refShip.MinCrew         = 100;
    refShip.SpeedRate		= 6.82;
    refShip.TurnRate        = 25;
    refShip.Price           = 90000;
    refShip.HP              = 5415;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_PINNACE";

	refship.WaterLine = 0.2;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 1.0;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 3;
	refship.InertiaAccelerationZ	= 2.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;

//-------------------------------------------------------------------------
// Heavy Galeon PORTUGAL
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_GALEON2_PORTUGAL]);
    refShip.Name            = "Galeon2";
	refShip.Nation			= PORTUGAL;
    refShip.Class           = 3;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 16;
	refShip.Weight			= Tonnes2CWT(945);
    refShip.Capacity        = 4800;
    refShip.CannonsQuantity = 38;
    refShip.MaxCrew         = 525;
    refShip.MinCrew         = 100;
    refShip.SpeedRate		= 6.5;
    refShip.TurnRate        = 26.25;
    refShip.Price           = 90000;
    refShip.HP              = 5415;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_PINNACE";

	refship.WaterLine = 0.2;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 1.0;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 3;
	refship.InertiaAccelerationZ	= 2.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;

//-------------------------------------------------------------------------
// Pinnace FRANCE
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_PINNACE_FRANCE]);
    refShip.Name            = "Pinnace1";
	refShip.Nation			= FRANCE;
    refShip.Class           = 3;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 16;
    refShip.Weight			= Tonnes2CWT(550);
    refShip.Capacity        = 3200;
    refShip.CannonsQuantity = 24;
    refShip.MaxCrew         = 300;
    refShip.MinCrew         = 60;
    refShip.SpeedRate		= 11;
    refShip.TurnRate        = 30;
    refShip.Price           = 70000;
    refShip.HP              = 4000;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_PINNACE";

	refship.WaterLine = 0.5;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 1.3;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 7;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 3.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// Pinnace SPAIN
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_PINNACE_SPAIN]);
    refShip.Name            = "Pinnace1";
	refShip.Nation			= SPAIN;
    refShip.Class           = 3;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 16;
    refShip.Weight			= Tonnes2CWT(550);
    refShip.Capacity        = 3360;
    refShip.CannonsQuantity = 24;
    refShip.MaxCrew         = 315;
    refShip.MinCrew         = 60;
    refShip.SpeedRate		= 10.45;
    refShip.TurnRate        = 28.5;
    refShip.Price           = 70000;
    refShip.HP              = 4300;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_PINNACE";

	refship.WaterLine = 0.5;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 1.3;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 7;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 3.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// Pinnace ENGLAND
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_PINNACE_ENGLAND]);
    refShip.Name            = "Pinnace1";
	refShip.Nation			= ENGLAND;
    refShip.Class           = 3;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 16;
    refShip.Weight			= Tonnes2CWT(550);
    refShip.Capacity        = 2880;
    refShip.CannonsQuantity = 24;
    refShip.MaxCrew         = 285;
    refShip.MinCrew         = 63;
    refShip.SpeedRate		= 11.55;
    refShip.TurnRate        = 31.5;
    refShip.Price           = 70000;
    refShip.HP              = 4000;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_PINNACE";

	refship.WaterLine = 0.5;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 1.3;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 7;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 3.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// Pinnace HOLLAND
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_PINNACE_HOLLAND]);
    refShip.Name            = "Pinnace1";
	refShip.Nation			= HOLLAND;
    refShip.Class           = 3;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 16;
    refShip.Weight			= Tonnes2CWT(522);
    refShip.Capacity        = 3200;
    refShip.CannonsQuantity = 24;
    refShip.MaxCrew         = 285;
    refShip.MinCrew         = 60;
    refShip.SpeedRate		= 11.55;
    refShip.TurnRate        = 30;
    refShip.Price           = 70000;
    refShip.HP              = 3800;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_PINNACE";

	refship.WaterLine = 0.5;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 1.3;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 7;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 3.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// Pinnace PORTUGAL
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_PINNACE_PORTUGAL]);
    refShip.Name            = "Pinnace1";
	refShip.Nation			= PORTUGAL;
    refShip.Class           = 3;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 16;
    refShip.Weight			= Tonnes2CWT(577);
    refShip.Capacity        = 3200;
    refShip.CannonsQuantity = 24;
    refShip.MaxCrew         = 315;
    refShip.MinCrew         = 60;
    refShip.SpeedRate		= 11;
    refShip.TurnRate        = 31.5;
    refShip.Price           = 70000;
    refShip.HP              = 3800;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_PINNACE";

	refship.WaterLine = 0.5;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 1.3;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 7;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 3.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// Pinnace FRANCE
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_PINNACE2_FRANCE]);
    refShip.Name            = "Pinnace2";
	refShip.Nation			= FRANCE;
    refShip.Class           = 3;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 16;
    refShip.Weight			= Tonnes2CWT(550);
    refShip.Capacity        = 3200;
    refShip.CannonsQuantity = 24;
    refShip.MaxCrew         = 300;
    refShip.MinCrew         = 60;
    refShip.SpeedRate		= 11;
    refShip.TurnRate        = 30;
    refShip.Price           = 70000;
    refShip.HP              = 4000;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_PINNACE";

	refship.WaterLine = 0.3;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 1.1;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 7;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 3.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// Pinnace SPAIN
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_PINNACE2_SPAIN]);
    refShip.Name            = "Pinnace2";
	refShip.Nation			= SPAIN;
    refShip.Class           = 3;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 16;
    refShip.Weight			= Tonnes2CWT(550);
    refShip.Capacity        = 3360;
    refShip.CannonsQuantity = 24;
    refShip.MaxCrew         = 315;
    refShip.MinCrew         = 60;
    refShip.SpeedRate		= 10.45;
    refShip.TurnRate        = 28.5;
    refShip.Price           = 70000;
    refShip.HP              = 4200;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_PINNACE";

	refship.WaterLine = 0.3;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 1.1;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 7;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 3.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// Pinnace ENGLAND
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_PINNACE2_ENGLAND]);
    refShip.Name            = "Pinnace2";
	refShip.Nation			= ENGLAND;
    refShip.Class           = 3;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 16;
    refShip.Weight			= Tonnes2CWT(550);
    refShip.Capacity        = 2880;
    refShip.CannonsQuantity = 24;
    refShip.MaxCrew         = 285;
    refShip.MinCrew         = 63;
    refShip.SpeedRate		= 11.55;
    refShip.TurnRate        = 31.5;
    refShip.Price           = 70000;
    refShip.HP              = 4000;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_PINNACE";

	refship.WaterLine = 0.3;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 1.1;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 7;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 3.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// Pinnace HOLLAND
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_PINNACE2_HOLLAND]);
    refShip.Name            = "Pinnace2";
	refShip.Nation			= HOLLAND;
    refShip.Class           = 3;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 16;
    refShip.Weight			= Tonnes2CWT(522);
    refShip.Capacity        = 3200;
    refShip.CannonsQuantity = 24;
    refShip.MaxCrew         = 285;
    refShip.MinCrew         = 60;
    refShip.SpeedRate		= 11.55;
    refShip.TurnRate        = 30;
    refShip.Price           = 70000;
    refShip.HP              = 3800;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_PINNACE";

	refship.WaterLine = 0.3;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 1.1;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 7;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 3.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// Pinnace PORTUGAL
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_PINNACE2_PORTUGAL]);
    refShip.Name            = "Pinnace2";
	refShip.Nation			= PORTUGAL;
    refShip.Class           = 3;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 16;
    refShip.Weight			= Tonnes2CWT(577);
    refShip.Capacity        = 3200;
    refShip.CannonsQuantity = 24;
    refShip.MaxCrew         = 315;
    refShip.MinCrew         = 60;
    refShip.SpeedRate		= 11;
    refShip.TurnRate        = 31.5;
    refShip.Price           = 70000;
    refShip.HP              = 3800;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_PINNACE";

	refship.WaterLine = 0.3;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 1.1;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 7;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 3.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// Frigate FRANCE
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_FRIGATE_FRANCE]);
    refShip.Name            = "Frigate1";
	refShip.Nation			= FRANCE;
    refShip.Class           = 2;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 24;
	refShip.Weight			= Tonnes2CWT(1000);
    refShip.Capacity        = 2500;
    refShip.CannonsQuantity = 44;
    refShip.MaxCrew         = 400;
    refShip.MinCrew         = 80;
    refShip.SpeedRate       = 14;
    refShip.TurnRate        = 40;
    refShip.Price           = 150000;
    refShip.HP              = 6000;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_CORVETTE";

	refship.WaterLine = 0.3;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 1.0;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 10;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 2.0;

	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y			= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY		= 0.5;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// Frigate SPAIN
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_FRIGATE_SPAIN]);
    refShip.Name            = "Frigate1";
	refShip.Nation			= SPAIN;
    refShip.Class           = 2;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 24;
	refShip.Weight			= Tonnes2CWT(1000);
    refShip.Capacity        = 2625;
    refShip.CannonsQuantity = 44;
    refShip.MaxCrew         = 420;
    refShip.MinCrew         = 80;
    refShip.SpeedRate       = 13.3;
    refShip.TurnRate        = 38;
    refShip.Price           = 150000;
    refShip.HP              = 6300;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_CORVETTE";

	refship.WaterLine = 0.3;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 1.0;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 10;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 2.0;

	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y			= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY		= 0.5;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// Frigate ENGLAND
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_FRIGATE_ENGLAND]);
    refShip.Name            = "Frigate1";
	refShip.Nation			= ENGLAND;
    refShip.Class           = 2;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 24;
	refShip.Weight			= Tonnes2CWT(1000);
    refShip.Capacity        = 2250;
    refShip.CannonsQuantity = 44;
    refShip.MaxCrew         = 380;
    refShip.MinCrew         = 84;
    refShip.SpeedRate       = 14.7;
    refShip.TurnRate        = 42;
    refShip.Price           = 150000;
    refShip.HP              = 6000;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_CORVETTE";

	refship.WaterLine = 0.3;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 1.0;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 10;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 2.0;

	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y			= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY		= 0.5;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// Frigate HOLLAND
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_FRIGATE_HOLLAND]);
    refShip.Name            = "Frigate1";
	refShip.Nation			= HOLLAND;
    refShip.Class           = 2;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 24;
	refShip.Weight			= Tonnes2CWT(950);
    refShip.Capacity        = 2500;
    refShip.CannonsQuantity = 44;
    refShip.MaxCrew         = 380;
    refShip.MinCrew         = 80;
    refShip.SpeedRate       = 14.7;
    refShip.TurnRate        = 40;
    refShip.Price           = 150000;
    refShip.HP              = 5700;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_CORVETTE";

	refship.WaterLine = 0.3;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 1.0;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 10;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 2.0;

	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y			= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY		= 0.5;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// Frigate PORTUGAL
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_FRIGATE_PORTUGAL]);
    refShip.Name            = "Frigate1";
	refShip.Nation			= PORTUGAL;
    refShip.Class           = 2;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 24;
	refShip.Weight			= Tonnes2CWT(1050);
    refShip.Capacity        = 2500;
    refShip.CannonsQuantity = 44;
    refShip.MaxCrew         = 420;
    refShip.MinCrew         = 80;
    refShip.SpeedRate       = 14;
    refShip.TurnRate        = 42;
    refShip.Price           = 150000;
    refShip.HP              = 5700;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_CORVETTE";

	refship.WaterLine = 0.3;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 1.0;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 10;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 2.0;

	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y			= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY		= 0.5;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// Frigate FRANCE
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_FRIGATE2_FRANCE]);
    refShip.Name            = "Frigate2";
	refShip.Nation			= FRANCE;
    refShip.Class           = 2;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 24;
	refShip.Weight			= Tonnes2CWT(1000);
    refShip.Capacity        = 2500;
    refShip.CannonsQuantity = 44;
    refShip.MaxCrew         = 400;
    refShip.MinCrew         = 80;
    refShip.SpeedRate       = 14;
    refShip.TurnRate        = 40;
    refShip.Price           = 150000;
    refShip.HP              = 6000;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_CORVETTE";

	refship.WaterLine = 0.2;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.9;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 10;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 2.0;

	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y			= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY		= 0.5;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// Frigate SPAIN
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_FRIGATE2_SPAIN]);
    refShip.Name            = "Frigate2";
	refShip.Nation			= SPAIN;
    refShip.Class           = 2;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 24;
	refShip.Weight			= Tonnes2CWT(1000);
    refShip.Capacity        = 2625;
    refShip.CannonsQuantity = 44;
    refShip.MaxCrew         = 420;
    refShip.MinCrew         = 80;
    refShip.SpeedRate       = 13.3;
    refShip.TurnRate        = 38;
    refShip.Price           = 150000;
    refShip.HP              = 6300;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_CORVETTE";

	refship.WaterLine = 0.2;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.9;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 10;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 2.0;

	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y			= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY		= 0.5;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// Frigate ENGLAND
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_FRIGATE2_ENGLAND]);
    refShip.Name            = "Frigate2";
	refShip.Nation			= ENGLAND;
    refShip.Class           = 2;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 24;
	refShip.Weight			= Tonnes2CWT(1000);
    refShip.Capacity        = 2250;
    refShip.CannonsQuantity = 44;
    refShip.MaxCrew         = 380;
    refShip.MinCrew         = 84;
    refShip.SpeedRate       = 14.7;
    refShip.TurnRate        = 42;
    refShip.Price           = 150000;
    refShip.HP              = 6000;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_CORVETTE";

	refship.WaterLine = 0.2;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.9;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 10;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 2.0;

	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y			= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY		= 0.5;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// Frigate HOLLAND
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_FRIGATE2_HOLLAND]);
    refShip.Name            = "Frigate2";
	refShip.Nation			= HOLLAND;
    refShip.Class           = 2;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 24;
	refShip.Weight			= Tonnes2CWT(950);
    refShip.Capacity        = 2500;
    refShip.CannonsQuantity = 44;
    refShip.MaxCrew         = 380;
    refShip.MinCrew         = 80;
    refShip.SpeedRate       = 14.7;
    refShip.TurnRate        = 40;
    refShip.Price           = 150000;
    refShip.HP              = 5700;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_CORVETTE";

	refship.WaterLine = 0.2;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.9;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 10;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 2.0;

	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y			= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY		= 0.5;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// Frigate PORTUGAL
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_FRIGATE2_PORTUGAL]);
    refShip.Name            = "Frigate2";
	refShip.Nation			= PORTUGAL;
    refShip.Class           = 2;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 24;
	refShip.Weight			= Tonnes2CWT(1050);
    refShip.Capacity        = 2500;
    refShip.CannonsQuantity = 44;
    refShip.MaxCrew         = 420;
    refShip.MinCrew         = 80;
    refShip.SpeedRate       = 14;
    refShip.TurnRate        = 42;
    refShip.Price           = 150000;
    refShip.HP              = 5700;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_CORVETTE";

	refship.WaterLine = 0.2;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.9;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 10;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 2.0;

	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y			= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY		= 0.5;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// Frigate SATANIST
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_FRIGATE_SAT]);
    refShip.Name            = "Frigate_sat";
	refShip.Nation			= ENGLAND;
    refShip.Class           = 2;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 24;
	refShip.Weight			= Tonnes2CWT(1100);
    refShip.Capacity        = 2500;
    refShip.CannonsQuantity = 44;
    refShip.MaxCrew         = 400;
    refShip.MinCrew         = 95;
    refShip.SpeedRate       = 15.4;
    refShip.TurnRate        = 45;
    refShip.Price           = 180000;
    refShip.HP              = 6500;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_CORVETTE";

	refShip.EmblemedSails.normalTex = "ships\sail_Pirates.tga";

	refship.WaterLine = 0.2;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.9;
	refship.TurnDependWeight = 0.8;

	refShip.CanEncounter	= false;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 10;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 2.0;

	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y			= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY		= 0.5;

//-------------------------------------------------------------------------
// Corvette FRANCE
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_CORVETTE_FRANCE]);
    refShip.Name            = "Corvette1";
	refShip.Nation			= FRANCE;
    refShip.Class           = 2;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 24;
	refShip.Weight			= Tonnes2CWT(600);
    refShip.Capacity        = 2000;
    refShip.CannonsQuantity = 32;
    refShip.MaxCrew         = 200;
    refShip.MinCrew         = 40;
    refShip.SpeedRate		= 16;
    refShip.TurnRate        = 45;
    refShip.Price           = 120000;
    refShip.HP              = 4000;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_CORVETTE";

	refship.WaterLine = 0.1;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.6;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// Corvette SPAIN
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_CORVETTE_SPAIN]);
    refShip.Name            = "Corvette1";
	refShip.Nation			= SPAIN;
    refShip.Class           = 2;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 24;
	refShip.Weight			= Tonnes2CWT(600);
    refShip.Capacity        = 2100;
    refShip.CannonsQuantity = 32;
    refShip.MaxCrew         = 210;
    refShip.MinCrew         = 40;
    refShip.SpeedRate		= 15.2;
    refShip.TurnRate        = 42.75;
    refShip.Price           = 120000;
    refShip.HP              = 4200;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_CORVETTE";

	refship.WaterLine = 0.1;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.6;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// Corvette ENGLAND
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_CORVETTE_ENGLAND]);
    refShip.Name            = "Corvette1";
	refShip.Nation			= ENGLAND;
    refShip.Class           = 2;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 24;
	refShip.Weight			= Tonnes2CWT(600);
    refShip.Capacity        = 1800;
    refShip.CannonsQuantity = 32;
    refShip.MaxCrew         = 190;
    refShip.MinCrew         = 42;
    refShip.SpeedRate		= 16.8;
    refShip.TurnRate        = 47.25;
    refShip.Price           = 120000;
    refShip.HP              = 4000;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_CORVETTE";

	refship.WaterLine = 0.1;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.6;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// Corvette HOLLAND
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_CORVETTE_HOLLAND]);
    refShip.Name            = "Corvette1";
	refShip.Nation			= HOLLAND;
    refShip.Class           = 2;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 24;
	refShip.Weight			= Tonnes2CWT(570);
    refShip.Capacity        = 2000;
    refShip.CannonsQuantity = 32;
    refShip.MaxCrew         = 200;
    refShip.MinCrew         = 38;
    refShip.SpeedRate		= 16.8;
    refShip.TurnRate        = 45;
    refShip.Price           = 120000;
    refShip.HP              = 3800;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_CORVETTE";

	refship.WaterLine = 0.1;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.6;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// Corvette PORTUGAL
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_CORVETTE_PORTUGAL]);
    refShip.Name            = "Corvette1";
	refShip.Nation			= PORTUGAL;
    refShip.Class           = 2;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 24;
	refShip.Weight			= Tonnes2CWT(630);
    refShip.Capacity        = 2000;
    refShip.CannonsQuantity = 32;
    refShip.MaxCrew         = 210;
    refShip.MinCrew         = 40;
    refShip.SpeedRate		= 16;
    refShip.TurnRate        = 47.25;
    refShip.Price           = 120000;
    refShip.HP              = 3800;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_CORVETTE";

	refship.WaterLine = 0.1;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.6;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// Corvette FRANCE
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_CORVETTE2_FRANCE]);
    refShip.Name            = "Corvette2";
	refShip.Nation			= FRANCE;
    refShip.Class           = 2;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 24;
	refShip.Weight			= Tonnes2CWT(600);
    refShip.Capacity        = 2000;
    refShip.CannonsQuantity = 32;
    refShip.MaxCrew         = 200;
    refShip.MinCrew         = 40;
    refShip.SpeedRate		= 16;
    refShip.TurnRate        = 45;
    refShip.Price           = 120000;
    refShip.HP              = 4000;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_CORVETTE";

	refship.WaterLine = 0.1;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.55;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// Corvette SPAIN
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_CORVETTE2_SPAIN]);
    refShip.Name            = "Corvette2";
	refShip.Nation			= SPAIN;
    refShip.Class           = 2;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 24;
	refShip.Weight			= Tonnes2CWT(600);
    refShip.Capacity        = 2100;
    refShip.CannonsQuantity = 32;
    refShip.MaxCrew         = 210;
    refShip.MinCrew         = 40;
    refShip.SpeedRate		= 15.2;
    refShip.TurnRate        = 42.75;
    refShip.Price           = 120000;
    refShip.HP              = 4200;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_CORVETTE";

	refship.WaterLine = 0.1;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.55;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// Corvette ENGLAND
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_CORVETTE2_ENGLAND]);
    refShip.Name            = "Corvette2";
	refShip.Nation			= ENGLAND;
    refShip.Class           = 2;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 24;
	refShip.Weight			= Tonnes2CWT(600);
    refShip.Capacity        = 1800;
    refShip.CannonsQuantity = 32;
    refShip.MaxCrew         = 190;
    refShip.MinCrew         = 42;
    refShip.SpeedRate		= 16.8;
    refShip.TurnRate        = 47.25;
    refShip.Price           = 120000;
    refShip.HP              = 4000;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_CORVETTE";

	refship.WaterLine = 0.1;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.55;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// Corvette HOLLAND
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_CORVETTE2_HOLLAND]);
    refShip.Name            = "Corvette2";
	refShip.Nation			= HOLLAND;
    refShip.Class           = 2;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 24;
	refShip.Weight			= Tonnes2CWT(570);
    refShip.Capacity        = 2000;
    refShip.CannonsQuantity = 32;
    refShip.MaxCrew         = 200;
    refShip.MinCrew         = 38;
    refShip.SpeedRate		= 16.8;
    refShip.TurnRate        = 45;
    refShip.Price           = 120000;
    refShip.HP              = 3800;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_CORVETTE";

	refship.WaterLine = 0.1;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.55;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// Corvette PORTUGAL
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_CORVETTE2_PORTUGAL]);
    refShip.Name            = "Corvette2";
	refShip.Nation			= PORTUGAL;
    refShip.Class           = 2;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 24;
	refShip.Weight			= Tonnes2CWT(630);
    refShip.Capacity        = 2000;
    refShip.CannonsQuantity = 32;
    refShip.MaxCrew         = 210;
    refShip.MinCrew         = 40;
    refShip.SpeedRate		= 16;
    refShip.TurnRate        = 47.25;
    refShip.Price           = 120000;
    refShip.HP              = 3800;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_CORVETTE";

	refship.WaterLine = 0.1;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.55;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// Battleship FRANCE
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_BATTLESHIP_FRANCE]);
    refShip.Name            = "Battleship1";
	refShip.Nation			= FRANCE;
    refShip.Class           = 1;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 24;
    refShip.Weight			= Tonnes2CWT(2500);
    refShip.Capacity        = 5000;
    refShip.CannonsQuantity = 70;
    refShip.MaxCrew         = 650;
    refShip.MinCrew         = 130;
    refShip.SpeedRate		= 12;
    refShip.TurnRate        = 30;
    refShip.Price           = 200000;
    refShip.HP              = 10000;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_BATTLESHIP";

	refship.WaterLine = 0.1;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.55;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 7;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 1.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// Battleship SPAIN
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_BATTLESHIP_SPAIN]);
    refShip.Name            = "Battleship1";
	refShip.Nation			= SPAIN;
    refShip.Class           = 1;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 24;
    refShip.Weight			= Tonnes2CWT(2500);
    refShip.Capacity        = 5250;
    refShip.CannonsQuantity = 70;
    refShip.MaxCrew         = 682;
    refShip.MinCrew         = 130;
    refShip.SpeedRate		= 11.4;
    refShip.TurnRate        = 28.5;
    refShip.Price           = 200000;
    refShip.HP              = 10500;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_BATTLESHIP";

	refship.WaterLine = 0.1;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.55;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 7;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 1.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// Battleship ENGLAND
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_BATTLESHIP_ENGLAND]);
    refShip.Name            = "Battleship1";
	refShip.Nation			= ENGLAND;
    refShip.Class           = 1;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 24;
    refShip.Weight			= Tonnes2CWT(2500);
    refShip.Capacity        = 4500;
    refShip.CannonsQuantity = 70;
    refShip.MaxCrew         = 618;
    refShip.MinCrew         = 137;
    refShip.SpeedRate		= 12.6;
    refShip.TurnRate        = 31.5;
    refShip.Price           = 200000;
    refShip.HP              = 10000;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_BATTLESHIP";

	refship.WaterLine = 0.1;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.55;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 7;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 1.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// Battleship HOLLAND
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_BATTLESHIP_HOLLAND]);
    refShip.Name            = "Battleship1";
	refShip.Nation			= HOLLAND;
    refShip.Class           = 1;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 24;
    refShip.Weight			= Tonnes2CWT(2375);
    refShip.Capacity        = 5000;
    refShip.CannonsQuantity = 70;
    refShip.MaxCrew         = 618;
    refShip.MinCrew         = 130;
    refShip.SpeedRate		= 12.6;
    refShip.TurnRate        = 30;
    refShip.Price           = 200000;
    refShip.HP              = 9500;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_BATTLESHIP";

	refship.WaterLine = 0.1;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.55;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 7;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 1.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// Battleship PORTUGAL
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_BATTLESHIP_PORTUGAL]);
    refShip.Name            = "Battleship1";
	refShip.Nation			= PORTUGAL;
    refShip.Class           = 1;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 24;
    refShip.Weight			= Tonnes2CWT(2625);
    refShip.Capacity        = 5000;
    refShip.CannonsQuantity = 70;
    refShip.MaxCrew         = 682;
    refShip.MinCrew         = 130;
    refShip.SpeedRate		= 12;
    refShip.TurnRate        = 31.5;
    refShip.Price           = 200000;
    refShip.HP              = 9500;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_BATTLESHIP";

	refship.WaterLine = 0.1;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.55;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 7;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 1.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// Battleship FRANCE
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_BATTLESHIP2_FRANCE]);
    refShip.Name            = "Battleship2";
	refShip.Nation			= FRANCE;
    refShip.Class           = 1;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 24;
    refShip.Weight			= Tonnes2CWT(2500);
    refShip.Capacity        = 5000;
    refShip.CannonsQuantity = 70;
    refShip.MaxCrew         = 650;
    refShip.MinCrew         = 130;
    refShip.SpeedRate		= 12;
    refShip.TurnRate        = 30;
    refShip.Price           = 200000;
    refShip.HP              = 10000;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_BATTLESHIP";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.55;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 7;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 1.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// Battleship SPAIN
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_BATTLESHIP2_SPAIN]);
    refShip.Name            = "Battleship2";
	refShip.Nation			= SPAIN;
    refShip.Class           = 1;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 24;
    refShip.Weight			= Tonnes2CWT(2500);
    refShip.Capacity        = 5250;
    refShip.CannonsQuantity = 70;
    refShip.MaxCrew         = 682;
    refShip.MinCrew         = 130;
    refShip.SpeedRate		= 11.4;
    refShip.TurnRate        = 28.5;
    refShip.Price           = 200000;
    refShip.HP              = 10500;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_BATTLESHIP";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.55;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 7;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 1.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// Battleship ENGLAND
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_BATTLESHIP2_ENGLAND]);
    refShip.Name            = "Battleship2";
	refShip.Nation			= ENGLAND;
    refShip.Class           = 1;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 24;
    refShip.Weight			= Tonnes2CWT(2500);
    refShip.Capacity        = 4500;
    refShip.CannonsQuantity = 70;
    refShip.MaxCrew         = 618;
    refShip.MinCrew         = 137;
    refShip.SpeedRate		= 12.6;
    refShip.TurnRate        = 31.5;
    refShip.Price           = 200000;
    refShip.HP              = 10000;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_BATTLESHIP";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.55;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 7;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 1.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// Battleship HOLLAND
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_BATTLESHIP2_HOLLAND]);
    refShip.Name            = "Battleship2";
	refShip.Nation			= HOLLAND;
    refShip.Class           = 1;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 24;
    refShip.Weight			= Tonnes2CWT(2375);
    refShip.Capacity        = 5000;
    refShip.CannonsQuantity = 70;
    refShip.MaxCrew         = 618;
    refShip.MinCrew         = 130;
    refShip.SpeedRate		= 12.6;
    refShip.TurnRate        = 30;
    refShip.Price           = 200000;
    refShip.HP              = 9500;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_BATTLESHIP";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.55;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 7;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 1.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// Battleship PORTUGAL
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_BATTLESHIP2_PORTUGAL]);
    refShip.Name            = "Battleship2";
	refShip.Nation			= PORTUGAL;
    refShip.Class           = 1;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS12;
    refShip.MaxCaliber      = 24;
    refShip.Weight			= Tonnes2CWT(2625);
    refShip.Capacity        = 5000;
    refShip.CannonsQuantity = 70;
    refShip.MaxCrew         = 682;
    refShip.MinCrew         = 130;
    refShip.SpeedRate		= 12;
    refShip.TurnRate        = 31.5;
    refShip.Price           = 200000;
    refShip.HP              = 9500;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_BATTLESHIP";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.55;
	refship.TurnDependWeight = 0.8;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 7;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 1.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// Manowar FRANCE
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_MANOWAR_FRANCE]);
    refShip.Name            = "Manowar1";
	refShip.Nation			= FRANCE;
    refShip.Class           = 1;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS16;
    refShip.MaxCaliber      = 24;
    refShip.Weight			= Tonnes2CWT(3500);
    refShip.Capacity        = 6000;
    refShip.CannonsQuantity = 100;
    refShip.MaxCrew         = 1000;
    refShip.MinCrew         = 200;
    refShip.SpeedRate		= 13;
    refShip.TurnRate        = 20;
    refShip.Price           = 300000;
    refShip.HP              = 15000;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_BATTLESHIP";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.9;
	refship.TurnDependWeight = 0.8;

	refShip.CanEncounter	= false;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 3;
	refship.InertiaAccelerationZ	= 3.0;	refship.InertiaBrakingZ		= 1.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// Manowar SPAIN
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_MANOWAR_SPAIN]);
    refShip.Name            = "Manowar1";
	refShip.Nation			= SPAIN;
    refShip.Class           = 1;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS16;
    refShip.MaxCaliber      = 24;
    refShip.Weight			= Tonnes2CWT(3500);
    refShip.Capacity        = 6300;
    refShip.CannonsQuantity = 100;
    refShip.MaxCrew         = 1050;
    refShip.MinCrew         = 200;
    refShip.SpeedRate		= 12.3;
    refShip.TurnRate        = 19;
    refShip.Price           = 300000;
    refShip.HP              = 15750;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_BATTLESHIP";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.9;
	refship.TurnDependWeight = 0.8;

	refShip.CanEncounter	= false;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 3;
	refship.InertiaAccelerationZ	= 3.0;	refship.InertiaBrakingZ		= 1.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// Manowar ENGLAND
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_MANOWAR_ENGLAND]);
    refShip.Name            = "Manowar1";
	refShip.Nation			= ENGLAND;
    refShip.Class           = 1;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS16;
    refShip.MaxCaliber      = 24;
    refShip.Weight			= Tonnes2CWT(3500);
    refShip.Capacity        = 5400;
    refShip.CannonsQuantity = 100;
    refShip.MaxCrew         = 950;
    refShip.MinCrew         = 210;
    refShip.SpeedRate		= 13.65;
    refShip.TurnRate        = 21;
    refShip.Price           = 300000;
    refShip.HP              = 15000;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_BATTLESHIP";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.9;
	refship.TurnDependWeight = 0.8;

	refShip.CanEncounter	= false;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 3;
	refship.InertiaAccelerationZ	= 3.0;	refship.InertiaBrakingZ		= 1.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// Manowar HOLLAND
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_MANOWAR_HOLLAND]);
    refShip.Name            = "Manowar1";
	refShip.Nation			= HOLLAND;
    refShip.Class           = 1;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS16;
    refShip.MaxCaliber      = 24;
    refShip.Weight			= Tonnes2CWT(3325);
    refShip.Capacity        = 6000;
    refShip.CannonsQuantity = 100;
    refShip.MaxCrew         = 950;
    refShip.MinCrew         = 200;
    refShip.SpeedRate		= 13.65;
    refShip.TurnRate        = 20;
    refShip.Price           = 300000;
    refShip.HP              = 14250;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_BATTLESHIP";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.9;
	refship.TurnDependWeight = 0.8;

	refShip.CanEncounter	= false;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 3;
	refship.InertiaAccelerationZ	= 3.0;	refship.InertiaBrakingZ		= 1.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// Manowar PORTUGAL
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_MANOWAR_PORTUGAL]);
    refShip.Name            = "Manowar1";
	refShip.Nation			= PORTUGAL;
    refShip.Class           = 1;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS16;
    refShip.MaxCaliber      = 24;
    refShip.Weight			= Tonnes2CWT(3675);
    refShip.Capacity        = 6000;
    refShip.CannonsQuantity = 100;
    refShip.MaxCrew         = 1050;
    refShip.MinCrew         = 200;
    refShip.SpeedRate		= 13;
    refShip.TurnRate        = 21;
    refShip.Price           = 300000;
    refShip.HP              = 14250;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_BATTLESHIP";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.9;
	refship.TurnDependWeight = 0.8;

	refShip.CanEncounter	= false;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 3;
	refship.InertiaAccelerationZ	= 3.0;	refship.InertiaBrakingZ		= 1.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// Manowar FRANCE
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_MANOWAR2_FRANCE]);
    refShip.Name            = "Manowar2";
	refShip.Nation			= FRANCE;
    refShip.Class           = 1;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS16;
    refShip.MaxCaliber      = 24;
    refShip.Weight			= Tonnes2CWT(3500);
    refShip.Capacity        = 6000;
    refShip.CannonsQuantity = 100;
    refShip.MaxCrew         = 1000;
    refShip.MinCrew         = 200;
    refShip.SpeedRate		= 13;
    refShip.TurnRate        = 20;
    refShip.Price           = 300000;
    refShip.HP              = 15000;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_BATTLESHIP";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.9;
	refship.TurnDependWeight = 0.8;

	refShip.CanEncounter	= false;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 3;
	refship.InertiaAccelerationZ	= 3.0;	refship.InertiaBrakingZ		= 1.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// Manowar SPAIN
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_MANOWAR2_SPAIN]);
    refShip.Name            = "Manowar2";
	refShip.Nation			= SPAIN;
    refShip.Class           = 1;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS16;
    refShip.MaxCaliber      = 24;
    refShip.Weight			= Tonnes2CWT(3500);
    refShip.Capacity        = 6300;
    refShip.CannonsQuantity = 100;
    refShip.MaxCrew         = 1050;
    refShip.MinCrew         = 200;
    refShip.SpeedRate		= 12.3;
    refShip.TurnRate        = 19;
    refShip.Price           = 300000;
    refShip.HP              = 15750;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_BATTLESHIP";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.9;
	refship.TurnDependWeight = 0.8;

	refShip.CanEncounter	= false;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 3;
	refship.InertiaAccelerationZ	= 3.0;	refship.InertiaBrakingZ		= 1.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// Manowar ENGLAND
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_MANOWAR2_ENGLAND]);
    refShip.Name            = "Manowar2";
	refShip.Nation			= ENGLAND;
    refShip.Class           = 1;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS16;
    refShip.MaxCaliber      = 24;
    refShip.Weight			= Tonnes2CWT(3500);
    refShip.Capacity        = 5400;
    refShip.CannonsQuantity = 100;
    refShip.MaxCrew         = 950;
    refShip.MinCrew         = 210;
    refShip.SpeedRate		= 13.65;
    refShip.TurnRate        = 21;
    refShip.Price           = 300000;
    refShip.HP              = 15000;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_BATTLESHIP";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.9;
	refship.TurnDependWeight = 0.8;

	refShip.CanEncounter	= false;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 3;
	refship.InertiaAccelerationZ	= 3.0;	refship.InertiaBrakingZ		= 1.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// Manowar HOLLAND
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_MANOWAR2_HOLLAND]);
    refShip.Name            = "Manowar2";
	refShip.Nation			= HOLLAND;
    refShip.Class           = 1;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS16;
    refShip.MaxCaliber      = 24;
    refShip.Weight			= Tonnes2CWT(3325);
    refShip.Capacity        = 6000;
    refShip.CannonsQuantity = 100;
    refShip.MaxCrew         = 950;
    refShip.MinCrew         = 200;
    refShip.SpeedRate		= 13.65;
    refShip.TurnRate        = 20;
    refShip.Price           = 300000;
    refShip.HP              = 14250;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_BATTLESHIP";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.9;
	refship.TurnDependWeight = 0.8;

	refShip.CanEncounter	= false;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 3;
	refship.InertiaAccelerationZ	= 3.0;	refship.InertiaBrakingZ		= 1.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// Manowar PORTUGAL
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_MANOWAR2_PORTUGAL]);
    refShip.Name            = "Manowar2";
	refShip.Nation			= PORTUGAL;
    refShip.Class           = 1;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS16;
    refShip.MaxCaliber      = 24;
    refShip.Weight			= Tonnes2CWT(3675);
    refShip.Capacity        = 6000;
    refShip.CannonsQuantity = 100;
    refShip.MaxCrew         = 1050;
    refShip.MinCrew         = 200;
    refShip.SpeedRate		= 13;
    refShip.TurnRate        = 21;
    refShip.Price           = 300000;
    refShip.HP              = 14250;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_BATTLESHIP";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.9;
	refship.TurnDependWeight = 0.8;

	refShip.CanEncounter	= false;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 3;
	refship.InertiaAccelerationZ	= 3.0;	refship.InertiaBrakingZ		= 1.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// Manowar GUBER
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_MANOWAR_GUB]);
    refShip.Name            = "Manowar_gub";
	refShip.Nation			= ENGLAND;
    refShip.Class           = 1;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS16;
    refShip.MaxCaliber      = 24;
    refShip.Weight			= Tonnes2CWT(3500);
    refShip.Capacity        = 5400;
    refShip.CannonsQuantity = 100;
    refShip.MaxCrew         = 950;
    refShip.MinCrew         = 210;
    refShip.SpeedRate		= 13.65;
    refShip.TurnRate        = 21;
    refShip.Price           = 300000;
    refShip.HP              = 15000;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_BATTLESHIP";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.9;
	refship.TurnDependWeight = 0.8;

	refShip.CanEncounter	= false;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 10;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 1.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// Tartane2
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_TARTANE2]);
    refShip.Name            = "Tartane2";
    refShip.Class			= 7;
    refShip.Cannon          = CANNON_TYPE_NONECANNON;
    refShip.MaxCaliber      = 0;
	refShip.Weight			= Tonnes2CWT(10);
    refShip.Capacity        = 50;
    refShip.CannonsQuantity = 0;
    refShip.MaxCrew         = 12;
    refShip.MinCrew         = 3;
    refShip.SpeedRate		= 7.0;
    refShip.TurnRate        = 50;
    refShip.Price			= 1000;
    refShip.HP              = 100;
    refShip.SP              = 100;

	refShip.CanEncounter	= false;

	refship.InertiaAccelerationX	= 3.0;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 14;	refship.InertiaBrakingY		= 5;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 3.0;

	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y			= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY		= 0.5;

//-------------------------------------------------------------------------
// BLACK_PEARL
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_BLACK_PEARL]);
    refShip.Name            = "BlackPearl";
    refShip.Class			= 1;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS32;
    refShip.MaxCaliber      = 32;
	refShip.Weight			= Tonnes2CWT(2200);
    refShip.Capacity        = 3500;
    refShip.CannonsQuantity = 44;
    refShip.MaxCrew         = 600;
    refShip.MinCrew         = 150;
    refShip.SpeedRate       = 17.2;
    refShip.TurnRate        = 26;
    refShip.Price           = 50000;
    refShip.HP              = 100000;
    refShip.SP              = 100;
	refShip.EmblemedSails.normalTex = "ships\sail_BlackPearl.tga";
	refShip.AbordageLocation = "BOARDING_BATTLESHIP";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.9;
	refship.TurnDependWeight = 0.8;

	refShip.CanEncounter	= false;

	refship.InertiaAccelerationX	= 3.0;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 14;	refship.InertiaBrakingY		= 5;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 3.0;

	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y			= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY		= 0.5;


//-------------------------------------------------------------------------
// FEARLESS
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_FEARLESS]);
    refShip.Name            = "Fearless";
    refShip.Class			= 1;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS32;
    refShip.MaxCaliber      = 32;
	refShip.Weight			= Tonnes2CWT(2200);
    refShip.Capacity        = 3500;
    refShip.CannonsQuantity = 44;
    refShip.MaxCrew         = 600;
    refShip.MinCrew         = 150;
    refShip.SpeedRate       = 17.2;
    refShip.TurnRate        = 26;
    refShip.Price           = 50000;
    refShip.HP              = 15000;
    refShip.SP              = 100;
	refShip.AbordageLocation = "BOARDING_FRIGATE";

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.9;
	refship.TurnDependWeight = 0.8;

	refShip.CanEncounter	= false;

	refship.InertiaAccelerationX	= 3.0;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 14;	refship.InertiaBrakingY		= 5;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 3.0;

	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y			= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY		= 0.5;

//-------------------------------------------------------------------------
// FORT
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[SHIP_FORT]);
    refShip.Name            = "Fort";
    refShip.Class           = 1;
    refShip.Cannon          = CANNON_TYPE_CANNON_LBS32;
    refShip.MaxCaliber      = 32;
    refShip.Weight			= Tonnes2CWT(22500);
    refShip.Capacity        = 27000;
    refShip.CannonsQuantity = 68;
    refShip.MaxCrew         = 3200;
    refShip.MinCrew         = 360;
    refShip.SpeedRate		= 11.2;
    refShip.TurnRate        = 20;
    refShip.Price           = 12000;
    refShip.HP              = 54000;
    refShip.SP              = 100;

	refShip.CanEncounter	= false;

	// Check
	for (int i=0; i<SHIP_TYPES_QUANTITY_WITH_FORT-1; i++)
	{
	    makeref(refShip, ShipsTypes[i]);
		if (!CheckAttribute(refShip,"Name")) { continue; }
		if (!CheckAttribute(refShip,"TurnRate"))
		{
			Trace("ERROR: Ship " + i + " doesn't have TurnRate attribute");
		}
		if (!CheckAttribute(refShip,"SpeedRate"))
		{
			Trace("ERROR: Ship " + i + " doesn't have SpeedRate attribute");
		}
		if (!CheckAttribute(refShip,"Class"))
		{
			Trace("ERROR: Ship " + i + " doesn't have class attribute");
		}
		else
		{
			int iClass = sti(refShip.Class);
			if (iClass > 7) { Trace("ERROR: Ship " + i + " class > 7"); }
			if (iClass < 1) { Trace("ERROR: Ship " + i + " class < 1"); }
		}
		refship.InertiaAccelerationY = stf(refship.InertiaAccelerationY) / 6.0;
	}

}

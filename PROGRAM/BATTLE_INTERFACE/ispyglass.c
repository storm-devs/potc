#define ISG_CHARGE_BALLS		0
#define ISG_CHARGE_GRAPES		1
#define ISG_CHARGE_KNIPPELS		2
#define ISG_CHARGE_BOMBS		3

object objISpyGlass;

void InterfaceSpyGlassInit()
{
	FillISpyGlassParameters();
	CreateEntity(&objISpyGlass,"ispyglass");
	DeleteAttribute(&objISpyGlass,"parameters");
	LayerAddObject(SEA_EXECUTE,&objISpyGlass,-1);
	LayerAddObject(SEA_REALIZE,&objISpyGlass,-1);
	SetEventHandler("SetTelescopeInfo","SetSpyGlassData",0);
	SetEventHandler("ReleaseTelescopeInfo","ResetSpyGlassData",0);
	SetEventHandler("BI_VISIBLE","CheckInterfaceVisible",0);
}

void InterfaceSpyGlassRelease()
{
	DelEventHandler("BI_VISIBLE","CheckInterfaceVisible");
	DelEventHandler("SetTelescopeInfo","SetSpyGlassData");
	DelEventHandler("ReleaseTelescopeInfo","ResetSpyGlassData");
	DeleteClass(&objISpyGlass);
}

void CheckInterfaceVisible()
{
	int vtype = GetEventData();
	if(vtype!=0) ResetSpyGlassData();
}

void SetSpyGlassData()
{
	int chrIdx = GetEventData();
	if(chrIdx<0) return;

	int	shipHull = -1;
	int shipSail = -1;
	int shipCrew = -1;
	int shipCannons = -1;
	int shipCharge = -1;
	int shipNation = -1;
	float shipSpeed = -1.0;
	string shipName = "";
	string shipType = "";

	object tmpobj;
	aref arScopeItm;

	ref chref = GetCharacter(chrIdx);
	ref mchref = GetMainCharacter();

	if( Items_FindItem( GetCharacterEquipByGroup(mchref,SPYGLASS_ITEM_TYPE), &arScopeItm)<0 )
		{	makearef(arScopeItm,tmpobj);	}

	if( !CheckAttribute(arScopeItm,"scope.show.nation") || sti(arScopeItm.scope.show.nation)!=0 )
		{	shipNation = TranslateNationCode(sti(chref.nation));	}

	// смотрим на форт
	if(CheckAttribute(chref,"Ship.Type") && sti(chref.Ship.Type)==SHIP_FORT)
	{
		if( !CheckAttribute(arScopeItm,"scope.show.ship_type") || sti(arScopeItm.scope.show.ship_type)!=0 )
			{	shipType = "Fort";	}
		if( !CheckAttribute(arScopeItm,"scope.show.cannons") || sti(arScopeItm.scope.show.cannons)!=0 )
			{	shipCannons = Fort_GetCannonsQuantity(chref);	}
		if( !CheckAttribute(arScopeItm,"scope.show.crew") || sti(arScopeItm.scope.show.crew)!=0 )
			{	shipCrew = GetCrewQuantity(chref);	}
		if( !CheckAttribute(arScopeItm,"scope.show.hull") || sti(arScopeItm.scope.show.hull)!=0 ) {
			if( CheckAttribute(chref,"ship.hp") && CheckAttribute(chref,"fort.hp") && stf(chref.Fort.hp)>0.0 ) {
				shipHull = makeint( stf(chref.ship.hp)/stf(chref.Fort.hp) * 100.0 );
			} else {
				shipHull = 100;
			}
		}
	}
	// смотрим на корабль
	else
	{
		if( !CheckAttribute(arScopeItm,"scope.show.cannons") || sti(arScopeItm.scope.show.cannons)!=0 )
		{
			shipCannons = GetCannonQuantity(chref);
		}
		if( !CheckAttribute(arScopeItm,"scope.show.ship_name") || sti(arScopeItm.scope.show.ship_name)!=0 )
		{
			shipName = XI_ConvertString(GetShipTypeName(chref)) + " : " + chref.Ship.Name;
		}
		if( !CheckAttribute(arScopeItm,"scope.show.ship_type") || sti(arScopeItm.scope.show.ship_type)!=0 )
		{
			shipType = GetCharacterShipClass(chref);
		}


		if( !CheckAttribute(arScopeItm,"scope.show.hull") || sti(arScopeItm.scope.show.hull)!=0 )
		{
			shipHull = makeint(GetHullPercent(chref));
		}
		if( !CheckAttribute(arScopeItm,"scope.show.sail") || sti(arScopeItm.scope.show.sail)!=0 )
		{
			shipSail = makeint(GetSailPercent(chref));
		}
		if( !CheckAttribute(arScopeItm,"scope.show.crew") || sti(arScopeItm.scope.show.crew)!=0 )
		{
			shipCrew = GetCrewQuantity(chref);
		}
		if( !CheckAttribute(arScopeItm,"scope.show.speed") || sti(arScopeItm.scope.show.speed)!=0 )
		{
			shipSpeed = stf(chref.Ship.speed.z);
		}
		if( !CheckAttribute(arScopeItm,"scope.show.charge") || sti(arScopeItm.scope.show.charge)!=0 )
		{
			shipCharge = sti(chref.Ship.Cannons.Charge.Type);
		}
	}

	SendMessage(&objISpyGlass,"lsslllflll",MSG_ISG_UPDATE, shipName,shipType, shipHull,shipSail,shipCrew, shipSpeed,shipCannons,shipCharge,shipNation);
	SendMessage(&objISpyGlass,"ll",MSG_ISG_VISIBLE,true);
}

void ResetSpyGlassData()
{
	SendMessage(&objISpyGlass,"ll",MSG_ISG_VISIBLE,false);
}

int TranslateNationCode(int nationCode)
{
	switch(nationCode)
	{
	case PORTUGAL: return 0; break;
	case SPAIN: return 1; break;
	case PIRATE: return 2; break;
	case ENGLAND: return 3; break;
	case HOLLAND: return 4; break;
	case FRANCE: return 5; break;
	}
}

void FillISpyGlassParameters()
{
	// скорость фэйда
	objISpyGlass.parameters.FadeTime = 0.5;
	// имена текстурных файлов для подложки и иконок
	objISpyGlass.parameters.BackTextureName = "battle_interface\panel.tga";
	objISpyGlass.parameters.IconsTextureName = "battle_interface\spyglasses_icons.tga";
	objISpyGlass.parameters.NationsTextureName = "battle_interface\all_nations.tga";
	int bottomOffset = 24;
	// позиция подложки
	objISpyGlass.parameters.globalpos.left = 0;
	objISpyGlass.parameters.globalpos.top = sti(showWindow.bottom)-RecalculateVIcon(50+bottomOffset);
	objISpyGlass.parameters.globalpos.right = sti(showWindow.width);
	objISpyGlass.parameters.globalpos.bottom = sti(showWindow.bottom)-RecalculateVIcon(bottomOffset);
	// размер иконок
	objISpyGlass.parameters.iconsize.x = RecalculateHIcon(40);
	objISpyGlass.parameters.iconsize.y = RecalculateVIcon(40);
	// текст об имени корабля и его типе
	objISpyGlass.parameters.ShipText.font = "interface_normal";
	objISpyGlass.parameters.ShipText.scale = 1.0;
	objISpyGlass.parameters.ShipText.left = sti(showWindow.left)+RecalculateHIcon(10+42);
	objISpyGlass.parameters.ShipText.topName = sti(showWindow.bottom)-RecalculateVIcon(bottomOffset+80);
	objISpyGlass.parameters.ShipText.topType = sti(showWindow.bottom)-RecalculateVIcon(bottomOffset+36);
	// текст инфы об корабле
	objISpyGlass.parameters.DigitData.font = "bold_numbers";
	objISpyGlass.parameters.DigitData.scale = 0.5;
	objISpyGlass.parameters.DigitData.topOffset = sti(showWindow.bottom)-RecalculateVIcon(bottomOffset+32);
	objISpyGlass.parameters.DigitData.leftHull = makeint(205.0*stf(showWindow.sw)/640.0);
	objISpyGlass.parameters.DigitData.leftSail = makeint(297.0*stf(showWindow.sw)/640.0);
	objISpyGlass.parameters.DigitData.leftCrew = makeint(393.0*stf(showWindow.sw)/640.0);
	objISpyGlass.parameters.DigitData.leftSpeed = makeint(478.0*stf(showWindow.sw)/640.0);
	objISpyGlass.parameters.DigitData.leftCannons = makeint(562.0*stf(showWindow.sw)/640.0);
	// координаты для иконок
	objISpyGlass.parameters.Icons.topOffset = sti(showWindow.bottom)-RecalculateVIcon(bottomOffset+45);
	objISpyGlass.parameters.Icons.leftNation = sti(showWindow.left)+RecalculateHIcon(10);
	objISpyGlass.parameters.Icons.leftHull = sti(objISpyGlass.parameters.DigitData.leftHull)-RecalculateHIcon(42);
	objISpyGlass.parameters.Icons.leftSail = sti(objISpyGlass.parameters.DigitData.leftSail)-RecalculateHIcon(42);
	objISpyGlass.parameters.Icons.leftCrew = sti(objISpyGlass.parameters.DigitData.leftCrew)-RecalculateHIcon(42);
	objISpyGlass.parameters.Icons.leftSpeed = sti(objISpyGlass.parameters.DigitData.leftSpeed)-RecalculateHIcon(42);
	objISpyGlass.parameters.Icons.leftCannons = sti(objISpyGlass.parameters.DigitData.leftCannons)-RecalculateHIcon(42);
	objISpyGlass.parameters.Icons.leftCharge = sti(showWindow.right)-RecalculateHIcon(42);
	// координаты tu,tv для иконок
	objISpyGlass.parameters.IconsTexture.hull.left = 0;
	objISpyGlass.parameters.IconsTexture.hull.top = 0;
	objISpyGlass.parameters.IconsTexture.hull.right = 0.3125;
	objISpyGlass.parameters.IconsTexture.hull.bottom = 0.3125;
	//
	objISpyGlass.parameters.IconsTexture.sail.left = 0.3125;
	objISpyGlass.parameters.IconsTexture.sail.top = 0;
	objISpyGlass.parameters.IconsTexture.sail.right = 0.625;
	objISpyGlass.parameters.IconsTexture.sail.bottom = 0.3125;
	//
	objISpyGlass.parameters.IconsTexture.crew.left = 0.625;
	objISpyGlass.parameters.IconsTexture.crew.top = 0;
	objISpyGlass.parameters.IconsTexture.crew.right = 0.9375;
	objISpyGlass.parameters.IconsTexture.crew.bottom = 0.3125;
	//
	objISpyGlass.parameters.IconsTexture.speed.left = 0;
	objISpyGlass.parameters.IconsTexture.speed.top = 0.3125;
	objISpyGlass.parameters.IconsTexture.speed.right = 0.3125;
	objISpyGlass.parameters.IconsTexture.speed.bottom = 0.625;
	//
	objISpyGlass.parameters.IconsTexture.cannons.left = 0.3125;
	objISpyGlass.parameters.IconsTexture.cannons.top = 0.3125;
	objISpyGlass.parameters.IconsTexture.cannons.right = 0.625;
	objISpyGlass.parameters.IconsTexture.cannons.bottom = 0.625;
	//
	objISpyGlass.parameters.IconsTexture.charge0.left = 0.625;
	objISpyGlass.parameters.IconsTexture.charge0.top = 0.625;
	objISpyGlass.parameters.IconsTexture.charge0.right = 0.9375;
	objISpyGlass.parameters.IconsTexture.charge0.bottom = 0.9375;
	//
	objISpyGlass.parameters.IconsTexture.charge1.left = 0.625;
	objISpyGlass.parameters.IconsTexture.charge1.top = 0.3125;
	objISpyGlass.parameters.IconsTexture.charge1.right = 0.9375;
	objISpyGlass.parameters.IconsTexture.charge1.bottom = 0.625;
	//
	objISpyGlass.parameters.IconsTexture.charge2.left = 0.3125;
	objISpyGlass.parameters.IconsTexture.charge2.top = 0.625;
	objISpyGlass.parameters.IconsTexture.charge2.right = 0.625;
	objISpyGlass.parameters.IconsTexture.charge2.bottom = 0.9375;
	//
	objISpyGlass.parameters.IconsTexture.charge3.left = 0;
	objISpyGlass.parameters.IconsTexture.charge3.top = 0.625;
	objISpyGlass.parameters.IconsTexture.charge3.right = 0.3125;
	objISpyGlass.parameters.IconsTexture.charge3.bottom = 0.9375;
	//
	objISpyGlass.parameters.IconsTexture.nations.portugal.left = 0;
	objISpyGlass.parameters.IconsTexture.nations.portugal.top = 0;
	objISpyGlass.parameters.IconsTexture.nations.portugal.right = 0.1640625;
	objISpyGlass.parameters.IconsTexture.nations.portugal.bottom = 0.65625;
	//
	objISpyGlass.parameters.IconsTexture.nations.spain.left = 0.1640625;
	objISpyGlass.parameters.IconsTexture.nations.spain.top = 0;
	objISpyGlass.parameters.IconsTexture.nations.spain.right = 0.328125;
	objISpyGlass.parameters.IconsTexture.nations.spain.bottom = 0.65625;
	//
	objISpyGlass.parameters.IconsTexture.nations.pirate.left = 0.328125;
	objISpyGlass.parameters.IconsTexture.nations.pirate.top = 0;
	objISpyGlass.parameters.IconsTexture.nations.pirate.right = 0.4921875;
	objISpyGlass.parameters.IconsTexture.nations.pirate.bottom = 0.65625;
	//
	objISpyGlass.parameters.IconsTexture.nations.england.left = 0.4921875;
	objISpyGlass.parameters.IconsTexture.nations.england.top = 0;
	objISpyGlass.parameters.IconsTexture.nations.england.right = 0.65625;
	objISpyGlass.parameters.IconsTexture.nations.england.bottom = 0.65625;
	//
	objISpyGlass.parameters.IconsTexture.nations.holland.left = 0.65625;
	objISpyGlass.parameters.IconsTexture.nations.holland.top = 0;
	objISpyGlass.parameters.IconsTexture.nations.holland.right = 0.8203125;
	objISpyGlass.parameters.IconsTexture.nations.holland.bottom = 0.65625;
	//
	objISpyGlass.parameters.IconsTexture.nations.france.left = 0.8203125;
	objISpyGlass.parameters.IconsTexture.nations.france.top = 0;
	objISpyGlass.parameters.IconsTexture.nations.france.right = 0.984375;
	objISpyGlass.parameters.IconsTexture.nations.france.bottom = 0.65625;
}

void TelescopeInitParameters(ref rTelescope)
{
	ref mchref = GetMainCharacter();

	aref arItmScope;
	if( Items_FindItem(GetCharacterEquipByGroup(mchref,SPYGLASS_ITEM_TYPE),&arItmScope)>=0 )
	{	setTelescopeInitParameters(rTelescope,arItmScope);
	}
	else
	{
		object tmpobj;
		setTelescopeInitParameters(rTelescope,&tmpobj);
	}
}

void setTelescopeInitParameters(ref rTelescope, aref arItmScope)
{
	string texName = "telescope.tga";
	float fZoom = 5.5;
	int nShowItm = 7;
	int activateTime = 500;
	int updateTime = 150;

	if( CheckAttribute(arItmScope,"scope.texture") )
	{	texName = arItmScope.scope.texture;
	}
	if( CheckAttribute(arItmScope,"scope.zoom") )
	{	fZoom = stf(arItmScope.scope.zoom);
	}
	if( CheckAttribute(arItmScope,"scope.time_activate") )
	{	activateTime = sti(arItmScope.scope.time_activate);
	}
	if( CheckAttribute(arItmScope,"scope.time_update") )
	{	updateTime = sti(arItmScope.scope.time_update);
	}

	SendMessage(rTelescope, "lsflll", MSG_TELESCOPE_SET_TYPE, texName, fZoom, nShowItm, activateTime, updateTime);
}

#define sailCostPercent		10
#define hullCostPercent		20

#define ISHOW_MODE_VIEW			0
#define ISHOW_MODE_EMPTYVIEW	1
#define ISHOW_MODE_BUY			2
#define ISHOW_MODE_SELL			3
#define ISHOW_MODE_REPAIR		4
#define ISHOW_MODE_COMPANION	5
#define ISHOW_MODE_CHOOSE		6
#define ISHOW_MODE_SKILLS		7

int nShowMode = -1;

int	nCurSScrollNum = -1;
int	nCurFScrollNum = -1;
int	nCurFourNum = -1;

string OldNodeName = "";

aref arShipList;

int nAllPassngerQuantity;

int nspRepair;
int nhpRepair;

bool removable = false;

string sPreviouseNode = "";

int nChrIdxForInfo = -1;

void InitInterface_R(string iniName,ref shipmaster)
{
    GameInterface.title = "titleShipyard";
	makearef(arShipList,shipmaster.shipyard);

    FillFScroll();
    FillSScroll();
    FillFourImages();

    SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);

    CreateString(true,"Money",MakeMoneyShow(sti(Characters[GetMainCharacterIndex()].money),""," "),FONT_NORMAL,COLOR_MONEY,320,406,SCRIPT_ALIGN_CENTER,1.0);
    CreateString(true,"ShipName","",FONT_NORMAL,COLOR_NORMAL,320,198,SCRIPT_ALIGN_CENTER,1.0);

    CreateString(true,"ShipClass","",FONT_NORMAL,COLOR_NORMAL,228,232,SCRIPT_ALIGN_LEFT,1.0);
    CreateString(true,"HullPoints","",FONT_NORMAL,COLOR_NORMAL,228,266,SCRIPT_ALIGN_LEFT,1.0);
    CreateString(true,"Speed","",FONT_NORMAL,COLOR_NORMAL,228,300,SCRIPT_ALIGN_LEFT,1.0);
    CreateString(true,"Maneuver","",FONT_NORMAL,COLOR_NORMAL,228,334,SCRIPT_ALIGN_LEFT,1.0);
    CreateString(true,"Capacity","",FONT_NORMAL,COLOR_NORMAL,228,368,SCRIPT_ALIGN_LEFT,1.0);
    CreateString(true,"MaxCrew","",FONT_NORMAL,COLOR_NORMAL,376,232,SCRIPT_ALIGN_LEFT,1.0);
    CreateString(true,"MinCrew","",FONT_NORMAL,COLOR_NORMAL,376,266,SCRIPT_ALIGN_LEFT,1.0);
    CreateString(true,"CannonsQuantity","",FONT_NORMAL,COLOR_NORMAL,376,300,SCRIPT_ALIGN_LEFT,1.0);
    CreateString(true,"MaxCaliber","",FONT_NORMAL,COLOR_NORMAL,376,334,SCRIPT_ALIGN_LEFT,1.0);
    CreateString(true,"ShipCost","",FONT_NORMAL,COLOR_NORMAL,376,368,SCRIPT_ALIGN_LEFT,1.0);

    CreateString(false,"RepairAllCost","",FONT_NORMAL,COLOR_NORMAL,366,234,SCRIPT_ALIGN_LEFT,1.0);
    CreateString(false,"HullPercent","",FONT_NORMAL,COLOR_NORMAL,320,278,SCRIPT_ALIGN_CENTER,1.0);
    CreateString(false,"RepairHullCost","",FONT_NORMAL,COLOR_NORMAL,426,278,SCRIPT_ALIGN_LEFT,1.0);
    CreateString(false,"SailsPercent","",FONT_NORMAL,COLOR_NORMAL,320,322,SCRIPT_ALIGN_CENTER,1.0);
    CreateString(false,"RepairSailsCost","",FONT_NORMAL,COLOR_NORMAL,426,322,SCRIPT_ALIGN_LEFT,1.0);

    CreateString(false,"TradePrice","",FONT_NORMAL,COLOR_NORMAL,320,255,SCRIPT_ALIGN_LEFT,1.0);

	CreateString(false,"CharacterName","",FONT_NORMAL,COLOR_NORMAL,320,198,SCRIPT_ALIGN_CENTER,1.0);
    CreateString(false,"skillLeadership","",FONT_BOLD_NUMBERS,COLOR_NORMAL,300,232,SCRIPT_ALIGN_RIGHT,1.0);
    CreateString(false,"skillFencing","",FONT_BOLD_NUMBERS,COLOR_NORMAL,300,266,SCRIPT_ALIGN_RIGHT,1.0);
    CreateString(false,"skillSailing","",FONT_BOLD_NUMBERS,COLOR_NORMAL,300,300,SCRIPT_ALIGN_RIGHT,1.0);
    CreateString(false,"skillAccuracy","",FONT_BOLD_NUMBERS,COLOR_NORMAL,300,334,SCRIPT_ALIGN_RIGHT,1.0);
    CreateString(false,"skillCannons","",FONT_BOLD_NUMBERS,COLOR_NORMAL,300,368,SCRIPT_ALIGN_RIGHT,1.0);
    CreateString(false,"skillGrappling","",FONT_BOLD_NUMBERS,COLOR_NORMAL,434,232,SCRIPT_ALIGN_RIGHT,1.0);
    CreateString(false,"skillRepair","",FONT_BOLD_NUMBERS,COLOR_NORMAL,434,266,SCRIPT_ALIGN_RIGHT,1.0);
    CreateString(false,"skillDefence","",FONT_BOLD_NUMBERS,COLOR_NORMAL,434,300,SCRIPT_ALIGN_RIGHT,1.0);
    CreateString(false,"skillCommerce","",FONT_BOLD_NUMBERS,COLOR_NORMAL,434,334,SCRIPT_ALIGN_RIGHT,1.0);
    CreateString(false,"skillSneak","",FONT_BOLD_NUMBERS,COLOR_NORMAL,434,368,SCRIPT_ALIGN_RIGHT,1.0);

	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
    SetEventHandler("frame","ProcessFrame",1);
    SetEventHandler("exitCancel","ProcessCancelExit",0);
	SetEventHandler("ievnt_command","ProcessCommandExecute",0);
}

void ProcessCancelExit()
{
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
    DelEventHandler("frame","ProcessFrame");
    DelEventHandler("exitCancel","ProcessCancelExit");
	DelEventHandler("ievnt_command","ProcessCommandExecute");

	DoShipParametersClamp();

	interfaceResultCommand = RC_INTERFACE_SHIPYARD_EXIT;
    EndCancelInterface(true);
}

void ProcessFrame()
{
	if(OldNodeName!=GetCurrentNode())
	{
		OldNodeName = GetCurrentNode();
		switch(OldNodeName)
		{
		case "SHIPSLIST":	nCurFourNum=-1; break;
		case "SCROLLITEMS":	nCurSScrollNum=-1; break;
		case "PASSENGERS":	nCurFScrollNum=-1; break;
		}
	}
	if(nCurFScrollNum!=sti(GameInterface.passengers.current))
	{
		nCurFScrollNum = sti(GameInterface.passengers.current);
		UpdateFScrollData();
	}
	if(nCurSScrollNum!=sti(GameInterface.scrollitems.current))
	{
		nCurSScrollNum = sti(GameInterface.scrollitems.current);
		UpdateSScrollData();
	}
	if(nCurFourNum!=sti(GameInterface.FourImage.current))
	{
		nCurFourNum = sti(GameInterface.FourImage.current);
		UpdateFourData();
	}
}

void UpdateFourData()
{
	int cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum);
	SetCharacterToInfoCharacter(cn);
	removable = true;
	if(cn<0)
	{
		if(nAllPassngerQuantity>0)
		{
			SetShowMode(ISHOW_MODE_COMPANION);
			SetCaptainButtonsEnable();
		}
		else
		{
			SetShowMode(ISHOW_MODE_EMPTYVIEW);
		}
		GameInterface.strings.ShipName = "";
	}
	else
	{
		removable = GetRemovable(GetCharacter(cn));
		if(CheckAttribute(GetCharacter(cn),"ship.name"))
		{
			GameInterface.strings.ShipName = Characters[cn].ship.name;
		}
		else
		{
			GameInterface.strings.ShipName = "";
		}
		int st = GetCharacterShipType(GetCharacter(cn));
		if(st==SHIP_NOTUSED)
		{
			SetShowMode(ISHOW_MODE_EMPTYVIEW);
		}
		else
		{
			SetShowMode(ISHOW_MODE_VIEW);
			SetViewShipData(st,GetSellPrice(nCurFourNum));
		}
	}
}

void UpdateFScrollData()
{
	if(nAllPassngerQuantity<=0) return;
	SetCharacterToInfoCharacter( GetPassengerFromScroll(nCurFScrollNum) );
	SetShowMode(ISHOW_MODE_COMPANION);
	SetCaptainButtonsEnable();
}

void SetRepairData()
{
	int cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum);
	int st = GetCharacterShipType(GetCharacter(cn));

	int hp = MakeInt(GetHullPercent(GetCharacter(cn)));
	int sp = MakeInt(GetSailPercent(GetCharacter(cn)));
	int hcost = GetHullRepairCost(st,GetHullDamagePercent(nCurFourNum));
	int scost = GetSailRepairCost(st,GetSailDamagePercent(nCurFourNum));
    GameInterface.strings.HullPercent = hp + "%";
    GameInterface.strings.SailsPercent = sp + "%";
    GameInterface.strings.RepairHullCost = 0;//hcost;
    GameInterface.strings.RepairSailsCost = 0;//scost;
    GameInterface.strings.RepairAllCost = hcost + scost;

	nhpRepair = hp;
	nspRepair = sp;
	SetRapairButtonSelected();
}

void SetRapairButtonSelected()
{
	int cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum);
	int st = GetCharacterShipType(GetCharacter(cn));

	int hp = MakeInt(GetHullPercent(GetCharacter(cn)));
	int sp = MakeInt(GetSailPercent(GetCharacter(cn)));
	int hcost = GetHullRepairCost(st,GetHullDamagePercent(nCurFourNum));
	int scost = GetSailRepairCost(st,GetSailDamagePercent(nCurFourNum));

	SetSelectable("FIXALL_BUTTON",hp<100 || sp<100);
	SetSelectable("HULLQUANTITY",hp<100);
	SetSelectable("SAILSQUANTITY",sp<100);
	SetSelectable("REPAIR_OK",nhpRepair>hp || nspRepair>sp);

	int color = COLOR_DESELECT;
	if(hp<100)	color = COLOR_NORMAL;
    CreateString(true,"HullPercent",hp+"%",FONT_NORMAL,color,320,278,SCRIPT_ALIGN_CENTER,1.0);
	color = COLOR_DESELECT;
	if(sp<100)	color = COLOR_NORMAL;
    CreateString(true,"SailsPercent",sp+"%",FONT_NORMAL,color,320,322,SCRIPT_ALIGN_CENTER,1.0);

	string curNod = GetCurrentNode();
	if( curNod=="FIXALL_BUTTON" || curNod=="HULLQUANTITY" ||
		curNod=="SAILSQUANTITY" || curNod=="REPAIR_OK" )
	{
		Event("ievnt_command","ss","downstep",curNod);
	}
}

void SetViewShipData(int shipType, int shipCost)
{
	ref shref = GetShipByType(shipType);
	GameInterface.strings.ShipClass = sti(shref.Class);
	GameInterface.strings.HullPoints = sti(shref.HP);
	GameInterface.strings.Speed = FloatToString(stf(shref.SpeedRate),2);
	GameInterface.strings.Maneuver = FloatToString(stf(shref.TurnRate),2);
	GameInterface.strings.Capacity = sti(shref.Capacity);
	GameInterface.strings.MaxCrew = sti(shref.MaxCrew);
	GameInterface.strings.MinCrew = sti(shref.MinCrew);
	GameInterface.strings.CannonsQuantity = sti(shref.CannonsQuantity);
	GameInterface.strings.MaxCaliber = sti(shref.MaxCaliber);
	GameInterface.strings.ShipCost = shipCost;
}

void UpdateSScrollData()
{
	int st = GetScrollShipType(nCurSScrollNum);
	if(st==SHIP_NOTUSED)
	{
		SetShowMode(ISHOW_MODE_EMPTYVIEW);
	}
	else
	{
		SetShowMode(ISHOW_MODE_VIEW);
		SetViewShipData(st,GetShipPriceByType(st));
	}
}

void SetCurrentRepairButton()
{
	if(GetSelectable("FIXALL_BUTTON"))
	{
		SetCurrentNode("FIXALL_BUTTON");
	}
}

void ProcessCommandExecute()
{
	int i,cn;

	string comName = GetEventData();
	string nodName = GetEventData();

	switch(nodName)
	{
	case "SCROLLITEMS":
		if(comName=="activate")
		{
			if( IsEnableBuyShip() && IsMoneyForBuyEnable() )
			{
				SetShowMode(ISHOW_MODE_BUY);
				SetCurrentNode("OK_BUTTON");
				GameInterface.strings.TradePrice = MakeMoneyShow(GetBuyPrice(nCurSScrollNum)-GetSellPrice(nCurFourNum),""," ");
			}
		}
	break;

	case "PASSENGERS":
		if(comName=="activate" || comName=="downstep")
		{
			SelectCaptainButton();
		}
	break;

	case "SHIPSLIST":
		if(comName=="activate")
		{
			if(nShowMode!=ISHOW_MODE_COMPANION)
			{
				SetShowMode(ISHOW_MODE_CHOOSE);
				EnableChooseButtons();
				ChooseButtonTopSelect();
			} else {SelectCaptainButton();}
		}
	break;

	case "LEFTSCROLLBUTTON":
		switch(comName)
		{
		case "click":
			if(GetSelectable("SCROLLITEMS"))
			{
				SetCurrentNode("SCROLLITEMS");
				SendMessage(&GameInterface,"lslll",MSG_INTERFACE_MSG_TO_NODE,"SCROLLITEMS",-1, 0,ACTION_LEFTSTEP);
			}
			else
			{
				SetCurrentNode("PASSENGERS");
				SendMessage(&GameInterface,"lslll",MSG_INTERFACE_MSG_TO_NODE,"PASSENGERS",-1, 0,ACTION_LEFTSTEP);
			}
		break;
		}
	break;

	case "RIGHTSCROLLBUTTON":
		switch(comName)
		{
		case "click":
			if(GetSelectable("SCROLLITEMS"))
			{
				SetCurrentNode("SCROLLITEMS");
				SendMessage(&GameInterface,"lslll",MSG_INTERFACE_MSG_TO_NODE,"SCROLLITEMS",-1, 0,ACTION_RIGHTSTEP);
			}
			else
			{
				SetCurrentNode("PASSENGERS");
				SendMessage(&GameInterface,"lslll",MSG_INTERFACE_MSG_TO_NODE,"PASSENGERS",-1, 0,ACTION_RIGHTSTEP);
			}
		break;
		}
	break;

	case "FIXALL_BUTTON":
		if(comName=="downstep")
		{
			if(GetSelectable("HULLQUANTITY"))
			{
				SetCurrentNode("HULLQUANTITY");
			}
			else
			{
				Event("ievnt_command","ss",comName,"HULLQUANTITY");
			}
		}
		if(comName=="activate" || comName=="click")
		{
			cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum);
			if(cn>=0)
			{
				DoHullRepairToPercent(GetCharacter(cn),100);
				DoSailRepairToPercent(GetCharacter(cn),100);
				SetRepairData();
				SetCurrentNode("SHIPSLIST");
			}
		}
	break;

	case "HULLQUANTITY":
		switch(comName)
		{
		case "downstep":
			if(GetSelectable("SAILSQUANTITY"))
			{
				SetCurrentNode("SAILSQUANTITY");
			}
			else
			{
				Event("ievnt_command","ss",comName,"SAILSQUANTITY");
			}
		break;
		case "upstep":
			if(GetSelectable("FIXALL_BUTTON"))
			{
				SetCurrentNode("FIXALL_BUTTON");
			}
		break;
		case "rightstep":
			ChangeHullRepair(1);
			cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum);
			if(cn<0) {SetSelectable("REPAIR_OK",false);}
			else
			{
				SetSelectable("REPAIR_OK",
					nhpRepair>MakeInt(GetHullPercent(GetCharacter(cn))) ||
					nspRepair>MakeInt(GetSailPercent(GetCharacter(cn))) );
			}
			if(OldNodeName!="HULLQUANTITY")
			{
				OldNodeName="HULLQUANTITY";
				SetCurrentNode("HULLQUANTITY");
			}
		break;
		case "leftstep":
			ChangeHullRepair(-1);
			cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum);
			if(cn<0) {SetSelectable("REPAIR_OK",false);}
			else
			{
				SetSelectable("REPAIR_OK",
					nhpRepair>MakeInt(GetHullPercent(GetCharacter(cn))) ||
					nspRepair>MakeInt(GetSailPercent(GetCharacter(cn))) );
			}
			if(OldNodeName!="HULLQUANTITY")
			{
				OldNodeName="HULLQUANTITY";
				SetCurrentNode("HULLQUANTITY");
			}
		break;
		}
	break;

	case "SAILSQUANTITY":
		switch(comName)
		{
		case "downstep":
			if(GetSelectable("REPAIR_OK"))
			{
				SetCurrentNode("REPAIR_OK");
			}
			else
			{
				Event("ievnt_command","ss",comName,"REPAIR_OK");
			}
		break;
		case "upstep":
			if(GetSelectable("HULLQUANTITY"))
			{
				SetCurrentNode("HULLQUANTITY");
			}
			else
			{
				Event("ievnt_command","ss",comName,"HULLQUANTITY");
			}
		break;
		case "rightstep":
			ChangeSailRepair(1);
			cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum);
			if(cn<0) {SetSelectable("REPAIR_OK",false);}
			else
			{
				SetSelectable("REPAIR_OK",
					nhpRepair>MakeInt(GetHullPercent(GetCharacter(cn))) ||
					nspRepair>MakeInt(GetSailPercent(GetCharacter(cn))) );
			}
			if(OldNodeName!="SAILSQUANTITY")
			{
				OldNodeName="SAILSQUANTITY";
				SetCurrentNode("SAILSQUANTITY");
			}
		break;
		case "leftstep":
			ChangeSailRepair(-1);
			cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum);
			if(cn<0) {SetSelectable("REPAIR_OK",false);}
			else
			{
				SetSelectable("REPAIR_OK",
					nhpRepair>MakeInt(GetHullPercent(GetCharacter(cn))) ||
					nspRepair>MakeInt(GetSailPercent(GetCharacter(cn))) );
			}
			if(OldNodeName!="SAILSQUANTITY")
			{
				OldNodeName="SAILSQUANTITY";
				SetCurrentNode("SAILSQUANTITY");
			}
		break;
		}
	break;

	case "REPAIR_OK":
		switch(comName)
		{
		case "upstep":
			if(GetSelectable("SAILSQUANTITY"))
			{
				SetCurrentNode("SAILSQUANTITY");
			}
			else
			{
				Event("ievnt_command","ss",comName,"SAILSQUANTITY");
			}
		break;
		}
		if(comName=="activate" || comName=="click")
		{
			cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum);
			if(cn>=0)
			{
				DoHullRepairToPercent(GetCharacter(cn),nhpRepair);
				DoSailRepairToPercent(GetCharacter(cn),nspRepair);
				SetRepairData();
				if( !IsEnableRepairShip() ) {
					SetCurrentNode("SHIPSLIST");
				}
				else {
					SetCurrentNode("FIXALL_BUTTON");
				}
			}
		}
	break;

	case "OK_BUTTON":
		if(comName=="activate" || comName=="click")
		{
			if(nShowMode==ISHOW_MODE_SELL)
			{
				DoSellShip();
			}
			if(nShowMode==ISHOW_MODE_BUY)
			{
				DoBuyShip();
			}
			UpdateFourImages();
			UpdateShipScroll();
			SetCurrentNode("SHIPSLIST");
			nCurSScrollNum = -1;
			nCurFourNum = -1;
		}
	break;

	case "CANCEL_BUTTON":
	break;

	case "SKILLINFO_BUTTON":
		if(comName=="activate" || comName=="click")
		{
			SetShowMode(ISHOW_MODE_SKILLS);
			SetSkillData();
			SetCurrentNode("SKILLS_IMAGES");
		}
		if(comName=="upstep")	{SetNextCaptainButton(nodName,true);}
		if(comName=="downstep")	{SetNextCaptainButton(nodName,false);}
	break;

	case "REMOVEC_BUTTON":
		if(comName=="activate" || comName=="click")
		{
			FireCaptain();
			SetCurrentNode("SHIPSLIST");
		}
		if(comName=="upstep")	{SetNextCaptainButton(nodName,true);}
		if(comName=="downstep")	{SetNextCaptainButton(nodName,false);}
	break;

	case "SETC_BUTTON":
		if(comName=="activate" || comName=="click")
		{
			UpdateCompanionCharacter();
			SetCurrentNode("SHIPSLIST");
		}
		if(comName=="upstep")	{SetNextCaptainButton(nodName,true);}
	break;

	case "BUY_BUTTON":
		if(comName=="activate" || comName=="click")
		{
			SetShowMode(ISHOW_MODE_VIEW);
			SetCurrentNode("SCROLLITEMS");
		}
		if(comName=="upstep")	{ChooseButtonNextSelect(nodName,true);}
		if(comName=="downstep")	{ChooseButtonNextSelect(nodName,false);}
	break;

	case "REPAIR_BUTTON":
		if(comName=="activate" || comName=="click")
		{
			SetShowMode(ISHOW_MODE_REPAIR);
			SetRepairData();
			SetCurrentRepairButton();
		}
		if(comName=="upstep")	{ChooseButtonNextSelect(nodName,true);}
		if(comName=="downstep")	{ChooseButtonNextSelect(nodName,false);}
	break;

	case "SELLSHIP_BUTTON":
		if(comName=="activate" || comName=="click")
		{
			SetShowMode(ISHOW_MODE_SELL);
			SetCurrentNode("OK_BUTTON");
			GameInterface.strings.TradePrice = MakeMoneyShow(GetSellPrice(nCurFourNum),""," ");
		}
		if(comName=="upstep")	{ChooseButtonNextSelect(nodName,true);}
		if(comName=="downstep")	{ChooseButtonNextSelect(nodName,false);}
	break;

	case "CHANGE_CAPTAIN":
		if(comName=="activate" || comName=="click")
		{
			SetShowMode(ISHOW_MODE_COMPANION);
			SetCaptainButtonsEnable();
			SetCurrentNode("PASSENGERS");
		}
		if(comName=="upstep")	{ChooseButtonNextSelect(nodName,true);}
		if(comName=="downstep")	{ChooseButtonNextSelect(nodName,false);}
	break;
	}
}

void SetShowMode(int newMode)
{
	if(newMode==nShowMode) return;
	switch(nShowMode)
	{
	case ISHOW_MODE_VIEW:
		DisableString("ShipClass");
		DisableString("HullPoints");
		DisableString("Speed");
		DisableString("Maneuver");
		DisableString("Capacity");
		DisableString("MaxCrew");
		DisableString("MinCrew");
		DisableString("CannonsQuantity");
		DisableString("MaxCaliber");
		DisableString("ShipCost");
		DisableString("ShipName");
		SetNodeUsing("SHIPNAMETITLE",false);
		SetNodeUsing("MAINPICTURES",false);
	break;

	case ISHOW_MODE_EMPTYVIEW:
		SetNodeUsing("SHIPNAMETITLE",false);
		DisableString("ShipName");
	break;

	case ISHOW_MODE_BUY:
		SetNodeUsing("BUYCONFIRM",false);
		SetNodeUsing("OK_BUTTON",false);
		SetNodeUsing("CANCEL_BUTTON",false);
		DisableString("TradePrice");
	break;

	case ISHOW_MODE_SELL:
		SetNodeUsing("SELLCONFIRM",false);
		SetNodeUsing("OK_BUTTON",false);
		SetNodeUsing("CANCEL_BUTTON",false);
		DisableString("TradePrice");
	break;

	case ISHOW_MODE_REPAIR:
		DisableString("RepairAllCost");
		DisableString("HullPercent");
		DisableString("RepairHullCost");
		DisableString("SailsPercent");
		DisableString("RepairSailsCost");
		DisableString("ShipName");

		SetNodeUsing("SHIPNAMETITLE",false);
		SetNodeUsing("REPAIRSTRINGS",false);
		SetNodeUsing("FIXALL_BUTTON",false);
		SetNodeUsing("HULLQUANTITY",false);
		SetNodeUsing("SAILSQUANTITY",false);
		SetNodeUsing("REPAIR_OK",false);
		SetNodeUsing("RECT_FIXALL_PRICE",false);
		SetNodeUsing("RECT_HULL_PRICE",false);
		SetNodeUsing("RECT_SAILS_PRICE",false);
		SetNodeUsing("RECT_SELL_PRICE",false);
		SetNodeUsing("REPAIRIMAGES",false);
	break;

	case ISHOW_MODE_COMPANION:
		DisableString("CharacterName");
		SetNodeUsing("SHIPNAMETITLE",false);
		SetNodeUsing("SCROLLITEMS",true);
		SetNodeUsing("PASSENGERS",false);
		SetNodeUsing("SKILLINFO_BUTTON",false);
		SetNodeUsing("REMOVEC_BUTTON",false);
		SetNodeUsing("SETC_BUTTON",false);
	break;

	case ISHOW_MODE_CHOOSE:
		SetNodeUsing("BUY_BUTTON",false);
		SetNodeUsing("REPAIR_BUTTON",false);
		SetNodeUsing("SELLSHIP_BUTTON",false);
		SetNodeUsing("CHANGE_CAPTAIN",false);
	break;

	case ISHOW_MODE_SKILLS:
		DisableString("CharacterName");
		DisableString("skillLeadership");
		DisableString("skillFencing");
		DisableString("skillSailing");
		DisableString("skillAccuracy");
		DisableString("skillCannons");
		DisableString("skillGrappling");
		DisableString("skillRepair");
		DisableString("skillDefence");
		DisableString("skillCommerce");
		DisableString("skillSneak");
		SetNodeUsing("SHIPNAMETITLE",false);
		SetNodeUsing("SKILLS_IMAGES",false);
		SetNodeUsing("SCROLLITEMS",true);
		SetNodeUsing("PASSENGERS",false);
	break;
	}

	nShowMode = newMode;
	switch(nShowMode)
	{
	case ISHOW_MODE_VIEW:
		EnableString("ShipClass");
		EnableString("HullPoints");
		EnableString("Speed");
		EnableString("Maneuver");
		EnableString("Capacity");
		EnableString("MaxCrew");
		EnableString("MinCrew");
		EnableString("CannonsQuantity");
		EnableString("MaxCaliber");
		EnableString("ShipCost");
		EnableString("ShipName");
		SetNodeUsing("SHIPNAMETITLE",true);
		SetNodeUsing("MAINPICTURES",true);
	break;

	case ISHOW_MODE_EMPTYVIEW:
		SetNodeUsing("SHIPNAMETITLE",true);
		EnableString("ShipName");
	break;

	case ISHOW_MODE_BUY:
		SetNodeUsing("BUYCONFIRM",true);
		SetNodeUsing("OK_BUTTON",true);
		SetNodeUsing("CANCEL_BUTTON",true);
		EnableString("TradePrice");
	break;

	case ISHOW_MODE_SELL:
		SetNodeUsing("SELLCONFIRM",true);
		SetNodeUsing("OK_BUTTON",true);
		SetNodeUsing("CANCEL_BUTTON",true);
		EnableString("TradePrice");
	break;

	case ISHOW_MODE_REPAIR:
		EnableString("RepairAllCost");
		EnableString("HullPercent");
		EnableString("RepairHullCost");
		EnableString("SailsPercent");
		EnableString("RepairSailsCost");
		EnableString("ShipName");

		SetNodeUsing("SHIPNAMETITLE",true);
		SetNodeUsing("REPAIRSTRINGS",true);
		SetNodeUsing("FIXALL_BUTTON",true);
		SetNodeUsing("HULLQUANTITY",true);
		SetNodeUsing("SAILSQUANTITY",true);
		SetNodeUsing("REPAIR_OK",true);
		SetNodeUsing("RECT_FIXALL_PRICE",true);
		SetNodeUsing("RECT_HULL_PRICE",true);
		SetNodeUsing("RECT_SAILS_PRICE",true);
		SetNodeUsing("RECT_SELL_PRICE",true);
		SetNodeUsing("REPAIRIMAGES",true);
	break;

	case ISHOW_MODE_COMPANION:
		EnableString("CharacterName");
		SetNodeUsing("SHIPNAMETITLE",true);
		SetNodeUsing("SCROLLITEMS",false);
		SetNodeUsing("PASSENGERS",true);
		SetNodeUsing("SKILLINFO_BUTTON",true);
		SetNodeUsing("REMOVEC_BUTTON",true);
		SetNodeUsing("SETC_BUTTON",true);
	break;

	case ISHOW_MODE_CHOOSE:
		sPreviouseNode = GetCurrentNode();
		SetNodeUsing("BUY_BUTTON",true);
		SetNodeUsing("REPAIR_BUTTON",true);
		SetNodeUsing("SELLSHIP_BUTTON",true);
		SetNodeUsing("CHANGE_CAPTAIN",true);
	break;

	case ISHOW_MODE_SKILLS:
		EnableString("CharacterName");
		EnableString("skillLeadership");
		EnableString("skillFencing");
		EnableString("skillSailing");
		EnableString("skillAccuracy");
		EnableString("skillCannons");
		EnableString("skillGrappling");
		EnableString("skillRepair");
		EnableString("skillDefence");
		EnableString("skillCommerce");
		EnableString("skillSneak");
		SetNodeUsing("SHIPNAMETITLE",true);
		SetNodeUsing("SKILLS_IMAGES",true);
		SetNodeUsing("SCROLLITEMS",false);
		SetNodeUsing("PASSENGERS",true);
	break;
	}
}

void FillSScroll()
{
	nCurSScrollNum = -1;
	if(!CheckAttribute(&GameInterface,"scrollitems.current"))
		GameInterface.scrollitems.current = 0;

    string attributeName;
    string shipName;
	GameInterface.scrollitems.BadPicture2 = "interfaces\blank_ship.tga";
	GameInterface.scrollitems.ImagesGroup.t0 = "ICONS";
	GameInterface.scrollitems.ImagesGroup.t1 = "SHIPS16";
	GameInterface.scrollitems.ImagesGroup.t2 = "SHIPS1";

	aref curref;
    for(int i=0;i<GetAttributesNum(arShipList);i++)
    {
		curref = GetAttributeN(arShipList,i);
        attributeName = "pic" + (i+1);
        shipName = ShipsTypes[sti(GetAttributeValue(curref))].Name;

        GameInterface.scrollitems.(attributeName).str1 = "#"+ShipsTypes[sti(GetAttributeValue(curref))].Class;
        GameInterface.scrollitems.(attributeName).str2 = shipName;
        GameInterface.scrollitems.(attributeName).img1 = "ship back";
        GameInterface.scrollitems.(attributeName).img2 = shipName;
		GameInterface.scrollitems.(attributeName).tex1 = 0;
		GameInterface.scrollitems.(attributeName).tex2 = 1+GetShipTexture(shipName);
    }

    GameInterface.scrollitems.ListSize = i;
	GameInterface.scrollitems.NotUsed = 5;
}

void FillFScroll()
{
	nCurFScrollNum = 0;
	DeleteAttribute(&GameInterface,"passengers");
    GameInterface.passengers.current = 0;
	GameInterface.passengers.NotUsed = 5;

	GameInterface.passengers.ImagesGroup.t0 = "EMPTYFACE";
	ref mchref = GetMainCharacter();
	FillFaceList( "passengers.ImagesGroup", mchref, 0 ); // officers
	FillFaceList( "passengers.ImagesGroup", mchref, 1 ); // companions
	FillFaceList( "passengers.ImagesGroup", mchref, 2 ); // passengers

	GameInterface.passengers.BadTex1 = 0;
	GameInterface.passengers.BadPic1 = "emptyface";

	ref charRef;
	string attributeName;
	nAllPassngerQuantity = 0;
	int cn = GetPassengerFromScroll(0);
	while(cn>=0)
	{
		attributeName = "pic" + (nAllPassngerQuantity+1);
		charRef = GetCharacter(cn);
		GameInterface.passengers.(attributeName).img1 = GetFacePicName(charRef);
		GameInterface.passengers.(attributeName).tex1 = FindFaceGroupNum("passengers.ImagesGroup","FACE128_"+charRef.FaceID);
		nAllPassngerQuantity++;
		cn=GetPassengerFromScroll(nAllPassngerQuantity);
	}
	GameInterface.passengers.ListSize = nAllPassngerQuantity;
}

void FillFourImages()
{
	nCurFourNum = -1;
	if(!CheckAttribute(&GameInterface,"FourImage.current"))
		GameInterface.FourImage.current = 0;

	GameInterface.FourImage.BadTwoPicture = "interfaces\blank_ship.tga";
	GameInterface.FourImage.ImagesGroup.t0 = "ICONS";
	GameInterface.FourImage.ImagesGroup.t1 = "SHIPS16";
	GameInterface.FourImage.ImagesGroup.t2 = "SHIPS1";
	GameInterface.FourImage.ImagesGroup.t3 = "EMPTYFACE";
	ref refMainCh = GetMainCharacter();
	FillFaceList( "FourImage.ImagesGroup", refMainCh, 0 ); // officers
	FillFaceList( "FourImage.ImagesGroup", refMainCh, 1 ); // companions
	FillFaceList( "FourImage.ImagesGroup", refMainCh, 2 ); // passengers

	int i,cn,tmpShipType;
	string tmp1,tmp2,tmpStr;

    for(i=0; i<4; i++)
    {
		tmpStr = "pic"+(i+1);

		tmpShipType = SHIP_NOTUSED;
		cn = GetCompanionIndex(refMainCh,i);
		if(cn!=-1)	tmpShipType = GetCharacterShipType(GetCharacter(cn));
		GameInterface.FourImage.(tmpStr).selected = cn!=-1 || nAllPassngerQuantity>0;

		if(tmpShipType==SHIP_NOTUSED)
		{
			if(cn>=0)
			{
				GameInterface.FourImage.(tmpStr).img1 = GetFacePicName(GetCharacter(cn));
				GameInterface.FourImage.(tmpStr).tex1 = FindFaceGroupNum("FourImage.ImagesGroup","FACE128_"+Characters[cn].FaceID);
				continue;
			}
			tmp1="";
			tmp2="";
		}
		else
		{
			ref baseShip = &ShipsTypes[tmpShipType];
			tmp1 = baseShip.Class;
			tmp2 = baseShip.Name;
		}

		GameInterface.FourImage.(tmpStr).img1		= "ship back";
		GameInterface.FourImage.(tmpStr).img2		= tmp2;
		GameInterface.FourImage.(tmpStr).str1		= "#"+tmp1;
		GameInterface.FourImage.(tmpStr).str2		= tmp2;
		GameInterface.FourImage.(tmpStr).tex1		= 0;
		GameInterface.FourImage.(tmpStr).tex2		= 1+GetShipTexture(tmp2);
    }
}

int GetFourShipType(int fourIdx)
{
	int cn = GetCompanionIndex(GetMainCharacter(),fourIdx);
	if(cn<0) return SHIP_NOTUSED;
	return GetCharacterShipType(GetCharacter(cn));
}

int GetScrollShipType(int scrollIdx)
{
	if(scrollIdx<0 || scrollIdx>=GetAttributesNum(arShipList)) return SHIP_NOTUSED;
	return sti(GetAttributeValue(GetAttributeN(arShipList,scrollIdx)));
}

int GetPassengerFromScroll(int scrollIdx)
{
	ref chref;
	ref mch = GetMainCharacter();
	int q = GetPassengersQuantity(mch);

	int i,idx,cn;
	idx = 0;
	for(i=0; i<q; i++)
	{
		cn = GetPassenger(mch,i);
		if(cn>=0)
		{
			chref = GetCharacter(cn);
			if(GetRemovable(chref))
			{
				if( !CheckAttribute(chref,"prisoned") || chref.prisoned=="0" )
				{
					if( GetCharacterSkill(chref,SKILL_LEADERSHIP)>0 && GetCharacterSkill(chref,SKILL_SAILING)>0 )
					{
						if(idx==scrollIdx) return cn;
						idx++;
					}
				}
			}
		}
	}
	return -1;
}

int GetBuyPrice(int scrollIdx)
{
	return GetShipPriceByType(GetScrollShipType(scrollIdx));
}

int GetSellPrice(int fourIdx)
{
	int cn = GetCompanionIndex(GetMainCharacter(),fourIdx);
	if(cn<0) return 0;
	int st = GetCharacterShipType(GetCharacter(cn));
	int price = GetShipPriceByType(st);
	price = price - GetSailRepairCost(st,GetSailDamagePercent(fourIdx));
	price = price - GetHullRepairCost(st,GetHullDamagePercent(fourIdx));
	price /= 2;
	price = price + GetCannonsDiffPrice(GetCharacter(cn));
	return price;
}

int GetShipPriceByType(int st)
{
	if(st==SHIP_NOTUSED) return 0;
	ref shref = GetShipByType(st);
	return sti(shref.Price);
}

int GetSailDamagePercent(int fourIdx)
{
	int cn = GetCompanionIndex(GetMainCharacter(),fourIdx);
	if(cn<0) return 0;
	return 100 - MakeInt(GetSailPercent(GetCharacter(cn)));
}

int GetHullDamagePercent(int fourIdx)
{
	int cn = GetCompanionIndex(GetMainCharacter(),fourIdx);
	if(cn<0) return 0;
	return 100 - MakeInt(GetHullPercent(GetCharacter(cn)));
}

int GetSailRepairCost(int shipType,int repairPercent)
{
	int shipPrice = GetShipPriceByType(shipType);
	if(shipPrice<=0) return 0;
	int scost = (shipPrice*sailCostPercent+99)/100;
	return (scost*repairPercent+99)/100;
}

int GetHullRepairCost(int shipType,int repairPercent)
{
	int shipPrice = GetShipPriceByType(shipType);
	if(shipPrice<=0) return 0;
	int scost = (shipPrice*hullCostPercent+99)/100;
	return (scost*repairPercent+99)/100;
}

int GetCannonsDiffPrice(ref chref)
{
	int cannonsQ = GetCannonQuantity(chref);
	if(cannonsQ<=0) return 0;
	int st = GetCharacterShipType(chref);
	if(st==SHIP_NOTUSED) return 0;
	int ct = GetCaracterShipCannonsType(chref);
	int ctbase = ShipsTypes[st].Cannon;
	if(ct==ctbase) return 0;
	return cannonsQ*(GetCannonPrice(ct)-GetCannonPrice(ctbase));
}

int GetCannonPrice(int nCannonType)
{
	if(nCannonType==CANNON_TYPE_NONECANNON) return 0;
	ref rCannon = GetCannonByType(nCannonType);
	return sti(rCannon.Cost);
}

int GetMyMoney()
{
	ref mychref = GetMainCharacter();
	return sti(mychref.Money);
}

void DoSellShip()
{
	int cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum);
	if(cn<0) return;
	ref chref = GetCharacter(cn);
	int sellPrice = GetSellPrice(nCurFourNum);

	AddMoneyToCharacter(GetMainCharacter(),sellPrice);
	GameInterface.strings.Money = MakeMoneyShow(sti(Characters[GetMainCharacterIndex()].money),""," ");
	DeleteAttribute(chref,"ship.sails");
	DeleteAttribute(chref,"ship.blots");
	chref.ship.type = SHIP_NOTUSED;
}

void DoBuyShip()
{
	int cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum);
	if(cn<0) return;

	int st = GetScrollShipType(nCurSScrollNum);
	int money = sti(Characters[GetMainCharacterIndex()].money);
	int sellPrice = GetSellPrice(nCurFourNum);
	int buyPrice = GetShipPriceByType(st);

	if(money+sellPrice < buyPrice) return;

	DoSellShip();

	AddMoneyToCharacter(GetMainCharacter(),-buyPrice);
	GameInterface.strings.Money = MakeMoneyShow(sti(Characters[GetMainCharacterIndex()].money),""," ");

	ref chref = GetCharacter(cn);
	if(st==SHIP_NOTUSED) return;

	ref brefShip = GetShipByType(st);

	chref.ship.type = st;
	DeleteAttribute(chref,"ship.sails");
	DeleteAttribute(chref,"ship.blots");
	chref.ship.sp = brefShip.SP;
	chref.ship.hp = brefShip.HP;
	chref.ship.Cannons.Type = brefShip.Cannon;
}

void UpdateFourImages()
{
/*	DeleteAttribute(&GameInterface,"FourImage");
	GameInterface.FourImage.current = nCurFourNum;
    FillFourImages();
	SendMessage(&GameInterface,"lsl", MSG_INTERFACE_FOURIMAGE_CHANGE, "SHIPSLIST", -1);
*/
	ref refMainCh = GetMainCharacter();

	int i,cn,tmpShipType;
	string tmp1,tmp2,tmpStr;

    for(i=0; i<4; i++)
    {
		tmpStr = "pic"+(i+1);
		DeleteAttribute(&GameInterface,"FourImage."+tmpStr);

		tmpShipType = SHIP_NOTUSED;
		cn = GetCompanionIndex(refMainCh,i);
		if(cn!=-1)	tmpShipType = GetCharacterShipType(GetCharacter(cn));
		GameInterface.FourImage.(tmpStr).selected = cn!=-1 || nAllPassngerQuantity>0;

		if(tmpShipType==SHIP_NOTUSED)
		{
			if(cn>=0)
			{
				GameInterface.FourImage.(tmpStr).img1 = GetFacePicName(GetCharacter(cn));
				GameInterface.FourImage.(tmpStr).tex1 = FindFaceGroupNum("FourImage.ImagesGroup","FACE128_"+Characters[cn].FaceID);
				continue;
			}
			tmp1="";
			tmp2="";
		}
		else
		{
			ref baseShip = &ShipsTypes[tmpShipType];
			tmp1 = baseShip.Class;
			tmp2 = baseShip.Name;
		}

		GameInterface.FourImage.(tmpStr).img1		= "ship back";
		GameInterface.FourImage.(tmpStr).img2		= tmp2;
		GameInterface.FourImage.(tmpStr).str1		= "#"+tmp1;
		GameInterface.FourImage.(tmpStr).str2		= tmp2;
		GameInterface.FourImage.(tmpStr).tex1		= 0;
		GameInterface.FourImage.(tmpStr).tex2		= 1+GetShipTexture(tmp2);
    }

	SendMessage(&GameInterface,"lsl", MSG_INTERFACE_FOURIMAGE_CHANGE, "SHIPSLIST", -1);
}

void UpdateShipScroll()
{
	DeleteAttribute(&GameInterface,"scrollitems");
	GameInterface.scrollitems.current = nCurSScrollNum;
    FillSScroll();
    SendMessage(&GameInterface,"lsl",MSG_INTERFACE_SCROLL_CHANGE,"SCROLLITEMS",-1);
}

void UpdateFaceScroll()
{
	// Delete old attributes
	int charQuantity = sti(GameInterface.passengers.ListSize);
	for(int i=0; i<charQuantity; i++)
	{
		attributeName = "passengers.pic" + (i+1);
		DeleteAttribute(&GameInterface, attributeName);
	}

	ref charRef;
	string attributeName;
	nAllPassngerQuantity = 0;
	int cn = GetPassengerFromScroll(0);
	while(cn>=0)
	{
		attributeName = "pic" + (nAllPassngerQuantity+1);
		charRef = GetCharacter(cn);
		GameInterface.passengers.(attributeName).img1 = GetFacePicName(charRef);
		GameInterface.passengers.(attributeName).tex1 = FindFaceGroupNum("passengers.ImagesGroup","FACE128_"+charRef.FaceID);
		nAllPassngerQuantity++;
		cn=GetPassengerFromScroll(nAllPassngerQuantity);
	}
	GameInterface.passengers.ListSize = nAllPassngerQuantity;
	if( nCurSScrollNum >= nAllPassngerQuantity ) nCurSScrollNum = nAllPassngerQuantity;
	SendMessage(&GameInterface,"lsl",MSG_INTERFACE_SCROLL_CHANGE,"PASSENGERS",-1);
}

void UpdateCompanionCharacter()
{
	int cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum);
	int nn = GetPassengerFromScroll(nCurFScrollNum);
	if(nn==cn) return;
	if(nn>=0 && GetRemovable(GetCharacter(nn))==false) return;

	if(nn<0)	DoSellShip();

	if( nn>=0 && cn>=0 )	ExchangeCharacterShip(GetCharacter(nn),GetCharacter(cn));

	if(nn>=0) RemovePassenger(GetMainCharacter(),GetCharacter(nn));
	SetCompanionIndex(GetMainCharacter(),nCurFourNum,nn);
	if(cn>=0) AddPassenger(GetMainCharacter(),GetCharacter(cn),false);

	UpdateFaceScroll();
	UpdateFourImages();
}

void FireCaptain()
{
	int cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum);
	if(cn<0) return;
	DoSellShip();

	SetCompanionIndex(GetMainCharacter(),nCurFourNum,-1);
	AddPassenger(GetMainCharacter(),GetCharacter(cn),false);

	UpdateFaceScroll();
	UpdateFourImages();
}

void DoShipParametersClamp()
{
	ref mchref = GetMainCharacter();
	ref chref;
	int i,cn,st,pq;

	for(i=0; i<4; i++)
	{
		cn = GetCompanionIndex(mchref,i);
		if(cn>=0)
		{
			chref = GetCharacter(cn);
			st = GetCharacterShipType(chref);
			if(st==SHIP_NOTUSED)
			{
				ClampShipToEmpty(chref);
				if(i>0)
				{
					SetCompanionIndex(mchref,i,-1);
					AddPassenger(mchref,chref,false);
				}
			}
			else {
				ClampShipToType(chref);
			}
		}
	}

	pq = GetPassengersQuantity(mchref);
	for(i=0; i<pq; i++)
	{
		cn = GetPassenger(mchref,i);
		if(cn>=0) {
			ClampShipToEmpty(GetCharacter(cn));
		}
	}
}

void ClampShipToEmpty(ref chref)
{
	string sname = "";
	if(CheckAttribute(chref,"ship.name")) {
		sname = chref.ship.name;
	}
	if( sti(chref.index)==GetMainCharacterIndex() )
	{
		if( CheckAttribute(chref,"location.from_sea") ) {
			if( !CheckAttribute(chref,"location.old_from_sea") ) {
				chref.location.old_from_sea = chref.location.from_sea;
			}
			chref.location.from_sea = "";
		}
	}
	DeleteAttribute(chref,"ship");
	chref.ship.type = SHIP_NOTUSED;
	if(sname=="") {
		SetRandomNameToShip(chref);
	}
	else {
		chref.ship.name = sname;
	}
}

void ClampShipToType(ref chref)
{
	int i;
	int st = GetCharacterShipType(chref);
	ref base_ship = GetShipByType(st);
	int mcrew = sti(base_ship.MaxCrew);

	if(GetCrewQuantity(chref)>mcrew)
	{
		chref.Ship.Crew.Quantity = mcrew;
	}

	if(!CheckAttribute(chref,"Ship.Name"))
	{
		SetRandomNameToShip(chref);
	}

	int gq[GOODS_QUANTITY];
	string goods_id;

	chref.Ship.Pos.x = 0;
	chref.Ship.Pos.z = 0;
	chref.Ship.Ang = "";
	chref.Ship.Cannons.Borts = "";
	chref.Ship.Cannons.Charge.Type = GOOD_BOMBS;
	if (!CheckAttribute(chref,"Ship.Cannons.Type")) { chref.Ship.Cannons.Type = MakeInt(base_ship.Cannon); }
	if (!CheckAttribute(chref,"Ship.Crew.Morale"))	{ chref.Ship.Crew.Morale = 45;	}
	if (!CheckAttribute(chref,"Ship.Crew.Quantity")) { chref.Ship.Crew.Quantity = base_ship.MaxCrew; }

	// уберем все товары
	for(i=0; i<GOODS_QUANTITY; i++)
	{
		goods_id = Goods[i].name;
		if( CheckAttribute(chref,"Ship.Cargo.Goods."+goods_id) )
		{
			gq[i] = sti(chref.Ship.Cargo.Goods.(goods_id));
		}
		else
		{
			gq[i] = 0;
		}
		chref.Ship.Cargo.Goods.(goods_id) = 0;
	}
	chref.Ship.Cargo.Load = 0;

	// установим все товары
	int loadMax = sti(base_ship.Capacity);
	int loadCur = 0;
	int loadAdd;
	string tmpStr;
	for(i=0; i<GOODS_QUANTITY; i++)
	{
		loadAdd = GetGoodWeightByType(i,gq[i]);
		tmpStr = Goods[i].name;
		if(loadAdd > loadMax-loadCur) {
			gq[i] = GetGoodQuantityByWeight(i,loadMax-loadCur);
			loadAdd = GetGoodWeightByType(i,gq[i]);
		}
		chref.ship.cargo.goods.(tmpStr) = gq[i];
		loadCur += loadAdd;
	}

	if( sti(chref.index)==GetMainCharacterIndex() )
	{
		if( CheckAttribute(chref,"location.old_from_sea") ) {
			chref.location.from_sea = chref.location.old_from_sea;
			DeleteAttribute(chref,"location.old_from_sea");
		}
	}
}

void DoSailRepairToPercent(ref chref,int toPerc)
{
	ref mchref = GetMainCharacter();

	int cursp = MakeInt(GetSailPercent(chref));
	if(cursp>=toPerc) return;

	int sailRepairCost = GetSailRepairCost(GetCharacterShipType(chref),toPerc-cursp);
	int nMyMoney = GetMyMoney();
	while(nMyMoney<sailRepairCost)
	{
		toPerc--;
		if(cursp>=toPerc) return;
		sailRepairCost = GetSailRepairCost(GetCharacterShipType(chref),toPerc-cursp);
	}

	AddMoneyToCharacter(mchref,-sailRepairCost);
	GameInterface.strings.Money = MakeMoneyShow(GetMyMoney(),""," ");

	if(toPerc>=100)
	{
		chref.ship.sp = GetCharacterShipSP(chref);
		DeleteAttribute(chref,"ship.sails");
		DeleteAttribute(chref,"ship.masts");
		return;
	}

	float fsail = MakeFloat(toPerc) - GetSailPercent(chref);
	ProcessSailRepair(chref,fsail);
	chref.ship.sp = CalculateShipSP(chref);
}

void DoHullRepairToPercent(ref chref,int toPerc)
{
	ref mchref = GetMainCharacter();

	int curhp = MakeInt(GetHullPercent(chref));
	if(curhp>=toPerc) return;

	int hullRepairCost = GetHullRepairCost(GetCharacterShipType(chref),toPerc-curhp);
	int nMyMoney = GetMyMoney();
	while(nMyMoney<hullRepairCost)
	{
		toPerc--;
		if(curhp>=toPerc) return;
		hullRepairCost = GetHullRepairCost(GetCharacterShipType(chref),toPerc-curhp);
	}

	AddMoneyToCharacter(mchref,-hullRepairCost);
	GameInterface.strings.Money = MakeMoneyShow(GetMyMoney(),""," ");

	if(toPerc==100)
	{
		chref.ship.hp = GetCharacterShipHP(chref);
		DeleteAttribute(chref,"ship.blots");
		return;
	}

	float fhull = MakeFloat(toPerc) - GetHullPercent(chref);
	ProcessHullRepair(chref,fhull);
	chref.ship.hp = GetCharacterShipHP(chref)*toPerc/100.0+0.01;
}

void ChangeHullRepair(int delta)
{
	int cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum);
	if(cn<0) return;

	int newHP = nhpRepair + delta;
	if(newHP>100)
	{
		newHP = 100;
	}

	int curHP = MakeInt(GetHullPercent(GetCharacter(cn)));
	if(newHP<curHP)
	{
		newHP = curHP;
	}

	int price = GetHullRepairCost(GetFourShipType(nCurFourNum),newHP-curHP);
	while(GetMyMoney()<price)
	{
		newHP--;
		price = GetHullRepairCost(GetFourShipType(nCurFourNum),newHP-curHP);
	}

	if(newHP==nhpRepair) return;
	nhpRepair = newHP;

    GameInterface.strings.HullPercent = nhpRepair + "%";
    GameInterface.strings.RepairHullCost = price;
}

void ChangeSailRepair(int delta)
{
	int cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum);
	if(cn<0) return;

	int newSP = nspRepair + delta;
	if(newSP>100)
	{
		newSP = 100;
	}

	int curSP = MakeInt(GetSailPercent(GetCharacter(cn)));
	if(newSP<curSP)
	{
		newSP = curSP;
	}

	int price = GetSailRepairCost(GetFourShipType(nCurFourNum),newSP-curSP);
	while(GetMyMoney()<price)
	{
		newSP--;
		price = GetSailRepairCost(GetFourShipType(nCurFourNum),newSP-curSP);
	}

	if(newSP==nspRepair) return;
	nspRepair = newSP;

    GameInterface.strings.SailsPercent = nspRepair + "%";
    GameInterface.strings.RepairSailsCost = price;
}

void EnableChooseButtons()
{
	SetSelectable( "BUY_BUTTON", IsEnableBuyShip() );
	SetSelectable( "REPAIR_BUTTON", IsEnableRepairShip() );
	SetSelectable( "SELLSHIP_BUTTON", IsEnableSellShip() );
	SetSelectable( "CHANGE_CAPTAIN", IsEnableChangeCaptain() );
}

string GetNextChoose(string curChoose, bool bUpDirection)
{
	switch(curChoose)
	{
	case "BUY_BUTTON":
		if(bUpDirection)	{return "";}
		else	{return "REPAIR_BUTTON";}
	break;
	case "REPAIR_BUTTON":
		if(bUpDirection)	{return "BUY_BUTTON";}
		else	{return "SELLSHIP_BUTTON";}
	break;
	case "SELLSHIP_BUTTON":
		if(bUpDirection)	{return "REPAIR_BUTTON";}
		else	{return "CHANGE_CAPTAIN";}
	break;
	case "CHANGE_CAPTAIN":
		if(bUpDirection)	{return "SELLSHIP_BUTTON";}
		else	{return "";}
	break;
	}
}

void ChooseButtonTopSelect()
{
	string nextNode = "BUY_BUTTON";
	while(nextNode!="")
	{
		if( GetSelectable(nextNode) )
		{
			SetCurrentNode(nextNode);
			return;
		}
		nextNode = GetNextChoose(nextNode, false);
	}
}

void ChooseButtonNextSelect(string chooseBtnName, bool bUpDirection)
{
	string nextNode = GetNextChoose(chooseBtnName, bUpDirection);
	while(nextNode!="")
	{
		if( GetSelectable(nextNode) )
		{
			SetCurrentNode(nextNode);
			return;
		}
		nextNode = GetNextChoose(nextNode, bUpDirection);
	}
}

bool IsEnableBuyShip()
{
	int cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum);
	if(cn<0) return false;
	ref chref = GetCharacter(cn);
	if( !GetRemovable(chref) ) return false;

	return GetShipRemovable(chref);
}

bool IsEnableSellShip()
{
	int cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum);
	if(cn<0) return false;
	ref chref = GetCharacter(cn);
	if( GetCharacterShipType(chref)==SHIP_NOTUSED ) return false;
	if( !GetRemovable(chref) ) return false;

	return GetShipRemovable(chref);
}

bool IsEnableRepairShip()
{
	int cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum);
	if(cn<0) return false;
	ref chref = GetCharacter(cn);
	if( GetCharacterShipType(chref)==SHIP_NOTUSED ) return false;
	if( GetSailPercent(chref)>=100.0 && GetHullPercent(chref)>=100.0 ) return false;
	return true;
}

bool IsEnableChangeCaptain()
{
	if(nCurFourNum<1) return false;
	int cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum);
	if(cn>=0)
	{
		ref chref = GetCharacter(cn);
		if( !GetRemovable(chref) ) return false;
	}
	return true;
}

bool IsMoneyForBuyEnable()
{
	int st = GetScrollShipType(nCurSScrollNum);
	int money = sti(Characters[GetMainCharacterIndex()].money);
	int sellPrice = GetSellPrice(nCurFourNum);
	int buyPrice = GetShipPriceByType(st);
	if(money+sellPrice < buyPrice) return false;
	return true;
}

void SetCaptainButtonsEnable()
{
	bool bRemoveEnable = true;
	bool bSetEnable = true;

	int cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum);
	if(cn<0 || !GetRemovable(GetCharacter(cn)) )	bRemoveEnable = false;

	int nn = GetPassengerFromScroll(nCurFScrollNum);
	if(nn==cn)	bSetEnable = false;
	if( nn>=0 && !GetRemovable(GetCharacter(nn)) )	bSetEnable = false;
	if( nn<0 )	bSetEnable = false;

	SetSelectable("SKILLINFO_BUTTON", nChrIdxForInfo>=0);
	SetSelectable("REMOVEC_BUTTON", bRemoveEnable);
	SetSelectable("SETC_BUTTON", bSetEnable);
}

void SelectCaptainButton()
{
	if( GetSelectable("SKILLINFO_BUTTON") ) {SetCurrentNode("SKILLINFO_BUTTON");}
	else
	{
		if( GetSelectable("REMOVEC_BUTTON") ) {SetCurrentNode("REMOVEC_BUTTON");}
		else
		{
			if( GetSelectable("SETC_BUTTON") ) {SetCurrentNode("SETC_BUTTON");}
			else {SetCurrentNode("PASSENGERS");}
		}
	}
}

string GetNextCaptainButton(string curNode, bool bUpDirection)
{
	switch(curNode)
	{
	case "PASSENGERS":
		if(bUpDirection) {return "";}
		else {return "SKILLINFO_BUTTON";}
	break;

	case "SKILLINFO_BUTTON":
		if(bUpDirection) {return "PASSENGERS";}
		else {return "REMOVEC_BUTTON";}
	break;

	case "REMOVEC_BUTTON":
		if(bUpDirection) {return "SKILLINFO_BUTTON";}
		else {return "SETC_BUTTON";}
	break;

	case "SETC_BUTTON":
		if(bUpDirection) {return "REMOVEC_BUTTON";}
		else {return "";}
	break;
	}
	return "";
}

void SetNextCaptainButton(string curNode, bool bUpDirection)
{
	string nextNode = GetNextCaptainButton(curNode, bUpDirection);
	while(nextNode!="")
	{
		if( GetSelectable(nextNode) )
		{
			SetCurrentNode(nextNode);
			return;
		}
		nextNode = GetNextCaptainButton(nextNode, bUpDirection);
	}
	SetCurrentNode(curNode);
}

void SetSkillData()
{
	if(nChrIdxForInfo<0)
	{
		GameInterface.strings.CharacterName = "";
		GameInterface.strings.skillLeadership = "0";
		GameInterface.strings.skillFencing = "0";
		GameInterface.strings.skillSailing = "0";
		GameInterface.strings.skillAccuracy = "0";
		GameInterface.strings.skillCannons = "0";
		GameInterface.strings.skillGrappling = "0";
		GameInterface.strings.skillRepair = "0";
		GameInterface.strings.skillDefence = "0";
		GameInterface.strings.skillCommerce = "0";
		GameInterface.strings.skillSneak = "0";
		return;
	}
	ref chref = GetCharacter(nChrIdxForInfo);
	GameInterface.strings.CharacterName = GetCharacterFullName(chref.id);
	GameInterface.strings.skillLeadership = GetCharacterSkill(chref,SKILL_LEADERSHIP);
	GameInterface.strings.skillFencing = GetCharacterSkill(chref,SKILL_FENCING);
	GameInterface.strings.skillSailing = GetCharacterSkill(chref,SKILL_SAILING);
	GameInterface.strings.skillAccuracy = GetCharacterSkill(chref,SKILL_ACCURACY);
	GameInterface.strings.skillCannons = GetCharacterSkill(chref,SKILL_CANNONS);
	GameInterface.strings.skillGrappling = GetCharacterSkill(chref,SKILL_GRAPPLING);
	GameInterface.strings.skillRepair = GetCharacterSkill(chref,SKILL_REPAIR);
	GameInterface.strings.skillDefence = GetCharacterSkill(chref,SKILL_DEFENCE);
	GameInterface.strings.skillCommerce = GetCharacterSkill(chref,SKILL_COMMERCE);
	GameInterface.strings.skillSneak = GetCharacterSkill(chref,SKILL_SNEAK);
}

void SetCharacterToInfoCharacter(int nInfoChrIdx)
{
	nChrIdxForInfo = nInfoChrIdx;
	if(nInfoChrIdx<0)
	{
		GameInterface.strings.CharacterName = "";
		return;
	}

	GameInterface.strings.CharacterName = GetCharacterFullName(Characters[nInfoChrIdx].id);
}

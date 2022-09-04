#include "rumour_data.c"

#define Few_Quest_Sum		400	
#define Some_Quest_Sum		2000
#define Medium_Quest_Sum	4000
#define Large_Quest_Sum		6000
#define Huge_Quest_Sum		10000
#define QUEST_COUNTER 		3

string FRA_COLONY = "Falaise De Fleur";
string SPA_COLONY = "Isla Muelle";
string POR_COLONY = "Conceicao";
string HOL_COLONY = "Douwesen";
string RED_COLONY = "Redmond";
string OX_COLONY = "Oxbay";
string GREEN_COLONY = "Greenford";


object Address_Form;

/*string LAi_FindRandomLocator(string group)
{
	if(IsEntity(loadedLocation) != true) return "";
	string at = "locators." + group;
	if(CheckAttribute(loadedLocation, at) == 0) return "";
	aref grp;
	makearef(grp, loadedLocation.(at));
	int num = GetAttributesNum(grp);
	if(num <= 0) return "";
	num = rand(num - 1);
	return GetAttributeName(GetAttributeN(grp, num));
}*/


void Quest_Init()
{
	SetRumourDefaults();

	FRA_COLONY = GlobalStringConvert("Falaise De Fleur");
	SPA_COLONY = GlobalStringConvert("Isla Muelle");
	POR_COLONY = GlobalStringConvert("Conceicao");
	HOL_COLONY = GlobalStringConvert("Douwesen");
	RED_COLONY = GlobalStringConvert("Redmond");
	OX_COLONY = GlobalStringConvert("Oxbay");
	GREEN_COLONY = GlobalStringConvert("Greenford");
}

void Set_inDialog_Attributes()
{ 
	ref The_Character_is;

	The_Character_is = GetMainCharacter();

	switch (The_Character_is.id)
	{	
		case "Blaze":
			
			Address_Form.Spa = GlobalStringConvert("Address_Form_Spa");
			Address_Form.Fra = GlobalStringConvert("Address_Form_Fra");
			Address_Form.Eng = GlobalStringConvert("Address_Form_Eng");
			Address_Form.Por = GlobalStringConvert("Address_Form_Por");
			Address_Form.Hol = GlobalStringConvert("Address_Form_Hol");
			return;
		break;

		case "Danielle":

			Address_Form.Spa = "Senorita";
			Address_Form.Fra = "Mademoiselle";
			Address_Form.Eng = "Miss";
			Address_Form.Por = "Senhorita";
			Address_Form.Hol = "Juffrouw";
			return;
		break;
	}
	trace("ERROR: Player Character is not defined - can't select address form");
}

string RandSwear()
{	
	int RandS = Rand(7);
	
	switch (RandS)
	{
		case 0:

			return GlobalStringConvert("Swear_1") + " ";

		break;

		case 1:

			return GlobalStringConvert("Swear_2") + " ";

		break;

		case 2:

			return GlobalStringConvert("Swear_3") + " ";

		break;

		case 3:

			return GlobalStringConvert("Swear_4") + " ";

		break;

		case 4:

			return GlobalStringConvert("Swear_5") + " ";

		break;

		case 5:

			return GlobalStringConvert("Swear_6") + " ";

		break;

		case 6:

			return GlobalStringConvert("Swear_7") + " ";

		break;

		case 7:

			return GlobalStringConvert("Swear_8") + " ";

		break;

		case 8:

			return GlobalStringConvert("Swear_9") + " ";

		break;

		case 9:

			return GlobalStringConvert("Swear_10") + " ";

		break;
	}
	return "";
}


int RandSum(string Amount)
{
	int Sum;

	switch(Amount)
	{
		case "Few":

			Sum = Few_Quest_Sum + Rand(Few_Quest_Sum/20)*10;
			//trace("Generated sum is: " + Sum);
			return Sum;

		break;


		case "Some":

			Sum = Some_Quest_Sum + Rand(Some_Quest_Sum/200)*100;
			//trace("Generated sum is: " + Sum);
			return Sum;

		break;

		case "Medium":

			Sum = Medium_Quest_Sum + Rand(Medium_Quest_Sum/200)*100;
			//trace("Generated sum is: " + Sum);
			return Sum;

		break;

		case "Large":

			Sum = Large_Quest_Sum + Rand(Large_Quest_Sum/200)*100;
			//trace("Generated sum is: " + Sum);
			return Sum;

		break;

		case "Huge":

			Sum = Huge_Quest_Sum + Rand(Huge_Quest_Sum/1000+1)*500;
			//trace("Generated sum is: " + Sum);
			return Sum;

		break;
	}
return 0;
}


string LinkRandPhrase (string Var1, string Var2, string Var3)
{
	int RandP;
	RandP = Rand(2);
	//Trace("AAA: " + RandP);
	//Trace("AAA1: " + Var1);
	//Trace("AAA2: " + Var2);
	//Trace("AAA3: " + Var3);
	switch(RandP)
	{
		case 0:

			return /*"First phrase selected" + */ Var1;

		break;

		case 1:

			return /*"Second phrase selected" + */Var2;

		break;

		case 2:

			return /*"Third phrase selected" + */Var3;

		break;
	}
	return "ERROR";
}



string RandPhrase (string Var1, string Var2, string Var3, ref Diag, string Sound1, string sound2, string sound3)
{
	int RandP;
	RandP = Rand(2);
	//Trace("AAA: " + RandP);
	//Trace("AAA1: " + Var1);
	//Trace("AAA2: " + Var2);
	//Trace("AAA3: " + Var3);
	DeleteAttribute(Diag, "snd1");
	DeleteAttribute(Diag, "snd2");
	DeleteAttribute(Diag, "snd3");
	switch(RandP)
	{
		case 0:

			diag.snd = sound1;			
			return /*"First phrase selected" + */ Var1;

		break;

		case 1:

			diag.snd = sound2;
			return /*"Second phrase selected" + */Var2;

		break;

		case 2:

			diag.snd = sound3;
			return /*"Third phrase selected" + */Var3;

		break;
	}
	return "ERROR";
}

string PCharPhrase (string Var1, string Var2)
{	
	ref PlayerCharacter = GetMainCharacter();
 
	switch(PlayerCharacter.id)
	{
		case "Blaze":

			return Var1;

		break;

		case "Danielle":
				
			return Var2;

		break;
	}
	return "___Player Character is not defined - can't select character phrase___";
}

string SelectRumour()
{
	int Rumour_Index;
	ref CurrentRumour;
	Rumour_Index = rand(MAX_RUMOURS - 1);
	//trace (Rumour[0].text);
	//trace (Rumour[0].state);
	//trace("Selected Rumour Index: " + Rumour_Index);
	for(Rumour_Index;Rumour_Index<MAX_RUMOURS; Rumour_Index++)
	{	
		makeref(CurrentRumour, Rumour[Rumour_Index]);
		if(CurrentRumour.state == "active")
		{	
			
			return CurrentRumour.text;
		}
	}
	return Rumour[0].text;
		
}


string SelectFraRumour()
{
	int Rumour_Index;
	ref CurrentRumour;
	Rumour_Index = rand(MAX_RUMOURS - 1);

	for(Rumour_Index; Rumour_Index<MAX_RUMOURS; Rumour_Index++)
	{	
		makeref (CurrentRumour, Rumour[Rumour_Index]);
		if(CurrentRumour.state == "active")
		{
			if(CurrentRumour.country == "fra")
			{
				return CurrentRumour.text;
			}
		}
	}
	return Rumour[0].text;
		
}

string PCharRepPhrase (string Var1, string Var2)
{	
	ref pchar = GetMainCharacter();

	if(makeint(pchar.reputation) < 41)
	{
		return Var2;
	}
	else
	{
		return Var1;
	}
}

void Alchogol (string ncharID)
{
	ref PChar;
	PChar = GetMainCharacter();

	switch(pchar.location)
	{
		case "Redmond_tavern":
			if (characters[GetCharacterIndex(ncharID)].location.locator == "sit1")		
			{
				DoQuestReloadToLocation("redmond_tavern", "Sit", "Sit9", "alc2");
			}
			if (characters[GetCharacterIndex(ncharID)].location.locator == "sit3")		
			{
				DoQuestReloadToLocation("redmond_tavern", "Sit", "Sit2", "alc2");
			}
		break;

		case "Oxbay_tavern":
			if (characters[GetCharacterIndex(ncharID)].location.locator == "sit1")		
			{
				DoQuestReloadToLocation("Oxbay_tavern", "Sit", "Sit9", "alc2");
			}
			if (characters[GetCharacterIndex(ncharID)].location.locator == "sit3")		
			{
				DoQuestReloadToLocation("Oxbay_tavern", "Sit", "Sit2", "alc2");
			}
		break;

		case "Greenford_tavern":
			if (characters[GetCharacterIndex(ncharID)].location.locator == "sit5")		
			{
				DoQuestReloadToLocation("Greenford_tavern", "Sit", "Sit4", "alc2");
			}
			if (characters[GetCharacterIndex(ncharID)].location.locator == "sit1")		
			{
				DoQuestReloadToLocation("Greenford_tavern", "Sit", "Sit2", "alc2");
			}	
		break;

		case "Falaise_De_Fleur_tavern":
					
		break;

		case "Muelle_tavern":
			if (characters[GetCharacterIndex(ncharID)].location.locator == "sit1")		
			{
				DoQuestReloadToLocation("Muelle_tavern", "Sit", "Sit2", "alc2");
			}
			if (characters[GetCharacterIndex(ncharID)].location.locator == "sit7")		
			{
				DoQuestReloadToLocation("Muelle_tavern", "Sit", "Sit3", "alc2");
			}			
		break;

		case "Douwesen_tavern":
			if (characters[GetCharacterIndex(ncharID)].location.locator == "sit1")		
			{
				DoQuestReloadToLocation("Douwesen_tavern", "Sit", "Sit2", "alc2");
			}
			if (characters[GetCharacterIndex(ncharID)].location.locator == "sit7")		
			{
				DoQuestReloadToLocation("Douwesen_tavern", "Sit", "Sit3", "alc2");
			}		
		break;

		case "Pirate_tavern":
			if (characters[GetCharacterIndex(ncharID)].location.locator == "sit1")		
			{
				DoQuestReloadToLocation("Conceicao_tavern", "Sit", "Sit2", "alc2");
			}
			if (characters[GetCharacterIndex(ncharID)].location.locator == "sit4")		
			{
				DoQuestReloadToLocation("Conceicao_tavern", "Sit", "Sit3", "alc2");
			}		
		break;

		case "Conceicao_tavern":
			if (characters[GetCharacterIndex(ncharID)].location.locator == "sit1")		
			{
				DoQuestReloadToLocation("Conceicao_tavern", "Sit", "Sit2", "alc2");
			}
			if (characters[GetCharacterIndex(ncharID)].location.locator == "sit7")		
			{
				DoQuestReloadToLocation("Conceicao_tavern", "Sit", "Sit3", "alc2");
			}
		break;

		case "Smugglers_tavern":
			if (characters[GetCharacterIndex(ncharID)].location.locator == "sit5")		
			{
				DoQuestReloadToLocation("Conceicao_tavern", "Sit", "Sit6", "alc2");
			}
			if (characters[GetCharacterIndex(ncharID)].location.locator == "sit4")		
			{
				DoQuestReloadToLocation("Conceicao_tavern", "Sit", "Sit3", "alc2");
			}	
		break;

		case "QC_tavern":
			if (characters[GetCharacterIndex(ncharID)].location.locator == "sit1")		
			{
				DoQuestReloadToLocation("Conceicao_tavern", "Sit", "Sit2", "alc2");
			}
			if (characters[GetCharacterIndex(ncharID)].location.locator == "sit3")		
			{
				DoQuestReloadToLocation("Conceicao_tavern", "Sit", "Sit7", "alc2");
			}		
		break;
	}
}

void PlaceSmugglersOnShore(string LocationId)
{
	ref Smuggler, player;
	int RandCounter;

	player = GetMainCharacter();

	string Models[20];
	Models[0] = "man1";
	Models[1] = "man1_1";
	Models[2] = "man1_2";
	Models[3] = "old_man1";
	Models[4] = "old_man2";
	Models[5] = "sailor1";
	Models[6] = "sailor2";
	Models[7] = "sailor3";
	Models[8] = "sailor4";
	Models[9] = "chelovek";
	Models[10] = "chelovek1";
	Models[11] = "man5_1";
	Models[12] = "bocman3";
	Models[13] = "bocman4";
	Models[14] = "sailor5";
	Models[15] = "Corsair1_2";
	Models[16] = "korsar";
	Models[17] = "Korsar1";
	Models[18] = "Black_Corsair";
	Models[19] = "Sailor6";

	//Trace("Перемещаю персонажей в локацию " + LocationID);

	Smuggler = CharacterFromId("Rand_Smug01");
	LAi_SetCurHPMax(CharacterFromId("Rand_Smug01"));
	Smuggler.model = Models[Rand(19)];
	Smuggler.Headmodel = "h_" + smuggler.model;
	Facemaker(Smuggler);

	LAi_SetWarriorTypeNoGroup(CharacterFromId("Rand_Smug01"));
	LAi_warrior_DialogEnable(CharacterFromId("Rand_Smug01"), true);
	LAi_warrior_SetStay(CharacterFromId("Rand_Smug01"), true);

	CalculateAppropriateSkills(Smuggler);	
	
	LAi_group_MoveCharacter(Smuggler, "Smugglers");
	ChangeCharacterAddressGroup(Smuggler,LocationID,"Smugglers","Smuggler01");

	Smuggler = CharacterFromId("Rand_Smug02");
	LAi_SetCurHPMax(CharacterFromId("Rand_Smug02"));
	Smuggler.model = Models[Rand(19)];
	Smuggler.Headmodel = "h_" + smuggler.model;
	Facemaker(Smuggler);

	LAi_SetWarriorTypeNoGroup(CharacterFromId("Rand_Smug02"));
	LAi_warrior_DialogEnable(CharacterFromId("Rand_Smug02"), true);
	LAi_warrior_SetStay(CharacterFromId("Rand_Smug02"), true);

	CalculateAppropriateSkills(Smuggler);

	LAi_group_MoveCharacter(Smuggler, "Smugglers");
	ChangeCharacterAddressGroup(Smuggler,LocationID,"Smugglers","Smuggler02");

	Smuggler = CharacterFromId("Rand_Smug03");
	LAi_SetCurHPMax(CharacterFromId("Rand_Smug03"));
	Smuggler.model = Models[Rand(19)];
	Smuggler.Headmodel = "h_" + smuggler.model;
	Facemaker(Smuggler);

	LAi_SetWarriorTypeNoGroup(CharacterFromId("Rand_Smug03"));
	LAi_warrior_DialogEnable(CharacterFromId("Rand_Smug03"), true);
	LAi_warrior_SetStay(CharacterFromId("Rand_Smug03"), true);

	CalculateAppropriateSkills(Smuggler);	

	LAi_group_MoveCharacter(Smuggler, "Smugglers");

	ChangeCharacterAddressGroup(Smuggler,LocationID,"Smugglers","Smuggler03");
	AddGeometryToLocation(LocationID, "smg");

	LAi_group_SetRelation(PLAYER_GROUP, "Smugglers", LAI_GROUP_NEITRAL);
	LAi_group_SetRelation("CoastalGuards", "Smugglers", LAI_GROUP_NEITRAL);

	Player.quest.Rand_Smuggling.win_condition.l1 = "Timer";
	Player.quest.Rand_Smuggling.win_condition.l1.date.day = GetAddingDataDay(0,0,3);
	Player.quest.Rand_Smuggling.win_condition.l1.date.month = GetAddingDataMonth(0,0,3);
	Player.quest.Rand_Smuggling.win_condition.l1.date.year = GetAddingDataYear(0,0,3);
	Player.quest.Rand_Smuggling.win_condition = "Rand_Smuggling";
}


void RemoveSmugglersFromShore()
{
	ref Smuggler, player;
	int RandCounter;

	player = getmainCharacter();

	//Trace("Убираю персонажей-контрабандистов");

	Player.quest.Rand_SmugglingRemove.win_condition.l1 = "ExitFromLocation";
	Player.quest.Rand_SmugglingRemove.win_condition.l1.location = player.location;
	Player.quest.Rand_SmugglingRemove.win_condition = "Rand_SmugglingRemove";

	DeleteAttribute(player, "quest.Contraband.Active");

	RemoveGeometryFromLocation(Player.Quest.SelectedSmugglingLocation, "smg");

	LAi_group_SetRelation(LAI_GROUP_PLAYER, "CoastalGuards", LAI_GROUP_NEITRAL);

}



string SelectSmugglingLocation()
{
	ref Pchar, CurIsland;
	String SmugLocation[4];
	string TargetLocation;

	Pchar = GetMainCharacter();
	int n;
	n = GetCharacterCurrentIsland(Pchar);
	if(n < 0) return "none";
	CurIsland = GetIslandByIndex(n);
	
	Trace("Selection Started. Island - " + CurIsland.id);
	TargetLocation = "None";

	switch (CurIsland.id)
	{
		case "FalaiseDeFleur":			
			TargetLocation = "Falaise_de_fleur_shore";
			Trace("Location " + TargetLocation + " Selected");
		break;

		case "Redmond":
			SmugLocation[0] = "Redmond_shore_01";
			SmugLocation[1] = "Redmond_shore_02";
			TargetLocation = SmugLocation[Rand(1)];
			Trace("Location " + TargetLocation + " Selected");
		break;

		case "Conceicao":
			SmugLocation[0] = "Conceicao_shore_01";
			SmugLocation[1] = "Conceicao_shore_02";
			TargetLocation = SmugLocation[Rand(1)];
			Trace("Location " + TargetLocation + " Selected");
		break;

		case "Oxbay":
			SmugLocation[0] = "Oxbay_shore_01";
			SmugLocation[1] = "Oxbay_shore_02";
			SmugLocation[2] = "Oxbay_lighthouse";
			TargetLocation = SmugLocation[Rand(2)];
			Trace("Location " + TargetLocation + " Selected");
		break;

		case "IslaMuelle":
			TargetLocation = "muelle_shore";
			Trace("Location " + TargetLocation + " Selected");
		break;

		case "Douwesen":
			SmugLocation[0] = "Douwesen_shore_01";
			SmugLocation[1] = "Douwesen_shore_02";
			TargetLocation = SmugLocation[Rand(1)];
			Trace("Location " + TargetLocation + " Selected");
		break;

		case "QuebradasCostillas":
			TargetLocation = "none";
			Trace("Location " + TargetLocation + " Selected");
		break;

		case "KhaelRoa":
			TargetLocation = "none";
			Trace("Location " + TargetLocation + " Selected");
		break;

	}

	Pchar.Quest.SelectedSmugglingLocation = TargetLocation;
return TargetLocation;
}


void SetCoastalGuardPursuit()
{
	ref Pchar, CurIsland, rCap1, rCap2, rCap3;
	Pchar = GetMainCharacter();
	rCap1 = CharacterFromID("Coastal_Captain01");
	rCap2 = CharacterFromID("Coastal_Captain02");
	rCap3 = CharacterFromID("Coastal_Captain03");
	//trace("Индекс текущего острова " + GetCharacterCurrentIsland(Pchar));
	CurIsland = GetIslandByIndex(GetCharacterCurrentIsland(Pchar));
	//trace("Текущий остров: " + CurIsland.id);
	//trace("Текущая нация острова: " + CurIsland.smuggling_nation);
		
	//Простановка параметров капитанам береговой стражи
	LAi_SetHP(rcap1, 120, 120);
	rcap1.nation =  CurIsland.smuggling_nation;
	//Trace("НАЦИЯ КАПИТАНА" + rcap1.nation);
	SetRandomNameToCharacter(rCap1);
	rcap1.rank = makeint(Pchar.rank) - 2 + Rand(4);
	rcap1.experience = CalculateExperienceFromRank(sti(rcap1.rank));
	rcap1.model = SelectSoldierModelByNation(rcap1, "Officer");
	rcap1.Headmodel = "h_" + rcap1.model;
	Facemaker(rcap1);

	CalculateAppropriateSkills(rcap1);	

	SelectCoastalGuardShip(rcap1);

	//SetBaseShipData(rcap1);

	Group_CreateGroup("Coastal_Guards");
	Group_addCharacter("Coastal_Guards", "Coastal_Captain01");
	Group_SetGroupCommander("Coastal_Guards", "Coastal_Captain01");

	if(GetCompanionQuantity(Pchar) > 1 || makeint(Pchar.rank) > 5)
	{
		LAi_SetHP(rcap2, 120, 120);
		rcap2.nation =  CurIsland.smuggling_nation;
		SetRandomNameToCharacter(rCap2);
		rcap2.rank = makeint(Pchar.rank) - 2 + Rand(4);
		rcap2.experience = CalculateExperienceFromRank(sti(rcap2.rank));
		rcap2.model = SelectSoldierModelByNation(rcap2, "Officer");
		rcap2.Headmodel = "h_" + rcap2.model;
		Facemaker(rcap2);

		CalculateAppropriateSkills(rcap2);	

		SelectCoastalGuardShip(rcap2);

		//SetBaseShipData(rcap2);

		Group_addCharacter("Coastal_Guards", "Coastal_Captain02");

	}

	if(GetCompanionQuantity(Pchar) > 2 || makeint(Pchar.rank) > 8)
	{
		LAi_SetHP(rcap3, 120, 120);
		rcap3.nation =  CurIsland.smuggling_nation;
		SetRandomNameToCharacter(rcap3);
		rcap3.rank = makeint(Pchar.rank) - 2 + Rand(4);
		rcap3.experience = CalculateExperienceFromRank(sti(rcap3.rank));
		rcap3.model = SelectSoldierModelByNation(rcap3, "Officer");
		rcap3.Headmodel = "h_" + rcap3.model;
		Facemaker(rcap3);


		CalculateAppropriateSkills(rcap3);	

		SelectCoastalGuardShip(rcap3);

		//SetBaseShipData(rcap3);

		Group_addCharacter("Coastal_Guards", "Coastal_Captain03");
	}
	//Trace("FUNCTION SetCoastalGuardPursuit Reports: Current PLayer Island is: " + Islands[GetCharacterCurrentIsland(Pchar)].id);

	Group_SetPursuitGroup("Coastal_Guards", PLAYER_GROUP);
	Group_SetAddress("Coastal_Guards", Islands[GetCharacterCurrentIsland(Pchar)].id, "", "");
	SetCharacterRelationBoth(GetCharacterIndex("Coastal_Captain01"),GetMainCharacterIndex(),RELATION_ENEMY);	
	Group_SetTaskAttack("Coastal_Guards", PLAYER_GROUP);
	Group_LockTask("Coastal_Guards");
}


void StopCoastalGuardPursuit()
{
	ref Pchar, rCap1, rCap2, rCap3;
	Pchar = GetMainCharacter();
	rCap1 = CharacterFromID("Coastal_Captain01");
	rCap2 = CharacterFromID("Coastal_Captain02");
	rCap3 = CharacterFromID("Coastal_Captain03");
	
	group_DeleteGroup("Coastal_Guards");
	ChangeCharacterAddressGroup(CharacterFromID("Coastal_Captain01"), "None", "", "");
	ChangeCharacterAddressGroup(CharacterFromID("Coastal_Captain02"), "None", "", "");
	ChangeCharacterAddressGroup(CharacterFromID("Coastal_Captain03"), "None", "", "");

}

void SelectCoastalGuardShip(ref rCharacter)
{
	ref pchar;
	int Jopa;

	Pchar = Getmaincharacter();
	//trace("FUNCTION SelectCoastalGuardShip Reports: Current Captain Nation Is: " + rCharacter.nation);

	if(sti(rCharacter.nation) == ENGLAND || sti(rCharacter.nation) == FRANCE || sti(rCharacter.nation) == SPAIN || sti(rCharacter.nation) == HOLLAND || sti(rCharacter.nation) == PORTUGAL)
	{

		jopa = sti(rCharacter.nation);
		DeleteAttribute(rCharacter, "ship");
		switch(jopa)
		{
			case ENGLAND:
				rCharacter.ship = SHIP_SLOOP_ENGLAND;
				if(sti(Pchar.rank) >= 3) rCharacter.ship.type = SHIP_BRIG_ENGLAND;
				if(sti(Pchar.rank) >= 5) rCharacter.ship.type = SHIP_CORVETTE_ENGLAND;
				if(sti(Pchar.rank) >= 7) rCharacter.ship.type = SHIP_FRIGATE_ENGLAND;
				//trace("FUNCTION SelectCoastalGuardShip Reports: Ship " + rCharacter.ship.type + " was selected for " + RCharacter.id);
			break;

			case FRANCE:
				rCharacter.ship = SHIP_SLOOP_FRANCE;
				if(sti(Pchar.rank) >= 3) rCharacter.ship.type = SHIP_BRIG_FRANCE;					
				if(sti(Pchar.rank) >= 5) rCharacter.ship.type = SHIP_CORVETTE_FRANCE;
				if(sti(Pchar.rank) >= 7) rCharacter.ship.type = SHIP_FRIGATE_FRANCE;
				//trace("FUNCTION SelectCoastalGuardShip Reports: Ship " + rCharacter.ship.type + " was selected for " + RCharacter.id);
			break;

			case SPAIN:
				rCharacter.ship = SHIP_SLOOP_SPAIN;
				if(sti(Pchar.rank) >= 3) rCharacter.ship.type = SHIP_BRIG_SPAIN;
				if(sti(Pchar.rank) >= 5) rCharacter.ship.type = SHIP_CORVETTE_SPAIN;
				if(sti(Pchar.rank) >= 7) rCharacter.ship.type = SHIP_FRIGATE_SPAIN;
				//trace("FUNCTION SelectCoastalGuardShip Reports: Ship " + rCharacter.ship.type + " was selected for " + RCharacter.id);
			break;

			case HOLLAND:
				rCharacter.ship = SHIP_SLOOP_HOLLAND;
				if(sti(Pchar.rank) >= 3) rCharacter.ship.type = SHIP_BRIG_HOLLAND;
				if(sti(Pchar.rank) >= 5) rCharacter.ship.type = SHIP_CORVETTE_HOLLAND;
				if(sti(Pchar.rank) >= 7) rCharacter.ship.type = SHIP_FRIGATE_HOLLAND;
				//trace("FUNCTION SelectCoastalGuardShip Reports: Ship " + rCharacter.ship.type + " was selected for " + RCharacter.id);
			break;

			case PORTUGAL:
				rCharacter.ship = SHIP_SLOOP_PORTUGAL;
				if(sti(Pchar.rank) >= 3) rCharacter.ship.type = SHIP_BRIG_PORTUGAL;
				if(sti(Pchar.rank) >= 5) rCharacter.ship.type = SHIP_CORVETTE_PORTUGAL;
				if(sti(Pchar.rank) >= 7) rCharacter.ship.type = SHIP_FRIGATE_PORTUGAL;
				//trace("FUNCTION SelectCoastalGuardShip Reports: Ship " + rCharacter.ship.type + " was selected for " + RCharacter.id);
			break;
		}
		SetBaseShipData(rCharacter);
		SetRandomNameToShip(rCharacter);
	}
	else
	{
		trace("FUNCTION SelectCoastalGuardShip reports: Character is a pirate or has no nation at all");
	}
}

string SelectSoldierModelByNation(ref rCharacter, string SoldierOrOfficer)
{
	string model;
	int jopa;

	if(sti(rCharacter.nation) == ENGLAND || sti(rCharacter.nation) == FRANCE || sti(rCharacter.nation) == SPAIN || sti(rCharacter.nation) == HOLLAND || sti(rCharacter.nation) == PORTUGAL)
	{
		jopa = sti(rCharacter.nation);
		switch(jopa)
		{
			case ENGLAND:
				if(SoldierorOfficer == "officer") model = "offic_eng";
				if(SoldierorOfficer == "soldier") model = "soldier_eng";
			break;

			case FRANCE:
				if(SoldierorOfficer == "officer") model = "offic_fra";
				if(SoldierorOfficer == "soldier") model = "soldier_fra";
			break;

			case SPAIN:
				if(SoldierorOfficer == "officer") model = "offic_spa";
				if(SoldierorOfficer == "soldier") model = "soldier_spa";
			break;

			case HOLLAND:
				if(SoldierorOfficer == "officer") model = "offic_hol";
				if(SoldierorOfficer == "soldier") model = "soldier_hol";
			break;

			case PORTUGAL:
				if(SoldierorOfficer == "officer") model = "offic_por";
				if(SoldierorOfficer == "soldier") model = "soldier_por";
			break;

		}
		return model;

	}
	else
	{
		trace("FUNCTION SelectSoldierModelByNation Reports: Character is a pirate or has no nation at all");
		//Log_SetStringToLog("FUNCTION SelectSoldierModelByNation Reports: Character is a pirate or has no nation at all");
		return "Blaze";
	}
}

void AddGeometryToLocation(string LocationID, string ModelName)
{
	ref LocationRef;
	int n = 1;
	string str;
	locationRef = &locations[FindLocation(LocationID)];

	for(n = 1; n < 10; n++)
	{
		str = n;
		if(!CheckAttribute(LocationRef, "models.always." + str))
		{
			LocationRef.models.always.(str) = ModelName;
			LocationRef.models.always.(str).tech = "dLightModel";
			break;
		}
	}
}	

void RemoveGeometryFromLocation(string LocationID, string ModelName)
{
	ref LocationRef;
	int n = 1;
	string str;
	//trace("FUNCTION RemoveGeometryFromLocation reports: Current location ID is " + LocationID + " and geometry " + ModelName + " should be removed");
	if(FindLocation(LocationID) != -1)
	{
		locationRef = &locations[FindLocation(LocationID)];
	}
	else
	{
		return;
	}

	for(n = 1; n < 10; n++)
	{
		str = n;
		//trace("FUNCTION RemoveGeometryFromLocation reports: Checking Geometry name for n = " + str + ". It is " + LocationRef.models.always.(str));
		if(LocationRef.models.always.(str) == ModelName)
		{
			//trace("JOPA!");
			DeleteAttribute(LocationRef, "models.always." + str);
			break;
		}
	}
}	

void CalculateAppropriateSkills(ref NPchar) 
{
	int MiddleK;

	ref Pchar;
	Pchar = GetMainCharacter();

	MiddleK = makeint((makeint(Pchar.skill.Leadership) + makeint(Pchar.skill.Fencing) + makeint(Pchar.skill.Sailing) +
makeint(Pchar.skill.Accuracy) + makeint(Pchar.skill.Cannons) + makeint(Pchar.skill.Grappling) + makeint(Pchar.skill.Repair) +
makeint(Pchar.skill.Defence) + makeint(Pchar.skill.Commerce) + makeint(Pchar.skill.Sneak))/10);


			Npchar.skill.Leadership = MiddleK - 3 + Rand(4);
			if(makeint(Npchar.skill.Leadership)	<= 1) Npchar.skill.Leadership = 1;
			if(makeint(Npchar.skill.Leadership)	>= 10) Npchar.skill.Leadership = 10;

			Npchar.skill.Fencing = MiddleK - 3 + Rand(4) 	
			if(makeint(Npchar.skill.Fencing)	<= 1) Npchar.skill.Fencing = 1;	
			if(makeint(Npchar.skill.Fencing)	>= 10) Npchar.skill.Fencing = 10;

			Npchar.skill.Sailing = MiddleK - 3 + Rand(4)	
			if(makeint(Npchar.skill.Sailing)	<= 1) Npchar.skill.Sailing = 1;
			if(makeint(Npchar.skill.Sailing)	>= 10) Npchar.skill.Sailing = 10;

			Npchar.skill.Accuracy = MiddleK - 3 + Rand(4) 
			if(makeint(Npchar.skill.Accuracy)	<= 1) Npchar.skill.Accuracy = 1;	
			if(makeint(Npchar.skill.Accuracy)	>= 10) Npchar.skill.Accuracy = 10;
				
			Npchar.skill.Cannons = MiddleK - 3 + Rand(4)
			if(makeint(Npchar.skill.Cannons)	<= 1) Npchar.skill.Cannons = 1;
			if(makeint(Npchar.skill.Cannons)	>= 10) Npchar.skill.Cannons = 10;

			Npchar.skill.Grappling = MiddleK - 3 + Rand(4)
			if(makeint(Npchar.skill.Grappling)	<= 1) Npchar.skill.Grappling = 1;
			if(makeint(Npchar.skill.Grappling)	>= 10) Npchar.skill.Grappling = 10;

			Npchar.skill.Repair = MiddleK - 3 + Rand(4)
			if(makeint(Npchar.skill.Repair)	<= 1) Npchar.skill.Repair = 1;
			if(makeint(Npchar.skill.Repair)	>= 10) Npchar.skill.Repair = 10;

			Npchar.skill.Defence = MiddleK - 3 + Rand(4)				
			if(makeint(Npchar.skill.Defence)	<= 1) Npchar.skill.Defence = 1;
			if(makeint(Npchar.skill.Defence)	>= 10) Npchar.skill.Defence = 10;

			Npchar.skill.Commerce = MiddleK - 3 + Rand(4)
			if(makeint(Npchar.skill.Commerce)	<= 1) Npchar.skill.Commerce = 1;
			if(makeint(Npchar.skill.Commerce)	>= 10) Npchar.skill.Commerce = 10;

			Npchar.skill.Sneak = MiddleK - 3 + Rand(4)
			if(makeint(Npchar.skill.Sneak)	<= 1) Npchar.skill.Sneak = 1;
			if(makeint(Npchar.skill.Sneak)	>= 10) Npchar.skill.Sneak = 10;
}


int FindFreeRandomOfficer()
{
	int Counter, OfficerIdx;
	ref Pchar;
	
	Pchar = GetMainCharacter();
	string OfficerId;

	for(counter = 0; counter <=9; counter++)
	{
		OfficerId = "Enc_Officer_0" + counter;
		OfficerIdx = GetCharacterIndex(OfficerId);
		if(FindFellowTravellers(PChar, CharacterFromId(OfficerId)) == 0) return OfficerIdx;
	}

	return -1;
}

string SelectSoldierModelbyLocationNation(string LocationID, string SoldierOrOfficer)
{

	ref PChar;
	string model, islandID;
	int jopa;


	Pchar = GetMainCharacter();

	//jopa = GetLocationNation(&Locations[FindLocation(LocationID)]);

	jopa = GetCharacterCurrentIsland(Pchar);

//	if(jopa == -1) return "pirat1";

	IslandID = Islands[jopa].id;

		switch(IslandID)
		{

		case "FalaiseDeFleur":			
			if(SoldierorOfficer == "officer") model = "offic_fra";
			if(SoldierorOfficer == "soldier") model = "soldier_fra" + (rand(4) + 2);
		break;

		case "Redmond":
			if(SoldierorOfficer == "officer") model = "offic_eng";
			if(SoldierorOfficer == "soldier") model = "soldier_eng" + (rand(4) + 2);
		break;

		case "Conceicao":
			if(SoldierorOfficer == "officer") model = "offic_por";
			if(SoldierorOfficer == "soldier") model = "soldier_por" + (rand(4) + 2);
		break;

		case "Oxbay":
			if(SoldierorOfficer == "officer") model = "offic_eng";
			if(SoldierorOfficer == "soldier") model = "soldier_eng" + (rand(4) + 2);
		break;

		case "IslaMuelle":
			if(SoldierorOfficer == "officer") model = "offic_spa";
			if(SoldierorOfficer == "soldier") model = "soldier_spa" + (rand(4) + 2);
		break;

		case "Douwesen":
			if(SoldierorOfficer == "officer") model = "offic_hol";
			if(SoldierorOfficer == "soldier") model = "soldier_hol" + (rand(4) + 2);
		break;

		case "QuebradasCostillas":
			if(SoldierorOfficer == "officer") model = "pirat1";
			if(SoldierorOfficer == "soldier") model = "pirat" + (rand(4) + 2);
		break;

		case "KhaelRoa":
			if(SoldierorOfficer == "officer") model = "mummy";
			if(SoldierorOfficer == "soldier") model = "mummy";
		break;
		}
	return model;

}
/*
int SelectRandomLandEncounter(aref CurLoc)
{
	int EncType;

	switch(CurLoc.EncType)
	{
		case "town":

			EncType = rand();

		break;

		case "jungle":

		break;

		case "shore":

		break;

		case "cave":

		break;
	}
	
}

void CreateJungleEncounters(int Type)
{
	switch(type)
	{


		case 1:
		break;
	}

}

void CreateTownEncounters(int Type)
{
}


void CreateShoreEncounters(int Type)
{
}


void CreateCaveEncounters(int Type)
{
}

int getDeadManMoney()
{
	int money;

	money = Rand(10)*Rand(10)*10;

	return money;
}

string returnRandomDeadItem()
{
	return "potion";
}
*/

//----------------------------- Недописанные функции, введенные для прописывания в диалоги ---------------------------


string TimeGreeting()
{
	return GlobalStringConvert("TimeGreeting");
}


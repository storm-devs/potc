
extern void initFastReloadTable();

void InitBaseInterfaces()
{
	SetEventHandler("GetQuestTextFileName","GetQuestTextFileName",0);
	GameInterface.GameTime.sec = InterfaceStates.GameTime.sec;
	GameInterface.GameTime.min = InterfaceStates.GameTime.min;
	GameInterface.GameTime.hour = InterfaceStates.GameTime.hour;
	CreateEntity(&GameInterface,"xinterface");
	DelEventHandler("GetQuestTextFileName","GetQuestTextFileName");
	LayerAddObject("iExecute",&GameInterface,-100);
	LayerAddObject("iRealize",&GameInterface,-100);
	if(!IsEntity(&LanguageObject))
	{	CreateEntity(&LanguageObject,"obj_strservice");
	}
	InitLogInterface();
	InitBattleLandInterface();
	InterfaceStates.Launched = false;
	if( storeDayUpdateCnt>=0 ) // обновление магазина можно включить
	{
		Event("EvStoreDayUpdate");
	}
	LanguageCloseFile("LocLables.txt");
	g_LocLngFileID = LanguageOpenFile("LocLables.txt");
}

string questTextFileName[2];
ref GetQuestTextFileName()
{
	questTextFileName[0] = "resource\ini\texts\" + LanguageGetLanguage() + "\questbook\quests_texts.txt";
	questTextFileName[1] = "";
	return &questTextFileName;
}

void InitBaseInterfaces_main()
{
	GameInterface.Scroll.current = 0;
	GameInterface.FourImage.current = 0;

	InterfaceStates.GameTime.sec = 0;
	InterfaceStates.GameTime.min = 0;
	InterfaceStates.GameTime.hour = 0;

	InterfaceStates.Buttons.New.enable = true;
	InterfaceStates.Buttons.Resume.enable = false;
	InterfaceStates.Buttons.Load.enable = false;
	InterfaceStates.Buttons.Save.enable = false;
	InterfaceStates.Buttons.Options.enable = true;
	InterfaceStates.Buttons.Credits.enable = true;
	InterfaceStates.Buttons.Quit.enable = true;
	InterfaceStates.Buttons.Controls.enable = true;

	InterfaceStates.BattleShow.FastCommand	= true;
	InterfaceStates.BattleShow.LogString	= true;
	InterfaceStates.BattleShow.Navigator	= true;
	InterfaceStates.BattleShow.Command		= true;
	InterfaceStates.BattleShow.Alarm		= true;

	InterfaceStates.doUnFreeze = true;
	InterfaceStates.Launched = false;

    Interfaces[INTERFACE_CANNONS].SectionName = "interface\cannons.c";
    Interfaces[INTERFACE_CANNONS].IniFile = "RESOURCE\INI\INTERFACES\cannons.ini";
    Interfaces[INTERFACE_STORE].SectionName = "interface\store.c";
    Interfaces[INTERFACE_STORE].IniFile = "RESOURCE\INI\INTERFACES\store.ini";
    Interfaces[INTERFACE_SHIP_CHOOSE].SectionName = "interface\ship.c";
    Interfaces[INTERFACE_SHIP_CHOOSE].IniFile = "RESOURCE\INI\INTERFACES\ship.ini";
    Interfaces[INTERFACE_SHIPYARD].SectionName = "interface\shipyard.c";
    Interfaces[INTERFACE_SHIPYARD].IniFile = "RESOURCE\INI\INTERFACES\shipyard.ini";
    Interfaces[INTERFACE_CHARACTER].SectionName = "interface\character.c";
    Interfaces[INTERFACE_CHARACTER].IniFile = "RESOURCE\INI\INTERFACES\character.ini";
    Interfaces[INTERFACE_MAINMENU].SectionName = "interface\mainmenu.c";
    Interfaces[INTERFACE_MAINMENU].IniFile = "RESOURCE\INI\INTERFACES\mainmenu.ini";
    Interfaces[INTERFACE_SHIPHOLD].SectionName = "interface\shiphold.c";
    Interfaces[INTERFACE_SHIPHOLD].IniFile = "RESOURCE\INI\INTERFACES\shiphold.ini";
    Interfaces[INTERFACE_HIRECREW].SectionName = "interface\hirecrew.c";
    Interfaces[INTERFACE_HIRECREW].IniFile = "RESOURCE\INI\INTERFACES\hirecrew.ini";
    Interfaces[INTERFACE_PASSENGERS].SectionName = "interface\passengers.c";
    Interfaces[INTERFACE_PASSENGERS].IniFile = "RESOURCE\INI\INTERFACES\passengers.ini";
	Interfaces[INTERFACE_CHARACTER_SELECT].SectionName = "interface\selectCharacter.c";
	Interfaces[INTERFACE_CHARACTER_SELECT].IniFile = "RESOURCE\INI\INTERFACES\selectCharacter.ini";
	Interfaces[INTERFACE_QUESTBOOK].SectionName = "interface\questbook.c";
	Interfaces[INTERFACE_QUESTBOOK].IniFile = "RESOURCE\INI\INTERFACES\questbook.ini";
	Interfaces[INTERFACE_TRADEBOOK].SectionName = "interface\tradebook.c";
	Interfaces[INTERFACE_TRADEBOOK].IniFile = "RESOURCE\INI\INTERFACES\tradebook.ini";
	Interfaces[INTERFACE_NATIONRELATION].SectionName = "interface\NationRelation.c";
	Interfaces[INTERFACE_NATIONRELATION].IniFile = "RESOURCE\INI\INTERFACES\NationRelation.ini";
	Interfaces[INTERFACE_SAVELOAD].SectionName = "interface\save_load.c";
	Interfaces[INTERFACE_SAVELOAD].IniFile = "RESOURCE\INI\INTERFACES\save_load.ini";
	Interfaces[INTERFACE_ITEMS].SectionName = "interface\items.c";
	Interfaces[INTERFACE_ITEMS].IniFile = "RESOURCE\INI\INTERFACES\items.ini";
	Interfaces[INTERFACE_FORTCAPTURE].SectionName = "interface\fortcapture.c";
	Interfaces[INTERFACE_FORTCAPTURE].IniFile = "RESOURCE\INI\INTERFACES\fortcapture.ini";
	Interfaces[INTERFACE_ITEMSBOX].SectionName = "interface\itemsbox.c";
	Interfaces[INTERFACE_ITEMSBOX].IniFile = "RESOURCE\INI\INTERFACES\itemsbox.ini";
	Interfaces[INTERFACE_HELPSCREEN].SectionName = "interface\helpscreen.c";
	Interfaces[INTERFACE_HELPSCREEN].IniFile = "RESOURCE\INI\INTERFACES\helpscreen.ini";
	Interfaces[INTERFACE_OPTIONSCREEN].SectionName = "interface\option_screen.c";
	Interfaces[INTERFACE_OPTIONSCREEN].IniFile = "RESOURCE\INI\INTERFACES\option_screen.ini";
	Interfaces[INTERFACE_SELECTMENU].SectionName = "interface\select_menu.c";
	Interfaces[INTERFACE_SELECTMENU].IniFile = "RESOURCE\INI\INTERFACES\select_menu.ini";
	Interfaces[INTERFACE_ITEMSTRADE].SectionName = "interface\itemstrade.c";
	Interfaces[INTERFACE_ITEMSTRADE].IniFile = "RESOURCE\INI\INTERFACES\itemstrade.ini";
	Interfaces[INTERFACE_CONTROLS].SectionName = "interface\controls.c";
	Interfaces[INTERFACE_CONTROLS].IniFile = "RESOURCE\INI\INTERFACES\controls.ini";
	Interfaces[INTERFACE_PERKS].SectionName = "interface\perks.c";
	Interfaces[INTERFACE_PERKS].IniFile = "RESOURCE\INI\INTERFACES\perks.ini";
	Interfaces[INTERFACE_SALARY].SectionName = "interface\salary.c";
	Interfaces[INTERFACE_SALARY].IniFile = "RESOURCE\INI\INTERFACES\salary.ini";
	Interfaces[INTERFACE_PLAYGAME].SectionName = "interface\playgame.c";
	Interfaces[INTERFACE_PLAYGAME].IniFile = "RESOURCE\INI\INTERFACES\playgame.ini";
	Interfaces[INTERFACE_ENDGAME].SectionName = "interface\endgame.c";
	Interfaces[INTERFACE_ENDGAME].IniFile = "RESOURCE\INI\INTERFACES\endgame.ini";
	Interfaces[INTERFACE_LANGUAGESET].SectionName = "interface\LanguageSelect.c";
	Interfaces[INTERFACE_LANGUAGESET].IniFile = "RESOURCE\INI\INTERFACES\LanguageSelect.ini";

    Interfaces[INTERFACE_RANSACK_JOIN].SectionName = "interface\ransack_join.c";
    Interfaces[INTERFACE_RANSACK_JOIN].IniFile = "RESOURCE\INI\INTERFACES\ransack_join.ini";
    Interfaces[INTERFACE_RANSACK_CREW].SectionName = "interface\ransack_crew.c";
    Interfaces[INTERFACE_RANSACK_CREW].IniFile = "RESOURCE\INI\INTERFACES\ransack_crew.ini";
    Interfaces[INTERFACE_RANSACK_CAPTAIN].SectionName = "interface\ransack_captain.c";
    Interfaces[INTERFACE_RANSACK_CAPTAIN].IniFile = "RESOURCE\INI\INTERFACES\ransack_captain.ini";
    Interfaces[INTERFACE_RANSACK_MAIN].SectionName = "interface\ransack_main.c";
    Interfaces[INTERFACE_RANSACK_MAIN].IniFile = "RESOURCE\INI\INTERFACES\transfer_main.ini";
    Interfaces[INTERFACE_TRANSFER_MAIN].SectionName = "interface\transfer_main.c";
    Interfaces[INTERFACE_TRANSFER_MAIN].IniFile = "RESOURCE\INI\INTERFACES\transfer_main.ini";
    Interfaces[INTERFACE_TRANSFER_GOODS].SectionName = "interface\transfer_goods.c";
    Interfaces[INTERFACE_TRANSFER_GOODS].IniFile = "RESOURCE\INI\INTERFACES\transfer_goods.ini";
    Interfaces[INTERFACE_TRANSFER_CHARACTER].SectionName = "interface\transfer_characters.c";
    Interfaces[INTERFACE_TRANSFER_CHARACTER].IniFile = "RESOURCE\INI\INTERFACES\transfer_characters.ini";
    Interfaces[INTERFACE_TRANSFER_CREW].SectionName = "interface\transfer_crew.c";
    Interfaces[INTERFACE_TRANSFER_CREW].IniFile = "RESOURCE\INI\INTERFACES\transfer_crew.ini";

	if( LoadSegment("battle_interface\fast_reload_table.c") )
	{
		initFastReloadTable();
		UnloadSegment("battle_interface\fast_reload_table.c");
	}
}

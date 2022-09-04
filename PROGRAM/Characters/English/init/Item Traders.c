
int CreateStreetMerchants(int n)
{	
	ref ch;

	makeref(ch,Characters[n]);		//Уличный торговец в Оксбэе
	ch.name 	= "Street";
	ch.lastname 	= "Merchant";
	ch.id		= "Oxbay_Street_merchant_1";
	ch.model	= "Fatman2_1"; 
	ch.sex = "man";
	ch.location = "Oxbay_port";
	ch.location.group = "merchant";
	ch.location.locator = "merchant2";
	ch.dialog.filename = "Item Trader_Dialog.c";
	ch.greeting = "Gr_Oxbay Citizen";
	ch.nation = ENGLAND;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "6";
	ch.skill.Fencing = "3";
	ch.skill.Sailing = "4";
	ch.skill.Accuracy = "9";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "5";
	ch.skill.Repair = "6";
	ch.skill.Defence = "8";
	ch.skill.Commerce = "7";
	ch.skill.Sneak = "8";
	ch.quest.area = "Oxbay";
	ch.money = "10";
	LAi_SetMerchantType(ch);
	LAi_SetHP(ch, 80.0, 80.0);
	
	n = n + 1;

	makeref(ch,Characters[n]);		//Уличный торговец в Оксбэе
	ch.name 	= "Street";
	ch.lastname 	= "Merchant";
	ch.id		= "Oxbay_Street_merchant_1";
	ch.model	= "Man1_2"; 
	ch.sex = "man";
	ch.location = "Oxbay_town";
	ch.location.group = "merchant";
	ch.location.locator = "merchant2";
	ch.dialog.filename = "Item Trader_Dialog.c";
	ch.greeting = "Gr_Oxbay Citizen";
	ch.nation = ENGLAND;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "6";
	ch.skill.Fencing = "3";
	ch.skill.Sailing = "4";
	ch.skill.Accuracy = "9";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "5";
	ch.skill.Repair = "6";
	ch.skill.Defence = "8";
	ch.skill.Commerce = "7";
	ch.skill.Sneak = "8";
	ch.quest.area = "Oxbay";
	ch.money = "10";
	LAi_SetMerchantType(ch);
	LAi_SetHP(ch, 80.0, 80.0);
	
	n = n + 1;


	makeref(ch,Characters[n]);		//Уличный торговец в FF
	ch.name 	= "Street";
	ch.lastname 	= "Merchant";
	ch.id		= "FF_Street_merchant_1";
	ch.model	= "Man1_2"; 
	ch.sex = "man";
	ch.location = "Falaise_De_Fleur_Location_03";
	ch.location.group = "merchant";
	ch.location.locator = "merchant2";
	ch.dialog.filename = "Item Trader_Dialog.c";
	ch.greeting = "Gr_falaise de fleur citizen";
	ch.nation = FRANCE;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "6";
	ch.skill.Fencing = "3";
	ch.skill.Sailing = "4";
	ch.skill.Accuracy = "9";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "5";
	ch.skill.Repair = "6";
	ch.skill.Defence = "8";
	ch.skill.Commerce = "7";
	ch.skill.Sneak = "8";
	ch.quest.area = "FalaiseDeFleur";
	ch.money = "10";
	LAi_SetMerchantType(ch);
	LAi_SetHP(ch, 80.0, 80.0);
	
	n = n + 1;


	makeref(ch,Characters[n]);		//Уличный торговец в Isla Muelle
	ch.name 	= "Street";
	ch.lastname 	= "Merchant";
	ch.id		= "Muelle_Street_merchant_1";
	ch.model	= "Man2"; 
	ch.sex = "man";
	ch.location = "Muelle_port";
	ch.location.group = "merchant";
	ch.location.locator = "merchant2";
	ch.dialog.filename = "Item Trader_Dialog.c";
	ch.greeting = "Gr_isla muelle citizen";
	ch.nation = SPAIN;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "6";
	ch.skill.Fencing = "3";
	ch.skill.Sailing = "4";
	ch.skill.Accuracy = "9";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "5";
	ch.skill.Repair = "6";
	ch.skill.Defence = "8";
	ch.skill.Commerce = "7";
	ch.skill.Sneak = "8";
	ch.quest.area = "IslaMuelle";
	ch.money = "10";
	LAi_SetMerchantType(ch);
	LAi_SetHP(ch, 80.0, 80.0);
	
	n = n + 1;

	makeref(ch,Characters[n]);		//Уличный торговец в Isla Muelle
	ch.name 	= "Street";
	ch.lastname 	= "Merchant";
	ch.id		= "Muelle_Street_merchant_2";
	ch.model	= "Man5"; 
	ch.sex = "man";
	ch.location = "Muelle_town_01";
	ch.location.group = "merchant";
	ch.location.locator = "merchant1";
	ch.dialog.filename = "Item Trader_Dialog.c";
	ch.greeting = "Gr_isla muelle citizen";
	ch.nation = SPAIN;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "6";
	ch.skill.Fencing = "3";
	ch.skill.Sailing = "4";
	ch.skill.Accuracy = "9";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "5";
	ch.skill.Repair = "6";
	ch.skill.Defence = "8";
	ch.skill.Commerce = "7";
	ch.skill.Sneak = "8";
	ch.quest.area = "IslaMuelle";
	ch.money = "10";
	LAi_SetMerchantType(ch);
	LAi_SetHP(ch, 80.0, 80.0);

	n = n + 1;

	makeref(ch,Characters[n]);		//Уличный торговец в Isla Muelle
	ch.name 	= "Street";
	ch.lastname 	= "Merchant";
	ch.id		= "Muelle_Street_merchant_3";
	ch.model	= "Sailor6"; 
	ch.sex = "man";
	ch.location = "Muelle_town_01";
	ch.location.group = "merchant";
	ch.location.locator = "merchant2";
	ch.dialog.filename = "Item Trader_Dialog.c";
	ch.greeting = "Gr_isla muelle citizen";
	ch.nation = SPAIN;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "6";
	ch.skill.Fencing = "3";
	ch.skill.Sailing = "4";
	ch.skill.Accuracy = "9";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "5";
	ch.skill.Repair = "6";
	ch.skill.Defence = "8";
	ch.skill.Commerce = "7";
	ch.skill.Sneak = "8";
	ch.quest.area = "IslaMuelle";
	ch.money = "10";
	LAi_SetMerchantType(ch);
	LAi_SetHP(ch, 80.0, 80.0);
	
	n = n + 1;


	makeref(ch,Characters[n]);		//Уличный торговец в Isla Muelle
	ch.name 	= "Street";
	ch.lastname 	= "Merchant";
	ch.id		= "Muelle_Street_merchant_4";
	ch.model	= "Old_man1"; 
	ch.sex = "man";
	ch.location = "Muelle_town_01";
	ch.location.group = "merchant";
	ch.location.locator = "merchant3";
	ch.dialog.filename = "Item Trader_Dialog.c";
	ch.greeting = "Gr_isla muelle citizen";
	ch.nation = SPAIN;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "6";
	ch.skill.Fencing = "3";
	ch.skill.Sailing = "4";
	ch.skill.Accuracy = "9";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "5";
	ch.skill.Repair = "6";
	ch.skill.Defence = "8";
	ch.skill.Commerce = "7";
	ch.skill.Sneak = "8";
	ch.quest.area = "IslaMuelle";
	ch.money = "10";
	LAi_SetMerchantType(ch);
	LAi_SetHP(ch, 80.0, 80.0);
	
	n = n + 1;

	makeref(ch,Characters[n]);		//Уличный торговец в Conceicao
	ch.name 	= "Street";
	ch.lastname 	= "Merchant";
	ch.id		= "Conceicao_Street_merchant_1";
	ch.model	= "Sailor3"; 
	ch.sex = "man";
	ch.location = "Conceicao_port";
	ch.location.group = "merchant";
	ch.location.locator = "merchant1";
	ch.dialog.filename = "Item Trader_Dialog.c";
	ch.greeting = "Gr_Conceicao Citizen";
	ch.nation = PORTUGAL;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "6";
	ch.skill.Fencing = "3";
	ch.skill.Sailing = "4";
	ch.skill.Accuracy = "9";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "5";
	ch.skill.Repair = "6";
	ch.skill.Defence = "8";
	ch.skill.Commerce = "7";
	ch.skill.Sneak = "8";
	ch.quest.area = "Conceicao";
	ch.money = "10";
	LAi_SetMerchantType(ch);
	LAi_SetHP(ch, 80.0, 80.0);
	
	n = n + 1;

	makeref(ch,Characters[n]);		//Уличный торговец в Douwesen
	ch.name 	= "Street";
	ch.lastname 	= "Merchant";
	ch.id		= "Douwesen_Street_merchant_1";
	ch.model	= "Sailor3"; 
	ch.sex = "man";
	ch.location = "Douwesen_port";
	ch.location.group = "merchant";
	ch.location.locator = "merchant1";
	ch.dialog.filename = "Item Trader_Dialog.c";
	ch.greeting = "Gr_Douwesen Citizen";
	ch.nation = HOLLAND;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "6";
	ch.skill.Fencing = "3";
	ch.skill.Sailing = "4";
	ch.skill.Accuracy = "9";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "5";
	ch.skill.Repair = "6";
	ch.skill.Defence = "8";
	ch.skill.Commerce = "7";
	ch.skill.Sneak = "8";
	ch.quest.area = "Conceicao";
	ch.money = "10";
	LAi_SetMerchantType(ch);
	LAi_SetHP(ch, 80.0, 80.0);
	
	n = n + 1;


	makeref(ch,Characters[n]);		//Уличный торговец в Douwesen
	ch.name 	= "Street";
	ch.lastname 	= "Merchant";
	ch.id		= "Douwesen_Street_merchant_2";
	ch.model	= "Chelovek1"; 
	ch.sex = "man";
	ch.location = "Douwesen_port";
	ch.location.group = "merchant";
	ch.location.locator = "merchant2";
	ch.dialog.filename = "Item Trader_Dialog.c";
	ch.greeting = "Gr_Douwesen Citizen";
	ch.nation = HOLLAND;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "6";
	ch.skill.Fencing = "3";
	ch.skill.Sailing = "4";
	ch.skill.Accuracy = "9";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "5";
	ch.skill.Repair = "6";
	ch.skill.Defence = "8";
	ch.skill.Commerce = "7";
	ch.skill.Sneak = "8";
	ch.quest.area = "Conceicao";
	ch.money = "10";
	LAi_SetMerchantType(ch);
	LAi_SetHP(ch, 80.0, 80.0);
	
	n = n + 1;


	makeref(ch,Characters[n]);		//Уличный торговец в Greenford
	ch.name 	= "Street";
	ch.lastname 	= "Merchant";
	ch.id		= "Greenford_Street_merchant_1";
	ch.model	= "fatman1"; 
	ch.sex = "man";
	ch.location = "Greenford_town";
	ch.location.group = "merchant";
	ch.location.locator = "merchant1";
	ch.dialog.filename = "Item Trader_Dialog.c";
	ch.greeting = "Gr_Oxbay Citizen";
	ch.nation = ENGLAND;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "6";
	ch.skill.Fencing = "3";
	ch.skill.Sailing = "4";
	ch.skill.Accuracy = "9";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "5";
	ch.skill.Repair = "6";
	ch.skill.Defence = "8";
	ch.skill.Commerce = "7";
	ch.skill.Sneak = "8";
	ch.quest.area = "Greenford";
	ch.money = "10";
	LAi_SetMerchantType(ch);
	LAi_SetHP(ch, 80.0, 80.0);
	
	n = n + 1;

	makeref(ch,Characters[n]);		//Уличный торговец в Greenford
	ch.name 	= "Street";
	ch.lastname 	= "Merchant";
	ch.id		= "Greenford_Street_merchant_2";
	ch.model	= "towngirl3"; 
	ch.sex = "woman";
	ch.location = "Greenford_town";
	ch.location.group = "merchant";
	ch.location.locator = "merchant2";
	ch.dialog.filename = "Item Trader_Dialog.c";
	ch.nation = ENGLAND;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "6";
	ch.skill.Fencing = "3";
	ch.skill.Sailing = "4";
	ch.skill.Accuracy = "9";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "5";
	ch.skill.Repair = "6";
	ch.skill.Defence = "8";
	ch.skill.Commerce = "7";
	ch.skill.Sneak = "8";
	ch.quest.area = "Greenford";
	ch.money = "10";
	ch.greeting = "Gr_Woman_English Citizen";
	LAi_SetMerchantType(ch);
	LAi_SetHP(ch, 80.0, 80.0);
	
	n = n + 1;

	makeref(ch,Characters[n]);		//Уличный торговец в Greenford
	ch.name 	= "Street";
	ch.lastname 	= "Merchant";
	ch.id		= "Greenford_Street_merchant_3";
	ch.model	= "towngirl5"; 
	ch.sex = "woman";
	ch.location = "Greenford_town";
	ch.location.group = "merchant";
	ch.location.locator = "merchant3";
	ch.dialog.filename = "Item Trader_Dialog.c";
	ch.nation = ENGLAND;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "6";
	ch.skill.Fencing = "3";
	ch.skill.Sailing = "4";
	ch.skill.Accuracy = "9";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "5";
	ch.skill.Repair = "6";
	ch.skill.Defence = "8";
	ch.skill.Commerce = "7";
	ch.skill.Sneak = "8";
	ch.quest.area = "Greenford";
	ch.money = "10";
	ch.greeting = "Gr_Woman_English Citizen";
	LAi_SetMerchantType(ch);
	LAi_SetHP(ch, 80.0, 80.0);

	n = n + 1;

	makeref(ch,Characters[n]);		//Уличный торговец в Greenford
	ch.name 	= "Street";
	ch.lastname 	= "Merchant";
	ch.id		= "Greenford_Street_merchant_4";
	ch.model	= "man3_1"; 
	ch.sex = "man";
	ch.location = "Greenford_town";
	ch.location.group = "merchant";
	ch.location.locator = "merchant4";
	ch.dialog.filename = "Item Trader_Dialog.c";
	ch.greeting = "Gr_Oxbay Citizen";
	ch.nation = ENGLAND;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "6";
	ch.skill.Fencing = "3";
	ch.skill.Sailing = "4";
	ch.skill.Accuracy = "9";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "5";
	ch.skill.Repair = "6";
	ch.skill.Defence = "8";
	ch.skill.Commerce = "7";
	ch.skill.Sneak = "8";
	ch.quest.area = "Greenford";
	ch.money = "10";
	LAi_SetMerchantType(ch);
	LAi_SetHP(ch, 80.0, 80.0);
	
	n = n + 1;

	return n;
}
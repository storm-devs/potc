void InitGoods()
{
	Goods[GOOD_BALLS].Name			= "Balls";
	Goods[GOOD_BALLS].Cost			= 2;
	Goods[GOOD_BALLS].Weight		= 3;
	Goods[GOOD_BALLS].Units			= 20;
	Goods[GOOD_BALLS].SpeedV0		= 1.0;
	Goods[GOOD_BALLS].DamageHull	= 10.0;
	Goods[GOOD_BALLS].DamageRig		= 5.0;
	Goods[GOOD_BALLS].DamageCrew	= 0.25;

	Goods[GOOD_GRAPES].Name			= "Grapes";
	Goods[GOOD_GRAPES].Cost			= 10;
	Goods[GOOD_GRAPES].Weight		= 2;
	Goods[GOOD_GRAPES].Units		= 20;
	Goods[GOOD_GRAPES].SpeedV0		= 0.5;
	Goods[GOOD_GRAPES].DamageHull	= 1.0;
	Goods[GOOD_GRAPES].DamageRig	= 1.0;
	Goods[GOOD_GRAPES].DamageCrew	= 1.5;
	
	Goods[GOOD_KNIPPELS].Name		= "Knippels";
	Goods[GOOD_KNIPPELS].Cost		= 20;
	Goods[GOOD_KNIPPELS].Weight		= 5;
	Goods[GOOD_KNIPPELS].Units		= 20;
	Goods[GOOD_KNIPPELS].SpeedV0	= 0.9;
	Goods[GOOD_KNIPPELS].DamageHull = 3.0;
	Goods[GOOD_KNIPPELS].DamageRig	= 20.0;
	Goods[GOOD_KNIPPELS].DamageCrew = 0.25;
	
	Goods[GOOD_BOMBS].Name			= "Bombs";
	Goods[GOOD_BOMBS].Cost			= 50;
	Goods[GOOD_BOMBS].Weight		= 3;
	Goods[GOOD_BOMBS].Units			= 20;
	Goods[GOOD_BOMBS].SpeedV0		= 0.8;
	Goods[GOOD_BOMBS].DamageHull	= 15.0;
	Goods[GOOD_BOMBS].DamageRig		= 5.0;
	Goods[GOOD_BOMBS].DamageCrew	= 0.5;

	Goods[GOOD_SAILCLOTH].Name		= "Sailcloth";
	Goods[GOOD_SAILCLOTH].Weight	= 3;
	Goods[GOOD_SAILCLOTH].Cost		= 3;
	Goods[GOOD_SAILCLOTH].Units		= 1;
	Goods[GOOD_SAILCLOTH].Swim.Model	= "roll_of_materials";
	Goods[GOOD_SAILCLOTH].Swim.Time		= 10;

	Goods[GOOD_PLANKS].Name		= "Planks";
	Goods[GOOD_PLANKS].Weight	= 4;
	Goods[GOOD_PLANKS].Cost		= 4;
	Goods[GOOD_PLANKS].Units	= 1;
	Goods[GOOD_PLANKS].Swim.Model	= "roll_of_planks";
	Goods[GOOD_PLANKS].Swim.Time	= 15;

	Goods[GOOD_WHEAT].Name		= "Wheat";
	Goods[GOOD_WHEAT].Weight	= 2;
	Goods[GOOD_WHEAT].Cost		= 4;
	Goods[GOOD_WHEAT].Units		= 1;
	Goods[GOOD_WHEAT].Swim.Model	= "sack";
	Goods[GOOD_WHEAT].Swim.Time		= 10;

	Goods[GOOD_EBONY].Name		= "Ebony";
	Goods[GOOD_EBONY].Weight	= 6;
	Goods[GOOD_EBONY].Cost		= 26;
	Goods[GOOD_EBONY].Units		= 1;

	Goods[GOOD_CHOCOLATE].Name		= "Chocolate";
	Goods[GOOD_CHOCOLATE].Weight	= 2;
	Goods[GOOD_CHOCOLATE].Cost		= 14;
	Goods[GOOD_CHOCOLATE].Units		= 1;
	Goods[GOOD_CHOCOLATE].Swim.Model	= "bale";
	Goods[GOOD_CHOCOLATE].Swim.Time		= 5;

	Goods[GOOD_SUGAR].Name		= "Sugar";
	Goods[GOOD_SUGAR].Weight	= 2;
	Goods[GOOD_SUGAR].Cost		= 6;
	Goods[GOOD_SUGAR].Units		= 1;

	Goods[GOOD_WINE].Name		= "Wine";
	Goods[GOOD_WINE].Weight	= 2;
	Goods[GOOD_WINE].Cost		= 10;
	Goods[GOOD_WINE].Units		= 1;

	Goods[GOOD_LINEN].Name		= "Linen";
	Goods[GOOD_LINEN].Weight	= 3;
	Goods[GOOD_LINEN].Cost		= 8;
	Goods[GOOD_LINEN].Units		= 1;
	Goods[GOOD_LINEN].Swim.Model	= "roll_of_rolls";
	Goods[GOOD_LINEN].Swim.Time		= 10;

	Goods[GOOD_RUM].Name		= "Rum";
	Goods[GOOD_RUM].Weight		= 1;
	Goods[GOOD_RUM].Cost		= 6;
	Goods[GOOD_RUM].Units		= 1;
	Goods[GOOD_RUM].Swim.Model	= "barrel";
	Goods[GOOD_RUM].Swim.Time	= 10;

	Goods[GOOD_TOBACCO].Name	= "Tobacco";
	Goods[GOOD_TOBACCO].Weight	= 4;
	Goods[GOOD_TOBACCO].Cost	= 12;
	Goods[GOOD_TOBACCO].Units	= 1;
	Goods[GOOD_TOBACCO].Swim.Model	= "bale";
	Goods[GOOD_TOBACCO].Swim.Time	= 5;

	Goods[GOOD_COFFEE].Name		= "Coffee";
	Goods[GOOD_COFFEE].Weight	= 2;
	Goods[GOOD_COFFEE].Cost		= 14;
	Goods[GOOD_COFFEE].Units	= 1;
	Goods[GOOD_COFFEE].Swim.Model	= "sack";
	Goods[GOOD_COFFEE].Swim.Time	= 5;

	Goods[GOOD_MAHOGANY].Name	= "Mahogany";
	Goods[GOOD_MAHOGANY].Weight	= 4;
	Goods[GOOD_MAHOGANY].Cost	= 16;
	Goods[GOOD_MAHOGANY].Units	= 1;
	Goods[GOOD_MAHOGANY].Swim.Model	= "roll_of_planks";
	Goods[GOOD_MAHOGANY].Swim.Time	= 15;

	Goods[GOOD_CINNAMON].Name	= "Cinnamon";
	Goods[GOOD_CINNAMON].Weight	= 2;
	Goods[GOOD_CINNAMON].Cost	= 16;
	Goods[GOOD_CINNAMON].Units	= 1;
	Goods[GOOD_CINNAMON].Swim.Model	= "bale";
	Goods[GOOD_CINNAMON].Swim.Time	= 5;

	Goods[GOOD_COPRA].Name		= "Copra";
	Goods[GOOD_COPRA].Weight	= 4;
	Goods[GOOD_COPRA].Cost		= 6;
	Goods[GOOD_COPRA].Units		= 1;
	Goods[GOOD_COPRA].Swim.Model	= "basket";
	Goods[GOOD_COPRA].Swim.Time		= 10;

	Goods[GOOD_PAPRIKA].Name	= "Paprika";
	Goods[GOOD_PAPRIKA].Weight	= 2;
	Goods[GOOD_PAPRIKA].Cost	= 12;
	Goods[GOOD_PAPRIKA].Units	= 1;
	Goods[GOOD_PAPRIKA].Swim.Model	= "box";
	Goods[GOOD_PAPRIKA].Swim.Time	= 5;

	Goods[GOOD_FRUITS].Name		= "Fruits";
	Goods[GOOD_FRUITS].Weight	= 3;
	Goods[GOOD_FRUITS].Cost		= 8;
	Goods[GOOD_FRUITS].Units	= 1;
	Goods[GOOD_FRUITS].Swim.Model	= "box";
	Goods[GOOD_FRUITS].Swim.Time	= 5;

	Goods[GOOD_ALE].Name	= "Ale";
	Goods[GOOD_ALE].Weight	= 1;
	Goods[GOOD_ALE].Cost	= 3;
	Goods[GOOD_ALE].Units	= 1;
	Goods[GOOD_ALE].Swim.Model	= "barrel";
	Goods[GOOD_ALE].Swim.Time	= 10;

	Goods[GOOD_SILK].Name	= "Silk";
	Goods[GOOD_SILK].Weight	= 4;
	Goods[GOOD_SILK].Cost	= 12;
	Goods[GOOD_SILK].Units	= 1;
	Goods[GOOD_SILK].Swim.Model	= "roll_of_rolls";
	Goods[GOOD_SILK].Swim.Time	= 10;

	Goods[GOOD_CLOTHES].Name	= "Clothes";
	Goods[GOOD_CLOTHES].Weight	= 3;
	Goods[GOOD_CLOTHES].Cost	= 8;
	Goods[GOOD_CLOTHES].Units	= 1;
	Goods[GOOD_CLOTHES].Swim.Model	= "bale";
	Goods[GOOD_CLOTHES].Swim.Time	= 10;

	Goods[GOOD_COTTON].Name		= "Cotton";
	Goods[GOOD_COTTON].Weight	= 3;
	Goods[GOOD_COTTON].Cost		= 6;
	Goods[GOOD_COTTON].Units	= 1;
	Goods[GOOD_COTTON].Swim.Model	= "bale";
	Goods[GOOD_COTTON].Swim.Time	= 5;

	Goods[GOOD_SANDAL].Name		= "Sandal";
	Goods[GOOD_SANDAL].Weight	= 4;
	Goods[GOOD_SANDAL].Cost		= 20;
	Goods[GOOD_SANDAL].Units	= 1;
	Goods[GOOD_SANDAL].Swim.Model	= "box";
	Goods[GOOD_SANDAL].Swim.Time	= 15;

	Goods[GOOD_LEATHER].Name	= "Leather";
	Goods[GOOD_LEATHER].Weight	= 4;
	Goods[GOOD_LEATHER].Cost	= 4;
	Goods[GOOD_LEATHER].Units	= 1;
	Goods[GOOD_LEATHER].Swim.Model	= "bale";
	Goods[GOOD_LEATHER].Swim.Time	= 10;

	Goods[GOOD_OIL].Name	= "Oil";
	Goods[GOOD_OIL].Weight	= 2;
	Goods[GOOD_OIL].Cost	= 5;
	Goods[GOOD_OIL].Units	= 1;
}


void extrnInitPerks()
{
	//	Combat Skills Group
	//==========================================================
	ChrPerksList.list.BasicDefense.descr = "perkBasicDefense";

	ChrPerksList.list.AdvancedDefense.descr = "perkAdvancedDefense";
	ChrPerksList.list.AdvancedDefense.condition.BasicDefense = true;

	ChrPerksList.list.SwordplayProfessional.descr = "perkSwordplayProfessional";
	ChrPerksList.list.SwordplayProfessional.condition.CriticalHit = true;
	ChrPerksList.list.SwordplayProfessional.condition.AdvancedDefense = true;

	ChrPerksList.list.Rush.descr = "perkRush";
	ChrPerksList.list.Rush.TimeDuration = 30;

	ChrPerksList.list.CriticalHit.descr = "perkCriticalHit";

	ChrPerksList.list.Gunman.descr = "perkGunman";

	ChrPerksList.list.GunProfessional.descr = "perkGunProfessional";
	ChrPerksList.list.GunProfessional.condition.Gunman = true;


	// Ship Combat Skills Group
	//===========================================================
	ChrPerksList.list.FastReload.descr = "perkFastReload";

	ChrPerksList.list.ImmediateReload.descr = "perkImmediateReload";
	ChrPerksList.list.ImmediateReload.condition.FastReload = true;
	ChrPerksList.list.ImmediateReload.TimeDelay = 300;

	ChrPerksList.list.HullDamageUp.descr = "perkHullDamageUp";

	ChrPerksList.list.SailsDamageUp.descr = "perkSailsDamageUp";

	ChrPerksList.list.CrewDamageUp.descr = "perkCrewDamageUp";

	ChrPerksList.list.CriticalShoot.descr = "perkCriticalShoot";
	ChrPerksList.list.CriticalShoot.condition.HullDamageUp = true;
	ChrPerksList.list.CriticalShoot.condition.SailsDamageUp = true;
	ChrPerksList.list.CriticalShoot.condition.CrewDamageUp = true;

	ChrPerksList.list.LongRangeShoot.descr = "perkLongRangeShoot";

	ChrPerksList.list.CannonProfessional.descr = "perkCannonProfessional";
	ChrPerksList.list.CannonProfessional.condition.CriticalShoot = true;
	ChrPerksList.list.CannonProfessional.condition.LongRangeShoot = true;
	ChrPerksList.list.CannonProfessional.condition.FastReload = true;

	ChrPerksList.list.LongRangeGrappling.descr = "perkLongRangeGrappling";

	//ChrPerksList.list.MusketsShoot.descr = "perkMusketsShoot";

	ChrPerksList.list.GrapplingProfessional.descr = "perkGrapplingProfessional";
	ChrPerksList.list.GrapplingProfessional.condition.LongRangeGrappling = true;
	//ChrPerksList.list.GrapplingProfessional.condition.MusketsShoot = true;

	ChrPerksList.list.InstantBoarding.descr = "perkInstantBoarding";
	ChrPerksList.list.InstantBoarding.condition.GrapplingProfessional = true;
	ChrPerksList.list.InstantBoarding.condition.SwordplayProfessional = true;
	ChrPerksList.list.InstantBoarding.condition.SailingProfessional = true;
	ChrPerksList.list.InstantBoarding.TimeDelay = -1;

	ChrPerksList.list.BasicBattleState.descr = "perkBasicBattleState";

	ChrPerksList.list.AdvancedBattleState.descr = "perkAdvancedBattleState";
	ChrPerksList.list.AdvancedBattleState.condition.BasicBattleState = true;

	ChrPerksList.list.ShipDefenseProfessional.descr = "perkShipDefenseProfessional";
	ChrPerksList.list.ShipDefenseProfessional.condition.AdvancedBattleState = true;



	// Ship Control Skills Group
	//================================================================
	ChrPerksList.list.LightRepair.descr = "perkLightRepair";
	ChrPerksList.list.LightRepair.TimeDelay = 60;

	ChrPerksList.list.InstantRepair.descr = "perkInstantRepair";
	ChrPerksList.list.InstantRepair.condition.LightRepair = true;

	ChrPerksList.list.ShipSpeedUp.descr = "perkShipSpeedUp";

	ChrPerksList.list.ShipTurnRateUp.descr = "perkShipTurnRateUp";

	ChrPerksList.list.StormProfessional.descr = "perkStormProfessional";

	ChrPerksList.list.Turn180.descr = "perkTurn180";
	ChrPerksList.list.Turn180.condition.ShipSpeedUp = true;
	ChrPerksList.list.Turn180.condition.ShipTurnRateUp = true;
	ChrPerksList.list.Turn180.TimeDelay = 180;

	ChrPerksList.list.SandbankManeuver.descr = "perkSandbankManeuver";
	ChrPerksList.list.SandbankManeuver.condition.Turn180 = true;
	ChrPerksList.list.SandbankManeuver.TimeDuration = 60;

	ChrPerksList.list.SailingProfessional.descr = "perkSailingProfessional";
	ChrPerksList.list.SailingProfessional.condition.SandbankManeuver = true;
	ChrPerksList.list.SailingProfessional.condition.StormProfessional = true;



	// Personal Abilities Skills Group
	//=================================================================
	ChrPerksList.list.IronWill.descr = "perkIronWill";

	ChrPerksList.list.SharedExperience.descr = "perkSharedExperience";

	ChrPerksList.list.Brander.descr = "perkBrander";

	//ChrPerksList.list.Troopers.descr = "perkTroopers";

	ChrPerksList.list.Trustworthy.descr = "perkTrustworthy";

	ChrPerksList.list.BasicCommerce.descr = "perkBasicCommerce";

	ChrPerksList.list.AdvancedCommerce.descr = "perkAdvancedCommerce";
	ChrPerksList.list.AdvancedCommerce.condition.BasicCommerce = true;
}

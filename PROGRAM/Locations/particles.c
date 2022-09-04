



void CreateParticles(ref Location)
{
	aref locator_group;
	aref locator;
	int n;
	int num;
	
	// DumpAttributes(Location);


	if(!CheckAttribute(Location, "locators")) return;

	if(CheckAttribute(Location, "locators.smoke"))
	{
		makearef(locator_group, location.locators.smoke);
		num = GetAttributesNum(locator_group);
		for(n = 0; n < num; n++)
		{
			locator = GetAttributeN(locator_group, n);
			if(frnd() < 0.3 ) CreateParticleSystem("smoke",stf(locator.x),stf(locator.y),stf(locator.z),-1.57,0,0,0);
			
			

		}
	}

	if(CheckAttribute(Location, "locators.fire"))
	{
		makearef(locator_group, location.locators.fire);
		num = GetAttributesNum(locator_group);
		for(n = 0; n < num; n++)
		{
			locator = GetAttributeN(locator_group, n);
			CreateParticleSystem("fire",stf(locator.x),stf(locator.y),stf(locator.z),-1.57,0,0,0);
		}
	}

	if(CheckAttribute(Location, "locators.heaters_p"))
	{
		makearef(locator_group, location.locators.heaters_p);
		num = GetAttributesNum(locator_group);
		for(n = 0; n < num; n++)
		{
			locator = GetAttributeN(locator_group, n);
			CreateParticleSystem("fire",stf(locator.x),stf(locator.y),stf(locator.z),-1.57,0,0,0);
		}
	}


/*	if(CheckAttribute(Location, "locators.waterfall"))
	{
		makearef(locator_group, location.locators.waterfall);
		num = GetAttributesNum(locator_group);
		for(n = 0; n < num; n++)
		{
			locator = GetAttributeN(locator_group, n);
			CreateParticleSystemX("waterfall",stf(locator.x),stf(locator.y),stf(locator.z),
				stf(locator.vz.x),stf(locator.vz.y),stf(locator.vz.z),0);
		}
	}
*/
	if(CheckAttribute(Location, "locators.candles_p"))
	{
		makearef(locator_group, location.locators.candles_p);
		num = GetAttributesNum(locator_group);
		for(n = 0; n < num; n++)
		{
			locator = GetAttributeN(locator_group, n);
			CreateParticleSystem("candle",stf(locator.x),stf(locator.y) + 0.04,stf(locator.z),-1.57,0,0,0);
		}
	}

	if(CheckAttribute(Location, "locators.torchlightes_p"))
	{
		makearef(locator_group, location.locators.torchlightes_p);
		num = GetAttributesNum(locator_group);
		for(n = 0; n < num; n++)
		{
			locator = GetAttributeN(locator_group, n);
			CreateParticleSystem("torch",stf(locator.x),stf(locator.y) - 0.07,stf(locator.z),-1.57,0,0,0);
		}
	}

	if(CheckAttribute(Location, "locators.torchlightes_o_p") && Whr_IsLight() != 0)
	{
		makearef(locator_group, location.locators.torchlightes_o_p);
		num = GetAttributesNum(locator_group);
		for(n = 0; n < num; n++)
		{
			locator = GetAttributeN(locator_group, n);
			CreateParticleSystem("torch",stf(locator.x),stf(locator.y) - 0.07,stf(locator.z),-1.57,0,0,0);
		}
	}

/*	if(CheckAttribute(Location, "locators.reload"))
	{
		makearef(locator_group, location.locators.reload);
		num = GetAttributesNum(locator_group);
		for(n = 0; n < num; n++)
		{
			locator = GetAttributeN(locator_group, n);
			CreateParticleSystem("fire_mix",stf(locator.x),stf(locator.y),stf(locator.z),-1.57,0,0,0);
		}
	}
*/
/*	if(CheckAttribute(Location, "locators.fountains"))
	{
		makearef(locator_group, location.locators.fountains);
		num = GetAttributesNum(locator_group);
		for(n = 0; n < num; n++)
		{
			locator = GetAttributeN(locator_group, n);
			CreateParticleSystem("fountain",stf(locator.x),stf(locator.y),stf(locator.z),-1.57,0,0,0);
			//CreateParticleSystemX("fountain",stf(locator.x),stf(locator.y),stf(locator.z),
			//	stf(locator.vz.x),stf(locator.vz.y),stf(locator.vz.z),0);
		}
	}
*/	
	if(CheckAttribute(Location, "locators.Waterfog"))
	{
		makearef(locator_group, location.locators.waterfog);
		num = GetAttributesNum(locator_group);
		for(n = 0; n < num; n++)
		{
			locator = GetAttributeN(locator_group, n);
			CreateParticleSystemX("waterfog",stf(locator.x),stf(locator.y),stf(locator.z),
				stf(locator.vz.x),stf(locator.vz.y),stf(locator.vz.z),0);
		}
	}

	if(CheckAttribute(Location, "locators.Waterfogfall"))
	{
		makearef(locator_group, location.locators.waterfogfall);
		num = GetAttributesNum(locator_group);
		for(n = 0; n < num; n++)
		{
			locator = GetAttributeN(locator_group, n);
			CreateParticleSystemX("waterfog_fall",stf(locator.x),stf(locator.y),stf(locator.z),
				stf(locator.vz.x),stf(locator.vz.y),stf(locator.vz.z),0);
		}
	}

	if(CheckAttribute(Location, "locators.stars"))
	{
		makearef(locator_group, location.locators.stars);
		num = GetAttributesNum(locator_group);
		for(n = 0; n < num; n++)
		{
			locator = GetAttributeN(locator_group, n);
			CreateParticleSystemX("stars",stf(locator.x),stf(locator.y),stf(locator.z),
				stf(locator.vz.x),stf(locator.vz.y),stf(locator.vz.z),0);
		}
	}

	Particles.winddirection.y = 0;
}



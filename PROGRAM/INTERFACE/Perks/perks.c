
#event_handler("evntChrPerkDelay","procChrPerkDelay");

object ChrPerksList;

extern void extrnInitPerks();

void InitPerks()
{
	if( LoadSegment("interface\perks\perks_init.c") )
	{
		extrnInitPerks();
		UnloadSegment("interface\perks\perks_init.c");
	}
}

bool CheckCharacterPerk(ref chref, string perkName)
{
	if( CheckAttribute(chref,"perks.list."+perkName) ) return true;
	return false;
}

void ActivateCharacterPerk(ref chref, string perkName)
{
	if( !CheckAttribute(&ChrPerksList,"list."+perkName) )
	{
		trace("Invalid perk name - " + perkName);
		return;
	}

	int timeDelay = 0;
	int timeDuration = 0;

	if( CheckAttribute(&ChrPerksList,"list."+perkName+".TimeDuration") )
	{	timeDelay = sti(ChrPerksList.list.(perkName).TimeDuration);
		timeDuration = timeDelay;
	}
	if( CheckAttribute(&ChrPerksList,"list."+perkName+".TimeDelay") )
	{	timeDelay = sti(ChrPerksList.list.(perkName).TimeDelay);
		if(timeDuration<=0)	{timeDuration=timeDelay;}
	}

	chref.perks.list.(perkName).delay = timeDelay;
	chref.perks.list.(perkName).active = timeDuration;

	if(sti(chref.index)==GetMainCharacterIndex())
	{
		AddPerkToActiveList(perkName);
	}

	if(timeDelay>0) PostEvent("evntChrPerkDelay",1000,"sl",perkName,sti(chref.index));
	Event("eSwitchPerks","l",sti(chref.index));
}

bool GetCharacterPerkUsing(ref chref, string perkName)
{
	if( !CheckAttribute(chref,"perks.list."+perkName) ) return false;
	if( CheckAttribute(chref,"perks.list."+perkName+".delay") ) return false;
	return true;
}

bool GetOfficersPerkUsing(ref chref, string perkName)
{
	for(int i=0; i<4; i++)
	{
		int cn = GetOfficersIndex(chref,i);
		if(cn<0) {continue;}
		if( GetCharacterPerkUsing(&Characters[cn], perkName) ) {return true;}
	}
	return false;
}

bool IsCharacterPerkOn(ref chref, string perkName)
{
	aref arRoot, arBase;
	makearef(arRoot,chref.perks.list);
	if( !CheckAttribute(arRoot,perkName) ) return false;
	makearef(arBase,ChrPerksList.list.(perkName));
	if( CheckAttribute(arBase,"TimeDuration") || CheckAttribute(arBase,"TimeDelay") ) {
		return CheckAttribute(arRoot,perkName+".active");
	}
	return true;
}

void CharacterPerkOff(ref chref, string perkName)
{
	DeleteAttribute(chref,"perks.list."+perkName+".active");
	Event("eSwitchPerks","l",sti(chref.index));
	if(sti(chref.index)==GetMainCharacterIndex())
	{
		DelPerkFromActiveList(perkName);
	}
}

bool CheckOfficersPerk(ref chref, string perkName)
{
	int i,cn;
	for(i=0; i<4; i++)
	{
		cn = GetOfficersIndex(chref,i);
		if(cn>=0)
		{	if( IsCharacterPerkOn(GetCharacter(cn),perkName) )	{return true;}
		}
	}
	return false;
}

bool CheckCompanionsPerk(ref chref, string perkName)
{
	int i,cn;
	for(i=0; i<4; i++)
	{
		cn = GetCompanionIndex(chref,i);
		if(cn>=0)
		{	if( IsCharacterPerkOn(GetCharacter(cn),perkName) )	{return true;}
		}
	}
}

void procChrPerkDelay()
{
	string perkName = GetEventData();
	int chrIdx = GetEventData();

	aref arPerk;
	makearef(arPerk,Characters[chrIdx].perks.list.(perkName));
	if( !CheckAttribute(arPerk,"delay") ) return;
	int delay = sti(arPerk.delay);
	delay--;

	if( CheckAttribute(arPerk,"active") )
	{
		int iActive = sti(arPerk.active)-1;
		if( iActive>0 )	{arPerk.active = iActive;}
		else
		{
			CharacterPerkOff(GetCharacter(chrIdx),perkName);
		}
	}

	if( delay<=0 )
	{	DeleteAttribute(&Characters[chrIdx],"perks.list."+perkName+".delay");
		DeleteAttribute(&Characters[chrIdx],"perks.list."+perkName+".active");
		PostEvent("evntPerkAgainUsable",1);
	}
	else
	{
		Characters[chrIdx].perks.list.(perkName).delay = delay;
		PostEvent("evntChrPerkDelay",1000,"sl",perkName,chrIdx);
	}
}

void EnableUsingAbility(ref chref,string perkName)
{
	Event("evntChrPerkDelay","sl",perkName,sti(chref.index));
}

void PerkLoad()
{
//	int iRDTSC = RDTSC_B();

	ref mainCh = GetMainCharacter();
	string locName = mainCh.location;
	aref arPerksRoot,arPerk;
	int i,j,n,tmpi;

	for(i=0; i<MAX_CHARACTERS; i++)
	{
		if(Characters[i].location == locName)
		{
			makearef(arPerksRoot,Characters[i].perks.list);
			n = GetAttributesNum(arPerksRoot);
			for(j=0; j<n; j++)
			{
				arPerk = GetAttributeN(arPerksRoot,j);
				if( CheckAttribute(arPerk,"delay") )
				{
					tmpi = sti(arPerk.delay);
					if( tmpi>0 )
					{
						PostEvent("evntChrPerkDelay",1000,"sl",GetAttributeName(arPerk),i);
					}
				}
			}
		}
	}

//	trace("TIME!!! PerkLoad() = " + RDTSC_E(iRDTSC));
}

void ClearActiveChrPerks(ref chref)
{
	aref arPerksRoot, arPerk;
	int i,n,j,cn;

	for(j=0; j<4; j++)
	{
		cn = GetOfficersIndex(chref,j);
		if( cn<0 ) {continue;}
		makearef( arPerksRoot, Characters[cn].perks.list );
		n = GetAttributesNum(arPerksRoot);
		for(i=0; i<n; i++)
		{
			arPerk = GetAttributeN(arPerksRoot,i);
			if( CheckAttribute(arPerk,"delay") ) {
				DeleteAttribute(arPerk,"delay");
			}
			if( CheckAttribute(arPerk,"active") ) {
				DeleteAttribute(arPerk,"active");
			}
		}
	}
}

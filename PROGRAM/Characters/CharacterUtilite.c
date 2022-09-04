#define FELLOWTRAVEL_NO			0
#define FELLOWTRAVEL_CAPTIVE	1
#define FELLOWTRAVEL_PASSENGER	2
#define FELLOWTRAVEL_OFFICER	3
#define FELLOWTRAVEL_COMPANION	4

#define EVENT_CHANGE_OFFICERS	"EvntChangeOfficers"
#define EVENT_CHANGE_COMPANIONS	"EvntChangeCompanions"

#define MAX_ITEM_TAKE	256

#define MSGICON_ACTIVE_TIME 10
#define MSGICON_LEVELUP	0
#define MSGICON_LOGBOOK	1
#define MSGICON_GETITEM	2

#event_handler("evnt_MsgIconTick","proc_MsgIconTick");

bool GetShipRemovable(ref _refCharacter)
{
	if( CheckAttribute(_refCharacter,"ShipRemovable") && sti(_refCharacter.ShipRemovable)==false ) return false;
	return true;
}

void SetShipRemovable(ref _refCharacter, bool bRemovable)
{
	if(bRemovable) DeleteAttribute(_refCharacter,"ShipRemovable");
	else _refCharacter.ShipRemovable = false;
}

//
bool CharacterIsDead(ref _refCharacter)
{
	return LAi_IsDead(_refCharacter);
}

bool IsCompanion(ref _refCharacter)
{
	int findIdx = sti(_refCharacter.index);
	ref mc = GetMainCharacter();
	for(int i=0; i<4; i++)
	{
		if(GetCompanionIndex(mc,i)==findIdx) return true;
	}
	return false;
}

bool IsOfficer(ref _refCharacter)
{
	int findIdx = sti(_refCharacter.index);
	ref mc = GetMainCharacter();
	for(int i=0; i<4; i++)
	{
		if(GetOfficersIndex(mc,i)==findIdx) return true;
	}
	return false;
}

void SetCharacterRemovable(ref _refCharacter,bool removable)
{
	if(removable) DeleteAttribute(_refCharacter,"NonRemovable");
	else _refCharacter.NonRemovable = true;
}

bool GetRemovable(ref _refCharacter)
{
	if( CheckAttribute(_refCharacter,"NonRemovable") ) return !sti(_refCharacter.NonRemovable);
	return true;
}

// Cargo utilites
//------------------------------------------
int GetCargoLoad(ref _refCharacter)
{
	if(!CheckAttribute(_refCharacter,"Ship.Cargo.Load")) return 0;
	return sti(_refCharacter.Ship.Cargo.Load);
}

int RecalculateCargoLoad(ref _refCharacter)
{
	if(!CheckAttribute(_refCharacter,"Ship.Cargo.Load")) return 0;
	int loadSpace = 0;
	for(int i=0; i<GOODS_QUANTITY; i++)
	{
		loadSpace = loadSpace + GetGoodWeightByType(i,GetCargoGoods(_refCharacter,i));
	}
	_refCharacter.Ship.Cargo.Load = loadSpace;
	return loadSpace;
}

int GetCargoFreeSpace(ref _refCharacter)
{
	if(!CheckAttribute(_refCharacter,"Ship.Cargo.Load")) return 0;
	int freeSpace = GetCargoMaxSpace(&_refCharacter) - GetCargoLoad(_refCharacter);
	return freeSpace;
}

int GetCargoMaxSpace(ref _refCharacter)
{
	if( !CheckAttribute(_refCharacter,"Ship.Type") ) return 0;
	int _ShipType = sti(_refCharacter.Ship.Type);
	if( _ShipType==SHIP_NOTUSED )
		return 0;
	return sti(ShipsTypes[_ShipType].Capacity);
}

int GetCharacterFreeSpace(ref _refCharacter,int _Goods)
{
	int weight = sti(Goods[_Goods].weight);
	int unitQ = sti(Goods[_Goods].Units);

	int retVal = unitQ * (GetCargoFreeSpace(&_refCharacter)/weight);
	return retVal;
}

int GetSquadronFreeSpace(ref _refCharacter,int _Goods)
{
	int weight = sti(Goods[_Goods].weight);
	int unitQ = sti(Goods[_Goods].Units);

	int retVal = unitQ * (GetCargoFreeSpace(&_refCharacter)/weight);
	int i,cn;
	for(i=1; i<4; i++)
	{
		cn = GetCompanionIndex(&_refCharacter,i);
		if(cn!=-1)
		{
			
			retVal = retVal + unitQ*(GetCargoFreeSpace(&Characters[cn])/weight);
		}
	}
	return retVal;
}

int GetCargoGoods(ref _refCharacter,int _Goods)
{
	string goodsName = Goods[_Goods].name;
	if(!CheckAttribute(_refCharacter,"Ship.Cargo.Goods."+goodsName))
		return 0;
	return sti(_refCharacter.Ship.Cargo.Goods.(goodsName));
}

int GetSquadronGoods(ref _refCharacter,int _Goods)
{
	int i,cn;
	int retVal = GetCargoGoods(&_refCharacter,_Goods);
	for(i=1; i<4; i++)
	{
		cn = GetCompanionIndex(&_refCharacter,i);
		if(cn!=-1)
		{
			retVal = retVal + GetCargoGoods(&Characters[cn],_Goods);
		}
	}
	return retVal;
}

void SetCharacterGoods(ref _refCharacter,int _Goods,int _Quantity)
{
	string goodsName = Goods[_Goods].name;
	_refCharacter.Ship.Cargo.Goods.(goodsName) = _Quantity;
	int curLoad = RecalculateCargoLoad(_refCharacter);
	int maxLoad = GetCargoMaxSpace(_refCharacter);
	if(curLoad>maxLoad)
	{
		Trace("ERROR! Cargo space overup (character=" + _refCharacter.index + ",Quantity=" + _Quantity + ")");
	}
}

int AddCharacterGoods(ref _refCharacter,int _Goods,int _Quantity)
{
	int i,cn,freeQuantity;
	string goodsName = Goods[_Goods].name;

	for(i=0; i<4; i++)
	{
		cn = GetCompanionIndex(_refCharacter,i);
		if(cn!=-1)
		{
			freeQuantity = GetGoodQuantityByWeight( _Goods, GetCargoFreeSpace(&Characters[cn]) );
			if(freeQuantity>=_Quantity)
			{
				Characters[cn].Ship.Cargo.Goods.(goodsName) = sti(Characters[cn].Ship.Cargo.Goods.(goodsName)) + _Quantity;
				RecalculateCargoLoad(&Characters[cn]);
				return true;
			}
			Characters[cn].Ship.Cargo.Goods.(goodsName) = sti(Characters[cn].Ship.Cargo.Goods.(goodsName)) + freeQuantity;
			_Quantity = _Quantity - freeQuantity;
			RecalculateCargoLoad(&Characters[cn]);
		}
	}
	Trace("Overup cargo space on "+_Quantity);
	return false;
}

void AddAmmoGoods(ref _refCharacter,int _Goods,int _Quantity)
{
	string goodsName = Goods[_Goods].name;
	int oldQ = 0;
	if( CheckAttribute(_refCharacter,"Ship.Cargo.Goods."+goodsName) ) {
		oldQ = sti(_refCharacter.Ship.Cargo.Goods.(goodsName));
	}
	int newQ = oldQ + _Quantity;
	int delta = newQ/20 - oldQ/20;
	if( delta==0) return;
	int nCargoLoad = 0;
	if( CheckAttribute(_refCharacter, "Ship.Cargo.Load") ) {
		nCargoLoad = sti(_refCharacter.Ship.Cargo.Load);
	}
	_refCharacter.Ship.Cargo.Load = nCargoLoad + delta*sti(Goods[_Goods].Weight);
}

int RemoveCharacterGoods(ref _refCharacter,int _Goods,int _Quantity)
{
	int i,cn,curQuantity;
	string goodsName = Goods[_Goods].name;

	for(i=0; i<4; i++)
	{
		cn = GetCompanionIndex(_refCharacter,i);
		if(cn!=-1)
		{
			curQuantity = sti( Characters[cn].Ship.Cargo.Goods.(goodsName) );
			if(curQuantity>=_Quantity)
			{
				Characters[cn].Ship.Cargo.Goods.(goodsName) = curQuantity - _Quantity;
				RecalculateCargoLoad(&Characters[cn]);
				return true;
			}
			Characters[cn].Ship.Cargo.Goods.(goodsName) = 0;
			_Quantity = _Quantity - curQuantity;
			RecalculateCargoLoad(&Characters[cn]);
		}
	}
	Trace("Overup cargo space on "+_Quantity);
	return false;
}

// Cannons utilite
int GetCaracterShipCannonsType(ref _refCharacter)
{
	if(!CheckAttribute(_refCharacter,"Ship.Cannons.Type")) return CANNON_TYPE_NONECANNON;
	return sti(_refCharacter.Ship.Cannons.Type);
}
int GetCannonQuantity(ref refCharacter)
{
	int nShipType = GetCharacterShipType(refCharacter);
	if(nShipType==SHIP_NOTUSED) return 0;
	ref rShip = GetShipByType(nShipType);
	return sti(rShip.CannonsQuantity);
}
int GetMaximumCaliber(ref refCharacter)
{
	int nShipType = GetCharacterShipType(refCharacter);
	if(nShipType==SHIP_NOTUSED) return 0;
	ref rShip = GetShipByType(nShipType);
	return sti(rShip.MaxCaliber);
}

// Ship utilite
int GetCharacterShipType(ref _refCharacter)
{
	if(CheckAttribute(_refCharacter,"Ship.Type"))
	{
		int iShipType = sti(_refCharacter.Ship.Type);
		if(iShipType>=0 && iShipType<SHIP_TYPES_QUANTITY_WITH_FORT)	return iShipType;
	}
	return SHIP_NOTUSED;
}
int GetCharacterShipHP(ref _refCharacter)
{
	int nShipType = GetCharacterShipType(_refCharacter);
	if(nShipType==SHIP_NOTUSED) return 0;
	return sti(ShipsTypes[nShipType].HP);
}
int GetCurrentShipHP(ref _refCharacter)
{
	if( CheckAttribute(_refCharacter,"ship.hp") ) return sti(_refCharacter.ship.hp);
	return 0;
}
int GetCharacterShipSP(ref _refCharacter)
{
	int nShipType = GetCharacterShipType(_refCharacter);
	if(nShipType==SHIP_NOTUSED) return 0;
	return sti(ShipsTypes[nShipType].SP);
}
string GetShipTypeName(ref _refCharacter)
{
	int nShipType = GetCharacterShipType(_refCharacter);
	if(nShipType==SHIP_NOTUSED) return SHIP_NOTUSED_TYPE_NAME;
	return ShipsTypes[nShipType].Name;
}
int GetCharacterShipClass(ref _refCharacter)
{
	int nShipType = GetCharacterShipType(_refCharacter);
	if( nShipType==SHIP_NOTUSED ) return -1;
	return sti(ShipsTypes[nShipType].Class);
}
int GetMaxCrewQuantity(ref _refCharacter)
{
	if(!CheckAttribute(_refCharacter,"Ship.Type")) return 0;
	int shipType = sti(_refCharacter.Ship.Type);
	if(shipType<0) return 0;
	if(shipType>=SHIP_TYPES_QUANTITY) return 0;
	return sti(ShipsTypes[shipType].MaxCrew);
}
int GetMinCrewQuantity(ref _refCharacter)
{
	if(!CheckAttribute(_refCharacter,"Ship.Type")) return 0;
	int shipType = sti(_refCharacter.Ship.Type);
	if(shipType<0) return 0;
	if(shipType>=SHIP_TYPES_QUANTITY) return 0;
	return sti(ShipsTypes[shipType].MinCrew);
}
int GetFreeCrewQuantity(ref _refCharacter)
{
	return (GetMaxCrewQuantity(_refCharacter)-GetCrewQuantity(_refCharacter));
}
int GetFreePartyCrewQuantity(ref _refCharacter)
{
	int cn;
	int sumCrew = 0;
	for(int i=0; i<4; i++)
	{
		cn = GetCompanionIndex(_refCharacter,i);
		if(cn!=-1)
		{
			sumCrew = sumCrew + GetFreeCrewQuantity(GetCharacter(cn));
		}
	}
	return sumCrew;
}
int GetCrewQuantity(ref _refCharacter)
{
	if(!CheckAttribute(_refCharacter,"Ship.Crew.Quantity")) return 0;
	return sti(_refCharacter.Ship.Crew.Quantity);
}
int SetCrewQuantity(ref _refCharacter,int num)
{
	int maxCrew = GetMaxCrewQuantity(_refCharacter);
	if(num>maxCrew)
	{
		Trace("Error!!! Overup maximum crew quantity (character=" + _refCharacter.index + ")");
		_refCharacter.Ship.Crew.Quantity = maxCrew;
		return false;
	}
	_refCharacter.Ship.Crew.Quantity = num;
	return true;
}
int AddCharacterCrew(ref _refCharacter,int num)
{
	return SetCrewQuantity(_refCharacter,GetCrewQuantity(_refCharacter)+num);
}
int RemoveCharacterCrew(ref _refCharacter,int num)
{
	int curCrew = GetCrewQuantity(_refCharacter);
	if(curCrew<num)
	{
		Trace("Error!!! Remove overup crew (character=" + _refCharacter.index + ")");
		SetCrewQuantity(_refCharacter,0);
		return false;
	}
	SetCrewQuantity(_refCharacter,curCrew-num);
	return true;
}
float GetSailPercent(ref _refCharacter)
{
	if( !CheckAttribute(_refCharacter,"Ship.SP") ) return 100.0;
	int iSP = GetCharacterShipSP(_refCharacter);
	if(iSP<=0) return 100.0;
	float fpsp = 100.0*stf(_refCharacter.Ship.SP)/iSP;
	return fpsp;
}
float GetHullPercent(ref _refCharacter)
{
	if(!CheckAttribute(_refCharacter,"Ship.HP")) return 100.0;
	int iHP = GetCharacterShipHP(_refCharacter);
	if(iHP<=0) return 100.0;
	float fphp = 100.0*stf(_refCharacter.Ship.HP)/iHP;
	return fphp;
}
float GetSailRPD(ref _refCharacter) // процент ремонта парусов в день
{
	int repairSkill = GetSummonSkillFromName(_refCharacter,SKILL_REPAIR);
	float damagePercent = 100.0 - GetSailPercent(_refCharacter);
	if(damagePercent==0.0) return 0.0;
	return repairSkill*10.0 / damagePercent;
}
float GetHullRPD(ref _refCharacter) // процент ремонта корпуса в день
{
	int repairSkill = GetSummonSkillFromName(_refCharacter,SKILL_REPAIR);
	float damagePercent = 100.0 - GetHullPercent(_refCharacter);
	if(damagePercent==0.0) return 0.0;
	return repairSkill*10.0 / damagePercent;
}
int GetSailSPP(ref _refCharacter) // количество парусины на один процент починки
{
	return 8-GetCharacterShipClass(_refCharacter);
}
int GetHullPPP(ref _refCharacter) // количество досок на один процент починки
{
	return 8-GetCharacterShipClass(_refCharacter);
}

// Fellowtravels utilites
// работа с пассажирами
int GetPassengersQuantity(ref _refCharacter)
{
	if(!CheckAttribute(_refCharacter,"Fellows.Passengers.Quantity")) return 0;
	return sti(_refCharacter.Fellows.Passengers.Quantity);
}
int GetPassenger(ref _refCharacter,int idx)
{
	if(idx<0) return -1;
	if(idx>=GetPassengersQuantity(_refCharacter)) return -1;

	string PsgAttrName = "id"+(idx+1);
	if(!CheckAttribute(_refCharacter,"Fellows.Passengers."+PsgAttrName)) return -1;
	return sti(_refCharacter.Fellows.Passengers.(PsgAttrName));
}
int GetPassengerNumber(ref _refCharacter,int findCharacterIdx)
{
	int psgQuant = GetPassengersQuantity(_refCharacter);
	int cn;
	ref cr;
	for(int i=0; i<psgQuant; i++)
	{
		cn = GetPassenger(_refCharacter,i);
		if(cn==-1) break;
		cr = GetCharacter(cn);
		if(findCharacterIdx==sti(cr.index)) return i;
	}
	return -1;
}
int GetNotCaptivePassenger(ref _refCharacter,int idx)
{
	if(idx<0) return -1;
	int psgQuant = GetPassengersQuantity(_refCharacter);

	int curIdx=0;
	ref curChar;
	int cn;
	for(int i=0;i<psgQuant;i++)
	{
		cn = GetPassenger(_refCharacter,i);
		if(cn==-1) break;

		curChar = GetCharacter(cn);
		if(CheckAttribute(curChar,"prisoned"))
		{
			if(sti(curChar.prisoned)==true) continue;
		}
		if(curIdx==idx)	return sti(curChar.index);
		curIdx++;
	}
	return -1;
}
int ChangePassenger(ref _refCharacter,int idx, int psngIdx)
{
	int retVal = GetPassenger(&_refCharacter,idx);
	if(idx>=0)
	{
		string PsgAttrName = "id"+(idx+1);
		_refCharacter.Fellows.Passengers.(PsgAttrName) = psngIdx;
	}
	return retVal;
}
int AddPassenger(ref _refCharacter,ref _refPassenger, int prisonFlag)
{
	int PsgQuantity = GetPassengersQuantity(_refCharacter);
	if(PsgQuantity<PASSENGERS_MAX)
	{
		aref tmpRef; makearef(tmpRef,_refCharacter.Fellows.Passengers);
		string PsgAttrName;
		for(int i=0;i<PsgQuantity;i++)
		{
			PsgAttrName = "id"+(i+1);
			if(tmpRef.(PsgAttrName)==_refPassenger.index) return PsgQuantity;
		}
		PsgQuantity++;
		tmpRef.Quantity = PsgQuantity;
		PsgAttrName = "id"+PsgQuantity;
		tmpRef.(PsgAttrName) = _refPassenger.index;
		if(prisonFlag==true)	_refPassenger.prisoned = true;
	}
	else	trace("Overup maximum passengers quantity");
	return PsgQuantity;
}
int RemovePassenger(ref _refCharacter,ref _refPassenger)
{
	RemoveOfficersIndex(_refCharacter,sti(_refPassenger.index));
	int PsgQuantity = GetPassengersQuantity(_refCharacter);
	int psgNum = GetPassengerNumber(_refCharacter,sti(_refPassenger.index));
	if(psgNum==-1) return PsgQuantity;

	aref tmpRef;
	makearef(tmpRef,_refCharacter.Fellows.Passengers);
	string inPsgAttrName,outPsgAttrName;
	for(int i=(psgNum+1); i<PsgQuantity; i++)
	{
		inPsgAttrName = "id"+i;
		outPsgAttrName = "id"+(i+1);
		tmpRef.(inPsgAttrName) = tmpRef.(outPsgAttrName);
	}

	outPsgAttrName = "id"+PsgQuantity;
	DeleteAttribute(tmpRef,outPsgAttrName);
	PsgQuantity--;
	tmpRef.Quantity = PsgQuantity;
	return PsgQuantity;
}
int FindFellowtravellers(ref _refCharacter,ref _refFindCharacter)
{
	int i;
	string stmp;
	aref atmp;
	aref curref;

	if(sti(_refFindCharacter.index)==-1) return FELLOWTRAVEL_NO;
	if(CheckAttribute(_refFindCharacter,"prisoned"))
	{
		if(sti(_refFindCharacter.prisoned)==true) return FELLOWTRAVEL_CAPTIVE;
	}
	for(i=1;i<4;i++)
	{
		if( sti(_refFindCharacter.index) == GetOfficersIndex(_refCharacter,i) )	return FELLOWTRAVEL_OFFICER;
	}
	for(i=0;i<GetPassengersQuantity(_refCharacter);i++)
	{
		if(sti(_refFindCharacter.index)==GetPassenger(_refCharacter,i))	return FELLOWTRAVEL_PASSENGER;
	}
	for(i=1;i<4;i++)
	{
		if( GetCompanionIndex(_refCharacter,i)==sti(_refFindCharacter.index) )	return FELLOWTRAVEL_COMPANION;
	}
	return FELLOWTRAVEL_NO;
}

// работа с компаньонами
int SetCompanionIndex(ref _refCharacter,int _CompanionNum, int _CompanionIdx)
{
    if(_CompanionNum == -1)
	{
		for(int i=1; i<4; i++)	
		{
			if (GetCompanionIndex(_refCharacter, i) == -1)
			{
				_CompanionNum = i;
				break;
			}
		}
	}
	if(_CompanionNum<1) return _CompanionIdx;
	if(_CompanionNum>3) return _CompanionIdx;

	if(_CompanionIdx!=-1)
	{
		for(i=0;i<4;i++)
		{
			if(GetCompanionIndex(_refCharacter,i)==_CompanionIdx) return -1;
		}
	}

	string compName = "id"+_CompanionNum;
	int retVal = GetCompanionIndex(_refCharacter,_CompanionNum);
	_refCharacter.Fellows.Companions.(compName) = _CompanionIdx;

	if( _CompanionIdx>=0 && CheckAttribute(&Characters[_CompanionIdx],"nation") ) {
		Characters[_CompanionIdx].prev_nation = Characters[_CompanionIdx].nation;
		Characters[_CompanionIdx].nation = _refCharacter.nation;
	}
	if( retVal>=0 && CheckAttribute(&Characters[retVal],"prev_nation") ) {
		Characters[retVal].nation = Characters[retVal].prev_nation;
	}

	Event(EVENT_CHANGE_COMPANIONS,"");
	return retVal;
}
int RemoveCharacterCompanion(ref _refCharacter, ref refCompanion)
{
	string compName;
	int i;

	aref refComps;
	makearef(refComps,_refCharacter.Fellows.Companions);
	for(i=1; i<4; i++)
	{
		compName = "id"+i;
		if(CheckAttribute(refComps,compName) && refComps.(compName)==refCompanion.index)
		{
			refComps.(compName) = -1;
			refCompanion.location = _refCharacter.location;
			refCompanion.location.group = _refCharacter.location.group;
			refCompanion.location.locator = _refCharacter.location.locator;
			Event(EVENT_CHANGE_COMPANIONS,"");
			return i;
		}
	}
	return -1;
}
int GetCompanionIndex(ref _refCharacter,int _CompanionNum)
{
	if(_CompanionNum<0) return -1;
	if(_CompanionNum>3) return -1;
	if(_CompanionNum==0) return sti(_refCharacter.index);

	string compName = "id"+_CompanionNum;
	if(!CheckAttribute(_refCharacter,"Fellows.Companions."+compName)) return -1;
	return sti(_refCharacter.Fellows.Companions.(compName));
}
int GetCompanionNumber(ref _refCharacter,int _CompanionIdx)
{
	for(int i=0; i<4; i++)
	{
		if( GetCompanionIndex(_refCharacter,i) == _CompanionIdx ) return i;
	}
	return -1;
}
int GetCompanionQuantity(ref _refCharacter)
{
	int qn = 1;
	for(int i=1; i<4; i++)
	{
		if( GetCompanionIndex(_refCharacter,i)>=0 ) qn++;
	}
	return qn;
}

// работа с офицерами
int GetOfficersQuantity(ref _refCharacter)
{
	int idx=0;
	for(int i=1; i<4; i++)
	{
		if( GetOfficersIndex(_refCharacter,i)!=-1 ) idx++;
	}
	return idx;
}
int GetOfficersIndex(ref _refCharacter,int _OfficerNum)
{
	if(_OfficerNum<0) return -1;
	if(_OfficerNum>3) return -1;
	if(_OfficerNum==0) return MakeInt(_refCharacter.index);

	string compName = "id"+_OfficerNum;
	if(!CheckAttribute(_refCharacter,"Fellows.Passengers.Officers."+compName)) return -1;
	return sti(_refCharacter.Fellows.Passengers.Officers.(compName));
}
int SetOfficersIndex(ref _refCharacter,int _OfficerNum, int _OfficerIdx)
{
	int i;
    if(_OfficerNum == -1)
	{
		for(i=1; i<4; i++)	
		{
			if(GetOfficersIndex(_refCharacter, i) == -1)
			{
				_OfficerNum = i;
				break;
			}
		}
	}
	if(_OfficerNum<1) return _OfficerIdx;
	if(_OfficerNum>3) return _OfficerIdx;

	if(_OfficerIdx!=-1)
	{
		for(i=0;i<4;i++)
		{
			if(GetOfficersIndex(_refCharacter,i)==_OfficerIdx) return -1;
		}
		AddPassenger(_refCharacter,GetCharacter(_OfficerIdx),false);
	}

	string compName = "id"+_OfficerNum;
	int retVal = GetOfficersIndex(_refCharacter,_OfficerNum);
	_refCharacter.Fellows.Passengers.Officers.(compName) = _OfficerIdx;
	if(_OfficerIdx>=0)
	{
		LAi_SetOfficerType(GetCharacter(_OfficerIdx));
		Characters[_OfficerIdx].location = _refCharacter.location;
	}
	if(retVal>=0)
	{
		LAi_SetCitizenTypeNoGroup(GetCharacter(retVal));
		Characters[retVal].location = "none";
	}
	Event(EVENT_CHANGE_OFFICERS,"");
	return retVal;
}
bool RemoveOfficersIndex(ref _refCharacter, int _OfficerIdx)
{
	if(_OfficerIdx==-1) return false;
	for(int i=1; i<4; i++)
	{
		if(GetOfficersIndex(_refCharacter,i) == _OfficerIdx)
		{
			SetOfficersIndex(_refCharacter,i,-1);
			return true;
		}
	}
	return false;
}

// table service
string GetReputationName(int reputation)
{
    if(reputation<11)
        return ReputationTable[REPUTATIONT_HORROR];
    if(reputation<21)
        return ReputationTable[REPUTATIONT_BASTARD];
    if(reputation<31)
        return ReputationTable[REPUTATIONT_SWINDLER];
    if(reputation<41)
        return ReputationTable[REPUTATIONT_RASCAL];
    if(reputation<51)
        return ReputationTable[REPUTATIONT_NEUTRAL];
    if(reputation<61)
        return ReputationTable[REPUTATIONT_PLAIN];
    if(reputation<71)
        return ReputationTable[REPUTATIONT_GOOD];
    if(reputation<81)
        return ReputationTable[REPUTATIONT_VERYGOOD];
    if(reputation<90)
        return ReputationTable[REPUTATIONT_HERO];
	return "";
}

string GetMoraleName(int morale)
{
	if(morale<10)
		return MoraleTable[MORALET_TREACHEROUS];
	if(morale<20)
		return MoraleTable[MORALET_AWFUL];
	if(morale<30)
		return MoraleTable[MORALET_LOW];
	if(morale<40)
		return MoraleTable[MORALET_POOR];
	if(morale<50)
		return MoraleTable[MORALET_NORMAL];
	if(morale<60)
		return MoraleTable[MORALET_ELATED];
	if(morale<70)
		return MoraleTable[MORALET_GOOD];
	if(morale<80)
		return MoraleTable[MORALET_HIGH];
	if(morale<90)
		return MoraleTable[MORALET_EXCELLENT];
	if(morale<100)
		return MoraleTable[MORALET_HEROIC];
	return "";
}

// skill and expirence service
string GetSkillName(int _SkillType)
{
	switch(_SkillType)
	{
	case 0:
		return SKILL_LEADERSHIP;
		break;
	case 1:
		return SKILL_FENCING;
		break;
	case 2:
		return SKILL_SAILING;
		break;
	case 3:
		return SKILL_ACCURACY;
		break;
	case 4:
		return SKILL_CANNONS;
		break;
	case 5:
		return SKILL_GRAPPLING;
		break;
	case 6:
		return SKILL_REPAIR;
		break;
	case 7:
		return SKILL_DEFENCE;
		break;
	case 8:
		return SKILL_COMMERCE;
		break;
	case 9:
		return SKILL_SNEAK;
		break;
	}
	return "";
}

int GetCharacterSkill(ref _refCharacter, string skillName)
{
	if( !CheckAttribute(_refCharacter,"Skill."+skillName) ) return 0;
	int skillN = sti(_refCharacter.Skill.(skillName));
	if( skillN<=10 ) return skillN;
	trace("Character ID = "+_refCharacter.id + "have skill "+skillName + " = "+skillN);
	return 10;
}

int GetSummonSkillFromName(ref _refCharacter, string skillName)
{
	int sumSkill = GetCharacterSkill(_refCharacter,skillName);
	int i,cn,curSkill;
	for(i=1;i<4;i++)
	{
		cn = GetOfficersIndex(&_refCharacter,i);
		if(cn!=-1)
		{
			curSkill = GetCharacterSkill(GetCharacter(cn),skillName);
			if(sumSkill<curSkill)
			{
				sumSkill = curSkill;
			}
		}
	}
	return sumSkill;
}

int GetSummonSkill(ref _refCharacter,int _SkillType)
{
	return GetSummonSkillFromName(&_refCharacter,GetSkillName(_SkillType));
}

string GetBasicSkill(ref _refCharacter)
{
	aref refSkill;
	makearef(refSkill,_refCharacter.Skill);
	string skillName;

	int i=0;
	int maxSkillValue = -1;
	string maxSkillName;
	for(i=0; i<10; i++)
	{
		skillName = GetSkillName(i);
		if(MakeInt(refSkill.(skillName))>maxSkillValue)
		{
			maxSkillName = skillName;
			maxSkillValue = MakeInt(refSkill.(skillName));
		}
	}
	return maxSkillName;
}

void AddPartyExp(ref _refCharacter,int _exp)
{
	int cn,i;
	ref chref;
	i = GetOfficersQuantity(_refCharacter);
	_exp = (_exp+i)/(i+1);
	for(i=0; i<4; i++)
	{
		cn = GetOfficersIndex(_refCharacter,i);
		if(cn!=-1)
		{	AddCharacterExp(GetCharacter(cn),_exp);
		}
	}
}

void AddExpAndShow(ref chref, int _exp)
{
	Log_SetStringToLog("+" + _exp + XI_ConvertString("add experience"));
	AddCharacterExp(chref, _exp);
}

int AddCharacterExp(ref _refCharacter,int _exp)
{
	int retVal = false;
	int curExp = sti(_refCharacter.Experience) + _exp;
	_refCharacter.Experience = curExp;
	int nextExp = CalculateExperienceFromRank(sti(_refCharacter.rank)+1);
	while(curExp>=nextExp)
	{
		_refCharacter.rank = sti(_refCharacter.rank) + 1;
		_refCharacter.Skill.FreeSkill = sti(_refCharacter.Skill.FreeSkill) + 2;
		if(CheckAttribute(_refCharacter,"perks.FreePoints"))
		{	_refCharacter.perks.FreePoints = sti(_refCharacter.perks.FreePoints) + 1;
		}
		else
		{	_refCharacter.perks.FreePoints = 1;
		}
		nextExp = CalculateExperienceFromRank(sti(_refCharacter.rank)+1);
		float mhp = LAi_GetCharacterMaxHP(_refCharacter) + 5.0;
		LAi_SetHP(_refCharacter,mhp,mhp);
		retVal = true;
		if(sti(_refCharacter.index)==GetMainCharacterIndex())
		{
			Log_SetStringToLog(XI_ConvertString("Level Up!"));
			PlayStereoSound("interface\new_level.wav");
		}
	}
	if( CheckCharacterPerk(_refCharacter,"SharedExperience") )
	{
		int cn;
		for(int i=1; i<4; i++)
		{
			cn = GetOfficersIndex(_refCharacter,i);
			if(cn!=-1)
			{	AddCharacterExp(GetCharacter(cn),(_exp+4)/5);
			}
		}
	}
	if(retVal)
	{
		if(IsOfficer(_refCharacter) || IsCompanion(_refCharacter))
		{
			AddMsgToCharacter(_refCharacter,MSGICON_LEVELUP);
		}
	}
	return retVal;
}

int CalculateExperienceFromRank(int _Rank)
{
	if(_Rank<2) return 0;
	int retVal = (MakeInt(1000 * pow(_Rank-1,2.3))/1000)*1000;
	return retVal;
}

int AddMoneyToCharacter(ref _refCharacter,int _Money)
{
	int newMoney = sti(_refCharacter.Money) + _Money;
	if(newMoney<0) newMoney=0;
	_refCharacter.Money = newMoney;
	return newMoney;
}

void SetBaseShipData(ref refCharacter)
{
    int  i;
    aref refShip;
    int  nShipType;
    ref  refBaseShip;

	if(CheckAttribute(refCharacter,"Ship"))
	{
		makearef(refShip,refCharacter.Ship);

		nShipType = GetCharacterShipType(refCharacter);
		if(nShipType==SHIP_NOTUSED) return;

		refBaseShip = GetShipByType(nShipType);

		refShip.HP = refBaseShip.HP;
		refShip.SP = refBaseShip.SP;

		refShip.Pos.x = 0;
		refShip.Pos.z = 0;
		refShip.Ang = "";
		refShip.Cannons.Borts = "";
		refShip.Cannons.Charge.Type = GOOD_BOMBS;
		if (!CheckAttribute(refShip,"Cannons.Type")) { refShip.Cannons.Type = MakeInt(refBaseShip.Cannon); }

		if (!CheckAttribute(refShip,"Crew.Morale"))	{ refShip.Crew.Morale = 45;	}
		if (!CheckAttribute(refShip,"Crew.Quantity")) { refShip.Crew.Quantity = refBaseShip.MaxCrew; }

		string goodsName;
		refCharacter.Ship.Cargo.Load = 0;
		for(i=0; i<GOODS_QUANTITY; i++)
		{
			goodsName = Goods[i].Name;
			refCharacter.Ship.Cargo.Goods.(goodsName) = 0;
		}

		// bombs
		i = GetCharacterFreeSpace(refCharacter,GOOD_BOMBS);
		if(i>0) {
			if(i>=570) {
				SetCharacterGoods(refCharacter,GOOD_BOMBS,570);
			} else {
				SetCharacterGoods(refCharacter,GOOD_BOMBS,i);
			}
		// grapes
			i = GetCharacterFreeSpace(refCharacter,GOOD_GRAPES);
			if(i>0) {
				if(i>=210) {
					SetCharacterGoods(refCharacter,GOOD_GRAPES,210);
				} else {
					SetCharacterGoods(refCharacter,GOOD_GRAPES,i);
				}
		// knippels
				i = GetCharacterFreeSpace(refCharacter,GOOD_KNIPPELS);
				if(i>0) {
					if(i>=80) {
						SetCharacterGoods(refCharacter,GOOD_KNIPPELS,80);
					} else {
						SetCharacterGoods(refCharacter,GOOD_KNIPPELS,i);
					}
		// cannonballs
					i = GetCharacterFreeSpace(refCharacter,GOOD_BALLS);
					if(i>0) {
						if(i>=900) {
							SetCharacterGoods(refCharacter,GOOD_BALLS,900);
						} else {
							SetCharacterGoods(refCharacter,GOOD_BALLS,i);
						}
					}
				}
			}
		}
	}
}

void SetBaseFellows(object refCharacter)
{
	aref tmpRef;

	makearef(tmpRef,refCharacter.Fellows.Companions);
	tmpRef.id1 = -1;
	tmpRef.id2 = -1;
	tmpRef.id3 = -1;

	makearef(tmpRef,refCharacter.Fellows.Passengers);
	tmpRef.Quantity = 0;
	tmpRef.id1 = -1;
	tmpRef.id2 = -1;
	tmpRef.id3 = -1;
	tmpRef.id4 = -1;
	tmpRef.id5 = -1;
	tmpRef.id6 = -1;
	tmpRef.id7 = -1;
	tmpRef.id8 = -1;

	makearef(tmpRef,refCharacter.Fellows.Passengers.Officers);
	tmpRef.id1 = -1;
	tmpRef.id2 = -1;
	tmpRef.id3 = -1;
}

// statistics utilite
void DoShipKilledStatistics(int killerCharacterIdx,int deadCharacterIdx)
{
	ref killer = GetCharacter(killerCharacterIdx);
	ref dead = GetCharacter(deadCharacterIdx);

	string attrName = Nations[sti(dead.nation)].Name;
	int oldValue = GetNationShipKilled(killer,attrName);
	killer.Statistics.KilledShip.Nation.(attrName) = oldValue+1;

	oldValue = GetClassShipKilled(GetCharacterShipClass(dead));
	attrName = "" + GetCharacterShipClass(dead);
	killer.Statistics.KilledShip.Class.(attrName) = oldValue+1;
}

void DoShipCaptureStatistics(int killerCharacterIdx,int captiveCharacterIdx)
{
	ref killer = GetCharacter(killerCharacterIdx);
	ref captive = GetCharacter(captiveCharacterIdx);

	string attrName = Nations[sti(captive.nation)].Name;
	int oldValue = GetNationShipCaptured(killer,attrName);
	killer.Statistics.CapturedShip.Nation.(attrName) = oldValue+1;

	oldValue = GetClassShipCaptured(killer,GetCharacterShipClass(captive));
	attrName = "" + GetCharacterShipClass(captive);
	killer.Statistics.CapturedShip.Class.(attrName) = oldValue+1;
}

int GetNationShipKilled(ref _refCharacter,string nation)
{
	if( CheckAttribute(_refCharacter,"Statistics.KilledShip.Nation." + nation) )
		return sti(_refCharacter.Statistics.KilledShip.Nation.(nation));
	return 0;
}
int GetClassShipKilled(ref _refCharacter,int classNum)
{
	string className = "" + classNum;
	if( CheckAttribute(_refCharacter,"Statistics.KilledShip.Class." + classNum) )
		return sti(_refCharacter.Statistics.KilledShip.Class.(className));
	return 0;
}

int GetNationShipCaptured(ref _refCharacter,string nation)
{
	if( CheckAttribute(_refCharacter,"Statistics.CapturedShip.Nation." + nation) )
		return sti(_refCharacter.Statistics.CapturedShip.Nation.(nation));
	return 0;
}
int GetClassShipCaptured(ref _refCharacter,int classNum)
{
	string className = "" + classNum;
	if( CheckAttribute(_refCharacter,"Statistics.CapturedShip.Class." + classNum) )
		return sti(_refCharacter.Statistics.CapturedShip.Class.(className));
	return 0;
}

// Items Utilite
int GetChrItemQuantity(ref _refCharacter)
{
	aref ar; makearef(ar,_refCharacter.items);
	return GetAttributesNum(ar);
}
bool GiveItem2Character(ref _refCharacter,string itemName)
{
	return TakeNItems(_refCharacter,itemName,1);
}
void TakeItemFromCharacter(ref _refCharacter,string itemName)
{
	TakeNItems(_refCharacter,itemName,-1);
}
bool CheckCharacterItem(ref _refCharacter,string itemName)
{
	if( CheckAttribute(_refCharacter,"Items."+itemName) && sti(_refCharacter.Items.(itemName))>0 )	return true;
	else	return false;
}
int GetCharacterItem(ref _refCharacter,string itemName)
{
	if(CheckAttribute(_refCharacter,"Items."+itemName))
	{
		return sti(_refCharacter.Items.(itemName));
	}
	return 0;
}
bool ReplaceItem(ref _refTakingCharacter,ref _refGivingCharacter,string itemName)
{
	bool retVal = CheckCharacterItem(_refGivingCharacter,itemName);
	if( TakeNItems(_refTakingCharacter,itemName,1) )
		TakeNItems(_refGivingCharacter,itemName,-1);
	return retVal;
}
bool TakeNItems(ref _refCharacter,string itemName, int n)
{
	int q;
	aref arItm;
	if( Items_FindItem(itemName,&arItm)<0 )
	{
		trace("WARNING!!! Item id = "+itemName+" not implemented");
		return false;
	}
	if( CheckAttribute(arItm,"gold") )
	{
		if( CheckAttribute(_refCharacter,"Money") )	q = sti(_refCharacter.Money);
		else q = 0;
		q += n*sti(arItm.gold);
		if(q<0) {q=0;}
		_refCharacter.Money = q;
		return true;
	}
	if( CheckAttribute(arItm,"price") && sti(arItm.price)==0 )
	{
		if(sti(_refCharacter.index)==GetMainCharacterIndex() && IsEntity(_refCharacter))
		{
			if(n>0)	{Log_SetStringToLog(XI_ConvertString("You take item"));}
			if(n<0)	{Log_SetStringToLog(XI_ConvertString("You give item"));}
			PlayStereoSound("interface\important_item.wav");
		}
		if( n>0 && IsOfficer(_refCharacter) || IsCompanion(_refCharacter) ) {
			AddMsgToCharacter(_refCharacter,MSGICON_GETITEM);
		}
	}
	q = GetCharacterItem(_refCharacter,itemName);
	if(q+n<=0) DeleteAttribute(_refCharacter,"Items."+itemName);
	else
	{
		if(q<=0 && GetChrItemQuantity(_refCharacter)>=MAX_ITEM_TAKE) return false;
		_refCharacter.Items.(itemName) = q+n;
	}
	return true;
}


// работа с контрабандой
int FindFirstContrabandGoods(ref _refCharacter)
{
	int i;
	int curStoreIdx = GetCharacterCurrentStore(_refCharacter);
	if(curStoreIdx>=0)
	{
		_refCharacter.FindContrabandGoods.StoreIdx = curStoreIdx;
		for(i=0; i<GOODS_QUANTITY; i++)
		{
			if( GetStoreGoodsType(&Stores[curStoreIdx],i) == TRADE_TYPE_CONTRABAND_NAME )
			{
				if( GetSquadronGoods(_refCharacter,i)>0 )
				{
					_refCharacter.FindContrabandGoods.GoodsIdx = i;
					return i;
				}
			}
		}
		DeleteAttribute(_refCharacter,"FindContrabandGoods");
		return -1;
	}
	int curLocIdx = FindLocation(_refCharacter.location);
	if(curLocIdx<0) return -1;
	int curIslandIdx = GetIslandIdxByLocationIdx(curLocIdx);
	if(curIslandIdx<0) return -1;
	aref islRef; makearef(islRef,Islands[curIslandIdx].Trade.Contraband);
	int n;
	for(i=0;i<GetAttributesNum(islRef);i++)
	{
		n = sti(GetAttributeValue(GetAttributeN(islRef,0)));
		if( GetSquadronGoods(_refCharacter,n)>0 )
		{
			_refCharacter.FindContrabandGoods.IslandIdx = curIslandIdx;
			_refCharacter.FindContrabandGoods.GoodsIdx = i;
			return n;
		}
	}
	return -1;
}

int FindNextContrabandGoods(ref _refCharacter)
{
	int i,n;
	if(CheckAttribute(_refCharacter,"FindContrabandGoods.StoreIdx"))
	{
		if(CheckAttribute(_refCharacter,"FindContrabandGoods.GoodsIdx"))
		{
			int curStoreIdx = sti(_refCharacter.FindContrabandGoods.StoreIdx);
			if(curStoreIdx>=0)
			{
				for(i=sti(_refCharacter.FindContrabandGoods.GoodsIdx)+1; i<GOODS_QUANTITY; i++)
				{
					if( GetStoreGoodsType(&Stores[curStoreIdx],i) == TRADE_TYPE_CONTRABAND_NAME )
					{
						if( GetSquadronGoods(_refCharacter,i)>0 )
						{
							_refCharacter.FindContrabandGoods.GoodsIdx = i;
							return i;
						}
					}
				}
			}
		}
	}
	else
	{
		if(CheckAttribute(_refCharacter,"FindContrabandGoods.IslandIdx"))
		{
			if(CheckAttribute(_refCharacter,"FindContrabandGoods.GoodsIdx"))
			{
				int curIslandIdx = sti(_refCharacter.FindContrabandGoods.IslandIdx);
				if(curIslandIdx>=0)
				{
					int curGoodsNum = sti(_refCharacter.FindContrabandGoods.GoodsIdx) + 1;
					aref islRef; makearef(islRef,Islands[curIslandIdx].Trade.Contraband);
					for(i=curGoodsNum; i<GetAttributesNum(islRef); i++)
					{
						n = GetAttributeValue(GetAttributeN(islRef,i));
						if( GetSquadronGoods(_refCharacter,n)>0 )
						{
							_refCharacter.FindContrabandGoods.GoodsIdx = i;
							return n;
						}
					}
				}
			}
		}
	}
	DeleteAttribute(_refCharacter,"FindContrabandGoods");
	return -1;
}

int GetCharacterCurrentIsland(ref _refCharacter)
{
	int curLocNum = FindLocation(Characters[GetMainCharacterIndex()].location);
	if(curLocNum<0) return -1;
	return GetIslandIdxByLocationIdx(curLocNum);
}

int GetIslandIdxByLocationIdx(int locIdx)
{
	aref rootar,ar;
	makearef(rootar,Locations[0].IslandsList);
	for(int i=0; i<GetAttributesNum(rootar); i++)
	{
		ar = GetAttributeN(rootar,i);
		if( locIdx>=sti(ar.begin) && locIdx<=sti(ar.end) )
		{
			return FindIsland(GetAttributeName(ar));
		}
	}
	return -1;
}

int GetCharacterCurrentStore(ref _refCharacter)
{
	int i;
	int curLocNum = FindLocation(Characters[GetMainCharacterIndex()].location);
	if(curLocNum<0) return -1;

	if( CheckAttribute(&Locations[curLocNum],"fastreload") )
	{
		string locGroupId = Locations[curLocNum].fastreload;
		for(i=0; i<STORE_QUANTITY; i++)
		{
			if(Stores[i].group==locGroupId)
			{
				return i;
			}
		}
	}
	else
	{
		curLocNum = GetIslandIdxByLocationIdx(curLocNum);
		if(curLocNum<0)	{return -1;}
		for(i=0; i<STORE_QUANTITY; i++)
		{
			if(stores[i].Island==Islands[curLocNum].id)
			{
				return i;
			}
		}
	}

	return  -1;
}

int GetCurrentIslandGoodsPrice(int GoodsType)
{
	int curStoreIdx = GetCharacterCurrentStore(GetMainCharacter());
	if(curStoreIdx<0) return 0;
	return GetStoreGoodsPrice(&Stores[curStoreIdx],GoodsType,PRICE_TYPE_SELL,GetMainCharacter());
}

int GetCurrentLocationNation() 
{
	int curLocNum = FindLocation(Characters[GetMainCharacterIndex()].location);
	if(curLocNum<0) return -1;
	return GetLocationNation(&Locations[curLocNum]);
}

void SetRandomNameToCharacter(ref rCharacter)
{
	int iNation = sti(rCharacter.nation);
	if (iNation == -1) iNation = PIRATE;
	while (iNation == PIRATE) { iNation = rand(MAX_NATIONS - 1); }
	
	ref rNames, rLastNames;

	switch(iNation)
	{
		case ENGLAND:
			rNames = &sEnManNames;
			if (rCharacter.sex != "man") rNames = &sEnWomenNames;
			rLastNames = &sEnFamilies;
		break;
		case FRANCE:
			rNames = &sFrManNames;
			if (rCharacter.sex != "man") rNames = &sFrWomenNames;
			rLastNames = &sFrFamilies;
		break;
		case SPAIN:
			rNames = &sSpManNames;
			if (rCharacter.sex != "man") rNames = &sSpWomenNames;
			rLastNames = &sSpFamilies;
		break;
		case HOLLAND:
			rNames = &sHoManNames;
			if (rCharacter.sex != "man") rNames = &sHoWomenNames;
			rLastNames = &sHoFamilies;
		break;
		case PORTUGAL:
			rNames = &sPoManNames;
			if (rCharacter.sex != "man") rNames = &sPoWomenNames;
			rLastNames = &sPoFamilies;
		break;
	}

	rCharacter.name = GetRandSubString(rNames[rand(GetArraySize(rNames) - 2)]);
	rCharacter.lastname = GetRandSubString(rLastNames[rand(GetArraySize(rLastNames) - 2)]);
}

//=============================================================================
//  EQUIP SECTION
//=============================================================================
string FindCharacterItemByGroup(ref chref, string groupID)
{
	int i,n;
	ref refItm;

	for(i=ITEMS_QUANTITY-1; i>=0; i--)
	{
		refItm = &Items[i];
		if( !CheckAttribute(refItm,"groupID") ) continue;
		if(refItm.groupID!=groupID) continue;
		if( !CheckAttribute(chref,"items."+refItm.id) ) continue;
		if(groupID==GUN_ITEM_TYPE)
		{
			if( !CheckAttribute(refItm,"chargeQ") ) continue;
			n = sti(refItm.chargeQ);
			if(n<2) {return refItm.id;}
			if(n<4)
			{
				if( IsCharacterPerkOn(chref,"Gunman") ) {return refItm.id;}
				else continue;
			}
			if( IsCharacterPerkOn(GetMainCharacter(),"GunProfessional") )	{return refItm.id;}
			continue;
		}
		return refItm.id;
	}
	return "";
}

bool IsEquipCharacterByItem(ref chref, string itemID)
{
	aref arEquip;
	makearef(arEquip,chref.equip);
	int q = GetAttributesNum(arEquip);
	for(int i=0; i<q; i++)
	{	if(GetAttributeValue(GetAttributeN(arEquip,i))==itemID) return true;
	}
	return false;
}

string GetCharacterEquipByGroup(ref chref, string groupID)
{
	if( CheckAttribute(chref,"equip."+groupID) ) return chref.equip.(groupID);
	return "";
}

void RemoveCharacterEquip(ref chref, string groupID)
{
	DeleteAttribute(chref,"equip."+groupID);
	SetEquipedItemToCharacter(chref,groupID,"");
}

void SetEquipedItemToCharacter(ref chref, string groupID, string itemID)
{
	object emptyItm;
	aref arItm;
	string modelName = "";
	makearef(arItm,emptyItm);
	if(itemID!="")
	{
		if( !CheckCharacterItem(chref,itemID) ) return;
		Items_FindItem(itemID,&arItm);
	}

	switch(groupID)
	{
	case SPYGLASS_ITEM_TYPE:
		if(CheckAttribute(arItm,"id"))
		{
			setTelescopeInitParameters(&Telescope,arItm);
		}
	break;

	case GUN_ITEM_TYPE:
		if(CheckAttribute(arItm,"model"))	{modelName = arItm.model;}
		SendMessage(chref,"ls",MSG_CHARACTER_SETGUN,modelName);
		if(CheckAttribute(arItm,"chargeQ"))
		{	LAi_GunSetChargeQuant(chref,sti(arItm.chargeQ));
		} else
		{	LAi_GunSetChargeQuant(chref,0);
		}
		if(CheckAttribute(arItm,"chargespeed") && stf(arItm.chargespeed)>0.0)
		{	LAi_GunSetChargeSpeed(chref,1.0/stf(arItm.chargespeed));
		} else
		{	LAi_GunSetChargeSpeed(chref,0.0);
		}
		if(CheckAttribute(arItm,"dmg_min"))
		{	LAi_GunSetDamageMin(chref,stf(arItm.dmg_min));
		} else
		{	LAi_GunSetDamageMin(chref,0.0);
		}
		if(CheckAttribute(arItm,"dmg_max"))
		{	LAi_GunSetDamageMax(chref,stf(arItm.dmg_max));
		} else
		{	LAi_GunSetDamageMax(chref,0.0);
		}
		if(CheckAttribute(arItm,"accuracy"))
		{	LAi_GunSetAccuracy(chref,stf(arItm.accuracy)*0.01);
		} else
		{	LAi_GunSetAccuracy(chref,0.0);
		}
	break;

	case BLADE_ITEM_TYPE:
		float liveTime = 0.1;
		int colors = argb(64, 64, 64, 64);
		int colore = argb(0, 32, 32, 32);
		if(CheckAttribute(arItm,"model"))	{modelName = arItm.model;}
		if(CheckAttribute(arItm, "blade.time"))	{liveTime = stf(arItm.blade.time);}
		if(CheckAttribute(arItm, "blade.colorstart"))	{colors = sti(arItm.blade.colorstart);}
		if(CheckAttribute(arItm, "blade.colorend"))	{colore = sti(arItm.blade.colorend);}
		SendMessage(chref, "lsfll", MSG_CHARACTER_SETBLADE, modelName, liveTime, colors, colore);
		if(CheckAttribute(arItm,"dmg_min"))
		{	LAi_BladeSetDamageMin(chref,stf(arItm.dmg_min));
		} else
		{	LAi_BladeSetDamageMin(chref,0.0);
		}
		if(CheckAttribute(arItm,"dmg_max"))
		{	LAi_BladeSetDamageMax(chref,stf(arItm.dmg_max));
		} else
		{	LAi_BladeSetDamageMax(chref,0.0);
		}
		if(CheckAttribute(arItm,"piercing"))
		{	LAi_BladeSetPiercing(chref,stf(arItm.piercing)*0.01);
		} else
		{	LAi_BladeSetPiercing(chref,0.0);
		}
		if(CheckAttribute(arItm,"block"))
		{	LAi_BladeSetBlock(chref,stf(arItm.block)*0.01);
		} else
		{	LAi_BladeSetBlock(chref,0.0);
		}
	break;
	}
}

void EquipCharacterByItem(ref chref, string itemID)
{
	aref arItm;

	if( !CheckCharacterItem(chref, itemID) ) return;
	if( Items_FindItem(itemID, &arItm)<0 )	return;
	if( !CheckAttribute(arItm, "groupID") ) return;

	string groupName = arItm.groupID;
	string oldItemID = GetCharacterEquipByGroup(chref, groupName);
	if(oldItemID==itemID) return;
	chref.equip.(groupName) = itemID;

	if(IsEntity(chref))
	{	SetEquipedItemToCharacter(chref, groupName, itemID);
	}
	if(groupName==GUN_ITEM_TYPE && sti(chref.index)==GetMainCharacterIndex())
	{	LAi_GunSetUnload(chref);
	}
}

void ExecuteCharacterEquip(ref chref)
{
	stmp = GetCharacterEquipByGroup(chref,BLADE_ITEM_TYPE);
	if(stmp!="")	{SetEquipedItemToCharacter(chref, BLADE_ITEM_TYPE, stmp);}
	string stmp = GetCharacterEquipByGroup(chref,GUN_ITEM_TYPE);
	if(stmp!="")	{SetEquipedItemToCharacter(chref, GUN_ITEM_TYPE, stmp);}
}

bool IsCanEquiping(ref chref, string equiping_group)
{
	if( CheckAttribute(chref,"equip.disabled_group."+equiping_group)
		&& sti(chref.equip.disabled_group.(equiping_group))==true ) return false;
	return true;
}

void EnableEquip(ref chref, string equiping_group, bool enable)
{
	if(enable)
	{	if(equiping_group=="")
		{	DeleteAttribute(chref,"equip.disabled_group");
		}
		else
		{	DeleteAttribute(chref,"equip.disabled_group."+equiping_group);
		}
	}
	else
	{	if(equiping_group=="")
		{
			string stmp;
			stmp = GUN_ITEM_TYPE;		chref.equip.disabled_group.(stmp) = true;
			stmp = BLADE_ITEM_TYPE;		chref.equip.disabled_group.(stmp) = true;
			stmp = SPYGLASS_ITEM_TYPE;	chref.equip.disabled_group.(stmp) = true;
		}
		else
		{
			chref.equip.disabled_group.(equiping_group) = true;
		}
	}
}

int ChangeCharacterReputation(ref chref, int incr)
{
	int prevVal = REPUTATION_NEUTRAL;
	if( CheckAttribute(chref,"reputation") )	prevVal = sti(chref.reputation);

	int newVal = prevVal + incr;
	if(newVal<REPUTATION_MIN) newVal = REPUTATION_MIN;
	if(newVal>REPUTATION_MAX) newVal = REPUTATION_MAX;
	chref.reputation = newVal;

	if( sti(chref.index) != GetMainCharacterIndex() ) return newVal;

	string prevName = GetReputationName(prevVal);
	string newName = GetReputationName(newVal);
	if(prevName!=newName)
	{
		string outString = XI_ConvertString("Your reputation")+" ";
		if(incr>0)	{outString+=XI_ConvertString("increase");}
		else	{outString+=XI_ConvertString("decrease");}
		outString += " "+XI_ConvertString("to")+" "+XI_ConvertString(newName);
		Log_SetStringToLog(outString);
	}

	return newVal;
}

bool Character_IsAbordageEnable(ref rCharacter)
{
	if (CheckAttribute(rCharacter, "Abordage.Enable")) { return sti(rCharacter.Abordage.Enable); }
	return true;
}

void Character_SetAbordageEnable(ref rCharacter, bool bEnable)
{
	rCharacter.Abordage.Enable = bEnable;
}

void Character_SetCompanionEnemyEnable(ref rCharacter, bool bEnable)
{
	rCharacter.CompanionEnemyEnable = bEnable;
}

void AddMsgToCharacter(ref chref, int nMsg)
{
	string msgName = "msg"+nMsg;
	bool bStartEvent = !CheckAttribute(chref,"MessageIcons."+msgName);
	chref.MessageIcons.(msgName).pic = nMsg;
	chref.MessageIcons.(msgName) = MSGICON_ACTIVE_TIME;
	if(bStartEvent) PostEvent("evnt_MsgIconTick",1000,"ll",nMsg,sti(chref.index));
}

void DelMsgFromCharacter(ref chref, int nMsg)
{
	DeleteAttribute(chref,"MessageIcons.msg"+nMsg);
}

void proc_MsgIconTick()
{
	int nMsg = GetEventData();
	int chrIdx = GetEventData();
	if(DialogRun!=0) {
		PostEvent("evnt_MsgIconTick",1000,"ll",nMsg,chrIdx);
		return;
	}
	ref chref = GetCharacter(chrIdx);
	string msgName = "msg"+nMsg;
	int nTime = 0;

	if( CheckAttribute(chref,"MessageIcons."+msgName) )
	{
		nTime = sti(chref.MessageIcons.(msgName));
		if(nTime>0)
		{
			chref.MessageIcons.(msgName) = nTime-1;
			PostEvent("evnt_MsgIconTick",1000,"ll",nMsg,chrIdx);
			return;
		}
		DelMsgFromCharacter(chref,nMsg);
	}
}

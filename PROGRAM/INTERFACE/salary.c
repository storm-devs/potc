#define I_MIN_MORALE	10

int nPaymentQ;
int nMoraleDecreaseQ;

void InitInterface(string iniName)
{
    GameInterface.title = "titleSalary";

    SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);

	CalculateInfoData();

	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	SetFormatedText("INFO_TEXT",LanguageConvertString(tmpLangFileID,"Salary info"));
	LanguageCloseFile(tmpLangFileID);
	SendMessage(&GameInterface,"lsl",MSG_INTERFACE_MSG_TO_NODE,"INFO_TEXT",5);

	SetEventHandler("InterfaceBreak","ProcessBreakExit",0)
	SetEventHandler("exitCancel","ProcessCancelExit",0);
	SetEventHandler("ievnt_command","ProcCommand",0);
	SetEventHandler("evntDoPostExit","DoPostExit",0);
}

void ProcessBreakExit()
{
	SkipSailorPayment();
	IDoExit( RC_INTERFACE_SALARY_EXIT );
}

void ProcessCancelExit()
{
	SkipSailorPayment();
	IDoExit( RC_INTERFACE_SALARY_EXIT );
}

void IDoExit(int exitCode)
{
	DelEventHandler("InterfaceBreak","ProcessBreakExit");
	DelEventHandler("exitCancel","ProcessCancelExit");
	DelEventHandler("ievnt_command","ProcCommand");
	DelEventHandler("evntDoPostExit","DoPostExit");

	interfaceResultCommand = exitCode;
	EndCancelInterface(true);
}

void ProcCommand()
{
	string comName = GetEventData();
	string nodName = GetEventData();

	switch(nodName)
	{
	case "B_OK":
		if(comName=="activate" || comName=="click")
		{
			ExecuteSailorPayment();
			PostEvent("evntDoPostExit",1,"l",RC_INTERFACE_SALARY_EXIT);
		}
	break;

	case "B_CANCEL":
		if(comName=="activate" || comName=="click")
		{
			SkipSailorPayment();
			PostEvent("evntDoPostExit",1,"l",RC_INTERFACE_SALARY_EXIT);
		}
		if(comName=="upstep")
		{
			if(GetSelectable("B_OK"))	{SetCurrentNode("B_OK");}
		}
	break;
	}
}

void ExecuteSailorPayment()
{
	AddMoneyToCharacter(GetMainCharacter(),-nPaymentQ);
	DeleteAttribute(GetMainCharacter(),"CrewPayment");
}

void SkipSailorPayment()
{
	ref mchref = GetMainCharacter();
	int morale = 45;
	if( CheckAttribute(mchref,"Ship.Crew.Morale") ) morale = sti(mchref.Ship.Crew.Morale);
	morale -= nMoraleDecreaseQ;
	if(morale<0)	morale = 0;

	mchref.CrewPayment = nPaymentQ;

	int cn;
	for(int i=0; i<4; i++)
	{
		cn = GetCompanionIndex(mchref,i);
		if(cn>=0)
		{
			Characters[cn].Ship.Crew.Morale = morale;
		}
	}

	if(morale<MORALE_NORMAL)
	{
		if(morale<=I_MIN_MORALE) {
			PostEvent("ievent_GameOver",1,"s","mutiny");
		}
	}
}

void DoPostExit()
{
	int exitCode = GetEventData();
	IDoExit(exitCode);
}

void CalculateInfoData()
{
	int i,cn,crewQ;
	ref mchref,chref;

	crewQ = 0;
	mchref = GetMainCharacter();
	for(i=0; i<4; i++)
	{
		cn = GetCompanionIndex(mchref,i);
		if( cn>=0 && GetRemovable(&Characters[cn]) )
		{
			chref = GetCharacter(cn);
			crewQ += GetCrewQuantity(chref);
		}
	}

	int nLeaderShip = GetSummonSkillFromName(mchref,SKILL_LEADERSHIP);
	nPaymentQ = 5 + crewQ*(16-nLeaderShip);
	if( CheckAttribute(mchref,"CrewPayment") ) {
		nPaymentQ += makeint( stf(mchref.CrewPayment)*(11.0-SKILL_LEADERSHIP)/10.0 );
	}

	nMoraleDecreaseQ = 30-nLeaderShip;
	if( CheckCharacterPerk(mchref,"IronWill") ) nMoraleDecreaseQ /= 2;

	CreateString(true,"payment",""+nPaymentQ,FONT_NORMAL,COLOR_NORMAL,320,258,SCRIPT_ALIGN_CENTER,1.0);

	if( sti(mchref.Money) < nPaymentQ )
	{
		SetSelectable("B_OK",false);
		SetCurrentNode("B_CANCEL");
	}
}

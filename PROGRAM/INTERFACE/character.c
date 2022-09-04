#define MAX_CHARACTER_SKILL		10

string sPlayerName;

int nPlayerMoney;
int nNextExperience;
int nCurrentExperience;
int nFreeSkillPoints;

int nLeadership;
int nFencing;
int nSailing;
int nAccuracy;
int nCannons;
int nGrappling;
int nRepair;
int nDefence;
int nCommerce;
int nSneak;

bool bBeParty;
int curOfficer;
ref xi_refMainChar;
ref xi_refCharacter;

int oldIndex = -1;

void InitInterface_R(string iniName,ref pCharacter)
{
	int i;
	curOfficer = 0;
	xi_refMainChar = pCharacter;
    xi_refCharacter = pCharacter;
	AddCharacterExp(xi_refCharacter,0);

    GameInterface.title = "titleCharacter";
    GameInterface.SkillChanger.current = 0;

    GameInterface.StatusLine.EXP.Max = CalculateExperienceFromRank(sti(xi_refCharacter.rank)+1);
    GameInterface.StatusLine.EXP.Min = CalculateExperienceFromRank(sti(xi_refCharacter.rank));
    GameInterface.StatusLine.EXP.Value = xi_refCharacter.Experience;

	if( CheckAttribute(&InterfaceStack,"CharacterView_pos") ) GameInterface.skillchanger.current = InterfaceStack.CharacterView_pos;
    SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);

	for(i=1;i<4;i++)	{if( GetOfficersIndex(pCharacter,i)>=0 || GetCompanionIndex(pCharacter,i)>=0 ) break;}
	if(i==4)
	{
		bBeParty = false;
		SetNodeUsing("LEFTCHANGE_CHARACTER",false);
		SetNodeUsing("RIGHTCHANGE_CHARACTER",false);
	}
	else
	{
		bBeParty = true;
	}
	SetNodeUsing("B_SKILLUP",false);
	SetNodeUsing("B_ABILITIES",false);

    CreateString(true,"CurrentExperience","",FONT_NORMAL,COLOR_NORMAL,175,376,SCRIPT_ALIGN_CENTER,1.0);
    CreateString(true,"NextExperience","",FONT_NORMAL,COLOR_NORMAL,175,407,SCRIPT_ALIGN_CENTER,1.0);
    CreateString(true,"Money","",FONT_NORMAL,COLOR_MONEY,175,438,SCRIPT_ALIGN_CENTER,1.0);
    CreateString(true,"CharacterName","",FONT_NORMAL,COLOR_NORMAL,156,48,SCRIPT_ALIGN_CENTER,1.0);
    CreateString(true,"Reputation","",FONT_NORMAL,COLOR_NORMAL,156,80,SCRIPT_ALIGN_CENTER,1.0);
    CreateString(true,"FreeAbilitiesPoints","",FONT_BOLD_NUMBERS,COLOR_NORMAL,444,416,SCRIPT_ALIGN_RIGHT,1.0);
    CreateString(true,"FreeSkillPoints","",FONT_BOLD_NUMBERS,COLOR_NORMAL,610,416,SCRIPT_ALIGN_RIGHT,1.0);
    CreateString(true,"Rank","",FONT_BOLD_NUMBERS,COLOR_NORMAL,268,324,SCRIPT_ALIGN_RIGHT,1.0);

    CreateString(true,"SkillLeadership","",FONT_BOLD_NUMBERS,COLOR_NORMAL,587,46,SCRIPT_ALIGN_RIGHT,1.0);
    CreateString(true,"SkillFencing","",FONT_BOLD_NUMBERS,COLOR_NORMAL,587,80,SCRIPT_ALIGN_RIGHT,1.0);
    CreateString(true,"SkillSailing","",FONT_BOLD_NUMBERS,COLOR_NORMAL,587,114,SCRIPT_ALIGN_RIGHT,1.0);
    CreateString(true,"SkillAccuracy","",FONT_BOLD_NUMBERS,COLOR_NORMAL,587,148,SCRIPT_ALIGN_RIGHT,1.0);
    CreateString(true,"SkillCannons","",FONT_BOLD_NUMBERS,COLOR_NORMAL,587,182,SCRIPT_ALIGN_RIGHT,1.0);
    CreateString(true,"SkillGrappling","",FONT_BOLD_NUMBERS,COLOR_NORMAL,587,216,SCRIPT_ALIGN_RIGHT,1.0);
    CreateString(true,"SkillRepair","",FONT_BOLD_NUMBERS,COLOR_NORMAL,587,250,SCRIPT_ALIGN_RIGHT,1.0);
    CreateString(true,"SkillDefence","",FONT_BOLD_NUMBERS,COLOR_NORMAL,587,284,SCRIPT_ALIGN_RIGHT,1.0);
    CreateString(true,"SkillCommerce","",FONT_BOLD_NUMBERS,COLOR_NORMAL,587,318,SCRIPT_ALIGN_RIGHT,1.0);
    CreateString(true,"SkillSneak","",FONT_BOLD_NUMBERS,COLOR_NORMAL,587,352,SCRIPT_ALIGN_RIGHT,1.0);

    CreateString(true,"MaxHP","",FONT_NORMAL,COLOR_NORMAL,66,331,SCRIPT_ALIGN_LEFT,1.0);

	SetVariable();

	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
    SetEventHandler("exitCancel","ProcessCancelExit",0);
	SetEventHandler("ievnt_command","ProcessCommandExecute",0);
	SetEventHandler("frame","ProcessFrame",1);
}

void SetNextParty(bool bRight)
{
	int i,cn;
	if(bRight)
	{
		curOfficer++;
		for(i=curOfficer; i<7; i++)
		{
			if(i<4)	{cn = GetOfficersIndex(xi_refMainChar,i);}
			else {cn = GetCompanionIndex(xi_refMainChar,i-3);}
			if( cn>-1 && GetRemovable(GetCharacter(cn)) ) break;
		}
		if(i<7)
		{
			xi_refCharacter = GetCharacter(cn);
			curOfficer = i;
		}
		else
		{
			xi_refCharacter = xi_refMainChar;
			curOfficer = 0;
		}
	}
	else
	{
		curOfficer--;
		if(curOfficer<0) curOfficer=6;
		for(i=curOfficer; i>0; i--)
		{
			if(i<4)	{cn = GetOfficersIndex(xi_refMainChar,i);}
			else {cn = GetCompanionIndex(xi_refMainChar,i-3);}
			if( cn>-1 && GetRemovable(GetCharacter(cn)) ) break;
		}
		if(i>0)	{xi_refCharacter = GetCharacter(cn);}
		else {xi_refCharacter = xi_refMainChar;}
		curOfficer = i;
	}
	AddCharacterExp(xi_refCharacter,0);
}

void SetVariable()
{
    sPlayerName = xi_refCharacter.name;

    nPlayerMoney = sti(xi_refCharacter.Money);
    nCurrentExperience = sti(xi_refCharacter.Experience);
    nNextExperience = CalculateExperienceFromRank(sti(xi_refCharacter.rank)+1);
    nFreeSkillPoints = sti(xi_refCharacter.Skill.FreeSkill);
	int nFreeAbilities = 0;
	if( CheckAttribute(xi_refCharacter,"perks.FreePoints") )
		nFreeAbilities = sti(xi_refCharacter.perks.FreePoints);

    nLeadership = sti(xi_refCharacter.Skill.Leadership);
    nFencing = sti(xi_refCharacter.Skill.Fencing);
    nSailing = sti(xi_refCharacter.Skill.Sailing);
    nAccuracy = sti(xi_refCharacter.Skill.Accuracy);
    nCannons = sti(xi_refCharacter.Skill.Cannons);
    nGrappling = sti(xi_refCharacter.Skill.Grappling);
    nRepair = sti(xi_refCharacter.Skill.Repair);
    nDefence = sti(xi_refCharacter.Skill.Defence);
    nCommerce = sti(xi_refCharacter.Skill.Commerce);
    nSneak = sti(xi_refCharacter.Skill.Sneak);

    GameInterface.StatusLine.EXP.Max = nNextExperience;
    GameInterface.StatusLine.EXP.Min = CalculateExperienceFromRank(sti(xi_refCharacter.rank));
    GameInterface.StatusLine.EXP.Value = nCurrentExperience;

    GameInterface.strings.CurrentExperience = nCurrentExperience;
    GameInterface.strings.NextExperience = nNextExperience;
    GameInterface.strings.Money = MakeMoneyShow(nPlayerMoney,MONEY_SIGN,MONEY_DELIVER);
    GameInterface.strings.CharacterName = xi_refCharacter.name+" "+xi_refCharacter.lastname;
    GameInterface.strings.Reputation = XI_ConvertString(GetReputationName(sti(xi_refCharacter.reputation)));
	GameInterface.strings.FreeAbilitiesPoints = nFreeAbilities;
    GameInterface.strings.FreeSkillPoints = nFreeSkillPoints;
    GameInterface.strings.Rank = xi_refCharacter.rank;
	GameInterface.strings.MaxHP = MakeInt(LAi_GetCharacterHP(xi_refCharacter)) + "/" + MakeInt(LAi_GetCharacterMaxHP(xi_refCharacter));

	SetSkillShow("SkillLeadership",nLeadership);
	SetSkillShow("SkillFencing",nFencing);
	SetSkillShow("SkillSailing",nSailing);
	SetSkillShow("SkillAccuracy",nAccuracy);
	SetSkillShow("SkillCannons",nCannons);
	SetSkillShow("SkillGrappling",nGrappling);
	SetSkillShow("SkillRepair",nRepair);
	SetSkillShow("SkillDefence",nDefence);
	SetSkillShow("SkillCommerce",nCommerce);
	SetSkillShow("SkillSneak",nSneak);

	SetNewPicture("FACEPICT", "interfaces\portraits\256\face_" + xi_refCharacter.FaceId + ".tga");
	if( xi_refCharacter.id == xi_refMainChar.id ) {
		SetNewPicture("TYPEPICT", "");
	} else {
		switch( FindFellowtravellers(xi_refMainChar,xi_refCharacter) )
		{
		case FELLOWTRAVEL_COMPANION:
			SetNewPicture("TYPEPICT", "interfaces\IsCompanion.tga");
		break;
		case FELLOWTRAVEL_OFFICER:
			SetNewPicture("TYPEPICT", "");
			//SetNewPicture("TYPEPICT", "interfaces\IsOfficer.tga");
		break;
		}
	}

	SendMessage(&GameInterface,"lsl",MSG_INTERFACE_MSG_TO_NODE,"exp",0);
	oldIndex = -1;
}

void ProcessCancelExit()
{
	interfaceResultCommand = RC_INTERFACE_CHARACTER_EXIT;
	if( CheckAttribute(&InterfaceStates,"InstantExit") && sti(InterfaceStates.InstantExit)==true )
	{
		CharInterfaceExit(true);
	}
	else
	{
		PostEvent("LaunchIAfterFrame",1,"sl", "I_SELECTMENU", 1);
		CharInterfaceExit(false);
	}
}

void CharInterfaceExit(bool flag)
{
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
    DelEventHandler("exitCancel","ProcessCancelExit");
	DelEventHandler("ievnt_command","ProcessCommandExecute");
	DelEventHandler("frame","ProcessFrame");

	WriteNewData();
    EndCancelInterface(flag);
}

void WriteNewData()
{
    xi_refCharacter.Skill.FreeSkill = nFreeSkillPoints;
    xi_refCharacter.Skill.Leadership = nLeadership;
    xi_refCharacter.Skill.Fencing = nFencing;
    xi_refCharacter.Skill.Sailing = nSailing;
    xi_refCharacter.Skill.Accuracy = nAccuracy;
    xi_refCharacter.Skill.Cannons = nCannons;
    xi_refCharacter.Skill.Grappling = nGrappling;
    xi_refCharacter.Skill.Repair = nRepair;
    xi_refCharacter.Skill.Defence = nDefence;
    xi_refCharacter.Skill.Commerce = nCommerce;
    xi_refCharacter.Skill.Sneak = nSneak;
}
    

void IncreaseSkill()
{
    if(nFreeSkillPoints>0)
    {
        switch( sti(GameInterface.SkillChanger.current) )
        {
        case 1:
			if(nLeadership==0)	{return;}
			if(nLeadership<MAX_CHARACTER_SKILL)
			{
				nLeadership++;
				SetSkillShow("SkillLeadership",nLeadership);
				SetNodeUsing("B_SKILLUP",nLeadership<MAX_CHARACTER_SKILL);
			}
			else return;
        break;

        case 2:
			if(nFencing==0)	{return;}
			if(nFencing<MAX_CHARACTER_SKILL)
			{
				nFencing++;
				SetSkillShow("SkillFencing",nFencing);
				SetNodeUsing("B_SKILLUP",nFencing<MAX_CHARACTER_SKILL);
			}
			else return;
        break;

        case 3:
			if(nSailing==0)	{return;}
			if(nSailing<MAX_CHARACTER_SKILL)
			{
				nSailing++;
				SetSkillShow("SkillSailing",nSailing);
				SetNodeUsing("B_SKILLUP",nSailing<MAX_CHARACTER_SKILL);
			}
			else return;
        break;

        case 4:
			if(nAccuracy==0)	{return;}
			if(nAccuracy<MAX_CHARACTER_SKILL)
			{
				nAccuracy++;
				SetSkillShow("SkillAccuracy",nAccuracy);
				SetNodeUsing("B_SKILLUP",nAccuracy<MAX_CHARACTER_SKILL);
			}
			else return;
        break;

        case 5:
			if(nCannons==0)	{return;}
			if(nCannons<MAX_CHARACTER_SKILL)
			{
				nCannons++;
				SetSkillShow("SkillCannons",nCannons);
				SetNodeUsing("B_SKILLUP",nCannons<MAX_CHARACTER_SKILL);
			}
			else return;
        break;

        case 6:
			if(nGrappling==0)	{return;}
			if(nGrappling<MAX_CHARACTER_SKILL)
			{
				nGrappling++;
				SetSkillShow("SkillGrappling",nGrappling);
				SetNodeUsing("B_SKILLUP",nGrappling<MAX_CHARACTER_SKILL);
			}
			else return;
        break;

        case 7:
			if(nRepair==0)	{return;}
			if(nRepair<MAX_CHARACTER_SKILL)
			{
				nRepair++;
				SetSkillShow("SkillRepair",nRepair);
				SetNodeUsing("B_SKILLUP",nRepair<MAX_CHARACTER_SKILL);
			}
			else return;
        break;

        case 8:
			if(nDefence==0)	{return;}
			if(nDefence<MAX_CHARACTER_SKILL)
			{
				nDefence++;
				SetSkillShow("SkillDefence",nDefence);
				SetNodeUsing("B_SKILLUP",nDefence<MAX_CHARACTER_SKILL);
			}
			else return;
        break;

        case 9:
			if(nCommerce==0)	{return;}
			if(nCommerce<MAX_CHARACTER_SKILL)
			{
				nCommerce++;
				SetSkillShow("SkillCommerce",nCommerce);
				SetNodeUsing("B_SKILLUP",nCommerce<MAX_CHARACTER_SKILL);
			}
			else return;
        break;

        case 10:
			if(nSneak==0)	{return;}
			if(nSneak<MAX_CHARACTER_SKILL)
			{
				nSneak++;
				SetSkillShow("SkillSneak",nSneak);
				SetNodeUsing("B_SKILLUP",nSneak<MAX_CHARACTER_SKILL);
			}
			else return;
        break;
        }
        nFreeSkillPoints--;
		GameInterface.strings.FreeSkillPoints = nFreeSkillPoints;
    }
}

int SetAlphaIntoColor(int col, int alpha)
{
	int newCol = and(col,16777215) + shl(alpha,24);
	return newCol;
}

int GetAlphaFromSkill(int nskill)
{
	switch(nskill)
	{
	case 0:		return 55;	break;
	case 1:		return 75;	break;
	case 2:		return 95;	break;
	case 3:		return 115;	break;
	case 4:		return 135;	break;
	case 5:		return 155;	break;
	case 6:		return 175;	break;
	case 7:		return 195;	break;
	case 8:		return 215;	break;
	case 9:		return 235;	break;
	case 10:	return 255;	break;
	}
	return 0;
}

void SetSkillShow(string skillName, int skillVal)
{
	GameInterface.strings.(skillName) = skillVal;
	int color = COLOR_NORMAL;
	if(skillVal==SKILL_MAX)	color = COLOR_MONEY;
	ChangeStringColor(skillName,SetAlphaIntoColor(color,GetAlphaFromSkill(skillVal)));
}

void ProcessCommandExecute()
{
	string comName = GetEventData();
	string nodName = GetEventData();

	switch(nodName)
	{
	case "LEFTCHANGE_CHARACTER":
		if(comName=="click")
		{
			if(bBeParty)
			{
				WriteNewData();
				SetNextParty(false);
				SetVariable();
			}
		}
	break;

	case "RIGHTCHANGE_CHARACTER":
		if(comName=="click")
		{
			if(bBeParty)
			{
				WriteNewData();
				SetNextParty(true);
				SetVariable();
			}
		}
	break;

	case "SKILLCHANGER":
		if(sti(GameInterface.SkillChanger.current)==0)
		{
			if(comName=="rightstep" && bBeParty)
			{
				WriteNewData();
				SetNextParty(true);
				SetVariable();
			}
			if(comName=="leftstep" && bBeParty)
			{
				WriteNewData();
				SetNextParty(false);
				SetVariable();
			}
		}
		else
		{
			if(sti(GameInterface.SkillChanger.current)==11)
			{
				if(comName=="activate")
				{
					GameInterface.AbilityChr = xi_refCharacter.index;
					PostEvent("LaunchIAfterFrame",1,"sl", "AbilityView", 1);
					interfaceResultCommand = RC_INTERFACE_CHARACTER_EXIT;
					CharInterfaceExit(false);
					return;
				}
			}
			else
			{
				if(comName=="activate")
				{	IncreaseSkill();
				}
			}
		}

	break;

	case "B_SKILLUP":
		if(comName=="click")
		{
			if(sti(GameInterface.SkillChanger.current)<11)
			{
				IncreaseSkill();
				oldIndex = -1;
			}
		}
	break;

	case "B_ABILITIES":
		if(comName=="click")
		{
			GameInterface.AbilityChr = xi_refCharacter.index;
			PostEvent("LaunchIAfterFrame",1,"sl", "AbilityView", 1);
			interfaceResultCommand = RC_INTERFACE_CHARACTER_EXIT;
			CharInterfaceExit(false);
			return;
		}
	break;
	}

}

void ProcessFrame()
{
	int newIndex = sti(GameInterface.SkillChanger.current);
	if(oldIndex!=newIndex)
	{
		bool bSetBtn = false;
		oldIndex = newIndex;
		if(newIndex>0)
		{
			if(nFreeSkillPoints>0)
			{
				switch(newIndex)
				{
				case 1:		if(nLeadership>0 && nLeadership<MAX_CHARACTER_SKILL){bSetBtn=true;}	break;
				case 2:		if(nFencing>0 && nFencing<MAX_CHARACTER_SKILL)		{bSetBtn=true;}	break;
				case 3:		if(nSailing>0 && nSailing<MAX_CHARACTER_SKILL)		{bSetBtn=true;}	break;
				case 4:		if(nAccuracy>0 && nAccuracy<MAX_CHARACTER_SKILL)	{bSetBtn=true;}	break;
				case 5:		if(nCannons>0 && nCannons<MAX_CHARACTER_SKILL)		{bSetBtn=true;}	break;
				case 6:		if(nGrappling>0 && nGrappling<MAX_CHARACTER_SKILL)	{bSetBtn=true;}	break;
				case 7:		if(nRepair>0 && nRepair<MAX_CHARACTER_SKILL)		{bSetBtn=true;}	break;
				case 8:		if(nDefence>0 && nDefence<MAX_CHARACTER_SKILL)		{bSetBtn=true;}	break;
				case 9:		if(nCommerce>0 && nCommerce<MAX_CHARACTER_SKILL)	{bSetBtn=true;}	break;
				case 10:	if(nSneak>0 && nSneak<MAX_CHARACTER_SKILL)			{bSetBtn=true;}	break;
				}
			}
			if(bSetBtn)
			{
				int pic_top = 12 + 34*newIndex;
				int pic_bottom = 44 + 34*newIndex;
				SendMessage(&GameInterface,"lsllllll", MSG_INTERFACE_MSG_TO_NODE,"B_SKILLUP",0, 528,pic_top,560,pic_bottom, 0);
			}
		}
		SetNodeUsing("B_ABILITIES",newIndex==11);
		SetNodeUsing("B_SKILLUP",bSetBtn);
	}
}

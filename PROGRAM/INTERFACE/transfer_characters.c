#define NONEFACE_TEXTURE_NAME "interfaces\empty_face.tga"

ref refMyCharacter;
ref refEnemyCharacter;
int nCompanionIndex;

int nMyCharacterCompanionPlace;

int curScrollNum;
int nFourImageNum;

string oldCurNode;

void InitInterface_RR(string iniName,ref myCh,ref enemyCh)
{
	int i;
	refMyCharacter = myCh;
	refEnemyCharacter = enemyCh;
	nMyCharacterCompanionPlace = -1;
	if(CheckAttribute(myCh,"InterfaceParam.i1")) {
		nMyCharacterCompanionPlace = sti(myCh.InterfaceParam.i1);
	} else {
		interfaceResultCommand = RC_INTERFACE_TRANSFER_MAIN_RETURN;
		EndCancelInterface(true);
		return;
	}
    GameInterface.title = "titleTransferCharacters";

	nCompanionIndex = GetCompanionIndex(refMyCharacter,nMyCharacterCompanionPlace);

	FillScroll();
	FillFourImages();

    SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);
	oldCurNode = GetCurrentNode();

    CreateString(true,"CharacterName",XI_ConvertString("Noname"),FONT_NORMAL,COLOR_NORMAL,320,192,SCRIPT_ALIGN_CENTER,1.0);

    CreateString(true,"SkillLeadership","",FONT_BOLD_NUMBERS,COLOR_NORMAL,300,224,SCRIPT_ALIGN_RIGHT,1.0);
    CreateString(true,"SkillFencing","",FONT_BOLD_NUMBERS,COLOR_NORMAL,300,258,SCRIPT_ALIGN_RIGHT,1.0);
    CreateString(true,"SkillSailing","",FONT_BOLD_NUMBERS,COLOR_NORMAL,300,292,SCRIPT_ALIGN_RIGHT,1.0);
    CreateString(true,"SkillAccuracy","",FONT_BOLD_NUMBERS,COLOR_NORMAL,300,326,SCRIPT_ALIGN_RIGHT,1.0);
    CreateString(true,"SkillCannons","",FONT_BOLD_NUMBERS,COLOR_NORMAL,300,358,SCRIPT_ALIGN_RIGHT,1.0);
    CreateString(true,"SkillGrappling","",FONT_BOLD_NUMBERS,COLOR_NORMAL,434,224,SCRIPT_ALIGN_RIGHT,1.0);
    CreateString(true,"SkillRepair","",FONT_BOLD_NUMBERS,COLOR_NORMAL,434,258,SCRIPT_ALIGN_RIGHT,1.0);
    CreateString(true,"SkillDefence","",FONT_BOLD_NUMBERS,COLOR_NORMAL,434,292,SCRIPT_ALIGN_RIGHT,1.0);
    CreateString(true,"SkillCommerce","",FONT_BOLD_NUMBERS,COLOR_NORMAL,434,326,SCRIPT_ALIGN_RIGHT,1.0);
    CreateString(true,"SkillSneak","",FONT_BOLD_NUMBERS,COLOR_NORMAL,434,358,SCRIPT_ALIGN_RIGHT,1.0);

	WasChange();

	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
    SetEventHandler("InterfaceCancel","ProcessCancelExit",0);
	SetEventHandler("RemovePress","RemoveProcess",0);
	SetEventHandler("frame","WasChange",0);
	SetEventHandler("PressPsgDown","ToRemoveButton",0);
	SetEventHandler("SelectPassenger","SelectPassenger",0);
}

void ProcessCancelExit()
{
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
    DelEventHandler("InterfaceCancel","ProcessCancelExit");
	DelEventHandler("RemovePress","RemoveProcess");
	DelEventHandler("frame","WasChange");
	DelEventHandler("PressPsgDown","ToRemoveButton");

	interfaceResultCommand = RC_INTERFACE_TRANSFER_MAIN_RETURN;
	EndCancelInterface(true);
}

void SelectPassenger()
{
	int i = GetCompanionIndex(refMyCharacter,nMyCharacterCompanionPlace);
	if(i>=0)
	{
		if(nFourImageNum<0) return;
		if(nFourImageNum>3) return;
	}
	else
	{
		if(nFourImageNum!=0) return;
	}
	int newCompanion = GetNotCaptivePassenger(refMyCharacter,curScrollNum);
	if(newCompanion<0) return;
	if( !GetRemovable(GetCharacter(newCompanion)) )
	{
		ShowHelpString("chelp_passengers#16");
		return;
	}

	int oldCharIdx;
	if(nFourImageNum==0)
	{
		if( GetCharacterSkill(GetCharacter(newCompanion),SKILL_LEADERSHIP)<1 ) {
			ShowHelpString( "chelp_CaptainAssign#1" );
			return;
		}
		if( GetCharacterSkill(GetCharacter(newCompanion),SKILL_SAILING)<1 ) {
			ShowHelpString( "chelp_CaptainAssign#2" );
			return;
		}
		oldCharIdx = SetCompanionIndex(refMyCharacter,nMyCharacterCompanionPlace,newCompanion);
		if(oldCharIdx==newCompanion) return;
		if(oldCharIdx>=0)
		{
			IMoveOfficers(GetCharacter(newCompanion),GetCharacter(oldCharIdx));
			if(oldCharIdx!=sti(refEnemyCharacter.index))
			{
				IDeleteShipAttributes(GetCharacter(oldCharIdx));
			}
		}
		ISetShipAttributes(GetCharacter(newCompanion));
		SetSelectable("REMOVE_BUTTON",true);
	}
	// Изменим список офицеров
	else
	{
		SetSelectable("REMOVE_BUTTON",true);
		oldCharIdx = GetCompanionIndex(refMyCharacter,nMyCharacterCompanionPlace);
		if(oldCharIdx<0) return;
		oldCharIdx = SetOfficersIndex(GetCharacter(oldCharIdx),nFourImageNum,newCompanion);
	}

	// изменим список пассажиров
	if(oldCharIdx!=-1)
		ChangePassenger(refMyCharacter,GetPassengerNumber(refMyCharacter,newCompanion),oldCharIdx);
	else
		RemovePassenger(refMyCharacter,GetCharacter(newCompanion));
	RefreshScreen();
}

void ToRemoveButton()
{
	if(GetSelectable("REMOVE_BUTTON")==true)
	{
		SetCurrentNode("REMOVE_BUTTON");
	}
}

void WasChange()
{
	int i,cn;
	int bYesChange = false;
	if(curScrollNum != sti(GameInterface.passengers_list.current))
	{
		curScrollNum = sti(GameInterface.passengers_list.current);
		bYesChange = true;
	}
	if(nFourImageNum != sti(GameInterface.FourImage.current))
	{
		nFourImageNum = sti(GameInterface.FourImage.current);
		SetSelectable("REMOVE_BUTTON",false);
		i = GetCompanionIndex(refMyCharacter,nMyCharacterCompanionPlace);
		if(i>=0)
		{
			cn = GetOfficersIndex(GetCharacter(i),nFourImageNum);
			if(cn>=0)
			{	SetSelectable("REMOVE_BUTTON",GetRemovable(GetCharacter(cn)));
			}
		}
		bYesChange = true;
	}
	if(oldCurNode!=GetCurrentNode())
	{
		oldCurNode = GetCurrentNode();
		bYesChange = true;
	}

	if(bYesChange == true)
	{
		ref CharRef;
		if(oldCurNode=="PASSENGERS_LIST")
		{
			cn = GetNotCaptivePassenger(refMyCharacter,curScrollNum);
			if(cn==-1)
			{
				GameInterface.strings.CharacterName = XI_ConvertString("Noname");

				GameInterface.strings.SkillLeadership = 0;
				GameInterface.strings.SkillFencing = 0;
				GameInterface.strings.SkillSailing = 0;
				GameInterface.strings.SkillAccuracy = 0;
				GameInterface.strings.SkillCannons = 0;
				GameInterface.strings.SkillGrappling = 0;
				GameInterface.strings.SkillRepair = 0;
				GameInterface.strings.SkillDefence = 0;
				GameInterface.strings.SkillCommerce = 0;
				GameInterface.strings.SkillSneak = 0;
			}
			else
			{
				CharRef = GetCharacter(cn);
				GameInterface.strings.CharacterName = CharRef.name+" "+CharRef.lastname;

				GameInterface.strings.SkillLeadership = CharRef.Skill.Leadership;
				GameInterface.strings.SkillFencing = CharRef.Skill.Fencing;
				GameInterface.strings.SkillSailing = CharRef.Skill.Sailing;
				GameInterface.strings.SkillAccuracy = CharRef.Skill.Accuracy;
				GameInterface.strings.SkillCannons = CharRef.Skill.Cannons;
				GameInterface.strings.SkillGrappling = CharRef.Skill.Grappling;
				GameInterface.strings.SkillRepair = CharRef.Skill.Repair;
				GameInterface.strings.SkillDefence = CharRef.Skill.Defence;
				GameInterface.strings.SkillCommerce = CharRef.Skill.Commerce;
				GameInterface.strings.SkillSneak = CharRef.Skill.Sneak;
			}
		}
		else
		{
			GameInterface.strings.CharacterName = XI_ConvertString("Summary Skills");
			i = GetCompanionIndex(refMyCharacter,nMyCharacterCompanionPlace);
			if(i>=0)
			{
				CharRef = GetCharacter(i);
				GameInterface.strings.SkillLeadership = GetSummonSkillFromName(CharRef,"Leadership");
				GameInterface.strings.SkillFencing = GetSummonSkillFromName(CharRef,"Fencing");
				GameInterface.strings.SkillSailing = GetSummonSkillFromName(CharRef,"Sailing");
				GameInterface.strings.SkillAccuracy = GetSummonSkillFromName(CharRef,"Accuracy");
				GameInterface.strings.SkillCannons = GetSummonSkillFromName(CharRef,"Cannons");
				GameInterface.strings.SkillGrappling = GetSummonSkillFromName(CharRef,"Grappling");
				GameInterface.strings.SkillRepair = GetSummonSkillFromName(CharRef,"Repair");
				GameInterface.strings.SkillDefence = GetSummonSkillFromName(CharRef,"Defence");
				GameInterface.strings.SkillCommerce = GetSummonSkillFromName(CharRef,"Commerce");
				GameInterface.strings.SkillSneak = GetSummonSkillFromName(CharRef,"Sneak");
			}
			else
			{
				GameInterface.strings.SkillLeadership = 0;
				GameInterface.strings.SkillFencing = 0;
				GameInterface.strings.SkillSailing = 0;
				GameInterface.strings.SkillAccuracy = 0;
				GameInterface.strings.SkillCannons = 0;
				GameInterface.strings.SkillGrappling = 0;
				GameInterface.strings.SkillRepair = 0;
				GameInterface.strings.SkillDefence = 0;
				GameInterface.strings.SkillCommerce = 0;
				GameInterface.strings.SkillSneak = 0;
			}
		}
	}
}

void RemoveProcess()
{
	int i,j,n;

	i = GetCompanionIndex(refMyCharacter,nMyCharacterCompanionPlace);
	if(i<0) return;

	if(nFourImageNum>0)
	{
		j = SetOfficersIndex(GetCharacter(i),nFourImageNum,-1);
		if(j>0)	AddPassenger(refMyCharacter,GetCharacter(j),false);
	}
	else
	{
		for(j=1; j<4; j++)
		{
			n = SetOfficersIndex(GetCharacter(i),j,-1);
			if(n>=0) AddPassenger(refMyCharacter,GetCharacter(n),false);
		}
		SetCompanionIndex(refMyCharacter,nMyCharacterCompanionPlace,-1);
		if(i!=sti(refEnemyCharacter.index))
		{
			IDeleteShipAttributes(GetCharacter(i));
		}
		AddPassenger(refMyCharacter,GetCharacter(i),false);
	}
	RefreshScreen();
	SetSelectable("REMOVE_BUTTON",false);
	if(GetNotCaptivePassenger(refMyCharacter,0)!=-1)	SetCurrentNode("PASSENGERS_LIST");
	else	SetCurrentNode("COMPAIN_LIST");
}

ref GetMyCharacterRef()
{
	return refMyCharacter;
}

ref GetEnemyCharacterRef()
{
	return refEnemyCharacter;
}

void FillScroll()
{
	curScrollNum = -1;
    GameInterface.passengers_list.current = 0;
	GameInterface.passengers_list.NotUsed = 5;

	GameInterface.passengers_list.ImagesGroup.t0 = "EMPTYFACE";
	FillFaceList("passengers_list.ImagesGroup",refMyCharacter,0); // officers
	FillFaceList("passengers_list.ImagesGroup",refMyCharacter,2); // passengers
	FillFaceList("passengers_list.ImagesGroup",refMyCharacter,1); // companions
	if(nCompanionIndex>=0)	FillFaceList("passengers_list.ImagesGroup",GetCharacter(nCompanionIndex),0); // enemy officers

	GameInterface.passengers_list.BadTex1 = FindFaceGroupNum("passengers_list.ImagesGroup","EMPTYFACE");
	GameInterface.passengers_list.BadPic1 = "emptyface";

	ref charRef;
	int charQuantity=0;
	string attributeName;
	while(GetNotCaptivePassenger(refMyCharacter,charQuantity)!=-1)
	{
		charRef = GetCharacter(GetNotCaptivePassenger(refMyCharacter,charQuantity));
		attributeName = "pic" + (charQuantity+1);
		GameInterface.passengers_list.(attributeName).img1 = GetFacePicName(charRef);
		GameInterface.passengers_list.(attributeName).tex1 = FindFaceGroupNum("passengers_list.ImagesGroup","FACE128_"+charRef.FaceId);
		charQuantity++;
	}
	GameInterface.passengers_list.ListSize = charQuantity;
}

void RefillScroll()
{
	ref charRef;
	int charQuantity=0;
	string attributeName;

	// Delete old attributes
	charQuantity = sti(GameInterface.passengers_list.ListSize);
	for(int i=0; i<charQuantity; i++)
	{
		attributeName = "passengers_list.pic" + (i+1);
		DeleteAttribute(&GameInterface, attributeName);
	}
	// fill new data
	charQuantity = 0;
	while(GetNotCaptivePassenger(refMyCharacter,charQuantity)!=-1)
	{
		charRef = GetCharacter(GetNotCaptivePassenger(refMyCharacter,charQuantity));
		attributeName = "pic" + (charQuantity+1);
		GameInterface.passengers_list.(attributeName).img1 = GetFacePicName(charRef);
		GameInterface.passengers_list.(attributeName).tex1 = FindFaceGroupNum("passengers_list.ImagesGroup","FACE128_"+charRef.FaceId);
		charQuantity++;
	}
	GameInterface.passengers_list.ListSize = charQuantity;
}

void FillFourImages()
{
	int i,cn;
	string attrName;
	ref refCurChar;

    nFourImageNum = -1;
	GameInterface.FourImage.current = 0;
	GameInterface.FourImage.ImagesGroup.t0 = "EMPTYFACE";
	GameInterface.FourImage.BadOnePicture = NONEFACE_TEXTURE_NAME;
	FillFaceList( "FourImage.ImagesGroup", refMyCharacter, 0 ); // officers
	FillFaceList( "FourImage.ImagesGroup", refMyCharacter, 2 ); // passengers
	FillFaceList( "FourImage.ImagesGroup", refMyCharacter, 1 ); // companions
	if(nCompanionIndex>=0) FillFaceList( "FourImage.ImagesGroup", GetCharacter(nCompanionIndex), 0 ); // enemy officers

	i = GetCompanionIndex(refMyCharacter,nMyCharacterCompanionPlace);
	ref baseChar;
	if(i>=0)
	{
		baseChar = GetCharacter(i);
		for(i=0; i<4; i++)
		{
			attrName = "pic"+(i+1);
			cn = GetOfficersIndex(baseChar,i);
			if(cn==-1)
			{
				GameInterface.FourImage.(attrName).img1 = "emptyface";
				GameInterface.FourImage.(attrName).tex1 = FindFaceGroupNum("FourImage.ImagesGroup","EMPTYFACE");
			}
			else
			{
				refCurChar = GetCharacter(cn);
				GameInterface.FourImage.(attrName).img1 = GetFacePicName(refCurChar);
				GameInterface.FourImage.(attrName).tex1 = FindFaceGroupNum("FourImage.ImagesGroup","FACE128_"+refCurChar.FaceID);
			}
			GameInterface.FourImage.(attrName).selected = true;
		}
	}
	else
	{
		for(i=0; i<4; i++)
		{
			attrName = "pic"+(i+1);
			GameInterface.FourImage.(attrName).img1 = "emptyface";
			GameInterface.FourImage.(attrName).tex1 = 0;
			GameInterface.FourImage.(attrName).selected = false;
		}
		GameInterface.FourImage.pic1.selected = true;
	}
}

void RefillFourImages()
{
	int i,cn;
	string attrName;
	ref baseChar,refCurChar;

	i = GetCompanionIndex(refMyCharacter,nMyCharacterCompanionPlace);
	if(i>=0)
	{
		baseChar = GetCharacter(i);
		for(i=0; i<4; i++)
		{
			attrName = "pic"+(i+1);
			cn = GetOfficersIndex(baseChar,i);
			if(cn==-1)
			{
				GameInterface.FourImage.(attrName).img1 = "emptyface";
				GameInterface.FourImage.(attrName).tex1 = FindFaceGroupNum("FourImage.ImagesGroup","EMPTYFACE");
			}
			else
			{
				refCurChar = GetCharacter(cn);
				GameInterface.FourImage.(attrName).img1 = GetFacePicName(refCurChar);
				GameInterface.FourImage.(attrName).tex1 = FindFaceGroupNum("FourImage.ImagesGroup","FACE128_"+refCurChar.FaceID);
			}
			GameInterface.FourImage.(attrName).selected = true;
		}
	}
	else
	{
		for(i=0; i<4; i++)
		{
			attrName = "pic"+(i+1);
			GameInterface.FourImage.(attrName).img1 = "emptyface";
			GameInterface.FourImage.(attrName).tex1 = 0;
			GameInterface.FourImage.(attrName).selected = false;
		}
		GameInterface.FourImage.pic1.selected = true;
	}
}

void RefreshScreen()
{
	//DeleteAttribute(&GameInterface,"passengers_list");
	//DeleteAttribute(&GameInterface,"FourImage");
	RefillScroll();//FillScroll();
	RefillFourImages();//FillFourImages();
	SendMessage(&GameInterface,"ls",MSG_INTERFACE_REFRESH_SCROLL,"PASSENGERS_LIST");
	SendMessage(&GameInterface,"lsl",MSG_INTERFACE_FOURIMAGE_CHANGE,"COMPAIN_LIST",-1);
}

void IMoveOfficers(ref rToChar,ref rFromChar)
{
	for(int i=1; i<4 ; i++)
	{
		SetOfficersIndex(rToChar,i,SetOfficersIndex(rFromChar,i,-1));
	}
}

void IDeleteShipAttributes(ref chref)
{
	DeleteAttribute(chref,"ship");
	chref.ship.type = SHIP_NOTUSED;
}

void ISetShipAttributes(ref chref)
{
	if(chref.index == refEnemyCharacter.index) return;
	DeleteAttribute(chref,"ship");
	aref arToChar;	makearef(arToChar,chref.ship);
	aref arFromChar;	makearef(arFromChar,refEnemyCharacter.ship);
	CopyAttributes(arToChar,arFromChar);
}

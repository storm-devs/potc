
native string LanguageGetLanguage();
native int LanguageOpenFile(string sFileName);
native void LanguageCloseFile(int idLngFile);
native string LanguageConvertString(int userLngFileID, string inStr);
native void LanguageSetLanguage(string sLanguageName);
native string XI_ConvertString(string inStr);
native int GlobalLngFileID();
native string LanguageGetFaderPic(string faderPicName);

native void XI_SetColorCorrection(float fContrast, float fGamma, float fBrightness);
native void XI_SetMouseSensitivity( float fMouseXSens, float fMouseYSens );
native void XI_ControlMakeInvert(string sControlName, int bInvertState);

#libriary "script_interface_functions"

void CreateImage(string AttrName,string imgListName,string imgName,int left,int top,int right,int bottom)
{
	GameInterface.pictures.(AttrName).tex = imgListName;
    GameInterface.pictures.(AttrName).pic = imgName;
    SendMessage(&GameInterface,"lslllll",MSG_INTERFACE_PLACE_IMAGE,AttrName,true,left,top,right,bottom);
}

void CreateAbsoluteImage(string AttrName,string imgListName,string imgName,int left,int top,int right,int bottom)
{
	GameInterface.pictures.(AttrName).tex = imgListName;
    GameInterface.pictures.(AttrName).pic = imgName;
    SendMessage(&GameInterface,"lslllll",MSG_INTERFACE_PLACE_IMAGE,AttrName,false,left,top,right,bottom);
}

void SetPictureBlind(string picName,bool blindFlag,int minCol,int maxCol)
{
	SendMessage(&GameInterface,"lslll",MSG_INTERFACE_SET_BLIND,picName,blindFlag,minCol,maxCol);
}

void CreateString(int enable,string strName, string strData, string fontName, int color, int x, int y, int alignment, float scale)
{
    GameInterface.strings.(strName) = strData;
    SendMessage(&GameInterface,"lssllllf",MSG_INTERFACE_CREATE_STRING, strName, fontName, color, x,y,alignment,scale);
    if(enable==FALSE)
    {
        SendMessage(&GameInterface,"ls", MSG_INTERFACE_DISABLE_STRING, strName);
    }
}

void DisableString(string strName)
{
    SendMessage(&GameInterface,"ls", MSG_INTERFACE_DISABLE_STRING, strName);
}

void EnableString(string strName)
{
    SendMessage(&GameInterface,"ls", MSG_INTERFACE_ENABLE_STRING, strName);
}

void ChangeStringColor(string strName, int newCol)
{
	SendMessage(&GameInterface,"lsl",MSG_INTERFACE_CHANGE_STR_COLOR,strName,newCol);
}

void SetNodeUsing(string nodeName,int bUsing)
{
    SendMessage(&GameInterface,"lsl", MSG_INTERFACE_SET_NODE_USING, nodeName, bUsing);
}

void SetCurrentNode(string nodeName)
{
    SendMessage(&GameInterface,"ls", MSG_INTERFACE_NEW_CURRENT_NODE,nodeName);
}
string GetCurrentNode()
{
	string retVal;
	SendMessage(&GameInterface,"le", MSG_INTERFACE_GET_CURRENT_NODE,&retVal);
	return retVal;
}

void ShowHelpString(string helpString)
{
    SendMessage(&GameInterface,"ls", MSG_INTERFACE_SETHELPSTRING, helpString);
}

string MakeMoneyShow(int moneyQuantity,string sign,string deliver)
{
	string moneyStr;
	int i,j;
	moneyStr="";
	while(moneyQuantity>999)
	{
		i = moneyQuantity/1000;
		j = moneyQuantity-i*1000;
		if(j>99)
		{
			moneyStr = deliver + j + moneyStr;
		}
		else
		{
			if(j>9)
			{
				moneyStr = deliver+"0" + j + moneyStr;
			}
			else
			{
				moneyStr = deliver+"00" + j + moneyStr;
			}
		}
		moneyQuantity = i;
	}
	moneyStr = sign+moneyQuantity+moneyStr;
	return moneyStr;
}

void SetNewPicture(string _NodeName,string _NewPictureFileName)
{
	SendMessage(&GameInterface,"lslls", MSG_INTERFACE_MSG_TO_NODE,_NodeName,2, false, _NewPictureFileName);
}
void SetNewVideoPicture(string _NodeName,string _NewVideoPicFileName)
{
	SendMessage(&GameInterface,"lslls", MSG_INTERFACE_MSG_TO_NODE,_NodeName,2, true, _NewVideoPicFileName);
}

void SetSelectable(string _NodeName,int _Selectable)
{
	SendMessage(&GameInterface,"lsl", MSG_INTERFACE_SET_SELECTABLE, _NodeName, _Selectable);
}
int GetSelectable(string _NodeName)
{
	return SendMessage(&GameInterface,"ls", MSG_INTERFACE_GET_SELECTABLE, _NodeName);
}

void SetClickable(string _NodeName, bool ClickStatus)
{
	SendMessage(&GameInterface,"lslll", MSG_INTERFACE_MSG_TO_NODE,_NodeName,-1,1, ClickStatus);
}
bool GetClickable(string _NodeName)
{
	return SendMessage(&GameInterface,"lsll", MSG_INTERFACE_MSG_TO_NODE,_NodeName,-1,2);
}

void DelFromScroll(string nodeName,int pnum)
{
	int qn = sti(GameInterface.(nodeName).ListSize)-1;
	aref inar,outar;
	string attrName;
	for(int i=pnum; i<qn; i++)
	{
		attrName = "pic"+(i+1);
		makearef(inar,GameInterface.(nodeName).(attrName));
		attrName = "pic"+(i+2);
		makearef(outar,GameInterface.(nodeName).(attrName));
		CopyAttributes(inar,outar);
	}
	attrName = "pic"+(i+1);
	DeleteAttribute(&GameInterface,nodeName+"."+attrName);
	if(qn>=0) GameInterface.(nodeName).ListSize = qn;
	SendMessage(&GameInterface,"lsl", MSG_INTERFACE_DEL_SCROLLIMAGE, nodeName, pnum);
}

void AddToScroll(string nodeName,int pnum)
{
	SendMessage(&GameInterface,"lsl", MSG_INTERFACE_ADD_SCROLLIMAGE, nodeName, pnum);
}

void XI_SetQuestTitles(string nodName,aref questInfo,int topNum)
{
	SendMessage(&GameInterface,"lsal",MSG_INTERFACE_SET_TITLE_STRINGS,nodName,questInfo,topNum);
}

int GetShipTexture(string shipType)
{
	if(shipType=="Not Used") return -1;
	if(shipType=="Galeoth1") return 1;
	if(shipType=="Galeoth2") return 1;
	return 0;
}

string GetShipTextureName(string shipType)
{
	if(shipType=="Not Used") return "";
	if(shipType=="Galeoth1") return "SHIPS1";
	if(shipType=="Galeoth2") return "SHIPS1";
	return "SHIPS16";
}

string GetFaceGroupName(int charIdx)
{
	if(charIdx<0) {return "EMPTYFACE";}
	return "FACE128_"+Characters[charIdx].FaceID;
}

string GetFacePictureName(int charIdx)
{
	if(charIdx<0) return "emptyface";
	return "face";
}

void SetFormatedText(string sNodeName, string sText)
{
	SendMessage(&GameInterface,"lss",MSG_INTERFACE_SET_FORMATEDTEXT,sNodeName,sText);
}

string FloatToString(float fl,int nDigAfterPoint)
{
	float fmul = pow(10.0,nDigAfterPoint);
	fl = fl + 0.5/fmul;
	int p1 = makeint(fl);
	int p2 = makeint((fl-p1)*fmul);
	return p1+"."+p2;
}

int GetStringWidth(string str, string fontID, float fScale)
{
	return SendMessage(&GameInterface, "lssf", MSG_INTERFACE_GET_STRWIDTH, str, fontID, fScale);
}

string GetItemPictureName(string itemName)
{
	aref arItm;
	if( Items_FindItem(itemName,&arItm)>=0 )
	{
		if( CheckAttribute(arItm,"picIndex") )
		{
			return	"itm"+sti(arItm.picIndex);
		}
	}
	return "cannon back";
}

string GetItemTextureName(string itemName)
{
	aref arItm;
	if( Items_FindItem(itemName,&arItm)>=0 )
	{
		if( CheckAttribute(arItm,"picTexture") )
		{
			return	arItm.picTexture;
		}
	}
	return "ICONS";
}

int GetItemPictureTexture(string accessString, string itemName)
{
	aref arItm,arGroup;
	makearef(arGroup,GameInterface.(accessString));
	string sTexName = "ICONS";

	if( Items_FindItem(itemName,&arItm)>=0 )
	{	if( CheckAttribute(arItm,"picTexture") )
		{	sTexName = arItm.picTexture;
		}
	}
	int q = GetAttributesNum(arGroup);
	for(int i=0; i<q; i++)
	{	if( GetAttributeValue(GetAttributeN(arGroup,i)) == sTexName )
		{	return i;
		}
	}
	return -1;
}

void FillImagesGroupForItems(aref arImgGrp)
{
	int i,n,q;
	string stmp;
	object objtmp;
	for(i=0; i<ITEMS_QUANTITY; i++)
	{
		if( CheckAttribute( &Items[i], "picTexture" ) && Items[i].picTexture!="" )
		{
			stmp = Items[i].picTexture;
			objtmp.(stmp) = true;
		}
	}
	q = GetAttributesNum(&objtmp);
	n = GetAttributesNum(arImgGrp)+1;
	for(i=0; i<q; i++)
	{
		stmp = "t"+n;
		arImgGrp.(stmp) = GetAttributeName(GetAttributeN(&objtmp,i));
		n++;
	}
}

string GetFacePicName(ref chref)
{
	return "face";
}

void FillFaceList(string strAccess, ref chref, int fillCode)
{
	aref ar;
	makearef(ar, GameInterface.(strAccess));

	int n, cn, q;

	AddFaceGroup(strAccess,"FACE128_"+chref.faceID);

	if(fillCode==0) // officers
	{
		for(n=1; n<4; n++)
		{
			cn = GetOfficersIndex(chref,n);
			if( cn>=0 ) {
				AddFaceGroup(strAccess,"FACE128_"+Characters[cn].faceID);
			}
		}
	}

	if(fillCode==1) // companions
	{
		for(n=1; n<4; n++)
		{
			cn = GetCompanionIndex(chref,n);
			if( cn>=0 ) {
				AddFaceGroup(strAccess,"FACE128_"+Characters[cn].faceID);
			}
		}
	}

	if(fillCode==2) // passengers
	{
		q = GetPassengersQuantity(chref);
		for(n=0; n<q; n++)
		{
			cn = GetPassenger(chref,n);
			if( cn>=0 ) {
				AddFaceGroup(strAccess,"FACE128_"+Characters[cn].faceID);
			}
		}
	}
}

void AddFaceGroup(string strAccess, string groupName)
{
	if( FindFaceGroupNum(strAccess,groupName)<0 )
	{
		aref ar;
		makearef(ar, GameInterface.(strAccess));
		string attrName = "t"+GetAttributesNum(ar);
		ar.(attrName) = groupName;
	}
}

int FindFaceGroupNum(string strAccess, string groupName)
{
	int n, q;
	aref aRoot, aCur;
	makearef(aRoot, GameInterface.(strAccess));

	q = GetAttributesNum(aRoot);
	for(n=0; n<q; n++)
	{
		aCur = GetAttributeN(aRoot,n);
		if( GetAttributeValue(aCur) == groupName ) return n;
	}

	return -1;
}

string GlobalStringConvert(string strID)
{
	return LanguageConvertString( GlobalLngFileID(), strID );
}

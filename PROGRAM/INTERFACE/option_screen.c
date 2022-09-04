#define OPAGE_MAIN			0
#define OPAGE_SAILING		1
#define OPAGE_VIDEO			2
#define OPAGE_SOUNDS		3
#define OPAGE_CAMERA_MOD	4
#define OPAGE_CONTROLS_1	5
#define OPAGE_CONTROLS_2	6
#define OPAGE_CONTROLS_3	7

#define MAX_PAGES_QUANTITY	4

float i_fCurMusic;
float i_fCurSound;
float i_fCurDialog;

float i_fCurContrast = 0.5;
float i_fCurGamma = 0.5;
float i_fCurBright = 0.5;

float i_fCurXSens = 0.5;
float i_fCurYSens = 0.5;

int gi_nCurrentPage = -1;

bool g_bDisableControlChange = false;

string gsKeyWindowName;

object objArrayControls;

string g_sGroupName;
int nLastTextGroupNum;
int nLastTextStringNum;
int curCntrlIdx;

int nFadeStr_AlUsed = 0;
int nFadeStr_NoStick = 0;

void InitInterface(string iniName)
{
	GameInterface.title = "titleOptions";

	if( GetTargetPlatform()=="pc" ) {
		g_bDisableControlChange = false;
		gsKeyWindowName = "KEYSWINDOW_PC";
	} else {
		g_bDisableControlChange = true;
		gsKeyWindowName = "KEYSWINDOW_XBOX";
	}
//	g_bDisableControlChange = true;

	ISetVariable();

	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);

	StartVideoSetting();

	SetNodeUsing("KEY_CHOOSER",false);
	gi_nCurrentPage = OPAGE_MAIN;
	SetFormatedText("RESTORE_STRINGS",XI_ConvertString("Confirm default restore keys"));

	CreateString(false,"GroupName","",FONT_NORMAL,COLOR_NORMAL,320,140,SCRIPT_ALIGN_CENTER,1.0);

	SetEventHandler("TitleSelect","DoTitleSelect",0);
	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
	SetEventHandler("exitCancel","ProcessCancelExit",0);
	SetEventHandler("ievnt_command","ProcessCommandExecute",0);

	SetEventHandler("FormatedTextActivate","procFTActivate",0);
	SetEventHandler("evntUpdateFormtText","procFTUpdate",0);
	SetEventHandler("SetScrollerPos","procFTSetScrollPos",0);
	SetEventHandler("ScrollPosChange","ProcScrollPosChange",0);
	SetEventHandler("frame","IProcessFrame",0);
	SetEventHandler("evntKeyChoose","procKeyChoose",0);
	SetEventHandler("ScrollTopChange","ProcScrollChange",0);

	aref ar; makearef(ar,objControlsState.key_codes);
	SendMessage(&GameInterface,"lsla",MSG_INTERFACE_MSG_TO_NODE,"KEY_CHOOSER", 0,ar);

	if( g_bDisableControlChange ) {
		SendMessage(&GameInterface,"lsls",MSG_INTERFACE_MSG_TO_NODE,"MB_CONTROLS", 0,XI_ConvertString("View Controls"));
	}

	if( GetTargetPlatform()=="pc" ) {
		//SetSelectable("MB_CAMERA",false);
		SetNodeUsing("MB_CAMERA",false);
	}

	SetEventHandler("evntFadeStrings","FadeStringsUpdate",0);
	PostEvent("evntFadeStrings",100);
}

void ISetVariable()
{
	// SOUNDS
	i_fCurMusic = 0.5;
	i_fCurSound = 0.5;
	i_fCurDialog = 0.5;

	SendMessage(&sound,"leee",MSG_SOUND_GET_MASTER_VOLUME,&i_fCurSound,&i_fCurMusic,&i_fCurDialog);

	GameInterface.nodes.music.value = i_fCurMusic;
	GameInterface.nodes.sound.value = i_fCurSound;
	GameInterface.nodes.dialog.value = i_fCurDialog;

	// MOUSE
	i_fCurXSens = 0.5;
	i_fCurYSens = 0.5;
	if( CheckAttribute(&InterfaceStates,"mouse.x_sens") ) {i_fCurXSens=stf(InterfaceStates.mouse.x_sens);}
	if( CheckAttribute(&InterfaceStates,"mouse.y_sens") ) {i_fCurYSens=stf(InterfaceStates.mouse.y_sens);}
	if(i_fCurXSens<0.0) i_fCurXSens = 0.0;
	if(i_fCurXSens>1.0) i_fCurXSens = 1.0;
	if(i_fCurYSens<0.0) i_fCurYSens = 0.0;
	if(i_fCurYSens>1.0) i_fCurYSens = 1.0;

	GameInterface.nodes.controls_x_sensive.value = i_fCurXSens;
	GameInterface.nodes.controls_y_sensive.value = i_fCurYSens;
}

void IProcessFrame()
{
	bool bYesChange = false;

	if(gi_nCurrentPage==OPAGE_SOUNDS)
	{
		if(i_fCurMusic!=stf(GameInterface.nodes.music.value)) {
			i_fCurMusic = stf(GameInterface.nodes.music.value);
			bYesChange = true;
		}
		if(i_fCurSound!=stf(GameInterface.nodes.sound.value)) {
			i_fCurSound = stf(GameInterface.nodes.sound.value);
			bYesChange = true;
		}
		if(i_fCurDialog!=stf(GameInterface.nodes.dialog.value)) {
			i_fCurDialog = stf(GameInterface.nodes.dialog.value);
			bYesChange = true;
		}
		if(bYesChange) {
			SendMessage(&sound,"lfff",MSG_SOUND_SET_MASTER_VOLUME,i_fCurSound,i_fCurMusic,i_fCurDialog);
		}
	}

	if(gi_nCurrentPage==OPAGE_VIDEO)
	{
		if(i_fCurContrast!=stf(GameInterface.nodes.contrast_slide.value)) {
			i_fCurContrast = stf(GameInterface.nodes.contrast_slide.value);
			bYesChange = true;
		}
		if(i_fCurGamma!=stf(GameInterface.nodes.gamma_slide.value)) {
			i_fCurGamma = stf(GameInterface.nodes.gamma_slide.value);
			bYesChange = true;
		}
		if(i_fCurBright!=stf(GameInterface.nodes.bright_slide.value)) {
			i_fCurBright = stf(GameInterface.nodes.bright_slide.value);
			bYesChange = true;
		}
		if(bYesChange) {
			XI_SetColorCorrection( ConvertContrast(i_fCurContrast,false), ConvertGamma(i_fCurGamma,false), ConvertBright(i_fCurBright,false) );
		}
	}

	if(gi_nCurrentPage==OPAGE_CONTROLS_1)
	{
		if(i_fCurXSens!=stf(GameInterface.nodes.controls_x_sensive.value)) {
			i_fCurXSens = stf(GameInterface.nodes.controls_x_sensive.value);
			bYesChange = true;
		}
		if(i_fCurYSens!=stf(GameInterface.nodes.controls_y_sensive.value)) {
			i_fCurYSens = stf(GameInterface.nodes.controls_y_sensive.value);
			bYesChange = true;
		}
		InterfaceStates.mouse.x_sens = i_fCurXSens;
		InterfaceStates.mouse.y_sens = i_fCurYSens;
		SetRealMouseSensitivity();
	}

}

void ProcessCancelExit()
{
	IDoExit(RC_INTERFACE_OPTIONSCREEN_EXIT);
	if( !CheckAttribute(&InterfaceStates,"InstantExit") || sti(InterfaceStates.InstantExit)==false ) {
		ReturnToMainMenu();
	}
}

void IDoExit(int exitCode)
{
	DelEventHandler("TitleSelect","DoTitleSelect");
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
	DelEventHandler("exitCancel","ProcessCancelExit");
	DelEventHandler("ievnt_command","ProcessCommandExecute");
	DelEventHandler("FormatedTextActivate","procFTActivate");
	DelEventHandler("evntUpdateFormtText","procFTUpdate");
	DelEventHandler("SetScrollerPos","procFTSetScrollPos");
	DelEventHandler("ScrollPosChange","ProcScrollPosChange");
	DelEventHandler("frame","IProcessFrame");
	DelEventHandler("evntKeyChoose","procKeyChoose");
	DelEventHandler("ScrollTopChange","ProcScrollChange");
	DelEventHandler("evntFadeStrings","FadeStringsUpdate");

    interfaceResultCommand = exitCode;
	if( CheckAttribute(&InterfaceStates,"InstantExit") && sti(InterfaceStates.InstantExit)==true ) {
	    EndCancelInterface(true);
	} else {
		EndCancelInterface(false);
	}
	ControlsMakeInvert();
	SaveGameOptions();
}

void ProcessCommandExecute()
{
	string comName = GetEventData();
	string nodName = GetEventData();

	switch(nodName)
	{
	case "MB_SAILING":
		if(comName=="activate" || comName=="click") {
			ShowOptionsPage(OPAGE_SAILING);
		}
	break;

	case "MB_VIDEO":
		if(comName=="activate" || comName=="click") {
			ShowOptionsPage(OPAGE_VIDEO);
		}
	break;

	case "MB_SOUNDS":
		if(comName=="activate" || comName=="click") {
			ShowOptionsPage(OPAGE_SOUNDS);
		}
	break;

	case "MB_CAMERA":
		if(comName=="activate" || comName=="click") {
			ShowOptionsPage(OPAGE_CAMERA_MOD);
		}
	break;

	case "MB_CONTROLS":
		if(comName=="activate" || comName=="click") {
			if( g_bDisableControlChange ) {ShowOptionsPage(OPAGE_CONTROLS_2);}
			else {ShowOptionsPage(OPAGE_CONTROLS_1);}
		}
		if(comName=="downstep")
		{
			if(GetSelectable("MB_CAMERA")) {SetCurrentNode("MB_CAMERA");}
		}
	break;



	case "ARCADEMODE_1":
		if(comName=="activate" || comName=="click")
		{
			bArcadeMode = true;
			TmpI_ShowArcadeMode();
		}
	break;

	case "ARCADEMODE_2":
		if(comName=="activate" || comName=="click")
		{
			bArcadeMode = false;
			TmpI_ShowArcadeMode();
		}
	break;

	case "CAMERAMODE_1":
		if(comName=="activate" || comName=="click")
		{
			locCameraEnableSpecialMode = true;
			TmpI_ShowCameraMode();
		}
	break;

	case "CAMERAMODE_2":
		if(comName=="activate" || comName=="click")
		{
			locCameraEnableSpecialMode = false;
			TmpI_ShowCameraMode();
		}
	break;





	case "VIDEO_DEFAULT":
		if(comName=="activate" || comName=="click") {
			ISetColorCorrection(1.0, 1.0, 0.0);
		}
	break;

	case "VIDEO_SAVE":
		if(comName=="activate" || comName=="click") {
			SaveVideoSettings();
		}
	break;





	case "CONTROLS_B_CHANGE":
		if(comName=="activate" || comName=="click") {
			ShowOptionsPage(OPAGE_CONTROLS_2);
		}
	break;
	case "CONTROLS_B_DEFAULT":
		if(comName=="activate" || comName=="click")
		{
			SetNodeUsing("RESTORE_RECT",true);
			SetNodeUsing("RESTORE_STRINGS",true);
			SetNodeUsing("RESTORE_OK",true);
			SetNodeUsing("RESTORE_CANCEL",true);
			SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 1, "RESTORE_OK");
			SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 2, "RESTORE_CANCEL");
			SetCurrentNode("RESTORE_OK");
		}
		if(comName=="downstep" && GetTargetPlatform()=="pc")
		{
			SetCurrentNode("CONTROLS_B_INVERT");
		}
	break;
	case "RESTORE_OK":
		if(comName=="activate" || comName=="click")
		{
			SetMouseToDefault();
			ControlsInit(GetTargetPlatform(),false);
			SetNodeUsing("RESTORE_RECT",false);
			SetNodeUsing("RESTORE_STRINGS",false);
			SetNodeUsing("RESTORE_OK",false);
			SetNodeUsing("RESTORE_CANCEL",false);
			SendMessage(&GameInterface,"ll", MSG_INTERFACE_LOCK_NODE, 0);
			SetCurrentNode("CONTROLS_B_DEFAULT");
		}
		if(comName=="deactivate")
		{
			SetNodeUsing("RESTORE_RECT",false);
			SetNodeUsing("RESTORE_STRINGS",false);
			SetNodeUsing("RESTORE_OK",false);
			SetNodeUsing("RESTORE_CANCEL",false);
			SendMessage(&GameInterface,"ll", MSG_INTERFACE_LOCK_NODE, 0);
			SetCurrentNode("CONTROLS_B_DEFAULT");
		}
	break;
	case "RESTORE_CANCEL":
		if(comName=="activate" || comName=="click" || comName=="deactivate")
		{
			SetNodeUsing("RESTORE_RECT",false);
			SetNodeUsing("RESTORE_STRINGS",false);
			SetNodeUsing("RESTORE_OK",false);
			SetNodeUsing("RESTORE_CANCEL",false);
			SendMessage(&GameInterface,"ll", MSG_INTERFACE_LOCK_NODE, 0);
			SetCurrentNode("CONTROLS_B_DEFAULT");
		}
	break;
	case "CONTROLS_B_INVERT":
		if(comName=="activate" || comName=="click")
		{
			MakeCamerasInvert();
			TmpI_ShowInvertMode();
		}
	break;



	case "B_SAILING1ST":
		if(comName=="deactivate")
		{
			if( g_bDisableControlChange ) {
				ShowOptionsPage(OPAGE_MAIN);
				SetCurrentNode("MB_CONTROLS");
			} else {
				ShowOptionsPage(OPAGE_CONTROLS_1);
				SetCurrentNode("CONTROLS_B_CHANGE");
			}
		}
		if(comName=="activate" || comName=="click")
		{
			ShowOptionsPage(OPAGE_CONTROLS_3);
			SetShowGroup("Sailing1Pers");
		}
	break;
	case "B_PRIMARY_LAND":
		if(comName=="deactivate")
		{
			if( g_bDisableControlChange ) {
				ShowOptionsPage(OPAGE_MAIN);
				SetCurrentNode("MB_CONTROLS");
			} else {
				ShowOptionsPage(OPAGE_CONTROLS_1);
				SetCurrentNode("CONTROLS_B_CHANGE");
			}
		}
		if(comName=="activate" || comName=="click")
		{
			ShowOptionsPage(OPAGE_CONTROLS_3);
			SetShowGroup("PrimaryLand");
		}
	break;
	case "B_SAILING3RD":
		if(comName=="deactivate")
		{
			if( g_bDisableControlChange ) {
				ShowOptionsPage(OPAGE_MAIN);
				SetCurrentNode("MB_CONTROLS");
			} else {
				ShowOptionsPage(OPAGE_CONTROLS_1);
				SetCurrentNode("CONTROLS_B_CHANGE");
			}
		}
		if(comName=="activate" || comName=="click")
		{
			ShowOptionsPage(OPAGE_CONTROLS_3);
			SetShowGroup("Sailing3Pers");
		}
	break;
	case "B_FIGHTMODE":
		if(comName=="deactivate")
		{
			if( g_bDisableControlChange ) {
				ShowOptionsPage(OPAGE_MAIN);
				SetCurrentNode("MB_CONTROLS");
			} else {
				ShowOptionsPage(OPAGE_CONTROLS_1);
				SetCurrentNode("CONTROLS_B_CHANGE");
			}
		}
		if(comName=="activate" || comName=="click")
		{
			ShowOptionsPage(OPAGE_CONTROLS_3);
			SetShowGroup("FightModeControls");
		}
	break;

	case "CONTROLSWINDOW":
		if(comName=="deactivate") {
			ShowOptionsPage(OPAGE_CONTROLS_2);
			SetOldButton();
		}
	break;

	

	case "SET_BUTTON":
		if(comName=="deactivate") {
			ReturnToViewControls();
		}
		if(comName=="activate" || comName=="click") {
			ReturnToViewControls();
			SetReassignMode();
		}
		if(comName=="downstep")
		{
			if(GetSelectable("DELETE_BUTTON"))
			{	SetCurrentNode("DELETE_BUTTON");
			}
			else
			{
				if(GetSelectable("INVERSE_BUTTON"))
				{	SetCurrentNode("INVERSE_BUTTON");
				}
			}
		}
	break;

	case "DELETE_BUTTON":
		if(comName=="deactivate") {
			ReturnToViewControls();
		}
		if(comName=="activate" || comName=="click") {
			ReturnToViewControls();
			UnmapControl();
		}
		if(comName=="downstep")
		{
			if(GetSelectable("INVERSE_BUTTON"))
				{	SetCurrentNode("INVERSE_BUTTON");	}
		}
		if(comName=="upstep")
			{	SetCurrentNode("SET_BUTTON")	}
	break;

	case "INVERSE_BUTTON":
		if(comName=="deactivate") {
			ReturnToViewControls();
		}
		if(comName=="activate" || comName=="click") {
			InverseControl();
			ReturnToViewControls();
		}
		if(comName=="upstep")
		{
			if(GetSelectable("DELETE_BUTTON"))
				{	SetCurrentNode("DELETE_BUTTON");	}
			else
				{	SetCurrentNode("SET_BUTTON");	}
		}
	break;

	}
}

void TmpI_ShowArcadeMode()
{
	if(bArcadeMode) {
		CreateImage("ArcadeModeImg","icons","complete",532,202,564,234);
	} else {
		CreateImage("ArcadeModeImg","icons","complete",532,248,564,280);
	}
}

void TmpI_ShowCameraMode()
{
	if(locCameraEnableSpecialMode) {
		CreateImage("CameraModeImg","icons","complete",532,206,564,238);
	} else {
		CreateImage("CameraModeImg","icons","complete",532,262,564,294);
	}
}

void TmpI_ShowInvertMode()
{
	if( CheckAttribute(&InterfaceStates,"InvertCameras") && sti(InterfaceStates.InvertCameras)==true ) {
		CreateImage("InvertCameraImg","icons","complete",532,284,564,316);
	} else {
		CreateImage("InvertCameraImg","","",0,0,0,0);
	}
}

void ShowOptionsPage(int pageNum)
{
	if(pageNum==gi_nCurrentPage) return;

	switch(gi_nCurrentPage)
	{
	case OPAGE_MAIN:
		SetNodeUsing("MB_SAILING",false);
		SetNodeUsing("MB_VIDEO",false);
		SetNodeUsing("MB_SOUNDS",false);
		SetNodeUsing("MB_CAMERA",false);
		SetNodeUsing("MB_CONTROLS",false);
	break;
	case OPAGE_SAILING:
		SetNodeUsing("SUBTITLE",false);
		SetNodeUsing("STRINGS_ARCADEMODE",false);
		SetNodeUsing("ARCADEMODE_1",false);
		SetNodeUsing("ARCADEMODE_2",false);
		GameInterface.pictures.ArcadeModeImg.pic = -1;
		GameInterface.pictures.ArcadeModeImg.tex = -1;
		SetCurrentNode("MB_SAILING");
	break;
	case OPAGE_VIDEO:
		SetNodeUsing("SUBTITLE",false);
		SetNodeUsing("STRINGS_VIDEO",false);
		SetNodeUsing("VIDEO_DEFAULT",false);
		SetNodeUsing("GAMMA_SLIDE",false);
		SetNodeUsing("BRIGHT_SLIDE",false);
		SetNodeUsing("CONTRAST_SLIDE",false);
		SetNodeUsing("VIDEO_SAVE",false);
		StartVideoSetting();
		SetCurrentNode("MB_VIDEO");
	break;
	case OPAGE_SOUNDS:
		SetNodeUsing("SUBTITLE",false);
		SetNodeUsing("STRINGS_SOUNDS",false);
		SetNodeUsing("DIALOG",false);
		SetNodeUsing("SOUND",false);
		SetNodeUsing("MUSIC",false);
		SetCurrentNode("MB_SOUNDS");
	break;
	case OPAGE_CAMERA_MOD:
		SetNodeUsing("SUBTITLE",false);
		SetNodeUsing("STRINGS_CAMERA",false);
		SetNodeUsing("CAMERAMODE_1",false);
		SetNodeUsing("CAMERAMODE_2",false);
		GameInterface.pictures.CameraModeImg.pic = -1;
		GameInterface.pictures.CameraModeImg.tex = -1;
		SetCurrentNode("MB_CAMERA");
	break;

	case OPAGE_CONTROLS_1:
		SetNodeUsing("SUBTITLE",false);
		SetNodeUsing("STRINGS_CONTROLS",false);
		SetNodeUsing("STRINGS_MOUSE",false);
		SetNodeUsing("CONTROLS_B_CHANGE",false);
		SetNodeUsing("CONTROLS_B_DEFAULT",false);
		SetNodeUsing("CONTROLS_B_INVERT",false);
		SetNodeUsing("CONTROLS_X_SENSIVE",false);
		SetNodeUsing("CONTROLS_Y_SENSIVE",false);
		GameInterface.pictures.InvertCameraImg.pic = -1;
		GameInterface.pictures.InvertCameraImg.tex = -1;
		SetCurrentNode("MB_CONTROLS");
	break;

	case OPAGE_CONTROLS_2:
		SetNodeUsing("SUBTITLE",false);
		SetNodeUsing("STRINGS_CONTROLS",false);
		SetNodeUsing("B_SAILING1ST",false);
		SetNodeUsing("B_PRIMARY_LAND",false);
		SetNodeUsing("B_SAILING3RD",false);
		SetNodeUsing("B_FIGHTMODE",false);
	break;

	case OPAGE_CONTROLS_3:
		SetNodeUsing("SUBTITLE",false);
		SetNodeUsing("STRINGS_CONTROLS",false);
		SetNodeUsing("CONTROLSWINDOW",false);
		SetNodeUsing(gsKeyWindowName,false);
		SetNodeUsing("CONTROLGROUP",false);
		SetNodeUsing("SCROLL",false);
		DisableString("GroupName");
	break;
	}

	gi_nCurrentPage = pageNum;

	switch(pageNum)
	{
	case OPAGE_MAIN:
		SetNodeUsing("MB_SAILING",true);
		SetNodeUsing("MB_SOUNDS",true);
		SetNodeUsing("MB_VIDEO",true);
		if(GetTargetPlatform()=="xbox")	{SetNodeUsing("MB_CAMERA",true);}
		SetNodeUsing("MB_CONTROLS",true);
	break;
	case OPAGE_SAILING:
		SetNodeUsing("SUBTITLE",true);
		SetNodeUsing("STRINGS_ARCADEMODE",true);
		SetNodeUsing("ARCADEMODE_1",true);
		SetNodeUsing("ARCADEMODE_2",true);
		TmpI_ShowArcadeMode();
		SetCurrentNode("ARCADEMODE_1");
	break;
	case OPAGE_VIDEO:
		SetNodeUsing("SUBTITLE",true);
		SetNodeUsing("STRINGS_VIDEO",true);
		SetNodeUsing("VIDEO_DEFAULT",true);
		SetNodeUsing("GAMMA_SLIDE",true);
		SetNodeUsing("BRIGHT_SLIDE",true);
		SetNodeUsing("CONTRAST_SLIDE",true);
		SetNodeUsing("VIDEO_SAVE",true);
		SetCurrentNode("VIDEO_DEFAULT");
	break;
	case OPAGE_SOUNDS:
		SetNodeUsing("SUBTITLE",true);
		SetNodeUsing("STRINGS_SOUNDS",true);
		SetNodeUsing("DIALOG",true);
		SetNodeUsing("SOUND",true);
		SetNodeUsing("MUSIC",true);
		SetCurrentNode("MUSIC");
	break;
	case OPAGE_CAMERA_MOD:
		SetNodeUsing("SUBTITLE",true);
		SetNodeUsing("STRINGS_CAMERA",true);
		SetNodeUsing("CAMERAMODE_1",true);
		SetNodeUsing("CAMERAMODE_2",true);
		TmpI_ShowCameraMode();
		if( GetTargetPlatform()=="pc" )	{
			SetSelectable("CAMERAMODE_1",false);
			SetSelectable("CAMERAMODE_2",false);
		} else {SetCurrentNode("CAMERAMODE_1");}
	break;

	case OPAGE_CONTROLS_1:
		SetNodeUsing("SUBTITLE",true);
		SetNodeUsing("STRINGS_CONTROLS",true);
		SetNodeUsing("STRINGS_MOUSE",true);
		SetNodeUsing("CONTROLS_B_CHANGE",true);
		SetNodeUsing("CONTROLS_B_DEFAULT",true);
		SetNodeUsing("CONTROLS_B_INVERT",true);
		SetNodeUsing("CONTROLS_X_SENSIVE",true);
		SetNodeUsing("CONTROLS_Y_SENSIVE",true);
		TmpI_ShowInvertMode();
		SetCurrentNode("CONTROLS_B_CHANGE");
	break;

	case OPAGE_CONTROLS_2:
		SetNodeUsing("SUBTITLE",true);
		SetNodeUsing("STRINGS_CONTROLS",true);
		SetNodeUsing("B_SAILING1ST",true);
		SetNodeUsing("B_PRIMARY_LAND",true);
		SetNodeUsing("B_SAILING3RD",true);
		SetNodeUsing("B_FIGHTMODE",true);
		SetCurrentNode("B_SAILING1ST");
	break;

	case OPAGE_CONTROLS_3:
		SetNodeUsing("SUBTITLE",true);
		SetNodeUsing("STRINGS_CONTROLS",true);
		SetNodeUsing("CONTROLSWINDOW",true);
		SetNodeUsing(gsKeyWindowName,true);
		SetNodeUsing("CONTROLGROUP",true);
		SetNodeUsing("SCROLL",true);
		EnableString("GroupName");
		SetCurrentNode("CONTROLSWINDOW");
	break;
	}
}

void DoTitleSelect()
{
	ShowOptionsPage(OPAGE_MAIN);
}

void SetShowGroup(string groupName)
{
	g_sGroupName = groupName;
	switch(groupName)
	{
	case "Sailing1Pers":
		GameInterface.strings.GroupName = XI_ConvertString("Sailing 1St Person");
	break;
	case "PrimaryLand":
		GameInterface.strings.GroupName = XI_ConvertString("Primary Land");
	break;
	case "Sailing3Pers":
		GameInterface.strings.GroupName = XI_ConvertString("Sailing 3rd Person");
	break;
	case "FightModeControls":
		GameInterface.strings.GroupName = XI_ConvertString("Fight Mode");
	break;
	}

	SetFormatedText("CONTROLSWINDOW","");

	int lngFile = LanguageOpenFile("ControlsNames.txt");
	if(lngFile<0) return;

	aref arGroup;
	makearef(arGroup,objControlsState.keygroups.(groupName));

	// Прописать контроли в список
	DeleteAttribute(&objArrayControls,"");
	int i, idx, tmpcolor;
	aref arControl;
	bool bTmpBool;
	int qn = GetAttributesNum(arGroup);
	string cntrlText,tmpstr;
	idx = 0;
	for(i=0; i<qn; i++)
	{
		arControl = GetAttributeN(arGroup,i);
		if( DisableShowControl(arControl) ) continue;
		//if( ControlIsStick(arControl) ) continue;
		if( CheckAttribute(arControl,"invisible") && sti(arControl.invisible)==true ) continue;
		if( CheckAttribute(arControl,"remapping") && sti(arControl.remapping)==false ) {
			bTmpBool = false;
			tmpcolor = argb(255,128,128,128);
		}
		else {
			bTmpBool = true;
			tmpcolor = argb(255,255,255,255);
		}

		if( g_bDisableControlChange )
		{
			bTmpBool = false;
			tmpcolor = argb(255,128,128,128);
		}

		tmpstr = GetAttributeName(arControl);

		cntrlText = LanguageConvertString(lngFile,tmpstr);
		if(cntrlText=="") continue;
		/*int nVSize = SendMessage(&GameInterface,"lsle",MSG_INTERFACE_MSG_TO_NODE,"CONTROLSWINDOW", 9,&cntrlText);
		while(nVSize<2) {
			cntrlText += LanguageConvertString(lngFile,"newLine");
			nVSize++;
		}*/
		SendMessage(&GameInterface,"lsle",MSG_INTERFACE_MSG_TO_NODE,"CONTROLSWINDOW", 0,&cntrlText);
		SendMessage(&GameInterface,"lslll",MSG_INTERFACE_MSG_TO_NODE,"CONTROLSWINDOW", 8,-1,tmpcolor);
		SetControlNameForIdx(idx, tmpstr, bTmpBool);
		idx++;
	}

	LanguageCloseFile(lngFile);
	Event("evntUpdateFormtText","sll","CONTROLSWINDOW",0,0);
}

void SetControlNameForIdx(int idx, string controlName, bool bRemapEnable)
{
	string attrName = "i"+idx;
	objArrayControls.(attrName) = controlName;
	objArrayControls.(attrName).enable = bRemapEnable;
}

void procFTUpdate()
{
	string nodName = GetEventData();
	if(nodName!="CONTROLSWINDOW") return;
	int grNum = GetEventData(); // первая группа в изменениях
	int strNum = GetEventData(); // первая строка в изменениях

	object objPos,obj;
	DeleteAttribute(&objPos,"");
	SendMessage(&GameInterface,"lsla",MSG_INTERFACE_MSG_TO_NODE,"CONTROLSWINDOW", 3,&objPos);

	SetFormatedText(gsKeyWindowName,"");

	int i,qn,posnum;
	qn = GetAttributesNum(&objPos);
	int idx=0;
	for(i=0; i<qn; i++)
	{
		posnum = sti( GetAttributeValue(GetAttributeN(&objPos,i)) );
		if(posnum>=0)
		{
			idx = SetKeysStrings(grNum+i,posnum,idx);
		}
	}
	nLastTextGroupNum = grNum;
	nLastTextStringNum = strNum;
}

void procFTSetScrollPos()
{
	string nodName = GetEventData();
	float fpos = GetEventData();
	if(nodName=="CONTROLSWINDOW")
	{
		SendMessage(&GameInterface,"lsf",MSG_INTERFACE_SET_SCROLLER,"SCROLL",fpos);
	}
}

void ProcScrollPosChange()
{
	float newPos = GetEventData();
	SendMessage(&GameInterface,"lslf",MSG_INTERFACE_MSG_TO_NODE,"CONTROLSWINDOW",2, newPos);
}

int SetKeysStrings(int grNum, int newpos, int oldpos)
{
	int i;
	string tmpStr;
	string keyStr = " ";
	for(i=oldpos; i<newpos; i++)
	{
		SendMessage(&GameInterface,"lsle",MSG_INTERFACE_MSG_TO_NODE,gsKeyWindowName, 0,&keyStr);
	}

	aref arGroupRoot,arKey;
	makearef(arGroupRoot,objControlsState.keygroups.(g_sGroupName));
	tmpStr = GetControlNameFromIdx(grNum);
	if( CheckAttribute(arGroupRoot,tmpStr) )	tmpStr = arGroupRoot.(tmpStr);
	else	tmpStr = "";

	if(CheckAttribute(&objControlsState,"key_codes."+tmpStr+".img"))
	{
		keyStr = objControlsState.key_codes.(tmpStr).img;
	}
	if(keyStr=="")	keyStr=" ";

	i += SendMessage(&GameInterface,"lsle",MSG_INTERFACE_MSG_TO_NODE,gsKeyWindowName, 0,&keyStr);
	return i;
}

string GetControlNameFromIdx(int idx)
{
	string attrName = "i"+idx;
	if( CheckAttribute(&objArrayControls,attrName) ) return objArrayControls.(attrName);
	return "";
}

void procFTActivate()
{
	string nodName = GetEventData();
	if(nodName!="CONTROLSWINDOW") return;
	curCntrlIdx = GetEventData(); // номер текста

	if( !IsEnableRemapping(curCntrlIdx) ) return;

	SetNodeUsing("KEYCHOOSE_RECT",true);
	SetNodeUsing("SET_BUTTON",true);
	SetNodeUsing("DELETE_BUTTON",true);
	SetNodeUsing("INVERSE_BUTTON",true);
	SetCurrentNode("SET_BUTTON");

	SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 1, "SET_BUTTON");
	SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 2, "DELETE_BUTTON");
	SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 2, "INVERSE_BUTTON");
}

bool IsEnableRemapping(int nControl)
{
	aref arControl;
	arControl = GetAttributeN(&objArrayControls,nControl);
	return sti(arControl.enable);
}

void ReturnToViewControls()
{
	SetNodeUsing("KEYCHOOSE_RECT",false);
	SetNodeUsing("SET_BUTTON",false);
	SetNodeUsing("DELETE_BUTTON",false);
	SetNodeUsing("INVERSE_BUTTON",false);
	SendMessage(&GameInterface,"ll", MSG_INTERFACE_LOCK_NODE, 0);
	SetCurrentNode("CONTROLSWINDOW");
}

void SetReassignMode()
{
	SetNodeUsing("KEYCHOOSE_RECT",true);
	SetNodeUsing("KEY_CHOOSER",true);
	SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 1, "KEY_CHOOSER");
	SetCurrentNode("KEY_CHOOSER");
}

void ReturnFromReassign()
{
	SetNodeUsing("KEYCHOOSE_RECT",false);
	SetNodeUsing("KEY_CHOOSER",false);
	SendMessage(&GameInterface,"ll", MSG_INTERFACE_LOCK_NODE, 0);
	SetCurrentNode("CONTROLSWINDOW");
}

void UnmapControl()
{
	aref arControlGroup;
	string contrlName,groupName;

	makearef(arControlGroup,objControlsState.keygroups.(g_sGroupName));

	contrlName = GetControlNameFromIdx(curCntrlIdx);

	int state = 0;
	if(CheckAttribute(&arControlGroup,contrlName+".state"))
	{	state = sti(arControlGroup.(contrlName).state);	}

	CI_CreateAndSetControls( g_sGroupName,contrlName, -1,state, true );

	Event("evntUpdateFormtText","sll","CONTROLSWINDOW", nLastTextGroupNum, nLastTextStringNum);
}

void InverseControl()
{
	if(curCntrlIdx<0)	return;
	aref arControlGroup;
	string contrlName;

	makearef(arControlGroup, objControlsState.keygroups.(g_sGroupName));
	contrlName = GetAttributeValue(GetAttributeN(&objArrayControls,curCntrlIdx));

	int state = 0;
	if(CheckAttribute(arControlGroup,contrlName+".state")) {
		state = sti(arControlGroup.(contrlName).state);
	}

	switch(state)
	{
	case USE_AXIS_AS_BUTTON:		state=USE_AXIS_AS_INVERSEBUTTON;	break;
	case USE_AXIS_AS_INVERSEBUTTON:	state=USE_AXIS_AS_BUTTON;	break;
	case INVERSE_CONTROL:			state=0;	break;
	case 0:							state=INVERSE_CONTROL;	break;
	}

	arControlGroup.(contrlName).state = state;
	CI_CreateAndSetControls( g_sGroupName, contrlName, CI_GetKeyCode(arControlGroup.(contrlName)), state, true );

	Event("evntUpdateFormtText","sll","CONTROLSWINDOW", nLastTextGroupNum, nLastTextStringNum);
}

int glob_retVal;
ref procKeyChoose()
{
	int keyIdx = GetEventData();
	int stickUp = GetEventData();

	glob_retVal = false;
	if( DoMapToOtherKey(keyIdx,stickUp) )
	{
		ReturnFromReassign();
		Event("evntUpdateFormtText","sll","CONTROLSWINDOW", nLastTextGroupNum, nLastTextStringNum);
		glob_retVal = true;
	}

	return &glob_retVal;
}

bool DoMapToOtherKey(int keyIdx,int stickUp)
{
	aref arControlGroup;
	aref arKeyRoot,arKey;
	string contrlName, tmpstr;
	int keyCode;

	if( stickUp )
	{
		SetStickNotAvailable();
		return false;
	}

	makearef(arControlGroup,objControlsState.keygroups.(g_sGroupName));

	contrlName = GetControlNameFromIdx(curCntrlIdx);

	makearef(arKeyRoot,objControlsState.key_codes);
	arKey = GetAttributeN(arKeyRoot,keyIdx);
	keyCode = sti(GetAttributeValue(arKey));

	if( CheckAttribute(arKey,"stick") && sti(arKey.stick)==true ) return false;

	if( KeyAlreadyUsed(g_sGroupName, contrlName, GetAttributeName(arKey)) )
	{
		SetAlreadyUsedShow();
		return false;
	}

	tmpstr = arControlGroup.(contrlName);
	if( CheckAttribute(arKeyRoot,tmpstr+".stick") && sti(arKeyRoot.(tmpstr).stick)==true ) return false;

	int state = 0;
	if(CheckAttribute(arControlGroup,contrlName+".state"))
	{	state = sti(arControlGroup.(contrlName).state);	}

	CI_CreateAndSetControls( g_sGroupName,contrlName,keyCode, state, true );
	return true;
}

void SetAlreadyUsedShow()
{
	nFadeStr_NoStick = 0;
	nFadeStr_AlUsed = 15;
}
void SetStickNotAvailable()
{
	nFadeStr_AlUsed = 0;
	nFadeStr_NoStick = 15;
}

void ProcScrollChange()
{
	int changeNum = GetEventData();
	if(changeNum==0) return;
	if(changeNum>0) {
		SendMessage(&GameInterface,"lslll",MSG_INTERFACE_MSG_TO_NODE,"CONTROLSWINDOW",-1, 0,ACTION_DOWNSTEP);
	} else {
		SendMessage(&GameInterface,"lslll",MSG_INTERFACE_MSG_TO_NODE,"CONTROLSWINDOW",-1, 0,ACTION_UPSTEP);
	}
}

void FadeStringsUpdate()
{
	int color;
	if( nFadeStr_AlUsed>0 )
	{
		nFadeStr_AlUsed--;
		if(nFadeStr_AlUsed==0)
		{
			GameInterface.strings.AlreadyUsed = "";
		}
		else
		{
			color = argb(GetAlphaFromFade(nFadeStr_AlUsed),255,255,255);
			CreateString(true,"AlreadyUsed",XI_ConvertString("Button Already Used"),FONT_NORMAL,color,320,258,SCRIPT_ALIGN_CENTER,1.0);
		}
	}

	if( nFadeStr_NoStick>0 )
	{
		nFadeStr_NoStick--;
		if(nFadeStr_NoStick==0)
		{
			GameInterface.strings.AlreadyUsed = "";
		}
		else
		{
			color = argb(GetAlphaFromFade(nFadeStr_NoStick),255,255,255);
			CreateString(true,"AlreadyUsed",XI_ConvertString("thumbstick cannot be used"),FONT_NORMAL,color,320,258,SCRIPT_ALIGN_CENTER,1.0);
		}
	}

	PostEvent("evntFadeStrings",100);
}

bool KeyAlreadyUsed(string groupName, string controlName, string keyName)
{
	int n, q;
	aref arRoot, arCntrl;
	makearef( arRoot, objControlsState.keygroups.(groupName) );
	q = GetAttributesNum(arRoot);

	for(n=0; n<q; n++)
	{
		arCntrl = GetAttributeN(arRoot,n);
		if( GetAttributeName(arCntrl)==controlName ) continue;
		if( GetAttributeValue(arCntrl)==keyName) return true;
	}

	return false;
}

int GetAlphaFromFade(int n)
{
	int alpha = n*20;
	if(alpha>255) alpha = 255;
	if(alpha<0) alpha = 0;
	return alpha;
}

void SetOldButton()
{
	switch(g_sGroupName)
	{
	case "Sailing1Pers":		SetCurrentNode("B_SAILING1ST"); break;
	case "PrimaryLand":			SetCurrentNode("B_PRIMARY_LAND"); break;
	case "Sailing3Pers":		SetCurrentNode("B_SAILING3RD"); break;
	case "FightModeControls":	SetCurrentNode("B_FIGHTMODE"); break;
	}
}

bool ControlIsStick(aref arControl)
{
	string sKeyName = GetAttributeValue(arControl);
	if( CheckAttribute(&objControlsState,"key_codes."+sKeyName+".stick") &&
		sti(objControlsState.key_codes.(sKeyName).stick)==true )
	{
		return true;
	}
	return false;
}

bool DisableShowControl(aref arControl)
{
	if( ControlIsStick(arControl) ) return true;
	switch( GetAttributeValue(arControl) )
	{
	case "DPAD_UP": return true; break;
	case "DPAD_DOWN": return true; break;
	case "DPAD_RIGHT": return true; break;
	case "DPAD_LEFT": return true; break;
	}
	return false;
}

void ISetColorCorrection(float fContrast, float fGamma, float fBright)
{
	i_fCurContrast = ConvertContrast(fContrast,true);
	i_fCurGamma = ConvertGamma(fGamma,true);
	i_fCurBright = ConvertBright(fBright,true);

	if(i_fCurContrast>1.0) i_fCurContrast=1.0;
	if(i_fCurContrast<0.0) i_fCurContrast=0.0;
	if(i_fCurGamma>1.0) i_fCurGamma=1.0;
	if(i_fCurGamma<0.0) i_fCurGamma=0.0;
	if(i_fCurBright>1.0) i_fCurBright=1.0;
	if(i_fCurBright<0.0) i_fCurBright=0.0;

	GameInterface.nodes.contrast_slide.value = i_fCurContrast;
	GameInterface.nodes.gamma_slide.value = i_fCurGamma;
	GameInterface.nodes.bright_slide.value = i_fCurBright;

	SendMessage(&GameInterface,"lslf",MSG_INTERFACE_MSG_TO_NODE,"CONTRAST_SLIDE", 0,i_fCurContrast);
	SendMessage(&GameInterface,"lslf",MSG_INTERFACE_MSG_TO_NODE,"GAMMA_SLIDE", 0,i_fCurGamma);
	SendMessage(&GameInterface,"lslf",MSG_INTERFACE_MSG_TO_NODE,"BRIGHT_SLIDE", 0,i_fCurBright);

	XI_SetColorCorrection(fContrast,fGamma,fBright);
}

void StartVideoSetting()
{
	float fC = 1.0;
	float fG = 1.0;
	float fB = 0.0;

	if( CheckAttribute(&InterfaceStates,"video.contrast") ) {
		fC = stf(InterfaceStates.video.contrast);
	}
	if( CheckAttribute(&InterfaceStates,"video.gamma") ) {
		fG = stf(InterfaceStates.video.gamma);
	}
	if( CheckAttribute(&InterfaceStates,"video.brightness") ) {
		fB = stf(InterfaceStates.video.brightness);
	}

	ISetColorCorrection( fC, fG, fB );
}

float ConvertContrast(float fContrast, bool Real2Slider)
{
	if(Real2Slider)
	{
		if(fContrast<=1.0) {return fContrast-0.5;}
		return fContrast/2.0;
	}
	if(fContrast<=0.5) {return fContrast+0.5;}
	return fContrast*2.0;
}
float ConvertGamma(float fGamma, bool Real2Slider)
{
	if(Real2Slider)
	{
		if(fGamma<=1.0) {return fGamma-0.5;}
		return (fGamma+1.5)/5.0;
	}
	if(fGamma<=0.5) {return fGamma+0.5;}
	return fGamma*5.0-1.5;
}
float ConvertBright(float fBright, bool Real2Slider)
{
	if(Real2Slider)
	{
		return (fBright+100.0)/200.0;
	}
	return fBright*200-100;
}

void SaveVideoSettings()
{
	InterfaceStates.video.contrast = ConvertContrast(i_fCurContrast,false);
	InterfaceStates.video.gamma = ConvertGamma(i_fCurGamma,false);
	InterfaceStates.video.brightness = ConvertBright(i_fCurBright,false);
}

void SetMouseToDefault()
{
	GameInterface.pictures.InvertCameraImg.pic = -1;
	GameInterface.pictures.InvertCameraImg.tex = -1;
	InterfaceStates.InvertCameras = false;
	XI_SetMouseSensitivity( 1.0, 1.0 );
	i_fCurXSens = 0.5;
	i_fCurYSens = 0.5;
	InterfaceStates.mouse.x_sens = i_fCurXSens;
	InterfaceStates.mouse.y_sens = i_fCurYSens;
	GameInterface.nodes.controls_x_sensive.value = i_fCurXSens;
	GameInterface.nodes.controls_y_sensive.value = i_fCurYSens;
	SendMessage(&GameInterface,"lslf",MSG_INTERFACE_MSG_TO_NODE,"CONTROLS_X_SENSIVE", 0,i_fCurXSens);
	SendMessage(&GameInterface,"lslf",MSG_INTERFACE_MSG_TO_NODE,"CONTROLS_Y_SENSIVE", 0,i_fCurYSens);
}

void MakeCamerasInvert()
{
	bool bCamInvert = true;
	if( CheckAttribute(&InterfaceStates,"InvertCameras") && sti(InterfaceStates.InvertCameras)==true) {
		bCamInvert = false;
	}
	InterfaceStates.InvertCameras = bCamInvert;
}

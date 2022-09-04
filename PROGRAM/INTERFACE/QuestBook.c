#define	CST_QUESTTITLE	1
#define CST_QUESTTEXT	2

int curShowType=CST_QUESTTITLE;
int curQuestTop;

void InitInterface(string iniName)
{
	GameInterface.title = "titleQuestBook";

	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);

	aref arefTmp;
	ref myCh = GetMainCharacter();
	makearef(arefTmp,myCh.QuestInfo);

	XI_SetQuestTitles("QUEST_TITLE",arefTmp,0);
	curQuestTop = 0;

	XI_SetQuestData(true);

	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
	SetEventHandler("exitCancel","ProcessCancelExit",0);

	SetEventHandler("QuestTopChange","QuestTopChange",0);
	SetEventHandler("BackToTitle","BackToTitle",0);
	SetEventHandler("QuestActivate","XI_QuestActivate",0);

	SetEventHandler("SetScrollerPos","SetScrollerPos",0);
	SetEventHandler("ScrollPosChange","ProcScrollPosChange",0);
	SetEventHandler("ScrollTopChange","ProcScrollChange",0);
}

void XI_SetQuestData(bool qtitle)
{
	// set node & string using
	SetNodeUsing("QUESTRECTANGLE",true);
	SetNodeUsing("QUESTBOUND",true);
	SetNodeUsing("QUESTSCROLL",true);
	SetNodeUsing("QUEST_TITLE",qtitle);
	SetNodeUsing("QUEST_TEXT",!qtitle);
}

void ProcessCancelExit()
{
	IDoExit(RC_INTERFACE_QUESTBOOK_EXIT);
}

void QuestTopChange()
{
	if(curShowType==CST_QUESTTITLE)
	{
		int newTop = curQuestTop+GetEventData();

		ref myCh = GetMainCharacter();
		aref arefTmp;
		makearef(arefTmp,myCh.QuestInfo);
		int maxVal = GetAttributesNum(arefTmp);
		if(newTop>=maxVal)
		{
			newTop=maxVal-1;
		}
		if(newTop<0)
		{
			newTop=0;
		}

		if(newTop!=curQuestTop)
		{
			curQuestTop=newTop;
			XI_SetQuestTitles("QUEST_TITLE",arefTmp,curQuestTop);
			XI_SetScroller(MakeFloat(newTop)/MakeFloat(maxVal));
		}
	}
}

void SetQTextShow(aref pA,int qnum)
{
	SendMessage(&GameInterface,"lsal",MSG_INTERFACE_INIT_QTEXT_SHOW,"QUEST_TEXT",pA,qnum);
}

void BackToTitle()
{
	curShowType = CST_QUESTTITLE;
	XI_SetQuestData(true);
	SetCurrentNode("QUEST_TITLE");
}

void XI_QuestActivate()
{
	curShowType = CST_QUESTTEXT;
	int aq = curQuestTop+GetEventData();
	ref refMyCh = GetMainCharacter();
	aref pA;
	makearef(pA,refMyCh.QuestInfo);
	SetQTextShow(pA,aq);
	XI_SetQuestData(false);
	SetCurrentNode("QUEST_TEXT");
}

void XI_SetScroller(float pos)
{
	SendMessage(&GameInterface,"lsf",MSG_INTERFACE_SET_SCROLLER,"QUESTSCROLL",pos);
}

void SetScrollerPos()
{
	string nodName = GetEventData();
	float pos = GetEventData();
	XI_SetScroller(pos);
}

void IDoExit(int exitCode)
{
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
	DelEventHandler("exitCancel","ProcessCancelExit");
	DelEventHandler("QuestTopChange","QuestTopChange");
	DelEventHandler("BackToTitle","BackToTitle");
	DelEventHandler("QuestActivate","XI_QuestActivate");
	DelEventHandler("SetScrollerPos","SetScrollerPos");
	DelEventHandler("ScrollPosChange","ProcScrollPosChange");
	DelEventHandler("ScrollTopChange","ProcScrollChange");

    interfaceResultCommand = exitCode;
	if( CheckAttribute(&InterfaceStates,"InstantExit") && sti(InterfaceStates.InstantExit)==true )
	{
		EndCancelInterface(true);
	}
	else
	{
		PostEvent("LaunchIAfterFrame",1,"sl", "I_SELECTMENU", 1);
		EndCancelInterface(false);
	}
}

void ProcScrollPosChange()
{
	float newPos = GetEventData();
	if(curShowType==CST_QUESTTITLE)
	{
		ref myCh = GetMainCharacter();
		aref arefTmp;
		makearef(arefTmp,myCh.QuestInfo);
		int maxVal = GetAttributesNum(arefTmp);
		int newTop = makeint(newPos*maxVal);

		if(newTop!=curQuestTop)
		{
			curQuestTop=newTop;
			XI_SetQuestTitles("QUEST_TITLE",arefTmp,curQuestTop);
		}
	}
	else
	{
		SendMessage(&GameInterface,"lslf",MSG_INTERFACE_MSG_TO_NODE,"QUEST_TEXT", 1,newPos);
	}
}

void ProcScrollChange()
{
	int changeNum = GetEventData();
	if(changeNum==0) return;
	string controlNode = "";
	if( GetSelectable("QUEST_TITLE") ) controlNode = "QUEST_TITLE";
	if( GetSelectable("QUEST_TEXT") ) controlNode = "QUEST_TEXT";

	if(controlNode!="")
	{
		if(changeNum>0) {
			SendMessage(&GameInterface,"lslll",MSG_INTERFACE_MSG_TO_NODE,controlNode,-1, 0,ACTION_DOWNSTEP);
		} else {
			SendMessage(&GameInterface,"lslll",MSG_INTERFACE_MSG_TO_NODE,controlNode,-1, 0,ACTION_UPSTEP);
		}
	}
}

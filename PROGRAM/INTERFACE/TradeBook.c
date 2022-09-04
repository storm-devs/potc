#define NONEISLAND_TEXTURE_NAME	"interfaces\empty_sea.tga"

int nCurScroll;

void InitInterface(string iniName)
{
	GameInterface.title = "titleTradeBook";

	FillScroll();
	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);

	CreateString(true,"IslandName","",FONT_NORMAL,COLOR_NORMAL,320,190,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(true,"Import0","",FONT_NORMAL,COLOR_NORMAL,72,266,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(true,"Import1","",FONT_NORMAL,COLOR_NORMAL,72,310,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(true,"Import2","",FONT_NORMAL,COLOR_NORMAL,72,354,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(true,"Import3","",FONT_NORMAL,COLOR_NORMAL,72,398,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(true,"Export0","",FONT_NORMAL,COLOR_NORMAL,258,266,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(true,"Export1","",FONT_NORMAL,COLOR_NORMAL,258,310,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(true,"Export2","",FONT_NORMAL,COLOR_NORMAL,258,354,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(true,"Export3","",FONT_NORMAL,COLOR_NORMAL,258,398,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(true,"Contraband0","",FONT_NORMAL,COLOR_NORMAL,468,266,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(true,"Contraband1","",FONT_NORMAL,COLOR_NORMAL,468,310,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(true,"Contraband2","",FONT_NORMAL,COLOR_NORMAL,468,354,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(true,"Contraband3","",FONT_NORMAL,COLOR_NORMAL,468,398,SCRIPT_ALIGN_LEFT,1.0);

	XI_SetIslandData();

	CreateImage("igood0","GOODS","",34,264,66,296);
	CreateImage("igood1","GOODS","",34,308,66,340);
	CreateImage("igood2","GOODS","",34,352,66,384);
	CreateImage("igood3","GOODS","",34,396,66,428);

	CreateImage("egood0","GOODS","",220,264,252,296);
	CreateImage("egood1","GOODS","",220,308,252,340);
	CreateImage("egood2","GOODS","",220,352,252,384);
	CreateImage("egood3","GOODS","",220,396,252,428);

	CreateImage("cgood0","GOODS","",430,264,462,296);
	CreateImage("cgood1","GOODS","",430,308,462,340);
	CreateImage("cgood2","GOODS","",430,352,462,384);
	CreateImage("cgood3","GOODS","",430,396,462,428);

	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
	SetEventHandler("frame","FrameProcess",1);
	SetEventHandler("exitCancel","ProcessCancelExit",0);
}

void FrameProcess()
{
	if(nCurScroll!=sti(GameInterface.islandslist.current))
	{
		nCurScroll = sti(GameInterface.islandslist.current);
		XI_SetIslandData();
	}
}

void XI_SetIslandData()
{
	int idxIsland = XI_GetIsland(nCurScroll);
	if(idxIsland==-1) return;
	ref refIsland = GetIslandByIndex(idxIsland);

	GameInterface.strings.IslandName = XI_ConvertString(refIsland.id);

	// trade info
	string tradeAttr,strAttr,picAttr;
	int idxGoods;
	bool fIvisible = false;
	if(CheckAttribute(refIsland,"visible") && sti(refIsland.visible)==true)	fIvisible = true;
	for(int i=0;i<4;i++)
	{
		tradeAttr = "id"+(i+1);
		// for import goods
		strAttr = "Import"+i;
		picAttr = "igood"+i;
		if(fIvisible)
		{
			if(CheckAttribute(refIsland,"Trade.Import."+tradeAttr))
			{
				idxGoods = sti(refIsland.Trade.Import.(tradeAttr));
				GameInterface.strings.(strAttr) = XI_ConvertString(Goods[idxGoods].name);
				GameInterface.pictures.(picAttr).pic = Goods[idxGoods].name;
			}
			else
			{
				GameInterface.strings.(strAttr) = "";
				GameInterface.pictures.(picAttr).pic = "";
			}
		}
		else
		{
			GameInterface.string.(strAttr) = "";
			GameInterface.pictures.(picAttr).pic = "";
		}
		// for export goods
		strAttr = "Export"+i;
		picAttr = "egood"+i;
		if(fIvisible)
		{
			if(CheckAttribute(refIsland,"Trade.Export."+tradeAttr))
			{
				idxGoods = sti(refIsland.Trade.Export.(tradeAttr));
				GameInterface.strings.(strAttr) = XI_ConvertString(Goods[idxGoods].name);
				GameInterface.pictures.(picAttr).pic = Goods[idxGoods].name;
			}
			else
			{
				GameInterface.strings.(strAttr) = "";
				GameInterface.pictures.(picAttr).pic = "";
			}
		}
		else
		{
			GameInterface.strings.(strAttr) = "";
			GameInterface.pictures.(picAttr).pic = "";
		}
		// for contraband goods
		strAttr = "Contraband"+i;
		picAttr = "cgood"+i;
		if(fIvisible)
		{
			if(CheckAttribute(refIsland,"Trade.Contraband."+tradeAttr))
			{
				idxGoods = sti(refIsland.Trade.Contraband.(tradeAttr));
				GameInterface.strings.(strAttr) = XI_ConvertString(Goods[idxGoods].name);
				GameInterface.pictures.(picAttr).pic = Goods[idxGoods].name;
			}
			else
			{
				GameInterface.strings.(strAttr) = "";
				GameInterface.pictures.(picAttr).pic = "";
			}
		}
		else
		{
			GameInterface.strings.(strAttr) = "";
			GameInterface.pictures.(picAttr).pic = "";
		}
	}
}

void FillScroll()
{
    int i;
    string attributeName;

	nCurScroll = -1;
	GameInterface.islandslist.current = 0;
	GameInterface.islandslist.BadPicture1 = NONEISLAND_TEXTURE_NAME;
	GameInterface.islandslist.ImagesGroup.t1 = "ISLANDSICON";

	int islandIdx;
	ref islandRef;
    for(i=0; i<MAX_ISLANDS; i++)
    {
		attributeName = "pic" + (i+1);
		islandIdx = XI_GetIsland(i);
		if(islandIdx==-1) break;

		islandRef = GetIslandByIndex(islandIdx);
		GameInterface.islandslist.(attributeName).img1 = islandRef.id;
		GameInterface.islandslist.(attributeName).tex1 = 0;
    }
	GameInterface.islandslist.ListSize = i;
}

void ProcessCancelExit()
{
	IDoExit(RC_INTERFACE_TRADEBOOK_EXIT);
}

int XI_GetIsland(int inum)
{
	if(inum<0) return -1;
	if(inum>=MAX_ISLANDS) return -1;

	int idx = 0;
	for(int i=0; i<MAX_ISLANDS; i++)
	{
		if( !CheckAttribute(&Islands[i],"visible") ) continue;
		if( !sti(Islands[i].visible) ) continue;
		if( idx==inum ) return i;
		idx++;
	}
	return -1;
}

void IDoExit(int exitCode)
{
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
	DelEventHandler("frame","FrameProcess");
	DelEventHandler("exitCancel","ProcessCancelExit");

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

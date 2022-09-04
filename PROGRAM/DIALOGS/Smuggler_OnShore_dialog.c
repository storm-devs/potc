//nclude "DIALOGS\Smuggler_OnShore_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_Meeting;	
	int Shit;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча

		case "Finish_exit":
			AddPartyExp(Pchar, 100*makeint(PChar.rank));
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();

			if(FindFirstContrabandGoods(Pchar) != -1) 
			{
				RemoveCharacterGoods(Pchar, makeint(Pchar.quest.contraband.goodsIDX1), GetCargoGoods(Pchar, makeint(Pchar.quest.contraband.goodsIDX1)));
				if(GetCompanionIndex(Pchar, 1) != -1)
				{
					RemoveCharacterGoods(&Characters[getCompanionIndex(Pchar, 1)], makeint(Pchar.quest.contraband.goodsIDX1), GetCargoGoods(&Characters[getCompanionIndex(Pchar, 1)], makeint(Pchar.quest.contraband.goodsIDX1)));
				}
				if(GetCompanionIndex(Pchar, 2) != -1)
				{
					RemoveCharacterGoods(&Characters[getCompanionIndex(Pchar, 2)], makeint(Pchar.quest.contraband.goodsIDX1), GetCargoGoods(&Characters[getCompanionIndex(Pchar, 2)], makeint(Pchar.quest.contraband.goodsIDX1)));
				}
				if(GetCompanionIndex(Pchar, 3) != -1)
				{
					RemoveCharacterGoods(&Characters[getCompanionIndex(Pchar, 3)], makeint(Pchar.quest.contraband.goodsIDX1), GetCargoGoods(&Characters[getCompanionIndex(Pchar, 3)], makeint(Pchar.quest.contraband.goodsIDX1)));
				}

			}
			if(FindNextContrabandGoods(Pchar) != -1) 
			{
				RemoveCharacterGoods(Pchar, makeint(Pchar.quest.contraband.goodsIDX2), GetCargoGoods(Pchar, makeint(Pchar.quest.contraband.goodsIDX2)));
				if(GetCompanionIndex(Pchar, 1) != -1)
				{
					RemoveCharacterGoods(&Characters[getCompanionIndex(Pchar, 1)], makeint(Pchar.quest.contraband.goodsIDX2), GetCargoGoods(&Characters[getCompanionIndex(Pchar, 1)], makeint(Pchar.quest.contraband.goodsIDX2)));
				}
				if(GetCompanionIndex(Pchar, 2) != -1)
				{
					RemoveCharacterGoods(&Characters[getCompanionIndex(Pchar, 2)], makeint(Pchar.quest.contraband.goodsIDX2), GetCargoGoods(&Characters[getCompanionIndex(Pchar, 2)], makeint(Pchar.quest.contraband.goodsIDX2)));
				}
				if(GetCompanionIndex(Pchar, 3) != -1)
				{
					RemoveCharacterGoods(&Characters[getCompanionIndex(Pchar, 3)], makeint(Pchar.quest.contraband.goodsIDX2), GetCargoGoods(&Characters[getCompanionIndex(Pchar, 3)], makeint(Pchar.quest.contraband.goodsIDX2)));
				}

			}
			if(FindNextContrabandGoods(Pchar) != -1) 
			{
				RemoveCharacterGoods(Pchar, makeint(Pchar.quest.contraband.goodsIDX3), GetCargoGoods(Pchar, makeint(Pchar.quest.contraband.goodsIDX3)));
				if(GetCompanionIndex(Pchar, 1) != -1)
				{
					RemoveCharacterGoods(&Characters[getCompanionIndex(Pchar, 1)], makeint(Pchar.quest.contraband.goodsIDX3), GetCargoGoods(&Characters[getCompanionIndex(Pchar, 1)], makeint(Pchar.quest.contraband.goodsIDX3)));
				}
				if(GetCompanionIndex(Pchar, 2) != -1)
				{
					RemoveCharacterGoods(&Characters[getCompanionIndex(Pchar, 2)], makeint(Pchar.quest.contraband.goodsIDX3), GetCargoGoods(&Characters[getCompanionIndex(Pchar, 2)], makeint(Pchar.quest.contraband.goodsIDX3)));
				}
				if(GetCompanionIndex(Pchar, 3) != -1)
				{
					RemoveCharacterGoods(&Characters[getCompanionIndex(Pchar, 3)], makeint(Pchar.quest.contraband.goodsIDX3), GetCargoGoods(&Characters[getCompanionIndex(Pchar, 3)], makeint(Pchar.quest.contraband.goodsIDX3)));
				}

			}

			if(FindNextContrabandGoods(Pchar) != -1) 
			{
				RemoveCharacterGoods(Pchar, makeint(Pchar.quest.contraband.goodsIDX4), GetCargoGoods(Pchar, makeint(Pchar.quest.contraband.goodsIDX4)));
				if(GetCompanionIndex(Pchar, 1) != -1)
				{
					RemoveCharacterGoods(&Characters[getCompanionIndex(Pchar, 1)], makeint(Pchar.quest.contraband.goodsIDX4), GetCargoGoods(&Characters[getCompanionIndex(Pchar, 1)], makeint(Pchar.quest.contraband.goodsIDX4)));
				}
				if(GetCompanionIndex(Pchar, 2) != -1)
				{
					RemoveCharacterGoods(&Characters[getCompanionIndex(Pchar, 2)], makeint(Pchar.quest.contraband.goodsIDX4), GetCargoGoods(&Characters[getCompanionIndex(Pchar, 2)], makeint(Pchar.quest.contraband.goodsIDX4)));
				}
				if(GetCompanionIndex(Pchar, 3) != -1)
				{
					RemoveCharacterGoods(&Characters[getCompanionIndex(Pchar, 3)], makeint(Pchar.quest.contraband.goodsIDX4), GetCargoGoods(&Characters[getCompanionIndex(Pchar, 3)], makeint(Pchar.quest.contraband.goodsIDX4)));
				}

			}

			AddMoneyToCharacter(Pchar, makeint(Pchar.quest.Contraband.sum));
			if(makeint(pchar.quest.Contraband.relation) <= 90)  pchar.quest.Contraband.relation = makeint(pchar.quest.Contraband.relation) + 10;

			
			DeleteAttribute(Pchar, "quest.Contraband.active");
			DeleteAttribute(Pchar, "quest.Contraband.counter");
			DeleteAttribute(Pchar, "quest.Contraband.price1");
			DeleteAttribute(Pchar, "quest.Contraband.price2");
			DeleteAttribute(Pchar, "quest.Contraband.price3");
			DeleteAttribute(Pchar, "quest.Contraband.price4");
			DeleteAttribute(Pchar, "quest.Contraband.goodsIDX1");
			DeleteAttribute(Pchar, "quest.Contraband.goodsIDX2");
			DeleteAttribute(Pchar, "quest.Contraband.goodsIDX3");
			DeleteAttribute(Pchar, "quest.Contraband.goodsIDX4");
			DeleteAttribute(Pchar, "quest.Contraband.sum");

			Pchar.quest.Rand_Smuggling.over = "yes";
			RemoveSmugglersFromShore();
		break;

		case "Exit_fight":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();

			DeleteAttribute(Pchar, "quest.Contraband.active");
			DeleteAttribute(Pchar, "quest.Contraband.counter");
			DeleteAttribute(Pchar, "quest.Contraband.price1");
			DeleteAttribute(Pchar, "quest.Contraband.price2");
			DeleteAttribute(Pchar, "quest.Contraband.price3");
			DeleteAttribute(Pchar, "quest.Contraband.price4");
			DeleteAttribute(Pchar, "quest.Contraband.goodsIDX1");
			DeleteAttribute(Pchar, "quest.Contraband.goodsIDX2");
			DeleteAttribute(Pchar, "quest.Contraband.goodsIDX3");
			DeleteAttribute(Pchar, "quest.Contraband.goodsIDX4");
			DeleteAttribute(Pchar, "quest.Contraband.sum");

			Pchar.quest.Rand_Smuggling.over = "yes";
			RemoveSmugglersFromShore();

			LAi_group_FightGroups(LAI_GROUP_PLAYER, "Smugglers", true);
		break;

		case "Exit_Cancel":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();

			DeleteAttribute(Pchar, "quest.Contraband.active");
			DeleteAttribute(Pchar, "quest.Contraband.counter");
			DeleteAttribute(Pchar, "quest.Contraband.price1");
			DeleteAttribute(Pchar, "quest.Contraband.price2");
			DeleteAttribute(Pchar, "quest.Contraband.price3");
			DeleteAttribute(Pchar, "quest.Contraband.price4");
			DeleteAttribute(Pchar, "quest.Contraband.goodsIDX1");
			DeleteAttribute(Pchar, "quest.Contraband.goodsIDX2");
			DeleteAttribute(Pchar, "quest.Contraband.goodsIDX3");
			DeleteAttribute(Pchar, "quest.Contraband.goodsIDX4");
			DeleteAttribute(Pchar, "quest.Contraband.sum");

			Pchar.quest.Rand_Smuggling.over = "yes";
			RemoveSmugglersFromShore();
		break;
		
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

		case "First time":	
			Diag.TempNode = "first time";
			if(CheckAttribute(PChar, "quest.Contraband.active"))
			{
				Dialog.snd = "voice\SMSH\SMSH001";
				d.Text = DLG_TEXT[0];
				Link.l1 = PcharPhrase(DLG_TEXT[1], DLG_TEXT[2]);
				if(Pchar.Location == Pchar.location.from_sea)
				{
					Link.l1.go = "Exchange";
				}
				else
				{
					Link.l1.go = "No_Ship";
				}
				
			}
			else
			{
				Dialog.snd = "voice\SMSH\SMSH002";
				d.Text = DLG_TEXT[3];
				Link.l1 = PcharPhrase(DLG_TEXT[4], DLG_TEXT[5]);
				Link.l1.go = "Exit_fight";
				Link.l2 = DLG_TEXT[6];
				Link.l2.go = "Exit";				
			}
		break;

		case "No_Ship":
			Dialog.snd = "voice\SMSH\SMSH003";
			d.Text = DLG_TEXT[7];
			Link.l1 = PcharPhrase(DLG_TEXT[8], DLG_TEXT[9]);
			Link.l1.go = "No_ship_1";
			Link.l2 = DLG_TEXT[10];
			Link.l2.go = "Cancellation";				
		break;

		case "No_ship_1":
			Dialog.snd = "voice\SMSH\SMSH004";
			d.Text = DLG_TEXT[11];
			Link.l1 = DLG_TEXT[12];
			Link.l1.go = "Exit";							
		break;

		case "Cancellation":
			Dialog.snd = "voice\SMSH\SMSH005";
			d.Text = DLG_TEXT[13];
			Link.l1 = DLG_TEXT[14];
			Link.l1.go = "Cancellation_1";				
		break;

		case "Cancellation_1":
			if( makeint(Pchar.rank) <= 3 || makeint(Pchar.skill.Fencing) <= 5 || makeint(Pchar.skill.Leadership) <= 5 )
			{
				if(Rand(2) == 1) 
				{
					pchar.quest.Contraband.relation = makeint(pchar.quest.Contraband.relation) - 20;
					Dialog.snd = "voice\SMSH\SMSH006";
					d.Text = DLG_TEXT[15];
					Link.l1 = DLG_TEXT[16];
					Link.l1.go = "Exit_fight";			
				}
				else
				{
					pchar.quest.Contraband.relation = makeint(pchar.quest.Contraband.relation) - 10;
					Dialog.snd = "voice\SMSH\SMSH007";
					d.Text = DLG_TEXT[17];
					Link.l1 = DLG_TEXT[18];
					Link.l1.go = "Exit_cancel";			
				}
			}	
			else
			{
				pchar.quest.Contraband.relation = makeint(pchar.quest.Contraband.relation) - 10;
				Dialog.snd = "voice\SMSH\SMSH008";
				d.Text = DLG_TEXT[19];
				Link.l1 = DLG_TEXT[20];
				Link.l1.go = "Exit_cancel";			
			}	
		break;

		case "Exchange":
			Pchar.quest.Contraband.Counter = 0;
			
			if(makeint((sti(Pchar.skill.Sneak) + 1)) <= Rand(10))
			{
				trace("Contraband transfer was interrupted by Coastal Guards");
				AddDialogExitQuest("Rand_ContrabandInterruption");
			}
			if(FindFirstContrabandGoods(Pchar) != -1) 
			{
				Pchar.quest.Contraband.goodsIDX1 = FindFirstContrabandGoods(Pchar);
				trace("FIRST CONTRABAND GOOD SELECTED TO TRADE IS: " + goods[sti(Pchar.quest.Contraband.goodsIDX1)].name); 
				Pchar.quest.Contraband.price1 = makeint(GetCurrentIslandGoodsPrice(FindFirstContrabandGoods(Pchar))*1.5);
				trace("FIRST CONTRABAND GOOD PRICE IS: " + Pchar.quest.Contraband.price1); 
				Pchar.quest.Contraband.Counter = makeint(Pchar.quest.Contraband.Counter) + 1;
				trace("CONTRABAND ONBOARD COUNTER HAS VALUE: " + Pchar.quest.Contraband.Counter); 
			}
			shit = FindNextContrabandGoods(Pchar);
			if(shit != -1) 
			{
				Pchar.quest.Contraband.goodsIDX2 = shit;
				Pchar.quest.Contraband.price2 = makeint(GetCurrentIslandGoodsPrice(shit)*1.5);
				Pchar.quest.Contraband.Counter = makeint(Pchar.quest.Contraband.Counter) + 1;
			}
			shit = FindNextContrabandGoods(Pchar);
			if(shit != -1) 
			{
				Pchar.quest.Contraband.goodsIDX3 = shit;
				Pchar.quest.Contraband.price3 = makeint(GetCurrentIslandGoodsPrice(shit)*1.5);
				Pchar.quest.Contraband.Counter = makeint(Pchar.quest.Contraband.Counter) + 1;		
			}
			shit = FindNextContrabandGoods(Pchar);
			if(shit != -1) 
			{
				Pchar.quest.Contraband.goodsIDX4 = shit;
				Pchar.quest.Contraband.price4 = makeint(GetCurrentIslandGoodsPrice(shit)*1.5);
				Pchar.quest.Contraband.Counter = makeint(Pchar.quest.Contraband.Counter) + 1;
			}
			if(FindFirstContrabandGoods(Pchar) != -1)
			{
				trace("QUANTITY OF FIRST CONTRABAND GOOD ONBOARD: " + GetCargoGoods(Pchar,makeint(Pchar.quest.Contraband.goodsIDX1)));
				trace("INDEX OF FIRST CONTRABAND IS: " + Pchar.quest.Contraband.goodsIDX1);
				Pchar.quest.Contraband.Sum = makeint(Pchar.quest.Contraband.price1)*GetSquadronGoods(Pchar,makeint(Pchar.quest.Contraband.goodsIDX1));
				Dialog.snd = "voice\SMSH\SMSH009";
				d.Text = DLG_TEXT[21] + GetSquadronGoods(Pchar,FindFirstContrabandGoods(Pchar)) + " " + XI_ConvertString(Goods[makeint(Pchar.quest.Contraband.goodsIDX1)].name) + DLG_TEXT[22] + Pchar.quest.Contraband.price1 + DLG_TEXT[23] + pchar.quest.contraband.sum + DLG_TEXT[24];
				Link.l1 = DLG_TEXT[25];
				Pchar.quest.Contraband.Counter = makeint(Pchar.quest.Contraband.Counter) - 1; 
				if(Pchar.quest.Contraband.Counter != "0")
				{
					trace("THERE ARE SOME MORE CONTRABAND GOODS");
					Link.l1.go = "SecondGoods";				
				}
				else
				{
					trace("ONLY ONE CONTRABAND GOOD IS AVAILABLE");
					Link.l1.go = "Finish";
				}
				Link.l2 = DLG_TEXT[26];
				Link.l2.go = "Cancellation";
			}
			else
			{
				Dialog.snd = "voice\SMSH\SMSH010";
				d.Text = DLG_TEXT[27];
				Link.l1 = DLG_TEXT[28];
				Link.l1.go = "NoGoods";				
			}
			
		break;

		case "SecondGoods":
			Dialog.snd = "voice\SMSH\SMSH012";
			Pchar.quest.Contraband.Sum = makeint(Pchar.quest.Contraband.Sum) + makeint(Pchar.quest.Contraband.price2)*GetSquadronGoods(Pchar,makeint(Pchar.quest.Contraband.goodsIDX2));
			d.Text = DLG_TEXT[29] + GetSquadronGoods(Pchar, FindNextContrabandGoods(Pchar)) + " " + XI_ConvertString(Goods[makeint(Pchar.quest.Contraband.goodsIDX2)].name) + DLG_TEXT[30] + Pchar.quest.Contraband.price2 + DLG_TEXT[31] + pchar.quest.contraband.sum + DLG_TEXT[32];
			Link.l1 = DLG_TEXT[33];
			Pchar.quest.Contraband.Counter = makeint(Pchar.quest.Contraband.Counter) - 1; 
			if(Pchar.quest.Contraband.Counter != "0")
			{
				Link.l1.go = "ThirdGoods";				
			}
			else
			{
				Link.l1.go = "Finish";
			}
			Link.l2 = DLG_TEXT[34];
			Link.l2.go = "Cancellation";
		break;

		case "ThirdGoods":
			Dialog.snd = "voice\SMSH\SMSH013";
			Pchar.quest.Contraband.Sum = makeint(Pchar.quest.Contraband.Sum) + makeint(Pchar.quest.Contraband.price3)*GetSquadronGoods(Pchar,makeint(Pchar.quest.Contraband.goodsIDX3));
			d.Text = DLG_TEXT[35] + GetSquadronGoods(Pchar,FindNextContrabandGoods(Pchar)) + " " + XI_ConvertString(Goods[makeint(Pchar.quest.Contraband.goodsIDX3)].name) + DLG_TEXT[36] + Pchar.quest.Contraband.price3 + DLG_TEXT[37] + pchar.quest.contraband.sum + DLG_TEXT[38];
			Link.l1 = DLG_TEXT[39];
			Pchar.quest.Contraband.Counter = makeint(Pchar.quest.Contraband.Counter) - 1; 
			if(Pchar.quest.Contraband.Counter != "0")
			{
				Link.l1.go = "FourthGoods";				
			}
			else
			{
				Link.l1.go = "Finish";
			}
			Link.l2 = DLG_TEXT[40];
			Link.l2.go = "Cancellation";
		break;

		case "FourthGoods":
			Dialog.snd = "voice\SMSH\SMSH014";
			Pchar.quest.Contraband.Sum = makeint(Pchar.quest.Contraband.Sum) + makeint(Pchar.quest.Contraband.price4)*GetSquadronGoods(Pchar,makeint(Pchar.quest.Contraband.goodsIDX4));
			Pchar.quest.Contraband.Counter = "0";
			d.Text = DLG_TEXT[41] + GetSquadronGoods(Pchar,FindNextContrabandGoods(Pchar)) + " " + XI_ConvertString(Goods[makeint(Pchar.quest.Contraband.goodsIDX4)].name) + DLG_TEXT[42] + Pchar.quest.Contraband.price4 + DLG_TEXT[43] + pchar.quest.contraband.sum + DLG_TEXT[44];
			Link.l1 = DLG_TEXT[45];
			Link.l1.go = "Finish";
			Link.l2 = DLG_TEXT[46];
			Link.l2.go = "Cancellation";
		break;

		case "NoGoods":
			Dialog.snd = "voice\SMSH\SMSH015";
			pchar.quest.Contraband.relation = makeint(pchar.quest.Contraband.relation) - 10;
			d.Text = DLG_TEXT[47];
			Link.l1 = DLG_TEXT[48];
			Link.l1.go = "Exit_Cancel";				
		break; 
			
		case "Finish":		
			Dialog.snd = "voice\SMSH\SMSH016";
			d.Text = DLG_TEXT[49] + Pchar.quest.Contraband.Sum + DLG_TEXT[50];
			Link.l1 = DLG_TEXT[51];
			Link.l1.go = "Finish_exit";
			Link.l2 = DLG_TEXT[52];
			Link.l2.go = "Cancellation";
		break;

	}
}
//nclude "DIALOGS\RelationAgent_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_Meeting, PeaceGroup;
	int Nation, Sum;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

		case "First time":
			Dialog.defAni = "dialog_stay2";
			Dialog.defCam = "2";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			
			if(Pchar.quest.RelationAgentMet == "0")
			{
				Dialog.snd = "voice\REDI\REDI001";
				d.Text = DLG_TEXT[0] + address_form.eng + DLG_TEXT[1];
				Link.l1 = DLG_TEXT[2];
				Link.l1.go = "Tutorial";
				NPC_Meeting = "1"; 
			}
			else
			{
				if(NPChar.quest.meeting == "0")
				{
					Dialog.snd = "voice\REDI\REDI002";
					d.Text = DLG_TEXT[3];
					Link.l1 = DLG_TEXT[4] + Pchar.name + DLG_TEXT[5];
					Link.l1.go = "Service";
					Link.l2 = DLG_TEXT[6];
					Link.l2.go = "Exit";					
				}
				else
				{
					Dialog.snd = "voice\REDI\REDI003";
					d.Text = DLG_TEXT[7] + Pchar.name"?" ;
					Link.l1 = DLG_TEXT[8];
					Link.l1.go = "Service";
					Link.l2 = DLG_TEXT[9];
					Link.l2.go = "exit";

				}
			}

		break;

		case "Service":
			Dialog.snd = "voice\REDI\REDI004";
			d.Text = DLG_TEXT[10];
			if(GetNationRelation2MainCharacter(ENGLAND) == RELATION_ENEMY)
			{
				Link.l1 = DLG_TEXT[11];
				Link.l1.go = "England";

			}
			if(GetNationRelation2MainCharacter(SPAIN) == RELATION_ENEMY)
			{
				Link.l2 = DLG_TEXT[12];
				Link.l2.go = "Spain";
			}
			if(GetNationRelation2MainCharacter(PORTUGAL) == RELATION_ENEMY)
			{
				Link.l3 = DLG_TEXT[13];
				Link.l3.go = "Portugal";			
			}
			if(GetNationRelation2MainCharacter(HOLLAND) == RELATION_ENEMY)
			{
				Link.l4 = DLG_TEXT[14];
				Link.l4.go = "Holland";			
			}
			if(GetNationRelation2MainCharacter(FRANCE) == RELATION_ENEMY)
			{
				Link.l5 = DLG_TEXT[15];
				Link.l5.go = "France";			
			}
			Link.l6 = DLG_TEXT[16];
			Link.l6.go = "exit";			
		break;

		case "Tutorial":
			Dialog.snd = "voice\REDI\REDI005";
			d.Text = DLG_TEXT[17];
			Link.l99 = DLG_TEXT[18];
			Link.l99.go = "Tutorial_1";
		break;

		case "Tutorial_1":
			Dialog.snd = "voice\REDI\REDI006";
			d.Text = DLG_TEXT[19];
			Link.l99 = DLG_TEXT[20];
			Link.l99.go = "Tutorial_2";
		break;

		case "Tutorial_2":
			Dialog.snd = "voice\REDI\REDI007";
			d.Text = DLG_TEXT[21];
			Link.l99 = DLG_TEXT[22];
			Link.l99.go = "Tutorial_3";
		break;

		case "Tutorial_3":
			Dialog.snd = "voice\REDI\REDI008";
			d.Text = DLG_TEXT[23];
			Link.l99 = DLG_TEXT[24];
			Link.l99.go = "Tutorial_4";
		break;

		case "Tutorial_4":
			Dialog.snd = "voice\REDI\REDI009";
			d.Text = DLG_TEXT[25];
			Link.l99 = DLG_TEXT[26];
			Link.l99.go = "Service";
		break;

		case "England":
			Pchar.quest.Relations.nation = ENGLAND;
			Pchar.quest.Relations.PeaceGroup = "ENGLAND_SOLDIERS";
			Pchar.quest.Relations.sum = makeint(stf(Pchar.rank)/stf(Pchar.reputation)*20000);	
			Dialog.snd = "voice\REDI\REDI010";
			d.Text = DLG_TEXT[27] + Pchar.quest.Relations.sum + DLG_TEXT[28];
			Link.l1 = DLG_TEXT[29];
			if(makeint(Pchar.money) < makeint(Pchar.quest.Relations.sum))
			{
				Link.l1.go = "No_money";			
			}
			else
			{
				Link.l1.go = "Agreed";			
			}
			Link.l2 = DLG_TEXT[30];
			Link.l2.go = "exit";			
		break;

		case "Spain":
			Pchar.quest.Relations.nation = SPAIN;
			Pchar.quest.Relations.PeaceGroup = "SPAIN_SOLDIERS";
			Pchar.quest.Relations.sum = makeint(stf(Pchar.rank)/stf(Pchar.reputation)*20000);	
			Dialog.snd = "voice\REDI\REDI011";
			d.Text = DLG_TEXT[31] + Pchar.quest.Relations.sum + DLG_TEXT[32];
			Link.l1 = DLG_TEXT[33];
			if(makeint(Pchar.money) < makeint(Pchar.quest.Relations.sum))
			{
				Link.l1.go = "No_money";			
			}
			else
			{
				Link.l1.go = "Agreed";			
			}
			Link.l2 = DLG_TEXT[34];
			Link.l2.go = "exit";			
		break;

		case "France":
			Pchar.quest.Relations.nation = FRANCE;
			Pchar.quest.Relations.PeaceGroup = "FRANCE_SOLDIERS";
			Pchar.quest.Relations.sum = makeint(stf(Pchar.rank)/stf(Pchar.reputation)*20000);	
			Dialog.snd = "voice\REDI\REDI012";
			d.Text = DLG_TEXT[35] + Pchar.quest.Relations.sum + DLG_TEXT[36];
			Link.l1 = DLG_TEXT[37];
			if(makeint(Pchar.money) < makeint(Pchar.quest.Relations.sum))
			{
				Link.l1.go = "No_money";			
			}
			else
			{
				Link.l1.go = "Agreed";			
			}
			Link.l2 = DLG_TEXT[38];
			Link.l2.go = "exit";			
		break;

		case "Portugal":
			Pchar.quest.Relations.nation = PORTUGAL;
			Pchar.quest.Relations.PeaceGroup = "CONCEICAO_SOLDIERS";
			Pchar.quest.Relations.sum = makeint(stf(Pchar.rank)/stf(Pchar.reputation)*20000);	
			Dialog.snd = "voice\REDI\REDI013";
			d.Text = DLG_TEXT[39] + Pchar.quest.Relations.sum + DLG_TEXT[40];
			Link.l1 = DLG_TEXT[41];
			if(makeint(Pchar.money) < makeint(Pchar.quest.Relations.sum))
			{
				Link.l1.go = "No_money";			
			}
			else
			{
				Link.l1.go = "Agreed";			
			}
			Link.l2 = DLG_TEXT[42];
			Link.l2.go = "exit";			
		break;

		case "Holland":
			Pchar.quest.Relations.nation = HOLLAND;
			Pchar.quest.Relations.PeaceGroup = "DOUWESEN_SOLDIERS";
			Pchar.quest.Relations.sum = makeint(stf(Pchar.rank)/stf(Pchar.reputation)*20000);	
			Dialog.snd = "voice\REDI\REDI014";
			d.Text = DLG_TEXT[43] + Pchar.quest.Relations.sum + DLG_TEXT[44];
			Link.l1 = DLG_TEXT[45];
			if(makeint(Pchar.money) < makeint(Pchar.quest.Relations.sum))
			{
				Link.l1.go = "No_money";			
			}
			else
			{
				Link.l1.go = "Agreed";			
			}
			Link.l2 = DLG_TEXT[46];
			Link.l2.go = "exit";			
		break;

		case "No_Money":
			Dialog.snd = "voice\REDI\REDI015";
			d.Text = DLG_TEXT[47];
			Link.l1 = DLG_TEXT[48];
			Link.l1.go = "exit";			
		break;

		case "Agreed":
			Dialog.snd = "voice\REDI\REDI016";
			SetNationRelation2MainCharacter(makeint(Pchar.quest.Relations.nation), RELATION_FRIEND);
			LAi_group_SetRelation(Pchar.quest.Relations.PeaceGroup, LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
			AddMoneyToCharacter(PChar, -(makeint(Pchar.quest.Relations.sum)));
			DeleteAttribute(Pchar, "quest.Relations");
			d.Text = DLG_TEXT[49];
			Link.l1 = DLG_TEXT[50];
			Link.l1.go = "Exit";
			Link.l2 = DLG_TEXT[51];
			Link.l2.go = "Service";
		break;
				

	}
}
//nclude "DIALOGS\Conceicao Citizen_dialog.h"
void ProcessDialogEvent()
{
    ref NPChar, PChar, d; 
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_Meeting, TempInfoCharacterID_1, TempInfoCharacterID_2;
	int DonationSize;
	
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
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";

			if(NPChar.quest.meeting == "0")
			{
				NPC_Meeting = "1"; 
				dialog.snd1 = "";
				dialog.snd2 = "";
				dialog.snd3 = "";
				d.Text = RandPhrase(TimeGreeting() + DLG_TEXT[0] + address_form.por + DLG_TEXT[1] + NPChar.name + " " + NPChar.lastname + DLG_TEXT[2], DLG_TEXT[3] + address_form.por + DLG_TEXT[4] + NPChar.name + " " + NPChar.lastname + DLG_TEXT[5], DLG_TEXT[6] + NPChar.name + " " + NPChar.lastname + DLG_TEXT[7] + address_form.por + DLG_TEXT[8], &Dialog, Dialog.snd1, Dialog.snd2, Dialog.snd3);
				Link.l1 = LinkRandPhrase(DLG_TEXT[9] + Pchar.name + " " + Pchar.lastname + DLG_TEXT[10] + PChar.Ship.name + DLG_TEXT[11], DLG_TEXT[12] + Pchar.name + " " + Pchar.lastname + DLG_TEXT[13], DLG_TEXT[14] + PChar.name + DLG_TEXT[15]);
				Link.l1.go = "Meeting";

				if(CheckQuestAttribute("Voysey_lost", "1"))
				{
					NPC_Meeting = "1"; 
					Link.l1 = DLG_TEXT[16] + Characters[GetCharacterIndex(DLG_TEXT[17])].name + " " + Characters[GetCharacterIndex(DLG_TEXT[18])].lastname + DLG_TEXT[19];
					Link.l1.go = "Meeting1";
				}

				if(CheckQuestAttribute("Nigel_lost", "1"))
				{
					NPC_Meeting = "1"; 
					Link.l2 = DLG_TEXT[20] + Characters[GetCharacterIndex(DLG_TEXT[21])].name + " " + Characters[GetCharacterIndex(DLG_TEXT[22])].lastname + DLG_TEXT[23];
					Link.l2.go = "Meeting1";
				}
			}
			else
			{
				if (npchar.location == "Conceicao_church")
				{
					dialog.text = DLG_TEXT[24];
					link.l1 = DLG_TEXT[25];
					link.l1.go = "exit";
				}
				else
				{
					dialog.snd1 = "";
					dialog.snd2 = "";
					dialog.snd3 = "";
					d.Text = RandPhrase(DLG_TEXT[26] + PChar.name + DLG_TEXT[27], DLG_TEXT[28] + TimeGreeting() + DLG_TEXT[29], DLG_TEXT[30] + address_form.por + " " + Pchar.name + DLG_TEXT[31], &Dialog, Dialog.snd1, Dialog.snd2, Dialog.snd3);
					if(Rand(1)==0)
					{
						Link.l1 = LinkRandPhrase(DLG_TEXT[32], DLG_TEXT[33], DLG_TEXT[34]);
						Link.l1.go = "rumours";
					}
					else
					{
						Link.l1 = LinkRandPhrase(DLG_TEXT[35], DLG_TEXT[36], DLG_TEXT[37]);
						Link.l1.go = "town";
					}
					if(Rand(1)==0)	
					{
						Link.l2 = LinkRandPhrase(DLG_TEXT[38], DLG_TEXT[39], DLG_TEXT[40]);
						Link.l2.go = "info";
					}
					else
					{
						Link.l2 = LinkRandPhrase(DLG_TEXT[41], DLG_TEXT[42], DLG_TEXT[43]);
						Link.l2.go = "colony";
					}
					if(CheckQuestAttribute("Voysey_lost", "1"))
					{
						NPC_Meeting = "1"; 
						Link.l4 = DLG_TEXT[44] + Characters[GetCharacterIndex(DLG_TEXT[45])].name + " " + Characters[GetCharacterIndex(DLG_TEXT[46])].lastname + DLG_TEXT[47];
						Link.l4.go = "Meeting1";
					}

					if(CheckQuestAttribute("Nigel_lost", "1"))
					{
						NPC_Meeting = "1"; 
						Link.l5 = DLG_TEXT[48] + Characters[GetCharacterIndex(DLG_TEXT[49])].name + " " + Characters[GetCharacterIndex(DLG_TEXT[50])].lastname + DLG_TEXT[51];
						Link.l5.go = "Meeting1";
					}
					Link.l3 = DLG_TEXT[52];
					Link.l3.go = "exit";
				}
			}
	    	break;

		case "Meeting1":
			d.Text = DLG_TEXT[53];
			Link.l1 = DLG_TEXT[54];
			Link.l1.go = "exit";
		break;

		case "Meeting":
				dialog.snd1 = "";
				dialog.snd2 = "";
				dialog.snd3 = "";
				d.Text = RandPhrase(DLG_TEXT[55], DLG_TEXT[56] + address_form.por + " " + PChar.name + DLG_TEXT[57], DLG_TEXT[58], &Dialog, Dialog.snd1, Dialog.snd2, Dialog.snd3);
				if(Rand(1)==0)
				{
					Link.l1 = LinkRandPhrase(DLG_TEXT[59], DLG_TEXT[60], DLG_TEXT[61]);
					Link.l1.go = "rumours";
				}
				else
				{
					Link.l1 = LinkRandPhrase(DLG_TEXT[62], DLG_TEXT[63], DLG_TEXT[64]);
					Link.l1.go = "town";
				}
				if(Rand(1)==0)	
				{
					Link.l2 = LinkRandPhrase(DLG_TEXT[65], DLG_TEXT[66], DLG_TEXT[67]);
					Link.l2.go = "info";
				}
				else
				{
					Link.l2 = LinkRandPhrase(DLG_TEXT[68], DLG_TEXT[69], DLG_TEXT[70]);
					Link.l2.go = "colony";
				}


				Link.l3 = DLG_TEXT[71];
				Link.l3.go = "exit";
		break;

		case "rumours":
				d.Text = SelectRumour();
				Link.l1 = DLG_TEXT[72];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[73];
				Link.l2.go = "exit";
		break;

		case "new question":
				dialog.snd1 = "";
				dialog.snd2 = "";
				dialog.snd3 = "";
				d.Text = RandPhrase(DLG_TEXT[74] + address_form.por + DLG_TEXT[75], DLG_TEXT[76] + address_form.por + DLG_TEXT[77], DLG_TEXT[78] + address_form.por + DLG_TEXT[79], &Dialog, Dialog.snd1, Dialog.snd2, Dialog.snd3);
				if(Rand(1)==0)
				{
					Link.l1 = LinkRandPhrase(DLG_TEXT[80], DLG_TEXT[81], DLG_TEXT[82]);
					Link.l1.go = "rumours";
				}
				else
				{
					Link.l1 = LinkRandPhrase(DLG_TEXT[83], DLG_TEXT[84], DLG_TEXT[85]);
					Link.l1.go = "town";
				}
				if(Rand(1)==0)	
				{
					Link.l2 = LinkRandPhrase(DLG_TEXT[86], DLG_TEXT[87], DLG_TEXT[88]);
					Link.l2.go = "info";
				}
				else
				{
					Link.l2 = LinkRandPhrase(DLG_TEXT[89], DLG_TEXT[90], DLG_TEXT[91]);
					Link.l2.go = "colony";
				}
				Link.l3 = DLG_TEXT[92];
				Link.l3.go = "exit";
		break;

		case "info":
				dialog.snd1 = "";
				dialog.snd2 = "";
				dialog.snd3 = "";
				d.Text = RandPhrase(DLG_TEXT[93] + address_form.por + DLG_TEXT[94], DLG_TEXT[95] + address_form.por + DLG_TEXT[96], DLG_TEXT[97] + address_form.por + DLG_TEXT[98], &Dialog, Dialog.snd1, Dialog.snd2, Dialog.snd3);
				if(Rand(1)==0)
				{	
					Link.l1 = DLG_TEXT[99];
					Link.l1.go = "governor";
				}
				else
				{
					Link.l1 = DLG_TEXT[100] + Characters[GetCharacterIndex(DLG_TEXT[101])].name + " " + Characters[GetCharacterIndex(DLG_TEXT[102])].lastname + DLG_TEXT[103];
					Link.l1.go = "tavern_keeper";
				}
				if(Rand(1)==0)	
				{
					Link.l2 = DLG_TEXT[104] + Characters[GetCharacterIndex(DLG_TEXT[105])].lastname + DLG_TEXT[106];
					Link.l2.go = "Shipwright";
				}
				else 
				{
					Link.l2 = DLG_TEXT[107] + Characters[GetCharacterIndex(DLG_TEXT[108])].name + " " + Characters[GetCharacterIndex(DLG_TEXT[109])].lastname + DLG_TEXT[110];;
					Link.l2.go = "Localtrader";
				}
				Link.l3 = DLG_TEXT[111];
				Link.l3.go = "new question";
		break;

		case "governor":				
				d.Text = DLG_TEXT[112];
				Link.l1 = DLG_TEXT[113];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[114];
				Link.l2.go = "exit";
		break;

		case "tavern_keeper":
				d.Text = DLG_TEXT[115];
				Link.l1 = DLG_TEXT[116];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[117];
				Link.l2.go = "exit";
		break;

		case "Shipwright":
				d.Text = DLG_TEXT[118];
				Link.l1 = DLG_TEXT[119];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[120];
				Link.l2.go = "exit";
		break;

		case "Localtrader":
				d.Text = DLG_TEXT[121];
				Link.l1 = DLG_TEXT[122];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[123];
				Link.l2.go = "exit";
		break;

		case "town":
			dialog.snd1 = "";
			dialog.snd2 = "";
			dialog.snd3 = "";
			d.Text = RandPhrase(DLG_TEXT[124], DLG_TEXT[125] + Address_Form.por + DLG_TEXT[126], DLG_TEXT[127] + Address_Form.por + DLG_TEXT[128], &Dialog, Dialog.snd1, Dialog.snd2, Dialog.snd3);
			Link.l1 = DLG_TEXT[129];
			Link.l1.go = "town_tavern";
			Link.l2 = DLG_TEXT[130];
			Link.l2.go = "town_shipyard";
			Link.l3 = DLG_TEXT[131];
			Link.l3.go = "town_store";
		break;

		case "town_tavern":
			d.Text = DLG_TEXT[132] + Characters[GetCharacterIndex(DLG_TEXT[133])].name + " " + Characters[GetCharacterIndex(DLG_TEXT[134])].lastname  + DLG_TEXT[135];
			Link.l1 = DLG_TEXT[136];
			Link.l1.go = "exit";
			Link.l2 = DLG_TEXT[137];
			Link.l2.go = "town_shipyard";
			Link.l3 = DLG_TEXT[138];
			Link.l3.go = "town_store";
		break;

		case "town_shipyard":
			d.Text = DLG_TEXT[139];
			Link.l1 = DLG_TEXT[140];
			Link.l1.go = "town_tavern";
			Link.l2 = DLG_TEXT[141];
			Link.l2.go = "town_store";
			Link.l3 = DLG_TEXT[142];
			Link.l3.go = "exit";
		break;

		case "town_store":
			d.Text = DLG_TEXT[143] + Address_Form.por + DLG_TEXT[144];
			Link.l1 = DLG_TEXT[145];
			Link.l1.go = "town_shipyard";
			Link.l2 = DLG_TEXT[146];
			Link.l2.go = "town_tavern";
			Link.l3 = DLG_TEXT[147];
			Link.l3.go = "exit";
		break;

		case "colony":
			dialog.snd1 = "";
			dialog.snd2 = "";
			dialog.snd3 = "";
			d.Text = RandPhrase(DLG_TEXT[148], DLG_TEXT[149], DLG_TEXT[150], &Dialog, Dialog.snd1, Dialog.snd2, Dialog.snd3);
			if(Rand(1)== 0)
			{
				Link.l1 = DLG_TEXT[151];
				Link.l1.go = "Conceicao";
			}
			else
			{
				Link.l1 = DLG_TEXT[152];
				Link.l1.go = "island";
			}
			if(Rand(1)== 0)
			{
				Link.l1 = DLG_TEXT[153];
				Link.l1.go = "fort";
			}
	/*		else
			{
				Link.l1 = "С кем торгуют местные торговцы?";
				Link.l1.go = "trade";
			}*/

			Link.l2 = DLG_TEXT[154];
			Link.l2.go = "new question";
		break;

		case "Conceicao":
			d.Text = DLG_TEXT[155];
			Link.l1 = DLG_TEXT[156];
			Link.l1.go = "Conceicao_1";
			Link.l2 = DLG_TEXT[157];
			Link.l2.go = "new question";
		break;

		case "Conceicao_1":
			d.Text = DLG_TEXT[158];
			//Link.l1 = "Дальше...";
			//Link.l1.go = "Redmond_2";
			Link.l2 = DLG_TEXT[159];
			Link.l2.go = "new question";
		break;

		case "island":
			switch(Rand(2))
			{	
				case 0:
					d.Text = DLG_TEXT[160];
					Link.l1 = DLG_TEXT[161];
					Link.l1.go = "colony";
				break;

				case 1:
					d.Text = DLG_TEXT[162];
					Link.l1 = DLG_TEXT[163];
					Link.l1.go = "colony";
				break;

				case 2:
					d.Text = DLG_TEXT[164];
					Link.l1 = DLG_TEXT[165];
					Link.l1.go = "colony";
				break;
			}
			Link.l2 = DLG_TEXT[166];
			Link.l2.go = "new question";
		break;

		case "fort":
			switch(Rand(2))
			{	
				case 0:
					d.Text = DLG_TEXT[167];
					Link.l1 = DLG_TEXT[168];
					Link.l1.go = "colony";
				break;

				case 1:
					d.Text = DLG_TEXT[169];
					Link.l1 = DLG_TEXT[170];
					Link.l1.go = "colony";
				break;

				case 2:
					d.Text = DLG_TEXT[171];
					Link.l1 = DLG_TEXT[172];
					Link.l1.go = "colony";
				break;
			}
			Link.l2 = DLG_TEXT[173];
			Link.l2.go = "new question";
		break;


			} // end of switch; 

}
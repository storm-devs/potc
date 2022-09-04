//nclude "DIALOGS\Greenford Citizen_Dialog.h"
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
				d.Text = RandPhrase(TimeGreeting() + DLG_TEXT[0] + address_form.eng + DLG_TEXT[1] + NPChar.name + " " + NPChar.lastname + DLG_TEXT[2], DLG_TEXT[3] + address_form.eng + DLG_TEXT[4] + NPChar.name + " " + NPChar.lastname + DLG_TEXT[5], DLG_TEXT[6] + address_form.eng + DLG_TEXT[7] + NPChar.name + " " + NPChar.lastname + DLG_TEXT[8], &Dialog, Dialog.snd1, Dialog.snd2, Dialog.snd3);
				Link.l1 = linkRandPhrase(DLG_TEXT[9] + Pchar.name + " " + Pchar.lastname + DLG_TEXT[10] + PChar.Ship.name + DLG_TEXT[11], DLG_TEXT[12] + Pchar.name + " " + Pchar.lastname + DLG_TEXT[13], DLG_TEXT[14] + PChar.name + DLG_TEXT[15]);
				Link.l1.go = "Meeting";
			}
			else
			{
				if(NPChar.sex == "man")
				{
					dialog.snd1 = "";
					dialog.snd2 = "";
					dialog.snd3 = "";
				    d.Text = RandPhrase(DLG_TEXT[16] + PChar.name + DLG_TEXT[17], DLG_TEXT[18] + Pchar.name + " " + Pchar.lastname + DLG_TEXT[19], DLG_TEXT[20] + address_form.eng + " " + Pchar.lastname + DLG_TEXT[21], &Dialog, Dialog.snd1, Dialog.snd2, Dialog.snd3);
				}
				else
				{
					dialog.snd1 = "";
					dialog.snd2 = "";
					dialog.snd3 = "";
				    d.Text = RandPhrase(DLG_TEXT[22] + PChar.name + DLG_TEXT[23], DLG_TEXT[24] + Pchar.name + " " + Pchar.lastname + DLG_TEXT[25], DLG_TEXT[26] + address_form.eng + " " + Pchar.lastname + DLG_TEXT[27], &Dialog, Dialog.snd1, Dialog.snd2, Dialog.snd3);
				}
				if(Rand(1)==0)
				{
					Link.l1 = LinkRandPhrase(DLG_TEXT[28], DLG_TEXT[29], DLG_TEXT[30]);
					Link.l1.go = "rumours";
				}
				else
				{
					Link.l1 = LinkRandPhrase(DLG_TEXT[31], DLG_TEXT[32], DLG_TEXT[33]);
					Link.l1.go = "town";
				}
				if(Rand(1)==0)	
				{
					Link.l2 = LinkRandPhrase(DLG_TEXT[34], DLG_TEXT[35], DLG_TEXT[36]);
					Link.l2.go = "info";
				}
				else
				{
					Link.l2 = LinkRandPhrase(DLG_TEXT[37], DLG_TEXT[38], DLG_TEXT[39]);
					Link.l2.go = "colony";
				}

				Link.l3 = DLG_TEXT[40];
				Link.l3.go = "exit";
			}
	    	break;

		case "Meeting":
			dialog.snd1 = "";
			dialog.snd2 = "";
			dialog.snd3 = "";
				d.Text = RandPhrase(DLG_TEXT[41], DLG_TEXT[42] + address_form.eng + " " + PChar.name + DLG_TEXT[43], DLG_TEXT[44] + PChar.name + DLG_TEXT[45], &Dialog, Dialog.snd1, Dialog.snd2, Dialog.snd3);
				if(Rand(1)==0)
				{
					Link.l1 = LinkRandPhrase(DLG_TEXT[46], DLG_TEXT[47], DLG_TEXT[48]);
					Link.l1.go = "rumours";
				}
				else
				{
					Link.l1 = LinkRandPhrase(DLG_TEXT[49], DLG_TEXT[50], DLG_TEXT[51]);
					Link.l1.go = "town";
				}
				if(Rand(1)==0)	
				{
					Link.l2 = LinkRandPhrase(DLG_TEXT[52], DLG_TEXT[53], DLG_TEXT[54]);
					Link.l2.go = "info";
				}
				else
				{
					Link.l2 = LinkRandPhrase(DLG_TEXT[55], DLG_TEXT[56], DLG_TEXT[57]);
					Link.l2.go = "colony";
				}


				Link.l3 = DLG_TEXT[58];
				Link.l3.go = "exit";
		break;

		case "rumours":
				d.Text = SelectRumour();
				Link.l1 = DLG_TEXT[59];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[60];
				Link.l2.go = "exit";
		break;

		case "new question":
			dialog.snd1 = "";
			dialog.snd2 = "";
			dialog.snd3 = "";
				d.Text = RandPhrase(DLG_TEXT[61] + address_form.eng + DLG_TEXT[62], DLG_TEXT[63] + address_form.eng + DLG_TEXT[64], DLG_TEXT[65], &Dialog, Dialog.snd1, Dialog.snd2, Dialog.snd3);
				if(Rand(1)==0)
				{
					Link.l1 = LinkRandPhrase(DLG_TEXT[66], DLG_TEXT[67], DLG_TEXT[68]);
					Link.l1.go = "rumours";
				}
				else
				{
					Link.l1 = LinkRandPhrase(DLG_TEXT[69], DLG_TEXT[70], DLG_TEXT[71]);
					Link.l1.go = "town";
				}
				if(Rand(1)==0)	
				{
					Link.l2 = LinkRandPhrase(DLG_TEXT[72], DLG_TEXT[73], DLG_TEXT[74]);
					Link.l2.go = "info";
				}
				else
				{
					Link.l2 = LinkRandPhrase(DLG_TEXT[75], DLG_TEXT[76], DLG_TEXT[77]);
					Link.l2.go = "colony";
				}

				Link.l3 = DLG_TEXT[78];
				Link.l3.go = "exit";
		break;

		case "info":
			dialog.snd1 = "";
			dialog.snd2 = "";
			dialog.snd3 = "";
				d.Text = RandPhrase(DLG_TEXT[79] + address_form.eng + DLG_TEXT[80], DLG_TEXT[81], DLG_TEXT[82] + address_form.eng + DLG_TEXT[83], &Dialog, Dialog.snd1, Dialog.snd2, Dialog.snd3);
				if(Rand(1)==0)
				{	
					
					Link.l1 = DLG_TEXT[84];
					Link.l1.go = "governor";
				}
				else
				{
					
					Link.l1 = DLG_TEXT[85] + Characters[GetCharacterIndex(DLG_TEXT[86])].name + " " + Characters[GetCharacterIndex(DLG_TEXT[87])].lastname + DLG_TEXT[88];
					Link.l1.go = "tavernkeeper";
				}
				if(Rand(1)==0)	
				{
					
					Link.l2 = DLG_TEXT[89] + Characters[GetCharacterIndex(DLG_TEXT[90])].name + " " + Characters[GetCharacterIndex(DLG_TEXT[91])].lastname + DLG_TEXT[92];
					Link.l2.go = "shipwright";
				}
				else 
				{
					
					Link.l2 = DLG_TEXT[93] + Characters[GetCharacterIndex(DLG_TEXT[94])].name + " " + Characters[GetCharacterIndex(DLG_TEXT[95])].lastname + DLG_TEXT[96];;
					Link.l2.go = "localtrader";
				}
				Link.l3 = DLG_TEXT[97];
				Link.l3.go = "new question";
		break;

		case "governor":				
				d.Text = DLG_TEXT[98];
				Link.l1 = DLG_TEXT[99];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[100];
				Link.l2.go = "exit";
		break;

		case "tavernkeeper":
				d.Text = DLG_TEXT[101];
				Link.l1 = DLG_TEXT[102];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[103];
				Link.l2.go = "exit";
		break;

		case "shipwright":
				d.Text = DLG_TEXT[104];
				Link.l1 = DLG_TEXT[105];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[106];
				Link.l2.go = "exit";
		break;

		case "localtrader":
				d.Text = DLG_TEXT[107];
				Link.l1 = DLG_TEXT[108];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[109];
				Link.l2.go = "exit";
		break;

		case "town":
			if(NPChar.sex == "man")
			{
				dialog.snd1 = "";
				dialog.snd2 = "";
				dialog.snd3 = "";
			   d.Text = RandPhrase(DLG_TEXT[110] + Address_Form.eng + " " + PChar.lastname + DLG_TEXT[111], DLG_TEXT[112], DLG_TEXT[113] + Address_Form.eng + DLG_TEXT[114], &Dialog, Dialog.snd1, Dialog.snd2, Dialog.snd3);
			}
			else
			{
				dialog.snd1 = "";
				dialog.snd2 = "";
				dialog.snd3 = "";
			   d.Text = RandPhrase(DLG_TEXT[115] + Address_Form.eng + " " + PChar.lastname + DLG_TEXT[116], DLG_TEXT[117], DLG_TEXT[118] + Address_Form.eng + DLG_TEXT[119], &Dialog, Dialog.snd1, Dialog.snd2, Dialog.snd3);
			}

			Link.l1 = DLG_TEXT[120];
			Link.l1.go = "town_tavern";
			Link.l2 = DLG_TEXT[121];
			Link.l2.go = "town_shipyard";
			Link.l3 = DLG_TEXT[122];
			Link.l3.go = "town_store";
		break;

		case "town_tavern":
			d.Text = DLG_TEXT[123];
			Link.l1 = DLG_TEXT[124];
			Link.l1.go = "exit";
			Link.l2 = DLG_TEXT[125];
			Link.l2.go = "town_shipyard";
			Link.l3 = DLG_TEXT[126];
			Link.l3.go = "town_store";
		break;

		case "town_shipyard":
			d.Text = DLG_TEXT[127]
			Link.l1 = DLG_TEXT[128];
			Link.l1.go = "town_tavern";
			Link.l2 = DLG_TEXT[129];
			Link.l2.go = "town_store";
			Link.l3 = DLG_TEXT[130];
			Link.l3.go = "exit";
		break;

		case "town_store":
			d.Text = DLG_TEXT[131];
			Link.l1 = DLG_TEXT[132];
			Link.l1.go = "town_shipyard";
			Link.l2 = DLG_TEXT[133];
			Link.l2.go = "town_tavern";
			Link.l3 = DLG_TEXT[134];
			Link.l3.go = "exit";
		break;


		case "colony":
			dialog.snd1 = "";
			dialog.snd2 = "";
			dialog.snd3 = "";
			d.Text = RandPhrase(DLG_TEXT[135], DLG_TEXT[136], DLG_TEXT[137] + address_form.eng + " " + PChar.lastname + DLG_TEXT[138], &Dialog, Dialog.snd1, Dialog.snd2, Dialog.snd3);
			if(Rand(1)== 0)
			{
				Link.l1 = DLG_TEXT[139];
				Link.l1.go = "Greenford";
			}
			else
			{
				Link.l1 = DLG_TEXT[140];
				Link.l1.go = "island";
			}
			if(Rand(1)== 0)
			{
				Link.l1 = DLG_TEXT[141];
				Link.l1.go = "fort";
			}
	/*		else
			{
				Link.l1 = "С кем торгуют местные торговцы?";
				Link.l1.go = "trade";
			}*/

			Link.l2 = DLG_TEXT[142];
			Link.l2.go = "new question";
		break;

		case "Greenford":
			d.Text = DLG_TEXT[143];
			Link.l1 = DLG_TEXT[144];
			Link.l1.go = "Greenford_1";
			Link.l2 = DLG_TEXT[145];
			Link.l2.go = "new question";
		break;

		case "Greenford_1":
			d.Text = DLG_TEXT[146];
			//Link.l1 = "Дальше...";
			//Link.l1.go = "Redmond_2";
			Link.l2 = DLG_TEXT[147];
			Link.l2.go = "new question";
		break;

		case "island":
			switch(Rand(2))
			{	
				case 0:
					d.Text = DLG_TEXT[148];
					Link.l1 = DLG_TEXT[149];
					Link.l1.go = "colony";
				break;

				case 1:
					d.Text = DLG_TEXT[150];
					Link.l1 = DLG_TEXT[151];
					Link.l1.go = "colony";
				break;

				case 2:
					d.Text = DLG_TEXT[152];
					Link.l1 = DLG_TEXT[153];
					Link.l1.go = "colony";
				break;
			}
			Link.l2 = DLG_TEXT[154];
			Link.l2.go = "new question";
		break;

		case "fort":
			switch(Rand(2))
			{	
				case 0:
					d.Text = DLG_TEXT[155];
					Link.l1 = DLG_TEXT[156];
					Link.l1.go = "colony";
				break;

				case 1:
					d.Text = DLG_TEXT[157]
					Link.l1 = DLG_TEXT[158];
					Link.l1.go = "colony";
				break;

				case 2:
					d.Text = DLG_TEXT[159];
					Link.l1 = DLG_TEXT[160];
					Link.l1.go = "colony";
				break;
			}
			Link.l2 = DLG_TEXT[161];
			Link.l2.go = "new question";
		break;


			} // end of switch; 

}
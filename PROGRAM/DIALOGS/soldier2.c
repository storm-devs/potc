//nclude "DIALOGS\soldier2.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
	// -----------------------------------Диалог первый - первая встреча
		case "First time":
			Dialog.defAni = "Gov_Dialog_1";
			Dialog.ani = "Gov_Dialog_2";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";

			d.Text = DLG_TEXT[0];
			Link.l1 = DLG_TEXT[1];
			Link.l1.go = "exit";
			Link.l2 = DLG_TEXT[2];
			Link.l2.go = "meeting";
		break;

		case "meeting":
			d.Text = DLG_TEXT[3];
			Link.l1 = DLG_TEXT[4];
			Link.l1.go = "exit1";
		break;

		case "meeting1":
			d.Text = DLG_TEXT[5];
			Link.l1 = DLG_TEXT[6];
			Link.l1.go = "exit2";
		break;

		case "exit":
			LAi_QuestDelay("stand_up", 3.0);
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;	
		
		case "exit1":
			LAi_QuestDelay("soldier_in_tavern3", 4.0);
			Diag.CurrentNode = "meeting1";
			DialogExit();
		break;	

		case "exit2":
			LAi_QuestDelay("convoy", 4.0);
			Diag.CurrentNode = "meeting1";
			DialogExit();
		break;	
	}
}
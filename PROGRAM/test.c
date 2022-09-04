
#event_handler("Control Activation","ProcessControls");

bool bseg1;

void Main()
{
	bseg1 = true;
	LoadSegment("test_seg1.c");
	CreateClass("modelr");
	CreateClass("dummy");
}

void ProcessControls()
{
	string ControlName = GetEventData();
	if( ControlName == "ILeft" && !bseg1 )
	{
		UnloadSegment("test_seg2.c");
		LoadSegment("test_seg1.c");
		Event("ChangeSegment");
		bseg1 = true;
	}
	if( ControlName == "IRight" && bseg1 )
	{
		UnloadSegment("test_seg1.c");
		LoadSegment("test_seg2.c");
		Event("ChangeSegment");
		bseg1 = false;
	}
}

void InitCharactersTables()
{
    InitReputationTable();
	InitMoraleTable();
	InitFaceDescribeTable();
}

void InitReputationTable()
{
    ReputationTable[REPUTATIONT_HORROR]   = "Horror of High Seas";
    ReputationTable[REPUTATIONT_BASTARD]  = "Bloody Bastard";
    ReputationTable[REPUTATIONT_SWINDLER] = "Cynic Swindler";
    ReputationTable[REPUTATIONT_RASCAL]   = "Quirky Rascal";
    ReputationTable[REPUTATIONT_NEUTRAL]  = "Neutral";
    ReputationTable[REPUTATIONT_PLAIN]    = "Plain Fellow";
    ReputationTable[REPUTATIONT_GOOD]     = "Good Matey";
    ReputationTable[REPUTATIONT_VERYGOOD] = "Very Good";
    ReputationTable[REPUTATIONT_HERO]     = "Hero";
}

void InitMoraleTable()
{
	MoraleTable[MORALET_TREACHEROUS]	= "Treacherous";
	MoraleTable[MORALET_AWFUL]			= "Awful";
	MoraleTable[MORALET_LOW]			= "Low";
	MoraleTable[MORALET_POOR]			= "Poor";
	MoraleTable[MORALET_NORMAL]			= "Normal";
	MoraleTable[MORALET_ELATED]			= "Elated";
	MoraleTable[MORALET_GOOD]			= "Good";
	MoraleTable[MORALET_HIGH]			= "High";
	MoraleTable[MORALET_EXCELLENT]		= "Excellent";
	MoraleTable[MORALET_HEROIC]			= "Heroic";
}

void InitFaceDescribeTable()
{
	int i;
	for(i=0; i<FACETABLE_SIZE; i++)
	{
		FaceDescribeTable[i].FaceIconName = "face"+(i+1);
		FaceDescribeTable[i].FaceIconGroup = "FACEICON";
		FaceDescribeTable[i].FacePortrateFileName = "interfaces\portraits\face_"+(i+1)+".tga";
	}
}

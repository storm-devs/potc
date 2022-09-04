#define MAX_SHIP_GROUPS		64

object	AIGroups[MAX_SHIP_GROUPS];

#event_handler(GROUP_CHECKTASKEVENT, "Group_CheckTask");

void SeaAIGroupsInit()
{
	for (int i=0;i<MAX_SHIP_GROUPS;i++)
	{
		DeleteAttribute(&AIGroups[i],"");
	}
}

// delete group by index
void Group_DeleteGroupIndex(int iGroupIndex)
{
	if (iGroupIndex < 0 || iGroupIndex >= MAX_SHIP_GROUPS)
	{
		Trace("Group_DeleteGroupIndex iGroupIndex is out of range = " + iGroupIndex);
		return;
	}
	DeleteAttribute(&AIGroups[iGroupIndex], "");
}

// delete group by ID
void Group_DeleteGroup(string sGroupID)
{
	int iGroupIndex = Group_FindGroup(sGroupID);
	if (iGroupIndex < 0)
	{
		if (sGroupID != PLAYER_GROUP) { Trace("Group_DeleteGroup sGroupID = " + sGroupID + ", can't find group"); }
		return;
	}
	Group_DeleteGroupIndex(iGroupIndex);
}

// if you call Group_DeleteUnusedGroup() all group marked this will be deleted
void Group_DeleteAtEnd(string sGroupID)
{
	ref rGroup = Group_GetGroupByID(sGroupID);
	rGroup.DelAtEnd = true;
}

// return group type
string Group_GetTypeR(ref rGroup) { return rGroup.Type; }
string Group_GetType(string sGroupID)
{
	ref rGroup = Group_GetGroupByID(sGroupID);
	return Group_GetTypeR(rGroup);
}

// set group type: "war" | "trade" | "pirate"
void Group_SetType(string sGroupID, string sGroupType)
{
	ref rGroup = Group_FindOrCreateGroup(sGroupID);
	rGroup.Type = sGroupType;

	if (isEntity(&AISea))
	{
		SendMessage(&AISea, "lss", AI_MESSAGE_GROUP_SET_TYPE, sGroupID, sGroupType);
	}
}

// create a new AI group for ships, return -1 if can't create
int Group_CreateGroup(string sGroupID)
{
	for (int i=0;i<MAX_SHIP_GROUPS;i++)
	{
		if (!CheckAttribute(&AIGroups[i],"id"))
		{
			//Trace("Group_CreateGroup create = " + sGroupID);
			AIGroups[i].id = sGroupID;
			Group_SetTaskNone(sGroupID);
			Group_SetType(sGroupID, "war");
			AIGroups[i].MainCharacter = "";
			return i;
		}
	}
	Trace("All slots in AIGroups are used, need to resize array!!!");
	return -1;
}

ref Group_GetGroupByID(string sGroupID)
{
	int	iGroupIndex = Group_FindGroup(sGroupID);
	// if (iGroupIndex < 0)
	return Group_GetGroupByIndex(iGroupIndex);
}

ref	Group_GetGroupByIndex(int iGroupIndex)
{
	return &AIGroups[iGroupIndex];
}

// find AI group for ships
int	Group_FindGroup(string sGroupID)
{
	for (int i=0;i<MAX_SHIP_GROUPS;i++)
	{
		if (!CheckAttribute(&AIGroups[i],"id")) { continue; }
		if (sGroupID == AIGroups[i].id) { return i; }
	}
	//Trace("Can't find SeaAI group = " + sGroupID);
	return -1;
}

ref	Group_FindOrCreateGroup(string sGroupID)
{
	int iGroupIndex = Group_FindGroup(sGroupID);
	if (iGroupIndex < 0)
	{
		iGroupIndex = Group_CreateGroup(sGroupID);
		if (iGroupIndex < 0) 
		{
			Trace("Group_FindOrCreateGroup sGroupID = " + sGroupID + ", can't create group ");
			AIGroups[iGroupIndex].Task.Lock = false;
			return &AIGroups[0];
		}
	}

	return &AIGroups[iGroupIndex];
}

// set group address to none
void Group_SetAddressNone(string sGroupID)
{
	ref rGroup = Group_FindOrCreateGroup(sGroupID);

	rGroup.Location = "none";
}

// set location near other group
void Group_SetPursuitGroup(string sGroupID, string sPursuitGroupID)
{
	ref rGroup = Group_FindOrCreateGroup(sGroupID);
	rGroup.Location.neargroup = sPursuitGroupID;

	if (isEntity(&AISea))
	{
		SendMessage(&AISea, "lss", AI_MESSAGE_GROUP_SET_LOCATION_OTHER_GROUP, sGroupID, sPursuitGroupID);
	}
}

// set new address for group
void Group_SetAddress(string sGroupID, string sLocationID, string sLocationGroup, string sLocationLocator)
{
	ref rGroup = Group_FindOrCreateGroup(sGroupID);

	rGroup.Location = sLocationID;
	rGroup.Location.group = sLocationGroup;
	rGroup.Location.locator = sLocationLocator;
}

void Group_DeleteUnusedGroup()
{
	for (int i=0;i<MAX_SHIP_GROUPS;i++)	
	{
		ref rGroup = Group_GetGroupByIndex(i);
		if (CheckAttribute(rGroup, "DelAtEnd"))
		{
			Group_DeleteGroupIndex(i);
		}
	}
}

// ======================================================================================================
// =										CHARACTER MANAGER											=
// ======================================================================================================

// Get main character for group
ref Group_GetGroupCommanderR(ref rGroup) { return GetCharacter(GetCharacterIndex(rGroup.MainCharacter)); }
ref Group_GetGroupCommander(string sGroupID)
{
	ref rGroup = Group_FindOrCreateGroup(sGroupID);
	return Group_GetGroupCommanderR(rGroup);
}

// Set group commander
void Group_SetGroupCommander(string sGroupID, string sCharacterID)
{
	ref rGroup = Group_FindOrCreateGroup(sGroupID);

	rGroup.MainCharacter = sCharacterID;

	if (bSeaActive)
	{
		ref rCharacter = GetCharacter(GetCharacterIndex(sCharacterID));
		SendMessage(&AISea, "lsa", AI_MESSAGE_GROUP_SET_COMMANDER, sGroupID, rCharacter);
	}
}

// delete character from others group, add character to new group
void Group_ChangeCharacter(string sGroupID, string sCharacterID)
{
	for (int i=0;i<MAX_SHIP_GROUPS;i++)	
	{
		ref rOldGroup = Group_GetGroupByIndex(i);
		if (CheckAttribute(rOldGroup, "id"))
		{
			Group_DelCharacter(rOldGroup.id, sCharacterID);
		}
	}

	Group_AddCharacter(sGroupID, sCharacterID);
}

// add new character to group
void Group_AddCharacter(string sGroupID, string sCharacterID)
{
	ref rGroup = Group_FindOrCreateGroup(sGroupID);
	
	// add new character to list
	int iCharacterIndex = GetCharacterIndex(sCharacterID);
	string sTemp = "id_" + iCharacterIndex;
	rGroup.Quest.(sTemp) = sCharacterID;
	rGroup.Quest.(sTemp).index = iCharacterIndex;
}

int Group_GetDeadCharactersNum(string sGroupID) { ref rGroup = Group_FindOrCreateGroup(sGroupID); return Group_GetDeadCharactersNumR(rGroup); }
int Group_GetDeadCharactersNumR(ref rGroup)
{
	int iDeads = 0;
	int iNum = Group_GetCharactersNumR(rGroup);
	for (int i=0; i<iNum; i++)
	{
		int iCharacterIndex = Group_GetCharacterIndexR(rGroup, i);
		if (iCharacterIndex < 0) { iDeads++; }
		if (LAi_IsDead(&Characters[iCharacterIndex])) { iDeads++; }
	}
	return iDeads;
}

int Group_GetCharactersNum(string sGroupID) { ref rGroup = Group_FindOrCreateGroup(sGroupID); return Group_GetCharactersNumR(rGroup); }
int Group_GetCharactersNumR(ref rGroup)
{
	aref arQuest; 
	if (!CheckAttribute(rGroup,"quest")) { return 0; }
	makearef(arQuest,rGroup.Quest);
	return GetAttributesNum(arQuest);
}

int Group_GetCharacterIndexR(ref rGroup, int iIndex)
{
	aref arQuest, arAttr; 
	if (!CheckAttribute(rGroup,"quest")) { return -1; }
	makearef(arQuest,rGroup.Quest);
	int iNumAttributes = GetAttributesNum(arQuest);
	if (iIndex >= iNumAttributes) { return -1; } 
	arAttr = GetAttributeN(arQuest, iIndex);
	return sti(arAttr.index);
}

// delete character from group
void Group_DelCharacter(string sGroupID, string sCharacterID)
{
	ref rGroup = Group_FindOrCreateGroup(sGroupID);

	string sTemp = "Quest.id_" + GetCharacterIndex(sCharacterID);

	if (CheckAttribute(rGroup, sTemp))
	{
		DeleteAttribute(rGroup, sTemp);
	}
}

// ======================================================================================================
// =											GROUP UTILS												=
// ======================================================================================================

bool Group_isDeadR(ref rGroup)
{
	int i = 0;
	int iNumDeadCharacters = 0;
	while (true)
	{
		int iCharacterIndex = Group_GetCharacterIndexR(rGroup, i);
		if (iCharacterIndex < 0) { break; }
		if (LAi_IsDead(&Characters[iCharacterIndex])) { iNumDeadCharacters++; }
		i++;
	}
	if (iNumDeadCharacters == i) { return true; }
	return false;
}

bool Group_isDead(string sGroupID)
{
	int	iGroupIndex = Group_FindGroup(sGroupID);
	if (iGroupIndex < 0) { return false; }

	ref rGroup = Group_GetGroupByIndex(iGroupIndex);
	return Group_isDeadR(rGroup);
}

// set start position
void Group_SetXZ_AY(string sGroupID, float x, float z, float ay)
{
	ref rGroup = Group_FindOrCreateGroup(sGroupID);
	
	rGroup.Pos.x = x;
	rGroup.Pos.z = z;
	rGroup.Pos.ay = ay;

	if (bSeaActive)
	{
		SendMessage(&AISea, "lsffff", AI_MESSAGE_GROUP_SET_XYZ_AY, sGroupID, x, 0.0, z, ay);
	}
}

float Group_GetAttackHPDistance_R(ref rGroup, float fDistance)
{
	float fHP = 0.0;
	if (bSeaActive)
	{
		SendMessage(&AISea, "lsfe", AI_MESSAGE_GROUP_GET_ATTACK_HP, rGroup.id, fDistance, &fHP);
	}
	return fHP;
}

float Group_GetAttackHP(string sGroupID) { ref rG = Group_FindOrCreateGroup(sGroupID); return Group_GetAttackHP_R(rG); }
float Group_GetAttackHP_R(ref rGroup)
{
	return Group_GetAttackHPDistance_R(rGroup, -1.0);
}

float Group_GetPowerHP(string sGroupID) { ref rG = Group_FindOrCreateGroup(sGroupID); return Group_GetPowerHP_R(rG); }
float Group_GetPowerHP_R(ref rGroup)
{
	float fHP = 0.0;
	int i = 0;
	while (true)
	{
		int iCharacterIndex = Group_GetCharacterIndexR(rGroup, i); i++;
		if (iCharacterIndex < 0) { break; }
		fHP = fHP + stf(Characters[iCharacterIndex].Ship.HP);
	}	
	return fHP;
}

// ======================================================================================================
// =											TASK SECTION											=
// ======================================================================================================

bool Group_isTaskLockR(ref rGroup) { return sti(rGroup.Task.Lock); }
bool Group_isTaskLock(string sGroupID)
{
	ref rGroup = Group_FindOrCreateGroup(sGroupID);
	return Group_isTaskLockR(rGroup);
}

// lock task, group can't change task before end current
void Group_LockTask(string sGroupID)
{
	ref rGroup = Group_FindOrCreateGroup(sGroupID);
	rGroup.Task.Lock = true;
}

// unlock task, group can change tasks 
void Group_UnlockTask(string sGroupID)
{
	ref rGroup = Group_FindOrCreateGroup(sGroupID);
	rGroup.Task.Lock = false;
}

// Task: Runaway
void Group_SetTaskRunaway(string sGroupID)
{
	ref rGroup = Group_FindOrCreateGroup(sGroupID);

	rGroup.Task = AITASK_RUNAWAY;
	rGroup.Task.Target = "";

	if (bSeaActive)	{ AIRunaway_GroupRunaway(sGroupID); }
}

// Task: Attack
void Group_SetTaskAttack(string sGroupID, string sAttackedGroup) { Group_SetTaskAttackEx(sGroupID, sAttackedGroup, true); }
void Group_SetTaskAttackEx(string sGroupID, string sAttackedGroup, bool bTaskBoth)
{
	ref rGroup = Group_FindOrCreateGroup(sGroupID);

	rGroup.Task = AITASK_ATTACK;
	rGroup.Task.Target = sAttackedGroup;

	if (bSeaActive) { AIAttack_GroupAttack(sGroupID, sAttackedGroup, bTaskBoth); }
}

// Task: Move
void Group_SetTaskMove(string sGroupID, float x, float z)
{
	ref rGroup = Group_FindOrCreateGroup(sGroupID);
	rGroup.Task = AITASK_MOVE;
	rGroup.Task.Target = "";
	rGroup.Task.Target.Pos.x = x;
	rGroup.Task.Target.Pos.y = 0.0;
	rGroup.Task.Target.Pos.z = z;

	int iIndex = 0;
	while (true)
	{
		int iCharacterIndex = Group_GetCharacterIndexR(rGroup, iIndex);
		if (iCharacterIndex < 0) { break; }
		iIndex++;
		Ship_SetTaskMove(SECONDARY_TASK,iCharacterIndex,x,z);
	}
}

// Task: Reset to none
void Group_SetTaskNone(string sGroupID)
{
	ref rGroup = Group_FindOrCreateGroup(sGroupID);

	rGroup.Task = AITASK_NONE;
	rGroup.Task.Target = "";
	rGroup.Task.Lock = false;
}

void Group_CheckTask()
{
	string sGroupID = GetEventData();
	if (sGroupID == PLAYER_GROUP) { return; }
	ref rGroup = Group_GetGroupByID(sGroupID);
	switch (sti(rGroup.Task))
	{
		case AITASK_ATTACK:
			AIAttack_CheckTask(sGroupID);
		break;
	}
}
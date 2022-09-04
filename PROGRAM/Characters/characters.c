
#include "characters\characters_ai.c"
#include "characters\characters_events.c"
#include "characters\characters_login.c"
#include "characters\characters_face.c"
#include "characters\characters.h"
#include "characters\characterUtilite.c"


object chrFindNearCharacters[32];
bool isBoardingLoading = false;


void CharactersInit()
{
    if(LoadSegment("characters\Characters_tables.c"))
	{
		InitCharactersTables();
		UnloadSegment("characters\Characters_tables.c");
	}
	ReloadProgressUpdate();

	string sPath = "characters\" + LanguageGetLanguage() + "\";
	LoadSegment(sPath + "init\FalaiseDeFleur.c");		ReloadProgressUpdate();
	LoadSegment(sPath + "init\Redmond.c");				ReloadProgressUpdate();
	LoadSegment(sPath + "init\IslaMuelle.c");			ReloadProgressUpdate();
	LoadSegment(sPath + "init\Oxbay.c");				ReloadProgressUpdate();
	LoadSegment(sPath + "init\Conceicao.c");			ReloadProgressUpdate();
	LoadSegment(sPath + "init\Douwesen.c");				ReloadProgressUpdate();
	LoadSegment(sPath + "init\officers.c");				ReloadProgressUpdate();
	LoadSegment(sPath + "init\StoryCharacters.c");		ReloadProgressUpdate();
	LoadSegment(sPath + "init\TempQuestCharacters.c");	ReloadProgressUpdate();
	LoadSegment(sPath + "init\Other.c");				ReloadProgressUpdate();
	LoadSegment(sPath + "init\QuebradasCostillas.c");	ReloadProgressUpdate();
	LoadSegment(sPath + "init\TempQuestEnemy.c");		ReloadProgressUpdate();
	LoadSegment(sPath + "init\FortCommandants.c");		ReloadProgressUpdate();
	LoadSegment(sPath + "init\Usurers.c");				ReloadProgressUpdate();
	LoadSegment(sPath + "init\Item Traders.c");			ReloadProgressUpdate();
	if(LoadSegment(sPath + "characters_init.c"))
	{
		CreateCharacters();
		UnloadSegment(sPath + "characters_init.c");
	}
	ReloadProgressUpdate();
	UnloadSegment(sPath + "init\FalaiseDeFleur.c");
	UnloadSegment(sPath + "init\Redmond.c");
	UnloadSegment(sPath + "init\IslaMuelle.c");
	UnloadSegment(sPath + "init\Oxbay.c");
	UnloadSegment(sPath + "init\Conceicao.c");
	UnloadSegment(sPath + "init\Douwesen.c");
	UnloadSegment(sPath + "init\officers.c");
	UnloadSegment(sPath + "init\StoryCharacters.c");
	UnloadSegment(sPath + "init\TempQuestCharacters.c");
	UnloadSegment(sPath + "init\Other.c");
	UnloadSegment(sPath + "init\QuebradasCostillas.c");
	UnloadSegment(sPath + "init\TempQuestEnemy.c");
	UnloadSegment(sPath + "init\FortCommandants.c");
	UnloadSegment(sPath + "init\Usurers.c");
	UnloadSegment(sPath + "init\Item Traders.c");

	ReloadProgressUpdate();
	InitCharacterEvents();
	ReloadProgressUpdate();
	LAi_NewGame();
}

bool CreateCharacter(ref character)
{
	CreateEntity(&character, character.model.entity);
	if(!SendMessage(character, "lss", MSG_CHARACTER_SETMODEL, character.model, character.model.animation))
	{
		Trace("CreateCharacter -> character can invalide model("+ character.model +") or animation(" + character.model.animation + ")");
		DeleteClass(&character);
		return false;
	}

	ExecuteCharacterEquip(character);

	//Set fight level
	float fgtlevel = 0.0;
	if(isBoardingLoading == false)
	{
		if(CheckAttribute(character, "skill.Fencing") != 0)
		{
			fgtlevel = stf(character.skill.Fencing);
		}
	}else{
		fgtlevel = GetSummonSkillFromName(character, SKILL_FENCING);
	}
	if(fgtlevel < 0.0) fgtlevel = 0.0;
	if(fgtlevel > SKILL_MAX) fgtlevel = SKILL_MAX;
	fgtlevel = fgtlevel/SKILL_MAX;
	SendMessage(character, "lf", MSG_CHARACTER_SETFTGLEVEL, fgtlevel);
	//Set character sex
	SendMessage(character, "lsl", MSG_CHARACTER_EX_MSG, "SetSex", character.sex == "man");
	//
	AddCharacterLocatorGroup(character, "goto");
	BeginChangeCharacterActions(character);
	SetDefaultFight(character);
	EndChangeCharacterActions(character);
	return true;
}

bool DeleteCharacter(ref character)
{
	DeleteClass(character);
	return true;
}

bool TeleportCharacterToPos(ref character, float x, float y, float z)
{
	return SendMessage(character, "lfff", MSG_CHARACTER_TELEPORT, x, y, z);
}

bool TeleportCharacterToPosAy(ref character, float x, float y, float z, float ay)
{
	return SendMessage(character, "lffff", MSG_CHARACTER_TELEPORT_AY, x, y, z, ay);
}

bool TeleportCharacterToLocator(ref character, string group, string locator)
{
	return SendMessage(character, "lss", MSG_CHARACTER_TELEPORT_TO_LOCATOR, group, locator);
}

bool CheckLocationPosition(ref location, float x, float y, float z)
{
	if(IsEntity(loadedLocation) == false) return false;
	return (SendMessage(loadedLocation, "lfff", MSG_LOCATION_CHECKENTRY, x, y, z) != 0);
}

object GetCharacterModel(ref character)
{
	object model;
	SendMessage(character, "le", MSG_CHARACTER_GETMODEL, &model);
	return model;
}

bool GetCharacterPos(ref character, ref float_x, ref float_y, ref float_z)
{
	float cx, cy, cz;
	if(SendMessage(character, "leee", MSG_CHARACTER_GETPOS, &cx, &cy, &cz) == 0) return false;
	float_x = cx; float_y = cy; float_z = cz;
	return true;
}

bool GetCharacterAy(ref character, ref float_ay)
{
	float ay = 0.0;
	if(SendMessage(character, "le", MSG_CHARACTER_GETAY, &ay) == 0) return false;
	float_ay = ay;
	return true;
}

bool PushCharacterAy(ref character)
{
	return SendMessage(character, "l", MSG_CHARACTER_TURNPUSH);
}

bool PopCharacterAy(ref character)
{
	return SendMessage(character, "l", MSG_CHARACTER_TURNPOP);
}

int FindNearCharacters(ref character, float rad, float ax, float testAng, float nearDist, bool isVisibleTest, bool isSort)
{
	int num = 0;
	SendMessage(character, "leeffffll", MSG_CHARACTER_FINDNEAR, &chrFindNearCharacters, &num, rad, ax, testAng, nearDist, isVisibleTest, isSort);
	return num;
}

bool CharactersVisibleTest(ref character, ref lookTo)
{
	return SendMessage(character, "li", MSG_CHARACTER_VISIBLE, lookTo);
}

//
void BeginChangeCharacterActions(ref character)
{
	DeleteAttribute(character, "actions");
}

//
void EndChangeCharacterActions(ref character)
{
	character.actions = "";
}

//Character is stay where play idle animation
void SetDefaultStayIdle(ref character)
{
	character.actions.idle.i1 = "idle_1";
	character.actions.idle.i2 = "idle_2";
	character.actions.idle.i3 = "idle_3";
	character.actions.idle.i4 = "idle_4";
	character.actions.idle.i5 = "idle_5";
	character.actions.idle.i6 = "idle_6";
	character.actions.idle.i7 = "idle_7";
	character.actions.idle.i8 = "idle_8";
	character.actions.idle.i9 = "idle_9";
	character.actions.idle.i10 = "idle_10";
}

//Character is sit where play idle animation
void SetDefaultSitIdle(ref character)
{	
	character.actions.idle.i1 = "Sit_Look_Around";
	character.actions.idle.i2 = "Sit_Lower_head";
	character.actions.idle.i3 = "Sit_WaveFly";
	character.actions.idle.i5 = "Sit_Blew_1";
	character.actions.idle.i6 = "Sit_Blew_1";
	character.actions.idle.i7 = "Sit_Blew_1";
}

void SetDefaultNormWalk(ref character)
{
	character.actions.walk = "walk";
	character.actions.backwalk = "back walk";
	character.actions.run = "run";
	character.actions.backrun = "back run";
	character.actions.stsUp = "stairs up";
	character.actions.stsDown = "stairs down";
	character.actions.stsUpBack = "back stairs up";
	character.actions.stsDownBack = "back stairs down";
	character.actions.stsUpRun = "run stairs up";
	character.actions.stsDownRun = "run stairs down";
	character.actions.stsUpRunBack = "back run stairs up";
	character.actions.stsDownRunBack = "back run stairs down";
	character.actions.turnLeft = "turn left";
	character.actions.turnRight = "turn right";
	character.actions.swim = "swim";
}

void SetDefaultFight(ref character)
{
	//Действия в режиме боя
	character.actions.fightwalk = "fight walk";
	character.actions.fightbackwalk = "fight back walk";
	character.actions.fightrun = "fight run";
	character.actions.fightbackrun = "fight back run";

	character.actions.attack.a1 = "attack_1";
	character.actions.attack.a2 = "attack_2";
	character.actions.attack.a3 = "attack_3";
	character.actions.attack.a4 = "attack_4";
	character.actions.attack.a5 = "attack_5";
	character.actions.attack.a6 = "attack_6";
	character.actions.attack.a7 = "attack_7";
	character.actions.attack.a8 = "attack_8";

	character.actions.attacktl.a1 = "attack_left_1";

	character.actions.attacktr.a1 = "attack_right_1";

	character.actions.hit.h1 = "hit_1";
	character.actions.hit.h2 = "hit_2";
	character.actions.hit.h3 = "hit_3";

	character.actions.block = "block";
	character.actions.blockhit = "block_hit";
	character.actions.recoil = "Recoil";
	character.actions.shot = "Shot";

	SetDefaultFightDead(character);

	//Idle анимация в режиме боя
	character.actions.fightidle.i1 = "fight stand_1";
	character.actions.fightidle.i2 = "fight stand_2";
	character.actions.fightidle.i3 = "fight stand_3";
	character.actions.fightidle.i4 = "fight stand_4";

}

void SetDefaultDead(ref character)
{
	character.actions.dead.d1 = "death_citizen_1";
	character.actions.dead.d2 = "death_citizen_2";
}

void SetDefaultSitDead(ref character)
{
	character.actions.dead.d1 = "Sit_Death";
}

void SetAfraidDead(ref character)
{
	character.actions.dead.d1 = "death_afraid_1";
	character.actions.dead.d2 = "death_afraid_2";

}

void SetDefaultFightDead(ref character)
{
	character.actions.fightdead.d1 = "death_0";
	character.actions.fightdead.d2 = "death_1";
	character.actions.fightdead.d3 = "death_2";
	character.actions.fightdead.d4 = "death_3";
}

void SetHuberAnimation(ref character)
{
	character.actions.idle.i1 = "Gov_ObserveHands";
	character.actions.idle.i2 = "Gov_LegOnLeg";
	character.actions.idle.i3 = "Gov_Look_Around";
	character.actions.idle.i4 = "Gov_think_1";
	character.actions.idle.i5 = "Gov_think_2";
}


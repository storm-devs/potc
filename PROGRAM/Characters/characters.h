#define CHARACTER_NOTUSED_NAME	"Noname"
#define BASE_CHARACTER_ONE 0
#define BASE_CHARACTER_TWO 1

#define MORALE_MAX		99
#define MORALE_NORMAL   45
#define MORALE_MIN		0
#define MORALE_TABLE_SIZE	10
#define MORALET_TREACHEROUS	0	//Ужасная
#define MORALET_AWFUL		1	//Отвратительная
#define MORALET_LOW			2	//Плохая
#define MORALET_POOR		3	//Низкая
#define MORALET_NORMAL		4	//Средняя
#define MORALET_ELATED		5	//Приподнятая
#define MORALET_GOOD		6	//Хорошая
#define MORALET_HIGH		7	//Высокая
#define MORALET_EXCELLENT	8	//Отличная
#define MORALET_HEROIC		9	//Героическая
string  MoraleTable[MORALE_TABLE_SIZE];

#define REPUTATION_MIN          1
#define REPUTATION_NEUTRAL      45
#define REPUTATION_MAX          89
#define REPUTATION_TABLE_SIZE   9
#define REPUTATIONT_HORROR      0
#define REPUTATIONT_BASTARD     1
#define REPUTATIONT_SWINDLER    2
#define REPUTATIONT_RASCAL      3
#define REPUTATIONT_NEUTRAL     4
#define REPUTATIONT_PLAIN       5
#define REPUTATIONT_GOOD        6
#define REPUTATIONT_VERYGOOD    7
#define REPUTATIONT_HERO        8
string  ReputationTable[REPUTATION_TABLE_SIZE];

#define PASSENGERS_MAX	32
#define COMPANION_MAX	4

#define SKILL_MAX		10
#define SKILL_LEADERSHIP	"Leadership"
#define SKILL_FENCING		"Fencing"
#define SKILL_SAILING		"Sailing"
#define SKILL_ACCURACY		"Accuracy"
#define SKILL_CANNONS		"Cannons"
#define SKILL_GRAPPLING		"Grappling"
#define SKILL_REPAIR		"Repair"
#define SKILL_DEFENCE		"Defence"
#define SKILL_COMMERCE		"Commerce"
#define SKILL_SNEAK			"Sneak"

#define KILL_BY_BALL		1
#define KILL_BY_ABORDAGE	2
#define KILL_BY_SPY			3
#define KILL_BY_ISLAND		4
#define KILL_BY_TOUCH		5

#define FACETABLE_SIZE		32
object FaceDescribeTable[FACETABLE_SIZE];

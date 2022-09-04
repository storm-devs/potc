#include "Weather\Init\Common.c"
#include "Weather\Init\Day.c"
#include "Weather\Init\Evening.c"
#include "Weather\Init\Morning.c"
#include "Weather\Init\Night.c"
#include "Weather\Init\DayStorm.c"
#include "Weather\Init\Special.c"

int InitWeather()
{
	int n = 0;

	n = Whr_InitDay(n);
	n = Whr_InitEvening(n);
	n = Whr_InitMorning(n);
	n = Whr_InitNight(n);
	n = Whr_InitDayStorm(n);
	n = Whr_InitSpecial(n);

	Whr_InitCommon();

	Trace("Init weathers complete. " + n + " weathers found.");

	return n;
}

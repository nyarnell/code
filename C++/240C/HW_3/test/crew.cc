#ifndef CREW_CC
#define CREW_CC
#include "crew.h"

Crew::Crew()
{
	busy=false;
	en_route=false;
	mowing=false;
	busy_minutes=0;
	number=0;
	best_time_to_home = 0.0;
	best_time_to_lawn = 0.0;
	best_time_to_mow = 0.0;
};
#endif

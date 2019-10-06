#include "Game.hpp"

#include <ctime>
#include <iostream>
#include <sys/time.h>

unsigned long long	get_curr_time( void )
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	unsigned long long millisecondsSinceEpoch =
    (unsigned long long)(tv.tv_sec) * 1000 +
    (unsigned long long)(tv.tv_usec) / 1000;
	return (millisecondsSinceEpoch);
}


int		main()
{
	Game g = Game();

	g.mainloop();
	return (0);
}
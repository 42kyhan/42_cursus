#include "philosophers.h"

long long	get_time()
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return((time.tv_sec * 1000) + (time.tv_usec * 0.001));
}

long long	curr_time(long long time)
{
	if (time > 0)
		return (get_time() - time);
	return (0);
}
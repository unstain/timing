#include "timing.h"

void tic()
{
	if (tictoc_index < TICTOC_SIZE)
		clock_gettime(CLOCK_REALTIME, &tictoc_arr[tictoc_index++]);
}

/* elapsed_time = seconds ^ (-precision)) */
long vartoc(unsigned int precision)
{
	struct timespec now;
	long elapsed;
	
	clock_gettime(CLOCK_REALTIME, &now);
	if (tictoc_index > 0)
	{
		elapsed = (now.tv_sec - tictoc_arr[tictoc_index].tv_sec) * precision;
		elapsed += (now.tv_nsec - tictoc_arr[tictoc_index].tv_nsec) / (1000000000 / precision);
		tictoc_index--;
	}
	else
		elapsed = 0;

	return elapsed;
}

/* integer seconds elapsed since the last tic()*/
long toc()
{
	return vartoc(1);
}

/* integer milliseconds elapsed since the last tic() */
long mtoc()
{
	return vartoc(1000);
}

/* integer microseconds elapsed since the last tic() */
long utoc()
{
	return vartoc(1000000);
}

/* integer nanoseconds elapsed since the last tic() */
long ntoc()
{
	return vartoc(1000000000);
}

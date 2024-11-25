#include "iec_std_lib.h"

inline TOD* __pdate_and_time_to_time_of_day(DT *IN) {
	static TOD res;
	res.tv_sec = IN->tv_sec % SECONDS_PER_DAY + (IN->tv_sec < 0 ? SECONDS_PER_DAY : 0);
	res.tv_nsec = IN->tv_nsec;

	return &res;
}
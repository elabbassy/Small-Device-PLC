#include "iec_std_lib.h"

inline DATE* __pdate_and_time_to_date(DT *IN){
	static DATE res;
	res.tv_sec = IN->tv_sec - IN->tv_sec % SECONDS_PER_DAY - (IN->tv_sec < 0 ? SECONDS_PER_DAY : 0);
	res.tv_nsec = 0;
	return &res;
}
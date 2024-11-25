#include "iec_std_lib.h"

inline LINT __ptime_to_int(TIME *IN){
	return IN->tv_sec;
}
#include "iec_std_lib.h"

inline TIME*    __pint_to_time(LINT IN){
	static TIME res;
	res.tv_sec = IN;
	res.tv_nsec = 0;
	return &res;
}
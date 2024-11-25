#include "iec_std_lib.h"

inline TIME*   __preal_to_time(LREAL IN){
static TIME res;
res.tv_sec = IN;
res.tv_nsec = (IN - (LINT)IN) * 1000000000;
return &res;
}
#include "iec_std_lib.h"

inline ULINT __real_to_uint(LREAL IN) 
{
return (ULINT)__preal_to_uint(IN);
}
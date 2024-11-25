#include "iec_std_lib.h"

inline LWORD __real_to_bit(LREAL IN)  
{
return (LWORD)__preal_to_uint(IN);
}
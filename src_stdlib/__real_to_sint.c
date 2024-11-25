#include "iec_std_lib.h"

inline LINT __real_to_sint(LREAL IN)  
{
return (LINT)__preal_to_sint(IN);
}
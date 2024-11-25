#include "iec_std_lib.h"

inline LINT __preal_to_uint(LREAL IN) {
   return IN >= 0 ? __real_round(IN + 0.5) : 0;
}
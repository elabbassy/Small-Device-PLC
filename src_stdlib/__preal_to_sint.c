#include "iec_std_lib.h"

inline LINT __preal_to_sint(LREAL IN) {
   return IN >= 0 ? __real_round(IN + 0.5) : __real_round(IN - 0.5);
}
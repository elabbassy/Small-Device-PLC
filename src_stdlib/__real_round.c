#include "iec_std_lib.h"

inline LINT __real_round(LREAL IN) {
	return modff(IN, 1) == 0 ? ((LINT)IN / 2) * 2 : (LINT)IN;
}
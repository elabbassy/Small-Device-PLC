#include "iec_std_lib.h"

inline BOOL __test_bcd(LWORD IN) {
	while (IN) {
		if ((IN & 0xf) > 9) return 1;
		IN >>= 4;
	}
	return 0;
}
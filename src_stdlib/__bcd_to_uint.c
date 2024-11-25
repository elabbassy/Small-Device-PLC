#include "iec_std_lib.h"

inline ULINT __bcd_to_uint(LWORD IN){
    ULINT res = IN & 0xf;
    ULINT factor = 10ULL;

    while (IN >>= 4) {
        res += (IN & 0xf) * factor;
        factor *= 10;
    }
    return res;
}
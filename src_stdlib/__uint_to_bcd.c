#include "iec_std_lib.h"

inline LWORD __uint_to_bcd(ULINT IN){
    LWORD res = IN % 10;
    USINT shift = 4;

    while (IN /= 10) {
        res |= (IN % 10) << shift;
        shift += 4;
    }
    return res;
}
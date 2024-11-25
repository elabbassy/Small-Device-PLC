#include "iec_std_lib.h"

inline LREAL __ptime_to_real(TIME *IN){
    return (LREAL)IN->tv_sec + ((LREAL)IN->tv_nsec/1000000000);
}
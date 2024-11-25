#include "iec_std_lib.h"

/*******************************/
/* Time normalization function */
/*******************************/

inline void __normalize_timespec (IEC_TIMESPEC *ts) {
  if( ts->tv_nsec < -1000000000L || (( ts->tv_sec > 0 ) && ( ts->tv_nsec < 0 ))){
    ts->tv_sec--;
    ts->tv_nsec += 1000000000L;
  }
  if( ts->tv_nsec > 1000000000L || (( ts->tv_sec < 0 ) && ( ts->tv_nsec > 0 ))){
    ts->tv_sec++;
    ts->tv_nsec -= 1000000000;
  }
}
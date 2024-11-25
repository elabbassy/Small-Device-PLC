#include "iec_std_lib.h"

/* NOTE: The following function was turned into a macro, so it could be used to initialize the initial value of TOD (TIME_OF_DAY) variables */
/* NOTE: many (but not all) of the same comments made regarding __time_to_timespec() are also valid here, so go and read those comments too!*/
inline IEC_TIMESPEC* __ptod_to_timespec(double seconds, double minutes, double hours) {
  static IEC_TIMESPEC ts;

  long double total_sec = (hours*60 + minutes)*60 + seconds;
  ts.tv_sec = (long int)total_sec;
  ts.tv_nsec = (long int)((total_sec - ts.tv_sec)*1e9);

  return &ts;
}

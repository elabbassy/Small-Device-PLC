#include "iec_std_lib.h"

inline IEC_TIMESPEC* __ptime_to_timespec(int sign, double mseconds, double seconds, double minutes, double hours, double days) {
  static IEC_TIMESPEC ts;

  // sign is 1 for positive values, -1 for negative time...
  long double total_sec = ((days*24 + hours)*60 + minutes)*60 + seconds + mseconds/1e3;
  if (sign >= 0) sign = 1; else sign = -1;
  ts.tv_sec = sign * (long int)total_sec;
  ts.tv_nsec = sign * (long int)((total_sec - ts.tv_sec)*1e9);

  return &ts;
}
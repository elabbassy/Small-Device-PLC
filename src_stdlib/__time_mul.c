#include "iec_std_lib.h"

inline TIME* __ptime_mul(TIME *IN1, LREAL IN2){
  LREAL s_f = IN1->tv_sec * IN2;
  time_t s = (time_t)s_f;
  div_t ns;
  ns  = div((long)((LREAL)IN1->tv_nsec * IN2), 1000000000); 
  static TIME res;
  res.tv_sec  = (long)s + ns.quot;
  res.tv_nsec = (long)ns.rem + (long)((s_f - (LREAL)s) * 1000000000) ;
  __normalize_timespec(&res);
  return &res;
}
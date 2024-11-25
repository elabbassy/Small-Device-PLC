#include "iec_std_lib.h"

inline TIME* __ptime_div(TIME *IN1, LREAL IN2){
  LREAL s_f = IN1->tv_sec / IN2;
  time_t s = (time_t)s_f;
  static TIME res = {(long)s,
              (long)(IN1->tv_nsec / IN2 + (s_f - s) * 1000000000) };
  __normalize_timespec(&res);
  return &res;
}
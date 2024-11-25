#include "iec_std_lib.h"

inline TIME* __ptime_add(TIME *IN1, TIME *IN2){
  static TIME res;
  res.tv_sec  = IN1->tv_sec + IN2->tv_sec;
  res.tv_nsec  = IN1->tv_nsec + IN2->tv_nsec;
  __normalize_timespec(&res);
  return &res;
}
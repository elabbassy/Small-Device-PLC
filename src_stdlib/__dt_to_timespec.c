#include "iec_std_lib.h"

inline IEC_TIMESPEC* __pdt_to_timespec(double seconds, double minutes, double hours, int day, int month, int year) {
  IEC_TIMESPEC ts_date;
  ts_date = __date_to_timespec(day, month, year);
  static IEC_TIMESPEC ts;
  ts = __tod_to_timespec(seconds, minutes, hours);
  ts.tv_sec += ts_date.tv_sec;

  return &ts;
}
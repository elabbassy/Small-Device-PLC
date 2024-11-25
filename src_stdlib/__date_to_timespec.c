#include "iec_std_lib.h"
static const __code unsigned short int __mon_yday[2][13] =
{
  /* Normal years.  */
  { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365},
  /* Leap years.  */
  { 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366}
};

inline IEC_TIMESPEC* __pdate_to_timespec(int day, int month, int year) {
  static IEC_TIMESPEC ts;
  int a4, b4, a100, b100, a400, b400;
  int yday;
  int intervening_leap_days;

  if (month < 1 || month > 12)
	 __iec_error();

  yday = __mon_yday[__isleap(year)][month - 1] + day;

  if (yday > __mon_yday[__isleap(year)][month])
	  __iec_error();

  a4 = (year >> 2) - ! (year & 3);
  b4 = (EPOCH_YEAR >> 2) - ! (EPOCH_YEAR & 3);
  a100 = a4 / 25 - (a4 % 25 < 0);
  b100 = b4 / 25 - (b4 % 25 < 0);
  a400 = a100 >> 2;
  b400 = b100 >> 2;
  intervening_leap_days = (a4 - b4) - (a100 - b100) + (a400 - b400);
  
  ts.tv_sec = ((year - EPOCH_YEAR) * 365 + intervening_leap_days + yday - 1) * 24 * 60 * 60;
  ts.tv_nsec = 0;

  return &ts;
}
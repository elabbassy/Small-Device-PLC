#include "iec_std_lib.h"


const __code unsigned short int __mon_yday[2][13] =
{
  /* Normal years.  */
  { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365},
  /* Leap years.  */
  { 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366}
};


inline tm1* pconvert_seconds_to_date_and_time(long int seconds) {
  static tm1 dt;
  long int days, rem;
  days = seconds / SECONDS_PER_DAY;
  rem = seconds % SECONDS_PER_DAY;
  if (rem < 0) {
	  rem += SECONDS_PER_DAY;
	  days--;
  }

  // time of day
  dt.tm_hour = rem / SECONDS_PER_HOUR;
  rem %= SECONDS_PER_HOUR;
  dt.tm_min = rem / 60;
  dt.tm_sec = rem % 60;

  // date
  dt.tm_year = EPOCH_YEAR;
  while (days >= (rem = __isleap(dt.tm_year) ? 366 : 365)) {
	  dt.tm_year++;
	  days -= rem;
  }
  while (days < 0) {
	  dt.tm_year--;
	  days += __isleap(dt.tm_year) ? 366 : 365;
  }
  dt.tm_mon = 1;
  while (days >= __mon_yday[__isleap(dt.tm_year)][dt.tm_mon]) {
	  dt.tm_mon += 1;
  }
  dt.tm_day = days - __mon_yday[__isleap(dt.tm_year)][dt.tm_mon - 1] + 1;

  return &dt;
}
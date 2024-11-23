
#include <iec_std_lib.h>


inline TIME* pDIVTIME_LREAL(BOOL EN, BOOL *ENO, TIME *IN1, LREAL IN2){
static TIME res;
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  res.tv_sec  = 0;
  res.tv_nsec = 0;
  return &res;//__INIT_TIME;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);
 
  
  LREAL s_f = (LREAL) (IN1->tv_sec / IN2);
  time_t s = (time_t)s_f;
  res.tv_sec = (long)s;
  res.tv_nsec = (long)(IN1->tv_nsec / IN2 + (s_f - s) * 1000000000);
  __normalize_timespec(&res);
  return &res; 
}
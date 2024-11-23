
#include <iec_std_lib.h>


inline DT* pCONCAT_DATE_TOD(BOOL EN, BOOL *ENO, DATE *IN1, TOD *IN2){
static DT res; 
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  res.tv_sec  = 0;
  res.tv_nsec = 0;
  return &res;//__INIT_DT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);
  
  res.tv_sec = IN1->tv_sec + IN2->tv_sec;
  res.tv_nsec = IN1->tv_nsec + IN2->tv_nsec;
  __normalize_timespec(&res);
  return &res;
}
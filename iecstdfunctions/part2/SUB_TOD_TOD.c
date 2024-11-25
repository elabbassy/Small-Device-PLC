#include <iec_std_lib.h>


/* explicitly typed function */
inline TIME* pSUB_TOD_TOD(BOOL EN, BOOL *ENO, TOD *IN1, TOD *IN2){
static TIME res;
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  res.tv_sec = 0;
  res.tv_nsec = 0;
  return &res;//__INIT_TIME;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  //return __time_sub(IN1, IN2);
  res.tv_sec = IN1->tv_sec - IN2->tv_sec;
  res.tv_nsec = IN1->tv_nsec - IN2->tv_nsec;
             
  __normalize_timespec(&res);
  return &res;
}
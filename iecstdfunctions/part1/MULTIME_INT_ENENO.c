
#include <iec_std_lib.h>


inline TIME* pMULTIME_INT(BOOL EN, BOOL *ENO, TIME *IN1, INT IN2){
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
 

LREAL s_f = (LREAL) (IN1->tv_sec * IN2);
time_t s = (time_t)s_f;
div_t ns;
ns  = div((int)((LREAL)IN1->tv_nsec * IN2), 1000000000);
res.tv_sec  = (long)s + ns.quot;
res.tv_nsec = (long)ns.rem + (long)((s_f - (LREAL)s) * 1000000000) ;
__normalize_timespec(&res);
return &res;  
}
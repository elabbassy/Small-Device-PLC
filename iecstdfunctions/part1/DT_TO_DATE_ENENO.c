
#include <iec_std_lib.h>


inline DATE* pDT_TO_DATE(BOOL EN, BOOL *ENO, DT *op){
static DATE res; 
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  res.tv_sec = 0;
  res.tv_nsec = 0;
  return &res;//__INIT_DATE;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

// __date_and_time_to_date(op);
res.tv_sec = op->tv_sec - op->tv_sec % SECONDS_PER_DAY - (op->tv_sec < 0 ? SECONDS_PER_DAY : 0);
res.tv_nsec = 0;
return &res;
}

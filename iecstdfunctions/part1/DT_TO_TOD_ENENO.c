
#include <iec_std_lib.h>


inline TOD* pDT_TO_TOD(BOOL EN, BOOL *ENO, DT *op){
static TOD res; 
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  res.tv_sec = 0;
  res.tv_nsec = 0;
  return &res;//__INIT_TOD;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

// __date_and_time_to_date(op);
res.tv_sec = op->tv_sec - op->tv_sec % SECONDS_PER_DAY - (op->tv_sec < 0 ? SECONDS_PER_DAY : 0);
res.tv_nsec = 0;
return &res;
}

#include <iec_std_lib.h>


inline DATE* pDATE_TO_DATE(BOOL EN, BOOL *ENO, DATE *op){
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
  res = *op;
  return &res;//(DATE) __move_DATE(op);
}


#include <iec_std_lib.h>


inline TIME* pTIME_TO_TIME(BOOL EN, BOOL *ENO, TIME *op){
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
  res = *op;
  return &res;//(TIME) __move_TIME(op);
}

#include <iec_std_lib.h>


inline TOD* pTOD_TO_TOD(BOOL EN, BOOL *ENO, TOD *op){
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
  res = *op;
  return &res;//(TOD) __move_TOD(op);
}

#include <iec_std_lib.h>


inline DT* pDT_TO_DT(BOOL EN, BOOL *ENO, DT *op){
static DT res;
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  res.tv_sec = 0;
  res.tv_nsec = 0;
  return &res;//__INIT_DT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);
  res = *op;
  return &res;//(DT) __move_DT(op);
}

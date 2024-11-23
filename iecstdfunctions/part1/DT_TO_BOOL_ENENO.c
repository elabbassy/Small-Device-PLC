
#include <iec_std_lib.h>


inline BOOL pDT_TO_BOOL(BOOL EN, BOOL *ENO, DT *op){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_BOOL;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return op->tv_sec == 0 && op->tv_nsec == 0 ? 0 : 1;
}

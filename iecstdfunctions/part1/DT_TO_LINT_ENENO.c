
#include <iec_std_lib.h>


inline LINT pDT_TO_LINT(BOOL EN, BOOL *ENO, DT *op){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_LINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  //time_to_int(op)
  return (LINT) op->tv_sec;
}

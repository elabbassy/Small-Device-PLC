
#include <iec_std_lib.h>


inline UDINT pDT_TO_UDINT(BOOL EN, BOOL *ENO, DT *op){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_UDINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  //time_to_int(op)
  return (UDINT) op->tv_sec;
}

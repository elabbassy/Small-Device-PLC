
#include <iec_std_lib.h>


inline UINT pTIME_TO_UINT(BOOL EN, BOOL *ENO, TIME *op){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_UINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  //time_to_int(op)
  return (UINT) op->tv_sec;
}

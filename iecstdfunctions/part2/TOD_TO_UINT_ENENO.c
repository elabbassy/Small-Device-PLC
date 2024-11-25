
#include <iec_std_lib.h>


inline UINT pTOD_TO_UINT(BOOL EN, BOOL *ENO, TOD *op){
  
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

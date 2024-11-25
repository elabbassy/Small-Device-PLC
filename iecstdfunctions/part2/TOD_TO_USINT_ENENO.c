
#include <iec_std_lib.h>


inline USINT pTOD_TO_USINT(BOOL EN, BOOL *ENO, TOD *op){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_USINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  //time_to_int(op)
  return (USINT) op->tv_sec;
}

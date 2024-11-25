
#include <iec_std_lib.h>


inline REAL pTIME_TO_REAL(BOOL EN, BOOL *ENO, TIME *op){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_REAL;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  //time_to_real(op)
  return (REAL)op->tv_sec + ((REAL)op->tv_nsec/1000000000);
}

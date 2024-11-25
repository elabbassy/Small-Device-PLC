
#include <iec_std_lib.h>


inline LREAL pTIME_TO_LREAL(BOOL EN, BOOL *ENO, TIME *op){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_LREAL;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  //time_to_real(op)
  return (LREAL)op->tv_sec + ((LREAL)op->tv_nsec/1000000000);
}

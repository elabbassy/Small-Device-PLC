
#include <iec_std_lib.h>


inline BOOL pNE_TOD(BOOL EN, BOOL *ENO, TOD *op1, TOD *op2){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_BOOL;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);
 
  return __ptime_cmp(op1, op2) != 0 ? 1 : 0;   
}

#include <iec_std_lib.h>


inline BOOL pNE_DATE(BOOL EN, BOOL *ENO, DATE *op1, DATE *op2){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_BOOL;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);
 
return __ptime_cmp(op1, op2) != 0 ? 1 : 0;   
}
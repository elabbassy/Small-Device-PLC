
#include <iec_std_lib.h>

//changed from varadiac to static function with two (2) arguments only 
inline BOOL pEQ_DT(BOOL EN, BOOL *ENO, DT *op1, DT *op2){

if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_BOOL;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

return __ptime_cmp(op1, op2) == 0 ? 1 : 0; 
}

#include <iec_std_lib.h>


inline BOOL NE__BOOL__REAL__REAL(BOOL EN, BOOL *ENO, REAL op1, REAL op2){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_BOOL;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);
 
  return op1 != op2 ? 1 : 0;          
}
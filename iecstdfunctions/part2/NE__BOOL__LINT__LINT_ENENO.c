
#include <iec_std_lib.h>


inline BOOL NE__BOOL__LINT__LINT(BOOL EN, BOOL *ENO, LINT op1, LINT op2){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_BOOL;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);
 
  return op1 != op2 ? 1 : 0;          
}
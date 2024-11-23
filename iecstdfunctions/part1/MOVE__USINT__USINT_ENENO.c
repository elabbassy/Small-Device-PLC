
#include <iec_std_lib.h>


/* Overloaded function */
inline USINT MOVE__USINT__USINT(BOOL EN, BOOL *ENO, USINT op1){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_USINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return op1;
}
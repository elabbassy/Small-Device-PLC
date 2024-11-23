
#include <iec_std_lib.h>


/* Overloaded function */
inline ULINT MOVE__ULINT__ULINT(BOOL EN, BOOL *ENO, ULINT op1){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_ULINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return op1;
}
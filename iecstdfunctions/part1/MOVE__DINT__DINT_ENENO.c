
#include <iec_std_lib.h>


/* Overloaded function */
inline DINT MOVE__DINT__DINT(BOOL EN, BOOL *ENO, DINT op1){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_DINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return op1;
}
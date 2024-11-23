
#include <iec_std_lib.h>


/* Overloaded function */
inline LINT MOVE__LINT__LINT(BOOL EN, BOOL *ENO, LINT op1){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_LINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return op1;
}
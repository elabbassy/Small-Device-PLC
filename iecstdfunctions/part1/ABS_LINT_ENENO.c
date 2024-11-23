
#include <iec_std_lib.h>


/* explicitly typed function */
inline LINT ABS_LINT(BOOL EN, BOOL *ENO, LINT op){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_LINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  if (op < 0)
    return -op;
  return op;
}
/* overloaded function */
inline LINT ABS__LINT__LINT(BOOL EN, BOOL *ENO, LINT op){
  return ABS_LINT(EN, ENO, op);
}
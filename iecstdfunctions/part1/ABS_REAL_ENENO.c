
#include <iec_std_lib.h>


/* explicitly typed function */
inline REAL ABS_REAL(BOOL EN, BOOL *ENO, REAL op){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_REAL;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  if (op < 0)
    return -op;
  return op;
}
/* overloaded function */
inline REAL ABS__REAL__REAL(BOOL EN, BOOL *ENO, REAL op){
  return ABS_REAL(EN, ENO, op);
}
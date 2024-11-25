
#include <iec_std_lib.h>


/* explicitly typed function */
inline REAL SQRT_REAL(BOOL EN, BOOL *ENO, REAL op){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_REAL;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return sqrtf(op);
}
/* overloaded function */
inline REAL SQRT__REAL__REAL(BOOL EN, BOOL *ENO, REAL op){
  return SQRT_REAL(EN, ENO, op);
}
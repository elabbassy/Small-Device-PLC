
#include <iec_std_lib.h>


/* explicitly typed function */
inline REAL ATAN_REAL(BOOL EN, BOOL *ENO, REAL op){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_REAL;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return atanf(op);
}
/* overloaded function */
inline REAL ATAN__REAL__REAL(BOOL EN, BOOL *ENO, REAL op){
  return ATAN_REAL(EN, ENO, op);
}
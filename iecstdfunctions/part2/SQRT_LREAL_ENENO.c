
#include <iec_std_lib.h>


/* explicitly typed function */
inline LREAL SQRT_LREAL(BOOL EN, BOOL *ENO, LREAL op){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_LREAL;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return sqrtf(op);
}
/* overloaded function */
inline LREAL SQRT__LREAL__LREAL(BOOL EN, BOOL *ENO, LREAL op){
  return SQRT_LREAL(EN, ENO, op);
}
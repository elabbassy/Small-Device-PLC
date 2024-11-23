
#include <iec_std_lib.h>


/* explicitly typed function */
inline LREAL ACOS_LREAL(BOOL EN, BOOL *ENO, LREAL op){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_LREAL;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return acosf(op);
}
/* overloaded function */
inline LREAL ACOS__LREAL__LREAL(BOOL EN, BOOL *ENO, LREAL op){
  return ACOS_LREAL(EN, ENO, op);
}
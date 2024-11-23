
#include <iec_std_lib.h>


/* explicitly typed function */
inline LREAL LOG_LREAL(BOOL EN, BOOL *ENO, LREAL op){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_LREAL;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return log10f(op);
}
/* overloaded function */
inline LREAL LOG__LREAL__LREAL(BOOL EN, BOOL *ENO, LREAL op){
  return LOG_LREAL(EN, ENO, op);
}
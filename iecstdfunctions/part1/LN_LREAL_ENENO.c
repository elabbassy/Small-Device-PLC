
#include <iec_std_lib.h>


/* explicitly typed function */
inline LREAL LN_LREAL(BOOL EN, BOOL *ENO, LREAL op){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_LREAL;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return logf(op);
}
/* overloaded function */
inline LREAL LN__LREAL__LREAL(BOOL EN, BOOL *ENO, LREAL op){
  return LN_LREAL(EN, ENO, op);
}
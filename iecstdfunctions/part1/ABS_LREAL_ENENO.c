
#include <iec_std_lib.h>


/* explicitly typed function */
inline LREAL ABS_LREAL(BOOL EN, BOOL *ENO, LREAL op){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_LREAL;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  if (op < 0)
    return -op;
  return op;
}
/* overloaded function */
inline LREAL ABS__LREAL__LREAL(BOOL EN, BOOL *ENO, LREAL op){
  return ABS_LREAL(EN, ENO, op);
}
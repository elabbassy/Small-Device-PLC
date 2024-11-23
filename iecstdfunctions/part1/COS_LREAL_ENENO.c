
#include <iec_std_lib.h>


/* explicitly typed function */
inline LREAL COS_LREAL(BOOL EN, BOOL *ENO, LREAL op){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_LREAL;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return cosf(op);
}
/* overloaded function */
inline LREAL COS__LREAL__LREAL(BOOL EN, BOOL *ENO, LREAL op){
  return COS_LREAL(EN, ENO, op);
}

#include <iec_std_lib.h>


 /* overloaded function */ 
inline LINT EXPT__LINT__LINT__LREAL(BOOL EN, BOOL *ENO, LINT IN1,  LREAL IN2){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_LINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return __expt(IN1, IN2);
}
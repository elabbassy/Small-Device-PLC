
#include <iec_std_lib.h>


 /* overloaded function */ 
inline UDINT EXPT__UDINT__UDINT__LREAL(BOOL EN, BOOL *ENO, UDINT IN1,  LREAL IN2){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_UDINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return __expt(IN1, IN2);
}
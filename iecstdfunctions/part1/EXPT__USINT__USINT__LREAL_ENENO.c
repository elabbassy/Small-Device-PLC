
#include <iec_std_lib.h>


 /* overloaded function */ 
inline USINT EXPT__USINT__USINT__LREAL(BOOL EN, BOOL *ENO, USINT IN1,  LREAL IN2){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_USINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return __expt(IN1, IN2);
}
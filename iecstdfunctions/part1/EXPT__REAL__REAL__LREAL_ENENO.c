
#include <iec_std_lib.h>


 /* overloaded function */ 
inline REAL EXPT__REAL__REAL__LREAL(BOOL EN, BOOL *ENO, REAL IN1,  LREAL IN2){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_REAL;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return __expt(IN1, IN2);
}
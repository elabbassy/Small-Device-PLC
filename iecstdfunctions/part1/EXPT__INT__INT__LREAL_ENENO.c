
#include <iec_std_lib.h>


 /* overloaded function */ 
inline INT EXPT__INT__INT__LREAL(BOOL EN, BOOL *ENO, INT IN1,  LREAL IN2){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_INT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return __expt(IN1, IN2);
}
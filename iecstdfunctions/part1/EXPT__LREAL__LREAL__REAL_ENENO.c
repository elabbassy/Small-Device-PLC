
#include <iec_std_lib.h>


 /* overloaded function */ 
inline LREAL EXPT__LREAL__LREAL__REAL(BOOL EN, BOOL *ENO, LREAL IN1,  REAL IN2){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_LREAL;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return __expt(IN1, IN2);
}
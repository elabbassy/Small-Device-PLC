
#include <iec_std_lib.h>


 /* overloaded function */ 
inline ULINT EXPT__ULINT__ULINT__LREAL(BOOL EN, BOOL *ENO, ULINT IN1,  LREAL IN2){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_ULINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return __expt(IN1, IN2);
}

#include <iec_std_lib.h>


 /* overloaded function */ 
inline SINT EXPT__SINT__SINT__LREAL(BOOL EN, BOOL *ENO, SINT IN1,  LREAL IN2){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_SINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return __expt(IN1, IN2);
}
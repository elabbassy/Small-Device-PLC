
#include <iec_std_lib.h>


 /* overloaded function */ 
inline DINT EXPT__DINT__DINT__REAL(BOOL EN, BOOL *ENO, DINT IN1,  REAL IN2){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_DINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return __expt(IN1, IN2);
}
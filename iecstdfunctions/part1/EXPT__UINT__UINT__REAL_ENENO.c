
#include <iec_std_lib.h>


 /* overloaded function */ 
inline UINT EXPT__UINT__UINT__REAL(BOOL EN, BOOL *ENO, UINT IN1,  REAL IN2){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_UINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return __expt(IN1, IN2);
}
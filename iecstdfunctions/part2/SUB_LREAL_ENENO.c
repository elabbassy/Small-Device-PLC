
#include <iec_std_lib.h>


/* explicitly typed function */
inline LREAL SUB_LREAL(BOOL EN, BOOL *ENO, LREAL op1,  LREAL op2){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_LREAL;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return op1 - op2;
 }
 /* overloaded function */
inline LREAL SUB__LREAL__LREAL__LREAL(BOOL EN, BOOL *ENO, LREAL op1,  LREAL op2){
  return SUB_LREAL(EN, ENO, op1, op2);
}
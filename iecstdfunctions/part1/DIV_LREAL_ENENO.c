
#include <iec_std_lib.h>


/* The explicitly typed standard functions */
inline LREAL DIV_LREAL(BOOL EN, BOOL *ENO, LREAL op1, LREAL op2){
if (!EN || (op2 == 0)) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_LREAL;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);
return op1 / op2;
}
/* The overloaded standard functions */
inline LREAL DIV__LREAL__LREAL__LREAL(BOOL EN, BOOL *ENO, LREAL op1, LREAL op2){
    return DIV_LREAL(EN, ENO, op1, op2);
}

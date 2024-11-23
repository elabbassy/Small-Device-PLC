
#include <iec_std_lib.h>


/* The explicitly typed standard functions */
inline USINT DIV_USINT(BOOL EN, BOOL *ENO, USINT op1, USINT op2){
if (!EN || (op2 == 0)) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_USINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);
return op1 / op2;
}
/* The overloaded standard functions */
inline USINT DIV__USINT__USINT__USINT(BOOL EN, BOOL *ENO, USINT op1, USINT op2){
    return DIV_USINT(EN, ENO, op1, op2);
}

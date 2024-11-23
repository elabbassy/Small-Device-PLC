
#include <iec_std_lib.h>


/* The explicitly typed standard functions */
inline DINT DIV_DINT(BOOL EN, BOOL *ENO, DINT op1, DINT op2){
if (!EN || (op2 == 0)) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_DINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);
return op1 / op2;
}
/* The overloaded standard functions */
inline DINT DIV__DINT__DINT__DINT(BOOL EN, BOOL *ENO, DINT op1, DINT op2){
    return DIV_DINT(EN, ENO, op1, op2);
}

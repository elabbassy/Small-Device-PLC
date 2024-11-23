
#include <iec_std_lib.h>


/* The explicitly typed standard functions */
inline LINT DIV_LINT(BOOL EN, BOOL *ENO, LINT op1, LINT op2){
if (!EN || (op2 == 0)) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_LINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);
return op1 / op2;
}
/* The overloaded standard functions */
inline LINT DIV__LINT__LINT__LINT(BOOL EN, BOOL *ENO, LINT op1, LINT op2){
    return DIV_LINT(EN, ENO, op1, op2);
}

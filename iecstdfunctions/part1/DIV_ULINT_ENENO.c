
#include <iec_std_lib.h>


/* The explicitly typed standard functions */
inline ULINT DIV_ULINT(BOOL EN, BOOL *ENO, ULINT op1, ULINT op2){
if (!EN || (op2 == 0)) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_ULINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);
return op1 / op2;
}
/* The overloaded standard functions */
inline ULINT DIV__ULINT__ULINT__ULINT(BOOL EN, BOOL *ENO, ULINT op1, ULINT op2){
    return DIV_ULINT(EN, ENO, op1, op2);
}

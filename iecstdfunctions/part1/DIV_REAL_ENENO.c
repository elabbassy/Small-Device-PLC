
#include <iec_std_lib.h>


/* The explicitly typed standard functions */
inline REAL DIV_REAL(BOOL EN, BOOL *ENO, REAL op1, REAL op2){
if (!EN || (op2 == 0)) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_REAL;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);
return op1 / op2;
}
/* The overloaded standard functions */
inline REAL DIV__REAL__REAL__REAL(BOOL EN, BOOL *ENO, REAL op1, REAL op2){
    return DIV_REAL(EN, ENO, op1, op2);
}

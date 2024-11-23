
#include <iec_std_lib.h>


/* The explicitly typed standard functions */
inline UINT DIV_UINT(BOOL EN, BOOL *ENO, UINT op1, UINT op2){
if (!EN || (op2 == 0)) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_UINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);
return op1 / op2;
}
/* The overloaded standard functions */
inline UINT DIV__UINT__UINT__UINT(BOOL EN, BOOL *ENO, UINT op1, UINT op2){
    return DIV_UINT(EN, ENO, op1, op2);
}

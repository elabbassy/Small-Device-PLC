
#include <iec_std_lib.h>


/* The explicitly typed standard functions */
inline SINT DIV_SINT(BOOL EN, BOOL *ENO, SINT op1, SINT op2){
if (!EN || (op2 == 0)) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_SINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);
return op1 / op2;
}
/* The overloaded standard functions */
inline SINT DIV__SINT__SINT__SINT(BOOL EN, BOOL *ENO, SINT op1, SINT op2){
    return DIV_SINT(EN, ENO, op1, op2);
}

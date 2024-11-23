
#include <iec_std_lib.h>


/* The explicitly typed standard functions */
inline UDINT DIV_UDINT(BOOL EN, BOOL *ENO, UDINT op1, UDINT op2){
if (!EN || (op2 == 0)) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_UDINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);
return op1 / op2;
}
/* The overloaded standard functions */
inline UDINT DIV__UDINT__UDINT__UDINT(BOOL EN, BOOL *ENO, UDINT op1, UDINT op2){
    return DIV_UDINT(EN, ENO, op1, op2);
}

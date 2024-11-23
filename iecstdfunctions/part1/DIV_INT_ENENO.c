
#include <iec_std_lib.h>


/* The explicitly typed standard functions */
inline INT DIV_INT(BOOL EN, BOOL *ENO, INT op1, INT op2){
if (!EN || (op2 == 0)) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_INT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);
return op1 / op2;
}
/* The overloaded standard functions */
inline INT DIV__INT__INT__INT(BOOL EN, BOOL *ENO, INT op1, INT op2){
    return DIV_INT(EN, ENO, op1, op2);
}

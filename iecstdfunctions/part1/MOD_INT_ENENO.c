
#include <iec_std_lib.h>


/* explicitly typed function */
inline INT MOD_INT(BOOL EN, BOOL *ENO, INT op1,  INT op2){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_INT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  if (op2 == 0) return 0;
  return op1 % op2;
 }
 /* overloaded function */
inline INT MOD__INT__INT__INT(BOOL EN, BOOL *ENO, INT op1,  INT op2){
  return MOD_INT(EN, ENO, op1, op2);
}
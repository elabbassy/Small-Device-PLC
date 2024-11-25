
#include <iec_std_lib.h>


/* explicitly typed function */
inline LINT SUB_LINT(BOOL EN, BOOL *ENO, LINT op1,  LINT op2){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_LINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return op1 - op2;
 }
 /* overloaded function */
inline LINT SUB__LINT__LINT__LINT(BOOL EN, BOOL *ENO, LINT op1,  LINT op2){
  return SUB_LINT(EN, ENO, op1, op2);
}
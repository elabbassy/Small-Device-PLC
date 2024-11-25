
#include <iec_std_lib.h>


/* explicitly typed function */
inline REAL SUB_REAL(BOOL EN, BOOL *ENO, REAL op1,  REAL op2){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_REAL;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return op1 - op2;
 }
 /* overloaded function */
inline REAL SUB__REAL__REAL__REAL(BOOL EN, BOOL *ENO, REAL op1,  REAL op2){
  return SUB_REAL(EN, ENO, op1, op2);
}
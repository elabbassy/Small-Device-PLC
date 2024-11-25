
#include <iec_std_lib.h>


/* explicitly typed function */
inline ULINT SUB_ULINT(BOOL EN, BOOL *ENO, ULINT op1,  ULINT op2){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_ULINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return op1 - op2;
 }
 /* overloaded function */
inline ULINT SUB__ULINT__ULINT__ULINT(BOOL EN, BOOL *ENO, ULINT op1,  ULINT op2){
  return SUB_ULINT(EN, ENO, op1, op2);
}
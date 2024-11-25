
#include <iec_std_lib.h>


/* explicitly typed function */
inline DINT SUB_DINT(BOOL EN, BOOL *ENO, DINT op1,  DINT op2){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_DINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return op1 - op2;
 }
 /* overloaded function */
inline DINT SUB__DINT__DINT__DINT(BOOL EN, BOOL *ENO, DINT op1,  DINT op2){
  return SUB_DINT(EN, ENO, op1, op2);
}
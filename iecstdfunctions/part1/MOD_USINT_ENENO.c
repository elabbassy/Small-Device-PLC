
#include <iec_std_lib.h>


/* explicitly typed function */
inline USINT MOD_USINT(BOOL EN, BOOL *ENO, USINT op1,  USINT op2){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_USINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  if (op2 == 0) return 0;
  return op1 % op2;
 }
 /* overloaded function */
inline USINT MOD__USINT__USINT__USINT(BOOL EN, BOOL *ENO, USINT op1,  USINT op2){
  return MOD_USINT(EN, ENO, op1, op2);
}
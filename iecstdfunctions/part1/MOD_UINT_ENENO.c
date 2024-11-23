
#include <iec_std_lib.h>


/* explicitly typed function */
inline UINT MOD_UINT(BOOL EN, BOOL *ENO, UINT op1,  UINT op2){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_UINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  if (op2 == 0) return 0;
  return op1 % op2;
 }
 /* overloaded function */
inline UINT MOD__UINT__UINT__UINT(BOOL EN, BOOL *ENO, UINT op1,  UINT op2){
  return MOD_UINT(EN, ENO, op1, op2);
}
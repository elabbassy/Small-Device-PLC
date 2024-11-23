
#include <iec_std_lib.h>


/* explicitly typed function */
inline SINT MOD_SINT(BOOL EN, BOOL *ENO, SINT op1,  SINT op2){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_SINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  if (op2 == 0) return 0;
  return op1 % op2;
 }
 /* overloaded function */
inline SINT MOD__SINT__SINT__SINT(BOOL EN, BOOL *ENO, SINT op1,  SINT op2){
  return MOD_SINT(EN, ENO, op1, op2);
}
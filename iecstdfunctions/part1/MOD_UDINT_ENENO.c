
#include <iec_std_lib.h>


/* explicitly typed function */
inline UDINT MOD_UDINT(BOOL EN, BOOL *ENO, UDINT op1,  UDINT op2){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_UDINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  if (op2 == 0) return 0;
  return op1 % op2;
 }
 /* overloaded function */
inline UDINT MOD__UDINT__UDINT__UDINT(BOOL EN, BOOL *ENO, UDINT op1,  UDINT op2){
  return MOD_UDINT(EN, ENO, op1, op2);
}
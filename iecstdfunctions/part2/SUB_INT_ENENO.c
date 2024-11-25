
#include <iec_std_lib.h>


/* explicitly typed function */
inline INT SUB_INT(BOOL EN, BOOL *ENO, INT op1,  INT op2){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_INT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return op1 - op2;
 }
 /* overloaded function */
inline INT SUB__INT__INT__INT(BOOL EN, BOOL *ENO, INT op1,  INT op2){
  return SUB_INT(EN, ENO, op1, op2);
}
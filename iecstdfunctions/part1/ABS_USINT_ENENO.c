
#include <iec_std_lib.h>


/* explicitly typed function */
inline USINT ABS_USINT(BOOL EN, BOOL *ENO, USINT op){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_USINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return op;
}
/* overloaded function */
inline USINT ABS__USINT__USINT(BOOL EN, BOOL *ENO, USINT op){
  return ABS_USINT(EN, ENO,  op);
}
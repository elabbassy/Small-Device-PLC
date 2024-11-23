
#include <iec_std_lib.h>


/* explicitly typed function */
inline DINT ABS_DINT(BOOL EN, BOOL *ENO, DINT op){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_DINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  if (op < 0)
    return -op;
  return op;
}
/* overloaded function */
inline DINT ABS__DINT__DINT(BOOL EN, BOOL *ENO, DINT op){
  return ABS_DINT(EN, ENO, op);
}
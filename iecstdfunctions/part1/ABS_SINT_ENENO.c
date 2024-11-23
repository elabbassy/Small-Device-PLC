
#include <iec_std_lib.h>


/* explicitly typed function */
inline SINT ABS_SINT(BOOL EN, BOOL *ENO, SINT op){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_SINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  if (op < 0)
    return -op;
  return op;
}
/* overloaded function */
inline SINT ABS__SINT__SINT(BOOL EN, BOOL *ENO, SINT op){
  return ABS_SINT(EN, ENO, op);
}
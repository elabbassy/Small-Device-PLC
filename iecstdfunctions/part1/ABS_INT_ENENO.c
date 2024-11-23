
#include <iec_std_lib.h>


/* explicitly typed function */
inline INT ABS_INT(BOOL EN, BOOL *ENO, INT op){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_INT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  if (op < 0)
    return -op;
  return op;
}
/* overloaded function */
inline INT ABS__INT__INT(BOOL EN, BOOL *ENO, INT op){
  return ABS_INT(EN, ENO, op);
}
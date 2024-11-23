
#include <iec_std_lib.h>


/* Overloaded function */
inline INT MOVE__INT__INT(BOOL EN, BOOL *ENO, INT op1){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_INT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return op1;
}
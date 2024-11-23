
#include <iec_std_lib.h>


/* The explicitly typed standard functions */
inline INT MOVE_INT(BOOL EN, BOOL *ENO, INT op1){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_INT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return op1;
}
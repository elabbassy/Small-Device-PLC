
#include <iec_std_lib.h>


inline INT UDINT_TO_INT(BOOL EN, BOOL *ENO, UDINT op){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_INT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return (INT) __move_INT(op);
}

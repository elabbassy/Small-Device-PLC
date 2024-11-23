
#include <iec_std_lib.h>


/* The explicitly typed standard functions */
inline USINT MOVE_USINT(BOOL EN, BOOL *ENO, USINT op1){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_USINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return op1;
}
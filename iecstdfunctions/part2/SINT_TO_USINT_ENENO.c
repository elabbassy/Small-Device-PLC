
#include <iec_std_lib.h>


inline USINT SINT_TO_USINT(BOOL EN, BOOL *ENO, SINT op){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_USINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return (USINT) __move_USINT(op);
}

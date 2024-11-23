
#include <iec_std_lib.h>


/* The explicitly typed standard functions */
inline UDINT MOVE_UDINT(BOOL EN, BOOL *ENO, UDINT op1){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_UDINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return op1;
}
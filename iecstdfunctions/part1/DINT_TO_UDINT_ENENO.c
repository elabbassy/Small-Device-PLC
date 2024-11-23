
#include <iec_std_lib.h>


inline UDINT DINT_TO_UDINT(BOOL EN, BOOL *ENO, DINT op){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_UDINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return (UDINT) __move_UDINT(op);
}

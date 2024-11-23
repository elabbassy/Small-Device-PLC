
#include <iec_std_lib.h>


inline UDINT INT_TO_UDINT(BOOL EN, BOOL *ENO, INT op){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_UDINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return (UDINT) __move_UDINT(op);
}

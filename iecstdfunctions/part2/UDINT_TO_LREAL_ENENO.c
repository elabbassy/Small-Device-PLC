
#include <iec_std_lib.h>


inline LREAL UDINT_TO_LREAL(BOOL EN, BOOL *ENO, UDINT op){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_LREAL;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return (LREAL) __move_LREAL(op);
}
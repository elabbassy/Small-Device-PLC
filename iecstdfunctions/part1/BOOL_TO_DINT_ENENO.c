
#include <iec_std_lib.h>


inline DINT BOOL_TO_DINT(BOOL EN, BOOL *ENO, BOOL op){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_DINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return (DINT) __move_DINT(op);
}
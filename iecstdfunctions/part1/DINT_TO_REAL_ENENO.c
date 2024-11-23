
#include <iec_std_lib.h>


inline REAL DINT_TO_REAL(BOOL EN, BOOL *ENO, DINT op){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_REAL;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return (REAL) __move_REAL(op);
}

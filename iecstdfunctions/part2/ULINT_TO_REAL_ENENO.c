
#include <iec_std_lib.h>


inline REAL ULINT_TO_REAL(BOOL EN, BOOL *ENO, ULINT op){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_REAL;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return (REAL) __move_REAL(op);
}

#include <iec_std_lib.h>


inline REAL LINT_TO_REAL(BOOL EN, BOOL *ENO, LINT op){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_REAL;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return (REAL) __move_REAL(op);
}

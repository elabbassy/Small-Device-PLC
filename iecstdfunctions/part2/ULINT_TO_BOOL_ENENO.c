
#include <iec_std_lib.h>


inline BOOL ULINT_TO_BOOL(BOOL EN, BOOL *ENO, ULINT op){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_BOOL;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return op == 0 ? 0 : 1;
}

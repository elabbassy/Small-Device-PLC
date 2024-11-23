
#include <iec_std_lib.h>


/* The explicitly typed standard functions */
inline BOOL MOVE_BOOL(BOOL EN, BOOL *ENO, BOOL op1){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_BOOL;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return op1;
}
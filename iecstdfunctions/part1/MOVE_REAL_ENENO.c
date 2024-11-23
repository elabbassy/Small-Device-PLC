
#include <iec_std_lib.h>


/* The explicitly typed standard functions */
inline REAL MOVE_REAL(BOOL EN, BOOL *ENO, REAL op1){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_REAL;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return op1;
}

#include <iec_std_lib.h>


/* The explicitly typed standard functions */
inline DINT MOVE_DINT(BOOL EN, BOOL *ENO, DINT op1){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_DINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return op1;
}
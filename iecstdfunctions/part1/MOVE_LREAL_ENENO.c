
#include <iec_std_lib.h>


/* The explicitly typed standard functions */
inline LREAL MOVE_LREAL(BOOL EN, BOOL *ENO, LREAL op1){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_LREAL;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return op1;
}
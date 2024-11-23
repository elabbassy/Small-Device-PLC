
#include <iec_std_lib.h>


/* The explicitly typed standard functions */
inline LINT MOVE_LINT(BOOL EN, BOOL *ENO, LINT op1){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_LINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return op1;
}
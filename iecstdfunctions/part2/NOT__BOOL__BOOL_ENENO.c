
#include <iec_std_lib.h>


/* Overloaded function */
inline BOOL NOT__BOOL__BOOL(BOOL EN, BOOL *ENO, BOOL op1){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_BOOL;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return !op1;
}
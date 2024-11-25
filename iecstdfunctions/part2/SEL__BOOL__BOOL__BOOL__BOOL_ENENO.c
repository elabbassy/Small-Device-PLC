
#include <iec_std_lib.h>


/* Overloaded function */
inline BOOL SEL__BOOL__BOOL__BOOL__BOOL(BOOL EN, BOOL *ENO, BOOL G, BOOL op0, BOOL op1){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_BOOL;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return G ? op1 : op0;
}
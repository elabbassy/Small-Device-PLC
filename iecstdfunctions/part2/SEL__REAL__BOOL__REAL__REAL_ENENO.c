
#include <iec_std_lib.h>


/* Overloaded function */
inline REAL SEL__REAL__BOOL__REAL__REAL(BOOL EN, BOOL *ENO, BOOL G, REAL op0, REAL op1){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_REAL;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return G ? op1 : op0;
}
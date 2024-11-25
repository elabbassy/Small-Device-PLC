
#include <iec_std_lib.h>


/* Overloaded function */
inline UINT SEL__UINT__UINT(BOOL EN, BOOL *ENO, BOOL G, UINT op0, UINT op1){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_UINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return G ? op1 : op0;
}
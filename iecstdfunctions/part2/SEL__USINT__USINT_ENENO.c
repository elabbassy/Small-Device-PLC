
#include <iec_std_lib.h>


/* Overloaded function */
inline USINT SEL__USINT__USINT(BOOL EN, BOOL *ENO, BOOL G, USINT op0, USINT op1){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_USINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return G ? op1 : op0;
}

#include <iec_std_lib.h>


/* The explicitly typed standard functions */
inline USINT SEL_USINT(BOOL EN, BOOL *ENO, BOOL G, USINT op0, USINT op1){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_USINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return G ? op1 : op0;
}
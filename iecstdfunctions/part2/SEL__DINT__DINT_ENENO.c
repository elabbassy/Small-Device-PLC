
#include <iec_std_lib.h>


/* Overloaded function */
inline DINT SEL__DINT__DINT(BOOL EN, BOOL *ENO, BOOL G, DINT op0, DINT op1){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_DINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return G ? op1 : op0;
}
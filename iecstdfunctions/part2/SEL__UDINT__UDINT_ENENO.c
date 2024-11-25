
#include <iec_std_lib.h>


/* Overloaded function */
inline UDINT SEL__UDINT__UDINT(BOOL EN, BOOL *ENO, BOOL G, UDINT op0, UDINT op1){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_UDINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return G ? op1 : op0;
}
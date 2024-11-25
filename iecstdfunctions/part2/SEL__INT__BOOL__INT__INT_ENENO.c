
#include <iec_std_lib.h>


/* Overloaded function */
inline INT SEL__INT__BOOL__INT__INT(BOOL EN, BOOL *ENO, BOOL G, INT op0, INT op1){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_INT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return G ? op1 : op0;
}

#include <iec_std_lib.h>


/* Overloaded function */
inline SINT SEL__SINT__BOOL__SINT__SINT(BOOL EN, BOOL *ENO, BOOL G, SINT op0, SINT op1){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_SINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return G ? op1 : op0;
}
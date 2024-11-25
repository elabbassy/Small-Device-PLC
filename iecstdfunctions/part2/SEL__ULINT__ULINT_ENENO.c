
#include <iec_std_lib.h>


/* Overloaded function */
inline ULINT SEL__ULINT__ULINT(BOOL EN, BOOL *ENO, BOOL G, ULINT op0, ULINT op1){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_ULINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return G ? op1 : op0;
}
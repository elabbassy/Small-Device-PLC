
#include <iec_std_lib.h>


/* The explicitly typed standard functions */
inline ULINT SEL_ULINT(BOOL EN, BOOL *ENO, BOOL G, ULINT op0, ULINT op1){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_ULINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return G ? op1 : op0;
}
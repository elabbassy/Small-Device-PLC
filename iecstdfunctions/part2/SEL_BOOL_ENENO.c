
#include <iec_std_lib.h>


/* The explicitly typed standard functions */
inline BOOL SEL_BOOL(BOOL EN, BOOL *ENO, BOOL G, BOOL op0, BOOL op1){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_BOOL;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return G ? op1 : op0;
}
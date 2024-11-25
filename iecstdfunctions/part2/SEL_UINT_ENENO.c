
#include <iec_std_lib.h>


/* The explicitly typed standard functions */
inline UINT SEL_UINT(BOOL EN, BOOL *ENO, BOOL G, UINT op0, UINT op1){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_UINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return G ? op1 : op0;
}
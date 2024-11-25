
#include <iec_std_lib.h>


/* The explicitly typed standard functions */
inline BYTE SEL_BYTE(BOOL EN, BOOL *ENO, BOOL G, BYTE op0, BYTE op1){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_BYTE;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return G ? op1 : op0;
}
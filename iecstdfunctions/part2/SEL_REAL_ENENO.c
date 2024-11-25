
#include <iec_std_lib.h>


/* The explicitly typed standard functions */
inline REAL SEL_REAL(BOOL EN, BOOL *ENO, BOOL G, REAL op0, REAL op1){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_REAL;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return G ? op1 : op0;
}
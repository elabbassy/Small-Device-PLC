
#include <iec_std_lib.h>


/* The explicitly typed standard functions */
inline LINT SEL_LINT(BOOL EN, BOOL *ENO, BOOL G, LINT op0, LINT op1){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_LINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return G ? op1 : op0;
}
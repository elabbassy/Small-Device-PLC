
#include <iec_std_lib.h>


/* Overloaded function */
inline LWORD SEL__LWORD__BOOL__LWORD__LWORD(BOOL EN, BOOL *ENO, BOOL G, LWORD op0, LWORD op1){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_LWORD;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return G ? op1 : op0;
}

#include <iec_std_lib.h>


/* The explicitly typed standard functions */
inline LWORD SEL_LWORD(BOOL EN, BOOL *ENO, BOOL G, LWORD op0, LWORD op1){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_LWORD;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return G ? op1 : op0;
}
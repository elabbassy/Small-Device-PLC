
#include <iec_std_lib.h>


/* The explicitly typed standard functions */
inline WORD SEL_WORD(BOOL EN, BOOL *ENO, BOOL G, WORD op0, WORD op1){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_WORD;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return G ? op1 : op0;
}
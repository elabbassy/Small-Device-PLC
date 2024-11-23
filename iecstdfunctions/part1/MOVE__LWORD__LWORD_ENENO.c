
#include <iec_std_lib.h>


/* Overloaded function */
inline LWORD MOVE__LWORD__LWORD(BOOL EN, BOOL *ENO, LWORD op1){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_LWORD;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return op1;
}
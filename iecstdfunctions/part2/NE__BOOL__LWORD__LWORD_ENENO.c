
#include <iec_std_lib.h>


inline BOOL NE__BOOL__LWORD__LWORD(BOOL EN, BOOL *ENO, LWORD op1, LWORD op2){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_BOOL;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);
 
  return op1 != op2 ? 1 : 0;          
}
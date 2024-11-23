
#include <iec_std_lib.h>


inline BOOL NE_WORD(BOOL EN, BOOL *ENO, WORD op1, WORD op2){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_BOOL;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);
 
  return op1 != op2 ? 1 : 0;          
}
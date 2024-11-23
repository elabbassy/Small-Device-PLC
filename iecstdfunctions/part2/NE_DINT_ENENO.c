
#include <iec_std_lib.h>


inline BOOL NE_DINT(BOOL EN, BOOL *ENO, DINT op1, DINT op2){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_BOOL;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);
 
  return op1 != op2 ? 1 : 0;          
}
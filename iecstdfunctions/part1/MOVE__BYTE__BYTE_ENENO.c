
#include <iec_std_lib.h>


/* Overloaded function */
inline BYTE MOVE__BYTE__BYTE(BOOL EN, BOOL *ENO, BYTE op1){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_BYTE;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return op1;
}
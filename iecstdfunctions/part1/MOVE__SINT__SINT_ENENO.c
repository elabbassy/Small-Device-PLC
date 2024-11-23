
#include <iec_std_lib.h>


/* Overloaded function */
inline SINT MOVE__SINT__SINT(BOOL EN, BOOL *ENO, SINT op1){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_SINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return op1;
}
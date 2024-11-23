
#include <iec_std_lib.h>


/* The explicitly typed standard functions */
inline SINT MOVE_SINT(BOOL EN, BOOL *ENO, SINT op1){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_SINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return op1;
}
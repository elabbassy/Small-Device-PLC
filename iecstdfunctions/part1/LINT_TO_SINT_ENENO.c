
#include <iec_std_lib.h>


inline SINT LINT_TO_SINT(BOOL EN, BOOL *ENO, LINT op){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_SINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return (SINT) __move_SINT(op);
}

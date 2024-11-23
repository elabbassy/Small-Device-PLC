
#include <iec_std_lib.h>


inline LINT LWORD_TO_LINT(BOOL EN, BOOL *ENO, LWORD op){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_LINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return (LINT) __move_LINT(op);
}

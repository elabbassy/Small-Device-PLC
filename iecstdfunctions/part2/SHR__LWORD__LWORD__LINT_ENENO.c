
#include <iec_std_lib.h>


inline LWORD SHR__LWORD__LWORD__LINT(BOOL EN, BOOL *ENO, LWORD IN,  LINT N){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_LWORD;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return IN >> N;
}
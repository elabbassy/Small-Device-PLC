
#include <iec_std_lib.h>


inline LWORD SHL__LWORD__LWORD__ULINT(BOOL EN, BOOL *ENO, LWORD IN,  ULINT N){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_LWORD;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return IN << N;
}
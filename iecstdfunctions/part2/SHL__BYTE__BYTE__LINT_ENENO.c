
#include <iec_std_lib.h>


inline BYTE SHL__BYTE__BYTE__LINT(BOOL EN, BOOL *ENO, BYTE IN,  LINT N){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_BYTE;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return IN << N;
}
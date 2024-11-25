
#include <iec_std_lib.h>


inline DWORD SHL__DWORD__DWORD__SINT(BOOL EN, BOOL *ENO, DWORD IN,  SINT N){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_DWORD;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return IN << N;
}
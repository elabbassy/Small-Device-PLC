
#include <iec_std_lib.h>


inline DWORD SHR__DWORD__DWORD__UINT(BOOL EN, BOOL *ENO, DWORD IN,  UINT N){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_DWORD;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return IN >> N;
}
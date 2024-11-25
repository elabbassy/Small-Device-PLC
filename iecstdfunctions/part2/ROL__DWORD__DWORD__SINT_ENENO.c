
#include <iec_std_lib.h>


inline DWORD ROL__DWORD__DWORD__SINT(BOOL EN, BOOL *ENO, DWORD IN,  SINT N){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_DWORD;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  N %= 8*sizeof(DWORD);
  return (IN << N) | (IN >> (8*sizeof(DWORD)-N));
}
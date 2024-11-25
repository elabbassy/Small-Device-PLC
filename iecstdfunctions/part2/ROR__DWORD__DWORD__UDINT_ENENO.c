
#include <iec_std_lib.h>


inline DWORD ROR__DWORD__DWORD__UDINT(BOOL EN, BOOL *ENO, DWORD IN,  UDINT N){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_DWORD;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  N %= 8*sizeof(DWORD);
  return (IN >> N) | (IN << (8*sizeof(DWORD)-N));
}
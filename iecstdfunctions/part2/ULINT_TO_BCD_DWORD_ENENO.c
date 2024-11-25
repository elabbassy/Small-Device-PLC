
#include <iec_std_lib.h>


inline DWORD ULINT_TO_BCD_DWORD(BOOL EN, BOOL *ENO, ULINT op){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_DWORD;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return (DWORD) __uint_to_bcd(op);
}
inline DWORD ULINT_TO_BCD__DWORD__ULINT(BOOL EN, BOOL *ENO, ULINT op){
  return ULINT_TO_BCD_DWORD(EN, ENO, op);
}

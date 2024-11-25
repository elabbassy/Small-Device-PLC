
#include <iec_std_lib.h>


inline DWORD USINT_TO_BCD_DWORD(BOOL EN, BOOL *ENO, USINT op){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_DWORD;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return (DWORD) __uint_to_bcd(op);
}
inline DWORD USINT_TO_BCD__DWORD__USINT(BOOL EN, BOOL *ENO, USINT op){
  return USINT_TO_BCD_DWORD(EN, ENO, op);
}

#include <iec_std_lib.h>


inline DWORD UINT_TO_BCD_DWORD(BOOL EN, BOOL *ENO, UINT op){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_DWORD;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return (DWORD) __uint_to_bcd(op);
}
inline DWORD UINT_TO_BCD__DWORD__UINT(BOOL EN, BOOL *ENO, UINT op){
  return UINT_TO_BCD_DWORD(EN, ENO, op);
}

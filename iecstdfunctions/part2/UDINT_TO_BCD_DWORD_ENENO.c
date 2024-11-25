
#include <iec_std_lib.h>


inline DWORD UDINT_TO_BCD_DWORD(BOOL EN, BOOL *ENO, UDINT op){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_DWORD;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return (DWORD) __uint_to_bcd(op);
}
inline DWORD UDINT_TO_BCD__DWORD__UDINT(BOOL EN, BOOL *ENO, UDINT op){
  return UDINT_TO_BCD_DWORD(EN, ENO, op);
}
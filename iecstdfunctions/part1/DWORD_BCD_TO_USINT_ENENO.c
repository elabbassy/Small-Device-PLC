
#include <iec_std_lib.h>


inline USINT DWORD_BCD_TO_USINT(BOOL EN, BOOL *ENO, DWORD op){

if (!EN || (__test_bcd(op))) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_USINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return (USINT) __bcd_to_uint(op);
}
inline USINT BCD_TO_USINT__USINT__DWORD(BOOL EN, BOOL *ENO, DWORD op){
  return DWORD_BCD_TO_USINT(EN, ENO, op);
}

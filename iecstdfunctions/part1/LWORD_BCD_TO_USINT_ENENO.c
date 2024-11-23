
#include <iec_std_lib.h>


inline USINT LWORD_BCD_TO_USINT(BOOL EN, BOOL *ENO, LWORD op){

if (!EN || (__test_bcd(op))) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_USINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return (USINT) __bcd_to_uint(op);
}
inline USINT BCD_TO_USINT__USINT__LWORD(BOOL EN, BOOL *ENO, LWORD op){
  return LWORD_BCD_TO_USINT(EN, ENO, op);
}

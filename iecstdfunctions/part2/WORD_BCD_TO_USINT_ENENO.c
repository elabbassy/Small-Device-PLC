
#include <iec_std_lib.h>


inline USINT WORD_BCD_TO_USINT(BOOL EN, BOOL *ENO, WORD op){

if (!EN || (__test_bcd(op))) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_USINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return (USINT) __bcd_to_uint(op);
}
inline USINT BCD_TO_USINT__USINT__WORD(BOOL EN, BOOL *ENO, WORD op){
  return WORD_BCD_TO_USINT(EN, ENO, op);
}

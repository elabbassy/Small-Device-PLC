
#include <iec_std_lib.h>


inline UDINT WORD_BCD_TO_UDINT(BOOL EN, BOOL *ENO, WORD op){

if (!EN || (__test_bcd(op))) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_UDINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return (UDINT) __bcd_to_uint(op);
}
inline UDINT BCD_TO_UDINT__UDINT__WORD(BOOL EN, BOOL *ENO, WORD op){
  return WORD_BCD_TO_UDINT(EN, ENO, op);
}

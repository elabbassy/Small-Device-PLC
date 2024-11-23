
#include <iec_std_lib.h>


inline UDINT LWORD_BCD_TO_UDINT(BOOL EN, BOOL *ENO, LWORD op){

if (!EN || (__test_bcd(op))) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_UDINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return (UDINT) __bcd_to_uint(op);
}
inline UDINT BCD_TO_UDINT__UDINT__LWORD(BOOL EN, BOOL *ENO, LWORD op){
  return LWORD_BCD_TO_UDINT(EN, ENO, op);
}

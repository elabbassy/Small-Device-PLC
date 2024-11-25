
#include <iec_std_lib.h>


inline LWORD USINT_TO_BCD_LWORD(BOOL EN, BOOL *ENO, USINT op){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_LWORD;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return (LWORD) __uint_to_bcd(op);
}
inline LWORD USINT_TO_BCD__LWORD__USINT(BOOL EN, BOOL *ENO, USINT op){
  return USINT_TO_BCD_LWORD(EN, ENO, op);
}


#include <iec_std_lib.h>


inline WORD USINT_TO_BCD_WORD(BOOL EN, BOOL *ENO, USINT op){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_WORD;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return (WORD) __uint_to_bcd(op);
}
inline WORD USINT_TO_BCD__WORD__USINT(BOOL EN, BOOL *ENO, USINT op){
  return USINT_TO_BCD_WORD(EN, ENO, op);
}


#include <iec_std_lib.h>


inline WORD UDINT_TO_BCD_WORD(BOOL EN, BOOL *ENO, UDINT op){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_WORD;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return (WORD) __uint_to_bcd(op);
}
inline WORD UDINT_TO_BCD__WORD__UDINT(BOOL EN, BOOL *ENO, UDINT op){
  return UDINT_TO_BCD_WORD(EN, ENO, op);
}


#include <iec_std_lib.h>


inline ULINT WORD_BCD_TO_ULINT(BOOL EN, BOOL *ENO, WORD op){

if (!EN || (__test_bcd(op))) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_ULINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return (ULINT) __bcd_to_uint(op);
}
inline ULINT BCD_TO_ULINT__ULINT__WORD(BOOL EN, BOOL *ENO, WORD op){
  return WORD_BCD_TO_ULINT(EN, ENO, op);
}


#include <iec_std_lib.h>


inline UINT WORD_BCD_TO_UINT(BOOL EN, BOOL *ENO, WORD op){

if (!EN || (__test_bcd(op))) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_UINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return (UINT) __bcd_to_uint(op);
}
inline UINT BCD_TO_UINT__UINT__WORD(BOOL EN, BOOL *ENO, WORD op){
  return WORD_BCD_TO_UINT(EN, ENO, op);
}

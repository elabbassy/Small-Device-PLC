
#include <iec_std_lib.h>


inline UINT LWORD_BCD_TO_UINT(BOOL EN, BOOL *ENO, LWORD op){

if (!EN || (__test_bcd(op))) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_UINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return (UINT) __bcd_to_uint(op);
}
inline UINT BCD_TO_UINT__UINT__LWORD(BOOL EN, BOOL *ENO, LWORD op){
  return LWORD_BCD_TO_UINT(EN, ENO, op);
}

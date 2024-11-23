
#include <iec_std_lib.h>


inline UINT BYTE_BCD_TO_UINT(BOOL EN, BOOL *ENO, BYTE op){

if (!EN || (__test_bcd(op))) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_UINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return (UINT) __bcd_to_uint(op);
}
inline UINT BCD_TO_UINT__UINT__BYTE(BOOL EN, BOOL *ENO, BYTE op){
  return BYTE_BCD_TO_UINT(EN, ENO, op);
}

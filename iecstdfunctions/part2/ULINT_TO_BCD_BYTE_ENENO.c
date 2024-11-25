
#include <iec_std_lib.h>


inline BYTE ULINT_TO_BCD_BYTE(BOOL EN, BOOL *ENO, ULINT op){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_BYTE;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return (BYTE) __uint_to_bcd(op);
}
inline BYTE ULINT_TO_BCD__BYTE__ULINT(BOOL EN, BOOL *ENO, ULINT op){
  return ULINT_TO_BCD_BYTE(EN, ENO, op);
}


#include <iec_std_lib.h>


inline BYTE LREAL_TO_BYTE(BOOL EN, BOOL *ENO, LREAL op){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_BYTE;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return (BYTE) __real_to_bit(op);
}

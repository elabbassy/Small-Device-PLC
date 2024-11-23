
#include <iec_std_lib.h>


inline UINT LREAL_TO_UINT(BOOL EN, BOOL *ENO, LREAL op){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_UINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return (UINT) __real_to_uint(op);
}

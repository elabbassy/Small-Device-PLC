
#include <iec_std_lib.h>


inline UINT BYTE_TO_UINT(BOOL EN, BOOL *ENO, BYTE op){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_UINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return (UINT) __move_UINT(op);
}
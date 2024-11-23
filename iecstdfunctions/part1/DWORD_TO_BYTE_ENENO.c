
#include <iec_std_lib.h>


inline BYTE DWORD_TO_BYTE(BOOL EN, BOOL *ENO, DWORD op){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_BYTE;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return (BYTE) __move_BYTE(op);
}

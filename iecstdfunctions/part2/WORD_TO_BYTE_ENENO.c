
#include <iec_std_lib.h>


inline BYTE WORD_TO_BYTE(BOOL EN, BOOL *ENO, WORD op){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_BYTE;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return (BYTE) __move_BYTE(op);
}

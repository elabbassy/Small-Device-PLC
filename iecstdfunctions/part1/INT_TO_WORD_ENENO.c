
#include <iec_std_lib.h>


inline WORD INT_TO_WORD(BOOL EN, BOOL *ENO, INT op){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_WORD;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return (WORD) __move_WORD(op);
}

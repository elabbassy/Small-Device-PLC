
#include <iec_std_lib.h>


inline ULINT WORD_TO_ULINT(BOOL EN, BOOL *ENO, WORD op){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_ULINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return (ULINT) __move_ULINT(op);
}
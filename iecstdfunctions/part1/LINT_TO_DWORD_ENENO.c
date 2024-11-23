
#include <iec_std_lib.h>


inline DWORD LINT_TO_DWORD(BOOL EN, BOOL *ENO, LINT op){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_DWORD;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return (DWORD) __move_DWORD(op);
}

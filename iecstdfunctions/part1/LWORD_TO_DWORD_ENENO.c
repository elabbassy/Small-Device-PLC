
#include <iec_std_lib.h>


inline DWORD LWORD_TO_DWORD(BOOL EN, BOOL *ENO, LWORD op){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_DWORD;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return (DWORD) __move_DWORD(op);
}


#include <iec_std_lib.h>


inline LWORD DWORD_TO_LWORD(BOOL EN, BOOL *ENO, DWORD op){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_LWORD;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return (LWORD) __move_LWORD(op);
}

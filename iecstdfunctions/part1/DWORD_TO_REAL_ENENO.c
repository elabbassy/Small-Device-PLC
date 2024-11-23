
#include <iec_std_lib.h>


inline REAL DWORD_TO_REAL(BOOL EN, BOOL *ENO, DWORD op){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_REAL;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return (REAL) __move_REAL(op);
}

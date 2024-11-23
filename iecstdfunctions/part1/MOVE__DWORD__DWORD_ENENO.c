
#include <iec_std_lib.h>


/* Overloaded function */
inline DWORD MOVE__DWORD__DWORD(BOOL EN, BOOL *ENO, DWORD op1){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_DWORD;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return op1;
}
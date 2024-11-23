
#include <iec_std_lib.h>


/* Overloaded function */
inline DWORD LIMIT__DWORD__DWORD__DWORD__DWORD(BOOL EN, BOOL *ENO, DWORD MN, DWORD IN, DWORD MX){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_DWORD;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return IN > MN ? IN < MX ? IN : MX : MN;
}
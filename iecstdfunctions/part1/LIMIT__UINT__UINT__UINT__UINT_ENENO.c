
#include <iec_std_lib.h>


/* Overloaded function */
inline UINT LIMIT__UINT__UINT__UINT__UINT(BOOL EN, BOOL *ENO, UINT MN, UINT IN, UINT MX){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_UINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return IN > MN ? IN < MX ? IN : MX : MN;
}
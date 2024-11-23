
#include <iec_std_lib.h>


/* The explicitly typed standard functions */
inline ULINT LIMIT_ULINT(BOOL EN, BOOL *ENO, ULINT MN, ULINT IN, ULINT MX){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_ULINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return IN > MN ? IN < MX ? IN : MX : MN;
}
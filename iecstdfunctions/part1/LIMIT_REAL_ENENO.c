
#include <iec_std_lib.h>


/* The explicitly typed standard functions */
inline REAL LIMIT_REAL(BOOL EN, BOOL *ENO, REAL MN, REAL IN, REAL MX){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_REAL;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return IN > MN ? IN < MX ? IN : MX : MN;
}
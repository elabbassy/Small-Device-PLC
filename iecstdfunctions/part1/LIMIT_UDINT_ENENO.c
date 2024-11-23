
#include <iec_std_lib.h>


/* The explicitly typed standard functions */
inline UDINT LIMIT_UDINT(BOOL EN, BOOL *ENO, UDINT MN, UDINT IN, UDINT MX){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_UDINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return IN > MN ? IN < MX ? IN : MX : MN;
}
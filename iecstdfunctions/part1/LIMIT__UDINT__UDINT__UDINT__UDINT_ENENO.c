
#include <iec_std_lib.h>


/* Overloaded function */
inline UDINT LIMIT__UDINT__UDINT__UDINT__UDINT(BOOL EN, BOOL *ENO, UDINT MN, UDINT IN, UDINT MX){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_UDINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return IN > MN ? IN < MX ? IN : MX : MN;
}
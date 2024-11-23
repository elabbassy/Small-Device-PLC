
#include <iec_std_lib.h>


/* Overloaded function */
inline LINT LIMIT__LINT__LINT__LINT__LINT(BOOL EN, BOOL *ENO, LINT MN, LINT IN, LINT MX){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_LINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return IN > MN ? IN < MX ? IN : MX : MN;
}
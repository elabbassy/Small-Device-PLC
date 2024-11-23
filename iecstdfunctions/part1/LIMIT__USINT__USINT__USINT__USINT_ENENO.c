
#include <iec_std_lib.h>


/* Overloaded function */
inline USINT LIMIT__USINT__USINT__USINT__USINT(BOOL EN, BOOL *ENO, USINT MN, USINT IN, USINT MX){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_USINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return IN > MN ? IN < MX ? IN : MX : MN;
}
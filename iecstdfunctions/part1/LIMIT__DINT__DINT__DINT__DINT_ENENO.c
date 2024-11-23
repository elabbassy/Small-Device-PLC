
#include <iec_std_lib.h>


/* Overloaded function */
inline DINT LIMIT__DINT__DINT__DINT__DINT(BOOL EN, BOOL *ENO, DINT MN, DINT IN, DINT MX){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_DINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return IN > MN ? IN < MX ? IN : MX : MN;
}
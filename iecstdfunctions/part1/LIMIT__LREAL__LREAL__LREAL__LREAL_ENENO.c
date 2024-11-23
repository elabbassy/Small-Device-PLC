
#include <iec_std_lib.h>


/* Overloaded function */
inline LREAL LIMIT__LREAL__LREAL__LREAL__LREAL(BOOL EN, BOOL *ENO, LREAL MN, LREAL IN, LREAL MX){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_LREAL;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return IN > MN ? IN < MX ? IN : MX : MN;
}
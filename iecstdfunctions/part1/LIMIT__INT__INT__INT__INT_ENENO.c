
#include <iec_std_lib.h>


/* Overloaded function */
inline INT LIMIT__INT__INT__INT__INT(BOOL EN, BOOL *ENO, INT MN, INT IN, INT MX){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_INT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return IN > MN ? IN < MX ? IN : MX : MN;
}

#include <iec_std_lib.h>


/* The explicitly typed standard functions */
inline LWORD LIMIT_LWORD(BOOL EN, BOOL *ENO, LWORD MN, LWORD IN, LWORD MX){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_LWORD;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return IN > MN ? IN < MX ? IN : MX : MN;
}
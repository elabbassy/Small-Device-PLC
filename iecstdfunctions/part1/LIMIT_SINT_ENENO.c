
#include <iec_std_lib.h>


/* The explicitly typed standard functions */
inline SINT LIMIT_SINT(BOOL EN, BOOL *ENO, SINT MN, SINT IN, SINT MX){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_SINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return IN > MN ? IN < MX ? IN : MX : MN;
}
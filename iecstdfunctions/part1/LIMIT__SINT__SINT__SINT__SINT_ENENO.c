
#include <iec_std_lib.h>


/* Overloaded function */
inline SINT LIMIT__SINT__SINT__SINT__SINT(BOOL EN, BOOL *ENO, SINT MN, SINT IN, SINT MX){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_SINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return IN > MN ? IN < MX ? IN : MX : MN;
}
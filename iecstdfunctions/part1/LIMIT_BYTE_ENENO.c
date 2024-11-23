
#include <iec_std_lib.h>


/* The explicitly typed standard functions */
inline BYTE LIMIT_BYTE(BOOL EN, BOOL *ENO, BYTE MN, BYTE IN, BYTE MX){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_BYTE;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return IN > MN ? IN < MX ? IN : MX : MN;
}
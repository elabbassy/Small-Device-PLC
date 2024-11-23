
#include <iec_std_lib.h>


/* The explicitly typed standard functions */
inline WORD LIMIT_WORD(BOOL EN, BOOL *ENO, WORD MN, WORD IN, WORD MX){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_WORD;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return IN > MN ? IN < MX ? IN : MX : MN;
}
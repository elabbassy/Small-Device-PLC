
#include <iec_std_lib.h>


/* The explicitly typed standard functions */
inline WORD NOT_WORD(BOOL EN, BOOL *ENO, WORD op1){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_WORD;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return ~op1;
}
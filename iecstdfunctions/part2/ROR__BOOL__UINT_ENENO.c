
#include <iec_std_lib.h>


/* Overloaded function */
inline BOOL ROR__BOOL__UINT(BOOL EN, BOOL *ENO, BOOL IN,  UINT N){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_BOOL;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return IN; /* rotating a single bit by any value N will not change that bit! */
}
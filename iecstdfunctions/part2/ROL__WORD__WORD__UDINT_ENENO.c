
#include <iec_std_lib.h>


inline WORD ROL__WORD__WORD__UDINT(BOOL EN, BOOL *ENO, WORD IN,  UDINT N){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_WORD;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  N %= 8*sizeof(WORD);
  return (IN << N) | (IN >> (8*sizeof(WORD)-N));
}
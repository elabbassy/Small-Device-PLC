
#include <iec_std_lib.h>


inline LWORD ROR__LWORD__LWORD__UDINT(BOOL EN, BOOL *ENO, LWORD IN,  UDINT N){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_LWORD;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  N %= 8*sizeof(LWORD);
  return (IN >> N) | (IN << (8*sizeof(LWORD)-N));
}

#include <iec_std_lib.h>


inline LWORD SHR__LWORD__LWORD__UDINT(BOOL EN, BOOL *ENO, LWORD IN,  UDINT N){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_LWORD;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return IN >> N;
}
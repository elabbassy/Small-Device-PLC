
#include <iec_std_lib.h>


inline BYTE SHR__BYTE__BYTE__USINT(BOOL EN, BOOL *ENO, BYTE IN,  USINT N){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_BYTE;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return IN >> N;
}
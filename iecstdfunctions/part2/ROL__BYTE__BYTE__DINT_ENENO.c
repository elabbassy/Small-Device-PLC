
#include <iec_std_lib.h>


inline BYTE ROL__BYTE__BYTE__DINT(BOOL EN, BOOL *ENO, BYTE IN,  DINT N){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_BYTE;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  N %= 8*sizeof(BYTE);
  return (IN << N) | (IN >> (8*sizeof(BYTE)-N));
}
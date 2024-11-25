
#include <iec_std_lib.h>


inline BYTE pTOD_TO_BYTE(BOOL EN, BOOL *ENO, TOD *op){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_BYTE;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  //time_to_int(op)
  return (BYTE) op->tv_sec;
}

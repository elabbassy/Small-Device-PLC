
#include <iec_std_lib.h>


inline DINT pDATE_TO_DINT(BOOL EN, BOOL *ENO, DATE *op){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_DINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  //time_to_int(op)
  return (DINT) op->tv_sec;
}

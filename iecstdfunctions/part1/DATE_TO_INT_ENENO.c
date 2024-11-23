
#include <iec_std_lib.h>


inline INT pDATE_TO_INT(BOOL EN, BOOL *ENO, DATE *op){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_INT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  //time_to_int(op)
  return (INT) op->tv_sec;
}

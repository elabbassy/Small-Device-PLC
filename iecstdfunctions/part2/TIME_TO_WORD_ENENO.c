
#include <iec_std_lib.h>


inline WORD pTIME_TO_WORD(BOOL EN, BOOL *ENO, TIME *op){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_WORD;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  //time_to_int(op)
  return (WORD) op->tv_sec;
}

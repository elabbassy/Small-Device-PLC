
#include <iec_std_lib.h>


inline LWORD pTOD_TO_LWORD(BOOL EN, BOOL *ENO, TOD *op){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_LWORD;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  //time_to_int(op)
  return (LWORD) op->tv_sec;
}

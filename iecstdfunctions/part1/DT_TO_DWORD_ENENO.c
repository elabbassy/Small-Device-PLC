
#include <iec_std_lib.h>


inline DWORD pDT_TO_DWORD(BOOL EN, BOOL *ENO, DT *op){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_DWORD;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  //time_to_int(op)
  return (DWORD) op->tv_sec;
}

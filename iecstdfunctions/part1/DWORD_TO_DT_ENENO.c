
#include <iec_std_lib.h>


inline DT* pDWORD_TO_DT(BOOL EN, BOOL *ENO, DWORD op){
static DT res;
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  res.tv_sec = 0;
  res.tv_nsec = 0;
  return &res;//__INIT_TOD;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

//return (DT) __int_to_time(op);
res.tv_sec = op;
res.tv_nsec = 0;
return &res;
}

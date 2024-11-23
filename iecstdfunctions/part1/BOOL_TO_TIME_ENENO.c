
#include <iec_std_lib.h>


inline TIME* pBOOL_TO_TIME(BOOL EN, BOOL *ENO, BOOL op){
static TIME res;
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  res.tv_sec = 0;
  res.tv_nsec = 0;
  return &res;//__INIT_TIME;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

//return (TIME) __int_to_time(op);
res.tv_sec = op;
res.tv_nsec = 0;
return &res;
}

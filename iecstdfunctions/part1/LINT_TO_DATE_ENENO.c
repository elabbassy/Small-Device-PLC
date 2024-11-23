
#include <iec_std_lib.h>


inline DATE* pLINT_TO_DATE(BOOL EN, BOOL *ENO, LINT op){
static DATE res;
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  res.tv_sec = 0;
  res.tv_nsec = 0;
  return &res;//__INIT_DATE;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

//return (DATE) __int_to_time(op);
res.tv_sec = op;
res.tv_nsec = 0;
return &res;
}

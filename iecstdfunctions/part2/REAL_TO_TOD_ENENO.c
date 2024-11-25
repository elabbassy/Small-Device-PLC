
#include <iec_std_lib.h>


inline TOD* pREAL_TO_TOD(BOOL EN, BOOL *ENO, REAL op){
static TOD res;
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  res.tv_sec = 0;
  res.tv_nsec = 0;
  return &res;//__INIT_TOD;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

//return (TOD) __real_to_time(op);
res.tv_sec = op;
res.tv_nsec = (op - (LINT)op) * 1000000000;
return &res;
}
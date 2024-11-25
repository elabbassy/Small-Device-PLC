
#include <iec_std_lib.h>


inline DT* pREAL_TO_DT(BOOL EN, BOOL *ENO, REAL op){
static DT res;
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  res.tv_sec = 0;
  res.tv_nsec = 0;
  return &res;//__INIT_DT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

//return (DT) __real_to_time(op);
res.tv_sec = op;
res.tv_nsec = (op - (LINT)op) * 1000000000;
return &res;
}

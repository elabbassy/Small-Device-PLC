
#include <iec_std_lib.h>


/* The explicitly typed standard functions */
inline DT* pMOVE_DT(BOOL EN, BOOL *ENO, DT *op1){
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

res = *op1;
return &res;
}

#include <iec_std_lib.h>

//changed from varadiac to static function with two (2) arguments only 
inline DT* pMIN_DT(BOOL EN, BOOL *ENO, DT *op1, DT *op2){
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

res = __ptime_cmp(op1, op2) > 0 ? *op2 : *op1;
return &res; 
}

#include <iec_std_lib.h>

//changed from varadiac to static function with two (2) arguments only 
inline TIME* pMAX_TIME(BOOL EN, BOOL *ENO, TIME *op1, TIME *op2){
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

res = __ptime_cmp(op1, op2) < 0 ? *op2 : *op1;
return &res; 
}
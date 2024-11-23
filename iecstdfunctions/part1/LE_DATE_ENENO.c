
#include <iec_std_lib.h>

//changed from varadiac to static function with two (2) arguments only 
inline BOOL pLE_DATE(BOOL EN, BOOL *ENO, DATE *op1, DATE *op2){
	
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_BOOL;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

if(__ptime_cmp(op1, op2) <= 0)
	return 1;
else
	return 0;
}
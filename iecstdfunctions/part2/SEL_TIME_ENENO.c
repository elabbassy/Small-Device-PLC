
#include <iec_std_lib.h>


/* The explicitly typed standard functions */
inline TIME* pSEL_TIME(BOOL EN, BOOL *ENO, BOOL G, TIME *op0, TIME *op1){
static TIME res;   
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  res.tv_sec = 0;
  res.tv_nsec = 0;
  return &res;// __INIT_TIME;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

res = G ? *op1 : *op0;
return &res;
}
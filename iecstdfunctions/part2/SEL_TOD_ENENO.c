
#include <iec_std_lib.h>


/* The explicitly typed standard functions */
inline TOD* pSEL_TOD(BOOL EN, BOOL *ENO, BOOL G, TOD *op0, TOD *op1){
static TOD res; 
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  res.tv_sec = 0;
  res.tv_nsec = 0;
  return &res;// __INIT_TOD;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

res = G ? *op1 : *op0;
return &res;
}

#include <iec_std_lib.h>


/* The explicitly typed standard functions */
inline DT* pLIMIT_DT(BOOL EN, BOOL *ENO, DT *MN, DT *IN, DT *MX){
static DT res;
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  res.tv_sec = 0;
  res.tv_nsec = 0;
  return &res;// __INIT_DT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

 res = __ptime_cmp(IN, MN) > 0 ? __ptime_cmp(IN, MX) < 0 ? *IN : *MX : *MN;  
             /* IN>MN ?*/             /* IN<MX ?*/
  return &res;          
}
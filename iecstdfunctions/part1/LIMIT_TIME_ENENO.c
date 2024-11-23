
#include <iec_std_lib.h>


/* The explicitly typed standard functions */
inline TIME* pLIMIT_TIME(BOOL EN, BOOL *ENO, TIME *MN, TIME *IN, TIME *MX){
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
	

 res = __ptime_cmp(IN, MN) > 0 ? __ptime_cmp(IN, MX) < 0 ? *IN : *MX : *MN;  
             /* IN>MN ?*/             /* IN<MX ?*/
  return &res;
            
}
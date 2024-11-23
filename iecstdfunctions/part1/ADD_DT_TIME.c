#include <iec_std_lib.h>


/* explicitly typed function */
inline DT* pADD_DT_TIME(BOOL EN, BOOL *ENO, DT *IN1, TIME *IN2){
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

  //return __time_add(IN1, IN2);
	res.tv_sec = IN1->tv_sec + IN2->tv_sec;
    res.tv_nsec  = IN1->tv_nsec + IN2->tv_nsec;
	__normalize_timespec(&res);
	return &res;
}
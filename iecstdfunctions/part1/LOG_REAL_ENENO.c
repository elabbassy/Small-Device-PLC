
#include <iec_std_lib.h>


/* explicitly typed function */
inline REAL LOG_REAL(BOOL EN, BOOL *ENO, REAL op){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_REAL;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return log10f(op);
}
/* overloaded function */
inline REAL LOG__REAL__REAL(BOOL EN, BOOL *ENO, REAL op){
  return LOG_REAL(EN, ENO, op);
}
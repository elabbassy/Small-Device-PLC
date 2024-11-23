
#include <iec_std_lib.h>


/* explicitly typed function */
inline UINT ABS_UINT(BOOL EN, BOOL *ENO, UINT op){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_UINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return op;
}
/* overloaded function */
inline UINT ABS__UINT__UINT(BOOL EN, BOOL *ENO, UINT op){
  return ABS_UINT(EN, ENO,  op);
}
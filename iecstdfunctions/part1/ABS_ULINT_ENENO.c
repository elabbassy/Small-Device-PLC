
#include <iec_std_lib.h>


/* explicitly typed function */
inline ULINT ABS_ULINT(BOOL EN, BOOL *ENO, ULINT op){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_ULINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return op;
}
/* overloaded function */
inline ULINT ABS__ULINT__ULINT(BOOL EN, BOOL *ENO, ULINT op){
  return ABS_ULINT(EN, ENO,  op);
}

#include <iec_std_lib.h>


/* explicitly typed function */
inline UDINT ABS_UDINT(BOOL EN, BOOL *ENO, UDINT op){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_UDINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return op;
}
/* overloaded function */
inline UDINT ABS__UDINT__UDINT(BOOL EN, BOOL *ENO, UDINT op){
  return ABS_UDINT(EN, ENO,  op);
}
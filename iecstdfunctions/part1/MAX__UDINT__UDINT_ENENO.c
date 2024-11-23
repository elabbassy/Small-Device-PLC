
#include <iec_std_lib.h>


inline UDINT MAX__UDINT__UDINT(BOOL EN, BOOL *ENO, UINT param_count, UDINT op1, ...){
  va_list ap;
  UINT i;
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_UDINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  va_start (ap, op1);         /* Initialize the argument list.  */
  
  for (i = 0; i < param_count - 1; i++){
    UDINT tmp = va_arg (ap, VA_ARGS_UDINT);
    op1 = op1 < tmp ? tmp : op1;
   }
   
  va_end (ap);                  /* Clean up.  */
  return op1;
}
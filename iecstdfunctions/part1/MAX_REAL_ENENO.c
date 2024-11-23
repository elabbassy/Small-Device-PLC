
#include <iec_std_lib.h>


inline REAL MAX_REAL(BOOL EN, BOOL *ENO, UINT param_count, REAL op1, ...){
  va_list ap;
  UINT i;
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_REAL;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  va_start (ap, op1);         /* Initialize the argument list.  */
  
  for (i = 0; i < param_count - 1; i++){
    REAL tmp = va_arg (ap, VA_ARGS_REAL);
    op1 = op1 < tmp ? tmp : op1;
   }
   
  va_end (ap);                  /* Clean up.  */
  return op1;
}
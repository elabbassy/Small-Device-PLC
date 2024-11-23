
#include <iec_std_lib.h>


/* explicitly typed function */
inline LREAL MUL__LREAL__LREAL(BOOL EN, BOOL *ENO, UINT param_count, LREAL op1, ...){
  va_list ap;
  UINT i;
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_LREAL;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  va_start (ap, op1);         /* Initialize the argument list.  */
  
  for (i = 0; i < param_count - 1; i++){
    op1 = op1 * va_arg (ap, VA_ARGS_LREAL);
   }
   
  va_end (ap);                  /* Clean up.  */
  return op1;
}
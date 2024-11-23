
#include <iec_std_lib.h>


inline LREAL MUX__LREAL__ULINT__LREAL(BOOL EN, BOOL *ENO, ULINT K, UINT param_count, ...){
  va_list ap;
  UINT i;
  LREAL tmp;
  
if (!EN || (K >= param_count)) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_ULINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  tmp = __INIT_LREAL;
  
  va_start (ap, param_count);         /* Initialize the argument list.  */
  
  for (i = 0; i < param_count; i++){
    if(K == i){
        tmp = va_arg (ap, VA_ARGS_LREAL);
        va_end (ap);                  /* Clean up.  */
        return tmp;
    }else{
        va_arg (ap, VA_ARGS_LREAL);
    }
  }
  va_end (ap);                  /* Clean up.  */
  return tmp;
}
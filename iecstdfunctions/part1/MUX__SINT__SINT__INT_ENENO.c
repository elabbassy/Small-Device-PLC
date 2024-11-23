
#include <iec_std_lib.h>


inline INT MUX__INT__SINT__INT(BOOL EN, BOOL *ENO, SINT K, UINT param_count, ...){
  va_list ap;
  UINT i;
  INT tmp;
  
if (!EN || (K >= param_count)) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_SINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  tmp = __INIT_INT;
  
  va_start (ap, param_count);         /* Initialize the argument list.  */
  
  for (i = 0; i < param_count; i++){
    if(K == i){
        tmp = va_arg (ap, VA_ARGS_INT);
        va_end (ap);                  /* Clean up.  */
        return tmp;
    }else{
        va_arg (ap, VA_ARGS_INT);
    }
  }
  va_end (ap);                  /* Clean up.  */
  return tmp;
}
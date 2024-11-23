
#include <iec_std_lib.h>


inline SINT MUX__SINT__UDINT__SINT(BOOL EN, BOOL *ENO, UDINT K, UINT param_count, ...){
  va_list ap;
  UINT i;
  SINT tmp;
  
if (!EN || (K >= param_count)) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_UDINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  tmp = __INIT_SINT;
  
  va_start (ap, param_count);         /* Initialize the argument list.  */
  
  for (i = 0; i < param_count; i++){
    if(K == i){
        tmp = va_arg (ap, VA_ARGS_SINT);
        va_end (ap);                  /* Clean up.  */
        return tmp;
    }else{
        va_arg (ap, VA_ARGS_SINT);
    }
  }
  va_end (ap);                  /* Clean up.  */
  return tmp;
}
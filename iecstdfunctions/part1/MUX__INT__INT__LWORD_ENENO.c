
#include <iec_std_lib.h>


inline LWORD MUX__LWORD__INT__LWORD(BOOL EN, BOOL *ENO, INT K, UINT param_count, ...){
  va_list ap;
  UINT i;
  LWORD tmp;
  
if (!EN || (K >= param_count)) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_INT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  tmp = __INIT_LWORD;
  
  va_start (ap, param_count);         /* Initialize the argument list.  */
  
  for (i = 0; i < param_count; i++){
    if(K == i){
        tmp = va_arg (ap, VA_ARGS_LWORD);
        va_end (ap);                  /* Clean up.  */
        return tmp;
    }else{
        va_arg (ap, VA_ARGS_LWORD);
    }
  }
  va_end (ap);                  /* Clean up.  */
  return tmp;
}

#include <iec_std_lib.h>


inline BYTE MUX__BYTE__DINT__BYTE(BOOL EN, BOOL *ENO, DINT K, UINT param_count, ...){
  va_list ap;
  UINT i;
  BYTE tmp;
  
if (!EN || (K >= param_count)) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_DINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  tmp = __INIT_BYTE;
  
  va_start (ap, param_count);         /* Initialize the argument list.  */
  
  for (i = 0; i < param_count; i++){
    if(K == i){
        tmp = va_arg (ap, VA_ARGS_BYTE);
        va_end (ap);                  /* Clean up.  */
        return tmp;
    }else{
        va_arg (ap, VA_ARGS_BYTE);
    }
  }
  va_end (ap);                  /* Clean up.  */
  return tmp;
}
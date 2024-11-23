
#include <iec_std_lib.h>


inline BOOL GT__BOOL__BYTE(BOOL EN, BOOL *ENO, UINT param_count, BYTE op1, ...){
  va_list ap;
  UINT i;
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_BOOL;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  va_start (ap, op1);         /* Initialize the argument list.  */
  /*DBG(GT__BOOL__BYTE BYTE)*/
  /*DBG_TYPE(BYTE, op1)*/
  
  for (i = 0; i < param_count - 1; i++){
    BYTE tmp = va_arg (ap, VA_ARGS_BYTE);
    /*DBG_TYPE(BYTE, tmp)*/
    if(op1 > tmp){
        op1 = tmp;
    }else{
        va_end (ap);                  /* Clean up.  */
        return 0;
    }
  }
  
  va_end (ap);                  /* Clean up.  */
  return 1;
}
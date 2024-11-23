
#include <iec_std_lib.h>


inline BOOL EQ__BOOL__INT(BOOL EN, BOOL *ENO, UINT param_count, INT op1, ...){
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
  /*DBG(EQ__BOOL__INT INT)*/
  /*DBG_TYPE(INT, op1)*/
  
  for (i = 0; i < param_count - 1; i++){
    INT tmp = va_arg (ap, VA_ARGS_INT);
    /*DBG_TYPE(INT, tmp)*/
    if(op1 == tmp){
        op1 = tmp;
    }else{
        va_end (ap);                  /* Clean up.  */
        return 0;
    }
  }
  
  va_end (ap);                  /* Clean up.  */
  return 1;
}
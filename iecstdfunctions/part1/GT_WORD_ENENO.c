
#include <iec_std_lib.h>


inline BOOL GT_WORD(BOOL EN, BOOL *ENO, UINT param_count, WORD op1, ...){
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
  /*DBG(GT_WORD WORD)*/
  /*DBG_TYPE(WORD, op1)*/
  
  for (i = 0; i < param_count - 1; i++){
    WORD tmp = va_arg (ap, VA_ARGS_WORD);
    /*DBG_TYPE(WORD, tmp)*/
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
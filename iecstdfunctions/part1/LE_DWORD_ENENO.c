
#include <iec_std_lib.h>


inline BOOL LE_DWORD(BOOL EN, BOOL *ENO, UINT param_count, DWORD op1, ...){
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
  /*DBG(LE_DWORD DWORD)*/
  /*DBG_TYPE(DWORD, op1)*/
  
  for (i = 0; i < param_count - 1; i++){
    DWORD tmp = va_arg (ap, VA_ARGS_DWORD);
    /*DBG_TYPE(DWORD, tmp)*/
    if(op1 <= tmp){
        op1 = tmp;
    }else{
        va_end (ap);                  /* Clean up.  */
        return 0;
    }
  }
  
  va_end (ap);                  /* Clean up.  */
  return 1;
}
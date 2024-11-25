
#include <iec_std_lib.h>


inline WORD SHL__WORD__WORD__DINT(BOOL EN, BOOL *ENO, WORD IN,  DINT N){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_WORD;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return IN << N;
}
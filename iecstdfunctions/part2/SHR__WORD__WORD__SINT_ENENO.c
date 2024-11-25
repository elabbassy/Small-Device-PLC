
#include <iec_std_lib.h>


inline WORD SHR__WORD__WORD__SINT(BOOL EN, BOOL *ENO, WORD IN,  SINT N){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_WORD;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return IN >> N;
}
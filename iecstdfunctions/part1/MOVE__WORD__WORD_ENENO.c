
#include <iec_std_lib.h>


/* Overloaded function */
inline WORD MOVE__WORD__WORD(BOOL EN, BOOL *ENO, WORD op1){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_WORD;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return op1;
}
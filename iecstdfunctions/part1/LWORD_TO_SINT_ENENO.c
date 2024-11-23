
#include <iec_std_lib.h>


inline SINT LWORD_TO_SINT(BOOL EN, BOOL *ENO, LWORD op){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_SINT;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return (SINT) __move_SINT(op);
}

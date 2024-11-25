
#include <iec_std_lib.h>


/* The explicitly typed standard functions */
inline DWORD SEL_DWORD(BOOL EN, BOOL *ENO, BOOL G, DWORD op0, DWORD op1){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_DWORD;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return G ? op1 : op0;
}
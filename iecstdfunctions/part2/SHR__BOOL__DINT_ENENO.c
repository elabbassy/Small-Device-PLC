
#include <iec_std_lib.h>


/* Overloaded function */
inline BOOL SHR__BOOL__DINT(BOOL EN, BOOL *ENO, BOOL IN,  DINT N){
  
if (!EN) {
  if (ENO != NULL)
    *ENO = __BOOL_LITERAL(FALSE);
  return __INIT_BOOL;
}
else if (ENO != NULL)
  *ENO = __BOOL_LITERAL(TRUE);

  return (N==0)? IN : __INIT_BOOL; /* shifting by N>1 will always introduce a 0 */
}
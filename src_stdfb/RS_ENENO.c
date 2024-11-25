#include "iec_std_lib.h"

void RS_init_ENENO__(RS *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->S,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->R1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q1,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void RS_body_ENENO__(RS *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,Q1,,(!(__GET_VAR(data__->R1,)) && (__GET_VAR(data__->S,) || __GET_VAR(data__->Q1,))));

  goto __end;

__end:
  return;
} // RS_body__() 
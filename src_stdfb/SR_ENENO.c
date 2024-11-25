#include "iec_std_lib.h"


void SR_init_ENENO__(SR *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->S1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->R,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q1,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void SR_body_ENENO__(SR *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,Q1,,(__GET_VAR(data__->S1,) || (!(__GET_VAR(data__->R,)) && __GET_VAR(data__->Q1,))));

  goto __end;

__end:
  return;
} // SR_body__() 
#include "iec_std_lib.h"


void R_TRIG_init_ENENO__(R_TRIG *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->CLK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->M,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void R_TRIG_body_ENENO__(R_TRIG *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,Q,,(__GET_VAR(data__->CLK,) && !(__GET_VAR(data__->M,))));
  __SET_VAR(data__->,M,,__GET_VAR(data__->CLK,));

  goto __end;

__end:
  return;
} // R_TRIG_body__() 
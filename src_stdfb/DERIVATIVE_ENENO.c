#include "iec_std_lib.h"


void DERIVATIVE_init_ENENO__(DERIVATIVE *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->RUN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->XIN,0,retain)
  __INIT_VAR(data__->CYCLE,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->XOUT,0,retain)
  __INIT_VAR(data__->X1,0,retain)
  __INIT_VAR(data__->X2,0,retain)
  __INIT_VAR(data__->X3,0,retain)
}

// Code part
void DERIVATIVE_body_ENENO__(DERIVATIVE *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if (__GET_VAR(data__->RUN,)) {
    __SET_VAR(data__->,XOUT,,((((3.0 * (__GET_VAR(data__->XIN,) - __GET_VAR(data__->X3,))) + __GET_VAR(data__->X1,)) - __GET_VAR(data__->X2,)) / (10.0 * TIME_TO_REAL((BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      __GET_VAR(data__->CYCLE,)))));
    __SET_VAR(data__->,X3,,__GET_VAR(data__->X2,));
    __SET_VAR(data__->,X2,,__GET_VAR(data__->X1,));
    __SET_VAR(data__->,X1,,__GET_VAR(data__->XIN,));
  } else {
    __SET_VAR(data__->,XOUT,,0.0);
    __SET_VAR(data__->,X1,,__GET_VAR(data__->XIN,));
    __SET_VAR(data__->,X2,,__GET_VAR(data__->XIN,));
    __SET_VAR(data__->,X3,,__GET_VAR(data__->XIN,));
  };

  goto __end;

__end:
  return;
} // DERIVATIVE_body__() 
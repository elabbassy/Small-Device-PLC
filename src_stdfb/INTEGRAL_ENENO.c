#include "iec_std_lib.h"


void INTEGRAL_init_ENENO__(INTEGRAL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->RUN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->R1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->XIN,0,retain)
  __INIT_VAR(data__->X0,0,retain)
  __INIT_VAR(data__->CYCLE,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->Q,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->XOUT,0,retain)
}

// Code part
void INTEGRAL_body_ENENO__(INTEGRAL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,Q,,!(__GET_VAR(data__->R1,)));
  if (__GET_VAR(data__->R1,)) {
    __SET_VAR(data__->,XOUT,,__GET_VAR(data__->X0,));
  } else if (__GET_VAR(data__->RUN,)) {
    __SET_VAR(data__->,XOUT,,(__GET_VAR(data__->XOUT,) + (__GET_VAR(data__->XIN,) * TIME_TO_REAL((BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      /*(TIME)*/__GET_VAR(data__->CYCLE,)))));
  };

  goto __end;

__end:
  return;
} // INTEGRAL_body__() 
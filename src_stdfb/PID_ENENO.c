#include "iec_std_lib.h"


void PID_init_ENENO__(PID *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->AUTO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PV,0,retain)
  __INIT_VAR(data__->SP,0,retain)
  __INIT_VAR(data__->X0,0,retain)
  __INIT_VAR(data__->KP,0,retain)
  __INIT_VAR(data__->TR,0,retain)
  __INIT_VAR(data__->TD,0,retain)
  __INIT_VAR(data__->CYCLE,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->XOUT,0,retain)
  __INIT_VAR(data__->ERROR,0,retain)
  INTEGRAL_init__(&data__->ITERM,retain);
  DERIVATIVE_init__(&data__->DTERM,retain);
}

// Code part
void PID_body_ENENO__(PID *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,ERROR,,(__GET_VAR(data__->PV,) - __GET_VAR(data__->SP,)));
  __SET_VAR(data__->ITERM.,RUN,,__GET_VAR(data__->AUTO,));
  __SET_VAR(data__->ITERM.,R1,,!(__GET_VAR(data__->AUTO,)));
  __SET_VAR(data__->ITERM.,XIN,,__GET_VAR(data__->ERROR,));
  __SET_VAR(data__->ITERM.,X0,,(__GET_VAR(data__->TR,) * (__GET_VAR(data__->X0,) - __GET_VAR(data__->ERROR,))));
  __SET_VAR(data__->ITERM.,CYCLE,,__GET_VAR(data__->CYCLE,));
  INTEGRAL_body__(&data__->ITERM);
  __SET_VAR(data__->DTERM.,RUN,,__GET_VAR(data__->AUTO,));
  __SET_VAR(data__->DTERM.,XIN,,__GET_VAR(data__->ERROR,));
  __SET_VAR(data__->DTERM.,CYCLE,,__GET_VAR(data__->CYCLE,));
  DERIVATIVE_body__(&data__->DTERM);
  __SET_VAR(data__->,XOUT,,(__GET_VAR(data__->KP,) * ((__GET_VAR(data__->ERROR,) + (__GET_VAR(data__->ITERM.XOUT,) / __GET_VAR(data__->TR,))) + (__GET_VAR(data__->DTERM.XOUT,) * __GET_VAR(data__->TD,)))));

  goto __end;

__end:
  return;
} // PID_body__() 
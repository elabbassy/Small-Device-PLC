#include "iec_std_lib.h"


void RAMP_init_ENENO__(RAMP *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->RUN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->X0,0,retain)
  __INIT_VAR(data__->X1,0,retain)
  __INIT_VAR(data__->TR,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->CYCLE,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->BUSY,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->XOUT,0.0,retain)
  __INIT_VAR(data__->XI,0,retain)
  __INIT_VAR(data__->T,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
}

// Code part
void RAMP_body_ENENO__(RAMP *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,BUSY,,__GET_VAR(data__->RUN,));
  if (__GET_VAR(data__->RUN,)) {
    if (GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->T,), __GET_VAR(data__->TR,))) {
      __SET_VAR(data__->,BUSY,,0);
      __SET_VAR(data__->,XOUT,,__GET_VAR(data__->X1,));
    } else {
      __SET_VAR(data__->,XOUT,,(__GET_VAR(data__->XI,) + (((__GET_VAR(data__->X1,) - __GET_VAR(data__->XI,)) * TIME_TO_REAL((BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        /*(TIME)*/__GET_VAR(data__->T,))) / TIME_TO_REAL((BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        /*(TIME)*/__GET_VAR(data__->TR,)))));
      __SET_VAR(data__->,T,,__time_add(__GET_VAR(data__->T,), __GET_VAR(data__->CYCLE,)));
    };
  } else {
    __SET_VAR(data__->,XOUT,,__GET_VAR(data__->X0,));
    __SET_VAR(data__->,XI,,__GET_VAR(data__->X0,));
    __SET_VAR(data__->,T,,__time_to_timespec(1, 0, 0, 0, 0, 0));
  };

  goto __end;

__end:
  return;
} // RAMP_body__() 
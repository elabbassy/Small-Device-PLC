#include "iec_std_lib.h"


void HYSTERESIS_init_ENENO__(HYSTERESIS *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->XIN1,0,retain)
  __INIT_VAR(data__->XIN2,0,retain)
  __INIT_VAR(data__->EPS_,0,retain)
  __INIT_VAR(data__->Q,0,retain)
}

// Code part
void HYSTERESIS_body_ENENO__(HYSTERESIS *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if (__GET_VAR(data__->Q,)) {
    if ((__GET_VAR(data__->XIN1,) < (__GET_VAR(data__->XIN2,) - __GET_VAR(data__->EPS_,)))) {
      __SET_VAR(data__->,Q,,0);
    };
  } else if ((__GET_VAR(data__->XIN1,) > (__GET_VAR(data__->XIN2,) + __GET_VAR(data__->EPS_,)))) {
    __SET_VAR(data__->,Q,,1);
  };

  goto __end;

__end:
  return;
} // HYSTERESIS_body__() 
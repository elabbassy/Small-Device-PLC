#include "iec_std_lib.h"


void CTD_UDINT_init_ENENO__(CTD_UDINT *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->CD,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LD,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PV,0,retain)
  __INIT_VAR(data__->Q,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CV,0,retain)
  R_TRIG_init__(&data__->CD_T,retain);
}

// Code part
void CTD_UDINT_body_ENENO__(CTD_UDINT *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->CD_T.,CLK,,__GET_VAR(data__->CD,));
  R_TRIG_body__(&data__->CD_T);
  if (__GET_VAR(data__->LD,)) {
    __SET_VAR(data__->,CV,,__GET_VAR(data__->PV,));
  } else if ((__GET_VAR(data__->CD_T.Q,) && (__GET_VAR(data__->CV,) > 0))) {
    __SET_VAR(data__->,CV,,(__GET_VAR(data__->CV,) - 1));
  };
  __SET_VAR(data__->,Q,,(__GET_VAR(data__->CV,) <= 0));

  goto __end;

__end:
  return;
} // CTD_UDINT_body__() 
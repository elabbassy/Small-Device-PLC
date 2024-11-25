#include "iec_std_lib.h"


void CTU_UDINT_init_ENENO__(CTU_UDINT *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->CU,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->R,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PV,0,retain)
  __INIT_VAR(data__->Q,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CV,0,retain)
  R_TRIG_init__(&data__->CU_T,retain);
}

// Code part
void CTU_UDINT_body_ENENO__(CTU_UDINT *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->CU_T.,CLK,,__GET_VAR(data__->CU,));
  R_TRIG_body__(&data__->CU_T);
  if (__GET_VAR(data__->R,)) {
    __SET_VAR(data__->,CV,,0);
  } else if ((__GET_VAR(data__->CU_T.Q,) && (__GET_VAR(data__->CV,) < __GET_VAR(data__->PV,)))) {
    __SET_VAR(data__->,CV,,(__GET_VAR(data__->CV,) + 1));
  };
  __SET_VAR(data__->,Q,,(__GET_VAR(data__->CV,) >= __GET_VAR(data__->PV,)));

  goto __end;

__end:
  return;
} // CTU_UDINT_body__() 

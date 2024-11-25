#include "iec_std_lib.h"


void CTUD_LINT_init_ENENO__(CTUD_LINT *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->CU,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CD,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->R,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LD,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PV,0,retain)
  __INIT_VAR(data__->QU,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->QD,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CV,0,retain)
  R_TRIG_init__(&data__->CD_T,retain);
  R_TRIG_init__(&data__->CU_T,retain);
}

// Code part
void CTUD_LINT_body_ENENO__(CTUD_LINT *data__) {
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
  __SET_VAR(data__->CU_T.,CLK,,__GET_VAR(data__->CU,));
  R_TRIG_body__(&data__->CU_T);
  if (__GET_VAR(data__->R,)) {
    __SET_VAR(data__->,CV,,0);
  } else if (__GET_VAR(data__->LD,)) {
    __SET_VAR(data__->,CV,,__GET_VAR(data__->PV,));
  } else {
    if (!((__GET_VAR(data__->CU_T.Q,) && __GET_VAR(data__->CD_T.Q,)))) {
      if ((__GET_VAR(data__->CU_T.Q,) && (__GET_VAR(data__->CV,) < __GET_VAR(data__->PV,)))) {
        __SET_VAR(data__->,CV,,(__GET_VAR(data__->CV,) + 1));
      } else if ((__GET_VAR(data__->CD_T.Q,) && (__GET_VAR(data__->CV,) > 0))) {
        __SET_VAR(data__->,CV,,(__GET_VAR(data__->CV,) - 1));
      };
    };
  };
  __SET_VAR(data__->,QU,,(__GET_VAR(data__->CV,) >= __GET_VAR(data__->PV,)));
  __SET_VAR(data__->,QD,,(__GET_VAR(data__->CV,) <= 0));

  goto __end;

__end:
  return;
} // CTUD_LINT_body__() 
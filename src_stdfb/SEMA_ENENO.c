#include "iec_std_lib.h"


void SEMA_init_ENENO__(SEMA *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->CLAIM,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RELEASE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BUSY,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q_INTERNAL,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void SEMA_body_ENENO__(SEMA *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,Q_INTERNAL,,(__GET_VAR(data__->CLAIM,) || (__GET_VAR(data__->Q_INTERNAL,) && !(__GET_VAR(data__->RELEASE,)))));
  __SET_VAR(data__->,BUSY,,__GET_VAR(data__->Q_INTERNAL,));

  goto __end;

__end:
  return;
} // SEMA_body__() 
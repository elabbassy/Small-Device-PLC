#include "iec_std_lib.h"

void TON_init_ENENO__(TON *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PT,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->Q,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ET,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->PREV_IN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CURRENT_TIME,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->START_TIME,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
}

// Code part
void TON_body_ENENO__(TON *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
  #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
__SET_VAR(data__->,CURRENT_TIME,,__CURRENT_TIME)
  #undef GetFbVar
  #undef SetFbVar
;
  if ((((__GET_VAR(data__->STATE,) == 0) && !(__GET_VAR(data__->PREV_IN,))) && __GET_VAR(data__->IN,))) {
    __SET_VAR(data__->,STATE,,1);
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,START_TIME,,__GET_VAR(data__->CURRENT_TIME,));
  } else {
    if (!(__GET_VAR(data__->IN,))) {
      __SET_VAR(data__->,ET,,__time_to_timespec(1, 0, 0, 0, 0, 0));
      __SET_VAR(data__->,Q,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,STATE,,0);
    } else if ((__GET_VAR(data__->STATE,) == 1)) {
      if (LE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_add(__GET_VAR(data__->START_TIME,), __GET_VAR(data__->PT,)), __GET_VAR(data__->CURRENT_TIME,))) {
        __SET_VAR(data__->,STATE,,2);
        __SET_VAR(data__->,Q,,__BOOL_LITERAL(TRUE));
        __SET_VAR(data__->,ET,,__GET_VAR(data__->PT,));
      } else {
        __SET_VAR(data__->,ET,,__time_sub(__GET_VAR(data__->CURRENT_TIME,), __GET_VAR(data__->START_TIME,)));
      };
    };
  };
  __SET_VAR(data__->,PREV_IN,,__GET_VAR(data__->IN,));

  goto __end;

__end:
  return;
} // TON_body__() 

#include "iec_std_lib.h"


void RTC_init_ENENO__(RTC *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PDT,__dt_to_timespec(0, 0, 0, 1, 1, 1970),retain)
  __INIT_VAR(data__->Q,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CDT,__dt_to_timespec(0, 0, 0, 1, 1, 1970),retain)
  __INIT_VAR(data__->PREV_IN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OFFSET,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->CURRENT_TIME,__dt_to_timespec(0, 0, 0, 1, 1, 1970),retain)
}

// Code part
void RTC_body_ENENO__(RTC *data__) {
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
  if (__GET_VAR(data__->IN,)) {
    if (!(__GET_VAR(data__->PREV_IN,))) {
      __SET_VAR(data__->,OFFSET,,__time_sub(__GET_VAR(data__->PDT,), __GET_VAR(data__->CURRENT_TIME,)));
    };
    __SET_VAR(data__->,CDT,,__time_add(__GET_VAR(data__->CURRENT_TIME,), __GET_VAR(data__->OFFSET,)));
  } else {
    __SET_VAR(data__->,CDT,,__GET_VAR(data__->CURRENT_TIME,));
  };
  __SET_VAR(data__->,Q,,__GET_VAR(data__->IN,));
  __SET_VAR(data__->,PREV_IN,,__GET_VAR(data__->IN,));

  goto __end;

__end:
  return;
} // RTC_body__() 
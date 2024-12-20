/* Small Device PLC
 * An SDCC (Small Device C Compiler) port for (MATIEC) implementaion of 
 * IEC 61131-3 standard.
 * based on MATIEC lib c project (See the license below)
 * the proting attempt is as follows:
 * 1- code part is stripped from header files, function prototypes
 *    was kept with a little modifications if nessessary.
 * 2- every individual function is written to a seperate file and linked to "lib"
 *    archive for the sake of SDCC Linker's code optimization.
 * 3- the current version of SDCC (4.4.0) dose not support: (a)Compound  
 *    literals, (b)’double’ precision floating point ('float' is used instead)
 *     and,(c)initialization of structure arrays.
 * 4- due to the limitations mentiond above:
 *    (a) DATE/TIME manuplation functions (ex: SUB_TIME, EQ_DATE, ...) were 
 *        changed to "STATIC" function type with (2) arguments (instead originally 
 *        variadic implementaion), this will lead to compile-time error 
 *        if more arguments passed.
 *    (b) "SFC" language is not supported yet.
 *    (c) explicitly casting for types (TIME, DATE, DT, DOT) generated by "iec2c"
 *        must be removed. (eg: by python script or shell commands)
 * 5- 'STRING' manuplation functions is not supported.
 * 6- most of the functions are (reentrant) so, lib archive shall be compiled/linked with 
 *   "stack-auto" (mcs51 target) or equivalent option.
 *
 * elabbassy2013@gmail.com
 * License: as below.
 */

/****
 * IEC 61131-3 standard function block library
 */

/* NOTE: The code in this file was generated by iec2c (i.e. matiec C compiler), using as source
 *        the *.txt files in the 'lib' directory.
 *       The only 'manual' change was:
 *          - to merge the generated .h and .c files into this single file
 *          - to remove the forward declarations of the functions
 *          - to change the function prototypes to become 'static'.
 *             e.g.:   static void R_TRIG_init__(...)
 *                     ^^^^^^
 * 
 * NOTE: If the structure of the C code generated by iec2c (matiec) should change, then this C 'library'
 *       file will need to be recompiled. 
 *       The correct way of going about this would be to have this file be automatically generated during
 *       the build process (i.e. after compiling matiec), but we will leave this for later if it ever
 *       becomes necessary.
 * 
 * WARNING: There are 2 versions of this file:
 *            - file: iec_std_FB.h
 *              Version to be used when the EN and ENO parameters are implicitly generated
 *              for all functions and function blocks
 *            - file: iec_std_FB_no_ENENO.h
 *              Version to be used when the EN and ENO parameters are NOT implicitly generated
 *              for all functions and function blocks
 */

#ifndef _IEC_STD_FB_H
#define _IEC_STD_FB_H


#include "accessor.h"



// FUNCTION_BLOCK R_TRIG
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,CLK)
  __DECLARE_VAR(BOOL,Q)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,M)

} R_TRIG;

// FUNCTION_BLOCK F_TRIG
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,CLK)
  __DECLARE_VAR(BOOL,Q)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,M)

} F_TRIG;

// FUNCTION_BLOCK SR
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,S1)
  __DECLARE_VAR(BOOL,R)
  __DECLARE_VAR(BOOL,Q1)

  // FB private variables - TEMP, private and located variables

} SR;

// FUNCTION_BLOCK RS
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,S)
  __DECLARE_VAR(BOOL,R1)
  __DECLARE_VAR(BOOL,Q1)

  // FB private variables - TEMP, private and located variables

} RS;

// FUNCTION_BLOCK CTU
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,CU)
  __DECLARE_VAR(BOOL,R)
  __DECLARE_VAR(INT,PV)
  __DECLARE_VAR(BOOL,Q)
  __DECLARE_VAR(INT,CV)

  // FB private variables - TEMP, private and located variables
  R_TRIG CU_T;

} CTU;

// FUNCTION_BLOCK CTU_DINT
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,CU)
  __DECLARE_VAR(BOOL,R)
  __DECLARE_VAR(DINT,PV)
  __DECLARE_VAR(BOOL,Q)
  __DECLARE_VAR(DINT,CV)

  // FB private variables - TEMP, private and located variables
  R_TRIG CU_T;

} CTU_DINT;

// FUNCTION_BLOCK CTU_LINT
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,CU)
  __DECLARE_VAR(BOOL,R)
  __DECLARE_VAR(LINT,PV)
  __DECLARE_VAR(BOOL,Q)
  __DECLARE_VAR(LINT,CV)

  // FB private variables - TEMP, private and located variables
  R_TRIG CU_T;

} CTU_LINT;

// FUNCTION_BLOCK CTU_UDINT
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,CU)
  __DECLARE_VAR(BOOL,R)
  __DECLARE_VAR(UDINT,PV)
  __DECLARE_VAR(BOOL,Q)
  __DECLARE_VAR(UDINT,CV)

  // FB private variables - TEMP, private and located variables
  R_TRIG CU_T;

} CTU_UDINT;

// FUNCTION_BLOCK CTU_ULINT
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,CU)
  __DECLARE_VAR(BOOL,R)
  __DECLARE_VAR(ULINT,PV)
  __DECLARE_VAR(BOOL,Q)
  __DECLARE_VAR(ULINT,CV)

  // FB private variables - TEMP, private and located variables
  R_TRIG CU_T;

} CTU_ULINT;

// FUNCTION_BLOCK CTD
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,CD)
  __DECLARE_VAR(BOOL,LD)
  __DECLARE_VAR(INT,PV)
  __DECLARE_VAR(BOOL,Q)
  __DECLARE_VAR(INT,CV)

  // FB private variables - TEMP, private and located variables
  R_TRIG CD_T;

} CTD;

// FUNCTION_BLOCK CTD_DINT
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,CD)
  __DECLARE_VAR(BOOL,LD)
  __DECLARE_VAR(DINT,PV)
  __DECLARE_VAR(BOOL,Q)
  __DECLARE_VAR(DINT,CV)

  // FB private variables - TEMP, private and located variables
  R_TRIG CD_T;

} CTD_DINT;

// FUNCTION_BLOCK CTD_LINT
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,CD)
  __DECLARE_VAR(BOOL,LD)
  __DECLARE_VAR(LINT,PV)
  __DECLARE_VAR(BOOL,Q)
  __DECLARE_VAR(LINT,CV)

  // FB private variables - TEMP, private and located variables
  R_TRIG CD_T;

} CTD_LINT;

// FUNCTION_BLOCK CTD_UDINT
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,CD)
  __DECLARE_VAR(BOOL,LD)
  __DECLARE_VAR(UDINT,PV)
  __DECLARE_VAR(BOOL,Q)
  __DECLARE_VAR(UDINT,CV)

  // FB private variables - TEMP, private and located variables
  R_TRIG CD_T;

} CTD_UDINT;

// FUNCTION_BLOCK CTD_ULINT
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,CD)
  __DECLARE_VAR(BOOL,LD)
  __DECLARE_VAR(ULINT,PV)
  __DECLARE_VAR(BOOL,Q)
  __DECLARE_VAR(ULINT,CV)

  // FB private variables - TEMP, private and located variables
  R_TRIG CD_T;

} CTD_ULINT;

// FUNCTION_BLOCK CTUD
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,CU)
  __DECLARE_VAR(BOOL,CD)
  __DECLARE_VAR(BOOL,R)
  __DECLARE_VAR(BOOL,LD)
  __DECLARE_VAR(INT,PV)
  __DECLARE_VAR(BOOL,QU)
  __DECLARE_VAR(BOOL,QD)
  __DECLARE_VAR(INT,CV)

  // FB private variables - TEMP, private and located variables
  R_TRIG CD_T;
  R_TRIG CU_T;

} CTUD;

// FUNCTION_BLOCK CTUD_DINT
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,CU)
  __DECLARE_VAR(BOOL,CD)
  __DECLARE_VAR(BOOL,R)
  __DECLARE_VAR(BOOL,LD)
  __DECLARE_VAR(DINT,PV)
  __DECLARE_VAR(BOOL,QU)
  __DECLARE_VAR(BOOL,QD)
  __DECLARE_VAR(DINT,CV)

  // FB private variables - TEMP, private and located variables
  R_TRIG CD_T;
  R_TRIG CU_T;

} CTUD_DINT;

// FUNCTION_BLOCK CTUD_LINT
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,CU)
  __DECLARE_VAR(BOOL,CD)
  __DECLARE_VAR(BOOL,R)
  __DECLARE_VAR(BOOL,LD)
  __DECLARE_VAR(LINT,PV)
  __DECLARE_VAR(BOOL,QU)
  __DECLARE_VAR(BOOL,QD)
  __DECLARE_VAR(LINT,CV)

  // FB private variables - TEMP, private and located variables
  R_TRIG CD_T;
  R_TRIG CU_T;

} CTUD_LINT;

// FUNCTION_BLOCK CTUD_UDINT
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,CU)
  __DECLARE_VAR(BOOL,CD)
  __DECLARE_VAR(BOOL,R)
  __DECLARE_VAR(BOOL,LD)
  __DECLARE_VAR(UDINT,PV)
  __DECLARE_VAR(BOOL,QU)
  __DECLARE_VAR(BOOL,QD)
  __DECLARE_VAR(UDINT,CV)

  // FB private variables - TEMP, private and located variables
  R_TRIG CD_T;
  R_TRIG CU_T;

} CTUD_UDINT;

// FUNCTION_BLOCK CTUD_ULINT
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,CU)
  __DECLARE_VAR(BOOL,CD)
  __DECLARE_VAR(BOOL,R)
  __DECLARE_VAR(BOOL,LD)
  __DECLARE_VAR(ULINT,PV)
  __DECLARE_VAR(BOOL,QU)
  __DECLARE_VAR(BOOL,QD)
  __DECLARE_VAR(ULINT,CV)

  // FB private variables - TEMP, private and located variables
  R_TRIG CD_T;
  R_TRIG CU_T;

} CTUD_ULINT;

// FUNCTION_BLOCK TP
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,IN)
  __DECLARE_VAR(TIME,PT)
  __DECLARE_VAR(BOOL,Q)
  __DECLARE_VAR(TIME,ET)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(SINT,STATE)
  __DECLARE_VAR(BOOL,PREV_IN)
  __DECLARE_VAR(TIME,CURRENT_TIME)
  __DECLARE_VAR(TIME,START_TIME)

} TP;

// FUNCTION_BLOCK TON
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,IN)
  __DECLARE_VAR(TIME,PT)
  __DECLARE_VAR(BOOL,Q)
  __DECLARE_VAR(TIME,ET)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(SINT,STATE)
  __DECLARE_VAR(BOOL,PREV_IN)
  __DECLARE_VAR(TIME,CURRENT_TIME)
  __DECLARE_VAR(TIME,START_TIME)

} TON;

// FUNCTION_BLOCK TOF
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,IN)
  __DECLARE_VAR(TIME,PT)
  __DECLARE_VAR(BOOL,Q)
  __DECLARE_VAR(TIME,ET)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(SINT,STATE)
  __DECLARE_VAR(BOOL,PREV_IN)
  __DECLARE_VAR(TIME,CURRENT_TIME)
  __DECLARE_VAR(TIME,START_TIME)

} TOF;

// FUNCTION_BLOCK DERIVATIVE
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,RUN)
  __DECLARE_VAR(REAL,XIN)
  __DECLARE_VAR(TIME,CYCLE)
  __DECLARE_VAR(REAL,XOUT)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(REAL,X1)
  __DECLARE_VAR(REAL,X2)
  __DECLARE_VAR(REAL,X3)

} DERIVATIVE;

// FUNCTION_BLOCK HYSTERESIS
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,XIN1)
  __DECLARE_VAR(REAL,XIN2)
  __DECLARE_VAR(REAL,EPS_)
  __DECLARE_VAR(BOOL,Q)

  // FB private variables - TEMP, private and located variables

} HYSTERESIS;

// FUNCTION_BLOCK INTEGRAL
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,RUN)
  __DECLARE_VAR(BOOL,R1)
  __DECLARE_VAR(REAL,XIN)
  __DECLARE_VAR(REAL,X0)
  __DECLARE_VAR(TIME,CYCLE)
  __DECLARE_VAR(BOOL,Q)
  __DECLARE_VAR(REAL,XOUT)

  // FB private variables - TEMP, private and located variables

} INTEGRAL;

// FUNCTION_BLOCK PID
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,AUTO)
  __DECLARE_VAR(REAL,PV)
  __DECLARE_VAR(REAL,SP)
  __DECLARE_VAR(REAL,X0)
  __DECLARE_VAR(REAL,KP)
  __DECLARE_VAR(REAL,TR)
  __DECLARE_VAR(REAL,TD)
  __DECLARE_VAR(TIME,CYCLE)
  __DECLARE_VAR(REAL,XOUT)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(REAL,ERROR)
  INTEGRAL ITERM;
  DERIVATIVE DTERM;

} PID;

// FUNCTION_BLOCK RAMP
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,RUN)
  __DECLARE_VAR(REAL,X0)
  __DECLARE_VAR(REAL,X1)
  __DECLARE_VAR(TIME,TR)
  __DECLARE_VAR(TIME,CYCLE)
  __DECLARE_VAR(BOOL,BUSY)
  __DECLARE_VAR(REAL,XOUT)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(REAL,XI)
  __DECLARE_VAR(TIME,T)

} RAMP;

// FUNCTION_BLOCK RTC
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,IN)
  __DECLARE_VAR(DT,PDT)
  __DECLARE_VAR(BOOL,Q)
  __DECLARE_VAR(DT,CDT)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,PREV_IN)
  __DECLARE_VAR(TIME,OFFSET)
  __DECLARE_VAR(DT,CURRENT_TIME)

} RTC;

// FUNCTION_BLOCK SEMA
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,CLAIM)
  __DECLARE_VAR(BOOL,RELEASE)
  __DECLARE_VAR(BOOL,BUSY)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,Q_INTERNAL)

} SEMA;


//function renamed to (ENENO) version to avoid linker's module naming conflict in library which contains both with/without ENENO)
void R_TRIG_init_ENENO__(R_TRIG *data__, BOOL retain);
void R_TRIG_body_ENENO__(R_TRIG *data__);

void F_TRIG_init_ENENO__(F_TRIG *data__, BOOL retain);
void F_TRIG_body_ENENO__(F_TRIG *data__);

void SR_init_ENENO__(SR *data__, BOOL retain);
void SR_body_ENENO__(SR *data__);

void RS_init_ENENO__(RS *data__, BOOL retain);

void CTU_init_ENENO__(CTU *data__, BOOL retain);
void CTU_body_ENENO__(CTU *data__);

void CTU_DINT_init_ENENO__(CTU_DINT *data__, BOOL retain);
void CTU_DINT_body_ENENO__(CTU_DINT *data__);

void CTU_LINT_init_ENENO__(CTU_LINT *data__, BOOL retain);

void CTU_UDINT_init_ENENO__(CTU_UDINT *data__, BOOL retain);
void CTU_UDINT_body_ENENO__(CTU_UDINT *data__);

void CTU_ULINT_init_ENENO__(CTU_ULINT *data__, BOOL retain);
void CTU_ULINT_body_ENENO__(CTU_ULINT *data__);

void CTD_init_ENENO__(CTD *data__, BOOL retain);
void CTD_body_ENENO__(CTD *data__);

void CTD_DINT_init_ENENO__(CTD_DINT *data__, BOOL retain);
void CTD_DINT_body_ENENO__(CTD_DINT *data__);

void CTD_LINT_init_ENENO__(CTD_LINT *data__, BOOL retain);
void CTD_LINT_body_ENENO__(CTD_LINT *data__);

void CTD_UDINT_init_ENENO__(CTD_UDINT *data__, BOOL retain);
void CTD_UDINT_body_ENENO__(CTD_UDINT *data__);

void CTD_ULINT_init_ENENO__(CTD_ULINT *data__, BOOL retain);
void CTD_ULINT_body_ENENO__(CTD_ULINT *data__);

void CTUD_init_ENENO__(CTUD *data__, BOOL retain);
void CTUD_body_ENENO__(CTUD *data__);

void CTUD_DINT_init_ENENO__(CTUD_DINT *data__, BOOL retain);
void CTUD_DINT_body_ENENO__(CTUD_DINT *data__);

void CTUD_LINT_init_ENENO__(CTUD_LINT *data__, BOOL retain);
void CTUD_LINT_body_ENENO__(CTUD_LINT *data__);

void CTUD_UDINT_init_ENENO__(CTUD_UDINT *data__, BOOL retain);
void CTUD_UDINT_body_ENENO__(CTUD_UDINT *data__);

void CTUD_ULINT_init_ENENO__(CTUD_ULINT *data__, BOOL retain);
void CTUD_ULINT_body_ENENO__(CTUD_ULINT *data__);

void TP_init_ENENO__(TP *data__, BOOL retain);
void TP_body_ENENO__(TP *data__);

void TON_init_ENENO__(TON *data__, BOOL retain);
void TON_body_ENENO__(TON *data__);

void TOF_init_ENENO__(TOF *data__, BOOL retain);
void TOF_body_ENENO__(TOF *data__);

void DERIVATIVE_init_ENENO__(DERIVATIVE *data__, BOOL retain);
void DERIVATIVE_body_ENENO__(DERIVATIVE *data__);

void HYSTERESIS_init_ENENO__(HYSTERESIS *data__, BOOL retain);
void HYSTERESIS_body_ENENO__(HYSTERESIS *data__);

void INTEGRAL_init_ENENO__(INTEGRAL *data__, BOOL retain);
void INTEGRAL_body_ENENO__(INTEGRAL *data__);

void PID_init_ENENO__(PID *data__, BOOL retain);
void PID_body_ENENO__(PID *data__);

void RAMP_init_ENENO__(RAMP *data__, BOOL retain);
void RAMP_body_ENENO__(RAMP *data__);

void RTC_init_ENENO__(RTC *data__, BOOL retain);
void RTC_body_ENENO__(RTC *data__);

void SEMA_init_ENENO__(SEMA *data__, BOOL retain);
void SEMA_body_ENENO__(SEMA *data__);



//redirecting to original function names
#define R_TRIG_init__ 	R_TRIG_init_ENENO__
#define R_TRIG_body__		R_TRIG_body_ENENO__

#define F_TRIG_init__	F_TRIG_init_ENENO__
#define F_TRIG_body__	F_TRIG_body_ENENO__

#define SR_init__		SR_init_ENENO__
#define SR_body__		SR_body_ENENO__

#define RS_init__		RS_init_ENENO__
#define RS_body__		RS_body_ENENO__

#define CTU_init__		CTU_init_ENENO__
#define CTU_body__		CTU_body_ENENO__

#define CTU_DINT_init__		CTU_DINT_init_ENENO__
#define CTU_DINT_body__		CTU_DINT_body_ENENO__

#define CTU_LINT_init__		CTU_LINT_init_ENENO__
#define CTU_LINT_body__		CTU_LINT_body_ENENO__

#define CTU_UDINT_init__		CTU_UDINT_init_ENENO__
#define CTU_UDINT_body__		CTU_UDINT_body_ENENO__

#define CTU_ULINT_init__		CTU_ULINT_init_ENENO__
#define CTU_ULINT_body__		CTU_ULINT_body_ENENO__

#define CTD_init__		CTD_init_ENENO__
#define CTD_body__		CTD_body_ENENO__

#define CTD_DINT_init__		CTD_DINT_init_ENENO__
#define CTD_DINT_body__		CTD_DINT_body_ENENO__

#define CTD_LINT_init__		CTD_LINT_init_ENENO__
#define CTD_LINT_body__		CTD_LINT_body_ENENO__

#define CTD_UDINT_init__		CTD_UDINT_init_ENENO__
#define CTD_UDINT_body__		CTD_UDINT_body_ENENO__

#define CTD_ULINT_init__		CTD_ULINT_init_ENENO__
#define CTD_ULINT_body__		CTD_ULINT_body_ENENO__

#define CTUD_init__		CTUD_init_ENENO__
#define CTUD_body__		CTUD_body_ENENO__

#define CTUD_DINT_init__		CTUD_DINT_init_ENENO__
#define CTUD_DINT_body__		CTUD_DINT_body_ENENO__

#define CTUD_LINT_init__		CTUD_LINT_init_ENENO__
#define CTUD_LINT_body__		CTUD_LINT_body_ENENO__

#define CTUD_UDINT_init__		CTUD_UDINT_init_ENENO__
#define CTUD_UDINT_body__		CTUD_UDINT_body_ENENO__

#define CTUD_ULINT_init__		CTUD_ULINT_init_ENENO__
#define CTUD_ULINT_body__		CTUD_ULINT_body_ENENO__

#define TP_init__		TP_init_ENENO__
#define TP_body__		TP_body_ENENO__

#define TON_init__		TON_init_ENENO__
#define TON_body__		TON_body_ENENO__

#define TOF_init__		TOF_init_ENENO__
#define TOF_body__		TOF_body_ENENO__

#define DERIVATIVE_init__		DERIVATIVE_init_ENENO__
#define DERIVATIVE_body__		DERIVATIVE_body_ENENO__

#define HYSTERESIS_init__		HYSTERESIS_init_ENENO__
#define HYSTERESIS_body__		HYSTERESIS_body_ENENO__

#define INTEGRAL_init__		INTEGRAL_init_ENENO__
#define INTEGRAL_body__		INTEGRAL_body_ENENO__

#define PID_init__		PID_init_ENENO__
#define PID_body__		PID_body_ENENO__

#define RAMP_init__		RAMP_init_ENENO__
#define RAMP_body__		RAMP_body_ENENO__

#define RTC_init__		RTC_init_ENENO__
#define RTC_body__		RTC_body_ENENO__

#define SEMA_init__		SEMA_init_ENENO__
#define SEMA_body__		SEMA_body_ENENO__



#endif //_IEC_STD_FB_H

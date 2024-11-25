/* Small Device PLC
 * An SDCC (Small Device C Compiler) port for (MATIEC) implementaion of 
 * IEC 61131-3 standard.
 * based on MATIEC "lib c" (See the license below)
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
 * 6- most of functions are (reentrant) so, lib archive shall be compiled/linked with 
 *    "stack-auto" - for mcs51 target - or equivalent option.
 *
 * elabbassy2013@gmail.com
 * License: as below.
 */
 
/* copyright 2008 Edouard TISSERANT
 * copyright 2011 Mario de Sousa (msousa@fe.up.pt)
 *
 * Offered to the public under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser
 * General Public License for more details.
 *
 * This code is made available on the understanding that it will not be
 * used in safety-critical situations without a full and competent review.
 */

/****
 * IEC 61131-3 standard function library
 */

/* NOTE: This file is full of (what may seem at first) very strange macros.
 *       If you want to know what all these strange macros are doing,
 *       just parse this file through a C preprocessor (e.g. cpp), 
 *       and analyse the output!
 *       $gcc -E iec_std_lib.h 
 */

#ifndef _IEC_STD_LIB_H
#define _IEC_STD_LIB_H


#include <limits.h>
#include <float.h>
#include <math.h>
#include <stdint.h>
#include <ctype.h>
#include <time.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#ifdef DEBUG_IEC
#define DBG(...) printf(__VA_ARGS__);
#define DBG_TYPE(TYPENAME, name) __print_##TYPENAME(name);
#else
#define DBG(...)
#define DBG_TYPE(TYPENAME, name)
#endif

/*
 * Include type defs.
 */
#include "iec_types_all.h"

extern TIME __CURRENT_TIME;
extern BOOL __DEBUG;

/* TODO
typedef struct {
    __strlen_t len;
    u_int16_t body[STR_MAX_LEN];
} WSTRING;
*/
/*
# if __WORDSIZE == 64
#define __32b_sufix
#define __64b_sufix L
#else
#define __32b_sufix L
#define __64b_sufix LL
#endif
*/

# if __WORDSIZE == 64
#define __32b_sufix
#define __64b_sufix L
#else
#define __32b_sufix L
/* changed this from LL to L temporarily. It was causing a bug when compiling resulting code with gcc.
 * I have other things to worry about at the moment.. 
 */
#define __64b_sufix L   
#endif


#define __lit(type,value,...) (type)value##__VA_ARGS__
// Keep this macro expention step to let sfx(__VA_ARGS__) change into L or LL
#define __literal(type,value,...) __lit(type,value,__VA_ARGS__)

#define __BOOL_LITERAL(value) __literal(BOOL,value)
#define __SINT_LITERAL(value) __literal(SINT,value)
#define __INT_LITERAL(value) __literal(INT,value)
#define __DINT_LITERAL(value) __literal(DINT,value,__32b_sufix)
#define __LINT_LITERAL(value) __literal(LINT,value,__64b_sufix)
#define __USINT_LITERAL(value) __literal(USINT,value)
#define __UINT_LITERAL(value) __literal(UINT,value)
#define __UDINT_LITERAL(value) __literal(UDINT,value,__32b_sufix)
#define __ULINT_LITERAL(value) __literal(ULINT,value,__64b_sufix)
#define __REAL_LITERAL(value) __literal(REAL,value,__32b_sufix)
#define __LREAL_LITERAL(value) __literal(LREAL,value,__64b_sufix)
#define __TIME_LITERAL(value) __literal(TIME,value)
#define __DATE_LITERAL(value) __literal(DATE,value)
#define __TOD_LITERAL(value) __literal(TOD,value)
#define __DT_LITERAL(value) __literal(DT,value)
#define __STRING_LITERAL(count,value) (STRING){count,value}
#define __BYTE_LITERAL(value) __literal(BYTE,value)
#define __WORD_LITERAL(value) __literal(WORD,value)
#define __DWORD_LITERAL(value) __literal(DWORD,value,__32b_sufix)
#define __LWORD_LITERAL(value) __literal(LWORD,value,__64b_sufix)


typedef union __IL_DEFVAR_T {
    BOOL    BOOLvar;

    SINT    SINTvar;
    INT     INTvar;
    DINT    DINTvar;
    LINT    LINTvar;

    USINT   USINTvar;
    UINT    UINTvar;
    UDINT   UDINTvar;
    ULINT   ULINTvar;

    BYTE    BYTEvar;
    WORD    WORDvar;
    DWORD   DWORDvar;
    LWORD   LWORDvar;

    REAL    REALvar;
    LREAL   LREALvar;

    TIME    TIMEvar;
    TOD TODvar;
    DT  DTvar;
    DATE    DATEvar;
} __IL_DEFVAR_T;


/**********************************************************************/
/**********************************************************************/
/*****                                                            *****/
/*****      Some helper functions...                              *****/
/*****                     ...used later:                         *****/
/*****    - when declaring the IEC 61131-3 standard functions     *****/
/*****    - in the C source code itself in SFC and ST expressions *****/
/*****                                                            *****/
/**********************************************************************/
/**********************************************************************/


/****************************/
/* Notify IEC runtime error */
/****************************/

/* function that generates an IEC runtime error */
inline void __iec_error(void);


/*******************/
/* Math Operations */
/*******************/

inline double __expt(double in1, double in2);


/*******************************/
/* Time normalization function */
/*******************************/

inline void __normalize_timespec (IEC_TIMESPEC *ts);
/**********************************************/
/* Time conversion to/from timespec functions */
/**********************************************/
/* NOTE: The following function was turned into a macro, so it could be used to initialize the initial value of TIME variables.
 *       Since each macro parameter is evaluated several times, the macro may result in multiple function invocations if an expression
 *       containing a function invocation is passed as a parameter. However, currently matiec only uses this conversion macro with 
 *       constant literals, so it is safe to change it into a macro.
 */
/* NOTE: I (Mario - msousa@fe.up.pt) believe that the following function contains a bug when handling negative times.
 *       The equivalent macro has this bug fixed.
 *       e.g.;
 *          T#3.8s
 *       using the function, will result in a timespec of 3.8s !!!: 
 *          tv_sec  =  4               <-----  1 *  3.8           is rounded up when converting a double to an int!
 *          tv_nsec = -200 000 000     <-----  1 * (3.8 - 4)*1e9
 * 
 *         -T#3.8s
 *       using the function, will result in a timespec of -11.8s !!!: 
 *          tv_sec  = -4                 <-----  -1 *  3.8 is rounded down when converting a double to an int!
 *          tv_nsec = -7 800 000 000     <-----  -1 * (3.8 - -4)*1e9
 */
/* NOTE: Due to the fact that the C compiler may round a tv_sec number away from zero, 
 *       the following macro may result in a timespec that is not normalized, i.e. with a tv_sec > 0, and a tv_nsec < 0 !!!!
 *       This is due to the rounding that C compiler applies when converting a (long double) to a (long int).
 *       To produce normalized timespec's we need to use floor(), but we cannot call any library functions since we want this macro to be 
 *       useable as a variable initializer.
 *       VAR x : TIME = T#3.5h; END_VAR --->  IEC_TIME x = __time_to_timespec(1, 0, 0, 0, 3.5, 0);
 */
/*
 inline IEC_TIMESPEC __time_to_timespec(int sign, double mseconds, double seconds, double minutes, double hours, double days) {
  IEC_TIMESPEC ts;

  // sign is 1 for positive values, -1 for negative time...
  long double total_sec = ((days*24 + hours)*60 + minutes)*60 + seconds + mseconds/1e3;
  if (sign >= 0) sign = 1; else sign = -1;
  ts.tv_sec = sign * (long int)total_sec;
  ts.tv_nsec = sign * (long int)((total_sec - ts.tv_sec)*1e9);

  return ts;
}
*/
/* NOTE: Unfortunately older versions of ANSI C (e.g. C99) do not allow explicit identification of elements in initializers
 *         e.g.  {tv_sec = 1, tv_nsec = 300}
 *       They are therefore commented out. This however means that any change to the definition of IEC_TIMESPEC may require this
 *       macro to be updated too!
 */


//function wrapper for SDCC's current version is not supporting "compound literals"
#define __time_to_timespec *__ptime_to_timespec
inline IEC_TIMESPEC* __ptime_to_timespec(int sign, double mseconds, double seconds, double minutes, double hours, double days);

/* NOTE: The following function was turned into a macro, so it could be used to initialize the initial value of TOD (TIME_OF_DAY) variables */
/* NOTE: many (but not all) of the same comments made regarding __time_to_timespec() are also valid here, so go and read those comments too!*/
/*
 inline IEC_TIMESPEC __tod_to_timespec(double seconds, double minutes, double hours) {
  IEC_TIMESPEC ts;

  long double total_sec = (hours*60 + minutes)*60 + seconds;
  ts.tv_sec = (long int)total_sec;
  ts.tv_nsec = (long int)((total_sec - ts.tv_sec)*1e9);

  return ts;
}
*/

inline IEC_TIMESPEC* __ptod_to_timespec(double seconds, double minutes, double hours);
#define __tod_to_timespec *__ptod_to_timespec


#define EPOCH_YEAR 1970
#define SECONDS_PER_MINUTE 60
#define SECONDS_PER_HOUR (60 * SECONDS_PER_MINUTE)
#define SECONDS_PER_DAY (24 * SECONDS_PER_HOUR)
#define __isleap(year) \
  ((year) % 4 == 0 && ((year) % 100 != 0 || (year) % 400 == 0))

//renamed to tm1 due to conflict with tm in SDCC's time.h
typedef struct {
	int tm_sec;			/* Seconds.	[0-60] (1 leap second) */
	int tm_min;			/* Minutes.	[0-59] */
	int tm_hour;			/* Hours.	[0-23] */
	int tm_day;			/* Day.		[1-31] */
	int tm_mon;			/* Month.	[0-11] */
	int tm_year;			/* Year	*/
} tm1; 

inline tm1* pconvert_seconds_to_date_and_time(long int seconds);
#define convert_seconds_to_date_and_time *pconvert_seconds_to_date_and_time

inline IEC_TIMESPEC* __pdate_to_timespec(int day, int month, int year);
#define __date_to_timespec *__pdate_to_timespec

inline IEC_TIMESPEC* __pdt_to_timespec(double seconds, double minutes, double hours, int day, int month, int year);
#define __dt_to_timespec *__pdt_to_timespec

/*******************/
/* Time operations */
/*******************/

#define __time_cmp(t1, t2) (t2.tv_sec == t1.tv_sec ? t1.tv_nsec - t2.tv_nsec : t1.tv_sec - t2.tv_sec)
#define __ptime_cmp(t1, t2) (t2->tv_sec == t1->tv_sec ? t1->tv_nsec - t2->tv_nsec : t1->tv_sec - t2->tv_sec)

#define __time_add(T1, T2) *__ptime_add(&(T1), &(T2))
inline TIME* __ptime_add(TIME *IN1, TIME *IN2);

#define __time_sub(T1, T2) *__ptime_sub(&(T1), &(T2))
inline TIME* __ptime_sub(TIME *IN1, TIME *IN2);

inline TIME* __ptime_mul(TIME *IN1, LREAL IN2);
#define __time_mul(IN1, IN2) *__ptime_mul(&(IN1), IN2)

inline TIME* __ptime_div(TIME *IN1, LREAL IN2);
#define __time_div(IN1, IN2) *__ptime_div(&(IN1), IN2)


/***************/
/* Convertions */
/***************/
    /*****************/
    /*  REAL_TO_INT  */
    /*****************/
 inline LINT __real_round(LREAL IN);
 inline LINT __preal_to_sint(LREAL IN);
 inline LINT __preal_to_uint(LREAL IN);
 inline LINT __real_to_sint(LREAL IN);
 inline LWORD __real_to_bit(LREAL IN);
 inline ULINT __real_to_uint(LREAL IN);

    /***************/
    /*  TO_STRING  */
    /***************/
/*  inline STRING __bool_to_string(BOOL IN);
 inline STRING __bit_to_string(LWORD IN);
 inline STRING __real_to_string(LREAL IN);
 inline STRING __sint_to_string(LINT IN);
 inline STRING __uint_to_string(ULINT IN); */
    /***************/
    /* FROM_STRING */
    /***************/
/*  inline BOOL __string_to_bool(STRING IN);

 inline LINT __pstring_to_sint(STRING* IN);

 inline LINT  __string_to_sint(STRING IN);
 inline LWORD __string_to_bit (STRING IN);
 inline ULINT __string_to_uint(STRING IN);
 inline LREAL __string_to_real(STRING IN); */

    /***************/
    /*   TO_TIME   */
    /***************/
 inline TIME*    __pint_to_time(LINT IN);
 #define __int_to_time *__pint_to_time
 inline TIME*   __preal_to_time(LREAL IN);
 #define __real_to_time *__preal_to_time
 
// inline TIME __string_to_time(STRING IN);
 

    /***************/
    /*  FROM_TIME  */
    /***************/
 inline LREAL __ptime_to_real(TIME *IN);
 #define __time_to_real(IN) __ptime_to_real(&IN)
 
 inline LINT __ptime_to_int(TIME *IN);
 #define __time_to_int(IN) __ptime_to_int(&IN)
 
/*  inline STRING __time_to_string(TIME IN);
 inline STRING __date_to_string(DATE IN);
 inline STRING __tod_to_string(TOD IN);
 inline STRING __dt_to_string(DT IN); */

    /**********************************************/
    /*  [ANY_DATE | TIME] _TO_ [ANY_DATE | TIME]  */
    /**********************************************/

 inline TOD* __pdate_and_time_to_time_of_day(DT *IN);
 #define __date_and_time_to_time_of_day(IN) *__pdate_and_time_to_time_of_day(&IN)
  
 inline DATE* __pdate_and_time_to_date(DT *IN);
 #define __date_and_time_to_date(IN) *__pdate_and_time_to_date(&IN)
    /*****************/
    /*  FROM/TO BCD  */
    /*****************/

 inline BOOL __test_bcd(LWORD IN) ;

 inline ULINT __bcd_to_uint(LWORD IN);

 inline LWORD __uint_to_bcd(ULINT IN);


    /************/
    /*  MOVE_*  */
    /************/

/* some helpful __move_[ANY] functions, used in the *_TO_** and MOVE  standard functions */
/* e.g. __move_BOOL, __move_BYTE, __move_REAL, __move_TIME, ... */
/* #define __move_(TYPENAME)\
 inline TYPENAME __move_##TYPENAME(TYPENAME op1) {return op1;}
__ANY(__move_) */
#define __move_REAL(op1) op1
#define __move_LREAL(op1) op1
#define __move_SINT(op1) op1
#define __move_INT(op1) op1
#define __move_DINT(op1) op1
#define __move_LINT(op1) op1
#define __move_USINT(op1) op1
#define __move_UINT(op1) op1
#define __move_UDINT(op1) op1
#define __move_ULINT(op1) op1
#define __move_TIME(op1) op1
#define __move_BYTE(op1) op1
#define __move_WORD(op1) op1
#define __move_DWORD(op1) op1
#define __move_LWORD(op1) op1
#define __move_BOOL(op1) op1
#define __move_STRING(op1) op1
#define __move_DATE(op1) op1
#define __move_TOD(op1) op1
#define __move_DT(op1) op1








#include "iec_std_functions.h"

#ifdef  DISABLE_EN_ENO_PARAMETERS
  #include "iec_std_FB_no_ENENO.h"
#else
  #include "iec_std_FB.h"
#endif

#endif /* _IEC_STD_LIB_H */

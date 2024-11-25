About:

An SDCC (Small Device C Compiler) port for (MATIEC) implementaion of 
IEC 61131-3 standard.
based on MATIEC "lib c"
Challenges and Limitations:
the proting attempt is as follows:
1- code part is stripped from header files, function prototypes
   was kept with a little modifications if nessessary.
2- every individual function is written to a seperate file and linked to "lib"
   archive for the sake of SDCC Linker's code optimization.
3- the current version of SDCC (4.4.0) dose not support: (a)Compound  
   literals, (b)’double’ precision floating point ('float' is used instead)
   and,(c)initialization of structure arrays.
4- due to the limitations mentiond above:
   (a) DATE/TIME manuplation functions (ex: SUB_TIME, EQ_DATE, ...) were 
	 changed to "STATIC" function type with (2) arguments (instead originally 
	 variadic implementaion), this will lead to compile-time error 
	 if more arguments passed.
   (b) "SFC" language is not supported yet.
   (c) explicitly casting for types (TIME, DATE, DT, DOT) generated by "iec2c"
	   must be removed. (eg: by python script or shell commands)
5- 'STRING' manuplation functions is not supported.
6- most of functions are (reentrant) so, lib archive shall be compiled/linked with 
   "stack-auto" - for mcs51 target - or equivalent option.
   
Usage:
- the repo contains pre-built *.lib archives for mcs51 target, for different targets or
  other build options just run:
  make all
- in your SDCC porject add the (3) generated liberaries to linker search path:

  LIBPATH = path_to_libraries
  LINK_LIBS = -liec_std_functions.lib -liec_std_FB.lib -liec_std_lib.lib
  LFLAGS = -L$(LIBPATH) $(LINK_LIBS)
- add (inc) folder to compiler search path

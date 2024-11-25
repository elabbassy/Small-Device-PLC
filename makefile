TARGET1 = iec_std_functions.lib
TARGET2 = iec_std_FB.lib
TARGET3 = iec_std_lib.lib

T1_CFILES_P1  = $(wildcard iecstdfunctions/part1/*.c)
T1_CFILES_P2  = $(wildcard iecstdfunctions/part2/*.c)
T1_RFILES_P1  = $(patsubst iecstdfunctions/part1/%, obj1/%,$(T1_CFILES_P1:.c=.rel))
T1_RFILES_P2  = $(patsubst iecstdfunctions/part2/%, obj1/%,$(T1_CFILES_P2:.c=.rel))

T2_CFILES  = $(wildcard src_stdfb/*.c)
T2_RFILES  = $(patsubst src_stdfb/%, obj2/%,$(T2_CFILES:.c=.rel))

T3_CFILES  = $(wildcard src_stdlib/*.c)
T3_RFILES  = $(patsubst src_stdlib/%, obj3/%,$(T3_CFILES:.c=.rel))

INCLUDE    = -I"inc"
INCLUDE    += -I"."

# Toolchain
CC         = sdcc
AR 		   = sdar
ASM        = sdas8051 
#disable warnings
NO_WARNINGS = --disable-warning 126 --disable-warning 93

# Compiler Flags
CFLAGS  = -mmcs51 --std-c23 --model-large --stack-auto --opt-code-speed  $(INCLUDE) $(NO_WARNINGS) -lliblonglong.lib -llibsdcc.lib

ASMFLAGS  = -plosgff

CLEAN   = del /q obj
	
obj1/%.rel : iecstdfunctions/part1/%.c
	@echo "Compiling $< ..."
	@$(CC) -c $(CFLAGS) $< -o $@
	
obj1/%.rel : iecstdfunctions/part2/%.c
	@echo "Compiling $< ..."
	@$(CC) -c $(CFLAGS) $< -o $@
	
obj2/%.rel : src_stdfb/%.c
	@echo "Compiling $< ..."
	@$(CC) -c $(CFLAGS) $< -o $@

obj3/%.rel : src_stdlib/%.c
	@echo "Compiling $< ..."
	@$(CC) -c $(CFLAGS) $< -o $@

all: lib1 lib2 lib3
	
lib1: lib1_p1 lib1_p2
	
lib1_p1: $(T1_RFILES_P1)
	@echo "Building $(TARGET1) ..."
	@$(AR)  -rc $(TARGET1)  $(T1_RFILES_P1) 

lib1_p2: $(T1_RFILES_P2)
	@echo "Building $(TARGET1) ..."
	@$(AR)  -rc $(TARGET1)  $(T1_RFILES_P2) 

lib2: $(T2_RFILES)
	@echo "Building $(TARGET2) ..."
	@$(AR)  -rc $(TARGET2)  $(T2_RFILES) 

lib3: $(T3_RFILES)
	@echo "Building $(TARGET3) ..."
	@$(AR)  -rc $(TARGET3)  $(T3_RFILES) 

clean:
	@echo "Cleaning all up ..."
	@$(CLEAN)
	del $(TARGET1)
	del $(TARGET2)
	del $(TARGET3)
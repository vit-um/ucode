# compiler to use 
CC = clang

# parameters required by the task
NAME = uls
LIB = libmx.a
DHDR = inc/
DSRC = src/
DOBJ = obj/
LMXD = libmx/

SRC = $(wildcard $(DSRC)*.c)
OBJ = $(SRC:$(DSRC)%.c=$(DOBJ)%.o)
LIB_PATH = -L$(LMXD) -lmx

# flags to pass compiler
WFLAGS = -Wall -Wextra -Werror -Wpedantic
LFLAGS = -Iinc -Ilibmx/inc
CFLAGS = -Ofast -march=native -fomit-frame-pointer -flto
DFLAGS = -O0 -g3 -glldb -ftrapv -fno-omit-frame-pointer -fsanitize=address,undefined

COMPILE = $(CC) -std=c11 -pipe $(WFLAGS) $(LFLAGS)
TARGET = build

R = \033[1;91m
G = \033[1;92m
Y = \033[1;93m
B = \033[1;94m
M = \033[1;95m
C = \033[1;96m
S = \033[38;5;45;1m
D = \033[0m
F = \033[5m
A = \033[A
K = \033[K

all: $(NAME)

# default target  $(CFLAGS)
$(NAME): $(DOBJ) $(OBJ)
	@make -s -C$(LMXD) -f Makefile all 
	@printf "$K$G COMPILING $Y[$M$(TARGET)$Y] $R$(NAME)$D\r"
	@$(COMPILE) $(OBJ) -o $(NAME) $(LIB_PATH)
	@printf "$K$GProgram successfully compiled!$D\n"

$(DOBJ):
	@mkdir -p $@

$(DOBJ)%.o: $(DSRC)%.c
	@printf "$K$G COMPILING $Y[$M$(TARGET)$Y] $B$(<:$(DSRC)%=%)$D\r"
	@$(COMPILE) -o $@ -c $<

debug:
	@make -s -C$(LMXD) -f Makefile debug clean
	@mkdir -p $(DOBJ)
	@$(COMPILE) $(DFLAGS) -c $(DSRC)*.c
	@mv *.o $(DOBJ)
	@printf "$K$G COMPILING $Y[$MDebug mode$Y] $R$(NAME)$D\r"
	@$(COMPILE) $(DFLAGS) $(OBJ) -o $(NAME) $(LIB_PATH)
	@printf "$K$YProgram compiled in debug mode!$D\n"
	@rm -rf $(DOBJ)
	@rm -rf $(LMXD)$(LIB)

clean:
	@rm -rf $(DOBJ)
	@rm -rf $(LMXD)$(LIB)
	@printf "$SAll cleaned$D\n"
	
uninstall: clean
	@rm -f $(NAME)
	@printf "$(NAME) \033[31;1muninstalled\033[0m\n"

reinstall: uninstall all
	
.PHONY: all clean uninstall reinstall $(NAME) debug

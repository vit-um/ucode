# compiler to use 
CC = clang

# parameters required by the task
NAME = ush
LIB = libmx.a
DHDR = inc/
DSRC = src/
DOBJ = obj/
LMXD = libmx/
DOBJ_D = obj_debug/

DIRS = $(notdir $(wildcard $(DSRC)*))
FILES = $(foreach dir, $(DIRS), $(basename $(wildcard $(DSRC)$(dir)/*.c)))
SRC	= $(FILES:%=%.c)
OBJ	= $(SRC:$(DSRC)%.c=$(DOBJ)%.o)
OBJ_D = $(SRC:$(DSRC)%.c=$(DOBJ_D)%.o)
INC_H = $(wildcard $(DHDR)*.h)


LIB_PATH = -L$(LMXD) -lmx -ltermcap

# flags to pass compiler
WFLAGS = -Wall -Wextra -Werror -Wpedantic
LFLAGS = -Iinc -Ilibmx/inc
CFLAGS = -Ofast -march=native -fomit-frame-pointer -flto
DFLAGS = -O0 -g3 -glldb -ftrapv -fno-omit-frame-pointer -fsanitize=address,undefined

COMPILE = $(CC) -std=c11 -pipe $(WFLAGS) $(LFLAGS)
TARGET = build

#interesting color: \033[1;5;36m
#red color: \033[1;91m

R = \033[1;31m
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

BEEP = \007

all: $(NAME)

# default target  $(CFLAGS)
$(NAME): $(DOBJ) $(OBJ)
	@make -s -C$(LMXD) -f Makefile all 
	@printf "$K$G COMPILING $Y[$M$(TARGET)$Y] $R$(NAME)$D\r"
	@$(COMPILE) $(OBJ) -o $@ $(LIB_PATH)
	@printf "$K$M$(NAME) $(BEEP)$Gsuccessfully compiled$D\n"

$(DOBJ):
	@mkdir -p $@ 
	@mkdir -p $(foreach dir, $(DIRS), $(DOBJ)$(dir))

$(DOBJ)%.o: $(DSRC)%.c $(INC_H) 
	@$(COMPILE) -o $@ -c $<
	@printf "$K$G COMPILING $Y[$M$(TARGET)$Y] $B$(<:$(DSRC)%=%)$D\r"


debug: $(DOBJ_D) $(OBJ_D)
	@make -s -C$(LMXD) -f Makefile debug clean
	@printf "$K$G COMPILING $Y[$Mdebug mode$Y] $R$(NAME)$D\r"
	@$(COMPILE) $(DFLAGS) $(OBJ_D) -o $(NAME) $(LIB_PATH)
	@printf "$K$M$(NAME) $Ysuccessfully compiled in debug mode$D\n"

$(DOBJ_D):
	@mkdir -p $(DOBJ_D) 
	@mkdir -p $(foreach dir, $(DIRS), $(DOBJ_D)$(dir))

$(DOBJ_D)%.o: $(DSRC)%.c $(INC_H) 
	@$(COMPILE) $(DFLAGS) -o $@ -c $<
	@printf "$K$G COMPILING $Y[$Mdebug mode$Y] $B$(<:$(DSRC)%=%)$D\r"

clean:
	@rm -rf $(DOBJ)
	@rm -rf $(DOBJ_D)
	@rm -rf $(LMXD)$(LIB)
	@printf "$Gall cleaned$D\n"
	
uninstall: clean
	@rm -f $(NAME)
	@printf "$M$(NAME) $(BEEP)$Runinstalled$D\n"

reinstall: uninstall all

.PHONY: all clean uninstall reinstall $(NAME) debug

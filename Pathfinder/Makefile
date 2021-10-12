# compiler to use 
CC = clang

# flags to pass compiler
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic
DFLAGS = -g3 -fsanitize=address,undefined

# parameters required by the task
NAME = pathfinder
DHDR = inc
DSRC = src
DOBJ = obj

LMXD = libmx
LMXA =	$(LMXD)/libmx.a
LMXI =	$(LMXD)/inc


# space-separated list of header files
HDRS = $(wildcard $(LMXI)/*.h)

# space-separated list of source files
SRCS = $(wildcard $(DSRC)/*.c)
#SRCS = $(DSRC)/main.c \
#$(DSRC)/mx_validation.c \
#$(DSRC)/mx_invalid_line.c

# automatically generated list of object files
OBJS = $(notdir $(SRCS:.c=.o))

all: $(NAME) clean

# default target
$(NAME): $(DOBJ)
	@make -s -C$(LMXD) -f Makefile all 
	@cp $(HDRS) $(DHDR)
	@$(CC) $(CFLAGS) -I$(DHDR) -c $(SRCS)
	@mv $(OBJS) $(DOBJ)
	@$(CC) $(CFLAGS) -I$(DHDR) -I$(LMXI) -o $(NAME) $(DOBJ)/*.o -L$(LMXD) -lmx
	@printf "\r\33[2K$@ \033[32;1mcreated\033[0m\n"

debug: $(DOBJ)
	@make -s -C$(LMXD) -f Makefile all
	@cp $(HDRS) $(DHDR)
	@$(CC) $(CFLAGS) $(DFLAGS) -I $(DHDR) -c $(SRCS)
	@mv $(OBJS) $(DOBJ)
	@$(CC) $(CFLAGS) $(DFLAGS) -I $(DHDR) -o $(NAME) $(DOBJ)/*.o -L$(LMXD) -lmx
	@printf "\r\33[2K$(NAME) \033[32;1mcreated in debug mode\033[0m\n"

$(DOBJ):
	@mkdir -p $(DOBJ)

clean:
	@rm -rf $(DOBJ)
	@rm -f $(DHDR)/libmx.h
	@rm -f $(LMXA)
	@rm -rf $(LMXD)/$(DOBJ)
	@printf "\r\033[32;1mall cleaned\033[0m\n"
	
uninstall: clean
	@rm -f $(NAME)
	@printf "$(NAME) \033[31;1muninstalled\033[0m\n"

reinstall: uninstall all
	
.PHONY: all clean uninstall reinstall $(NAME) debug

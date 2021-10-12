# compiler to use 
CC = gcc

# flags to pass compiler
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic
DFLAGS = -g3 -fsanitize=address,undefined
## LDFLAGS = -Wl,-rpath=/home/vit/TrackC/Libmx

# parameters required by the task
NAME = libmx.a
DHDR = inc
DSRC = src
DOBJ = obj

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

# space-separated list of header files
HDRS = $(notdir $(wildcard $(DHDR)/*.h))

# space-separated list of source files
SRCS = $(wildcard $(DSRC)/*.c)
#SRCSL = $(notdir $(wildcard $(DSRC)/*.c))


# automatically generated list of object files
OBJS = $(notdir $(SRCS:.c=.o))

all: $(NAME) clean

# default target
$(NAME): $(DOBJ)
	@$(CC) $(CFLAGS) -I $(DHDR) -c $(SRCS)
	@$(AR) rc $(NAME) $(OBJS)
	@mv $(OBJS) $(DOBJ)
	@printf "$K$M$@ $Gcreated$D\n"

$(DOBJ):
	@mkdir -p $(DOBJ)

debug: $(DOBJ)
	@$(CC) $(CFLAGS) $(DFLAGS) -I $(DHDR) -c $(SRCS)
	@$(AR) rc $(NAME) $(OBJS)
	@mv $(OBJS) $(DOBJ)
	@printf "\r\33[2K$M$(NAME) \033[1;93mcreated in debug mode\033[0m\n"

clean:
	@rm -rf $(DOBJ)
	@rm -f $(OBJS)

uninstall:
	@rm -rf $(DOBJ)
	@rm -f $(NAME)

reinstall: uninstall $(NAME)

	
.PHONY: all clean uninstall reinstall $(NAME) debug

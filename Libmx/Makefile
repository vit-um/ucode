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


# space-separated list of header files
HDRS = $(notdir $(wildcard $(DHDR)/*.h))

# space-separated list of source files
SRCS = $(wildcard $(DSRC)/*.c)
#SRCSL = $(notdir $(wildcard $(DSRC)/*.c))


# automatically generated list of object files
OBJS = $(notdir $(SRCS:.c=.o))

all: $(NAME)

# default target
$(NAME): $(DOBJ)
	@$(CC) $(CFLAGS) -I $(DHDR) -c $(SRCS)
	@$(AR) rc $(NAME) $(OBJS)
	@mv $(OBJS) $(DOBJ)

$(DOBJ):
	@mkdir -p $(DOBJ)

debug: $(NAME)
	@$(CC) $(CFLAGS) $(DFLAGS) -I $(DHDR) -c *.c 
	@$(CC) $(CFLAGS) $(DFLAGS) -I $(DHDR) -o main *.o -L. -lmx
	@rm -f main.o

clean:
	@rm -rf $(DOBJ)
	@rm -f $(OBJS)

uninstall:
	@rm -rf $(DOBJ)
	@rm -f $(NAME)

reinstall: uninstall $(NAME)

	
.PHONY: all clean uninstall reinstall $(NAME) debug

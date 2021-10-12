CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic -lncurses
DFLAGS = $(CFLAGS) -g3 -fsanitize=address,undefined
NAME = matrix_rain
SRC_DIR = src/

SRC = $(wildcard $(SRC_DIR)*.c)

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) -Iinc $(SRC) -o $(NAME)

debug:
	@$(CC) $(DFLAGS) -Iinc $(SRC) -o $(NAME)

uninstall:
	@rm -rf $(NAME)

reinstall: uninstall $(NAME)

.PHONY: debug $(NAME) reinstall uninstall

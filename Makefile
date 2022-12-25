##list = ft_putchar_d.c ft_puthex.c ft_putchar_p.c ft_putchar_s.c ft_putchar_u.c ft_uitoa.c ft_putchar_x.c ft_printf.c
DEFAULT = \033[0;39m
RED		= \033[0;91m
GREEN	= \033[0;92m
BLUE	= \033[0;94m
MAGENTA	= \033[0;95m

BIN		= fd_print.a
NAME	= $(BIN_DIR)/$(BIN)
CC		= gcc -I inc/
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f
AR		= ar rcs

SRC_DIR	= src
OBJ_DIR	= obj
INC_DIR	= inc
BIN_DIR	= bin

SRC		= $(shell find src -type f -name "*.c" | cut -c 5-)
OBJ		= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: $(NAME)
	@echo "$(MAGENTA)$(BIN) created$(DEFAULT)"

exec: create_dirs $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o fd_printf_exec

$(NAME): create_dirs $(OBJ)
	@$(AR) $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@if [ -d "$(OBJ_DIR)" ]; then \
		$(RM) -r $(OBJ_DIR); \
		echo "$(RED)fd_printf$(BLUE) objects removed.$(GREEN)"; \
	else \
		echo "$(RED)fd_printf$(BLUE) objects already removed.$(GREEN)"; \
	fi

fclean:
	@if [ -d "$(OBJ_DIR)" ]; then \
		$(RM) -r $(OBJ_DIR); \
		echo "$(RED)fd_printf$(BLUE) objects removed.$(GREEN)"; \
	else \
		echo "$(RED)fd_printf$(BLUE) objects already removed.$(GREEN)"; \
	fi
	@if [ -d "$(BIN_DIR)" ]; then \
		$(RM) -r $(BIN_DIR); \
		echo "$(RED)$(BIN)$(BLUE) removed.$(GREEN)"; \
	else \
		echo "$(RED)$(BIN)$(BLUE) already removed.$(GREEN)"; \
	fi
	@if [ -f "fd_printf_exec" ]; then \
		$(RM) fd_printf_exec; \
		echo "$(RED)fd_printf_exec$(BLUE) removed.$(GREEN)"; \
	else \
		echo "$(RED)fd_printf_exec$(BLUE) already removed.$(GREEN)"; \
	fi

re: fclean all

create_dirs:
	@echo "$(BLUE)Creating fd_printf directories...$(GREEN)"
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(BIN_DIR)
	@echo "$(GREEN)Compiling fd_printf...$(BLUE)"

.PHONY: all clean fclean re create_dirs

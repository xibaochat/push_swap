MAKEFLAGS += --no-print-directory

NAME = checker

SRCS_PATH = push_swap_checker

CC_FLAGS = -Werror -Wextra -Wall

SRC = main.c init_stack.c ft_stack_free.c check_arg.c \
		get_instruction_and_sort.c check_is_sorted.c \
		do_instruction.c do_instruction2.c

SRC_PATH = $(addprefix $(SRCS_PATH)/,$(SRC))

OBJ = $(SRC:.c=.o)

OBJ_DIR = ./objects

OBJS = $(addprefix $(OBJ_DIR)/,$(OBJ))

HEADER_DIR = include

LIBFT_DIR = libft

LIBFT_A = $(LIBFT_DIR)/libft.a


BLINK=\e[5m
RED=\033[91m
ORANGE=\e[38;5;202m
PURPLE=\e[38;5;57m
BLUE=\033[94m
DARK_YELLOW=\033[0;33m
YELLOW=\033[93m
GREEN=\033[0;32m
NC=\033[0;0m

all:	libft_compile
		@mkdir -p $(OBJ_DIR)
		@$(CC) $(CC_FLAGS) -I $(HEADER_DIR) -c $(SRC_PATH)
		@mv $(OBJ) $(OBJ_DIR)
		@$(CC) $(CC_FLAGS) $(OBJS) -L ./libft -lft -o $(NAME)
		@printf "${BLUE}Checker${NC}:      ${DARK_YELLOW}Compilation is done    ${YELLOW}%-15.15s${NC}\n"

libft_compile:
		@make -C ./libft all

clean : libft_clean
		@rm -fr $(OBJS) $(OBJ_DIR)
		@printf "${BLUE}PROJECT${NC}:      ${GREEN}Cleaned${NC}\n"
libft_clean:
		@make -C ./libft clean

fclean: clean libft_fclean
		@rm -f $(NAME)
		@rm -fr $(OBJS) $(OBJ_DIR)
		@rm -f **/*~

libft_fclean:
		@make -C ./libft fclean

re: fclean all

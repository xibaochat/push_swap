MAKEFLAGS += --no-print-directory

NAME = checker
NAME2 = push_swap

SRCS_PATH = push_swap_checker
SRCS_PATH2 = push_swap_program

CC_FLAGS = -Werror -Wextra -Wall

SRC = main.c init_stack.c ft_stack_free.c check_arg.c \
		get_instruction_and_sort.c check_is_sorted.c \
		do_instruction.c do_instruction2.c has_empty_arg.c

USE = init_stack.c ft_stack_free.c check_is_sorted.c \
	check_arg.c get_instruction_and_sort.c \
	do_instruction2.c has_empty_arg.c

SRC2 = push_swap.c do_push_swap.c get_mid_nb.c \
		do_instruction_on_tab.c utile.c \
		move_element.c push_swap_instructions.c utile2.c manage_small_nb.c \
		move_a_to_b.c check_sorted.c

SRC_PATH = $(addprefix $(SRCS_PATH)/,$(SRC))
USE_PATH = $(addprefix $(SRCS_PATH)/,$(USE))
SRC_PATH2 = $(addprefix $(SRCS_PATH2)/,$(SRC2))

OBJ = $(SRC:.c=.o)
OBJ2 = $(SRC2:.c=.o)
USE_OBJ = $(USE:.c=.o)

OBJ_DIR = ./objects
OBJ_DIR2 = ./objects2

OBJS = $(addprefix $(OBJ_DIR)/,$(OBJ))
OBJS2 = $(addprefix $(OBJ_DIR2)/,$(OBJ2))
USE_OBJS = $(addprefix $(OBJ_DIR2)/,$(USE_OBJ))

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

all: $(NAME) $(NAME2)


$(NAME): libft_compile
		@mkdir -p $(OBJ_DIR)
		@$(CC) $(CC_FLAGS) -I $(HEADER_DIR) -c $(SRC_PATH)
		@mv $(OBJ) $(OBJ_DIR)
		@$(CC) $(CC_FLAGS) $(OBJS) -L ./libft -lft -o $(NAME)
		@printf "${BLUE}Checker${NC}:      ${DARK_YELLOW}Compilation is done    ${YELLOW}%-15.15s${NC}\n"


$(NAME2): libft_compile
		@mkdir -p $(OBJ_DIR2)
		@$(CC) $(CC_FLAGS) -I $(HEADER_DIR) -c $(SRC_PATH2) $(USE_PATH)
		@mv $(OBJ2) $(OBJ_DIR2)
		@mv $(USE_OBJ) $(OBJ_DIR2)
		@$(CC) $(CC_FLAGS) $(USE_OBJS) $(OBJS2) -L ./libft -lft -o $(NAME2)
		@printf "${BLUE}push swap${NC}:    ${DARK_YELLOW}Compilation is done    ${YELLOW}%-15.15s${NC}\n"



libft_compile:
		@make -C ./libft all

clean : libft_clean
		@rm -fr $(OBJS) $(OBJ_DIR) $(OBJ_DIR2)
		@rm -fr *.o
		@printf "${BLUE}PROJECT${NC}:      ${GREEN}Cleaned${NC}\n"
libft_clean:
		@make -C ./libft clean

fclean: clean libft_fclean
		@rm -f $(NAME) $(NAME2)
			@rm -f **/*~

libft_fclean:
		@make -C ./libft fclean

re: fclean all

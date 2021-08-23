#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/16 10:08:51 by xinwang           #+#    #+#              #
#    Updated: 2020/10/10 20:39:39 by maobe            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

#.SILENT:

NAME = libft.a

HEADER_DIR = include

########
# MAIN #
########
SRCS_PATH = ./src

SRCS = ft_strcmp.c ft_atoi.c ft_split.c ft_bzero.c ft_strchr.c ft_calloc.c \
	ft_strdup.c ft_isdigit.c ft_strjoin.c ft_isalpha.c ft_memccpy.c \
	ft_strlcat.c ft_isascii.c ft_memchr.c ft_strlcpy.c  ft_isalnum.c \
	ft_memcmp.c ft_strlen.c ft_isprint.c ft_memcpy.c ft_strmapi.c ft_itoa.c \
	ft_memmove.c ft_strncmp.c ft_memset.c ft_strnstr.c ft_putchar_fd.c \
	ft_strtrim.c ft_putendl_fd.c ft_substr.c ft_putnbr_fd.c ft_tolower.c \
	ft_putstr_fd.c ft_toupper.c ft_strrchr.c  ft_putstr.c  get_next_line.c  \
	get_next_line_utils.c  ft_putchar.c  ft_putendl.c  ft_putstr_w_new_line.c \
	ft_strnew.c  ft_strcat.c ft_is_space.c ft_lstadd_back.c ft_lstadd_front.c \
	ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c \
	ft_lstnew.c ft_lstsize.c free_str.c free_p_str.c ft_strnew_with_char.c \
	ft_strrmv.c ft_putstr_w_newline_fd.c ft_split_w_quotes.c \
	delete_quotes_from_arr.c delete_quotes_from_s.c init_quotes_struct.c \
	manage_struct_quotes.c escapted_char_management.c delete_slash_from_str.c \
	delete_slash_from_arr.c ft_tabfree.c ft_is_directory.c get_buffer.c show_arr_value.c \
	malloc_and_copy.c get_nb_size.c ft_max_min.c empty_arr.c \
	no_new_line_in_str.c ft_strncat.c get_next_line.c free_static_var.c  \
	get_nb_words_in_arr.c no_newline_in_str.c

SRC_W_PATH = $(addprefix $(SRCS_PATH)/,$(SRCS))

SRCO = $(SRCS:.c=.o)

##########
# COMMON #
##########

NC=\033[0;0m
DARK_YELLOW=\033[0;33m
YELLOW=\033[93m
BLUE=\033[94m

CC = gcc

CC_FLAGS = -Wall -Werror -Wextra

all:  $(NAME)

$(NAME):
		@$(CC) $(CC_FLAGS) -c  $(SRCS)
		@ar rcs $(NAME)  $(SRCO)
		@printf "${BLUE}LIBFT${NC}:        ${DARK_YELLOW}Compilation is done    ${YELLOW}%-15.15s${NC}\n"
clean:
		@rm -f $(SRCO)

fclean: clean
		@rm -f $(NAME)
		@rm -f #*#
re: fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/14 18:17:00 by msuokas           #+#    #+#              #
#    Updated: 2025/02/14 18:17:20 by msuokas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRC_DIR = src
INCLUDES = includes
OBJ_DIR = objs
LIBFT_DIR = $(SRC_DIR)/libft
PUSH_SWAP_DIR = $(SRC_DIR)/push_swap
LIBFT_FLS = $(LIBFT_DIR)/ft_calloc.c \
			$(LIBFT_DIR)/ft_atol.c \
			$(LIBFT_DIR)/ft_strlen.c \
			$(LIBFT_DIR)/ft_strdup.c \
			$(LIBFT_DIR)/ft_memset.c \
			$(LIBFT_DIR)/ft_bzero.c \
			$(LIBFT_DIR)/ft_memcpy.c \
			$(LIBFT_DIR)/ft_memmove.c \
			$(LIBFT_DIR)/ft_memchr.c \
			$(LIBFT_DIR)/ft_memcmp.c \
			$(LIBFT_DIR)/ft_strchr.c \
			$(LIBFT_DIR)/ft_strrchr.c \
			$(LIBFT_DIR)/ft_strnstr.c \
			$(LIBFT_DIR)/ft_strncmp.c \
			$(LIBFT_DIR)/ft_atoi.c \
			$(LIBFT_DIR)/ft_isdigit.c \
			$(LIBFT_DIR)/ft_isalpha.c \
			$(LIBFT_DIR)/ft_isalnum.c \
			$(LIBFT_DIR)/ft_isascii.c \
			$(LIBFT_DIR)/ft_isprint.c \
			$(LIBFT_DIR)/ft_toupper.c \
			$(LIBFT_DIR)/ft_tolower.c \
			$(LIBFT_DIR)/ft_striteri.c \
			$(LIBFT_DIR)/ft_strmapi.c \
			$(LIBFT_DIR)/ft_substr.c \
			$(LIBFT_DIR)/ft_strjoin.c \
			$(LIBFT_DIR)/ft_strtrim.c \
			$(LIBFT_DIR)/ft_split.c \
			$(LIBFT_DIR)/ft_putchar_fd.c \
			$(LIBFT_DIR)/ft_putstr_fd.c \
			$(LIBFT_DIR)/ft_putendl_fd.c \
			$(LIBFT_DIR)/ft_putnbr_fd.c \
			$(LIBFT_DIR)/ft_itoa.c \
			$(LIBFT_DIR)/ft_strlcat.c \
			$(LIBFT_DIR)/ft_putstr.c \
			$(LIBFT_DIR)/ft_free_split.c \
			$(LIBFT_DIR)/ft_isnum.c \
			$(LIBFT_DIR)/ft_isspace.c \

PUSH_SWAP_FLS = $(PUSH_SWAP_DIR)/push_swap.c \
				$(PUSH_SWAP_DIR)/operations.c \
				$(PUSH_SWAP_DIR)/count_cost.c \
				$(PUSH_SWAP_DIR)/error_checks.c \
				$(PUSH_SWAP_DIR)/long_sort.c \
				$(PUSH_SWAP_DIR)/operations3.c \
				$(PUSH_SWAP_DIR)/short_sort.c \
				$(PUSH_SWAP_DIR)/operations2.c \
				$(PUSH_SWAP_DIR)/rotation_prep.c \
				$(PUSH_SWAP_DIR)/utils.c \
				$(PUSH_SWAP_DIR)/list_utils.c \

SRC_FILES = $(LIBFT_FLS) $(PUSH_SWAP_FLS)

OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

CC = cc
RM = rm -rf
CFLAGS = -Wall -Werror -Wextra
IFLAGS = -I$(INCLUDES)

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c -o $@ $< $(IFLAGS)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(IFLAGS)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

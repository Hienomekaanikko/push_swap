NAME	= push_swap
LIBFT	= ./libft
HEADERS	= -I ./includes -I ${LIBFT}
LIBS	= ${LIBFT}/libft.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRC = push_swap.c \
		calc_cost.c \
		list_utils.c \
		operations.c \
		operations2.c \
		rotation_prep.c \
		rotation_prep2.c \
		sort_large.c \
		sort_short.c \
		utils.c \
		validate_input.c

OBJS = $(SRC:.c=.o)

all: libft $(NAME)

libft:
	$(MAKE) -C $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS) $(LIBS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re libft

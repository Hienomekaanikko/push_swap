CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFT_SRC = ../libft
NAME = push_swap
SRC = push_swap_utils.c push_swap.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -L $(LIBFT_SRC) -lft -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all



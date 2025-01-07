#include "push_swap.h"

void	add_node(node *list, int value)
{
	list = malloc(sizeof(int));
	list->data = value;
	list = list->next;
}

int	main(int argc, char *argv[])
{
	if (argc > 1)
	{
		write(1, &argv[1], 1);
		return (0);
	}
	ft_printf("%d", 13);
	ft_printf("%s", "13");
	return (0);
}

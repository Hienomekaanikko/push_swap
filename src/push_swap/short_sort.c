#include "push_swap.h"

static void	three_num(t_list **stack_a)
{
	t_list		*temp;
	long		lowest;

	temp = *stack_a;
	lowest = *(long*)temp->content;
	while (temp)
	{
		if (*(long*)temp->content < lowest)
			lowest = *(long*)temp->content;
		temp = temp->next;
	}
	temp = *stack_a;
	while (*(long*)temp->content != lowest)
	{
		rotate_one_up(stack_a);
		ft_putendl_fd("ra", 1);
		temp = *stack_a;
	}
	temp = temp->next;
	if (*(long*)temp->content > *(long*)temp->next->content)
	{
		rotate_one_up(stack_a);
		ft_putendl_fd("ra", 1);
		swap_first_two(stack_a);
		ft_putendl_fd("sa", 1);
		reverse_rotate_one(stack_a);
		ft_putendl_fd("rra", 1);
	}
}

void short_sort(t_list **stack_a)
{
	int		size;
	t_list	*temp;

	size = ft_lstsize(*stack_a);
	temp = *stack_a;
	if (size == 2)
	{
		if (*(long*)temp->content > *(long*)temp->next->content)
		{
			swap_first_two(stack_a);
			ft_putendl_fd("sa", 1);
		}
	}
	else if (size == 3)
		three_num(stack_a);
	else if (size > 3)
	{
		if (*(long*)temp->content > *(long*)temp->next->content)
		{
			swap_first_two(stack_a);
			ft_putendl_fd("sa", 1);
		}
		if (*(long*)temp->content > *(long*)temp->next->content)
		{
			rotate_one_up(stack_a);
			ft_putendl_fd("ra", 1);
		}
		short_sort(stack_a);
	}
}

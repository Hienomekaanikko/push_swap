#include "push_swap.h"

static void	three_num(t_list **stack_a)
{
	t_list	*temp;
	int		lowest;

	temp = *stack_a;
	lowest = *(int *)temp->content;
	while (temp)
	{
		if (*(int *)temp->content < lowest)
			lowest = *(int *)temp->content;
		temp = temp->next;
	}
	temp = *stack_a;
	while (*(int *)temp->content != lowest)
	{
		rotate_one_up(stack_a);
		temp = *stack_a;
	}
	temp = temp->next;
	if (*(int *)temp->content > *(int *)temp->next->content)
	{
		rotate_one_up(stack_a);
		swap_first_two(stack_a);
		reverse_rotate_one(stack_a);
	}
}

void	short_sort(t_list **stack_a)
{
	int		size;
	t_list	*temp;

	temp = *stack_a;
	size = ft_lstsize(*stack_a);
	if (size > 3)
	{
		if (*(int *)temp->content > *(int *)temp->next->content)
			swap_first_two(stack_a);
	}
	else if (size == 3)
		three_num(stack_a);
	else if (size == 2)
	{
		if (*(int *)temp->content > *(int *)temp->next->content)
			swap_first_two(stack_a);
	}
}

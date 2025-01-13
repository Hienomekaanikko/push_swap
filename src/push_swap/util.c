#include "push_swap.h"

int lowest(t_list **stack)
{
	t_list *temp_stack;
	int temp;

	if (!stack || !*stack)
		return (0);

	temp_stack = *stack;
	temp = *(int *)temp_stack->content;
	while (temp_stack)
	{
		if (*(int *)temp_stack->content < temp)
			temp = *(int *)temp_stack->content;
		temp_stack = temp_stack->next;
	}
	return (temp);
}


int	highest(t_list **stack)
{
	t_list	*temp_stack;
	int	temp;

	temp_stack = *stack;
	temp = *(int *)temp_stack->content;
	while (temp_stack)
	{
		if (*(int *)temp_stack->content > temp)
			temp = *(int *)temp_stack->content;
		temp_stack = temp_stack->next;
	}
	return (temp);
}

void	rotate_max_on_top(t_list **stack)
{
	int		target;

	target = highest(stack);
	while (*(int *)(*stack)->content != target)
	{
		rb(stack);
	}
}

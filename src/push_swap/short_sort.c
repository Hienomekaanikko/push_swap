#include "push_swap.h"

static void	three_num(t_list **stack_a)
{
	t_list	*temp;
	long long		lowest;

	temp = *stack_a;
	lowest = *(long long *)temp->content;
	while (temp)
	{
		if (*(long long *)temp->content < lowest)
			lowest = *(long long *)temp->content;
		temp = temp->next;
	}
	temp = *stack_a;
	while (*(long long *)temp->content != lowest)
	{
		ra(stack_a);
		temp = *stack_a;
	}
	temp = temp->next;
	if (*(long long *)temp->content > *(long long *)temp->next->content)
	{
		ra(stack_a);
		sa(stack_a);
		rra(stack_a);
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
		if (*(long long *)temp->content > *(long long *)temp->next->content)
			sa(stack_a);
	}
	else if (size == 3)
		three_num(stack_a);
	else if (size == 2)
	{
		if (*(long long *)temp->content > *(long long *)temp->next->content)
			sa(stack_a);
	}
}

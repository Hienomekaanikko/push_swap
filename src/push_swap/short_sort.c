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
		rotate(stack_a, "ra");
		temp = *stack_a;
	}
	temp = temp->next;
	if (*(long long *)temp->content > *(long long *)temp->next->content)
	{
		rotate(stack_a, "ra");
		s(stack_a, "sa");
		reverse(stack_a, "rra");
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
			s(stack_a, "sa");
	}
	else if (size == 3)
		three_num(stack_a);
	else if (size == 2)
	{
		if (*(long long *)temp->content > *(long long *)temp->next->content)
			s(stack_a, "sa");
	}
}

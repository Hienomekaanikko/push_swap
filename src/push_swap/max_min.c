#include "push_swap.h"

long long lowest(t_list **stack)
{
	t_list *temp_stack;
	long long temp;

	if (!stack || !*stack)
		return (0);

	temp_stack = *stack;
	temp = *(long long *)temp_stack->content;
	while (temp_stack)
	{
		if (*(long long *)temp_stack->content < temp)
			temp = *(long long *)temp_stack->content;
		temp_stack = temp_stack->next;
	}
	return (temp);
}


long long	highest(t_list **stack)
{
	t_list	*temp_stack;
	long long	temp;

	temp_stack = *stack;
	temp = *(long long *)temp_stack->content;
	while (temp_stack)
	{
		if (*(long long *)temp_stack->content > temp)
			temp = *(long long *)temp_stack->content;
		temp_stack = temp_stack->next;
	}
	return (temp);
}

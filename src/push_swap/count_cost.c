#include "push_swap.h"

static void assign_index_to_stack(t_list **stack)
{
	t_list	*temp;
	int		pos;

	temp = *stack;
	pos = 0;
	while (temp)
	{
		temp->index = pos;
		pos++;
		temp = temp->next;
	}
}

static int calculate_cost_with_reverse_roll(t_list *temp, int median, int *size)
{
	int	cost;

	cost = temp->index;
	if (cost < 0)
		cost = *size - cost;
	else if (cost > median)
		cost = *size - cost;
	return (cost);
}

static void calculate_cost_for_element(t_list *temp_a, t_list *stack_b, int *size_a, int *size_b, int median_a, int median_b)
{
	t_list	*temp_b;
	int		cost;

	cost = temp_a->index;
	temp_b = stack_b;
	cost = calculate_cost_with_reverse_roll(temp_a, median_a, size_a);
	while (temp_b)
	{
		if (* (int*)temp_b->content == temp_a->target)
			break;
		if (temp_b->index > median_b)
			cost = *size_b - temp_b->index;
		cost++;
		temp_b = temp_b->next;
	}
	temp_a->cost = cost;
}

void count_cost(t_list **stack_a, t_list **stack_b, int *size_a, int *size_b, int is_stack_a)
{
	t_list	*temp_a;
	t_list	*temp_b;
	int median_a;
	int median_b;

	temp_a = *stack_a;
	temp_b = *stack_b;
	median_a = *size_a / 2;
	median_b = *size_b / 2;
	assign_index_to_stack(stack_a);
	assign_index_to_stack(stack_b);
	if (is_stack_a)
	{
		while (temp_a)
		{
			calculate_cost_for_element(temp_a, *stack_b, size_a, size_b, median_a, median_b);
			temp_a = temp_a->next;
		}
	}
	else
	{
		while (temp_b)
		{
			calculate_cost_for_element(temp_b, *stack_a, size_a, size_b, median_a, median_b);
			temp_b = temp_b->next;
		}
	}
}

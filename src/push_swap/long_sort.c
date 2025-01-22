#include "push_swap.h"

static void assign_index_to_stack(t_list **stack)
{
	t_list	*temp;
	int		index;

	temp = *stack;
	index = 0;
	while (temp)
	{
		temp->index = index;
		index++;
		temp = temp->next;
	}
}

static int find_min_position(t_list **stack)
{
	t_list *temp;
	int min;
	int min_pos;
	int current_pos;

	temp = *stack;
	min = *(int*)temp->content;
	min_pos = 0;
	current_pos = 0;
	while (temp)
	{
		if (*(int*)temp->content < min)
		{
			min = *(int*)temp->content;
			min_pos = current_pos;
		}
		temp = temp->next;
		current_pos++;
	}
	return min_pos;
}

static t_list *find_best_candidate(t_list *stack)
{
	t_list	*best_candidate;
	int		min_cost;
	t_list	*temp;

	best_candidate = stack;
	min_cost = best_candidate->cost;
	temp = stack->next;
	while (temp)
	{
		if (temp->cost < min_cost)
		{
			min_cost = temp->cost;
			best_candidate = temp;
		}
		temp = temp->next;
	}
	return (best_candidate);
}

static void rotate_to_position(t_list **stack, int position, int size)
{
	if (position <= size / 2)
	{
		while (position--)
		{
			rotate_one_up(stack);
			ft_putendl_fd("ra", 1);
		}
	}
	else
	{
		position = size - position;
		while (position--)
		{
			reverse_rotate_one(stack);
			ft_putendl_fd("rra", 1);
		}
	}
	assign_index_to_stack(stack);
}

void full_sort(t_list **stack_a, t_list **stack_b, int *size_a, int *size_b)
{
	while (*size_a > 3)
	{
		push_one(stack_a, stack_b);
		ft_putendl_fd("pb", 1);
		(*size_a)--;
		(*size_b)++;
	}
	short_sort(stack_a);
	while (*stack_b)
	{
		add_targets(stack_b, stack_a, 1);
		count_cost(stack_a, stack_b, size_a, size_b, 0);
		count_cost(stack_b, stack_a, size_b, size_a, 1);
		t_list *best_candidate = find_best_candidate(*stack_b);
		while (*(int*)(*stack_a)->content != best_candidate->target &&
				*(int*)(*stack_b)->content != *(int*)best_candidate->content)
		{
			rotate_both_up(stack_a, stack_b);
			ft_putendl_fd("rr", 1);
			assign_index_to_stack(stack_a);
			assign_index_to_stack(stack_b);
		}
		int safety_counter = 0;
		while (*(int*)(*stack_a)->content != best_candidate->target && safety_counter < *size_a)
		{
			if ((*stack_a)->index < *size_a / 2)
			{
				rotate_one_up(stack_a);
				ft_putendl_fd("ra", 1);
			}
			else
			{
				reverse_rotate_one(stack_a);
				ft_putendl_fd("rra", 1);
			}
			assign_index_to_stack(stack_a);
			safety_counter++;
		}
		safety_counter = 0;
		while (*(int*)(*stack_b)->content != *(int*)best_candidate->content && safety_counter < *size_b)
		{
			if (best_candidate->index < *size_b / 2)
			{
				rotate_one_up(stack_b);
				ft_putendl_fd("rb", 1);
			}
			else
			{
				reverse_rotate_one(stack_b);
				ft_putendl_fd("rrb", 1);
			}
			assign_index_to_stack(stack_b);
			safety_counter++;
		}
		push_one(stack_b, stack_a);
		ft_putendl_fd("pa", 1);
		(*size_a)++;
		(*size_b)--;
		assign_index_to_stack(stack_a);
		assign_index_to_stack(stack_b);
	}
	int min_pos = find_min_position(stack_a);
	rotate_to_position(stack_a, min_pos, *size_a);
}

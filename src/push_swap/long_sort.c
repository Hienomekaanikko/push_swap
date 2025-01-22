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
	long long min;
	int min_pos;
	int current_pos;

	temp = *stack;
	min = *(long long*)temp->content;
	min_pos = 0;
	current_pos = 0;
	while (temp)
	{
		if (*(long long*)temp->content < min)
		{
			min = *(long long*)temp->content;
			min_pos = current_pos;
		}
		temp = temp->next;
		current_pos++;
	}
	return (min_pos);
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

static int find_median(t_list *stack, int size)
{
	long long *arr;
	t_list *temp;
	int i = 0;
	int j;
	long long t;
	long long median;

	arr = malloc(size * sizeof(long long));
	temp = stack;
	while (i < size)
	{
		arr[i] = *(long long*)temp->content;
		temp = temp->next;
		i++;
	}
	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
			j++;
		}
		i++;
	}
	median = arr[size / 2];
	free(arr);
	return (median);
}

static void push_to_b(t_list **stack_a, t_list **stack_b, int *size_a, int *size_b)
{
	while (*size_a > 3)
	{
		if (*(long long*)(*stack_a)->content < (long long)find_median(*stack_a, *size_a))
		{
			push_one(stack_a, stack_b);
			ft_putendl_fd("pb", 1);
			(*size_a)--;
			(*size_b)++;
		}
		else
		{
			rotate_one_up(stack_a);
			ft_putendl_fd("ra", 1);
		}
	}
}

static void perform_rotations(t_list **stack_a, t_list **stack_b, int *rot_a, int *rot_b)
{
	while (*rot_a > 0 && *rot_b > 0)
	{
		rotate_both_up(stack_a, stack_b);
		ft_putendl_fd("rr", 1);
		(*rot_a)--;
		(*rot_b)--;
	}
	while (*rot_a < 0 && *rot_b < 0)
	{
		reverse_rotate_both(stack_a, stack_b);
		ft_putendl_fd("rrr", 1);
		(*rot_a)++;
		(*rot_b)++;
	}
	while (*rot_a != 0)
	{
		if (*rot_a > 0)
		{
			rotate_one_up(stack_a);
			ft_putendl_fd("ra", 1);
			(*rot_a)--;
		}
		else
		{
			reverse_rotate_one(stack_a);
			ft_putendl_fd("rra", 1);
			(*rot_a)++;
		}
	}
	while (*rot_b != 0)
	{
		if (*rot_b > 0)
		{
			rotate_one_up(stack_b);
			ft_putendl_fd("rb", 1);
			(*rot_b)--;
		}
		else
		{
			reverse_rotate_one(stack_b);
			ft_putendl_fd("rrb", 1);
			(*rot_b)++;
		}
	}
}

static void push_back_to_a(t_list **stack_a, t_list **stack_b, int *size_a, int *size_b)
{
	while (*stack_b)
	{
		add_targets(stack_b, stack_a, 1);
		count_cost(stack_a, stack_b, size_a, size_b, 0);
		count_cost(stack_b, stack_a, size_b, size_a, 1);
		t_list *best_candidate = find_best_candidate(*stack_b);
		int rotations_a = 0;
		int rotations_b = best_candidate->index;
		t_list *temp = *stack_a;
		while (temp && *(long long*)temp->content != best_candidate->target)
		{
			rotations_a++;
			temp = temp->next;
		}
		if (rotations_a > *size_a / 2)
			rotations_a = rotations_a - *size_a;
		if (rotations_b > *size_b / 2)
			rotations_b = rotations_b - *size_b;
		perform_rotations(stack_a, stack_b, &rotations_a, &rotations_b);
		push_one(stack_b, stack_a);
		ft_putendl_fd("pa", 1);
		(*size_a)++;
		(*size_b)--;
	}
}

void full_sort(t_list **stack_a, t_list **stack_b, int *size_a, int *size_b)
{
	int	min_pos;
	push_to_b(stack_a, stack_b, size_a, size_b);
	short_sort(stack_a);
	push_back_to_a(stack_a, stack_b, size_a, size_b);
	min_pos = find_min_position(stack_a);
	rotate_to_position(stack_a, min_pos, *size_a);
	}

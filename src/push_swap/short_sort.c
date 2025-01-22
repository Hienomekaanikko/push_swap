#include "push_swap.h"

static void	sort_two(t_list **stack_a)
{
	if (*(long*)(*stack_a)->content > *(long*)(*stack_a)->next->content)
	{
		swap_first_two(stack_a);
		ft_putendl_fd("sa", 1);
	}
}

static void	sort_three_case_one(t_list **stack_a)
{
	swap_first_two(stack_a);
	ft_putendl_fd("sa", 1);
}

static void	sort_three_case_two(t_list **stack_a)
{
	swap_first_two(stack_a);
	ft_putendl_fd("sa", 1);
	reverse_rotate_one(stack_a);
	ft_putendl_fd("rra", 1);
}

static void	sort_three_case_three(t_list **stack_a)
{
	rotate_one_up(stack_a);
	ft_putendl_fd("ra", 1);
}

static void	sort_three_case_four(t_list **stack_a)
{
	swap_first_two(stack_a);
	ft_putendl_fd("sa", 1);
	rotate_one_up(stack_a);
	ft_putendl_fd("ra", 1);
}

static void	sort_three_case_five(t_list **stack_a)
{
	reverse_rotate_one(stack_a);
	ft_putendl_fd("rra", 1);
}

static void	sort_three(t_list **stack_a)
{
	long	a;
	long	b;
	long	c;

	a = *(long*)(*stack_a)->content;
	b = *(long*)(*stack_a)->next->content;
	c = *(long*)(*stack_a)->next->next->content;
	if (a > b && b < c && a < c)
		sort_three_case_one(stack_a);
	else if (a > b && b > c)
		sort_three_case_two(stack_a);
	else if (a > b && b < c && a > c)
		sort_three_case_three(stack_a);
	else if (a < b && b > c && a < c)
		sort_three_case_four(stack_a);
	else if (a < b && b > c && a > c)
		sort_three_case_five(stack_a);
}

void	short_sort(t_list **stack_a)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size == 2)
		sort_two(stack_a);
	else if (size == 3)
		sort_three(stack_a);
}

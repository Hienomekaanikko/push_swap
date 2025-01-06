/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:01:10 by msuokas           #+#    #+#             */
/*   Updated: 2025/01/06 17:07:51 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//check if the order is correct
int	check_order(int *stack, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (stack[i] > stack[i + 1])
			return(0);
		i++;
	}
	return (1);
}

int	check_inverse_order(int *stack, int len)
{
	int	i;

	i = len - 1;
	while (i >= 0)
	{
		if (stack[i] > stack[i - 1])
			return(0);
		i--;
	}
	return (1);
}
//return the highest value in the current array
int check_highest(int *stack, int len)
{
	int i;
	int highest;

	i = 1;

	if (len <= 0)
		return 0;
	highest = stack[0];

	while (i < len)
	{
		if (stack[i] > highest)
			highest = stack[i];
		i++;
	}

	return (highest);
}
//when the order is right but it's not yet starting at highest ("spin the wheel" to make the order correct)
void	place_inverse_order(int *stack, int len)
{
	int	highest;
	int	i;
	int	j;
	int	n;

	highest = check_highest(stack, len);
	ft_printf("%d\n", highest);
	i = 0;
	j = 0;
	n = len - 1;
	while (stack[i] != highest)
		i++;
	while (stack[n] != highest)
	{
		n--;
		j++;
	}
	if (i > j)
	{
		while (stack[0] != highest)
			ra_rb_rr(stack, len);
	}
	else
	{
		while (stack[0] != highest)
			rra_rrb_rrr(stack, len);
	}
}

//check order of first two, return 0 if in descending order, 1 if in ascending order
int	check_order_of_two(int *stack)
{
	int	i;

	i = 0;
	if (stack[i] > stack[i + 1])
		return (0);
	return (1);
}

//do the swaps
void	push_swap(int *stack_a, int *stack_b, int len)
{
	int	i;
	int	count;

	i = 0;
	//swap firsts. sa, sb or ss (for both at the same time)
	//sa_sb_ss(stack_a, len);
	//first of src to the top of dest
	pa_pb(stack_b, stack_a);
	pa_pb(stack_b, stack_a);
	//rotate everything up one step. first becomes last
	//ra_rb_rr(stack_a, len);
	//rotate everything down one step. last becomes first
	//rra_rrb_rrr(stack_a, len);
}

int	main(int argc, char *argv[])
{
	int		i;
	int		j;
	int		*stack_a;
	int		*stack_b;
	int		stack_size;

	stack_size = argc - 1;
	stack_a = ft_calloc(stack_size, sizeof(int));
	stack_b = ft_calloc(stack_size, sizeof(int));
	if (!stack_a || !stack_b)
	{
		free(stack_a);
		free(stack_b);
		return (0);
	}
	i = 1;
	j = 0;
	if (i < stack_size)
	{
		while (argv[i])
			stack_a[j++] = ft_atoi(argv[i++]);
		push_swap(stack_a, stack_b, stack_size);
	}
	i = 0;
	while (stack_a[i])
	{
		ft_printf("%d ", stack_a[i]);
		i++;
	}
	ft_printf("\n");
	i = 0;
	while (stack_b[i])
	{
		ft_printf("%d ", stack_b[i]);
		i++;
	}
	return (0);
}

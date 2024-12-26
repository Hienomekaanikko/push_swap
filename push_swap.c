/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:01:10 by msuokas           #+#    #+#             */
/*   Updated: 2024/12/26 14:59:23 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int *stack_a, int *stack_b, int len)
{
	//swap firsts. sa, sb or ss (for both at the same time)
	sa_sb_ss(stack_a);
	//first of src to the top of dest
	pa_pb(stack_b, stack_a);
	//rotate everything up one step. first becomes last
	ra_rb_rr(stack_a, len);
	//rotate everything down one step. last becomes first
	rra_rrb_rrr(stack_a, len);
}

int	main(int argc, char *argv[])
{
	int		i;
	int		j;
	int		*stack_a;
	int		*stack_b;

	stack_a = malloc((argc - 1) * sizeof(int));
	if (!stack_a)
		return (0);
	stack_b = malloc((argc - 1) * sizeof(int));
	if (!stack_a)
		return (0);
	i = 1;
	j = 0;
	if (argc > 1)
	{
		while (argv[i])
			stack_a[j++] = ft_atoi(argv[i++]);
		push_swap(stack_a, stack_b, argc);
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

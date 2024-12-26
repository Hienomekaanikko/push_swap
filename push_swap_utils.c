/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:52:05 by msuokas           #+#    #+#             */
/*   Updated: 2024/12/26 14:59:49 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_sb_ss(int *stack)
{
	int	temp;

	temp = stack[0];
	stack[0] = stack[1];
	stack[1] = temp;
}
void	pa_pb(int *dest, int *src)
{
	int	i;

	i = 0;
	dest[i] = src[i];
	while (src[i])
	{
		src[i] = src[i + 1];
		i++;
	}
	src[i] = '\0';
}
void	ra_rb_rr(int *stack, int len)
{
	int	temp;
	int	i;

	i = 0;
	temp = stack[i];
	while (i < len - 2)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[i] = temp;
}
void	rra_rrb_rrr(int *stack, int len)
{
	int	temp;
	int	i;

	i = len - 2;
	temp = stack[i];
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[i] = temp;
}

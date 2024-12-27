/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:52:05 by msuokas           #+#    #+#             */
/*   Updated: 2024/12/27 15:35:46 by msuokas          ###   ########.fr       */
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
void	pa_pb(int *dest, int *src, int len)
{
	int	i;

	i = 0;
	if (!dest[0])
		dest[0] = src[0];
	else {
		i = len;
		while (i > 0)
		{
			dest[i] = dest[i - 1];
			i--;
		}
		dest[0] = src[0];
	}
	i = 0;
	while (src[i])
	{
		src[i] = src[i + 1];
		i++;
	}
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

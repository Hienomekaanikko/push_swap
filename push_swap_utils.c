/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:52:05 by msuokas           #+#    #+#             */
/*   Updated: 2025/01/06 17:08:33 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_elements(int *stack)
{
	int	i;

	i = 0;
	while (stack[i])
		i++;
	return (i);
}

void	sa_sb_ss(int *stack, int len)
{
	int	temp;

	temp = stack[0];
	stack[0] = stack[1];
	stack[1] = temp;
	stack[len] = 0;
}
void	pa_pb(int *dest, int *src)
{
	int	i;
	int	dest_len;
	int src_len;

	dest_len = count_elements(dest) - 1;
	if (!dest[0])
		dest[0] = src[0];
	else {
		while (dest_len > 0)
		{
			dest[dest_len] = dest[dest_len];
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
	src_len = count_elements(src) - 1;
	src[src_len] = 0;
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

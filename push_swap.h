/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:01:28 by msuokas           #+#    #+#             */
/*   Updated: 2025/01/06 17:05:08 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define	PUSH_SWAP_H

#include "../libft/libft.h"

void	sa_sb_ss(int *stack, int len);
void	pa_pb(int *dest, int *src);
void	ra_rb_rr(int *stack, int len);
void	rra_rrb_rrr(int *stack, int len);
int		count_elements(int *stack);

#endif

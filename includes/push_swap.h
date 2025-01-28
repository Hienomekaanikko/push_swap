/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:41:40 by msuokas           #+#    #+#             */
/*   Updated: 2025/01/28 12:16:09 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define	PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"

void	pb(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rra(t_list **stack_b);
void	rrb(t_list **stack_b);
void	add_targets_a(t_list **stack_a, t_list **stack_b);
void	count_cost(t_list **stack_src, t_list **stack_dst, int *size_src, int *size_dst);
void	long_sort(t_list **stack_a, t_list **stack_b, int *size_a, int *size_b);
void	rotate_max_on_top(t_list **stack);
long long	highest(t_list **stack);
long long	lowest(t_list **stack);
void	empty_b_to_a(t_list	**stack_a, t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	short_sort(t_list **stack_a);
void	add_index(t_list **stack_a, t_list **stack_b);
void	free_stack(t_list **stack);
void	add_targets_b(t_list **stack_a, t_list **stack_b);
void	rotate_min_on_top(t_list **stack);
void	error_checks(int argc, char **argv);
#endif

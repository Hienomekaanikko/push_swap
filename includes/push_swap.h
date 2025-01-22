/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:41:40 by msuokas           #+#    #+#             */
/*   Updated: 2025/01/17 19:07:21 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define	PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"

void	short_sort(t_list **stack_a);
long long	lowest(t_list **stack);
long long	highest(t_list **stack);
void	reverse_rotate_both(t_list **stack_a, t_list **stack_b);
void	rotate_both_up(t_list **stack_a, t_list **stack_b);
void	push_one(t_list **stack_src, t_list **stack_dst);
void	swap_first_two(t_list **stack);
void	rotate_one_up(t_list **stack);
void	reverse_rotate_one(t_list **stack);
void	rotate_max_on_top(t_list **stack);
void	rotate_min_on_top(t_list **stack);
void	free_stack(t_list **stack);
void	error_checks(int argc, char **argv);
void	sort(t_list **stack_a, t_list **stack_b);
void	add_targets(t_list **to, t_list **from, int mode);
void	count_cost(t_list **stack_a, t_list **stack_b, int *size_a, int *size_b, int is_stack_a);
void	full_sort(t_list **stack_a, t_list **stack_b, int *size_a, int *size_b);

#endif

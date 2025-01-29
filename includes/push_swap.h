/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:41:40 by msuokas           #+#    #+#             */
/*   Updated: 2025/01/29 16:54:13 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define	PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"

void	push(t_list **stack_src, t_list **stack_dst, const char *operations);
void	s(t_list **stack_src, const char *operation);
void	rotate(t_list **stack_a, const char *operation);
void	reverse(t_list **stack, const char *operation);
void	add_targets(t_list **stack_src, t_list **stack_dst, int mode);
void	count_cost(t_list **stack_src, t_list **stack_dst);
void	long_sort(t_list **stack_a, t_list **stack_b, int *size_a, int *size_b);
void	rotate_max_on_top(t_list **stack);
long long	highest(t_list **stack);
long long	lowest(t_list **stack);
void	reverse_both(t_list **stack_src, t_list **stack_dst, const char *operation);
void	rotate_both(t_list **stack_src, t_list **stack_dst, const char *operation);
void	short_sort(t_list **stack_a);
void	add_index(t_list **stack_a, t_list **stack_b);
void	free_stack(t_list **stack);
void	rotate_min_on_top(t_list **stack);
void	error_checks(int argc, char **argv);
int		find_cheapest(t_list **stack);

#endif

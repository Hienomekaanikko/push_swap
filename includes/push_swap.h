/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:41:40 by msuokas           #+#    #+#             */
/*   Updated: 2025/02/14 15:13:13 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

typedef struct s_stack
{
	long long		*content;
	long long		target;
	int				cost;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_data
{
	int	cheapest;
	int	src_median;
	int	dst_median;
	int	src_index;
	int	dst_index;
	int	stack_flag;
	int	src_size;
	int	dst_size;
	int	highest;
	int	lowest;
	int	both;
	int	limit;
}	t_data;

void		push(t_stack **src, t_stack **dst, const char *operations);
void		rotate(t_stack **stck, const char *operation);
void		reverse(t_stack **stck, const char *operation);
void		rev_both(t_stack **src, t_stack **dst, const char *op, t_data *d);
void		rot_both(t_stack **src, t_stack **dst, const char *op, t_data *d);
void		add_targets(t_stack **src, t_stack **dst, t_data *data);
long long	highest(t_stack **stck);
long long	lowest(t_stack **stck);
void		short_sort(t_stack **a, size_t size);
void		free_stack(t_stack **stck);
void		rotate_min_on_top(t_stack **a);
int			find_cheapest(t_stack **stck);
int			src_dist(int chpst, t_stack **src);
int			dst_dist(int chpst, t_stack **src, t_stack **dest);
void		parse_input(int argc, char **argv);
void		error(char *msg, char **args, int should_free);
void		init_data_a(t_stack **a, t_stack **b, t_data *data);
void		init_data_b(t_stack **a, t_stack **b, t_data *data);
void		update_values(t_stack **src, t_stack **dst, t_data *data);
void		add_index(t_stack **src);
void		fill(t_stack **src, t_stack **dst, t_data *data);
void		ft_exit(t_stack **src, t_stack **dst);
int			ft_lstsize(t_stack *lst);
t_stack		*ft_lstnew(void *content);
t_stack		*ft_lstlast(t_stack *lst);
void		ft_add_node(t_stack **stack, long long content);
int			ft_make_list(t_stack **a, char **content);

#endif

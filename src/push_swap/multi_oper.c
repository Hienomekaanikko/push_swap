#include "push_swap.h"

void reverse_rotate_both(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate_one(stack_a);
	reverse_rotate_one(stack_b);
	//print rrr
}

void	rotate_both_up(t_list **stack_a, t_list **stack_b)
{
	rotate_one_up(stack_a);
	rotate_one_up(stack_b);
	//print rr
}
void	push_one(t_list **stack_src, t_list **stack_dst)
{
	t_list	*temp;

	if (*stack_src == NULL)
		return ;
	temp = *stack_src;
	*stack_src = (*stack_src)->next;
	temp->next = (*stack_dst);
	*stack_dst = temp;
	//print pa or pb
}

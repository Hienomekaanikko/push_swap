#include "push_swap.h"

void    add_node(t_list **stack, int content)
{
    t_list  *new_node;
    t_list  *temp;
    int     *content_copy;

    content_copy = malloc(sizeof(int));
    if (!content_copy)
        return ;
    *content_copy = content;
    new_node = ft_lstnew(content_copy);
    if (*stack == NULL)
        *stack = new_node;
    else
    {
        temp = *stack;
        while (temp->next)
            temp = temp->next;
        temp->next = new_node;
    }
}

int main(int argc, char *argv[])
{
    int     i;
    t_list  *stack_a;
    t_list  *temp;

    i = 1;
    stack_a = NULL;
    if (argc > 1)
    {
        while (argv[i])
        {
            add_node(&stack_a, ft_atoi(argv[i]));
            i++;
        }
    }
    temp = stack_a;
    while (temp)
    {
        ft_printf("%d ", *(int *)temp->content);
        temp = temp->next;
    }
    return (0);
}

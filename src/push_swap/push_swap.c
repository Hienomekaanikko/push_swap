#include <stdio.h>
#include "libft.h"

// Helper function to print the list
void print_list(t_list *lst)
{
    while (lst)
    {
        printf("%d -> ", *(int *)lst->content);
        lst = lst->next;
    }
    printf("NULL\n");
}

// Delete function for integers
void del_int(void *content)
{
    free(content);
}

// Function to double the integer value
void *double_int(void *content)
{
    int *new_content = malloc(sizeof(int));
    if (new_content)
        *new_content = *(int *)content * 2;
    return new_content;
}

// Function to print an integer
void print_int(void *content)
{
    printf("%d ", *(int *)content);
}

int main(void)
{
    t_list *list = NULL;
    int *num1, *num2, *num3;

    // Create three nodes
    num1 = malloc(sizeof(int)); *num1 = 10;
    num2 = malloc(sizeof(int)); *num2 = 20;
    num3 = malloc(sizeof(int)); *num3 = 30;

    // Add nodes to the list
    ft_lstadd_back(&list, ft_lstnew(num1));
    ft_lstadd_back(&list, ft_lstnew(num2));
    ft_lstadd_front(&list, ft_lstnew(num3));

    printf("Original list: ");
    print_list(list);

    // Use ft_lstsize
    printf("List size: %d\n", ft_lstsize(list));

    // Use ft_lstlast
    t_list *last = ft_lstlast(list);
    printf("Last element: %d\n", *(int *)last->content);

    // Use ft_lstiter
    printf("List elements: ");
    ft_lstiter(list, print_int);
    printf("\n");

    // Use ft_lstmap
    t_list *doubled_list = ft_lstmap(list, double_int, del_int);
    printf("Doubled list: ");
    print_list(doubled_list);

    // Use ft_lstclear
    ft_lstclear(&list, del_int);
    printf("Original list after clearing: ");
    if (list == NULL)
        printf("List is empty\n");
    else
        print_list(list);

    // Clean up doubled list
    ft_lstclear(&doubled_list, del_int);

    return 0;
}

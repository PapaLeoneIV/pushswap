 #include "pushswap.h"
#include "ft_printf.h"
#include "../libft.h"

void sb(dll_list *stack_b)
{
    dll_list *second_node;
    dll_list *head;

    head = ft_dll_return_head(stack_b);
    second_node = head->next;
    head->next = second_node->next;
    head->prev = second_node;
    second_node->prev = NULL;
    second_node->next = head;
    
}
/* 
int main()
{
    dll_list *head;
    int arr[] = {1, 2 , 3, 4};
    head = ft_dll_initi(arr, 4);

    sa(head);
    head = ft_dll_return_head(head);
    while(head != NULL)
    {
        printf("%i\n", *(int *)head->val);
        head = head->next;
    }


}  */
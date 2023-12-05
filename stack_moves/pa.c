 #include "../pushswap.h"
#include "ft_printf.h"
#include "../libft.h"

void pa(dll_list **stack_a, dll_list **stack_b)
{
    int tmp;
    dll_list *newnode;

    tmp = *(int*)(*stack_b)->val;
    newnode = ft_dll_new((int *)(&tmp));
    ft_dll_insert_head(&(*stack_a), newnode);


}
/* 
int main()
{
    dll_list *a_head;
    dll_list *b_head;
    int arr[] = {1, 2 , 3, 4};
    int arr2[] = {99, 98 , 97, 96};
    a_head = ft_dll_initi(arr, 4);
    b_head = ft_dll_initi(arr2, 4);


    pa(&a_head, &b_head);
    while(a_head != NULL)
    {
        printf("%i\n", *(int *)a_head->val);
        a_head = a_head->next;
    }
    while(b_head != NULL)
    {
        printf("%i\n", *(int *)b_head->val);
        b_head = b_head->next;
    } 
} */
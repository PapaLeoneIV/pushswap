#include "../pushswap.h"
#include "ft_printf.h"
#include "../libft.h"

void rrb(dll_list** stack)
{
    int*   tmp;
    int*   tail_val;
    
    ft_dll_return_head(stack);
    if(ft_dll_size((*stack)) <= 1)
        return ;
    ft_dll_return_tail(stack);
    tail_val = (*stack)->val;
    ft_dll_return_head(stack);
    tmp = (*stack)->val;
    (*stack)->val = (int *)tail_val;
    (*stack) = (*stack)->next;
    while((*stack) != NULL)
    {
        tail_val = (*stack)->val;
        (*stack)->val = tmp;
        tmp = tail_val;
        if((*stack)->next == NULL)
            break;
        (*stack) = (*stack)->next;
    }
    ft_dll_return_head(stack);
}
 
 /* int main(void)
{
    int arr[] = {1, 2, 3, 4};
    int arr2[] = {0, 0, 0, 0, 0, 0};
    dll_list* a = ft_dll_initi(arr, 4);
    dll_list* b = ft_dll_initi(arr2, 6);

    rra(&a);
    ft_dll_return_head(&a);
    while(a != NULL)
	{
		printf("%i\n", *(int *)a->val);
		if(a->next == NULL)
				break;
		a = a->next;
	} 
    printf("[----------------------]\n");
    while(b != NULL)
	{
		printf("%i\n", *(int *)b->val);
		if(b->next == NULL)
				break;
		b = b->next;
	}
    ft_dll_return_head(&a);
    ft_dll_clear(&a, free);
    ft_dll_return_head(&b);
    ft_dll_clear(&b, free);
}  */
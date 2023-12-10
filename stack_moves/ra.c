#include "../pushswap.h"
#include "ft_printf.h"
#include "../libft.h"

void ra(dll_list** stack)
{
    int*   tmp;
    int*   tmp2;

    ft_dll_return_head(&(*stack));
    tmp2 = (*stack)->val;
    ft_dll_return_tail(&(*stack));
    tmp = (*stack)->val;
    (*stack)->val = (int *)tmp2;
    (*stack) = (*stack)->prev;
    while((*stack) != NULL)
    {

        /**avevo lasciato qui ieri sera*/
        tmp2 = (*stack)->val;
        (*stack)->val = tmp;


        if((*stack)->prev == NULL)
            break;
        (*stack) = (*stack)->prev;
    }
}


int main(void)
{
    int arr[] = {2, 1, 3, 6, 5, 8};
    int arr2[] = {0, 0, 0, 0, 0, 0};
    dll_list* a = ft_dll_initi(arr, 6);
    dll_list* b = ft_dll_initi(arr2, 6);

    ra(&a);
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



}



/*
NULL<--[1]<-->[2]<-->[3]<-->[4]<-->[5]<-->[6]->NULL
*/
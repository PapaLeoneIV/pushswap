#include "../pushswap.h"
#include "ft_printf.h"
#include "../libft.h"

/* void ra(dll_list **stack_a)
{

} */


/* int main(void)
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    dll_list* a = ft_dll_initi(arr, 6);

    ra(&a);
    while(a != NULL)
	{
		printf("%i\n", *(int *)a->val);
		if(a->next == NULL)
				break;
		a = a->next;
	} 
	printf("[----------------------]\n");
    ft_dll_return_head(&a);
    ft_dll_clear(&a, free);



} */



/*
NULL<--[1]<-->[2]<-->[3]<-->[4]<-->[5]<-->[6]->NULL
*/
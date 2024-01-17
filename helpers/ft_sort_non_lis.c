#include "pushswap.h"
#include "ft_printf.h"
#include "../libft.h"

static void ft_eliminate_lis_elem(t_stacks* stacks)
{
    dll_list* ptr;
    dll_list* newnode;
    int i;

    i = 0;
    while(i < stacks->input_arr_len)
    {
        ptr = stacks->lis;
        while(ptr != NULL)
        {
            if(stacks->input_arr[i] == *(int*)(ptr->val))
                break ;
            if (ptr->next == NULL)
            {
                newnode = ft_dll_new(&stacks->input_arr[i]);
                if (!newnode)
                {
                    ft_dll_return_head(&ptr);
                    ft_dll_clear(&ptr, free);
                }
                ft_dll_insert_tail(&stacks->o_non_lis, newnode);
                stacks->o_non_lis_len++;
            }
            ptr = ptr->next;
        }
        i++;
    }
}

void ft_sort_non_lis(t_stacks* stacks)
{
    ft_eliminate_lis_elem(stacks);
}

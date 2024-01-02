#include "pushswap.h"
#include "ft_printf.h"
#include "../libft.h"

static void ft_eliminate_lis_elem(t_stacks* stacks)
{
    dll_list* ptr;
    dll_list* newnode;
    dll_list* head;
    int i;
    int j;
    int* k;

    stacks->non_lis = NULL;
    head = stacks->lis;

    k = 0;
    i = 0;
    j = 0;
    while(i < stacks->input_arr_len)
    {
        ptr = stacks->lis;
        while(ptr != NULL)
        {
            if(stacks->input_arr[i] == *(int*)(ptr->val))
                break ;
            if (ptr->next == NULL)
            {   
                k = malloc(sizeof(int));
                *k = stacks->input_arr[i];
                newnode = ft_dll_new(k);
                newnode->index = i;
                if(!newnode)
                {
                    ft_dll_return_head(&(stacks->non_lis));
                    ft_dll_clear(&(stacks->non_lis), free);
                    return;
                }
                ft_dll_insert_tail(&(stacks->non_lis), newnode);
            }
            ptr = ptr->next;
        }
        i++;
    }
    stacks->lis = head;
}

void ft_return_non_lis_with_idx(t_stacks* stacks)
{
    ft_eliminate_lis_elem(stacks); 
    ft_dll_bubble_sort(stacks->non_lis);

} 

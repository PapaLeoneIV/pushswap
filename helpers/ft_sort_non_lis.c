#include "pushswap.h"
#include "ft_printf.h"
#include "../libft.h"

static void ft_eliminate_lis_elem(t_stacks* stacks, iarr* res)
{
    dll_list* ptr;
    int i;
    int j;

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
                res->arr[j++] = stacks->input_arr[i];
                res->len = j;
            }
            ptr = ptr->next;
        }
        i++;
    }
}

void ft_sort_non_lis(t_stacks* stacks)
{
    iarr o_non_lis;
    o_non_lis.len = 0;
    o_non_lis.arr = malloc((stacks->input_arr_len - stacks->lis_len) * sizeof(int));
    ft_eliminate_lis_elem(stacks, &o_non_lis);
    ft_quick_sort(o_non_lis.arr, 0, o_non_lis.len - 1);
    int i = 0; 
    while(i < o_non_lis.len)
    {
        printf("%i\n",o_non_lis.arr[i]);
        i++;
    }
    free(o_non_lis.arr);
}

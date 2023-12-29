#include "pushswap.h"
#include "ft_printf.h"
#include "../libft.h"

static void ft_eliminate_lis_elem(t_stacks* stacks)
{
    dll_list* ptr;
    dll_list* newnode;
    int i;
    int j;
    int k;

    k = 0;
    stacks->u_non_lis = NULL;
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
                k = stacks->input_arr[i];
                newnode = ft_dll_new(k);
                if(!newnode)
                {
                    ft_dll_return_head(&(stacks->u_non_lis));
                    ft_dll_clear(&(stacks->u_non_lis), free);
                    return;
                }
                ft_dll_insert_tail(&(stacks->u_non_lis), newnode);
                newnode->index = i;

            }
            ptr = ptr->next;
        }
        i++;
    }
    
}

static void ft_insert_u_non_lis(t_stacks* stacks, int* arr, int len)
{
    int i;

    i = 0;
    if(!stacks || !arr || !len)
        return ;
    stacks->u_non_lis = ft_calloc(len, sizeof(int));
    while(arr && i < len)
    {
        stacks->u_non_lis[i] = arr[i]; 
        i++;
    }
    stacks->u_non_lis_len = len;
}

void ft_sort_non_lis(t_stacks* stacks)
{
    ft_eliminate_lis_elem(stacks);                                      
    ft_quick_sort(u_non_lis.arr, 0, u_non_lis.len - 1);

    ft_insert_u_non_lis(stacks, u_non_lis.arr, u_non_lis.len);
    free(u_non_lis.arr);
}

    /*TODO modificare quick_sort in modo da funzionare con delle dll {o.o}**
    * ->una volta fatto:
        creare una nuova dll usando quick_sort su u_non_lis (mantenendo gl indici gia presenti in u_non_lis !!!!NON AGGIORNARLI)
        FATTO QUESTO:
            dovrei avere :
                    lis dll (con gli indici originali)
                    u_non_lis (con gli indici originali)
                    order_non_lis (con gli indici originali)

    */

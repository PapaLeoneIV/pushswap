#include "libft.h"
#include "ft_printf.h"
#include "pushswap.h"
/*static int ft_find_middle(dll_list* list)
{	
	int index;
	dll_list* tmp;

	tmp = list;
	ft_dll_return_tail(&tmp);
	index = tmp->index / 2;
	return (index);
}*/
static void ft_insert_mosse_node(dll_list** mosse_a, int val)
{
    dll_list* new;
    int *tmp1;

    tmp1 = ft_calloc(1, sizeof(int));
    *tmp1 = val;
    new = ft_dll_new(tmp1);
    ft_dll_insert_tail(mosse_a, new);
}
static int ft_handle_mosse_condition_o(dll_list** mosse_a, dll_list* ptr_a, dll_list* ptr_b, t_stacks* stack)
{
    int len;

    len = ft_dll_get_tail_index(ptr_a);
    	if ((*(int*)ptr_b->val > *(int*)ptr_a->val
			&& *(int*)ptr_b->val < *(int*)ptr_a->next->val)
		|| (*(int*)ptr_a->val == stack->minmax[1]
			&& *(int*)ptr_a->next->val > *(int*)ptr_b->val)
		|| (*(int*)ptr_a->next->val == stack->minmax[0]
			&& *(int*)ptr_a->val < *(int*)ptr_b->val))
        {
            ft_insert_mosse_node(mosse_a, -1 * (len - ptr_a->next->index + 1));
            return 1;
        }
    return 0;
}

static int ft_handle_mosse_condition_u(dll_list** mosse_a, dll_list* ptr_a, dll_list* ptr_b, t_stacks* stack)
{
    if ((*(int*)ptr_b->val > *(int*)ptr_a->val
			&& *(int*)ptr_b->val < *(int*)ptr_a->next->val)
		|| (*(int*)ptr_a->val == stack->minmax[1]
			&& *(int*)ptr_a->next->val > *(int*)ptr_b->val)
		|| (*(int*)ptr_a->next->val == stack->minmax[0]
			&& *(int*)ptr_a->val < *(int*)ptr_b->val))
        {
            ft_insert_mosse_node(mosse_a, ptr_a->index + 1);
            return 1;
        }
    return 0;
}

static int ft_check_and_insert_mosse(dll_list** mosse_a, dll_list* ptr_a, dll_list* ptr_b, t_stacks* stack)
{
    if (ptr_a->index <= stack->pivotindex)
    {
        if (ft_handle_mosse_condition_u(mosse_a, ptr_a, ptr_b, stack))
            return 1;
    }
    else if(ptr_a->index >= stack->pivotindex)
    {
        if(ft_handle_mosse_condition_o(mosse_a, ptr_a, ptr_b, stack))
            return 1;
    }
    return 0;
}

static dll_list* ft_handle_empty_stack_b(dll_list* ptr_b)
{
    dll_list* mosse_a;
    dll_list* tmp;

    mosse_a = NULL;
    tmp = ptr_b;
    while (tmp != NULL)
    {
        ft_insert_mosse_node(&mosse_a, 0);
        tmp = tmp->next;
    }

    return mosse_a;
}

static void ft_process_mosse_nodes(dll_list** mosse_a, dll_list* ptr_a, dll_list* ptr_b, t_stacks* stack)
{/* 
    int tail_idx; */

    while (ptr_a != NULL)
    {
        if (ft_check_and_insert_mosse(mosse_a, ptr_a, ptr_b, stack))
            break;
        ptr_a = ptr_a->next;
        if (ptr_a->next == NULL)
        {
            ft_insert_mosse_node(mosse_a, 0);
            break;
        }
    }
}
static dll_list* ft_generate_mosse_list_a(t_stacks* stack)
{
    dll_list* mosse_a;
    dll_list* ptr_b;
    dll_list* ptr_a;

    mosse_a = NULL;
    ptr_b = stack->b;
    ptr_a = stack->a;
    while (ptr_b != NULL)
    {
        ft_process_mosse_nodes(&mosse_a, ptr_a, ptr_b, stack);
        ptr_b = ptr_b->next;
    }

    return mosse_a;
}
dll_list* ft_dll_calcola_mosse_a(t_stacks* stack)
{
    dll_list* mosse_a;
    int len;
    mosse_a = NULL;
    len = ft_dll_get_tail_index(stack->a);
    stack->pivotindex = len / 2 ;
    if(len == 0)
    {
        mosse_a = ft_handle_empty_stack_b(stack->b);
        return mosse_a;
    }
    return ft_generate_mosse_list_a(stack);
}
/*     while(ptr_b != NULL)
    {
        ptr_a = stack->a;
        while(ptr_a != NULL)
        {
            
            if(ptr_a->index < pivot_idx )
            {
                if((ptr_a->index == 0) && *(int*)ptr_b->val < *(int*)ptr_a->val)
                {
                    ft_insert_mosse_node(&mosse_a, 0);
                    break;
                }
                else if (*(int*)ptr_a->val < *(int*)ptr_b->val && *(int*)ptr_b->val < *(int*)ptr_a->next->val)
                {
                    ft_insert_mosse_node(&mosse_a, ptr_a->index);
                    break;
                }
            }
            else if (*(int*)ptr_a->val < *(int*)ptr_b->val && *(int*)ptr_b->val < *(int*)ptr_a->next->val)
            {
                ft_insert_mosse_node(&mosse_a, -1 * (len - ptr_a->next->index + 1));
                break;
            }
            else if (*(int*)ptr_b->val > *(int*)ptr_a->next->val)
            {
                 ft_insert_mosse_node(&mosse_a, -1);
                break;
            }
            ptr_a = ptr_a->next;
            if(ptr_a->next == NULL)
                break;
        }
    ptr_b = ptr_b->next;       
    }
    return mosse_a;
}
dll_list* ft_dll_calcola_mosse_a(t_stacks* stack)
{
	int pivot_idx;
	dll_list* mosse_a;

	pivot_idx = ft_find_middle(stack->a);
	mosse_a = ft_create_mosse_list_a(stack, pivot_idx);

	return (mosse_a);
	
} */

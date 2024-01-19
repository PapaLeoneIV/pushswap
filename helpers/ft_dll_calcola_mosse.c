#include "pushswap.h"
/* 	|	mov_b +		|	mov_b -
--------|-----------------------|-----------------------
mov_a +	|   max(mov_a, mov_b)	|   mov_a + |mov_b|
--------|-----------------------|-----------------------
mov_a -	|  |mov_a| + mov_b	|  |min(mov_a, mov_b)| */




static int ft_min(int a, int b)
{
    if(a < b)
        return a;
    else
        return b;
}

static int ft_max(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}

static int ft_calcola_n_mosse(int a, int b)
{
    if(a == 0 && b == 0)
        return 0;
    if(a > 0 && b > 0)
        return (ft_max(a, b));
    else if(a < 0 && b < 0)
        return (ft_min(a, b) * -1);
    else if(a >= 0 && b < 0)
        return (a + (b * -1));
    else if(a < 0 && b >= 0)
        return ((a * -1) + b);
    else if(a >= 0 && b == 0)
        return a;
    else if (a == 0 && b >= 0)
        return b;
    return 0;    

}


int  ft_dll_calcola_mosse(dll_list* a, dll_list* b)
{
    dll_list* ptr_a;
    dll_list* ptr_b;
    int tmp;
    int min_mosse;
    int n_mosse;

    min_mosse = 0;
    ptr_a = a;
    ptr_b = b;
    while(ptr_b != NULL )
    {
        n_mosse = ft_calcola_n_mosse(*(int*)ptr_a->val, *(int*)ptr_b->val);
        if(n_mosse < min_mosse)
        {
            min_mosse = n_mosse;
            tmp = ptr_a->index;
        }
        ptr_b = ptr_b->next;
        ptr_a = ptr_a->next;
    }
    
    return tmp;
}
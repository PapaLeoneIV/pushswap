#include <stdio.h>
#include <stdlib.h>
#include "limits.h"
#include "../libft.h"

static void ft_initialize_arrays(dll_list** len_arr, dll_list** index_arr, int len)
{
    (*len_arr) = ft_dll_initi_to(len, 1);
    (*index_arr) = ft_dll_initi_to(len, -1);
}
static void ft_find_biggest_index(lis_vars *var,dll_list* len_list)
{
    int i;
    dll_list* tmp;
    dll_list* tmp2;

    i = 1;
    while(i < var->arr_size)
    {
        tmp = ft_dll_get_node(len_list, i);
        tmp2 = ft_dll_get_node(len_list, var->max_index);
        if(*(int*)(tmp->val) > *(int*)(tmp2->val))
        {
            var->max_index = i;
        }
        i++;
    }
}

static void ft_get_indexs_lis(dll_list** list,dll_list**  len_list,dll_list**  index_list,int size)
{
    int i;
    int j;
    dll_list* tmpi;
    dll_list* tmpj;
    
    
    i = 1; 
    while(i < size)
    {
        j = 0;
        while(j < i)
        {
            if(ft_dll_get_value((*list), &j) < ft_dll_get_value((*list), &i) && ft_dll_get_value((*len_list), &i) < ft_dll_get_value((*index_list), &j) + 1)
            {
                tmpi = ft_dll_get_node((*len_list), i);
                tmpj = ft_dll_get_node((*len_list), j);
                *(int*)(tmpi->val) = *(int*)(tmpj->val) + 1;
                tmpi = ft_dll_get_node((*index_list), i);
                tmpj = ft_dll_get_node((*index_list), j);
                tmpi->val = &j;
            }
            j = j + 1;
        }
        i = i + 1;
    }

}

dll_list*    ft_build_lis_arr(dll_list* list,dll_list* len_list,lis_vars* var, dll_list* index_list)
{
    dll_list* res;
    dll_list* tmp;
    int* index_counter;
    int len_counter; 


    index_counter = NULL;
    var->lis_lenght = ft_dll_get_value(len_list, &var->max_index); 
    res = ft_dll_initi_to(*(var->lis_lenght) ,0);
    index_counter = &(var->max_index);
    len_counter =  *(var->lis_lenght) - 1;
    while(index_counter >= 0 && len_counter >= 0)
    {
        tmp = ft_dll_get_node(res, len_counter);
        tmp->val = ft_dll_get_value(list, index_counter); 
        index_counter = ft_dll_get_value(index_list, index_counter); 
        len_counter--;
    }
    return (res);
}




dll_list* ft_lis_algo_list(int* lis_len, dll_list* a)
{
    dll_list* len_list;
    dll_list* index_list;
    dll_list* result;
    lis_vars var;

    ft_dll_return_tail(&a);
    len_list = NULL;
    index_list = NULL;
    var = (lis_vars){0};
    var.arr_size = a->index;
    var.lis_lenght = lis_len;

    ft_initialize_arrays(&len_list, &index_list, var.arr_size);
    ft_get_indexs_lis(&a, &len_list, &index_list, var.arr_size);
    ft_find_biggest_index(&var, len_list);
    result = ft_build_lis_arr(a, len_list, &var, index_list);   
    lis_len = var.lis_lenght;

    return result;
}



 
/*  int main() {
    int lis_length;

    int arr[] = {0, 2, 34, 23, 1, 43, 53352,25324, 523, 53,532,5123 ,2};
    int lenght = sizeof(arr) / sizeof(arr[0]);
    dll_list* a = ft_dll_initi(arr, lenght);
    lis_length = 1;


    
    dll_list* lis_sequence = ft_lis_algo_list(&lis_length, a);

    printf("LIS: ");
    for (int i = 0; i < lis_length; i++) {
        printf("%d ", *(int*)lis_sequence->val);
        lis_sequence= lis_sequence->next;
    }
    printf("\n");

    free(lis_sequence);

  return 0;
}  */
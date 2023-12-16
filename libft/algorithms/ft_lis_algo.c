#include <stdio.h>
#include <stdlib.h>
#include "limits.h"
#include "../libft.h"

static void ft_initialize_arrays(int** len_arr, int** index_arr, int len)
{
    int i;

    i = 0;
    while(i < len)
    {
        *(*len_arr) = 1;
        *(*index_arr) = -1;
        i++;
    }
}
static void ft_find_biggest_index(variables **var, int* len_arr)
{
    int i;

    i = 1;
    while(i < (*var)->arr_size)
    {
        if(len_arr[i] > len_arr[(*var)->max_index])
        {
            (*var)->max_index = i;
        }
        i++;
    }
   /*  while(i < len)
    {
        if((*len_arr)[i] > (*len_arr)[*max_index])
            *max_index = i;
        i++;
    } */
}

static void ft_get_indexs_lis(int* arr,int** len_arr,int** index_arr, int len)
{
    int i;
    int j;

    i = 1;
    j = 0;
    while(i < len)
    {
        while(j < i)
        {
            if(arr[j] < arr[i] && (*len_arr)[i] < (*len_arr)[j] + 1)
            {
                (*len_arr)[i] = (*len_arr)[j] + 1;
                (*index_arr)[i] = j;
            }
            j++;
        }
        i++;
    }
}

int*    ft_build_lis_arr(int* arr,int* len_arr,variables** var, int* index_arr)
{
    int* res;
    int i;
    int j;

    res = ft_calloc(len_arr[(*var)->max_index], sizeof(int));
    (*var)->lis_lenght = len_arr[(*var)->max_index];
    i = (*var)->max_index;
    j =  (*var)->lis_lenght - 1;
    while(i >=0 && j >= 0)
    {
        res[j] = arr[i];
        i = index_arr[i];
        j--;
    }
    return (res);
}




int* ft_lis_algo(int* arr, variables** var)
{
    int* len_arr;
    int* index_arr;
    int* result;

    len_arr = ft_calloc((*var)->arr_size, sizeof(int));
    index_arr = ft_calloc((*var)->arr_size, sizeof(int));

    ft_initialize_arrays(&len_arr, &index_arr, (*var)->arr_size);
    ft_get_indexs_lis(arr, &len_arr, &index_arr, (*var)->arr_size);
    ft_find_biggest_index(var, len_arr);
/*     (*var)->lis_lenght = 6; */
    result = ft_build_lis_arr( arr, len_arr, var, index_arr);  
    return result;
}




int main() {
    int arr[] = {INT_MIN, -1, 9, 33, 21, 50, INT_MAX, 100};
    variables* var;
    var = malloc(sizeof(variables));
    var->arr_size = sizeof(arr) / sizeof(arr[0]);

    int* lis_sequence = ft_lis_algo(arr, &var);


    printf("LIS: ");
    for (int i = 0; i < var->lis_lenght; i++) {
        printf("%d ", lis_sequence[i]);
    }
    printf("\n");

    // Libera la memoria allocata per l'array LIS
    free(lis_sequence);

    return 0;
}
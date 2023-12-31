#include "../libft.h"
#include "limits.h"

int ft_check_for_dupl(int *arr, int size)
{
    hash_map *map;
    int i;
    int res;

    i = 0;
    res = 0;
    map = ft_create_hash_map(size);
    while(i < size)
    {
        ft_insert_in_hash_map(map, arr[i]);
        i++;
    }
    i = 0;
    while(i < size)
    {
        res = ft_get_frequency(map, arr[i]);
        if(res > 1)
        {
            ft_free_hash_map(map);
            return 1;
        }  
        i++;
    }
    ft_free_hash_map(map);
    return 0;
}


/* int main() 
{
    int array[] = {INT_MIN, 7, 1, 3, 2, 0, INT_MAX};
    int size = sizeof(array) / sizeof(array[0]);

    if (ft_check_for_dupl(array, 10)) 
    {
        printf("L'array contiene duplicati.\n");
    } 
    else 
    {
        printf("L'array non contiene duplicati.\n");
    }

    return 0;
}  */
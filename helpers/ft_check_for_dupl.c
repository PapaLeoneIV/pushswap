#include "libft.h"

void ft_check_for_dupl(int* arr, int size) 
{
    for (int i = 0; i < size - 1; i++) 
    {
        for (int j = i + 1; j < size; j++) 
        {
            if (arr[i] == arr[j]) 
            {
                error_fn();
            }
        }
    }
   
    return ;
}

/* int main() 
{
    int array[] = {3, 7, 1, 4, 2, 8, 5};
    int size = sizeof(array) / sizeof(array[0]);

    if (has_duplicates(array, size)) 
    {
        printf("L'array contiene duplicati.\n");
    } 
    else 
    {
        printf("L'array non contiene duplicati.\n");
    }

    return 0;
} */
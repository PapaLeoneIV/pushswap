#include "../libft.h"

void ft_free_hash_map(hash_map* map) 
{
    int i;
    item* current; 

    i = 0; 
    while(i < map->size)
    {
        current = map->array[i];
        while (current != NULL) 
        {
            item* temp = current;
            current = current->next;
            free(temp);
        }
        i++;
    }
    free(map->array);
    free(map);
}
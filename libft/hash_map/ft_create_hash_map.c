#include "../libft.h"
hash_map* ft_create_hash_map(int size) 
{
    hash_map* map;
    int i;

    i = 0;
    map = (hash_map *)malloc(sizeof(hash_map)); 
    map->size = size;
    map->n_item = 0;
    map->array = (item **)calloc(size, sizeof(item*));
    while(i < size)
    {
        map->array[i] = NULL;
        i++;
    }
    return map;
}



/* 
int main()
{
    hash_map* map;
    int i = 0;
    map = ft_create_hash_map(10);
    while(i < 10)
    {
        printf("%p\n", (void *)map->array[i]);
        i++;
    }
} */
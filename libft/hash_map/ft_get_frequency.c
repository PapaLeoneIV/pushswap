#include "../libft.h"

int ft_get_frequency(hash_map* map, int key)
{
    int index = ft_hash_fn(key, map->size);
    item* current = map->array[index];

    while (current != NULL) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }
    return 0;
}
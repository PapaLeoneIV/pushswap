#include "../libft.h"
#include "limits.h"

void ft_insert_in_hash_map(hash_map* map, int key) 
{
    int riga_hash_map;
    item* nodo;

    riga_hash_map = ft_hash_fn(key, map->size);
    nodo = map->array[riga_hash_map];
    while (nodo != NULL) {
        if (nodo->key == key) {
            nodo->value++;
            return ;
        }
        nodo = nodo->next;
    }
    item* new_item = (item *)malloc(sizeof(item));
    new_item->key = key;
    new_item->value = 1;
    new_item->next = map->array[riga_hash_map];
    map->array[riga_hash_map] = new_item;
}

/* int main() 
{
    hash_map* map;
    int i = 0;
    map = ft_create_hash_map(10);

      ft_insert_in_hash_map(map, -19);
    ft_insert_in_hash_map(map, 2);
    ft_insert_in_hash_map(map, -19);
    ft_insert_in_hash_map(map, 1);
    ft_insert_in_hash_map(map, 1);
    ft_insert_in_hash_map(map, -99);
    ft_insert_in_hash_map(map, -100);
    ft_insert_in_hash_map(map, 4);
    ft_insert_in_hash_map(map, 23); 
     ft_insert_in_hash_map(map, INT_MAX);
    ft_insert_in_hash_map(map, INT_MAX);  
      ft_insert_in_hash_map(map, INT_MIN);
    ft_insert_in_hash_map(map, INT_MIN);  
  ft_insert_in_hash_map(map, 23242);
    ft_insert_in_hash_map(map, 44324); 
 ft_insert_in_hash_map(map, 1);
    ft_insert_in_hash_map(map, 2);
    ft_insert_in_hash_map(map, 3);
    ft_insert_in_hash_map(map, 4);
    ft_insert_in_hash_map(map, 5);
    ft_insert_in_hash_map(map, 6);
    ft_insert_in_hash_map(map, 1);  

    for (i = 0; i < 10; i++) {
        printf("Index %d: ", i);
        item* current = map->array[i];
        while (current != NULL) {
            printf("(%d, %d) ", current->key, current->value);
            current = current->next;
        }
        printf("\n");int main() 
{
    hash_map* map;
    int i = 0;
    map = ft_create_hash_map(10);

      ft_insert_in_hash_map(map, -19);
    ft_insert_in_hash_map(map, 2);
    ft_insert_in_hash_map(map, -19);
    ft_insert_in_hash_map(map, 1);
    ft_insert_in_hash_map(map, 1);
    ft_insert_in_hash_map(map, -99);
    ft_insert_in_hash_map(map, -100);
    ft_insert_in_hash_map(map, 4);
    ft_insert_in_hash_map(map, 23); 
     ft_insert_in_hash_map(map, INT_MAX);
    ft_insert_in_hash_map(map, INT_MAX);  
      ft_insert_in_hash_map(map, INT_MIN);
    ft_insert_in_hash_map(map, INT_MIN);  
  ft_insert_in_hash_map(map, 23242);
    ft_insert_in_hash_map(map, 44324); 
 ft_insert_in_hash_map(map, 1);
    ft_insert_in_hash_map(map, 2);
    ft_insert_in_hash_map(map, 3);
    ft_insert_in_hash_map(map, 4);
    ft_insert_in_hash_map(map, 5);
    ft_insert_in_hash_map(map, 6);
    ft_insert_in_hash_map(map, 1);  

    for (i = 0; i < 10; i++) {
        printf("Index %d: ", i);
        item* current = map->array[i];
        while (current != NULL) {
            printf("(%d, %d) ", current->key, current->value);
            current = current->next;
        }
        printf("\n");
    }
    int res = ft_get_frequency(map, -19);
    if(res > 1) 
    {
        printf("L'array contiene duplicati.\n");
    } 
    else 
    {
        printf("L'array non contiene duplicati.\n");
    }
    ft_free_hash_map(map);

    return 0;
} duplicati.\n");
    } 
    else 
    {
        printf("L'array non contiene duplicati.\n");
    }
    ft_free_hash_map(map);

    return 0;
}  */
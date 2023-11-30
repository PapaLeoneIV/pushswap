#include "../libft.h"
void error_fn()
{
	write(1, "Error\n", 6);
	exit(0);
} 
void ft_insert_in_hash_map(hash_map* map, int key) 
{
    // Calcola l'indice della tabella hash per la chiave
    int index;
    // Controlla se c'è già un elemento nella posizione corrente
    item* current;

    index = key % map->size;
    current = map->array[index];
    while (current != NULL) {
        if (current->key == key) {
            // Se la chiave è già presente, incrementa il numero di occorrenze
            error_fn();
        }
        current = current->next;
    }

    // Se la chiave non è presente, crea un nuovo elemento
    item* new_item = (item *)malloc(sizeof(item));
    new_item->key = key;
    new_item->value = 1; // Prima occorrenza
    new_item->next = map->array[index];
    map->array[index] = new_item;
}
/* 
int main() 
{
    hash_map* map;
    int i = 0;
    map = ft_create_hash_map(5);

    ft_insert_in_hash_map(map, 1);
    ft_insert_in_hash_map(map, 2);
    ft_insert_in_hash_map(map, 44);
    ft_insert_in_hash_map(map, 99);
    ft_insert_in_hash_map(map, 99);

    for (i = 0; i < 5; i++) {
        printf("Index %d: ", i);
        item* current = map->array[i];
        while (current != NULL) {
            printf("(%d, %d) ", current->key, current->value);
            current = current->next;
        }
        printf("\n");
    }

    return 0;
} */
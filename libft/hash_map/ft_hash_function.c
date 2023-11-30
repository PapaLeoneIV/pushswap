#include "../libft.h"

int ft_hash_function(int key, int size) 
{
    return key % size;
}
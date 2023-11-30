#include "../libft.h"

int ft_hash_fn(int key, int size) 
{
    long int tmp;
    tmp = key;
    if(key < 0)
    {
        tmp = key * -1;
    }
    if (tmp < 0)
        tmp = tmp * -1;
    return(tmp % size);
}
#include"pushswap.h"

void check_if_ordered(int *arr, int len)
{
    int i;

    i = 0;
    while(i < len - 1)
    {
        if(arr[i] > arr[i + 1])
            return ;
        i++;
    }
    exit(0);
}
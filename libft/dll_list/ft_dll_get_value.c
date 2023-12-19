#include "../libft.h"

int* ft_dll_get_value(dll_list* list, int* index)
{
    int i;

    i = 0;
    if(!list)
        printf("errore nel ft_dll_get_value!");
    while(i < *index)
    {
        if(list->next == NULL)
            return NULL;
        list = list->next;
        i++;
    }
    return ((int *)list->val);
}

/* 
int main()
{
    int arr[] = {1, 2, 3, 4};
    int len = 4;

    dll_list* list = ft_dll_initi(arr, len);
    int* res = ft_dll_get_value(list, 6);
    if(res)
        printf("res : %i\n", *res);
    else 
        return 0;
} */
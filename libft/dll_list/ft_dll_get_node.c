#include "../libft.h"

dll_list* ft_dll_get_node(dll_list* list, int index)
{
    int i;

    i = 0;
    if(!list)
        printf("errore nel ft_dll_get_value!");
    while(list && i < index)
    {
        list = list->next;
        i++;
    }
    if(list == NULL)
        return NULL;
    return (list);
}

/* 
int main()
{
    int arr[] = {1, 2, 3, 4};
    int len = 4;

    dll_list* list = ft_dll_initi(arr, len);
    dll_list* res = ft_dll_get_node(list, 6);
    if(res)
        printf("res : %i\n", *(int*)res->val);
    else 
        return 0;
} */
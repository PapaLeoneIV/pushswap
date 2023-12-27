#include "../libft.h"

dll_list* ft_dll_get_node(dll_list* list, int index)
{
    int i;
    dll_list* ptr;

    i = 0;
    ptr = list;
    if(!list)
        printf("errore nel ft_dll_get_value!");
    while(ptr != NULL)
    {
        if(ptr->index == index)
            return (ptr);
        ptr = ptr->next;
        i++;
    }
    return NULL;
}
/* 

int main()
{
    int arr[] = {1, 2, 3, 4};
    int len = 4;

    dll_list* list = ft_dll_initi(arr, len);
    dll_list* res = ft_dll_get_node(list, -99);
    if(res != NULL)
        printf("res : %i\n", *(int*)res->val);
    else 
        return 0;
}  */
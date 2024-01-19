#include "../libft.h"

int ft_dll_get_value(dll_list* list, int index)
{
    int i;
    dll_list* ptr;

    i = 0;
    ptr = list;
    if(!list)
        write(1, "list is NULL\n", 13);
    while(i < index)
    {
        if(ptr == NULL)
            return (-1);
        i++;
        ptr = ptr->next;
    }
    return (*(int *)(ptr->val));
}


/* int main()
{
    int arr[] = {0, 99, 23, 354, 46};
    int len = 5;

    dll_list* list = ft_dll_initi(arr, len);
    if(ft_dll_get_value(list, 2) > ft_dll_get_value(list, 0))
        printf("res : %i\n", 9999);
    else 
        printf("res non esiste");
}  */
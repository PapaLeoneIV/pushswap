/* #include "../libft.h"

void swap(dll_list *a, dll_list *b) {
    void *temp_val;
    int temp_index;

    temp_val = a->val;
    temp_index = a->index;
    a->val = b->val;
    a->index = b->index;

    b->val = temp_val;
    b->index = temp_index;
}

dll_list* ft_dll_bubble_sort(dll_list** list)
{
    dll_list* ptr;
    int flag;

    flag = 1;
    if(list == NULL)
        return NULL;
    while(flag)
    {
        flag = 0;
        ptr = *(list);
        while(ptr->next != NULL)
        {
        if(*(int *)(ptr->val > *(int *)ptr->next->val))
        {
            swap(ptr, ptr->next);
            flag = 1;
        }
        ptr = ptr->next;
        }
    }
    return ptr;
}



int main()
{
    dll_list* list;
    int arr[] = {1, 23, 12, 11};

    list = ft_dll_initi(arr, 4);
    dll_list* new = ft_dll_bubble_sort(&list);
} */
#include "../libft.h"



static void swap(dll_list *a, dll_list *b) {
    void *temp_val;
    int temp_index;

    temp_val = a->val;
    temp_index = a->index;
    a->val = b->val;
    a->index = b->index;
    b->val = temp_val;
    b->index = temp_index;
}

void ft_dll_bubble_sort(dll_list *head)
{
    int flag;
    dll_list *ptr;
    dll_list *lptr;

    lptr = NULL;
    if (head == NULL)
        return;
    flag = 1;
    while (flag) {
        flag = 0;
        ptr = head;
        while (ptr->next != NULL)
        {
            if (*(int *)ptr->val > *(int *)ptr->next->val)
            {
                swap(ptr, ptr->next);
                flag = 1;
            }
            ptr = ptr->next;
        }
    }
}
/* 
int main() {
    dll_list *head;
    head = NULL;
    int values[] = {-4, -2, 7, -1, 9, 0, 23, 213,42,5233,5, 362,35,834,2167,3321323,421,44214};
    head = ft_dll_initi(values, 18);

    ft_dll_bubble_sort(head);

    while(head != NULL)
    {
        printf("(%i %i) \n", head->index, *(int*)head->val);
        head = head->next;
    }
    ft_dll_clear(&head, free);
    return 0;
}  */
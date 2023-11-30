#include "libft.h"
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));

t_list *lstcreate(t_list **head, char **argv, int arrlen)
{
    t_list *ptr;
    t_list *newnode;
    int i;


    i = 0;
    ptr = (*head);
    while(i < arrlen)
    {
        newnode = ft_lstnew(argv[i]);
        printf("valore new node %d\n", *(int *)newnode->content);
        {
            ft_lstclear(head, free);
			return (NULL);
        }
        if(ptr->next == NULL)
            ft_lstadd_front(&ptr, newnode); 
        else
            ft_lstadd_back(&ptr, newnode);
        ptr = ptr->next;
        array++;
        i++;
    }
    return (*head);
}
int main()
{
    t_list *head;
    head = NULL; 

    int i = 0;
    array = (int *)malloc(sizeof(int) * 5);
    while(i < 5)
    {
        array[i] = i;
        i++;
    }
    head = lstcreate(&head, array, 5);

}
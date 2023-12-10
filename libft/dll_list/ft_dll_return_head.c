#include "../libft.h"

void    ft_dll_return_head(dll_list **lst)
{
	if(!(*lst) || !lst)
		return ;
	while((*lst)->prev)
	{
		*lst = (*lst)->prev;
	}
} 



 
/*  int main()
{
	int b[4] = {1, 2, 3, 4};
	dll_list *a = ft_dll_initi(b, 4);

	while(a != NULL)
	{
		printf("%i\n", *(int *)a->val);
		if(a->next == NULL)
			break;
		a = a->next;
	}
	ft_dll_return_head(&a);
	while(a != NULL)
	{
		printf("%i\n", *(int *)a->val);
		a = a->next;
	}
} */
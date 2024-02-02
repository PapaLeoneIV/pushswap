/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dll_initi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <riccardo.leone@student.42fir      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:47:50 by rileone           #+#    #+#             */
/*   Updated: 2024/02/01 15:48:01 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void ft_dll_clear2(dll_list* list)
{
	ft_dll_return_head(&list);
	ft_dll_clear(&list, free);
}

dll_list	*ft_dll_initi(int *arr, int len)
{
	dll_list*	head;
	dll_list*	newnode;
	int*		val;
	int          i;

	i = -1;
	head = NULL;
	if(len == 0 || !arr)
		return NULL;
	while(++i < len)
	{
		val = malloc(sizeof(int));
		*val = arr[i];
		newnode = ft_dll_new(val);
		if(!newnode || val == NULL)
		{
			ft_dll_clear2(head);
			return(NULL);
		}
        newnode->index = i;
		ft_dll_insert_tail(&head, newnode);
	}
	return (head);
}

/* 
int main()
{
	dll_list *start;
	int arr[5] = {1, 2 , 3, 4, -99};
	start = ft_dll_initi(arr, 5);
	int i = 0;
 	while(start->next != NULL)
	{
		printf("%i\n", *(int *)start->val);
		start = start->next;
		i++;
	}
	ft_dll_return_head(&start);
	ft_dll_clear(&start, free);



}  */

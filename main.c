/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <riccardo.leone@student.42fir      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:55:06 by rileone           #+#    #+#             */
/*   Updated: 2023/11/22 13:55:07 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"
#include "ft_printf.h"
#include "../libft.h"
int main(int ac, char **av)
{
        int input_length;
		int *dati_norm;
		dll_list *a;
		dll_list *b;
		
        input_length = ft_get_input_length(ac, av);
		dati_norm = ft_normalizzazione_dati(ac ,av);
		a = ft_dll_initi(dati_norm, input_length);
        b = ft_dll_initi_to_zero(input_length);

/*         while(a != NULL)
        {
            printf("%i\n", *(int *)a->val);
            if(a->next == NULL)
			    break;
            a = a->next;
        } */
        ft_dll_return_head(&b);
		ft_dll_clear(&b, free);
        ft_dll_return_head(&a);
		ft_dll_clear(&a, free);
		free(dati_norm);
		return 0;


}

/*         while(a != NULL)
        {
            printf("%i\n", *(int *)a->val);
            if(a->next == NULL)
			    break;
            a = a->next;
        }
       while(b != NULL)
        {
            printf("%i\n", *(int *)b->val);
            if(b->next == NULL)
			    break;
            b = b->next;
        } */
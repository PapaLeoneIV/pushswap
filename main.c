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

int main(int ac, char **av)
{
		int i;
		int *dati_norm;
		dll_list *a;
		dll_list *b;
		
		i = 0;
		b = NULL;
		a = NULL;
		dati_norm = ft_normalizzazione_dati(ac ,av);
		 while(i < ac - 1)
		{
			ft_printf("dati : %i\n",dati_norm[i]);
			i++;
		} 
	
	// a = push_dati_into_stack(dati_norm, &a);
	return 0;
}


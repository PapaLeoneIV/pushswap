#include "libft.h"
#include "ft_printf.h"
#include "pushswap.h"




void ft_sortback(t_stacks* stack)
{
	dll_list* mosse_a;
	dll_list* mosse_b;
	int best_idx;

		mosse_b = ft_dll_calcola_mosse_b(stack);
		mosse_a = ft_dll_calcola_mosse_a(stack);
		best_idx = ft_dll_calcola_mosse(mosse_a, mosse_b);
		printf("best index --->%i\n", best_idx);
		 printf("\nmosse_b: \n");
		ft_dll_printi(mosse_b);
		printf("\nmosse_a: \n");
		ft_dll_printi(mosse_a); 
		/*mosse_a = ft_dll_calcola_mosse_a(stack);
		best_idx = ft_dll_calcola_mosse(mosse_a, mosse_b);
		ft_move_from_b_to_a(stack, best_idx);
		ptr = ptr->next;
		*/
    /* ft_dll_return_head(&(stack->o_non_lis));
	ft_dll_return_head(&stack->a); */
}
	/** Il calcolo delle mosse
Se state immaginando una quindicina di funzioni da scrivere dopo questo titolo, probabilmente avete sottostimato il lavoro che avete ancora di fronte.

Non c'è molto da fare: dovete calcolarvi per ogni numero quante mosse dovete fare nel migliore dei casi. Abbiamo ragionato così:

Create due array di appoggio (mov_a e mov_b possono andare benissimo!) dove salvare i valori di cui sotto 😉 Entrambi devono avere dimensione size_b: infatti i numeri da salvarsi sono riferiti unicamente ai numeri nella stack_b. Mi spiego peggio: siccome il nostro obiettivo è riportare tutti i numeri di b nella a, dobbiamo calcolare quante mosse dobbiamo fare sia per muovere il numero di b in prima posizione, sia per muovere lo stack_a in modo tale da poter inserire correttamente il numero di b. Conseguentemente, ad ogni numero di b corrisponde non solo un tot di mosse per arrivare in prima posizione ed applicare quindi pa, ma anche un tot di mosse per mettere in prima posizione il numero corretto di a, tale per cui con l'inserimento del numero di b la stack_a rimanga ordinata.
Cominciamo quindi a fare i nostri calcoli: si prende la stack_b e si calcola la distanza di ogni numero dalla prima posizione. Banalmente, a seconda che loro si trovino sopra o sotto la posizione size_b / 2, si utilizzeranno le mosse rb o rrb. Il valore assegnato sarà positivo se bisogna utilizzare rb, negativo se bisogna utilizzare rrb.
si trova nello stack_a il numero immediatamente maggiore a quello preso in considerazione nello stack_b. Aiutatevi col presupposto che lo stack_a è già ordinato! Trovate la coppia per il quale mov_a[i] < mov_b[j] < mov_a[i + 1] e mettete mov_a[i + 1] in prima posizione. Esempio: se abbiamo da inserire un 5 in uno stack_a uguale a 3 - 8 - 19 - 25, sarà l'8 ad andare in prima posizione.
si calcola lo stesso valore del passaggio 2, ma riguardante mov_a[i + 1].
Vi porto un esempio pragmatico più complesso, preso da una simulazione reale in cui avevo 7 numeri sullo stack_b e più di 12 numeri sullo stack_a:

MOV_A   MOV_B
4       0
-5      1
3       2
-1      3
0       -3
4       -2
-5      -1
La colonna B indica la distanza di ogni numero di stack_b, mentre la colonna A indica la distanza del numero di stack_a immediatamente maggiore al suo corrispondente in b. Vediamo ora come arrivare all'atto pratico!

La scelta del numero
Ok, sappiamo tutte le mosse per ogni numero che abbiamo nella stack_b. Ma quale prendiamo? La risposta dipende dalle casistiche, a seconda del senso di rotazione del vettore:

	|	mov_b +		|	mov_b -
--------|-----------------------|-----------------------
mov_a +	|   max(mov_a, mov_b)	|   mov_a + |mov_b|
--------|-----------------------|-----------------------
mov_a -	|  |mov_a| + mov_b	|  |min(mov_a, mov_b)|
Prendo per assodato che ricordiate il valore assoluto...

In tutti e quattro i casi, il valore rilasciato altro non è che il numero totale di mosse che dovete fare prima di pa!

Ma prima occorre sottolineare perché sia necessario prendere il massimo o il minimo dei due valori nel caso dello stesso segno per i due numeri. Se vogliamo ottimizzare al meglio il codice, dobbiamo per forza usufruire delle mosse rr e rrr, che con una sola riga di output effettuano la rotazione ad entrambi gli stack. Va da sé che dividere per 2 le mosse è un guadagno di tempo che non possiamo lasciarci sfuggire...

Riprendendo quindi l'esempio di cui alla sezione sopra, va da sé che 4   0 diventa meno conveniente di 3   2, in quanto per il primo si eseguono 4 mosse mentre per il secondo 3.

Ovviamente tutti questi calcoli vanno ripetuti size_b volte!
	*/
42 Push Swap

Descrizione del Progetto

Il progetto 42 push_swap consiste nella scrittura di un algoritmo di ordinamento utilizzando il linguaggio C. L'obiettivo principale è ordinare uno stack di dimensioni variabili con il minor numero di mosse possibili, utilizzando solo un set predefinito di mosse.
Mosse Disponibili

Durante l'implementazione del progetto, sono disponibili le seguenti mosse:


 <table style="width:100%">
  <tr>
    <th>Mossa</th>
    <th>Comportamento</th>
  </tr>
  <tr>
    <td>sa (swap a)</td>
    <td style="text-align:right">Scambia i primi due elementi dello stack a. Non fa nulla se ci sono uno o nessun elemento</td>
  </tr>
  <tr>
    <td>sb (swap b)</td>
    <td style="text-align:right">Scambia i primi due elementi dello stack b. Non fa nulla se ci sono uno o nessun elemento</td>
  </tr>
  <tr>
    <td>ss</td>
    <td style="text-align:right">Esegue sa e sb contemporaneamente</td>
  </tr>
   <td>pa (push a)</td>
    <td style="text-align:right">Prende il primo elemento dello stack b e lo sposta in cima allo stack a. Non fa nulla se lo stack b è vuoto</td>
  </tr>
  <tr>
    <td>pb (push b)</td>
    <td style="text-align:right">Prende il primo elemento dello stack a e lo sposta in cima allo stack b. Non fa nulla se lo stack a è vuoto</td>
  </tr>
  <tr>
    <td>ra (rotate a)</td>
    <td style="text-align:right">Sposta tutti gli elementi dello stack a verso l'alto di una posizione. Il primo elemento diventa l'ultimo</td>
  </tr>
  <tr>
    <td>rb (rotate b)</td>
    <td style="text-align:right">Sposta tutti gli elementi dello stack b verso l'alto di una posizione. Il primo elemento diventa l'ultimo</td>
  </tr>
  <tr>
    <td>rr</td>
    <td style="text-align:right">Esegue ra e rb contemporaneamente</td>
  </tr>
   <td>rra (reverse rotate a)</td>
    <td style="text-align:right">Sposta tutti gli elementi dello stack a verso il basso di una posizione. L'ultimo elemento diventa il primo</td>
  </tr>
  <tr>
    <td>rrb (reverse rotate b)</td>
    <td style="text-align:right">Sposta tutti gli elementi dello stack b verso il basso di una posizione. L'ultimo elemento diventa il primo</td>
  </tr>
   <tr>
    <td>rrr</td>
    <td style="text-align:right">Esegue rra e rrb contemporaneamente</td>
  </tr>
</table>


Approccio al Progetto

Ho scelto di utilizzare delle liste doppiamente linkate come principale struttura dati nel progetto.Ho proceduto innanzitutto al parsing dell input, una particolare nota in questa parte del progetto va lasciata su come vengono 
controllati se sono presenti dei doppiani all interno dell input. Ho deciso di gestirlo tramite l implementazione di una hash map, che inserisca tutti gli elementi incontrati all interno di  una matrice di liste linkate, per poi 
scorrere nuovamente le liste alla ricerca di un valore che avesse una frequenza diversa da 1.

Dopo aver parsato l input e creato i due stack : A e B, ho proceduto prima a calcolare il LIS, per successivamente spostare dallo stack A in B tutti i valori che non fossero compresi all interno della LIS.
Fatto questo, abbiamo lo stack A che contiene una lista di numeri gia ordinata mentre lo stack B contiene i valori che devono essere pushati indietro in stack A.

Per ottimizzare questo ultimo passaggio ho seguito il calcolo del minor numero di rotazioni per poter inserire un valore di B in A, ho prima calcolato le rotazioni necessarie per spingere ogni valore di B in cima, e poi ho calcolato per ogni
valore di B, le rotazioni in A necessarie prima di poterlo pushare.

Worst Case : 5200ish
Best Case : 4700ish

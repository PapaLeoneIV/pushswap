#include <stdio.h>
#include <stdlib.h>
#include "limits.h"

// Funzione per trovare la LIS e restituire un array contenente la sottosequenza
int* LIS(int arr[], int n, int* lis_length) {
    int* lis = (int*)malloc(n * sizeof(int));
    int* prev_index = (int*)malloc(n * sizeof(int));
    int i, j, max_index = 0;

    // Inizializza gli array LIS e prev_index
    for (i = 0; i < n; i++) {
        lis[i] = 1;
        prev_index[i] = -1;
    }

    // Calcola la LIS e l'array prev_index
    for (i = 1; i < n; i++) {
        for (j = 0; j < i; j++) {
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
                prev_index[i] = j;
            }
        }
    }

    // Trova l'indice dell'elemento massimo in LIS
    for (i = 1; i < n; i++) {
        if (lis[i] > lis[max_index]) {
            max_index = i;
        }
    }

    // Costruisci l'array LIS
    *lis_length = lis[max_index];
    int* result = (int*)malloc(*lis_length * sizeof(int));
    i = max_index;
    j = *lis_length - 1;

    while (i >= 0 && j >= 0) {
        result[j] = arr[i];
        i = prev_index[i];
        j--;
    }

    // Libera la memoria allocata per gli array temporanei
    free(lis);
    free(prev_index);

    return result;
}
/* int main() {
    int arr[] = {INT_MIN + 200, -1, 9, 33, 21, 50, INT_MAX, 100};
    int n = sizeof(arr) / sizeof(arr[0]);

    int lis_length;
    int* lis_sequence = LIS(arr, n, &lis_length);

    printf("Length of LIS is %d\n", lis_length);
    printf("LIS: ");
    for (int i = 0; i < lis_length; i++) {
        printf("%d ", lis_sequence[i]);
    }
    printf("\n");

    // Libera la memoria allocata per l'array LIS
    free(lis_sequence);

    return 0;
}
 */
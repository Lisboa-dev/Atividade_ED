
#include <stdlib.h>
#include <time.h>


void trocar(int *a, int *b);
void quicksort(int *vetor, int inicio, int fim);

// Função para trocar dois elementos
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função QuickSort (ordem crescente)
void quicksort(int *vetor, int inicio, int fim) {
    if (inicio >= fim) return;

    int i = inicio;
    int j = fim;
    int m = vetor[(inicio + fim) / 2]; 

    while (i <= j) {
       
        while (vetor[i] < m) i++;
        while (vetor[j] > m) j--;
        if (i <= j) {
            trocar(&vetor[i], &vetor[j]);
            i++;
            j--;
        }
    }

    // Recursivamente ordena as duas metades
    if (inicio < j) quicksort(vetor, inicio, j);
    if (i < fim)    quicksort(vetor, i, fim);
}
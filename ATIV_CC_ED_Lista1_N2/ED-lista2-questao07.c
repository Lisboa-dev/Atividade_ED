/*    
**   Função :  Implemente uma função que classifica os elementos de um vetor em ordem crescente
 usando o algoritmo “quicksort”, que pode ser estabelecido da forma a seguir:
 1. Seja 
m o elemento do vetor que ocupa a posição “central” no vetor;
 2. Seja 
i o índice do primeiro e 
j o índice do último elemento do vetor;
 3. Enquanto 
i for menor ou igual a 
O valor de 
j , faça com que:
 i aumente até encontrar um elemento maior do que 
O valor de 
j diminua até encontrar um elemento menor que 
m ;
 Haja troca entre os elementos que ocupam as posições 
i e j;
 m ;
 4. Ao final desses passos a situação do vetor será a seguinte: à esquerda da posição
 central, existem somente elementos menores que 
m e à direita da posição central,
 existem somente elementos maiores que 
m .
 Assim, o problema de ordenar o vetor se reduz a um problema de ordenar cada uma
 dessas “metades”. Para ordenar, então, basta aplicar os mesmos passos a cada uma das
 “metades” RECURSIVAMENTE.
 5. Teste a função com valores gerados aleatoriamente
**   Autor : Matheus Lira Lisboa
**   Data  : 10/06/2025
**   Observações:  
*/

#include <stdio.h>
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

int main() {
    int tamanho, i;
    int *vetor;

    srand(time(NULL));

    printf("Digite o número de elementos do vetor: ");
    scanf("%d", &tamanho);

    // Aloca o vetor dinamicamente
    vetor = (int *)malloc(tamanho * sizeof(int));
    if (vetor == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    // Preenche o vetor com valores aleatórios de 0 a 99
    printf("Vetor original:\n");
    for (i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 100;
        printf("%d ", vetor[i]);
    }
    printf("\n");

    // Chama o quicksort
    quicksort(vetor, 0, tamanho - 1);

    // Exibe o vetor ordenado
    printf("Vetor ordenado com QuickSort:\n");
    for (i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    // Libera a memória
    free(vetor);
    return 0;
}

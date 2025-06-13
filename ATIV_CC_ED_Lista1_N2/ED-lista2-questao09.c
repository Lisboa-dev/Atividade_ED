/*    
**   Função :  Crie uma função para ordenar elementos de um vetor (pode ser de inteiros ou reais)
 usando o "método BubbleSort" (ordenação Bolha). Em seguida realize a CONTAGEM do
números de 
if's realizados e a quantidade de trocas realizadas. Mostre, ao final, após o
 vetor estar ordenado, a quantidade de 
if's e de 
trocas realizadas. Use a função em um
 programa que solicita a quantidade de elementos do vetor para o usuário e preenche este
 vetor com valores aleatórios
**   Autor : Matheus Lira Lisboa
**   Data  : 10/06/2025
**   Observações:  
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função Bubble Sort com contagem de ifs e trocas
void bubbleSort(int *vetor, int tamanho, int *contIfs, int *contTrocas) {
    int i, j, temp;
    *contIfs = 0;
    *contTrocas = 0;

    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - 1 - i; j++) {
            (*contIfs)++; 
            if (vetor[j] > vetor[j + 1]) {
                // Troca os elementos
                temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
                (*contTrocas)++; 
            }
        }
    }
}

int main() {
    int tamanho, i;
    int *vetor;
    int contIfs, contTrocas;

    srand(time(NULL)); 

    printf("Digite o número de elementos do vetor: ");
    scanf("%d", &tamanho);

    
    vetor = (int *)malloc(tamanho * sizeof(int));
    if (vetor == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    
    printf("Vetor original:\n");
    for (i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 100;
        printf("%d ", vetor[i]);
    }
    printf("\n");

   
    bubbleSort(vetor, tamanho, &contIfs, &contTrocas);

    
    printf("Vetor ordenado:\n");
    for (i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    
    printf("Número de 'if's executados: %d\n", contIfs);
    printf("Número de trocas realizadas: %d\n", contTrocas);

    
    free(vetor);
    return 0;
}

/*    
**   Função : Implemente uma função que classifica os elementos de um vetor em ordem crescente usando o seguinte algoritmo (conhecido como “classificação por seleção”):
**   Autor : 
**   Data  : 
**   Observações:  
*/

#include <stdio.h>

// Função para ordenar um vetor usando o algoritmo de seleção
void selectionSort(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        int indice_menor = i;
        for (int j = i + 1; j < tamanho; j++) {
            if (vetor[j] < vetor[indice_menor]) {
                indice_menor = j;
            }
        }
        // Troca os elementos
        if (indice_menor != i) {
            int temp = vetor[i];
            vetor[i] = vetor[indice_menor];
            vetor[indice_menor] = temp;
        }
    }
}

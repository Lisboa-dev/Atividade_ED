/*    
**   Função : Implemente uma função que classifica os elementos de um vetor em ordem crescente usando o seguinte algoritmo (conhecido como “classificação por seleção”):
**   Autor : Matheus Lira Lisboa
**   Data  : 07/06/2025
**   Observações:  
*/

#include <stdio.h>

void selectionSort(int vetor[]);

void selectionSort(int vetor[]) {
 int tamanho = sizeof(vetor)/sizeof(int);

    for (int i = 0; i < tamanho - 1; i++) {
        int indiceMenor = i;
        for (int j = i + 1; j < tamanho; j++) {
            if (vetor[j] < vetor[indiceMenor]) {
                indiceMenor = j;
            }
        }
     
        if (indiceMenor != i) {
            int guardar = vetor[i];
            vetor[i] = vetor[indiceMenor];
            vetor[indiceMenor] = guardar;
        }
    }
}
 
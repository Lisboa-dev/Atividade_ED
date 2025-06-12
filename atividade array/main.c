#include <stdio.h>
int main(){
    int array[]={'a'};
    printf("%d \n", array[1]);
   int array2[]={1,23,4,5,6,7};
   printf("%d", sizeof(array2)/sizeof(int));
}






 int p1 = inicio, p2 = meio + 1;
    int tamanho = fim - inicio + 1;
    int temp[tamanho];
    int i = 0;

    printf("combina     "); exibeSubVetor(V, p1, meio);
    printf("            "); exibeSubVetor(V, meio + 1, fim);

    // Merge dos dois subvetores
    while (p1 <= meio && p2 <= fim) {
        if (V[p1] < V[p2]) {
            temp[i++] = V[p1++];
        } else {
            temp[i++] = V[p2++];
        }
    }
    // Copia o restante do primeiro subvetor, se houver
    while (p1 <= meio) {
        temp[i++] = V[p1++];
    }
    // Copia o restante do segundo subvetor, se houver
    while (p2 <= fim) {
        temp[i++] = V[p2++];
    }
    // Copia de volta para o vetor original
    for (i = 0; i < tamanho; i++) {
        V[inicio + i] = temp[i];
    }

    printf("              "); exibeSubVetor(V, inicio, fim); printf("\n");
}

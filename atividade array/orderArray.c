#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void merge(int *V, int inicio, int meio, int fim);
void mergeSort(int *V, int inicio, int fim);
void exibeSubVetor( int array[], int primeiro, int ultimo);

void merge(int *V, int inicio, int meio, int fim){
    int p1, p2, tamanho, j, k;
    int fim1=0, fim2=0;
    tamanho= fim-inicio+1;
    p1=inicio;
    p2=meio+1;

    
    int  *temp = malloc(tamanho * sizeof(int));
;

    printf("combina     "); exibeSubVetor(V,p1,meio);
    printf("            "); exibeSubVetor(V,p1,meio);

    if(temp != NULL){
        for(int i=0; i<tamanho; i++){
            if(!fim1 && !fim2){
                if (V[p1]<V[p2]) temp[i]=V[p1++];
                else temp[i]=V[p2++];

                if(p1>meio) fim1=1;
                if(p2>meio) fim2=1;
                    
            }else{
                if(!fim1) temp[i]=V[p1++];
                else temp[i]=V[p2++];
            }
        }
        for(j=0, k=inicio; j<tamanho; j++, k++) V[k]=temp[j];

    }
    printf("              ");exibeSubVetor(V,inicio, fim-1);printf("\n");

    free(temp);
}







void mergeSort(int *V, int inicio, int fim){
    int meio;
    if(inicio<fim){
       meio= floor((inicio+fim)/2);

       printf("Divide:    "); exibeSubVetor(V, inicio, fim);
    printf("           "); exibeSubVetor(V, inicio, meio);
       printf("           "); exibeSubVetor(V, meio+1,fim);

       mergeSort(V, inicio, meio);
       mergeSort(V, meio+1, fim);
       merge(V,inicio,meio,fim);  

    }



}

void exibeSubVetor( int array[], int primeiro, int ultimo){
    int i;
    for(i=0; i<primeiro; i++) printf(" ");
    for(i=primeiro; i<=ultimo; i++)printf(" %d", array[i]);
    printf("\n");
}

int main(){
   int array[]={8,7,6,5,4,3,2,1};
    mergeSort(array, 0, 7);
    printf("\n");
    for(int i=0; i<8; i++){
        printf("%d, ", array[i]);
    }
}
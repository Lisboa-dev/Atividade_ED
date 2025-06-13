/*    
**   Função : Ler n números inteiros e exibir o maior, o menor, a média e quantos são maiores que a média;
**   Autor : Matheus Lira Lisboa
**   Data  : 29/05/2025
**   Observações:  none
*/
#include <stdio.h>
#include <stdlib.h>


int* preencherArray();
void Q3 (void);
void classificateNumber(int *);

//function principal
void Q3 (void){
   int array =  preencherArray();
   void classificateNumber(array);
}

int* preencherArray(){
  int tamanho, valor;
scanf("insira o valor de n para o tamanho do array: ",&tamanho);
int array[tamanho];
for (int i=0; i<tamanho; i++){
  valor=0;
  scanf("insira o valor que deve ser inserido no array: ",&valor);
  array[i]=valor;
}

return(array);
}



void classificateNumber(int * array){ 
 int tamanho = (sizeof(array)/sizeof(int)), contagem;
 float media;

    for (int i=0; i<tamanho; i++){
      media += array[i]/tamanho;
    }

    for(int i=0; i<tamanho; i++){
        if(array[i]>media){
          contagem++;
        }
    }

 printf("resposta: %d, %d, %f, %d", array[tamanho-1], array[0], media, contagem);
 free(array);
}

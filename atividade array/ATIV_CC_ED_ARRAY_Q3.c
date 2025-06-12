/*    
**   Função : Ler n números inteiros e exibir o maior, o menor, a média e quantos são maiores que a média;
**   Autor : Matheus Lira Lisboa
**   Data  : 29/05/2025
**   Observações:  none
*/
#include <stdio.h>
#include <stdlib.h>
#include "ATIV_CC_ED_ARRAY_Q2.c"


void Q3 (void);
void classificateNumber(int *);


void Q3 (void){
   int array =  gradeAverage();

   void classificateNumber(array);
}

void classificateNumber(int * array){ 
 int tamanho = (sizeof(array)/sizeof(int)), contage;
 float media;

    for (int i=0; i<tamanho; i++){
      media += array[i]/tamanho;
    }

    for(int i=0; i<tamanho; i++){
        if(array[i]>media){
          contage++;
        }
    }

 printf("resposta: %d, %d, %f, %d", array[tamanho-1], array[0], media, contage);
    
}

/*    
**   Função : exibe uma média de notas recebidas
**   Autor : Matheus Lira Lisboa
**   Data  : 29/05/2025
**   Observações:  none
*/

#include <stdio.h>
#include <stdlib.h>
float* gradeAverage (void);
float gradeAvaregeList(float* list);



float*  gradeAverage (void){
   //uma function que recebe valores digitados pelo usuário e gera uma média, também retorna o arrey de notas com a média como ultimo elemento

   float average, number;
   int lenght;
   scanf("digite um  tamanho para o array: ",&lenght);
   int array[] = (float*)malloc(sizeof(float) * (lenght+1));
  
   for(int i=0; i<lenght; i++){
       
       scanf("insira uma nota: ", &number);
       array[i]= number;

        average =+ number/lenght;
   }
   printf("A média é %f", average);
   array[lenght]=average;

   return array;
}

float gradeAvaregeInList(float* list){
//uma função que recebe um array de notas e retorna a média

   float average;
   float lenght= sizeof(list)/sizeof(float);

   for(int i=0; i<lenght; i++){
      average=+list[i];
   }
    
   return (average/lenght);
}
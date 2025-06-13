/*    
**   Função : Preencher um array de 100 elementos com elementos aleatórios (inteiros) e calcular e exibir, a média, o maior, o menor e quantos (e quais são) os menores que a média
**   Autor : Matheus Lira Lisboa
**   Data  :  29/05/2025
**   Observações:  
*/
#include <stdio.h>
#include <stdlib.h>
#include "../orderArray.c"
 
int * randomNumberArray (int n);
float calcularMedia(int * array);
void classificateArray();



//criar array
int * randomNumberArray (int n){
    srand(time(NULL));
    int array[100];

    printf("array[");

   for(int i=0; i<100; i++){
     int number = 0;
     number =rand()%n;
     array[i]=number;
     printf(" %d,", number);
    }
    printf("] \n");
   return(array);


}
float calcularMedia(int * array){
float media;
int tamanho= sizeof(array)/sizeof(int);

   for (int i=0; i<tamanho; i++){
      media += array[i]/tamanho;
    }

 return media;
}


void classificateArray(){
int array [100]=ramdomNumberArray(1000);
quickSort(array);
float media=calcularMedia(array);

int contagem;

for(int i=0; i< sizeof(array)/sizeof(int); i++ ){
   if(array[i]<media){
       printf("o valor %d na posição %d é menor que a média \n", array[0], i);
       contagem++;
}}

printf("\n");
printf(" a media é %f\n o maior valor é %d\n o menor valor é %d\n aquantidade de menores que a media é %d",media, array[99], array[0], contagem);

free(array);
}
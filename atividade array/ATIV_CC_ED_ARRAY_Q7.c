/*    
**   Função : Preencher um array de 100 elementos com elementos aleatórios (inteiros) e calcular e exibir, a média, o maior, o menor e quantos (e quais são) os menores que a média
**   Autor : Matheus Lira Lisboa
**   Data  :  29/05/2025
**   Observações:  
*/
#include <stdio.h>
#include <stdlib.h>

/*Preencher um array de 100 elementos com elementos aleatórios (inteiros)
 e calcular e exibir, a média, o maior, o menor e quantos (e quais são) os menores que a média*/

 #include "ATIV_CC_ED_ARRAY_Q2.c"
 #include "ATIV_CC_ED_ARRAY_Q3.c"
 #include "ATIV_CC_ED_ARRAY_Q4.c"




int * randomNumberArray (int n){
    srand(time(NULL));
    int loop, equal, true=1, false=0, increment=0,array[100];

   for(int i=0; i<100; i++){
     int number = 0;
     number =rand()%n;
     array[increment]=number;
   
    }
   
   return(array);
}

int orderArray (int * array){
   for(int j=0; j<50; j++){
       for (int i=0; i<50; i++){

       if( array[j] > array[i]){
          int a=array[j], b=array[i];

          array[i]=a;
          array[j]=b;
       }
     
    }
}


}


void classificateArray(){
int array [100]=ramdomNumberArray(1000);
orderArray(array);

printf("%f, %d, %d, %d",media, array[99], array[0], qtMenores);

for(int i=0; i< sizeof(arrayMenores)/sizeof(int); i++ ){
printf("%d", arrayMenores[0]);
}
}
 a média, o maior, o menor e quantos (e quais são) os menores que a média*/
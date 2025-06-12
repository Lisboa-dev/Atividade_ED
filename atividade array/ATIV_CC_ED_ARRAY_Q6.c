/*    
**   Função : 
**   Autor : 
**   Data  : 
**   Observações:  
*/
#include <stdio.h>
#include <stdlib.h>

/*Mostrar os n primeiros números de Fibonacci usando Arrays.
*/



int* calculum(){
  int n;
  scanf("",&n);
  
  int *array=(int*)malloc(sizeof(int)*(n+2));
  array[0]=0;
  array[1]=1;
for(int i=2; i<n+1; i++){
    array[i] = array[i-1]+array[i-2];
}

}

void displayFibonacciNumber(int* array){
   for(int i =0; i<sizeof(array)/1; i++){
    printf("%d",array[i]);
   }
}
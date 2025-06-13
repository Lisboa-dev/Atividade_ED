/*    
**   Função : Mostrar os n primeiros números de Fibonacci usando Arrays.
**   Autor : Matheus Lira Lisboa
**   Data  : 11/06/2025
**   Observações:  
*/
#include <stdio.h>
#include <stdlib.h>


int* calculum();
void displayFibonacciNumber(int* array);

//
int* calculum(){
  int n;
  scanf("***obs: os primeiros 2 numeros sempre serão 0 e 1, é uma constante independente de n \ninforme até onde deve ser exibido: ",&n);
  
  int *array=(int*)malloc(sizeof(int)*(n+2));
  array[0]=0;
  array[1]=1;
for(int i=2; i<n+1; i++){
    array[i] = array[i-1]+array[i-2];
}

}

void displayFibonacciNumber(int* array){
   for(int i =0; i<sizeof(array)/sizeof(int); i++){
    printf("%d",array[i]);
   }

   free(array);
}
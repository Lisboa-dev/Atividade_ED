/*    
**   Função : exibir 10 valores recebidos do usuário
**   Autor : Matheus Lira Lisboa
**   Data  : 29/05/2025
**   Observações:  none
*/

#include <stdio.h>

void displayNumber(void);


void displayNumber(void){
    int array [10];
    int number;

    for (int i=0; i<10; i++){
    
        scanf("insira um valor inteiro: ", &number);
        array[i] = number;
    }

   for (int i=0; i<10; i++){
       printf("number %d: %d\n", i+1, array[i]);
   }
}





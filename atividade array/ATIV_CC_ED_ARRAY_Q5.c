/*    
**   Função : Calcular a variância e o desvio-padrão de 20 temperaturas guardadas em um array (que foram digitadas pelo usuário);
**   Autor : Matheus Lira Lisboa
**   Data  :  29/05/2025
**   Observações:  
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calculoVariancia(void);

void calculoVariancia(void){
 float desvioPadrao=0, variancia=0, media=0, array[20];

  for (int i=0; i<20; i++){
    scanf("%f",&array[i]);
  }
  for (int i=0; i<20; i++){
    media+=array[i];
  }
  for (int i=0; i<20; i++){
     variancia+= (array[i]-media)/19;

  }

  desvioPadrao = sqrt(variancia);
  printf("o desvio padrão é: %f e a variancia é: %f ", desvioPadrao, variancia);
  
  free(array);
}
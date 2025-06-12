/*    
**   Função : exibir 50 impares
**   Autor : Matheus Lira Lisboa
**   Data  : 29/05/2025
**   Observações:  não entendi de onde devem vir os 50 primeiros impares, coloquei de forma randomica.
*/
#include <stdio.h>
#include <stdlib.h>

int * randomOdd (void);
int * orderArray (int* array);
void print_50Odd (int* array);



int * randomOdd (){
    srand(time(NULL));
    
    int loop, equal, true=1, false=0;
    int increment=0,array[50];
    loop=true;

    do{

     if(sizeof(array)/1==50){loop=false;}
    
     int number =rand()%1000;

     if(number%2==0){
        for (int i=0; i<increment; i++){
            if(array[i]==number){
                equal=true;
           }
        }
     }

     if(equal==false){
            array[increment]=number;
            increment++;
        }
   
    }while(loop==true);
   
  
}

int * orderArray (int * array){
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
void print_50Odd (int* array){
   for (int i=0; i<50; i++){
       printf("%d",array[i]);
   }
}


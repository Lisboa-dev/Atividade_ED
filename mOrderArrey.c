order(int* array){
    if(array != NULL){
         int* arrayCompara = (int*)malloc(sizeof(array));

         if(sizeof(array)>1){
            if(array[0]>array[1]){
                arrayCompara[0]=array[0]
            }
            else{}
         }


         return array;
    }
}

mediaArrendondar(int valor){
    if(valor%2==0){
        return(valor/2);
    }
    else{ 
        int result =((valor-1)/2)+1
        return result;
}

mergeSort(int* array){
if(array != NULL){
int tamanho= sizeof(array)/sizeof(int);
int mediana= mediaArrendar(tamanho);

int inicioNovoArray1= 0;
int inicioNovoArray2= meio+1;

int *novoArray1= (*int)malloc(sizeof(int)*meio);
int *novoArray2=  (*int)malloc(sizeof(int)*(tamanho-meio));

for(int i=0; i<tamanho; i++){
    if(i<meio){
       novoArrey1[i]=arrey[i];
    }else{
       novoArrey2[i]=arrey[i];
    }
}

mergesort(novoArrey1);
mergesort(novoArrey2);
order(arrey);

}}
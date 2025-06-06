#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
1. Leia `N` alunos do teclado (com nome, idade e nota), armazenados em um vetor de structs.
2. Use `fgets` para ler os nomes.
3. Permita adicionar mais alunos depois com `realloc`.
4. Imprima todos os alunos recursivamente.
5. Calcule a média das notas com uma função.
6. Libere a memória ao final.*/


typedef struct
{
    char nome[70];
    int idade;
    float nota;

}aluno;



//definições para as functions

aluno *modify_lista_alunos(aluno *lista, int quantidade_lista);
aluno *create_lista_alunos(int tamanho_lista);
void print_lista_alunos(aluno *lista);
void media_notas_alunos(aluno *lista);
void media_notas_alunos_rec(aluno *lista, int i, float soma, int contar);




//esta função preenche o array de alunos e inicializa a memoria

aluno *create_lista_alunos(int tamanho_lista){

    aluno *lista =(aluno *) malloc((tamanho_lista+1) *sizeof(aluno));
     
    //mensagem de erro para problemas na alocação
    if (lista==NULL){
        perror("erro de alocação");
        exit( EXIT_FAILURE);
    }

    //preechimento
    for (int i =0; i<tamanho_lista; i++){
        printf("\ninsira um nome: ");
        //limpar buffer 
        getchar();
        fgets(lista[i].nome, 70 * sizeof(char), stdin );
        //limpar o \n
        lista[i].nome[strcspn(lista[i].nome, "\n")] ='\0';

        printf("insira uma idade (apenas em anos inteiros): ");
        scanf("%d", &lista[i].idade);

        printf("insira uma nota: ");
        scanf("%f", &lista[i].nota);
       
        
    }
    //marcador de fim para o array
    strcpy(lista[tamanho_lista].nome,"NONE");
    lista[tamanho_lista].idade=-1;
    lista[tamanho_lista].nota=-1.0;

    
    return lista;
}




// esta função altera o espaço da memoria (obs: não impletei uma restrição para evitar redução da memoria de forma equivocada)
aluno *modify_lista_alunos(aluno *lista, int quantidade_lista){
      lista= (aluno *) realloc (lista, (quantidade_lista+1) *sizeof(aluno));
      int continuar;
      
      if (lista==NULL){
        perror("erro de alocação");
        exit( EXIT_FAILURE);
      }

      printf("\ndigite 1 para adicionar novos alunos ou 0 para não adicionar: ");
      scanf("%d", &continuar);
      
       //função de preenchimento do espaço restante
      if(continuar!=0){

        int T1=0;

        printf("\ndigite o tamanhoo anterior da lista: ");
        scanf("%d", &T1);


        for (int i =T1; i<quantidade_lista; i++){
            
            printf("\ninsira um nome: ");
            getchar();
            fgets(lista[i].nome, 70* sizeof(char), stdin );
            lista[i].nome[strcspn(lista[i].nome, "\n")] ='\0';
            

            printf("insira uma idade (apenas em anos inteiros): ");
            scanf("%d", &lista[i].idade);

            printf("insira uma nota: ");
            scanf("%f", &lista[i].nota);
        }
    
      strcpy(lista[quantidade_lista].nome,"NONE");
      lista[quantidade_lista].idade=-1;
      lista[quantidade_lista].nota=-1.0;

    
    }



    return lista;
}
//esta função exibe os alunos dentro do array
void print_lista_alunos(aluno *lista){

    printf("os alunos dentro da lista são: \n");
    int contar=0;

    //exibição apenas do nome

    printf("\n posição  nome");
    while(1){
      
        if (lista[contar].idade!=-1){

            printf("%d   %s", contar+1, lista[contar].nome);

        }else{
            break;
        }
        contar++;

    }
    printf("\n");

}

//função recursiva para exibir a média entre as notas contidas no array

void media_notas_alunos_rec(aluno *lista, int i, float soma, int contar) {
    if (lista[i].nota == -1.0) {
        if (contar > 0)
            printf("\nA média das notas dos alunos é %.2f\n", soma / contar);
        else
            printf("Nenhuma nota válida foi encontrada.\n");
        return;
    }

    media_notas_alunos_rec(lista, i + 1, soma + lista[i].nota, contar + 1);
}

//chamada da função para permitir a recursividade sem a necissidade de inserir dados manualmente
void media_notas_alunos(aluno *lista) {
    media_notas_alunos_rec(lista, 0, 0.0, 0);
}




int main(){
 
 aluno *lista = create_lista_alunos(3);
 lista = modify_lista_alunos(lista, 5);
 print_lista_alunos(lista);
 media_notas_alunos(lista);

 free(lista);



}
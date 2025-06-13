/*    
**   Função : 
**   Autor : 
**   Data  : 
**   Observações:  
*/
 /*Suponha que uma empresa aérea mantém um cadastro de aeroportos como um vetor de
ponteiros para estruturas que contêm as seguintes informações:
a. Sigla: string com até 3 caracteres;
b.Cidade: string com até 50 caracteres;
c.Pais: string com até 30caracteres;
d.Taxa: um valor real;
e.Capacidade: um valor inteiro;
Defina uma estrutura em C com o nome de aeroporto, que tenha os campos apropriados
para guardar todas as informações descritas anteriormente. Defina também um novo tipo
de dados com o nome de Aeroporto, correspondendo a essa estrutura. Defina um vetor de
Aeroportos (usando alocação dinâmica para a quantidade de aeroportos) para armazenar
todos os aeroportos que a empresa aérea trabalha. Implementar rotinas para ler, escrever e
excluir registros deste tipo.*/

#include <stdio.h>

typedef struct{
 char sigla[4];
 char cidade[50];
 char pais[30];
 float taxa;
 int capacidade;
}aeroporto;

typedef struct{
    aeroporto *cadastro;
    int quantidade;
}AeroportosList;

void preencherAeroporto(aeroporto novo) {
    

    printf("Sigla (3 letras): ");
    scanf(" %3s", novo.sigla);

    printf("Cidade: ");
    scanf(" %49s]", novo.cidade);

    printf("País: ");
    scanf(" %29s", novo.pais);

    printf("Taxa: ");
    scanf("%f", &novo.taxa);

    printf("Capacidade: ");
    scanf("%d", &novo.capacidade);

    return novo;
}


AeroportosList* cadastrarAeroporto(aeroporto aeroportoQualquer, AeroportosList list ){



 if(list.cadastro==NULL){
   list.cadastro=(aeroporto*) realloc((list.quantidade+1)*sizeof(aeroporto));
   list.quantidade=list.quantidade+1;
 }
 else{
     list.cadastro=(aeroporto*) malloc(sizeof(aeroporto));
     list.quantidade=1;
 }
 int position=list.quantidade-1;
 list.cadastro[position]= aeroportoQualquer;

}







void listarAeroportos(AeroportosList lista) {
    printf("\n--- Lista de Aeroportos ---\n");
    for (int i = 0; i < lista.quantidade; i++) {
        printf("Aeroporto %d:\n", i + 1);
        printf("  Sigla: %s\n", lista.cadastro[i].sigla);
        printf("  Cidade: %s\n", lista.cadastro[i].cidade);
        printf("  País: %s\n", lista.cadastro[i].pais);
        printf("  Taxa: %.2f\n", lista.cadastro[i].taxa);
        printf("  Capacidade: %d\n", lista.cadastro[i].capacidade);
    }
    if (lista.quantidade == 0) {
        printf("Nenhum aeroporto cadastrado.\n");
    }
}

void excluirAeroporto(AeroportosList lista, const char* sigla) {
   int *quantidade=lista.quantidade;
    for (int i = 0; i < *quantidade; i++) {
        if (strcmp(lista.cadastro[i].sigla, sigla) == 0) {
            free(lista.cadastro[i]);
            // Move os demais para preencher a lacuna
            for (int j = i; j < *quantidade - 1; j++) {
                lista.cadastro[j] = lista.cadastro[j + 1];
            }
            lista.quantidade=(*quantidade)--;
            printf("Aeroporto com sigla '%s' removido.\n", sigla);
            return;
        }
    }
    printf("Sigla '%s' não encontrada.\n", sigla);
}

void liberarAeroportos(AeroportosList lista, int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        free(lista.cadastro[i]);
    }
    free(lista);
}

aeroporto buscarAeroporto(AeroportosList lista, char* texto){
    for (int i=0; i<lista.quantidade; i++){
        if(texto==lista.cadastro[i].sigla){
        printf("Aeroporto com sigla %s encontraddo\n A seguir mais informações:", texto);
        printf("cidade: %s\n, pais: %s\n, taxa: %f\n, capacidade%d\n", lista.cadastro[i].cidade,lista.cadastro[i].pais,lista.cadastro[i].taxa,lista.cadastro[i].capacidade);
        return(lista.cadastro[i]);
    
    }
    }

    printf("aeroporto não encontrado");
}
/*    
**   Função : empresa aerea
**   Autor : Matheus Lira Lisboa
**   Data  : 12/06/2025
**   Observações:  não fiz tratamento de dados pq C da muito trabalho
*/
 

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

void liberarAeroportos(AeroportosList lista) {
    for (int i = 0; i < lista.quantidade; i++) {
        free(lista.cadastro[i]);
    }
    free(lista);
}

int buscarAeroporto(AeroportosList lista, char* texto){
    for (int i=0; i<lista.quantidade; i++){
        if(texto==lista.cadastro[i].sigla){
        printf("Aeroporto com sigla %s encontraddo\n A seguir mais informações:", texto);
        printf("cidade: %s\n, pais: %s\n, taxa: %f\n, capacidade%d\n", lista.cadastro[i].cidade,lista.cadastro[i].pais,lista.cadastro[i].taxa,lista.cadastro[i].capacidade);
        return(i);
    
    }
    }
    return(0);

    printf("aeroporto não encontrado");
}

aeroporto alterarAeroporto(AeroportosList lista, char* texto){
    int posicao= buscarAeroporto(lista,texto);
    aeroporto novo;
    preencherAeroporto( novo);

    lista.cadastro[posicao]=novo;

}
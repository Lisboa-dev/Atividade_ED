/*    
**   Função : structs do empregado e empregados
**   Autor : Matheus lira Lisboa
**   Data  : 10/06/2025
**   Observações:  não fiz tratamento de dados pq C da muito trabalho
*/

#include <stdio.h>

typedef struct {
    char RG[10];
    char nome[50];
    char nascimento[11];
    char admissao[11];
    float salario;
    
} empregado;

typedef struct{
empregado* cadastro;
int quantidade;
}Empregados;




void CriarEmpregado(empregado Nome){
   for(int i=0; i<5; i++){
    switch (i){
      case 0:
       printf("insirao RG do funcionario: ");
       scanf("%10s",&Nome.RG);
       break;
      case 1:
       printf("insirao Nome do funcionario: ");
       scanf("%50s",&Nome.nome);
       break;
      case 2:
       printf("insirao nascimento do funcionario: ");
       scanf("%11s",&Nome.nascimento);
       break;
      case 3:
       printf("insirao admissao do funcionario: ");
       scanf("%11s",&Nome.admissao);
       break;
      case 4:
       printf("insirao salario do funcionario: ");
       scanf("%2.f",&Nome.salario);
       break;
      default:
       print("insirao RG do funcionario: algum erro ocorreu na criação do seu funcionario! tente novamente\n");
    }
   }
}

void registrarEmpregado(empregado funcionario, Empregados list){
     
 if(list.cadastro==NULL){
   list.cadastro=(empregado*) realloc((list.quantidade+1)*sizeof(empregado));
   list.quantidade=list.quantidade+1;
 }
 else{
     list.cadastro=(empregado*) malloc(sizeof(empregado));
     list.quantidade=1;
 }
 int position=list.quantidade-1;
 list.cadastro[position]= funcionario;
   
}



void liberarEmpregados(Empregados lista) {
    for (int i = 0; i < lista.quantidade; i++) {
        free(lista.cadastro[i]);
    }
    free(lista);
}

int buscarEmpregado(Empregados lista, char* texto){
    for (int i=0; i<lista.quantidade; i++){
        if(texto==lista.cadastro[i].RG){
        printf("funcionario com RG %s encontraddo\n A seguir mais informações:", texto);
        printf("nome: %s\n, nascimento: %s\n, admissao: %s\n, salario%d\n", lista.cadastro[i].nome,lista.cadastro[i].nascimento,lista.cadastro[i].admissao,lista.cadastro[i].salario);
        return(i);
    
    }
    }
    return(0);

    printf("Empregado não encontrado");
}

empregado alterarEmpregado(Empregados lista, char* texto){
    int posicao= buscarEmpregado(lista,texto);
    empregado novo;
    preencherEmpregado( novo);

    lista.cadastro[posicao]=novo;

}



void listarEmpregados(Empregados lista) {
    printf("\n--- Lista de Empregados ---\n");
    for (int i = 0; i < lista.quantidade; i++) {
        printf("Empregado %d:\n", i + 1);
        printf("  RG: %s\n", lista.cadastro[i].RG);
        printf("  nome: %s\n", lista.cadastro[i].nome);
        printf("  nascimento: %s\n", lista.cadastro[i].nascimento);
        printf("  admissao: %.2f\n", lista.cadastro[i].admissao);
        printf("  salario: %d\n", lista.cadastro[i].salario);
    }
    if (lista.quantidade == 0) {
        printf("Nenhum Empregado cadastrado.\n");
    }
}

void excluirEmpregado(Empregados lista, const char* RG) {
   int *quantidade=lista.quantidade;
    for (int i = 0; i < *quantidade; i++) {
        if (strcmp(lista.cadastro[i].RG, RG) == 0) {
            free(lista.cadastro[i]);
            // Move os demais para preencher a lacuna
            for (int j = i; j < *quantidade - 1; j++) {
                lista.cadastro[j] = lista.cadastro[j + 1];
            }
            lista.quantidade=(*quantidade)--;
            printf("Empregado com RG '%s' removido.\n", RG);
            return;
        }
    }
    printf("RG '%s' não encontrada.\n", RG);
}
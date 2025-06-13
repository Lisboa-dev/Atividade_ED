/*    
**   Função : structs do empregado e empregados
**   Autor : Matheus lira Lisboa
**   Data  : 10/06/2025
**   Observações:  
*/

/* Defina um registro (estrutura - struct) empregado para armazenar os dados (nome, data de
nascimento, RG, data de admissão e salário)de um empregado de uma empresa. Criar um
novo tipo de dados chamado Empregado usando a estrutura empregado. Defina um vetor
de empregados (usando alocação dinâmica) para armazenar todos os empregados de sua
empresa. Implementar rotinas para ler, escrever e excluir registros deste tipo.*/
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
       printf("\n");
       scanf("%10s",&Nome.RG);
       break;
      case 1:
       printf("\n");
       scanf("%50s",&Nome.nome);
       break;
      case 2:
       printf("\n");
       scanf("%11s",&Nome.nascimento);
       break;
      case 3:
       printf("\n");
       scanf("%11s",&Nome.admissao);
       break;
      case 4:
       printf("\n");
       scanf("%2.f",&Nome.salario);
       break;
      default:
       print("\n algum erro ocorreu na criação do seu funcionario! tente novamente\n");
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

encontar, alterar, excluir
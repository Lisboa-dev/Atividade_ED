/*    
**   Função : 
**   Autor : 
**   Data  : 
**   Observações:  
*/

/* Defina um registro (estrutura - struct) empregado para armazenar os dados (nome, data de
nascimento, RG, data de admissão e salário)de um empregado de uma empresa. Criar um
novo tipo de dados chamado Empregado usando a estrutura empregado. Defina um vetor
de empregados (usando alocação dinâmica) para armazenar todos os empregados de sua
empresa. Implementar rotinas para ler, escrever e excluir registros deste tipo.*/

typedef struct {
    char RG[10];
    char nome[50];
    char nascimento[11];
    char admissao[11];
    float salario;
    
} empregado;

typedef struct{
empregado** list;
int quantidade;
}Empregados;




void CriarEmpregado(empregado Nome){
   for(int i=0; i<5; i++){
    switch (i){
      case 0:
       scanf("",&Nome.RG);
       break;
      case 1:
       scanf("",&Nome.nome);
       break;
      case 2:
       scanf("",&Nome.nascimento);
       break;
      case 3:
       scanf("",&Nome.admissao);
       break;
      case 4:
       scanf("",&Nome.salario);
       break;
      default:
       print("\n algum erro occorreu na criação do seu funcionario! tente novamente\n");
    }
   }
}

void registrarEmpregado(empregado funcionario, Empregados list){
     int posicao;
    
    if(sizeof(list)!=NULL){
        posicao= sizeof(list)/sizeof(empregado)-1;
        list->list = (* Empregados)realloc(sizeof(List)+sizeof(empregado));
    }else{
        posicao = 0
         list->list= (* Empregados)malloc(sizeof(empregado));
    }

    list->list[posicao]=funcionario;

   
}

encontar, alterar, excluir
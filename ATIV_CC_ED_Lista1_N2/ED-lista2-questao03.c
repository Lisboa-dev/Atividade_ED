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

typedef struct{
 char sigla[4];
 char cidade[50];
 char pais[30];
 float taxa;
}aeroporto;

typedef struct{
    aeroporto **list;
    int quantidade;
}Aeroportos;

Aeroporto* criarAeroporto() {
    Aeroporto* novo = (Aeroporto*) malloc(sizeof(Aeroporto));
    if (novo == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    printf("Sigla (3 letras): ");
    scanf(" %3s", novo->sigla);

    printf("Cidade: ");
    scanf(" %49[^\n]", novo->cidade);

    printf("País: ");
    scanf(" %29[^\n]", novo->pais);

    printf("Taxa: ");
    scanf("%f", &novo->taxa);

    printf("Capacidade: ");
    scanf("%d", &novo->capacidade);

    return novo;
}

void listarAeroportos(Aeroporto** lista, int quantidade) {
    printf("\n--- Lista de Aeroportos ---\n");
    for (int i = 0; i < quantidade; i++) {
        printf("Aeroporto %d:\n", i + 1);
        printf("  Sigla: %s\n", lista[i]->sigla);
        printf("  Cidade: %s\n", lista[i]->cidade);
        printf("  País: %s\n", lista[i]->pais);
        printf("  Taxa: %.2f\n", lista[i]->taxa);
        printf("  Capacidade: %d\n", lista[i]->capacidade);
    }
    if (quantidade == 0) {
        printf("Nenhum aeroporto cadastrado.\n");
    }
}

void excluirAeroporto(Aeroporto** lista, int* quantidade, const char* sigla) {
    for (int i = 0; i < *quantidade; i++) {
        if (strcmp(lista[i]->sigla, sigla) == 0) {
            free(lista[i]);
            // Move os demais para preencher a lacuna
            for (int j = i; j < *quantidade - 1; j++) {
                lista[j] = lista[j + 1];
            }
            (*quantidade)--;
            printf("Aeroporto com sigla '%s' removido.\n", sigla);
            return;
        }
    }
    printf("Sigla '%s' não encontrada.\n", sigla);
}

void liberarAeroportos(Aeroporto** lista, int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        free(lista[i]);
    }
    free(lista);
}

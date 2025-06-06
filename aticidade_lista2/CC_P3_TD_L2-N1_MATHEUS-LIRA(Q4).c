/*Agenda de Contatos com Realloc e Ordenação
Crie um programa para gerenciar contatos:

- Nome (string)
- Telefone (string)
- Idade (int)

1. Permita ao usuário cadastrar contatos dinamicamente.
2. Adicione mais contatos com `realloc` caso necessário.
3. Liste todos os contatos com função recursiva.
4. Libere toda a memória ao final.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    char telefone[12];
    int idade;
} contato;

// Funções
contato* cadastrar_contatos(int* total);
void listar_recursivo(contato* lista, int indice, int total);




// Listar contatos com função recursiva
void listar_recursivo(contato* lista, int indice, int total) {
    if (indice >= total) return;

    printf("\nContato %d:\n", indice + 1);
    printf("Nome: %s\n", lista[indice].nome);
    printf("Telefone: %s\n", lista[indice].telefone);
    printf("Idade: %d\n", lista[indice].idade);

    listar_recursivo(lista, indice + 1, total);
}


// Cadastrar contatos dinamicamente
contato* cadastrar_contatos(int* total) {
    int capacidade = 2;
    *total = 0;
    contato* lista = malloc(capacidade * sizeof(contato));

    if (!lista) {
        perror("Erro de alocação");
        exit(EXIT_FAILURE);
    }

    while (1) {
        if (*total >= capacidade) {
            capacidade *= 2;
            lista = realloc(lista, capacidade * sizeof(contato));
            if (!lista) {
                perror("Erro de realocação");
                exit(EXIT_FAILURE);
            }
        }

        printf("\n Cadastro do contato %d\n", *total + 1);
        printf("Nome (digite 'N' para parar): ");
        fgets(lista[*total].nome, sizeof(lista[*total].nome), stdin);
        lista[*total].nome[strcspn(lista[*total].nome, "\n")] = '\0';
        if (strcmp(lista[*total].nome, "N") == 0) break;

        printf("Telefone: ");
        fgets(lista[*total].telefone, sizeof(lista[*total].telefone), stdin);
        lista[*total].telefone[strcspn(lista[*total].telefone, "\n")] = '\0';

        printf("Idade: ");
        scanf("%d", &lista[*total].idade);
        getchar(); // limpa \n do scanf

        (*total)++;
    }

    return lista;
}



int main() {
    int total = 0;
    contato* lista = cadastrar_contatos(&total);

    printf("\n Lista de contatos :\n");
    listar_recursivo(lista, 0, total);

    
    free(lista);
    return 0;
}


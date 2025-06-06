/*Sistema de Livros com Busca Recursiva
Implemente um sistema para cadastrar livros com:

- Título (string)
- Autor (string)
- Ano (inteiro)

1. Use `malloc` para alocar o vetor inicial de livros.
2. Permita adicionar mais livros com `realloc`.
3. Faça uma função recursiva para buscar um livro pelo título.
4. Liste todos os livros ao final.
5. Use `fgets` para entrada de strings e libere memória com `free`.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para armazenar dados de um livro
typedef struct {
    char Titulo[50];
    char Autor[50];
    int Ano;
} livro;

// Funções do sistema
livro *cadastrar_livros(int *total);
void listar_livros(livro *lista, int total);
int buscar_livro_por_titulo(livro *lista, int tamanho, char *titulo, int i);





// Função para cadastrar livros com realloc
livro *cadastrar_livros(int *total) {
    livro *lista = NULL;
    int capacidade = 2;
    *total = 0;

    lista = malloc(capacidade * sizeof(livro));
    if (lista == NULL) {
        perror("Erro de alocação");
        exit(EXIT_FAILURE);
    }

    while (1) {
        if (*total >= capacidade) {
            capacidade *= 2;
            lista = realloc(lista, capacidade * sizeof(livro));
            if (lista == NULL) {
                perror("Erro de realocação");
                exit(EXIT_FAILURE);
            }
        }

        printf("\n Cadastro do livro %d\n", *total + 1);

        printf("Título (digite N para parar): ");
        fgets(lista[*total].Titulo, sizeof(lista[*total].Titulo), stdin);
        lista[*total].Titulo[strcspn(lista[*total].Titulo, "\n")] = '\0';
        if (strcmp(lista[*total].Titulo, "N") == 0) break;

        printf("Autor: ");
        fgets(lista[*total].Autor, sizeof(lista[*total].Autor), stdin);
        lista[*total].Autor[strcspn(lista[*total].Autor, "\n")] = '\0';

        printf("Ano: ");
        scanf("%d", &lista[*total].Ano);
        getchar(); // Limpa o \n deixado pelo scanf

        (*total)++;
    }

    return lista;
}

// Função recursiva para buscar livro por título
int buscar_livro_por_titulo(livro *lista, int tamanho, char *titulo, int i) {
    if (i >= tamanho) return -1;
    if (strcmp(lista[i].Titulo, titulo) == 0) return i;
    return buscar_livro_por_titulo(lista, tamanho, titulo, i + 1);
}

// Lista todos os livros
void listar_livros(livro *lista, int total) {
    for (int i = 0; i < total; i++) {
        printf("\nLivro %d:\n", i + 1);
        printf("Título: %s\n", lista[i].Titulo);
        printf("Autor: %s\n", lista[i].Autor);
        printf("Ano: %d\n", lista[i].Ano);
    }
}






int main() {
    int total;
    livro *livros = cadastrar_livros(&total);

    // Busca recursiva por título
    char titulo_busca[50];
    printf("\nDigite o título do livro a buscar: ");
    fgets(titulo_busca, sizeof(titulo_busca), stdin);
    titulo_busca[strcspn(titulo_busca, "\n")] = '\0';


    //não sei se esse formato satisfaz a questão, mas achei mais pratico colocar função de exibição no main
    int pos = buscar_livro_por_titulo(livros, total, titulo_busca, 0);
    if (pos != -1) {
        printf("\n Livro encontrado:\n");
        printf("Título: %s\n", livros[pos].Titulo);
        printf("Autor: %s\n", livros[pos].Autor);
        printf("Ano: %d\n", livros[pos].Ano);
    } else {
        printf("\n Livro não encontrado.\n");
    }

    // Listar todos os livros
    printf("\n Lista de todos os livros cadastrados:\n");
    listar_livros(livros, total);

    // Libera a memória
    free(livros);
    return 0;
}

/*Matriz Dinâmica e Structs
Crie um programa que:

1. Aloca uma matriz `NxM` dinamicamente (`int **matriz`) e preenche com valores do teclado.
2. Use uma `struct` chamada `InfoMatriz` contendo número de linhas, colunas, e ponteiro para a matriz.
3. Faça uma função que some todos os elementos.
4. Use `free` para liberar a matriz e o struct.*/

#include <stdio.h>
#include <stdlib.h>

// Struct que contém as informações da matriz
typedef struct {
    int rows;
    int columns;
    int **matriz;
} InfoMatriz;

// Funções
InfoMatriz criar_matriz(int rows, int columns);
int somar_elementos(InfoMatriz info);
void liberar_matriz(InfoMatriz *info);


// Criação dinâmica da matriz
InfoMatriz criar_matriz(int rows, int columns) {
    InfoMatriz info;
    info.rows = rows;
    info.columns = columns;

   //aloca um bloco linhas
    info.matriz = malloc(rows * sizeof(int*));
    if (!info.matriz) {
        perror("Erro ao alocar linhas");
        exit(EXIT_FAILURE);
    }

    // Aloca cada linha
    for (int i = 0; i < rows; i++) {
        info.matriz[i] = malloc(columns * sizeof(int));
        if (!info.matriz[i]) {
            perror("Erro ao alocar colunas");
            exit(EXIT_FAILURE);
        }
    }

    // Preenchimento
    printf("\n📥 Insira os valores da matriz (%dx%d):\n", rows, columns);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &info.matriz[i][j]);
        }
    }

    return info;
}

// Soma dos elementos da matriz
int somar_elementos(InfoMatriz info) {
    int soma = 0;
    for (int i = 0; i < info.rows; i++) {
        for (int j = 0; j < info.columns; j++) {
            soma += info.matriz[i][j];
        }
    }
    return soma;
}

// Libera toda a memória alocada
void liberar_matriz(InfoMatriz *info) {
    for (int i = 0; i < info->rows; i++) {
        free(info->matriz[i]);
    }
    free(info->matriz);
    info->matriz = NULL;
}

int main() {
    int n, m;

    printf("Digite o número de linhas: ");
    scanf("%d", &n);
    printf("Digite o número de colunas: ");
    scanf("%d", &m);

    InfoMatriz info = criar_matriz(n, m);

    printf("\n Matriz inserida:\n");
    for (int i = 0; i < info.rows; i++) {
        for (int j = 0; j < info.columns; j++) {
            printf("%d ", info.matriz[i][j]);
        }
        printf("\n");
    }

    int soma = somar_elementos(info);
    printf("\n Soma total dos elementos da matriz: %d\n", soma);

    liberar_matriz(&info);

    return 0;
}

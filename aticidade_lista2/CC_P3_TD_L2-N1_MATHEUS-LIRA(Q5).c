/*Sistema de Produtos com Estoque Dinâmico
Implemente um sistema com os seguintes requisitos:

- Cada produto tem `nome`, `preco`, `quantidade`.
- Use um vetor dinâmico de `Produto`.
- Crie funções para:

    - Cadastrar produtos
    - Calcular valor total em estoque
    - estoquer produtos com estoque baixo (qtd < 5) recursivamente

- Use `realloc` ao adicionar produtos.
- Libere memória com `free`.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[30];
    float preco;
    int quantidade;
} produto;

// Funções
produto* cadastrar_produtos(int* total);
float calcular_valor_total(produto* estoque, int total);
void listar_estoque_baixo(produto* estoque, int total, int i);

// Cadastro dinâmico com realloc
produto* cadastrar_produtos(int* total) {
    int capacidade = 2;
    *total = 0;
    produto* estoque = malloc(capacidade * sizeof(produto));

    if (!estoque) {
        perror("Erro de alocação");
        exit(EXIT_FAILURE);
    }

    while (1) {
        if (*total >= capacidade) {
            capacidade *= 2;
            estoque = realloc(estoque, capacidade * sizeof(produto));
            if (!estoque) {
                perror("Erro de realocação");
                exit(EXIT_FAILURE);
            }
        }

        printf("\n📦 Cadastro do produto %d\n", *total + 1);
        printf("Nome (ou N para parar): ");
        fgets(estoque[*total].nome, sizeof(estoque[*total].nome), stdin);
        estoque[*total].nome[strcspn(estoque[*total].nome, "\n")] = '\0';
        if (strcmp(estoque[*total].nome, "N") == 0) break;

        printf("Preço: ");
        scanf("%f", &estoque[*total].preco);
        printf("Quantidade: ");
        scanf("%d", &estoque[*total].quantidade);
        getchar(); // limpa o '\n' do buffer

        (*total)++;
    }

    return estoque;
}

// Cálculo do valor total do estoque
float calcular_valor_total(produto* estoque, int total) {
    float total_valor = 0;
    for (int i = 0; i < total; i++) {
        total_valor += estoque[i].preco * estoque[i].quantidade;
    }
    return total_valor;
}

// Função recursiva para listar produtos com estoque baixo
void listar_estoque_baixo(produto* estoque, int total, int i) {
    if (i >= total) return;

    if (estoque[i].quantidade < 5) {
        printf("Produto: %s | Qtd: %d | Preço: R$ %.2f\n",
               estoque[i].nome, estoque[i].quantidade, estoque[i].preco);
    }

    listar_estoque_baixo(estoque, total, i + 1);
}


int main() {
    int total = 0;
    produto* estoque = cadastrar_produtos(&total);

    float valor_total = calcular_valor_total(estoque, total);
    printf("\n Valor total em estoque: R$ %.2f\n", valor_total);

    printf("\n Produtos com estoque baixo (quantidade < 5):\n");
    listar_estoque_baixo(estoque, total, 0);

    free(estoque);
    return 0;
}

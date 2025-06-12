/*    
**   Função : 
**   Autor : 
**   Data  : 
**   Observações:  
*/
/* Crie um novo TAD (Tipo Abstrato de Dado) de arquivo único chamado Complexo para
realizar aritmética com números complexos. Utilize variáveis double para representar os
campos deste tipo. Implemente funções para as seguintes operações: criar e destruir um
número complexo; ler um número complexo, somar dois números complexos, subtrair dois
números complexos, multiplicar dois números complexos, dividir dois números complexos,
mostrar um número complexo na forma (a,b) onde a é a parte real e b, a parte imaginária.*/

#include <stdio.h>
#include <stdlib.h>

// Definição do tipo abstrato de dado Complexo
typedef struct {
    double real;
    double imaginario;
} Complexo;

// Cria um número complexo com parte real e imaginária fornecidas
Complexo* criarComplexo(double real, double imaginario) {
    Complexo* c = (Complexo*) malloc(sizeof(Complexo));
    if (c != NULL) {
        c->real = real;
        c->imaginario = imaginario;
    }
    return c;
}

// Destrói (libera) um número complexo
void destruirComplexo(Complexo* c) {
    if (c != NULL) {
        free(c);
    }
}

// Lê um número complexo do teclado e retorna um ponteiro para ele
Complexo* lerComplexo() {
    double r, i;
    printf("Digite a parte real: ");
    scanf("%lf", &r);
    printf("Digite a parte imaginária: ");
    scanf("%lf", &i);
    return criarComplexo(r, i);
}

// Imprime um número complexo
void imprimirComplexo(const Complexo* c) {
    if (c != NULL) {
        printf("Número complexo: %.2f %c %.2fi\n", c->real,
               (c->imaginario < 0 ? '-' : '+'),
               (c->imaginario < 0 ? -c->imaginario : c->imaginario));
    }
}

// Função principal de teste
int main() {
    Complexo* z = lerComplexo();
    imprimirComplexo(z);
    destruirComplexo(z);
    return 0;
}


#include <stdio.h>
#include <stdlib.h>

// Definição do tipo Complexo
typedef struct {
    double real;
    double imaginario;
} Complexo;

// Criação e destruição
Complexo* criarComplexo(double real, double imaginario) {
    Complexo* c = (Complexo*) malloc(sizeof(Complexo));
    if (c != NULL) {
        c->real = real;
        c->imaginario = imaginario;
    }
    return c;
}

void destruirComplexo(Complexo* c) {
    if (c != NULL) {
        free(c);
    }
}

// Leitura e impressão
Complexo* lerComplexo() {
    double r, i;
    printf("Digite a parte real: ");
    scanf("%lf", &r);
    printf("Digite a parte imaginária: ");
    scanf("%lf", &i);
    return criarComplexo(r, i);
}

void imprimirComplexo(const Complexo* c) {
    if (c != NULL) {
        printf("Número complexo: %.2f %c %.2fi\n", c->real,
               (c->imaginario < 0 ? '-' : '+'),
               (c->imaginario < 0 ? -c->imaginario : c->imaginario));
    }
}

void mostrarComplexoCoordenada(const Complexo* c) {
    if (c != NULL) {
        printf("Forma (a,b): (%.2f, %.2f)\n", c->real, c->imaginario);
    }
}

// Operações com complexos
Complexo* somarComplexo(const Complexo* a, const Complexo* b) {
    return criarComplexo(a->real + b->real, a->imaginario + b->imaginario);
}

Complexo* subtrairComplexo(const Complexo* a, const Complexo* b) {
    return criarComplexo(a->real - b->real, a->imaginario - b->imaginario);
}

Complexo* multiplicarComplexo(const Complexo* a, const Complexo* b) {
    double real = a->real * b->real - a->imaginario * b->imaginario;
    double imag = a->real * b->imaginario + a->imaginario * b->real;
    return criarComplexo(real, imag);
}

Complexo* dividirComplexo(const Complexo* a, const Complexo* b) {
    double denominador = b->real * b->real + b->imaginario * b->imaginario;
    if (denominador == 0) return NULL;

    double real = (a->real * b->real + a->imaginario * b->imaginario) / denominador;
    double imag = (a->imaginario * b->real - a->real * b->imaginario) / denominador;
    return criarComplexo(real, imag);
}

// Função principal de teste
int main() {
    Complexo* z1 = lerComplexo();
    Complexo* z2 = lerComplexo();

    Complexo* soma = somarComplexo(z1, z2);
    Complexo* sub = subtrairComplexo(z1, z2);
    Complexo* mult = multiplicarComplexo(z1, z2);
    Complexo* div = dividirComplexo(z1, z2);

    printf("\nSoma: ");
    imprimirComplexo(soma);

    printf("Subtração: ");
    imprimirComplexo(sub);

    printf("Multiplicação: ");
    imprimirComplexo(mult);

    printf("Divisão: ");
    if (div != NULL) imprimirComplexo(div);
    else printf("Divisão por zero não permitida.\n");

    printf("\nz1 na forma (a,b): ");
    mostrarComplexoCoordenada(z1);

    // Liberação
    destruirComplexo(z1);
    destruirComplexo(z2);
    destruirComplexo(soma);
    destruirComplexo(sub);
    destruirComplexo(mult);
    destruirComplexo(div);

    return 0;
}

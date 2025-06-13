/*    
**   Função : Crie um novo TAD (Tipo Abstrato de Dado) de arquivo único chamado Complexo para realizar aritmética com números complexos. 
**   Autor : Matheus Lira Lisboa
**   Data  : 
**   Observações:  
*/


#include <stdio.h>
#include <stdlib.h>


typedef struct {
    double real;
    double imaginario;
} Complexo;


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

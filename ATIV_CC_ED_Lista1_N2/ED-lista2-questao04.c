/*    
**   Função : 
**   Autor : 
**   Data  : 
**   Observações:  
*/
/*A famosa Conjectura de Goldbach diz que todo inteiro par maior que 2 é a soma de dois
outros números primos. Testes extensivos foram feitos sem, contudo, ser encontrado um
contra-exemplo. Escreva um programa que mostre que a afirmação é verdadeira para
todo número par entre 700 e 1100. O programa deve imprimir cada número e os primos
correspondentes.*/

#include <stdio.h>
#include <stdbool.h>

// Função que verifica se um número é primo
bool ehPrimo(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    printf("Verificando a Conjectura de Goldbach de 700 a 1100:\n\n");

    for (int n = 700; n <= 1100; n += 2) {
        bool encontrado = false;
        for (int i = 2; i <= n / 2; i++) {
            if (ehPrimo(i) && ehPrimo(n - i)) {
                printf("%d = %d + %d\n", n, i, n - i);
                encontrado = true;
                break; // Apenas o primeiro par de primos encontrado
            }
        }
        if (!encontrado) {
            printf("!!! Contra-exemplo encontrado: %d não pode ser decomposto.\n", n);
        }
    }

    return 0;
}

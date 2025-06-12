/*    
**   Função : A famosa Conjectura de Goldbach diz que todo inteiro par maior que 2 é a soma de dois
outros números primos. Testes extensivos foram feitos sem, contudo, ser encontrado um
contra-exemplo. Escreva um programa que mostre que a afirmação é verdadeira para
todo número par entre 700 e 1100. O programa deve imprimir cada número e os primos
correspondentes.
**   Autor : 
**   Data  : 
**   Observações:  
*/

#include <stdio.h>
#include <stdbool.h>

// Função para verificar se um número é primo
bool ehPrimo(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    printf("Verificando a Conjectura de Goldbach para números pares entre 700 e 1100:\n\n");

    for (int n = 700; n <= 1100; n += 2) { // só pares
        bool encontrou = false;

        for (int i = 2; i <= n / 2; i++) {
            int j = n - i;
            if (ehPrimo(i) && ehPrimo(j)) {
                printf("%d = %d + %d\n", n, i, j);
                encontrou = true;
                break; // exibe apenas o primeiro par encontrado
            }
        }

        if (!encontrou) {
            printf("!!! Não foi encontrado par de primos para %d\n", n); // Teoricamente nunca deve acontecer
        }
    }

    return 0;
}

/*    
**   Função :Conjectura de Goldbach 
**   Autor : Matheus Lira Lisboa
**   Data  : 5/06/2025
**   Observações:  
*/
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

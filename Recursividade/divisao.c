#include <stdio.h>

int div(int m, int n) {
    if (m < n) {
        return 0; // Caso base: se m eh menor que n, o quociente eh 0
    }
    return 1 + div(m - n, n); // Subtrai n de m e soma 1 ao quociente
}

int main() {
    int m, n;

    printf("Digite o valor de m (dividendo): ");
    scanf("%d", &m);

    printf("Digite o valor de n (divisor): ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("O divisor deve ser maior que zero.\n");
        return 1; // Termina o programa com erro
    }

    printf("Resultado da divisão inteira de %d por %d: %d\n", m, n, div(m, n));

    return 0;
}

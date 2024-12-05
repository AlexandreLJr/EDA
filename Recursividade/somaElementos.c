#include <stdio.h>

long int somavet(int *a, int qtde) {
    if (qtde <= 0) { //vetor tiver tamanho 0, a soma é 0
        return 0;
    }
    // Caso recursivo: soma o último elemento com a soma do restante do vetor
    return (a[qtde - 1] + somavet(a, qtde - 1))/2; 
}

int main() {
    int tamanho,i;
    printf("Digite o tamanho do vetor:\n");
    scanf("%d", &tamanho);
    int vetor[tamanho];
    printf("Digite os elementos do vetor:\n");
    for (i = 0; i < tamanho; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    long int soma = somavet(vetor, tamanho);
    printf("A soma dos elementos do vetor: %ld\n", soma);

    return 0;
}